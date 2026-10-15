// Hoenn's gyms (Emerald's field_specials.c and field_tasks.c): Mauville's switches, Petalburg's sliding doors,
// Sootopolis's ice, plus what RFVF+ adds around them (Hoenn badge count, gym leader rematches).
#include "global.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "constants/metatile_labels.h"
#include "constants/songs.h"

#define MAPGRID_IMPASSABLE MAPGRID_COLLISION_MASK

void CountHoennBadges(void)
{
    u16 flag;

    gSpecialVar_Result = 0;
    for (flag = FLAG_HOENN_BADGE01_GET; flag <= FLAG_HOENN_BADGE08_GET; flag++)
        if (FlagGet(flag))
            gSpecialVar_Result++;
}

// After Hoenn's Hall of Fame, a gym leader rematches when talked to (Emerald's Match Call), without the VS Seeker
void SetLastTalkedTrainerReadyForRematch(void)
{
    gSaveBlock1Ptr->trainerRematches[gSpecialVar_LastTalked] = TRUE;
}

static const struct UCoords8 sMauvilleGymSwitchCoords[] =
{
    { 0 + MAP_OFFSET, 15 + MAP_OFFSET},
    { 4 + MAP_OFFSET, 12 + MAP_OFFSET},
    { 3 + MAP_OFFSET,  9 + MAP_OFFSET},
    { 8 + MAP_OFFSET,  9 + MAP_OFFSET}
};

// Presses the stepped-on switch and raises the rest
void MauvilleGymPressSwitch(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sMauvilleGymSwitchCoords); i++)
    {
        if (i == gSpecialVar_0x8004)
            MapGridSetMetatileIdAt(sMauvilleGymSwitchCoords[i].x, sMauvilleGymSwitchCoords[i].y, METATILE_HoennMauvilleGym_PressedSwitch);
        else
            MapGridSetMetatileIdAt(sMauvilleGymSwitchCoords[i].x, sMauvilleGymSwitchCoords[i].y, METATILE_HoennMauvilleGym_RaisedSwitch);
    }
}

// Sets the gym barriers back to the default state; their alt state is handled by MauvilleCity_Gym_EventScript_SetAltBarriers
void MauvilleGymSetDefaultBarriers(void)
{
    int x, y;
    // All switches/barriers are within these coord ranges
    for (y = 5 + MAP_OFFSET; y < 17 + MAP_OFFSET; y++)
    {
        for (x = 0 + MAP_OFFSET; x < 9 + MAP_OFFSET; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
            case METATILE_HoennMauvilleGym_GreenBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH1_Off);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH2_Off);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH3_Off);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH4_Off);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH1_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH1_On);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH2_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH2_On);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH3_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH3_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH4_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH4_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH1_Off);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH2_Off);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH3_Off);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH4_Off);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH1_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH1_On);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH2_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH2_On);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH3_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH3_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH4_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH4_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_PoleBottom_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamV2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_FloorTile);
                break;
            case METATILE_HoennMauvilleGym_RedBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_PoleBottom_Off | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_RedBeamV2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_FloorTile);
                break;
            case METATILE_HoennMauvilleGym_PoleBottom_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamV1_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_FloorTile:
                if (MapGridGetMetatileIdAt(x, y - 1) == METATILE_HoennMauvilleGym_GreenBeamV1_On)
                    MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamV2_On | MAPGRID_IMPASSABLE);
                else
                    MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamV2_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_PoleBottom_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamV1_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_PoleTop_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_PoleTop_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_PoleTop_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_PoleTop_Off);
                break;
            }
        }
    }
}

// Presses all switches and deactivates all beams.
void MauvilleGymDeactivatePuzzle(void)
{
    int i, x, y;
    const struct UCoords8 *switchCoords = sMauvilleGymSwitchCoords;
    for (i = ARRAY_COUNT(sMauvilleGymSwitchCoords) - 1; i >= 0; i--)
    {
        MapGridSetMetatileIdAt(switchCoords->x, switchCoords->y, METATILE_HoennMauvilleGym_PressedSwitch);
        switchCoords++;
    }
    for (y = 5 + MAP_OFFSET; y < 17 + MAP_OFFSET; y++)
    {
        for (x = 0 + MAP_OFFSET; x < 9 + MAP_OFFSET; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
            case METATILE_HoennMauvilleGym_GreenBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH1_Off);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH2_Off);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH3_Off);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_GreenBeamH4_Off);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH1_Off);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH2_Off);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH3_Off);
                break;
            case METATILE_HoennMauvilleGym_RedBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_RedBeamH4_Off);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_PoleBottom_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_RedBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_PoleBottom_Off | MAPGRID_IMPASSABLE);
                break;
            case METATILE_HoennMauvilleGym_GreenBeamV2_On:
            case METATILE_HoennMauvilleGym_RedBeamV2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_FloorTile);
                break;
            case METATILE_HoennMauvilleGym_PoleTop_On:
                MapGridSetMetatileIdAt(x, y, METATILE_HoennMauvilleGym_PoleTop_Off);
                break;
            }
        }
    }
}

