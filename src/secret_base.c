#include "global.h"
#include "gflib.h"
#include "decoration.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_fadetransition.h"
#include "field_player_avatar.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "map_name_popup.h"
#include "overworld.h"
#include "region_map.h"
#include "script.h"
#include "secret_base.h"
#include "fldeff.h"
#include "task.h"
#include "constants/decorations.h"
#include "constants/event_bg.h"
#include "constants/event_objects.h"
#include "constants/maps.h"
#include "constants/map_types.h"
#include "constants/metatile_behaviors.h"
#include "constants/metatile_labels.h"
#include "constants/secret_bases.h"

// RFVF+: Emerald's secret_base.c without other players' bases (no record mixing, no registry entries, no owner
// battles): the player's base is gSaveBlock2Ptr->secretBases[0] (SECRET_BASES_COUNT 1), its map one of the 24
// SecretBase_* maps of gMapGroup_SecretBases (Emerald's order; tools/hoenn_import/secret_bases.py).

#define MAPGRID_IMPASSABLE (1 << MAPGRID_COLLISION_SHIFT) // Emerald's

struct SecretBaseEntranceMetatiles
{
    u16 closedMetatileId;
    u16 openMetatileId;
};

static EWRAM_DATA u8 sCurSecretBaseId = 0;

static const struct SecretBaseEntranceMetatiles sSecretBaseEntranceMetatiles[] =
{
    {.closedMetatileId = METATILE_HoennGeneral_SecretBase_TreeLeft,  .openMetatileId = METATILE_HoennGeneral_SecretBase_VineLeft},
    {.closedMetatileId = METATILE_HoennGeneral_SecretBase_TreeRight, .openMetatileId = METATILE_HoennGeneral_SecretBase_VineRight},
    {.closedMetatileId = METATILE_HoennGeneral_RedCaveIndent,        .openMetatileId = METATILE_HoennGeneral_RedCaveOpen},
    {.closedMetatileId = METATILE_HoennGeneral_YellowCaveIndent,     .openMetatileId = METATILE_HoennGeneral_YellowCaveOpen},
    {.closedMetatileId = METATILE_HoennGeneral_BlueCaveIndent,       .openMetatileId = METATILE_HoennGeneral_BlueCaveOpen},
    {.closedMetatileId = METATILE_HoennFallarbor_BrownCaveIndent,    .openMetatileId = METATILE_HoennFallarbor_BrownCaveOpen},
    {.closedMetatileId = METATILE_HoennFortree_SecretBase_Shrub,     .openMetatileId = METATILE_HoennFortree_SecretBase_ShrubOpen},
};

