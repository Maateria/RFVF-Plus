#include "global.h"
#include "gflib.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_fadetransition.h"
#include "field_player_avatar.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "list_menu.h"
#include "menu.h"
#include "menu_indicators.h"
#include "metatile_behavior.h"
#include "new_menu_helpers.h"
#include "overworld.h"
#include "script.h"
#include "secret_base.h"
#include "strings.h"
#include "task.h"
#include "constants/decorations.h"
#include "constants/event_objects.h"
#include "constants/maps.h"
#include "constants/metatile_behaviors.h"
#include "constants/metatile_labels.h"
#include "constants/songs.h"

#include "data/decoration/tiles.h"
#include "data/decoration/description.h"
#include "data/decoration/header.h"
#include "data/decoration/tilemaps.h"

// RFVF+: Emerald's decoration PC menu (decoration.c). DECORER / RANGER / JETER from the PC of the player's secret base
// and from the Pallet Town bedroom's (dolls and cushions only, on its rug: GetDecorationSpotBehaviorAt), JETER only
// from the other PCs (DoDecorationPCMenu), and the Mauville old man's trader. Tile decorations are drawn on the base's
// map grid (ShowDecorationOnMap), dolls and cushions are its FLAG_DECORATION_x objects (VAR_OBJ_GFX_ID_x).
// Placed decorations stay in the inventory: "in use" means placed (secretBases[0] / playerRoomDecorations).

#define PLACE_DECORATION_SELECTOR_TAG 0xBE5
#define PLACE_DECORATION_PLAYER_TAG   0x008
#define NUM_DECORATION_FLAGS (FLAG_DECORATION_14 - FLAG_DECORATION_1 + 1)
#define MAPGRID_IMPASSABLE (1 << MAPGRID_COLLISION_SHIFT) // Emerald's
#define NUM_TILES_PER_METATILE 8

#define tCursorX         data[0]
#define tCursorY         data[1]
#define tState           data[2]
#define tInitialX        data[3]
#define tInitialY        data[4]
#define tDecorWidth      data[5]
#define tDecorHeight     data[6]
#define tButton          data[10]
#define tMenuCommand     data[11]
#define tItemsMenuCommand data[12]
#define tListTaskId      data[13]

enum { DECOR_MENU_PLACE, DECOR_MENU_TOSS, DECOR_MENU_TRADE };
enum { DECOR_ITEMS_MENU_PLACE, DECOR_ITEMS_MENU_PUT_AWAY };
enum { CONTEXT_PC, CONTEXT_PLAYER_ROOM, CONTEXT_SECRET_BASE }; // the PC the menu was opened from
enum { WIN_CATEGORIES, WIN_SUMMARY, WIN_DESCRIPTION, WIN_MAIN, WIN_COUNT };

#define MAX_SHOWN 8

struct PlaceDecorationGraphicsDataBuffer
{
    const struct Decoration *decoration;
    u16 tiles[0x40];
    u8 image[0x800];
    u16 palette[16];
};

struct DecorRearrangementDataBuffer
{
    u8 idx;
    u8 width;
    u8 height;
    u16 flagId;
};

static EWRAM_DATA u8 sWindowIds[WIN_COUNT] = {};
static EWRAM_DATA u8 sContext = 0;
static EWRAM_DATA u8 sCategory = 0;
static EWRAM_DATA u8 sNumOwned = 0;
static EWRAM_DATA u16 sScroll = 0;
static EWRAM_DATA u16 sRow = 0;
static EWRAM_DATA u8 sScrollArrowsTaskId = 0;
static EWRAM_DATA u8 sActionsCursorPos = 0;
static EWRAM_DATA u8 sCurDecorIndex = 0; // in the category's inventory
static EWRAM_DATA TaskFunc sExitFunc = NULL;
static EWRAM_DATA TaskFunc sYesFunc = NULL;
static EWRAM_DATA TaskFunc sNoFunc = NULL;
static EWRAM_DATA struct ListMenuItem sListItems[40 + 1] = {};
static EWRAM_DATA u8 sSecretBaseItemsIndicesBuffer[DECOR_MAX_SECRET_BASE] = {};
static EWRAM_DATA u8 sPlayerRoomItemsIndicesBuffer[DECOR_MAX_PLAYERS_HOUSE] = {};
// Emerald's is in EWRAM (2 KB): on the heap here, while the selector is shown
static EWRAM_DATA struct PlaceDecorationGraphicsDataBuffer *sPlaceDecorationGraphicsDataBuffer = NULL;
static EWRAM_DATA struct SpriteFrameImage sDecorSelectorSpriteFrameImages = {};
static EWRAM_DATA u8 sPlacedDecor = 0; // SetDecoration's doll or cushion
static EWRAM_DATA u16 sCurDecorMapX = 0;
static EWRAM_DATA u16 sCurDecorMapY = 0;
static EWRAM_DATA u8 sDecor_CameraSpriteObjectIdx1 = 0;
static EWRAM_DATA u8 sDecor_CameraSpriteObjectIdx2 = 0;
static EWRAM_DATA u8 sDecorationLastDirectionMoved = 0;
static EWRAM_DATA struct OamData sDecorSelectorOam = {};
static EWRAM_DATA struct DecorRearrangementDataBuffer sDecorRearrangementDataBuffer[DECOR_MAX_SECRET_BASE] = {};
static EWRAM_DATA u8 sCurDecorSelectedInRearrangement = 0;

static void ShowMainMenu(u8 taskId);
static void Task_HandleMainMenuInput(u8 taskId);
static void ShowCategories(u8 taskId);
static void Task_HandleCategoriesInput(u8 taskId);
static void ShowItems(u8 taskId);
static void Task_HandleItemsInput(u8 taskId);
static void IdentifyOwnedDecorationsCurrentlyInUse(void);
static void Task_PlaceDecoration(u8 taskId);
static void Task_SelectLocation(u8 taskId);
static void ContinueDecorating(u8 taskId);
static void CancelDecorating_(u8 taskId);
static void AttemptPlaceDecoration(u8 taskId);
static void AttemptCancelPlaceDecoration(u8 taskId);
static void Task_ContinuePuttingAwayDecorations(u8 taskId);
static void Task_ContinuePuttingAwayDecorationsPrompt(u8 taskId);
static void ContinuePuttingAwayDecorations(u8 taskId);
static void AttemptPutAwayDecoration(u8 taskId);
static void AttemptCancelPutAwayDecoration(u8 taskId);
static void InitializeCameraSprite1(struct Sprite *sprite);
static void InitializePuttingAwayCursorSprite(struct Sprite *sprite);
static u8 CreateDecorationSelectorSprite(u8 decor);

static const u8 *const sCategoryNames[DECORCAT_COUNT] =
{
    gText_Desk, gText_Chair, gText_Plant, gText_Ornament, gText_Mat, gText_Poster, gText_Doll, gText_Cushion
};

static const u8 *const sMainMenuItems[] = {gText_Decorate, gText_PutAway, gText_Toss2, gFameCheckerText_Cancel};

static const u8 *const sMainMenuDescriptions[] =
{
    gText_PutOutSelectedDecorItem, gText_StoreChosenDecorInPC, gText_ThrowAwayUnwantedDecors, gText_GoBackPrevMenu
};

static const struct WindowTemplate sWindowTemplates[WIN_COUNT] =
{
    [WIN_CATEGORIES]  = {.bg = 0, .tilemapLeft = 1,  .tilemapTop = 1,  .width = 13, .height = 18, .paletteNum = 13, .baseBlock = 0x001},
    [WIN_SUMMARY]     = {.bg = 0, .tilemapLeft = 17, .tilemapTop = 1,  .width = 12, .height = 2,  .paletteNum = 15, .baseBlock = 0x0EB},
    [WIN_DESCRIPTION] = {.bg = 0, .tilemapLeft = 16, .tilemapTop = 13, .width = 13, .height = 6,  .paletteNum = 15, .baseBlock = 0x103},
    [WIN_MAIN]        = {.bg = 0, .tilemapLeft = 1,  .tilemapTop = 1,  .width = 10, .height = 8,  .paletteNum = 15, .baseBlock = 0x001}, // never with the others; 0x198-: the message box
};

// Emerald's: disabled categories in grey (colors 4, 5), the red / blue "in use" balls
static const u16 sDecorationMenuPalette[] = INCBIN_U16("graphics/decorations/decoration_menu.gbapal");
static const u8 sInUseBalls_Gfx[] = INCBIN_U8("graphics/decorations/in_use_balls.4bpp"); // red (base), blue (room)

static const struct {
    u8 shape;
    u8 size;
    u8 cameraX;
    u8 cameraY;
} sDecorationMovementInfo[] =
{
    [DECORSHAPE_1x1] = {SPRITE_SHAPE(16x16), SPRITE_SIZE(16x16), 120, 78},
    [DECORSHAPE_2x1] = {SPRITE_SHAPE(32x16), SPRITE_SIZE(32x16), 128, 78},
    [DECORSHAPE_3x1] = {SPRITE_SHAPE(64x32), SPRITE_SIZE(64x32), 144, 86},
    [DECORSHAPE_4x2] = {SPRITE_SHAPE(64x32), SPRITE_SIZE(64x32), 144, 70},
    [DECORSHAPE_2x2] = {SPRITE_SHAPE(32x32), SPRITE_SIZE(32x32), 128, 70},
    [DECORSHAPE_1x2] = {SPRITE_SHAPE(16x32), SPRITE_SIZE(16x32), 120, 70},
    [DECORSHAPE_1x3] = {SPRITE_SHAPE(32x64), SPRITE_SIZE(32x64), 128, 86},
    [DECORSHAPE_2x4] = {SPRITE_SHAPE(32x64), SPRITE_SIZE(32x64), 128, 54},
    [DECORSHAPE_3x3] = {SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), 144, 70},
    [DECORSHAPE_3x2] = {SPRITE_SHAPE(64x32), SPRITE_SIZE(64x32), 144, 70},
};

