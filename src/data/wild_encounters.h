#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 20  
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 + 20 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 + 10 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 + 10 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 + 10 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 + 10 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 + 5 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 + 5 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 + 4 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 + 4 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 + 1 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_11 ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 + 1 
#define ENCOUNTER_CHANCE_LAND_MONS_TOTAL (ENCOUNTER_CHANCE_LAND_MONS_SLOT_11)

#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 60  
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 + 30 
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 + 5 
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 + 4 
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_4 ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 + 1 
#define ENCOUNTER_CHANCE_WATER_MONS_TOTAL (ENCOUNTER_CHANCE_WATER_MONS_SLOT_4)

#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 60  
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 + 30 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 + 5 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 + 4 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 + 1 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_TOTAL (ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4)

#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 60 
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)

#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 70 
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1 ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 + 30
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1)

#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 40 
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 + 40
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 + 15
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 + 4
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 + 1
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)

const struct WildPokemon sSevenIslandTanobyRuinsMoneanChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsMoneanChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsMoneanChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsLiptooChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsLiptooChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsLiptooChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsWeepthChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsWeepthChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsWeepthChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsDilfordChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsDilfordChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsDilfordChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsScufibChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsScufibChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsScufibChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsRixyChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsRixyChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsRixyChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsViapoisChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsViapoisChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsViapoisChamber_FireRed_LandMons };

const struct WildPokemon sViridianForest_FireRed_LandMons[] =
{
    { 4, 4, SPECIES_CATERPIE },
    { 4, 4, SPECIES_WEEDLE },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_WEEDLE },
    { 3, 3, SPECIES_CATERPIE },
    { 3, 3, SPECIES_WEEDLE },
    { 5, 5, SPECIES_METAPOD },
    { 5, 5, SPECIES_KAKUNA },
    { 4, 4, SPECIES_KAKUNA },
    { 3, 3, SPECIES_PIKACHU },
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_PIKACHU },
};

const struct WildPokemonInfo sViridianForest_FireRed_LandMonsInfo = { 14, sViridianForest_FireRed_LandMons };

const struct WildPokemon sMtMoon1F_FireRed_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 7, 7, SPECIES_GEODUDE },
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 8, 8, SPECIES_GEODUDE },
    { 9, 9, SPECIES_GEODUDE },
    { 8, 8, SPECIES_PARAS },
    { 7, 7, SPECIES_ZUBAT },
    { 7, 7, SPECIES_ZUBAT },
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_CLEFAIRY },
};

const struct WildPokemonInfo sMtMoon1F_FireRed_LandMonsInfo = { 7, sMtMoon1F_FireRed_LandMons };

const struct WildPokemon sMtMoonB1F_FireRed_LandMons[] =
{
    { 7, 7, SPECIES_PARAS },
    { 8, 8, SPECIES_PARAS },
    { 5, 5, SPECIES_PARAS },
    { 6, 6, SPECIES_PARAS },
    { 9, 9, SPECIES_PARAS },
    { 10, 10, SPECIES_PARAS },
    { 7, 7, SPECIES_PARAS },
    { 8, 8, SPECIES_PARAS },
    { 5, 5, SPECIES_PARAS },
    { 6, 6, SPECIES_PARAS },
    { 9, 9, SPECIES_PARAS },
    { 10, 10, SPECIES_PARAS },
};

const struct WildPokemonInfo sMtMoonB1F_FireRed_LandMonsInfo = { 5, sMtMoonB1F_FireRed_LandMons };

const struct WildPokemon sMtMoonB2F_FireRed_LandMons[] =
{
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_GEODUDE },
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 10, 10, SPECIES_GEODUDE },
    { 10, 10, SPECIES_PARAS },
    { 12, 12, SPECIES_PARAS },
    { 10, 10, SPECIES_CLEFAIRY },
    { 11, 11, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ZUBAT },
    { 12, 12, SPECIES_CLEFAIRY },
};

const struct WildPokemonInfo sMtMoonB2F_FireRed_LandMonsInfo = { 7, sMtMoonB2F_FireRed_LandMons };

const struct WildPokemon sSSAnneExterior_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sSSAnneExterior_FireRed_WaterMonsInfo = { 1, sSSAnneExterior_FireRed_WaterMons };

const struct WildPokemon sSSAnneExterior_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSSAnneExterior_FireRed_FishingMonsInfo = { 10, sSSAnneExterior_FireRed_FishingMons };

const struct WildPokemon sDiglettsCaveB1F_FireRed_LandMons[] =
{
    { 18, 18, SPECIES_DIGLETT },
    { 19, 19, SPECIES_DIGLETT },
    { 17, 17, SPECIES_DIGLETT },
    { 15, 15, SPECIES_DIGLETT },
    { 16, 16, SPECIES_DIGLETT },
    { 20, 20, SPECIES_DIGLETT },
    { 21, 21, SPECIES_DIGLETT },
    { 22, 22, SPECIES_DIGLETT },
    { 17, 17, SPECIES_DIGLETT },
    { 29, 29, SPECIES_DUGTRIO },
    { 17, 17, SPECIES_DIGLETT },
    { 31, 31, SPECIES_DUGTRIO },
};

const struct WildPokemonInfo sDiglettsCaveB1F_FireRed_LandMonsInfo = { 5, sDiglettsCaveB1F_FireRed_LandMons };

const struct WildPokemon sVictoryRoad1F_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 40, 40, SPECIES_ONIX },
    { 43, 43, SPECIES_ONIX },
    { 46, 46, SPECIES_ONIX },
    { 32, 32, SPECIES_ZUBAT },
    { 44, 44, SPECIES_ARBOK },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_MAROWAK },
    { 44, 44, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad1F_FireRed_LandMonsInfo = { 7, sVictoryRoad1F_FireRed_LandMons };

const struct WildPokemon sVictoryRoad2F_FireRed_LandMons[] =
{
    { 34, 34, SPECIES_MACHOP },
    { 34, 34, SPECIES_GEODUDE },
    { 42, 42, SPECIES_PRIMEAPE },
    { 45, 45, SPECIES_ONIX },
    { 48, 48, SPECIES_ONIX },
    { 34, 34, SPECIES_ZUBAT },
    { 46, 46, SPECIES_ARBOK },
    { 46, 46, SPECIES_GOLBAT },
    { 46, 46, SPECIES_MAROWAK },
    { 46, 46, SPECIES_MACHOKE },
    { 48, 48, SPECIES_MACHOKE },
    { 48, 48, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad2F_FireRed_LandMonsInfo = { 7, sVictoryRoad2F_FireRed_LandMons };

const struct WildPokemon sVictoryRoad3F_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 40, 40, SPECIES_ONIX },
    { 43, 43, SPECIES_ONIX },
    { 46, 46, SPECIES_ONIX },
    { 32, 32, SPECIES_ZUBAT },
    { 44, 44, SPECIES_ARBOK },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_MAROWAK },
    { 44, 44, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad3F_FireRed_LandMonsInfo = { 7, sVictoryRoad3F_FireRed_LandMons };

const struct WildPokemon sPokemonMansion1F_FireRed_LandMons[] =
{
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_KOFFING },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_GROWLITHE },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_WEEZING },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion1F_FireRed_LandMonsInfo = { 7, sPokemonMansion1F_FireRed_LandMons };

const struct WildPokemon sPokemonMansion2F_FireRed_LandMons[] =
{
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_KOFFING },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_GROWLITHE },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_WEEZING },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion2F_FireRed_LandMonsInfo = { 7, sPokemonMansion2F_FireRed_LandMons };

const struct WildPokemon sPokemonMansion3F_FireRed_LandMons[] =
{
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_KOFFING },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_GROWLITHE },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_WEEZING },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion3F_FireRed_LandMonsInfo = { 7, sPokemonMansion3F_FireRed_LandMons };

const struct WildPokemon sPokemonMansionB1F_FireRed_LandMons[] =
{
    { 28, 28, SPECIES_KOFFING },
    { 34, 34, SPECIES_RATICATE },
    { 30, 30, SPECIES_KOFFING },
    { 30, 30, SPECIES_DITTO },
    { 30, 30, SPECIES_GROWLITHE },
    { 38, 38, SPECIES_RATICATE },
    { 28, 28, SPECIES_GRIMER },
    { 34, 34, SPECIES_WEEZING },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansionB1F_FireRed_LandMonsInfo = { 5, sPokemonMansionB1F_FireRed_LandMons };

const struct WildPokemon sSafariZoneCenter_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_RHYHORN },
    { 22, 22, SPECIES_NIDORAN_M },
    { 24, 24, SPECIES_EXEGGCUTE },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 22, 22, SPECIES_VENONAT },
    { 31, 31, SPECIES_NIDORINO },
    { 31, 31, SPECIES_NIDORINA },
    { 30, 30, SPECIES_PARASECT },
    { 22, 22, SPECIES_VENONAT },
    { 23, 23, SPECIES_SCYTHER },
    { 22, 22, SPECIES_VENONAT },
    { 23, 23, SPECIES_CHANSEY },
};

const struct WildPokemonInfo sSafariZoneCenter_FireRed_LandMonsInfo = { 21, sSafariZoneCenter_FireRed_LandMons };

const struct WildPokemon sSafariZoneCenter_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSafariZoneCenter_FireRed_WaterMonsInfo = { 2, sSafariZoneCenter_FireRed_WaterMons };

const struct WildPokemon sSafariZoneCenter_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneCenter_FireRed_FishingMonsInfo = { 20, sSafariZoneCenter_FireRed_FishingMons };

const struct WildPokemon sSafariZoneEast_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_NIDORAN_M },
    { 26, 26, SPECIES_DODUO },
    { 23, 23, SPECIES_EXEGGCUTE },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 22, 22, SPECIES_PARAS },
    { 33, 33, SPECIES_NIDORINO },
    { 24, 24, SPECIES_NIDORAN_F },
    { 25, 25, SPECIES_PARASECT },
    { 22, 22, SPECIES_PARAS },
    { 25, 25, SPECIES_KANGASKHAN },
    { 22, 22, SPECIES_PARAS },
    { 28, 28, SPECIES_SCYTHER },
};

const struct WildPokemonInfo sSafariZoneEast_FireRed_LandMonsInfo = { 21, sSafariZoneEast_FireRed_LandMons };

const struct WildPokemon sSafariZoneEast_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSafariZoneEast_FireRed_WaterMonsInfo = { 2, sSafariZoneEast_FireRed_WaterMons };

const struct WildPokemon sSafariZoneEast_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneEast_FireRed_FishingMonsInfo = { 20, sSafariZoneEast_FireRed_FishingMons };

const struct WildPokemon sSafariZoneNorth_FireRed_LandMons[] =
{
    { 26, 26, SPECIES_RHYHORN },
    { 30, 30, SPECIES_NIDORAN_M },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 27, 27, SPECIES_EXEGGCUTE },
    { 23, 23, SPECIES_PARAS },
    { 30, 30, SPECIES_NIDORINO },
    { 30, 30, SPECIES_NIDORINA },
    { 32, 32, SPECIES_VENOMOTH },
    { 23, 23, SPECIES_PARAS },
    { 26, 26, SPECIES_CHANSEY },
    { 23, 23, SPECIES_PARAS },
    { 28, 28, SPECIES_TAUROS },
};

const struct WildPokemonInfo sSafariZoneNorth_FireRed_LandMonsInfo = { 21, sSafariZoneNorth_FireRed_LandMons };

const struct WildPokemon sSafariZoneNorth_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSafariZoneNorth_FireRed_WaterMonsInfo = { 2, sSafariZoneNorth_FireRed_WaterMons };

const struct WildPokemon sSafariZoneNorth_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneNorth_FireRed_FishingMonsInfo = { 20, sSafariZoneNorth_FireRed_FishingMons };

const struct WildPokemon sSafariZoneWest_FireRed_LandMons[] =
{
    { 26, 26, SPECIES_DODUO },
    { 22, 22, SPECIES_NIDORAN_M },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 27, 27, SPECIES_EXEGGCUTE },
    { 23, 23, SPECIES_VENONAT },
    { 30, 30, SPECIES_NIDORINO },
    { 30, 30, SPECIES_NIDORAN_F },
    { 32, 32, SPECIES_VENOMOTH },
    { 23, 23, SPECIES_VENONAT },
    { 25, 25, SPECIES_TAUROS },
    { 23, 23, SPECIES_VENONAT },
    { 28, 28, SPECIES_KANGASKHAN },
};

const struct WildPokemonInfo sSafariZoneWest_FireRed_LandMonsInfo = { 21, sSafariZoneWest_FireRed_LandMons };

const struct WildPokemon sSafariZoneWest_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSafariZoneWest_FireRed_WaterMonsInfo = { 2, sSafariZoneWest_FireRed_WaterMons };

const struct WildPokemon sSafariZoneWest_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneWest_FireRed_FishingMonsInfo = { 20, sSafariZoneWest_FireRed_FishingMons };

const struct WildPokemon sCeruleanCave1F_FireRed_LandMons[] =
{
    { 49, 49, SPECIES_MAGNETON },
    { 49, 49, SPECIES_PARASECT },
    { 46, 46, SPECIES_GOLBAT },
    { 46, 46, SPECIES_MACHOKE },
    { 52, 52, SPECIES_PRIMEAPE },
    { 52, 52, SPECIES_DITTO },
    { 58, 58, SPECIES_ELECTRODE },
    { 58, 58, SPECIES_PARASECT },
    { 55, 55, SPECIES_GOLBAT },
    { 55, 55, SPECIES_WOBBUFFET },
    { 61, 61, SPECIES_PRIMEAPE },
    { 61, 61, SPECIES_DITTO },
};

const struct WildPokemonInfo sCeruleanCave1F_FireRed_LandMonsInfo = { 7, sCeruleanCave1F_FireRed_LandMons };

const struct WildPokemon sCeruleanCave1F_FireRed_WaterMons[] =
{
    { 30, 40, SPECIES_PSYDUCK },
    { 40, 50, SPECIES_GOLDUCK },
    { 45, 55, SPECIES_GOLDUCK },
    { 40, 50, SPECIES_PSYDUCK },
    { 40, 50, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCeruleanCave1F_FireRed_WaterMonsInfo = { 2, sCeruleanCave1F_FireRed_WaterMons };

const struct WildPokemon sCeruleanCave1F_FireRed_RockSmashMons[] =
{
    { 30, 40, SPECIES_GEODUDE },
    { 40, 50, SPECIES_GRAVELER },
    { 45, 55, SPECIES_GRAVELER },
    { 40, 50, SPECIES_GEODUDE },
    { 40, 50, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCave1F_FireRed_RockSmashMonsInfo = { 50, sCeruleanCave1F_FireRed_RockSmashMons };

const struct WildPokemon sCeruleanCave1F_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCeruleanCave1F_FireRed_FishingMonsInfo = { 20, sCeruleanCave1F_FireRed_FishingMons };

const struct WildPokemon sCeruleanCave2F_FireRed_LandMons[] =
{
    { 49, 49, SPECIES_GOLBAT },
    { 49, 49, SPECIES_MACHOKE },
    { 52, 52, SPECIES_MAGNETON },
    { 52, 52, SPECIES_PARASECT },
    { 55, 55, SPECIES_KADABRA },
    { 55, 55, SPECIES_DITTO },
    { 58, 58, SPECIES_GOLBAT },
    { 58, 58, SPECIES_WOBBUFFET },
    { 61, 61, SPECIES_ELECTRODE },
    { 61, 61, SPECIES_PARASECT },
    { 64, 64, SPECIES_KADABRA },
    { 64, 64, SPECIES_DITTO },
};

const struct WildPokemonInfo sCeruleanCave2F_FireRed_LandMonsInfo = { 7, sCeruleanCave2F_FireRed_LandMons };

const struct WildPokemon sCeruleanCave2F_FireRed_RockSmashMons[] =
{
    { 35, 45, SPECIES_GEODUDE },
    { 45, 55, SPECIES_GRAVELER },
    { 50, 60, SPECIES_GRAVELER },
    { 45, 55, SPECIES_GEODUDE },
    { 45, 55, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCave2F_FireRed_RockSmashMonsInfo = { 50, sCeruleanCave2F_FireRed_RockSmashMons };

const struct WildPokemon sCeruleanCaveB1F_FireRed_LandMons[] =
{
    { 58, 58, SPECIES_KADABRA },
    { 58, 58, SPECIES_DITTO },
    { 55, 55, SPECIES_MAGNETON },
    { 55, 55, SPECIES_PARASECT },
    { 52, 52, SPECIES_GOLBAT },
    { 52, 52, SPECIES_MACHOKE },
    { 67, 67, SPECIES_KADABRA },
    { 67, 67, SPECIES_DITTO },
    { 64, 64, SPECIES_ELECTRODE },
    { 64, 64, SPECIES_PARASECT },
    { 61, 61, SPECIES_GOLBAT },
    { 61, 61, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo sCeruleanCaveB1F_FireRed_LandMonsInfo = { 7, sCeruleanCaveB1F_FireRed_LandMons };

const struct WildPokemon sCeruleanCaveB1F_FireRed_WaterMons[] =
{
    { 40, 50, SPECIES_PSYDUCK },
    { 50, 60, SPECIES_GOLDUCK },
    { 55, 65, SPECIES_GOLDUCK },
    { 50, 60, SPECIES_PSYDUCK },
    { 50, 60, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCeruleanCaveB1F_FireRed_WaterMonsInfo = { 2, sCeruleanCaveB1F_FireRed_WaterMons };

const struct WildPokemon sCeruleanCaveB1F_FireRed_RockSmashMons[] =
{
    { 40, 50, SPECIES_GEODUDE },
    { 50, 60, SPECIES_GRAVELER },
    { 55, 65, SPECIES_GRAVELER },
    { 50, 60, SPECIES_GEODUDE },
    { 50, 60, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCaveB1F_FireRed_RockSmashMonsInfo = { 50, sCeruleanCaveB1F_FireRed_RockSmashMons };

const struct WildPokemon sCeruleanCaveB1F_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sCeruleanCaveB1F_FireRed_FishingMonsInfo = { 20, sCeruleanCaveB1F_FireRed_FishingMons };

const struct WildPokemon sRockTunnel1F_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_ZUBAT },
    { 16, 16, SPECIES_GEODUDE },
    { 16, 16, SPECIES_MANKEY },
    { 17, 17, SPECIES_GEODUDE },
    { 16, 16, SPECIES_ZUBAT },
    { 16, 16, SPECIES_MACHOP },
    { 17, 17, SPECIES_MANKEY },
    { 17, 17, SPECIES_MACHOP },
    { 15, 15, SPECIES_GEODUDE },
    { 13, 13, SPECIES_ONIX },
    { 15, 15, SPECIES_CHARMANDER },
    { 15, 15, SPECIES_ONIX },
};

const struct WildPokemonInfo sRockTunnel1F_FireRed_LandMonsInfo = { 7, sRockTunnel1F_FireRed_LandMons };

const struct WildPokemon sRockTunnelB1F_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_ZUBAT },
    { 17, 17, SPECIES_GEODUDE },
    { 17, 17, SPECIES_MANKEY },
    { 16, 16, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ZUBAT },
    { 17, 17, SPECIES_MACHOP },
    { 16, 16, SPECIES_MANKEY },
    { 13, 13, SPECIES_ONIX },
    { 15, 15, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ONIX },
    { 15, 15, SPECIES_CHARMANDER },
    { 17, 17, SPECIES_ONIX },
};

const struct WildPokemonInfo sRockTunnelB1F_FireRed_LandMonsInfo = { 7, sRockTunnelB1F_FireRed_LandMons };

const struct WildPokemon sRockTunnelB1F_FireRed_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sRockTunnelB1F_FireRed_RockSmashMonsInfo = { 50, sRockTunnelB1F_FireRed_RockSmashMons };

const struct WildPokemon sSeafoamIslands1F_FireRed_LandMons[] =
{
    { 27, 27, SPECIES_PSYDUCK },
    { 29, 29, SPECIES_PSYDUCK },
    { 31, 31, SPECIES_PSYDUCK },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 28, 28, SPECIES_GOLBAT },
    { 33, 33, SPECIES_PSYDUCK },
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_PSYDUCK },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslands1F_FireRed_LandMonsInfo = { 7, sSeafoamIslands1F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB1F_FireRed_LandMons[] =
{
    { 29, 29, SPECIES_PSYDUCK },
    { 31, 31, SPECIES_PSYDUCK },
    { 28, 28, SPECIES_SEEL },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 28, 28, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLDUCK },
    { 26, 26, SPECIES_ZUBAT },
    { 35, 35, SPECIES_GOLDUCK },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB1F_FireRed_LandMonsInfo = { 7, sSeafoamIslandsB1F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB2F_FireRed_LandMons[] =
{
    { 30, 30, SPECIES_PSYDUCK },
    { 32, 32, SPECIES_PSYDUCK },
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_GOLDUCK },
    { 32, 32, SPECIES_GOLDUCK },
    { 28, 28, SPECIES_GOLBAT },
    { 32, 32, SPECIES_GOLDUCK },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB2F_FireRed_LandMonsInfo = { 7, sSeafoamIslandsB2F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB3F_FireRed_LandMons[] =
{
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 32, 32, SPECIES_PSYDUCK },
    { 30, 30, SPECIES_PSYDUCK },
    { 32, 32, SPECIES_GOLDUCK },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_GOLDUCK },
    { 32, 32, SPECIES_DEWGONG },
    { 28, 28, SPECIES_GOLBAT },
    { 34, 34, SPECIES_DEWGONG },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_FireRed_LandMonsInfo = { 7, sSeafoamIslandsB3F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB3F_FireRed_WaterMons[] =
{
    { 25, 35, SPECIES_SEEL },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_DEWGONG },
    { 30, 40, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_FireRed_WaterMonsInfo = { 2, sSeafoamIslandsB3F_FireRed_WaterMons };

const struct WildPokemon sSeafoamIslandsB3F_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 20, 30, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_FireRed_FishingMonsInfo = { 20, sSeafoamIslandsB3F_FireRed_FishingMons };

const struct WildPokemon sSeafoamIslandsB4F_FireRed_LandMons[] =
{
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 32, 32, SPECIES_PSYDUCK },
    { 34, 34, SPECIES_SEEL },
    { 32, 32, SPECIES_GOLDUCK },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_DEWGONG },
    { 34, 34, SPECIES_GOLDUCK },
    { 36, 36, SPECIES_DEWGONG },
    { 28, 28, SPECIES_GOLBAT },
    { 36, 36, SPECIES_DEWGONG },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_FireRed_LandMonsInfo = { 7, sSeafoamIslandsB4F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB4F_FireRed_WaterMons[] =
{
    { 25, 35, SPECIES_SEEL },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_DEWGONG },
    { 30, 40, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_FireRed_WaterMonsInfo = { 2, sSeafoamIslandsB4F_FireRed_WaterMons };

const struct WildPokemon sSeafoamIslandsB4F_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 20, 30, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_FireRed_FishingMonsInfo = { 20, sSeafoamIslandsB4F_FireRed_FishingMons };

const struct WildPokemon sPokemonTower3F_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower3F_FireRed_LandMonsInfo = { 2, sPokemonTower3F_FireRed_LandMons };

const struct WildPokemon sPokemonTower4F_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
};

const struct WildPokemonInfo sPokemonTower4F_FireRed_LandMonsInfo = { 4, sPokemonTower4F_FireRed_LandMons };

const struct WildPokemon sPokemonTower5F_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
};

const struct WildPokemonInfo sPokemonTower5F_FireRed_LandMonsInfo = { 6, sPokemonTower5F_FireRed_LandMons };

const struct WildPokemon sPokemonTower6F_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 15, 15, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 21, 21, SPECIES_HAUNTER },
    { 17, 17, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 19, 19, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower6F_FireRed_LandMonsInfo = { 8, sPokemonTower6F_FireRed_LandMons };

const struct WildPokemon sPokemonTower7F_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 15, 15, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
    { 17, 17, SPECIES_CUBONE },
    { 19, 19, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
    { 18, 18, SPECIES_GASTLY },
    { 25, 25, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower7F_FireRed_LandMonsInfo = { 10, sPokemonTower7F_FireRed_LandMons };

const struct WildPokemon sPowerPlant_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_PIKACHU },
    { 24, 24, SPECIES_PIKACHU },
    { 31, 31, SPECIES_MAGNETON },
    { 34, 34, SPECIES_MAGNETON },
    { 26, 26, SPECIES_PIKACHU },
    { 32, 32, SPECIES_ELECTABUZZ },
    { 26, 26, SPECIES_PIKACHU },
    { 35, 35, SPECIES_ELECTABUZZ },
};

const struct WildPokemonInfo sPowerPlant_FireRed_LandMonsInfo = { 7, sPowerPlant_FireRed_LandMons };

const struct WildPokemon sMtEmberExterior_FireRed_LandMons[] =
{
    { 30, 30, SPECIES_PONYTA },
    { 38, 38, SPECIES_FEAROW },
    { 33, 33, SPECIES_PONYTA },
    { 32, 32, SPECIES_SPEAROW },
    { 35, 35, SPECIES_MACHOP },
    { 33, 33, SPECIES_GEODUDE },
    { 36, 36, SPECIES_PONYTA },
    { 40, 40, SPECIES_FEAROW },
    { 30, 30, SPECIES_SPEAROW },
    { 39, 39, SPECIES_RAPIDASH },
    { 30, 30, SPECIES_SPEAROW },
    { 42, 42, SPECIES_RAPIDASH },
};

const struct WildPokemonInfo sMtEmberExterior_FireRed_LandMonsInfo = { 21, sMtEmberExterior_FireRed_LandMons };

const struct WildPokemon sMtEmberExterior_FireRed_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sMtEmberExterior_FireRed_RockSmashMonsInfo = { 50, sMtEmberExterior_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberSummitPath1F_FireRed_LandMons[] =
{
    { 33, 33, SPECIES_GEODUDE },
    { 35, 35, SPECIES_MACHOP },
    { 29, 29, SPECIES_GEODUDE },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MACHOP },
    { 33, 33, SPECIES_MACHOP },
    { 35, 35, SPECIES_GEODUDE },
    { 37, 37, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
};

const struct WildPokemonInfo sMtEmberSummitPath1F_FireRed_LandMonsInfo = { 7, sMtEmberSummitPath1F_FireRed_LandMons };

const struct WildPokemon sMtEmberSummitPath2F_FireRed_LandMons[] =
{
    { 34, 34, SPECIES_GEODUDE },
    { 36, 36, SPECIES_MACHOP },
    { 30, 30, SPECIES_GEODUDE },
    { 32, 32, SPECIES_GEODUDE },
    { 32, 32, SPECIES_MACHOP },
    { 34, 34, SPECIES_MACHOP },
    { 38, 38, SPECIES_MACHOKE },
    { 38, 38, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
};

const struct WildPokemonInfo sMtEmberSummitPath2F_FireRed_LandMonsInfo = { 7, sMtEmberSummitPath2F_FireRed_LandMons };

const struct WildPokemon sMtEmberSummitPath2F_FireRed_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sMtEmberSummitPath2F_FireRed_RockSmashMonsInfo = { 50, sMtEmberSummitPath2F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberSummitPath3F_FireRed_LandMons[] =
{
    { 33, 33, SPECIES_GEODUDE },
    { 35, 35, SPECIES_MACHOP },
    { 29, 29, SPECIES_GEODUDE },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MACHOP },
    { 33, 33, SPECIES_MACHOP },
    { 35, 35, SPECIES_GEODUDE },
    { 37, 37, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
};

const struct WildPokemonInfo sMtEmberSummitPath3F_FireRed_LandMonsInfo = { 7, sMtEmberSummitPath3F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPath1F_FireRed_LandMons[] =
{
    { 36, 36, SPECIES_GEODUDE },
    { 38, 38, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 34, 34, SPECIES_MACHOP },
    { 36, 36, SPECIES_MACHOP },
    { 38, 38, SPECIES_GEODUDE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_GEODUDE },
    { 42, 42, SPECIES_MACHOKE },
    { 40, 40, SPECIES_GEODUDE },
    { 42, 42, SPECIES_MACHOKE },
};

const struct WildPokemonInfo sMtEmberRubyPath1F_FireRed_LandMonsInfo = { 7, sMtEmberRubyPath1F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPath1F_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPath1F_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPath1F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB1F_FireRed_LandMons[] =
{
    { 38, 38, SPECIES_GEODUDE },
    { 36, 36, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 40, 40, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 28, 28, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB1F_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB1F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB1F_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB1F_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB1F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB2F_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GEODUDE },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 32, 32, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB2F_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB2F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB2F_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB2F_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB2F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB3F_FireRed_LandMons[] =
{
    { 26, 26, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 32, 32, SPECIES_SLUGMA },
    { 24, 24, SPECIES_SLUGMA },
    { 22, 22, SPECIES_SLUGMA },
    { 20, 20, SPECIES_SLUGMA },
    { 34, 34, SPECIES_SLUGMA },
    { 36, 36, SPECIES_SLUGMA },
    { 18, 18, SPECIES_SLUGMA },
    { 36, 36, SPECIES_SLUGMA },
    { 18, 18, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB3F_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB3F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB3F_FireRed_RockSmashMons[] =
{
    { 15, 25, SPECIES_SLUGMA },
    { 25, 35, SPECIES_SLUGMA },
    { 40, 45, SPECIES_MAGCARGO },
    { 35, 45, SPECIES_MAGCARGO },
    { 25, 35, SPECIES_MAGCARGO },
};

const struct WildPokemonInfo sMtEmberRubyPathB3F_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB3F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB1FStairs_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GEODUDE },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 32, 32, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB1FStairs_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB1FStairs_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB1FStairs_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB1FStairs_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB1FStairs_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB2FStairs_FireRed_LandMons[] =
{
    { 38, 38, SPECIES_GEODUDE },
    { 36, 36, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 40, 40, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 28, 28, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB2FStairs_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB2FStairs_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB2FStairs_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB2FStairs_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB2FStairs_FireRed_RockSmashMons };

const struct WildPokemon sThreeIslandBerryForest_FireRed_LandMons[] =
{
    { 37, 37, SPECIES_PIDGEOTTO },
    { 35, 35, SPECIES_GLOOM },
    { 32, 32, SPECIES_PIDGEY },
    { 30, 30, SPECIES_ODDISH },
    { 34, 34, SPECIES_VENONAT },
    { 34, 34, SPECIES_DROWZEE },
    { 35, 35, SPECIES_EXEGGCUTE },
    { 31, 31, SPECIES_PSYDUCK },
    { 37, 37, SPECIES_VENOMOTH },
    { 37, 37, SPECIES_HYPNO },
    { 40, 40, SPECIES_VENOMOTH },
    { 40, 40, SPECIES_HYPNO },
};

const struct WildPokemonInfo sThreeIslandBerryForest_FireRed_LandMonsInfo = { 21, sThreeIslandBerryForest_FireRed_LandMons };

const struct WildPokemon sThreeIslandBerryForest_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_PSYDUCK },
    { 20, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_GOLDUCK },
    { 35, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo sThreeIslandBerryForest_FireRed_WaterMonsInfo = { 2, sThreeIslandBerryForest_FireRed_WaterMons };

const struct WildPokemon sThreeIslandBerryForest_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sThreeIslandBerryForest_FireRed_FishingMonsInfo = { 20, sThreeIslandBerryForest_FireRed_FishingMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_FireRed_LandMons[] =
{
    { 43, 43, SPECIES_SEEL },
    { 45, 45, SPECIES_SPHEAL },
    { 45, 45, SPECIES_SEEL },
    { 47, 47, SPECIES_SEEL },
    { 40, 40, SPECIES_ZUBAT },
    { 49, 49, SPECIES_DEWGONG },
    { 51, 51, SPECIES_DEWGONG },
    { 41, 41, SPECIES_PSYDUCK },
    { 48, 48, SPECIES_SNORUNT },
    { 53, 53, SPECIES_DEWGONG },
    { 48, 48, SPECIES_SNORUNT },
    { 53, 53, SPECIES_DEWGONG },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_FireRed_LandMonsInfo = { 7, sFourIslandIcefallCaveEntrance_FireRed_LandMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_SEEL },
    { 5, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_DEWGONG },
    { 5, 15, SPECIES_WOOPER },
    { 5, 15, SPECIES_WOOPER },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_FireRed_WaterMonsInfo = { 2, sFourIslandIcefallCaveEntrance_FireRed_WaterMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_FireRed_FishingMonsInfo = { 20, sFourIslandIcefallCaveEntrance_FireRed_FishingMons };

const struct WildPokemon sFourIslandIcefallCave1F_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_SWINUB },
    { 45, 45, SPECIES_SPHEAL },
    { 45, 45, SPECIES_SEEL },
    { 27, 27, SPECIES_SWINUB },
    { 40, 40, SPECIES_ZUBAT },
    { 29, 29, SPECIES_SWINUB },
    { 30, 30, SPECIES_DELIBIRD },
    { 31, 31, SPECIES_SWINUB },
    { 48, 48, SPECIES_SNORUNT },
    { 23, 23, SPECIES_SWINUB },
    { 48, 48, SPECIES_SNORUNT },
    { 23, 23, SPECIES_SWINUB },
};

const struct WildPokemonInfo sFourIslandIcefallCave1F_FireRed_LandMonsInfo = { 7, sFourIslandIcefallCave1F_FireRed_LandMons };

const struct WildPokemon sFourIslandIcefallCaveB1F_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_SWINUB },
    { 45, 45, SPECIES_SPHEAL },
    { 45, 45, SPECIES_SEEL },
    { 27, 27, SPECIES_SWINUB },
    { 40, 40, SPECIES_ZUBAT },
    { 29, 29, SPECIES_SWINUB },
    { 30, 30, SPECIES_DELIBIRD },
    { 31, 31, SPECIES_SWINUB },
    { 48, 48, SPECIES_SNORUNT },
    { 23, 23, SPECIES_SWINUB },
    { 48, 48, SPECIES_SNORUNT },
    { 23, 23, SPECIES_SWINUB },
};

const struct WildPokemonInfo sFourIslandIcefallCaveB1F_FireRed_LandMonsInfo = { 7, sFourIslandIcefallCaveB1F_FireRed_LandMons };

const struct WildPokemon sFourIslandIcefallCaveBack_FireRed_LandMons[] =
{
    { 43, 43, SPECIES_SEEL },
    { 45, 45, SPECIES_SPHEAL },
    { 45, 45, SPECIES_SEEL },
    { 47, 47, SPECIES_SEEL },
    { 40, 40, SPECIES_ZUBAT },
    { 49, 49, SPECIES_DEWGONG },
    { 51, 51, SPECIES_DEWGONG },
    { 41, 41, SPECIES_PSYDUCK },
    { 48, 48, SPECIES_SNORUNT },
    { 53, 53, SPECIES_DEWGONG },
    { 48, 48, SPECIES_SNORUNT },
    { 53, 53, SPECIES_DEWGONG },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_FireRed_LandMonsInfo = { 7, sFourIslandIcefallCaveBack_FireRed_LandMons };

const struct WildPokemon sFourIslandIcefallCaveBack_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 45, SPECIES_TENTACOOL },
    { 35, 45, SPECIES_TENTACRUEL },
    { 30, 45, SPECIES_LAPRAS },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_FireRed_WaterMonsInfo = { 2, sFourIslandIcefallCaveBack_FireRed_WaterMons };

const struct WildPokemon sFourIslandIcefallCaveBack_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_FireRed_FishingMonsInfo = { 20, sFourIslandIcefallCaveBack_FireRed_FishingMons };

const struct WildPokemon sSixIslandPatternBush_FireRed_LandMons[] =
{
    { 9, 9, SPECIES_SPINARAK },
    { 9, 9, SPECIES_LEDYBA },
    { 14, 14, SPECIES_SPINARAK },
    { 15, 15, SPECIES_VOLBEAT },
    { 8, 8, SPECIES_WURMPLE },
    { 15, 15, SPECIES_ILLUMISE },
    { 18, 18, SPECIES_SHROOMISH },
    { 30, 30, SPECIES_TROPIUS },
    { 25, 25, SPECIES_HERACROSS },
    { 25, 25, SPECIES_HERACROSS },
    { 5, 5, SPECIES_TREECKO },
    { 5, 5, SPECIES_CHIKORITA },
};

const struct WildPokemonInfo sSixIslandPatternBush_FireRed_LandMonsInfo = { 21, sSixIslandPatternBush_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom1_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom1_FireRed_LandMonsInfo = { 1, sFiveIslandLostCaveRoom1_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom2_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom2_FireRed_LandMonsInfo = { 2, sFiveIslandLostCaveRoom2_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom3_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom3_FireRed_LandMonsInfo = { 3, sFiveIslandLostCaveRoom3_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom4_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom4_FireRed_LandMonsInfo = { 4, sFiveIslandLostCaveRoom4_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom5_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom5_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom5_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom6_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom6_FireRed_LandMonsInfo = { 6, sFiveIslandLostCaveRoom6_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom7_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom7_FireRed_LandMonsInfo = { 7, sFiveIslandLostCaveRoom7_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom8_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom8_FireRed_LandMonsInfo = { 8, sFiveIslandLostCaveRoom8_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom9_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom9_FireRed_LandMonsInfo = { 9, sFiveIslandLostCaveRoom9_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom10_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom10_FireRed_LandMonsInfo = { 10, sFiveIslandLostCaveRoom10_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom11_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MURKROW },
    { 20, 20, SPECIES_MURKROW },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom11_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom11_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom12_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MURKROW },
    { 20, 20, SPECIES_MURKROW },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom12_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom12_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom13_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MURKROW },
    { 20, 20, SPECIES_MURKROW },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom13_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom13_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom14_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MURKROW },
    { 20, 20, SPECIES_MURKROW },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom14_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom14_FireRed_LandMons };

const struct WildPokemon sOneIslandKindleRoad_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_SPEAROW },
    { 34, 34, SPECIES_PONYTA },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_PONYTA },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MEOWTH },
    { 30, 30, SPECIES_SPEAROW },
    { 34, 34, SPECIES_PSYDUCK },
    { 37, 37, SPECIES_RAPIDASH },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_RAPIDASH },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sOneIslandKindleRoad_FireRed_LandMonsInfo = { 21, sOneIslandKindleRoad_FireRed_LandMons };

const struct WildPokemon sOneIslandKindleRoad_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIslandKindleRoad_FireRed_WaterMonsInfo = { 2, sOneIslandKindleRoad_FireRed_WaterMons };

const struct WildPokemon sOneIslandKindleRoad_FireRed_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sOneIslandKindleRoad_FireRed_RockSmashMonsInfo = { 25, sOneIslandKindleRoad_FireRed_RockSmashMons };

const struct WildPokemon sOneIslandKindleRoad_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sOneIslandKindleRoad_FireRed_FishingMonsInfo = { 20, sOneIslandKindleRoad_FireRed_FishingMons };

const struct WildPokemon sOneIslandTreasureBeach_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_SPEAROW },
    { 33, 33, SPECIES_TANGELA },
    { 31, 31, SPECIES_SPEAROW },
    { 35, 35, SPECIES_TANGELA },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_MEOWTH },
    { 38, 38, SPECIES_FEAROW },
    { 31, 31, SPECIES_PSYDUCK },
    { 40, 40, SPECIES_FEAROW },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_FEAROW },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_FireRed_LandMonsInfo = { 21, sOneIslandTreasureBeach_FireRed_LandMons };

const struct WildPokemon sOneIslandTreasureBeach_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_FireRed_WaterMonsInfo = { 2, sOneIslandTreasureBeach_FireRed_WaterMons };

const struct WildPokemon sOneIslandTreasureBeach_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_FireRed_FishingMonsInfo = { 20, sOneIslandTreasureBeach_FireRed_FishingMons };

const struct WildPokemon sTwoIslandCapeBrink_FireRed_LandMons[] =
{
    { 31, 31, SPECIES_SPEAROW },
    { 30, 30, SPECIES_ODDISH },
    { 32, 32, SPECIES_ODDISH },
    { 36, 36, SPECIES_GLOOM },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_MEOWTH },
    { 38, 38, SPECIES_GLOOM },
    { 31, 31, SPECIES_PSYDUCK },
    { 37, 37, SPECIES_GOLDUCK },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_GOLDUCK },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_FireRed_LandMonsInfo = { 21, sTwoIslandCapeBrink_FireRed_LandMons };

const struct WildPokemon sTwoIslandCapeBrink_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_PSYDUCK },
    { 20, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_GOLDUCK },
    { 35, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_FireRed_WaterMonsInfo = { 2, sTwoIslandCapeBrink_FireRed_WaterMons };

const struct WildPokemon sTwoIslandCapeBrink_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_FireRed_FishingMonsInfo = { 20, sTwoIslandCapeBrink_FireRed_FishingMons };

const struct WildPokemon sThreeIslandBondBridge_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_PIDGEY },
    { 31, 31, SPECIES_ODDISH },
    { 29, 29, SPECIES_PIDGEY },
    { 36, 36, SPECIES_GLOOM },
    { 34, 34, SPECIES_PIDGEOTTO },
    { 31, 31, SPECIES_MEOWTH },
    { 34, 34, SPECIES_VENONAT },
    { 31, 31, SPECIES_PSYDUCK },
    { 37, 37, SPECIES_PIDGEOTTO },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_PIDGEOTTO },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sThreeIslandBondBridge_FireRed_LandMonsInfo = { 21, sThreeIslandBondBridge_FireRed_LandMons };

const struct WildPokemon sThreeIslandBondBridge_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sThreeIslandBondBridge_FireRed_WaterMonsInfo = { 2, sThreeIslandBondBridge_FireRed_WaterMons };

const struct WildPokemon sThreeIslandBondBridge_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sThreeIslandBondBridge_FireRed_FishingMonsInfo = { 20, sThreeIslandBondBridge_FireRed_FishingMons };

const struct WildPokemon sThreeIslandPort_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_DUNSPARCE },
    { 15, 15, SPECIES_DUNSPARCE },
    { 10, 10, SPECIES_DUNSPARCE },
    { 10, 10, SPECIES_DUNSPARCE },
    { 20, 20, SPECIES_DUNSPARCE },
    { 20, 20, SPECIES_DUNSPARCE },
    { 25, 25, SPECIES_DUNSPARCE },
    { 30, 30, SPECIES_DUNSPARCE },
    { 25, 25, SPECIES_DUNSPARCE },
    { 30, 30, SPECIES_DUNSPARCE },
    { 5, 5, SPECIES_DUNSPARCE },
    { 35, 35, SPECIES_DUNSPARCE },
};

const struct WildPokemonInfo sThreeIslandPort_FireRed_LandMonsInfo = { 1, sThreeIslandPort_FireRed_LandMons };

const struct WildPokemon sFiveIslandResortGorgeous_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandResortGorgeous_FireRed_WaterMonsInfo = { 2, sFiveIslandResortGorgeous_FireRed_WaterMons };

const struct WildPokemon sFiveIslandResortGorgeous_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIslandResortGorgeous_FireRed_FishingMonsInfo = { 20, sFiveIslandResortGorgeous_FireRed_FishingMons };

const struct WildPokemon sFiveIslandWaterLabyrinth_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandWaterLabyrinth_FireRed_WaterMonsInfo = { 2, sFiveIslandWaterLabyrinth_FireRed_WaterMons };

const struct WildPokemon sFiveIslandWaterLabyrinth_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIslandWaterLabyrinth_FireRed_FishingMonsInfo = { 20, sFiveIslandWaterLabyrinth_FireRed_FishingMons };

const struct WildPokemon sFiveIslandMeadow_FireRed_LandMons[] =
{
    { 44, 44, SPECIES_PIDGEY },
    { 10, 10, SPECIES_SENTRET },
    { 48, 48, SPECIES_PIDGEOTTO },
    { 10, 10, SPECIES_HOPPIP },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 15, 15, SPECIES_HOPPIP },
    { 41, 41, SPECIES_PSYDUCK },
    { 50, 50, SPECIES_PIDGEOTTO },
    { 47, 47, SPECIES_PERSIAN },
    { 50, 50, SPECIES_PIDGEOTTO },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sFiveIslandMeadow_FireRed_LandMonsInfo = { 21, sFiveIslandMeadow_FireRed_LandMons };

const struct WildPokemon sFiveIslandMeadow_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandMeadow_FireRed_WaterMonsInfo = { 2, sFiveIslandMeadow_FireRed_WaterMons };

const struct WildPokemon sFiveIslandMeadow_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIslandMeadow_FireRed_FishingMonsInfo = { 20, sFiveIslandMeadow_FireRed_FishingMons };

const struct WildPokemon sFiveIslandMemorialPillar_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_HOPPIP },
    { 12, 12, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
    { 10, 10, SPECIES_HOPPIP },
    { 12, 12, SPECIES_HOPPIP },
    { 16, 16, SPECIES_HOPPIP },
    { 6, 6, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_FireRed_LandMonsInfo = { 21, sFiveIslandMemorialPillar_FireRed_LandMons };

const struct WildPokemon sFiveIslandMemorialPillar_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_FireRed_WaterMonsInfo = { 2, sFiveIslandMemorialPillar_FireRed_WaterMons };

const struct WildPokemon sFiveIslandMemorialPillar_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_FireRed_FishingMonsInfo = { 20, sFiveIslandMemorialPillar_FireRed_FishingMons };

const struct WildPokemon sSixIslandOutcastIsland_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandOutcastIsland_FireRed_WaterMonsInfo = { 2, sSixIslandOutcastIsland_FireRed_WaterMons };

const struct WildPokemon sSixIslandOutcastIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSixIslandOutcastIsland_FireRed_FishingMonsInfo = { 20, sSixIslandOutcastIsland_FireRed_FishingMons };

const struct WildPokemon sSixIslandGreenPath_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandGreenPath_FireRed_WaterMonsInfo = { 2, sSixIslandGreenPath_FireRed_WaterMons };

const struct WildPokemon sSixIslandGreenPath_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSixIslandGreenPath_FireRed_FishingMonsInfo = { 20, sSixIslandGreenPath_FireRed_FishingMons };

const struct WildPokemon sSixIslandWaterPath_FireRed_LandMons[] =
{
    { 44, 44, SPECIES_SPEAROW },
    { 10, 10, SPECIES_SENTRET },
    { 44, 44, SPECIES_ODDISH },
    { 48, 48, SPECIES_FEAROW },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 48, 48, SPECIES_GLOOM },
    { 41, 41, SPECIES_PSYDUCK },
    { 50, 50, SPECIES_FEAROW },
    { 47, 47, SPECIES_PERSIAN },
    { 5, 5, SPECIES_MUDKIP },
    { 5, 5, SPECIES_TOTODILE },
};

const struct WildPokemonInfo sSixIslandWaterPath_FireRed_LandMonsInfo = { 21, sSixIslandWaterPath_FireRed_LandMons };

const struct WildPokemon sSixIslandWaterPath_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandWaterPath_FireRed_WaterMonsInfo = { 2, sSixIslandWaterPath_FireRed_WaterMons };

const struct WildPokemon sSixIslandWaterPath_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSixIslandWaterPath_FireRed_FishingMonsInfo = { 20, sSixIslandWaterPath_FireRed_FishingMons };

const struct WildPokemon sSixIslandRuinValley_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_NATU },
    { 44, 44, SPECIES_SPEAROW },
    { 18, 18, SPECIES_YANMA },
    { 15, 15, SPECIES_WOOPER },
    { 49, 49, SPECIES_FEAROW },
    { 43, 43, SPECIES_MEOWTH },
    { 25, 25, SPECIES_WOBBUFFET },
    { 41, 41, SPECIES_PSYDUCK },
    { 20, 20, SPECIES_NATU },
    { 49, 49, SPECIES_PERSIAN },
    { 5, 5, SPECIES_TORCHIC },
    { 5, 5, SPECIES_CYNDAQUIL },
};

const struct WildPokemonInfo sSixIslandRuinValley_FireRed_LandMonsInfo = { 21, sSixIslandRuinValley_FireRed_LandMons };

const struct WildPokemon sSixIslandRuinValley_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_WOOPER },
    { 10, 20, SPECIES_WOOPER },
    { 15, 25, SPECIES_WOOPER },
    { 20, 25, SPECIES_WOOPER },
    { 20, 25, SPECIES_WOOPER },
};

const struct WildPokemonInfo sSixIslandRuinValley_FireRed_WaterMonsInfo = { 2, sSixIslandRuinValley_FireRed_WaterMons };

const struct WildPokemon sSixIslandRuinValley_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSixIslandRuinValley_FireRed_FishingMonsInfo = { 20, sSixIslandRuinValley_FireRed_FishingMons };

const struct WildPokemon sSevenIslandTrainerTower_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSevenIslandTrainerTower_FireRed_WaterMonsInfo = { 2, sSevenIslandTrainerTower_FireRed_WaterMons };

const struct WildPokemon sSevenIslandTrainerTower_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSevenIslandTrainerTower_FireRed_FishingMonsInfo = { 20, sSevenIslandTrainerTower_FireRed_FishingMons };

const struct WildPokemon sSevenIslandSevaultCanyonEntrance_FireRed_LandMons[] =
{
    { 44, 44, SPECIES_SPEAROW },
    { 10, 10, SPECIES_SENTRET },
    { 10, 10, SPECIES_PHANPY },
    { 48, 48, SPECIES_FEAROW },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 50, 50, SPECIES_FEAROW },
    { 41, 41, SPECIES_PSYDUCK },
    { 15, 15, SPECIES_PHANPY },
    { 47, 47, SPECIES_PERSIAN },
    { 15, 15, SPECIES_PHANPY },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyonEntrance_FireRed_LandMonsInfo = { 21, sSevenIslandSevaultCanyonEntrance_FireRed_LandMons };

const struct WildPokemon sSevenIslandSevaultCanyon_FireRed_LandMons[] =
{
    { 46, 46, SPECIES_GEODUDE },
    { 15, 15, SPECIES_PHANPY },
    { 46, 46, SPECIES_CUBONE },
    { 50, 50, SPECIES_FEAROW },
    { 52, 52, SPECIES_MAROWAK },
    { 43, 43, SPECIES_MEOWTH },
    { 54, 54, SPECIES_ONIX },
    { 30, 30, SPECIES_SKARMORY },
    { 15, 15, SPECIES_LARVITAR },
    { 49, 49, SPECIES_PERSIAN },
    { 20, 20, SPECIES_LARVITAR },
    { 52, 52, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyon_FireRed_LandMonsInfo = { 21, sSevenIslandSevaultCanyon_FireRed_LandMons };

const struct WildPokemon sSevenIslandSevaultCanyon_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyon_FireRed_RockSmashMonsInfo = { 25, sSevenIslandSevaultCanyon_FireRed_RockSmashMons };

const struct WildPokemon sSevenIslandTanobyRuins_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSevenIslandTanobyRuins_FireRed_WaterMonsInfo = { 2, sSevenIslandTanobyRuins_FireRed_WaterMons };

const struct WildPokemon sSevenIslandTanobyRuins_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSevenIslandTanobyRuins_FireRed_FishingMonsInfo = { 20, sSevenIslandTanobyRuins_FireRed_FishingMons };

const struct WildPokemon sRoute1_FireRed_LandMons[] =
{
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 2, 2, SPECIES_PIDGEY },
    { 2, 2, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 4, 4, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
    { 5, 5, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
};

const struct WildPokemonInfo sRoute1_FireRed_LandMonsInfo = { 21, sRoute1_FireRed_LandMons };

const struct WildPokemon sRoute2_FireRed_LandMons[] =
{
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
    { 4, 4, SPECIES_PIDGEY },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_PIDGEY },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_PIDGEY },
    { 4, 4, SPECIES_CATERPIE },
    { 4, 4, SPECIES_WEEDLE },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_WEEDLE },
};

const struct WildPokemonInfo sRoute2_FireRed_LandMonsInfo = { 21, sRoute2_FireRed_LandMons };

const struct WildPokemon sRoute3_FireRed_LandMons[] =
{
    { 6, 6, SPECIES_SPEAROW },
    { 6, 6, SPECIES_PIDGEY },
    { 7, 7, SPECIES_SPEAROW },
    { 7, 7, SPECIES_MANKEY },
    { 6, 6, SPECIES_NIDORAN_M },
    { 7, 7, SPECIES_PIDGEY },
    { 8, 8, SPECIES_SPEAROW },
    { 3, 3, SPECIES_JIGGLYPUFF },
    { 7, 7, SPECIES_NIDORAN_M },
    { 5, 5, SPECIES_JIGGLYPUFF },
    { 6, 6, SPECIES_NIDORAN_F },
    { 7, 7, SPECIES_JIGGLYPUFF },
};

const struct WildPokemonInfo sRoute3_FireRed_LandMonsInfo = { 21, sRoute3_FireRed_LandMons };

const struct WildPokemon sRoute4_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_SPEAROW },
    { 10, 10, SPECIES_RATTATA },
    { 6, 6, SPECIES_EKANS },
    { 10, 10, SPECIES_EKANS },
    { 8, 8, SPECIES_SPEAROW },
    { 8, 8, SPECIES_RATTATA },
    { 12, 12, SPECIES_SPEAROW },
    { 12, 12, SPECIES_RATTATA },
    { 10, 10, SPECIES_MANKEY },
    { 8, 8, SPECIES_EKANS },
    { 12, 12, SPECIES_MANKEY },
    { 12, 12, SPECIES_EKANS },
};

const struct WildPokemonInfo sRoute4_FireRed_LandMonsInfo = { 21, sRoute4_FireRed_LandMons };

const struct WildPokemon sRoute4_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute4_FireRed_WaterMonsInfo = { 2, sRoute4_FireRed_WaterMons };

const struct WildPokemon sRoute4_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute4_FireRed_FishingMonsInfo = { 20, sRoute4_FireRed_FishingMons };

const struct WildPokemon sRoute5_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_MEOWTH },
    { 13, 13, SPECIES_PIDGEY },
    { 13, 13, SPECIES_ODDISH },
    { 12, 12, SPECIES_MEOWTH },
    { 15, 15, SPECIES_ODDISH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_ODDISH },
    { 16, 16, SPECIES_PIDGEY },
    { 15, 15, SPECIES_PIDGEY },
    { 14, 14, SPECIES_MEOWTH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute5_FireRed_LandMonsInfo = { 21, sRoute5_FireRed_LandMons };

const struct WildPokemon sRoute6_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_MEOWTH },
    { 13, 13, SPECIES_PIDGEY },
    { 13, 13, SPECIES_ODDISH },
    { 12, 12, SPECIES_MEOWTH },
    { 15, 15, SPECIES_ODDISH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_ODDISH },
    { 16, 16, SPECIES_PIDGEY },
    { 15, 15, SPECIES_PIDGEY },
    { 14, 14, SPECIES_MEOWTH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute6_FireRed_LandMonsInfo = { 21, sRoute6_FireRed_LandMons };

const struct WildPokemon sRoute6_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute6_FireRed_WaterMonsInfo = { 2, sRoute6_FireRed_WaterMons };

const struct WildPokemon sRoute6_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute6_FireRed_FishingMonsInfo = { 20, sRoute6_FireRed_FishingMons };

const struct WildPokemon sRoute7_FireRed_LandMons[] =
{
    { 19, 19, SPECIES_PIDGEY },
    { 17, 17, SPECIES_MEOWTH },
    { 19, 19, SPECIES_ODDISH },
    { 18, 18, SPECIES_MEOWTH },
    { 22, 22, SPECIES_PIDGEY },
    { 22, 22, SPECIES_ODDISH },
    { 18, 18, SPECIES_GROWLITHE },
    { 20, 20, SPECIES_GROWLITHE },
    { 17, 17, SPECIES_MEOWTH },
    { 19, 19, SPECIES_MEOWTH },
    { 17, 17, SPECIES_MEOWTH },
    { 20, 20, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute7_FireRed_LandMonsInfo = { 21, sRoute7_FireRed_LandMons };

const struct WildPokemon sRoute8_FireRed_LandMons[] =
{
    { 18, 18, SPECIES_PIDGEY },
    { 18, 18, SPECIES_MEOWTH },
    { 16, 16, SPECIES_GROWLITHE },
    { 20, 20, SPECIES_PIDGEY },
    { 20, 20, SPECIES_MEOWTH },
    { 17, 17, SPECIES_EKANS },
    { 17, 17, SPECIES_GROWLITHE },
    { 19, 19, SPECIES_EKANS },
    { 17, 17, SPECIES_EKANS },
    { 15, 15, SPECIES_GROWLITHE },
    { 17, 17, SPECIES_EKANS },
    { 18, 18, SPECIES_GROWLITHE },
};

const struct WildPokemonInfo sRoute8_FireRed_LandMonsInfo = { 21, sRoute8_FireRed_LandMons };

const struct WildPokemon sRoute9_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_SPEAROW },
    { 16, 16, SPECIES_RATTATA },
    { 11, 11, SPECIES_EKANS },
    { 15, 15, SPECIES_EKANS },
    { 13, 13, SPECIES_SPEAROW },
    { 14, 14, SPECIES_RATTATA },
    { 17, 17, SPECIES_SPEAROW },
    { 17, 17, SPECIES_RATTATA },
    { 14, 14, SPECIES_RATTATA },
    { 13, 13, SPECIES_EKANS },
    { 14, 14, SPECIES_RATTATA },
    { 17, 17, SPECIES_EKANS },
};

const struct WildPokemonInfo sRoute9_FireRed_LandMonsInfo = { 21, sRoute9_FireRed_LandMons };

const struct WildPokemon sRoute10_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_SPEAROW },
    { 16, 16, SPECIES_VOLTORB },
    { 11, 11, SPECIES_EKANS },
    { 15, 15, SPECIES_EKANS },
    { 13, 13, SPECIES_SPEAROW },
    { 14, 14, SPECIES_VOLTORB },
    { 17, 17, SPECIES_SPEAROW },
    { 17, 17, SPECIES_VOLTORB },
    { 14, 14, SPECIES_VOLTORB },
    { 13, 13, SPECIES_EKANS },
    { 14, 14, SPECIES_VOLTORB },
    { 17, 17, SPECIES_EKANS },
};

const struct WildPokemonInfo sRoute10_FireRed_LandMonsInfo = { 21, sRoute10_FireRed_LandMons };

const struct WildPokemon sRoute10_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute10_FireRed_WaterMonsInfo = { 2, sRoute10_FireRed_WaterMons };

const struct WildPokemon sRoute10_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute10_FireRed_FishingMonsInfo = { 20, sRoute10_FireRed_FishingMons };

const struct WildPokemon sRoute11_FireRed_LandMons[] =
{
    { 14, 14, SPECIES_EKANS },
    { 15, 15, SPECIES_SPEAROW },
    { 12, 12, SPECIES_EKANS },
    { 13, 13, SPECIES_SPEAROW },
    { 11, 11, SPECIES_DROWZEE },
    { 13, 13, SPECIES_DROWZEE },
    { 15, 15, SPECIES_EKANS },
    { 17, 17, SPECIES_SPEAROW },
    { 12, 12, SPECIES_EKANS },
    { 15, 15, SPECIES_DROWZEE },
    { 12, 12, SPECIES_EKANS },
    { 15, 15, SPECIES_DROWZEE },
};

const struct WildPokemonInfo sRoute11_FireRed_LandMonsInfo = { 21, sRoute11_FireRed_LandMons };

const struct WildPokemon sRoute11_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute11_FireRed_WaterMonsInfo = { 2, sRoute11_FireRed_WaterMons };

const struct WildPokemon sRoute11_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute11_FireRed_FishingMonsInfo = { 20, sRoute11_FireRed_FishingMons };

const struct WildPokemon sRoute12_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_ODDISH },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_ODDISH },
    { 23, 23, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_ODDISH },
    { 27, 27, SPECIES_PIDGEY },
    { 23, 23, SPECIES_PIDGEY },
    { 28, 28, SPECIES_GLOOM },
    { 23, 23, SPECIES_PIDGEY },
    { 30, 30, SPECIES_GLOOM },
};

const struct WildPokemonInfo sRoute12_FireRed_LandMonsInfo = { 21, sRoute12_FireRed_LandMons };

const struct WildPokemon sRoute12_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute12_FireRed_WaterMonsInfo = { 2, sRoute12_FireRed_WaterMons };

const struct WildPokemon sRoute12_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute12_FireRed_FishingMonsInfo = { 60, sRoute12_FireRed_FishingMons };

const struct WildPokemon sRoute13_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_ODDISH },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_ODDISH },
    { 27, 27, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_ODDISH },
    { 25, 25, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 28, 28, SPECIES_GLOOM },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 30, 30, SPECIES_GLOOM },
};

const struct WildPokemonInfo sRoute13_FireRed_LandMonsInfo = { 21, sRoute13_FireRed_LandMons };

const struct WildPokemon sRoute13_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute13_FireRed_WaterMonsInfo = { 2, sRoute13_FireRed_WaterMons };

const struct WildPokemon sRoute13_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute13_FireRed_FishingMonsInfo = { 20, sRoute13_FireRed_FishingMons };

const struct WildPokemon sRoute14_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_ODDISH },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_ODDISH },
    { 23, 23, SPECIES_DITTO },
    { 27, 27, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_ODDISH },
    { 30, 30, SPECIES_GLOOM },
    { 23, 23, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 23, 23, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
};

const struct WildPokemonInfo sRoute14_FireRed_LandMonsInfo = { 21, sRoute14_FireRed_LandMons };

const struct WildPokemon sRoute15_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_ODDISH },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_ODDISH },
    { 27, 27, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_ODDISH },
    { 25, 25, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 28, 28, SPECIES_GLOOM },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 30, 30, SPECIES_GLOOM },
};

const struct WildPokemonInfo sRoute15_FireRed_LandMonsInfo = { 21, sRoute15_FireRed_LandMons };

const struct WildPokemon sRoute16_FireRed_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 18, 18, SPECIES_DODUO },
    { 18, 18, SPECIES_RATTATA },
    { 20, 20, SPECIES_RATTATA },
    { 22, 22, SPECIES_SPEAROW },
    { 20, 20, SPECIES_DODUO },
    { 22, 22, SPECIES_RATTATA },
    { 22, 22, SPECIES_DODUO },
    { 18, 18, SPECIES_RATTATA },
    { 23, 23, SPECIES_RATICATE },
    { 18, 18, SPECIES_RATTATA },
    { 25, 25, SPECIES_RATICATE },
};

const struct WildPokemonInfo sRoute16_FireRed_LandMonsInfo = { 21, sRoute16_FireRed_LandMons };

const struct WildPokemon sRoute17_FireRed_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 24, 24, SPECIES_DODUO },
    { 22, 22, SPECIES_SPEAROW },
    { 26, 26, SPECIES_DODUO },
    { 25, 25, SPECIES_RATICATE },
    { 27, 27, SPECIES_RATICATE },
    { 28, 28, SPECIES_DODUO },
    { 29, 29, SPECIES_RATICATE },
    { 22, 22, SPECIES_RATTATA },
    { 25, 25, SPECIES_FEAROW },
    { 22, 22, SPECIES_RATTATA },
    { 27, 27, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute17_FireRed_LandMonsInfo = { 21, sRoute17_FireRed_LandMons };

const struct WildPokemon sRoute18_FireRed_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 24, 24, SPECIES_DODUO },
    { 22, 22, SPECIES_SPEAROW },
    { 26, 26, SPECIES_DODUO },
    { 25, 25, SPECIES_RATICATE },
    { 25, 25, SPECIES_FEAROW },
    { 28, 28, SPECIES_DODUO },
    { 29, 29, SPECIES_RATICATE },
    { 22, 22, SPECIES_RATTATA },
    { 27, 27, SPECIES_FEAROW },
    { 22, 22, SPECIES_RATTATA },
    { 29, 29, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute18_FireRed_LandMonsInfo = { 21, sRoute18_FireRed_LandMons };

const struct WildPokemon sRoute19_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute19_FireRed_WaterMonsInfo = { 2, sRoute19_FireRed_WaterMons };

const struct WildPokemon sRoute19_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute19_FireRed_FishingMonsInfo = { 20, sRoute19_FireRed_FishingMons };

const struct WildPokemon sRoute20_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute20_FireRed_WaterMonsInfo = { 2, sRoute20_FireRed_WaterMons };

const struct WildPokemon sRoute20_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute20_FireRed_FishingMonsInfo = { 20, sRoute20_FireRed_FishingMons };

const struct WildPokemon sRoute21North_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_TANGELA },
    { 23, 23, SPECIES_TANGELA },
    { 24, 24, SPECIES_TANGELA },
    { 21, 21, SPECIES_TANGELA },
    { 25, 25, SPECIES_TANGELA },
    { 20, 20, SPECIES_TANGELA },
    { 19, 19, SPECIES_TANGELA },
    { 26, 26, SPECIES_TANGELA },
    { 18, 18, SPECIES_TANGELA },
    { 27, 27, SPECIES_TANGELA },
    { 17, 17, SPECIES_TANGELA },
    { 28, 28, SPECIES_TANGELA },
};

const struct WildPokemonInfo sRoute21North_FireRed_LandMonsInfo = { 14, sRoute21North_FireRed_LandMons };

const struct WildPokemon sRoute21North_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute21North_FireRed_WaterMonsInfo = { 2, sRoute21North_FireRed_WaterMons };

const struct WildPokemon sRoute21North_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute21North_FireRed_FishingMonsInfo = { 20, sRoute21North_FireRed_FishingMons };

const struct WildPokemon sRoute21South_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_TANGELA },
    { 23, 23, SPECIES_TANGELA },
    { 24, 24, SPECIES_TANGELA },
    { 21, 21, SPECIES_TANGELA },
    { 25, 25, SPECIES_TANGELA },
    { 20, 20, SPECIES_TANGELA },
    { 19, 19, SPECIES_TANGELA },
    { 26, 26, SPECIES_TANGELA },
    { 18, 18, SPECIES_TANGELA },
    { 27, 27, SPECIES_TANGELA },
    { 17, 17, SPECIES_TANGELA },
    { 28, 28, SPECIES_TANGELA },
};

const struct WildPokemonInfo sRoute21South_FireRed_LandMonsInfo = { 14, sRoute21South_FireRed_LandMons };

const struct WildPokemon sRoute21South_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute21South_FireRed_WaterMonsInfo = { 2, sRoute21South_FireRed_WaterMons };

const struct WildPokemon sRoute21South_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute21South_FireRed_FishingMonsInfo = { 20, sRoute21South_FireRed_FishingMons };

const struct WildPokemon sRoute22_FireRed_LandMons[] =
{
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_MANKEY },
    { 4, 4, SPECIES_RATTATA },
    { 4, 4, SPECIES_MANKEY },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_MANKEY },
    { 3, 3, SPECIES_SPEAROW },
    { 5, 5, SPECIES_SPEAROW },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_MANKEY },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_MANKEY },
};

const struct WildPokemonInfo sRoute22_FireRed_LandMonsInfo = { 21, sRoute22_FireRed_LandMons };

const struct WildPokemon sRoute22_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute22_FireRed_WaterMonsInfo = { 2, sRoute22_FireRed_WaterMons };

const struct WildPokemon sRoute22_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute22_FireRed_FishingMonsInfo = { 20, sRoute22_FireRed_FishingMons };

const struct WildPokemon sRoute23_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_MANKEY },
    { 40, 40, SPECIES_FEAROW },
    { 34, 34, SPECIES_MANKEY },
    { 34, 34, SPECIES_SPEAROW },
    { 32, 32, SPECIES_EKANS },
    { 34, 34, SPECIES_EKANS },
    { 42, 42, SPECIES_PRIMEAPE },
    { 44, 44, SPECIES_ARBOK },
    { 32, 32, SPECIES_SPEAROW },
    { 42, 42, SPECIES_FEAROW },
    { 32, 32, SPECIES_SPEAROW },
    { 44, 44, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute23_FireRed_LandMonsInfo = { 21, sRoute23_FireRed_LandMons };

const struct WildPokemon sRoute23_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute23_FireRed_WaterMonsInfo = { 2, sRoute23_FireRed_WaterMons };

const struct WildPokemon sRoute23_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute23_FireRed_FishingMonsInfo = { 20, sRoute23_FireRed_FishingMons };

const struct WildPokemon sRoute24_FireRed_LandMons[] =
{
    { 7, 7, SPECIES_WEEDLE },
    { 7, 7, SPECIES_CATERPIE },
    { 11, 11, SPECIES_PIDGEY },
    { 12, 12, SPECIES_ODDISH },
    { 13, 13, SPECIES_ODDISH },
    { 10, 10, SPECIES_ABRA },
    { 13, 13, SPECIES_PIDGEY },
    { 14, 14, SPECIES_ODDISH },
    { 8, 8, SPECIES_KAKUNA },
    { 8, 8, SPECIES_ABRA },
    { 8, 8, SPECIES_SQUIRTLE },
    { 12, 12, SPECIES_ABRA },
};

const struct WildPokemonInfo sRoute24_FireRed_LandMonsInfo = { 21, sRoute24_FireRed_LandMons };

const struct WildPokemon sRoute24_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute24_FireRed_WaterMonsInfo = { 2, sRoute24_FireRed_WaterMons };

const struct WildPokemon sRoute24_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute24_FireRed_FishingMonsInfo = { 20, sRoute24_FireRed_FishingMons };

const struct WildPokemon sRoute25_FireRed_LandMons[] =
{
    { 8, 8, SPECIES_WEEDLE },
    { 8, 8, SPECIES_CATERPIE },
    { 13, 13, SPECIES_PIDGEY },
    { 14, 14, SPECIES_ODDISH },
    { 13, 13, SPECIES_ODDISH },
    { 11, 11, SPECIES_ABRA },
    { 11, 11, SPECIES_PIDGEY },
    { 12, 12, SPECIES_ODDISH },
    { 9, 9, SPECIES_KAKUNA },
    { 9, 9, SPECIES_ABRA },
    { 9, 9, SPECIES_METAPOD },
    { 13, 13, SPECIES_ABRA },
};

const struct WildPokemonInfo sRoute25_FireRed_LandMonsInfo = { 21, sRoute25_FireRed_LandMons };

const struct WildPokemon sRoute25_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute25_FireRed_WaterMonsInfo = { 2, sRoute25_FireRed_WaterMons };

const struct WildPokemon sRoute25_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute25_FireRed_FishingMonsInfo = { 20, sRoute25_FireRed_FishingMons };

const struct WildPokemon sPalletTown_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sPalletTown_FireRed_WaterMonsInfo = { 1, sPalletTown_FireRed_WaterMons };

const struct WildPokemon sPalletTown_FireRed_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sPalletTown_FireRed_FishingMonsInfo = { 10, sPalletTown_FireRed_FishingMons };

const struct WildPokemon sViridianCity_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sViridianCity_FireRed_WaterMonsInfo = { 1, sViridianCity_FireRed_WaterMons };

const struct WildPokemon sViridianCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sViridianCity_FireRed_FishingMonsInfo = { 10, sViridianCity_FireRed_FishingMons };

const struct WildPokemon sCeruleanCity_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sCeruleanCity_FireRed_WaterMonsInfo = { 1, sCeruleanCity_FireRed_WaterMons };

const struct WildPokemon sCeruleanCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCeruleanCity_FireRed_FishingMonsInfo = { 10, sCeruleanCity_FireRed_FishingMons };

const struct WildPokemon sVermilionCity_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sVermilionCity_FireRed_WaterMonsInfo = { 1, sVermilionCity_FireRed_WaterMons };

const struct WildPokemon sVermilionCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sVermilionCity_FireRed_FishingMonsInfo = { 10, sVermilionCity_FireRed_FishingMons };

const struct WildPokemon sCeladonCity_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_PSYDUCK },
    { 10, 20, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 40, SPECIES_PSYDUCK },
    { 30, 40, SPECIES_KOFFING },
};

const struct WildPokemonInfo sCeladonCity_FireRed_WaterMonsInfo = { 1, sCeladonCity_FireRed_WaterMons };

const struct WildPokemon sCeladonCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 25, 35, SPECIES_MAGIKARP },
    { 30, 40, SPECIES_GRIMER },
};

const struct WildPokemonInfo sCeladonCity_FireRed_FishingMonsInfo = { 10, sCeladonCity_FireRed_FishingMons };

const struct WildPokemon sFuchsiaCity_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFuchsiaCity_FireRed_WaterMonsInfo = { 1, sFuchsiaCity_FireRed_WaterMons };

const struct WildPokemon sFuchsiaCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFuchsiaCity_FireRed_FishingMonsInfo = { 10, sFuchsiaCity_FireRed_FishingMons };

const struct WildPokemon sCinnabarIsland_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sCinnabarIsland_FireRed_WaterMonsInfo = { 1, sCinnabarIsland_FireRed_WaterMons };

const struct WildPokemon sCinnabarIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCinnabarIsland_FireRed_FishingMonsInfo = { 10, sCinnabarIsland_FireRed_FishingMons };

const struct WildPokemon sOneIsland_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIsland_FireRed_WaterMonsInfo = { 1, sOneIsland_FireRed_WaterMons };

const struct WildPokemon sOneIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sOneIsland_FireRed_FishingMonsInfo = { 10, sOneIsland_FireRed_FishingMons };

const struct WildPokemon sFourIsland_FireRed_WaterMons[] =
{
    { 5, 15, SPECIES_WOOPER },
    { 5, 35, SPECIES_PSYDUCK },
    { 15, 25, SPECIES_WOOPER },
    { 15, 25, SPECIES_WOOPER },
    { 15, 25, SPECIES_WOOPER },
};

const struct WildPokemonInfo sFourIsland_FireRed_WaterMonsInfo = { 2, sFourIsland_FireRed_WaterMons };

const struct WildPokemon sFourIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFourIsland_FireRed_FishingMonsInfo = { 20, sFourIsland_FireRed_FishingMons };

const struct WildPokemon sFiveIsland_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIsland_FireRed_WaterMonsInfo = { 1, sFiveIsland_FireRed_WaterMons };

const struct WildPokemon sFiveIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIsland_FireRed_FishingMonsInfo = { 10, sFiveIsland_FireRed_FishingMons };

const struct WildPokemon sSixIslandAlteringCave_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 16, 16, SPECIES_ZUBAT },
    { 6, 6, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
};

const struct WildPokemonInfo sSixIslandAlteringCave_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_2_FireRed_LandMons[] =
{
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 13, 13, SPECIES_MAREEP },
    { 3, 3, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
};

const struct WildPokemonInfo sSixIslandAlteringCave_2_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_2_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_3_FireRed_LandMons[] =
{
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 22, 22, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 29, 29, SPECIES_PINECO },
    { 19, 19, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
};

const struct WildPokemonInfo sSixIslandAlteringCave_3_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_3_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_4_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 22, 22, SPECIES_HOUNDOUR },
    { 12, 12, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
};

const struct WildPokemonInfo sSixIslandAlteringCave_4_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_4_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_5_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_TEDDIURSA },
    { 24, 24, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
    { 22, 22, SPECIES_TEDDIURSA },
    { 24, 24, SPECIES_TEDDIURSA },
    { 28, 28, SPECIES_TEDDIURSA },
    { 18, 18, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
};

const struct WildPokemonInfo sSixIslandAlteringCave_5_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_5_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_6_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 28, 28, SPECIES_AIPOM },
    { 18, 18, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
};

const struct WildPokemonInfo sSixIslandAlteringCave_6_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_6_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_7_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 28, 28, SPECIES_SHUCKLE },
    { 18, 18, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo sSixIslandAlteringCave_7_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_7_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_8_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 28, 28, SPECIES_STANTLER },
    { 18, 18, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
};

const struct WildPokemonInfo sSixIslandAlteringCave_8_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_8_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_9_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 28, 28, SPECIES_SMEARGLE },
    { 18, 18, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo sSixIslandAlteringCave_9_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_9_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsMoneanChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsMoneanChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsMoneanChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsLiptooChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsLiptooChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsLiptooChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsWeepthChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsWeepthChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsWeepthChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsDilfordChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsDilfordChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsDilfordChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsScufibChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsScufibChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsScufibChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsRixyChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsRixyChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsRixyChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsViapoisChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsViapoisChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsViapoisChamber_LeafGreen_LandMons };

const struct WildPokemon sViridianForest_LeafGreen_LandMons[] =
{
    { 4, 4, SPECIES_CATERPIE },
    { 4, 4, SPECIES_WEEDLE },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_WEEDLE },
    { 3, 3, SPECIES_CATERPIE },
    { 3, 3, SPECIES_WEEDLE },
    { 5, 5, SPECIES_KAKUNA },
    { 5, 5, SPECIES_METAPOD },
    { 4, 4, SPECIES_METAPOD },
    { 3, 3, SPECIES_PIKACHU },
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_PIKACHU },
};

const struct WildPokemonInfo sViridianForest_LeafGreen_LandMonsInfo = { 14, sViridianForest_LeafGreen_LandMons };

const struct WildPokemon sMtMoon1F_LeafGreen_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 7, 7, SPECIES_GEODUDE },
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 8, 8, SPECIES_GEODUDE },
    { 9, 9, SPECIES_GEODUDE },
    { 8, 8, SPECIES_PARAS },
    { 7, 7, SPECIES_ZUBAT },
    { 7, 7, SPECIES_ZUBAT },
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_CLEFAIRY },
};

const struct WildPokemonInfo sMtMoon1F_LeafGreen_LandMonsInfo = { 7, sMtMoon1F_LeafGreen_LandMons };

const struct WildPokemon sMtMoonB1F_LeafGreen_LandMons[] =
{
    { 7, 7, SPECIES_PARAS },
    { 8, 8, SPECIES_PARAS },
    { 5, 5, SPECIES_PARAS },
    { 6, 6, SPECIES_PARAS },
    { 9, 9, SPECIES_PARAS },
    { 10, 10, SPECIES_PARAS },
    { 7, 7, SPECIES_PARAS },
    { 8, 8, SPECIES_PARAS },
    { 5, 5, SPECIES_PARAS },
    { 6, 6, SPECIES_PARAS },
    { 9, 9, SPECIES_PARAS },
    { 10, 10, SPECIES_PARAS },
};

const struct WildPokemonInfo sMtMoonB1F_LeafGreen_LandMonsInfo = { 5, sMtMoonB1F_LeafGreen_LandMons };

const struct WildPokemon sMtMoonB2F_LeafGreen_LandMons[] =
{
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_GEODUDE },
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 10, 10, SPECIES_GEODUDE },
    { 10, 10, SPECIES_PARAS },
    { 12, 12, SPECIES_PARAS },
    { 10, 10, SPECIES_CLEFAIRY },
    { 11, 11, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ZUBAT },
    { 12, 12, SPECIES_CLEFAIRY },
};

const struct WildPokemonInfo sMtMoonB2F_LeafGreen_LandMonsInfo = { 7, sMtMoonB2F_LeafGreen_LandMons };

const struct WildPokemon sSSAnneExterior_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sSSAnneExterior_LeafGreen_WaterMonsInfo = { 1, sSSAnneExterior_LeafGreen_WaterMons };

const struct WildPokemon sSSAnneExterior_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSSAnneExterior_LeafGreen_FishingMonsInfo = { 10, sSSAnneExterior_LeafGreen_FishingMons };

const struct WildPokemon sDiglettsCaveB1F_LeafGreen_LandMons[] =
{
    { 18, 18, SPECIES_DIGLETT },
    { 19, 19, SPECIES_DIGLETT },
    { 17, 17, SPECIES_DIGLETT },
    { 15, 15, SPECIES_DIGLETT },
    { 16, 16, SPECIES_DIGLETT },
    { 20, 20, SPECIES_DIGLETT },
    { 21, 21, SPECIES_DIGLETT },
    { 22, 22, SPECIES_DIGLETT },
    { 17, 17, SPECIES_DIGLETT },
    { 29, 29, SPECIES_DUGTRIO },
    { 17, 17, SPECIES_DIGLETT },
    { 31, 31, SPECIES_DUGTRIO },
};

const struct WildPokemonInfo sDiglettsCaveB1F_LeafGreen_LandMonsInfo = { 5, sDiglettsCaveB1F_LeafGreen_LandMons };

const struct WildPokemon sVictoryRoad1F_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 40, 40, SPECIES_ONIX },
    { 43, 43, SPECIES_ONIX },
    { 46, 46, SPECIES_ONIX },
    { 32, 32, SPECIES_ZUBAT },
    { 44, 44, SPECIES_SANDSLASH },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_MAROWAK },
    { 44, 44, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad1F_LeafGreen_LandMonsInfo = { 7, sVictoryRoad1F_LeafGreen_LandMons };

const struct WildPokemon sVictoryRoad2F_LeafGreen_LandMons[] =
{
    { 34, 34, SPECIES_MACHOP },
    { 34, 34, SPECIES_GEODUDE },
    { 42, 42, SPECIES_PRIMEAPE },
    { 45, 45, SPECIES_ONIX },
    { 48, 48, SPECIES_ONIX },
    { 34, 34, SPECIES_ZUBAT },
    { 46, 46, SPECIES_SANDSLASH },
    { 46, 46, SPECIES_GOLBAT },
    { 46, 46, SPECIES_MAROWAK },
    { 46, 46, SPECIES_MACHOKE },
    { 48, 48, SPECIES_MACHOKE },
    { 48, 48, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad2F_LeafGreen_LandMonsInfo = { 7, sVictoryRoad2F_LeafGreen_LandMons };

const struct WildPokemon sVictoryRoad3F_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 40, 40, SPECIES_ONIX },
    { 43, 43, SPECIES_ONIX },
    { 46, 46, SPECIES_ONIX },
    { 32, 32, SPECIES_ZUBAT },
    { 44, 44, SPECIES_SANDSLASH },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_MAROWAK },
    { 44, 44, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad3F_LeafGreen_LandMonsInfo = { 7, sVictoryRoad3F_LeafGreen_LandMons };

const struct WildPokemon sPokemonMansion1F_LeafGreen_LandMons[] =
{
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_GRIMER },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_VULPIX },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_MUK },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion1F_LeafGreen_LandMonsInfo = { 7, sPokemonMansion1F_LeafGreen_LandMons };

const struct WildPokemon sPokemonMansion2F_LeafGreen_LandMons[] =
{
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_GRIMER },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_VULPIX },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_MUK },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion2F_LeafGreen_LandMonsInfo = { 7, sPokemonMansion2F_LeafGreen_LandMons };

const struct WildPokemon sPokemonMansion3F_LeafGreen_LandMons[] =
{
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_GRIMER },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_VULPIX },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_MUK },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion3F_LeafGreen_LandMonsInfo = { 7, sPokemonMansion3F_LeafGreen_LandMons };

const struct WildPokemon sPokemonMansionB1F_LeafGreen_LandMons[] =
{
    { 28, 28, SPECIES_GRIMER },
    { 34, 34, SPECIES_RATICATE },
    { 30, 30, SPECIES_GRIMER },
    { 30, 30, SPECIES_DITTO },
    { 30, 30, SPECIES_VULPIX },
    { 38, 38, SPECIES_RATICATE },
    { 28, 28, SPECIES_KOFFING },
    { 34, 34, SPECIES_MUK },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansionB1F_LeafGreen_LandMonsInfo = { 5, sPokemonMansionB1F_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneCenter_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_RHYHORN },
    { 22, 22, SPECIES_NIDORAN_F },
    { 24, 24, SPECIES_EXEGGCUTE },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 22, 22, SPECIES_VENONAT },
    { 31, 31, SPECIES_NIDORINA },
    { 31, 31, SPECIES_NIDORINO },
    { 30, 30, SPECIES_PARASECT },
    { 22, 22, SPECIES_VENONAT },
    { 23, 23, SPECIES_PINSIR },
    { 22, 22, SPECIES_VENONAT },
    { 23, 23, SPECIES_CHANSEY },
};

const struct WildPokemonInfo sSafariZoneCenter_LeafGreen_LandMonsInfo = { 21, sSafariZoneCenter_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneCenter_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSafariZoneCenter_LeafGreen_WaterMonsInfo = { 2, sSafariZoneCenter_LeafGreen_WaterMons };

const struct WildPokemon sSafariZoneCenter_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneCenter_LeafGreen_FishingMonsInfo = { 20, sSafariZoneCenter_LeafGreen_FishingMons };

const struct WildPokemon sSafariZoneEast_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_NIDORAN_F },
    { 26, 26, SPECIES_DODUO },
    { 23, 23, SPECIES_EXEGGCUTE },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 22, 22, SPECIES_PARAS },
    { 33, 33, SPECIES_NIDORINA },
    { 24, 24, SPECIES_NIDORAN_M },
    { 25, 25, SPECIES_PARASECT },
    { 22, 22, SPECIES_PARAS },
    { 25, 25, SPECIES_KANGASKHAN },
    { 22, 22, SPECIES_PARAS },
    { 28, 28, SPECIES_PINSIR },
};

const struct WildPokemonInfo sSafariZoneEast_LeafGreen_LandMonsInfo = { 21, sSafariZoneEast_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneEast_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSafariZoneEast_LeafGreen_WaterMonsInfo = { 2, sSafariZoneEast_LeafGreen_WaterMons };

const struct WildPokemon sSafariZoneEast_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneEast_LeafGreen_FishingMonsInfo = { 20, sSafariZoneEast_LeafGreen_FishingMons };

const struct WildPokemon sSafariZoneNorth_LeafGreen_LandMons[] =
{
    { 26, 26, SPECIES_RHYHORN },
    { 30, 30, SPECIES_NIDORAN_F },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 27, 27, SPECIES_EXEGGCUTE },
    { 23, 23, SPECIES_PARAS },
    { 30, 30, SPECIES_NIDORINA },
    { 30, 30, SPECIES_NIDORINO },
    { 32, 32, SPECIES_VENOMOTH },
    { 23, 23, SPECIES_PARAS },
    { 26, 26, SPECIES_CHANSEY },
    { 23, 23, SPECIES_PARAS },
    { 28, 28, SPECIES_TAUROS },
};

const struct WildPokemonInfo sSafariZoneNorth_LeafGreen_LandMonsInfo = { 21, sSafariZoneNorth_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneNorth_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSafariZoneNorth_LeafGreen_WaterMonsInfo = { 2, sSafariZoneNorth_LeafGreen_WaterMons };

const struct WildPokemon sSafariZoneNorth_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneNorth_LeafGreen_FishingMonsInfo = { 20, sSafariZoneNorth_LeafGreen_FishingMons };

const struct WildPokemon sSafariZoneWest_LeafGreen_LandMons[] =
{
    { 26, 26, SPECIES_DODUO },
    { 22, 22, SPECIES_NIDORAN_F },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 27, 27, SPECIES_EXEGGCUTE },
    { 23, 23, SPECIES_VENONAT },
    { 30, 30, SPECIES_NIDORINA },
    { 30, 30, SPECIES_NIDORAN_M },
    { 32, 32, SPECIES_VENOMOTH },
    { 23, 23, SPECIES_VENONAT },
    { 25, 25, SPECIES_TAUROS },
    { 23, 23, SPECIES_VENONAT },
    { 28, 28, SPECIES_KANGASKHAN },
};

const struct WildPokemonInfo sSafariZoneWest_LeafGreen_LandMonsInfo = { 21, sSafariZoneWest_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneWest_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSafariZoneWest_LeafGreen_WaterMonsInfo = { 2, sSafariZoneWest_LeafGreen_WaterMons };

const struct WildPokemon sSafariZoneWest_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneWest_LeafGreen_FishingMonsInfo = { 20, sSafariZoneWest_LeafGreen_FishingMons };

const struct WildPokemon sCeruleanCave1F_LeafGreen_LandMons[] =
{
    { 49, 49, SPECIES_MAGNETON },
    { 49, 49, SPECIES_PARASECT },
    { 46, 46, SPECIES_GOLBAT },
    { 46, 46, SPECIES_MACHOKE },
    { 52, 52, SPECIES_PRIMEAPE },
    { 52, 52, SPECIES_DITTO },
    { 58, 58, SPECIES_ELECTRODE },
    { 58, 58, SPECIES_PARASECT },
    { 55, 55, SPECIES_GOLBAT },
    { 55, 55, SPECIES_WOBBUFFET },
    { 61, 61, SPECIES_PRIMEAPE },
    { 61, 61, SPECIES_DITTO },
};

const struct WildPokemonInfo sCeruleanCave1F_LeafGreen_LandMonsInfo = { 7, sCeruleanCave1F_LeafGreen_LandMons };

const struct WildPokemon sCeruleanCave1F_LeafGreen_WaterMons[] =
{
    { 30, 40, SPECIES_SLOWPOKE },
    { 40, 50, SPECIES_SLOWBRO },
    { 45, 55, SPECIES_SLOWBRO },
    { 40, 50, SPECIES_SLOWPOKE },
    { 40, 50, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCeruleanCave1F_LeafGreen_WaterMonsInfo = { 2, sCeruleanCave1F_LeafGreen_WaterMons };

const struct WildPokemon sCeruleanCave1F_LeafGreen_RockSmashMons[] =
{
    { 30, 40, SPECIES_GEODUDE },
    { 40, 50, SPECIES_GRAVELER },
    { 45, 55, SPECIES_GRAVELER },
    { 40, 50, SPECIES_GEODUDE },
    { 40, 50, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCave1F_LeafGreen_RockSmashMonsInfo = { 50, sCeruleanCave1F_LeafGreen_RockSmashMons };

const struct WildPokemon sCeruleanCave1F_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCeruleanCave1F_LeafGreen_FishingMonsInfo = { 20, sCeruleanCave1F_LeafGreen_FishingMons };

const struct WildPokemon sCeruleanCave2F_LeafGreen_LandMons[] =
{
    { 49, 49, SPECIES_GOLBAT },
    { 49, 49, SPECIES_MACHOKE },
    { 52, 52, SPECIES_MAGNETON },
    { 52, 52, SPECIES_PARASECT },
    { 55, 55, SPECIES_KADABRA },
    { 55, 55, SPECIES_DITTO },
    { 58, 58, SPECIES_GOLBAT },
    { 58, 58, SPECIES_WOBBUFFET },
    { 61, 61, SPECIES_ELECTRODE },
    { 61, 61, SPECIES_PARASECT },
    { 64, 64, SPECIES_KADABRA },
    { 64, 64, SPECIES_DITTO },
};

const struct WildPokemonInfo sCeruleanCave2F_LeafGreen_LandMonsInfo = { 7, sCeruleanCave2F_LeafGreen_LandMons };

const struct WildPokemon sCeruleanCave2F_LeafGreen_RockSmashMons[] =
{
    { 35, 45, SPECIES_GEODUDE },
    { 45, 55, SPECIES_GRAVELER },
    { 50, 60, SPECIES_GRAVELER },
    { 45, 55, SPECIES_GEODUDE },
    { 45, 55, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCave2F_LeafGreen_RockSmashMonsInfo = { 50, sCeruleanCave2F_LeafGreen_RockSmashMons };

const struct WildPokemon sCeruleanCaveB1F_LeafGreen_LandMons[] =
{
    { 58, 58, SPECIES_KADABRA },
    { 58, 58, SPECIES_DITTO },
    { 55, 55, SPECIES_MAGNETON },
    { 55, 55, SPECIES_PARASECT },
    { 52, 52, SPECIES_GOLBAT },
    { 52, 52, SPECIES_MACHOKE },
    { 67, 67, SPECIES_KADABRA },
    { 67, 67, SPECIES_DITTO },
    { 64, 64, SPECIES_ELECTRODE },
    { 64, 64, SPECIES_PARASECT },
    { 61, 61, SPECIES_GOLBAT },
    { 61, 61, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo sCeruleanCaveB1F_LeafGreen_LandMonsInfo = { 7, sCeruleanCaveB1F_LeafGreen_LandMons };

const struct WildPokemon sCeruleanCaveB1F_LeafGreen_WaterMons[] =
{
    { 40, 50, SPECIES_SLOWPOKE },
    { 50, 60, SPECIES_SLOWBRO },
    { 55, 65, SPECIES_SLOWBRO },
    { 50, 60, SPECIES_SLOWPOKE },
    { 50, 60, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCeruleanCaveB1F_LeafGreen_WaterMonsInfo = { 2, sCeruleanCaveB1F_LeafGreen_WaterMons };

const struct WildPokemon sCeruleanCaveB1F_LeafGreen_RockSmashMons[] =
{
    { 40, 50, SPECIES_GEODUDE },
    { 50, 60, SPECIES_GRAVELER },
    { 55, 65, SPECIES_GRAVELER },
    { 50, 60, SPECIES_GEODUDE },
    { 50, 60, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCaveB1F_LeafGreen_RockSmashMonsInfo = { 50, sCeruleanCaveB1F_LeafGreen_RockSmashMons };

const struct WildPokemon sCeruleanCaveB1F_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sCeruleanCaveB1F_LeafGreen_FishingMonsInfo = { 20, sCeruleanCaveB1F_LeafGreen_FishingMons };

const struct WildPokemon sRockTunnel1F_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_ZUBAT },
    { 16, 16, SPECIES_GEODUDE },
    { 16, 16, SPECIES_MANKEY },
    { 17, 17, SPECIES_GEODUDE },
    { 16, 16, SPECIES_ZUBAT },
    { 16, 16, SPECIES_MACHOP },
    { 17, 17, SPECIES_MANKEY },
    { 17, 17, SPECIES_MACHOP },
    { 15, 15, SPECIES_GEODUDE },
    { 13, 13, SPECIES_ONIX },
    { 15, 15, SPECIES_CHARMANDER },
    { 15, 15, SPECIES_ONIX },
};

const struct WildPokemonInfo sRockTunnel1F_LeafGreen_LandMonsInfo = { 7, sRockTunnel1F_LeafGreen_LandMons };

const struct WildPokemon sRockTunnelB1F_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_ZUBAT },
    { 17, 17, SPECIES_GEODUDE },
    { 17, 17, SPECIES_MANKEY },
    { 16, 16, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ZUBAT },
    { 17, 17, SPECIES_MACHOP },
    { 16, 16, SPECIES_MANKEY },
    { 13, 13, SPECIES_ONIX },
    { 15, 15, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ONIX },
    { 15, 15, SPECIES_CHARMANDER },
    { 17, 17, SPECIES_ONIX },
};

const struct WildPokemonInfo sRockTunnelB1F_LeafGreen_LandMonsInfo = { 7, sRockTunnelB1F_LeafGreen_LandMons };

const struct WildPokemon sRockTunnelB1F_LeafGreen_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sRockTunnelB1F_LeafGreen_RockSmashMonsInfo = { 50, sRockTunnelB1F_LeafGreen_RockSmashMons };

const struct WildPokemon sSeafoamIslands1F_LeafGreen_LandMons[] =
{
    { 27, 27, SPECIES_SLOWPOKE },
    { 29, 29, SPECIES_SLOWPOKE },
    { 31, 31, SPECIES_SLOWPOKE },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 28, 28, SPECIES_GOLBAT },
    { 33, 33, SPECIES_SLOWPOKE },
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SLOWPOKE },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslands1F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslands1F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB1F_LeafGreen_LandMons[] =
{
    { 29, 29, SPECIES_SLOWPOKE },
    { 31, 31, SPECIES_SLOWPOKE },
    { 28, 28, SPECIES_SEEL },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 28, 28, SPECIES_GOLBAT },
    { 33, 33, SPECIES_SLOWBRO },
    { 26, 26, SPECIES_ZUBAT },
    { 35, 35, SPECIES_SLOWBRO },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB1F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslandsB1F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB2F_LeafGreen_LandMons[] =
{
    { 30, 30, SPECIES_SLOWPOKE },
    { 32, 32, SPECIES_SLOWPOKE },
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SLOWBRO },
    { 32, 32, SPECIES_SLOWBRO },
    { 28, 28, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SLOWBRO },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB2F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslandsB2F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB3F_LeafGreen_LandMons[] =
{
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 32, 32, SPECIES_SLOWPOKE },
    { 30, 30, SPECIES_SLOWPOKE },
    { 32, 32, SPECIES_SLOWBRO },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SLOWBRO },
    { 32, 32, SPECIES_DEWGONG },
    { 28, 28, SPECIES_GOLBAT },
    { 34, 34, SPECIES_DEWGONG },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslandsB3F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB3F_LeafGreen_WaterMons[] =
{
    { 25, 35, SPECIES_SEEL },
    { 25, 30, SPECIES_KRABBY },
    { 35, 40, SPECIES_DEWGONG },
    { 30, 40, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_LeafGreen_WaterMonsInfo = { 2, sSeafoamIslandsB3F_LeafGreen_WaterMons };

const struct WildPokemon sSeafoamIslandsB3F_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 20, 30, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_LeafGreen_FishingMonsInfo = { 20, sSeafoamIslandsB3F_LeafGreen_FishingMons };

const struct WildPokemon sSeafoamIslandsB4F_LeafGreen_LandMons[] =
{
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 32, 32, SPECIES_SLOWPOKE },
    { 34, 34, SPECIES_SEEL },
    { 32, 32, SPECIES_SLOWBRO },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_DEWGONG },
    { 34, 34, SPECIES_SLOWBRO },
    { 36, 36, SPECIES_DEWGONG },
    { 28, 28, SPECIES_GOLBAT },
    { 36, 36, SPECIES_DEWGONG },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslandsB4F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB4F_LeafGreen_WaterMons[] =
{
    { 25, 35, SPECIES_SEEL },
    { 25, 30, SPECIES_KRABBY },
    { 35, 40, SPECIES_DEWGONG },
    { 30, 40, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_LeafGreen_WaterMonsInfo = { 2, sSeafoamIslandsB4F_LeafGreen_WaterMons };

const struct WildPokemon sSeafoamIslandsB4F_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 20, 30, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_LeafGreen_FishingMonsInfo = { 20, sSeafoamIslandsB4F_LeafGreen_FishingMons };

const struct WildPokemon sPokemonTower3F_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower3F_LeafGreen_LandMonsInfo = { 2, sPokemonTower3F_LeafGreen_LandMons };

const struct WildPokemon sPokemonTower4F_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
};

const struct WildPokemonInfo sPokemonTower4F_LeafGreen_LandMonsInfo = { 4, sPokemonTower4F_LeafGreen_LandMons };

const struct WildPokemon sPokemonTower5F_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
};

const struct WildPokemonInfo sPokemonTower5F_LeafGreen_LandMonsInfo = { 6, sPokemonTower5F_LeafGreen_LandMons };

const struct WildPokemon sPokemonTower6F_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 15, 15, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 21, 21, SPECIES_HAUNTER },
    { 17, 17, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 19, 19, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower6F_LeafGreen_LandMonsInfo = { 8, sPokemonTower6F_LeafGreen_LandMons };

const struct WildPokemon sPokemonTower7F_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 15, 15, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
    { 17, 17, SPECIES_CUBONE },
    { 19, 19, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
    { 18, 18, SPECIES_GASTLY },
    { 25, 25, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower7F_LeafGreen_LandMonsInfo = { 10, sPokemonTower7F_LeafGreen_LandMons };

const struct WildPokemon sPowerPlant_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_PIKACHU },
    { 24, 24, SPECIES_PIKACHU },
    { 31, 31, SPECIES_MAGNETON },
    { 34, 34, SPECIES_MAGNETON },
    { 26, 26, SPECIES_PIKACHU },
    { 31, 31, SPECIES_MAGNETON },
    { 26, 26, SPECIES_PIKACHU },
    { 34, 34, SPECIES_MAGNETON },
};

const struct WildPokemonInfo sPowerPlant_LeafGreen_LandMonsInfo = { 7, sPowerPlant_LeafGreen_LandMons };

const struct WildPokemon sMtEmberExterior_LeafGreen_LandMons[] =
{
    { 30, 30, SPECIES_PONYTA },
    { 38, 38, SPECIES_FEAROW },
    { 33, 33, SPECIES_PONYTA },
    { 32, 32, SPECIES_SPEAROW },
    { 35, 35, SPECIES_MACHOP },
    { 33, 33, SPECIES_GEODUDE },
    { 36, 36, SPECIES_PONYTA },
    { 40, 40, SPECIES_FEAROW },
    { 38, 38, SPECIES_MAGMAR },
    { 39, 39, SPECIES_RAPIDASH },
    { 40, 40, SPECIES_MAGMAR },
    { 42, 42, SPECIES_RAPIDASH },
};

const struct WildPokemonInfo sMtEmberExterior_LeafGreen_LandMonsInfo = { 21, sMtEmberExterior_LeafGreen_LandMons };

const struct WildPokemon sMtEmberExterior_LeafGreen_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sMtEmberExterior_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberExterior_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberSummitPath1F_LeafGreen_LandMons[] =
{
    { 33, 33, SPECIES_GEODUDE },
    { 35, 35, SPECIES_MACHOP },
    { 29, 29, SPECIES_GEODUDE },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MACHOP },
    { 33, 33, SPECIES_MACHOP },
    { 35, 35, SPECIES_GEODUDE },
    { 37, 37, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
};

const struct WildPokemonInfo sMtEmberSummitPath1F_LeafGreen_LandMonsInfo = { 7, sMtEmberSummitPath1F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberSummitPath2F_LeafGreen_LandMons[] =
{
    { 34, 34, SPECIES_GEODUDE },
    { 36, 36, SPECIES_MACHOP },
    { 30, 30, SPECIES_GEODUDE },
    { 32, 32, SPECIES_GEODUDE },
    { 32, 32, SPECIES_MACHOP },
    { 34, 34, SPECIES_MACHOP },
    { 38, 38, SPECIES_MACHOKE },
    { 38, 38, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
};

const struct WildPokemonInfo sMtEmberSummitPath2F_LeafGreen_LandMonsInfo = { 7, sMtEmberSummitPath2F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberSummitPath2F_LeafGreen_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sMtEmberSummitPath2F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberSummitPath2F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberSummitPath3F_LeafGreen_LandMons[] =
{
    { 33, 33, SPECIES_GEODUDE },
    { 35, 35, SPECIES_MACHOP },
    { 29, 29, SPECIES_GEODUDE },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MACHOP },
    { 33, 33, SPECIES_MACHOP },
    { 35, 35, SPECIES_GEODUDE },
    { 37, 37, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
};

const struct WildPokemonInfo sMtEmberSummitPath3F_LeafGreen_LandMonsInfo = { 7, sMtEmberSummitPath3F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPath1F_LeafGreen_LandMons[] =
{
    { 36, 36, SPECIES_GEODUDE },
    { 38, 38, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 34, 34, SPECIES_MACHOP },
    { 36, 36, SPECIES_MACHOP },
    { 38, 38, SPECIES_GEODUDE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_GEODUDE },
    { 42, 42, SPECIES_MACHOKE },
    { 40, 40, SPECIES_GEODUDE },
    { 42, 42, SPECIES_MACHOKE },
};

const struct WildPokemonInfo sMtEmberRubyPath1F_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPath1F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPath1F_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPath1F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPath1F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB1F_LeafGreen_LandMons[] =
{
    { 38, 38, SPECIES_GEODUDE },
    { 36, 36, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 40, 40, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 28, 28, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB1F_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB1F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB1F_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB1F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB1F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB2F_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GEODUDE },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 32, 32, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB2F_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB2F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB2F_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB2F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB2F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB3F_LeafGreen_LandMons[] =
{
    { 26, 26, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 32, 32, SPECIES_SLUGMA },
    { 24, 24, SPECIES_SLUGMA },
    { 22, 22, SPECIES_SLUGMA },
    { 20, 20, SPECIES_SLUGMA },
    { 34, 34, SPECIES_SLUGMA },
    { 36, 36, SPECIES_SLUGMA },
    { 18, 18, SPECIES_SLUGMA },
    { 36, 36, SPECIES_SLUGMA },
    { 18, 18, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB3F_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB3F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB3F_LeafGreen_RockSmashMons[] =
{
    { 15, 25, SPECIES_SLUGMA },
    { 25, 35, SPECIES_SLUGMA },
    { 40, 45, SPECIES_MAGCARGO },
    { 35, 45, SPECIES_MAGCARGO },
    { 25, 35, SPECIES_MAGCARGO },
};

const struct WildPokemonInfo sMtEmberRubyPathB3F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB3F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB1FStairs_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GEODUDE },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 32, 32, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB1FStairs_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB1FStairs_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB1FStairs_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB1FStairs_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB1FStairs_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB2FStairs_LeafGreen_LandMons[] =
{
    { 38, 38, SPECIES_GEODUDE },
    { 36, 36, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 40, 40, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 28, 28, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB2FStairs_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB2FStairs_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB2FStairs_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB2FStairs_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB2FStairs_LeafGreen_RockSmashMons };

const struct WildPokemon sThreeIslandBerryForest_LeafGreen_LandMons[] =
{
    { 37, 37, SPECIES_PIDGEOTTO },
    { 35, 35, SPECIES_WEEPINBELL },
    { 32, 32, SPECIES_PIDGEY },
    { 30, 30, SPECIES_BELLSPROUT },
    { 34, 34, SPECIES_VENONAT },
    { 34, 34, SPECIES_DROWZEE },
    { 35, 35, SPECIES_EXEGGCUTE },
    { 31, 31, SPECIES_SLOWPOKE },
    { 37, 37, SPECIES_VENOMOTH },
    { 37, 37, SPECIES_HYPNO },
    { 40, 40, SPECIES_VENOMOTH },
    { 40, 40, SPECIES_HYPNO },
};

const struct WildPokemonInfo sThreeIslandBerryForest_LeafGreen_LandMonsInfo = { 21, sThreeIslandBerryForest_LeafGreen_LandMons };

const struct WildPokemon sThreeIslandBerryForest_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_SLOWPOKE },
    { 20, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWBRO },
    { 35, 40, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo sThreeIslandBerryForest_LeafGreen_WaterMonsInfo = { 2, sThreeIslandBerryForest_LeafGreen_WaterMons };

const struct WildPokemon sThreeIslandBerryForest_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sThreeIslandBerryForest_LeafGreen_FishingMonsInfo = { 20, sThreeIslandBerryForest_LeafGreen_FishingMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_LeafGreen_LandMons[] =
{
    { 43, 43, SPECIES_SEEL },
    { 45, 45, SPECIES_SPHEAL },
    { 45, 45, SPECIES_SEEL },
    { 47, 47, SPECIES_SEEL },
    { 40, 40, SPECIES_ZUBAT },
    { 49, 49, SPECIES_DEWGONG },
    { 51, 51, SPECIES_DEWGONG },
    { 41, 41, SPECIES_SLOWPOKE },
    { 48, 48, SPECIES_SNORUNT },
    { 53, 53, SPECIES_DEWGONG },
    { 48, 48, SPECIES_SNORUNT },
    { 53, 53, SPECIES_DEWGONG },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_LeafGreen_LandMonsInfo = { 7, sFourIslandIcefallCaveEntrance_LeafGreen_LandMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_SEEL },
    { 5, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_DEWGONG },
    { 5, 15, SPECIES_MARILL },
    { 5, 15, SPECIES_MARILL },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_LeafGreen_WaterMonsInfo = { 2, sFourIslandIcefallCaveEntrance_LeafGreen_WaterMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_LeafGreen_FishingMonsInfo = { 20, sFourIslandIcefallCaveEntrance_LeafGreen_FishingMons };

const struct WildPokemon sFourIslandIcefallCave1F_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_SWINUB },
    { 45, 45, SPECIES_SPHEAL },
    { 45, 45, SPECIES_SEEL },
    { 27, 27, SPECIES_SWINUB },
    { 40, 40, SPECIES_ZUBAT },
    { 29, 29, SPECIES_SWINUB },
    { 30, 30, SPECIES_SNEASEL },
    { 31, 31, SPECIES_SWINUB },
    { 48, 48, SPECIES_SNORUNT },
    { 23, 23, SPECIES_SWINUB },
    { 48, 48, SPECIES_SNORUNT },
    { 23, 23, SPECIES_SWINUB },
};

const struct WildPokemonInfo sFourIslandIcefallCave1F_LeafGreen_LandMonsInfo = { 7, sFourIslandIcefallCave1F_LeafGreen_LandMons };

const struct WildPokemon sFourIslandIcefallCaveB1F_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_SWINUB },
    { 45, 45, SPECIES_SPHEAL },
    { 45, 45, SPECIES_SEEL },
    { 27, 27, SPECIES_SWINUB },
    { 40, 40, SPECIES_ZUBAT },
    { 29, 29, SPECIES_SWINUB },
    { 30, 30, SPECIES_SNEASEL },
    { 31, 31, SPECIES_SWINUB },
    { 48, 48, SPECIES_SNORUNT },
    { 23, 23, SPECIES_SWINUB },
    { 48, 48, SPECIES_SNORUNT },
    { 23, 23, SPECIES_SWINUB },
};

const struct WildPokemonInfo sFourIslandIcefallCaveB1F_LeafGreen_LandMonsInfo = { 7, sFourIslandIcefallCaveB1F_LeafGreen_LandMons };

const struct WildPokemon sFourIslandIcefallCaveBack_LeafGreen_LandMons[] =
{
    { 43, 43, SPECIES_SEEL },
    { 45, 45, SPECIES_SPHEAL },
    { 45, 45, SPECIES_SEEL },
    { 47, 47, SPECIES_SEEL },
    { 40, 40, SPECIES_ZUBAT },
    { 49, 49, SPECIES_DEWGONG },
    { 51, 51, SPECIES_DEWGONG },
    { 41, 41, SPECIES_SLOWPOKE },
    { 48, 48, SPECIES_SNORUNT },
    { 53, 53, SPECIES_DEWGONG },
    { 48, 48, SPECIES_SNORUNT },
    { 53, 53, SPECIES_DEWGONG },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_LeafGreen_LandMonsInfo = { 7, sFourIslandIcefallCaveBack_LeafGreen_LandMons };

const struct WildPokemon sFourIslandIcefallCaveBack_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 45, SPECIES_TENTACOOL },
    { 35, 45, SPECIES_TENTACRUEL },
    { 30, 45, SPECIES_LAPRAS },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_LeafGreen_WaterMonsInfo = { 2, sFourIslandIcefallCaveBack_LeafGreen_WaterMons };

const struct WildPokemon sFourIslandIcefallCaveBack_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_LeafGreen_FishingMonsInfo = { 20, sFourIslandIcefallCaveBack_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandPatternBush_LeafGreen_LandMons[] =
{
    { 9, 9, SPECIES_SPINARAK },
    { 9, 9, SPECIES_LEDYBA },
    { 14, 14, SPECIES_SPINARAK },
    { 15, 15, SPECIES_VOLBEAT },
    { 8, 8, SPECIES_WURMPLE },
    { 15, 15, SPECIES_ILLUMISE },
    { 18, 18, SPECIES_SHROOMISH },
    { 30, 30, SPECIES_TROPIUS },
    { 25, 25, SPECIES_HERACROSS },
    { 25, 25, SPECIES_HERACROSS },
    { 5, 5, SPECIES_TREECKO },
    { 5, 5, SPECIES_CHIKORITA },
};

const struct WildPokemonInfo sSixIslandPatternBush_LeafGreen_LandMonsInfo = { 21, sSixIslandPatternBush_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom1_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom1_LeafGreen_LandMonsInfo = { 1, sFiveIslandLostCaveRoom1_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom2_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom2_LeafGreen_LandMonsInfo = { 2, sFiveIslandLostCaveRoom2_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom3_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom3_LeafGreen_LandMonsInfo = { 3, sFiveIslandLostCaveRoom3_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom4_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom4_LeafGreen_LandMonsInfo = { 4, sFiveIslandLostCaveRoom4_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom5_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom5_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom5_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom6_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom6_LeafGreen_LandMonsInfo = { 6, sFiveIslandLostCaveRoom6_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom7_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom7_LeafGreen_LandMonsInfo = { 7, sFiveIslandLostCaveRoom7_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom8_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom8_LeafGreen_LandMonsInfo = { 8, sFiveIslandLostCaveRoom8_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom9_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom9_LeafGreen_LandMonsInfo = { 9, sFiveIslandLostCaveRoom9_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom10_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom10_LeafGreen_LandMonsInfo = { 10, sFiveIslandLostCaveRoom10_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom11_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MISDREAVUS },
    { 20, 20, SPECIES_MISDREAVUS },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom11_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom11_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom12_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MISDREAVUS },
    { 20, 20, SPECIES_MISDREAVUS },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom12_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom12_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom13_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MISDREAVUS },
    { 20, 20, SPECIES_MISDREAVUS },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom13_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom13_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom14_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MISDREAVUS },
    { 20, 20, SPECIES_MISDREAVUS },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom14_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom14_LeafGreen_LandMons };

const struct WildPokemon sOneIslandKindleRoad_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_SPEAROW },
    { 34, 34, SPECIES_PONYTA },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_PONYTA },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MEOWTH },
    { 30, 30, SPECIES_SPEAROW },
    { 34, 34, SPECIES_SLOWPOKE },
    { 37, 37, SPECIES_RAPIDASH },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_RAPIDASH },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sOneIslandKindleRoad_LeafGreen_LandMonsInfo = { 21, sOneIslandKindleRoad_LeafGreen_LandMons };

const struct WildPokemon sOneIslandKindleRoad_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIslandKindleRoad_LeafGreen_WaterMonsInfo = { 2, sOneIslandKindleRoad_LeafGreen_WaterMons };

const struct WildPokemon sOneIslandKindleRoad_LeafGreen_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sOneIslandKindleRoad_LeafGreen_RockSmashMonsInfo = { 25, sOneIslandKindleRoad_LeafGreen_RockSmashMons };

const struct WildPokemon sOneIslandKindleRoad_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sOneIslandKindleRoad_LeafGreen_FishingMonsInfo = { 20, sOneIslandKindleRoad_LeafGreen_FishingMons };

const struct WildPokemon sOneIslandTreasureBeach_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_SPEAROW },
    { 33, 33, SPECIES_TANGELA },
    { 31, 31, SPECIES_SPEAROW },
    { 35, 35, SPECIES_TANGELA },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_MEOWTH },
    { 38, 38, SPECIES_FEAROW },
    { 31, 31, SPECIES_SLOWPOKE },
    { 40, 40, SPECIES_FEAROW },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_FEAROW },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_LeafGreen_LandMonsInfo = { 21, sOneIslandTreasureBeach_LeafGreen_LandMons };

const struct WildPokemon sOneIslandTreasureBeach_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_LeafGreen_WaterMonsInfo = { 2, sOneIslandTreasureBeach_LeafGreen_WaterMons };

const struct WildPokemon sOneIslandTreasureBeach_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_LeafGreen_FishingMonsInfo = { 20, sOneIslandTreasureBeach_LeafGreen_FishingMons };

const struct WildPokemon sTwoIslandCapeBrink_LeafGreen_LandMons[] =
{
    { 31, 31, SPECIES_SPEAROW },
    { 30, 30, SPECIES_BELLSPROUT },
    { 32, 32, SPECIES_BELLSPROUT },
    { 36, 36, SPECIES_WEEPINBELL },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_MEOWTH },
    { 38, 38, SPECIES_WEEPINBELL },
    { 31, 31, SPECIES_SLOWPOKE },
    { 37, 37, SPECIES_SLOWBRO },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_SLOWBRO },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_LeafGreen_LandMonsInfo = { 21, sTwoIslandCapeBrink_LeafGreen_LandMons };

const struct WildPokemon sTwoIslandCapeBrink_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_SLOWPOKE },
    { 20, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWBRO },
    { 35, 40, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_LeafGreen_WaterMonsInfo = { 2, sTwoIslandCapeBrink_LeafGreen_WaterMons };

const struct WildPokemon sTwoIslandCapeBrink_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_LeafGreen_FishingMonsInfo = { 20, sTwoIslandCapeBrink_LeafGreen_FishingMons };

const struct WildPokemon sThreeIslandBondBridge_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_PIDGEY },
    { 31, 31, SPECIES_BELLSPROUT },
    { 29, 29, SPECIES_PIDGEY },
    { 36, 36, SPECIES_WEEPINBELL },
    { 34, 34, SPECIES_PIDGEOTTO },
    { 31, 31, SPECIES_MEOWTH },
    { 34, 34, SPECIES_VENONAT },
    { 31, 31, SPECIES_SLOWPOKE },
    { 37, 37, SPECIES_PIDGEOTTO },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_PIDGEOTTO },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sThreeIslandBondBridge_LeafGreen_LandMonsInfo = { 21, sThreeIslandBondBridge_LeafGreen_LandMons };

const struct WildPokemon sThreeIslandBondBridge_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sThreeIslandBondBridge_LeafGreen_WaterMonsInfo = { 2, sThreeIslandBondBridge_LeafGreen_WaterMons };

const struct WildPokemon sThreeIslandBondBridge_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sThreeIslandBondBridge_LeafGreen_FishingMonsInfo = { 20, sThreeIslandBondBridge_LeafGreen_FishingMons };

const struct WildPokemon sThreeIslandPort_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_DUNSPARCE },
    { 15, 15, SPECIES_DUNSPARCE },
    { 10, 10, SPECIES_DUNSPARCE },
    { 10, 10, SPECIES_DUNSPARCE },
    { 20, 20, SPECIES_DUNSPARCE },
    { 20, 20, SPECIES_DUNSPARCE },
    { 25, 25, SPECIES_DUNSPARCE },
    { 30, 30, SPECIES_DUNSPARCE },
    { 25, 25, SPECIES_DUNSPARCE },
    { 30, 30, SPECIES_DUNSPARCE },
    { 5, 5, SPECIES_DUNSPARCE },
    { 35, 35, SPECIES_DUNSPARCE },
};

const struct WildPokemonInfo sThreeIslandPort_LeafGreen_LandMonsInfo = { 1, sThreeIslandPort_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandResortGorgeous_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandResortGorgeous_LeafGreen_WaterMonsInfo = { 2, sFiveIslandResortGorgeous_LeafGreen_WaterMons };

const struct WildPokemon sFiveIslandResortGorgeous_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIslandResortGorgeous_LeafGreen_FishingMonsInfo = { 20, sFiveIslandResortGorgeous_LeafGreen_FishingMons };

const struct WildPokemon sFiveIslandWaterLabyrinth_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandWaterLabyrinth_LeafGreen_WaterMonsInfo = { 2, sFiveIslandWaterLabyrinth_LeafGreen_WaterMons };

const struct WildPokemon sFiveIslandWaterLabyrinth_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIslandWaterLabyrinth_LeafGreen_FishingMonsInfo = { 20, sFiveIslandWaterLabyrinth_LeafGreen_FishingMons };

const struct WildPokemon sFiveIslandMeadow_LeafGreen_LandMons[] =
{
    { 44, 44, SPECIES_PIDGEY },
    { 10, 10, SPECIES_SENTRET },
    { 48, 48, SPECIES_PIDGEOTTO },
    { 10, 10, SPECIES_HOPPIP },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 15, 15, SPECIES_HOPPIP },
    { 41, 41, SPECIES_SLOWPOKE },
    { 50, 50, SPECIES_PIDGEOTTO },
    { 47, 47, SPECIES_PERSIAN },
    { 50, 50, SPECIES_PIDGEOTTO },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sFiveIslandMeadow_LeafGreen_LandMonsInfo = { 21, sFiveIslandMeadow_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandMeadow_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandMeadow_LeafGreen_WaterMonsInfo = { 2, sFiveIslandMeadow_LeafGreen_WaterMons };

const struct WildPokemon sFiveIslandMeadow_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIslandMeadow_LeafGreen_FishingMonsInfo = { 20, sFiveIslandMeadow_LeafGreen_FishingMons };

const struct WildPokemon sFiveIslandMemorialPillar_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_HOPPIP },
    { 12, 12, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
    { 10, 10, SPECIES_HOPPIP },
    { 12, 12, SPECIES_HOPPIP },
    { 16, 16, SPECIES_HOPPIP },
    { 6, 6, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_LeafGreen_LandMonsInfo = { 21, sFiveIslandMemorialPillar_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandMemorialPillar_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_LeafGreen_WaterMonsInfo = { 2, sFiveIslandMemorialPillar_LeafGreen_WaterMons };

const struct WildPokemon sFiveIslandMemorialPillar_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_LeafGreen_FishingMonsInfo = { 20, sFiveIslandMemorialPillar_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandOutcastIsland_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandOutcastIsland_LeafGreen_WaterMonsInfo = { 2, sSixIslandOutcastIsland_LeafGreen_WaterMons };

const struct WildPokemon sSixIslandOutcastIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSixIslandOutcastIsland_LeafGreen_FishingMonsInfo = { 20, sSixIslandOutcastIsland_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandGreenPath_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandGreenPath_LeafGreen_WaterMonsInfo = { 2, sSixIslandGreenPath_LeafGreen_WaterMons };

const struct WildPokemon sSixIslandGreenPath_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSixIslandGreenPath_LeafGreen_FishingMonsInfo = { 20, sSixIslandGreenPath_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandWaterPath_LeafGreen_LandMons[] =
{
    { 44, 44, SPECIES_SPEAROW },
    { 10, 10, SPECIES_SENTRET },
    { 44, 44, SPECIES_BELLSPROUT },
    { 48, 48, SPECIES_FEAROW },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 48, 48, SPECIES_WEEPINBELL },
    { 41, 41, SPECIES_SLOWPOKE },
    { 50, 50, SPECIES_FEAROW },
    { 47, 47, SPECIES_PERSIAN },
    { 5, 5, SPECIES_MUDKIP },
    { 5, 5, SPECIES_TOTODILE },
};

const struct WildPokemonInfo sSixIslandWaterPath_LeafGreen_LandMonsInfo = { 21, sSixIslandWaterPath_LeafGreen_LandMons };

const struct WildPokemon sSixIslandWaterPath_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandWaterPath_LeafGreen_WaterMonsInfo = { 2, sSixIslandWaterPath_LeafGreen_WaterMons };

const struct WildPokemon sSixIslandWaterPath_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSixIslandWaterPath_LeafGreen_FishingMonsInfo = { 20, sSixIslandWaterPath_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandRuinValley_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_NATU },
    { 44, 44, SPECIES_SPEAROW },
    { 18, 18, SPECIES_YANMA },
    { 15, 15, SPECIES_MARILL },
    { 49, 49, SPECIES_FEAROW },
    { 43, 43, SPECIES_MEOWTH },
    { 25, 25, SPECIES_WOBBUFFET },
    { 41, 41, SPECIES_SLOWPOKE },
    { 20, 20, SPECIES_NATU },
    { 49, 49, SPECIES_PERSIAN },
    { 5, 5, SPECIES_TORCHIC },
    { 5, 5, SPECIES_CYNDAQUIL },
};

const struct WildPokemonInfo sSixIslandRuinValley_LeafGreen_LandMonsInfo = { 21, sSixIslandRuinValley_LeafGreen_LandMons };

const struct WildPokemon sSixIslandRuinValley_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 15, 25, SPECIES_MARILL },
    { 20, 25, SPECIES_MARILL },
    { 20, 25, SPECIES_MARILL },
};

const struct WildPokemonInfo sSixIslandRuinValley_LeafGreen_WaterMonsInfo = { 2, sSixIslandRuinValley_LeafGreen_WaterMons };

const struct WildPokemon sSixIslandRuinValley_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSixIslandRuinValley_LeafGreen_FishingMonsInfo = { 20, sSixIslandRuinValley_LeafGreen_FishingMons };

const struct WildPokemon sSevenIslandTrainerTower_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_MANTINE },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSevenIslandTrainerTower_LeafGreen_WaterMonsInfo = { 2, sSevenIslandTrainerTower_LeafGreen_WaterMons };

const struct WildPokemon sSevenIslandTrainerTower_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSevenIslandTrainerTower_LeafGreen_FishingMonsInfo = { 20, sSevenIslandTrainerTower_LeafGreen_FishingMons };

const struct WildPokemon sSevenIslandSevaultCanyonEntrance_LeafGreen_LandMons[] =
{
    { 44, 44, SPECIES_SPEAROW },
    { 10, 10, SPECIES_SENTRET },
    { 10, 10, SPECIES_PHANPY },
    { 48, 48, SPECIES_FEAROW },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 50, 50, SPECIES_FEAROW },
    { 41, 41, SPECIES_SLOWPOKE },
    { 15, 15, SPECIES_PHANPY },
    { 47, 47, SPECIES_PERSIAN },
    { 15, 15, SPECIES_PHANPY },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyonEntrance_LeafGreen_LandMonsInfo = { 21, sSevenIslandSevaultCanyonEntrance_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandSevaultCanyon_LeafGreen_LandMons[] =
{
    { 46, 46, SPECIES_GEODUDE },
    { 15, 15, SPECIES_PHANPY },
    { 46, 46, SPECIES_CUBONE },
    { 50, 50, SPECIES_FEAROW },
    { 52, 52, SPECIES_MAROWAK },
    { 43, 43, SPECIES_MEOWTH },
    { 54, 54, SPECIES_ONIX },
    { 50, 50, SPECIES_FEAROW },
    { 15, 15, SPECIES_LARVITAR },
    { 49, 49, SPECIES_PERSIAN },
    { 20, 20, SPECIES_LARVITAR },
    { 52, 52, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyon_LeafGreen_LandMonsInfo = { 21, sSevenIslandSevaultCanyon_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandSevaultCanyon_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyon_LeafGreen_RockSmashMonsInfo = { 25, sSevenIslandSevaultCanyon_LeafGreen_RockSmashMons };

const struct WildPokemon sSevenIslandTanobyRuins_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_MANTINE },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSevenIslandTanobyRuins_LeafGreen_WaterMonsInfo = { 2, sSevenIslandTanobyRuins_LeafGreen_WaterMons };

const struct WildPokemon sSevenIslandTanobyRuins_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSevenIslandTanobyRuins_LeafGreen_FishingMonsInfo = { 20, sSevenIslandTanobyRuins_LeafGreen_FishingMons };

const struct WildPokemon sRoute1_LeafGreen_LandMons[] =
{
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 2, 2, SPECIES_PIDGEY },
    { 2, 2, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 4, 4, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
    { 5, 5, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
};

const struct WildPokemonInfo sRoute1_LeafGreen_LandMonsInfo = { 21, sRoute1_LeafGreen_LandMons };

const struct WildPokemon sRoute2_LeafGreen_LandMons[] =
{
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
    { 4, 4, SPECIES_PIDGEY },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_PIDGEY },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_PIDGEY },
    { 4, 4, SPECIES_CATERPIE },
    { 4, 4, SPECIES_WEEDLE },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_WEEDLE },
};

const struct WildPokemonInfo sRoute2_LeafGreen_LandMonsInfo = { 21, sRoute2_LeafGreen_LandMons };

const struct WildPokemon sRoute3_LeafGreen_LandMons[] =
{
    { 6, 6, SPECIES_SPEAROW },
    { 6, 6, SPECIES_PIDGEY },
    { 7, 7, SPECIES_SPEAROW },
    { 7, 7, SPECIES_MANKEY },
    { 6, 6, SPECIES_NIDORAN_F },
    { 7, 7, SPECIES_PIDGEY },
    { 8, 8, SPECIES_SPEAROW },
    { 3, 3, SPECIES_JIGGLYPUFF },
    { 7, 7, SPECIES_NIDORAN_F },
    { 5, 5, SPECIES_JIGGLYPUFF },
    { 6, 6, SPECIES_NIDORAN_M },
    { 7, 7, SPECIES_JIGGLYPUFF },
};

const struct WildPokemonInfo sRoute3_LeafGreen_LandMonsInfo = { 21, sRoute3_LeafGreen_LandMons };

const struct WildPokemon sRoute4_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_SPEAROW },
    { 10, 10, SPECIES_RATTATA },
    { 6, 6, SPECIES_SANDSHREW },
    { 10, 10, SPECIES_SANDSHREW },
    { 8, 8, SPECIES_SPEAROW },
    { 8, 8, SPECIES_RATTATA },
    { 12, 12, SPECIES_SPEAROW },
    { 12, 12, SPECIES_RATTATA },
    { 10, 10, SPECIES_MANKEY },
    { 8, 8, SPECIES_SANDSHREW },
    { 12, 12, SPECIES_MANKEY },
    { 12, 12, SPECIES_SANDSHREW },
};

const struct WildPokemonInfo sRoute4_LeafGreen_LandMonsInfo = { 21, sRoute4_LeafGreen_LandMons };

const struct WildPokemon sRoute4_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute4_LeafGreen_WaterMonsInfo = { 2, sRoute4_LeafGreen_WaterMons };

const struct WildPokemon sRoute4_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute4_LeafGreen_FishingMonsInfo = { 20, sRoute4_LeafGreen_FishingMons };

const struct WildPokemon sRoute5_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_MEOWTH },
    { 13, 13, SPECIES_PIDGEY },
    { 13, 13, SPECIES_BELLSPROUT },
    { 12, 12, SPECIES_MEOWTH },
    { 15, 15, SPECIES_BELLSPROUT },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_BELLSPROUT },
    { 16, 16, SPECIES_PIDGEY },
    { 15, 15, SPECIES_PIDGEY },
    { 14, 14, SPECIES_MEOWTH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute5_LeafGreen_LandMonsInfo = { 21, sRoute5_LeafGreen_LandMons };

const struct WildPokemon sRoute6_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_MEOWTH },
    { 13, 13, SPECIES_PIDGEY },
    { 13, 13, SPECIES_BELLSPROUT },
    { 12, 12, SPECIES_MEOWTH },
    { 15, 15, SPECIES_BELLSPROUT },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_BELLSPROUT },
    { 16, 16, SPECIES_PIDGEY },
    { 15, 15, SPECIES_PIDGEY },
    { 14, 14, SPECIES_MEOWTH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute6_LeafGreen_LandMonsInfo = { 21, sRoute6_LeafGreen_LandMons };

const struct WildPokemon sRoute6_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute6_LeafGreen_WaterMonsInfo = { 2, sRoute6_LeafGreen_WaterMons };

const struct WildPokemon sRoute6_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute6_LeafGreen_FishingMonsInfo = { 20, sRoute6_LeafGreen_FishingMons };

const struct WildPokemon sRoute7_LeafGreen_LandMons[] =
{
    { 19, 19, SPECIES_PIDGEY },
    { 17, 17, SPECIES_MEOWTH },
    { 19, 19, SPECIES_BELLSPROUT },
    { 18, 18, SPECIES_MEOWTH },
    { 22, 22, SPECIES_PIDGEY },
    { 22, 22, SPECIES_BELLSPROUT },
    { 18, 18, SPECIES_VULPIX },
    { 20, 20, SPECIES_VULPIX },
    { 17, 17, SPECIES_MEOWTH },
    { 19, 19, SPECIES_MEOWTH },
    { 17, 17, SPECIES_MEOWTH },
    { 20, 20, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute7_LeafGreen_LandMonsInfo = { 21, sRoute7_LeafGreen_LandMons };

const struct WildPokemon sRoute8_LeafGreen_LandMons[] =
{
    { 18, 18, SPECIES_PIDGEY },
    { 18, 18, SPECIES_MEOWTH },
    { 16, 16, SPECIES_VULPIX },
    { 20, 20, SPECIES_PIDGEY },
    { 20, 20, SPECIES_MEOWTH },
    { 17, 17, SPECIES_SANDSHREW },
    { 17, 17, SPECIES_VULPIX },
    { 19, 19, SPECIES_SANDSHREW },
    { 17, 17, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_VULPIX },
    { 17, 17, SPECIES_SANDSHREW },
    { 18, 18, SPECIES_VULPIX },
};

const struct WildPokemonInfo sRoute8_LeafGreen_LandMonsInfo = { 21, sRoute8_LeafGreen_LandMons };

const struct WildPokemon sRoute9_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_SPEAROW },
    { 16, 16, SPECIES_RATTATA },
    { 11, 11, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_SANDSHREW },
    { 13, 13, SPECIES_SPEAROW },
    { 14, 14, SPECIES_RATTATA },
    { 17, 17, SPECIES_SPEAROW },
    { 17, 17, SPECIES_RATTATA },
    { 14, 14, SPECIES_RATTATA },
    { 13, 13, SPECIES_SANDSHREW },
    { 14, 14, SPECIES_RATTATA },
    { 17, 17, SPECIES_SANDSHREW },
};

const struct WildPokemonInfo sRoute9_LeafGreen_LandMonsInfo = { 21, sRoute9_LeafGreen_LandMons };

const struct WildPokemon sRoute10_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_SPEAROW },
    { 16, 16, SPECIES_VOLTORB },
    { 11, 11, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_SANDSHREW },
    { 13, 13, SPECIES_SPEAROW },
    { 14, 14, SPECIES_VOLTORB },
    { 17, 17, SPECIES_SPEAROW },
    { 17, 17, SPECIES_VOLTORB },
    { 14, 14, SPECIES_VOLTORB },
    { 13, 13, SPECIES_SANDSHREW },
    { 14, 14, SPECIES_VOLTORB },
    { 17, 17, SPECIES_SANDSHREW },
};

const struct WildPokemonInfo sRoute10_LeafGreen_LandMonsInfo = { 21, sRoute10_LeafGreen_LandMons };

const struct WildPokemon sRoute10_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute10_LeafGreen_WaterMonsInfo = { 2, sRoute10_LeafGreen_WaterMons };

const struct WildPokemon sRoute10_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute10_LeafGreen_FishingMonsInfo = { 20, sRoute10_LeafGreen_FishingMons };

const struct WildPokemon sRoute11_LeafGreen_LandMons[] =
{
    { 14, 14, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_SPEAROW },
    { 12, 12, SPECIES_SANDSHREW },
    { 13, 13, SPECIES_SPEAROW },
    { 11, 11, SPECIES_DROWZEE },
    { 13, 13, SPECIES_DROWZEE },
    { 15, 15, SPECIES_SANDSHREW },
    { 17, 17, SPECIES_SPEAROW },
    { 12, 12, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_DROWZEE },
    { 12, 12, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_DROWZEE },
};

const struct WildPokemonInfo sRoute11_LeafGreen_LandMonsInfo = { 21, sRoute11_LeafGreen_LandMons };

const struct WildPokemon sRoute11_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute11_LeafGreen_WaterMonsInfo = { 2, sRoute11_LeafGreen_WaterMons };

const struct WildPokemon sRoute11_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute11_LeafGreen_FishingMonsInfo = { 20, sRoute11_LeafGreen_FishingMons };

const struct WildPokemon sRoute12_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_BELLSPROUT },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_BELLSPROUT },
    { 23, 23, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_BELLSPROUT },
    { 27, 27, SPECIES_PIDGEY },
    { 23, 23, SPECIES_PIDGEY },
    { 28, 28, SPECIES_WEEPINBELL },
    { 23, 23, SPECIES_PIDGEY },
    { 30, 30, SPECIES_WEEPINBELL },
};

const struct WildPokemonInfo sRoute12_LeafGreen_LandMonsInfo = { 21, sRoute12_LeafGreen_LandMons };

const struct WildPokemon sRoute12_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute12_LeafGreen_WaterMonsInfo = { 2, sRoute12_LeafGreen_WaterMons };

const struct WildPokemon sRoute12_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute12_LeafGreen_FishingMonsInfo = { 60, sRoute12_LeafGreen_FishingMons };

const struct WildPokemon sRoute13_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_BELLSPROUT },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_BELLSPROUT },
    { 27, 27, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_BELLSPROUT },
    { 25, 25, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 28, 28, SPECIES_WEEPINBELL },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 30, 30, SPECIES_WEEPINBELL },
};

const struct WildPokemonInfo sRoute13_LeafGreen_LandMonsInfo = { 21, sRoute13_LeafGreen_LandMons };

const struct WildPokemon sRoute13_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute13_LeafGreen_WaterMonsInfo = { 2, sRoute13_LeafGreen_WaterMons };

const struct WildPokemon sRoute13_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute13_LeafGreen_FishingMonsInfo = { 20, sRoute13_LeafGreen_FishingMons };

const struct WildPokemon sRoute14_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_BELLSPROUT },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_BELLSPROUT },
    { 23, 23, SPECIES_DITTO },
    { 27, 27, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_BELLSPROUT },
    { 30, 30, SPECIES_WEEPINBELL },
    { 23, 23, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 23, 23, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
};

const struct WildPokemonInfo sRoute14_LeafGreen_LandMonsInfo = { 21, sRoute14_LeafGreen_LandMons };

const struct WildPokemon sRoute15_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_BELLSPROUT },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_BELLSPROUT },
    { 27, 27, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_BELLSPROUT },
    { 25, 25, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 28, 28, SPECIES_WEEPINBELL },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 30, 30, SPECIES_WEEPINBELL },
};

const struct WildPokemonInfo sRoute15_LeafGreen_LandMonsInfo = { 21, sRoute15_LeafGreen_LandMons };

const struct WildPokemon sRoute16_LeafGreen_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 18, 18, SPECIES_DODUO },
    { 18, 18, SPECIES_RATTATA },
    { 20, 20, SPECIES_RATTATA },
    { 22, 22, SPECIES_SPEAROW },
    { 20, 20, SPECIES_DODUO },
    { 22, 22, SPECIES_RATTATA },
    { 22, 22, SPECIES_DODUO },
    { 18, 18, SPECIES_RATTATA },
    { 23, 23, SPECIES_RATICATE },
    { 18, 18, SPECIES_RATTATA },
    { 25, 25, SPECIES_RATICATE },
};

const struct WildPokemonInfo sRoute16_LeafGreen_LandMonsInfo = { 21, sRoute16_LeafGreen_LandMons };

const struct WildPokemon sRoute17_LeafGreen_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 24, 24, SPECIES_DODUO },
    { 22, 22, SPECIES_SPEAROW },
    { 26, 26, SPECIES_DODUO },
    { 25, 25, SPECIES_RATICATE },
    { 27, 27, SPECIES_RATICATE },
    { 28, 28, SPECIES_DODUO },
    { 29, 29, SPECIES_RATICATE },
    { 22, 22, SPECIES_RATTATA },
    { 25, 25, SPECIES_FEAROW },
    { 22, 22, SPECIES_RATTATA },
    { 27, 27, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute17_LeafGreen_LandMonsInfo = { 21, sRoute17_LeafGreen_LandMons };

const struct WildPokemon sRoute18_LeafGreen_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 24, 24, SPECIES_DODUO },
    { 22, 22, SPECIES_SPEAROW },
    { 26, 26, SPECIES_DODUO },
    { 25, 25, SPECIES_RATICATE },
    { 25, 25, SPECIES_FEAROW },
    { 28, 28, SPECIES_DODUO },
    { 29, 29, SPECIES_RATICATE },
    { 22, 22, SPECIES_RATTATA },
    { 27, 27, SPECIES_FEAROW },
    { 22, 22, SPECIES_RATTATA },
    { 29, 29, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute18_LeafGreen_LandMonsInfo = { 21, sRoute18_LeafGreen_LandMons };

const struct WildPokemon sRoute19_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute19_LeafGreen_WaterMonsInfo = { 2, sRoute19_LeafGreen_WaterMons };

const struct WildPokemon sRoute19_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute19_LeafGreen_FishingMonsInfo = { 20, sRoute19_LeafGreen_FishingMons };

const struct WildPokemon sRoute20_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute20_LeafGreen_WaterMonsInfo = { 2, sRoute20_LeafGreen_WaterMons };

const struct WildPokemon sRoute20_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute20_LeafGreen_FishingMonsInfo = { 20, sRoute20_LeafGreen_FishingMons };

const struct WildPokemon sRoute21North_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_TANGELA },
    { 23, 23, SPECIES_TANGELA },
    { 24, 24, SPECIES_TANGELA },
    { 21, 21, SPECIES_TANGELA },
    { 25, 25, SPECIES_TANGELA },
    { 20, 20, SPECIES_TANGELA },
    { 19, 19, SPECIES_TANGELA },
    { 26, 26, SPECIES_TANGELA },
    { 18, 18, SPECIES_TANGELA },
    { 27, 27, SPECIES_TANGELA },
    { 17, 17, SPECIES_TANGELA },
    { 28, 28, SPECIES_TANGELA },
};

const struct WildPokemonInfo sRoute21North_LeafGreen_LandMonsInfo = { 14, sRoute21North_LeafGreen_LandMons };

const struct WildPokemon sRoute21North_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute21North_LeafGreen_WaterMonsInfo = { 2, sRoute21North_LeafGreen_WaterMons };

const struct WildPokemon sRoute21North_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute21North_LeafGreen_FishingMonsInfo = { 20, sRoute21North_LeafGreen_FishingMons };

const struct WildPokemon sRoute21South_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_TANGELA },
    { 23, 23, SPECIES_TANGELA },
    { 24, 24, SPECIES_TANGELA },
    { 21, 21, SPECIES_TANGELA },
    { 25, 25, SPECIES_TANGELA },
    { 20, 20, SPECIES_TANGELA },
    { 19, 19, SPECIES_TANGELA },
    { 26, 26, SPECIES_TANGELA },
    { 18, 18, SPECIES_TANGELA },
    { 27, 27, SPECIES_TANGELA },
    { 17, 17, SPECIES_TANGELA },
    { 28, 28, SPECIES_TANGELA },
};

const struct WildPokemonInfo sRoute21South_LeafGreen_LandMonsInfo = { 14, sRoute21South_LeafGreen_LandMons };

const struct WildPokemon sRoute21South_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute21South_LeafGreen_WaterMonsInfo = { 2, sRoute21South_LeafGreen_WaterMons };

const struct WildPokemon sRoute21South_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute21South_LeafGreen_FishingMonsInfo = { 20, sRoute21South_LeafGreen_FishingMons };

const struct WildPokemon sRoute22_LeafGreen_LandMons[] =
{
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_MANKEY },
    { 4, 4, SPECIES_RATTATA },
    { 4, 4, SPECIES_MANKEY },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_MANKEY },
    { 3, 3, SPECIES_SPEAROW },
    { 5, 5, SPECIES_SPEAROW },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_MANKEY },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_MANKEY },
};

const struct WildPokemonInfo sRoute22_LeafGreen_LandMonsInfo = { 21, sRoute22_LeafGreen_LandMons };

const struct WildPokemon sRoute22_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute22_LeafGreen_WaterMonsInfo = { 2, sRoute22_LeafGreen_WaterMons };

const struct WildPokemon sRoute22_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute22_LeafGreen_FishingMonsInfo = { 20, sRoute22_LeafGreen_FishingMons };

const struct WildPokemon sRoute23_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_MANKEY },
    { 40, 40, SPECIES_FEAROW },
    { 34, 34, SPECIES_MANKEY },
    { 34, 34, SPECIES_SPEAROW },
    { 32, 32, SPECIES_SANDSHREW },
    { 34, 34, SPECIES_SANDSHREW },
    { 42, 42, SPECIES_PRIMEAPE },
    { 44, 44, SPECIES_SANDSLASH },
    { 32, 32, SPECIES_SPEAROW },
    { 42, 42, SPECIES_FEAROW },
    { 32, 32, SPECIES_SPEAROW },
    { 44, 44, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute23_LeafGreen_LandMonsInfo = { 21, sRoute23_LeafGreen_LandMons };

const struct WildPokemon sRoute23_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute23_LeafGreen_WaterMonsInfo = { 2, sRoute23_LeafGreen_WaterMons };

const struct WildPokemon sRoute23_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute23_LeafGreen_FishingMonsInfo = { 20, sRoute23_LeafGreen_FishingMons };

const struct WildPokemon sRoute24_LeafGreen_LandMons[] =
{
    { 7, 7, SPECIES_WEEDLE },
    { 7, 7, SPECIES_CATERPIE },
    { 11, 11, SPECIES_PIDGEY },
    { 12, 12, SPECIES_BELLSPROUT },
    { 13, 13, SPECIES_BELLSPROUT },
    { 10, 10, SPECIES_ABRA },
    { 13, 13, SPECIES_PIDGEY },
    { 14, 14, SPECIES_BELLSPROUT },
    { 8, 8, SPECIES_METAPOD },
    { 8, 8, SPECIES_ABRA },
    { 8, 8, SPECIES_SQUIRTLE },
    { 12, 12, SPECIES_ABRA },
};

const struct WildPokemonInfo sRoute24_LeafGreen_LandMonsInfo = { 21, sRoute24_LeafGreen_LandMons };

const struct WildPokemon sRoute24_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute24_LeafGreen_WaterMonsInfo = { 2, sRoute24_LeafGreen_WaterMons };

const struct WildPokemon sRoute24_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute24_LeafGreen_FishingMonsInfo = { 20, sRoute24_LeafGreen_FishingMons };

const struct WildPokemon sRoute25_LeafGreen_LandMons[] =
{
    { 8, 8, SPECIES_WEEDLE },
    { 8, 8, SPECIES_CATERPIE },
    { 13, 13, SPECIES_PIDGEY },
    { 14, 14, SPECIES_BELLSPROUT },
    { 13, 13, SPECIES_BELLSPROUT },
    { 11, 11, SPECIES_ABRA },
    { 11, 11, SPECIES_PIDGEY },
    { 12, 12, SPECIES_BELLSPROUT },
    { 9, 9, SPECIES_METAPOD },
    { 9, 9, SPECIES_ABRA },
    { 9, 9, SPECIES_KAKUNA },
    { 13, 13, SPECIES_ABRA },
};

const struct WildPokemonInfo sRoute25_LeafGreen_LandMonsInfo = { 21, sRoute25_LeafGreen_LandMons };

const struct WildPokemon sRoute25_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute25_LeafGreen_WaterMonsInfo = { 2, sRoute25_LeafGreen_WaterMons };

const struct WildPokemon sRoute25_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute25_LeafGreen_FishingMonsInfo = { 20, sRoute25_LeafGreen_FishingMons };

const struct WildPokemon sPalletTown_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sPalletTown_LeafGreen_WaterMonsInfo = { 1, sPalletTown_LeafGreen_WaterMons };

const struct WildPokemon sPalletTown_LeafGreen_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sPalletTown_LeafGreen_FishingMonsInfo = { 10, sPalletTown_LeafGreen_FishingMons };

const struct WildPokemon sViridianCity_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sViridianCity_LeafGreen_WaterMonsInfo = { 1, sViridianCity_LeafGreen_WaterMons };

const struct WildPokemon sViridianCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sViridianCity_LeafGreen_FishingMonsInfo = { 10, sViridianCity_LeafGreen_FishingMons };

const struct WildPokemon sCeruleanCity_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sCeruleanCity_LeafGreen_WaterMonsInfo = { 1, sCeruleanCity_LeafGreen_WaterMons };

const struct WildPokemon sCeruleanCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCeruleanCity_LeafGreen_FishingMonsInfo = { 10, sCeruleanCity_LeafGreen_FishingMons };

const struct WildPokemon sVermilionCity_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sVermilionCity_LeafGreen_WaterMonsInfo = { 1, sVermilionCity_LeafGreen_WaterMons };

const struct WildPokemon sVermilionCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sVermilionCity_LeafGreen_FishingMonsInfo = { 10, sVermilionCity_LeafGreen_FishingMons };

const struct WildPokemon sCeladonCity_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_SLOWPOKE },
    { 10, 20, SPECIES_SLOWPOKE },
    { 20, 30, SPECIES_SLOWPOKE },
    { 30, 40, SPECIES_SLOWPOKE },
    { 30, 40, SPECIES_KOFFING },
};

const struct WildPokemonInfo sCeladonCity_LeafGreen_WaterMonsInfo = { 1, sCeladonCity_LeafGreen_WaterMons };

const struct WildPokemon sCeladonCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 25, 35, SPECIES_MAGIKARP },
    { 30, 40, SPECIES_GRIMER },
};

const struct WildPokemonInfo sCeladonCity_LeafGreen_FishingMonsInfo = { 10, sCeladonCity_LeafGreen_FishingMons };

const struct WildPokemon sFuchsiaCity_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFuchsiaCity_LeafGreen_WaterMonsInfo = { 1, sFuchsiaCity_LeafGreen_WaterMons };

const struct WildPokemon sFuchsiaCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFuchsiaCity_LeafGreen_FishingMonsInfo = { 10, sFuchsiaCity_LeafGreen_FishingMons };

const struct WildPokemon sCinnabarIsland_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sCinnabarIsland_LeafGreen_WaterMonsInfo = { 1, sCinnabarIsland_LeafGreen_WaterMons };

const struct WildPokemon sCinnabarIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SLOWBRO },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCinnabarIsland_LeafGreen_FishingMonsInfo = { 10, sCinnabarIsland_LeafGreen_FishingMons };

const struct WildPokemon sOneIsland_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIsland_LeafGreen_WaterMonsInfo = { 1, sOneIsland_LeafGreen_WaterMons };

const struct WildPokemon sOneIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sOneIsland_LeafGreen_FishingMonsInfo = { 10, sOneIsland_LeafGreen_FishingMons };

const struct WildPokemon sFourIsland_LeafGreen_WaterMons[] =
{
    { 5, 15, SPECIES_MARILL },
    { 5, 35, SPECIES_SLOWPOKE },
    { 15, 25, SPECIES_MARILL },
    { 15, 25, SPECIES_MARILL },
    { 15, 25, SPECIES_MARILL },
};

const struct WildPokemonInfo sFourIsland_LeafGreen_WaterMonsInfo = { 2, sFourIsland_LeafGreen_WaterMons };

const struct WildPokemon sFourIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFourIsland_LeafGreen_FishingMonsInfo = { 20, sFourIsland_LeafGreen_FishingMons };

const struct WildPokemon sFiveIsland_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIsland_LeafGreen_WaterMonsInfo = { 1, sFiveIsland_LeafGreen_WaterMons };

const struct WildPokemon sFiveIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIsland_LeafGreen_FishingMonsInfo = { 10, sFiveIsland_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandAlteringCave_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 16, 16, SPECIES_ZUBAT },
    { 6, 6, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
};

const struct WildPokemonInfo sSixIslandAlteringCave_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_2_LeafGreen_LandMons[] =
{
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 13, 13, SPECIES_MAREEP },
    { 3, 3, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
};

const struct WildPokemonInfo sSixIslandAlteringCave_2_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_2_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_3_LeafGreen_LandMons[] =
{
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 22, 22, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 29, 29, SPECIES_PINECO },
    { 19, 19, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
};

const struct WildPokemonInfo sSixIslandAlteringCave_3_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_3_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_4_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 22, 22, SPECIES_HOUNDOUR },
    { 12, 12, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
};

const struct WildPokemonInfo sSixIslandAlteringCave_4_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_4_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_5_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_TEDDIURSA },
    { 24, 24, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
    { 22, 22, SPECIES_TEDDIURSA },
    { 24, 24, SPECIES_TEDDIURSA },
    { 28, 28, SPECIES_TEDDIURSA },
    { 18, 18, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
};

const struct WildPokemonInfo sSixIslandAlteringCave_5_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_5_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_6_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 28, 28, SPECIES_AIPOM },
    { 18, 18, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
};

const struct WildPokemonInfo sSixIslandAlteringCave_6_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_6_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_7_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 28, 28, SPECIES_SHUCKLE },
    { 18, 18, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo sSixIslandAlteringCave_7_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_7_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_8_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 28, 28, SPECIES_STANTLER },
    { 18, 18, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
};

const struct WildPokemonInfo sSixIslandAlteringCave_8_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_8_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_9_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 28, 28, SPECIES_SMEARGLE },
    { 18, 18, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo sSixIslandAlteringCave_9_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_9_LeafGreen_LandMons };

const struct WildPokemon sRoute20_Underwater_FireRed_LandMons[] =
{
    { 33, 36, SPECIES_TENTACOOL },
    { 25, 25, SPECIES_HORSEA },
    { 12, 14, SPECIES_KRABBY },
    { 15, 15, SPECIES_KRABBY },
    { 22, 23, SPECIES_HORSEA },
    { 36, 40, SPECIES_TENTACOOL },
    { 25, 25, SPECIES_GYARADOS },
    { 38, 40, SPECIES_TENTACOOL },
    { 33, 35, SPECIES_SEADRA },
    { 28, 30, SPECIES_SEADRA },
    { 31, 33, SPECIES_SEADRA },
    { 33, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute20_Underwater_FireRed_LandMonsInfo = { 7, sRoute20_Underwater_FireRed_LandMons };

const struct WildPokemon sRoute20_Underwater_LeafGreen_LandMons[] =
{
    { 33, 36, SPECIES_TENTACOOL },
    { 25, 25, SPECIES_KRABBY },
    { 12, 14, SPECIES_HORSEA },
    { 15, 15, SPECIES_HORSEA },
    { 22, 23, SPECIES_KRABBY },
    { 36, 40, SPECIES_TENTACOOL },
    { 25, 25, SPECIES_GYARADOS },
    { 38, 40, SPECIES_TENTACOOL },
    { 33, 35, SPECIES_KINGLER },
    { 28, 30, SPECIES_KINGLER },
    { 31, 33, SPECIES_KINGLER },
    { 33, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute20_Underwater_LeafGreen_LandMonsInfo = { 7, sRoute20_Underwater_LeafGreen_LandMons };

const struct WildPokemon sSafariZone_NorthWest_LandMons[] =
{
    { 33, 33, SPECIES_SUNKERN },
    { 34, 34, SPECIES_MAREEP },
    { 35, 35, SPECIES_SUNKERN },
    { 36, 36, SPECIES_MAREEP },
    { 34, 34, SPECIES_AIPOM },
    { 27, 27, SPECIES_GIRAFARIG },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_SNUBBULL },
    { 36, 36, SPECIES_STANTLER },
    { 37, 37, SPECIES_MILTANK },
    { 39, 39, SPECIES_STANTLER },
    { 40, 40, SPECIES_MILTANK },
};

const struct WildPokemonInfo sSafariZone_NorthWest_LandMonsInfo = { 25, sSafariZone_NorthWest_LandMons };

const struct WildPokemon sSafariZone_NorthWest_FireRed_WaterMons[] = // Wooper/Marill are FR/LG exclusive
{
    { 25, 30, SPECIES_WOOPER },
    { 25, 30, SPECIES_WOOPER },
    { 25, 30, SPECIES_WOOPER },
    { 25, 30, SPECIES_WOOPER },
    { 35, 40, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo sSafariZone_NorthWest_FireRed_WaterMonsInfo = { 9, sSafariZone_NorthWest_FireRed_WaterMons };

const struct WildPokemon sSafariZone_NorthWest_LeafGreen_WaterMons[] = // Wooper/Marill are FR/LG exclusive
{
    { 25, 30, SPECIES_MARILL },
    { 25, 30, SPECIES_MARILL },
    { 25, 30, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 33, 35, SPECIES_MARILL },
};

const struct WildPokemonInfo sSafariZone_NorthWest_LeafGreen_WaterMonsInfo = { 9, sSafariZone_NorthWest_LeafGreen_WaterMons };

const struct WildPokemon sSafariZone_NorthWest_FireRed_FishingMons[] = // Qwilfish/Remoraid are FR/LG exclusive, but Qwilfish isn't obtainable at Hoenn Safari Zone
{
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_SEAKING },
    { 30, 35, SPECIES_SEAKING },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
};

const struct WildPokemonInfo sSafariZone_NorthWest_FireRed_FishingMonsInfo = { 35, sSafariZone_NorthWest_FireRed_FishingMons };

const struct WildPokemon sSafariZone_NorthWest_LeafGreen_FishingMons[] = // Qwilfish/Remoraid are FR/LG exclusive, but Qwilfish isn't obtainable at Hoenn Safari Zone
{
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_REMORAID },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 35, 40, SPECIES_OCTILLERY },
};

const struct WildPokemonInfo sSafariZone_NorthWest_LeafGreen_FishingMonsInfo = { 35, sSafariZone_NorthWest_LeafGreen_FishingMons };

const struct WildPokemon sSafariZone_NorthWest_RockSmashMons[] =
{
    { 25, 30, SPECIES_SHUCKLE },
    { 20, 25, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 35, 40, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo sSafariZone_NorthWest_RockSmashMonsInfo = { 25, sSafariZone_NorthWest_RockSmashMons };

const struct WildPokemon sSafariZone_NorthEast_LandMons[] =
{
    { 33, 33, SPECIES_AIPOM },
    { 34, 34, SPECIES_TEDDIURSA },
    { 35, 35, SPECIES_AIPOM },
    { 36, 36, SPECIES_TEDDIURSA },
    { 34, 34, SPECIES_SUNKERN },
    { 27, 27, SPECIES_GIRAFARIG },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_PINECO },
    { 36, 36, SPECIES_HOUNDOUR },
    { 37, 37, SPECIES_GLIGAR },
    { 39, 39, SPECIES_HOUNDOUR },
    { 40, 40, SPECIES_GLIGAR },
};

const struct WildPokemonInfo sSafariZone_NorthEast_LandMonsInfo = { 25, sSafariZone_NorthEast_LandMons };

// ==================== SAFARI ZONE HOENN ====================

// --- NorthHoenn ---
const struct WildPokemon sSafariZone_NorthHoenn_LandMons[] =
{
    { 20, 30, SPECIES_ZIGZAGOON },  // slot 0 - 20%
    { 20, 30, SPECIES_TAILLOW },    // slot 1 - 20%
    { 20, 30, SPECIES_ROSELIA },    // slot 2 - 10%
    { 20, 30, SPECIES_ELECTRIKE },  // slot 3 - 10%
    { 20, 30, SPECIES_GULPIN },     // slot 4 - 10%
    { 20, 30, SPECIES_SLAKOTH },    // slot 5 - 10%
    { 20, 30, SPECIES_LOTAD },      // slot 6 - 5%
    { 20, 30, SPECIES_SEEDOT },     // slot 7 - 5%
    { 20, 30, SPECIES_PLUSLE },     // slot 8 - 4%
    { 20, 30, SPECIES_MINUN },      // slot 9 - 4%
    { 20, 30, SPECIES_SKITTY },     // slot 10 - 1%
    { 30, 40, SPECIES_KECLEON },    // slot 11 - 1%
};

const struct WildPokemonInfo sSafariZone_NorthHoenn_LandMonsInfo = { 25, sSafariZone_NorthHoenn_LandMons };

const struct WildPokemon sSafariZone_NorthHoenn_WaterMons[] =
{
    { 20, 30, SPECIES_WINGULL },   // slot 0 - 60%
    { 20, 30, SPECIES_WAILMER },   // slot 1 - 30%
    { 20, 30, SPECIES_SURSKIT },   // slot 2 - 5%
    { 30, 35, SPECIES_PELIPPER },  // slot 3 - 4%
    { 50, 60, SPECIES_WAILORD },   // slot 4 - 1%
};

const struct WildPokemonInfo sSafariZone_NorthHoenn_WaterMonsInfo = { 9, sSafariZone_NorthHoenn_WaterMons };

const struct WildPokemon sSafariZone_NorthHoenn_FishingMons[] =
{
    { 20, 30, SPECIES_CORPHISH },   // slot 0 - Vieille Canne 70%
    { 20, 30, SPECIES_CLAMPERL },   // slot 1 - Vieille Canne 30%
    { 20, 30, SPECIES_CORPHISH },   // slot 2 - Bonne Canne 60%
    { 20, 30, SPECIES_CLAMPERL },   // slot 3 - Bonne Canne 20%
    { 20, 30, SPECIES_BARBOACH },   // slot 4 - Bonne Canne 20%
    { 20, 30, SPECIES_CARVANHA },   // slot 5 - Super Canne 40%
    { 20, 30, SPECIES_LUVDISC },    // slot 6 - Super Canne 40%
    { 20, 30, SPECIES_CORSOLA },    // slot 7 - Super Canne 15%
    { 20, 30, SPECIES_RELICANTH },  // slot 8 - Super Canne 4%
    { 20, 30, SPECIES_FEEBAS },     // slot 9 - Super Canne 1%
};

const struct WildPokemonInfo sSafariZone_NorthHoenn_FishingMonsInfo = { 35, sSafariZone_NorthHoenn_FishingMons };

// --- HoennCave ---
const struct WildPokemon sSafariZone_HoennCave_LandMons[] =
{
    { 20, 30, SPECIES_WHISMUR },   // slot 0 - 20%
    { 20, 30, SPECIES_ARON },      // slot 1 - 20%
    { 20, 30, SPECIES_MAKUHITA },  // slot 2 - 10%
    { 20, 30, SPECIES_MEDITITE },  // slot 3 - 10%
    { 20, 30, SPECIES_NINCADA },   // slot 4 - 10%
    { 20, 30, SPECIES_NINCADA },   // slot 5 - 10%
    { 20, 30, SPECIES_LILEEP },    // slot 6 - 5%
    { 20, 30, SPECIES_ANORITH },   // slot 7 - 5%
    { 20, 30, SPECIES_MAWILE },    // slot 8 - 4%
    { 20, 34, SPECIES_NOSEPASS },  // slot 9 - 4%
    { 30, 35, SPECIES_BAGON },     // slot 10 - 1%
    { 30, 35, SPECIES_BELDUM },    // slot 11 - 1%
};

const struct WildPokemonInfo sSafariZone_HoennCave_LandMonsInfo = { 10, sSafariZone_HoennCave_LandMons };

// --- HoennCaveSand ---
const struct WildPokemon sSafariZone_HoennCaveSand_LandMons[] =
{
    { 20, 30, SPECIES_TRAPINCH },  // slot 0 - 20%
    { 20, 30, SPECIES_BALTOY },    // slot 1 - 20%
    { 20, 30, SPECIES_NUMEL },     // slot 2 - 10%
    { 20, 30, SPECIES_CACNEA },    // slot 3 - 10%
    { 20, 30, SPECIES_SPINDA },    // slot 4 - 10%
    { 20, 30, SPECIES_TORKOAL },   // slot 5 - 10%
    { 20, 30, SPECIES_LUNATONE },  // slot 6 - 5%
    { 20, 30, SPECIES_SOLROCK },   // slot 7 - 5%
    { 20, 30, SPECIES_SWABLU },    // slot 8 - 4%
    { 20, 30, SPECIES_SWABLU },    // slot 9 - 4%
    { 35, 40, SPECIES_SKARMORY },  // slot 10 - 1%
    { 35, 40, SPECIES_SKARMORY },  // slot 11 - 1%
};

const struct WildPokemonInfo sSafariZone_HoennCaveSand_LandMonsInfo = { 10, sSafariZone_HoennCaveSand_LandMons };

// --- HoennCaveGhost ---
const struct WildPokemon sSafariZone_HoennCaveGhost_LandMons[] =
{
    { 20, 30, SPECIES_SHUPPET },   // slot 0 - 20%
    { 20, 30, SPECIES_DUSKULL },   // slot 1 - 20%
    { 20, 30, SPECIES_POOCHYENA }, // slot 2 - 10%
    { 20, 30, SPECIES_SPOINK },    // slot 3 - 10%
    { 20, 30, SPECIES_CASTFORM },  // slot 4 - 10%
    { 20, 30, SPECIES_SABLEYE },   // slot 5 - 10%
    { 20, 30, SPECIES_SEVIPER },   // slot 6 - 5%
    { 20, 30, SPECIES_ZANGOOSE },  // slot 7 - 5%
    { 20, 35, SPECIES_ABSOL },     // slot 8 - 4%
    { 20, 35, SPECIES_CHIMECHO },  // slot 9 - 4%
    { 20, 30, SPECIES_RALTS },     // slot 10 - 1%
    { 20, 30, SPECIES_RALTS },     // slot 11 - 1%
};

const struct WildPokemonInfo sSafariZone_HoennCaveGhost_LandMonsInfo = { 10, sSafariZone_HoennCaveGhost_LandMons };

const struct WildPokemon sThreeIslandBondBridge_Underwater_LandMons[] =
{
    { 20, 20, SPECIES_CHINCHOU },
    { 20, 20, SPECIES_CHINCHOU },
    { 21, 21, SPECIES_CHINCHOU },
    { 22, 22, SPECIES_CHINCHOU },
    { 23, 23, SPECIES_CHINCHOU },
    { 24, 24, SPECIES_CHINCHOU },
    { 25, 25, SPECIES_CHINCHOU },
    { 26, 26, SPECIES_CHINCHOU },
    { 27, 27, SPECIES_CHINCHOU },
    { 28, 28, SPECIES_CHINCHOU },
    { 29, 29, SPECIES_CHINCHOU },
    { 30, 30, SPECIES_CHINCHOU },
};

const struct WildPokemonInfo sThreeIslandBondBridge_Underwater_LandMonsInfo = { 7, sThreeIslandBondBridge_Underwater_LandMons };

const struct WildPokemon sArtisanCave_LandMons[] =
{
    { 40, 40, SPECIES_SMEARGLE },
    { 41, 41, SPECIES_SMEARGLE },
    { 42, 42, SPECIES_SMEARGLE },
    { 43, 43, SPECIES_SMEARGLE },
    { 44, 44, SPECIES_SMEARGLE },
    { 45, 45, SPECIES_SMEARGLE },
    { 46, 46, SPECIES_SMEARGLE },
    { 47, 47, SPECIES_SMEARGLE },
    { 48, 48, SPECIES_SMEARGLE },
    { 49, 49, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo sArtisanCave_LandMonsInfo = { 10, sArtisanCave_LandMons };

const struct WildPokemon gLilycoveCity_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gLilycoveCity_WaterMonsInfo = { 4, gLilycoveCity_WaterMons };

const struct WildPokemon gLilycoveCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_STARYU },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gLilycoveCity_FishingMonsInfo = { 10, gLilycoveCity_FishingMons };

const struct WildPokemon gRoute121_LandMons[] =
{
    { 26, 26, SPECIES_POOCHYENA },
    { 26, 26, SPECIES_SHUPPET },
    { 26, 26, SPECIES_MIGHTYENA },
    { 28, 28, SPECIES_SHUPPET },
    { 28, 28, SPECIES_MIGHTYENA },
    { 26, 26, SPECIES_ODDISH },
    { 28, 28, SPECIES_ODDISH },
    { 28, 28, SPECIES_GLOOM },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo gRoute121_LandMonsInfo = { 20, gRoute121_LandMons };

const struct WildPokemon gRoute121_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute121_WaterMonsInfo = { 4, gRoute121_WaterMons };

const struct WildPokemon gRoute121_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute121_FishingMonsInfo = { 30, gRoute121_FishingMons };

const struct WildPokemon gRoute122_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute122_WaterMonsInfo = { 4, gRoute122_WaterMons };

const struct WildPokemon gRoute122_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute122_FishingMonsInfo = { 30, gRoute122_FishingMons };

const struct WildPokemon gRoute123_LandMons[] =
{
    { 26, 26, SPECIES_POOCHYENA },
    { 26, 26, SPECIES_SHUPPET },
    { 26, 26, SPECIES_MIGHTYENA },
    { 28, 28, SPECIES_SHUPPET },
    { 28, 28, SPECIES_MIGHTYENA },
    { 26, 26, SPECIES_ODDISH },
    { 28, 28, SPECIES_ODDISH },
    { 28, 28, SPECIES_GLOOM },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo gRoute123_LandMonsInfo = { 20, gRoute123_LandMons };

const struct WildPokemon gRoute123_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute123_WaterMonsInfo = { 4, gRoute123_WaterMons };

const struct WildPokemon gRoute123_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute123_FishingMonsInfo = { 30, gRoute123_FishingMons };

const struct WildPokemon gRoute120_LandMons[] =
{
    { 25, 25, SPECIES_POOCHYENA },
    { 25, 25, SPECIES_MIGHTYENA },
    { 27, 27, SPECIES_MIGHTYENA },
    { 25, 25, SPECIES_ODDISH },
    { 25, 25, SPECIES_MARILL },
    { 26, 26, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 27, 27, SPECIES_MARILL },
    { 25, 25, SPECIES_ABSOL },
    { 27, 27, SPECIES_ABSOL },
    { 25, 25, SPECIES_KECLEON },
    { 25, 25, SPECIES_SEEDOT },
};

const struct WildPokemonInfo gRoute120_LandMonsInfo = { 20, gRoute120_LandMons };

const struct WildPokemon gRoute120_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute120_WaterMonsInfo = { 4, gRoute120_WaterMons };

const struct WildPokemon gRoute120_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo gRoute120_FishingMonsInfo = { 30, gRoute120_FishingMons };

const struct WildPokemon gRoute119_LandMons[] =
{
    { 25, 25, SPECIES_ZIGZAGOON },
    { 25, 25, SPECIES_LINOONE },
    { 27, 27, SPECIES_ZIGZAGOON },
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_LINOONE },
    { 26, 26, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 24, 24, SPECIES_ODDISH },
    { 25, 25, SPECIES_TROPIUS },
    { 26, 26, SPECIES_TROPIUS },
    { 27, 27, SPECIES_TROPIUS },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo gRoute119_LandMonsInfo = { 15, gRoute119_LandMons };

const struct WildPokemon gRoute119_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute119_WaterMonsInfo = { 4, gRoute119_WaterMons };

const struct WildPokemon gRoute119_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_CARVANHA },
    { 25, 30, SPECIES_CARVANHA },
    { 30, 35, SPECIES_CARVANHA },
    { 20, 25, SPECIES_CARVANHA },
    { 35, 40, SPECIES_CARVANHA },
    { 40, 45, SPECIES_CARVANHA },
};

const struct WildPokemonInfo gRoute119_FishingMonsInfo = { 30, gRoute119_FishingMons };

const struct WildPokemon gEverGrandeCity_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gEverGrandeCity_WaterMonsInfo = { 4, gEverGrandeCity_WaterMons };

const struct WildPokemon gEverGrandeCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_LUVDISC },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_LUVDISC },
    { 30, 35, SPECIES_WAILMER },
    { 30, 35, SPECIES_CORSOLA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gEverGrandeCity_FishingMonsInfo = { 10, gEverGrandeCity_FishingMons };

const struct WildPokemon gRoute131_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute131_WaterMonsInfo = { 4, gRoute131_WaterMons };

const struct WildPokemon gRoute131_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute131_FishingMonsInfo = { 30, gRoute131_FishingMons };

const struct WildPokemon gPacifidlogTown_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gPacifidlogTown_WaterMonsInfo = { 4, gPacifidlogTown_WaterMons };

const struct WildPokemon gPacifidlogTown_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gPacifidlogTown_FishingMonsInfo = { 10, gPacifidlogTown_FishingMons };

const struct WildPokemon gRoute132_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute132_WaterMonsInfo = { 4, gRoute132_WaterMons };

const struct WildPokemon gRoute132_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute132_FishingMonsInfo = { 30, gRoute132_FishingMons };

const struct WildPokemon gRoute133_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute133_WaterMonsInfo = { 4, gRoute133_WaterMons };

const struct WildPokemon gRoute133_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute133_FishingMonsInfo = { 30, gRoute133_FishingMons };

const struct WildPokemon gRoute134_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute134_WaterMonsInfo = { 4, gRoute134_WaterMons };

const struct WildPokemon gRoute134_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute134_FishingMonsInfo = { 30, gRoute134_FishingMons };

const struct WildPokemon gRoute113_LandMons[] =
{
    { 15, 15, SPECIES_SPINDA },
    { 15, 15, SPECIES_SPINDA },
    { 15, 15, SPECIES_SLUGMA },
    { 14, 14, SPECIES_SPINDA },
    { 14, 14, SPECIES_SPINDA },
    { 14, 14, SPECIES_SLUGMA },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SLUGMA },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SKARMORY },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SKARMORY },
};

const struct WildPokemonInfo gRoute113_LandMonsInfo = { 20, gRoute113_LandMons };

const struct WildPokemon gRoute114_LandMons[] =
{
    { 16, 16, SPECIES_SWABLU },
    { 16, 16, SPECIES_LOTAD },
    { 17, 17, SPECIES_SWABLU },
    { 15, 15, SPECIES_SWABLU },
    { 15, 15, SPECIES_LOTAD },
    { 16, 16, SPECIES_LOMBRE },
    { 16, 16, SPECIES_LOMBRE },
    { 18, 18, SPECIES_LOMBRE },
    { 17, 17, SPECIES_SEVIPER },
    { 15, 15, SPECIES_SEVIPER },
    { 17, 17, SPECIES_SEVIPER },
    { 15, 15, SPECIES_NUZLEAF },
};

const struct WildPokemonInfo gRoute114_LandMonsInfo = { 20, gRoute114_LandMons };

const struct WildPokemon gRoute114_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute114_WaterMonsInfo = { 4, gRoute114_WaterMons };

const struct WildPokemon gRoute114_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gRoute114_RockSmashMonsInfo = { 20, gRoute114_RockSmashMons };

const struct WildPokemon gRoute114_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo gRoute114_FishingMonsInfo = { 30, gRoute114_FishingMons };

const struct WildPokemon gRoute115_LandMons[] =
{
    { 23, 23, SPECIES_SWABLU },
    { 23, 23, SPECIES_TAILLOW },
    { 25, 25, SPECIES_SWABLU },
    { 24, 24, SPECIES_TAILLOW },
    { 25, 25, SPECIES_TAILLOW },
    { 25, 25, SPECIES_SWELLOW },
    { 24, 24, SPECIES_JIGGLYPUFF },
    { 25, 25, SPECIES_JIGGLYPUFF },
    { 24, 24, SPECIES_WINGULL },
    { 24, 24, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 25, 25, SPECIES_WINGULL },
};

const struct WildPokemonInfo gRoute115_LandMonsInfo = { 20, gRoute115_LandMons };

const struct WildPokemon gRoute115_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute115_WaterMonsInfo = { 4, gRoute115_WaterMons };

const struct WildPokemon gRoute115_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute115_FishingMonsInfo = { 30, gRoute115_FishingMons };

const struct WildPokemon gRoute116_LandMons[] =
{
    { 6, 6, SPECIES_POOCHYENA },
    { 6, 6, SPECIES_WHISMUR },
    { 6, 6, SPECIES_NINCADA },
    { 7, 7, SPECIES_ABRA },
    { 7, 7, SPECIES_NINCADA },
    { 6, 6, SPECIES_TAILLOW },
    { 7, 7, SPECIES_TAILLOW },
    { 8, 8, SPECIES_TAILLOW },
    { 7, 7, SPECIES_POOCHYENA },
    { 8, 8, SPECIES_POOCHYENA },
    { 7, 7, SPECIES_SKITTY },
    { 8, 8, SPECIES_SKITTY },
};

const struct WildPokemonInfo gRoute116_LandMonsInfo = { 20, gRoute116_LandMons };

const struct WildPokemon gRoute104_LandMons[] =
{
    { 4, 4, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_WURMPLE },
    { 5, 5, SPECIES_POOCHYENA },
    { 5, 5, SPECIES_MARILL },
    { 4, 4, SPECIES_MARILL },
    { 5, 5, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_TAILLOW },
    { 5, 5, SPECIES_TAILLOW },
    { 4, 4, SPECIES_WINGULL },
    { 4, 4, SPECIES_WINGULL },
    { 3, 3, SPECIES_WINGULL },
    { 5, 5, SPECIES_WINGULL },
};

const struct WildPokemonInfo gRoute104_LandMonsInfo = { 20, gRoute104_LandMons };

const struct WildPokemon gRoute104_WaterMons[] =
{
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute104_WaterMonsInfo = { 4, gRoute104_WaterMons };

const struct WildPokemon gRoute104_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 20, 25, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_MAGIKARP },
    { 40, 45, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute104_FishingMonsInfo = { 30, gRoute104_FishingMons };

const struct WildPokemon gRoute105_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute105_WaterMonsInfo = { 4, gRoute105_WaterMons };

const struct WildPokemon gRoute105_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute105_FishingMonsInfo = { 30, gRoute105_FishingMons };

const struct WildPokemon gRoute106_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute106_WaterMonsInfo = { 4, gRoute106_WaterMons };

const struct WildPokemon gRoute106_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute106_FishingMonsInfo = { 30, gRoute106_FishingMons };

const struct WildPokemon gDewfordTown_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gDewfordTown_WaterMonsInfo = { 4, gDewfordTown_WaterMons };

const struct WildPokemon gDewfordTown_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gDewfordTown_FishingMonsInfo = { 10, gDewfordTown_FishingMons };

const struct WildPokemon gRoute107_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute107_WaterMonsInfo = { 4, gRoute107_WaterMons };

const struct WildPokemon gRoute107_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute107_FishingMonsInfo = { 30, gRoute107_FishingMons };

const struct WildPokemon gPetalburgCity_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
};

const struct WildPokemonInfo gPetalburgCity_WaterMonsInfo = { 1, gPetalburgCity_WaterMons };

const struct WildPokemon gPetalburgCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo gPetalburgCity_FishingMonsInfo = { 10, gPetalburgCity_FishingMons };

const struct WildPokemon gRoute102_LandMons[] =
{
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_WURMPLE },
    { 4, 4, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_WURMPLE },
    { 3, 3, SPECIES_LOTAD },
    { 4, 4, SPECIES_LOTAD },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_RALTS },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_SEEDOT },
};

const struct WildPokemonInfo gRoute102_LandMonsInfo = { 20, gRoute102_LandMons };

const struct WildPokemon gRoute102_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute102_WaterMonsInfo = { 4, gRoute102_WaterMons };

const struct WildPokemon gRoute102_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo gRoute102_FishingMonsInfo = { 30, gRoute102_FishingMons };

const struct WildPokemon gRoute101_LandMons[] =
{
    { 2, 2, SPECIES_WURMPLE },
    { 2, 2, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_WURMPLE },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_ZIGZAGOON },
    { 2, 2, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
};

const struct WildPokemonInfo gRoute101_LandMonsInfo = { 20, gRoute101_LandMons };

const struct WildPokemon gRoute103_LandMons[] =
{
    { 2, 2, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_WINGULL },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_WINGULL },
    { 3, 3, SPECIES_WINGULL },
    { 2, 2, SPECIES_WINGULL },
    { 4, 4, SPECIES_WINGULL },
};

const struct WildPokemonInfo gRoute103_LandMonsInfo = { 20, gRoute103_LandMons };

const struct WildPokemon gRoute103_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute103_WaterMonsInfo = { 4, gRoute103_WaterMons };

const struct WildPokemon gRoute103_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute103_FishingMonsInfo = { 30, gRoute103_FishingMons };

const struct WildPokemon gRoute118_LandMons[] =
{
    { 24, 24, SPECIES_ZIGZAGOON },
    { 24, 24, SPECIES_ELECTRIKE },
    { 26, 26, SPECIES_ZIGZAGOON },
    { 26, 26, SPECIES_ELECTRIKE },
    { 26, 26, SPECIES_LINOONE },
    { 26, 26, SPECIES_MANECTRIC },
    { 25, 25, SPECIES_WINGULL },
    { 25, 25, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo gRoute118_LandMonsInfo = { 20, gRoute118_LandMons };

const struct WildPokemon gRoute118_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute118_WaterMonsInfo = { 4, gRoute118_WaterMons };

const struct WildPokemon gRoute118_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_CARVANHA },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_CARVANHA },
    { 20, 25, SPECIES_CARVANHA },
    { 35, 40, SPECIES_CARVANHA },
    { 40, 45, SPECIES_CARVANHA },
};

const struct WildPokemonInfo gRoute118_FishingMonsInfo = { 30, gRoute118_FishingMons };

const struct WildPokemon gRoute124_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute124_WaterMonsInfo = { 4, gRoute124_WaterMons };

const struct WildPokemon gRoute124_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute124_FishingMonsInfo = { 30, gRoute124_FishingMons };

const struct WildPokemon gMossdeepCity_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gMossdeepCity_WaterMonsInfo = { 4, gMossdeepCity_WaterMons };

const struct WildPokemon gMossdeepCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gMossdeepCity_FishingMonsInfo = { 10, gMossdeepCity_FishingMons };

const struct WildPokemon gRoute125_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute125_WaterMonsInfo = { 4, gRoute125_WaterMons };

const struct WildPokemon gRoute125_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute125_FishingMonsInfo = { 30, gRoute125_FishingMons };

const struct WildPokemon gRoute127_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute127_WaterMonsInfo = { 4, gRoute127_WaterMons };

const struct WildPokemon gRoute127_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute127_FishingMonsInfo = { 30, gRoute127_FishingMons };

const struct WildPokemon gRoute128_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute128_WaterMonsInfo = { 4, gRoute128_WaterMons };

const struct WildPokemon gRoute128_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_LUVDISC },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_LUVDISC },
    { 30, 35, SPECIES_WAILMER },
    { 30, 35, SPECIES_CORSOLA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute128_FishingMonsInfo = { 30, gRoute128_FishingMons };

const struct WildPokemon gRoute126_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute126_WaterMonsInfo = { 4, gRoute126_WaterMons };

const struct WildPokemon gRoute126_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute126_FishingMonsInfo = { 30, gRoute126_FishingMons };

const struct WildPokemon gRoute129_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_WAILORD },
};

const struct WildPokemonInfo gRoute129_WaterMonsInfo = { 4, gRoute129_WaterMons };

const struct WildPokemon gRoute129_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute129_FishingMonsInfo = { 30, gRoute129_FishingMons };

const struct WildPokemon gRoute130_LandMons[] =
{
    { 30, 30, SPECIES_WYNAUT },
    { 35, 35, SPECIES_WYNAUT },
    { 25, 25, SPECIES_WYNAUT },
    { 40, 40, SPECIES_WYNAUT },
    { 20, 20, SPECIES_WYNAUT },
    { 45, 45, SPECIES_WYNAUT },
    { 15, 15, SPECIES_WYNAUT },
    { 50, 50, SPECIES_WYNAUT },
    { 10, 10, SPECIES_WYNAUT },
    { 5, 5, SPECIES_WYNAUT },
    { 10, 10, SPECIES_WYNAUT },
    { 5, 5, SPECIES_WYNAUT },
};

const struct WildPokemonInfo gRoute130_LandMonsInfo = { 20, gRoute130_LandMons };

const struct WildPokemon gRoute130_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute130_WaterMonsInfo = { 4, gRoute130_WaterMons };

const struct WildPokemon gRoute130_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute130_FishingMonsInfo = { 30, gRoute130_FishingMons };

const struct WildPokemon gRoute117_LandMons[] =
{
    { 13, 13, SPECIES_POOCHYENA },
    { 13, 13, SPECIES_ODDISH },
    { 14, 14, SPECIES_POOCHYENA },
    { 14, 14, SPECIES_ODDISH },
    { 13, 13, SPECIES_MARILL },
    { 13, 13, SPECIES_ODDISH },
    { 13, 13, SPECIES_ILLUMISE },
    { 13, 13, SPECIES_ILLUMISE },
    { 14, 14, SPECIES_ILLUMISE },
    { 14, 14, SPECIES_ILLUMISE },
    { 13, 13, SPECIES_VOLBEAT },
    { 13, 13, SPECIES_SEEDOT },
};

const struct WildPokemonInfo gRoute117_LandMonsInfo = { 20, gRoute117_LandMons };

const struct WildPokemon gRoute117_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute117_WaterMonsInfo = { 4, gRoute117_WaterMons };

const struct WildPokemon gRoute117_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo gRoute117_FishingMonsInfo = { 30, gRoute117_FishingMons };

const struct WildPokemon gRoute110_LandMons[] =
{
    { 12, 12, SPECIES_POOCHYENA },
    { 12, 12, SPECIES_ELECTRIKE },
    { 12, 12, SPECIES_GULPIN },
    { 13, 13, SPECIES_ELECTRIKE },
    { 13, 13, SPECIES_MINUN },
    { 13, 13, SPECIES_ODDISH },
    { 13, 13, SPECIES_MINUN },
    { 13, 13, SPECIES_GULPIN },
    { 12, 12, SPECIES_WINGULL },
    { 12, 12, SPECIES_WINGULL },
    { 12, 12, SPECIES_PLUSLE },
    { 13, 13, SPECIES_PLUSLE },
};

const struct WildPokemonInfo gRoute110_LandMonsInfo = { 20, gRoute110_LandMons };

const struct WildPokemon gRoute110_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute110_WaterMonsInfo = { 4, gRoute110_WaterMons };

const struct WildPokemon gRoute110_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute110_FishingMonsInfo = { 30, gRoute110_FishingMons };

const struct WildPokemon gRoute111_LandMons[] =
{
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 19, 19, SPECIES_BALTOY },
    { 21, 21, SPECIES_BALTOY },
    { 19, 19, SPECIES_SANDSHREW },
    { 19, 19, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_BALTOY },
    { 20, 20, SPECIES_CACNEA },
    { 22, 22, SPECIES_CACNEA },
    { 22, 22, SPECIES_CACNEA },
};

const struct WildPokemonInfo gRoute111_LandMonsInfo = { 10, gRoute111_LandMons };

const struct WildPokemon gRoute111_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute111_WaterMonsInfo = { 4, gRoute111_WaterMons };

const struct WildPokemon gRoute111_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gRoute111_RockSmashMonsInfo = { 20, gRoute111_RockSmashMons };

const struct WildPokemon gRoute111_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo gRoute111_FishingMonsInfo = { 30, gRoute111_FishingMons };

const struct WildPokemon gRoute112_LandMons[] =
{
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_MARILL },
    { 14, 14, SPECIES_NUMEL },
    { 14, 14, SPECIES_NUMEL },
    { 14, 14, SPECIES_MARILL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_MARILL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
};

const struct WildPokemonInfo gRoute112_LandMonsInfo = { 20, gRoute112_LandMons };

const struct WildPokemon gRoute108_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute108_WaterMonsInfo = { 4, gRoute108_WaterMons };

const struct WildPokemon gRoute108_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute108_FishingMonsInfo = { 30, gRoute108_FishingMons };

const struct WildPokemon gRoute109_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute109_WaterMonsInfo = { 4, gRoute109_WaterMons };

const struct WildPokemon gRoute109_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute109_FishingMonsInfo = { 30, gRoute109_FishingMons };

const struct WildPokemon gSlateportCity_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gSlateportCity_WaterMonsInfo = { 4, gSlateportCity_WaterMons };

const struct WildPokemon gSlateportCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gSlateportCity_FishingMonsInfo = { 10, gSlateportCity_FishingMons };

const struct WildPokemon gSootopolisCity_WaterMons[] =
{
    { 5, 35, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gSootopolisCity_WaterMonsInfo = { 1, gSootopolisCity_WaterMons };

const struct WildPokemon gSootopolisCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_GYARADOS },
    { 35, 45, SPECIES_GYARADOS },
    { 5, 45, SPECIES_GYARADOS },
};

const struct WildPokemonInfo gSootopolisCity_FishingMonsInfo = { 10, gSootopolisCity_FishingMons };

const struct WildPokemon gUnderwater_Route124_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_RELICANTH },
};

const struct WildPokemonInfo gUnderwater_Route124_WaterMonsInfo = { 4, gUnderwater_Route124_WaterMons };

const struct WildPokemon gUnderwater_Route126_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_RELICANTH },
};

const struct WildPokemonInfo gUnderwater_Route126_WaterMonsInfo = { 4, gUnderwater_Route126_WaterMons };

const struct WildPokemon gPetalburgWoods_LandMons[] =
{
    { 5, 5, SPECIES_POOCHYENA },
    { 5, 5, SPECIES_WURMPLE },
    { 5, 5, SPECIES_SHROOMISH },
    { 6, 6, SPECIES_POOCHYENA },
    { 5, 5, SPECIES_SILCOON },
    { 5, 5, SPECIES_CASCOON },
    { 6, 6, SPECIES_WURMPLE },
    { 6, 6, SPECIES_SHROOMISH },
    { 5, 5, SPECIES_TAILLOW },
    { 5, 5, SPECIES_SLAKOTH },
    { 6, 6, SPECIES_TAILLOW },
    { 6, 6, SPECIES_SLAKOTH },
};

const struct WildPokemonInfo gPetalburgWoods_LandMonsInfo = { 20, gPetalburgWoods_LandMons };

const struct WildPokemon gRusturfTunnel_LandMons[] =
{
    { 6, 6, SPECIES_WHISMUR },
    { 7, 7, SPECIES_WHISMUR },
    { 6, 6, SPECIES_WHISMUR },
    { 6, 6, SPECIES_WHISMUR },
    { 7, 7, SPECIES_WHISMUR },
    { 7, 7, SPECIES_WHISMUR },
    { 5, 5, SPECIES_WHISMUR },
    { 8, 8, SPECIES_WHISMUR },
    { 5, 5, SPECIES_WHISMUR },
    { 8, 8, SPECIES_WHISMUR },
    { 5, 5, SPECIES_WHISMUR },
    { 8, 8, SPECIES_WHISMUR },
};

const struct WildPokemonInfo gRusturfTunnel_LandMonsInfo = { 10, gRusturfTunnel_LandMons };

const struct WildPokemon gGraniteCave_1F_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ABRA },
    { 10, 10, SPECIES_MAKUHITA },
    { 6, 6, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_GEODUDE },
    { 8, 8, SPECIES_GEODUDE },
    { 6, 6, SPECIES_GEODUDE },
    { 9, 9, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gGraniteCave_1F_LandMonsInfo = { 10, gGraniteCave_1F_LandMons };

const struct WildPokemon gGraniteCave_B1F_LandMons[] =
{
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ARON },
    { 9, 9, SPECIES_ARON },
    { 11, 11, SPECIES_ARON },
    { 10, 10, SPECIES_ZUBAT },
    { 9, 9, SPECIES_ABRA },
    { 10, 10, SPECIES_MAKUHITA },
    { 11, 11, SPECIES_MAKUHITA },
    { 10, 10, SPECIES_SABLEYE },
    { 10, 10, SPECIES_SABLEYE },
    { 9, 9, SPECIES_SABLEYE },
    { 11, 11, SPECIES_SABLEYE },
};

const struct WildPokemonInfo gGraniteCave_B1F_LandMonsInfo = { 10, gGraniteCave_B1F_LandMons };

const struct WildPokemon gGraniteCave_B2F_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ARON },
    { 10, 10, SPECIES_ARON },
    { 11, 11, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ARON },
    { 10, 10, SPECIES_ABRA },
    { 10, 10, SPECIES_SABLEYE },
    { 11, 11, SPECIES_SABLEYE },
    { 12, 12, SPECIES_SABLEYE },
    { 10, 10, SPECIES_SABLEYE },
    { 12, 12, SPECIES_SABLEYE },
    { 10, 10, SPECIES_SABLEYE },
};

const struct WildPokemonInfo gGraniteCave_B2F_LandMonsInfo = { 10, gGraniteCave_B2F_LandMons };

const struct WildPokemon gGraniteCave_B2F_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 10, 20, SPECIES_NOSEPASS },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gGraniteCave_B2F_RockSmashMonsInfo = { 20, gGraniteCave_B2F_RockSmashMons };

const struct WildPokemon gGraniteCave_StevensRoom_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ABRA },
    { 10, 10, SPECIES_MAKUHITA },
    { 6, 6, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_ARON },
    { 8, 8, SPECIES_ARON },
    { 7, 7, SPECIES_ARON },
    { 8, 8, SPECIES_ARON },
};

const struct WildPokemonInfo gGraniteCave_StevensRoom_LandMonsInfo = { 10, gGraniteCave_StevensRoom_LandMons };

const struct WildPokemon gMeteorFalls_B1F_2R_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 30, 30, SPECIES_BAGON },
    { 35, 35, SPECIES_SOLROCK },
    { 35, 35, SPECIES_BAGON },
    { 37, 37, SPECIES_SOLROCK },
    { 25, 25, SPECIES_BAGON },
    { 39, 39, SPECIES_SOLROCK },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gMeteorFalls_B1F_2R_LandMonsInfo = { 10, gMeteorFalls_B1F_2R_LandMons };

const struct WildPokemon gMeteorFalls_B1F_2R_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_B1F_2R_WaterMonsInfo = { 4, gMeteorFalls_B1F_2R_WaterMons };

const struct WildPokemon gMeteorFalls_B1F_2R_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo gMeteorFalls_B1F_2R_FishingMonsInfo = { 30, gMeteorFalls_B1F_2R_FishingMons };

const struct WildPokemon gMeteorFalls_1F_1R_LandMons[] =
{
    { 16, 16, SPECIES_ZUBAT },
    { 17, 17, SPECIES_ZUBAT },
    { 18, 18, SPECIES_ZUBAT },
    { 15, 15, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 16, 16, SPECIES_SOLROCK },
    { 18, 18, SPECIES_SOLROCK },
    { 14, 14, SPECIES_SOLROCK },
    { 19, 19, SPECIES_ZUBAT },
    { 20, 20, SPECIES_ZUBAT },
    { 19, 19, SPECIES_ZUBAT },
    { 20, 20, SPECIES_ZUBAT },
};

const struct WildPokemonInfo gMeteorFalls_1F_1R_LandMonsInfo = { 10, gMeteorFalls_1F_1R_LandMons };

const struct WildPokemon gMeteorFalls_1F_1R_WaterMons[] =
{
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_1F_1R_WaterMonsInfo = { 4, gMeteorFalls_1F_1R_WaterMons };

const struct WildPokemon gMeteorFalls_1F_1R_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo gMeteorFalls_1F_1R_FishingMonsInfo = { 30, gMeteorFalls_1F_1R_FishingMons };

const struct WildPokemon gMeteorFalls_1F_2R_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_SOLROCK },
    { 33, 33, SPECIES_SOLROCK },
    { 37, 37, SPECIES_SOLROCK },
    { 35, 35, SPECIES_GOLBAT },
    { 39, 39, SPECIES_SOLROCK },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gMeteorFalls_1F_2R_LandMonsInfo = { 10, gMeteorFalls_1F_2R_LandMons };

const struct WildPokemon gMeteorFalls_1F_2R_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_1F_2R_WaterMonsInfo = { 4, gMeteorFalls_1F_2R_WaterMons };

const struct WildPokemon gMeteorFalls_1F_2R_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo gMeteorFalls_1F_2R_FishingMonsInfo = { 30, gMeteorFalls_1F_2R_FishingMons };

const struct WildPokemon gMeteorFalls_B1F_1R_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_SOLROCK },
    { 33, 33, SPECIES_SOLROCK },
    { 37, 37, SPECIES_SOLROCK },
    { 35, 35, SPECIES_GOLBAT },
    { 39, 39, SPECIES_SOLROCK },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gMeteorFalls_B1F_1R_LandMonsInfo = { 10, gMeteorFalls_B1F_1R_LandMons };

const struct WildPokemon gMeteorFalls_B1F_1R_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_B1F_1R_WaterMonsInfo = { 4, gMeteorFalls_B1F_1R_WaterMons };

const struct WildPokemon gMeteorFalls_B1F_1R_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo gMeteorFalls_B1F_1R_FishingMonsInfo = { 30, gMeteorFalls_B1F_1R_FishingMons };

const struct WildPokemon gMeteorFalls_StevensCave_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_SOLROCK },
    { 33, 33, SPECIES_SOLROCK },
    { 37, 37, SPECIES_SOLROCK },
    { 35, 35, SPECIES_GOLBAT },
    { 39, 39, SPECIES_SOLROCK },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gMeteorFalls_StevensCave_LandMonsInfo = { 10, gMeteorFalls_StevensCave_LandMons };

const struct WildPokemon gJaggedPass_LandMons[] =
{
    { 21, 21, SPECIES_NUMEL },
    { 21, 21, SPECIES_NUMEL },
    { 21, 21, SPECIES_MACHOP },
    { 20, 20, SPECIES_NUMEL },
    { 20, 20, SPECIES_SPOINK },
    { 20, 20, SPECIES_MACHOP },
    { 21, 21, SPECIES_SPOINK },
    { 22, 22, SPECIES_MACHOP },
    { 22, 22, SPECIES_NUMEL },
    { 22, 22, SPECIES_SPOINK },
    { 22, 22, SPECIES_NUMEL },
    { 22, 22, SPECIES_SPOINK },
};

const struct WildPokemonInfo gJaggedPass_LandMonsInfo = { 20, gJaggedPass_LandMons };

const struct WildPokemon gFieryPath_LandMons[] =
{
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_KOFFING },
    { 16, 16, SPECIES_NUMEL },
    { 15, 15, SPECIES_MACHOP },
    { 15, 15, SPECIES_TORKOAL },
    { 15, 15, SPECIES_SLUGMA },
    { 16, 16, SPECIES_KOFFING },
    { 16, 16, SPECIES_MACHOP },
    { 14, 14, SPECIES_TORKOAL },
    { 16, 16, SPECIES_TORKOAL },
    { 14, 14, SPECIES_GRIMER },
    { 14, 14, SPECIES_GRIMER },
};

const struct WildPokemonInfo gFieryPath_LandMonsInfo = { 10, gFieryPath_LandMons };

const struct WildPokemon gMagmaHideout_1F_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_1F_LandMonsInfo = { 10, gMagmaHideout_1F_LandMons };

const struct WildPokemon gMagmaHideout_2F_1R_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_2F_1R_LandMonsInfo = { 10, gMagmaHideout_2F_1R_LandMons };

const struct WildPokemon gMagmaHideout_2F_2R_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_2F_2R_LandMonsInfo = { 10, gMagmaHideout_2F_2R_LandMons };

const struct WildPokemon gMagmaHideout_3F_1R_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_3F_1R_LandMonsInfo = { 10, gMagmaHideout_3F_1R_LandMons };

const struct WildPokemon gMagmaHideout_3F_2R_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_3F_2R_LandMonsInfo = { 10, gMagmaHideout_3F_2R_LandMons };

const struct WildPokemon gMagmaHideout_4F_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_4F_LandMonsInfo = { 10, gMagmaHideout_4F_LandMons };

const struct WildPokemon gMagmaHideout_3F_3R_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_3F_3R_LandMonsInfo = { 10, gMagmaHideout_3F_3R_LandMons };

const struct WildPokemon gMagmaHideout_2F_3R_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_2F_3R_LandMonsInfo = { 10, gMagmaHideout_2F_3R_LandMons };

const struct WildPokemon gNewMauville_Inside_LandMons[] =
{
    { 24, 24, SPECIES_VOLTORB },
    { 24, 24, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 23, 23, SPECIES_VOLTORB },
    { 23, 23, SPECIES_MAGNEMITE },
    { 26, 26, SPECIES_VOLTORB },
    { 26, 26, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 26, 26, SPECIES_ELECTRODE },
    { 26, 26, SPECIES_MAGNETON },
};

const struct WildPokemonInfo gNewMauville_Inside_LandMonsInfo = { 10, gNewMauville_Inside_LandMons };

const struct WildPokemon gNewMauville_Entrance_LandMons[] =
{
    { 24, 24, SPECIES_VOLTORB },
    { 24, 24, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 23, 23, SPECIES_VOLTORB },
    { 23, 23, SPECIES_MAGNEMITE },
    { 26, 26, SPECIES_VOLTORB },
    { 26, 26, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
};

const struct WildPokemonInfo gNewMauville_Entrance_LandMonsInfo = { 10, gNewMauville_Entrance_LandMons };

const struct WildPokemon gAbandonedShip_Rooms_B1F_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_Rooms_B1F_WaterMonsInfo = { 4, gAbandonedShip_Rooms_B1F_WaterMons };

const struct WildPokemon gAbandonedShip_Rooms_B1F_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_TENTACOOL },
    { 25, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
    { 25, 30, SPECIES_TENTACRUEL },
    { 20, 25, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_Rooms_B1F_FishingMonsInfo = { 20, gAbandonedShip_Rooms_B1F_FishingMons };

const struct WildPokemon gAbandonedShip_HiddenFloorCorridors_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_HiddenFloorCorridors_WaterMonsInfo = { 4, gAbandonedShip_HiddenFloorCorridors_WaterMons };

const struct WildPokemon gAbandonedShip_HiddenFloorCorridors_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_TENTACOOL },
    { 25, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
    { 25, 30, SPECIES_TENTACRUEL },
    { 20, 25, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_HiddenFloorCorridors_FishingMonsInfo = { 20, gAbandonedShip_HiddenFloorCorridors_FishingMons };

const struct WildPokemon gMtPyre_1F_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
};

const struct WildPokemonInfo gMtPyre_1F_LandMonsInfo = { 10, gMtPyre_1F_LandMons };

const struct WildPokemon gMtPyre_2F_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
};

const struct WildPokemonInfo gMtPyre_2F_LandMonsInfo = { 10, gMtPyre_2F_LandMons };

const struct WildPokemon gMtPyre_3F_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
};

const struct WildPokemonInfo gMtPyre_3F_LandMonsInfo = { 10, gMtPyre_3F_LandMons };

const struct WildPokemon gMtPyre_4F_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 27, 27, SPECIES_DUSKULL },
    { 27, 27, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
};

const struct WildPokemonInfo gMtPyre_4F_LandMonsInfo = { 10, gMtPyre_4F_LandMons };

const struct WildPokemon gMtPyre_5F_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 27, 27, SPECIES_DUSKULL },
    { 27, 27, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
};

const struct WildPokemonInfo gMtPyre_5F_LandMonsInfo = { 10, gMtPyre_5F_LandMons };

const struct WildPokemon gMtPyre_6F_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 27, 27, SPECIES_DUSKULL },
    { 27, 27, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
};

const struct WildPokemonInfo gMtPyre_6F_LandMonsInfo = { 10, gMtPyre_6F_LandMons };

const struct WildPokemon gMtPyre_Exterior_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 29, 29, SPECIES_VULPIX },
    { 27, 27, SPECIES_VULPIX },
    { 29, 29, SPECIES_VULPIX },
    { 25, 25, SPECIES_VULPIX },
    { 27, 27, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
};

const struct WildPokemonInfo gMtPyre_Exterior_LandMonsInfo = { 10, gMtPyre_Exterior_LandMons };

const struct WildPokemon gMtPyre_Summit_LandMons[] =
{
    { 28, 28, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 27, 27, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 30, 30, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 28, 28, SPECIES_DUSKULL },
    { 26, 26, SPECIES_DUSKULL },
    { 30, 30, SPECIES_DUSKULL },
    { 28, 28, SPECIES_CHIMECHO },
    { 28, 28, SPECIES_CHIMECHO },
};

const struct WildPokemonInfo gMtPyre_Summit_LandMonsInfo = { 10, gMtPyre_Summit_LandMons };

const struct WildPokemon gShoalCave_LowTideStairsRoom_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideStairsRoom_LandMonsInfo = { 10, gShoalCave_LowTideStairsRoom_LandMons };

const struct WildPokemon gShoalCave_LowTideLowerRoom_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideLowerRoom_LandMonsInfo = { 10, gShoalCave_LowTideLowerRoom_LandMons };

const struct WildPokemon gShoalCave_LowTideInnerRoom_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoom_LandMonsInfo = { 10, gShoalCave_LowTideInnerRoom_LandMons };

const struct WildPokemon gShoalCave_LowTideInnerRoom_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoom_WaterMonsInfo = { 4, gShoalCave_LowTideInnerRoom_WaterMons };

const struct WildPokemon gShoalCave_LowTideInnerRoom_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoom_FishingMonsInfo = { 10, gShoalCave_LowTideInnerRoom_FishingMons };

const struct WildPokemon gShoalCave_LowTideEntranceRoom_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoom_LandMonsInfo = { 10, gShoalCave_LowTideEntranceRoom_LandMons };

const struct WildPokemon gShoalCave_LowTideEntranceRoom_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoom_WaterMonsInfo = { 4, gShoalCave_LowTideEntranceRoom_WaterMons };

const struct WildPokemon gShoalCave_LowTideEntranceRoom_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoom_FishingMonsInfo = { 10, gShoalCave_LowTideEntranceRoom_FishingMons };

const struct WildPokemon gShoalCave_LowTideIceRoom_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 26, 26, SPECIES_SNORUNT },
    { 32, 32, SPECIES_SPHEAL },
    { 30, 30, SPECIES_GOLBAT },
    { 28, 28, SPECIES_SNORUNT },
    { 32, 32, SPECIES_GOLBAT },
    { 30, 30, SPECIES_SNORUNT },
};

const struct WildPokemonInfo gShoalCave_LowTideIceRoom_LandMonsInfo = { 10, gShoalCave_LowTideIceRoom_LandMons };

const struct WildPokemon gSeafloorCavern_Room1_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room1_LandMonsInfo = { 4, gSeafloorCavern_Room1_LandMons };

const struct WildPokemon gSeafloorCavern_Room2_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room2_LandMonsInfo = { 4, gSeafloorCavern_Room2_LandMons };

const struct WildPokemon gSeafloorCavern_Room3_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room3_LandMonsInfo = { 4, gSeafloorCavern_Room3_LandMons };

const struct WildPokemon gSeafloorCavern_Room4_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room4_LandMonsInfo = { 4, gSeafloorCavern_Room4_LandMons };

const struct WildPokemon gSeafloorCavern_Room5_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room5_LandMonsInfo = { 4, gSeafloorCavern_Room5_LandMons };

const struct WildPokemon gSeafloorCavern_Room6_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room6_LandMonsInfo = { 4, gSeafloorCavern_Room6_LandMons };

const struct WildPokemon gSeafloorCavern_Room6_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room6_WaterMonsInfo = { 4, gSeafloorCavern_Room6_WaterMons };

const struct WildPokemon gSeafloorCavern_Room6_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gSeafloorCavern_Room6_FishingMonsInfo = { 10, gSeafloorCavern_Room6_FishingMons };

const struct WildPokemon gSeafloorCavern_Room7_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room7_LandMonsInfo = { 4, gSeafloorCavern_Room7_LandMons };

const struct WildPokemon gSeafloorCavern_Room7_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room7_WaterMonsInfo = { 4, gSeafloorCavern_Room7_WaterMons };

const struct WildPokemon gSeafloorCavern_Room7_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gSeafloorCavern_Room7_FishingMonsInfo = { 10, gSeafloorCavern_Room7_FishingMons };

const struct WildPokemon gSeafloorCavern_Room8_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room8_LandMonsInfo = { 4, gSeafloorCavern_Room8_LandMons };

const struct WildPokemon gSeafloorCavern_Entrance_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Entrance_WaterMonsInfo = { 4, gSeafloorCavern_Entrance_WaterMons };

const struct WildPokemon gSeafloorCavern_Entrance_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gSeafloorCavern_Entrance_FishingMonsInfo = { 10, gSeafloorCavern_Entrance_FishingMons };

const struct WildPokemon gCaveOfOrigin_Entrance_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gCaveOfOrigin_Entrance_LandMonsInfo = { 4, gCaveOfOrigin_Entrance_LandMons };

const struct WildPokemon gCaveOfOrigin_1F_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gCaveOfOrigin_1F_LandMonsInfo = { 4, gCaveOfOrigin_1F_LandMons };

const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap1_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap1_LandMonsInfo = { 4, gCaveOfOrigin_UnusedRubySapphireMap1_LandMons };

const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap2_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap2_LandMonsInfo = { 4, gCaveOfOrigin_UnusedRubySapphireMap2_LandMons };

const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap3_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap3_LandMonsInfo = { 4, gCaveOfOrigin_UnusedRubySapphireMap3_LandMons };

const struct WildPokemon gHoennVictoryRoad_1F_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_HARIYAMA },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_LOUDRED },
    { 36, 36, SPECIES_ZUBAT },
    { 36, 36, SPECIES_MAKUHITA },
    { 38, 38, SPECIES_GOLBAT },
    { 38, 38, SPECIES_HARIYAMA },
    { 36, 36, SPECIES_ARON },
    { 36, 36, SPECIES_WHISMUR },
    { 36, 36, SPECIES_ARON },
    { 36, 36, SPECIES_WHISMUR },
};

const struct WildPokemonInfo gHoennVictoryRoad_1F_LandMonsInfo = { 10, gHoennVictoryRoad_1F_LandMons };

const struct WildPokemon gHoennVictoryRoad_B1F_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_HARIYAMA },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_LAIRON },
    { 38, 38, SPECIES_GOLBAT },
    { 38, 38, SPECIES_HARIYAMA },
    { 42, 42, SPECIES_GOLBAT },
    { 42, 42, SPECIES_HARIYAMA },
    { 42, 42, SPECIES_LAIRON },
    { 38, 38, SPECIES_MAWILE },
    { 42, 42, SPECIES_LAIRON },
    { 38, 38, SPECIES_MAWILE },
};

const struct WildPokemonInfo gHoennVictoryRoad_B1F_LandMonsInfo = { 10, gHoennVictoryRoad_B1F_LandMons };

const struct WildPokemon gHoennVictoryRoad_B1F_RockSmashMons[] =
{
    { 30, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gHoennVictoryRoad_B1F_RockSmashMonsInfo = { 20, gHoennVictoryRoad_B1F_RockSmashMons };

const struct WildPokemon gHoennVictoryRoad_B2F_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_SABLEYE },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_LAIRON },
    { 42, 42, SPECIES_GOLBAT },
    { 42, 42, SPECIES_SABLEYE },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_SABLEYE },
    { 42, 42, SPECIES_LAIRON },
    { 42, 42, SPECIES_MAWILE },
    { 44, 44, SPECIES_LAIRON },
    { 44, 44, SPECIES_MAWILE },
};

const struct WildPokemonInfo gHoennVictoryRoad_B2F_LandMonsInfo = { 10, gHoennVictoryRoad_B2F_LandMons };

const struct WildPokemon gHoennVictoryRoad_B2F_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 25, 30, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gHoennVictoryRoad_B2F_WaterMonsInfo = { 4, gHoennVictoryRoad_B2F_WaterMons };

const struct WildPokemon gHoennVictoryRoad_B2F_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo gHoennVictoryRoad_B2F_FishingMonsInfo = { 30, gHoennVictoryRoad_B2F_FishingMons };

const struct WildPokemon gSkyPillar_1F_LandMons[] =
{
    { 33, 33, SPECIES_SABLEYE },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SABLEYE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_BANETTE },
    { 38, 38, SPECIES_BANETTE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_CLAYDOL },
};

const struct WildPokemonInfo gSkyPillar_1F_LandMonsInfo = { 10, gSkyPillar_1F_LandMons };

const struct WildPokemon gSkyPillar_3F_LandMons[] =
{
    { 33, 33, SPECIES_SABLEYE },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SABLEYE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_BANETTE },
    { 38, 38, SPECIES_BANETTE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_CLAYDOL },
};

const struct WildPokemonInfo gSkyPillar_3F_LandMonsInfo = { 10, gSkyPillar_3F_LandMons };

const struct WildPokemon gSkyPillar_5F_LandMons[] =
{
    { 33, 33, SPECIES_SABLEYE },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SABLEYE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_BANETTE },
    { 38, 38, SPECIES_BANETTE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_ALTARIA },
    { 39, 39, SPECIES_ALTARIA },
    { 39, 39, SPECIES_ALTARIA },
};

const struct WildPokemonInfo gSkyPillar_5F_LandMonsInfo = { 10, gSkyPillar_5F_LandMons };

const struct WildPokemon gMirageTower_1F_LandMons[] =
{
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 22, 22, SPECIES_SANDSHREW },
    { 22, 22, SPECIES_TRAPINCH },
    { 23, 23, SPECIES_SANDSHREW },
    { 23, 23, SPECIES_TRAPINCH },
    { 24, 24, SPECIES_SANDSHREW },
    { 24, 24, SPECIES_TRAPINCH },
};

const struct WildPokemonInfo gMirageTower_1F_LandMonsInfo = { 10, gMirageTower_1F_LandMons };

const struct WildPokemon gMirageTower_2F_LandMons[] =
{
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 22, 22, SPECIES_SANDSHREW },
    { 22, 22, SPECIES_TRAPINCH },
    { 23, 23, SPECIES_SANDSHREW },
    { 23, 23, SPECIES_TRAPINCH },
    { 24, 24, SPECIES_SANDSHREW },
    { 24, 24, SPECIES_TRAPINCH },
};

const struct WildPokemonInfo gMirageTower_2F_LandMonsInfo = { 10, gMirageTower_2F_LandMons };

const struct WildPokemon gMirageTower_3F_LandMons[] =
{
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 22, 22, SPECIES_SANDSHREW },
    { 22, 22, SPECIES_TRAPINCH },
    { 23, 23, SPECIES_SANDSHREW },
    { 23, 23, SPECIES_TRAPINCH },
    { 24, 24, SPECIES_SANDSHREW },
    { 24, 24, SPECIES_TRAPINCH },
};

const struct WildPokemonInfo gMirageTower_3F_LandMonsInfo = { 10, gMirageTower_3F_LandMons };

const struct WildPokemon gMirageTower_4F_LandMons[] =
{
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 22, 22, SPECIES_SANDSHREW },
    { 22, 22, SPECIES_TRAPINCH },
    { 23, 23, SPECIES_SANDSHREW },
    { 23, 23, SPECIES_TRAPINCH },
    { 24, 24, SPECIES_SANDSHREW },
    { 24, 24, SPECIES_TRAPINCH },
};

const struct WildPokemonInfo gMirageTower_4F_LandMonsInfo = { 10, gMirageTower_4F_LandMons };

const struct WildPokemon gDesertUnderpass_LandMons[] =
{
    { 38, 38, SPECIES_DITTO },
    { 35, 35, SPECIES_WHISMUR },
    { 40, 40, SPECIES_DITTO },
    { 40, 40, SPECIES_LOUDRED },
    { 41, 41, SPECIES_DITTO },
    { 36, 36, SPECIES_WHISMUR },
    { 38, 38, SPECIES_LOUDRED },
    { 42, 42, SPECIES_DITTO },
    { 38, 38, SPECIES_WHISMUR },
    { 43, 43, SPECIES_DITTO },
    { 44, 44, SPECIES_LOUDRED },
    { 45, 45, SPECIES_DITTO },
};

const struct WildPokemonInfo gDesertUnderpass_LandMonsInfo = { 10, gDesertUnderpass_LandMons };

const struct WildPokemon gAlteringCave1_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 16, 16, SPECIES_ZUBAT },
    { 6, 6, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
};

const struct WildPokemonInfo gAlteringCave1_LandMonsInfo = { 7, gAlteringCave1_LandMons };

const struct WildPokemon gHoennSafariZone_South_LandMons[] =
{
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 25, 25, SPECIES_GIRAFARIG },
    { 27, 27, SPECIES_GIRAFARIG },
    { 25, 25, SPECIES_NATU },
    { 25, 25, SPECIES_DODUO },
    { 25, 25, SPECIES_GLOOM },
    { 27, 27, SPECIES_WOBBUFFET },
    { 25, 25, SPECIES_PIKACHU },
    { 27, 27, SPECIES_WOBBUFFET },
    { 27, 27, SPECIES_PIKACHU },
    { 29, 29, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo gHoennSafariZone_South_LandMonsInfo = { 25, gHoennSafariZone_South_LandMons };

const struct WildPokemon gHoennSafariZone_Southwest_LandMons[] =
{
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 25, 25, SPECIES_GIRAFARIG },
    { 27, 27, SPECIES_GIRAFARIG },
    { 25, 25, SPECIES_NATU },
    { 27, 27, SPECIES_DODUO },
    { 25, 25, SPECIES_GLOOM },
    { 27, 27, SPECIES_WOBBUFFET },
    { 25, 25, SPECIES_PIKACHU },
    { 27, 27, SPECIES_WOBBUFFET },
    { 27, 27, SPECIES_PIKACHU },
    { 29, 29, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo gHoennSafariZone_Southwest_LandMonsInfo = { 25, gHoennSafariZone_Southwest_LandMons };

const struct WildPokemon gHoennSafariZone_Southwest_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo gHoennSafariZone_Southwest_WaterMonsInfo = { 9, gHoennSafariZone_Southwest_WaterMons };

const struct WildPokemon gHoennSafariZone_Southwest_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 25, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
    { 25, 30, SPECIES_SEAKING },
};

const struct WildPokemonInfo gHoennSafariZone_Southwest_FishingMonsInfo = { 35, gHoennSafariZone_Southwest_FishingMons };

const struct WildPokemon gHoennSafariZone_North_LandMons[] =
{
    { 27, 27, SPECIES_PHANPY },
    { 27, 27, SPECIES_ODDISH },
    { 29, 29, SPECIES_PHANPY },
    { 29, 29, SPECIES_ODDISH },
    { 27, 27, SPECIES_NATU },
    { 29, 29, SPECIES_GLOOM },
    { 31, 31, SPECIES_GLOOM },
    { 29, 29, SPECIES_NATU },
    { 29, 29, SPECIES_XATU },
    { 27, 27, SPECIES_HERACROSS },
    { 31, 31, SPECIES_XATU },
    { 29, 29, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gHoennSafariZone_North_LandMonsInfo = { 25, gHoennSafariZone_North_LandMons };

const struct WildPokemon gHoennSafariZone_North_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 20, 25, SPECIES_GEODUDE },
    { 25, 30, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gHoennSafariZone_North_RockSmashMonsInfo = { 25, gHoennSafariZone_North_RockSmashMons };

const struct WildPokemon gHoennSafariZone_Northwest_LandMons[] =
{
    { 27, 27, SPECIES_RHYHORN },
    { 27, 27, SPECIES_ODDISH },
    { 29, 29, SPECIES_RHYHORN },
    { 29, 29, SPECIES_ODDISH },
    { 27, 27, SPECIES_DODUO },
    { 29, 29, SPECIES_GLOOM },
    { 31, 31, SPECIES_GLOOM },
    { 29, 29, SPECIES_DODUO },
    { 29, 29, SPECIES_DODRIO },
    { 27, 27, SPECIES_PINSIR },
    { 31, 31, SPECIES_DODRIO },
    { 29, 29, SPECIES_PINSIR },
};

const struct WildPokemonInfo gHoennSafariZone_Northwest_LandMonsInfo = { 25, gHoennSafariZone_Northwest_LandMons };

const struct WildPokemon gHoennSafariZone_Northwest_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_GOLDUCK },
    { 25, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo gHoennSafariZone_Northwest_WaterMonsInfo = { 9, gHoennSafariZone_Northwest_WaterMons };

const struct WildPokemon gHoennSafariZone_Northwest_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 25, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
    { 25, 30, SPECIES_SEAKING },
};

const struct WildPokemonInfo gHoennSafariZone_Northwest_FishingMonsInfo = { 35, gHoennSafariZone_Northwest_FishingMons };

const struct WildPokemon gHoennSafariZone_Southeast_LandMons[] =
{
    { 33, 33, SPECIES_SUNKERN },
    { 34, 34, SPECIES_MAREEP },
    { 35, 35, SPECIES_SUNKERN },
    { 36, 36, SPECIES_MAREEP },
    { 34, 34, SPECIES_AIPOM },
    { 33, 33, SPECIES_SPINARAK },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_SNUBBULL },
    { 36, 36, SPECIES_STANTLER },
    { 37, 37, SPECIES_GLIGAR },
    { 39, 39, SPECIES_STANTLER },
    { 40, 40, SPECIES_GLIGAR },
};

const struct WildPokemonInfo gHoennSafariZone_Southeast_LandMonsInfo = { 25, gHoennSafariZone_Southeast_LandMons };

const struct WildPokemon gHoennSafariZone_Southeast_WaterMons[] =
{
    { 25, 30, SPECIES_WOOPER },
    { 25, 30, SPECIES_MARILL },
    { 25, 30, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 35, 40, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gHoennSafariZone_Southeast_WaterMonsInfo = { 9, gHoennSafariZone_Southeast_WaterMons };

const struct WildPokemon gHoennSafariZone_Southeast_FishingMons[] =
{
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_REMORAID },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 35, 40, SPECIES_OCTILLERY },
};

const struct WildPokemonInfo gHoennSafariZone_Southeast_FishingMonsInfo = { 35, gHoennSafariZone_Southeast_FishingMons };

const struct WildPokemon gHoennSafariZone_Northeast_LandMons[] =
{
    { 33, 33, SPECIES_AIPOM },
    { 34, 34, SPECIES_TEDDIURSA },
    { 35, 35, SPECIES_AIPOM },
    { 36, 36, SPECIES_TEDDIURSA },
    { 34, 34, SPECIES_SUNKERN },
    { 33, 33, SPECIES_LEDYBA },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_PINECO },
    { 36, 36, SPECIES_HOUNDOUR },
    { 37, 37, SPECIES_MILTANK },
    { 39, 39, SPECIES_HOUNDOUR },
    { 40, 40, SPECIES_MILTANK },
};

const struct WildPokemonInfo gHoennSafariZone_Northeast_LandMonsInfo = { 25, gHoennSafariZone_Northeast_LandMons };

const struct WildPokemon gHoennSafariZone_Northeast_RockSmashMons[] =
{
    { 25, 30, SPECIES_SHUCKLE },
    { 20, 25, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 35, 40, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo gHoennSafariZone_Northeast_RockSmashMonsInfo = { 25, gHoennSafariZone_Northeast_RockSmashMons };

// BEGIN johto_import
const struct WildPokemon gNewBarkTown_LandMons[] =
{
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
};

const struct WildPokemonInfo gNewBarkTown_LandMonsInfo = { 0, gNewBarkTown_LandMons };

const struct WildPokemon gNewBarkTown_WaterMons[] =
{
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
    { 25, 29, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo gNewBarkTown_WaterMonsInfo = { 7, gNewBarkTown_WaterMons };

const struct WildPokemon gNewBarkTown_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gNewBarkTown_RockSmashMonsInfo = { 60, gNewBarkTown_RockSmashMons };

const struct WildPokemon gNewBarkTown_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_CHINCHOU },
    { 20, 20, SPECIES_SHELLDER },
    { 40, 40, SPECIES_CHINCHOU },
    { 40, 40, SPECIES_SHELLDER },
    { 40, 40, SPECIES_TENTACRUEL },
    { 40, 40, SPECIES_LANTURN },
};

const struct WildPokemonInfo gNewBarkTown_FishingMonsInfo = { 30, gNewBarkTown_FishingMons };

const struct WildPokemon gCherrygroveCity_WaterMons[] =
{
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gCherrygroveCity_WaterMonsInfo = { 7, gCherrygroveCity_WaterMons };

const struct WildPokemon gCherrygroveCity_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gCherrygroveCity_RockSmashMonsInfo = { 60, gCherrygroveCity_RockSmashMons };

const struct WildPokemon gCherrygroveCity_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_KRABBY },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_STARYU },
    { 40, 40, SPECIES_KRABBY },
    { 40, 40, SPECIES_CORSOLA },
    { 40, 40, SPECIES_KINGLER },
    { 40, 40, SPECIES_CORSOLA },
    { 40, 40, SPECIES_KRABBY },
};

const struct WildPokemonInfo gCherrygroveCity_FishingMonsInfo = { 30, gCherrygroveCity_FishingMons };

const struct WildPokemon gVioletCity_LandMons[] =
{
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
};

const struct WildPokemonInfo gVioletCity_LandMonsInfo = { 0, gVioletCity_LandMons };

const struct WildPokemon gVioletCity_WaterMons[] =
{
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
};

const struct WildPokemonInfo gVioletCity_WaterMonsInfo = { 7, gVioletCity_WaterMons };

const struct WildPokemon gVioletCity_RockSmashMons[] =
{
    { 10, 10, SPECIES_BELLSPROUT },
    { 10, 10, SPECIES_RATTATA },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gVioletCity_RockSmashMonsInfo = { 60, gVioletCity_RockSmashMons };

const struct WildPokemon gVioletCity_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gVioletCity_FishingMonsInfo = { 30, gVioletCity_FishingMons };

const struct WildPokemon gAzaleaTown_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_HERACROSS },
    { 10, 10, SPECIES_AIPOM },
    { 10, 10, SPECIES_AIPOM },
};

const struct WildPokemonInfo gAzaleaTown_RockSmashMonsInfo = { 60, gAzaleaTown_RockSmashMons };

const struct WildPokemon gGoldenrodCity_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gGoldenrodCity_RockSmashMonsInfo = { 60, gGoldenrodCity_RockSmashMons };

const struct WildPokemon gEcruteakCity_WaterMons[] =
{
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
};

const struct WildPokemonInfo gEcruteakCity_WaterMonsInfo = { 7, gEcruteakCity_WaterMons };

const struct WildPokemon gEcruteakCity_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gEcruteakCity_RockSmashMonsInfo = { 60, gEcruteakCity_RockSmashMons };

const struct WildPokemon gEcruteakCity_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gEcruteakCity_FishingMonsInfo = { 30, gEcruteakCity_FishingMons };

const struct WildPokemon gOlivineCity_LandMons[] =
{
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
};

const struct WildPokemonInfo gOlivineCity_LandMonsInfo = { 0, gOlivineCity_LandMons };

const struct WildPokemon gOlivineCity_WaterMons[] =
{
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gOlivineCity_WaterMonsInfo = { 7, gOlivineCity_WaterMons };

const struct WildPokemon gOlivineCity_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gOlivineCity_RockSmashMonsInfo = { 60, gOlivineCity_RockSmashMons };

const struct WildPokemon gOlivineCity_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_KRABBY },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_STARYU },
    { 40, 40, SPECIES_KRABBY },
    { 40, 40, SPECIES_CORSOLA },
    { 40, 40, SPECIES_KINGLER },
    { 40, 40, SPECIES_CORSOLA },
    { 40, 40, SPECIES_KRABBY },
};

const struct WildPokemonInfo gOlivineCity_FishingMonsInfo = { 30, gOlivineCity_FishingMons };

const struct WildPokemon gCianwoodCity_WaterMons[] =
{
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gCianwoodCity_WaterMonsInfo = { 7, gCianwoodCity_WaterMons };

const struct WildPokemon gCianwoodCity_RockSmashMons[] =
{
    { 20, 22, SPECIES_GEODUDE },
    { 20, 22, SPECIES_GEODUDE },
    { 20, 22, SPECIES_GEODUDE },
    { 20, 22, SPECIES_SHUCKLE },
    { 20, 22, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo gCianwoodCity_RockSmashMonsInfo = { 60, gCianwoodCity_RockSmashMons };

const struct WildPokemon gCianwoodCity_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_CHINCHOU },
    { 20, 20, SPECIES_STARYU },
    { 20, 20, SPECIES_CHINCHOU },
    { 40, 40, SPECIES_SHELLDER },
    { 40, 40, SPECIES_LANTURN },
    { 40, 40, SPECIES_TENTACRUEL },
    { 40, 40, SPECIES_KINGLER },
};

const struct WildPokemonInfo gCianwoodCity_FishingMonsInfo = { 30, gCianwoodCity_FishingMons };

const struct WildPokemon gSafariZoneGate_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gSafariZoneGate_RockSmashMonsInfo = { 60, gSafariZoneGate_RockSmashMons };

const struct WildPokemon gMahoganyTown_RockSmashMons[] =
{
    { 15, 15, SPECIES_AIPOM },
    { 15, 15, SPECIES_AIPOM },
    { 15, 15, SPECIES_PINECO },
    { 15, 15, SPECIES_HERACROSS },
    { 15, 15, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gMahoganyTown_RockSmashMonsInfo = { 60, gMahoganyTown_RockSmashMons };

const struct WildPokemon gBlackthornCity_LandMons[] =
{
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
};

const struct WildPokemonInfo gBlackthornCity_LandMonsInfo = { 0, gBlackthornCity_LandMons };

const struct WildPokemon gBlackthornCity_WaterMons[] =
{
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gBlackthornCity_WaterMonsInfo = { 7, gBlackthornCity_WaterMons };

const struct WildPokemon gBlackthornCity_RockSmashMons[] =
{
    { 15, 15, SPECIES_AIPOM },
    { 15, 15, SPECIES_AIPOM },
    { 15, 15, SPECIES_PINECO },
    { 15, 15, SPECIES_HERACROSS },
    { 15, 15, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gBlackthornCity_RockSmashMonsInfo = { 60, gBlackthornCity_RockSmashMons };

const struct WildPokemon gBlackthornCity_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gBlackthornCity_FishingMonsInfo = { 30, gBlackthornCity_FishingMons };

const struct WildPokemon gRoute29_LandMons[] =
{
    { 2, 3, SPECIES_PIDGEY },
    { 2, 3, SPECIES_PIDGEY },
    { 2, 3, SPECIES_PIDGEY },
    { 2, 3, SPECIES_SENTRET },
    { 2, 3, SPECIES_SENTRET },
    { 2, 3, SPECIES_HOPPIP },
    { 2, 3, SPECIES_HOPPIP },
    { 2, 3, SPECIES_SENTRET },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_HOOTHOOT },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_HOPPIP },
};

const struct WildPokemonInfo gRoute29_LandMonsInfo = { 20, gRoute29_LandMons };

const struct WildPokemon gRoute29_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gRoute29_RockSmashMonsInfo = { 60, gRoute29_RockSmashMons };

const struct WildPokemon gRoute30_LandMons[] =
{
    { 3, 4, SPECIES_HOOTHOOT },
    { 3, 4, SPECIES_CATERPIE },
    { 3, 4, SPECIES_CATERPIE },
    { 3, 4, SPECIES_SPINARAK },
    { 3, 4, SPECIES_PIDGEY },
    { 3, 4, SPECIES_PIDGEY },
    { 4, 4, SPECIES_POLIWAG },
    { 4, 4, SPECIES_LEDYBA },
    { 3, 4, SPECIES_WEEDLE },
    { 3, 4, SPECIES_WEEDLE },
    { 3, 4, SPECIES_ZUBAT },
    { 3, 4, SPECIES_WEEDLE },
};

const struct WildPokemonInfo gRoute30_LandMonsInfo = { 20, gRoute30_LandMons };

const struct WildPokemon gRoute30_WaterMons[] =
{
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
    { 20, 24, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gRoute30_WaterMonsInfo = { 7, gRoute30_WaterMons };

const struct WildPokemon gRoute30_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gRoute30_RockSmashMonsInfo = { 60, gRoute30_RockSmashMons };

const struct WildPokemon gRoute30_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gRoute30_FishingMonsInfo = { 30, gRoute30_FishingMons };

const struct WildPokemon gRoute31_LandMons[] =
{
    { 4, 4, SPECIES_SPINARAK },
    { 4, 5, SPECIES_POLIWAG },
    { 4, 4, SPECIES_LEDYBA },
    { 4, 5, SPECIES_BELLSPROUT },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_HOOTHOOT },
    { 5, 5, SPECIES_MAREEP },
    { 4, 4, SPECIES_ZUBAT },
    { 5, 5, SPECIES_GASTLY },
    { 4, 4, SPECIES_WEEDLE },
    { 5, 5, SPECIES_PICHU },
};

const struct WildPokemonInfo gRoute31_LandMonsInfo = { 20, gRoute31_LandMons };

const struct WildPokemon gRoute31_WaterMons[] =
{
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 15, 24, SPECIES_POLIWAG },
    { 20, 24, SPECIES_POLIWHIRL },
    { 20, 24, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gRoute31_WaterMonsInfo = { 7, gRoute31_WaterMons };

const struct WildPokemon gRoute31_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gRoute31_RockSmashMonsInfo = { 60, gRoute31_RockSmashMons };

const struct WildPokemon gRoute31_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 20, 20, SPECIES_POLIWAG },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gRoute31_FishingMonsInfo = { 30, gRoute31_FishingMons };

const struct WildPokemon gRoute32_LandMons[] =
{
    { 5, 7, SPECIES_MAREEP },
    { 5, 7, SPECIES_MAREEP },
    { 5, 7, SPECIES_MAREEP },
    { 7, 7, SPECIES_ZUBAT },
    { 7, 7, SPECIES_WOOPER },
    { 7, 7, SPECIES_WOOPER },
    { 6, 6, SPECIES_GASTLY },
    { 6, 6, SPECIES_EKANS },
    { 7, 7, SPECIES_PIDGEY },
    { 7, 7, SPECIES_BELLSPROUT },
    { 7, 7, SPECIES_PIDGEY },
    { 7, 7, SPECIES_BELLSPROUT },
};

const struct WildPokemonInfo gRoute32_LandMonsInfo = { 20, gRoute32_LandMons };

const struct WildPokemon gRoute32_WaterMons[] =
{
    { 15, 19, SPECIES_TENTACOOL },
    { 15, 19, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_QUAGSIRE },
    { 20, 24, SPECIES_TENTACRUEL },
    { 20, 24, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gRoute32_WaterMonsInfo = { 7, gRoute32_WaterMons };

const struct WildPokemon gRoute32_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_EKANS },
    { 10, 10, SPECIES_EKANS },
    { 10, 10, SPECIES_EKANS },
};

const struct WildPokemonInfo gRoute32_RockSmashMonsInfo = { 60, gRoute32_RockSmashMons };

const struct WildPokemon gRoute32_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_QWILFISH },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_QWILFISH },
    { 20, 20, SPECIES_TENTACOOL },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo gRoute32_FishingMonsInfo = { 30, gRoute32_FishingMons };

const struct WildPokemon gRoute33_LandMons[] =
{
    { 8, 9, SPECIES_ZUBAT },
    { 8, 9, SPECIES_MACHOP },
    { 8, 9, SPECIES_EKANS },
    { 8, 9, SPECIES_EKANS },
    { 8, 9, SPECIES_EKANS },
    { 8, 8, SPECIES_RATTATA },
    { 8, 8, SPECIES_RATTATA },
    { 8, 9, SPECIES_SPEAROW },
    { 9, 9, SPECIES_EKANS },
    { 8, 8, SPECIES_RATTATA },
    { 8, 8, SPECIES_SPEAROW },
    { 8, 8, SPECIES_SPEAROW },
};

const struct WildPokemonInfo gRoute33_LandMonsInfo = { 20, gRoute33_LandMons };

const struct WildPokemon gRoute33_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_AIPOM },
    { 10, 10, SPECIES_EKANS },
    { 10, 10, SPECIES_EKANS },
    { 10, 10, SPECIES_EKANS },
};

const struct WildPokemonInfo gRoute33_RockSmashMonsInfo = { 60, gRoute33_RockSmashMons };

const struct WildPokemon gRoute34_LandMons[] =
{
    { 14, 14, SPECIES_DROWZEE },
    { 13, 13, SPECIES_ABRA },
    { 14, 14, SPECIES_SNUBBULL },
    { 13, 13, SPECIES_ABRA },
    { 14, 14, SPECIES_MANKEY },
    { 14, 14, SPECIES_SNUBBULL },
    { 13, 13, SPECIES_GRIMER },
    { 13, 13, SPECIES_GRIMER },
    { 14, 14, SPECIES_JIGGLYPUFF },
    { 10, 10, SPECIES_DITTO },
    { 14, 14, SPECIES_JIGGLYPUFF },
    { 10, 10, SPECIES_DITTO },
};

const struct WildPokemonInfo gRoute34_LandMonsInfo = { 20, gRoute34_LandMons };

const struct WildPokemon gRoute34_WaterMons[] =
{
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gRoute34_WaterMonsInfo = { 7, gRoute34_WaterMons };

const struct WildPokemon gRoute34_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gRoute34_RockSmashMonsInfo = { 60, gRoute34_RockSmashMons };

const struct WildPokemon gRoute34_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_KRABBY },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_CORSOLA },
    { 20, 20, SPECIES_STARYU },
    { 40, 40, SPECIES_KRABBY },
    { 40, 40, SPECIES_CORSOLA },
    { 40, 40, SPECIES_STARYU },
    { 40, 40, SPECIES_KINGLER },
};

const struct WildPokemonInfo gRoute34_FishingMonsInfo = { 30, gRoute34_FishingMons };

const struct WildPokemon gRoute35_LandMons[] =
{
    { 15, 15, SPECIES_PSYDUCK },
    { 15, 15, SPECIES_PIDGEY },
    { 15, 15, SPECIES_ABRA },
    { 14, 18, SPECIES_YANMA },
    { 14, 15, SPECIES_DITTO },
    { 15, 15, SPECIES_PIDGEY },
    { 15, 15, SPECIES_ABRA },
    { 15, 15, SPECIES_SNUBBULL },
    { 14, 18, SPECIES_YANMA },
    { 14, 18, SPECIES_YANMA },
    { 14, 15, SPECIES_GROWLITHE },
    { 14, 18, SPECIES_YANMA },
};

const struct WildPokemonInfo gRoute35_LandMonsInfo = { 20, gRoute35_LandMons };

const struct WildPokemon gRoute35_WaterMons[] =
{
    { 15, 24, SPECIES_PSYDUCK },
    { 15, 24, SPECIES_PSYDUCK },
    { 15, 24, SPECIES_PSYDUCK },
    { 20, 24, SPECIES_GOLDUCK },
    { 15, 24, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo gRoute35_WaterMonsInfo = { 7, gRoute35_WaterMons };

const struct WildPokemon gRoute35_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gRoute35_RockSmashMonsInfo = { 60, gRoute35_RockSmashMons };

const struct WildPokemon gRoute35_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 20, 20, SPECIES_POLIWAG },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gRoute35_FishingMonsInfo = { 30, gRoute35_FishingMons };

const struct WildPokemon gRoute36_LandMons[] =
{
    { 4, 5, SPECIES_RATTATA },
    { 4, 4, SPECIES_GASTLY },
    { 5, 6, SPECIES_HOOTHOOT },
    { 4, 4, SPECIES_BELLSPROUT },
    { 5, 6, SPECIES_PIDGEY },
    { 4, 5, SPECIES_RATTATA },
    { 5, 6, SPECIES_PIDGEY },
    { 4, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_HOUNDOUR },
    { 5, 5, SPECIES_GROWLITHE },
    { 5, 5, SPECIES_GROWLITHE },
    { 5, 5, SPECIES_GROWLITHE },
};

const struct WildPokemonInfo gRoute36_LandMonsInfo = { 20, gRoute36_LandMons };

const struct WildPokemon gRoute36_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gRoute36_RockSmashMonsInfo = { 60, gRoute36_RockSmashMons };

const struct WildPokemon gRoute37_LandMons[] =
{
    { 16, 18, SPECIES_VULPIX },
    { 16, 18, SPECIES_PIDGEY },
    { 18, 18, SPECIES_STANTLER },
    { 16, 18, SPECIES_GROWLITHE },
    { 16, 18, SPECIES_HOOTHOOT },
    { 16, 18, SPECIES_GROWLITHE },
    { 16, 18, SPECIES_LEDIAN },
    { 18, 18, SPECIES_PIDGEOTTO },
    { 18, 18, SPECIES_NOCTOWL },
    { 18, 18, SPECIES_ARIADOS },
    { 16, 18, SPECIES_STANTLER },
    { 16, 18, SPECIES_SPINARAK },
};

const struct WildPokemonInfo gRoute37_LandMonsInfo = { 20, gRoute37_LandMons };

const struct WildPokemon gRoute37_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_SPINARAK },
    { 10, 10, SPECIES_LEDYBA },
    { 10, 10, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gRoute37_RockSmashMonsInfo = { 60, gRoute37_RockSmashMons };

const struct WildPokemon gRoute38_LandMons[] =
{
    { 20, 20, SPECIES_MAGNEMITE },
    { 21, 21, SPECIES_MILTANK },
    { 21, 21, SPECIES_TAUROS },
    { 20, 20, SPECIES_DODUO },
    { 20, 20, SPECIES_MAGNEMITE },
    { 21, 21, SPECIES_MILTANK },
    { 21, 21, SPECIES_TAUROS },
    { 20, 20, SPECIES_DODUO },
    { 20, 20, SPECIES_NOCTOWL },
    { 19, 19, SPECIES_RATICATE },
    { 20, 20, SPECIES_MEOWTH },
    { 19, 19, SPECIES_RATICATE },
};

const struct WildPokemonInfo gRoute38_LandMonsInfo = { 20, gRoute38_LandMons };

const struct WildPokemon gRoute38_RockSmashMons[] =
{
    { 15, 15, SPECIES_PINECO },
    { 15, 15, SPECIES_EXEGGCUTE },
    { 15, 15, SPECIES_SPINARAK },
    { 15, 15, SPECIES_LEDYBA },
    { 15, 15, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gRoute38_RockSmashMonsInfo = { 60, gRoute38_RockSmashMons };

const struct WildPokemon gRoute39_LandMons[] =
{
    { 21, 21, SPECIES_MEOWTH },
    { 21, 21, SPECIES_RATICATE },
    { 21, 21, SPECIES_MAGNEMITE },
    { 21, 21, SPECIES_NOCTOWL },
    { 21, 21, SPECIES_PONYTA },
    { 21, 21, SPECIES_RATICATE },
    { 21, 21, SPECIES_MAGNEMITE },
    { 21, 21, SPECIES_DODUO },
    { 21, 21, SPECIES_MILTANK },
    { 21, 21, SPECIES_TAUROS },
    { 21, 21, SPECIES_MILTANK },
    { 21, 21, SPECIES_TAUROS },
};

const struct WildPokemonInfo gRoute39_LandMonsInfo = { 20, gRoute39_LandMons };

const struct WildPokemon gRoute39_RockSmashMons[] =
{
    { 15, 15, SPECIES_PINECO },
    { 15, 15, SPECIES_EXEGGCUTE },
    { 15, 15, SPECIES_SPINARAK },
    { 15, 15, SPECIES_LEDYBA },
    { 15, 15, SPECIES_LEDYBA },
};

const struct WildPokemonInfo gRoute39_RockSmashMonsInfo = { 60, gRoute39_RockSmashMons };

const struct WildPokemon gRoute40_WaterMons[] =
{
    { 20, 24, SPECIES_TENTACOOL },
    { 21, 25, SPECIES_SHELLDER },
    { 22, 26, SPECIES_TENTACRUEL },
    { 20, 24, SPECIES_TENTACOOL },
    { 21, 25, SPECIES_SHELLDER },
};

const struct WildPokemonInfo gRoute40_WaterMonsInfo = { 7, gRoute40_WaterMons };

const struct WildPokemon gRoute40_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_KRABBY },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_CORSOLA },
    { 20, 20, SPECIES_STARYU },
    { 40, 40, SPECIES_KRABBY },
    { 40, 40, SPECIES_CORSOLA },
    { 40, 40, SPECIES_STARYU },
    { 40, 40, SPECIES_KINGLER },
};

const struct WildPokemonInfo gRoute40_FishingMonsInfo = { 30, gRoute40_FishingMons };

const struct WildPokemon gRoute41_WaterMons[] =
{
    { 20, 24, SPECIES_TENTACOOL },
    { 21, 25, SPECIES_HORSEA },
    { 22, 26, SPECIES_MANTINE },
    { 20, 24, SPECIES_TENTACOOL },
    { 21, 25, SPECIES_HORSEA },
};

const struct WildPokemonInfo gRoute41_WaterMonsInfo = { 7, gRoute41_WaterMons };

const struct WildPokemon gRoute41_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_SHELLDER },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_CHINCHOU },
    { 20, 20, SPECIES_SHELLDER },
    { 20, 20, SPECIES_CHINCHOU },
    { 40, 40, SPECIES_SHELLDER },
    { 40, 40, SPECIES_LANTURN },
    { 40, 40, SPECIES_TENTACRUEL },
    { 40, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gRoute41_FishingMonsInfo = { 30, gRoute41_FishingMons };

const struct WildPokemon gRoute42_LandMons[] =
{
    { 20, 20, SPECIES_FEAROW },
    { 20, 20, SPECIES_ZUBAT },
    { 21, 21, SPECIES_GLIGAR },
    { 21, 21, SPECIES_GOLBAT },
    { 20, 20, SPECIES_FEAROW },
    { 20, 20, SPECIES_EKANS },
    { 21, 21, SPECIES_GLIGAR },
    { 22, 22, SPECIES_ARBOK },
    { 21, 21, SPECIES_RATICATE },
    { 22, 22, SPECIES_FEAROW },
    { 22, 22, SPECIES_MARILL },
    { 22, 22, SPECIES_RATICATE },
};

const struct WildPokemonInfo gRoute42_LandMonsInfo = { 20, gRoute42_LandMons };

const struct WildPokemon gRoute42_WaterMons[] =
{
    { 21, 25, SPECIES_REMORAID },
    { 20, 24, SPECIES_GOLDEEN },
    { 25, 29, SPECIES_SEAKING },
    { 21, 25, SPECIES_REMORAID },
    { 20, 24, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute42_WaterMonsInfo = { 7, gRoute42_WaterMons };

const struct WildPokemon gRoute42_RockSmashMons[] =
{
    { 15, 15, SPECIES_PINECO },
    { 15, 15, SPECIES_AIPOM },
    { 15, 15, SPECIES_AIPOM },
    { 15, 15, SPECIES_HERACROSS },
    { 15, 15, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gRoute42_RockSmashMonsInfo = { 60, gRoute42_RockSmashMons };

const struct WildPokemon gRoute42_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute42_FishingMonsInfo = { 30, gRoute42_FishingMons };

const struct WildPokemon gRoute43_LandMons[] =
{
    { 21, 21, SPECIES_VENONAT },
    { 22, 22, SPECIES_GIRAFARIG },
    { 22, 22, SPECIES_FARFETCHD },
    { 23, 23, SPECIES_FLAAFFY },
    { 21, 21, SPECIES_FURRET },
    { 22, 22, SPECIES_GIRAFARIG },
    { 22, 22, SPECIES_FARFETCHD },
    { 23, 23, SPECIES_FLAAFFY },
    { 22, 22, SPECIES_RATICATE },
    { 24, 24, SPECIES_SKARMORY },
    { 23, 23, SPECIES_FLAAFFY },
    { 24, 24, SPECIES_VENOMOTH },
};

const struct WildPokemonInfo gRoute43_LandMonsInfo = { 20, gRoute43_LandMons };

const struct WildPokemon gRoute43_WaterMons[] =
{
    { 10, 24, SPECIES_MAGIKARP },
    { 10, 24, SPECIES_MAGIKARP },
    { 10, 24, SPECIES_MAGIKARP },
    { 10, 24, SPECIES_MAGIKARP },
    { 10, 24, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute43_WaterMonsInfo = { 7, gRoute43_WaterMons };

const struct WildPokemon gRoute43_RockSmashMons[] =
{
    { 20, 20, SPECIES_PINECO },
    { 20, 20, SPECIES_EXEGGCUTE },
    { 20, 20, SPECIES_VENONAT },
    { 20, 20, SPECIES_VENONAT },
    { 20, 20, SPECIES_VENONAT },
};

const struct WildPokemonInfo gRoute43_RockSmashMonsInfo = { 60, gRoute43_RockSmashMons };

const struct WildPokemon gRoute43_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute43_FishingMonsInfo = { 30, gRoute43_FishingMons };

const struct WildPokemon gRoute44_LandMons[] =
{
    { 33, 33, SPECIES_POLIWHIRL },
    { 32, 32, SPECIES_LICKITUNG },
    { 32, 32, SPECIES_WEEPINBELL },
    { 34, 34, SPECIES_PIDGEOTTO },
    { 33, 33, SPECIES_TANGELA },
    { 32, 32, SPECIES_LICKITUNG },
    { 32, 32, SPECIES_WEEPINBELL },
    { 34, 34, SPECIES_PIDGEOTTO },
    { 36, 36, SPECIES_ELECTABUZZ },
    { 36, 36, SPECIES_ELECTABUZZ },
    { 33, 33, SPECIES_TANGELA },
    { 36, 36, SPECIES_ELECTABUZZ },
};

const struct WildPokemonInfo gRoute44_LandMonsInfo = { 20, gRoute44_LandMons };

const struct WildPokemon gRoute44_WaterMons[] =
{
    { 24, 29, SPECIES_POLIWAG },
    { 28, 32, SPECIES_POLIWHIRL },
    { 24, 29, SPECIES_POLIWAG },
    { 28, 32, SPECIES_POLIWHIRL },
    { 24, 29, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gRoute44_WaterMonsInfo = { 7, gRoute44_WaterMons };

const struct WildPokemon gRoute44_RockSmashMons[] =
{
    { 20, 20, SPECIES_PINECO },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_HERACROSS },
    { 20, 20, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gRoute44_RockSmashMonsInfo = { 60, gRoute44_RockSmashMons };

const struct WildPokemon gRoute44_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute44_FishingMonsInfo = { 30, gRoute44_FishingMons };

const struct WildPokemon gRoute45_LandMons[] =
{
    { 34, 35, SPECIES_DONPHAN },
    { 34, 34, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GLIGAR },
    { 35, 35, SPECIES_URSARING },
    { 34, 35, SPECIES_DONPHAN },
    { 34, 34, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GLIGAR },
    { 37, 37, SPECIES_SKARMORY },
    { 35, 35, SPECIES_URSARING },
    { 37, 37, SPECIES_SKARMORY },
    { 34, 35, SPECIES_DONPHAN },
    { 34, 34, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gRoute45_LandMonsInfo = { 20, gRoute45_LandMons };

const struct WildPokemon gRoute45_WaterMons[] =
{
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
    { 5, 24, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute45_WaterMonsInfo = { 7, gRoute45_WaterMons };

const struct WildPokemon gRoute45_RockSmashMons[] =
{
    { 20, 20, SPECIES_PINECO },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_HERACROSS },
    { 20, 20, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gRoute45_RockSmashMonsInfo = { 60, gRoute45_RockSmashMons };

const struct WildPokemon gRoute45_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_DRATINI },
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_DRATINI },
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_DRATINI },
    { 10, 10, SPECIES_DRAGONAIR },
    { 10, 10, SPECIES_DRATINI },
    { 10, 10, SPECIES_DRATINI },
    { 10, 10, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute45_FishingMonsInfo = { 30, gRoute45_FishingMons };

const struct WildPokemon gRoute46_LandMons[] =
{
    { 2, 3, SPECIES_GEODUDE },
    { 2, 3, SPECIES_GEODUDE },
    { 2, 3, SPECIES_GEODUDE },
    { 2, 2, SPECIES_SPEAROW },
    { 2, 2, SPECIES_SPEAROW },
    { 2, 2, SPECIES_SPEAROW },
    { 2, 3, SPECIES_RATTATA },
    { 2, 3, SPECIES_RATTATA },
    { 2, 3, SPECIES_RATTATA },
    { 2, 3, SPECIES_PHANPY },
    { 2, 3, SPECIES_PHANPY },
    { 2, 3, SPECIES_RATTATA },
};

const struct WildPokemonInfo gRoute46_LandMonsInfo = { 20, gRoute46_LandMons };

const struct WildPokemon gRoute46_RockSmashMons[] =
{
    { 20, 20, SPECIES_PINECO },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_HERACROSS },
    { 20, 20, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gRoute46_RockSmashMonsInfo = { 60, gRoute46_RockSmashMons };

const struct WildPokemon gRoute47_LandMons[] =
{
    { 40, 40, SPECIES_CHANSEY },
    { 40, 40, SPECIES_CHANSEY },
    { 40, 40, SPECIES_MILTANK },
    { 40, 40, SPECIES_MILTANK },
    { 33, 40, SPECIES_FARFETCHD },
    { 33, 40, SPECIES_FARFETCHD },
    { 40, 40, SPECIES_RATICATE },
    { 33, 40, SPECIES_FEAROW },
    { 33, 40, SPECIES_FEAROW },
    { 33, 40, SPECIES_GLOOM },
    { 33, 40, SPECIES_GLOOM },
    { 33, 40, SPECIES_DITTO },
};

const struct WildPokemonInfo gRoute47_LandMonsInfo = { 20, gRoute47_LandMons };

const struct WildPokemon gRoute47_WaterMons[] =
{
    { 15, 25, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_SEEL },
    { 15, 20, SPECIES_STARYU },
    { 15, 20, SPECIES_STARYU },
    { 15, 20, SPECIES_STARYU },
};

const struct WildPokemonInfo gRoute47_WaterMonsInfo = { 4, gRoute47_WaterMons };

const struct WildPokemon gRoute47_RockSmashMons[] =
{
    { 20, 20, SPECIES_PINECO },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_HERACROSS },
    { 20, 20, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gRoute47_RockSmashMonsInfo = { 60, gRoute47_RockSmashMons };

const struct WildPokemon gRoute47_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_SHELLDER },
    { 20, 20, SPECIES_CHINCHOU },
    { 40, 40, SPECIES_CHINCHOU },
    { 40, 40, SPECIES_SHELLDER },
    { 40, 40, SPECIES_TENTACRUEL },
    { 40, 40, SPECIES_LANTURN },
    { 40, 40, SPECIES_LANTURN },
};

const struct WildPokemonInfo gRoute47_FishingMonsInfo = { 30, gRoute47_FishingMons };

const struct WildPokemon gRoute48_LandMons[] =
{
    { 22, 26, SPECIES_TAUROS },
    { 22, 26, SPECIES_GLOOM },
    { 22, 26, SPECIES_FARFETCHD },
    { 22, 26, SPECIES_FARFETCHD },
    { 22, 26, SPECIES_SKIPLOOM },
    { 22, 23, SPECIES_FEAROW },
    { 22, 26, SPECIES_GROWLITHE },
    { 22, 26, SPECIES_VULPIX },
    { 22, 26, SPECIES_GROWLITHE },
    { 22, 26, SPECIES_VULPIX },
    { 22, 26, SPECIES_GIRAFARIG },
    { 22, 26, SPECIES_GIRAFARIG },
};

const struct WildPokemonInfo gRoute48_LandMonsInfo = { 20, gRoute48_LandMons };

const struct WildPokemon gRoute48_RockSmashMons[] =
{
    { 20, 20, SPECIES_PINECO },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_HERACROSS },
    { 20, 20, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gRoute48_RockSmashMonsInfo = { 60, gRoute48_RockSmashMons };

const struct WildPokemon gRoute26_LandMons[] =
{
    { 38, 42, SPECIES_MURKROW },
    { 38, 38, SPECIES_ARBOK },
    { 39, 39, SPECIES_PONYTA },
    { 42, 42, SPECIES_RAPIDASH },
    { 38, 42, SPECIES_DODRIO },
    { 38, 38, SPECIES_ARBOK },
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_CHARMANDER },
    { 38, 42, SPECIES_SQUIRTLE },
    { 42, 42, SPECIES_RAPIDASH },
    { 39, 39, SPECIES_PONYTA },
    { 5, 5, SPECIES_CHARMANDER },
};

const struct WildPokemonInfo gRoute26_LandMonsInfo = { 20, gRoute26_LandMons };

const struct WildPokemon gRoute26_WaterMons[] =
{
    { 25, 34, SPECIES_TENTACOOL },
    { 25, 34, SPECIES_TENTACOOL },
    { 25, 34, SPECIES_TENTACOOL },
    { 25, 34, SPECIES_TENTACOOL },
    { 30, 34, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gRoute26_WaterMonsInfo = { 7, gRoute26_WaterMons };

const struct WildPokemon gRoute26_RockSmashMons[] =
{
    { 20, 20, SPECIES_PINECO },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_HERACROSS },
    { 20, 20, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
};

const struct WildPokemonInfo gRoute26_RockSmashMonsInfo = { 60, gRoute26_RockSmashMons };

const struct WildPokemon gRoute26_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_TENTACOOL },
    { 40, 40, SPECIES_TENTACOOL },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_TENTACRUEL },
    { 20, 20, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute26_FishingMonsInfo = { 30, gRoute26_FishingMons };

const struct WildPokemon gRoute27_LandMons[] =
{
    { 38, 42, SPECIES_MURKROW },
    { 38, 38, SPECIES_ARBOK },
    { 39, 39, SPECIES_PONYTA },
    { 42, 42, SPECIES_RAPIDASH },
    { 38, 42, SPECIES_DODRIO },
    { 38, 38, SPECIES_ARBOK },
    { 5, 5, SPECIES_CHIKORITA },
    { 5, 5, SPECIES_TOTODILE },
    { 38, 42, SPECIES_DODRIO },
    { 42, 42, SPECIES_RAPIDASH },
    { 39, 39, SPECIES_PONYTA },
    { 5, 5, SPECIES_CYNDAQUIL },
};

const struct WildPokemonInfo gRoute27_LandMonsInfo = { 20, gRoute27_LandMons };

const struct WildPokemon gRoute27_WaterMons[] =
{
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gRoute27_WaterMonsInfo = { 7, gRoute27_WaterMons };

const struct WildPokemon gRoute27_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_EKANS },
    { 10, 10, SPECIES_EKANS },
    { 10, 10, SPECIES_EKANS },
};

const struct WildPokemonInfo gRoute27_RockSmashMonsInfo = { 60, gRoute27_RockSmashMons };

const struct WildPokemon gRoute27_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_TENTACOOL },
    { 40, 40, SPECIES_TENTACOOL },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_TENTACRUEL },
    { 20, 20, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute27_FishingMonsInfo = { 30, gRoute27_FishingMons };

const struct WildPokemon gRoute28_LandMons[] =
{
    { 39, 39, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_PONYTA },
    { 40, 40, SPECIES_GOLBAT },
    { 42, 42, SPECIES_ARBOK },
    { 39, 39, SPECIES_TANGELA },
    { 40, 40, SPECIES_PONYTA },
    { 40, 40, SPECIES_RAPIDASH },
    { 41, 41, SPECIES_DODUO },
    { 43, 43, SPECIES_DODRIO },
    { 41, 41, SPECIES_DODUO },
    { 43, 43, SPECIES_DODRIO },
    { 42, 42, SPECIES_ARBOK },
};

const struct WildPokemonInfo gRoute28_LandMonsInfo = { 20, gRoute28_LandMons };

const struct WildPokemon gRoute28_WaterMons[] =
{
    { 34, 44, SPECIES_POLIWAG },
    { 34, 44, SPECIES_POLIWAG },
    { 34, 44, SPECIES_POLIWAG },
    { 40, 44, SPECIES_POLIWHIRL },
    { 34, 44, SPECIES_POLIWAG },
    { 34, 44, SPECIES_POLIWAG },
    { 34, 44, SPECIES_POLIWAG },
    { 40, 44, SPECIES_POLIWHIRL },
    { 34, 44, SPECIES_POLIWAG },
    { 40, 44, SPECIES_POLIWHIRL },
    { 34, 44, SPECIES_POLIWAG },
    { 40, 44, SPECIES_POLIWHIRL },
};

const struct WildPokemonInfo gRoute28_WaterMonsInfo = { 7, gRoute28_WaterMons };

const struct WildPokemon gRoute28_RockSmashMons[] =
{
    { 40, 40, SPECIES_FORRETRESS },
    { 40, 40, SPECIES_AIPOM },
    { 40, 40, SPECIES_HERACROSS },
    { 40, 40, SPECIES_SCYTHER },
    { 40, 40, SPECIES_SCYTHER },
};

const struct WildPokemonInfo gRoute28_RockSmashMonsInfo = { 20, gRoute28_RockSmashMons };

const struct WildPokemon gRoute28_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
};

const struct WildPokemonInfo gRoute28_FishingMonsInfo = { 30, gRoute28_FishingMons };

const struct WildPokemon gOlivineCity_PortOutside_LandMons[] =
{
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
};

const struct WildPokemonInfo gOlivineCity_PortOutside_LandMonsInfo = { 0, gOlivineCity_PortOutside_LandMons };

const struct WildPokemon gOlivineCity_PortOutside_WaterMons[] =
{
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gOlivineCity_PortOutside_WaterMonsInfo = { 7, gOlivineCity_PortOutside_WaterMons };

const struct WildPokemon gOlivineCity_PortOutside_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_CHINCHOU },
    { 20, 20, SPECIES_SHELLDER },
    { 40, 40, SPECIES_CHINCHOU },
    { 40, 40, SPECIES_SHELLDER },
    { 40, 40, SPECIES_TENTACRUEL },
    { 40, 40, SPECIES_LANTURN },
};

const struct WildPokemonInfo gOlivineCity_PortOutside_FishingMonsInfo = { 30, gOlivineCity_PortOutside_FishingMons };

const struct WildPokemon gDarkCave_SouthSide_LandMons[] =
{
    { 2, 2, SPECIES_ZUBAT },
    { 2, 2, SPECIES_ZUBAT },
    { 2, 2, SPECIES_TEDDIURSA },
    { 3, 4, SPECIES_GEODUDE },
    { 3, 4, SPECIES_GEODUDE },
    { 3, 4, SPECIES_GEODUDE },
    { 2, 2, SPECIES_DUNSPARCE },
    { 3, 4, SPECIES_ZUBAT },
    { 2, 2, SPECIES_TEDDIURSA },
    { 2, 2, SPECIES_LARVITAR },
    { 4, 4, SPECIES_LARVITAR },
    { 4, 4, SPECIES_DUNSPARCE },
};

const struct WildPokemonInfo gDarkCave_SouthSide_LandMonsInfo = { 5, gDarkCave_SouthSide_LandMons };

const struct WildPokemon gDarkCave_SouthSide_WaterMons[] =
{
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gDarkCave_SouthSide_WaterMonsInfo = { 7, gDarkCave_SouthSide_WaterMons };

const struct WildPokemon gDarkCave_SouthSide_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gDarkCave_SouthSide_FishingMonsInfo = { 30, gDarkCave_SouthSide_FishingMons };

const struct WildPokemon gDarkCave_NorthSide_LandMons[] =
{
    { 33, 33, SPECIES_GEODUDE },
    { 33, 33, SPECIES_ZUBAT },
    { 35, 35, SPECIES_GRAVELER },
    { 35, 35, SPECIES_WOBBUFFET },
    { 33, 33, SPECIES_GEODUDE },
    { 33, 33, SPECIES_ZUBAT },
    { 35, 35, SPECIES_GRAVELER },
    { 30, 35, SPECIES_URSARING },
    { 33, 33, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_URSARING },
    { 33, 33, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gDarkCave_NorthSide_LandMonsInfo = { 5, gDarkCave_NorthSide_LandMons };

const struct WildPokemon gDarkCave_NorthSide_WaterMons[] =
{
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
    { 5, 19, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gDarkCave_NorthSide_WaterMonsInfo = { 7, gDarkCave_NorthSide_WaterMons };

const struct WildPokemon gDarkCave_NorthSide_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gDarkCave_NorthSide_FishingMonsInfo = { 30, gDarkCave_NorthSide_FishingMons };

const struct WildPokemon gSproutTower_2F_LandMons[] =
{
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_GASTLY },
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_RATTATA },
    { 3, 6, SPECIES_RATTATA },
};

const struct WildPokemonInfo gSproutTower_2F_LandMonsInfo = { 10, gSproutTower_2F_LandMons };

const struct WildPokemon gSproutTower_3F_LandMons[] =
{
    { 3, 5, SPECIES_RATTATA },
    { 3, 5, SPECIES_RATTATA },
    { 3, 5, SPECIES_RATTATA },
    { 3, 5, SPECIES_RATTATA },
    { 3, 5, SPECIES_RATTATA },
    { 3, 5, SPECIES_RATTATA },
    { 3, 5, SPECIES_RATTATA },
    { 3, 5, SPECIES_RATTATA },
    { 5, 6, SPECIES_GASTLY },
    { 5, 6, SPECIES_GASTLY },
    { 5, 6, SPECIES_GASTLY },
    { 5, 6, SPECIES_GASTLY },
};

const struct WildPokemonInfo gSproutTower_3F_LandMonsInfo = { 10, gSproutTower_3F_LandMons };

const struct WildPokemon gRuinsOfAlph_Outside_LandMons[] =
{
    { 4, 6, SPECIES_NATU },
    { 4, 6, SPECIES_NATU },
    { 4, 6, SPECIES_NATU },
    { 4, 6, SPECIES_NATU },
    { 4, 6, SPECIES_NATU },
    { 4, 6, SPECIES_NATU },
    { 4, 6, SPECIES_NATU },
    { 4, 6, SPECIES_NATU },
    { 4, 6, SPECIES_WOOPER },
    { 4, 6, SPECIES_UNOWN },
    { 4, 6, SPECIES_UNOWN },
    { 4, 6, SPECIES_UNOWN },
};

const struct WildPokemonInfo gRuinsOfAlph_Outside_LandMonsInfo = { 20, gRuinsOfAlph_Outside_LandMons };

const struct WildPokemon gRuinsOfAlph_Outside_WaterMons[] =
{
    { 15, 19, SPECIES_WOOPER },
    { 15, 19, SPECIES_WOOPER },
    { 15, 19, SPECIES_WOOPER },
    { 15, 24, SPECIES_QUAGSIRE },
    { 15, 24, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gRuinsOfAlph_Outside_WaterMonsInfo = { 7, gRuinsOfAlph_Outside_WaterMons };

const struct WildPokemon gRuinsOfAlph_Outside_RockSmashMons[] =
{
    { 30, 40, SPECIES_SMEARGLE },
    { 30, 40, SPECIES_SMEARGLE },
    { 30, 40, SPECIES_SMEARGLE },
    { 30, 40, SPECIES_SMEARGLE },
    { 30, 40, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo gRuinsOfAlph_Outside_RockSmashMonsInfo = { 60, gRuinsOfAlph_Outside_RockSmashMons };

const struct WildPokemon gRuinsOfAlph_Outside_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 20, 20, SPECIES_POLIWAG },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gRuinsOfAlph_Outside_FishingMonsInfo = { 30, gRuinsOfAlph_Outside_FishingMons };

const struct WildPokemon gRuinsOfAlph_B1F_LandMons[] =
{
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
    { 5, 5, SPECIES_UNOWN },
};

const struct WildPokemonInfo gRuinsOfAlph_B1F_LandMonsInfo = { 10, gRuinsOfAlph_B1F_LandMons };

const struct WildPokemon gUnionCave_1F_LandMons[] =
{
    { 8, 9, SPECIES_GEODUDE },
    { 8, 9, SPECIES_GEODUDE },
    { 8, 8, SPECIES_SANDSHREW },
    { 8, 8, SPECIES_SANDSHREW },
    { 8, 8, SPECIES_SANDSHREW },
    { 9, 9, SPECIES_ZUBAT },
    { 9, 9, SPECIES_ZUBAT },
    { 8, 8, SPECIES_CUBONE },
    { 8, 9, SPECIES_ONIX },
    { 8, 9, SPECIES_ONIX },
    { 8, 8, SPECIES_CUBONE },
    { 9, 9, SPECIES_ZUBAT },
};

const struct WildPokemonInfo gUnionCave_1F_LandMonsInfo = { 10, gUnionCave_1F_LandMons };

const struct WildPokemon gUnionCave_1F_WaterMons[] =
{
    { 15, 19, SPECIES_WOOPER },
    { 15, 19, SPECIES_WOOPER },
    { 15, 19, SPECIES_WOOPER },
    { 15, 24, SPECIES_QUAGSIRE },
    { 15, 24, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gUnionCave_1F_WaterMonsInfo = { 7, gUnionCave_1F_WaterMons };

const struct WildPokemon gUnionCave_1F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_GOLDEEN },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gUnionCave_1F_FishingMonsInfo = { 30, gUnionCave_1F_FishingMons };

const struct WildPokemon gUnionCave_B1F_LandMons[] =
{
    { 8, 9, SPECIES_ZUBAT },
    { 8, 9, SPECIES_ZUBAT },
    { 8, 9, SPECIES_ZUBAT },
    { 8, 8, SPECIES_GEODUDE },
    { 8, 8, SPECIES_GEODUDE },
    { 8, 8, SPECIES_GEODUDE },
    { 8, 8, SPECIES_ONIX },
    { 8, 8, SPECIES_ONIX },
    { 8, 9, SPECIES_MARILL },
    { 8, 9, SPECIES_MARILL },
    { 8, 9, SPECIES_MARILL },
    { 8, 9, SPECIES_MARILL },
};

const struct WildPokemonInfo gUnionCave_B1F_LandMonsInfo = { 10, gUnionCave_B1F_LandMons };

const struct WildPokemon gUnionCave_B1F_WaterMons[] =
{
    { 15, 19, SPECIES_WOOPER },
    { 15, 19, SPECIES_WOOPER },
    { 15, 19, SPECIES_WOOPER },
    { 15, 24, SPECIES_QUAGSIRE },
    { 15, 24, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gUnionCave_B1F_WaterMonsInfo = { 7, gUnionCave_B1F_WaterMons };

const struct WildPokemon gUnionCave_B1F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_GOLDEEN },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gUnionCave_B1F_FishingMonsInfo = { 30, gUnionCave_B1F_FishingMons };

const struct WildPokemon gUnionCave_B2F_LandMons[] =
{
    { 22, 22, SPECIES_ONIX },
    { 25, 25, SPECIES_GOLBAT },
    { 22, 22, SPECIES_CUBONE },
    { 22, 22, SPECIES_ONIX },
    { 25, 25, SPECIES_GOLBAT },
    { 22, 22, SPECIES_CUBONE },
    { 21, 21, SPECIES_RATICATE },
    { 21, 21, SPECIES_RATICATE },
    { 20, 20, SPECIES_QUAGSIRE },
    { 23, 23, SPECIES_KANGASKHAN },
    { 20, 20, SPECIES_QUAGSIRE },
    { 23, 23, SPECIES_KANGASKHAN },
};

const struct WildPokemonInfo gUnionCave_B2F_LandMonsInfo = { 10, gUnionCave_B2F_LandMons };

const struct WildPokemon gUnionCave_B2F_WaterMons[] =
{
    { 15, 19, SPECIES_TENTACOOL },
    { 15, 19, SPECIES_TENTACOOL },
    { 20, 24, SPECIES_QUAGSIRE },
    { 20, 24, SPECIES_TENTACRUEL },
    { 20, 24, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gUnionCave_B2F_WaterMonsInfo = { 7, gUnionCave_B2F_WaterMons };

const struct WildPokemon gUnionCave_B2F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_TENTACOOL },
    { 20, 20, SPECIES_CHINCHOU },
    { 20, 20, SPECIES_SHELLDER },
    { 40, 40, SPECIES_CHINCHOU },
    { 40, 40, SPECIES_SHELLDER },
    { 40, 40, SPECIES_TENTACRUEL },
    { 40, 40, SPECIES_LANTURN },
};

const struct WildPokemonInfo gUnionCave_B2F_FishingMonsInfo = { 30, gUnionCave_B2F_FishingMons };

const struct WildPokemon gSlowpokeWell_B1F_LandMons[] =
{
    { 5, 8, SPECIES_ZUBAT },
    { 5, 8, SPECIES_ZUBAT },
    { 5, 8, SPECIES_ZUBAT },
    { 5, 8, SPECIES_ZUBAT },
    { 5, 8, SPECIES_ZUBAT },
    { 5, 8, SPECIES_ZUBAT },
    { 5, 8, SPECIES_ZUBAT },
    { 6, 8, SPECIES_SLOWPOKE },
    { 6, 8, SPECIES_SLOWPOKE },
    { 6, 8, SPECIES_SLOWPOKE },
    { 6, 8, SPECIES_SLOWPOKE },
    { 6, 8, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo gSlowpokeWell_B1F_LandMonsInfo = { 10, gSlowpokeWell_B1F_LandMons };

const struct WildPokemon gSlowpokeWell_B1F_WaterMons[] =
{
    { 10, 24, SPECIES_SLOWPOKE },
    { 10, 24, SPECIES_SLOWPOKE },
    { 10, 24, SPECIES_SLOWPOKE },
    { 10, 24, SPECIES_SLOWPOKE },
    { 10, 24, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo gSlowpokeWell_B1F_WaterMonsInfo = { 7, gSlowpokeWell_B1F_WaterMons };

const struct WildPokemon gSlowpokeWell_B1F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_GOLDEEN },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gSlowpokeWell_B1F_FishingMonsInfo = { 30, gSlowpokeWell_B1F_FishingMons };

const struct WildPokemon gSlowpokeWell_B2F_LandMons[] =
{
    { 19, 23, SPECIES_ZUBAT },
    { 19, 23, SPECIES_ZUBAT },
    { 19, 23, SPECIES_ZUBAT },
    { 19, 23, SPECIES_ZUBAT },
    { 19, 23, SPECIES_ZUBAT },
    { 19, 23, SPECIES_ZUBAT },
    { 21, 23, SPECIES_SLOWPOKE },
    { 21, 23, SPECIES_SLOWPOKE },
    { 21, 23, SPECIES_SLOWPOKE },
    { 23, 23, SPECIES_GOLBAT },
    { 23, 23, SPECIES_GOLBAT },
    { 23, 23, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSlowpokeWell_B2F_LandMonsInfo = { 10, gSlowpokeWell_B2F_LandMons };

const struct WildPokemon gSlowpokeWell_B2F_WaterMons[] =
{
    { 15, 24, SPECIES_SLOWPOKE },
    { 15, 24, SPECIES_SLOWPOKE },
    { 15, 24, SPECIES_SLOWPOKE },
    { 20, 24, SPECIES_SLOWBRO },
    { 20, 24, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo gSlowpokeWell_B2F_WaterMonsInfo = { 7, gSlowpokeWell_B2F_WaterMons };

const struct WildPokemon gSlowpokeWell_B2F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_GOLDEEN },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gSlowpokeWell_B2F_FishingMonsInfo = { 30, gSlowpokeWell_B2F_FishingMons };

const struct WildPokemon gIlexForest_LandMons[] =
{
    { 8, 8, SPECIES_CATERPIE },
    { 8, 8, SPECIES_VENONAT },
    { 12, 13, SPECIES_PARAS },
    { 8, 8, SPECIES_WEEDLE },
    { 8, 8, SPECIES_CATERPIE },
    { 12, 13, SPECIES_METAPOD },
    { 12, 12, SPECIES_HOOTHOOT },
    { 9, 9, SPECIES_KAKUNA },
    { 12, 12, SPECIES_ODDISH },
    { 13, 13, SPECIES_PARAS },
    { 12, 12, SPECIES_PSYDUCK },
    { 9, 9, SPECIES_KAKUNA },
};

const struct WildPokemonInfo gIlexForest_LandMonsInfo = { 5, gIlexForest_LandMons };

const struct WildPokemon gIlexForest_WaterMons[] =
{
    { 10, 19, SPECIES_PSYDUCK },
    { 10, 19, SPECIES_PSYDUCK },
    { 15, 19, SPECIES_GOLDUCK },
    { 10, 19, SPECIES_PSYDUCK },
    { 10, 19, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo gIlexForest_WaterMonsInfo = { 7, gIlexForest_WaterMons };

const struct WildPokemon gIlexForest_RockSmashMons[] =
{
    { 10, 10, SPECIES_PINECO },
    { 10, 10, SPECIES_EXEGGCUTE },
    { 10, 10, SPECIES_BUTTERFREE },
    { 10, 10, SPECIES_BEEDRILL },
    { 10, 10, SPECIES_BEEDRILL },
};

const struct WildPokemonInfo gIlexForest_RockSmashMonsInfo = { 60, gIlexForest_RockSmashMons };

const struct WildPokemon gIlexForest_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 20, 20, SPECIES_POLIWAG },
    { 10, 10, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gIlexForest_FishingMonsInfo = { 30, gIlexForest_FishingMons };

const struct WildPokemon gNationalPark_Normal_LandMons[] =
{
    { 14, 14, SPECIES_PSYDUCK },
    { 15, 15, SPECIES_MURKROW },
    { 10, 10, SPECIES_SPINARAK },
    { 17, 17, SPECIES_HOOTHOOT },
    { 10, 10, SPECIES_WEEDLE },
    { 14, 14, SPECIES_NIDORAN_F },
    { 15, 15, SPECIES_NIDORAN_M },
    { 17, 17, SPECIES_SUNKERN },
    { 10, 10, SPECIES_VENONAT },
    { 16, 16, SPECIES_SUNKERN },
    { 10, 10, SPECIES_CATERPIE },
    { 16, 16, SPECIES_SCYTHER },
};

const struct WildPokemonInfo gNationalPark_Normal_LandMonsInfo = { 20, gNationalPark_Normal_LandMons };

const struct WildPokemon gNationalPark_BugContest_LandMons[] =
{
    { 14, 14, SPECIES_CATERPIE },
    { 15, 15, SPECIES_WEEDLE },
    { 12, 15, SPECIES_METAPOD },
    { 17, 17, SPECIES_KAKUNA },
    { 12, 17, SPECIES_PARAS },
    { 14, 14, SPECIES_VENONAT },
    { 16, 16, SPECIES_BUTTERFREE },
    { 15, 15, SPECIES_BEEDRILL },
    { 16, 16, SPECIES_SCYTHER },
    { 16, 16, SPECIES_PINSIR },
    { 16, 16, SPECIES_SCYTHER },
    { 16, 16, SPECIES_PINSIR },
};

const struct WildPokemonInfo gNationalPark_BugContest_LandMonsInfo = { 20, gNationalPark_BugContest_LandMons };

const struct WildPokemon gBurnedTower_1F_LandMons[] =
{
    { 13, 13, SPECIES_RATTATA },
    { 14, 14, SPECIES_KOFFING },
    { 15, 15, SPECIES_ZUBAT },
    { 14, 15, SPECIES_SLUGMA },
    { 13, 13, SPECIES_RATTATA },
    { 14, 14, SPECIES_KOFFING },
    { 15, 15, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_SLUGMA },
    { 15, 15, SPECIES_SLUGMA },
    { 15, 15, SPECIES_RATICATE },
    { 15, 15, SPECIES_SLUGMA },
    { 15, 15, SPECIES_RATICATE },
};

const struct WildPokemonInfo gBurnedTower_1F_LandMonsInfo = { 10, gBurnedTower_1F_LandMons };

const struct WildPokemon gBurnedTower_B1F_LandMons[] =
{
    { 16, 17, SPECIES_KOFFING },
    { 18, 18, SPECIES_ZUBAT },
    { 16, 16, SPECIES_MAGMAR },
    { 16, 17, SPECIES_KOFFING },
    { 18, 18, SPECIES_ZUBAT },
    { 17, 17, SPECIES_MAGMAR },
    { 16, 17, SPECIES_KOFFING },
    { 16, 16, SPECIES_ZUBAT },
    { 16, 17, SPECIES_KOFFING },
    { 18, 18, SPECIES_MAGMAR },
    { 16, 16, SPECIES_MISDREAVUS },
    { 16, 16, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo gBurnedTower_B1F_LandMonsInfo = { 10, gBurnedTower_B1F_LandMons };

const struct WildPokemon gCliffEdgeGate_WaterMons[] =
{
    { 20, 30, SPECIES_WOOPER },
    { 20, 30, SPECIES_WOOPER },
    { 20, 30, SPECIES_QUAGSIRE },
    { 30, 40, SPECIES_QUAGSIRE },
    { 30, 40, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gCliffEdgeGate_WaterMonsInfo = { 4, gCliffEdgeGate_WaterMons };

const struct WildPokemon gMtMortar_1F_South_LandMons[] =
{
    { 20, 20, SPECIES_GEODUDE },
    { 20, 20, SPECIES_ZUBAT },
    { 21, 21, SPECIES_MARILL },
    { 22, 22, SPECIES_GOLBAT },
    { 20, 20, SPECIES_GEODUDE },
    { 20, 20, SPECIES_ZUBAT },
    { 21, 21, SPECIES_MACHOP },
    { 22, 22, SPECIES_GOLBAT },
    { 21, 21, SPECIES_RHYHORN },
    { 22, 22, SPECIES_CUBONE },
    { 21, 21, SPECIES_RHYHORN },
    { 22, 22, SPECIES_CUBONE },
};

const struct WildPokemonInfo gMtMortar_1F_South_LandMonsInfo = { 5, gMtMortar_1F_South_LandMons };

const struct WildPokemon gMtMortar_1F_South_WaterMons[] =
{
    { 15, 19, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_MARILL },
    { 20, 24, SPECIES_SEAKING },
    { 15, 19, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_MARILL },
};

const struct WildPokemonInfo gMtMortar_1F_South_WaterMonsInfo = { 7, gMtMortar_1F_South_WaterMons };

const struct WildPokemon gMtMortar_1F_South_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gMtMortar_1F_South_FishingMonsInfo = { 30, gMtMortar_1F_South_FishingMons };

const struct WildPokemon gMtMortar_1F_North_LandMons[] =
{
    { 20, 20, SPECIES_GEODUDE },
    { 20, 20, SPECIES_ZUBAT },
    { 21, 21, SPECIES_MARILL },
    { 22, 22, SPECIES_GOLBAT },
    { 20, 20, SPECIES_GEODUDE },
    { 20, 20, SPECIES_ZUBAT },
    { 21, 21, SPECIES_MACHOP },
    { 22, 22, SPECIES_GOLBAT },
    { 21, 21, SPECIES_RHYHORN },
    { 22, 22, SPECIES_CUBONE },
    { 21, 21, SPECIES_RHYHORN },
    { 22, 22, SPECIES_CUBONE },
};

const struct WildPokemonInfo gMtMortar_1F_North_LandMonsInfo = { 5, gMtMortar_1F_North_LandMons };

const struct WildPokemon gMtMortar_1F_North_WaterMons[] =
{
    { 15, 19, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_MARILL },
    { 20, 24, SPECIES_SEAKING },
    { 15, 19, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_MARILL },
};

const struct WildPokemonInfo gMtMortar_1F_North_WaterMonsInfo = { 7, gMtMortar_1F_North_WaterMons };

const struct WildPokemon gMtMortar_1F_North_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gMtMortar_1F_North_FishingMonsInfo = { 30, gMtMortar_1F_North_FishingMons };

const struct WildPokemon gMtMortar_2F_LandMons[] =
{
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_MACHOKE },
    { 31, 31, SPECIES_GEODUDE },
    { 30, 30, SPECIES_RATICATE },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_MACHOKE },
    { 31, 31, SPECIES_GEODUDE },
    { 30, 30, SPECIES_RATICATE },
    { 28, 28, SPECIES_MARILL },
    { 30, 30, SPECIES_GOLBAT },
    { 28, 28, SPECIES_MACHOP },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gMtMortar_2F_LandMonsInfo = { 5, gMtMortar_2F_LandMons };

const struct WildPokemon gMtMortar_2F_WaterMons[] =
{
    { 20, 24, SPECIES_GOLDEEN },
    { 25, 29, SPECIES_MARILL },
    { 25, 29, SPECIES_SEAKING },
    { 20, 24, SPECIES_GOLDEEN },
    { 25, 29, SPECIES_MARILL },
};

const struct WildPokemonInfo gMtMortar_2F_WaterMonsInfo = { 7, gMtMortar_2F_WaterMons };

const struct WildPokemon gMtMortar_2F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gMtMortar_2F_FishingMonsInfo = { 30, gMtMortar_2F_FishingMons };

const struct WildPokemon gMtMortar_B1F_LandMons[] =
{
    { 20, 20, SPECIES_GEODUDE },
    { 20, 20, SPECIES_ZUBAT },
    { 21, 21, SPECIES_MARILL },
    { 22, 22, SPECIES_GOLBAT },
    { 20, 20, SPECIES_GEODUDE },
    { 20, 20, SPECIES_ZUBAT },
    { 21, 21, SPECIES_MACHOP },
    { 22, 22, SPECIES_GOLBAT },
    { 21, 21, SPECIES_RHYHORN },
    { 22, 22, SPECIES_CUBONE },
    { 21, 21, SPECIES_RHYHORN },
    { 22, 22, SPECIES_CUBONE },
};

const struct WildPokemonInfo gMtMortar_B1F_LandMonsInfo = { 5, gMtMortar_B1F_LandMons };

const struct WildPokemon gMtMortar_B1F_WaterMons[] =
{
    { 15, 19, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_MARILL },
    { 20, 24, SPECIES_SEAKING },
    { 15, 19, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_MARILL },
};

const struct WildPokemonInfo gMtMortar_B1F_WaterMonsInfo = { 7, gMtMortar_B1F_WaterMons };

const struct WildPokemon gMtMortar_B1F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GOLDEEN },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_SEAKING },
    { 40, 40, SPECIES_SEAKING },
    { 20, 20, SPECIES_GOLDEEN },
    { 20, 20, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gMtMortar_B1F_FishingMonsInfo = { 30, gMtMortar_B1F_FishingMons };

const struct WildPokemon gLakeOfRage_WaterMons[] =
{
    { 10, 11, SPECIES_MAGIKARP },
    { 12, 12, SPECIES_MAGIKARP },
    { 10, 13, SPECIES_MAGIKARP },
    { 13, 13, SPECIES_MAGIKARP },
    { 10, 13, SPECIES_GYARADOS },
    { 13, 13, SPECIES_MAGIKARP },
    { 12, 12, SPECIES_GYARADOS },
    { 15, 15, SPECIES_GYARADOS },
    { 15, 19, SPECIES_GYARADOS },
    { 15, 19, SPECIES_GYARADOS },
    { 15, 19, SPECIES_GYARADOS },
    { 15, 19, SPECIES_GYARADOS },
};

const struct WildPokemonInfo gLakeOfRage_WaterMonsInfo = { 7, gLakeOfRage_WaterMons };

const struct WildPokemon gLakeOfRage_RockSmashMons[] =
{
    { 20, 20, SPECIES_PINECO },
    { 20, 20, SPECIES_EXEGGCUTE },
    { 20, 20, SPECIES_VENONAT },
    { 20, 20, SPECIES_VENONAT },
    { 20, 20, SPECIES_VENONAT },
};

const struct WildPokemonInfo gLakeOfRage_RockSmashMonsInfo = { 60, gLakeOfRage_RockSmashMons };

const struct WildPokemon gLakeOfRage_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_GYARADOS },
    { 40, 40, SPECIES_GYARADOS },
    { 40, 40, SPECIES_GYARADOS },
    { 40, 40, SPECIES_GYARADOS },
    { 40, 40, SPECIES_GYARADOS },
    { 100, 100, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gLakeOfRage_FishingMonsInfo = { 30, gLakeOfRage_FishingMons };

const struct WildPokemon gIcePath_1F_LandMons[] =
{
    { 21, 23, SPECIES_DELIBIRD },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 24, SPECIES_GOLBAT },
    { 21, 23, SPECIES_SWINUB },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 24, SPECIES_GOLBAT },
    { 21, 23, SPECIES_SWINUB },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 24, SPECIES_GOLBAT },
    { 22, 24, SPECIES_GOLBAT },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 24, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gIcePath_1F_LandMonsInfo = { 10, gIcePath_1F_LandMons };

const struct WildPokemon gIcePath_B1F_LandMons[] =
{
    { 32, 32, SPECIES_DELIBIRD },
    { 33, 33, SPECIES_JYNX },
    { 33, 33, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SNEASEL },
    { 32, 32, SPECIES_SWINUB },
    { 33, 33, SPECIES_JYNX },
    { 33, 33, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SNEASEL },
    { 33, 33, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SNEASEL },
    { 33, 33, SPECIES_JYNX },
    { 33, 33, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gIcePath_B1F_LandMonsInfo = { 10, gIcePath_B1F_LandMons };

const struct WildPokemon gIcePath_B2F_LandMons[] =
{
    { 32, 32, SPECIES_DELIBIRD },
    { 33, 33, SPECIES_JYNX },
    { 33, 33, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SNEASEL },
    { 32, 32, SPECIES_SWINUB },
    { 33, 33, SPECIES_JYNX },
    { 33, 33, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SNEASEL },
    { 33, 33, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SNEASEL },
    { 33, 33, SPECIES_JYNX },
    { 33, 33, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gIcePath_B2F_LandMonsInfo = { 10, gIcePath_B2F_LandMons };

const struct WildPokemon gIcePath_B3F_LandMons[] =
{
    { 32, 36, SPECIES_JYNX },
    { 34, 34, SPECIES_SNEASEL },
    { 35, 35, SPECIES_GOLBAT },
    { 36, 36, SPECIES_DELIBIRD },
    { 32, 36, SPECIES_JYNX },
    { 34, 34, SPECIES_SNEASEL },
    { 35, 35, SPECIES_GOLBAT },
    { 36, 36, SPECIES_SWINUB },
    { 34, 34, SPECIES_SNEASEL },
    { 36, 36, SPECIES_SWINUB },
    { 32, 36, SPECIES_JYNX },
    { 36, 36, SPECIES_SWINUB },
};

const struct WildPokemonInfo gIcePath_B3F_LandMonsInfo = { 10, gIcePath_B3F_LandMons };

const struct WildPokemon gIcePath_B4F_LandMons[] =
{
    { 32, 36, SPECIES_JYNX },
    { 34, 34, SPECIES_SNEASEL },
    { 35, 35, SPECIES_GOLBAT },
    { 36, 36, SPECIES_DELIBIRD },
    { 32, 36, SPECIES_JYNX },
    { 34, 34, SPECIES_SNEASEL },
    { 35, 35, SPECIES_GOLBAT },
    { 36, 36, SPECIES_SWINUB },
    { 34, 34, SPECIES_SNEASEL },
    { 36, 36, SPECIES_SWINUB },
    { 32, 36, SPECIES_JYNX },
    { 36, 36, SPECIES_SWINUB },
};

const struct WildPokemonInfo gIcePath_B4F_LandMonsInfo = { 10, gIcePath_B4F_LandMons };

const struct WildPokemon gDragonsDen_Cavern_WaterMons[] =
{
    { 10, 19, SPECIES_MAGIKARP },
    { 10, 14, SPECIES_HORSEA },
    { 10, 19, SPECIES_DRATINI },
    { 10, 14, SPECIES_DRATINI },
    { 10, 19, SPECIES_DRATINI },
};

const struct WildPokemonInfo gDragonsDen_Cavern_WaterMonsInfo = { 7, gDragonsDen_Cavern_WaterMons };

const struct WildPokemon gDragonsDen_Cavern_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_DRATINI },
    { 20, 20, SPECIES_MAGIKARP },
    { 30, 30, SPECIES_DRATINI },
    { 30, 30, SPECIES_DRATINI },
    { 30, 30, SPECIES_SEADRA },
    { 30, 30, SPECIES_DRAGONAIR },
    { 30, 30, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo gDragonsDen_Cavern_FishingMonsInfo = { 30, gDragonsDen_Cavern_FishingMons };

const struct WildPokemon gWhirlIslands_1F_LandMons[] =
{
    { 26, 27, SPECIES_KRABBY },
    { 25, 25, SPECIES_GOLBAT },
    { 24, 26, SPECIES_SEEL },
    { 25, 25, SPECIES_CORSOLA },
    { 26, 27, SPECIES_KRABBY },
    { 24, 26, SPECIES_NATU },
    { 25, 25, SPECIES_CORSOLA },
    { 24, 26, SPECIES_SEEL },
    { 24, 26, SPECIES_SEEL },
    { 25, 25, SPECIES_CORSOLA },
    { 25, 25, SPECIES_CORSOLA },
    { 25, 25, SPECIES_PIDGEOTTO },
};

const struct WildPokemonInfo gWhirlIslands_1F_LandMonsInfo = { 10, gWhirlIslands_1F_LandMons };

const struct WildPokemon gWhirlIslands_1F_WaterMons[] =
{
    { 20, 24, SPECIES_TENTACOOL },
    { 15, 19, SPECIES_HORSEA },
    { 20, 24, SPECIES_MANTINE },
    { 20, 24, SPECIES_MANTINE },
    { 15, 19, SPECIES_MANTINE },
};

const struct WildPokemonInfo gWhirlIslands_1F_WaterMonsInfo = { 7, gWhirlIslands_1F_WaterMons };

const struct WildPokemon gWhirlIslands_1F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_KRABBY },
    { 20, 20, SPECIES_STARYU },
    { 20, 20, SPECIES_HORSEA },
    { 40, 40, SPECIES_KRABBY },
    { 40, 40, SPECIES_HORSEA },
    { 40, 40, SPECIES_KINGLER },
    { 40, 40, SPECIES_SEADRA },
    { 40, 40, SPECIES_SEADRA },
};

const struct WildPokemonInfo gWhirlIslands_1F_FishingMonsInfo = { 30, gWhirlIslands_1F_FishingMons };

const struct WildPokemon gWhirlIslands_B1F_LandMons[] =
{
    { 26, 27, SPECIES_KRABBY },
    { 25, 25, SPECIES_GOLBAT },
    { 24, 26, SPECIES_SEEL },
    { 25, 25, SPECIES_CORSOLA },
    { 26, 27, SPECIES_KRABBY },
    { 24, 26, SPECIES_NATU },
    { 25, 25, SPECIES_CORSOLA },
    { 24, 26, SPECIES_SEEL },
    { 24, 26, SPECIES_SEEL },
    { 25, 25, SPECIES_CORSOLA },
    { 25, 25, SPECIES_CORSOLA },
    { 25, 25, SPECIES_PIDGEOTTO },
};

const struct WildPokemonInfo gWhirlIslands_B1F_LandMonsInfo = { 10, gWhirlIslands_B1F_LandMons };

const struct WildPokemon gWhirlIslands_B1F_WaterMons[] =
{
    { 20, 24, SPECIES_TENTACOOL },
    { 15, 19, SPECIES_HORSEA },
    { 20, 24, SPECIES_MANTINE },
    { 20, 24, SPECIES_MANTINE },
    { 15, 19, SPECIES_MANTINE },
};

const struct WildPokemonInfo gWhirlIslands_B1F_WaterMonsInfo = { 7, gWhirlIslands_B1F_WaterMons };

const struct WildPokemon gWhirlIslands_B1F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_KRABBY },
    { 20, 20, SPECIES_STARYU },
    { 20, 20, SPECIES_HORSEA },
    { 40, 40, SPECIES_KRABBY },
    { 40, 40, SPECIES_HORSEA },
    { 40, 40, SPECIES_KINGLER },
    { 40, 40, SPECIES_SEADRA },
    { 40, 40, SPECIES_SEADRA },
};

const struct WildPokemonInfo gWhirlIslands_B1F_FishingMonsInfo = { 30, gWhirlIslands_B1F_FishingMons };

const struct WildPokemon gWhirlIslands_B1F_Inner_LandMons[] =
{
    { 26, 27, SPECIES_KRABBY },
    { 25, 25, SPECIES_GOLBAT },
    { 24, 26, SPECIES_SEEL },
    { 25, 25, SPECIES_CORSOLA },
    { 26, 27, SPECIES_KRABBY },
    { 24, 26, SPECIES_NATU },
    { 25, 25, SPECIES_CORSOLA },
    { 24, 26, SPECIES_SEEL },
    { 24, 26, SPECIES_SEEL },
    { 25, 25, SPECIES_CORSOLA },
    { 25, 25, SPECIES_CORSOLA },
    { 25, 25, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gWhirlIslands_B1F_Inner_LandMonsInfo = { 10, gWhirlIslands_B1F_Inner_LandMons };

const struct WildPokemon gWhirlIslands_B2F_LandMons[] =
{
    { 28, 29, SPECIES_GOLDUCK },
    { 27, 28, SPECIES_DROWZEE },
    { 26, 28, SPECIES_SLOWBRO },
    { 27, 28, SPECIES_SLOWBRO },
    { 28, 29, SPECIES_SKARMORY },
    { 26, 28, SPECIES_SEEL },
    { 27, 28, SPECIES_GOLBAT },
    { 26, 28, SPECIES_SEEL },
    { 26, 28, SPECIES_SEEL },
    { 27, 28, SPECIES_DEWGONG },
    { 27, 28, SPECIES_DEWGONG },
    { 27, 28, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gWhirlIslands_B2F_LandMonsInfo = { 10, gWhirlIslands_B2F_LandMons };

const struct WildPokemon gWhirlIslands_B2F_WaterMons[] =
{
    { 15, 24, SPECIES_HORSEA },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_HORSEA },
    { 15, 24, SPECIES_HORSEA },
    { 20, 24, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gWhirlIslands_B2F_WaterMonsInfo = { 7, gWhirlIslands_B2F_WaterMons };

const struct WildPokemon gWhirlIslands_B2F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_KRABBY },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_HORSEA },
    { 40, 40, SPECIES_KRABBY },
    { 40, 40, SPECIES_HORSEA },
    { 40, 40, SPECIES_KINGLER },
    { 40, 40, SPECIES_SEADRA },
    { 40, 40, SPECIES_SEADRA },
};

const struct WildPokemonInfo gWhirlIslands_B2F_FishingMonsInfo = { 30, gWhirlIslands_B2F_FishingMons };

const struct WildPokemon gWhirlIslands_B3F_LandMons[] =
{
    { 28, 29, SPECIES_GOLDUCK },
    { 27, 28, SPECIES_DROWZEE },
    { 26, 28, SPECIES_SLOWBRO },
    { 27, 28, SPECIES_SLOWBRO },
    { 28, 29, SPECIES_SKARMORY },
    { 26, 28, SPECIES_SEEL },
    { 27, 28, SPECIES_GOLBAT },
    { 26, 28, SPECIES_SEEL },
    { 26, 28, SPECIES_SEEL },
    { 27, 28, SPECIES_DEWGONG },
    { 27, 28, SPECIES_DEWGONG },
    { 27, 28, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gWhirlIslands_B3F_LandMonsInfo = { 10, gWhirlIslands_B3F_LandMons };

const struct WildPokemon gWhirlIslands_B3F_WaterMons[] =
{
    { 15, 24, SPECIES_HORSEA },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_HORSEA },
    { 15, 24, SPECIES_HORSEA },
    { 20, 24, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gWhirlIslands_B3F_WaterMonsInfo = { 7, gWhirlIslands_B3F_WaterMons };

const struct WildPokemon gWhirlIslands_B3F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_KRABBY },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_HORSEA },
    { 40, 40, SPECIES_KRABBY },
    { 40, 40, SPECIES_HORSEA },
    { 40, 40, SPECIES_KINGLER },
    { 40, 40, SPECIES_SEADRA },
    { 40, 40, SPECIES_SEADRA },
};

const struct WildPokemonInfo gWhirlIslands_B3F_FishingMonsInfo = { 30, gWhirlIslands_B3F_FishingMons };

const struct WildPokemon gWhirlIslands_Descent_LandMons[] =
{
    { 28, 29, SPECIES_DEWGONG },
    { 27, 28, SPECIES_XATU },
    { 26, 28, SPECIES_TENTACRUEL },
    { 27, 28, SPECIES_TENTACRUEL },
    { 28, 29, SPECIES_GOLBAT },
    { 26, 28, SPECIES_SEEL },
    { 27, 28, SPECIES_GOLBAT },
    { 26, 28, SPECIES_SEEL },
    { 26, 28, SPECIES_TENTACRUEL },
    { 27, 28, SPECIES_TENTACRUEL },
    { 27, 28, SPECIES_OMANYTE },
    { 27, 28, SPECIES_KABUTO },
};

const struct WildPokemonInfo gWhirlIslands_Descent_LandMonsInfo = { 10, gWhirlIslands_Descent_LandMons };

const struct WildPokemon gWhirlIslands_Descent_WaterMons[] =
{
    { 15, 24, SPECIES_HORSEA },
    { 20, 24, SPECIES_TENTACRUEL },
    { 15, 24, SPECIES_HORSEA },
    { 15, 24, SPECIES_HORSEA },
    { 20, 24, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gWhirlIslands_Descent_WaterMonsInfo = { 7, gWhirlIslands_Descent_WaterMons };

const struct WildPokemon gWhirlIslands_Descent_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_KRABBY },
    { 20, 20, SPECIES_KRABBY },
    { 20, 20, SPECIES_MAGIKARP },
    { 20, 20, SPECIES_HORSEA },
    { 40, 40, SPECIES_KRABBY },
    { 40, 40, SPECIES_HORSEA },
    { 40, 40, SPECIES_KINGLER },
    { 40, 40, SPECIES_SEADRA },
    { 40, 40, SPECIES_SEADRA },
};

const struct WildPokemonInfo gWhirlIslands_Descent_FishingMonsInfo = { 30, gWhirlIslands_Descent_FishingMons };

const struct WildPokemon gTinTower_3F_LandMons[] =
{
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_RATTATA },
    { 35, 45, SPECIES_RATICATE },
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_FEAROW },
    { 35, 45, SPECIES_NOCTOWL },
    { 35, 45, SPECIES_FURRET },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo gTinTower_3F_LandMonsInfo = { 20, gTinTower_3F_LandMons };

const struct WildPokemon gTinTower_4F_LandMons[] =
{
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_RATTATA },
    { 35, 45, SPECIES_RATICATE },
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_FEAROW },
    { 35, 45, SPECIES_NOCTOWL },
    { 35, 45, SPECIES_FURRET },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo gTinTower_4F_LandMonsInfo = { 20, gTinTower_4F_LandMons };

const struct WildPokemon gTinTower_5F_LandMons[] =
{
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_RATTATA },
    { 35, 45, SPECIES_RATICATE },
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_FEAROW },
    { 35, 45, SPECIES_NOCTOWL },
    { 35, 45, SPECIES_FURRET },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo gTinTower_5F_LandMonsInfo = { 20, gTinTower_5F_LandMons };

const struct WildPokemon gTinTower_6F_LandMons[] =
{
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_RATTATA },
    { 35, 45, SPECIES_RATICATE },
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_FEAROW },
    { 35, 45, SPECIES_NOCTOWL },
    { 35, 45, SPECIES_FURRET },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo gTinTower_6F_LandMonsInfo = { 20, gTinTower_6F_LandMons };

const struct WildPokemon gTinTower_7F_LandMons[] =
{
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_RATTATA },
    { 35, 45, SPECIES_RATICATE },
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_FEAROW },
    { 35, 45, SPECIES_NOCTOWL },
    { 35, 45, SPECIES_FURRET },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo gTinTower_7F_LandMonsInfo = { 20, gTinTower_7F_LandMons };

const struct WildPokemon gTinTower_8F_LandMons[] =
{
    { 35, 45, SPECIES_GASTLY },
    { 35, 45, SPECIES_GASTLY },
    { 35, 45, SPECIES_NOCTOWL },
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_FEAROW },
    { 35, 45, SPECIES_NOCTOWL },
    { 35, 45, SPECIES_FEAROW },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo gTinTower_8F_LandMonsInfo = { 20, gTinTower_8F_LandMons };

const struct WildPokemon gTinTower_9F_LandMons[] =
{
    { 35, 45, SPECIES_GASTLY },
    { 35, 45, SPECIES_GASTLY },
    { 35, 45, SPECIES_NOCTOWL },
    { 35, 45, SPECIES_AIPOM },
    { 35, 45, SPECIES_FEAROW },
    { 35, 45, SPECIES_NOCTOWL },
    { 35, 45, SPECIES_FEAROW },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
    { 35, 45, SPECIES_HAUNTER },
    { 35, 45, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo gTinTower_9F_LandMonsInfo = { 20, gTinTower_9F_LandMons };

const struct WildPokemon gTohjoFalls_Cavern_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_RATICATE },
    { 30, 30, SPECIES_GOLBAT },
    { 28, 30, SPECIES_SLOWPOKE },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_RATICATE },
    { 30, 30, SPECIES_GOLBAT },
    { 30, 30, SPECIES_RATTATA },
    { 28, 30, SPECIES_SLOWPOKE },
    { 28, 30, SPECIES_SLOWPOKE },
    { 28, 30, SPECIES_SLOWPOKE },
    { 30, 30, SPECIES_RATTATA },
};

const struct WildPokemonInfo gTohjoFalls_Cavern_LandMonsInfo = { 10, gTohjoFalls_Cavern_LandMons };

const struct WildPokemon gTohjoFalls_Cavern_WaterMons[] =
{
    { 20, 24, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_SLOWPOKE },
    { 20, 24, SPECIES_SLOWPOKE },
    { 20, 24, SPECIES_SEAKING },
};

const struct WildPokemonInfo gTohjoFalls_Cavern_WaterMonsInfo = { 7, gTohjoFalls_Cavern_WaterMons };

const struct WildPokemon gTohjoFalls_Cavern_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_GOLDEEN },
    { 20, 24, SPECIES_MAGIKARP },
    { 24, 24, SPECIES_SEAKING },
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_GOLDEEN },
    { 24, 24, SPECIES_SEAKING },
    { 20, 24, SPECIES_SLOWPOKE },
    { 24, 24, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo gTohjoFalls_Cavern_FishingMonsInfo = { 30, gTohjoFalls_Cavern_FishingMons };

const struct WildPokemon gMtSilver_Outside_LandMons[] =
{
    { 50, 50, SPECIES_URSARING },
    { 51, 51, SPECIES_QUAGSIRE },
    { 54, 54, SPECIES_SKARMORY },
    { 54, 54, SPECIES_RAPIDASH },
    { 50, 50, SPECIES_URSARING },
    { 52, 52, SPECIES_GOLEM },
    { 54, 54, SPECIES_VENUSAUR },
    { 52, 53, SPECIES_DONPHAN },
    { 50, 50, SPECIES_CHARIZARD },
    { 50, 50, SPECIES_BLASTOISE },
    { 54, 54, SPECIES_HOUNDOOM },
    { 50, 50, SPECIES_CROBAT },
};

const struct WildPokemonInfo gMtSilver_Outside_LandMonsInfo = { 10, gMtSilver_Outside_LandMons };

const struct WildPokemon gMtSilver_Outside_WaterMons[] =
{
    { 34, 44, SPECIES_POLIWAG },
    { 40, 44, SPECIES_POLIWHIRL },
    { 34, 44, SPECIES_POLIWAG },
    { 34, 44, SPECIES_POLIWAG },
    { 34, 44, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gMtSilver_Outside_WaterMonsInfo = { 7, gMtSilver_Outside_WaterMons };

const struct WildPokemon gMtSilver_Outside_RockSmashMons[] =
{
    { 40, 40, SPECIES_FORRETRESS },
    { 40, 40, SPECIES_AIPOM },
    { 40, 40, SPECIES_HERACROSS },
    { 40, 40, SPECIES_SCYTHER },
    { 40, 40, SPECIES_SCYTHER },
};

const struct WildPokemonInfo gMtSilver_Outside_RockSmashMonsInfo = { 60, gMtSilver_Outside_RockSmashMons };

const struct WildPokemon gMtSilver_Outside_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gMtSilver_Outside_FishingMonsInfo = { 30, gMtSilver_Outside_FishingMons };

const struct WildPokemon gMtSilver_1F_ItemRoom_LandMons[] =
{
    { 63, 63, SPECIES_GRAVELER },
    { 64, 64, SPECIES_URSARING },
    { 62, 62, SPECIES_ONIX },
    { 65, 65, SPECIES_GOLDUCK },
    { 63, 63, SPECIES_ELECTABUZZ },
    { 64, 64, SPECIES_URSARING },
    { 62, 62, SPECIES_ONIX },
    { 35, 40, SPECIES_PUPITAR },
    { 65, 65, SPECIES_MAGMAR },
    { 65, 65, SPECIES_GOLBAT },
    { 15, 20, SPECIES_LARVITAR },
    { 65, 65, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gMtSilver_1F_ItemRoom_LandMonsInfo = { 10, gMtSilver_1F_ItemRoom_LandMons };

const struct WildPokemon gMtSilver_1F_ItemRoom_WaterMons[] =
{
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
};

const struct WildPokemonInfo gMtSilver_1F_ItemRoom_WaterMonsInfo = { 7, gMtSilver_1F_ItemRoom_WaterMons };

const struct WildPokemon gMtSilver_1F_ItemRoom_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gMtSilver_1F_ItemRoom_FishingMonsInfo = { 30, gMtSilver_1F_ItemRoom_FishingMons };

const struct WildPokemon gMtSilver_1F_WaterfallRoom_LandMons[] =
{
    { 63, 63, SPECIES_GOLEM },
    { 64, 64, SPECIES_URSARING },
    { 62, 62, SPECIES_ONIX },
    { 65, 65, SPECIES_MISDREAVUS },
    { 63, 63, SPECIES_ELECTABUZZ },
    { 64, 64, SPECIES_URSARING },
    { 62, 62, SPECIES_GOLDUCK },
    { 35, 40, SPECIES_PUPITAR },
    { 65, 65, SPECIES_MAGMAR },
    { 65, 65, SPECIES_GOLBAT },
    { 15, 20, SPECIES_LARVITAR },
    { 65, 65, SPECIES_PARASECT },
};

const struct WildPokemonInfo gMtSilver_1F_WaterfallRoom_LandMonsInfo = { 10, gMtSilver_1F_WaterfallRoom_LandMons };

const struct WildPokemon gMtSilver_1F_WaterfallRoom_WaterMons[] =
{
    { 60, 65, SPECIES_GOLDUCK },
    { 60, 65, SPECIES_SEAKING },
    { 40, 60, SPECIES_LAPRAS },
    { 40, 60, SPECIES_LAPRAS },
    { 40, 60, SPECIES_LAPRAS },
};

const struct WildPokemonInfo gMtSilver_1F_WaterfallRoom_WaterMonsInfo = { 7, gMtSilver_1F_WaterfallRoom_WaterMons };

const struct WildPokemon gMtSilver_1F_WaterfallRoom_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gMtSilver_1F_WaterfallRoom_FishingMonsInfo = { 30, gMtSilver_1F_WaterfallRoom_FishingMons };

const struct WildPokemon gMtSilver_1F_MoltresRoom_LandMons[] =
{
    { 63, 63, SPECIES_GRAVELER },
    { 64, 64, SPECIES_GOLDUCK },
    { 62, 62, SPECIES_ONIX },
    { 65, 65, SPECIES_MISDREAVUS },
    { 63, 63, SPECIES_ELECTABUZZ },
    { 64, 64, SPECIES_MACHOKE },
    { 62, 62, SPECIES_ONIX },
    { 35, 40, SPECIES_PUPITAR },
    { 65, 65, SPECIES_MAGMAR },
    { 65, 65, SPECIES_GOLBAT },
    { 62, 64, SPECIES_PARASECT },
    { 65, 65, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gMtSilver_1F_MoltresRoom_LandMonsInfo = { 10, gMtSilver_1F_MoltresRoom_LandMons };

const struct WildPokemon gMtSilver_1F_MoltresRoom_WaterMons[] =
{
    { 35, 39, SPECIES_SEAKING },
    { 35, 39, SPECIES_GOLDUCK },
    { 35, 39, SPECIES_GOLDEEN },
    { 35, 39, SPECIES_SEAKING },
    { 35, 39, SPECIES_SEAKING },
};

const struct WildPokemonInfo gMtSilver_1F_MoltresRoom_WaterMonsInfo = { 7, gMtSilver_1F_MoltresRoom_WaterMons };

const struct WildPokemon gMtSilver_1F_MoltresRoom_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gMtSilver_1F_MoltresRoom_FishingMonsInfo = { 30, gMtSilver_1F_MoltresRoom_FishingMons };

const struct WildPokemon gMtSilver_MountainSide_LandMons[] =
{
    { 61, 69, SPECIES_URSARING },
    { 68, 68, SPECIES_ONIX },
    { 68, 68, SPECIES_GOLEM },
    { 65, 65, SPECIES_SKARMORY },
    { 61, 69, SPECIES_MACHOKE },
    { 68, 68, SPECIES_ONIX },
    { 68, 68, SPECIES_GOLEM },
    { 61, 69, SPECIES_HOUNDOOM },
    { 61, 69, SPECIES_HOUNDOOM },
    { 65, 65, SPECIES_RAPIDASH },
    { 61, 69, SPECIES_RAPIDASH },
    { 65, 65, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo gMtSilver_MountainSide_LandMonsInfo = { 20, gMtSilver_MountainSide_LandMons };

const struct WildPokemon gMtSilver_MountainSide_WaterMons[] =
{
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
    { 5, 5, SPECIES_NONE },
};

const struct WildPokemonInfo gMtSilver_MountainSide_WaterMonsInfo = { 7, gMtSilver_MountainSide_WaterMons };

const struct WildPokemon gMtSilver_MountainSide_RockSmashMons[] =
{
    { 40, 40, SPECIES_FORRETRESS },
    { 40, 40, SPECIES_AIPOM },
    { 40, 40, SPECIES_HERACROSS },
    { 40, 40, SPECIES_SCYTHER },
    { 40, 40, SPECIES_SCYTHER },
};

const struct WildPokemonInfo gMtSilver_MountainSide_RockSmashMonsInfo = { 60, gMtSilver_MountainSide_RockSmashMons };

const struct WildPokemon gMtSilver_MountainSide_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gMtSilver_MountainSide_FishingMonsInfo = { 30, gMtSilver_MountainSide_FishingMons };

const struct WildPokemon gMtSilver_2F_LandMons[] =
{
    { 63, 63, SPECIES_GOLEM },
    { 64, 64, SPECIES_MACHOKE },
    { 62, 62, SPECIES_QUAGSIRE },
    { 65, 65, SPECIES_MAGMAR },
    { 63, 63, SPECIES_ELECTABUZZ },
    { 64, 64, SPECIES_GOLDUCK },
    { 62, 62, SPECIES_QUAGSIRE },
    { 35, 40, SPECIES_PUPITAR },
    { 65, 65, SPECIES_GOLBAT },
    { 65, 65, SPECIES_GOLBAT },
    { 62, 64, SPECIES_PARASECT },
    { 65, 65, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gMtSilver_2F_LandMonsInfo = { 10, gMtSilver_2F_LandMons };

const struct WildPokemon gMtSilver_2F_WaterMons[] =
{
    { 60, 65, SPECIES_GOLDUCK },
    { 60, 65, SPECIES_QUAGSIRE },
    { 40, 60, SPECIES_LAPRAS },
    { 40, 60, SPECIES_LAPRAS },
    { 40, 60, SPECIES_LAPRAS },
};

const struct WildPokemonInfo gMtSilver_2F_WaterMonsInfo = { 7, gMtSilver_2F_WaterMons };

const struct WildPokemon gMtSilver_2F_FishingMons[] =
{
    { 10, 10, SPECIES_MAGIKARP },
    { 10, 10, SPECIES_POLIWAG },
    { 20, 20, SPECIES_POLIWAG },
    { 20, 20, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWHIRL },
    { 40, 40, SPECIES_POLIWAG },
    { 40, 40, SPECIES_MAGIKARP },
    { 40, 40, SPECIES_POLIWAG },
};

const struct WildPokemonInfo gMtSilver_2F_FishingMonsInfo = { 30, gMtSilver_2F_FishingMons };

const struct WildPokemon gMtSilver_3F_LandMons[] =
{
    { 63, 63, SPECIES_GOLEM },
    { 64, 64, SPECIES_MACHOKE },
    { 62, 62, SPECIES_ONIX },
    { 65, 65, SPECIES_URSARING },
    { 63, 63, SPECIES_URSARING },
    { 64, 64, SPECIES_CROBAT },
    { 62, 62, SPECIES_ONIX },
    { 35, 40, SPECIES_PUPITAR },
    { 65, 65, SPECIES_CROBAT },
    { 65, 65, SPECIES_CROBAT },
    { 62, 64, SPECIES_URSARING },
    { 65, 65, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gMtSilver_3F_LandMonsInfo = { 10, gMtSilver_3F_LandMons };

const struct WildPokemon gMtSilver_Snow_LandMons[] =
{
    { 61, 69, SPECIES_URSARING },
    { 68, 68, SPECIES_SNEASEL },
    { 68, 68, SPECIES_PRIMEAPE },
    { 65, 65, SPECIES_SKARMORY },
    { 61, 69, SPECIES_MACHOKE },
    { 68, 68, SPECIES_PILOSWINE },
    { 68, 68, SPECIES_PILOSWINE },
    { 61, 69, SPECIES_HOUNDOOM },
    { 61, 69, SPECIES_HOUNDOOM },
    { 65, 65, SPECIES_RAPIDASH },
    { 61, 69, SPECIES_RAPIDASH },
    { 65, 65, SPECIES_HOUNDOOM },
};

const struct WildPokemonInfo gMtSilver_Snow_LandMonsInfo = { 20, gMtSilver_Snow_LandMons };

const struct WildPokemon gCliffEdgeCave_LandMons[] =
{
    { 23, 25, SPECIES_GOLBAT },
    { 23, 24, SPECIES_GEODUDE },
    { 23, 25, SPECIES_MACHOP },
    { 23, 26, SPECIES_ONIX },
    { 23, 25, SPECIES_KRABBY },
    { 23, 25, SPECIES_KINGLER },
    { 23, 25, SPECIES_WOOPER },
    { 23, 25, SPECIES_QUAGSIRE },
    { 23, 25, SPECIES_GRAVELER },
    { 23, 25, SPECIES_MACHOKE },
    { 23, 25, SPECIES_STEELIX },
    { 23, 26, SPECIES_STEELIX },
};

const struct WildPokemonInfo gCliffEdgeCave_LandMonsInfo = { 10, gCliffEdgeCave_LandMons };

const struct WildPokemon gCliffEdgeCave_RockSmashMons[] =
{
    { 23, 23, SPECIES_KRABBY },
    { 23, 23, SPECIES_KRABBY },
    { 28, 31, SPECIES_KINGLER },
    { 28, 31, SPECIES_KINGLER },
    { 28, 31, SPECIES_KINGLER },
};

const struct WildPokemonInfo gCliffEdgeCave_RockSmashMonsInfo = { 20, gCliffEdgeCave_RockSmashMons };

const struct WildPokemon gJohtoRocketHideout_B1F_LandMons[] =
{
    { 21, 21, SPECIES_VOLTORB },
    { 21, 21, SPECIES_VOLTORB },
    { 21, 21, SPECIES_GEODUDE },
    { 21, 21, SPECIES_GEODUDE },
    { 21, 21, SPECIES_GEODUDE },
    { 21, 21, SPECIES_KOFFING },
    { 21, 21, SPECIES_KOFFING },
    { 21, 21, SPECIES_KOFFING },
    { 21, 21, SPECIES_KOFFING },
    { 21, 21, SPECIES_KOFFING },
    { 21, 21, SPECIES_KOFFING },
    { 21, 21, SPECIES_KOFFING },
};

const struct WildPokemonInfo gJohtoRocketHideout_B1F_LandMonsInfo = { 100, gJohtoRocketHideout_B1F_LandMons };

const struct WildPokemon gSafariZone_Top_Left_LandMons[] =
{
    { 19, 26, SPECIES_MILTANK },
    { 19, 26, SPECIES_DODUO },
    { 19, 26, SPECIES_YANMA },
    { 19, 26, SPECIES_SCYTHER },
    { 19, 26, SPECIES_PINSIR },
    { 19, 26, SPECIES_KANGASKHAN },
    { 19, 26, SPECIES_PINECO },
    { 19, 26, SPECIES_HERACROSS },
    { 19, 26, SPECIES_CHANSEY },
    { 19, 26, SPECIES_DITTO },
    { 19, 26, SPECIES_CHANSEY },
    { 19, 26, SPECIES_DITTO },
};

const struct WildPokemonInfo gSafariZone_Top_Left_LandMonsInfo = { 20, gSafariZone_Top_Left_LandMons };

const struct WildPokemon gSafariZone_Low_Mid_LandMons[] =
{
    { 19, 26, SPECIES_GEODUDE },
    { 19, 26, SPECIES_GRAVELER },
    { 19, 26, SPECIES_RHYHORN },
    { 19, 26, SPECIES_MAGNEMITE },
    { 19, 26, SPECIES_TAUROS },
    { 19, 26, SPECIES_MAGNETON },
    { 19, 26, SPECIES_SKARMORY },
    { 19, 26, SPECIES_TEDDIURSA },
    { 19, 26, SPECIES_AIPOM },
    { 19, 26, SPECIES_TEDDIURSA },
    { 19, 26, SPECIES_AIPOM },
    { 19, 26, SPECIES_TEDDIURSA },
};

const struct WildPokemonInfo gSafariZone_Low_Mid_LandMonsInfo = { 20, gSafariZone_Low_Mid_LandMons };

const struct WildPokemon gSafariZone_Low_Mid_WaterMons[] =
{
    { 19, 26, SPECIES_POLIWAG },
    { 19, 26, SPECIES_REMORAID },
    { 19, 26, SPECIES_POLIWHIRL },
    { 19, 26, SPECIES_POLIWHIRL },
    { 19, 26, SPECIES_POLIWHIRL },
};

const struct WildPokemonInfo gSafariZone_Low_Mid_WaterMonsInfo = { 4, gSafariZone_Low_Mid_WaterMons };

const struct WildPokemon gSafariZone_Low_Mid_FishingMons[] =
{
    { 19, 26, SPECIES_MAGIKARP },
    { 19, 26, SPECIES_MAGIKARP },
    { 19, 26, SPECIES_MAGIKARP },
    { 19, 26, SPECIES_GOLDEEN },
    { 19, 26, SPECIES_KRABBY },
    { 19, 26, SPECIES_SEAKING },
    { 19, 26, SPECIES_KINGLER },
    { 19, 26, SPECIES_REMORAID },
    { 19, 26, SPECIES_REMORAID },
    { 19, 26, SPECIES_REMORAID },
};

const struct WildPokemonInfo gSafariZone_Low_Mid_FishingMonsInfo = { 30, gSafariZone_Low_Mid_FishingMons };

const struct WildPokemon gSafariZone_Low_Left_LandMons[] =
{
    { 19, 26, SPECIES_SANDSHREW },
    { 19, 26, SPECIES_SANDSLASH },
    { 19, 26, SPECIES_RHYHORN },
    { 19, 26, SPECIES_GLIGAR },
    { 19, 26, SPECIES_FEAROW },
    { 19, 26, SPECIES_CUBONE },
    { 19, 26, SPECIES_CUBONE },
    { 19, 26, SPECIES_PHANPY },
    { 19, 26, SPECIES_LARVITAR },
    { 19, 26, SPECIES_ONIX },
    { 19, 26, SPECIES_LARVITAR },
    { 19, 26, SPECIES_ONIX },
};

const struct WildPokemonInfo gSafariZone_Low_Left_LandMonsInfo = { 20, gSafariZone_Low_Left_LandMons };

const struct WildPokemon gSafariZone_Low_Right_LandMons[] =
{
    { 35, 40, SPECIES_WOOPER },
    { 35, 40, SPECIES_WOOPER },
    { 35, 40, SPECIES_PUPITAR },
    { 35, 40, SPECIES_DRATINI },
    { 35, 40, SPECIES_DRAGONAIR },
    { 35, 40, SPECIES_DUNSPARCE },
    { 35, 40, SPECIES_DRATINI },
    { 35, 40, SPECIES_PILOSWINE },
    { 35, 40, SPECIES_SNEASEL },
    { 35, 40, SPECIES_DUNSPARCE },
    { 35, 40, SPECIES_SNEASEL },
    { 35, 40, SPECIES_DUNSPARCE },
};

const struct WildPokemonInfo gSafariZone_Low_Right_LandMonsInfo = { 5, gSafariZone_Low_Right_LandMons };

const struct WildPokemon gSafariZone_Low_Right_WaterMons[] =
{
    { 35, 40, SPECIES_WOOPER },
    { 35, 40, SPECIES_GOLDUCK },
    { 35, 40, SPECIES_GOLDUCK },
    { 35, 40, SPECIES_QUAGSIRE },
    { 35, 40, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gSafariZone_Low_Right_WaterMonsInfo = { 4, gSafariZone_Low_Right_WaterMons };

const struct WildPokemon gSafariZone_Low_Right_FishingMons[] =
{
    { 35, 40, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_DRATINI },
    { 35, 40, SPECIES_DRATINI },
    { 35, 40, SPECIES_QUAGSIRE },
    { 35, 40, SPECIES_QUAGSIRE },
    { 35, 40, SPECIES_DRAGONAIR },
    { 35, 40, SPECIES_DRAGONAIR },
    { 35, 40, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo gSafariZone_Low_Right_FishingMonsInfo = { 30, gSafariZone_Low_Right_FishingMons };

const struct WildPokemon gSafariZone_Top_Mid_LandMons[] =
{
    { 19, 26, SPECIES_PARAS },
    { 19, 26, SPECIES_HAUNTER },
    { 19, 26, SPECIES_GIRAFARIG },
    { 19, 26, SPECIES_PIDGEOTTO },
    { 19, 26, SPECIES_ABRA },
    { 19, 26, SPECIES_HOOTHOOT },
    { 19, 26, SPECIES_MURKROW },
    { 19, 26, SPECIES_EEVEE },
    { 19, 26, SPECIES_TANGELA },
    { 19, 26, SPECIES_MR_MIME },
    { 19, 26, SPECIES_TANGELA },
    { 19, 26, SPECIES_MR_MIME },
};

const struct WildPokemonInfo gSafariZone_Top_Mid_LandMonsInfo = { 20, gSafariZone_Top_Mid_LandMons };

const struct WildPokemon gSafariZone_Top_Mid_WaterMons[] =
{
    { 19, 26, SPECIES_POLIWAG },
    { 19, 26, SPECIES_REMORAID },
    { 19, 26, SPECIES_POLIWHIRL },
    { 19, 26, SPECIES_POLIWHIRL },
    { 19, 26, SPECIES_POLIWHIRL },
};

const struct WildPokemonInfo gSafariZone_Top_Mid_WaterMonsInfo = { 4, gSafariZone_Top_Mid_WaterMons };

const struct WildPokemon gSafariZone_Top_Mid_FishingMons[] =
{
    { 19, 26, SPECIES_MAGIKARP },
    { 19, 26, SPECIES_MAGIKARP },
    { 19, 26, SPECIES_MAGIKARP },
    { 19, 26, SPECIES_GOLDEEN },
    { 19, 26, SPECIES_KRABBY },
    { 19, 26, SPECIES_SEAKING },
    { 19, 26, SPECIES_KINGLER },
    { 19, 26, SPECIES_REMORAID },
    { 19, 26, SPECIES_REMORAID },
    { 19, 26, SPECIES_REMORAID },
};

const struct WildPokemonInfo gSafariZone_Top_Mid_FishingMonsInfo = { 30, gSafariZone_Top_Mid_FishingMons };

const struct WildPokemon gSafariZone_Top_Right_LandMons[] =
{
    { 19, 26, SPECIES_KRABBY },
    { 19, 26, SPECIES_PSYDUCK },
    { 19, 26, SPECIES_WOOPER },
    { 19, 26, SPECIES_SKIPLOOM },
    { 19, 26, SPECIES_WOOPER },
    { 19, 26, SPECIES_EXEGGCUTE },
    { 19, 26, SPECIES_EXEGGCUTE },
    { 19, 26, SPECIES_SHUCKLE },
    { 19, 26, SPECIES_KINGLER },
    { 19, 26, SPECIES_PSYDUCK },
    { 19, 26, SPECIES_KINGLER },
    { 19, 26, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo gSafariZone_Top_Right_LandMonsInfo = { 20, gSafariZone_Top_Right_LandMons };

const struct WildPokemon gSafariZone_Top_Right_WaterMons[] =
{
    { 19, 26, SPECIES_HORSEA },
    { 19, 26, SPECIES_STARYU },
    { 19, 26, SPECIES_CORSOLA },
    { 19, 26, SPECIES_DRATINI },
    { 19, 26, SPECIES_DRATINI },
};

const struct WildPokemonInfo gSafariZone_Top_Right_WaterMonsInfo = { 4, gSafariZone_Top_Right_WaterMons };

const struct WildPokemon gSafariZone_Top_Right_FishingMons[] =
{
    { 19, 26, SPECIES_MAGIKARP },
    { 19, 26, SPECIES_MAGIKARP },
    { 19, 26, SPECIES_QWILFISH },
    { 19, 26, SPECIES_CHINCHOU },
    { 19, 26, SPECIES_SHELLDER },
    { 19, 26, SPECIES_QWILFISH },
    { 19, 26, SPECIES_KINGLER },
    { 19, 26, SPECIES_SHELLDER },
    { 19, 26, SPECIES_CHINCHOU },
    { 19, 26, SPECIES_CHINCHOU },
};

const struct WildPokemonInfo gSafariZone_Top_Right_FishingMonsInfo = { 30, gSafariZone_Top_Right_FishingMons };

// END johto_import
const struct WildPokemonHeader gWildMonHeaders[] =
{
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsMoneanChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsMoneanChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsLiptooChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsLiptooChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsWeepthChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsWeepthChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsDilfordChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsDilfordChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsScufibChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsScufibChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsRixyChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsRixyChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsViapoisChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsViapoisChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VIRIDIAN_FOREST),
        .mapNum = MAP_NUM(VIRIDIAN_FOREST),
        .landMonsInfo_FR = &sViridianForest_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sViridianForest_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_MOON_1F),
        .mapNum = MAP_NUM(MT_MOON_1F),
        .landMonsInfo_FR = &sMtMoon1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtMoon1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_MOON_B1F),
        .mapNum = MAP_NUM(MT_MOON_B1F),
        .landMonsInfo_FR = &sMtMoonB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtMoonB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_MOON_B2F),
        .mapNum = MAP_NUM(MT_MOON_B2F),
        .landMonsInfo_FR = &sMtMoonB2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtMoonB2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SSANNE_EXTERIOR),
        .mapNum = MAP_NUM(SSANNE_EXTERIOR),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSSAnneExterior_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSSAnneExterior_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSSAnneExterior_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSSAnneExterior_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(DIGLETTS_CAVE_B1F),
        .mapNum = MAP_NUM(DIGLETTS_CAVE_B1F),
        .landMonsInfo_FR = &sDiglettsCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sDiglettsCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_1F),
        .landMonsInfo_FR = &sVictoryRoad1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sVictoryRoad1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_2F),
        .mapNum = MAP_NUM(VICTORY_ROAD_2F),
        .landMonsInfo_FR = &sVictoryRoad2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sVictoryRoad2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_3F),
        .mapNum = MAP_NUM(VICTORY_ROAD_3F),
        .landMonsInfo_FR = &sVictoryRoad3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sVictoryRoad3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_MANSION_1F),
        .mapNum = MAP_NUM(POKEMON_MANSION_1F),
        .landMonsInfo_FR = &sPokemonMansion1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonMansion1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_MANSION_2F),
        .mapNum = MAP_NUM(POKEMON_MANSION_2F),
        .landMonsInfo_FR = &sPokemonMansion2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonMansion2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_MANSION_3F),
        .mapNum = MAP_NUM(POKEMON_MANSION_3F),
        .landMonsInfo_FR = &sPokemonMansion3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonMansion3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_MANSION_B1F),
        .mapNum = MAP_NUM(POKEMON_MANSION_B1F),
        .landMonsInfo_FR = &sPokemonMansionB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonMansionB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_CENTER),
        .mapNum = MAP_NUM(SAFARI_ZONE_CENTER),
        .landMonsInfo_FR = &sSafariZoneCenter_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZoneCenter_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZoneCenter_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZoneCenter_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSafariZoneCenter_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZoneCenter_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_EAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_EAST),
        .landMonsInfo_FR = &sSafariZoneEast_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZoneEast_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZoneEast_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZoneEast_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSafariZoneEast_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZoneEast_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH),
        .landMonsInfo_FR = &sSafariZoneNorth_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZoneNorth_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZoneNorth_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZoneNorth_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSafariZoneNorth_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZoneNorth_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_WEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_WEST),
        .landMonsInfo_FR = &sSafariZoneWest_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZoneWest_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZoneWest_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZoneWest_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSafariZoneWest_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZoneWest_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_1F),
        .mapNum = MAP_NUM(CERULEAN_CAVE_1F),
        .landMonsInfo_FR = &sCeruleanCave1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCave1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCave1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCave1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCave1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCave1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_2F),
        .mapNum = MAP_NUM(CERULEAN_CAVE_2F),
        .landMonsInfo_FR = &sCeruleanCave2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sCeruleanCave2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_B1F),
        .mapNum = MAP_NUM(CERULEAN_CAVE_B1F),
        .landMonsInfo_FR = &sCeruleanCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCaveB1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCaveB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCaveB1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROCK_TUNNEL_1F),
        .mapNum = MAP_NUM(ROCK_TUNNEL_1F),
        .landMonsInfo_FR = &sRockTunnel1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRockTunnel1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROCK_TUNNEL_B1F),
        .mapNum = MAP_NUM(ROCK_TUNNEL_B1F),
        .landMonsInfo_FR = &sRockTunnelB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRockTunnelB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sRockTunnelB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sRockTunnelB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_1F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_1F),
        .landMonsInfo_FR = &sSeafoamIslands1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslands1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B1F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B1F),
        .landMonsInfo_FR = &sSeafoamIslandsB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslandsB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B2F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B2F),
        .landMonsInfo_FR = &sSeafoamIslandsB2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslandsB2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B3F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B3F),
        .landMonsInfo_FR = &sSeafoamIslandsB3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslandsB3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSeafoamIslandsB3F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSeafoamIslandsB3F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSeafoamIslandsB3F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSeafoamIslandsB3F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B4F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B4F),
        .landMonsInfo_FR = &sSeafoamIslandsB4F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslandsB4F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSeafoamIslandsB4F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSeafoamIslandsB4F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSeafoamIslandsB4F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSeafoamIslandsB4F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_3F),
        .mapNum = MAP_NUM(POKEMON_TOWER_3F),
        .landMonsInfo_FR = &sPokemonTower3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_4F),
        .mapNum = MAP_NUM(POKEMON_TOWER_4F),
        .landMonsInfo_FR = &sPokemonTower4F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower4F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_5F),
        .mapNum = MAP_NUM(POKEMON_TOWER_5F),
        .landMonsInfo_FR = &sPokemonTower5F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower5F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_6F),
        .mapNum = MAP_NUM(POKEMON_TOWER_6F),
        .landMonsInfo_FR = &sPokemonTower6F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower6F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_7F),
        .mapNum = MAP_NUM(POKEMON_TOWER_7F),
        .landMonsInfo_FR = &sPokemonTower7F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower7F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POWER_PLANT),
        .mapNum = MAP_NUM(POWER_PLANT),
        .landMonsInfo_FR = &sPowerPlant_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPowerPlant_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_EXTERIOR),
        .mapNum = MAP_NUM(MT_EMBER_EXTERIOR),
        .landMonsInfo_FR = &sMtEmberExterior_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberExterior_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberExterior_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberExterior_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_SUMMIT_PATH_1F),
        .mapNum = MAP_NUM(MT_EMBER_SUMMIT_PATH_1F),
        .landMonsInfo_FR = &sMtEmberSummitPath1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberSummitPath1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_SUMMIT_PATH_2F),
        .mapNum = MAP_NUM(MT_EMBER_SUMMIT_PATH_2F),
        .landMonsInfo_FR = &sMtEmberSummitPath2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberSummitPath2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberSummitPath2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberSummitPath2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_SUMMIT_PATH_3F),
        .mapNum = MAP_NUM(MT_EMBER_SUMMIT_PATH_3F),
        .landMonsInfo_FR = &sMtEmberSummitPath3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberSummitPath3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_1F),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_1F),
        .landMonsInfo_FR = &sMtEmberRubyPath1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPath1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPath1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPath1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B1F),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B1F),
        .landMonsInfo_FR = &sMtEmberRubyPathB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B2F),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B2F),
        .landMonsInfo_FR = &sMtEmberRubyPathB2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B3F),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B3F),
        .landMonsInfo_FR = &sMtEmberRubyPathB3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB3F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB3F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B1F_STAIRS),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B1F_STAIRS),
        .landMonsInfo_FR = &sMtEmberRubyPathB1FStairs_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB1FStairs_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB1FStairs_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB1FStairs_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B2F_STAIRS),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B2F_STAIRS),
        .landMonsInfo_FR = &sMtEmberRubyPathB2FStairs_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB2FStairs_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB2FStairs_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB2FStairs_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(THREE_ISLAND_BERRY_FOREST),
        .mapNum = MAP_NUM(THREE_ISLAND_BERRY_FOREST),
        .landMonsInfo_FR = &sThreeIslandBerryForest_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sThreeIslandBerryForest_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sThreeIslandBerryForest_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sThreeIslandBerryForest_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sThreeIslandBerryForest_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sThreeIslandBerryForest_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE),
        .mapNum = MAP_NUM(FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE),
        .landMonsInfo_FR = &sFourIslandIcefallCaveEntrance_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFourIslandIcefallCaveEntrance_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sFourIslandIcefallCaveEntrance_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFourIslandIcefallCaveEntrance_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFourIslandIcefallCaveEntrance_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFourIslandIcefallCaveEntrance_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND_ICEFALL_CAVE_1F),
        .mapNum = MAP_NUM(FOUR_ISLAND_ICEFALL_CAVE_1F),
        .landMonsInfo_FR = &sFourIslandIcefallCave1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFourIslandIcefallCave1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND_ICEFALL_CAVE_B1F),
        .mapNum = MAP_NUM(FOUR_ISLAND_ICEFALL_CAVE_B1F),
        .landMonsInfo_FR = &sFourIslandIcefallCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFourIslandIcefallCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND_ICEFALL_CAVE_BACK),
        .mapNum = MAP_NUM(FOUR_ISLAND_ICEFALL_CAVE_BACK),
        .landMonsInfo_FR = &sFourIslandIcefallCaveBack_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFourIslandIcefallCaveBack_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sFourIslandIcefallCaveBack_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFourIslandIcefallCaveBack_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFourIslandIcefallCaveBack_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFourIslandIcefallCaveBack_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_PATTERN_BUSH),
        .mapNum = MAP_NUM(SIX_ISLAND_PATTERN_BUSH),
        .landMonsInfo_FR = &sSixIslandPatternBush_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandPatternBush_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM1),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM1),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom1_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom1_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM2),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM2),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom2_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom2_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM3),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM3),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom3_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom3_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM4),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM4),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom4_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom4_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM5),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM5),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom5_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom5_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM6),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM6),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom6_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom6_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM7),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM7),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom7_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom7_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM8),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM8),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom8_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom8_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM9),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM9),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom9_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom9_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM10),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM10),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom10_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom10_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM11),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM11),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom11_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom11_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM12),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM12),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom12_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom12_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM13),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM13),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom13_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom13_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM14),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM14),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom14_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom14_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ONE_ISLAND_KINDLE_ROAD),
        .mapNum = MAP_NUM(ONE_ISLAND_KINDLE_ROAD),
        .landMonsInfo_FR = &sOneIslandKindleRoad_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sOneIslandKindleRoad_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sOneIslandKindleRoad_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sOneIslandKindleRoad_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sOneIslandKindleRoad_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sOneIslandKindleRoad_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sOneIslandKindleRoad_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sOneIslandKindleRoad_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ONE_ISLAND_TREASURE_BEACH),
        .mapNum = MAP_NUM(ONE_ISLAND_TREASURE_BEACH),
        .landMonsInfo_FR = &sOneIslandTreasureBeach_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sOneIslandTreasureBeach_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sOneIslandTreasureBeach_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sOneIslandTreasureBeach_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sOneIslandTreasureBeach_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sOneIslandTreasureBeach_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(TWO_ISLAND_CAPE_BRINK),
        .mapNum = MAP_NUM(TWO_ISLAND_CAPE_BRINK),
        .landMonsInfo_FR = &sTwoIslandCapeBrink_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sTwoIslandCapeBrink_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sTwoIslandCapeBrink_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sTwoIslandCapeBrink_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sTwoIslandCapeBrink_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sTwoIslandCapeBrink_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(THREE_ISLAND_BOND_BRIDGE),
        .mapNum = MAP_NUM(THREE_ISLAND_BOND_BRIDGE),
        .landMonsInfo_FR = &sThreeIslandBondBridge_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sThreeIslandBondBridge_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sThreeIslandBondBridge_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sThreeIslandBondBridge_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sThreeIslandBondBridge_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sThreeIslandBondBridge_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(THREE_ISLAND_PORT),
        .mapNum = MAP_NUM(THREE_ISLAND_PORT),
        .landMonsInfo_FR = &sThreeIslandPort_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sThreeIslandPort_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_RESORT_GORGEOUS),
        .mapNum = MAP_NUM(FIVE_ISLAND_RESORT_GORGEOUS),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFiveIslandResortGorgeous_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIslandResortGorgeous_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIslandResortGorgeous_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIslandResortGorgeous_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_WATER_LABYRINTH),
        .mapNum = MAP_NUM(FIVE_ISLAND_WATER_LABYRINTH),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFiveIslandWaterLabyrinth_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIslandWaterLabyrinth_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIslandWaterLabyrinth_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIslandWaterLabyrinth_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_MEADOW),
        .mapNum = MAP_NUM(FIVE_ISLAND_MEADOW),
        .landMonsInfo_FR = &sFiveIslandMeadow_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandMeadow_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sFiveIslandMeadow_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIslandMeadow_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIslandMeadow_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIslandMeadow_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_MEMORIAL_PILLAR),
        .mapNum = MAP_NUM(FIVE_ISLAND_MEMORIAL_PILLAR),
        .landMonsInfo_FR = &sFiveIslandMemorialPillar_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandMemorialPillar_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sFiveIslandMemorialPillar_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIslandMemorialPillar_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIslandMemorialPillar_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIslandMemorialPillar_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_OUTCAST_ISLAND),
        .mapNum = MAP_NUM(SIX_ISLAND_OUTCAST_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSixIslandOutcastIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSixIslandOutcastIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSixIslandOutcastIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSixIslandOutcastIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_GREEN_PATH),
        .mapNum = MAP_NUM(SIX_ISLAND_GREEN_PATH),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSixIslandGreenPath_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSixIslandGreenPath_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSixIslandGreenPath_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSixIslandGreenPath_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_WATER_PATH),
        .mapNum = MAP_NUM(SIX_ISLAND_WATER_PATH),
        .landMonsInfo_FR = &sSixIslandWaterPath_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandWaterPath_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSixIslandWaterPath_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSixIslandWaterPath_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSixIslandWaterPath_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSixIslandWaterPath_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_RUIN_VALLEY),
        .mapNum = MAP_NUM(SIX_ISLAND_RUIN_VALLEY),
        .landMonsInfo_FR = &sSixIslandRuinValley_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandRuinValley_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSixIslandRuinValley_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSixIslandRuinValley_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSixIslandRuinValley_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSixIslandRuinValley_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TRAINER_TOWER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TRAINER_TOWER),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSevenIslandTrainerTower_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSevenIslandTrainerTower_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSevenIslandTrainerTower_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSevenIslandTrainerTower_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE),
        .mapNum = MAP_NUM(SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE),
        .landMonsInfo_FR = &sSevenIslandSevaultCanyonEntrance_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandSevaultCanyonEntrance_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_SEVAULT_CANYON),
        .mapNum = MAP_NUM(SEVEN_ISLAND_SEVAULT_CANYON),
        .landMonsInfo_FR = &sSevenIslandSevaultCanyon_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandSevaultCanyon_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sSevenIslandSevaultCanyon_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sSevenIslandSevaultCanyon_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSevenIslandTanobyRuins_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSevenIslandTanobyRuins_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSevenIslandTanobyRuins_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSevenIslandTanobyRuins_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE1),
        .mapNum = MAP_NUM(ROUTE1),
        .landMonsInfo_FR = &sRoute1_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute1_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE2),
        .mapNum = MAP_NUM(ROUTE2),
        .landMonsInfo_FR = &sRoute2_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute2_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE3),
        .mapNum = MAP_NUM(ROUTE3),
        .landMonsInfo_FR = &sRoute3_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute3_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE4),
        .mapNum = MAP_NUM(ROUTE4),
        .landMonsInfo_FR = &sRoute4_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute4_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute4_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute4_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute4_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute4_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE5),
        .mapNum = MAP_NUM(ROUTE5),
        .landMonsInfo_FR = &sRoute5_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute5_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE6),
        .mapNum = MAP_NUM(ROUTE6),
        .landMonsInfo_FR = &sRoute6_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute6_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute6_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute6_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute6_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute6_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE7),
        .mapNum = MAP_NUM(ROUTE7),
        .landMonsInfo_FR = &sRoute7_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute7_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE8),
        .mapNum = MAP_NUM(ROUTE8),
        .landMonsInfo_FR = &sRoute8_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute8_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE9),
        .mapNum = MAP_NUM(ROUTE9),
        .landMonsInfo_FR = &sRoute9_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute9_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE10),
        .mapNum = MAP_NUM(ROUTE10),
        .landMonsInfo_FR = &sRoute10_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute10_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute10_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute10_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute10_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute10_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE11),
        .mapNum = MAP_NUM(ROUTE11),
        .landMonsInfo_FR = &sRoute11_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute11_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute11_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute11_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute11_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute11_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE12),
        .mapNum = MAP_NUM(ROUTE12),
        .landMonsInfo_FR = &sRoute12_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute12_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute12_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute12_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute12_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute12_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE13),
        .mapNum = MAP_NUM(ROUTE13),
        .landMonsInfo_FR = &sRoute13_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute13_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute13_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute13_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute13_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute13_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE14),
        .mapNum = MAP_NUM(ROUTE14),
        .landMonsInfo_FR = &sRoute14_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute14_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE15),
        .mapNum = MAP_NUM(ROUTE15),
        .landMonsInfo_FR = &sRoute15_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute15_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE16),
        .mapNum = MAP_NUM(ROUTE16),
        .landMonsInfo_FR = &sRoute16_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute16_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE17),
        .mapNum = MAP_NUM(ROUTE17),
        .landMonsInfo_FR = &sRoute17_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute17_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE18),
        .mapNum = MAP_NUM(ROUTE18),
        .landMonsInfo_FR = &sRoute18_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute18_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE19),
        .mapNum = MAP_NUM(ROUTE19),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sRoute19_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute19_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute19_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute19_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE20),
        .mapNum = MAP_NUM(ROUTE20),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sRoute20_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute20_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute20_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute20_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE21_NORTH),
        .mapNum = MAP_NUM(ROUTE21_NORTH),
        .landMonsInfo_FR = &sRoute21North_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute21North_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute21North_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute21North_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute21North_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute21North_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE21_SOUTH),
        .mapNum = MAP_NUM(ROUTE21_SOUTH),
        .landMonsInfo_FR = &sRoute21South_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute21South_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute21South_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute21South_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute21South_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute21South_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE22),
        .mapNum = MAP_NUM(ROUTE22),
        .landMonsInfo_FR = &sRoute22_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute22_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute22_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute22_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute22_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute22_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE23),
        .mapNum = MAP_NUM(ROUTE23),
        .landMonsInfo_FR = &sRoute23_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute23_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute23_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute23_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute23_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute23_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE24),
        .mapNum = MAP_NUM(ROUTE24),
        .landMonsInfo_FR = &sRoute24_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute24_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute24_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute24_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute24_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute24_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE25),
        .mapNum = MAP_NUM(ROUTE25),
        .landMonsInfo_FR = &sRoute25_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute25_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute25_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute25_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute25_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute25_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PALLET_TOWN),
        .mapNum = MAP_NUM(PALLET_TOWN),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sPalletTown_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sPalletTown_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sPalletTown_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sPalletTown_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(VIRIDIAN_CITY),
        .mapNum = MAP_NUM(VIRIDIAN_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sViridianCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sViridianCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sViridianCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sViridianCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CITY),
        .mapNum = MAP_NUM(CERULEAN_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sCeruleanCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sCeruleanCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(VERMILION_CITY),
        .mapNum = MAP_NUM(VERMILION_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sVermilionCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sVermilionCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sVermilionCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sVermilionCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CELADON_CITY),
        .mapNum = MAP_NUM(CELADON_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sCeladonCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeladonCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sCeladonCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeladonCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FUCHSIA_CITY),
        .mapNum = MAP_NUM(FUCHSIA_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFuchsiaCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFuchsiaCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFuchsiaCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFuchsiaCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CINNABAR_ISLAND),
        .mapNum = MAP_NUM(CINNABAR_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sCinnabarIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCinnabarIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sCinnabarIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCinnabarIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ONE_ISLAND),
        .mapNum = MAP_NUM(ONE_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sOneIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sOneIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sOneIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sOneIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND),
        .mapNum = MAP_NUM(FOUR_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFourIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFourIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFourIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFourIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND),
        .mapNum = MAP_NUM(FIVE_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFiveIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_2_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_2_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_3_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_3_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_4_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_4_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_5_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_5_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_6_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_6_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_7_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_7_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_8_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_8_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_9_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_9_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE20_UNDERWATER),
        .mapNum = MAP_NUM(ROUTE20_UNDERWATER),
        .landMonsInfo_FR = &sRoute20_Underwater_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute20_Underwater_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH_WEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH_WEST),
        .landMonsInfo_FR = &sSafariZone_NorthWest_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZone_NorthWest_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZone_NorthWest_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZone_NorthWest_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sSafariZone_NorthWest_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sSafariZone_NorthWest_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sSafariZone_NorthWest_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZone_NorthWest_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH_EAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH_EAST),
        .landMonsInfo_FR = &sSafariZone_NorthEast_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZone_NorthEast_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sSafariZone_NorthWest_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sSafariZone_NorthWest_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(THREE_ISLAND_BOND_BRIDGE_UNDERWATER),
        .mapNum = MAP_NUM(THREE_ISLAND_BOND_BRIDGE_UNDERWATER),
        .landMonsInfo_FR = &sThreeIslandBondBridge_Underwater_LandMonsInfo,
        .landMonsInfo_LG = &sThreeIslandBondBridge_Underwater_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_B1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_B1F),
        .landMonsInfo_FR = &sArtisanCave_LandMonsInfo,
        .landMonsInfo_LG = &sArtisanCave_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_1F),
        .landMonsInfo_FR = &sArtisanCave_LandMonsInfo,
        .landMonsInfo_LG = &sArtisanCave_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_1F_BLUE),
        .mapNum = MAP_NUM(CERULEAN_CAVE_1F_BLUE),
        .landMonsInfo_FR = &sCeruleanCave1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCave1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCave1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCave1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCave1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCave1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_2F_BLUE),
        .mapNum = MAP_NUM(CERULEAN_CAVE_2F_BLUE),
        .landMonsInfo_FR = &sCeruleanCave2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sCeruleanCave2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_B1F_BLUE),
        .mapNum = MAP_NUM(CERULEAN_CAVE_B1F_BLUE),
        .landMonsInfo_FR = &sCeruleanCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCaveB1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCaveB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCaveB1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_1F_YELLOW),
        .mapNum = MAP_NUM(CERULEAN_CAVE_1F_YELLOW),
        .landMonsInfo_FR = &sCeruleanCave1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCave1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCave1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCave1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCave1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCave1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_2F_YELLOW),
        .mapNum = MAP_NUM(CERULEAN_CAVE_2F_YELLOW),
        .landMonsInfo_FR = &sCeruleanCave2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sCeruleanCave2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_B1F_YELLOW),
        .mapNum = MAP_NUM(CERULEAN_CAVE_B1F_YELLOW),
        .landMonsInfo_FR = &sCeruleanCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCaveB1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCaveB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCaveB1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH_HOENN),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH_HOENN),
        .landMonsInfo_FR = &sSafariZone_NorthHoenn_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZone_NorthHoenn_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZone_NorthHoenn_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZone_NorthHoenn_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSafariZone_NorthHoenn_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZone_NorthHoenn_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_HOENN_CAVE),
        .mapNum = MAP_NUM(SAFARI_ZONE_HOENN_CAVE),
        .landMonsInfo_FR = &sSafariZone_HoennCave_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZone_HoennCave_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_HOENN_CAVE_SAND),
        .mapNum = MAP_NUM(SAFARI_ZONE_HOENN_CAVE_SAND),
        .landMonsInfo_FR = &sSafariZone_HoennCaveSand_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZone_HoennCaveSand_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_HOENN_CAVE_GHOST),
        .mapNum = MAP_NUM(SAFARI_ZONE_HOENN_CAVE_GHOST),
        .landMonsInfo_FR = &sSafariZone_HoennCaveGhost_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZone_HoennCaveGhost_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(LILYCOVE_CITY),
        .mapNum = MAP_NUM(LILYCOVE_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gLilycoveCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gLilycoveCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gLilycoveCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gLilycoveCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE121),
        .mapNum = MAP_NUM(ROUTE121),
        .landMonsInfo_FR = &gRoute121_LandMonsInfo,
        .landMonsInfo_LG = &gRoute121_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute121_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute121_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute121_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute121_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE122),
        .mapNum = MAP_NUM(ROUTE122),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute122_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute122_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute122_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute122_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE123),
        .mapNum = MAP_NUM(ROUTE123),
        .landMonsInfo_FR = &gRoute123_LandMonsInfo,
        .landMonsInfo_LG = &gRoute123_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute123_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute123_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute123_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute123_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE120),
        .mapNum = MAP_NUM(ROUTE120),
        .landMonsInfo_FR = &gRoute120_LandMonsInfo,
        .landMonsInfo_LG = &gRoute120_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute120_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute120_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute120_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute120_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE119),
        .mapNum = MAP_NUM(ROUTE119),
        .landMonsInfo_FR = &gRoute119_LandMonsInfo,
        .landMonsInfo_LG = &gRoute119_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute119_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute119_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute119_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute119_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(EVER_GRANDE_CITY),
        .mapNum = MAP_NUM(EVER_GRANDE_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gEverGrandeCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gEverGrandeCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gEverGrandeCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gEverGrandeCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE131),
        .mapNum = MAP_NUM(ROUTE131),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute131_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute131_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute131_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute131_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PACIFIDLOG_TOWN),
        .mapNum = MAP_NUM(PACIFIDLOG_TOWN),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gPacifidlogTown_WaterMonsInfo,
        .waterMonsInfo_LG = &gPacifidlogTown_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gPacifidlogTown_FishingMonsInfo,
        .fishingMonsInfo_LG = &gPacifidlogTown_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE132),
        .mapNum = MAP_NUM(ROUTE132),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute132_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute132_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute132_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute132_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE133),
        .mapNum = MAP_NUM(ROUTE133),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute133_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute133_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute133_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute133_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE134),
        .mapNum = MAP_NUM(ROUTE134),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute134_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute134_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute134_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute134_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE113),
        .mapNum = MAP_NUM(ROUTE113),
        .landMonsInfo_FR = &gRoute113_LandMonsInfo,
        .landMonsInfo_LG = &gRoute113_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE114),
        .mapNum = MAP_NUM(ROUTE114),
        .landMonsInfo_FR = &gRoute114_LandMonsInfo,
        .landMonsInfo_LG = &gRoute114_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute114_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute114_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute114_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute114_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute114_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute114_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE115),
        .mapNum = MAP_NUM(ROUTE115),
        .landMonsInfo_FR = &gRoute115_LandMonsInfo,
        .landMonsInfo_LG = &gRoute115_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute115_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute115_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute115_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute115_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE116),
        .mapNum = MAP_NUM(ROUTE116),
        .landMonsInfo_FR = &gRoute116_LandMonsInfo,
        .landMonsInfo_LG = &gRoute116_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE104),
        .mapNum = MAP_NUM(ROUTE104),
        .landMonsInfo_FR = &gRoute104_LandMonsInfo,
        .landMonsInfo_LG = &gRoute104_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute104_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute104_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute104_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute104_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE105),
        .mapNum = MAP_NUM(ROUTE105),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute105_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute105_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute105_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute105_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE106),
        .mapNum = MAP_NUM(ROUTE106),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute106_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute106_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute106_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute106_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(DEWFORD_TOWN),
        .mapNum = MAP_NUM(DEWFORD_TOWN),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gDewfordTown_WaterMonsInfo,
        .waterMonsInfo_LG = &gDewfordTown_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gDewfordTown_FishingMonsInfo,
        .fishingMonsInfo_LG = &gDewfordTown_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE107),
        .mapNum = MAP_NUM(ROUTE107),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute107_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute107_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute107_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute107_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PETALBURG_CITY),
        .mapNum = MAP_NUM(PETALBURG_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gPetalburgCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gPetalburgCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gPetalburgCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gPetalburgCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE102),
        .mapNum = MAP_NUM(ROUTE102),
        .landMonsInfo_FR = &gRoute102_LandMonsInfo,
        .landMonsInfo_LG = &gRoute102_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute102_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute102_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute102_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute102_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE101),
        .mapNum = MAP_NUM(ROUTE101),
        .landMonsInfo_FR = &gRoute101_LandMonsInfo,
        .landMonsInfo_LG = &gRoute101_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE103),
        .mapNum = MAP_NUM(ROUTE103),
        .landMonsInfo_FR = &gRoute103_LandMonsInfo,
        .landMonsInfo_LG = &gRoute103_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute103_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute103_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute103_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute103_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE118),
        .mapNum = MAP_NUM(ROUTE118),
        .landMonsInfo_FR = &gRoute118_LandMonsInfo,
        .landMonsInfo_LG = &gRoute118_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute118_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute118_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute118_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute118_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE124),
        .mapNum = MAP_NUM(ROUTE124),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute124_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute124_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute124_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute124_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MOSSDEEP_CITY),
        .mapNum = MAP_NUM(MOSSDEEP_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gMossdeepCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gMossdeepCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMossdeepCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMossdeepCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE125),
        .mapNum = MAP_NUM(ROUTE125),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute125_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute125_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute125_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute125_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE127),
        .mapNum = MAP_NUM(ROUTE127),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute127_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute127_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute127_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute127_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE128),
        .mapNum = MAP_NUM(ROUTE128),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute128_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute128_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute128_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute128_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE126),
        .mapNum = MAP_NUM(ROUTE126),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute126_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute126_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute126_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute126_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE129),
        .mapNum = MAP_NUM(ROUTE129),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute129_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute129_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute129_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute129_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE130),
        .mapNum = MAP_NUM(ROUTE130),
        .landMonsInfo_FR = &gRoute130_LandMonsInfo,
        .landMonsInfo_LG = &gRoute130_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute130_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute130_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute130_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute130_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE117),
        .mapNum = MAP_NUM(ROUTE117),
        .landMonsInfo_FR = &gRoute117_LandMonsInfo,
        .landMonsInfo_LG = &gRoute117_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute117_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute117_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute117_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute117_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE110),
        .mapNum = MAP_NUM(ROUTE110),
        .landMonsInfo_FR = &gRoute110_LandMonsInfo,
        .landMonsInfo_LG = &gRoute110_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute110_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute110_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute110_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute110_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE111),
        .mapNum = MAP_NUM(ROUTE111),
        .landMonsInfo_FR = &gRoute111_LandMonsInfo,
        .landMonsInfo_LG = &gRoute111_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute111_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute111_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute111_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute111_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute111_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute111_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE112),
        .mapNum = MAP_NUM(ROUTE112),
        .landMonsInfo_FR = &gRoute112_LandMonsInfo,
        .landMonsInfo_LG = &gRoute112_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE108),
        .mapNum = MAP_NUM(ROUTE108),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute108_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute108_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute108_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute108_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE109),
        .mapNum = MAP_NUM(ROUTE109),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute109_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute109_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute109_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute109_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SLATEPORT_CITY),
        .mapNum = MAP_NUM(SLATEPORT_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gSlateportCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gSlateportCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSlateportCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSlateportCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SOOTOPOLIS_CITY),
        .mapNum = MAP_NUM(SOOTOPOLIS_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gSootopolisCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gSootopolisCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSootopolisCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSootopolisCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER_ROUTE124),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE124),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gUnderwater_Route124_WaterMonsInfo,
        .waterMonsInfo_LG = &gUnderwater_Route124_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER_ROUTE126),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE126),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gUnderwater_Route126_WaterMonsInfo,
        .waterMonsInfo_LG = &gUnderwater_Route126_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(PETALBURG_WOODS),
        .mapNum = MAP_NUM(PETALBURG_WOODS),
        .landMonsInfo_FR = &gPetalburgWoods_LandMonsInfo,
        .landMonsInfo_LG = &gPetalburgWoods_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(RUSTURF_TUNNEL),
        .mapNum = MAP_NUM(RUSTURF_TUNNEL),
        .landMonsInfo_FR = &gRusturfTunnel_LandMonsInfo,
        .landMonsInfo_LG = &gRusturfTunnel_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_1F),
        .landMonsInfo_FR = &gGraniteCave_1F_LandMonsInfo,
        .landMonsInfo_LG = &gGraniteCave_1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B1F),
        .landMonsInfo_FR = &gGraniteCave_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gGraniteCave_B1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B2F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B2F),
        .landMonsInfo_FR = &gGraniteCave_B2F_LandMonsInfo,
        .landMonsInfo_LG = &gGraniteCave_B2F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gGraniteCave_B2F_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gGraniteCave_B2F_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_STEVENS_ROOM),
        .mapNum = MAP_NUM(GRANITE_CAVE_STEVENS_ROOM),
        .landMonsInfo_FR = &gGraniteCave_StevensRoom_LandMonsInfo,
        .landMonsInfo_LG = &gGraniteCave_StevensRoom_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_2R),
        .landMonsInfo_FR = &gMeteorFalls_B1F_2R_LandMonsInfo,
        .landMonsInfo_LG = &gMeteorFalls_B1F_2R_LandMonsInfo,
        .waterMonsInfo_FR = &gMeteorFalls_B1F_2R_WaterMonsInfo,
        .waterMonsInfo_LG = &gMeteorFalls_B1F_2R_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMeteorFalls_B1F_2R_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMeteorFalls_B1F_2R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_1R),
        .landMonsInfo_FR = &gMeteorFalls_1F_1R_LandMonsInfo,
        .landMonsInfo_LG = &gMeteorFalls_1F_1R_LandMonsInfo,
        .waterMonsInfo_FR = &gMeteorFalls_1F_1R_WaterMonsInfo,
        .waterMonsInfo_LG = &gMeteorFalls_1F_1R_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMeteorFalls_1F_1R_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMeteorFalls_1F_1R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_2R),
        .landMonsInfo_FR = &gMeteorFalls_1F_2R_LandMonsInfo,
        .landMonsInfo_LG = &gMeteorFalls_1F_2R_LandMonsInfo,
        .waterMonsInfo_FR = &gMeteorFalls_1F_2R_WaterMonsInfo,
        .waterMonsInfo_LG = &gMeteorFalls_1F_2R_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMeteorFalls_1F_2R_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMeteorFalls_1F_2R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_1R),
        .landMonsInfo_FR = &gMeteorFalls_B1F_1R_LandMonsInfo,
        .landMonsInfo_LG = &gMeteorFalls_B1F_1R_LandMonsInfo,
        .waterMonsInfo_FR = &gMeteorFalls_B1F_1R_WaterMonsInfo,
        .waterMonsInfo_LG = &gMeteorFalls_B1F_1R_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMeteorFalls_B1F_1R_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMeteorFalls_B1F_1R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_STEVENS_CAVE),
        .mapNum = MAP_NUM(METEOR_FALLS_STEVENS_CAVE),
        .landMonsInfo_FR = &gMeteorFalls_StevensCave_LandMonsInfo,
        .landMonsInfo_LG = &gMeteorFalls_StevensCave_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(JAGGED_PASS),
        .mapNum = MAP_NUM(JAGGED_PASS),
        .landMonsInfo_FR = &gJaggedPass_LandMonsInfo,
        .landMonsInfo_LG = &gJaggedPass_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIERY_PATH),
        .mapNum = MAP_NUM(FIERY_PATH),
        .landMonsInfo_FR = &gFieryPath_LandMonsInfo,
        .landMonsInfo_LG = &gFieryPath_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_1F),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_1F),
        .landMonsInfo_FR = &gMagmaHideout_1F_LandMonsInfo,
        .landMonsInfo_LG = &gMagmaHideout_1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_1R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_1R),
        .landMonsInfo_FR = &gMagmaHideout_2F_1R_LandMonsInfo,
        .landMonsInfo_LG = &gMagmaHideout_2F_1R_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_2R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_2R),
        .landMonsInfo_FR = &gMagmaHideout_2F_2R_LandMonsInfo,
        .landMonsInfo_LG = &gMagmaHideout_2F_2R_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_1R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_1R),
        .landMonsInfo_FR = &gMagmaHideout_3F_1R_LandMonsInfo,
        .landMonsInfo_LG = &gMagmaHideout_3F_1R_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_2R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_2R),
        .landMonsInfo_FR = &gMagmaHideout_3F_2R_LandMonsInfo,
        .landMonsInfo_LG = &gMagmaHideout_3F_2R_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_4F),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_4F),
        .landMonsInfo_FR = &gMagmaHideout_4F_LandMonsInfo,
        .landMonsInfo_LG = &gMagmaHideout_4F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_3R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_3R),
        .landMonsInfo_FR = &gMagmaHideout_3F_3R_LandMonsInfo,
        .landMonsInfo_LG = &gMagmaHideout_3F_3R_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_3R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_3R),
        .landMonsInfo_FR = &gMagmaHideout_2F_3R_LandMonsInfo,
        .landMonsInfo_LG = &gMagmaHideout_2F_3R_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_INSIDE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_INSIDE),
        .landMonsInfo_FR = &gNewMauville_Inside_LandMonsInfo,
        .landMonsInfo_LG = &gNewMauville_Inside_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_ENTRANCE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_ENTRANCE),
        .landMonsInfo_FR = &gNewMauville_Entrance_LandMonsInfo,
        .landMonsInfo_LG = &gNewMauville_Entrance_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_ROOMS_B1F),
        .mapNum = MAP_NUM(ABANDONED_SHIP_ROOMS_B1F),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gAbandonedShip_Rooms_B1F_WaterMonsInfo,
        .waterMonsInfo_LG = &gAbandonedShip_Rooms_B1F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gAbandonedShip_Rooms_B1F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gAbandonedShip_Rooms_B1F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .mapNum = MAP_NUM(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gAbandonedShip_HiddenFloorCorridors_WaterMonsInfo,
        .waterMonsInfo_LG = &gAbandonedShip_HiddenFloorCorridors_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gAbandonedShip_HiddenFloorCorridors_FishingMonsInfo,
        .fishingMonsInfo_LG = &gAbandonedShip_HiddenFloorCorridors_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_1F),
        .mapNum = MAP_NUM(MT_PYRE_1F),
        .landMonsInfo_FR = &gMtPyre_1F_LandMonsInfo,
        .landMonsInfo_LG = &gMtPyre_1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_2F),
        .mapNum = MAP_NUM(MT_PYRE_2F),
        .landMonsInfo_FR = &gMtPyre_2F_LandMonsInfo,
        .landMonsInfo_LG = &gMtPyre_2F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_3F),
        .mapNum = MAP_NUM(MT_PYRE_3F),
        .landMonsInfo_FR = &gMtPyre_3F_LandMonsInfo,
        .landMonsInfo_LG = &gMtPyre_3F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_4F),
        .mapNum = MAP_NUM(MT_PYRE_4F),
        .landMonsInfo_FR = &gMtPyre_4F_LandMonsInfo,
        .landMonsInfo_LG = &gMtPyre_4F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_5F),
        .mapNum = MAP_NUM(MT_PYRE_5F),
        .landMonsInfo_FR = &gMtPyre_5F_LandMonsInfo,
        .landMonsInfo_LG = &gMtPyre_5F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_6F),
        .mapNum = MAP_NUM(MT_PYRE_6F),
        .landMonsInfo_FR = &gMtPyre_6F_LandMonsInfo,
        .landMonsInfo_LG = &gMtPyre_6F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .mapNum = MAP_NUM(MT_PYRE_EXTERIOR),
        .landMonsInfo_FR = &gMtPyre_Exterior_LandMonsInfo,
        .landMonsInfo_LG = &gMtPyre_Exterior_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_SUMMIT),
        .mapNum = MAP_NUM(MT_PYRE_SUMMIT),
        .landMonsInfo_FR = &gMtPyre_Summit_LandMonsInfo,
        .landMonsInfo_LG = &gMtPyre_Summit_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .landMonsInfo_FR = &gShoalCave_LowTideStairsRoom_LandMonsInfo,
        .landMonsInfo_LG = &gShoalCave_LowTideStairsRoom_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .landMonsInfo_FR = &gShoalCave_LowTideLowerRoom_LandMonsInfo,
        .landMonsInfo_LG = &gShoalCave_LowTideLowerRoom_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .landMonsInfo_FR = &gShoalCave_LowTideInnerRoom_LandMonsInfo,
        .landMonsInfo_LG = &gShoalCave_LowTideInnerRoom_LandMonsInfo,
        .waterMonsInfo_FR = &gShoalCave_LowTideInnerRoom_WaterMonsInfo,
        .waterMonsInfo_LG = &gShoalCave_LowTideInnerRoom_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gShoalCave_LowTideInnerRoom_FishingMonsInfo,
        .fishingMonsInfo_LG = &gShoalCave_LowTideInnerRoom_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .landMonsInfo_FR = &gShoalCave_LowTideEntranceRoom_LandMonsInfo,
        .landMonsInfo_LG = &gShoalCave_LowTideEntranceRoom_LandMonsInfo,
        .waterMonsInfo_FR = &gShoalCave_LowTideEntranceRoom_WaterMonsInfo,
        .waterMonsInfo_LG = &gShoalCave_LowTideEntranceRoom_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gShoalCave_LowTideEntranceRoom_FishingMonsInfo,
        .fishingMonsInfo_LG = &gShoalCave_LowTideEntranceRoom_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .landMonsInfo_FR = &gShoalCave_LowTideIceRoom_LandMonsInfo,
        .landMonsInfo_LG = &gShoalCave_LowTideIceRoom_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM1),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM1),
        .landMonsInfo_FR = &gSeafloorCavern_Room1_LandMonsInfo,
        .landMonsInfo_LG = &gSeafloorCavern_Room1_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM2),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM2),
        .landMonsInfo_FR = &gSeafloorCavern_Room2_LandMonsInfo,
        .landMonsInfo_LG = &gSeafloorCavern_Room2_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM3),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM3),
        .landMonsInfo_FR = &gSeafloorCavern_Room3_LandMonsInfo,
        .landMonsInfo_LG = &gSeafloorCavern_Room3_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM4),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM4),
        .landMonsInfo_FR = &gSeafloorCavern_Room4_LandMonsInfo,
        .landMonsInfo_LG = &gSeafloorCavern_Room4_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM5),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM5),
        .landMonsInfo_FR = &gSeafloorCavern_Room5_LandMonsInfo,
        .landMonsInfo_LG = &gSeafloorCavern_Room5_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM6),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM6),
        .landMonsInfo_FR = &gSeafloorCavern_Room6_LandMonsInfo,
        .landMonsInfo_LG = &gSeafloorCavern_Room6_LandMonsInfo,
        .waterMonsInfo_FR = &gSeafloorCavern_Room6_WaterMonsInfo,
        .waterMonsInfo_LG = &gSeafloorCavern_Room6_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSeafloorCavern_Room6_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSeafloorCavern_Room6_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM7),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM7),
        .landMonsInfo_FR = &gSeafloorCavern_Room7_LandMonsInfo,
        .landMonsInfo_LG = &gSeafloorCavern_Room7_LandMonsInfo,
        .waterMonsInfo_FR = &gSeafloorCavern_Room7_WaterMonsInfo,
        .waterMonsInfo_LG = &gSeafloorCavern_Room7_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSeafloorCavern_Room7_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSeafloorCavern_Room7_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM8),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM8),
        .landMonsInfo_FR = &gSeafloorCavern_Room8_LandMonsInfo,
        .landMonsInfo_LG = &gSeafloorCavern_Room8_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ENTRANCE),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ENTRANCE),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gSeafloorCavern_Entrance_WaterMonsInfo,
        .waterMonsInfo_LG = &gSeafloorCavern_Entrance_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSeafloorCavern_Entrance_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSeafloorCavern_Entrance_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_ENTRANCE),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_ENTRANCE),
        .landMonsInfo_FR = &gCaveOfOrigin_Entrance_LandMonsInfo,
        .landMonsInfo_LG = &gCaveOfOrigin_Entrance_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_1F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_1F),
        .landMonsInfo_FR = &gCaveOfOrigin_1F_LandMonsInfo,
        .landMonsInfo_LG = &gCaveOfOrigin_1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .landMonsInfo_FR = &gCaveOfOrigin_UnusedRubySapphireMap1_LandMonsInfo,
        .landMonsInfo_LG = &gCaveOfOrigin_UnusedRubySapphireMap1_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .landMonsInfo_FR = &gCaveOfOrigin_UnusedRubySapphireMap2_LandMonsInfo,
        .landMonsInfo_LG = &gCaveOfOrigin_UnusedRubySapphireMap2_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .landMonsInfo_FR = &gCaveOfOrigin_UnusedRubySapphireMap3_LandMonsInfo,
        .landMonsInfo_LG = &gCaveOfOrigin_UnusedRubySapphireMap3_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(HOENN_VICTORY_ROAD_1F),
        .mapNum = MAP_NUM(HOENN_VICTORY_ROAD_1F),
        .landMonsInfo_FR = &gHoennVictoryRoad_1F_LandMonsInfo,
        .landMonsInfo_LG = &gHoennVictoryRoad_1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(HOENN_VICTORY_ROAD_B1F),
        .mapNum = MAP_NUM(HOENN_VICTORY_ROAD_B1F),
        .landMonsInfo_FR = &gHoennVictoryRoad_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gHoennVictoryRoad_B1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gHoennVictoryRoad_B1F_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gHoennVictoryRoad_B1F_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(HOENN_VICTORY_ROAD_B2F),
        .mapNum = MAP_NUM(HOENN_VICTORY_ROAD_B2F),
        .landMonsInfo_FR = &gHoennVictoryRoad_B2F_LandMonsInfo,
        .landMonsInfo_LG = &gHoennVictoryRoad_B2F_LandMonsInfo,
        .waterMonsInfo_FR = &gHoennVictoryRoad_B2F_WaterMonsInfo,
        .waterMonsInfo_LG = &gHoennVictoryRoad_B2F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gHoennVictoryRoad_B2F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gHoennVictoryRoad_B2F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_1F),
        .mapNum = MAP_NUM(SKY_PILLAR_1F),
        .landMonsInfo_FR = &gSkyPillar_1F_LandMonsInfo,
        .landMonsInfo_LG = &gSkyPillar_1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_3F),
        .mapNum = MAP_NUM(SKY_PILLAR_3F),
        .landMonsInfo_FR = &gSkyPillar_3F_LandMonsInfo,
        .landMonsInfo_LG = &gSkyPillar_3F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_5F),
        .mapNum = MAP_NUM(SKY_PILLAR_5F),
        .landMonsInfo_FR = &gSkyPillar_5F_LandMonsInfo,
        .landMonsInfo_LG = &gSkyPillar_5F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_1F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_1F),
        .landMonsInfo_FR = &gMirageTower_1F_LandMonsInfo,
        .landMonsInfo_LG = &gMirageTower_1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_2F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_2F),
        .landMonsInfo_FR = &gMirageTower_2F_LandMonsInfo,
        .landMonsInfo_LG = &gMirageTower_2F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_3F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_3F),
        .landMonsInfo_FR = &gMirageTower_3F_LandMonsInfo,
        .landMonsInfo_LG = &gMirageTower_3F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_4F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_4F),
        .landMonsInfo_FR = &gMirageTower_4F_LandMonsInfo,
        .landMonsInfo_LG = &gMirageTower_4F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(DESERT_UNDERPASS),
        .mapNum = MAP_NUM(DESERT_UNDERPASS),
        .landMonsInfo_FR = &gDesertUnderpass_LandMonsInfo,
        .landMonsInfo_LG = &gDesertUnderpass_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo_FR = &gAlteringCave1_LandMonsInfo,
        .landMonsInfo_LG = &gAlteringCave1_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(HOENN_SAFARI_ZONE_SOUTH),
        .mapNum = MAP_NUM(HOENN_SAFARI_ZONE_SOUTH),
        .landMonsInfo_FR = &gHoennSafariZone_South_LandMonsInfo,
        .landMonsInfo_LG = &gHoennSafariZone_South_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(HOENN_SAFARI_ZONE_SOUTHWEST),
        .mapNum = MAP_NUM(HOENN_SAFARI_ZONE_SOUTHWEST),
        .landMonsInfo_FR = &gHoennSafariZone_Southwest_LandMonsInfo,
        .landMonsInfo_LG = &gHoennSafariZone_Southwest_LandMonsInfo,
        .waterMonsInfo_FR = &gHoennSafariZone_Southwest_WaterMonsInfo,
        .waterMonsInfo_LG = &gHoennSafariZone_Southwest_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gHoennSafariZone_Southwest_FishingMonsInfo,
        .fishingMonsInfo_LG = &gHoennSafariZone_Southwest_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(HOENN_SAFARI_ZONE_NORTH),
        .mapNum = MAP_NUM(HOENN_SAFARI_ZONE_NORTH),
        .landMonsInfo_FR = &gHoennSafariZone_North_LandMonsInfo,
        .landMonsInfo_LG = &gHoennSafariZone_North_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gHoennSafariZone_North_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gHoennSafariZone_North_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(HOENN_SAFARI_ZONE_NORTHWEST),
        .mapNum = MAP_NUM(HOENN_SAFARI_ZONE_NORTHWEST),
        .landMonsInfo_FR = &gHoennSafariZone_Northwest_LandMonsInfo,
        .landMonsInfo_LG = &gHoennSafariZone_Northwest_LandMonsInfo,
        .waterMonsInfo_FR = &gHoennSafariZone_Northwest_WaterMonsInfo,
        .waterMonsInfo_LG = &gHoennSafariZone_Northwest_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gHoennSafariZone_Northwest_FishingMonsInfo,
        .fishingMonsInfo_LG = &gHoennSafariZone_Northwest_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(HOENN_SAFARI_ZONE_SOUTHEAST),
        .mapNum = MAP_NUM(HOENN_SAFARI_ZONE_SOUTHEAST),
        .landMonsInfo_FR = &gHoennSafariZone_Southeast_LandMonsInfo,
        .landMonsInfo_LG = &gHoennSafariZone_Southeast_LandMonsInfo,
        .waterMonsInfo_FR = &gHoennSafariZone_Southeast_WaterMonsInfo,
        .waterMonsInfo_LG = &gHoennSafariZone_Southeast_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gHoennSafariZone_Southeast_FishingMonsInfo,
        .fishingMonsInfo_LG = &gHoennSafariZone_Southeast_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(HOENN_SAFARI_ZONE_NORTHEAST),
        .mapNum = MAP_NUM(HOENN_SAFARI_ZONE_NORTHEAST),
        .landMonsInfo_FR = &gHoennSafariZone_Northeast_LandMonsInfo,
        .landMonsInfo_LG = &gHoennSafariZone_Northeast_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gHoennSafariZone_Northeast_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gHoennSafariZone_Northeast_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    // BEGIN johto_import headers
    {
        .mapGroup = MAP_GROUP(NEW_BARK_TOWN),
        .mapNum = MAP_NUM(NEW_BARK_TOWN),
        .landMonsInfo_FR = &gNewBarkTown_LandMonsInfo,
        .landMonsInfo_LG = &gNewBarkTown_LandMonsInfo,
        .waterMonsInfo_FR = &gNewBarkTown_WaterMonsInfo,
        .waterMonsInfo_LG = &gNewBarkTown_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gNewBarkTown_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gNewBarkTown_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gNewBarkTown_FishingMonsInfo,
        .fishingMonsInfo_LG = &gNewBarkTown_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CHERRYGROVE_CITY),
        .mapNum = MAP_NUM(CHERRYGROVE_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gCherrygroveCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gCherrygroveCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gCherrygroveCity_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gCherrygroveCity_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gCherrygroveCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gCherrygroveCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(VIOLET_CITY),
        .mapNum = MAP_NUM(VIOLET_CITY),
        .landMonsInfo_FR = &gVioletCity_LandMonsInfo,
        .landMonsInfo_LG = &gVioletCity_LandMonsInfo,
        .waterMonsInfo_FR = &gVioletCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gVioletCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gVioletCity_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gVioletCity_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gVioletCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gVioletCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(AZALEA_TOWN),
        .mapNum = MAP_NUM(AZALEA_TOWN),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gAzaleaTown_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gAzaleaTown_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GOLDENROD_CITY),
        .mapNum = MAP_NUM(GOLDENROD_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gGoldenrodCity_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gGoldenrodCity_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ECRUTEAK_CITY),
        .mapNum = MAP_NUM(ECRUTEAK_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gEcruteakCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gEcruteakCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gEcruteakCity_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gEcruteakCity_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gEcruteakCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gEcruteakCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(OLIVINE_CITY),
        .mapNum = MAP_NUM(OLIVINE_CITY),
        .landMonsInfo_FR = &gOlivineCity_LandMonsInfo,
        .landMonsInfo_LG = &gOlivineCity_LandMonsInfo,
        .waterMonsInfo_FR = &gOlivineCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gOlivineCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gOlivineCity_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gOlivineCity_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gOlivineCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gOlivineCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CIANWOOD_CITY),
        .mapNum = MAP_NUM(CIANWOOD_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gCianwoodCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gCianwoodCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gCianwoodCity_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gCianwoodCity_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gCianwoodCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gCianwoodCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_GATE),
        .mapNum = MAP_NUM(SAFARI_ZONE_GATE),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gSafariZoneGate_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gSafariZoneGate_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAHOGANY_TOWN),
        .mapNum = MAP_NUM(MAHOGANY_TOWN),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gMahoganyTown_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gMahoganyTown_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(BLACKTHORN_CITY),
        .mapNum = MAP_NUM(BLACKTHORN_CITY),
        .landMonsInfo_FR = &gBlackthornCity_LandMonsInfo,
        .landMonsInfo_LG = &gBlackthornCity_LandMonsInfo,
        .waterMonsInfo_FR = &gBlackthornCity_WaterMonsInfo,
        .waterMonsInfo_LG = &gBlackthornCity_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gBlackthornCity_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gBlackthornCity_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gBlackthornCity_FishingMonsInfo,
        .fishingMonsInfo_LG = &gBlackthornCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE29),
        .mapNum = MAP_NUM(ROUTE29),
        .landMonsInfo_FR = &gRoute29_LandMonsInfo,
        .landMonsInfo_LG = &gRoute29_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gRoute29_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute29_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE30),
        .mapNum = MAP_NUM(ROUTE30),
        .landMonsInfo_FR = &gRoute30_LandMonsInfo,
        .landMonsInfo_LG = &gRoute30_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute30_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute30_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute30_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute30_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute30_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute30_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE31),
        .mapNum = MAP_NUM(ROUTE31),
        .landMonsInfo_FR = &gRoute31_LandMonsInfo,
        .landMonsInfo_LG = &gRoute31_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute31_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute31_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute31_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute31_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute31_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute31_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE32),
        .mapNum = MAP_NUM(ROUTE32),
        .landMonsInfo_FR = &gRoute32_LandMonsInfo,
        .landMonsInfo_LG = &gRoute32_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute32_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute32_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute32_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute32_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute32_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute32_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE33),
        .mapNum = MAP_NUM(ROUTE33),
        .landMonsInfo_FR = &gRoute33_LandMonsInfo,
        .landMonsInfo_LG = &gRoute33_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gRoute33_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute33_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE34),
        .mapNum = MAP_NUM(ROUTE34),
        .landMonsInfo_FR = &gRoute34_LandMonsInfo,
        .landMonsInfo_LG = &gRoute34_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute34_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute34_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute34_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute34_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute34_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute34_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE35),
        .mapNum = MAP_NUM(ROUTE35),
        .landMonsInfo_FR = &gRoute35_LandMonsInfo,
        .landMonsInfo_LG = &gRoute35_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute35_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute35_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute35_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute35_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute35_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute35_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE36),
        .mapNum = MAP_NUM(ROUTE36),
        .landMonsInfo_FR = &gRoute36_LandMonsInfo,
        .landMonsInfo_LG = &gRoute36_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gRoute36_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute36_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE37),
        .mapNum = MAP_NUM(ROUTE37),
        .landMonsInfo_FR = &gRoute37_LandMonsInfo,
        .landMonsInfo_LG = &gRoute37_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gRoute37_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute37_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE38),
        .mapNum = MAP_NUM(ROUTE38),
        .landMonsInfo_FR = &gRoute38_LandMonsInfo,
        .landMonsInfo_LG = &gRoute38_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gRoute38_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute38_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE39),
        .mapNum = MAP_NUM(ROUTE39),
        .landMonsInfo_FR = &gRoute39_LandMonsInfo,
        .landMonsInfo_LG = &gRoute39_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gRoute39_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute39_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE40),
        .mapNum = MAP_NUM(ROUTE40),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute40_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute40_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute40_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute40_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE41),
        .mapNum = MAP_NUM(ROUTE41),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gRoute41_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute41_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gRoute41_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute41_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE42),
        .mapNum = MAP_NUM(ROUTE42),
        .landMonsInfo_FR = &gRoute42_LandMonsInfo,
        .landMonsInfo_LG = &gRoute42_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute42_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute42_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute42_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute42_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute42_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute42_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE43),
        .mapNum = MAP_NUM(ROUTE43),
        .landMonsInfo_FR = &gRoute43_LandMonsInfo,
        .landMonsInfo_LG = &gRoute43_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute43_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute43_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute43_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute43_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute43_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute43_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE44),
        .mapNum = MAP_NUM(ROUTE44),
        .landMonsInfo_FR = &gRoute44_LandMonsInfo,
        .landMonsInfo_LG = &gRoute44_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute44_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute44_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute44_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute44_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute44_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute44_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE45),
        .mapNum = MAP_NUM(ROUTE45),
        .landMonsInfo_FR = &gRoute45_LandMonsInfo,
        .landMonsInfo_LG = &gRoute45_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute45_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute45_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute45_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute45_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute45_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute45_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE46),
        .mapNum = MAP_NUM(ROUTE46),
        .landMonsInfo_FR = &gRoute46_LandMonsInfo,
        .landMonsInfo_LG = &gRoute46_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gRoute46_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute46_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE47),
        .mapNum = MAP_NUM(ROUTE47),
        .landMonsInfo_FR = &gRoute47_LandMonsInfo,
        .landMonsInfo_LG = &gRoute47_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute47_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute47_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute47_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute47_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute47_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute47_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE48),
        .mapNum = MAP_NUM(ROUTE48),
        .landMonsInfo_FR = &gRoute48_LandMonsInfo,
        .landMonsInfo_LG = &gRoute48_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gRoute48_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute48_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE26),
        .mapNum = MAP_NUM(ROUTE26),
        .landMonsInfo_FR = &gRoute26_LandMonsInfo,
        .landMonsInfo_LG = &gRoute26_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute26_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute26_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute26_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute26_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute26_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute26_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE27),
        .mapNum = MAP_NUM(ROUTE27),
        .landMonsInfo_FR = &gRoute27_LandMonsInfo,
        .landMonsInfo_LG = &gRoute27_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute27_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute27_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute27_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute27_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute27_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute27_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE28),
        .mapNum = MAP_NUM(ROUTE28),
        .landMonsInfo_FR = &gRoute28_LandMonsInfo,
        .landMonsInfo_LG = &gRoute28_LandMonsInfo,
        .waterMonsInfo_FR = &gRoute28_WaterMonsInfo,
        .waterMonsInfo_LG = &gRoute28_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRoute28_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRoute28_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRoute28_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRoute28_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(OLIVINE_CITY_PORT_OUTSIDE),
        .mapNum = MAP_NUM(OLIVINE_CITY_PORT_OUTSIDE),
        .landMonsInfo_FR = &gOlivineCity_PortOutside_LandMonsInfo,
        .landMonsInfo_LG = &gOlivineCity_PortOutside_LandMonsInfo,
        .waterMonsInfo_FR = &gOlivineCity_PortOutside_WaterMonsInfo,
        .waterMonsInfo_LG = &gOlivineCity_PortOutside_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gOlivineCity_PortOutside_FishingMonsInfo,
        .fishingMonsInfo_LG = &gOlivineCity_PortOutside_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(DARK_CAVE_SOUTH_SIDE),
        .mapNum = MAP_NUM(DARK_CAVE_SOUTH_SIDE),
        .landMonsInfo_FR = &gDarkCave_SouthSide_LandMonsInfo,
        .landMonsInfo_LG = &gDarkCave_SouthSide_LandMonsInfo,
        .waterMonsInfo_FR = &gDarkCave_SouthSide_WaterMonsInfo,
        .waterMonsInfo_LG = &gDarkCave_SouthSide_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gDarkCave_SouthSide_FishingMonsInfo,
        .fishingMonsInfo_LG = &gDarkCave_SouthSide_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(DARK_CAVE_NORTH_SIDE),
        .mapNum = MAP_NUM(DARK_CAVE_NORTH_SIDE),
        .landMonsInfo_FR = &gDarkCave_NorthSide_LandMonsInfo,
        .landMonsInfo_LG = &gDarkCave_NorthSide_LandMonsInfo,
        .waterMonsInfo_FR = &gDarkCave_NorthSide_WaterMonsInfo,
        .waterMonsInfo_LG = &gDarkCave_NorthSide_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gDarkCave_NorthSide_FishingMonsInfo,
        .fishingMonsInfo_LG = &gDarkCave_NorthSide_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SPROUT_TOWER_2F),
        .mapNum = MAP_NUM(SPROUT_TOWER_2F),
        .landMonsInfo_FR = &gSproutTower_2F_LandMonsInfo,
        .landMonsInfo_LG = &gSproutTower_2F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SPROUT_TOWER_3F),
        .mapNum = MAP_NUM(SPROUT_TOWER_3F),
        .landMonsInfo_FR = &gSproutTower_3F_LandMonsInfo,
        .landMonsInfo_LG = &gSproutTower_3F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(RUINS_OF_ALPH_OUTSIDE),
        .mapNum = MAP_NUM(RUINS_OF_ALPH_OUTSIDE),
        .landMonsInfo_FR = &gRuinsOfAlph_Outside_LandMonsInfo,
        .landMonsInfo_LG = &gRuinsOfAlph_Outside_LandMonsInfo,
        .waterMonsInfo_FR = &gRuinsOfAlph_Outside_WaterMonsInfo,
        .waterMonsInfo_LG = &gRuinsOfAlph_Outside_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gRuinsOfAlph_Outside_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gRuinsOfAlph_Outside_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gRuinsOfAlph_Outside_FishingMonsInfo,
        .fishingMonsInfo_LG = &gRuinsOfAlph_Outside_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(RUINS_OF_ALPH_B1F),
        .mapNum = MAP_NUM(RUINS_OF_ALPH_B1F),
        .landMonsInfo_FR = &gRuinsOfAlph_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gRuinsOfAlph_B1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNION_CAVE_1F),
        .mapNum = MAP_NUM(UNION_CAVE_1F),
        .landMonsInfo_FR = &gUnionCave_1F_LandMonsInfo,
        .landMonsInfo_LG = &gUnionCave_1F_LandMonsInfo,
        .waterMonsInfo_FR = &gUnionCave_1F_WaterMonsInfo,
        .waterMonsInfo_LG = &gUnionCave_1F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gUnionCave_1F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gUnionCave_1F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(UNION_CAVE_B1F),
        .mapNum = MAP_NUM(UNION_CAVE_B1F),
        .landMonsInfo_FR = &gUnionCave_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gUnionCave_B1F_LandMonsInfo,
        .waterMonsInfo_FR = &gUnionCave_B1F_WaterMonsInfo,
        .waterMonsInfo_LG = &gUnionCave_B1F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gUnionCave_B1F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gUnionCave_B1F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(UNION_CAVE_B2F),
        .mapNum = MAP_NUM(UNION_CAVE_B2F),
        .landMonsInfo_FR = &gUnionCave_B2F_LandMonsInfo,
        .landMonsInfo_LG = &gUnionCave_B2F_LandMonsInfo,
        .waterMonsInfo_FR = &gUnionCave_B2F_WaterMonsInfo,
        .waterMonsInfo_LG = &gUnionCave_B2F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gUnionCave_B2F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gUnionCave_B2F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SLOWPOKE_WELL_B1F),
        .mapNum = MAP_NUM(SLOWPOKE_WELL_B1F),
        .landMonsInfo_FR = &gSlowpokeWell_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gSlowpokeWell_B1F_LandMonsInfo,
        .waterMonsInfo_FR = &gSlowpokeWell_B1F_WaterMonsInfo,
        .waterMonsInfo_LG = &gSlowpokeWell_B1F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSlowpokeWell_B1F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSlowpokeWell_B1F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SLOWPOKE_WELL_B2F),
        .mapNum = MAP_NUM(SLOWPOKE_WELL_B2F),
        .landMonsInfo_FR = &gSlowpokeWell_B2F_LandMonsInfo,
        .landMonsInfo_LG = &gSlowpokeWell_B2F_LandMonsInfo,
        .waterMonsInfo_FR = &gSlowpokeWell_B2F_WaterMonsInfo,
        .waterMonsInfo_LG = &gSlowpokeWell_B2F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSlowpokeWell_B2F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSlowpokeWell_B2F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ILEX_FOREST),
        .mapNum = MAP_NUM(ILEX_FOREST),
        .landMonsInfo_FR = &gIlexForest_LandMonsInfo,
        .landMonsInfo_LG = &gIlexForest_LandMonsInfo,
        .waterMonsInfo_FR = &gIlexForest_WaterMonsInfo,
        .waterMonsInfo_LG = &gIlexForest_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gIlexForest_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gIlexForest_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gIlexForest_FishingMonsInfo,
        .fishingMonsInfo_LG = &gIlexForest_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(NATIONAL_PARK_NORMAL),
        .mapNum = MAP_NUM(NATIONAL_PARK_NORMAL),
        .landMonsInfo_FR = &gNationalPark_Normal_LandMonsInfo,
        .landMonsInfo_LG = &gNationalPark_Normal_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(NATIONAL_PARK_BUG_CONTEST),
        .mapNum = MAP_NUM(NATIONAL_PARK_BUG_CONTEST),
        .landMonsInfo_FR = &gNationalPark_BugContest_LandMonsInfo,
        .landMonsInfo_LG = &gNationalPark_BugContest_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(BURNED_TOWER_1F),
        .mapNum = MAP_NUM(BURNED_TOWER_1F),
        .landMonsInfo_FR = &gBurnedTower_1F_LandMonsInfo,
        .landMonsInfo_LG = &gBurnedTower_1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(BURNED_TOWER_B1F),
        .mapNum = MAP_NUM(BURNED_TOWER_B1F),
        .landMonsInfo_FR = &gBurnedTower_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gBurnedTower_B1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CLIFF_EDGE_GATE),
        .mapNum = MAP_NUM(CLIFF_EDGE_GATE),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gCliffEdgeGate_WaterMonsInfo,
        .waterMonsInfo_LG = &gCliffEdgeGate_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_MORTAR_1F_SOUTH),
        .mapNum = MAP_NUM(MT_MORTAR_1F_SOUTH),
        .landMonsInfo_FR = &gMtMortar_1F_South_LandMonsInfo,
        .landMonsInfo_LG = &gMtMortar_1F_South_LandMonsInfo,
        .waterMonsInfo_FR = &gMtMortar_1F_South_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtMortar_1F_South_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMtMortar_1F_South_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtMortar_1F_South_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_MORTAR_1F_NORTH),
        .mapNum = MAP_NUM(MT_MORTAR_1F_NORTH),
        .landMonsInfo_FR = &gMtMortar_1F_North_LandMonsInfo,
        .landMonsInfo_LG = &gMtMortar_1F_North_LandMonsInfo,
        .waterMonsInfo_FR = &gMtMortar_1F_North_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtMortar_1F_North_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMtMortar_1F_North_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtMortar_1F_North_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_MORTAR_2F),
        .mapNum = MAP_NUM(MT_MORTAR_2F),
        .landMonsInfo_FR = &gMtMortar_2F_LandMonsInfo,
        .landMonsInfo_LG = &gMtMortar_2F_LandMonsInfo,
        .waterMonsInfo_FR = &gMtMortar_2F_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtMortar_2F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMtMortar_2F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtMortar_2F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_MORTAR_B1F),
        .mapNum = MAP_NUM(MT_MORTAR_B1F),
        .landMonsInfo_FR = &gMtMortar_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gMtMortar_B1F_LandMonsInfo,
        .waterMonsInfo_FR = &gMtMortar_B1F_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtMortar_B1F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMtMortar_B1F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtMortar_B1F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(LAKE_OF_RAGE),
        .mapNum = MAP_NUM(LAKE_OF_RAGE),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gLakeOfRage_WaterMonsInfo,
        .waterMonsInfo_LG = &gLakeOfRage_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gLakeOfRage_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gLakeOfRage_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gLakeOfRage_FishingMonsInfo,
        .fishingMonsInfo_LG = &gLakeOfRage_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ICE_PATH_1F),
        .mapNum = MAP_NUM(ICE_PATH_1F),
        .landMonsInfo_FR = &gIcePath_1F_LandMonsInfo,
        .landMonsInfo_LG = &gIcePath_1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ICE_PATH_B1F),
        .mapNum = MAP_NUM(ICE_PATH_B1F),
        .landMonsInfo_FR = &gIcePath_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gIcePath_B1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ICE_PATH_B2F),
        .mapNum = MAP_NUM(ICE_PATH_B2F),
        .landMonsInfo_FR = &gIcePath_B2F_LandMonsInfo,
        .landMonsInfo_LG = &gIcePath_B2F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ICE_PATH_B3F),
        .mapNum = MAP_NUM(ICE_PATH_B3F),
        .landMonsInfo_FR = &gIcePath_B3F_LandMonsInfo,
        .landMonsInfo_LG = &gIcePath_B3F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ICE_PATH_B4F),
        .mapNum = MAP_NUM(ICE_PATH_B4F),
        .landMonsInfo_FR = &gIcePath_B4F_LandMonsInfo,
        .landMonsInfo_LG = &gIcePath_B4F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(DRAGONS_DEN_CAVERN),
        .mapNum = MAP_NUM(DRAGONS_DEN_CAVERN),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &gDragonsDen_Cavern_WaterMonsInfo,
        .waterMonsInfo_LG = &gDragonsDen_Cavern_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gDragonsDen_Cavern_FishingMonsInfo,
        .fishingMonsInfo_LG = &gDragonsDen_Cavern_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(WHIRL_ISLANDS_1F),
        .mapNum = MAP_NUM(WHIRL_ISLANDS_1F),
        .landMonsInfo_FR = &gWhirlIslands_1F_LandMonsInfo,
        .landMonsInfo_LG = &gWhirlIslands_1F_LandMonsInfo,
        .waterMonsInfo_FR = &gWhirlIslands_1F_WaterMonsInfo,
        .waterMonsInfo_LG = &gWhirlIslands_1F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gWhirlIslands_1F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gWhirlIslands_1F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(WHIRL_ISLANDS_B1F),
        .mapNum = MAP_NUM(WHIRL_ISLANDS_B1F),
        .landMonsInfo_FR = &gWhirlIslands_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gWhirlIslands_B1F_LandMonsInfo,
        .waterMonsInfo_FR = &gWhirlIslands_B1F_WaterMonsInfo,
        .waterMonsInfo_LG = &gWhirlIslands_B1F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gWhirlIslands_B1F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gWhirlIslands_B1F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(WHIRL_ISLANDS_B1F_INNER),
        .mapNum = MAP_NUM(WHIRL_ISLANDS_B1F_INNER),
        .landMonsInfo_FR = &gWhirlIslands_B1F_Inner_LandMonsInfo,
        .landMonsInfo_LG = &gWhirlIslands_B1F_Inner_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(WHIRL_ISLANDS_B2F),
        .mapNum = MAP_NUM(WHIRL_ISLANDS_B2F),
        .landMonsInfo_FR = &gWhirlIslands_B2F_LandMonsInfo,
        .landMonsInfo_LG = &gWhirlIslands_B2F_LandMonsInfo,
        .waterMonsInfo_FR = &gWhirlIslands_B2F_WaterMonsInfo,
        .waterMonsInfo_LG = &gWhirlIslands_B2F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gWhirlIslands_B2F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gWhirlIslands_B2F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(WHIRL_ISLANDS_B3F),
        .mapNum = MAP_NUM(WHIRL_ISLANDS_B3F),
        .landMonsInfo_FR = &gWhirlIslands_B3F_LandMonsInfo,
        .landMonsInfo_LG = &gWhirlIslands_B3F_LandMonsInfo,
        .waterMonsInfo_FR = &gWhirlIslands_B3F_WaterMonsInfo,
        .waterMonsInfo_LG = &gWhirlIslands_B3F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gWhirlIslands_B3F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gWhirlIslands_B3F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(WHIRL_ISLANDS_DESCENT),
        .mapNum = MAP_NUM(WHIRL_ISLANDS_DESCENT),
        .landMonsInfo_FR = &gWhirlIslands_Descent_LandMonsInfo,
        .landMonsInfo_LG = &gWhirlIslands_Descent_LandMonsInfo,
        .waterMonsInfo_FR = &gWhirlIslands_Descent_WaterMonsInfo,
        .waterMonsInfo_LG = &gWhirlIslands_Descent_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gWhirlIslands_Descent_FishingMonsInfo,
        .fishingMonsInfo_LG = &gWhirlIslands_Descent_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(TIN_TOWER_3F),
        .mapNum = MAP_NUM(TIN_TOWER_3F),
        .landMonsInfo_FR = &gTinTower_3F_LandMonsInfo,
        .landMonsInfo_LG = &gTinTower_3F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(TIN_TOWER_4F),
        .mapNum = MAP_NUM(TIN_TOWER_4F),
        .landMonsInfo_FR = &gTinTower_4F_LandMonsInfo,
        .landMonsInfo_LG = &gTinTower_4F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(TIN_TOWER_5F),
        .mapNum = MAP_NUM(TIN_TOWER_5F),
        .landMonsInfo_FR = &gTinTower_5F_LandMonsInfo,
        .landMonsInfo_LG = &gTinTower_5F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(TIN_TOWER_6F),
        .mapNum = MAP_NUM(TIN_TOWER_6F),
        .landMonsInfo_FR = &gTinTower_6F_LandMonsInfo,
        .landMonsInfo_LG = &gTinTower_6F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(TIN_TOWER_7F),
        .mapNum = MAP_NUM(TIN_TOWER_7F),
        .landMonsInfo_FR = &gTinTower_7F_LandMonsInfo,
        .landMonsInfo_LG = &gTinTower_7F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(TIN_TOWER_8F),
        .mapNum = MAP_NUM(TIN_TOWER_8F),
        .landMonsInfo_FR = &gTinTower_8F_LandMonsInfo,
        .landMonsInfo_LG = &gTinTower_8F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(TIN_TOWER_9F),
        .mapNum = MAP_NUM(TIN_TOWER_9F),
        .landMonsInfo_FR = &gTinTower_9F_LandMonsInfo,
        .landMonsInfo_LG = &gTinTower_9F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(TOHJO_FALLS_CAVERN),
        .mapNum = MAP_NUM(TOHJO_FALLS_CAVERN),
        .landMonsInfo_FR = &gTohjoFalls_Cavern_LandMonsInfo,
        .landMonsInfo_LG = &gTohjoFalls_Cavern_LandMonsInfo,
        .waterMonsInfo_FR = &gTohjoFalls_Cavern_WaterMonsInfo,
        .waterMonsInfo_LG = &gTohjoFalls_Cavern_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gTohjoFalls_Cavern_FishingMonsInfo,
        .fishingMonsInfo_LG = &gTohjoFalls_Cavern_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_SILVER_OUTSIDE),
        .mapNum = MAP_NUM(MT_SILVER_OUTSIDE),
        .landMonsInfo_FR = &gMtSilver_Outside_LandMonsInfo,
        .landMonsInfo_LG = &gMtSilver_Outside_LandMonsInfo,
        .waterMonsInfo_FR = &gMtSilver_Outside_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtSilver_Outside_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gMtSilver_Outside_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gMtSilver_Outside_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gMtSilver_Outside_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtSilver_Outside_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_SILVER_1F_ITEM_ROOM),
        .mapNum = MAP_NUM(MT_SILVER_1F_ITEM_ROOM),
        .landMonsInfo_FR = &gMtSilver_1F_ItemRoom_LandMonsInfo,
        .landMonsInfo_LG = &gMtSilver_1F_ItemRoom_LandMonsInfo,
        .waterMonsInfo_FR = &gMtSilver_1F_ItemRoom_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtSilver_1F_ItemRoom_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMtSilver_1F_ItemRoom_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtSilver_1F_ItemRoom_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_SILVER_1F_WATERFALL_ROOM),
        .mapNum = MAP_NUM(MT_SILVER_1F_WATERFALL_ROOM),
        .landMonsInfo_FR = &gMtSilver_1F_WaterfallRoom_LandMonsInfo,
        .landMonsInfo_LG = &gMtSilver_1F_WaterfallRoom_LandMonsInfo,
        .waterMonsInfo_FR = &gMtSilver_1F_WaterfallRoom_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtSilver_1F_WaterfallRoom_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMtSilver_1F_WaterfallRoom_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtSilver_1F_WaterfallRoom_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_SILVER_1F_MOLTRES_ROOM),
        .mapNum = MAP_NUM(MT_SILVER_1F_MOLTRES_ROOM),
        .landMonsInfo_FR = &gMtSilver_1F_MoltresRoom_LandMonsInfo,
        .landMonsInfo_LG = &gMtSilver_1F_MoltresRoom_LandMonsInfo,
        .waterMonsInfo_FR = &gMtSilver_1F_MoltresRoom_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtSilver_1F_MoltresRoom_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMtSilver_1F_MoltresRoom_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtSilver_1F_MoltresRoom_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_SILVER_MOUNTAIN_SIDE),
        .mapNum = MAP_NUM(MT_SILVER_MOUNTAIN_SIDE),
        .landMonsInfo_FR = &gMtSilver_MountainSide_LandMonsInfo,
        .landMonsInfo_LG = &gMtSilver_MountainSide_LandMonsInfo,
        .waterMonsInfo_FR = &gMtSilver_MountainSide_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtSilver_MountainSide_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &gMtSilver_MountainSide_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gMtSilver_MountainSide_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &gMtSilver_MountainSide_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtSilver_MountainSide_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_SILVER_2F),
        .mapNum = MAP_NUM(MT_SILVER_2F),
        .landMonsInfo_FR = &gMtSilver_2F_LandMonsInfo,
        .landMonsInfo_LG = &gMtSilver_2F_LandMonsInfo,
        .waterMonsInfo_FR = &gMtSilver_2F_WaterMonsInfo,
        .waterMonsInfo_LG = &gMtSilver_2F_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gMtSilver_2F_FishingMonsInfo,
        .fishingMonsInfo_LG = &gMtSilver_2F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_SILVER_3F),
        .mapNum = MAP_NUM(MT_SILVER_3F),
        .landMonsInfo_FR = &gMtSilver_3F_LandMonsInfo,
        .landMonsInfo_LG = &gMtSilver_3F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_SILVER_SNOW),
        .mapNum = MAP_NUM(MT_SILVER_SNOW),
        .landMonsInfo_FR = &gMtSilver_Snow_LandMonsInfo,
        .landMonsInfo_LG = &gMtSilver_Snow_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CLIFF_EDGE_CAVE),
        .mapNum = MAP_NUM(CLIFF_EDGE_CAVE),
        .landMonsInfo_FR = &gCliffEdgeCave_LandMonsInfo,
        .landMonsInfo_LG = &gCliffEdgeCave_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &gCliffEdgeCave_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &gCliffEdgeCave_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(JOHTO_ROCKET_HIDEOUT_B1F),
        .mapNum = MAP_NUM(JOHTO_ROCKET_HIDEOUT_B1F),
        .landMonsInfo_FR = &gJohtoRocketHideout_B1F_LandMonsInfo,
        .landMonsInfo_LG = &gJohtoRocketHideout_B1F_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_TOP_LEFT),
        .mapNum = MAP_NUM(SAFARI_ZONE_TOP_LEFT),
        .landMonsInfo_FR = &gSafariZone_Top_Left_LandMonsInfo,
        .landMonsInfo_LG = &gSafariZone_Top_Left_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_LOW_MID),
        .mapNum = MAP_NUM(SAFARI_ZONE_LOW_MID),
        .landMonsInfo_FR = &gSafariZone_Low_Mid_LandMonsInfo,
        .landMonsInfo_LG = &gSafariZone_Low_Mid_LandMonsInfo,
        .waterMonsInfo_FR = &gSafariZone_Low_Mid_WaterMonsInfo,
        .waterMonsInfo_LG = &gSafariZone_Low_Mid_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSafariZone_Low_Mid_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSafariZone_Low_Mid_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_LOW_LEFT),
        .mapNum = MAP_NUM(SAFARI_ZONE_LOW_LEFT),
        .landMonsInfo_FR = &gSafariZone_Low_Left_LandMonsInfo,
        .landMonsInfo_LG = &gSafariZone_Low_Left_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_LOW_RIGHT),
        .mapNum = MAP_NUM(SAFARI_ZONE_LOW_RIGHT),
        .landMonsInfo_FR = &gSafariZone_Low_Right_LandMonsInfo,
        .landMonsInfo_LG = &gSafariZone_Low_Right_LandMonsInfo,
        .waterMonsInfo_FR = &gSafariZone_Low_Right_WaterMonsInfo,
        .waterMonsInfo_LG = &gSafariZone_Low_Right_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSafariZone_Low_Right_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSafariZone_Low_Right_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_TOP_MID),
        .mapNum = MAP_NUM(SAFARI_ZONE_TOP_MID),
        .landMonsInfo_FR = &gSafariZone_Top_Mid_LandMonsInfo,
        .landMonsInfo_LG = &gSafariZone_Top_Mid_LandMonsInfo,
        .waterMonsInfo_FR = &gSafariZone_Top_Mid_WaterMonsInfo,
        .waterMonsInfo_LG = &gSafariZone_Top_Mid_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSafariZone_Top_Mid_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSafariZone_Top_Mid_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_TOP_RIGHT),
        .mapNum = MAP_NUM(SAFARI_ZONE_TOP_RIGHT),
        .landMonsInfo_FR = &gSafariZone_Top_Right_LandMonsInfo,
        .landMonsInfo_LG = &gSafariZone_Top_Right_LandMonsInfo,
        .waterMonsInfo_FR = &gSafariZone_Top_Right_WaterMonsInfo,
        .waterMonsInfo_LG = &gSafariZone_Top_Right_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &gSafariZone_Top_Right_FishingMonsInfo,
        .fishingMonsInfo_LG = &gSafariZone_Top_Right_FishingMonsInfo,
    },
    // END johto_import headers
    // Terminator: both loops over this table (wild_encounter.c, wild_pokemon_area.c) stop here.
    // Keep it last; new entries go above it (indexes 133/134 are tested in wild_pokemon_area.c).
    {
        .mapGroup = MAP_GROUP(UNDEFINED),
        .mapNum = MAP_NUM(UNDEFINED),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
};
