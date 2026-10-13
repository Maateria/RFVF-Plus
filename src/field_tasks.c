#include "global.h"
#include "gflib.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "field_camera.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "item.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "quest_log.h"
#include "script.h"
#include "task.h"
#include "constants/field_tasks.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/metatile_labels.h"
#include "constants/songs.h"

/*  This file handles some persistent tasks that run in the overworld.
 *  - Task_RunTimeBasedEvents: Triggers ambient cries. In RSE, this also periodically updates local time and RTC events.
 *  - Task_RunPerStepCallback: Calls one of the functions in sPerStepCallbacks, listed below...
 *      . DummyPerStepCallback: Default, does nothing. Includes functionality from RS that was removed.
 *      . AshGrassPerStepCallback: Leftover from RS. Removes the ash from ash-covered grass that the player steps on.
 *      . IcefallCaveIcePerStepCallback: Cracks/breaks ice in Icefall Cave that the player steps on.
 *      . CrackedFloorPerStepCallback: Leftover from RS. Breaks cracked floors that the player steps on.
 *
 *  NOTE: "PerStep" is perhaps misleading. One function in sPerStepCallbacks is called
 *        every frame while in the overworld by Task_RunPerStepCallback regardless of
 *        whether or not steps are being taken. However, nearly all of the functions in
 *        the table check if the player has moved from their previous position before
 *        doing anything else.
 */

static void DummyPerStepCallback(u8 taskId);
static void AshGrassPerStepCallback(u8 taskId);
static void FortreeBridgePerStepCallback(u8 taskId);
static void PacifidlogBridgePerStepCallback(u8 taskId);
static void IcefallCaveIcePerStepCallback(u8 taskId);
static void CrackedFloorPerStepCallback(u8 taskId);

// Fortree and Pacifidlog: pokeemerald's callbacks, set by those Hoenn maps' OnResume scripts (Emerald's)
static const TaskFunc sPerStepCallbacks[] =
{
    [STEP_CB_DUMMY]             = DummyPerStepCallback,
    [STEP_CB_ASH]               = AshGrassPerStepCallback,
    [STEP_CB_FORTREE_BRIDGE]    = FortreeBridgePerStepCallback,
    [STEP_CB_PACIFIDLOG_BRIDGE] = PacifidlogBridgePerStepCallback,
    [STEP_CB_ICE]               = IcefallCaveIcePerStepCallback,
    [STEP_CB_TRUCK]             = DummyPerStepCallback,
    [STEP_CB_SECRET_BASE]       = DummyPerStepCallback,
    [STEP_CB_CRACKED_FLOOR]     = CrackedFloorPerStepCallback
};

// The positions of each map space with crackable ice in Icefall Cave.
static const u8 sIcefallCaveIceCoords[][2] =
{
    {  8,  3 },
    { 10,  5 },
    { 15,  5 },
    {  8,  9 },
    {  9,  9 },
    { 16,  9 },
    {  8, 10 },
    {  9, 10 },
    {  8, 14 }
};

#define tCallbackId data[0]

static void Task_RunPerStepCallback(u8 taskId)
{
    int idx = gTasks[taskId].tCallbackId;
    sPerStepCallbacks[idx](taskId);
}

#define tAmbientCryState data[1]
#define tAmbientCryDelay data[2]

// RTC functionality from RS was removed here.
static void Task_RunTimeBasedEvents(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!ArePlayerFieldControlsLocked() && !QL_IS_PLAYBACK_STATE)
        UpdateAmbientCry(&tAmbientCryState, &tAmbientCryDelay);
}

void SetUpFieldTasks(void)
{
    if (!FuncIsActiveTask(Task_RunPerStepCallback))
    {
        u8 taskId = CreateTask(Task_RunPerStepCallback, 80);
        gTasks[taskId].tCallbackId = STEP_CB_DUMMY;
    }

    if (!FuncIsActiveTask(Task_RunTimeBasedEvents))
        CreateTask(Task_RunTimeBasedEvents, 80);
}