static const u8 sDecorShapeDimensions[][2] = // width, height
{
    [DECORSHAPE_1x1] = {1, 1},
    [DECORSHAPE_2x1] = {2, 1},
    [DECORSHAPE_3x1] = {3, 1},
    [DECORSHAPE_4x2] = {4, 2},
    [DECORSHAPE_2x2] = {2, 2},
    [DECORSHAPE_1x2] = {1, 2},
    [DECORSHAPE_1x3] = {1, 3},
    [DECORSHAPE_2x4] = {2, 4},
    [DECORSHAPE_3x3] = {3, 3},
    [DECORSHAPE_3x2] = {3, 2},
};

static const union AnimCmd sDecorSelectorAnimCmd0[] =
{
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sDecorSelectorAnimCmds[] = { sDecorSelectorAnimCmd0 };

static const struct SpriteTemplate sDecorationSelectorSpriteTemplate =
{
    TAG_NONE,
    PLACE_DECORATION_SELECTOR_TAG,
    &sDecorSelectorOam,
    sDecorSelectorAnimCmds,
    &sDecorSelectorSpriteFrameImages,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static const u8 sDecorationStandElevations[] =
{
    4, 4, 4, 4,
    0, 3, 3, 0
};

static const u8 sDecorationSlideElevation[] =
{
    4, 4,
    4, 4,
    0, 4,
    3, 0,
};

// Emerald's cursor in Brendan's / May's colors
static const u16 sBrendanPalette[] = INCBIN_U16("graphics/decorations/brendan.gbapal");
static const u16 sMayPalette[] = INCBIN_U16("graphics/decorations/may.gbapal");
static const u8 sDecorationPuttingAwayCursor[] = INCBIN_U8("graphics/decorations/put_away_cursor.4bpp");

static const struct SpritePalette sSpritePal_PuttingAwayCursorBrendan = {sBrendanPalette, PLACE_DECORATION_PLAYER_TAG};
static const struct SpritePalette sSpritePal_PuttingAwayCursorMay = {sMayPalette, PLACE_DECORATION_PLAYER_TAG};

static const struct OamData sPuttingAwayCursorOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const union AnimCmd sPuttingAwayCursorAnimCmd0[] =
{
    ANIMCMD_FRAME(0, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sPuttingAwayCursorAnimCmds[] = { sPuttingAwayCursorAnimCmd0 };

static const struct SpriteFrameImage sPuttingAwayCursorPicTable =
{
    .data = sDecorationPuttingAwayCursor,
    .size = sizeof(sDecorationPuttingAwayCursor),
};

static const struct SpriteTemplate sPuttingAwayCursorSpriteTemplate =
{
    TAG_NONE,
    PLACE_DECORATION_PLAYER_TAG,
    &sPuttingAwayCursorOamData,
    sPuttingAwayCursorAnimCmds,
    &sPuttingAwayCursorPicTable,
    gDummySpriteAffineAnimTable,
    InitializeCameraSprite1
};

// --- where the menu works on

static bool8 InPlayerRoom(void)
{
    return sContext == CONTEXT_PLAYER_ROOM;
}

static u8 *ContextItems(void)
{
    return InPlayerRoom() ? gSaveBlock2Ptr->playerRoomDecorations : gSaveBlock2Ptr->secretBases[0].decorations;
}

static u8 *ContextPos(void)
{
    return InPlayerRoom() ? gSaveBlock2Ptr->playerRoomDecorationPositions : gSaveBlock2Ptr->secretBases[0].decorationPositions;
}

static u8 ContextSize(void)
{
    return InPlayerRoom() ? DECOR_MAX_PLAYERS_HOUSE : DECOR_MAX_SECRET_BASE;
}

static u8 *CurItems(void)
{
    u8 size;

    return GetDecorationInventory(sCategory, &size);
}

static u8 CurCategorySize(void)
{
    u8 size;

    GetDecorationInventory(sCategory, &size);
    return size;
}

static u8 CurDecor(void)
{
    return CurItems()[sCurDecorIndex];
}

// --- windows and yes/no (FRLG has no DoYesNoFuncWithChoice)

static u8 AddDecorWindow(u8 win)
{
    sWindowIds[win] = AddWindow(&sWindowTemplates[win]);
    SetStdWindowBorderStyle(sWindowIds[win], FALSE);
    FillWindowPixelBuffer(sWindowIds[win], PIXEL_FILL(1));
    ScheduleBgCopyTilemapToVram(0);
    return sWindowIds[win];
}

static void RemoveDecorWindow(u8 win)
{
    ClearStdWindowAndFrameToTransparent(sWindowIds[win], FALSE);
    ClearWindowTilemap(sWindowIds[win]);
    RemoveWindow(sWindowIds[win]);
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_HandleYesNo(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case 0:
        sYesFunc(taskId);
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        // fallthrough
    case 1:
        sNoFunc(taskId);
        break;
    }
}

static void DoYesNo(u8 taskId, TaskFunc yesFunc, TaskFunc noFunc)
{
    DisplayYesNoMenuDefaultYes();
    sYesFunc = yesFunc;
    sNoFunc = noFunc;
    gTasks[taskId].func = Task_HandleYesNo;
}

static void ShowMessage(u8 taskId, const u8 *str, TaskFunc callback)
{
    StringExpandPlaceholders(gStringVar4, str);
    DisplayItemMessageOnField(taskId, FONT_NORMAL, gStringVar4, callback);
}

// --- main menu: DECORER / RANGER / JETER / SORTIR

static void PrintMainMenuDescription(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, FONT_NORMAL, sMainMenuDescriptions[sActionsCursorPos], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
}

static void ShowMainMenu(u8 taskId)
{
    u8 i, windowId = AddDecorWindow(WIN_MAIN);

    for (i = 0; i < ARRAY_COUNT(sMainMenuItems); i++)
        AddTextPrinterParameterized(windowId, FONT_NORMAL, sMainMenuItems[i], 8, i * 16 + 2, TEXT_SKIP_DRAW, NULL);
    Menu_InitCursor(windowId, FONT_NORMAL, 0, 2, 16, ARRAY_COUNT(sMainMenuItems), sActionsCursorPos);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    DrawDialogueFrame(0, FALSE);
    PrintMainMenuDescription();
    gTasks[taskId].func = Task_HandleMainMenuInput;
}

static void InitMainMenu(u8 taskId, u8 context)
{
    sContext = context;
    sActionsCursorPos = 0;
    LockPlayerFieldControls();
    ShowMainMenu(taskId);
}

void DoSecretBaseDecorationMenu(u8 taskId)
{
    InitMainMenu(taskId, CONTEXT_SECRET_BASE);
}

void DoPlayerRoomDecorationMenu(u8 taskId, TaskFunc exitFunc)
{
    sExitFunc = exitFunc;
    InitMainMenu(taskId, CONTEXT_PLAYER_ROOM);
}

static void ReturnToMainMenuAfterMessage(u8 taskId)
{
    PrintMainMenuDescription();
    gTasks[taskId].func = Task_HandleMainMenuInput;
}

static bool8 HasDecorations(void)
{
    u8 i;

    for (i = 0; i < DECORCAT_COUNT; i++)
    {
        if (GetNumOwnedDecorationsInCategory(i))
            return TRUE;
    }
    return FALSE;
}

static bool8 HasDecorationsInUse(void)
{
    u8 i;

    for (i = 0; i < ContextSize(); i++)
    {
        if (ContextItems()[i] != DECOR_NONE)
            return TRUE;
    }
    return FALSE;
}

static void OpenCategories(u8 taskId, u8 command)
{
    gTasks[taskId].tMenuCommand = command;
    sCategory = DECORCAT_DESK;
    LoadPalette(sDecorationMenuPalette, BG_PLTT_ID(13), sizeof(sDecorationMenuPalette));
    ClearDialogWindowAndFrame(0, FALSE);
    ShowCategories(taskId);
}

static void Task_HandleMainMenuInput(u8 taskId)
{
    s8 prevPos = Menu_GetCursorPos();
    s8 input;

    if (gPaletteFade.active)
        return;
    input = Menu_ProcessInput();
    switch (input)
    {
    case MENU_NOTHING_CHOSEN:
        sActionsCursorPos = Menu_GetCursorPos();
        if (prevPos != sActionsCursorPos)
            PrintMainMenuDescription();
        break;
    case 0: // DECORER
    case 2: // JETER
        PlaySE(SE_SELECT);
        if (!HasDecorations())
        {
            ShowMessage(taskId, gText_NoDecorations, ReturnToMainMenuAfterMessage);
        }
        else
        {
            RemoveDecorWindow(WIN_MAIN);
            OpenCategories(taskId, input == 0 ? DECOR_MENU_PLACE : DECOR_MENU_TOSS);
        }
        break;
    case 1: // RANGER
        PlaySE(SE_SELECT);
        if (!HasDecorationsInUse())
        {
            ShowMessage(taskId, gText_NoDecorationsInUse, ReturnToMainMenuAfterMessage);
        }
        else
        {
            RemoveDecorWindow(WIN_MAIN);
            ClearDialogWindowAndFrame(0, FALSE);
            FadeScreen(FADE_TO_BLACK, 0);
            gTasks[taskId].tState = 0;
            gTasks[taskId].func = Task_ContinuePuttingAwayDecorations;
        }
        break;
    default: // SORTIR, B
        PlaySE(SE_SELECT);
        RemoveDecorWindow(WIN_MAIN);
        if (sContext == CONTEXT_SECRET_BASE)
        {
            ScriptContext_SetupScript(SecretBase_EventScript_PCCancel);
            DestroyTask(taskId);
        }
        else
        {
            sExitFunc(taskId);
        }
        break;
    }
}

// --- categories

static bool8 IsCategoryDisabled(u8 taskId, u8 category)
{
    // Only dolls and cushions go to the player's room
    return InPlayerRoom() && gTasks[taskId].tMenuCommand == DECOR_MENU_PLACE
        && category != DECORCAT_DOLL && category != DECORCAT_CUSHION;
}

static void ColorMenuItemString(u8 *str, bool8 disabled)
{
    StringCopy(str, gText_Color161Shadow161);
    str[2] = disabled ? 4 : 2;
    str[5] = disabled ? 5 : 3;
}

// "BUREAU     2/10"
static void PrintCategoryLine(u8 windowId, u8 category, u8 x, u8 y, u8 width, bool8 disabled)
{
    u8 size;
    u8 *str;

    GetDecorationInventory(category, &size);
    ColorMenuItemString(gStringVar4, disabled);
    StringAppend(gStringVar4, sCategoryNames[category]);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, x, y, TEXT_SKIP_DRAW, NULL);
    ColorMenuItemString(gStringVar4, disabled);
    str = gStringVar4 + StringLength(gStringVar4);
    str = ConvertIntToDecimalStringN(str, GetNumOwnedDecorationsInCategory(category), STR_CONV_MODE_RIGHT_ALIGN, 2);
    *str++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(str, size, STR_CONV_MODE_RIGHT_ALIGN, 2);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, width - GetStringWidth(FONT_NORMAL, gStringVar4, 0), y, TEXT_SKIP_DRAW, NULL);
}

static void PrintCategories(u8 taskId)
{
    u8 i, windowId = sWindowIds[WIN_CATEGORIES];

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    for (i = 0; i < DECORCAT_COUNT; i++)
        PrintCategoryLine(windowId, i, 8, i * 16 + 2, 104, IsCategoryDisabled(taskId, i));
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gTasks[taskId].tMenuCommand == DECOR_MENU_TRADE ? gOtherText_Exit : gFameCheckerText_Cancel, 8, i * 16 + 2, TEXT_SKIP_DRAW, NULL);
    Menu_InitCursor(windowId, FONT_NORMAL, 0, 2, 16, DECORCAT_COUNT + 1, sCategory);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    gTasks[taskId].func = Task_HandleCategoriesInput;
}

static void ShowCategories(u8 taskId)
{
    AddDecorWindow(WIN_CATEGORIES);
    PrintCategories(taskId);
}

static void ShowCategoriesAfterMessage(u8 taskId)
{
    ClearDialogWindowAndFrame(0, FALSE);
    ShowCategories(taskId);
}

static void ExitCategories(u8 taskId)
{
    RemoveDecorWindow(WIN_CATEGORIES);
    if (gTasks[taskId].tMenuCommand == DECOR_MENU_TRADE)
    {
        gSpecialVar_0x8006 = 0;
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
    else if (sContext == CONTEXT_PC)
    {
        sExitFunc(taskId);
    }
    else
    {
        ShowMainMenu(taskId);
    }
}

static void Task_HandleCategoriesInput(u8 taskId)
{
    s8 input;

    if (gPaletteFade.active)
        return;
    input = Menu_ProcessInput();
    switch (input)
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case MENU_B_PRESSED:
    case DECORCAT_COUNT:
        PlaySE(SE_SELECT);
        ExitCategories(taskId);
        break;
    default:
        PlaySE(SE_SELECT);
        sCategory = input;
        if (GetNumOwnedDecorationsInCategory(sCategory) == 0)
        {
            RemoveDecorWindow(WIN_CATEGORIES);
            ShowMessage(taskId, gText_NoDecorations, ShowCategoriesAfterMessage);
        }
        else
        {
            sScroll = sRow = 0;
            ShowItems(taskId);
        }
        break;
    }
}

// --- items of a category

static bool8 IsIndexIn(const u8 *buffer, u8 count, u8 idx)
{
    u8 i;

    for (i = 0; i < count; i++)
    {
        if (buffer[i] == idx)
            return TRUE;
    }
    return FALSE;
}

// Emerald's IdentifyOwnedDecorationsCurrentlyInUseInternal: the inventory indices (+1) of the current category's
// decorations placed in the base, then in the room (a decoration owned twice and placed once: one of the two)
static void IdentifyOwnedDecorationsCurrentlyInUse(void)
{
    u8 i, j, count;
    u8 *items = CurItems();

    memset(sSecretBaseItemsIndicesBuffer, 0, sizeof(sSecretBaseItemsIndicesBuffer));
    memset(sPlayerRoomItemsIndicesBuffer, 0, sizeof(sPlayerRoomItemsIndicesBuffer));
    for (i = 0, count = 0; i < DECOR_MAX_SECRET_BASE; i++)
    {
        if (gSaveBlock2Ptr->secretBases[0].decorations[i] == DECOR_NONE)
            continue;
        for (j = 0; j < CurCategorySize(); j++)
        {
            if (items[j] == gSaveBlock2Ptr->secretBases[0].decorations[i]
             && !IsIndexIn(sSecretBaseItemsIndicesBuffer, count, j + 1))
            {
                sSecretBaseItemsIndicesBuffer[count++] = j + 1;
                break;
            }
        }
    }
    for (i = 0, count = 0; i < DECOR_MAX_PLAYERS_HOUSE; i++)
    {
        if (gSaveBlock2Ptr->playerRoomDecorations[i] == DECOR_NONE)
            continue;
        for (j = 0; j < CurCategorySize(); j++)
        {
            if (items[j] == gSaveBlock2Ptr->playerRoomDecorations[i]
             && !IsIndexIn(sSecretBaseItemsIndicesBuffer, DECOR_MAX_SECRET_BASE, j + 1)
             && !IsIndexIn(sPlayerRoomItemsIndicesBuffer, count, j + 1))
            {
                sPlayerRoomItemsIndicesBuffer[count++] = j + 1;
                break;
            }
        }
    }
}

static bool8 IsSelectedDecorInThePC(void)
{
    return !IsIndexIn(sSecretBaseItemsIndicesBuffer, DECOR_MAX_SECRET_BASE, sCurDecorIndex + 1)
        && !IsIndexIn(sPlayerRoomItemsIndicesBuffer, DECOR_MAX_PLAYERS_HOUSE, sCurDecorIndex + 1);
}

static void ListCursorMoved(s32 index, bool8 onInit, struct ListMenu *list)
{
    u8 windowId = sWindowIds[WIN_DESCRIPTION];

    if (onInit != TRUE)
        PlaySE(SE_SELECT);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, FONT_NORMAL, (u32)index < sNumOwned ? gDecorations[CurItems()[index]].description : gText_GoBackPrevMenu, 0, 1, 0, NULL);
}

