#include "global.h"
#include "bike.h"
#include "field_player_avatar.h"
#include "metatile_behavior.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "overworld.h"
#include "constants/map_types.h"
#include "constants/songs.h"
#include "constants/flags.h"
#include "quest_log.h"
#include "constants/event_object_movement.h"

static u8 GetBikeTransitionId(u8 *, u16, u16);
static void Bike_SetBikeStill(void);
static u8 CanBikeFaceDirectionOnRail(u8 direction, u8 metatileBehavior);
static u8 GetBikeCollision(u8);
static u8 GetBikeCollisionAt(struct ObjectEvent *playerObjEvent, s16 x, s16 y, u8 direction, u8 metatileBehavior);
static bool8 MetatileBehaviorForbidsBiking(u8);
static void BikeTransition_FaceDirection(u8);
static void BikeTransition_TurnDirection(u8);
static void BikeTransition_MoveDirection(u8);
static void BikeTransition_Downhill(u8);
static void BikeTransition_Uphill(u8);
static u8 BikeInputHandler_Normal(u8 *, u16, u16);
static u8 BikeInputHandler_Turning(u8 *, u16, u16);
static u8 BikeInputHandler_Slope(u8 *, u16, u16);

static void (*const sBikeTransitions[])(u8) =
{
    [BIKE_TRANS_FACE_DIRECTION] = BikeTransition_FaceDirection,
    [BIKE_TRANS_TURNING]        = BikeTransition_TurnDirection,
    [BIKE_TRANS_MOVE]           = BikeTransition_MoveDirection,
    [BIKE_TRANS_DOWNHILL]       = BikeTransition_Downhill,
    [BIKE_TRANS_UPHILL]         = BikeTransition_Uphill,
};

static u8 (*const sBikeInputHandlers[])(u8 *, u16, u16) =
{
    [BIKE_STATE_NORMAL]  = BikeInputHandler_Normal,
    [BIKE_STATE_TURNING] = BikeInputHandler_Turning,
    [BIKE_STATE_SLOPE]   = BikeInputHandler_Slope,
};

// RFVF+: once Rodolphe (Mauville's bike shop) has upgraded it (FLAG_BIKE_UPGRADED), the Bicycle has the moves of
// Emerald's Mach and Acro Bikes (pokeemerald src/bike.c): B held while riding speeds it up as the Mach Bike does
// (full speed from the second step: cracked floors, muddy slopes); B held standing still raises the front wheel and
// after 40 frames hops in place, the arrows then hop it forward (bumpy slopes, ledges), releasing B ends it; B with an
// arrow from a standstill jumps sideways (onto isolated rails) or turns around. Emerald's wheelie while moving is the
// Mach Bike's speed here, and the bike's sprite has no wheelie frames (sAnimTable_PlayerBike). Before the upgrade the
// Bicycle is FRLG's, with RFVF+'s gears (SwitchBikeGears).
enum
{
    ACRO_TRANS_FACE_DIRECTION,
    ACRO_TRANS_TURN_DIRECTION,
    ACRO_TRANS_MOVING,
    ACRO_TRANS_MACH_MOVING,
    ACRO_TRANS_NORMAL_TO_WHEELIE,
    ACRO_TRANS_WHEELIE_TO_NORMAL,
    ACRO_TRANS_WHEELIE_IDLE,
    ACRO_TRANS_WHEELIE_HOPPING_STANDING,
    ACRO_TRANS_WHEELIE_HOPPING_MOVING,
    ACRO_TRANS_SIDE_JUMP,
    ACRO_TRANS_TURN_JUMP,
};

static u8 CheckMovementInputAcroBike(u8 *, u16, u16);
static u8 AcroBike_GetJumpDirection(void);
static void AcroBikeTransition_FaceDirection(u8);
static void AcroBikeTransition_TurnDirection(u8);
static void AcroBikeTransition_Moving(u8);
static void AcroBikeTransition_MachMoving(u8);
static void AcroBikeTransition_NormalToWheelie(u8);
static void AcroBikeTransition_WheelieToNormal(u8);
static void AcroBikeTransition_WheelieIdle(u8);
static void AcroBikeTransition_WheelieHoppingStanding(u8);
static void AcroBikeTransition_WheelieHoppingMoving(u8);
static void AcroBikeTransition_SideJump(u8);
static void AcroBikeTransition_TurnJump(u8);

static void (*const sAcroBikeTransitions[])(u8) =
{
    [ACRO_TRANS_FACE_DIRECTION]          = AcroBikeTransition_FaceDirection,
    [ACRO_TRANS_TURN_DIRECTION]          = AcroBikeTransition_TurnDirection,
    [ACRO_TRANS_MOVING]                  = AcroBikeTransition_Moving,
    [ACRO_TRANS_MACH_MOVING]             = AcroBikeTransition_MachMoving,
    [ACRO_TRANS_NORMAL_TO_WHEELIE]       = AcroBikeTransition_NormalToWheelie,
    [ACRO_TRANS_WHEELIE_TO_NORMAL]       = AcroBikeTransition_WheelieToNormal,
    [ACRO_TRANS_WHEELIE_IDLE]            = AcroBikeTransition_WheelieIdle,
    [ACRO_TRANS_WHEELIE_HOPPING_STANDING] = AcroBikeTransition_WheelieHoppingStanding,
    [ACRO_TRANS_WHEELIE_HOPPING_MOVING]  = AcroBikeTransition_WheelieHoppingMoving,
    [ACRO_TRANS_SIDE_JUMP]               = AcroBikeTransition_SideJump,
    [ACRO_TRANS_TURN_JUMP]               = AcroBikeTransition_TurnJump,
};

