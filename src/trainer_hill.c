// RFVF+: Emerald's Trainer Hill (Hoenn batch 5, src/trainer_hill.c and its records window from battle_records.c),
// without its e-Reader challenges. The floor data (src/data/trainer_hill.h) is Emerald's, with French Emerald's
// names; the floors draw with gTileset_HoennTrainerHillFloors (Emerald's ids). The timer is FRLG's VBlank counter 1
// (the Trainer Tower's: save.c pauses it). The challenge state is SaveBlock1.trainerHill (+ Emerald's
// SaveBlock2.frontier fields it used), the records SaveBlock1.trainerHillTimes (0 = none yet: older saves).
#include "global.h"
#include "gflib.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "easy_chat.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_message_box.h"
#include "fieldmap.h"
#include "item.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "new_menu_helpers.h"
#include "overworld.h"
#include "pokemon.h"
#include "scanline_effect.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "trainer_hill.h"
#include "constants/battle_ai.h"
#include "constants/easy_chat.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/trainer_types.h"

#define FLOOR_DATA(id) (sHillData->data.floors[id])

struct FloorTrainers
{
    u8 name[HILL_TRAINERS_PER_FLOOR][HILL_TRAINER_NAME_LENGTH + 1];
    u8 facilityClass[HILL_TRAINERS_PER_FLOOR];
};

static EWRAM_DATA struct {
    u8 floorId;
    struct TrainerHillChallengeData data;
} *sHillData = NULL;

static EWRAM_DATA struct FloorTrainers *sFloorTrainers = NULL;
static EWRAM_DATA u16 *sRecordsTilemapBuffer = NULL;

static void TrainerHillStartChallenge(void);
static void GetOwnerState(void);
static void GiveChallengePrize(void);
static void CheckFinalTime(void);
static void TrainerHillResumeTimer(void);
static void TrainerHillSetPlayerLost(void);
static void TrainerHillGetChallengeStatus(void);
static void BufferChallengeTime(void);
static void GetAllFloorsUsed(void);
static void GetInEReaderMode(void);
static void IsTrainerHillChallengeActive(void);
static void ShowTrainerHillPostBattleText(void);
static void SetAllTrainerFlags(void);
static void GetGameSaved(void);
static void SetGameSaved(void);
static void ClearGameSaved(void);
static void GetChallengeWon(void);
static void TrainerHillSetMode(void);
static void SetUpDataStruct(void);
static void FreeDataStruct(void);
static void SetTimerValue(u32 *dst, u32 val);
static u32 GetTimerValue(u32 *src);
static void SetTrainerHillMonLevel(struct Pokemon *mon, u8 level);
static u16 GetPrizeItemId(void);

#define EC_EMPTY_WORD EC_WORD_UNDEFINED // Emerald's name
#include "data/trainer_hill.h"