static EWRAM_DATA u8 sSlidingDoorNextFrameCounter = 0;
static EWRAM_DATA u8 sSlidingDoorFrame = 0;

static const bool8 sSlidingDoorNextFrameDelay[] = {0, 1, 1, 1, 1};

static const u16 sPetalburgGymSlidingDoorMetatiles[] = {
    METATILE_HoennPetalburgGym_SlidingDoor_Frame0,
    METATILE_HoennPetalburgGym_SlidingDoor_Frame1,
    METATILE_HoennPetalburgGym_SlidingDoor_Frame2,
    METATILE_HoennPetalburgGym_SlidingDoor_Frame3,
    METATILE_HoennPetalburgGym_SlidingDoor_Frame4,
};

static void PetalburgGymSetDoorMetatiles(u8 roomNumber, u16 metatileId)
{
    u16 doorCoordsX[4];
    u16 doorCoordsY[4];
    u8 i;
    u8 nDoors = 0;
    switch (roomNumber)
    {
    case 1:
        nDoors = 2;
        doorCoordsX[0] = 1;
        doorCoordsX[1] = 7;
        doorCoordsY[0] = 104;
        doorCoordsY[1] = 104;
        break;
    case 2:
        nDoors = 2;
        doorCoordsX[0] = 1;
        doorCoordsX[1] = 7;
        doorCoordsY[0] = 78;
        doorCoordsY[1] = 78;
        break;
    case 3:
        nDoors = 2;
        doorCoordsX[0] = 1;
        doorCoordsX[1] = 7;
        doorCoordsY[0] = 91;
        doorCoordsY[1] = 91;
        break;
    case 4:
        nDoors = 1;
        doorCoordsX[0] = 7;
        doorCoordsY[0] = 39;
        break;
    case 5:
        nDoors = 2;
        doorCoordsX[0] = 1;
        doorCoordsX[1] = 7;
        doorCoordsY[0] = 52;
        doorCoordsY[1] = 52;
        break;
    case 6:
        nDoors = 1;
        doorCoordsX[0] = 1;
        doorCoordsY[0] = 65;
        break;
    case 7:
        nDoors = 1;
        doorCoordsX[0] = 7;
        doorCoordsY[0] = 13;
        break;
    case 8:
        nDoors = 1;
        doorCoordsX[0] = 1;
        doorCoordsY[0] = 26;
        break;
    }
    for (i = 0; i < nDoors; i++)
    {
        MapGridSetMetatileIdAt(doorCoordsX[i] + MAP_OFFSET, doorCoordsY[i] + MAP_OFFSET, metatileId | MAPGRID_IMPASSABLE);
        MapGridSetMetatileIdAt(doorCoordsX[i] + MAP_OFFSET, doorCoordsY[i] + MAP_OFFSET + 1, (metatileId + 8) | MAPGRID_IMPASSABLE);
    }
    DrawWholeMapView();
}

static void Task_PetalburgGymSlideOpenRoomDoors(u8 taskId)
{
    if (sSlidingDoorNextFrameDelay[sSlidingDoorFrame] == sSlidingDoorNextFrameCounter)
    {
        PetalburgGymSetDoorMetatiles(gSpecialVar_0x8004, sPetalburgGymSlidingDoorMetatiles[sSlidingDoorFrame]);
        sSlidingDoorNextFrameCounter = 0;
        if ((++sSlidingDoorFrame) == ARRAY_COUNT(sPetalburgGymSlidingDoorMetatiles))
        {
            DestroyTask(taskId);
            ScriptContext_Enable();
        }
    }
    else
    {
        sSlidingDoorNextFrameCounter++;
    }
}

void PetalburgGymSlideOpenRoomDoors(void)
{
    sSlidingDoorNextFrameCounter = 0;
    sSlidingDoorFrame = 0;
    PlaySE(SE_UNLOCK);
    CreateTask(Task_PetalburgGymSlideOpenRoomDoors, 8);
}

void PetalburgGymUnlockRoomDoors(void)
{
    PetalburgGymSetDoorMetatiles(gSpecialVar_0x8004, sPetalburgGymSlidingDoorMetatiles[4]);
}

