// Hoenn special scripts, batch 3 (dungeons): Emerald's braille window and puzzles (src/braille_puzzles.c), Shoal Cave's
// tide, the abnormal weather of Marine and Terra caves (src/field_specials.c), the Abandoned Ship's key sparkles.
// RFVF+ has no clock: a "day" is 1,000 steps (src/hoenn_specials.c).
#include "global.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "menu.h"
#include "new_menu_helpers.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokemon.h"
#include "random.h"
#include "region_map.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "hoenn_dungeons.h"
#include "constants/maps.h"
#include "constants/metatile_labels.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/weather.h"

#define ON_MAP(map) (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(map) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(map))
#define MAPGRID_IMPASSABLE (1 << MAPGRID_COLLISION_SHIFT) // Emerald's
#define CURRENT_MAP ((u16)(gSaveBlock1Ptr->location.mapNum | (gSaveBlock1Ptr->location.mapGroup << 8)))

// ------------------------------------------------------------------------------------------------ braille window
// Emerald's braillemessage: a window sized to the text (its braille runs up to 4 lines, FRLG's dialogue box holds 2).
// RFVF+'s braille strings have no 6-byte brailleformat header.
static EWRAM_DATA u8 sBrailleWindowId = 0;

bool8 ScrCmd_braillewindow(struct ScriptContext *ctx)
{
    const u8 *text = (const u8 *)ScriptReadWord(ctx);
    struct WindowTemplate template;
    s32 i;
    u8 width, height;

    StringExpandPlaceholders(gStringVar4, text);
    width = GetStringWidth(FONT_BRAILLE, gStringVar4, -1) / 8u;
    if (width > 28)
        width = 28;
    for (i = 0, height = 4; gStringVar4[i] != EOS;)
    {
        if (gStringVar4[i++] == CHAR_NEWLINE)
            height += 3;
    }
    if (height > 18)
        height = 18;
    template = SetWindowTemplateFields(0, (30 - (width + 2)) / 2 + 1, (20 - (height + 2)) / 2 + 1, width, height, 15, 0x038);
    sBrailleWindowId = AddWindow(&template);
    LoadStdWindowFrameGfx();
    DrawStdWindowFrame(sBrailleWindowId, FALSE);
    AddTextPrinterParameterized(sBrailleWindowId, FONT_BRAILLE, gStringVar4, 3, 8, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sBrailleWindowId, COPYWIN_FULL);
    return FALSE;
}

bool8 ScrCmd_closebraillewindow(struct ScriptContext *ctx)
{
    ClearStdWindowAndFrame(sBrailleWindowId, TRUE);
    RemoveWindow(sBrailleWindowId);
    return FALSE;
}