// The Mach Bike's speeds, from the bike's own: the third step on is the fastest (Emerald: walk, fast, faster)
static void (*const sMachBikeSpeedCallbacks[])(u8) =
{
    PlayerRideWaterCurrent,
    PlayerRideWaterCurrent,
    PlayerWalkFaster,
};

static bool8 sOnCyclingRoadSlope; // the upgraded bike runs FRLG's handlers on the Cycling Road's slopes

bool8 IsBikeUpgraded(void)
{
    return FlagGet(FLAG_BIKE_UPGRADED);
}

void MovePlayerOnBike(u8 direction, u16 newKeys, u16 heldKeys)
{
    if (IsBikeUpgraded())
    {
        if (MetatileBehavior_IsCyclingRoadPullDownTile(gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior))
        {
            if (!sOnCyclingRoadSlope)
                gPlayerAvatar.acroBikeState = BIKE_STATE_NORMAL;
            sOnCyclingRoadSlope = TRUE;
        }
        else if (sOnCyclingRoadSlope)
        {
            sOnCyclingRoadSlope = FALSE;
            gPlayerAvatar.acroBikeState = ACRO_STATE_NORMAL;
        }
        if (!sOnCyclingRoadSlope)
        {
            sAcroBikeTransitions[CheckMovementInputAcroBike(&direction, newKeys, heldKeys)](direction);
            return;
        }
    }
    sBikeTransitions[GetBikeTransitionId(&direction, newKeys, heldKeys)](direction);
}

static u8 GetBikeTransitionId(u8 *direction, u16 newKeys, u16 heldKeys)
{
    return sBikeInputHandlers[gPlayerAvatar.acroBikeState](direction, newKeys, heldKeys);
}

static u8 BikeInputHandler_Normal(u8 *direction_p, u16 newKeys, u16 heldKeys)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    u8 direction = GetPlayerMovementDirection();

    gPlayerAvatar.bikeFrameCounter = 0;
    if (MetatileBehavior_IsCyclingRoadPullDownTile(playerObjEvent->currentMetatileBehavior) == TRUE)
    {
        if (!JOY_HELD(B_BUTTON))
        {
            gPlayerAvatar.acroBikeState = BIKE_STATE_SLOPE;
            gPlayerAvatar.runningState = MOVING;
            if (*direction_p < DIR_NORTH)
                return BIKE_TRANS_DOWNHILL;
            else
                return BIKE_TRANS_UPHILL;
        }
        else
        {
            if (*direction_p != DIR_NONE)
            {
                gPlayerAvatar.acroBikeState = BIKE_STATE_SLOPE;
                gPlayerAvatar.runningState = MOVING;
                return BIKE_TRANS_UPHILL;
            }
        }
    }
    if (*direction_p == DIR_NONE)
    {
        *direction_p = direction;
        gPlayerAvatar.runningState = NOT_MOVING;
        return BIKE_TRANS_FACE_DIRECTION;
    }
    else
    {
        if (*direction_p != direction && gPlayerAvatar.runningState != MOVING)
        {
            gPlayerAvatar.acroBikeState = BIKE_STATE_TURNING;
            gPlayerAvatar.newDirBackup = *direction_p;
            gPlayerAvatar.runningState = NOT_MOVING;
            return GetBikeTransitionId(direction_p, newKeys, heldKeys);
        }
        else
        {
            gPlayerAvatar.runningState = MOVING;
            return BIKE_TRANS_MOVE;
        }
    }
}

static u8 BikeInputHandler_Turning(u8 *direction_p, u16 newKeys, u16 heldKeys)
{
    *direction_p = gPlayerAvatar.newDirBackup;
    gPlayerAvatar.runningState = TURN_DIRECTION;
    gPlayerAvatar.acroBikeState = BIKE_STATE_NORMAL;
    Bike_SetBikeStill();
    return BIKE_TRANS_TURNING;
}