void ActivatePerStepCallback(u8 callbackId)
{
    u8 taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != TASK_NONE)
    {
        s32 i;
        s16 *data = gTasks[taskId].data;

        for (i = 0; i < NUM_TASK_DATA; i++)
            data[i] = 0;

        if (callbackId >= ARRAY_COUNT(sPerStepCallbacks))
            tCallbackId = STEP_CB_DUMMY;
        else
            tCallbackId = callbackId;
    }
}

void ResetFieldTasksArgs(void)
{
    u8 taskId;
    s16 *data;

    taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != TASK_NONE)
        data = gTasks[taskId].data;

    taskId = FindTaskIdByFunc(Task_RunTimeBasedEvents);
    if (taskId != TASK_NONE)
    {
        data = gTasks[taskId].data;
        tAmbientCryState = 0;
        tAmbientCryDelay = 0;
    }
}

#undef tAmbientCryState
#undef tAmbientCryDelay

static void DummyPerStepCallback(u8 taskId)
{
}

static void MarkIcePuzzleCoordVisited(s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sIcefallCaveIceCoords); i++)
    {
        if (sIcefallCaveIceCoords[i][0] + MAP_OFFSET == x && sIcefallCaveIceCoords[i][1] + MAP_OFFSET == y)
        {
            FlagSet(i + 1);
            break;
        }
    }
}

void SetIcefallCaveCrackedIceMetatiles(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sIcefallCaveIceCoords); i++)
    {
        if (FlagGet(i + 1) == TRUE)
        {
            int x = sIcefallCaveIceCoords[i][0] + MAP_OFFSET;
            int y = sIcefallCaveIceCoords[i][1] + MAP_OFFSET;
            MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
        }
    }
}

#define tState data[1]
#define tPrevX data[2]
#define tPrevY data[3]
#define tIceX  data[4]
#define tIceY  data[5]
#define tDelay data[6]

static void IcefallCaveIcePerStepCallback(u8 taskId)
{
    s16 x, y;
    u8 tileBehavior;
    u16 *iceStepCount;
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
        case 0:
            PlayerGetDestCoords(&x, &y);
            tPrevX = x;
            tPrevY = y;
            tState = 1;
            break;
        case 1:
            PlayerGetDestCoords(&x, &y);
            // End if player hasn't moved
            if (x == tPrevX && y == tPrevY)
                return;

            tPrevX = x;
            tPrevY = y;
            tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
            if (MetatileBehavior_IsThinIce(tileBehavior) == TRUE)
            {
                // Thin ice, set it to cracked ice
                MarkIcePuzzleCoordVisited(x, y);
                tDelay = 4;
                tState = 2;
                tIceX = x;
                tIceY = y;
            }
            else if (MetatileBehavior_IsCrackedIce(tileBehavior) == TRUE)
            {
                // Cracked ice, set it to broken ice
                tDelay = 4;
                tState = 3;
                tIceX = x;
                tIceY = y;
            }
            break;
        case 2:
            if (tDelay != 0)
            {
                tDelay--;
            }
            else
            {
                // Crack ice
                x = tIceX;
                y = tIceY;
                PlaySE(SE_ICE_CRACK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
                CurrentMapDrawMetatileAt(x, y);
                tState = 1;
            }
            break;
        case 3:
            FreezeObjects_WaitForPlayer();
            if (tDelay != 0)
            {
                tDelay--;
            }
            else
            {
                // Break ice
                x = tIceX;
                y = tIceY;
                PlaySE(SE_ICE_BREAK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_IceHole);
                CurrentMapDrawMetatileAt(x, y);
                VarSet(VAR_TEMP_1, 1);
                tState = 1;
            }
            break;
    }
}

#undef tState
#undef tPrevX
#undef tPrevY
#undef tIceX
#undef tIceY
#undef tDelay

#define tPrevX data[1]
#define tPrevY data[2]