// mapNum, warpId, x, y: x, y = in front of the computer, where the player stands once the base is made
static const u8 sSecretBaseEntrancePositions[NUM_SECRET_BASE_GROUPS * 4] =
{
    [SECRET_BASE_RED_CAVE1]    = MAP_NUM(SECRET_BASE_RED_CAVE1),    0,  1,  3,
    [SECRET_BASE_RED_CAVE2]    = MAP_NUM(SECRET_BASE_RED_CAVE2),    0,  5,  9,
    [SECRET_BASE_RED_CAVE3]    = MAP_NUM(SECRET_BASE_RED_CAVE3),    0,  1,  3,
    [SECRET_BASE_RED_CAVE4]    = MAP_NUM(SECRET_BASE_RED_CAVE4),    0,  7, 13,
    [SECRET_BASE_BROWN_CAVE1]  = MAP_NUM(SECRET_BASE_BROWN_CAVE1),  0,  2,  3,
    [SECRET_BASE_BROWN_CAVE2]  = MAP_NUM(SECRET_BASE_BROWN_CAVE2),  0,  9,  2,
    [SECRET_BASE_BROWN_CAVE3]  = MAP_NUM(SECRET_BASE_BROWN_CAVE3),  0, 13,  4,
    [SECRET_BASE_BROWN_CAVE4]  = MAP_NUM(SECRET_BASE_BROWN_CAVE4),  0,  1,  2,
    [SECRET_BASE_BLUE_CAVE1]   = MAP_NUM(SECRET_BASE_BLUE_CAVE1),   0,  1,  3,
    [SECRET_BASE_BLUE_CAVE2]   = MAP_NUM(SECRET_BASE_BLUE_CAVE2),   0,  1,  2,
    [SECRET_BASE_BLUE_CAVE3]   = MAP_NUM(SECRET_BASE_BLUE_CAVE3),   0,  3, 15,
    [SECRET_BASE_BLUE_CAVE4]   = MAP_NUM(SECRET_BASE_BLUE_CAVE4),   0,  3, 14,
    [SECRET_BASE_YELLOW_CAVE1] = MAP_NUM(SECRET_BASE_YELLOW_CAVE1), 0,  9,  3,
    [SECRET_BASE_YELLOW_CAVE2] = MAP_NUM(SECRET_BASE_YELLOW_CAVE2), 0,  8,  7,
    [SECRET_BASE_YELLOW_CAVE3] = MAP_NUM(SECRET_BASE_YELLOW_CAVE3), 0,  3,  6,
    [SECRET_BASE_YELLOW_CAVE4] = MAP_NUM(SECRET_BASE_YELLOW_CAVE4), 0,  5,  9,
    [SECRET_BASE_TREE1]        = MAP_NUM(SECRET_BASE_TREE1),        0,  2,  3,
    [SECRET_BASE_TREE2]        = MAP_NUM(SECRET_BASE_TREE2),        0,  5,  6,
    [SECRET_BASE_TREE3]        = MAP_NUM(SECRET_BASE_TREE3),        0, 15,  3,
    [SECRET_BASE_TREE4]        = MAP_NUM(SECRET_BASE_TREE4),        0,  4, 10,
    [SECRET_BASE_SHRUB1]       = MAP_NUM(SECRET_BASE_SHRUB1),       0,  3,  3,
    [SECRET_BASE_SHRUB2]       = MAP_NUM(SECRET_BASE_SHRUB2),       0,  1,  2,
    [SECRET_BASE_SHRUB3]       = MAP_NUM(SECRET_BASE_SHRUB3),       0,  7,  8,
    [SECRET_BASE_SHRUB4]       = MAP_NUM(SECRET_BASE_SHRUB4),       0,  9,  6,
};

#define GET_BASE_MAP_NUM(group)    (sSecretBaseEntrancePositions[(group) + 0])
#define GET_BASE_WARP_ID(group)    (sSecretBaseEntrancePositions[(group) + 1])
#define GET_BASE_COMPUTER_X(group) (sSecretBaseEntrancePositions[(group) + 2])
#define GET_BASE_COMPUTER_Y(group) (sSecretBaseEntrancePositions[(group) + 3])

static const u8 sText_SecretBaseOf[] = _("BASE DE "); // French Emerald's gText_ApostropheSBase, "BASE DE {STR_VAR_1}"

static void ClearSecretBase(struct SecretBase *secretBase)
{
    u16 i;
    CpuFastFill16(0, secretBase, sizeof(struct SecretBase));
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        secretBase->trainerName[i] = EOS;
}

void ClearSecretBases(void)
{
    u16 i;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
        ClearSecretBase(&gSaveBlock2Ptr->secretBases[i]);
}

void TrySetCurSecretBaseIndex(void)
{
    u16 i;

    gSpecialVar_Result = FALSE;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (sCurSecretBaseId == gSaveBlock2Ptr->secretBases[i].secretBaseId)
        {
            gSpecialVar_Result = TRUE;
            VarSet(VAR_CURRENT_SECRET_BASE, i);
            break;
        }
    }
}

void CheckPlayerHasSecretBase(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->secretBases[0].secretBaseId != 0;
}