static void PrintDecorationInUse(u8 windowId, u32 index, u8 y)
{
    if (index == LIST_CANCEL)
        return;
    if (IsIndexIn(sSecretBaseItemsIndicesBuffer, DECOR_MAX_SECRET_BASE, index + 1))
        BlitBitmapRectToWindow(windowId, sInUseBalls_Gfx, 0, 0, 16, 8, 92, y + 2, 8, 8);
    else if (IsIndexIn(sPlayerRoomItemsIndicesBuffer, DECOR_MAX_PLAYERS_HOUSE, index + 1))
        BlitBitmapRectToWindow(windowId, sInUseBalls_Gfx, 8, 0, 16, 8, 92, y + 2, 8, 8);
}

static void ShowItems(u8 taskId)
{
    u8 i;
    u8 *items = CurItems();
    bool8 disabled = IsCategoryDisabled(taskId, sCategory);

    IdentifyOwnedDecorationsCurrentlyInUse();
    sNumOwned = GetNumOwnedDecorationsInCategory(sCategory);
    for (i = 0; i < sNumOwned; i++)
    {
        sListItems[i].label = gDecorations[items[i]].name;
        sListItems[i].index = i;
    }
    sListItems[i].label = gFameCheckerText_Cancel;
    sListItems[i].index = LIST_CANCEL;

    AddDecorWindow(WIN_SUMMARY);
    PrintCategoryLine(sWindowIds[WIN_SUMMARY], sCategory, 0, 1, 96, FALSE);
    CopyWindowToVram(sWindowIds[WIN_SUMMARY], COPYWIN_FULL);
    AddDecorWindow(WIN_DESCRIPTION);

    gMultiuseListMenuTemplate = (struct ListMenuTemplate){
        .items = sListItems,
        .moveCursorFunc = ListCursorMoved,
        .itemPrintFunc = PrintDecorationInUse,
        .totalItems = sNumOwned + 1,
        .maxShowed = min(sNumOwned + 1, MAX_SHOWN),
        .windowId = sWindowIds[WIN_CATEGORIES],
        .header_X = 0,
        .item_X = 8,
        .cursor_X = 0,
        .upText_Y = 2,
        .cursorPal = disabled ? 4 : 2,
        .fillValue = 1,
        .cursorShadowPal = disabled ? 5 : 3,
        .lettersSpacing = 0,
        .itemVerticalPadding = 2,
        .scrollMultiple = 0,
        .fontId = FONT_SMALL, // Emerald's FONT_NARROW: the longest names reach the "in use" ball
        .cursorKind = 0,
    };
    if (sScroll + sRow > sNumOwned) // the last one was tossed
        sScroll = sRow = 0;
    gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, sScroll, sRow);
    sScrollArrowsTaskId = TASK_NONE;
    if (sNumOwned + 1 > MAX_SHOWN)
        sScrollArrowsTaskId = AddScrollIndicatorArrowPairParameterized(2, 0x3C, 0x0C, 0x94, sNumOwned + 1 - MAX_SHOWN, 110, 110, &sScroll);
    gTasks[taskId].func = Task_HandleItemsInput;
}

