const struct PokedexEntry gPokedexEntries[] =
{
    [NATIONAL_DEX_NONE] =
    {
        .categoryName = _("INCONNU"),
        .height = 0,
        .weight = 0,
        .description_FR = gDummyPokedexText_FR,
        .description_LG = gDummyPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BULBASAUR] =
    {
        .categoryName = _("GRAINE"),
        .height = 7,
        .weight = 69,
        .description_FR = gBulbasaurPokedexText_FR,
        .description_LG = gBulbasaurPokedexText_LG,
        .pokemonScale = 356,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_IVYSAUR] =
    {
        .categoryName = _("GRAINE"),
        .height = 10,
        .weight = 130,
        .description_FR = gIvysaurPokedexText_FR,
        .description_LG = gIvysaurPokedexText_LG,
        .pokemonScale = 332,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_VENUSAUR] =
    {
        .categoryName = _("GRAINE"),
        .height = 20,
        .weight = 1000,
        .description_FR = gVenusaurPokedexText_FR,
        .description_LG = gVenusaurPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 375,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_CHARMANDER] =
    {
        .categoryName = _("LEZARD"),
        .height = 6,
        .weight = 85,
        .description_FR = gCharmanderPokedexText_FR,
        .description_LG = gCharmanderPokedexText_LG,
        .pokemonScale = 410,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CHARMELEON] =
    {
        .categoryName = _("FLAMME"),
        .height = 11,
        .weight = 190,
        .description_FR = gCharmeleonPokedexText_FR,
        .description_LG = gCharmeleonPokedexText_LG,
        .pokemonScale = 294,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CHARIZARD] =
    {
        .categoryName = _("FLAMME"),
        .height = 17,
        .weight = 905,
        .description_FR = gCharizardPokedexText_FR,
        .description_LG = gCharizardPokedexText_LG,
        .pokemonScale = 271,
        .pokemonOffset = 0,
        .trainerScale = 317,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_SQUIRTLE] =
    {
        .categoryName = _("MINITORTUE"),
        .height = 5,
        .weight = 90,
        .description_FR = gSquirtlePokedexText_FR,
        .description_LG = gSquirtlePokedexText_LG,
        .pokemonScale = 412,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WARTORTLE] =
    {
        .categoryName = _("TORTUE"),
        .height = 10,
        .weight = 225,
        .description_FR = gWartortlePokedexText_FR,
        .description_LG = gWartortlePokedexText_LG,
        .pokemonScale = 334,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BLASTOISE] =
    {
        .categoryName = _("CARAPACE"),
        .height = 16,
        .weight = 855,
        .description_FR = gBlastoisePokedexText_FR,
        .description_LG = gBlastoisePokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 329,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_CATERPIE] =
    {
        .categoryName = _("VER"),
        .height = 3,
        .weight = 29,
        .description_FR = gCaterpiePokedexText_FR,
        .description_LG = gCaterpiePokedexText_LG,
        .pokemonScale = 549,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_METAPOD] =
    {
        .categoryName = _("COCON"),
        .height = 7,
        .weight = 99,
        .description_FR = gMetapodPokedexText_FR,
        .description_LG = gMetapodPokedexText_LG,
        .pokemonScale = 350,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BUTTERFREE] =
    {
        .categoryName = _("PAPILLON"),
        .height = 11,
        .weight = 320,
        .description_FR = gButterfreePokedexText_FR,
        .description_LG = gButterfreePokedexText_LG,
        .pokemonScale = 312,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WEEDLE] =
    {
        .categoryName = _("INSECTOPIC"),
        .height = 3,
        .weight = 32,
        .description_FR = gWeedlePokedexText_FR,
        .description_LG = gWeedlePokedexText_LG,
        .pokemonScale = 455,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_KAKUNA] =
    {
        .categoryName = _("COCON"),
        .height = 6,
        .weight = 100,
        .description_FR = gKakunaPokedexText_FR,
        .description_LG = gKakunaPokedexText_LG,
        .pokemonScale = 424,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BEEDRILL] =
    {
        .categoryName = _("GUEPOISON"),
        .height = 10,
        .weight = 295,
        .description_FR = gBeedrillPokedexText_FR,
        .description_LG = gBeedrillPokedexText_LG,
        .pokemonScale = 366,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PIDGEY] =
    {
        .categoryName = _("MINOISEAU"),
        .height = 3,
        .weight = 18,
        .description_FR = gPidgeyPokedexText_FR,
        .description_LG = gPidgeyPokedexText_LG,
        .pokemonScale = 492,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PIDGEOTTO] =
    {
        .categoryName = _("OISEAU"),
        .height = 11,
        .weight = 300,
        .description_FR = gPidgeottoPokedexText_FR,
        .description_LG = gPidgeottoPokedexText_LG,
        .pokemonScale = 334,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PIDGEOT] =
    {
        .categoryName = _("OISEAU"),
        .height = 15,
        .weight = 395,
        .description_FR = gPidgeotPokedexText_FR,
        .description_LG = gPidgeotPokedexText_LG,
        .pokemonScale = 269,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_RATTATA] =
    {
        .categoryName = _("SOURIS"),
        .height = 3,
        .weight = 35,
        .description_FR = gRattataPokedexText_FR,
        .description_LG = gRattataPokedexText_LG,
        .pokemonScale = 481,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_RATICATE] =
    {
        .categoryName = _("SOURIS"),
        .height = 7,
        .weight = 185,
        .description_FR = gRaticatePokedexText_FR,
        .description_LG = gRaticatePokedexText_LG,
        .pokemonScale = 401,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SPEAROW] =
    {
        .categoryName = _("MINOISEAU"),
        .height = 3,
        .weight = 20,
        .description_FR = gSpearowPokedexText_FR,
        .description_LG = gSpearowPokedexText_LG,
        .pokemonScale = 571,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_FEAROW] =
    {
        .categoryName = _("BEC-OISEAU"),
        .height = 12,
        .weight = 380,
        .description_FR = gFearowPokedexText_FR,
        .description_LG = gFearowPokedexText_LG,
        .pokemonScale = 282,
        .pokemonOffset = -1,
        .trainerScale = 272,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_EKANS] =
    {
        .categoryName = _("SERPENT"),
        .height = 20,
        .weight = 69,
        .description_FR = gEkansPokedexText_FR,
        .description_LG = gEkansPokedexText_LG,
        .pokemonScale = 298,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ARBOK] =
    {
        .categoryName = _("COBRA"),
        .height = 35,
        .weight = 650,
        .description_FR = gArbokPokedexText_FR,
        .description_LG = gArbokPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 296,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_PIKACHU] =
    {
        .categoryName = _("SOURIS"),
        .height = 4,
        .weight = 60,
        .description_FR = gPikachuPokedexText_FR,
        .description_LG = gPikachuPokedexText_LG,
        .pokemonScale = 479,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_RAICHU] =
    {
        .categoryName = _("SOURIS"),
        .height = 8,
        .weight = 300,
        .description_FR = gRaichuPokedexText_FR,
        .description_LG = gRaichuPokedexText_LG,
        .pokemonScale = 426,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SANDSHREW] =
    {
        .categoryName = _("SOURIS"),
        .height = 6,
        .weight = 120,
        .description_FR = gSandshrewPokedexText_FR,
        .description_LG = gSandshrewPokedexText_LG,
        .pokemonScale = 370,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SANDSLASH] =
    {
        .categoryName = _("SOURIS"),
        .height = 10,
        .weight = 295,
        .description_FR = gSandslashPokedexText_FR,
        .description_LG = gSandslashPokedexText_LG,
        .pokemonScale = 341,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NIDORAN_F] =
    {
        .categoryName = _("VENEPIC"),
        .height = 4,
        .weight = 70,
        .description_FR = gNidoranFPokedexText_FR,
        .description_LG = gNidoranFPokedexText_LG,
        .pokemonScale = 488,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NIDORINA] =
    {
        .categoryName = _("VENEPIC"),
        .height = 8,
        .weight = 200,
        .description_FR = gNidorinaPokedexText_FR,
        .description_LG = gNidorinaPokedexText_LG,
        .pokemonScale = 381,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NIDOQUEEN] =
    {
        .categoryName = _("PERCEUR"),
        .height = 13,
        .weight = 600,
        .description_FR = gNidoqueenPokedexText_FR,
        .description_LG = gNidoqueenPokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NIDORAN_M] =
    {
        .categoryName = _("VENEPIC"),
        .height = 5,
        .weight = 90,
        .description_FR = gNidoranMPokedexText_FR,
        .description_LG = gNidoranMPokedexText_LG,
        .pokemonScale = 480,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NIDORINO] =
    {
        .categoryName = _("VENEPIC"),
        .height = 9,
        .weight = 195,
        .description_FR = gNidorinoPokedexText_FR,
        .description_LG = gNidorinoPokedexText_LG,
        .pokemonScale = 408,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NIDOKING] =
    {
        .categoryName = _("PERCEUR"),
        .height = 14,
        .weight = 620,
        .description_FR = gNidokingPokedexText_FR,
        .description_LG = gNidokingPokedexText_LG,
        .pokemonScale = 304,
        .pokemonOffset = 3,
        .trainerScale = 323,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CLEFAIRY] =
    {
        .categoryName = _("FEE"),
        .height = 6,
        .weight = 75,
        .description_FR = gClefairyPokedexText_FR,
        .description_LG = gClefairyPokedexText_LG,
        .pokemonScale = 425,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CLEFABLE] =
    {
        .categoryName = _("FEE"),
        .height = 13,
        .weight = 400,
        .description_FR = gClefablePokedexText_FR,
        .description_LG = gClefablePokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 272,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_VULPIX] =
    {
        .categoryName = _("RENARD"),
        .height = 6,
        .weight = 99,
        .description_FR = gVulpixPokedexText_FR,
        .description_LG = gVulpixPokedexText_LG,
        .pokemonScale = 497,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NINETALES] =
    {
        .categoryName = _("RENARD"),
        .height = 11,
        .weight = 199,
        .description_FR = gNinetalesPokedexText_FR,
        .description_LG = gNinetalesPokedexText_LG,
        .pokemonScale = 339,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_JIGGLYPUFF] =
    {
        .categoryName = _("BOUBOULE"),
        .height = 5,
        .weight = 55,
        .description_FR = gJigglypuffPokedexText_FR,
        .description_LG = gJigglypuffPokedexText_LG,
        .pokemonScale = 419,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WIGGLYTUFF] =
    {
        .categoryName = _("BOUBOULE"),
        .height = 10,
        .weight = 120,
        .description_FR = gWigglytuffPokedexText_FR,
        .description_LG = gWigglytuffPokedexText_LG,
        .pokemonScale = 328,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ZUBAT] =
    {
        .categoryName = _("CHOVSOURIS"),
        .height = 8,
        .weight = 75,
        .description_FR = gZubatPokedexText_FR,
        .description_LG = gZubatPokedexText_LG,
        .pokemonScale = 355,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GOLBAT] =
    {
        .categoryName = _("CHOVSOURIS"),
        .height = 16,
        .weight = 550,
        .description_FR = gGolbatPokedexText_FR,
        .description_LG = gGolbatPokedexText_LG,
        .pokemonScale = 291,
        .pokemonOffset = 0,
        .trainerScale = 296,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_ODDISH] =
    {
        .categoryName = _("RACINE"),
        .height = 5,
        .weight = 54,
        .description_FR = gOddishPokedexText_FR,
        .description_LG = gOddishPokedexText_LG,
        .pokemonScale = 423,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GLOOM] =
    {
        .categoryName = _("RACINE"),
        .height = 8,
        .weight = 86,
        .description_FR = gGloomPokedexText_FR,
        .description_LG = gGloomPokedexText_LG,
        .pokemonScale = 329,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_VILEPLUME] =
    {
        .categoryName = _("FLEUR"),
        .height = 12,
        .weight = 186,
        .description_FR = gVileplumePokedexText_FR,
        .description_LG = gVileplumePokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 272,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PARAS] =
    {
        .categoryName = _("CHAMPIGNON"),
        .height = 3,
        .weight = 54,
        .description_FR = gParasPokedexText_FR,
        .description_LG = gParasPokedexText_LG,
        .pokemonScale = 546,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PARASECT] =
    {
        .categoryName = _("CHAMPIGNON"),
        .height = 10,
        .weight = 295,
        .description_FR = gParasectPokedexText_FR,
        .description_LG = gParasectPokedexText_LG,
        .pokemonScale = 307,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_VENONAT] =
    {
        .categoryName = _("VERMINE"),
        .height = 10,
        .weight = 300,
        .description_FR = gVenonatPokedexText_FR,
        .description_LG = gVenonatPokedexText_LG,
        .pokemonScale = 360,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_VENOMOTH] =
    {
        .categoryName = _("PAPIPOISON"),
        .height = 15,
        .weight = 125,
        .description_FR = gVenomothPokedexText_FR,
        .description_LG = gVenomothPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 293,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_DIGLETT] =
    {
        .categoryName = _("TAUPE"),
        .height = 2,
        .weight = 8,
        .description_FR = gDiglettPokedexText_FR,
        .description_LG = gDiglettPokedexText_LG,
        .pokemonScale = 706,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DUGTRIO] =
    {
        .categoryName = _("TAUPE"),
        .height = 7,
        .weight = 333,
        .description_FR = gDugtrioPokedexText_FR,
        .description_LG = gDugtrioPokedexText_LG,
        .pokemonScale = 384,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MEOWTH] =
    {
        .categoryName = _("CHADEGOUT"),
        .height = 4,
        .weight = 42,
        .description_FR = gMeowthPokedexText_FR,
        .description_LG = gMeowthPokedexText_LG,
        .pokemonScale = 480,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PERSIAN] =
    {
        .categoryName = _("CHADEVILLE"),
        .height = 10,
        .weight = 320,
        .description_FR = gPersianPokedexText_FR,
        .description_LG = gPersianPokedexText_LG,
        .pokemonScale = 320,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PSYDUCK] =
    {
        .categoryName = _("CANARD"),
        .height = 8,
        .weight = 196,
        .description_FR = gPsyduckPokedexText_FR,
        .description_LG = gPsyduckPokedexText_LG,
        .pokemonScale = 347,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GOLDUCK] =
    {
        .categoryName = _("CANARD"),
        .height = 17,
        .weight = 766,
        .description_FR = gGolduckPokedexText_FR,
        .description_LG = gGolduckPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = 4,
        .trainerScale = 287,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_MANKEY] =
    {
        .categoryName = _("PORSINGE"),
        .height = 5,
        .weight = 280,
        .description_FR = gMankeyPokedexText_FR,
        .description_LG = gMankeyPokedexText_LG,
        .pokemonScale = 388,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PRIMEAPE] =
    {
        .categoryName = _("PORSINGE"),
        .height = 10,
        .weight = 320,
        .description_FR = gPrimeapePokedexText_FR,
        .description_LG = gPrimeapePokedexText_LG,
        .pokemonScale = 326,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GROWLITHE] =
    {
        .categoryName = _("CHIOT"),
        .height = 7,
        .weight = 190,
        .description_FR = gGrowlithePokedexText_FR,
        .description_LG = gGrowlithePokedexText_LG,
        .pokemonScale = 346,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ARCANINE] =
    {
        .categoryName = _("LEGENDAIRE"),
        .height = 19,
        .weight = 1550,
        .description_FR = gArcaninePokedexText_FR,
        .description_LG = gArcaninePokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 312,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_POLIWAG] =
    {
        .categoryName = _("TETARD"),
        .height = 6,
        .weight = 124,
        .description_FR = gPoliwagPokedexText_FR,
        .description_LG = gPoliwagPokedexText_LG,
        .pokemonScale = 353,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_POLIWHIRL] =
    {
        .categoryName = _("TETARD"),
        .height = 10,
        .weight = 200,
        .description_FR = gPoliwhirlPokedexText_FR,
        .description_LG = gPoliwhirlPokedexText_LG,
        .pokemonScale = 288,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_POLIWRATH] =
    {
        .categoryName = _("TETARD"),
        .height = 13,
        .weight = 540,
        .description_FR = gPoliwrathPokedexText_FR,
        .description_LG = gPoliwrathPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ABRA] =
    {
        .categoryName = _("PSY"),
        .height = 9,
        .weight = 195,
        .description_FR = gAbraPokedexText_FR,
        .description_LG = gAbraPokedexText_LG,
        .pokemonScale = 374,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_KADABRA] =
    {
        .categoryName = _("PSY"),
        .height = 13,
        .weight = 565,
        .description_FR = gKadabraPokedexText_FR,
        .description_LG = gKadabraPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ALAKAZAM] =
    {
        .categoryName = _("PSY"),
        .height = 15,
        .weight = 480,
        .description_FR = gAlakazamPokedexText_FR,
        .description_LG = gAlakazamPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = -1,
        .trainerScale = 271,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_MACHOP] =
    {
        .categoryName = _("COLOSSE"),
        .height = 8,
        .weight = 195,
        .description_FR = gMachopPokedexText_FR,
        .description_LG = gMachopPokedexText_LG,
        .pokemonScale = 320,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MACHOKE] =
    {
        .categoryName = _("COLOSSE"),
        .height = 15,
        .weight = 705,
        .description_FR = gMachokePokedexText_FR,
        .description_LG = gMachokePokedexText_LG,
        .pokemonScale = 304,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MACHAMP] =
    {
        .categoryName = _("COLOSSE"),
        .height = 16,
        .weight = 1300,
        .description_FR = gMachampPokedexText_FR,
        .description_LG = gMachampPokedexText_LG,
        .pokemonScale = 278,
        .pokemonOffset = 2,
        .trainerScale = 283,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BELLSPROUT] =
    {
        .categoryName = _("FLEUR"),
        .height = 7,
        .weight = 40,
        .description_FR = gBellsproutPokedexText_FR,
        .description_LG = gBellsproutPokedexText_LG,
        .pokemonScale = 354,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WEEPINBELL] =
    {
        .categoryName = _("CARNIVORE"),
        .height = 10,
        .weight = 64,
        .description_FR = gWeepinbellPokedexText_FR,
        .description_LG = gWeepinbellPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_VICTREEBEL] =
    {
        .categoryName = _("CARNIVORE"),
        .height = 17,
        .weight = 155,
        .description_FR = gVictreebelPokedexText_FR,
        .description_LG = gVictreebelPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 302,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_TENTACOOL] =
    {
        .categoryName = _("MOLLUSQUE"),
        .height = 9,
        .weight = 455,
        .description_FR = gTentacoolPokedexText_FR,
        .description_LG = gTentacoolPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TENTACRUEL] =
    {
        .categoryName = _("MOLLUSQUE"),
        .height = 16,
        .weight = 550,
        .description_FR = gTentacruelPokedexText_FR,
        .description_LG = gTentacruelPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = -1,
        .trainerScale = 312,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GEODUDE] =
    {
        .categoryName = _("ROCHE"),
        .height = 4,
        .weight = 200,
        .description_FR = gGeodudePokedexText_FR,
        .description_LG = gGeodudePokedexText_LG,
        .pokemonScale = 330,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GRAVELER] =
    {
        .categoryName = _("ROCHE"),
        .height = 10,
        .weight = 1050,
        .description_FR = gGravelerPokedexText_FR,
        .description_LG = gGravelerPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = 8,
        .trainerScale = 305,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_GOLEM] =
    {
        .categoryName = _("TITANESQUE"),
        .height = 14,
        .weight = 3000,
        .description_FR = gGolemPokedexText_FR,
        .description_LG = gGolemPokedexText_LG,
        .pokemonScale = 266,
        .pokemonOffset = 3,
        .trainerScale = 298,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_PONYTA] =
    {
        .categoryName = _("CHEVAL FEU"),
        .height = 10,
        .weight = 300,
        .description_FR = gPonytaPokedexText_FR,
        .description_LG = gPonytaPokedexText_LG,
        .pokemonScale = 288,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_RAPIDASH] =
    {
        .categoryName = _("CHEVAL FEU"),
        .height = 17,
        .weight = 950,
        .description_FR = gRapidashPokedexText_FR,
        .description_LG = gRapidashPokedexText_LG,
        .pokemonScale = 282,
        .pokemonOffset = -1,
        .trainerScale = 312,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_SLOWPOKE] =
    {
        .categoryName = _("CRETIN"),
        .height = 12,
        .weight = 360,
        .description_FR = gSlowpokePokedexText_FR,
        .description_LG = gSlowpokePokedexText_LG,
        .pokemonScale = 271,
        .pokemonOffset = 10,
        .trainerScale = 272,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SLOWBRO] =
    {
        .categoryName = _("SYMBIOSE"),
        .height = 16,
        .weight = 785,
        .description_FR = gSlowbroPokedexText_FR,
        .description_LG = gSlowbroPokedexText_LG,
        .pokemonScale = 257,
        .pokemonOffset = -2,
        .trainerScale = 312,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAGNEMITE] =
    {
        .categoryName = _("MAGNETIQUE"),
        .height = 3,
        .weight = 60,
        .description_FR = gMagnemitePokedexText_FR,
        .description_LG = gMagnemitePokedexText_LG,
        .pokemonScale = 294,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MAGNETON] =
    {
        .categoryName = _("MAGNETIQUE"),
        .height = 10,
        .weight = 600,
        .description_FR = gMagnetonPokedexText_FR,
        .description_LG = gMagnetonPokedexText_LG,
        .pokemonScale = 293,
        .pokemonOffset = -4,
        .trainerScale = 273,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_FARFETCHD] =
    {
        .categoryName = _("CANARD FOU"),
        .height = 8,
        .weight = 150,
        .description_FR = gFarfetchdPokedexText_FR,
        .description_LG = gFarfetchdPokedexText_LG,
        .pokemonScale = 317,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = -3,
    },

    [NATIONAL_DEX_DODUO] =
    {
        .categoryName = _("DUOISEAU"),
        .height = 14,
        .weight = 392,
        .description_FR = gDoduoPokedexText_FR,
        .description_LG = gDoduoPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 287,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DODRIO] =
    {
        .categoryName = _("TRIOISEAU"),
        .height = 18,
        .weight = 852,
        .description_FR = gDodrioPokedexText_FR,
        .description_LG = gDodrioPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = -2,
        .trainerScale = 296,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_SEEL] =
    {
        .categoryName = _("OTARIE"),
        .height = 11,
        .weight = 900,
        .description_FR = gSeelPokedexText_FR,
        .description_LG = gSeelPokedexText_LG,
        .pokemonScale = 298,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DEWGONG] =
    {
        .categoryName = _("OTARIE"),
        .height = 17,
        .weight = 1200,
        .description_FR = gDewgongPokedexText_FR,
        .description_LG = gDewgongPokedexText_LG,
        .pokemonScale = 288,
        .pokemonOffset = 1,
        .trainerScale = 306,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_GRIMER] =
    {
        .categoryName = _("DEGUEU"),
        .height = 9,
        .weight = 300,
        .description_FR = gGrimerPokedexText_FR,
        .description_LG = gGrimerPokedexText_LG,
        .pokemonScale = 258,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MUK] =
    {
        .categoryName = _("DEGUEU"),
        .height = 12,
        .weight = 300,
        .description_FR = gMukPokedexText_FR,
        .description_LG = gMukPokedexText_LG,
        .pokemonScale = 288,
        .pokemonOffset = 7,
        .trainerScale = 288,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_SHELLDER] =
    {
        .categoryName = _("BIVALVE"),
        .height = 3,
        .weight = 40,
        .description_FR = gShellderPokedexText_FR,
        .description_LG = gShellderPokedexText_LG,
        .pokemonScale = 643,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CLOYSTER] =
    {
        .categoryName = _("BIVALVE"),
        .height = 15,
        .weight = 1325,
        .description_FR = gCloysterPokedexText_FR,
        .description_LG = gCloysterPokedexText_LG,
        .pokemonScale = 264,
        .pokemonOffset = 0,
        .trainerScale = 288,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_GASTLY] =
    {
        .categoryName = _("GAZ"),
        .height = 13,
        .weight = 1,
        .description_FR = gGastlyPokedexText_FR,
        .description_LG = gGastlyPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HAUNTER] =
    {
        .categoryName = _("GAZ"),
        .height = 16,
        .weight = 1,
        .description_FR = gHaunterPokedexText_FR,
        .description_LG = gHaunterPokedexText_LG,
        .pokemonScale = 269,
        .pokemonOffset = 2,
        .trainerScale = 308,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_GENGAR] =
    {
        .categoryName = _("OMBRE"),
        .height = 15,
        .weight = 405,
        .description_FR = gGengarPokedexText_FR,
        .description_LG = gGengarPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 317,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_ONIX] =
    {
        .categoryName = _("SERPENROC"),
        .height = 88,
        .weight = 2100,
        .description_FR = gOnixPokedexText_FR,
        .description_LG = gOnixPokedexText_LG,
        .pokemonScale = 257,
        .pokemonOffset = 0,
        .trainerScale = 515,
        .trainerOffset = 12,
    },

    [NATIONAL_DEX_DROWZEE] =
    {
        .categoryName = _("HYPNOSE"),
        .height = 10,
        .weight = 324,
        .description_FR = gDrowzeePokedexText_FR,
        .description_LG = gDrowzeePokedexText_LG,
        .pokemonScale = 274,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HYPNO] =
    {
        .categoryName = _("HYPNOSE"),
        .height = 16,
        .weight = 756,
        .description_FR = gHypnoPokedexText_FR,
        .description_LG = gHypnoPokedexText_LG,
        .pokemonScale = 298,
        .pokemonOffset = 3,
        .trainerScale = 310,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_KRABBY] =
    {
        .categoryName = _("DOUX CRABE"),
        .height = 4,
        .weight = 65,
        .description_FR = gKrabbyPokedexText_FR,
        .description_LG = gKrabbyPokedexText_LG,
        .pokemonScale = 469,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_KINGLER] =
    {
        .categoryName = _("PINCE"),
        .height = 13,
        .weight = 600,
        .description_FR = gKinglerPokedexText_FR,
        .description_LG = gKinglerPokedexText_LG,
        .pokemonScale = 287,
        .pokemonOffset = 3,
        .trainerScale = 308,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_VOLTORB] =
    {
        .categoryName = _("BALLE"),
        .height = 5,
        .weight = 104,
        .description_FR = gVoltorbPokedexText_FR,
        .description_LG = gVoltorbPokedexText_LG,
        .pokemonScale = 364,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ELECTRODE] =
    {
        .categoryName = _("BALLE"),
        .height = 12,
        .weight = 666,
        .description_FR = gElectrodePokedexText_FR,
        .description_LG = gElectrodePokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_EXEGGCUTE] =
    {
        .categoryName = _("OEUF"),
        .height = 4,
        .weight = 25,
        .description_FR = gExeggcutePokedexText_FR,
        .description_LG = gExeggcutePokedexText_LG,
        .pokemonScale = 495,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_EXEGGUTOR] =
    {
        .categoryName = _("FRUITPALME"),
        .height = 20,
        .weight = 1200,
        .description_FR = gExeggutorPokedexText_FR,
        .description_LG = gExeggutorPokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = 0,
        .trainerScale = 376,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_CUBONE] =
    {
        .categoryName = _("SOLITAIRE"),
        .height = 4,
        .weight = 65,
        .description_FR = gCubonePokedexText_FR,
        .description_LG = gCubonePokedexText_LG,
        .pokemonScale = 545,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MAROWAK] =
    {
        .categoryName = _("GARD'OS"),
        .height = 10,
        .weight = 450,
        .description_FR = gMarowakPokedexText_FR,
        .description_LG = gMarowakPokedexText_LG,
        .pokemonScale = 293,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HITMONLEE] =
    {
        .categoryName = _("LATTEUR"),
        .height = 15,
        .weight = 498,
        .description_FR = gHitmonleePokedexText_FR,
        .description_LG = gHitmonleePokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 273,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HITMONCHAN] =
    {
        .categoryName = _("PUNCHEUR"),
        .height = 14,
        .weight = 502,
        .description_FR = gHitmonchanPokedexText_FR,
        .description_LG = gHitmonchanPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 264,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LICKITUNG] =
    {
        .categoryName = _("LECHEUR"),
        .height = 12,
        .weight = 655,
        .description_FR = gLickitungPokedexText_FR,
        .description_LG = gLickitungPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 272,
        .trainerOffset = -3,
    },

    [NATIONAL_DEX_KOFFING] =
    {
        .categoryName = _("GAZ MORTEL"),
        .height = 6,
        .weight = 10,
        .description_FR = gKoffingPokedexText_FR,
        .description_LG = gKoffingPokedexText_LG,
        .pokemonScale = 369,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WEEZING] =
    {
        .categoryName = _("GAZ MORTEL"),
        .height = 12,
        .weight = 95,
        .description_FR = gWeezingPokedexText_FR,
        .description_LG = gWeezingPokedexText_LG,
        .pokemonScale = 321,
        .pokemonOffset = -1,
        .trainerScale = 276,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_RHYHORN] =
    {
        .categoryName = _("PIQUANT"),
        .height = 10,
        .weight = 1150,
        .description_FR = gRhyhornPokedexText_FR,
        .description_LG = gRhyhornPokedexText_LG,
        .pokemonScale = 291,
        .pokemonOffset = 7,
        .trainerScale = 276,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_RHYDON] =
    {
        .categoryName = _("PERCEUR"),
        .height = 19,
        .weight = 1200,
        .description_FR = gRhydonPokedexText_FR,
        .description_LG = gRhydonPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = -1,
        .trainerScale = 344,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_CHANSEY] =
    {
        .categoryName = _("OEUF"),
        .height = 11,
        .weight = 346,
        .description_FR = gChanseyPokedexText_FR,
        .description_LG = gChanseyPokedexText_LG,
        .pokemonScale = 257,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TANGELA] =
    {
        .categoryName = _("VIGNE"),
        .height = 10,
        .weight = 350,
        .description_FR = gTangelaPokedexText_FR,
        .description_LG = gTangelaPokedexText_LG,
        .pokemonScale = 320,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_KANGASKHAN] =
    {
        .categoryName = _("MATERNEL"),
        .height = 22,
        .weight = 800,
        .description_FR = gKangaskhanPokedexText_FR,
        .description_LG = gKangaskhanPokedexText_LG,
        .pokemonScale = 257,
        .pokemonOffset = -3,
        .trainerScale = 349,
        .trainerOffset = 5,
    },

    [NATIONAL_DEX_HORSEA] =
    {
        .categoryName = _("DRAGON"),
        .height = 4,
        .weight = 80,
        .description_FR = gHorseaPokedexText_FR,
        .description_LG = gHorseaPokedexText_LG,
        .pokemonScale = 399,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SEADRA] =
    {
        .categoryName = _("DRAGON"),
        .height = 12,
        .weight = 250,
        .description_FR = gSeadraPokedexText_FR,
        .description_LG = gSeadraPokedexText_LG,
        .pokemonScale = 296,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GOLDEEN] =
    {
        .categoryName = _("POISSON"),
        .height = 6,
        .weight = 150,
        .description_FR = gGoldeenPokedexText_FR,
        .description_LG = gGoldeenPokedexText_LG,
        .pokemonScale = 379,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SEAKING] =
    {
        .categoryName = _("POISSON"),
        .height = 13,
        .weight = 390,
        .description_FR = gSeakingPokedexText_FR,
        .description_LG = gSeakingPokedexText_LG,
        .pokemonScale = 304,
        .pokemonOffset = 1,
        .trainerScale = 288,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_STARYU] =
    {
        .categoryName = _("ETOILE"),
        .height = 8,
        .weight = 345,
        .description_FR = gStaryuPokedexText_FR,
        .description_LG = gStaryuPokedexText_LG,
        .pokemonScale = 326,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_STARMIE] =
    {
        .categoryName = _("MYSTERIEUX"),
        .height = 11,
        .weight = 800,
        .description_FR = gStarmiePokedexText_FR,
        .description_LG = gStarmiePokedexText_LG,
        .pokemonScale = 301,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MR_MIME] =
    {
        .categoryName = _("BLOQUEUR"),
        .height = 13,
        .weight = 545,
        .description_FR = gMrmimePokedexText_FR,
        .description_LG = gMrmimePokedexText_LG,
        .pokemonScale = 258,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SCYTHER] =
    {
        .categoryName = _("MANTE"),
        .height = 15,
        .weight = 560,
        .description_FR = gScytherPokedexText_FR,
        .description_LG = gScytherPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = 0,
        .trainerScale = 293,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_JYNX] =
    {
        .categoryName = _("HUMANOIDE"),
        .height = 14,
        .weight = 406,
        .description_FR = gJynxPokedexText_FR,
        .description_LG = gJynxPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 300,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_ELECTABUZZ] =
    {
        .categoryName = _("ELECTRIQUE"),
        .height = 11,
        .weight = 300,
        .description_FR = gElectabuzzPokedexText_FR,
        .description_LG = gElectabuzzPokedexText_LG,
        .pokemonScale = 330,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MAGMAR] =
    {
        .categoryName = _("CRACHE-FEU"),
        .height = 13,
        .weight = 445,
        .description_FR = gMagmarPokedexText_FR,
        .description_LG = gMagmarPokedexText_LG,
        .pokemonScale = 293,
        .pokemonOffset = 4,
        .trainerScale = 272,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PINSIR] =
    {
        .categoryName = _("SCARABEE"),
        .height = 15,
        .weight = 550,
        .description_FR = gPinsirPokedexText_FR,
        .description_LG = gPinsirPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 257,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TAUROS] =
    {
        .categoryName = _("BUFFLE"),
        .height = 14,
        .weight = 884,
        .description_FR = gTaurosPokedexText_FR,
        .description_LG = gTaurosPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 312,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_MAGIKARP] =
    {
        .categoryName = _("POISSON"),
        .height = 9,
        .weight = 100,
        .description_FR = gMagikarpPokedexText_FR,
        .description_LG = gMagikarpPokedexText_LG,
        .pokemonScale = 317,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GYARADOS] =
    {
        .categoryName = _("TERRIFIANT"),
        .height = 65,
        .weight = 2350,
        .description_FR = gGyaradosPokedexText_FR,
        .description_LG = gGyaradosPokedexText_LG,
        .pokemonScale = 288,
        .pokemonOffset = -1,
        .trainerScale = 512,
        .trainerOffset = 11,
    },

    [NATIONAL_DEX_LAPRAS] =
    {
        .categoryName = _("TRANSPORT"),
        .height = 25,
        .weight = 2200,
        .description_FR = gLaprasPokedexText_FR,
        .description_LG = gLaprasPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 425,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_DITTO] =
    {
        .categoryName = _("MORPHING"),
        .height = 3,
        .weight = 40,
        .description_FR = gDittoPokedexText_FR,
        .description_LG = gDittoPokedexText_LG,
        .pokemonScale = 602,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_EEVEE] =
    {
        .categoryName = _("EVOLUTIF"),
        .height = 3,
        .weight = 65,
        .description_FR = gEeveePokedexText_FR,
        .description_LG = gEeveePokedexText_LG,
        .pokemonScale = 476,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_VAPOREON] =
    {
        .categoryName = _("BULLEUR"),
        .height = 10,
        .weight = 290,
        .description_FR = gVaporeonPokedexText_FR,
        .description_LG = gVaporeonPokedexText_LG,
        .pokemonScale = 316,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_JOLTEON] =
    {
        .categoryName = _("ORAGE"),
        .height = 8,
        .weight = 245,
        .description_FR = gJolteonPokedexText_FR,
        .description_LG = gJolteonPokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_FLAREON] =
    {
        .categoryName = _("FLAMME"),
        .height = 9,
        .weight = 250,
        .description_FR = gFlareonPokedexText_FR,
        .description_LG = gFlareonPokedexText_LG,
        .pokemonScale = 302,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PORYGON] =
    {
        .categoryName = _("VIRTUEL"),
        .height = 8,
        .weight = 365,
        .description_FR = gPorygonPokedexText_FR,
        .description_LG = gPorygonPokedexText_LG,
        .pokemonScale = 328,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_OMANYTE] =
    {
        .categoryName = _("SPIRALE"),
        .height = 4,
        .weight = 75,
        .description_FR = gOmanytePokedexText_FR,
        .description_LG = gOmanytePokedexText_LG,
        .pokemonScale = 521,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_OMASTAR] =
    {
        .categoryName = _("SPIRALE"),
        .height = 10,
        .weight = 350,
        .description_FR = gOmastarPokedexText_FR,
        .description_LG = gOmastarPokedexText_LG,
        .pokemonScale = 307,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_KABUTO] =
    {
        .categoryName = _("CARAPACE"),
        .height = 5,
        .weight = 115,
        .description_FR = gKabutoPokedexText_FR,
        .description_LG = gKabutoPokedexText_LG,
        .pokemonScale = 438,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_KABUTOPS] =
    {
        .categoryName = _("CARAPACE"),
        .height = 13,
        .weight = 405,
        .description_FR = gKabutopsPokedexText_FR,
        .description_LG = gKabutopsPokedexText_LG,
        .pokemonScale = 271,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_AERODACTYL] =
    {
        .categoryName = _("FOSSILE"),
        .height = 18,
        .weight = 590,
        .description_FR = gAerodactylPokedexText_FR,
        .description_LG = gAerodactylPokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = -1,
        .trainerScale = 317,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_SNORLAX] =
    {
        .categoryName = _("PIONCEUR"),
        .height = 21,
        .weight = 4600,
        .description_FR = gSnorlaxPokedexText_FR,
        .description_LG = gSnorlaxPokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = 1,
        .trainerScale = 408,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_ARTICUNO] =
    {
        .categoryName = _("GLACIAIRE"),
        .height = 17,
        .weight = 554,
        .description_FR = gArticunoPokedexText_FR,
        .description_LG = gArticunoPokedexText_LG,
        .pokemonScale = 278,
        .pokemonOffset = 0,
        .trainerScale = 308,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_ZAPDOS] =
    {
        .categoryName = _("ELECTRIQUE"),
        .height = 16,
        .weight = 526,
        .description_FR = gZapdosPokedexText_FR,
        .description_LG = gZapdosPokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = 1,
        .trainerScale = 330,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_MOLTRES] =
    {
        .categoryName = _("FLAMME"),
        .height = 20,
        .weight = 600,
        .description_FR = gMoltresPokedexText_FR,
        .description_LG = gMoltresPokedexText_LG,
        .pokemonScale = 270,
        .pokemonOffset = 1,
        .trainerScale = 379,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_DRATINI] =
    {
        .categoryName = _("DRAGON"),
        .height = 18,
        .weight = 33,
        .description_FR = gDratiniPokedexText_FR,
        .description_LG = gDratiniPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 8,
        .trainerScale = 386,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_DRAGONAIR] =
    {
        .categoryName = _("DRAGON"),
        .height = 40,
        .weight = 165,
        .description_FR = gDragonairPokedexText_FR,
        .description_LG = gDragonairPokedexText_LG,
        .pokemonScale = 274,
        .pokemonOffset = 0,
        .trainerScale = 423,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_DRAGONITE] =
    {
        .categoryName = _("DRAGON"),
        .height = 22,
        .weight = 2100,
        .description_FR = gDragonitePokedexText_FR,
        .description_LG = gDragonitePokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = -1,
        .trainerScale = 342,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_MEWTWO] =
    {
        .categoryName = _("GENETIQUE"),
        .height = 20,
        .weight = 1220,
        .description_FR = gMewtwoPokedexText_FR,
        .description_LG = gMewtwoPokedexText_LG,
        .pokemonScale = 276,
        .pokemonOffset = -1,
        .trainerScale = 342,
        .trainerOffset = 5,
    },

    [NATIONAL_DEX_MEW] =
    {
        .categoryName = _("NOUVEAU"),
        .height = 4,
        .weight = 40,
        .description_FR = gMewPokedexText_FR,
        .description_LG = gMewPokedexText_LG,
        .pokemonScale = 460,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CHIKORITA] =
    {
        .categoryName = _("FEUILLE"),
        .height = 9,
        .weight = 64,
        .description_FR = gChikoritaPokedexText_FR,
        .description_LG = gChikoritaPokedexText_LG,
        .pokemonScale = 512,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BAYLEEF] =
    {
        .categoryName = _("FEUILLE"),
        .height = 12,
        .weight = 158,
        .description_FR = gBayleefPokedexText_FR,
        .description_LG = gBayleefPokedexText_LG,
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MEGANIUM] =
    {
        .categoryName = _("HERBE"),
        .height = 18,
        .weight = 1005,
        .description_FR = gMeganiumPokedexText_FR,
        .description_LG = gMeganiumPokedexText_LG,
        .pokemonScale = 286,
        .pokemonOffset = 0,
        .trainerScale = 317,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CYNDAQUIL] =
    {
        .categoryName = _("SOURIS FEU"),
        .height = 5,
        .weight = 79,
        .description_FR = gCyndaquilPokedexText_FR,
        .description_LG = gCyndaquilPokedexText_LG,
        .pokemonScale = 539,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_QUILAVA] =
    {
        .categoryName = _("VOLCAN"),
        .height = 9,
        .weight = 190,
        .description_FR = gQuilavaPokedexText_FR,
        .description_LG = gQuilavaPokedexText_LG,
        .pokemonScale = 329,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TYPHLOSION] =
    {
        .categoryName = _("VOLCAN"),
        .height = 17,
        .weight = 795,
        .description_FR = gTyphlosionPokedexText_FR,
        .description_LG = gTyphlosionPokedexText_LG,
        .pokemonScale = 284,
        .pokemonOffset = -1,
        .trainerScale = 287,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TOTODILE] =
    {
        .categoryName = _("MACHOIRE"),
        .height = 6,
        .weight = 95,
        .description_FR = gTotodilePokedexText_FR,
        .description_LG = gTotodilePokedexText_LG,
        .pokemonScale = 487,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CROCONAW] =
    {
        .categoryName = _("MACHOIRE"),
        .height = 11,
        .weight = 250,
        .description_FR = gCroconawPokedexText_FR,
        .description_LG = gCroconawPokedexText_LG,
        .pokemonScale = 378,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_FERALIGATR] =
    {
        .categoryName = _("MACHOIRE"),
        .height = 23,
        .weight = 888,
        .description_FR = gFeraligatrPokedexText_FR,
        .description_LG = gFeraligatrPokedexText_LG,
        .pokemonScale = 282,
        .pokemonOffset = -1,
        .trainerScale = 375,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_SENTRET] =
    {
        .categoryName = _("ESPION"),
        .height = 8,
        .weight = 60,
        .description_FR = gSentretPokedexText_FR,
        .description_LG = gSentretPokedexText_LG,
        .pokemonScale = 439,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_FURRET] =
    {
        .categoryName = _("ALLONGE"),
        .height = 18,
        .weight = 325,
        .description_FR = gFurretPokedexText_FR,
        .description_LG = gFurretPokedexText_LG,
        .pokemonScale = 346,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HOOTHOOT] =
    {
        .categoryName = _("HIBOU"),
        .height = 7,
        .weight = 212,
        .description_FR = gHoothootPokedexText_FR,
        .description_LG = gHoothootPokedexText_LG,
        .pokemonScale = 380,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NOCTOWL] =
    {
        .categoryName = _("HIBOU"),
        .height = 16,
        .weight = 408,
        .description_FR = gNoctowlPokedexText_FR,
        .description_LG = gNoctowlPokedexText_LG,
        .pokemonScale = 278,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LEDYBA] =
    {
        .categoryName = _("5 ETOILES"),
        .height = 10,
        .weight = 108,
        .description_FR = gLedybaPokedexText_FR,
        .description_LG = gLedybaPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LEDIAN] =
    {
        .categoryName = _("5 ETOILES"),
        .height = 14,
        .weight = 356,
        .description_FR = gLedianPokedexText_FR,
        .description_LG = gLedianPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SPINARAK] =
    {
        .categoryName = _("CRACHE FIL"),
        .height = 5,
        .weight = 85,
        .description_FR = gSpinarakPokedexText_FR,
        .description_LG = gSpinarakPokedexText_LG,
        .pokemonScale = 414,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ARIADOS] =
    {
        .categoryName = _("LONG-PATTE"),
        .height = 11,
        .weight = 335,
        .description_FR = gAriadosPokedexText_FR,
        .description_LG = gAriadosPokedexText_LG,
        .pokemonScale = 316,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CROBAT] =
    {
        .categoryName = _("CHOVSOURIS"),
        .height = 18,
        .weight = 750,
        .description_FR = gCrobatPokedexText_FR,
        .description_LG = gCrobatPokedexText_LG,
        .pokemonScale = 279,
        .pokemonOffset = -1,
        .trainerScale = 313,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CHINCHOU] =
    {
        .categoryName = _("POISSON"),
        .height = 5,
        .weight = 120,
        .description_FR = gChinchouPokedexText_FR,
        .description_LG = gChinchouPokedexText_LG,
        .pokemonScale = 424,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LANTURN] =
    {
        .categoryName = _("LUMIERE"),
        .height = 12,
        .weight = 225,
        .description_FR = gLanturnPokedexText_FR,
        .description_LG = gLanturnPokedexText_LG,
        .pokemonScale = 269,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PICHU] =
    {
        .categoryName = _("MINISOURIS"),
        .height = 3,
        .weight = 20,
        .description_FR = gPichuPokedexText_FR,
        .description_LG = gPichuPokedexText_LG,
        .pokemonScale = 508,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CLEFFA] =
    {
        .categoryName = _("ETOILE"),
        .height = 3,
        .weight = 30,
        .description_FR = gCleffaPokedexText_FR,
        .description_LG = gCleffaPokedexText_LG,
        .pokemonScale = 462,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_IGGLYBUFF] =
    {
        .categoryName = _("BOUBOULE"),
        .height = 3,
        .weight = 10,
        .description_FR = gIgglybuffPokedexText_FR,
        .description_LG = gIgglybuffPokedexText_LG,
        .pokemonScale = 457,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TOGEPI] =
    {
        .categoryName = _("BALLE PIC"),
        .height = 3,
        .weight = 15,
        .description_FR = gTogepiPokedexText_FR,
        .description_LG = gTogepiPokedexText_LG,
        .pokemonScale = 507,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TOGETIC] =
    {
        .categoryName = _("BONHEUR"),
        .height = 6,
        .weight = 32,
        .description_FR = gTogeticPokedexText_FR,
        .description_LG = gTogeticPokedexText_LG,
        .pokemonScale = 424,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NATU] =
    {
        .categoryName = _("MINOISEAU"),
        .height = 2,
        .weight = 20,
        .description_FR = gNatuPokedexText_FR,
        .description_LG = gNatuPokedexText_LG,
        .pokemonScale = 610,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_XATU] =
    {
        .categoryName = _("MYSTIQUE"),
        .height = 15,
        .weight = 150,
        .description_FR = gXatuPokedexText_FR,
        .description_LG = gXatuPokedexText_LG,
        .pokemonScale = 258,
        .pokemonOffset = 4,
        .trainerScale = 317,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_MAREEP] =
    {
        .categoryName = _("LAINE"),
        .height = 6,
        .weight = 78,
        .description_FR = gMareepPokedexText_FR,
        .description_LG = gMareepPokedexText_LG,
        .pokemonScale = 379,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_FLAAFFY] =
    {
        .categoryName = _("LAINE"),
        .height = 8,
        .weight = 133,
        .description_FR = gFlaaffyPokedexText_FR,
        .description_LG = gFlaaffyPokedexText_LG,
        .pokemonScale = 372,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_AMPHAROS] =
    {
        .categoryName = _("LUMIERE"),
        .height = 14,
        .weight = 615,
        .description_FR = gAmpharosPokedexText_FR,
        .description_LG = gAmpharosPokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = 2,
        .trainerScale = 283,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_BELLOSSOM] =
    {
        .categoryName = _("FLEUR"),
        .height = 4,
        .weight = 58,
        .description_FR = gBellossomPokedexText_FR,
        .description_LG = gBellossomPokedexText_LG,
        .pokemonScale = 472,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MARILL] =
    {
        .categoryName = _("AQUASOURIS"),
        .height = 4,
        .weight = 85,
        .description_FR = gMarillPokedexText_FR,
        .description_LG = gMarillPokedexText_LG,
        .pokemonScale = 476,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_AZUMARILL] =
    {
        .categoryName = _("AQUALAPIN"),
        .height = 8,
        .weight = 285,
        .description_FR = gAzumarillPokedexText_FR,
        .description_LG = gAzumarillPokedexText_LG,
        .pokemonScale = 448,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SUDOWOODO] =
    {
        .categoryName = _("IMITATION"),
        .height = 12,
        .weight = 380,
        .description_FR = gSudowoodoPokedexText_FR,
        .description_LG = gSudowoodoPokedexText_LG,
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_POLITOED] =
    {
        .categoryName = _("GRENOUILLE"),
        .height = 11,
        .weight = 339,
        .description_FR = gPolitoedPokedexText_FR,
        .description_LG = gPolitoedPokedexText_LG,
        .pokemonScale = 289,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HOPPIP] =
    {
        .categoryName = _("PISSENLIT"),
        .height = 4,
        .weight = 5,
        .description_FR = gHoppipPokedexText_FR,
        .description_LG = gHoppipPokedexText_LG,
        .pokemonScale = 562,
        .pokemonOffset = -7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SKIPLOOM] =
    {
        .categoryName = _("PISSENLIT"),
        .height = 6,
        .weight = 10,
        .description_FR = gSkiploomPokedexText_FR,
        .description_LG = gSkiploomPokedexText_LG,
        .pokemonScale = 387,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_JUMPLUFF] =
    {
        .categoryName = _("PISSENLIT"),
        .height = 8,
        .weight = 30,
        .description_FR = gJumpluffPokedexText_FR,
        .description_LG = gJumpluffPokedexText_LG,
        .pokemonScale = 418,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_AIPOM] =
    {
        .categoryName = _("LONGQUEUE"),
        .height = 8,
        .weight = 115,
        .description_FR = gAipomPokedexText_FR,
        .description_LG = gAipomPokedexText_LG,
        .pokemonScale = 363,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SUNKERN] =
    {
        .categoryName = _("GRAINE"),
        .height = 3,
        .weight = 18,
        .description_FR = gSunkernPokedexText_FR,
        .description_LG = gSunkernPokedexText_LG,
        .pokemonScale = 541,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SUNFLORA] =
    {
        .categoryName = _("SOLEIL"),
        .height = 8,
        .weight = 85,
        .description_FR = gSunfloraPokedexText_FR,
        .description_LG = gSunfloraPokedexText_LG,
        .pokemonScale = 374,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_YANMA] =
    {
        .categoryName = _("TRANSLAILE"),
        .height = 12,
        .weight = 380,
        .description_FR = gYanmaPokedexText_FR,
        .description_LG = gYanmaPokedexText_LG,
        .pokemonScale = 274,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WOOPER] =
    {
        .categoryName = _("POISSON"),
        .height = 4,
        .weight = 85,
        .description_FR = gWooperPokedexText_FR,
        .description_LG = gWooperPokedexText_LG,
        .pokemonScale = 479,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_QUAGSIRE] =
    {
        .categoryName = _("POISSON"),
        .height = 14,
        .weight = 750,
        .description_FR = gQuagsirePokedexText_FR,
        .description_LG = gQuagsirePokedexText_LG,
        .pokemonScale = 273,
        .pokemonOffset = 4,
        .trainerScale = 273,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ESPEON] =
    {
        .categoryName = _("SOLEIL"),
        .height = 9,
        .weight = 265,
        .description_FR = gEspeonPokedexText_FR,
        .description_LG = gEspeonPokedexText_LG,
        .pokemonScale = 363,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_UMBREON] =
    {
        .categoryName = _("LUNE"),
        .height = 10,
        .weight = 270,
        .description_FR = gUmbreonPokedexText_FR,
        .description_LG = gUmbreonPokedexText_LG,
        .pokemonScale = 317,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MURKROW] =
    {
        .categoryName = _("OBSCURITE"),
        .height = 5,
        .weight = 21,
        .description_FR = gMurkrowPokedexText_FR,
        .description_LG = gMurkrowPokedexText_LG,
        .pokemonScale = 401,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SLOWKING] =
    {
        .categoryName = _("ROYAL"),
        .height = 20,
        .weight = 795,
        .description_FR = gSlowkingPokedexText_FR,
        .description_LG = gSlowkingPokedexText_LG,
        .pokemonScale = 265,
        .pokemonOffset = -1,
        .trainerScale = 330,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_MISDREAVUS] =
    {
        .categoryName = _("STRIDENT"),
        .height = 7,
        .weight = 10,
        .description_FR = gMisdreavusPokedexText_FR,
        .description_LG = gMisdreavusPokedexText_LG,
        .pokemonScale = 407,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_UNOWN] =
    {
        .categoryName = _("SYMBOLIQUE"),
        .height = 5,
        .weight = 50,
        .description_FR = gUnownPokedexText_FR,
        .description_LG = gUnownPokedexText_LG,
        .pokemonScale = 411,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WOBBUFFET] =
    {
        .categoryName = _("PATIENT"),
        .height = 13,
        .weight = 285,
        .description_FR = gWobbuffetPokedexText_FR,
        .description_LG = gWobbuffetPokedexText_LG,
        .pokemonScale = 274,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GIRAFARIG] =
    {
        .categoryName = _("LONG-COU"),
        .height = 15,
        .weight = 415,
        .description_FR = gGirafarigPokedexText_FR,
        .description_LG = gGirafarigPokedexText_LG,
        .pokemonScale = 281,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PINECO] =
    {
        .categoryName = _("VER CACHE"),
        .height = 6,
        .weight = 72,
        .description_FR = gPinecoPokedexText_FR,
        .description_LG = gPinecoPokedexText_LG,
        .pokemonScale = 445,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_FORRETRESS] =
    {
        .categoryName = _("VER CACHE"),
        .height = 12,
        .weight = 1258,
        .description_FR = gForretressPokedexText_FR,
        .description_LG = gForretressPokedexText_LG,
        .pokemonScale = 293,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DUNSPARCE] =
    {
        .categoryName = _("SERPENT"),
        .height = 15,
        .weight = 140,
        .description_FR = gDunsparcePokedexText_FR,
        .description_LG = gDunsparcePokedexText_LG,
        .pokemonScale = 284,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GLIGAR] =
    {
        .categoryName = _("SCORPIVOL"),
        .height = 11,
        .weight = 648,
        .description_FR = gGligarPokedexText_FR,
        .description_LG = gGligarPokedexText_LG,
        .pokemonScale = 350,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_STEELIX] =
    {
        .categoryName = _("SERPENFER"),
        .height = 92,
        .weight = 4000,
        .description_FR = gSteelixPokedexText_FR,
        .description_LG = gSteelixPokedexText_LG,
        .pokemonScale = 278,
        .pokemonOffset = -1,
        .trainerScale = 557,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_SNUBBULL] =
    {
        .categoryName = _("FEE"),
        .height = 6,
        .weight = 78,
        .description_FR = gSnubbullPokedexText_FR,
        .description_LG = gSnubbullPokedexText_LG,
        .pokemonScale = 465,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GRANBULL] =
    {
        .categoryName = _("FEE"),
        .height = 14,
        .weight = 487,
        .description_FR = gGranbullPokedexText_FR,
        .description_LG = gGranbullPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_QWILFISH] =
    {
        .categoryName = _("BOUBOULE"),
        .height = 5,
        .weight = 39,
        .description_FR = gQwilfishPokedexText_FR,
        .description_LG = gQwilfishPokedexText_LG,
        .pokemonScale = 430,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SCIZOR] =
    {
        .categoryName = _("PINCE"),
        .height = 18,
        .weight = 1180,
        .description_FR = gScizorPokedexText_FR,
        .description_LG = gScizorPokedexText_LG,
        .pokemonScale = 282,
        .pokemonOffset = 0,
        .trainerScale = 282,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHUCKLE] =
    {
        .categoryName = _("POURRI"),
        .height = 6,
        .weight = 205,
        .description_FR = gShucklePokedexText_FR,
        .description_LG = gShucklePokedexText_LG,
        .pokemonScale = 485,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HERACROSS] =
    {
        .categoryName = _("UNICORNE"),
        .height = 15,
        .weight = 540,
        .description_FR = gHeracrossPokedexText_FR,
        .description_LG = gHeracrossPokedexText_LG,
        .pokemonScale = 285,
        .pokemonOffset = 0,
        .trainerScale = 283,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SNEASEL] =
    {
        .categoryName = _("GRIFACEREE"),
        .height = 9,
        .weight = 280,
        .description_FR = gSneaselPokedexText_FR,
        .description_LG = gSneaselPokedexText_LG,
        .pokemonScale = 413,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TEDDIURSA] =
    {
        .categoryName = _("MINI OURS"),
        .height = 6,
        .weight = 88,
        .description_FR = gTeddiursaPokedexText_FR,
        .description_LG = gTeddiursaPokedexText_LG,
        .pokemonScale = 455,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_URSARING] =
    {
        .categoryName = _("HIBERNANT"),
        .height = 18,
        .weight = 1258,
        .description_FR = gUrsaringPokedexText_FR,
        .description_LG = gUrsaringPokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = 0,
        .trainerScale = 280,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SLUGMA] =
    {
        .categoryName = _("LAVE"),
        .height = 7,
        .weight = 350,
        .description_FR = gSlugmaPokedexText_FR,
        .description_LG = gSlugmaPokedexText_LG,
        .pokemonScale = 329,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MAGCARGO] =
    {
        .categoryName = _("LAVE"),
        .height = 8,
        .weight = 550,
        .description_FR = gMagcargoPokedexText_FR,
        .description_LG = gMagcargoPokedexText_LG,
        .pokemonScale = 332,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SWINUB] =
    {
        .categoryName = _("COCHON"),
        .height = 4,
        .weight = 65,
        .description_FR = gSwinubPokedexText_FR,
        .description_LG = gSwinubPokedexText_LG,
        .pokemonScale = 324,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PILOSWINE] =
    {
        .categoryName = _("PORC"),
        .height = 11,
        .weight = 558,
        .description_FR = gPiloswinePokedexText_FR,
        .description_LG = gPiloswinePokedexText_LG,
        .pokemonScale = 306,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CORSOLA] =
    {
        .categoryName = _("CORAIL"),
        .height = 6,
        .weight = 50,
        .description_FR = gCorsolaPokedexText_FR,
        .description_LG = gCorsolaPokedexText_LG,
        .pokemonScale = 410,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_REMORAID] =
    {
        .categoryName = _("JET"),
        .height = 6,
        .weight = 120,
        .description_FR = gRemoraidPokedexText_FR,
        .description_LG = gRemoraidPokedexText_LG,
        .pokemonScale = 316,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_OCTILLERY] =
    {
        .categoryName = _("JET"),
        .height = 9,
        .weight = 285,
        .description_FR = gOctilleryPokedexText_FR,
        .description_LG = gOctilleryPokedexText_LG,
        .pokemonScale = 296,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DELIBIRD] =
    {
        .categoryName = _("LIVRAISON"),
        .height = 9,
        .weight = 160,
        .description_FR = gDelibirdPokedexText_FR,
        .description_LG = gDelibirdPokedexText_LG,
        .pokemonScale = 293,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MANTINE] =
    {
        .categoryName = _("CERVOLANT"),
        .height = 21,
        .weight = 2200,
        .description_FR = gMantinePokedexText_FR,
        .description_LG = gMantinePokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = 0,
        .trainerScale = 360,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_SKARMORY] =
    {
        .categoryName = _("ARMOISEAU"),
        .height = 17,
        .weight = 505,
        .description_FR = gSkarmoryPokedexText_FR,
        .description_LG = gSkarmoryPokedexText_LG,
        .pokemonScale = 285,
        .pokemonOffset = 0,
        .trainerScale = 276,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HOUNDOUR] =
    {
        .categoryName = _("SOMBRE"),
        .height = 6,
        .weight = 108,
        .description_FR = gHoundourPokedexText_FR,
        .description_LG = gHoundourPokedexText_LG,
        .pokemonScale = 393,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HOUNDOOM] =
    {
        .categoryName = _("SOMBRE"),
        .height = 14,
        .weight = 350,
        .description_FR = gHoundoomPokedexText_FR,
        .description_LG = gHoundoomPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_KINGDRA] =
    {
        .categoryName = _("DRAGON"),
        .height = 18,
        .weight = 1520,
        .description_FR = gKingdraPokedexText_FR,
        .description_LG = gKingdraPokedexText_LG,
        .pokemonScale = 257,
        .pokemonOffset = 1,
        .trainerScale = 293,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_PHANPY] =
    {
        .categoryName = _("LONG-NEZ"),
        .height = 5,
        .weight = 335,
        .description_FR = gPhanpyPokedexText_FR,
        .description_LG = gPhanpyPokedexText_LG,
        .pokemonScale = 465,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DONPHAN] =
    {
        .categoryName = _("ARMURE"),
        .height = 11,
        .weight = 1200,
        .description_FR = gDonphanPokedexText_FR,
        .description_LG = gDonphanPokedexText_LG,
        .pokemonScale = 313,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PORYGON2] =
    {
        .categoryName = _("VIRTUEL"),
        .height = 6,
        .weight = 325,
        .description_FR = gPorygon2PokedexText_FR,
        .description_LG = gPorygon2PokedexText_LG,
        .pokemonScale = 320,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_STANTLER] =
    {
        .categoryName = _("MAXI CORNE"),
        .height = 14,
        .weight = 712,
        .description_FR = gStantlerPokedexText_FR,
        .description_LG = gStantlerPokedexText_LG,
        .pokemonScale = 277,
        .pokemonOffset = -1,
        .trainerScale = 277,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SMEARGLE] =
    {
        .categoryName = _("PEINTRE"),
        .height = 12,
        .weight = 580,
        .description_FR = gSmearglePokedexText_FR,
        .description_LG = gSmearglePokedexText_LG,
        .pokemonScale = 287,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TYROGUE] =
    {
        .categoryName = _("BAGARREUR"),
        .height = 7,
        .weight = 210,
        .description_FR = gTyroguePokedexText_FR,
        .description_LG = gTyroguePokedexText_LG,
        .pokemonScale = 292,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HITMONTOP] =
    {
        .categoryName = _("POIRIER"),
        .height = 14,
        .weight = 480,
        .description_FR = gHitmontopPokedexText_FR,
        .description_LG = gHitmontopPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 257,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SMOOCHUM] =
    {
        .categoryName = _("BISOU"),
        .height = 4,
        .weight = 60,
        .description_FR = gSmoochumPokedexText_FR,
        .description_LG = gSmoochumPokedexText_LG,
        .pokemonScale = 440,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ELEKID] =
    {
        .categoryName = _("ELECTRIQUE"),
        .height = 6,
        .weight = 235,
        .description_FR = gElekidPokedexText_FR,
        .description_LG = gElekidPokedexText_LG,
        .pokemonScale = 363,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MAGBY] =
    {
        .categoryName = _("CHARBON"),
        .height = 7,
        .weight = 214,
        .description_FR = gMagbyPokedexText_FR,
        .description_LG = gMagbyPokedexText_LG,
        .pokemonScale = 284,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MILTANK] =
    {
        .categoryName = _("VACHALAIT"),
        .height = 12,
        .weight = 755,
        .description_FR = gMiltankPokedexText_FR,
        .description_LG = gMiltankPokedexText_LG,
        .pokemonScale = 280,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BLISSEY] =
    {
        .categoryName = _("BONHEUR"),
        .height = 15,
        .weight = 468,
        .description_FR = gBlisseyPokedexText_FR,
        .description_LG = gBlisseyPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 310,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_RAIKOU] =
    {
        .categoryName = _("FOUDRE"),
        .height = 19,
        .weight = 1780,
        .description_FR = gRaikouPokedexText_FR,
        .description_LG = gRaikouPokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = 0,
        .trainerScale = 359,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_ENTEI] =
    {
        .categoryName = _("VOLCAN"),
        .height = 21,
        .weight = 1980,
        .description_FR = gEnteiPokedexText_FR,
        .description_LG = gEnteiPokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = 0,
        .trainerScale = 370,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_SUICUNE] =
    {
        .categoryName = _("AURORE"),
        .height = 20,
        .weight = 1870,
        .description_FR = gSuicunePokedexText_FR,
        .description_LG = gSuicunePokedexText_LG,
        .pokemonScale = 286,
        .pokemonOffset = 0,
        .trainerScale = 371,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_LARVITAR] =
    {
        .categoryName = _("PEAUPIERRE"),
        .height = 6,
        .weight = 720,
        .description_FR = gLarvitarPokedexText_FR,
        .description_LG = gLarvitarPokedexText_LG,
        .pokemonScale = 472,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PUPITAR] =
    {
        .categoryName = _("CARAPADURE"),
        .height = 12,
        .weight = 1520,
        .description_FR = gPupitarPokedexText_FR,
        .description_LG = gPupitarPokedexText_LG,
        .pokemonScale = 292,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TYRANITAR] =
    {
        .categoryName = _("ARMURE"),
        .height = 20,
        .weight = 2020,
        .description_FR = gTyranitarPokedexText_FR,
        .description_LG = gTyranitarPokedexText_LG,
        .pokemonScale = 285,
        .pokemonOffset = 0,
        .trainerScale = 383,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_LUGIA] =
    {
        .categoryName = _("PLONGEON"),
        .height = 52,
        .weight = 2160,
        .description_FR = gLugiaPokedexText_FR,
        .description_LG = gLugiaPokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = 0,
        .trainerScale = 742,
        .trainerOffset = 18,
    },

    [NATIONAL_DEX_HO_OH] =
    {
        .categoryName = _("ARCENCIEL"),
        .height = 38,
        .weight = 1990,
        .description_FR = gHoOhPokedexText_FR,
        .description_LG = gHoOhPokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = 0,
        .trainerScale = 620,
        .trainerOffset = 16,
    },

    [NATIONAL_DEX_CELEBI] =
    {
        .categoryName = _("TEMPOREL"),
        .height = 6,
        .weight = 50,
        .description_FR = gCelebiPokedexText_FR,
        .description_LG = gCelebiPokedexText_LG,
        .pokemonScale = 393,
        .pokemonOffset = -10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TREECKO] =
    {
        .categoryName = _("BOIS GECKO"),
        .height = 5,
        .weight = 50,
        .description_FR = gTreeckoPokedexText_FR,
        .description_LG = gTreeckoPokedexText_LG,
        .pokemonScale = 541,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GROVYLE] =
    {
        .categoryName = _("BOIS GECKO"),
        .height = 9,
        .weight = 216,
        .description_FR = gGrovylePokedexText_FR,
        .description_LG = gGrovylePokedexText_LG,
        .pokemonScale = 360,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SCEPTILE] =
    {
        .categoryName = _("FORET"),
        .height = 17,
        .weight = 522,
        .description_FR = gSceptilePokedexText_FR,
        .description_LG = gSceptilePokedexText_LG,
        .pokemonScale = 282,
        .pokemonOffset = -1,
        .trainerScale = 313,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_TORCHIC] =
    {
        .categoryName = _("POUSSIN"),
        .height = 4,
        .weight = 25,
        .description_FR = gTorchicPokedexText_FR,
        .description_LG = gTorchicPokedexText_LG,
        .pokemonScale = 566,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_COMBUSKEN] =
    {
        .categoryName = _("POULET"),
        .height = 9,
        .weight = 195,
        .description_FR = gCombuskenPokedexText_FR,
        .description_LG = gCombuskenPokedexText_LG,
        .pokemonScale = 343,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BLAZIKEN] =
    {
        .categoryName = _("ARDENT"),
        .height = 19,
        .weight = 520,
        .description_FR = gBlazikenPokedexText_FR,
        .description_LG = gBlazikenPokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = -1,
        .trainerScale = 314,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_MUDKIP] =
    {
        .categoryName = _("POISSONBOUE"),
        .height = 4,
        .weight = 76,
        .description_FR = gMudkipPokedexText_FR,
        .description_LG = gMudkipPokedexText_LG,
        .pokemonScale = 535,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MARSHTOMP] =
    {
        .categoryName = _("POISSONBOUE"),
        .height = 7,
        .weight = 280,
        .description_FR = gMarshtompPokedexText_FR,
        .description_LG = gMarshtompPokedexText_LG,
        .pokemonScale = 340,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SWAMPERT] =
    {
        .categoryName = _("POISSONBOUE"),
        .height = 15,
        .weight = 819,
        .description_FR = gSwampertPokedexText_FR,
        .description_LG = gSwampertPokedexText_LG,
        .pokemonScale = 276,
        .pokemonOffset = -1,
        .trainerScale = 282,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_POOCHYENA] =
    {
        .categoryName = _("MORSURE"),
        .height = 5,
        .weight = 136,
        .description_FR = gPoochyenaPokedexText_FR,
        .description_LG = gPoochyenaPokedexText_LG,
        .pokemonScale = 481,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MIGHTYENA] =
    {
        .categoryName = _("MORSURE"),
        .height = 10,
        .weight = 370,
        .description_FR = gMightyenaPokedexText_FR,
        .description_LG = gMightyenaPokedexText_LG,
        .pokemonScale = 359,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ZIGZAGOON] =
    {
        .categoryName = _("PETIT RATON"),
        .height = 4,
        .weight = 175,
        .description_FR = gZigzagoonPokedexText_FR,
        .description_LG = gZigzagoonPokedexText_LG,
        .pokemonScale = 560,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LINOONE] =
    {
        .categoryName = _("FONCEUR"),
        .height = 5,
        .weight = 325,
        .description_FR = gLinoonePokedexText_FR,
        .description_LG = gLinoonePokedexText_LG,
        .pokemonScale = 321,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WURMPLE] =
    {
        .categoryName = _("VER"),
        .height = 3,
        .weight = 36,
        .description_FR = gWurmplePokedexText_FR,
        .description_LG = gWurmplePokedexText_LG,
        .pokemonScale = 711,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SILCOON] =
    {
        .categoryName = _("COCON"),
        .height = 6,
        .weight = 100,
        .description_FR = gSilcoonPokedexText_FR,
        .description_LG = gSilcoonPokedexText_LG,
        .pokemonScale = 431,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BEAUTIFLY] =
    {
        .categoryName = _("PAPILLON"),
        .height = 10,
        .weight = 284,
        .description_FR = gBeautiflyPokedexText_FR,
        .description_LG = gBeautiflyPokedexText_LG,
        .pokemonScale = 298,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CASCOON] =
    {
        .categoryName = _("COCON"),
        .height = 7,
        .weight = 115,
        .description_FR = gCascoonPokedexText_FR,
        .description_LG = gCascoonPokedexText_LG,
        .pokemonScale = 391,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DUSTOX] =
    {
        .categoryName = _("PAPIPOISON"),
        .height = 12,
        .weight = 316,
        .description_FR = gDustoxPokedexText_FR,
        .description_LG = gDustoxPokedexText_LG,
        .pokemonScale = 269,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LOTAD] =
    {
        .categoryName = _("AQUAPLANTE"),
        .height = 5,
        .weight = 26,
        .description_FR = gLotadPokedexText_FR,
        .description_LG = gLotadPokedexText_LG,
        .pokemonScale = 406,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LOMBRE] =
    {
        .categoryName = _("JOVIAL"),
        .height = 12,
        .weight = 325,
        .description_FR = gLombrePokedexText_FR,
        .description_LG = gLombrePokedexText_LG,
        .pokemonScale = 277,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LUDICOLO] =
    {
        .categoryName = _("INSOUCIANT"),
        .height = 15,
        .weight = 550,
        .description_FR = gLudicoloPokedexText_FR,
        .description_LG = gLudicoloPokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = 0,
        .trainerScale = 282,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SEEDOT] =
    {
        .categoryName = _("GLAND"),
        .height = 5,
        .weight = 40,
        .description_FR = gSeedotPokedexText_FR,
        .description_LG = gSeedotPokedexText_LG,
        .pokemonScale = 472,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NUZLEAF] =
    {
        .categoryName = _("MALIN"),
        .height = 10,
        .weight = 280,
        .description_FR = gNuzleafPokedexText_FR,
        .description_LG = gNuzleafPokedexText_LG,
        .pokemonScale = 299,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SHIFTRY] =
    {
        .categoryName = _("MALVEILLANT"),
        .height = 13,
        .weight = 596,
        .description_FR = gShiftryPokedexText_FR,
        .description_LG = gShiftryPokedexText_LG,
        .pokemonScale = 290,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TAILLOW] =
    {
        .categoryName = _("MINIRONDEL"),
        .height = 3,
        .weight = 23,
        .description_FR = gTaillowPokedexText_FR,
        .description_LG = gTaillowPokedexText_LG,
        .pokemonScale = 465,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SWELLOW] =
    {
        .categoryName = _("HIRONDELLE"),
        .height = 7,
        .weight = 198,
        .description_FR = gSwellowPokedexText_FR,
        .description_LG = gSwellowPokedexText_LG,
        .pokemonScale = 428,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WINGULL] =
    {
        .categoryName = _("MOUETTE"),
        .height = 6,
        .weight = 95,
        .description_FR = gWingullPokedexText_FR,
        .description_LG = gWingullPokedexText_LG,
        .pokemonScale = 295,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PELIPPER] =
    {
        .categoryName = _("OISEAUDO"),
        .height = 12,
        .weight = 280,
        .description_FR = gPelipperPokedexText_FR,
        .description_LG = gPelipperPokedexText_LG,
        .pokemonScale = 288,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_RALTS] =
    {
        .categoryName = _("SENTIMENT"),
        .height = 4,
        .weight = 66,
        .description_FR = gRaltsPokedexText_FR,
        .description_LG = gRaltsPokedexText_LG,
        .pokemonScale = 457,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_KIRLIA] =
    {
        .categoryName = _("EMOTION"),
        .height = 8,
        .weight = 202,
        .description_FR = gKirliaPokedexText_FR,
        .description_LG = gKirliaPokedexText_LG,
        .pokemonScale = 354,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GARDEVOIR] =
    {
        .categoryName = _("ETREINTE"),
        .height = 16,
        .weight = 484,
        .description_FR = gGardevoirPokedexText_FR,
        .description_LG = gGardevoirPokedexText_LG,
        .pokemonScale = 277,
        .pokemonOffset = 0,
        .trainerScale = 276,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_SURSKIT] =
    {
        .categoryName = _("MARESURFEUR"),
        .height = 5,
        .weight = 17,
        .description_FR = gSurskitPokedexText_FR,
        .description_LG = gSurskitPokedexText_LG,
        .pokemonScale = 375,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MASQUERAIN] =
    {
        .categoryName = _("BOULE OEIL"),
        .height = 8,
        .weight = 36,
        .description_FR = gMasquerainPokedexText_FR,
        .description_LG = gMasquerainPokedexText_LG,
        .pokemonScale = 378,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SHROOMISH] =
    {
        .categoryName = _("CHAMPIGNON"),
        .height = 4,
        .weight = 45,
        .description_FR = gShroomishPokedexText_FR,
        .description_LG = gShroomishPokedexText_LG,
        .pokemonScale = 513,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BRELOOM] =
    {
        .categoryName = _("CHAMPIGNON"),
        .height = 12,
        .weight = 392,
        .description_FR = gBreloomPokedexText_FR,
        .description_LG = gBreloomPokedexText_LG,
        .pokemonScale = 324,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SLAKOTH] =
    {
        .categoryName = _("FLANEUR"),
        .height = 8,
        .weight = 240,
        .description_FR = gSlakothPokedexText_FR,
        .description_LG = gSlakothPokedexText_LG,
        .pokemonScale = 291,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_VIGOROTH] =
    {
        .categoryName = _("TURBUSINGE"),
        .height = 14,
        .weight = 465,
        .description_FR = gVigorothPokedexText_FR,
        .description_LG = gVigorothPokedexText_LG,
        .pokemonScale = 301,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SLAKING] =
    {
        .categoryName = _("FAINEANT"),
        .height = 20,
        .weight = 1305,
        .description_FR = gSlakingPokedexText_FR,
        .description_LG = gSlakingPokedexText_LG,
        .pokemonScale = 277,
        .pokemonOffset = 5,
        .trainerScale = 326,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_NINCADA] =
    {
        .categoryName = _("APPRENTI"),
        .height = 5,
        .weight = 55,
        .description_FR = gNincadaPokedexText_FR,
        .description_LG = gNincadaPokedexText_LG,
        .pokemonScale = 405,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NINJASK] =
    {
        .categoryName = _("NINJA"),
        .height = 8,
        .weight = 120,
        .description_FR = gNinjaskPokedexText_FR,
        .description_LG = gNinjaskPokedexText_LG,
        .pokemonScale = 383,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SHEDINJA] =
    {
        .categoryName = _("EXUVIE"),
        .height = 8,
        .weight = 12,
        .description_FR = gShedinjaPokedexText_FR,
        .description_LG = gShedinjaPokedexText_LG,
        .pokemonScale = 372,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WHISMUR] =
    {
        .categoryName = _("CHUCHOTEUR"),
        .height = 6,
        .weight = 163,
        .description_FR = gWhismurPokedexText_FR,
        .description_LG = gWhismurPokedexText_LG,
        .pokemonScale = 373,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LOUDRED] =
    {
        .categoryName = _("GROSSE VOIX"),
        .height = 10,
        .weight = 405,
        .description_FR = gLoudredPokedexText_FR,
        .description_LG = gLoudredPokedexText_LG,
        .pokemonScale = 356,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_EXPLOUD] =
    {
        .categoryName = _("BRUIT SOURD"),
        .height = 15,
        .weight = 840,
        .description_FR = gExploudPokedexText_FR,
        .description_LG = gExploudPokedexText_LG,
        .pokemonScale = 284,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MAKUHITA] =
    {
        .categoryName = _("TENACE"),
        .height = 10,
        .weight = 864,
        .description_FR = gMakuhitaPokedexText_FR,
        .description_LG = gMakuhitaPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HARIYAMA] =
    {
        .categoryName = _("COGNEUR"),
        .height = 23,
        .weight = 2538,
        .description_FR = gHariyamaPokedexText_FR,
        .description_LG = gHariyamaPokedexText_LG,
        .pokemonScale = 268,
        .pokemonOffset = -1,
        .trainerScale = 375,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_AZURILL] =
    {
        .categoryName = _("POINT POLKA"),
        .height = 2,
        .weight = 20,
        .description_FR = gAzurillPokedexText_FR,
        .description_LG = gAzurillPokedexText_LG,
        .pokemonScale = 603,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_NOSEPASS] =
    {
        .categoryName = _("BOUSSOLE"),
        .height = 10,
        .weight = 970,
        .description_FR = gNosepassPokedexText_FR,
        .description_LG = gNosepassPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 9,
        .trainerScale = 289,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_SKITTY] =
    {
        .categoryName = _("CHATON"),
        .height = 6,
        .weight = 110,
        .description_FR = gSkittyPokedexText_FR,
        .description_LG = gSkittyPokedexText_LG,
        .pokemonScale = 492,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DELCATTY] =
    {
        .categoryName = _("GUINDE"),
        .height = 11,
        .weight = 326,
        .description_FR = gDelcattyPokedexText_FR,
        .description_LG = gDelcattyPokedexText_LG,
        .pokemonScale = 322,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SABLEYE] =
    {
        .categoryName = _("OBSCURITE"),
        .height = 5,
        .weight = 110,
        .description_FR = gSableyePokedexText_FR,
        .description_LG = gSableyePokedexText_LG,
        .pokemonScale = 451,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MAWILE] =
    {
        .categoryName = _("TROMPEUR"),
        .height = 6,
        .weight = 115,
        .description_FR = gMawilePokedexText_FR,
        .description_LG = gMawilePokedexText_LG,
        .pokemonScale = 466,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -3,
    },

    [NATIONAL_DEX_ARON] =
    {
        .categoryName = _("ARMURFER"),
        .height = 4,
        .weight = 600,
        .description_FR = gAronPokedexText_FR,
        .description_LG = gAronPokedexText_LG,
        .pokemonScale = 419,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LAIRON] =
    {
        .categoryName = _("ARMURFER"),
        .height = 9,
        .weight = 1200,
        .description_FR = gLaironPokedexText_FR,
        .description_LG = gLaironPokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_AGGRON] =
    {
        .categoryName = _("ARMURFER"),
        .height = 21,
        .weight = 3600,
        .description_FR = gAggronPokedexText_FR,
        .description_LG = gAggronPokedexText_LG,
        .pokemonScale = 274,
        .pokemonOffset = -1,
        .trainerScale = 374,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_MEDITITE] =
    {
        .categoryName = _("MEDITATION"),
        .height = 6,
        .weight = 112,
        .description_FR = gMedititePokedexText_FR,
        .description_LG = gMedititePokedexText_LG,
        .pokemonScale = 465,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MEDICHAM] =
    {
        .categoryName = _("MEDITATION"),
        .height = 13,
        .weight = 315,
        .description_FR = gMedichamPokedexText_FR,
        .description_LG = gMedichamPokedexText_LG,
        .pokemonScale = 298,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ELECTRIKE] =
    {
        .categoryName = _("ORAGE"),
        .height = 6,
        .weight = 152,
        .description_FR = gElectrikePokedexText_FR,
        .description_LG = gElectrikePokedexText_LG,
        .pokemonScale = 290,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MANECTRIC] =
    {
        .categoryName = _("DECHARGE"),
        .height = 15,
        .weight = 402,
        .description_FR = gManectricPokedexText_FR,
        .description_LG = gManectricPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 257,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_PLUSLE] =
    {
        .categoryName = _("ACCLAMEUR"),
        .height = 4,
        .weight = 42,
        .description_FR = gPluslePokedexText_FR,
        .description_LG = gPluslePokedexText_LG,
        .pokemonScale = 515,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MINUN] =
    {
        .categoryName = _("ACCLAMEUR"),
        .height = 4,
        .weight = 42,
        .description_FR = gMinunPokedexText_FR,
        .description_LG = gMinunPokedexText_LG,
        .pokemonScale = 512,
        .pokemonOffset = -7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_VOLBEAT] =
    {
        .categoryName = _("LUCIOLE"),
        .height = 7,
        .weight = 177,
        .description_FR = gVolbeatPokedexText_FR,
        .description_LG = gVolbeatPokedexText_LG,
        .pokemonScale = 442,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ILLUMISE] =
    {
        .categoryName = _("LUCIOLE"),
        .height = 6,
        .weight = 177,
        .description_FR = gIllumisePokedexText_FR,
        .description_LG = gIllumisePokedexText_LG,
        .pokemonScale = 572,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ROSELIA] =
    {
        .categoryName = _("EPINE"),
        .height = 3,
        .weight = 20,
        .description_FR = gRoseliaPokedexText_FR,
        .description_LG = gRoseliaPokedexText_LG,
        .pokemonScale = 677,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GULPIN] =
    {
        .categoryName = _("ESTOMAC"),
        .height = 4,
        .weight = 103,
        .description_FR = gGulpinPokedexText_FR,
        .description_LG = gGulpinPokedexText_LG,
        .pokemonScale = 593,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SWALOT] =
    {
        .categoryName = _("SAC POISON"),
        .height = 17,
        .weight = 800,
        .description_FR = gSwalotPokedexText_FR,
        .description_LG = gSwalotPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 5,
        .trainerScale = 345,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_CARVANHA] =
    {
        .categoryName = _("FEROCE"),
        .height = 8,
        .weight = 208,
        .description_FR = gCarvanhaPokedexText_FR,
        .description_LG = gCarvanhaPokedexText_LG,
        .pokemonScale = 362,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SHARPEDO] =
    {
        .categoryName = _("BRUTAL"),
        .height = 18,
        .weight = 888,
        .description_FR = gSharpedoPokedexText_FR,
        .description_LG = gSharpedoPokedexText_LG,
        .pokemonScale = 265,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_WAILMER] =
    {
        .categoryName = _("BALEINBOULE"),
        .height = 20,
        .weight = 1300,
        .description_FR = gWailmerPokedexText_FR,
        .description_LG = gWailmerPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 10,
        .trainerScale = 493,
        .trainerOffset = 10,
    },

    [NATIONAL_DEX_WAILORD] =
    {
        .categoryName = _("CACHABOUEE"),
        .height = 145,
        .weight = 3980,
        .description_FR = gWailordPokedexText_FR,
        .description_LG = gWailordPokedexText_LG,
        .pokemonScale = 276,
        .pokemonOffset = -1,
        .trainerScale = 1428,
        .trainerOffset = 20,
    },

    [NATIONAL_DEX_NUMEL] =
    {
        .categoryName = _("ENGOURDI"),
        .height = 7,
        .weight = 240,
        .description_FR = gNumelPokedexText_FR,
        .description_LG = gNumelPokedexText_LG,
        .pokemonScale = 310,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CAMERUPT] =
    {
        .categoryName = _("ERUPTION"),
        .height = 19,
        .weight = 2200,
        .description_FR = gCameruptPokedexText_FR,
        .description_LG = gCameruptPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_TORKOAL] =
    {
        .categoryName = _("CHARBON"),
        .height = 5,
        .weight = 804,
        .description_FR = gTorkoalPokedexText_FR,
        .description_LG = gTorkoalPokedexText_LG,
        .pokemonScale = 392,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SPOINK] =
    {
        .categoryName = _("REBOND"),
        .height = 7,
        .weight = 306,
        .description_FR = gSpoinkPokedexText_FR,
        .description_LG = gSpoinkPokedexText_LG,
        .pokemonScale = 423,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GRUMPIG] =
    {
        .categoryName = _("MAGOUILLEUR"),
        .height = 9,
        .weight = 715,
        .description_FR = gGrumpigPokedexText_FR,
        .description_LG = gGrumpigPokedexText_LG,
        .pokemonScale = 358,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SPINDA] =
    {
        .categoryName = _("PANDA TACHE"),
        .height = 11,
        .weight = 50,
        .description_FR = gSpindaPokedexText_FR,
        .description_LG = gSpindaPokedexText_LG,
        .pokemonScale = 321,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_TRAPINCH] =
    {
        .categoryName = _("PIEGEUR"),
        .height = 7,
        .weight = 150,
        .description_FR = gTrapinchPokedexText_FR,
        .description_LG = gTrapinchPokedexText_LG,
        .pokemonScale = 298,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_VIBRAVA] =
    {
        .categoryName = _("VIBRATION"),
        .height = 11,
        .weight = 153,
        .description_FR = gVibravaPokedexText_FR,
        .description_LG = gVibravaPokedexText_LG,
        .pokemonScale = 370,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_FLYGON] =
    {
        .categoryName = _("MYSTIQUE"),
        .height = 20,
        .weight = 820,
        .description_FR = gFlygonPokedexText_FR,
        .description_LG = gFlygonPokedexText_LG,
        .pokemonScale = 280,
        .pokemonOffset = 0,
        .trainerScale = 299,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CACNEA] =
    {
        .categoryName = _("CACTUS"),
        .height = 4,
        .weight = 513,
        .description_FR = gCacneaPokedexText_FR,
        .description_LG = gCacneaPokedexText_LG,
        .pokemonScale = 455,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CACTURNE] =
    {
        .categoryName = _("EPOUVANTAIL"),
        .height = 13,
        .weight = 774,
        .description_FR = gCacturnePokedexText_FR,
        .description_LG = gCacturnePokedexText_LG,
        .pokemonScale = 327,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SWABLU] =
    {
        .categoryName = _("OISEAUCOTON"),
        .height = 4,
        .weight = 12,
        .description_FR = gSwabluPokedexText_FR,
        .description_LG = gSwabluPokedexText_LG,
        .pokemonScale = 422,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ALTARIA] =
    {
        .categoryName = _("VIREVOLTEUR"),
        .height = 11,
        .weight = 206,
        .description_FR = gAltariaPokedexText_FR,
        .description_LG = gAltariaPokedexText_LG,
        .pokemonScale = 327,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ZANGOOSE] =
    {
        .categoryName = _("CHAT FURET"),
        .height = 13,
        .weight = 403,
        .description_FR = gZangoosePokedexText_FR,
        .description_LG = gZangoosePokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SEVIPER] =
    {
        .categoryName = _("SERPACROC"),
        .height = 27,
        .weight = 525,
        .description_FR = gSeviperPokedexText_FR,
        .description_LG = gSeviperPokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LUNATONE] =
    {
        .categoryName = _("METEORITE"),
        .height = 10,
        .weight = 1680,
        .description_FR = gLunatonePokedexText_FR,
        .description_LG = gLunatonePokedexText_LG,
        .pokemonScale = 300,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SOLROCK] =
    {
        .categoryName = _("METEORITE"),
        .height = 12,
        .weight = 1540,
        .description_FR = gSolrockPokedexText_FR,
        .description_LG = gSolrockPokedexText_LG,
        .pokemonScale = 328,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BARBOACH] =
    {
        .categoryName = _("BARBILLON"),
        .height = 4,
        .weight = 19,
        .description_FR = gBarboachPokedexText_FR,
        .description_LG = gBarboachPokedexText_LG,
        .pokemonScale = 581,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WHISCASH] =
    {
        .categoryName = _("BARBILLON"),
        .height = 9,
        .weight = 236,
        .description_FR = gWhiscashPokedexText_FR,
        .description_LG = gWhiscashPokedexText_LG,
        .pokemonScale = 317,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CORPHISH] =
    {
        .categoryName = _("BRUTE"),
        .height = 6,
        .weight = 115,
        .description_FR = gCorphishPokedexText_FR,
        .description_LG = gCorphishPokedexText_LG,
        .pokemonScale = 484,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CRAWDAUNT] =
    {
        .categoryName = _("CRAPULE"),
        .height = 11,
        .weight = 328,
        .description_FR = gCrawdauntPokedexText_FR,
        .description_LG = gCrawdauntPokedexText_LG,
        .pokemonScale = 365,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BALTOY] =
    {
        .categoryName = _("POUPARGILE"),
        .height = 5,
        .weight = 215,
        .description_FR = gBaltoyPokedexText_FR,
        .description_LG = gBaltoyPokedexText_LG,
        .pokemonScale = 384,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = -3,
    },

    [NATIONAL_DEX_CLAYDOL] =
    {
        .categoryName = _("POUPARGILE"),
        .height = 15,
        .weight = 1080,
        .description_FR = gClaydolPokedexText_FR,
        .description_LG = gClaydolPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 280,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LILEEP] =
    {
        .categoryName = _("LIS D'EAU"),
        .height = 10,
        .weight = 238,
        .description_FR = gLileepPokedexText_FR,
        .description_LG = gLileepPokedexText_LG,
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_CRADILY] =
    {
        .categoryName = _("BERNACLE"),
        .height = 15,
        .weight = 604,
        .description_FR = gCradilyPokedexText_FR,
        .description_LG = gCradilyPokedexText_LG,
        .pokemonScale = 275,
        .pokemonOffset = -1,
        .trainerScale = 269,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_ANORITH] =
    {
        .categoryName = _("CRUSTAGE"),
        .height = 7,
        .weight = 125,
        .description_FR = gAnorithPokedexText_FR,
        .description_LG = gAnorithPokedexText_LG,
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ARMALDO] =
    {
        .categoryName = _("BLINDAGE"),
        .height = 15,
        .weight = 682,
        .description_FR = gArmaldoPokedexText_FR,
        .description_LG = gArmaldoPokedexText_LG,
        .pokemonScale = 312,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_FEEBAS] =
    {
        .categoryName = _("POISSON"),
        .height = 6,
        .weight = 74,
        .description_FR = gFeebasPokedexText_FR,
        .description_LG = gFeebasPokedexText_LG,
        .pokemonScale = 423,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_MILOTIC] =
    {
        .categoryName = _("TENDRE"),
        .height = 62,
        .weight = 1620,
        .description_FR = gMiloticPokedexText_FR,
        .description_LG = gMiloticPokedexText_LG,
        .pokemonScale = 282,
        .pokemonOffset = -1,
        .trainerScale = 382,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_CASTFORM] =
    {
        .categoryName = _("CLIMAT"),
        .height = 3,
        .weight = 8,
        .description_FR = gCastformPokedexText_FR,
        .description_LG = gCastformPokedexText_LG,
        .pokemonScale = 435,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_KECLEON] =
    {
        .categoryName = _("MULTICOLOR"),
        .height = 10,
        .weight = 220,
        .description_FR = gKecleonPokedexText_FR,
        .description_LG = gKecleonPokedexText_LG,
        .pokemonScale = 316,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SHUPPET] =
    {
        .categoryName = _("POUPEE"),
        .height = 6,
        .weight = 23,
        .description_FR = gShuppetPokedexText_FR,
        .description_LG = gShuppetPokedexText_LG,
        .pokemonScale = 440,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BANETTE] =
    {
        .categoryName = _("MARIONETTE"),
        .height = 11,
        .weight = 125,
        .description_FR = gBanettePokedexText_FR,
        .description_LG = gBanettePokedexText_LG,
        .pokemonScale = 262,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DUSKULL] =
    {
        .categoryName = _("REQUIEM"),
        .height = 8,
        .weight = 150,
        .description_FR = gDuskullPokedexText_FR,
        .description_LG = gDuskullPokedexText_LG,
        .pokemonScale = 376,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DUSCLOPS] =
    {
        .categoryName = _("APPEL"),
        .height = 16,
        .weight = 306,
        .description_FR = gDusclopsPokedexText_FR,
        .description_LG = gDusclopsPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 299,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_TROPIUS] =
    {
        .categoryName = _("FRUIT"),
        .height = 20,
        .weight = 1000,
        .description_FR = gTropiusPokedexText_FR,
        .description_LG = gTropiusPokedexText_LG,
        .pokemonScale = 283,
        .pokemonOffset = -1,
        .trainerScale = 371,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_CHIMECHO] =
    {
        .categoryName = _("CARILLON"),
        .height = 6,
        .weight = 10,
        .description_FR = gChimechoPokedexText_FR,
        .description_LG = gChimechoPokedexText_LG,
        .pokemonScale = 505,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_ABSOL] =
    {
        .categoryName = _("DESASTRE"),
        .height = 12,
        .weight = 470,
        .description_FR = gAbsolPokedexText_FR,
        .description_LG = gAbsolPokedexText_LG,
        .pokemonScale = 301,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WYNAUT] =
    {
        .categoryName = _("RAVI"),
        .height = 6,
        .weight = 140,
        .description_FR = gWynautPokedexText_FR,
        .description_LG = gWynautPokedexText_LG,
        .pokemonScale = 453,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SNORUNT] =
    {
        .categoryName = _("CAPUCHE"),
        .height = 7,
        .weight = 168,
        .description_FR = gSnoruntPokedexText_FR,
        .description_LG = gSnoruntPokedexText_LG,
        .pokemonScale = 380,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GLALIE] =
    {
        .categoryName = _("FACE"),
        .height = 15,
        .weight = 2565,
        .description_FR = gGlaliePokedexText_FR,
        .description_LG = gGlaliePokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 344,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_SPHEAL] =
    {
        .categoryName = _("CLAP CLAP"),
        .height = 8,
        .weight = 395,
        .description_FR = gSphealPokedexText_FR,
        .description_LG = gSphealPokedexText_LG,
        .pokemonScale = 315,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SEALEO] =
    {
        .categoryName = _("ROULE BOULE"),
        .height = 11,
        .weight = 876,
        .description_FR = gSealeoPokedexText_FR,
        .description_LG = gSealeoPokedexText_LG,
        .pokemonScale = 338,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_WALREIN] =
    {
        .categoryName = _("BRISE GLACE"),
        .height = 14,
        .weight = 1506,
        .description_FR = gWalreinPokedexText_FR,
        .description_LG = gWalreinPokedexText_LG,
        .pokemonScale = 305,
        .pokemonOffset = 2,
        .trainerScale = 277,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLAMPERL] =
    {
        .categoryName = _("BIVALVE"),
        .height = 4,
        .weight = 525,
        .description_FR = gClamperlPokedexText_FR,
        .description_LG = gClamperlPokedexText_LG,
        .pokemonScale = 691,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_HUNTAIL] =
    {
        .categoryName = _("ABYSSE"),
        .height = 17,
        .weight = 270,
        .description_FR = gHuntailPokedexText_FR,
        .description_LG = gHuntailPokedexText_LG,
        .pokemonScale = 307,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_GOREBYSS] =
    {
        .categoryName = _("MER DU SUD"),
        .height = 18,
        .weight = 226,
        .description_FR = gGorebyssPokedexText_FR,
        .description_LG = gGorebyssPokedexText_LG,
        .pokemonScale = 278,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_RELICANTH] =
    {
        .categoryName = _("LONGEVITE"),
        .height = 10,
        .weight = 234,
        .description_FR = gRelicanthPokedexText_FR,
        .description_LG = gRelicanthPokedexText_LG,
        .pokemonScale = 316,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LUVDISC] =
    {
        .categoryName = _("RENDEZVOUS"),
        .height = 6,
        .weight = 87,
        .description_FR = gLuvdiscPokedexText_FR,
        .description_LG = gLuvdiscPokedexText_LG,
        .pokemonScale = 371,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_BAGON] =
    {
        .categoryName = _("TETE DE ROC"),
        .height = 6,
        .weight = 421,
        .description_FR = gBagonPokedexText_FR,
        .description_LG = gBagonPokedexText_LG,
        .pokemonScale = 448,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SHELGON] =
    {
        .categoryName = _("ENDURANT"),
        .height = 11,
        .weight = 1105,
        .description_FR = gShelgonPokedexText_FR,
        .description_LG = gShelgonPokedexText_LG,
        .pokemonScale = 311,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_SALAMENCE] =
    {
        .categoryName = _("DRAGON"),
        .height = 15,
        .weight = 1026,
        .description_FR = gSalamencePokedexText_FR,
        .description_LG = gSalamencePokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = 2,
        .trainerScale = 307,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BELDUM] =
    {
        .categoryName = _("BOULEFER"),
        .height = 6,
        .weight = 952,
        .description_FR = gBeldumPokedexText_FR,
        .description_LG = gBeldumPokedexText_LG,
        .pokemonScale = 414,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_METANG] =
    {
        .categoryName = _("PINCEFER"),
        .height = 12,
        .weight = 2025,
        .description_FR = gMetangPokedexText_FR,
        .description_LG = gMetangPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 272,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_METAGROSS] =
    {
        .categoryName = _("PATTEFER"),
        .height = 16,
        .weight = 5500,
        .description_FR = gMetagrossPokedexText_FR,
        .description_LG = gMetagrossPokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 461,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_REGIROCK] =
    {
        .categoryName = _("PIC ROCHEUX"),
        .height = 17,
        .weight = 2300,
        .description_FR = gRegirockPokedexText_FR,
        .description_LG = gRegirockPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 309,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_REGICE] =
    {
        .categoryName = _("ICEBERG"),
        .height = 18,
        .weight = 1750,
        .description_FR = gRegicePokedexText_FR,
        .description_LG = gRegicePokedexText_LG,
        .pokemonScale = 265,
        .pokemonOffset = 0,
        .trainerScale = 317,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_REGISTEEL] =
    {
        .categoryName = _("FER"),
        .height = 19,
        .weight = 2050,
        .description_FR = gRegisteelPokedexText_FR,
        .description_LG = gRegisteelPokedexText_LG,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 359,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_LATIAS] =
    {
        .categoryName = _("EON"),
        .height = 14,
        .weight = 400,
        .description_FR = gLatiasPokedexText_FR,
        .description_LG = gLatiasPokedexText_LG,
        .pokemonScale = 291,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_LATIOS] =
    {
        .categoryName = _("EON"),
        .height = 20,
        .weight = 600,
        .description_FR = gLatiosPokedexText_FR,
        .description_LG = gLatiosPokedexText_LG,
        .pokemonScale = 273,
        .pokemonOffset = 0,
        .trainerScale = 313,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_KYOGRE] =
    {
        .categoryName = _("BASSINMARIN"),
        .height = 45,
        .weight = 3520,
        .description_FR = gKyogrePokedexText_FR,
        .description_LG = gKyogrePokedexText_LG,
        .pokemonScale = 272,
        .pokemonOffset = 1,
        .trainerScale = 639,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_GROUDON] =
    {
        .categoryName = _("CONTINENT"),
        .height = 35,
        .weight = 9500,
        .description_FR = gGroudonPokedexText_FR,
        .description_LG = gGroudonPokedexText_LG,
        .pokemonScale = 276,
        .pokemonOffset = 0,
        .trainerScale = 530,
        .trainerOffset = 12,
    },

    [NATIONAL_DEX_RAYQUAZA] =
    {
        .categoryName = _("CIEUX"),
        .height = 70,
        .weight = 2065,
        .description_FR = gRayquazaPokedexText_FR,
        .description_LG = gRayquazaPokedexText_LG,
        .pokemonScale = 286,
        .pokemonOffset = -1,
        .trainerScale = 483,
        .trainerOffset = 9,
    },

    [NATIONAL_DEX_JIRACHI] =
    {
        .categoryName = _("SOUHAIT"),
        .height = 3,
        .weight = 11,
        .description_FR = gJirachiPokedexText_FR,
        .description_LG = gJirachiPokedexText_LG,
        .pokemonScale = 608,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = -2,
    },

    [NATIONAL_DEX_DEOXYS] =
    {
        .categoryName = _("ADN"),
        .height = 17,
        .weight = 608,
        .description_FR = gDeoxysPokedexText_FR,
        .description_LG = gDeoxysPokedexText_LG,
        .pokemonScale = 293,
        .pokemonOffset = 0,
        .trainerScale = 337,
        .trainerOffset = 2,
    },
};