static u8 GetSecretBaseTypeInFrontOfPlayer_(void)
{
    s16 x, y;
    s16 behavior;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);
    if (behavior == MB_SECRET_BASE_SPOT_RED_CAVE || behavior == MB_SECRET_BASE_SPOT_RED_CAVE_OPEN)
        return SECRET_BASE_RED_CAVE;
    if (behavior == MB_SECRET_BASE_SPOT_BROWN_CAVE || behavior == MB_SECRET_BASE_SPOT_BROWN_CAVE_OPEN)
        return SECRET_BASE_BROWN_CAVE;
    if (behavior == MB_SECRET_BASE_SPOT_BLUE_CAVE || behavior == MB_SECRET_BASE_SPOT_BLUE_CAVE_OPEN)
        return SECRET_BASE_BLUE_CAVE;
    if (behavior == MB_SECRET_BASE_SPOT_YELLOW_CAVE || behavior == MB_SECRET_BASE_SPOT_YELLOW_CAVE_OPEN)
        return SECRET_BASE_YELLOW_CAVE;
    if (behavior == MB_SECRET_BASE_SPOT_TREE_LEFT  || behavior == MB_SECRET_BASE_SPOT_TREE_LEFT_OPEN
     || behavior == MB_SECRET_BASE_SPOT_TREE_RIGHT || behavior == MB_SECRET_BASE_SPOT_TREE_RIGHT_OPEN)
        return SECRET_BASE_TREE;
    if (behavior == MB_SECRET_BASE_SPOT_SHRUB || behavior == MB_SECRET_BASE_SPOT_SHRUB_OPEN)
        return SECRET_BASE_SHRUB;
    return 0;
}

void GetSecretBaseTypeInFrontOfPlayer(void)
{
    gSpecialVar_0x8007 = GetSecretBaseTypeInFrontOfPlayer_();
}

static void FindMetatileIdMapCoords(s16 *x, s16 *y, u16 metatileId)
{
    s16 i, j;
    const struct MapLayout *mapLayout = gMapHeader.mapLayout;

    for (j = 0; j < mapLayout->height; j++)
    {
        for (i = 0; i < mapLayout->width; i++)
        {
            if ((mapLayout->map[j * mapLayout->width + i] & MAPGRID_METATILE_ID_MASK) == metatileId)
            {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

// Opens or closes the secret base entrance metatile in front of the player.
void ToggleSecretBaseEntranceMetatile(void)
{
    u16 i;
    s16 x, y;
    s16 metatileId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    metatileId = MapGridGetMetatileIdAt(x, y);
    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
    {
        if (sSecretBaseEntranceMetatiles[i].closedMetatileId == metatileId)
        {
            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].openMetatileId | MAPGRID_IMPASSABLE);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }
    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
    {
        if (sSecretBaseEntranceMetatiles[i].openMetatileId == metatileId)
        {
            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].closedMetatileId | MAPGRID_IMPASSABLE);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }
}

static u8 GetNameLength(const u8 *secretBaseOwnerName)
{
    u8 i;
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
    {
        if (secretBaseOwnerName[i] == EOS)
            return i;
    }
    return PLAYER_NAME_LENGTH;
}

void SetPlayerSecretBase(void)
{
    u16 i;

    gSaveBlock2Ptr->secretBases[0].secretBaseId = sCurSecretBaseId;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        gSaveBlock2Ptr->secretBases[0].trainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];
    VarSet(VAR_CURRENT_SECRET_BASE, 0);
    StringCopyN(gSaveBlock2Ptr->secretBases[0].trainerName, gSaveBlock2Ptr->playerName, GetNameLength(gSaveBlock2Ptr->playerName));
    gSaveBlock2Ptr->secretBases[0].gender = gSaveBlock2Ptr->playerGender;
    gSaveBlock2Ptr->secretBases[0].language = GAME_LANGUAGE;
    VarSet(VAR_SECRET_BASE_MAP, gMapHeader.regionMapSectionId);
}

// The 'open' entrance metatile for an occupied secret base of this map (InitMap)
void SetOccupiedSecretBaseEntranceMetatiles(const struct MapEvents *events)
{
    u16 bgId;
    u16 i, j;

    for (bgId = 0; bgId < events->bgEventCount; bgId++)
    {
        if (events->bgEvents[bgId].kind != BG_EVENT_SECRET_BASE)
            continue;
        for (j = 0; j < SECRET_BASES_COUNT; j++)
        {
            if (gSaveBlock2Ptr->secretBases[j].secretBaseId == events->bgEvents[bgId].bgUnion.secretBaseId)
            {
                s16 x = events->bgEvents[bgId].x + MAP_OFFSET;
                s16 y = events->bgEvents[bgId].y + MAP_OFFSET;
                s16 tile_id = MapGridGetMetatileIdAt(x, y);
                for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
                {
                    if (sSecretBaseEntranceMetatiles[i].closedMetatileId == tile_id)
                    {
                        MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].openMetatileId | MAPGRID_IMPASSABLE);
                        break;
                    }
                }
                break;
            }
        }
    }
}