static void RemoveItems(u8 taskId)
{
    if (sScrollArrowsTaskId != TASK_NONE)
        RemoveScrollIndicatorArrowPair(sScrollArrowsTaskId);
    DestroyListMenuTask(gTasks[taskId].tListTaskId, &sScroll, &sRow);
    RemoveDecorWindow(WIN_SUMMARY);
    RemoveDecorWindow(WIN_DESCRIPTION);
}

static void ShowItemsAgain(u8 taskId)
{
    ClearDialogWindowAndFrame(0, FALSE);
    AddDecorWindow(WIN_CATEGORIES);
    ShowItems(taskId);
}

static void Task_ShowItemsAfterMessage(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
        ShowItemsAgain(taskId);
}

static void TossDecoration(u8 taskId)
{
    DecorationRemove(CurDecor());
    ShowMessage(taskId, gText_DecorationThrownAway, Task_ShowItemsAfterMessage);
}

static void TossDecorationPrompt(u8 taskId)
{
    DoYesNo(taskId, TossDecoration, ShowItemsAgain);
}

static void AttemptToss(u8 taskId)
{
    if (IsSelectedDecorInThePC())
    {
        StringCopy(gStringVar1, gDecorations[CurDecor()].name);
        ShowMessage(taskId, gText_DecorationWillBeDiscarded, TossDecorationPrompt);
    }
    else
    {
        ShowMessage(taskId, gText_CantThrowAwayInUse, Task_ShowItemsAfterMessage);
    }
}

static bool8 HasDecorationSpace(void)
{
    u8 i;

    for (i = 0; i < ContextSize(); i++)
    {
        if (ContextItems()[i] == DECOR_NONE)
            return TRUE;
    }
    return FALSE;
}

static void AttemptPlace(u8 taskId)
{
    if (IsCategoryDisabled(taskId, sCategory))
    {
        ShowMessage(taskId, gText_CantPlaceInRoom, Task_ShowItemsAfterMessage);
    }
    else if (!IsSelectedDecorInThePC())
    {
        ShowMessage(taskId, gText_InUseAlready, Task_ShowItemsAfterMessage);
    }
    else if (!HasDecorationSpace())
    {
        ConvertIntToDecimalStringN(gStringVar1, ContextSize(), STR_CONV_MODE_RIGHT_ALIGN, 2);
        ShowMessage(taskId, InPlayerRoom() ? gText_NoMoreDecorations2 : gText_NoMoreDecorations, Task_ShowItemsAfterMessage);
    }
    else
    {
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_PlaceDecoration;
    }
}

static void Task_HandleItemsInput(u8 taskId)
{
    s32 input;

    if (gPaletteFade.active)
        return;
    input = ListMenu_ProcessInput(gTasks[taskId].tListTaskId);
    ListMenuGetScrollAndRow(gTasks[taskId].tListTaskId, &sScroll, &sRow);
    switch (input)
    {
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        PlaySE(SE_SELECT);
        RemoveItems(taskId);
        PrintCategories(taskId);
        break;
    default:
        PlaySE(SE_SELECT);
        sCurDecorIndex = input;
        RemoveItems(taskId);
        RemoveDecorWindow(WIN_CATEGORIES);
        switch (gTasks[taskId].tMenuCommand)
        {
        case DECOR_MENU_TRADE:
            // Emerald's DecorationItemsMenuAction_Trade (trader.c): 0xFFFF = placed, can't be traded
            if (IsSelectedDecorInThePC())
            {
                gSpecialVar_0x8006 = CurDecor();
                StringCopy(gStringVar3, gDecorations[gSpecialVar_0x8004].name);
                StringCopy(gStringVar2, gDecorations[gSpecialVar_0x8006].name);
            }
            else
            {
                gSpecialVar_0x8006 = 0xFFFF;
            }
            DestroyTask(taskId);
            ScriptContext_Enable();
            break;
        case DECOR_MENU_TOSS:
            AttemptToss(taskId);
            break;
        default:
            AttemptPlace(taskId);
            break;
        }
        break;
    }
}

// The other PCs: JETER only, back to exitFunc when done
void DoDecorationPCMenu(u8 taskId, TaskFunc exitFunc)
{
    sExitFunc = exitFunc;
    sContext = CONTEXT_PC;
    if (!HasDecorations())
    {
        DisplayItemMessageOnField(taskId, FONT_NORMAL, gText_NoDecorations, exitFunc);
        return;
    }
    OpenCategories(taskId, DECOR_MENU_TOSS);
}

// The Mauville old man's trader: gSpecialVar_0x8006 = the decoration offered, 0 if none
void ShowDecorationCategoriesWindow(u8 taskId)
{
    sContext = CONTEXT_PC;
    OpenCategories(taskId, DECOR_MENU_TRADE);
}

void CopyDecorationCategoryName(u8 *dest, u8 category)
{
    StringCopy(dest, sCategoryNames[category]);
}

// --- drawing the decorations on the map

static u32 GetDecorationAttributes(u16 tile)
{
    return gMapHeader.mapLayout->secondaryTileset->metatileAttributes[tile];
}

static u16 GetDecorationElevation(u8 decoration, u8 tileIndex)
{
    switch (decoration)
    {
    case DECOR_STAND:
        return sDecorationStandElevations[tileIndex] << MAPGRID_ELEVATION_SHIFT;
    case DECOR_SLIDE:
        return sDecorationSlideElevation[tileIndex] << MAPGRID_ELEVATION_SHIFT;
    default:
        return 0xFFFF;
    }
}

static void ShowDecorationOnMap_(u16 mapX, u16 mapY, u8 decWidth, u8 decHeight, u16 decoration)
{
    u16 i, j;
    s16 x, y;
    u32 attributes;
    u16 impassableFlag, overlapsWall, elevation, tile;

    for (j = 0; j < decHeight; j++)
    {
        y = mapY - decHeight + 1 + j;
        for (i = 0; i < decWidth; i++)
        {
            x = mapX + i;
            tile = gDecorations[decoration].tiles[j * decWidth + i];
            attributes = GetDecorationAttributes(tile);
            if (ExtractMetatileAttribute(attributes, METATILE_ATTRIBUTE_BEHAVIOR) == MB_SECRET_BASE_IMPASSABLE
             || (gDecorations[decoration].permission != DECORPERM_PASS_FLOOR
              && ExtractMetatileAttribute(attributes, METATILE_ATTRIBUTE_LAYER_TYPE) != METATILE_LAYER_TYPE_NORMAL))
                impassableFlag = MAPGRID_IMPASSABLE;
            else
                impassableFlag = 0;

            // Choose the metatile that has the wall background instead of the floor if overlapping a wall.
            if (gDecorations[decoration].permission != DECORPERM_NA_WALL && MapGridGetMetatileBehaviorAt(x, y) == MB_SECRET_BASE_NORTH_WALL)
                overlapsWall = 1;
            else
                overlapsWall = 0;

            elevation = GetDecorationElevation(gDecorations[decoration].id, j * decWidth + i);
            if (elevation != 0xFFFF)
                MapGridSetMetatileEntryAt(x, y, (tile + (NUM_METATILES_IN_PRIMARY | overlapsWall)) | impassableFlag | elevation);
            else
                MapGridSetMetatileIdAt(x, y, (tile + (NUM_METATILES_IN_PRIMARY | overlapsWall)) | impassableFlag);
        }
    }
}

void ShowDecorationOnMap(u16 mapX, u16 mapY, u16 decoration)
{
    const u8 *dim = sDecorShapeDimensions[gDecorations[decoration].shape];

    ShowDecorationOnMap_(mapX, mapY, dim[0], dim[1], decoration);
}