static u8 BikeInputHandler_Slope(u8 *direction_p, u16 newKeys, u16 heldKeys)
{
    u8 direction = GetPlayerMovementDirection();
    u8 playerObjEventId = gPlayerAvatar.objectEventId;
    if (MetatileBehavior_IsCyclingRoadPullDownTile(playerObjEventId[gObjectEvents].currentMetatileBehavior) == TRUE)
    {
        if (*direction_p != direction)
        {
            gPlayerAvatar.acroBikeState = BIKE_STATE_TURNING;
            gPlayerAvatar.newDirBackup = *direction_p;
            gPlayerAvatar.runningState = NOT_MOVING;
            return GetBikeTransitionId(direction_p, newKeys, heldKeys);
        }
        else
        {
            gPlayerAvatar.runningState = MOVING;
            gPlayerAvatar.acroBikeState = BIKE_STATE_SLOPE;
            if (*direction_p < DIR_NORTH)
                return BIKE_TRANS_DOWNHILL;
            else
                return BIKE_TRANS_UPHILL;
        }
    }
    gPlayerAvatar.acroBikeState = BIKE_STATE_NORMAL;
    if (*direction_p == DIR_NONE)
    {
        *direction_p = direction;
        gPlayerAvatar.runningState = NOT_MOVING;
        return BIKE_TRANS_FACE_DIRECTION;
    }
    else
    {
        gPlayerAvatar.runningState = MOVING;
        return BIKE_TRANS_MOVE;
    }
}

static void BikeTransition_FaceDirection(u8 direction)
{
    PlayerFaceDirection(direction);
}

static void BikeTransition_TurnDirection(u8 direction)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!CanBikeFaceDirectionOnRail(direction, playerObjEvent->currentMetatileBehavior))
        direction = playerObjEvent->movementDirection;
    PlayerFaceDirection(direction);
}

static void BikeTransition_MoveDirection(u8 direction)
{
    struct ObjectEvent *playerObjEvent;
    
    playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (!CanBikeFaceDirectionOnRail(direction, playerObjEvent->currentMetatileBehavior))
    {
        BikeTransition_FaceDirection(playerObjEvent->movementDirection);
    }
    else
    {
        u8 collision = GetBikeCollision(direction);

        if (collision > COLLISION_NONE && collision <= COLLISION_ISOLATED_HORIZONTAL_RAIL)
        {
            if (collision == COLLISION_LEDGE_JUMP)
                PlayerJumpLedge(direction);
            else if (collision != COLLISION_STOP_SURFING
                  && collision != COLLISION_LEDGE_JUMP
                  && collision != COLLISION_PUSHED_BOULDER
                  && collision != COLLISION_DIRECTIONAL_STAIR_WARP)
                PlayerOnBikeCollide(direction);
        }
        else
        {
            if(!FlagGet(FLAG_BIKE_GEAR)) //if not set, FRLG speed
            {
                if (collision == COLLISION_COUNT)
                    PlayerWalkFast(direction);
                else if (PlayerIsMovingOnRockStairs(direction))
                    PlayerWalkFast(direction);
                else
                    PlayerRideWaterCurrent(direction);
            }
            else
            {
                if (collision == COLLISION_COUNT)
                    PlayerRideWaterCurrent(direction);
                else if (PlayerIsMovingOnRockStairs(direction))
                    PlayerRideWaterCurrent(direction);
                else
                    PlayerWalkFaster(direction);
            }
        }
    }
}

static void BikeTransition_Downhill(u8 v)
{
    u8 collision = GetBikeCollision(DIR_SOUTH);

    if (collision == COLLISION_NONE)
        PlayerWalkFaster(DIR_SOUTH);
    else if (collision == COLLISION_LEDGE_JUMP)
        PlayerJumpLedge(DIR_SOUTH);
}

static void BikeTransition_Uphill(u8 direction)
{
    if (GetBikeCollision(direction) == COLLISION_NONE)
        PlayerWalkNormal(direction);
}

static u8 GetBikeCollision(u8 direction)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x, y;
    u8 metatileBehavior;

    x = playerObjEvent->currentCoords.x;
    y = playerObjEvent->currentCoords.y;
    MoveCoords(direction, &x, &y);
    metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    return GetBikeCollisionAt(playerObjEvent, x, y, direction, metatileBehavior);
}

static u8 GetBikeCollisionAt(struct ObjectEvent *playerObjEvent, s16 x, s16 y, u8 direction, u8 metatileBehavior)
{
    u8 retVal = CheckForObjectEventCollision(playerObjEvent, x, y, direction, metatileBehavior);

    if (retVal <= COLLISION_OBJECT_EVENT)
    {
        bool8 isCrackedIce = MetatileBehavior_IsCrackedIce(metatileBehavior);
        if (isCrackedIce == TRUE)
            return COLLISION_COUNT;
        if (retVal == COLLISION_NONE && MetatileBehaviorForbidsBiking(metatileBehavior))
            retVal = COLLISION_IMPASSABLE;
    }
    return retVal;
}

bool8 RS_IsRunningDisallowed(u8 r0)
{
    if (MetatileBehaviorForbidsBiking(r0))
        return TRUE;
    if (gMapHeader.mapType != MAP_TYPE_INDOOR)
        return FALSE;
    else
        return TRUE;
}

bool32 IsRunningDisallowed(u8 metatileBehavior)
{
    if (MetatileBehaviorForbidsBiking(metatileBehavior) != TRUE)
        return FALSE;
    else
        return TRUE;
}

static bool8 MetatileBehaviorForbidsBiking(u8 metatileBehavior)
{
    if(MetatileBehavior_IsLongGrass(metatileBehavior))
        return TRUE;
    if (MetatileBehavior_IsRunningDisallowed(metatileBehavior))
        return TRUE;
    if (!MetatileBehavior_IsFortreeBridge(metatileBehavior))
        return FALSE;
    if (PlayerGetElevation() & 1)
        return FALSE;
    return TRUE;
}