static void AshGrassPerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 *ashGatherCount;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);

    // End if player hasn't moved
    if (x == tPrevX && y == tPrevY)
        return;

    tPrevX = x;
    tPrevY = y;
    if (MetatileBehavior_IsAshGrass((u8)MapGridGetMetatileBehaviorAt(x, y)))
    {
        // Hoenn (Route 113, Jagged Pass): pokeemerald's choice, Fallarbor's ash grass or else Lavaridge's
        if (IsHoennMapLayout())
            StartAshFieldEffect(x, y, MapGridGetMetatileIdAt(x, y) == METATILE_HoennFallarbor_AshGrass
                                      ? METATILE_HoennFallarbor_NormalGrass : METATILE_HoennLavaridge_NormalGrass, 4);
        else if (MapGridGetMetatileIdAt(x, y) == METATILE_SeviiIslands123_OneIsland_AshGrass)
            StartAshFieldEffect(x, y, METATILE_SeviiIslands123_OneIsland_Grass, 4);

        if (CheckBagHasItem(ITEM_SOOT_SACK, 1))
        {
            ashGatherCount = GetVarPointer(VAR_ASH_GATHER_COUNT);
            if (*ashGatherCount < 9999)
                (*ashGatherCount)++;
        }
    }
}

#undef tPrevX
#undef tPrevY

// Pacifidlog log bridges and Fortree bridges, from pokeemerald src/field_tasks.c (vanilla behavior, BUGFIX not
// applied), with the Hoenn import's metatile ids. Each pair: the two metatiles of one log and their offsets, for a
// player on the top / bottom of a vertical log, then the left / right of a horizontal one.
struct PacifidlogMetatileOffsets
{
    s8 x;
    s8 y;
    u16 metatileId;
};

static const struct PacifidlogMetatileOffsets sHalfSubmergedBridgeMetatileOffsets[] =
{
    { 0,  0, METATILE_HoennPacifidlog_HalfSubmergedLogs_VerticalTop}, {0, 1, METATILE_HoennPacifidlog_HalfSubmergedLogs_VerticalBottom},
    { 0, -1, METATILE_HoennPacifidlog_HalfSubmergedLogs_VerticalTop}, {0, 0, METATILE_HoennPacifidlog_HalfSubmergedLogs_VerticalBottom},
    { 0,  0, METATILE_HoennPacifidlog_HalfSubmergedLogs_HorizontalLeft}, {1, 0, METATILE_HoennPacifidlog_HalfSubmergedLogs_HorizontalRight},
    {-1,  0, METATILE_HoennPacifidlog_HalfSubmergedLogs_HorizontalLeft}, {0, 0, METATILE_HoennPacifidlog_HalfSubmergedLogs_HorizontalRight}
};

static const struct PacifidlogMetatileOffsets sFullySubmergedBridgeMetatileOffsets[] =
{
    { 0,  0, METATILE_HoennPacifidlog_SubmergedLogs_VerticalTop}, {0, 1, METATILE_HoennPacifidlog_SubmergedLogs_VerticalBottom},
    { 0, -1, METATILE_HoennPacifidlog_SubmergedLogs_VerticalTop}, {0, 0, METATILE_HoennPacifidlog_SubmergedLogs_VerticalBottom},
    { 0,  0, METATILE_HoennPacifidlog_SubmergedLogs_HorizontalLeft}, {1, 0, METATILE_HoennPacifidlog_SubmergedLogs_HorizontalRight},
    {-1,  0, METATILE_HoennPacifidlog_SubmergedLogs_HorizontalLeft}, {0, 0, METATILE_HoennPacifidlog_SubmergedLogs_HorizontalRight}
};

static const struct PacifidlogMetatileOffsets sFloatingBridgeMetatileOffsets[] =
{
    { 0,  0, METATILE_HoennPacifidlog_FloatingLogs_VerticalTop}, {0, 1, METATILE_HoennPacifidlog_FloatingLogs_VerticalBottom},
    { 0, -1, METATILE_HoennPacifidlog_FloatingLogs_VerticalTop}, {0, 0, METATILE_HoennPacifidlog_FloatingLogs_VerticalBottom},
    { 0,  0, METATILE_HoennPacifidlog_FloatingLogs_HorizontalLeft}, {1, 0, METATILE_HoennPacifidlog_FloatingLogs_HorizontalRight},
    {-1,  0, METATILE_HoennPacifidlog_FloatingLogs_HorizontalLeft}, {0, 0, METATILE_HoennPacifidlog_FloatingLogs_HorizontalRight}
};