// ------------------------------------------------------------------------------------------------ Regi puzzles
// The opened wall: Emerald's six metatiles, (x, y) = top left
static void OpenSealedWall(s32 x, s32 y, u16 flag)
{
    MapGridSetMetatileIdAt(x + 0 + MAP_OFFSET, y + MAP_OFFSET, METATILE_HoennCave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(x + 1 + MAP_OFFSET, y + MAP_OFFSET, METATILE_HoennCave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(x + 2 + MAP_OFFSET, y + MAP_OFFSET, METATILE_HoennCave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt(x + 0 + MAP_OFFSET, y + 1 + MAP_OFFSET, METATILE_HoennCave_SealedChamberEntrance_BottomLeft | MAPGRID_IMPASSABLE);
    MapGridSetMetatileIdAt(x + 1 + MAP_OFFSET, y + 1 + MAP_OFFSET, METATILE_HoennCave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(x + 2 + MAP_OFFSET, y + 1 + MAP_OFFSET, METATILE_HoennCave_SealedChamberEntrance_BottomRight | MAPGRID_IMPASSABLE);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(flag);
    UnlockPlayerFieldControls();
}

// Dig below the outer room's braille
bool8 ShouldDoBrailleDigEffect(void)
{
    return !FlagGet(FLAG_SYS_BRAILLE_DIG) && ON_MAP(SEALED_CHAMBER_OUTER_ROOM)
        && gSaveBlock1Ptr->pos.y == 3 && gSaveBlock1Ptr->pos.x >= 9 && gSaveBlock1Ptr->pos.x <= 11;
}

void DoBrailleDigEffect(void)
{
    OpenSealedWall(9, 1, FLAG_SYS_BRAILLE_DIG);
}

// Emerald: Wailord first, Relicanth last
bool8 CheckRelicanthWailord(void)
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, NULL) == SPECIES_WAILORD)
    {
        CalculatePlayerPartyCount();
        if (GetMonData(&gPlayerParty[gPlayerPartyCount - 1], MON_DATA_SPECIES_OR_EGG, NULL) == SPECIES_RELICANTH)
            return TRUE;
    }
    return FALSE;
}

// Rock Smash in Desert Ruins, Flash in Ancient Tomb, below their braille
bool8 ShouldDoBrailleRegirockEffect(void)
{
    return !FlagGet(FLAG_SYS_REGIROCK_PUZZLE_COMPLETED) && ON_MAP(DESERT_RUINS)
        && gSaveBlock1Ptr->pos.y == 23 && gSaveBlock1Ptr->pos.x >= 5 && gSaveBlock1Ptr->pos.x <= 7;
}

bool8 ShouldDoBrailleRegisteelEffect(void)
{
    return !FlagGet(FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED) && ON_MAP(ANCIENT_TOMB)
        && gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 25;
}

static void OpenTombWall(void)
{
    if (ON_MAP(DESERT_RUINS))
        OpenSealedWall(7, 19, FLAG_SYS_REGIROCK_PUZZLE_COMPLETED);
    else
        OpenSealedWall(7, 19, FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED);
}

// gPostMenuFieldCallback of Rock Smash / Flash on the puzzle tile: the mon shows itself, then the wall opens
void FieldCallback_UseTombPuzzle(void)
{
    u8 taskId = CreateFieldEffectShowMon();

    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FLDEFF_SET_FUNC_TO_DATA(OpenTombWall);
}

// Island Cave: read the braille, walk once along the whole wall (and only there), back to the braille
static const u8 sRegicePathCoords[][2] =
{
    {4, 21}, {5, 21}, {6, 21}, {7, 21}, {8, 21}, {9, 21}, {10, 21}, {11, 21}, {12, 21}, {12, 22}, {12, 23}, {13, 23},
    {13, 24}, {13, 25}, {13, 26}, {13, 27}, {12, 27}, {12, 28}, {4, 29}, {5, 29}, {6, 29}, {7, 29}, {8, 29}, {9, 29},
    {10, 29}, {11, 29}, {12, 29}, {4, 28}, {4, 27}, {3, 27}, {3, 26}, {3, 25}, {3, 24}, {3, 23}, {4, 23}, {4, 22},
};

bool8 ShouldDoBrailleRegicePuzzle(void)
{
    u8 i;

    if (!ON_MAP(ISLAND_CAVE) || FlagGet(FLAG_SYS_BRAILLE_REGICE_COMPLETED)
     || !FlagGet(FLAG_TEMP_REGICE_PUZZLE_STARTED) || FlagGet(FLAG_TEMP_REGICE_PUZZLE_FAILED))
        return FALSE;

    for (i = 0; i < ARRAY_COUNT(sRegicePathCoords); i++)
    {
        if (gSaveBlock1Ptr->pos.x == sRegicePathCoords[i][0] && gSaveBlock1Ptr->pos.y == sRegicePathCoords[i][1])
        {
            u16 var = VAR_REGICE_STEPS_1 + i / 16;

            VarSet(var, VarGet(var) | (1 << (i % 16)));
            if (VarGet(VAR_REGICE_STEPS_1) != 0xFFFF || VarGet(VAR_REGICE_STEPS_2) != 0xFFFF || VarGet(VAR_REGICE_STEPS_3) != 0xF)
                return FALSE;
            return gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 21;
        }
    }
    FlagSet(FLAG_TEMP_REGICE_PUZZLE_FAILED);
    FlagClear(FLAG_TEMP_REGICE_PUZZLE_STARTED);
    return FALSE;
}

// Sealed Chamber's inner room shakes when the doors open
#define tDelayCounter  data[1]
#define tShakeCounter  data[2]
#define tVerticalPan   data[4]
#define tDelay         data[5]
#define tNumShakes     data[6]

static void Task_SealedChamberShakingEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (++task->tDelayCounter % task->tDelay == 0)
    {
        task->tDelayCounter = 0;
        task->tShakeCounter++;
        task->tVerticalPan = -task->tVerticalPan;
        SetCameraPanning(0, task->tVerticalPan);
        if (task->tShakeCounter == task->tNumShakes)
        {
            DestroyTask(taskId);
            ScriptContext_Enable();
            InstallCameraPanAheadCallback();
        }
    }
}

