#include "global.h"
#include "gflib.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_data.h"
#include "list_menu.h"
#include "menu.h"
#include "menu_indicators.h"
#include "new_menu_helpers.h"
#include "script.h"
#include "strings.h"
#include "task.h"
#include "constants/decorations.h"
#include "constants/songs.h"

#include "data/decoration/tiles.h"
#include "data/decoration/description.h"
#include "data/decoration/header.h"

// RFVF+: the part of Emerald's decoration PC menu (decoration.c) that works without secret bases: browse the
// categories and toss a decoration (DECOR_MENU_TOSS), or pick one for the Mauville old man's trader
// (DECOR_MENU_TRADE). Placing and putting away come with the secret bases.

#define tMenuCommand data[11]
#define tListTaskId  data[13]

enum { DECOR_MENU_TOSS, DECOR_MENU_TRADE };
enum { WIN_CATEGORIES, WIN_SUMMARY, WIN_DESCRIPTION, WIN_COUNT };

#define MAX_SHOWN 8

static EWRAM_DATA u8 sWindowIds[WIN_COUNT] = {};
static EWRAM_DATA u8 sCategory = 0;
static EWRAM_DATA u8 sNumOwned = 0;
static EWRAM_DATA u16 sScroll = 0;
static EWRAM_DATA u16 sRow = 0;
static EWRAM_DATA u8 sScrollArrowsTaskId = 0;
static EWRAM_DATA u8 sSelectedDecor = 0;
static EWRAM_DATA TaskFunc sExitFunc = NULL;
static EWRAM_DATA struct ListMenuItem sListItems[40 + 1] = {};

static void ShowCategories(u8 taskId);
static void Task_HandleCategoriesInput(u8 taskId);
static void Task_HandleItemsInput(u8 taskId);
static void ShowItems(u8 taskId);

static const u8 *const sCategoryNames[DECORCAT_COUNT] =
{
    gText_Desk, gText_Chair, gText_Plant, gText_Ornament, gText_Mat, gText_Poster, gText_Doll, gText_Cushion
};

static const struct WindowTemplate sWindowTemplates[WIN_COUNT] =
{
    [WIN_CATEGORIES]  = {.bg = 0, .tilemapLeft = 1,  .tilemapTop = 1,  .width = 13, .height = 18, .paletteNum = 15, .baseBlock = 0x001},
    [WIN_SUMMARY]     = {.bg = 0, .tilemapLeft = 17, .tilemapTop = 1,  .width = 12, .height = 2,  .paletteNum = 15, .baseBlock = 0x0EB},
    [WIN_DESCRIPTION] = {.bg = 0, .tilemapLeft = 16, .tilemapTop = 13, .width = 13, .height = 6,  .paletteNum = 15, .baseBlock = 0x103},
};

static void AddDecorWindow(u8 win)
{
    sWindowIds[win] = AddWindow(&sWindowTemplates[win]);
    SetStdWindowBorderStyle(sWindowIds[win], FALSE);
    FillWindowPixelBuffer(sWindowIds[win], PIXEL_FILL(1));
    ScheduleBgCopyTilemapToVram(0);
}

static void RemoveDecorWindow(u8 win)
{
    ClearStdWindowAndFrameToTransparent(sWindowIds[win], FALSE);
    ClearWindowTilemap(sWindowIds[win]);
    RemoveWindow(sWindowIds[win]);
    ScheduleBgCopyTilemapToVram(0);
}

// "BUREAU     2/10"
static void PrintCategoryLine(u8 windowId, u8 category, u8 x, u8 y, u8 width)
{
    u8 size;
    u8 *str;

    GetDecorationInventory(category, &size);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, sCategoryNames[category], x, y, TEXT_SKIP_DRAW, NULL);
    str = ConvertIntToDecimalStringN(gStringVar4, GetNumOwnedDecorationsInCategory(category), STR_CONV_MODE_RIGHT_ALIGN, 2);
    *str++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(str, size, STR_CONV_MODE_RIGHT_ALIGN, 2);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, width - GetStringWidth(FONT_NORMAL, gStringVar4, 0), y, TEXT_SKIP_DRAW, NULL);
}

static void PrintCategories(u8 taskId)
{
    u8 i, windowId = sWindowIds[WIN_CATEGORIES];

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    for (i = 0; i < DECORCAT_COUNT; i++)
        PrintCategoryLine(windowId, i, 8, i * 16 + 2, 104);
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
    else
    {
        sExitFunc(taskId);
    }
}

static void Task_HandleCategoriesInput(u8 taskId)
{
    s8 input = Menu_ProcessInput();

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
            DisplayItemMessageOnField(taskId, FONT_NORMAL, gText_NoDecorations, ShowCategoriesAfterMessage);
        }
        else
        {
            sScroll = sRow = 0;
            ShowItems(taskId);
        }
        break;
    }
}

