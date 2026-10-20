// Emerald's field specials used by Hoenn's NPCs (point 1 scripts), and RFVF+'s replacements for what needs a clock.
#include "global.h"
#include "battle.h"
#include "characters.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "string_util.h"
#include "main.h"
#include "field_player_avatar.h"
#include "overworld.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "field_specials.h"
#include "hoenn_specials.h"
#include "dewford_trend.h"
#include "berry.h"
#include "event_object_movement.h"
#include "constants/items.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/opponents.h"
#include "constants/pokemon.h"

// French Emerald's gText_BigGuy / gText_BigGirl are empty: its texts do not use them.
void GetPlayerBigGuyGirlString(void)
{
    gStringVar1[0] = EOS;
}

void IsGrassTypeInParty(void)
{
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES) && !GetMonData(mon, MON_DATA_IS_EGG))
        {
            u16 species = GetMonData(mon, MON_DATA_SPECIES);
            if (gSpeciesInfo[species].types[0] == TYPE_GRASS || gSpeciesInfo[species].types[1] == TYPE_GRASS)
            {
                gSpecialVar_Result = TRUE;
                return;
            }
        }
    }
    gSpecialVar_Result = FALSE;
}

bool8 FoundBlackGlasses(void)
{
    return FlagGet(FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES);
}

// Emerald's CopyMonFavoritePokeblockName: the first flavor the lead Pokemon's nature likes (official French names).
static const u8 sText_RedPokeblock[] = _("POKéBLOC ROUGE");
static const u8 sText_BluePokeblock[] = _("POKéBLOC BLEU");
static const u8 sText_PinkPokeblock[] = _("POKéBLOC ROSE");
static const u8 sText_GreenPokeblock[] = _("POKéBLOC VERT");
static const u8 sText_YellowPokeblock[] = _("POKéBLOC JAUNE");
static const u8 *const sFavoritePokeblockNames[] = {
    sText_RedPokeblock, sText_BluePokeblock, sText_PinkPokeblock, sText_GreenPokeblock, sText_YellowPokeblock
};

// Emerald's gPokeblockFlavorCompatibilityTable: spicy, dry, sweet, bitter, sour, for each nature
static const s8 sNatureFlavorLikes[NUM_NATURES][5] = {
    { 0,  0,  0,  0,  0}, { 1,  0,  0,  0, -1}, { 1,  0, -1,  0,  0}, { 1, -1,  0,  0,  0}, { 1,  0,  0, -1,  0},
    {-1,  0,  0,  0,  1}, { 0,  0,  0,  0,  0}, { 0,  0, -1,  0,  1}, { 0, -1,  0,  0,  1}, { 0,  0,  0, -1,  1},
    {-1,  0,  1,  0,  0}, { 0,  0,  1,  0, -1}, { 0,  0,  0,  0,  0}, { 0, -1,  1,  0,  0}, { 0,  0,  1, -1,  0},
    {-1,  1,  0,  0,  0}, { 0,  1,  0,  0, -1}, { 0,  1, -1,  0,  0}, { 0,  0,  0,  0,  0}, { 0,  1,  0, -1,  0},
    {-1,  0,  0,  1,  0}, { 0,  0,  0,  1, -1}, { 0,  0, -1,  1,  0}, { 0, -1,  0,  1,  0}, { 0,  0,  0,  0,  0},
};

u8 GetPokeblockNameByMonNature(void)
{
    u8 nature = GetNature(&gPlayerParty[GetLeadMonIndex()]);
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sFavoritePokeblockNames); i++)
    {
        if (sNatureFlavorLikes[nature][i] > 0)
        {
            StringCopy(gStringVar1, sFavoritePokeblockNames[i]);
            return TRUE;
        }
    }
    return FALSE;
}

// RFVF+: no clock, a "day" is 1,000 steps (user's choice, 2026-10-19).
#define STEPS_PER_DAY 1000

void HoennDays_OnStep(void)
{
    u16 i;
    u16 steps = VarGet(VAR_HOENN_DAY_STEPS) + 1;

    if (steps >= STEPS_PER_DAY)
    {
        steps = 0;
        VarSet(VAR_HOENN_DAY_COUNT, VarGet(VAR_HOENN_DAY_COUNT) + 1);
        UpdateDewfordTrendPerDay(1);
        for (i = FLAG_HOENN_BERRY_TREES_START; i <= FLAG_HOENN_BERRY_TREES_END; i++) // the picked trees grow back
            FlagClear(i);
        for (i = FLAG_RECEIVED_SHOAL_SALT_1; i <= FLAG_RECEIVED_SHOAL_SHELL_4; i++) // Shoal Cave's salt and shells too
            FlagClear(i);
    }
    VarSet(VAR_HOENN_DAY_STEPS, steps);
}