static void SetSecretBaseWarpDestination(void)
{
    s8 secretBaseGroup = SECRET_BASE_ID_TO_GROUP(sCurSecretBaseId);
    SetWarpDestinationToMapWarp(MAP_GROUP(SECRET_BASE_RED_CAVE1), GET_BASE_MAP_NUM(secretBaseGroup), GET_BASE_WARP_ID(secretBaseGroup));
}

#define tState data[0]

static void Task_EnterSecretBase(u8 taskId)
{
    u16 secretBaseIdx;

    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!gPaletteFade.active)
            gTasks[taskId].tState = 1;
        break;
    case 1:
        secretBaseIdx = VarGet(VAR_CURRENT_SECRET_BASE);
        if (gSaveBlock2Ptr->secretBases[secretBaseIdx].numTimesEntered < 255)
            gSaveBlock2Ptr->secretBases[secretBaseIdx].numTimesEntered++;
        SetSecretBaseWarpDestination();
        WarpIntoMap();
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
        break;
    }
}

#undef tState

void EnterSecretBase(void)
{
    CreateTask(Task_EnterSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

// No map name the first time in: the player has not made the base yet
bool8 SecretBaseMapPopupEnabled(void)
{
    return !(gMapHeader.mapType == MAP_TYPE_SECRET_BASE && VarGet(VAR_INIT_SECRET_BASE) == 0);
}

static void EnterNewlyCreatedSecretBase_WaitFadeIn(u8 taskId)
{
    ObjectEventTurn(&gObjectEvents[gPlayerAvatar.objectEventId], DIR_NORTH);
    if (IsWeatherNotFadingIn() == TRUE)
    {
        ScriptContext_Enable();
        DestroyTask(taskId);
    }
}

static void EnterNewlyCreatedSecretBase_StartFadeIn(void)
{
    s16 x, y;

    LockPlayerFieldControls();
    DismissMapNamePopup();
    FindMetatileIdMapCoords(&x, &y, METATILE_HoennSecretBase_PC);
    x += MAP_OFFSET;
    y += MAP_OFFSET;
    MapGridSetMetatileIdAt(x, y, METATILE_HoennSecretBase_PC | MAPGRID_IMPASSABLE);
    CurrentMapDrawMetatileAt(x, y);
    FadeInFromBlack();
    CreateTask(EnterNewlyCreatedSecretBase_WaitFadeIn, 0);
}

static void Task_EnterNewlyCreatedSecretBase(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        s8 secretBaseGroup = SECRET_BASE_ID_TO_GROUP(sCurSecretBaseId);
        SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE,
                           GET_BASE_COMPUTER_X(secretBaseGroup), GET_BASE_COMPUTER_Y(secretBaseGroup));
        WarpIntoMap();
        gFieldCallback = EnterNewlyCreatedSecretBase_StartFadeIn;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
    }
}

void EnterNewlyCreatedSecretBase(void)
{
    CreateTask(Task_EnterNewlyCreatedSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
}

bool8 CurMapIsSecretBase(void)
{
    return gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SECRET_BASE_RED_CAVE1);
}