// Each element corresponds to a y coordinate row in the Sootopolis Gym 1F map.
// The rows with ice each have a temp var used to track the ice steps. Each bit in the var
// represents whether ice at that x coordinate (starting from the left edge) has been visited.
static const u16 sSootopolisGymIceRowVars[] =
{
    0, 0, 0, 0, 0, 0,
    VAR_TEMP_1, VAR_TEMP_2, VAR_TEMP_3, VAR_TEMP_4,
    0, 0,
    VAR_TEMP_5, VAR_TEMP_6, VAR_TEMP_7,
    0, 0,
    VAR_TEMP_8, VAR_TEMP_9, VAR_TEMP_A,
    0, 0, 0, 0, 0, 0
};

// Boundaries of the ice puzzle in Sootopolis Gym
#define ICE_PUZZLE_L 3
#define ICE_PUZZLE_R 13
#define ICE_PUZZLE_T 6
#define ICE_PUZZLE_B 19

#define ICE_PUZZLE_WIDTH  (ICE_PUZZLE_R - ICE_PUZZLE_L + 1)
#define ICE_PUZZLE_HEIGHT (ICE_PUZZLE_B - ICE_PUZZLE_T + 1)

static bool32 CoordInIcePuzzleRegion(s16 x, s16 y)
{
    if ((u16)(x - ICE_PUZZLE_L) < ICE_PUZZLE_WIDTH
     && (u16)(y - ICE_PUZZLE_T) < ICE_PUZZLE_HEIGHT
     && sSootopolisGymIceRowVars[y])
        return TRUE;
    else
        return FALSE;
}

static void MarkIcePuzzleCoordVisited(s16 x, s16 y)
{
    if (CoordInIcePuzzleRegion(x, y))
        *GetVarPointer(sSootopolisGymIceRowVars[y]) |= (1 << (x - ICE_PUZZLE_L));
}

static bool32 IsIcePuzzleCoordVisited(s16 x, s16 y)
{
    if (!CoordInIcePuzzleRegion(x, y))
        return FALSE;
    return (VarGet(sSootopolisGymIceRowVars[y]) & (1 << (x - ICE_PUZZLE_L))) != 0;
}

void SetSootopolisGymCrackedIceMetatiles(void)
{
    s32 x, y;
    s32 width = gMapHeader.mapLayout->width;
    s32 height = gMapHeader.mapLayout->height;
    for (x = 0; x < width; x++)
    {
        for (y = 0; y < height; y++)
        {
            if (IsIcePuzzleCoordVisited(x, y) == TRUE)
                MapGridSetMetatileIdAt(x + MAP_OFFSET, y + MAP_OFFSET, METATILE_HoennSootopolisGym_Ice_Cracked);
        }
    }
}

#define tState  data[1]
#define tPrevX  data[2]
#define tPrevY  data[3]
#define tIceX   data[4]
#define tIceY   data[5]
#define tDelay  data[6]

// STEP_CB_SOOTOPOLIS_ICE: cracks/breaks the ice of Sootopolis Gym that the player steps on
void SootopolisGymIcePerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 tileBehavior;
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
        iceStepCount = GetVarPointer(VAR_ICE_STEP_COUNT);
        if (MetatileBehavior_IsThinIce(tileBehavior) == TRUE)
        {
            // Thin ice, set it to cracked ice
            (*iceStepCount)++;
            tDelay = 4;
            tState = 2;
            tIceX = x;
            tIceY = y;
        }
        else if (MetatileBehavior_IsCrackedIce(tileBehavior) == TRUE)
        {
            // Cracked ice, set it to broken ice
            *iceStepCount = 0;
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
            MapGridSetMetatileIdAt(x, y, METATILE_HoennSootopolisGym_Ice_Cracked);
            CurrentMapDrawMetatileAt(x, y);
            MarkIcePuzzleCoordVisited(x - MAP_OFFSET, y - MAP_OFFSET);
            tState = 1;
        }
        break;
    case 3:
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
            MapGridSetMetatileIdAt(x, y, METATILE_HoennSootopolisGym_Ice_Broken);
            CurrentMapDrawMetatileAt(x, y);
            tState = 1;
        }
        break;
    }
}

// Trick House: the End room's hidden Nugget shows only after the 8th puzzle (Emerald's field_specials.c)
void SetTrickHouseNuggetFlag(void)
{
    gSpecialVar_0x8004 = FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET;
    FlagSet(FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET);
}

void ResetTrickHouseNuggetFlag(void)
{
    gSpecialVar_0x8004 = FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET;
    FlagClear(FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET);
}