// SecretBase_EventScript_SetDecoration: the doll or cushion just placed gets the first free decoration object
void SetDecoration(void)
{
    u8 i, j;

    for (i = 0; i < NUM_DECORATION_FLAGS; i++)
    {
        if (FlagGet(FLAG_DECORATION_1 + i) == TRUE)
        {
            FlagClear(FLAG_DECORATION_1 + i);
            for (j = 0; j < gMapHeader.events->objectEventCount; j++)
            {
                if (gMapHeader.events->objectEvents[j].flagId == FLAG_DECORATION_1 + i)
                    break;
            }
            if (j == gMapHeader.events->objectEventCount) // the room has 12 objects, the bases 14
                return;

            VarSet(VAR_OBJ_GFX_ID_0 + (ObjTemplateGfxId(&gMapHeader.events->objectEvents[j]) - OBJ_EVENT_GFX_VAR_0),
                   gDecorations[sPlacedDecor].tiles[0]);
            gSpecialVar_0x8005 = gMapHeader.events->objectEvents[j].localId;
            gSpecialVar_0x8006 = sCurDecorMapX;
            gSpecialVar_0x8007 = sCurDecorMapY;
            TrySpawnObjectEvent(gSpecialVar_0x8005, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            TryMoveObjectEventToMapCoords(gSpecialVar_0x8005, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
            TryOverrideObjectEventTemplateCoords(gSpecialVar_0x8005, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            break;
        }
    }
}

// --- placing

static void SetInitialPositions(u8 taskId)
{
    gTasks[taskId].tInitialX = gSaveBlock1Ptr->pos.x;
    gTasks[taskId].tInitialY = gSaveBlock1Ptr->pos.y;
    PlayerGetDestCoords(&gTasks[taskId].tCursorX, &gTasks[taskId].tCursorY);
}

static void WarpToInitialPosition(u8 taskId)
{
    DrawWholeMapView();
    SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE, gTasks[taskId].tInitialX, gTasks[taskId].tInitialY);
    WarpIntoMap();
}

static u16 GetPlayerAvatarGfxId(void)
{
    return gSaveBlock2Ptr->playerGender == MALE ? OBJ_EVENT_GFX_RED_NORMAL : OBJ_EVENT_GFX_GREEN_NORMAL;
}

static void ConfigureCameraObjectForPlacingDecoration(u8 decor)
{
    sDecor_CameraSpriteObjectIdx1 = gSprites[gFieldCamera.spriteId].data[0];
    gFieldCamera.spriteId = CreateDecorationSelectorSprite(decor);
    gSprites[gFieldCamera.spriteId].oam.priority = 1;
    gSprites[gFieldCamera.spriteId].callback = InitializePuttingAwayCursorSprite;
    gSprites[gFieldCamera.spriteId].x = sDecorationMovementInfo[gDecorations[decor].shape].cameraX;
    gSprites[gFieldCamera.spriteId].y = sDecorationMovementInfo[gDecorations[decor].shape].cameraY;
}

// Emerald draws Brendan / May "decorating": Red / Leaf facing down here
static void SetUpPlacingDecorationPlayerAvatar(u8 taskId, u8 decor)
{
    u8 shape = gDecorations[decor].shape;
    u8 x = 16 * (u8)gTasks[taskId].tDecorWidth + sDecorationMovementInfo[shape].cameraX - 8 * ((u8)gTasks[taskId].tDecorWidth - 1);

    if (shape == DECORSHAPE_3x1 || shape == DECORSHAPE_3x3 || shape == DECORSHAPE_3x2)
        x -= 8;
    sDecor_CameraSpriteObjectIdx2 = CreateObjectGraphicsSprite(GetPlayerAvatarGfxId(), SpriteCallbackDummy, x, 72, 0);
    gSprites[sDecor_CameraSpriteObjectIdx2].oam.priority = 1;
    DestroySprite(&gSprites[sDecor_CameraSpriteObjectIdx1]);
    sDecor_CameraSpriteObjectIdx1 = gFieldCamera.spriteId;
}

static void SetUpDecorationShape(u8 taskId)
{
    u8 shape = gDecorations[CurDecor()].shape;

    gTasks[taskId].tDecorWidth = sDecorShapeDimensions[shape][0];
    gTasks[taskId].tDecorHeight = sDecorShapeDimensions[shape][1];
    if (shape == DECORSHAPE_1x3)
        gTasks[taskId].tCursorY++;
}

static void Task_PlaceDecoration(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!gPaletteFade.active)
        {
            SetInitialPositions(taskId);
            gTasks[taskId].tState = 1;
        }
        break;
    case 1:
        gPaletteFade.bufferTransferDisabled = TRUE;
        ConfigureCameraObjectForPlacingDecoration(CurDecor());
        SetUpDecorationShape(taskId);
        SetUpPlacingDecorationPlayerAvatar(taskId, CurDecor());
        FadeInFromBlack();
        gPaletteFade.bufferTransferDisabled = FALSE;
        gTasks[taskId].tState = 2;
        break;
    case 2:
        if (IsWeatherNotFadingIn() == TRUE)
        {
            gTasks[taskId].tItemsMenuCommand = DECOR_ITEMS_MENU_PLACE;
            ContinueDecorating(taskId);
        }
        break;
    }
}

static bool8 IsFloorOrBoardAndHole(u8 behaviorAt, const struct Decoration *decoration)
{
    if (behaviorAt == MB_SECRET_BASE_TRAINER_SPOT)
        return FALSE;
    if (decoration->id == DECOR_SOLID_BOARD && behaviorAt == MB_SECRET_BASE_HOLE)
        return TRUE;
    return behaviorAt == MB_NORMAL;
}

// Can't place a decoration where the player was standing when they interacted with the PC
static bool8 IsntInitialPosition(u8 taskId, s16 x, s16 y, u16 layerType)
{
    return !(x == gTasks[taskId].tInitialX + MAP_OFFSET && y == gTasks[taskId].tInitialY + MAP_OFFSET
          && layerType != METATILE_LAYER_TYPE_NORMAL);
}

static u16 GetLayerType(u16 tile)
{
    return ExtractMetatileAttribute(GetDecorationAttributes(tile), METATILE_ATTRIBUTE_LAYER_TYPE);
}

static bool8 IsNoObjectAt(s16 x, s16 y)
{
    u8 objectEventId = GetObjectEventIdByPosition(x, y, 0);

    return objectEventId == 0 || objectEventId == OBJECT_EVENTS_COUNT;
}

static bool8 CanPlaceDecoration(u8 taskId, const struct Decoration *decoration)
{
    u8 i, j, behaviorAt;
    u16 layerType;
    u8 height = gTasks[taskId].tDecorHeight;
    u8 width = gTasks[taskId].tDecorWidth;
    s16 curX, curY;

    switch (decoration->permission)
    {
    case DECORPERM_SOLID_FLOOR:
    case DECORPERM_PASS_FLOOR:
        for (i = 0; i < height; i++)
        {
            curY = gTasks[taskId].tCursorY - i;
            for (j = 0; j < width; j++)
            {
                curX = gTasks[taskId].tCursorX + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                layerType = GetLayerType(decoration->tiles[(height - 1 - i) * width + j]);
                if (!IsFloorOrBoardAndHole(behaviorAt, decoration))
                    return FALSE;
                if (!IsntInitialPosition(taskId, curX, curY, layerType))
                    return FALSE;
                if (!IsNoObjectAt(curX, curY))
                    return FALSE;
            }
        }
        break;
    case DECORPERM_BEHIND_FLOOR:
        for (i = 0; i < height - 1; i++)
        {
            curY = gTasks[taskId].tCursorY - i;
            for (j = 0; j < width; j++)
            {
                curX = gTasks[taskId].tCursorX + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                layerType = GetLayerType(decoration->tiles[(height - 1 - i) * width + j]);
                if (behaviorAt != MB_NORMAL && !(behaviorAt == MB_SECRET_BASE_TRAINER_SPOT && layerType == METATILE_LAYER_TYPE_NORMAL))
                    return FALSE;
                if (!IsntInitialPosition(taskId, curX, curY, layerType))
                    return FALSE;
                if (GetObjectEventIdByPosition(curX, curY, 0) != OBJECT_EVENTS_COUNT)
                    return FALSE;
            }
        }
        curY = gTasks[taskId].tCursorY - height + 1;
        for (j = 0; j < width; j++)
        {
            curX = gTasks[taskId].tCursorX + j;
            behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
            layerType = GetLayerType(decoration->tiles[j]);
            if (behaviorAt != MB_NORMAL && behaviorAt != MB_SECRET_BASE_NORTH_WALL)
                return FALSE;
            if (!IsntInitialPosition(taskId, curX, curY, layerType))
                return FALSE;
            if (!IsNoObjectAt(curX, curY))
                return FALSE;
        }
        break;
    case DECORPERM_NA_WALL:
        for (i = 0; i < height; i++)
        {
            curY = gTasks[taskId].tCursorY - i;
            for (j = 0; j < width; j++)
            {
                curX = gTasks[taskId].tCursorX + j;
                if (MapGridGetMetatileBehaviorAt(curX, curY) != MB_SECRET_BASE_NORTH_WALL)
                    return FALSE;
                if (MapGridGetMetatileIdAt(curX, curY + 1) == METATILE_HoennSecretBase_SandOrnament_BrokenBase)
                    return FALSE;
            }
        }
        break;
    case DECORPERM_SPRITE:
        curY = gTasks[taskId].tCursorY;
        for (j = 0; j < width; j++)
        {
            curX = gTasks[taskId].tCursorX + j;
            behaviorAt = GetDecorationSpotBehaviorAt(curX, curY);
            if (decoration->shape == DECORSHAPE_1x2)
            {
                if (behaviorAt != MB_HOLDS_LARGE_DECORATION)
                    return FALSE;
            }
            else if (behaviorAt != MB_HOLDS_SMALL_DECORATION && behaviorAt != MB_HOLDS_LARGE_DECORATION)
            {
                return FALSE;
            }
            if (GetObjectEventIdByPosition(curX, curY, 0) != OBJECT_EVENTS_COUNT)
                return FALSE;
        }
        break;
    }
    return TRUE;
}

static void PlaceDecoration_(u8 taskId)
{
    u8 i;

    for (i = 0; i < ContextSize(); i++)
    {
        if (ContextItems()[i] == DECOR_NONE)
        {
            ContextItems()[i] = CurDecor();
            ContextPos()[i] = ((gTasks[taskId].tCursorX - MAP_OFFSET) << 4) + (gTasks[taskId].tCursorY - MAP_OFFSET);
            break;
        }
    }
}

static void PlaceDecoration(u8 taskId)
{
    ClearDialogWindowAndFrame(0, FALSE);
    PlaceDecoration_(taskId);
    if (gDecorations[CurDecor()].permission != DECORPERM_SPRITE)
    {
        ShowDecorationOnMap(gTasks[taskId].tCursorX, gTasks[taskId].tCursorY, CurDecor());
    }
    else
    {
        sCurDecorMapX = gTasks[taskId].tCursorX - MAP_OFFSET;
        sCurDecorMapY = gTasks[taskId].tCursorY - MAP_OFFSET;
        sPlacedDecor = CurDecor();
        ScriptContext_SetupScript(SecretBase_EventScript_SetDecoration);
    }
    gSprites[sDecor_CameraSpriteObjectIdx1].y += 2;
    CancelDecorating_(taskId);
}