static void ListCursorMoved(s32 index, bool8 onInit, struct ListMenu *list)
{
    u8 size, windowId = sWindowIds[WIN_DESCRIPTION];
    u8 *items = GetDecorationInventory(sCategory, &size);

    if (onInit != TRUE)
        PlaySE(SE_SELECT);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, FONT_NORMAL, (u32)index < sNumOwned ? gDecorations[items[index]].description : gText_GoBackToThePreviousMenu, 0, 1, 0, NULL);
}

static void ShowItems(u8 taskId)
{
    u8 i, size;
    u8 *items = GetDecorationInventory(sCategory, &size);

    sNumOwned = GetNumOwnedDecorationsInCategory(sCategory);
    for (i = 0; i < sNumOwned; i++)
    {
        sListItems[i].label = gDecorations[items[i]].name;
        sListItems[i].index = i;
    }
    sListItems[i].label = gFameCheckerText_Cancel;
    sListItems[i].index = LIST_CANCEL;

    AddDecorWindow(WIN_SUMMARY);
    PrintCategoryLine(sWindowIds[WIN_SUMMARY], sCategory, 0, 1, 96);
    CopyWindowToVram(sWindowIds[WIN_SUMMARY], COPYWIN_FULL);
    AddDecorWindow(WIN_DESCRIPTION);

    gMultiuseListMenuTemplate = (struct ListMenuTemplate){
        .items = sListItems,
        .moveCursorFunc = ListCursorMoved,
        .itemPrintFunc = NULL,
        .totalItems = sNumOwned + 1,
        .maxShowed = min(sNumOwned + 1, MAX_SHOWN),
        .windowId = sWindowIds[WIN_CATEGORIES],
        .header_X = 0,
        .item_X = 8,
        .cursor_X = 0,
        .upText_Y = 2,
        .cursorPal = 2,
        .fillValue = 1,
        .cursorShadowPal = 3,
        .lettersSpacing = 0,
        .itemVerticalPadding = 2,
        .scrollMultiple = 0,
        .fontId = FONT_NORMAL,
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

static void Task_ShowItemsAfterMessage(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, FALSE);
        AddDecorWindow(WIN_CATEGORIES);
        ShowItems(taskId);
    }
}

static void Task_TossYesNo(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case 0:
        DecorationRemove(sSelectedDecor);
        DisplayItemMessageOnField(taskId, FONT_NORMAL, gText_DecorationThrownAway, Task_ShowItemsAfterMessage);
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        // fallthrough
    case 1:
        ClearDialogWindowAndFrame(0, FALSE);
        AddDecorWindow(WIN_CATEGORIES);
        ShowItems(taskId);
        break;
    }
}

static void Task_TossPrompt(u8 taskId)
{
    DisplayYesNoMenuDefaultYes();
    gTasks[taskId].func = Task_TossYesNo;
}

static void Task_HandleItemsInput(u8 taskId)
{
    u8 size;
    s32 input = ListMenu_ProcessInput(gTasks[taskId].tListTaskId);

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
        sSelectedDecor = GetDecorationInventory(sCategory, &size)[input];
        RemoveItems(taskId);
        RemoveDecorWindow(WIN_CATEGORIES);
        if (gTasks[taskId].tMenuCommand == DECOR_MENU_TRADE)
        {
            // Emerald's DecorationItemsMenuAction_Trade (trader.c)
            gSpecialVar_0x8006 = sSelectedDecor;
            StringCopy(gStringVar3, gDecorations[gSpecialVar_0x8004].name);
            StringCopy(gStringVar2, gDecorations[gSpecialVar_0x8006].name);
            DestroyTask(taskId);
            ScriptContext_Enable();
        }
        else
        {
            StringCopy(gStringVar1, gDecorations[sSelectedDecor].name);
            StringExpandPlaceholders(gStringVar4, gText_DecorationWillBeDiscarded);
            DisplayItemMessageOnField(taskId, FONT_NORMAL, gStringVar4, Task_TossPrompt);
        }
        break;
    }
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

// The player's PC: back to exitFunc when done
void DoDecorationPCMenu(u8 taskId, TaskFunc exitFunc)
{
    sExitFunc = exitFunc;
    if (!HasDecorations())
    {
        DisplayItemMessageOnField(taskId, FONT_NORMAL, gText_NoDecorations, exitFunc);
        return;
    }
    gTasks[taskId].tMenuCommand = DECOR_MENU_TOSS;
    sCategory = DECORCAT_DESK;
    ClearDialogWindowAndFrame(0, FALSE);
    ShowCategories(taskId);
}

// The Mauville old man's trader: gSpecialVar_0x8006 = the decoration offered, 0 if none
void ShowDecorationCategoriesWindow(u8 taskId)
{
    gTasks[taskId].tMenuCommand = DECOR_MENU_TRADE;
    sCategory = DECORCAT_DESK;
    ClearDialogWindowAndFrame(0, FALSE);
    ShowCategories(taskId);
}

void CopyDecorationCategoryName(u8 *dest, u8 category)
{
    StringCopy(dest, sCategoryNames[category]);
}