static bool8 CanBikeFaceDirectionOnRail(u8 direction, u8 metatileBehavior)
{
    if (direction == DIR_EAST || direction == DIR_WEST)
    {
        if (MetatileBehavior_IsIsolatedVerticalRail(metatileBehavior) || MetatileBehavior_IsVerticalRail(metatileBehavior))
            return FALSE;
    }
    else
    {
        if (MetatileBehavior_IsIsolatedHorizontalRail(metatileBehavior) || MetatileBehavior_IsHorizontalRail(metatileBehavior))
            return FALSE;
    }
    return TRUE;
}

bool8 IsBikingDisallowedByPlayer(void)
{
    s16 x, y;
    u8 metatileBehavior;

    if (!(gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_UNDERWATER | PLAYER_AVATAR_FLAG_SURFING)))
    {
        PlayerGetDestCoords(&x, &y);
        metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
        if (!MetatileBehaviorForbidsBiking(metatileBehavior))
            return FALSE;
    }
    return TRUE;
}

bool8 IsPlayerNotUsingAcroBikeOnBumpySlope(void)
{
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE) && IsBikeUpgraded())
    {
        if (MetatileBehavior_IsBumpySlope(gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior))
            return FALSE;
    }
    return TRUE;
}

void GetOnOffBike(u8 flags)
{
    gBikeCameraAheadPanback = FALSE;
    if (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
    {
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
        Overworld_ClearSavedMusic();
        Overworld_PlaySpecialMapMusic();
    }
    else
    {
        SetPlayerAvatarTransitionFlags(flags);
        if (Overworld_MusicCanOverrideMapMusic(MUS_CYCLING))
        {
            Overworld_SetSavedMusic(GetRegionalFieldMusic(MUS_CYCLING));
            Overworld_ChangeMusicTo(GetRegionalFieldMusic(MUS_CYCLING));
        }
    }
}

void BikeClearState(u32 directionHistory, u32 abStartSelectHistory)
{
    u32 i;

    gPlayerAvatar.acroBikeState = BIKE_STATE_NORMAL;
    gPlayerAvatar.newDirBackup = 0;
    gPlayerAvatar.bikeFrameCounter = 0;
    gPlayerAvatar.bikeSpeed = PLAYER_SPEED_STANDING;
    gPlayerAvatar.directionHistory = directionHistory;
    gPlayerAvatar.abStartSelectHistory = abStartSelectHistory;
    gPlayerAvatar.lastSpinTile = 0;
    for (i = 0; i < NELEMS(gPlayerAvatar.dirTimerHistory); ++i)
            gPlayerAvatar.dirTimerHistory[i] = 0;
    for (i = 0; i < NELEMS(gPlayerAvatar.abStartSelectTimerHistory); ++i)
            gPlayerAvatar.abStartSelectTimerHistory[i] = 0;
}

void Bike_UpdateBikeCounterSpeed(u8 counter)
{
    gPlayerAvatar.bikeFrameCounter = counter;
    gPlayerAvatar.bikeSpeed = counter + (gPlayerAvatar.bikeFrameCounter >> 1);
}

static void Bike_SetBikeStill(void)
{
    gPlayerAvatar.bikeFrameCounter = 0;
    gPlayerAvatar.bikeSpeed = PLAYER_SPEED_STANDING;
}

s16 GetPlayerSpeed(void)
{
    s16 machBikeSpeeds[] = { PLAYER_SPEED_NORMAL, PLAYER_SPEED_FAST, PLAYER_SPEED_FASTEST };

    if ((gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE)) && IsBikeUpgraded())
        return gPlayerAvatar.acroBikeState == ACRO_STATE_NORMAL && gPlayerAvatar.bikeFrameCounter >= 2 && !sOnCyclingRoadSlope
             ? PLAYER_SPEED_FASTEST : PLAYER_SPEED_FASTER;
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE)
        return machBikeSpeeds[gPlayerAvatar.bikeFrameCounter];
    else if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE)
        return PLAYER_SPEED_FASTER;
    else if (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_DASH))
        return PLAYER_SPEED_FAST;
    else
        return PLAYER_SPEED_NORMAL;
}

void Bike_HandleBumpySlopeJump(void)
{
    s16 x, y;
    u8 tileBehavior;

    if ((gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE)) && IsBikeUpgraded())
    {
        PlayerGetDestCoords(&x, &y);
        tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
        if (MetatileBehavior_IsBumpySlope(tileBehavior))
        {
            gPlayerAvatar.acroBikeState = ACRO_STATE_WHEELIE_STANDING;
            PlayerUseAcroBikeOnBumpySlope(GetPlayerMovementDirection());
        }
    }
}

// R/S leftover