static void StartSealedChamberShake(s16 pan, s16 shakes)
{
    u8 taskId = CreateTask(Task_SealedChamberShakingEffect, 9);

    gTasks[taskId].tDelayCounter = 0;
    gTasks[taskId].tShakeCounter = 0;
    gTasks[taskId].tVerticalPan = pan;
    gTasks[taskId].tDelay = 5;
    gTasks[taskId].tNumShakes = shakes;
    SetCameraPanningCallback(NULL);
}

void DoSealedChamberShakingEffect_Long(void)
{
    StartSealedChamberShake(2, 50);
}

void DoSealedChamberShakingEffect_Short(void)
{
    StartSealedChamberShake(3, 2);
}

// ------------------------------------------------------------------------------------------------ Shoal Cave
// Emerald's tide follows the clock; RFVF+: low tide on even days, high on odd ones. Updated only when coming in from
// outside, as in Emerald, so it never changes under the player's feet.
void UpdateShoalTideFlag(void)
{
    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()))
    {
        if (VarGet(VAR_HOENN_DAY_COUNT) & 1)
            FlagSet(FLAG_SYS_SHOAL_TIDE);
        else
            FlagClear(FLAG_SYS_SHOAL_TIDE);
    }
}

// ------------------------------------------------------------------------------------------------ Abandoned Ship
// VAR_0x8004 = the key's hidden item flag (Emerald's), TRUE if found already
static bool8 FoundAbandonedShipKey(u16 flag)
{
    gSpecialVar_0x8004 = flag;
    return FlagGet(flag);
}

bool8 FoundAbandonedShipRoom1Key(void) { return FoundAbandonedShipKey(FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY); }
bool8 FoundAbandonedShipRoom2Key(void) { return FoundAbandonedShipKey(FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY); }
bool8 FoundAbandonedShipRoom4Key(void) { return FoundAbandonedShipKey(FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY); }
bool8 FoundAbandonedShipRoom6Key(void) { return FoundAbandonedShipKey(FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY); }

// ------------------------------------------------------------------------------------------------ abnormal weather
// From the Hoenn League win, a new route every day among the free legendaries (user's choice; Emerald: one event per
// talk to the Weather Institute's scientist, gone after 1,000 steps). Kyogre / Groudon count as free unless caught or
// knocked out / fled (back after the next League win).
static const u16 sAbnormalWeatherMaps[ABNORMAL_WEATHER_LOCATIONS] =
{
    MAP_ROUTE114, MAP_ROUTE114, MAP_ROUTE115, MAP_ROUTE115, MAP_ROUTE116, MAP_ROUTE116, MAP_ROUTE118, MAP_ROUTE118,
    MAP_ROUTE105, MAP_ROUTE105, MAP_ROUTE125, MAP_ROUTE125, MAP_ROUTE127, MAP_ROUTE127, MAP_ROUTE129, MAP_ROUTE129,
};