static const u16 sPrizeListRareCandy1[]  = {ITEM_RARE_CANDY,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListLuxuryBall1[] = {ITEM_LUXURY_BALL,      ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxRevive1[]  = {ITEM_MAX_REVIVE,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxEther1[]   = {ITEM_MAX_ETHER,        ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListElixir1[]     = {ITEM_ELIXIR,           ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListRoar[]        = {ITEM_TM05_ROAR,        ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListSludgeBomb[]  = {ITEM_TM36_SLUDGE_BOMB, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListToxic[]       = {ITEM_TM06_TOXIC,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListSunnyDay[]    = {ITEM_TM11_SUNNY_DAY,   ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListEarthQuake[]  = {ITEM_TM26_EARTHQUAKE,  ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};

static const u16 sPrizeListRareCandy2[]  = {ITEM_RARE_CANDY,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListLuxuryBall2[] = {ITEM_LUXURY_BALL,      ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxRevive2[]  = {ITEM_MAX_REVIVE,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxEther2[]   = {ITEM_MAX_ETHER,        ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListElixir2[]     = {ITEM_ELIXIR,           ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListBrickBreak[]  = {ITEM_TM31_BRICK_BREAK, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListTorment[]     = {ITEM_TM41_TORMENT,     ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListSkillSwap[]   = {ITEM_TM48_SKILL_SWAP,  ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListGigaDrain[]   = {ITEM_TM19_GIGA_DRAIN,  ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListAttract[]     = {ITEM_TM45_ATTRACT,     ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};

static const u16 *const sPrizeLists1[NUM_TRAINER_HILL_PRIZE_LISTS] =
{
    sPrizeListRareCandy1,
    sPrizeListLuxuryBall1,
    sPrizeListMaxRevive1,
    sPrizeListMaxEther1,
    sPrizeListElixir1,
    sPrizeListRoar,
    sPrizeListSludgeBomb,
    sPrizeListToxic,
    sPrizeListSunnyDay,
    sPrizeListEarthQuake
};

static const u16 *const sPrizeLists2[NUM_TRAINER_HILL_PRIZE_LISTS] =
{
    sPrizeListRareCandy2,
    sPrizeListLuxuryBall2,
    sPrizeListMaxRevive2,
    sPrizeListMaxEther2,
    sPrizeListElixir2,
    sPrizeListBrickBreak,
    sPrizeListTorment,
    sPrizeListSkillSwap,
    sPrizeListGigaDrain,
    sPrizeListAttract
};

static const u16 *const *const sPrizeListSets[] =
{
    sPrizeLists1,
    sPrizeLists2
};

static const u8 sRecordWinColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

static const struct TrainerHillChallengeData *const sChallengeData[NUM_TRAINER_HILL_MODES] =
{
    [HILL_MODE_NORMAL]  = &sChallenge_Normal,
    [HILL_MODE_VARIETY] = &sChallenge_Variety,
    [HILL_MODE_UNIQUE]  = &sChallenge_Unique,
    [HILL_MODE_EXPERT]  = &sChallenge_Expert,
};

static void (*const sHillFunctions[])(void) =
{
    [TRAINER_HILL_FUNC_START]                 = TrainerHillStartChallenge,
    [TRAINER_HILL_FUNC_GET_OWNER_STATE]       = GetOwnerState,
    [TRAINER_HILL_FUNC_GIVE_PRIZE]            = GiveChallengePrize,
    [TRAINER_HILL_FUNC_CHECK_FINAL_TIME]      = CheckFinalTime,
    [TRAINER_HILL_FUNC_RESUME_TIMER]          = TrainerHillResumeTimer,
    [TRAINER_HILL_FUNC_SET_LOST]              = TrainerHillSetPlayerLost,
    [TRAINER_HILL_FUNC_GET_CHALLENGE_STATUS]  = TrainerHillGetChallengeStatus,
    [TRAINER_HILL_FUNC_GET_CHALLENGE_TIME]    = BufferChallengeTime,
    [TRAINER_HILL_FUNC_GET_ALL_FLOORS_USED]   = GetAllFloorsUsed,
    [TRAINER_HILL_FUNC_GET_IN_EREADER_MODE]   = GetInEReaderMode,
    [TRAINER_HILL_FUNC_IN_CHALLENGE]          = IsTrainerHillChallengeActive,
    [TRAINER_HILL_FUNC_POST_BATTLE_TEXT]      = ShowTrainerHillPostBattleText,
    [TRAINER_HILL_FUNC_SET_ALL_TRAINER_FLAGS] = SetAllTrainerFlags,
    [TRAINER_HILL_FUNC_GET_GAME_SAVED]        = GetGameSaved,
    [TRAINER_HILL_FUNC_SET_GAME_SAVED]        = SetGameSaved,
    [TRAINER_HILL_FUNC_CLEAR_GAME_SAVED]      = ClearGameSaved,
    [TRAINER_HILL_FUNC_GET_WON]               = GetChallengeWon,
    [TRAINER_HILL_FUNC_SET_MODE]              = TrainerHillSetMode,
};

// official French texts (Emerald's strings.c)
static const u8 sText_TimeBoard[] = _("PANNEAU DES TEMPS");
static const u8 sText_TimeCleared[] = _("TEMPS ");
static const u8 sText_XMinYDotZSec[] = _("{STR_VAR_1} min {STR_VAR_2},{STR_VAR_3} s");

static const u8 *const sModeStrings[NUM_TRAINER_HILL_MODES] =
{
    [HILL_MODE_NORMAL]  = gText_NormalTagMatch,
    [HILL_MODE_VARIETY] = gText_VarietyTagMatch,
    [HILL_MODE_UNIQUE]  = gText_UniqueTagMatch,
    [HILL_MODE_EXPERT]  = gText_ExpertTagMatch,
};

static const struct ObjectEventTemplate sTrainerObjectEventTemplate =
{
    .kind = OBJ_KIND_NORMAL,
    .objUnion = {
        .normal = {
            .elevation = 3,
            .movementType = MOVEMENT_TYPE_LOOK_AROUND,
            .movementRangeX = 1,
            .movementRangeY = 1,
            .trainerType = TRAINER_TYPE_NORMAL,
        },
    },
};

static const u8 sTrainerPartySlots[HILL_TRAINERS_PER_FLOOR][PARTY_SIZE / 2] =
{
    {0, 1, 2},
    {3, 4, 5}
};

void CallTrainerHillFunction(void)
{
    SetUpDataStruct();
    sHillFunctions[gSpecialVar_0x8004]();
    FreeDataStruct();
}

void ResetTrainerHillResults(void)
{
    s32 i;

    gSaveBlock1Ptr->trainerHill.savedGame = 0;
    gSaveBlock1Ptr->trainerHill.bestTime = 0;
    for (i = 0; i < NUM_TRAINER_HILL_MODES; i++)
        SetTimerValue(&gSaveBlock1Ptr->trainerHillTimes[i], HILL_MAX_TIME);
}

static u8 GetFloorId(void)
{
    return gMapHeader.mapLayoutId - LAYOUT_TRAINER_HILL_1F;
}

u8 GetTrainerHillOpponentClass(u16 trainerId)
{
    u8 id = trainerId - 1;

    return sHillTrainerClasses[sFloorTrainers->facilityClass[id]].trainerClass;
}

void GetTrainerHillTrainerName(u8 *dst, u16 trainerId)
{
    s32 i;
    u8 id = trainerId - 1;

    for (i = 0; i < HILL_TRAINER_NAME_LENGTH + 1; i++)
        dst[i] = sFloorTrainers->name[id][i];
}

u8 GetTrainerHillTrainerFrontSpriteId(u16 trainerId)
{
    u8 id, facilityClass;

    SetUpDataStruct();
    id = trainerId - 1;
    facilityClass = FLOOR_DATA(sHillData->floorId).trainers[id].facilityClass;
    FreeDataStruct();

    return sHillTrainerClasses[facilityClass].trainerPic;
}

void InitTrainerHillBattleStruct(void)
{
    s32 i, j;

    SetUpDataStruct();
    sFloorTrainers = AllocZeroed(sizeof(*sFloorTrainers));

    for (i = 0; i < HILL_TRAINERS_PER_FLOOR; i++)
    {
        for (j = 0; j < HILL_TRAINER_NAME_LENGTH + 1; j++)
            sFloorTrainers->name[i][j] = FLOOR_DATA(sHillData->floorId).trainers[i].name[j];

        sFloorTrainers->facilityClass[i] = FLOOR_DATA(sHillData->floorId).trainers[i].facilityClass;
    }
    SetVBlankCounter1Ptr(&gSaveBlock1Ptr->trainerHill.timer);
    FreeDataStruct();
}

void FreeTrainerHillBattleStruct(void)
{
    TRY_FREE_AND_SET_NULL(sFloorTrainers);
}

static void SetUpDataStruct(void)
{
    if (sHillData == NULL)
    {
        sHillData = AllocZeroed(sizeof(*sHillData));
        sHillData->floorId = gMapHeader.mapLayoutId - LAYOUT_TRAINER_HILL_1F;
        CpuCopy32(sChallengeData[gSaveBlock1Ptr->trainerHill.mode], &sHillData->data, sizeof(sHillData->data));
    }
}

static void FreeDataStruct(void)
{
    TRY_FREE_AND_SET_NULL(sHillData);
}

// Emerald's FrontierSpeechToString (FRLG's Trainer Tower does the same)
static void HillSpeechToString(const u16 *words)
{
    s32 i;

    ConvertEasyChatWordsToString(gStringVar4, words, 3, 2);
    if ((unsigned)GetStringWidth(FONT_NORMAL, gStringVar4, -1) > 196)
    {
        ConvertEasyChatWordsToString(gStringVar4, words, 2, 3);
        i = 0;
        while (gStringVar4[i++] != CHAR_NEWLINE)
            ;
        while (gStringVar4[i] != CHAR_NEWLINE)
            i++;
        gStringVar4[i] = CHAR_PROMPT_SCROLL;
    }
}

void CopyTrainerHillTrainerText(u8 which, u16 trainerId)
{
    u8 id, floorId;

    SetUpDataStruct();
    floorId = GetFloorId();
    id = trainerId - 1;

    switch (which)
    {
    case TRAINER_HILL_TEXT_INTRO:
        HillSpeechToString(FLOOR_DATA(floorId).trainers[id].speechBefore);
        break;
    case TRAINER_HILL_TEXT_PLAYER_LOST:
        HillSpeechToString(FLOOR_DATA(floorId).trainers[id].speechWin);
        break;
    case TRAINER_HILL_TEXT_PLAYER_WON:
        HillSpeechToString(FLOOR_DATA(floorId).trainers[id].speechLose);
        break;
    case TRAINER_HILL_TEXT_AFTER:
        HillSpeechToString(FLOOR_DATA(floorId).trainers[id].speechAfter);
        break;
    }

    FreeDataStruct();
}

static void TrainerHillStartChallenge(void)
{
    gSaveBlock1Ptr->trainerHill.field_3D6E_0f = 1; // no e-Reader challenge here (Emerald: one was read)
    gSaveBlock1Ptr->trainerHill.unk_3D6C = 0;
    SetVBlankCounter1Ptr(&gSaveBlock1Ptr->trainerHill.timer);
    gSaveBlock1Ptr->trainerHill.timer = 0;
    gSaveBlock1Ptr->trainerHill.spokeToOwner = 0;
    gSaveBlock1Ptr->trainerHill.checkedFinalTime = 0;
    gSaveBlock1Ptr->trainerHill.maybeECardScanDuringChallenge = 0;
    gSaveBlock1Ptr->trainerHill.trainerFlags = 0;
    gBattleOutcome = 0;
    gSaveBlock1Ptr->trainerHill.receivedPrize = 0;
}

static void GetOwnerState(void)
{
    DisableVBlankCounter1();
    gSpecialVar_Result = 0;
    if (gSaveBlock1Ptr->trainerHill.spokeToOwner)
        gSpecialVar_Result++;
    if (gSaveBlock1Ptr->trainerHill.receivedPrize && gSaveBlock1Ptr->trainerHill.checkedFinalTime)
        gSpecialVar_Result++;

    gSaveBlock1Ptr->trainerHill.spokeToOwner = TRUE;
}

static void GiveChallengePrize(void)
{
    u16 itemId = GetPrizeItemId();

    if (sHillData->data.challenge.numFloors != NUM_TRAINER_HILL_FLOORS || gSaveBlock1Ptr->trainerHill.receivedPrize)
    {
        gSpecialVar_Result = 2;
    }
    else if (AddBagItem(itemId, 1) == TRUE)
    {
        CopyItemName(itemId, gStringVar2);
        gSaveBlock1Ptr->trainerHill.receivedPrize = TRUE;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }
}

// If bestTime > timer, the challenge was completed faster and its a new record
// Otherwise the owner says it was a slow time and to complete it faster next time
static void CheckFinalTime(void)
{
    if (gSaveBlock1Ptr->trainerHill.checkedFinalTime)
    {
        gSpecialVar_Result = 2;
    }
    else if (GetTimerValue(&gSaveBlock1Ptr->trainerHill.bestTime) > gSaveBlock1Ptr->trainerHill.timer)
    {
        SetTimerValue(&gSaveBlock1Ptr->trainerHill.bestTime, gSaveBlock1Ptr->trainerHill.timer);
        gSaveBlock1Ptr->trainerHillTimes[gSaveBlock1Ptr->trainerHill.mode] = gSaveBlock1Ptr->trainerHill.bestTime;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }

    gSaveBlock1Ptr->trainerHill.checkedFinalTime = TRUE;
}

static void TrainerHillResumeTimer(void)
{
    if (!gSaveBlock1Ptr->trainerHill.spokeToOwner)
    {
        if (gSaveBlock1Ptr->trainerHill.timer >= HILL_MAX_TIME)
            gSaveBlock1Ptr->trainerHill.timer = HILL_MAX_TIME;
        else
            SetVBlankCounter1Ptr(&gSaveBlock1Ptr->trainerHill.timer);
    }
}

static void TrainerHillSetPlayerLost(void)
{
    gSaveBlock1Ptr->trainerHill.hasLost = TRUE;
}

static void TrainerHillGetChallengeStatus(void)
{
    if (gSaveBlock1Ptr->trainerHill.hasLost)
    {
        // The player lost their last match.
        gSaveBlock1Ptr->trainerHill.hasLost = FALSE;
        gSpecialVar_Result = TRAINER_HILL_PLAYER_STATUS_LOST;
    }
    else if (gSaveBlock1Ptr->trainerHill.maybeECardScanDuringChallenge)
    {
        gSaveBlock1Ptr->trainerHill.maybeECardScanDuringChallenge = 0;
        gSpecialVar_Result = TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED;
    }
    else
    {
        // Continue playing.
        gSpecialVar_Result = TRAINER_HILL_PLAYER_STATUS_NORMAL;
    }
}

static void BufferChallengeTime(void)
{
    s32 total, minutes, secondsWhole, secondsFraction;

    total = gSaveBlock1Ptr->trainerHill.timer;
    if (total >= HILL_MAX_TIME)
        total = HILL_MAX_TIME;

    minutes = total / (60 * 60);
    total %= (60 * 60);
    secondsWhole = total / 60;
    total %= 60;
    secondsFraction = (total * 168) / 100;

    ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
}

// Returns TRUE if all 4 floors are used (always, without Emerald's JP challenges)
static void GetAllFloorsUsed(void)
{
    SetUpDataStruct();
    if (sHillData->data.challenge.numFloors != NUM_TRAINER_HILL_FLOORS)
    {
        ConvertIntToDecimalStringN(gStringVar1, sHillData->data.challenge.numFloors, STR_CONV_MODE_LEFT_ALIGN, 1);
        gSpecialVar_Result = FALSE;
    }
    else
    {
        gSpecialVar_Result = TRUE;
    }

    FreeDataStruct();
}

static void GetInEReaderMode(void)
{
    gSpecialVar_Result = FALSE;
}

bool8 InTrainerHillChallenge(void)
{
    if (VarGet(VAR_TRAINER_HILL_IS_ACTIVE) == 0)
        return FALSE;
    else if (gSaveBlock1Ptr->trainerHill.spokeToOwner)
        return FALSE;
    else if (GetCurrentTrainerHillMapId() != 0)
        return TRUE;
    else
        return FALSE;
}

static void IsTrainerHillChallengeActive(void)
{
    if (!InTrainerHillChallenge())
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
}

static void PrintOnTrainerHillRecordsWindow(void)
{
    s32 i, x, y;
    u32 total, minutes, secondsWhole, secondsFraction;

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    x = GetStringCenterAlignXOffset(FONT_NORMAL, sText_TimeBoard, 0xD0);
    AddTextPrinterParameterized3(0, FONT_NORMAL, x, 2, sRecordWinColors, TEXT_SKIP_DRAW, sText_TimeBoard);

    y = 18;
    for (i = 0; i < NUM_TRAINER_HILL_MODES; i++)
    {
        AddTextPrinterParameterized3(0, FONT_NORMAL, 0, y, sRecordWinColors, TEXT_SKIP_DRAW, sModeStrings[i]);
        y += 15;
        total = GetTimerValue(&gSaveBlock1Ptr->trainerHillTimes[i]);
        minutes = total / (60 * 60);
        total %= (60 * 60);
        ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsWhole = total / 60;
        total %= 60;
        ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsFraction = (total * 168) / 100;
        ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringExpandPlaceholders(StringCopy(gStringVar4, sText_TimeCleared), sText_XMinYDotZSec);
        x = 0xD0 - GetStringWidth(FONT_NORMAL, gStringVar4, 0); // Emerald's GetStringRightAlignXOffset
        AddTextPrinterParameterized3(0, FONT_NORMAL, x, y, sRecordWinColors, TEXT_SKIP_DRAW, gStringVar4);
        y += 17;
    }

    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

// RFVF+: a record of 0 is none yet (the save had no room for them before: zero in older saves)
static u32 GetTimerValue(u32 *src)
{
    return (*src == 0 || *src > HILL_MAX_TIME) ? HILL_MAX_TIME : *src;
}

static void SetTimerValue(u32 *dst, u32 val)
{
    *dst = val;
}

void LoadTrainerHillObjectEventTemplates(void)
{
    u8 i, floorId;
    struct ObjectEventTemplate *eventTemplates = gSaveBlock1Ptr->objectEventTemplates;

    SetUpDataStruct();
    for (i = 0; i < HILL_TRAINERS_PER_FLOOR; i++)
        gSaveBlock1Ptr->trainerHill.trainerIds[i] = 0xFF;
    CpuFill32(0, gSaveBlock1Ptr->objectEventTemplates, sizeof(gSaveBlock1Ptr->objectEventTemplates));

    floorId = GetFloorId();
    for (i = 0; i < HILL_TRAINERS_PER_FLOOR; i++)
    {
        u8 bits;

        eventTemplates[i] = sTrainerObjectEventTemplate;
        eventTemplates[i].localId = i + 1;
        ObjTemplateStoreGfxId(&eventTemplates[i], sHillTrainerClasses[FLOOR_DATA(floorId).trainers[i].facilityClass].graphicsId);
        eventTemplates[i].x = FLOOR_DATA(floorId).map.trainerCoords[i] & 0xF;
        eventTemplates[i].y = ((FLOOR_DATA(floorId).map.trainerCoords[i] >> 4) & 0xF) + HILL_FLOOR_HEIGHT_MARGIN;
        bits = i << 2;
        eventTemplates[i].objUnion.normal.movementType = ((FLOOR_DATA(floorId).map.trainerDirections >> bits) & 0xF) + MOVEMENT_TYPE_FACE_UP;
        eventTemplates[i].objUnion.normal.trainerRange_berryTreeId = (FLOOR_DATA(floorId).map.trainerRanges >> bits) & 0xF;
        eventTemplates[i].script = TrainerHill_EventScript_TrainerBattle;
        gSaveBlock1Ptr->trainerHill.trainerIds[i] = i + 1;
    }

    FreeDataStruct();
}

static u16 GetMapDataForFloor(u8 floorId, u32 x, u32 y, u32 floorWidth) // floorWidth is always 16
{
    bool8 impassable;
    u16 metatileId;
    u16 elevation;

    impassable = (FLOOR_DATA(floorId).map.collisionData[y] >> (15 - x) & 1);
    metatileId = FLOOR_DATA(floorId).map.metatileData[floorWidth * y + x] + NUM_METATILES_IN_PRIMARY;
    elevation = 3 << MAPGRID_ELEVATION_SHIFT;

    return (impassable << MAPGRID_COLLISION_SHIFT) | elevation | (metatileId & MAPGRID_METATILE_ID_MASK);
}

// RFVF+: the floor's map is loaded (fieldmap.c), then its 16x16 area under the 5 margin rows is drawn from the data
void GenerateTrainerHillFloorLayout(void)
{
    s32 y, x;
    u8 floorId;

    if (!InTrainerHill())
        return;
    SetUpDataStruct();
    floorId = GetFloorId();
    for (y = 0; y < HILL_FLOOR_HEIGHT_MAIN; y++)
        for (x = 0; x < HILL_FLOOR_WIDTH; x++)
            MapGridSetMetatileEntryAt(x + MAP_OFFSET, y + HILL_FLOOR_HEIGHT_MARGIN + MAP_OFFSET, GetMapDataForFloor(floorId, x, y, HILL_FLOOR_WIDTH));
    FreeDataStruct();
}

bool32 InTrainerHill(void)
{
    return gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_1F
        || gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_2F
        || gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_3F
        || gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_4F;
}

u8 GetCurrentTrainerHillMapId(void)
{
    u8 mapId;

    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_1F)
        mapId = TRAINER_HILL_1F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_2F)
        mapId = TRAINER_HILL_2F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_3F)
        mapId = TRAINER_HILL_3F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_4F)
        mapId = TRAINER_HILL_4F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_ROOF)
        mapId = TRAINER_HILL_ROOF;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_ENTRANCE)
        mapId = TRAINER_HILL_ENTRANCE;
    else
        mapId = 0;

    return mapId;
}

u16 LocalIdToHillTrainerId(u8 localId)
{
    return gSaveBlock1Ptr->trainerHill.trainerIds[localId - 1];
}

bool8 GetHillTrainerFlag(u8 objectEventId)
{
    u32 trainerIndexStart = GetFloorId() * HILL_TRAINERS_PER_FLOOR;
    u8 bitId = gObjectEvents[objectEventId].localId - 1 + trainerIndexStart;

    return gSaveBlock1Ptr->trainerHill.trainerFlags & (1 << bitId);
}

void SetHillTrainerFlag(void)
{
    u8 i;
    u8 trainerIndexStart = GetFloorId() * HILL_TRAINERS_PER_FLOOR;

    for (i = 0; i < HILL_TRAINERS_PER_FLOOR; i++)
    {
        if (gSaveBlock1Ptr->trainerHill.trainerIds[i] == gTrainerBattleOpponent_A)
        {
            gSaveBlock1Ptr->trainerHill.trainerFlags |= 1 << (trainerIndexStart + i);
            break;
        }
    }

    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        for (i = 0; i < HILL_TRAINERS_PER_FLOOR; i++)
        {
            if (gSaveBlock1Ptr->trainerHill.trainerIds[i] == gTrainerBattleOpponent_B)
            {
                gSaveBlock1Ptr->trainerHill.trainerFlags |= 1 << (trainerIndexStart + i);
                break;
            }
        }
    }
}

const u8 *GetTrainerHillTrainerScript(void)
{
    return TrainerHill_EventScript_TrainerBattle;
}

static void ShowTrainerHillPostBattleText(void)
{
    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_AFTER, gSpecialVar_LastTalked);
    ShowFieldMessage(gStringVar4);
}

static void CreateNPCTrainerHillParty(u16 trainerId, u8 firstMonId)
{
    u8 trId, level;
    s32 i, floorId, partySlot;

    if (trainerId == 0 || trainerId > HILL_TRAINERS_PER_FLOOR)
        return;

    trId = trainerId - 1;
    SetUpDataStruct();
    level = GetHighestLevelInPlayerParty();
    floorId = GetFloorId();
    for (i = firstMonId, partySlot = 0; i < firstMonId + PARTY_SIZE / 2; i++, partySlot++)
    {
        u8 id = sTrainerPartySlots[trId][partySlot];
        struct Pokemon *mon = &gEnemyParty[i];

        CreateBattleTowerMon(mon, &FLOOR_DATA(floorId).trainers[trId].mons[id]);
        SetTrainerHillMonLevel(mon, level);
    }

    FreeDataStruct();
}

void FillHillTrainerParty(void)
{
    ZeroEnemyPartyMons();
    CreateNPCTrainerHillParty(gTrainerBattleOpponent_A, 0);
}

void FillHillTrainersParties(void)
{
    ZeroEnemyPartyMons();
    CreateNPCTrainerHillParty(gTrainerBattleOpponent_A, 0);
    CreateNPCTrainerHillParty(gTrainerBattleOpponent_B, PARTY_SIZE / 2);
}

u8 GetTrainerEncounterMusicIdInTrainerHill(u16 trainerId)
{
    u8 trId, facilityClass;

    SetUpDataStruct();
    trId = trainerId - 1;
    facilityClass = FLOOR_DATA(sHillData->floorId).trainers[trId].facilityClass;
    FreeDataStruct();

    return sHillTrainerClasses[facilityClass].encounterMusic;
}

static void SetTrainerHillMonLevel(struct Pokemon *mon, u8 level)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 exp = gExperienceTables[gSpeciesInfo[species].growthRate][level];

    SetMonData(mon, MON_DATA_EXP, &exp);
    SetMonData(mon, MON_DATA_LEVEL, &level);
    CalculateMonStats(mon, TRUE);
}

u8 GetNumFloorsInTrainerHillChallenge(void)
{
    u8 numFloors;

    SetUpDataStruct();
    numFloors = sHillData->data.challenge.numFloors;
    FreeDataStruct();

    return numFloors;
}

static void SetAllTrainerFlags(void)
{
    gSaveBlock1Ptr->trainerHill.trainerFlags = 0xFF;
}

static void GetGameSaved(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->trainerHill.savedGame;
}

static void SetGameSaved(void)
{
    gSaveBlock1Ptr->trainerHill.savedGame = TRUE;
}

static void ClearGameSaved(void)
{
    gSaveBlock1Ptr->trainerHill.savedGame = FALSE;
}

static void GetChallengeWon(void)
{
    if (gSaveBlock1Ptr->trainerHill.hasLost)
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
}

static void TrainerHillSetMode(void)
{
    gSaveBlock1Ptr->trainerHill.mode = gSpecialVar_0x8005;
    gSaveBlock1Ptr->trainerHill.bestTime = gSaveBlock1Ptr->trainerHillTimes[gSpecialVar_0x8005];
}

// Determines which prize list to use from the set of prize lists (Emerald's).
static u8 GetPrizeListId(bool8 allowTMs)
{
    u8 prizeListId, i, modBy;

    prizeListId = 0;
    for (i = 0; i < NUM_TRAINER_HILL_FLOORS; i++)
    {
        prizeListId ^= sHillData->data.floors[i].trainerNum1 & 0x1F;
        prizeListId ^= sHillData->data.floors[i].trainerNum2 & 0x1F;
    }

    if (allowTMs)
        modBy = NUM_TRAINER_HILL_PRIZE_LISTS;
    else
        modBy = NUM_TRAINER_HILL_PRIZE_LISTS / 2;

    prizeListId %= modBy;
    return prizeListId;
}

// Emerald's: Normal TM11, Variety Elixir, Unique TM19, Expert TM31 under 12 minutes, then Ether, Max Potion, Revive,
// Fluffy Tail and Great Ball as the time grows
static u16 GetPrizeItemId(void)
{
    u8 i;
    const u16 *prizeList;
    s32 trainerNumSum = 0, prizeListSetId, minutes, id;

    for (i = 0; i < NUM_TRAINER_HILL_FLOORS; i++)
    {
        trainerNumSum += sHillData->data.floors[i].trainerNum1;
        trainerNumSum += sHillData->data.floors[i].trainerNum2;
    }
    prizeListSetId = trainerNumSum / 256;
    prizeListSetId %= (int)ARRAY_COUNT(sPrizeListSets);

    if (FlagGet(FLAG_HOENN_GAME_CLEAR) && sHillData->data.challenge.numTrainers == NUM_TRAINER_HILL_TRAINERS)
        i = GetPrizeListId(TRUE);
    else
        i = GetPrizeListId(FALSE);

    // 1 is added to Expert mode's prize list selection because otherwise it has the same prizes as Variety
    if (gSaveBlock1Ptr->trainerHill.mode == HILL_MODE_EXPERT)
        i = (i + 1) % NUM_TRAINER_HILL_PRIZE_LISTS;

    prizeList = sPrizeListSets[prizeListSetId][i];

    minutes = (signed)(gSaveBlock1Ptr->trainerHill.timer) / (60 * 60);
    if (minutes < 12)
        id = 0; // Depends on list
    else if (minutes < 13)
        id = 1; // ITEM_ETHER
    else if (minutes < 14)
        id = 2; // ITEM_MAX_POTION
    else if (minutes < 16)
        id = 3; // ITEM_REVIVE
    else if (minutes < 18)
        id = 4; // ITEM_FLUFFY_TAIL
    else
        id = 5; // ITEM_GREAT_BALL

    return prizeList[id];
}

// ---------------------------------------------------------------- the records board (Emerald's battle_records.c)
static const u32 sTrainerHillWindowTileset[] = INCBIN_U32("graphics/trainer_hill/records_window.4bpp");
static const u16 sTrainerHillWindowPalette[] = INCBIN_U16("graphics/trainer_hill/records_window.gbapal");
static const u32 sTrainerHillWindowTilemap[] = INCBIN_U32("graphics/trainer_hill/records_window.bin");

static const struct BgTemplate sTrainerHillRecordsBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sTrainerHillRecordsWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 20
    },
    DUMMY_WIN_TEMPLATE
};

static void Task_ExitTrainerHillRecords(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        Free(sRecordsTilemapBuffer);
        FillWindowPixelBuffer(0, PIXEL_FILL(0));
        ClearWindowTilemap(0);
        CopyWindowToVram(0, COPYWIN_GFX);
        RemoveWindow(0);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
    }
}

static void Task_CloseTrainerHillRecordsOnButton(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ExitTrainerHillRecords;
    }
}

static void Task_TrainerHillWaitForPaletteFade(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_CloseTrainerHillRecordsOnButton;
}

static void VblankCB_TrainerHillRecords(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MainCB2_TrainerHillRecords(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CB2_ShowTrainerHillRecords(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 2:
        sRecordsTilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sTrainerHillRecordsBgTemplates, ARRAY_COUNT(sTrainerHillRecordsBgTemplates));
        SetBgTilemapBuffer(3, sRecordsTilemapBuffer);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(3, sTrainerHillWindowTileset, sizeof(sTrainerHillWindowTileset), 0);
        CopyToBgTilemapBufferRect(3, sTrainerHillWindowTilemap, 0, 0, 0x20, 0x20);
        LoadPalette(sTrainerHillWindowPalette, BG_PLTT_ID(0), sizeof(sTrainerHillWindowPalette));
        LoadPalette(GetTextWindowPalette(0), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 4:
        if (IsDma3ManagerBusyWithBgCopy() != TRUE)
        {
            ShowBg(0);
            ShowBg(3);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
        }
        break;
    case 5:
        InitWindows(sTrainerHillRecordsWindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_1D_MAP);
        SetVBlankCallback(VblankCB_TrainerHillRecords);
        PrintOnTrainerHillRecordsWindow();
        CreateTask(Task_TrainerHillWaitForPaletteFade, 8);
        SetMainCallback2(MainCB2_TrainerHillRecords);
        gMain.state = 0;
        break;
    }
}

void ShowTrainerHillRecords(void)
{
    SetVBlankCallback(NULL);
    SetMainCallback2(CB2_ShowTrainerHillRecords);
}