// the struct below is used for checking button combinations of the last input so that the acro can potentially perform a side/turn jump.
// its possible that at some point Game Freak intended for the acro bike to have more complex tricks: but only the acro jump combinations can be seen in the final ROM.
struct BikeHistoryInputInfo
{
    u32 dirHistoryMatch; // the direction you need to press
    u32 abStartSelectHistoryMatch; // the button you need to press
    u32 dirHistoryMask; // mask applied so that way only the recent nybble (the recent input) is checked
    u32 abStartSelectHistoryMask; // mask applied so that way only the recent nybble (the recent input) is checked
    const u8 *dirTimerHistoryList; // list of timers to check for direction before the button+dir combination can be verified.
    const u8 *abStartSelectHistoryList; // list of timers to check for buttons before the button+dir combination can be verified.
    u32 direction; // direction to jump
};

// this is a list of timers to compare against later, terminated with 0. the only timer being compared against is 4 frames in this list.
static const u8 sAcroBikeJumpTimerList[] = {4, 0};

// this is a list of history inputs to do in order to do the check to retrieve a jump direction for acro bike. it seems to be an extensible list, so its possible that Game Freak may have intended for the Acro Bike to have more complex tricks at some point. The final list only has the acro jump.
static const struct BikeHistoryInputInfo sAcroBikeTricksList[] =
{
    // the 0xF is a mask performed with each byte of the array in order to perform the check on only the last entry of the history list, otherwise the check wouldn't work as there can be 0xF0 as opposed to 0x0F.
    {DIR_SOUTH, B_BUTTON, 0xF, 0xF, sAcroBikeJumpTimerList, sAcroBikeJumpTimerList, DIR_SOUTH},
    {DIR_NORTH, B_BUTTON, 0xF, 0xF, sAcroBikeJumpTimerList, sAcroBikeJumpTimerList, DIR_NORTH},
    {DIR_WEST, B_BUTTON, 0xF, 0xF, sAcroBikeJumpTimerList, sAcroBikeJumpTimerList, DIR_WEST},
    {DIR_EAST, B_BUTTON, 0xF, 0xF, sAcroBikeJumpTimerList, sAcroBikeJumpTimerList, DIR_EAST},
};

// ---------------------------------------------------------------- the upgraded bike (Emerald's Acro Bike + Mach speed)

static u8 AcroBikeHandleInputNormal(u8 *newDirection, u16 newKeys, u16 heldKeys)
{
    u8 direction = GetPlayerMovementDirection();

    if (*newDirection == DIR_NONE)
    {
        gPlayerAvatar.bikeFrameCounter = 0;
        *newDirection = direction;
        gPlayerAvatar.runningState = NOT_MOVING;
        if (newKeys & B_BUTTON)
        {
            // Standing still with B pressed: raise the front wheel
            gPlayerAvatar.acroBikeState = ACRO_STATE_WHEELIE_STANDING;
            return ACRO_TRANS_NORMAL_TO_WHEELIE;
        }
        return ACRO_TRANS_FACE_DIRECTION;
    }
    if (*newDirection != direction && gPlayerAvatar.runningState != MOVING)
    {
        gPlayerAvatar.bikeFrameCounter = 0;
        gPlayerAvatar.acroBikeState = ACRO_STATE_TURNING;
        gPlayerAvatar.newDirBackup = *newDirection;
        gPlayerAvatar.runningState = NOT_MOVING;
        return CheckMovementInputAcroBike(newDirection, newKeys, heldKeys);
    }
    gPlayerAvatar.runningState = MOVING;
    if (heldKeys & B_BUTTON)
        return ACRO_TRANS_MACH_MOVING;
    gPlayerAvatar.bikeFrameCounter = 0;
    return ACRO_TRANS_MOVING;
}

static u8 AcroBikeHandleInputTurning(u8 *newDirection, u16 newKeys, u16 heldKeys)
{
    u8 direction;

    *newDirection = gPlayerAvatar.newDirBackup;
    gPlayerAvatar.bikeFrameCounter++;

    // Wait 6 frames before actually changing direction: a B press meanwhile is a jump
    if (gPlayerAvatar.bikeFrameCounter > 6)
    {
        gPlayerAvatar.runningState = TURN_DIRECTION;
        gPlayerAvatar.acroBikeState = ACRO_STATE_NORMAL;
        Bike_SetBikeStill();
        return ACRO_TRANS_TURN_DIRECTION;
    }
    direction = GetPlayerMovementDirection();
    if (*newDirection == AcroBike_GetJumpDirection())
    {
        Bike_SetBikeStill();
        gPlayerAvatar.bikeSpeed = PLAYER_SPEED_NORMAL;
        if (*newDirection == GetOppositeDirection(direction))
        {
            gPlayerAvatar.acroBikeState = ACRO_STATE_TURN_JUMP;
            return ACRO_TRANS_TURN_JUMP;
        }
        gPlayerAvatar.runningState = MOVING;
        gPlayerAvatar.acroBikeState = ACRO_STATE_SIDE_JUMP;
        return ACRO_TRANS_SIDE_JUMP;
    }
    *newDirection = direction;
    return ACRO_TRANS_FACE_DIRECTION;
}