static const struct PacifidlogMetatileOffsets *GetPacifidlogBridgeMetatileOffsets(const struct PacifidlogMetatileOffsets *offsets, u16 metatileBehavior)
{
    if (MetatileBehavior_IsPacifidlogVerticalLogTop(metatileBehavior))
        return &offsets[0 * 2];
    else if (MetatileBehavior_IsPacifidlogVerticalLogBottom(metatileBehavior))
        return &offsets[1 * 2];
    else if (MetatileBehavior_IsPacifidlogHorizontalLogLeft(metatileBehavior))
        return &offsets[2 * 2];
    else if (MetatileBehavior_IsPacifidlogHorizontalLogRight(metatileBehavior))
        return &offsets[3 * 2];
    else
        return NULL;
}

static void TrySetPacifidlogBridgeMetatiles(const struct PacifidlogMetatileOffsets *offsets, s16 x, s16 y, bool32 redrawMap)
{
    offsets = GetPacifidlogBridgeMetatileOffsets(offsets, MapGridGetMetatileBehaviorAt(x, y));
    if (offsets)
    {
        MapGridSetMetatileIdAt(x + offsets[0].x, y + offsets[0].y, offsets[0].metatileId);
        if (redrawMap)
            CurrentMapDrawMetatileAt(x + offsets[0].x, y + offsets[0].y);

        MapGridSetMetatileIdAt(x + offsets[1].x, y + offsets[1].y, offsets[1].metatileId);
        if (redrawMap)
            CurrentMapDrawMetatileAt(x + offsets[1].x, y + offsets[1].y);
    }
}

static void TrySetLogBridgeHalfSubmerged(s16 x, s16 y, bool32 redrawMap)
{
    TrySetPacifidlogBridgeMetatiles(sHalfSubmergedBridgeMetatileOffsets, x, y, redrawMap);
}

static void TrySetLogBridgeFullySubmerged(s16 x, s16 y, bool32 redrawMap)
{
    TrySetPacifidlogBridgeMetatiles(sFullySubmergedBridgeMetatileOffsets, x, y, redrawMap);
}

static void TrySetLogBridgeFloating(s16 x, s16 y, bool32 redrawMap)
{
    TrySetPacifidlogBridgeMetatiles(sFloatingBridgeMetatileOffsets, x, y, redrawMap);
}

// FALSE if the player moved from one end of a log to its other end (the log stays down)
static bool32 ShouldRaisePacifidlogLogs(s16 newX, s16 newY, s16 oldX, s16 oldY)
{
    u16 oldBehavior = MapGridGetMetatileBehaviorAt(oldX, oldY);

    if (MetatileBehavior_IsPacifidlogVerticalLogTop(oldBehavior))
    {
        if (newY > oldY)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogVerticalLogBottom(oldBehavior))
    {
        if (newY < oldY)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogHorizontalLogLeft(oldBehavior))
    {
        if (newX > oldX)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogHorizontalLogRight(oldBehavior))
    {
        if (newX < oldX)
            return FALSE;
    }
    return TRUE;
}

static bool32 ShouldSinkPacifidlogLogs(s16 newX, s16 newY, s16 oldX, s16 oldY)
{
    u16 newBehavior = MapGridGetMetatileBehaviorAt(newX, newY);

    if (MetatileBehavior_IsPacifidlogVerticalLogTop(newBehavior))
    {
        if (newY < oldY)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogVerticalLogBottom(newBehavior))
    {
        if (newY > oldY)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogHorizontalLogLeft(newBehavior))
    {
        if (newX < oldX)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogHorizontalLogRight(newBehavior))
    {
        if (newX > oldX)
            return FALSE;
    }
    return TRUE;
}

#define tState    data[1]
#define tPrevX    data[2]
#define tPrevY    data[3]
#define tToRaiseX data[4]
#define tToRaiseY data[5]
#define tDelay    data[6]

