// RFVF+: Emerald's Battle Pike and Battle Pyramid wild mons (batch 6, work/hoenn_scripts/frontier_wild.py)
// Index: GetBattlePikeWildMonHeaderId() / the Pyramid's battle number (curChallengeBattleNum)
static const struct WildPokemon gBattlePyramid_1_LandMons[] =
{
    {5, 5, SPECIES_BULBASAUR},
    {5, 5, SPECIES_BULBASAUR},
    {5, 5, SPECIES_BULBASAUR},
    {5, 5, SPECIES_BULBASAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_CHARMANDER},
};

static const struct WildPokemonInfo gBattlePyramid_1_LandMonsInfo = {4, gBattlePyramid_1_LandMons};

static const struct WildPokemon gBattlePyramid_2_LandMons[] =
{
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMANDER},
};

static const struct WildPokemonInfo gBattlePyramid_2_LandMonsInfo = {4, gBattlePyramid_2_LandMons};

static const struct WildPokemon gBattlePyramid_3_LandMons[] =
{
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARIZARD},
};

static const struct WildPokemonInfo gBattlePyramid_3_LandMonsInfo = {4, gBattlePyramid_3_LandMons};

static const struct WildPokemon gBattlePyramid_4_LandMons[] =
{
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_SQUIRTLE},
};

static const struct WildPokemonInfo gBattlePyramid_4_LandMonsInfo = {4, gBattlePyramid_4_LandMons};

static const struct WildPokemon gBattlePyramid_5_LandMons[] =
{
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_WARTORTLE},
};

static const struct WildPokemonInfo gBattlePyramid_5_LandMonsInfo = {4, gBattlePyramid_5_LandMons};

static const struct WildPokemon gBattlePyramid_6_LandMons[] =
{
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
};

static const struct WildPokemonInfo gBattlePyramid_6_LandMonsInfo = {4, gBattlePyramid_6_LandMons};

static const struct WildPokemon gBattlePyramid_7_LandMons[] =
{
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
};

static const struct WildPokemonInfo gBattlePyramid_7_LandMonsInfo = {8, gBattlePyramid_7_LandMons};

static const struct WildPokemonHeader gBattlePyramidWildMonHeaders[] =
{
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePyramid_1_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePyramid_1_LandMonsInfo,
    },
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePyramid_2_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePyramid_2_LandMonsInfo,
    },
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePyramid_3_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePyramid_3_LandMonsInfo,
    },
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePyramid_4_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePyramid_4_LandMonsInfo,
    },
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePyramid_5_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePyramid_5_LandMonsInfo,
    },
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePyramid_6_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePyramid_6_LandMonsInfo,
    },
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePyramid_7_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePyramid_7_LandMonsInfo,
    },
};

static const struct WildPokemon gBattlePike_1_LandMons[] =
{
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
};

static const struct WildPokemonInfo gBattlePike_1_LandMonsInfo = {10, gBattlePike_1_LandMons};

static const struct WildPokemon gBattlePike_2_LandMons[] =
{
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
};

static const struct WildPokemonInfo gBattlePike_2_LandMonsInfo = {10, gBattlePike_2_LandMons};

static const struct WildPokemon gBattlePike_3_LandMons[] =
{
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
};

static const struct WildPokemonInfo gBattlePike_3_LandMonsInfo = {10, gBattlePike_3_LandMons};

static const struct WildPokemon gBattlePike_4_LandMons[] =
{
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
};

static const struct WildPokemonInfo gBattlePike_4_LandMonsInfo = {10, gBattlePike_4_LandMons};

static const struct WildPokemonHeader gBattlePikeWildMonHeaders[] =
{
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePike_1_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePike_1_LandMonsInfo,
    },
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePike_2_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePike_2_LandMonsInfo,
    },
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePike_3_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePike_3_LandMonsInfo,
    },
    {
        .mapGroup = 0,
        .mapNum = 0,
        .landMonsInfo_FR = &gBattlePike_4_LandMonsInfo,
        .landMonsInfo_LG = &gBattlePike_4_LandMonsInfo,
    },
};