static u8 AcroBikeHandleInputWheelieStanding(u8 *newDirection, u16 newKeys, u16 heldKeys)
{
    u8 direction = GetPlayerMovementDirection();
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    gPlayerAvatar.runningState = NOT_MOVING;
    if (heldKeys & B_BUTTON)
    {
        gPlayerAvatar.bikeFrameCounter++;
    }
    else
    {
        // B released: lower the front wheel, unless on a bumpy slope
        gPlayerAvatar.bikeFrameCounter = 0;
        if (!MetatileBehavior_IsBumpySlope(playerObjEvent->currentMetatileBehavior))
        {
            *newDirection = direction;
            gPlayerAvatar.acroBikeState = ACRO_STATE_NORMAL;
            Bike_SetBikeStill();
            return ACRO_TRANS_WHEELIE_TO_NORMAL;
        }
    }
    if (gPlayerAvatar.bikeFrameCounter >= 40)
    {
        *newDirection = direction;
        gPlayerAvatar.acroBikeState = ACRO_STATE_BUNNY_HOP;
        Bike_SetBikeStill();
        return ACRO_TRANS_WHEELIE_HOPPING_STANDING;
    }
    if (*newDirection == direction)
    {
        // On a bumpy slope the front wheel stays up against anything that blocks, as Emerald's moving wheelie
        // does: only hops leave the slope
        if (MetatileBehavior_IsBumpySlope(playerObjEvent->currentMetatileBehavior))
        {
            u8 collision = GetBikeCollision(direction);

            if (collision != COLLISION_NONE && collision != COLLISION_LEDGE_JUMP)
                return ACRO_TRANS_WHEELIE_IDLE;
        }
        // Emerald rides on the back wheel; here moving with B held is the Mach Bike's speed
        gPlayerAvatar.runningState = MOVING;
        gPlayerAvatar.acroBikeState = ACRO_STATE_NORMAL;
        Bike_SetBikeStill();
        return (heldKeys & B_BUTTON) ? ACRO_TRANS_MACH_MOVING : ACRO_TRANS_MOVING;
    }
    if (*newDirection == DIR_NONE)
    {
        *newDirection = direction;
        return ACRO_TRANS_WHEELIE_IDLE;
    }
    gPlayerAvatar.runningState = TURN_DIRECTION;
    return ACRO_TRANS_WHEELIE_IDLE;
}

static u8 AcroBikeHandleInputBunnyHop(u8 *newDirection, u16 newKeys, u16 heldKeys)
{
    u8 direction = GetPlayerMovementDirection();
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!(heldKeys & B_BUTTON))
    {
        // B released: stop hopping, unless on a bumpy slope
        Bike_SetBikeStill();
        if (MetatileBehavior_IsBumpySlope(playerObjEvent->currentMetatileBehavior))
        {
            gPlayerAvatar.acroBikeState = ACRO_STATE_WHEELIE_STANDING;
            return CheckMovementInputAcroBike(newDirection, newKeys, heldKeys);
        }
        *newDirection = direction;
        gPlayerAvatar.runningState = NOT_MOVING;
        gPlayerAvatar.acroBikeState = ACRO_STATE_NORMAL;
        return ACRO_TRANS_WHEELIE_TO_NORMAL;
    }
    if (*newDirection == DIR_NONE)
    {
        *newDirection = direction;
        gPlayerAvatar.runningState = NOT_MOVING;
        return ACRO_TRANS_WHEELIE_HOPPING_STANDING;
    }
    if (*newDirection != direction && gPlayerAvatar.runningState != MOVING)
    {
        gPlayerAvatar.runningState = TURN_DIRECTION;
        return ACRO_TRANS_WHEELIE_HOPPING_STANDING;
    }
    gPlayerAvatar.runningState = MOVING;
    return ACRO_TRANS_WHEELIE_HOPPING_MOVING;
}

static u8 AcroBikeHandleInputSidewaysJump(u8 *newDirection, u16 newKeys, u16 heldKeys)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    playerObjEvent->facingDirectionLocked = FALSE;
    SetObjectEventDirection(playerObjEvent, playerObjEvent->facingDirection);
    QuestLogRecordPlayerStep(MOVEMENT_ACTION_UNLOCK_FACING_DIRECTION);
    gPlayerAvatar.acroBikeState = ACRO_STATE_NORMAL;
    return CheckMovementInputAcroBike(newDirection, newKeys, heldKeys);
}

static u8 AcroBikeHandleInputTurnJump(u8 *newDirection, u16 newKeys, u16 heldKeys)
{
    gPlayerAvatar.acroBikeState = ACRO_STATE_NORMAL;
    return CheckMovementInputAcroBike(newDirection, newKeys, heldKeys);
}

static u8 CheckMovementInputAcroBike(u8 *newDirection, u16 newKeys, u16 heldKeys)
{
    switch (gPlayerAvatar.acroBikeState)
    {
    case ACRO_STATE_TURNING:
        return AcroBikeHandleInputTurning(newDirection, newKeys, heldKeys);
    case ACRO_STATE_WHEELIE_STANDING:
        return AcroBikeHandleInputWheelieStanding(newDirection, newKeys, heldKeys);
    case ACRO_STATE_BUNNY_HOP:
        return AcroBikeHandleInputBunnyHop(newDirection, newKeys, heldKeys);
    case ACRO_STATE_SIDE_JUMP:
        return AcroBikeHandleInputSidewaysJump(newDirection, newKeys, heldKeys);
    case ACRO_STATE_TURN_JUMP:
        return AcroBikeHandleInputTurnJump(newDirection, newKeys, heldKeys);
    default:
        return AcroBikeHandleInputNormal(newDirection, newKeys, heldKeys);
    }
}

