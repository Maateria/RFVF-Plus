// RFVF+: TEMPORARY. Batch 6 ports Emerald's Battle Frontier over several sessions (memory hoenn-lot6-frontier):
// these stand in for the files of the later sessions and go away, one block per session, as their real code lands.
// ponytail: stubs only reached by facilities not ported yet (Dome, Factory, recordings).
#include "global.h"
#include "characters.h"
#include "battle_dome.h"
#include "battle_factory.h"
#include "battle_pyramid.h"
#include "recorded_battle.h"

// ---- session 4: battle_factory.c
u8 GetFactoryMonFixedIV(u8 challengeNum, bool8 isLastBattle)
{
    return 0;
}

void FillFactoryBrainParty(void)
{
}

void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 moveArg, u8 moveSlot)
{
}

// ---- session 5: battle_dome.c
int GetDomeTrainerSelectedMons(u16 tournamentTrainerId)
{
    return 0;
}

int TrainerIdToDomeTournamentId(u16 trainerId)
{
    return 0;
}

// ---- session 6: battle_pyramid.c (the Frontier Pass asks where the player stands)
u8 CurrentBattlePyramidLocation(void)
{
    return PYRAMID_LOCATION_NONE;
}

// ---- session 7: the Lounge 3 gambler (field_specials.c)
void FrontierGamblerSetWonOrLost(bool8 won)
{
}

// ---- session 7: recorded_battle.c (no recording before it: "cannot record" paths)
bool32 CanCopyRecordedBattleSaveData(void)
{
    return FALSE;
}

void PlayRecordedBattle(void (*CB2_After)(void))
{
}

bool32 MoveRecordedBattleToSaveData(void)
{
    return FALSE;
}

u8 GetRecordedBattleFrontierFacility(void)
{
    return 0;
}

u8 GetRecordedBattleFronterBrainSymbol(void)
{
    return 0;
}

void GetRecordedBattleRecordMixFriendName(u8 *dst)
{
    dst[0] = EOS;
}

u8 GetRecordedBattleRecordMixFriendClass(void)
{
    return 0;
}

u8 GetRecordedBattleApprenticeId(void)
{
    return 0;
}

u8 GetRecordedBattleRecordMixFriendLanguage(void)
{
    return GAME_LANGUAGE;
}

u8 GetRecordedBattleApprenticeLanguage(void)
{
    return GAME_LANGUAGE;
}

void RecordedBattle_SaveBattleOutcome(void)
{
}

u16 *GetRecordedBattleEasyChatSpeech(void)
{
    static u16 sNone[EASY_CHAT_BATTLE_WORDS_COUNT];
    return sNone;
}