static const u8 sAbnormalWeatherMapSecs[ABNORMAL_WEATHER_LOCATIONS] =
{
    MAPSEC_ROUTE_114, MAPSEC_ROUTE_114, MAPSEC_ROUTE_115, MAPSEC_ROUTE_115, MAPSEC_ROUTE_116, MAPSEC_ROUTE_116,
    MAPSEC_ROUTE_118, MAPSEC_ROUTE_118, MAPSEC_ROUTE_105, MAPSEC_ROUTE_105, MAPSEC_ROUTE_125, MAPSEC_ROUTE_125,
    MAPSEC_ROUTE_127, MAPSEC_ROUTE_127, MAPSEC_ROUTE_129, MAPSEC_ROUTE_129,
};

void CreateAbnormalWeatherEvent(void)
{
    bool8 kyogre = !FlagGet(FLAG_CAUGHT_KYOGRE) && !FlagGet(FLAG_DEFEATED_KYOGRE);
    bool8 groudon = !FlagGet(FLAG_CAUGHT_GROUDON) && !FlagGet(FLAG_DEFEATED_GROUDON);
    u16 location = ABNORMAL_WEATHER_NONE;

    if (FlagGet(FLAG_HOENN_GAME_CLEAR))
    {
        if (kyogre && (!groudon || (Random() & 1)))
            location = MARINE_CAVE_LOCATIONS_START + Random() % MARINE_CAVE_LOCATIONS;
        else if (groudon)
            location = TERRA_CAVE_LOCATIONS_START + Random() % TERRA_CAVE_LOCATIONS;
    }
    VarSet(VAR_ABNORMAL_WEATHER_LOCATION, location);
    VarSet(VAR_SHOULD_END_ABNORMAL_WEATHER, 0);
}

// Emerald's: STR_VAR_1 = the route, TRUE for Kyogre's rain, FALSE for Groudon's sun
bool32 GetAbnormalWeatherMapNameAndType(void)
{
    u16 location = VarGet(VAR_ABNORMAL_WEATHER_LOCATION);

    GetMapName(gStringVar1, sAbnormalWeatherMapSecs[location - 1], 0);
    return location >= MARINE_CAVE_LOCATIONS_START;
}

// Called on each step, after HoennDays_OnStep. TRUE: a new day finds the player on the weather's route, where
// Emerald's script ends it with a message (AbnormalWeather_EventScript_EndEventAndCleanup_1, which picks the next one).
bool8 AbnormalWeatherHasExpired(void)
{
    u16 location = VarGet(VAR_ABNORMAL_WEATHER_LOCATION);

    if (VarGet(VAR_HOENN_DAY_STEPS) != 0) // not the step that began a day
        return FALSE;
    if (location == ABNORMAL_WEATHER_NONE)
    {
        CreateAbnormalWeatherEvent();
        return FALSE;
    }
    switch (CURRENT_MAP)
    {
    case MAP_UNDERWATER_MARINE_CAVE:
    case MAP_MARINE_CAVE_ENTRANCE:
    case MAP_MARINE_CAVE_END:
    case MAP_TERRA_CAVE_ENTRANCE:
    case MAP_TERRA_CAVE_END:
    case MAP_UNDERWATER_ROUTE105:
    case MAP_UNDERWATER_ROUTE125:
    case MAP_UNDERWATER_ROUTE127:
    case MAP_UNDERWATER_ROUTE129:
        VarSet(VAR_SHOULD_END_ABNORMAL_WEATHER, 1); // Emerald's: ends back on the route (its ON_FRAME script)
        return FALSE;
    }
    if (CURRENT_MAP == sAbnormalWeatherMaps[location - 1])
        return TRUE;
    CreateAbnormalWeatherEvent();
    return FALSE;
}