static void AcroBikeTransition_FaceDirection(u8 direction)
{
    PlayerFaceDirection(direction);
}

static void AcroBikeTransition_TurnDirection(u8 direction)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!CanBikeFaceDirectionOnRail(direction, playerObjEvent->currentMetatileBehavior))
        direction = playerObjEvent->movementDirection;
    PlayerFaceDirection(direction);
}

// FRLG's collisions: COLLISION_DIRECTIONAL_STAIR_WARP holds Emerald's COLLISION_ROTATING_GATE slot
static void AcroBikeMove(u8 direction, bool8 mach)
{
    u8 collision;
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!CanBikeFaceDirectionOnRail(direction, playerObjEvent->currentMetatileBehavior))
    {
        Bike_SetBikeStill();
        AcroBikeTransition_FaceDirection(playerObjEvent->movementDirection);
        return;
    }
    collision = GetBikeCollision(direction);
    if (collision > COLLISION_NONE && collision < COLLISION_VERTICAL_RAIL)
    {
        if (collision == COLLISION_LEDGE_JUMP)
        {
            PlayerJumpLedge(direction);
        }
        else
        {
            Bike_SetBikeStill();
            if (collision < COLLISION_STOP_SURFING || collision > COLLISION_DIRECTIONAL_STAIR_WARP)
                PlayerOnBikeCollide(direction);
        }
    }
    else if (collision == COLLISION_COUNT || PlayerIsMovingOnRockStairs(direction))
    {
        Bike_SetBikeStill();
        PlayerWalkFast(direction);
    }
    else if (mach)
    {
        if (gPlayerAvatar.bikeFrameCounter >= NELEMS(sMachBikeSpeedCallbacks))
            gPlayerAvatar.bikeFrameCounter = NELEMS(sMachBikeSpeedCallbacks) - 1;
        sMachBikeSpeedCallbacks[gPlayerAvatar.bikeFrameCounter](direction);
        if (gPlayerAvatar.bikeFrameCounter < 2)
            gPlayerAvatar.bikeFrameCounter++;
    }
    else
    {
        PlayerRideWaterCurrent(direction);
    }
}

static void AcroBikeTransition_Moving(u8 direction)
{
    AcroBikeMove(direction, FALSE);
}

static void AcroBikeTransition_MachMoving(u8 direction)
{
    AcroBikeMove(direction, TRUE);
}

static void AcroBikeTransition_NormalToWheelie(u8 direction)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!CanBikeFaceDirectionOnRail(direction, playerObjEvent->currentMetatileBehavior))
        direction = playerObjEvent->movementDirection;
    PlayerStartWheelie(direction);
}

static void AcroBikeTransition_WheelieToNormal(u8 direction)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!CanBikeFaceDirectionOnRail(direction, playerObjEvent->currentMetatileBehavior))
        direction = playerObjEvent->movementDirection;
    PlayerEndWheelie(direction);
}

static void AcroBikeTransition_WheelieIdle(u8 direction)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!CanBikeFaceDirectionOnRail(direction, playerObjEvent->currentMetatileBehavior))
        direction = playerObjEvent->movementDirection;
    PlayerIdleWheelie(direction);
}

static void AcroBikeTransition_WheelieHoppingStanding(u8 direction)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!CanBikeFaceDirectionOnRail(direction, playerObjEvent->currentMetatileBehavior))
        direction = playerObjEvent->movementDirection;
    PlayerStandingHoppingWheelie(direction);
}

static void AcroBikeTransition_WheelieHoppingMoving(u8 direction)
{
    u8 collision;
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!CanBikeFaceDirectionOnRail(direction, playerObjEvent->currentMetatileBehavior))
    {
        AcroBikeTransition_WheelieHoppingStanding(playerObjEvent->movementDirection);
        return;
    }
    collision = GetBikeCollision(direction);
    // COLLISION_WHEELIE_HOP is a bumpy slope: hopping crosses it
    if (collision && collision != COLLISION_WHEELIE_HOP)
    {
        if (collision == COLLISION_LEDGE_JUMP)
        {
            PlayerLedgeHoppingWheelie(direction);
            return;
        }
        if (collision >= COLLISION_STOP_SURFING && collision <= COLLISION_DIRECTIONAL_STAIR_WARP)
            return;
        if (collision < COLLISION_VERTICAL_RAIL)
        {
            AcroBikeTransition_WheelieHoppingStanding(direction);
            return;
        }
    }
    PlayerMovingHoppingWheelie(direction);
}