static void PacifidlogBridgePerStepCallback(u8 taskId)
{
    s16 *data;
    s16 x, y;
    data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    switch (tState)
    {
    case 0:
        tPrevX = x;
        tPrevY = y;
        // Already on a log when the callback is set: it sinks at once
        TrySetLogBridgeFullySubmerged(x, y, TRUE);
        tState = 1;
        break;
    case 1:
        if (x == tPrevX && y == tPrevY)
            return;

        if (ShouldRaisePacifidlogLogs(x, y, tPrevX, tPrevY))
        {
            // The log left behind rises (half-submerged now, floating in state 2)
            TrySetLogBridgeHalfSubmerged(tPrevX, tPrevY, TRUE);
            TrySetLogBridgeFloating(tPrevX, tPrevY, FALSE);
            tToRaiseX = tPrevX;
            tToRaiseY = tPrevY;
            tState = 2;
            tDelay = 8;
        }
        else
        {
            tToRaiseX = -1;
            tToRaiseY = -1;
        }

        if (ShouldSinkPacifidlogLogs(x, y, tPrevX, tPrevY))
        {
            TrySetLogBridgeHalfSubmerged(x, y, TRUE);
            tState = 2;
            tDelay = 8;
        }

        tPrevX = x;
        tPrevY = y;
        if (MetatileBehavior_IsPacifidlogLog(MapGridGetMetatileBehaviorAt(x, y)))
            PlaySE(SE_PUDDLE);
        break;
    case 2:
        if (--tDelay == 0)
        {
            TrySetLogBridgeFullySubmerged(x, y, TRUE);
            if (tToRaiseX != -1 && tToRaiseY != -1)
                TrySetLogBridgeFloating(tToRaiseX, tToRaiseY, TRUE);
            tState = 1;
        }
        break;
    }
}

#undef tState
#undef tPrevX
#undef tPrevY
#undef tToRaiseX
#undef tToRaiseY
#undef tDelay

// Only from above: a player under the bridge stands at an odd elevation
static void TryLowerFortreeBridge(s16 x, s16 y)
{
    u8 elevation = PlayerGetElevation();
    if (!(elevation & 1))
    {
        switch (MapGridGetMetatileIdAt(x, y))
        {
        case METATILE_HoennFortree_BridgeOverGrass_Raised:
            MapGridSetMetatileIdAt(x, y, METATILE_HoennFortree_BridgeOverGrass_Lowered);
            break;
        case METATILE_HoennFortree_BridgeOverTrees_Raised:
            MapGridSetMetatileIdAt(x, y, METATILE_HoennFortree_BridgeOverTrees_Lowered);
            break;
        }
    }
}

static void TryRaiseFortreeBridge(s16 x, s16 y)
{
    u8 elevation = PlayerGetElevation();
    if (!(elevation & 1))
    {
        switch (MapGridGetMetatileIdAt(x, y))
        {
        case METATILE_HoennFortree_BridgeOverGrass_Lowered:
            MapGridSetMetatileIdAt(x, y, METATILE_HoennFortree_BridgeOverGrass_Raised);
            break;
        case METATILE_HoennFortree_BridgeOverTrees_Lowered:
            MapGridSetMetatileIdAt(x, y, METATILE_HoennFortree_BridgeOverTrees_Raised);
            break;
        }
    }
}

#define tState      data[1]
#define tPrevX      data[2]
#define tPrevY      data[3]
#define tOldBridgeX data[4]
#define tOldBridgeY data[5]
#define tBounceTime data[6]