#include "data/hoenn_berry_trees.h"

// The berry tree just talked to (Emerald's tree id in its object): VAR_0x8004 = its berry, VAR_0x8005 = how many
// (Emerald's yield without watering: the berry's minimum), STR_VAR_1 = their name, STR_VAR_2 = the count
void GetHoennBerryTreeBerries(void)
{
    u16 item = sHoennBerryTrees[gObjectEvents[gSelectedObjectEvent].trainerRange_berryTreeId];
    u8 count = gBerries[item - FIRST_BERRY_INDEX].minYield;
    u8 *s;

    gSpecialVar_0x8004 = item;
    gSpecialVar_0x8005 = count;
    CopyItemName(item, gStringVar1);
    // "BAIE ORAN" -> "BAIES ORAN"
    if (count > 1 && gStringVar1[4] == CHAR_SPACE)
    {
        for (s = gStringVar1 + StringLength(gStringVar1) + 1; s > gStringVar1 + 4; s--)
            *s = *(s - 1);
        gStringVar1[4] = CHAR_S;
    }
    ConvertIntToDecimalStringN(gStringVar2, count, STR_CONV_MODE_LEFT_ALIGN, 2);
}

// Mirage Island (Route 130): RFVF+'s rule (user's choice): the Pacifidlog watcher sees it when the party has Latios or
// Latias, and it stays until the next day. VAR_MIRAGE_ISLAND_DAY = that day + 1.
bool8 IsMirageIslandPresent(void)
{
    return VarGet(VAR_MIRAGE_ISLAND_DAY) == (u16)(VarGet(VAR_HOENN_DAY_COUNT) + 1);
}

bool8 TryShowMirageIsland(void)
{
    u8 i;

    for (i = 0; i < PARTY_SIZE && !IsMirageIslandPresent(); i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species == SPECIES_LATIOS || species == SPECIES_LATIAS)
        {
            VarSet(VAR_MIRAGE_ISLAND_DAY, VarGet(VAR_HOENN_DAY_COUNT) + 1);
            FlagClear(FLAG_HOENN_BERRY_TREE_ROUTE_130_LIECHI); // hidden while the island was away
        }
    }
    return IsMirageIslandPresent();
}

// Emerald's Pacifidlog Fan Club TM: once a week (7 days)
void SetPacifidlogTMReceivedDay(void)
{
    VarSet(VAR_PACIFIDLOG_TM_RECEIVED_DAY, VarGet(VAR_HOENN_DAY_COUNT));
}

// Lilycove Department Store's clear-out sale (Emerald's comes with a TV news): every 7th day
bool8 IsLilycoveClearOutSaleDay(void)
{
    return VarGet(VAR_HOENN_DAY_COUNT) % 7 == 0;
}

u16 GetDaysUntilPacifidlogTMAvailable(void)
{
    u16 elapsed = VarGet(VAR_HOENN_DAY_COUNT) - VarGet(VAR_PACIFIDLOG_TM_RECEIVED_DAY);

    return elapsed >= 7 ? 0 : 7 - elapsed;
}

// RFVF+: Kiri (Sootopolis) and the Berry Master's wife (Route 123) give their berries again after every win against a
// Hoenn gym leader, Elite Four member or Champion, rematches included (user's choice): one pending gift per win.
#define MAX_PENDING_BERRY_GIFTS 99

static bool8 IsHoennLeagueTrainer(u16 trainerId)
{
    u8 trainerClass;

    if (trainerId < TRAINER_HOENN_START || trainerId >= TRAINER_HOENN_START + HOENN_TRAINERS_COUNT)
        return FALSE;
    trainerClass = gTrainers[trainerId].trainerClass;
    return trainerClass == TRAINER_CLASS_LEADER || trainerClass == TRAINER_CLASS_ELITE_FOUR
        || trainerClass == TRAINER_CLASS_CHAMPION;
}

static void AddPendingGift(u16 var)
{
    if (VarGet(var) < MAX_PENDING_BERRY_GIFTS)
        VarSet(var, VarGet(var) + 1);
}

void HoennBerryGifts_OnTrainerBattleWon(u16 trainerId)
{
    if (IsHoennLeagueTrainer(trainerId))
    {
        AddPendingGift(VAR_KIRI_BERRY_GIFTS);
        AddPendingGift(VAR_BERRY_MASTERS_WIFE_GIFTS);
    }
}