static void PlaceDecorationPrompt(u8 taskId)
{
    DoYesNo(taskId, PlaceDecoration, ContinueDecorating);
}

static void CantPlaceDecorationPrompt(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        ContinueDecorating(taskId);
}

static void ResetCursorMovement(void)
{
    sDecorationLastDirectionMoved = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].data[2] = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].data[3] = 0;
}

static void AttemptPlaceDecoration(u8 taskId)
{
    gTasks[taskId].tButton = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].data[7] = 1;
    gSprites[sDecor_CameraSpriteObjectIdx2].data[7] = 1;
    ResetCursorMovement();
    if (CanPlaceDecoration(taskId, &gDecorations[CurDecor()]) == TRUE)
    {
        ShowMessage(taskId, gText_PlaceItHere, PlaceDecorationPrompt);
    }
    else
    {
        PlaySE(SE_FAILURE);
        ShowMessage(taskId, gText_CantBePlacedHere, CantPlaceDecorationPrompt);
    }
}

static void CancelDecorating(u8 taskId)
{
    ClearDialogWindowAndFrame(0, FALSE);
    CancelDecorating_(taskId);
}

static void CancelDecoratingPrompt(u8 taskId)
{
    DoYesNo(taskId, CancelDecorating, ContinueDecorating);
}

static void AttemptCancelPlaceDecoration(u8 taskId)
{
    gTasks[taskId].tButton = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].data[7] = 1;
    gSprites[sDecor_CameraSpriteObjectIdx2].data[7] = 1;
    ResetCursorMovement();
    ShowMessage(taskId, gText_CancelDecorating, CancelDecoratingPrompt);
}

// Back to the field: the decoration objects are drawn again, then the items menu
static void Task_InitDecorationItemsWindow(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        HideSecretBaseDecorationSprites();
        gTasks[taskId].tState++;
        break;
    case 1:
        ScriptContext_SetupScript(SecretBase_EventScript_InitDecorations);
        gTasks[taskId].tState++;
        break;
    case 2:
        LockPlayerFieldControls();
        gTasks[taskId].tState++;
        break;
    case 3:
        if (IsWeatherNotFadingIn() == TRUE)
            gTasks[taskId].func = Task_HandleItemsInput;
        break;
    }
}

static void FieldCB_InitDecorationItemsWindow(void)
{
    u8 taskId;

    LockPlayerFieldControls();
    FadeInFromBlack();
    taskId = CreateTask(Task_InitDecorationItemsWindow, 8);
    gTasks[taskId].tMenuCommand = DECOR_MENU_PLACE;
    LoadPalette(sDecorationMenuPalette, BG_PLTT_ID(13), sizeof(sDecorationMenuPalette));
    AddDecorWindow(WIN_CATEGORIES);
    ShowItems(taskId);
    gTasks[taskId].func = Task_InitDecorationItemsWindow;
    gTasks[taskId].tState = 0;
}

static void Task_ReturnFromDecorating(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        LockPlayerFieldControls();
        if (!gPaletteFade.active)
        {
            WarpToInitialPosition(taskId);
            gTasks[taskId].tState = 1;
        }
        break;
    case 1:
        FreeSpritePaletteByTag(PLACE_DECORATION_PLAYER_TAG);
        FreeSpritePaletteByTag(PLACE_DECORATION_SELECTOR_TAG);
        if (sPlaceDecorationGraphicsDataBuffer != NULL)
        {
            Free(sPlaceDecorationGraphicsDataBuffer);
            sPlaceDecorationGraphicsDataBuffer = NULL;
        }
        gFieldCallback = FieldCB_InitDecorationItemsWindow;
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
        break;
    }
}

static void CancelDecorating_(u8 taskId)
{
    FadeScreen(FADE_TO_BLACK, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].func = Task_ReturnFromDecorating;
}

static bool8 ApplyCursorMovement_IsInvalid(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (sDecorationLastDirectionMoved == DIR_SOUTH && tCursorY - tDecorHeight - 6 < 0)
    {
        tCursorY++;
        return FALSE;
    }
    if (sDecorationLastDirectionMoved == DIR_NORTH && tCursorY - 7 >= gMapHeader.mapLayout->height)
    {
        tCursorY--;
        return FALSE;
    }
    if (sDecorationLastDirectionMoved == DIR_WEST && tCursorX - 7 < 0)
    {
        tCursorX++;
        return FALSE;
    }
    if (sDecorationLastDirectionMoved == DIR_EAST && tCursorX + tDecorWidth - 8 >= gMapHeader.mapLayout->width)
    {
        tCursorX--;
        return FALSE;
    }
    return TRUE;
}

static bool8 IsHoldingDirection(void)
{
    u16 heldKeys = JOY_HELD(DPAD_ANY);

    return heldKeys == DPAD_UP || heldKeys == DPAD_DOWN || heldKeys == DPAD_LEFT || heldKeys == DPAD_RIGHT;
}

// The camera follows the selector sprite (data[2], data[3]: its speed): 8 frames of 2 pixels per metatile
static void Task_SelectLocation(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gSprites[sDecor_CameraSpriteObjectIdx1].data[4])
    {
        if (tButton == A_BUTTON)
        {
            if (tItemsMenuCommand == DECOR_ITEMS_MENU_PLACE)
                AttemptPlaceDecoration(taskId);
            else
                AttemptPutAwayDecoration(taskId);
            return;
        }
        if (tButton == B_BUTTON)
        {
            if (tItemsMenuCommand == DECOR_ITEMS_MENU_PLACE)
                AttemptCancelPlaceDecoration(taskId);
            else
                AttemptCancelPutAwayDecoration(taskId);
            return;
        }
        if ((JOY_HELD(DPAD_ANY)) == DPAD_UP)
        {
            sDecorationLastDirectionMoved = DIR_SOUTH;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[2] =  0;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[3] = -2;
            tCursorY--;
        }
        if ((JOY_HELD(DPAD_ANY)) == DPAD_DOWN)
        {
            sDecorationLastDirectionMoved = DIR_NORTH;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[2] =  0;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[3] =  2;
            tCursorY++;
        }
        if ((JOY_HELD(DPAD_ANY)) == DPAD_LEFT)
        {
            sDecorationLastDirectionMoved = DIR_WEST;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[2] = -2;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[3] =  0;
            tCursorX--;
        }
        if ((JOY_HELD(DPAD_ANY)) == DPAD_RIGHT)
        {
            sDecorationLastDirectionMoved = DIR_EAST;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[2] =  2;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[3] =  0;
            tCursorX++;
        }
        if (!IsHoldingDirection() || !ApplyCursorMovement_IsInvalid(taskId))
            ResetCursorMovement();
    }

    if (sDecorationLastDirectionMoved)
    {
        gSprites[sDecor_CameraSpriteObjectIdx1].data[4]++;
        gSprites[sDecor_CameraSpriteObjectIdx1].data[4] &= 7;
    }

    if (!tButton)
    {
        if (JOY_NEW(A_BUTTON))
            tButton = A_BUTTON;
        if (JOY_NEW(B_BUTTON))
            tButton = B_BUTTON;
    }
}

static void ContinueDecorating(u8 taskId)
{
    ClearDialogWindowAndFrame(0, TRUE);
    gSprites[sDecor_CameraSpriteObjectIdx1].data[7] = 0;
    gTasks[taskId].tButton = 0;
    gTasks[taskId].func = Task_SelectLocation;
}

// --- the selector: the decoration drawn as a sprite with its metatiles' tiles (Emerald copies them from the secret
// base primary tileset's ROM data, compressed here: they are read from the map's tiles in VRAM instead, and the
// palette from the map's palettes)

static void CopyTile(u8 *dest, u16 tile)
{
    u8 ALIGNED(4) buffer[TILE_SIZE_4BPP];
    u16 mode, i;
    const u8 *mapTiles = (const u8 *)BG_CHAR_ADDR(GetBgAttribute(2, BG_ATTR_CHARBASEINDEX));

    mode = tile >> 10;
    if (tile != 0)
        tile &= 0x03FF;

    CpuCopy16(&mapTiles[tile * TILE_SIZE_4BPP], buffer, TILE_SIZE_4BPP);
    switch (mode)
    {
    case 0:
        CpuFastCopy(buffer, dest, TILE_SIZE_4BPP);
        break;
    case BG_TILE_H_FLIP(0) >> 10:
        for (i = 0; i < 8; i++)
        {
            dest[4 * i + 0] = (buffer[4 * (i + 1) - 1] >> 4) + ((buffer[4 * (i + 1) - 1] & 0x0F) << 4);
            dest[4 * i + 1] = (buffer[4 * (i + 1) - 2] >> 4) + ((buffer[4 * (i + 1) - 2] & 0x0F) << 4);
            dest[4 * i + 2] = (buffer[4 * (i + 1) - 3] >> 4) + ((buffer[4 * (i + 1) - 3] & 0x0F) << 4);
            dest[4 * i + 3] = (buffer[4 * (i + 1) - 4] >> 4) + ((buffer[4 * (i + 1) - 4] & 0x0F) << 4);
        }
        break;
    case BG_TILE_V_FLIP(0) >> 10:
        for (i = 0; i < 8; i++)
        {
            dest[4 * i + 0] = buffer[4 * (7 - i) + 0];
            dest[4 * i + 1] = buffer[4 * (7 - i) + 1];
            dest[4 * i + 2] = buffer[4 * (7 - i) + 2];
            dest[4 * i + 3] = buffer[4 * (7 - i) + 3];
        }
        break;
    case BG_TILE_H_FLIP(BG_TILE_V_FLIP(0)) >> 10:
        for (i = 0; i < 32; i++)
            dest[i] = (buffer[31 - i] >> 4) + ((buffer[31 - i] & 0x0F) << 4);
        break;
    }
}