static void FortreeBridgePerStepCallback(u8 taskId)
{
    bool8 isFortreeBridgeCur;
    bool8 isFortreeBridgePrev;
    u8 elevation, onBridgeElevation;
    s16 x, y, prevX, prevY;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    switch (tState)
    {
    default:
        break;
    case 0:
        tPrevX = x;
        tPrevY = y;
        if (MetatileBehavior_IsFortreeBridge(MapGridGetMetatileBehaviorAt(x, y)))
        {
            TryLowerFortreeBridge(x, y);
            CurrentMapDrawMetatileAt(x, y);
        }
        tState = 1;
        break;
    case 1:
        prevX = tPrevX;
        prevY = tPrevY;
        if (x == prevX && y == prevY)
            break;

        isFortreeBridgeCur = MetatileBehavior_IsFortreeBridge(MapGridGetMetatileBehaviorAt(x, y));
        isFortreeBridgePrev = MetatileBehavior_IsFortreeBridge(MapGridGetMetatileBehaviorAt(prevX, prevY));

        elevation = PlayerGetElevation();
        onBridgeElevation = FALSE;
        if ((u8)(elevation & 1) == 0)
            onBridgeElevation = TRUE;

        if (onBridgeElevation && (isFortreeBridgeCur == TRUE || isFortreeBridgePrev == TRUE))
            PlaySE(SE_BRIDGE_WALK);

        // As in Emerald: a section is not lowered when stepped on from something other than another section
        if (isFortreeBridgePrev)
        {
            TryRaiseFortreeBridge(prevX, prevY);
            CurrentMapDrawMetatileAt(prevX, prevY);
            TryLowerFortreeBridge(x, y);
            CurrentMapDrawMetatileAt(x, y);
        }

        tOldBridgeX = prevX;
        tOldBridgeY = prevY;
        tPrevX = x;
        tPrevY = y;
        if (!isFortreeBridgePrev)
            break;

        tBounceTime = 16;
        tState = 2;
        // fallthrough
    case 2:
        tBounceTime--;
        prevX = tOldBridgeX;
        prevY = tOldBridgeY;
        switch (tBounceTime % 7)
        {
        case 0:
            CurrentMapDrawMetatileAt(prevX, prevY);
        case 1:
        case 2:
        case 3:
            break;
        case 4:
            // The section just left bounces
            TryLowerFortreeBridge(prevX, prevY);
            CurrentMapDrawMetatileAt(prevX, prevY);
            TryRaiseFortreeBridge(prevX, prevY);
        case 5:
        case 6:
            break;
        }
        if (tBounceTime == 0)
            tState = 1;
        break;
    }
}

#undef tState
#undef tPrevX
#undef tPrevY
#undef tOldBridgeX
#undef tOldBridgeY
#undef tBounceTime

// Unused. For some reason these were not dummied out like the other RSE-exclusive step callbacks.
static void SetCrackedFloorHoleMetatile(s16 x, s16 y)
{
    MapGridSetMetatileIdAt(x, y, MapGridGetMetatileIdAt(x, y) == METATILE_RSCave_CrackedFloor ? METATILE_RSCave_CrackedFloor_Hole : METATILE_Pacifidlog_SkyPillar_CrackedFloor_Hole);
    CurrentMapDrawMetatileAt(x, y);
}

#define tPrevX       data[2]
#define tPrevY       data[3]
#define tFloor1Delay data[4]
#define tFloor1X     data[5]
#define tFloor1Y     data[6]
#define tFloor2Delay data[7]
#define tFloor2X     data[8]
#define tFloor2Y     data[9]

// Unused. See above.
static void CrackedFloorPerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 behavior;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);

    // Update up to 2 previous cracked floor spaces
    if (tFloor1Delay != 0 && (--tFloor1Delay) == 0)
        SetCrackedFloorHoleMetatile(tFloor1X, tFloor1Y);
    if (tFloor2Delay != 0 && (--tFloor2Delay) == 0)
        SetCrackedFloorHoleMetatile(tFloor2X, tFloor2Y);

    // End if player hasn't moved
    if (x == tPrevX && y == tPrevY)
        return;

    tPrevX = x;
    tPrevY = y;
    if (MetatileBehavior_IsCrackedFloor(behavior))
    {
        if (GetPlayerSpeed() != PLAYER_SPEED_FASTEST)
            VarSet(VAR_ICE_STEP_COUNT, 0); // this var does double duty

        if (tFloor1Delay == 0)
        {
            tFloor1Delay = 3;
            tFloor1X = x;
            tFloor1Y = y;
        }
        else if (tFloor2Delay == 0)
        {
            tFloor2Delay = 3;
            tFloor2X = x;
            tFloor2Y = y;
        }
    }
}

#undef tPrevX
#undef tPrevY
#undef tFloor1Delay
#undef tFloor1X
#undef tFloor1Y
#undef tFloor2Delay
#undef tFloor2X
#undef tFloor2Y