// The Berry Master's wife gives all her berries at once: one of each berry she may give in Emerald
// (Cheri to Sitrus) and her five phrase berries.
// Returns how many went into the bag.
u16 GiveBerryMastersWifeBerries(void)
{
    static const u16 sPhraseBerries[] = {ITEM_SPELON_BERRY, ITEM_PAMTRE_BERRY, ITEM_WATMEL_BERRY, ITEM_DURIN_BERRY,
                                         ITEM_BELUE_BERRY};
    u16 i, given = 0;

    for (i = 0; i < NUM_BERRY_MASTER_WIFE_BERRIES; i++)
        given += AddBagItem(FIRST_BERRY_MASTER_WIFE_BERRY + i, 1);
    for (i = 0; i < ARRAY_COUNT(sPhraseBerries); i++)
        given += AddBagItem(sPhraseBerries[i], 1);
    return given;
}

// Emerald's Seaside Cycling Road challenge (Route 110): collisions and time between the north gate and the south end.
// RFVF+: any bike qualifies (the only Bicycle has the Mach and Acro moves once upgraded).
static const u8 sText_99TimesPlus[] = _("plus de 99");    // official French texts
static const u8 sText_1MinutePlus[] = _("plus d'1 min");
static const u8 sText_SpaceSeconds[] = _(" secondes");

EWRAM_DATA bool8 gBikeCyclingChallenge = FALSE;
EWRAM_DATA u8 gBikeCollisions = 0;
static EWRAM_DATA u32 sBikeCyclingTimer = 0;

void Bike_TryAdvanceCyclingRoadCollisions(void)
{
    if (gBikeCyclingChallenge && gBikeCollisions < 100)
        gBikeCollisions++;
}

void Special_BeginCyclingRoadChallenge(void)
{
    gBikeCyclingChallenge = TRUE;
    gBikeCollisions = 0;
    sBikeCyclingTimer = gMain.vblankCounter2;
}

static void DetermineCyclingRoadResults(u32 numFrames, u8 numBikeCollisions)
{
    u8 result;

    if (numBikeCollisions < 100)
        ConvertIntToDecimalStringN(gStringVar1, numBikeCollisions, STR_CONV_MODE_LEFT_ALIGN, 2);
    else
        StringCopy(gStringVar1, sText_99TimesPlus);

    if (numFrames < 3600)
    {
        ConvertIntToDecimalStringN(gStringVar2, numFrames / 60, STR_CONV_MODE_RIGHT_ALIGN, 2);
        gStringVar2[2] = CHAR_COMMA;
        ConvertIntToDecimalStringN(&gStringVar2[3], ((numFrames % 60) * 100) / 60, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringAppend(gStringVar2, sText_SpaceSeconds);
    }
    else
    {
        StringCopy(gStringVar2, sText_1MinutePlus);
    }

    result = 0;
    if (numBikeCollisions == 0)
        result = 5;
    else if (numBikeCollisions < 4)
        result = 4;
    else if (numBikeCollisions < 10)
        result = 3;
    else if (numBikeCollisions < 20)
        result = 2;
    else if (numBikeCollisions < 100)
        result = 1;

    if (numFrames / 60 <= 10)
        result += 5;
    else if (numFrames / 60 <= 15)
        result += 4;
    else if (numFrames / 60 <= 20)
        result += 3;
    else if (numFrames / 60 <= 40)
        result += 2;
    else if (numFrames / 60 < 60)
        result += 1;

    gSpecialVar_Result = result;
}

static void RecordCyclingRoadResults(u32 numFrames, u8 numBikeCollisions)
{
    u32 framesRecord = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L) + (VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H) << 16);

    if (framesRecord > numFrames || framesRecord == 0)
    {
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_L, numFrames);
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_H, numFrames >> 16);
        VarSet(VAR_CYCLING_ROAD_RECORD_COLLISIONS, numBikeCollisions);
    }
}

void FinishCyclingRoadChallenge(void)
{
    u32 numFrames = gMain.vblankCounter2 - sBikeCyclingTimer;

    DetermineCyclingRoadResults(numFrames, gBikeCollisions);
    RecordCyclingRoadResults(numFrames, gBikeCollisions);
    gBikeCyclingChallenge = FALSE;
}

u16 GetRecordedCyclingRoadResults(void)
{
    u32 framesRecord = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L) + (VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H) << 16);

    if (framesRecord == 0)
        return FALSE;
    DetermineCyclingRoadResults(framesRecord, VarGet(VAR_CYCLING_ROAD_RECORD_COLLISIONS));
    return TRUE;
}

void UpdateCyclingRoadState(void)
{
    if (gLastUsedWarp.mapNum == MAP_NUM(ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE)
     && gLastUsedWarp.mapGroup == MAP_GROUP(ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE))
        return;

    if (VarGet(VAR_CYCLING_CHALLENGE_STATE) == 2 || VarGet(VAR_CYCLING_CHALLENGE_STATE) == 3)
    {
        VarSet(VAR_CYCLING_CHALLENGE_STATE, 0);
        gBikeCyclingChallenge = FALSE;
        Overworld_SetSavedMusic(MUS_DUMMY);
    }
}