static u16 GetMetatileTile(u16 tile)
{
    return gMapHeader.mapLayout->secondaryTileset->metatiles[tile];
}

static void SetDecorSelectionMetatiles(struct PlaceDecorationGraphicsDataBuffer *data)
{
    u8 i, shape = data->decoration->shape;

    for (i = 0; i < sDecorTilemaps[shape].size; i++)
        data->tiles[sDecorTilemaps[shape].tiles[i]] = GetMetatileTile(data->decoration->tiles[sDecorTilemaps[shape].y[i]] * NUM_TILES_PER_METATILE + sDecorTilemaps[shape].x[i]) & 0xFFF;
}

static void SetDecorSelectionBoxOamAttributes(u8 decorShape)
{
    sDecorSelectorOam.y = 0;
    sDecorSelectorOam.affineMode = ST_OAM_AFFINE_OFF;
    sDecorSelectorOam.objMode = ST_OAM_OBJ_NORMAL;
    sDecorSelectorOam.mosaic = FALSE;
    sDecorSelectorOam.bpp = ST_OAM_4BPP;
    sDecorSelectorOam.shape = sDecorationMovementInfo[decorShape].shape;
    sDecorSelectorOam.x = 0;
    sDecorSelectorOam.matrixNum = 0;
    sDecorSelectorOam.size = sDecorationMovementInfo[decorShape].size;
    sDecorSelectorOam.tileNum = 0;
    sDecorSelectorOam.priority = 0;
    sDecorSelectorOam.paletteNum = 0;
}

static u8 CreateDecorationSelectorSprite(u8 decor)
{
    u16 i;
    struct PlaceDecorationGraphicsDataBuffer *data;
    struct SpritePalette palette;

    if (gDecorations[decor].permission == DECORPERM_SPRITE)
        return CreateObjectGraphicsSprite(gDecorations[decor].tiles[0], SpriteCallbackDummy, 0, 0, 1);

    data = sPlaceDecorationGraphicsDataBuffer = AllocZeroed(sizeof(*sPlaceDecorationGraphicsDataBuffer));
    data->decoration = &gDecorations[decor];
    sDecorSelectorSpriteFrameImages.data = data->image;
    sDecorSelectorSpriteFrameImages.size = sizeof(data->image);
    FreeSpritePaletteByTag(PLACE_DECORATION_SELECTOR_TAG);
    SetDecorSelectionMetatiles(data);
    SetDecorSelectionBoxOamAttributes(data->decoration->shape);
    for (i = 0; i < 64; i++)
        CopyTile(&data->image[i * TILE_SIZE_4BPP], data->tiles[i]);
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(GetMetatileTile(data->decoration->tiles[0] * NUM_TILES_PER_METATILE + 7) >> 12)], data->palette, PLTT_SIZE_4BPP);
    palette.data = data->palette;
    palette.tag = PLACE_DECORATION_SELECTOR_TAG;
    LoadSpritePalette(&palette);
    return CreateSprite(&sDecorationSelectorSpriteTemplate, 0, 0, 0);
}

static void InitializePuttingAwayCursorSprite2(struct Sprite *sprite)
{
    if (sprite->data[7] == 0)
    {
        sprite->invisible = sprite->data[6] >= 15;
        sprite->data[6]++;
        sprite->data[6] &= 0x1F;
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

static void InitializePuttingAwayCursorSprite(struct Sprite *sprite)
{
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
    sprite->data[6] = 0;
    sprite->data[7] = 0;
    sprite->callback = InitializePuttingAwayCursorSprite2;
}

static void InitializeCameraSprite1(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->data[0] &= 0x1F;
    sprite->invisible = sprite->data[0] > 15;
}

// --- putting away

static void ClearDecorationContextIndex(u8 idx)
{
    ContextItems()[idx] = DECOR_NONE;
    ContextPos()[idx] = 0;
}

// SecretBase_EventScript_PutAwayDecoration, for each decoration put away (gSpecialVar_0x8004)
// Output: gSpecialVar_Result TRUE once done; gSpecialVar_0x8005 the flag of a doll or cushion put away (set here:
// Emerald's script setflag'd the var's number), gSpecialVar_0x8006 its object
void PutAwayDecorationIteration(void)
{
    u16 i;

    gSpecialVar_0x8005 = 0;
    gSpecialVar_Result = FALSE;
    if (gSpecialVar_0x8004 == sCurDecorSelectedInRearrangement)
    {
        gSpecialVar_Result = TRUE;
    }
    else if (gDecorations[ContextItems()[sDecorRearrangementDataBuffer[gSpecialVar_0x8004].idx]].permission == DECORPERM_SPRITE)
    {
        gSpecialVar_0x8005 = sDecorRearrangementDataBuffer[gSpecialVar_0x8004].flagId;
        ClearDecorationContextIndex(sDecorRearrangementDataBuffer[gSpecialVar_0x8004].idx);
        for (i = 0; i < gMapHeader.events->objectEventCount; i++)
        {
            if (gMapHeader.events->objectEvents[i].flagId == gSpecialVar_0x8005)
            {
                gSpecialVar_0x8006 = gMapHeader.events->objectEvents[i].localId;
                break;
            }
        }
        if (gSpecialVar_0x8005)
            FlagSet(gSpecialVar_0x8005);
    }
}

static void ClearRearrangementNonSprites(void)
{
    u8 i, x, y;
    int posX, posY;

    for (i = 0; i < sCurDecorSelectedInRearrangement; i++)
    {
        posX = ContextPos()[sDecorRearrangementDataBuffer[i].idx] >> 4;
        posY = ContextPos()[sDecorRearrangementDataBuffer[i].idx] & 0x0F;
        if (gDecorations[ContextItems()[sDecorRearrangementDataBuffer[i].idx]].permission != DECORPERM_SPRITE)
        {
            for (y = 0; y < sDecorRearrangementDataBuffer[i].height; y++)
            {
                for (x = 0; x < sDecorRearrangementDataBuffer[i].width; x++)
                    MapGridSetMetatileEntryAt(posX + MAP_OFFSET + x, posY + MAP_OFFSET - y, gMapHeader.mapLayout->map[posX + x + gMapHeader.mapLayout->width * (posY - y)] | 0x3000);
            }
            ClearDecorationContextIndex(sDecorRearrangementDataBuffer[i].idx);
        }
    }
}

static void Task_PutAwayDecoration(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        ClearRearrangementNonSprites();
        gTasks[taskId].tState = 1;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            DrawWholeMapView();
            ScriptContext_SetupScript(SecretBase_EventScript_PutAwayDecoration);
            ClearDialogWindowAndFrame(0, TRUE);
            gTasks[taskId].tState = 2;
        }
        break;
    case 2:
        LockPlayerFieldControls();
        FadeInFromBlack();
        gTasks[taskId].tState = 3;
        break;
    case 3:
        if (IsWeatherNotFadingIn() == TRUE)
            ShowMessage(taskId, gText_DecorationReturnedToPC, Task_ContinuePuttingAwayDecorationsPrompt);
        break;
    }
}

static void SetUpPuttingAwayDecorationPlayerAvatar(void)
{
    sDecor_CameraSpriteObjectIdx1 = gSprites[gFieldCamera.spriteId].data[0];
    LoadSpritePalette(gSaveBlock2Ptr->playerGender == MALE ? &sSpritePal_PuttingAwayCursorBrendan : &sSpritePal_PuttingAwayCursorMay);
    gFieldCamera.spriteId = CreateSprite(&sPuttingAwayCursorSpriteTemplate, 120, 80, 0);
    sDecor_CameraSpriteObjectIdx2 = CreateObjectGraphicsSprite(GetPlayerAvatarGfxId(), SpriteCallbackDummy, 136, 72, 0);
    gSprites[sDecor_CameraSpriteObjectIdx2].oam.priority = 1;
    DestroySprite(&gSprites[sDecor_CameraSpriteObjectIdx1]);
    sDecor_CameraSpriteObjectIdx1 = gFieldCamera.spriteId;
    gSprites[sDecor_CameraSpriteObjectIdx1].oam.priority = 1;
}

static void Task_ContinuePuttingAwayDecorations(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        if (!gPaletteFade.active)
        {
            SetInitialPositions(taskId);
            tState = 1;
            tDecorHeight = 1;
            tDecorWidth = 1;
        }
        break;
    case 1:
        SetUpPuttingAwayDecorationPlayerAvatar();
        FadeInFromBlack();
        tState = 2;
        break;
    case 2:
        if (IsWeatherNotFadingIn() == TRUE)
        {
            tItemsMenuCommand = DECOR_ITEMS_MENU_PUT_AWAY;
            ContinuePuttingAwayDecorations(taskId);
        }
        break;
    }
}

static void ContinuePuttingAwayDecorations(u8 taskId)
{
    ClearDialogWindowAndFrame(0, TRUE);
    gSprites[sDecor_CameraSpriteObjectIdx1].data[7] = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].invisible = FALSE;
    gSprites[sDecor_CameraSpriteObjectIdx1].callback = InitializeCameraSprite1;
    gSprites[sDecor_CameraSpriteObjectIdx2].x = 136;
    gSprites[sDecor_CameraSpriteObjectIdx2].y = 72;
    gTasks[taskId].tButton = 0;
    gTasks[taskId].func = Task_SelectLocation;
}

