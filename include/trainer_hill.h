#ifndef GUARD_TRAINER_HILL_H
#define GUARD_TRAINER_HILL_H

// RFVF+: Emerald's Trainer Hill (Hoenn batch 5), without its e-Reader challenges

#include "constants/trainer_hill.h"

#define HILL_TRAINER_NAME_LENGTH 10 // Emerald's TRAINER_NAME_LENGTH

struct TrainerHillTrainer
{
    u8 name[HILL_TRAINER_NAME_LENGTH + 1];
    u8 facilityClass; // RFVF+: index in sHillTrainerClasses (src/data/trainer_hill.h)
    bool32 unused;
    u16 speechBefore[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechWin[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechLose[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechAfter[EASY_CHAT_BATTLE_WORDS_COUNT];
    struct BattleTowerPokemon mons[PARTY_SIZE];
};

struct TrainerHillFloorMap
{
    u8 metatileData[HILL_FLOOR_WIDTH * HILL_FLOOR_HEIGHT_MAIN]; // + NUM_METATILES_IN_PRIMARY: gTileset_HoennTrainerHillFloors
    u16 collisionData[HILL_FLOOR_WIDTH]; // One bit for each tile in column-major order, so every array entry is one row. 1 = impassable, 0 = passable
    u8 trainerCoords[HILL_TRAINERS_PER_FLOOR]; // Starting at (0,5). Format is 0bYYYYXXXX.
    u8 trainerDirections; // DIR_* - 1, 4 bits per trainer
    u8 trainerRanges; // 4 bits per trainer
};

struct TrainerHillFloor
{
    u8 trainerNum1;
    u8 trainerNum2;
    struct TrainerHillTrainer trainers[HILL_TRAINERS_PER_FLOOR];
    struct TrainerHillFloorMap map;
};

struct TrainerHillChallenge
{
    u8 numTrainers;
    u8 unused1;
    u8 numFloors;
    u32 checksum; // A byte array sum of the floor data
};

struct TrainerHillChallengeData
{
    struct TrainerHillChallenge challenge;
    struct TrainerHillFloor floors[NUM_TRAINER_HILL_FLOORS];
};

// RFVF+: Emerald's facility classes of the floors, as this game draws them
struct HillTrainerClass
{
    u8 trainerClass;
    u8 trainerPic;
    u16 graphicsId;
    u8 encounterMusic;
};

void CallTrainerHillFunction(void);
void ResetTrainerHillResults(void);
u8 GetTrainerHillOpponentClass(u16 trainerId);
void GetTrainerHillTrainerName(u8 *dst, u16 trainerId);
u8 GetTrainerHillTrainerFrontSpriteId(u16 trainerId);
void InitTrainerHillBattleStruct(void);
void FreeTrainerHillBattleStruct(void);
void CopyTrainerHillTrainerText(u8 which, u16 trainerId);
bool8 InTrainerHillChallenge(void);
void ShowTrainerHillRecords(void);
void LoadTrainerHillObjectEventTemplates(void);
void GenerateTrainerHillFloorLayout(void);
bool32 InTrainerHill(void);
u8 GetCurrentTrainerHillMapId(void);
u16 LocalIdToHillTrainerId(u8 localId);
bool8 GetHillTrainerFlag(u8 objectEventId);
void SetHillTrainerFlag(void);
const u8 *GetTrainerHillTrainerScript(void);
void FillHillTrainerParty(void);
void FillHillTrainersParties(void);
u8 GetTrainerEncounterMusicIdInTrainerHill(u16 trainerId);
u8 GetNumFloorsInTrainerHillChallenge(void);

#endif // GUARD_TRAINER_HILL_H