// A side jump lands on a rail only across it
static bool8 WillPlayerCollideWithCollision(u8 newTileCollision, u8 direction)
{
    if (direction == DIR_NORTH || direction == DIR_SOUTH)
    {
        if (newTileCollision == COLLISION_ISOLATED_VERTICAL_RAIL || newTileCollision == COLLISION_VERTICAL_RAIL)
            return FALSE;
    }
    else if (newTileCollision == COLLISION_ISOLATED_HORIZONTAL_RAIL || newTileCollision == COLLISION_HORIZONTAL_RAIL)
    {
        return FALSE;
    }
    return TRUE;
}

static void AcroBikeTransition_SideJump(u8 direction)
{
    u8 collision = GetBikeCollision(direction);

    if (collision)
    {
        if (collision == COLLISION_PUSHED_BOULDER)
            return;
        if (collision < COLLISION_ISOLATED_VERTICAL_RAIL || !WillPlayerCollideWithCollision(collision, direction))
        {
            AcroBikeTransition_TurnDirection(direction);
            return;
        }
    }
    PlayerAcroSideJump(direction);
}

static void AcroBikeTransition_TurnJump(u8 direction)
{
    PlayerAcroTurnJump(direction);
}

// The inputs of the last frames: a jump is B and an arrow within 4 frames
static void Bike_UpdateDirTimerHistory(u8 dir)
{
    u8 i;

    gPlayerAvatar.directionHistory = (gPlayerAvatar.directionHistory << 4) | (dir & 0xF);
    for (i = NELEMS(gPlayerAvatar.dirTimerHistory) - 1; i != 0; i--)
        gPlayerAvatar.dirTimerHistory[i] = gPlayerAvatar.dirTimerHistory[i - 1];
    gPlayerAvatar.dirTimerHistory[0] = 1;
}

static void Bike_UpdateABStartSelectHistory(u8 input)
{
    u8 i;

    gPlayerAvatar.abStartSelectHistory = (gPlayerAvatar.abStartSelectHistory << 4) | (input & 0xF);
    for (i = NELEMS(gPlayerAvatar.abStartSelectTimerHistory) - 1; i != 0; i--)
        gPlayerAvatar.abStartSelectTimerHistory[i] = gPlayerAvatar.abStartSelectTimerHistory[i - 1];
    gPlayerAvatar.abStartSelectTimerHistory[0] = 1;
}

static u8 Bike_DPadToDirection(u16 heldKeys)
{
    if (heldKeys & DPAD_UP)
        return DIR_NORTH;
    if (heldKeys & DPAD_DOWN)
        return DIR_SOUTH;
    if (heldKeys & DPAD_LEFT)
        return DIR_WEST;
    if (heldKeys & DPAD_RIGHT)
        return DIR_EAST;
    return DIR_NONE;
}

void Bike_TryAcroBikeHistoryUpdate(u16 newKeys, u16 heldKeys)
{
    u8 input;

    if (!(gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE)) || !IsBikeUpgraded())
        return;
    input = Bike_DPadToDirection(heldKeys);
    if (input == (gPlayerAvatar.directionHistory & 0xF))
    {
        if (gPlayerAvatar.dirTimerHistory[0] < 0xFF)
            gPlayerAvatar.dirTimerHistory[0]++;
    }
    else
    {
        Bike_UpdateDirTimerHistory(input);
        gPlayerAvatar.bikeSpeed = PLAYER_SPEED_STANDING;
    }
    input = heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON);
    if (input == (gPlayerAvatar.abStartSelectHistory & 0xF))
    {
        if (gPlayerAvatar.abStartSelectTimerHistory[0] < 0xFF)
            gPlayerAvatar.abStartSelectTimerHistory[0]++;
    }
    else
    {
        Bike_UpdateABStartSelectHistory(input);
        gPlayerAvatar.bikeSpeed = PLAYER_SPEED_STANDING;
    }
}

static bool8 HasPlayerInputTakenLongerThanList(const u8 *dirTimerList, const u8 *abStartSelectTimerList)
{
    u8 i;

    for (i = 0; dirTimerList[i] != 0; i++)
    {
        if (gPlayerAvatar.dirTimerHistory[i] > dirTimerList[i])
            return FALSE;
    }
    for (i = 0; abStartSelectTimerList[i] != 0; i++)
    {
        if (gPlayerAvatar.abStartSelectTimerHistory[i] > abStartSelectTimerList[i])
            return FALSE;
    }
    return TRUE;
}

static u8 AcroBike_GetJumpDirection(void)
{
    u32 i;

    for (i = 0; i < NELEMS(sAcroBikeTricksList); i++)
    {
        const struct BikeHistoryInputInfo *historyInputInfo = &sAcroBikeTricksList[i];
        u32 dirHistory = gPlayerAvatar.directionHistory & historyInputInfo->dirHistoryMask;
        u32 abStartSelectHistory = gPlayerAvatar.abStartSelectHistory & historyInputInfo->abStartSelectHistoryMask;

        if (dirHistory == historyInputInfo->dirHistoryMatch
         && abStartSelectHistory == historyInputInfo->abStartSelectHistoryMatch
         && HasPlayerInputTakenLongerThanList(historyInputInfo->dirTimerHistoryList, historyInputInfo->abStartSelectHistoryList))
            return historyInputInfo->direction;
    }
    return DIR_NONE;
}