static void Task_ContinuePuttingAwayDecorationsPrompt(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        ContinuePuttingAwayDecorations(taskId);
}

static void SetCameraSpritePosition(u8 x, u8 y)
{
    gSprites[sDecor_CameraSpriteObjectIdx1].invisible = TRUE;
    gSprites[sDecor_CameraSpriteObjectIdx1].callback = SpriteCallbackDummy;
    gSprites[sDecor_CameraSpriteObjectIdx2].x = x * 16 + 136;
    gSprites[sDecor_CameraSpriteObjectIdx2].y = y * 16 + 72;
}

static void SetDecorRearrangementShape(u8 decor, struct DecorRearrangementDataBuffer *data)
{
    data->width = sDecorShapeDimensions[gDecorations[decor].shape][0];
    data->height = sDecorShapeDimensions[gDecorations[decor].shape][1];
}

static bool8 DecorationIsUnderCursor(u8 taskId, u8 idx, struct DecorRearrangementDataBuffer *data)
{
    u8 x = gTasks[taskId].tCursorX - MAP_OFFSET;
    u8 y = gTasks[taskId].tCursorY - MAP_OFFSET;
    u8 xOff = ContextPos()[idx] >> 4;
    u8 yOff = ContextPos()[idx] & 0x0F;
    u8 ht = data->height;

    if (ContextItems()[idx] == DECOR_SAND_ORNAMENT && MapGridGetMetatileIdAt(xOff + MAP_OFFSET, yOff + MAP_OFFSET) == METATILE_HoennSecretBase_SandOrnament_BrokenBase)
        ht--;
    if (x >= xOff && x < xOff + data->width && y > yOff - ht && y <= yOff)
    {
        SetCameraSpritePosition(data->width - (x - xOff + 1), yOff - y);
        return TRUE;
    }
    return FALSE;
}

static void SetDecorRearrangementFlagIdIfFlagUnset(void)
{
    u8 i;
    u8 xOff = ContextPos()[sDecorRearrangementDataBuffer[sCurDecorSelectedInRearrangement].idx] >> 4;
    u8 yOff = ContextPos()[sDecorRearrangementDataBuffer[sCurDecorSelectedInRearrangement].idx] & 0x0F;

    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        if (gSaveBlock1Ptr->objectEventTemplates[i].x == xOff && gSaveBlock1Ptr->objectEventTemplates[i].y == yOff
         && !FlagGet(gSaveBlock1Ptr->objectEventTemplates[i].flagId))
        {
            sDecorRearrangementDataBuffer[sCurDecorSelectedInRearrangement].flagId = gSaveBlock1Ptr->objectEventTemplates[i].flagId;
            break;
        }
    }
}

static bool8 AttemptMarkSpriteDecorUnderCursorForRemoval(u8 taskId)
{
    u8 i;

    for (i = 0; i < ContextSize(); i++)
    {
        if (ContextItems()[i] != DECOR_NONE && gDecorations[ContextItems()[i]].permission == DECORPERM_SPRITE)
        {
            SetDecorRearrangementShape(ContextItems()[i], sDecorRearrangementDataBuffer);
            if (DecorationIsUnderCursor(taskId, i, sDecorRearrangementDataBuffer) == TRUE)
            {
                sDecorRearrangementDataBuffer->idx = i;
                SetDecorRearrangementFlagIdIfFlagUnset();
                sCurDecorSelectedInRearrangement = 1;
                return TRUE;
            }
        }
    }
    return FALSE;
}

static void MarkSpriteDecorsInBoundsForRemoval(u8 left, u8 top, u8 right, u8 bottom)
{
    u8 i, xOff, yOff, decor;

    for (i = 0; i < ContextSize(); i++)
    {
        decor = ContextItems()[i];
        xOff = ContextPos()[i] >> 4;
        yOff = ContextPos()[i] & 0x0F;
        if (decor != DECOR_NONE && gDecorations[decor].permission == DECORPERM_SPRITE && left <= xOff && top <= yOff && right >= xOff && bottom >= yOff)
        {
            sDecorRearrangementDataBuffer[sCurDecorSelectedInRearrangement].idx = i;
            SetDecorRearrangementFlagIdIfFlagUnset();
            sCurDecorSelectedInRearrangement++;
        }
    }
}

static void AttemptMarkDecorUnderCursorForRemoval(u8 taskId)
{
    u8 i, xOff, yOff, top;
    u32 right;

    sCurDecorSelectedInRearrangement = 0;
    if (AttemptMarkSpriteDecorUnderCursorForRemoval(taskId) == TRUE)
        return;
    // Not a sprite.
    for (i = 0; i < ContextSize(); i++)
    {
        if (ContextItems()[i] != DECOR_NONE)
        {
            SetDecorRearrangementShape(ContextItems()[i], &sDecorRearrangementDataBuffer[0]);
            if (DecorationIsUnderCursor(taskId, i, &sDecorRearrangementDataBuffer[0]) == TRUE)
            {
                sDecorRearrangementDataBuffer[0].idx = i;
                sCurDecorSelectedInRearrangement++;
                break;
            }
        }
    }
    if (sCurDecorSelectedInRearrangement != 0)
    {
        xOff = ContextPos()[sDecorRearrangementDataBuffer[0].idx] >> 4;
        yOff = ContextPos()[sDecorRearrangementDataBuffer[0].idx] & 0x0F;
        top = yOff - sDecorRearrangementDataBuffer[0].height + 1;
        right = sDecorRearrangementDataBuffer[0].width + xOff - 1;
        // Remove any dolls/cushions on this decoration.
        MarkSpriteDecorsInBoundsForRemoval(xOff, top, right, yOff);
    }
}

static void PutAwayDecoration(u8 taskId)
{
    FadeScreen(FADE_TO_BLACK, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].func = Task_PutAwayDecoration;
}

static void ReturnDecorationPrompt(u8 taskId)
{
    DoYesNo(taskId, PutAwayDecoration, ContinuePuttingAwayDecorations);
}

static void FieldCB_StopPuttingAwayDecorations(void);

static void Task_StopPuttingAwayDecorations(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!gPaletteFade.active)
        {
            WarpToInitialPosition(taskId);
            gTasks[taskId].tState = 1;
        }
        break;
    case 1:
        FreeSpritePaletteByTag(PLACE_DECORATION_PLAYER_TAG);
        gFieldCallback = FieldCB_StopPuttingAwayDecorations;
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
        break;
    }
}

static void StopPuttingAwayDecorations(u8 taskId)
{
    ClearDialogWindowAndFrame(0, FALSE);
    FadeScreen(FADE_TO_BLACK, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].func = Task_StopPuttingAwayDecorations;
}

static void StopPuttingAwayDecorationsPrompt(u8 taskId)
{
    DoYesNo(taskId, StopPuttingAwayDecorations, ContinuePuttingAwayDecorations);
}

static void AttemptPutAwayDecoration(u8 taskId)
{
    u8 behavior;

    gTasks[taskId].tButton = 0;
    ResetCursorMovement();
    AttemptMarkDecorUnderCursorForRemoval(taskId);
    if (sCurDecorSelectedInRearrangement != 0)
    {
        ShowMessage(taskId, gText_ReturnDecorationToPC, ReturnDecorationPrompt);
        return;
    }
    behavior = MapGridGetMetatileBehaviorAt(gTasks[taskId].tCursorX, gTasks[taskId].tCursorY);
    if (MetatileBehavior_IsSecretBasePC(behavior) == TRUE || behavior == MB_PLAYER_ROOM_PC_ON)
    {
        gSprites[sDecor_CameraSpriteObjectIdx1].invisible = FALSE;
        gSprites[sDecor_CameraSpriteObjectIdx1].callback = SpriteCallbackDummy;
        ShowMessage(taskId, gText_StopPuttingAwayDecorations, StopPuttingAwayDecorationsPrompt);
    }
    else
    {
        ShowMessage(taskId, gText_NoDecorationHere, Task_ContinuePuttingAwayDecorationsPrompt);
    }
}

static void AttemptCancelPutAwayDecoration(u8 taskId)
{
    gTasks[taskId].tButton = 0;
    ResetCursorMovement();
    gSprites[sDecor_CameraSpriteObjectIdx1].invisible = FALSE;
    gSprites[sDecor_CameraSpriteObjectIdx1].callback = SpriteCallbackDummy;
    ShowMessage(taskId, gText_StopPuttingAwayDecorations, StopPuttingAwayDecorationsPrompt);
}

static void Task_ReinitializeDecorationMenuHandler(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        HideSecretBaseDecorationSprites();
        gTasks[taskId].tState++;
        break;
    case 1:
        ScriptContext_SetupScript(SecretBase_EventScript_InitDecorations);
        gTasks[taskId].tState++;
        break;
    case 2:
        LockPlayerFieldControls();
        gTasks[taskId].tState++;
        break;
    case 3:
        if (IsWeatherNotFadingIn() == TRUE)
            gTasks[taskId].func = Task_HandleMainMenuInput;
        break;
    }
}

static void FieldCB_StopPuttingAwayDecorations(void)
{
    u8 taskId;

    FadeInFromBlack();
    taskId = CreateTask(Task_ReinitializeDecorationMenuHandler, 8);
    LockPlayerFieldControls();
    ShowMainMenu(taskId);
    gTasks[taskId].func = Task_ReinitializeDecorationMenuHandler;
    gTasks[taskId].tState = 0;
}