// Draws the base's tile decorations (dolls and cushions are objects: InitSecretBaseDecorationSprites)
void InitSecretBaseAppearance(bool8 hidePC)
{
    u16 i;
    s16 x, y;
    u8 *decorations, *decorPos;

    if (!CurMapIsSecretBase())
        return;
    decorations = gSaveBlock2Ptr->secretBases[0].decorations;
    decorPos = gSaveBlock2Ptr->secretBases[0].decorationPositions;
    for (i = 0; i < DECOR_MAX_SECRET_BASE; i++)
    {
        if (decorations[i] > 0 && decorations[i] <= NUM_DECORATIONS && gDecorations[decorations[i]].permission != DECORPERM_SPRITE)
            ShowDecorationOnMap((decorPos[i] >> 4) + MAP_OFFSET, (decorPos[i] & 0xF) + MAP_OFFSET, decorations[i]);
    }
    if (hidePC == TRUE && VarGet(VAR_SECRET_BASE_INITIALIZED) == 1)
    {
        // The base is not made yet (first time in): no PC until the player says yes
        FindMetatileIdMapCoords(&x, &y, METATILE_HoennSecretBase_PC);
        MapGridSetMetatileIdAt(x + MAP_OFFSET, y + MAP_OFFSET, METATILE_HoennSecretBase_Ground | MAPGRID_IMPASSABLE);
    }
}

// The Pallet Town bedroom keeps FRLG's tileset, whose rug has no decoration behaviors. Emerald's bedroom takes dolls
// and cushions on its rug only: its edges hold the small ones (MB_HOLDS_SMALL_DECORATION), its middle the big dolls too
// (MB_HOLDS_LARGE_DECORATION). Pallet's rug: 5x4 at 4,4, the TV and the NES in its middle column, left free (the NES
// stays reachable).
#define S MB_HOLDS_SMALL_DECORATION
#define L MB_HOLDS_LARGE_DECORATION
static const u8 sPlayerRoomRugBehaviors[4][5] =
{
    {S, S, MB_NORMAL, S, S},
    {S, L, MB_NORMAL, L, S},
    {S, L, MB_NORMAL, L, S},
    {S, S, MB_NORMAL, S, S},
};
#undef S
#undef L

static bool8 CurMapIsPlayersRoom(void)
{
    return gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PALLET_TOWN_PLAYERS_HOUSE_2F)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(PALLET_TOWN_PLAYERS_HOUSE_2F);
}

// The maps with decoration objects (Emerald's dolls and cushions): they load Emerald's NPC palettes (overworld.c)
bool8 UsesDecorationObjects(void)
{
    return CurMapIsSecretBase() || CurMapIsPlayersRoom();
}

// x, y: map grid coordinates (MAP_OFFSET included)
u8 GetDecorationSpotBehaviorAt(s16 x, s16 y)
{
    if (CurMapIsPlayersRoom())
    {
        x -= MAP_OFFSET + 4;
        y -= MAP_OFFSET + 4;
        if (x >= 0 && x < 5 && y >= 0 && y < 4)
            return sPlayerRoomRugBehaviors[y][x];
        return MB_NORMAL;
    }
    return MapGridGetMetatileBehaviorAt(x, y);
}

// Shows the decoration objects of the placed dolls and cushions (the base's or the bedroom's), from gSpecialVar_0x8004
void InitSecretBaseDecorationSprites(void)
{
    u8 i, objectEventId, metatileBehavior, numDecorations;
    u8 *decorations, *decorationPositions;

    if (!CurMapIsSecretBase())
    {
        decorations = gSaveBlock2Ptr->playerRoomDecorations;
        decorationPositions = gSaveBlock2Ptr->playerRoomDecorationPositions;
        numDecorations = DECOR_MAX_PLAYERS_HOUSE;
    }
    else
    {
        decorations = gSaveBlock2Ptr->secretBases[0].decorations;
        decorationPositions = gSaveBlock2Ptr->secretBases[0].decorationPositions;
        numDecorations = DECOR_MAX_SECRET_BASE;
    }

    for (i = 0; i < numDecorations; i++)
    {
        if (decorations[i] == DECOR_NONE || gDecorations[decorations[i]].permission != DECORPERM_SPRITE)
            continue;
        for (objectEventId = 0; objectEventId < gMapHeader.events->objectEventCount; objectEventId++)
        {
            if (gMapHeader.events->objectEvents[objectEventId].flagId == FLAG_DECORATION_1 + gSpecialVar_0x8004)
                break;
        }
        if (objectEventId == gMapHeader.events->objectEventCount)
            continue;

        gSpecialVar_0x8006 = decorationPositions[i] >> 4;
        gSpecialVar_0x8007 = decorationPositions[i] & 0xF;
        metatileBehavior = GetDecorationSpotBehaviorAt(gSpecialVar_0x8006 + MAP_OFFSET, gSpecialVar_0x8007 + MAP_OFFSET);
        if (metatileBehavior == MB_HOLDS_SMALL_DECORATION || metatileBehavior == MB_HOLDS_LARGE_DECORATION)
        {
            gSpecialVar_Result = VAR_OBJ_GFX_ID_0 + (ObjTemplateGfxId(&gMapHeader.events->objectEvents[objectEventId]) - OBJ_EVENT_GFX_VAR_0);
            VarSet(gSpecialVar_Result, gDecorations[decorations[i]].tiles[0]);
            gSpecialVar_Result = gMapHeader.events->objectEvents[objectEventId].localId;
            FlagClear(FLAG_DECORATION_1 + gSpecialVar_0x8004);
            TrySpawnObjectEvent(gSpecialVar_Result, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            TryMoveObjectEventToMapCoords(gSpecialVar_Result, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
            TryOverrideObjectEventTemplateCoords(gSpecialVar_Result, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            gSpecialVar_0x8004++;
        }
    }
}

void HideSecretBaseDecorationSprites(void)
{
    u8 objectEventId;
    u16 flag;

    for (objectEventId = 0; objectEventId < gMapHeader.events->objectEventCount; objectEventId++)
    {
        flag = gMapHeader.events->objectEvents[objectEventId].flagId;
        if (flag >= FLAG_DECORATION_1 && flag <= FLAG_DECORATION_14)
        {
            RemoveObjectEventByLocalIdAndMap(gMapHeader.events->objectEvents[objectEventId].localId,
                                             gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            FlagSet(flag);
        }
    }
}

// STEP_CB_SECRET_BASE (SecretBase_OnResume): pops the balloons and breaks the breakable doors stepped on. Emerald's
// also records what the player did in another player's base for the TV: no other bases here.
#define tState   data[1]
#define tPlayerX data[2]
#define tPlayerY data[3]
void SecretBasePerStepCallback(u8 taskId)
{
    s16 x, y;
    u8 behavior;
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        PlayerGetDestCoords(&tPlayerX, &tPlayerY);
        tState = 1;
        break;
    case 1:
        PlayerGetDestCoords(&x, &y);
        if (x == tPlayerX && y == tPlayerY)
            return;
        tPlayerX = x;
        tPlayerY = y;
        behavior = MapGridGetMetatileBehaviorAt(x, y);
        if (behavior == MB_SECRET_BASE_BALLOON)
            PopSecretBaseBalloon(MapGridGetMetatileIdAt(x, y), x, y);
        else if (behavior == MB_SECRET_BASE_BREAKABLE_DOOR)
            ShatterSecretBaseBreakableDoor(x, y);
        break;
    }
}
#undef tState
#undef tPlayerX
#undef tPlayerY

void SetCurSecretBaseIdFromPosition(const struct MapPosition *position, const struct MapEvents *events)
{
    s16 i;
    for (i = 0; i < events->bgEventCount; i++)
    {
        if (events->bgEvents[i].kind == BG_EVENT_SECRET_BASE
          && position->x == events->bgEvents[i].x + MAP_OFFSET
          && position->y == events->bgEvents[i].y + MAP_OFFSET)
        {
            sCurSecretBaseId = events->bgEvents[i].bgUnion.secretBaseId;
            break;
        }
    }
}

void WarpIntoSecretBase(const struct MapPosition *position, const struct MapEvents *events)
{
    SetCurSecretBaseIdFromPosition(position, events);
    TrySetCurSecretBaseIndex();
    ScriptContext_SetupScript(SecretBase_EventScript_Enter);
}

// gSpecialVar_0x8004 = the entrance's id: TRUE if it is free
bool8 TrySetCurSecretBase(void)
{
    sCurSecretBaseId = gSpecialVar_0x8004;
    TrySetCurSecretBaseIndex();
    return gSpecialVar_Result != TRUE;
}

static void Task_WarpOutOfSecretBase(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        LockPlayerFieldControls();
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        if (!gPaletteFade.active)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        SetWarpDestinationToDynamicWarp(WARP_ID_SECRET_BASE);
        WarpIntoMap();
        gFieldCallback = FieldCB_DefaultWarpExit;
        SetMainCallback2(CB2_LoadMap);
        UnlockPlayerFieldControls();
        DestroyTask(taskId);
        break;
    }
}

static void WarpOutOfSecretBase(void)
{
    CreateTask(Task_WarpOutOfSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
}

// The map name of a base (GetMapName, MAPSEC_SECRET_BASE): "BASE DE <owner>"
u8 *GetSecretBaseMapName(u8 *dest)
{
    const u8 *name = gSaveBlock2Ptr->secretBases[VarGet(VAR_CURRENT_SECRET_BASE)].trainerName;
    dest = StringCopy(dest, sText_SecretBaseOf);
    dest = StringCopyN(dest, name, GetNameLength(name));
    *dest = EOS;
    return dest;
}

// Where the player's base is: "Would you like to move from the SECRET BASE near {STR_VAR_1}?"
void GetSecretBaseNearbyMapName(void)
{
    GetMapName(gStringVar1, VarGet(VAR_SECRET_BASE_MAP), 0);
}

void ClearAndLeaveSecretBase(void)
{
    u16 temp = gSaveBlock2Ptr->secretBases[0].numSecretBasesReceived;
    ClearSecretBase(&gSaveBlock2Ptr->secretBases[0]);
    gSaveBlock2Ptr->secretBases[0].numSecretBasesReceived = temp;
    WarpOutOfSecretBase();
}

// The base PC's PLIER BAGAGE: the decorations stay in the inventory (placed ones are only marked there)
void MoveOutOfSecretBase(void)
{
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    ClearAndLeaveSecretBase();
}

static void ClosePlayerSecretBaseEntrance(void)
{
    u16 i, j;
    s16 metatileId;
    const struct MapEvents *events = gMapHeader.events;

    for (i = 0; i < events->bgEventCount; i++)
    {
        if (events->bgEvents[i].kind == BG_EVENT_SECRET_BASE
         && gSaveBlock2Ptr->secretBases[0].secretBaseId == events->bgEvents[i].bgUnion.secretBaseId)
        {
            metatileId = MapGridGetMetatileIdAt(events->bgEvents[i].x + MAP_OFFSET, events->bgEvents[i].y + MAP_OFFSET);
            for (j = 0; j < ARRAY_COUNT(sSecretBaseEntranceMetatiles); j++)
            {
                if (sSecretBaseEntranceMetatiles[j].openMetatileId == metatileId)
                {
                    MapGridSetMetatileIdAt(events->bgEvents[i].x + MAP_OFFSET, events->bgEvents[i].y + MAP_OFFSET,
                                           sSecretBaseEntranceMetatiles[j].closedMetatileId | MAPGRID_IMPASSABLE);
                    break;
                }
            }
            DrawWholeMapView();
            break;
        }
    }
}

// Moving to a new entrance from outside
void MoveOutOfSecretBaseFromOutside(void)
{
    u16 temp;

    ClosePlayerSecretBaseEntrance();
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    temp = gSaveBlock2Ptr->secretBases[0].numSecretBasesReceived;
    ClearSecretBase(&gSaveBlock2Ptr->secretBases[0]);
    gSaveBlock2Ptr->secretBases[0].numSecretBasesReceived = temp;
}

void ShowSecretBaseDecorationMenu(void)
{
    CreateTask(DoSecretBaseDecorationMenu, 0);
}
