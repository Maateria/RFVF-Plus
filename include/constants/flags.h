#ifndef GUARD_CONSTANTS_FLAGS_H
#define GUARD_CONSTANTS_FLAGS_H

#include "constants/trainers.h"

// Temporary Flags
// These temporary flags are are cleared every time a map is loaded. They are used
// for things like shortening an NPCs introduction text if the player already spoke
// to them once.
#define TEMP_FLAGS_START 0x0
#define FLAG_TEMP_1      (TEMP_FLAGS_START + 0x01)
#define FLAG_TEMP_2      (TEMP_FLAGS_START + 0x02)
#define FLAG_TEMP_3      (TEMP_FLAGS_START + 0x03)
#define FLAG_TEMP_4      (TEMP_FLAGS_START + 0x04)
#define FLAG_TEMP_5      (TEMP_FLAGS_START + 0x05)
#define FLAG_TEMP_6      (TEMP_FLAGS_START + 0x06)
#define FLAG_TEMP_7      (TEMP_FLAGS_START + 0x07)
#define FLAG_TEMP_8      (TEMP_FLAGS_START + 0x08)
#define FLAG_TEMP_9      (TEMP_FLAGS_START + 0x09)
#define FLAG_TEMP_A      (TEMP_FLAGS_START + 0x0A)
#define FLAG_TEMP_B      (TEMP_FLAGS_START + 0x0B)
#define FLAG_TEMP_C      (TEMP_FLAGS_START + 0x0C)
#define FLAG_TEMP_D      (TEMP_FLAGS_START + 0x0D)
#define FLAG_TEMP_E      (TEMP_FLAGS_START + 0x0E)
#define FLAG_TEMP_F      (TEMP_FLAGS_START + 0x0F)
#define FLAG_TEMP_10     (TEMP_FLAGS_START + 0x10)

// Used for obstacles (e.g. cut trees and rock smash rocks)
#define FLAG_TEMP_11     (TEMP_FLAGS_START + 0x11)
#define FLAG_TEMP_12     (TEMP_FLAGS_START + 0x12)
#define FLAG_TEMP_13     (TEMP_FLAGS_START + 0x13)
#define FLAG_TEMP_14     (TEMP_FLAGS_START + 0x14)
#define FLAG_TEMP_15     (TEMP_FLAGS_START + 0x15)
#define FLAG_TEMP_16     (TEMP_FLAGS_START + 0x16)
#define FLAG_TEMP_17     (TEMP_FLAGS_START + 0x17)
#define FLAG_TEMP_18     (TEMP_FLAGS_START + 0x18)
#define FLAG_TEMP_19     (TEMP_FLAGS_START + 0x19)
#define FLAG_TEMP_1A     (TEMP_FLAGS_START + 0x1A)
#define FLAG_TEMP_1B     (TEMP_FLAGS_START + 0x1B)
#define FLAG_TEMP_1C     (TEMP_FLAGS_START + 0x1C)
#define FLAG_TEMP_1D     (TEMP_FLAGS_START + 0x1D)
#define FLAG_TEMP_1E     (TEMP_FLAGS_START + 0x1E)
#define FLAG_TEMP_1F     (TEMP_FLAGS_START + 0x1F)
#define TEMP_FLAGS_END   FLAG_TEMP_1F

#define FLAG_0x020               0x020
#define FLAG_0x021               0x021
#define FLAG_0x022               0x022
#define FLAG_0x023               0x023
#define FLAG_0x024               0x024
#define FLAG_0x025               0x025
#define FLAG_0x026               0x026

// Hide/show flags
#define FLAG_HIDE_AWARD_SCOTT_BATTLE_TOWER                 0x027
#define FLAG_HIDE_BULBASAUR_BALL                           0x028
#define FLAG_HIDE_SQUIRTLE_BALL                            0x029
#define FLAG_HIDE_CHARMANDER_BALL                          0x02A
#define FLAG_HIDE_OAK_IN_HIS_LAB                           0x02B
#define FLAG_HIDE_OAK_IN_PALLET_TOWN                       0x02C
#define FLAG_HIDE_RIVAL_IN_LAB                             0x02D
#define FLAG_HIDE_PEWTER_CITY_GYM_GUIDE                    0x02E
#define FLAG_HIDE_DOME_FOSSIL                              0x02F
#define FLAG_HIDE_HELIX_FOSSIL                             0x030
#define FLAG_HIDE_NUGGET_BRIDGE_ROCKET                     0x031
#define FLAG_HIDE_BILL_CLEFAIRY                            0x032
#define FLAG_HIDE_BILL_HUMAN_SEA_COTTAGE                   0x033
#define FLAG_HIDE_TOWER_FUJI                               0x034
#define FLAG_HIDE_POKEHOUSE_FUJI                           0x035
#define FLAG_HIDE_LIFT_KEY                                 0x036
#define FLAG_HIDE_SILPH_SCOPE                              0x037
#define FLAG_HIDE_HIDEOUT_GIOVANNI                         0x038
#define FLAG_HIDE_TOWN_MAP                                 0x039
#define FLAG_HIDE_POKEDEX                                  0x03A
#define FLAG_HIDE_CERULEAN_ROCKET                          0x03B
#define FLAG_HIDE_CERULEAN_RIVAL                           0x03C
#define FLAG_HIDE_SS_ANNE_RIVAL                            0x03D
#define FLAG_HIDE_SAFFRON_ROCKETS                          0x03E
#define FLAG_HIDE_SAFFRON_CIVILIANS                        0x03F
#define FLAG_HIDE_SEAFOAM_1F_BOULDER_1                     0x040
#define FLAG_HIDE_SEAFOAM_1F_BOULDER_2                     0x041
#define FLAG_HIDE_SEAFOAM_B1F_BOULDER_1                    0x042
#define FLAG_HIDE_SEAFOAM_B1F_BOULDER_2                    0x043
#define FLAG_HIDE_SEAFOAM_B2F_BOULDER_1                    0x044
#define FLAG_HIDE_SEAFOAM_B2F_BOULDER_2                    0x045
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_1                    0x046
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_2                    0x047
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_3                    0x048
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_4                    0x049
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_5                    0x04A
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_6                    0x04B
#define FLAG_HIDE_SEAFOAM_B4F_BOULDER_1                    0x04C
#define FLAG_HIDE_SEAFOAM_B4F_BOULDER_2                    0x04D
#define FLAG_HIDE_SILPH_RIVAL                              0x04E
#define FLAG_HIDE_ROUTE_22_RIVAL                           0x04F
#define FLAG_HIDE_PEWTER_MUSEUM_GUIDE                      0x050
#define FLAG_HIDE_TOWER_RIVAL                              0x051
#define FLAG_HIDE_MOLTRES                                  0x052
#define FLAG_HIDE_SILPH_ROCKETS                            0x053
#define FLAG_HIDE_ROUTE_12_SNORLAX                         0x054
#define FLAG_HIDE_VIRIDIAN_GIOVANNI                        0x055
#define FLAG_HIDE_OLD_AMBER                                0x056
#define FLAG_HIDE_EEVEE_BALL                               0x057
#define FLAG_HIDE_VICTORY_ROAD_2F_BOULDER                  0x058
#define FLAG_HIDE_VICTORY_ROAD_3F_BOULDER                  0x059
#define FLAG_HIDE_OAK_IN_CHAMP_ROOM                        0x05A
#define FLAG_HIDE_GAME_CORNER_ROCKET                       0x05B
#define FLAG_HIDE_CERULEAN_CAVE_GUARD                      0x05C
#define FLAG_HIDE_ZAPDOS                                   0x05D
#define FLAG_HIDE_TOWER_ROCKET_1                           0x05E
#define FLAG_HIDE_CELADON_ROCKETS                          0x05F
#define FLAG_HIDE_DOJO_HITMONLEE_BALL                      0x060
#define FLAG_HIDE_DOJO_HITMONCHAN_BALL                     0x061
#define FLAG_HIDE_CINNABAR_BILL                            0x062
#define FLAG_HIDE_UNION_ROOM_PLAYER_1                      0x063
#define FLAG_HIDE_UNION_ROOM_PLAYER_2                      0x064
#define FLAG_HIDE_UNION_ROOM_PLAYER_3                      0x065
#define FLAG_HIDE_UNION_ROOM_PLAYER_4                      0x066
#define FLAG_HIDE_UNION_ROOM_PLAYER_5                      0x067
#define FLAG_HIDE_UNION_ROOM_PLAYER_6                      0x068
#define FLAG_HIDE_UNION_ROOM_PLAYER_7                      0x069
#define FLAG_HIDE_UNION_ROOM_PLAYER_8                      0x06A
#define FLAG_HIDE_CINNABAR_SEAGALLOP                       0x06B
#define FLAG_HIDE_SAFFRON_FAN_CLUB_BLACKBELT               0x06C
#define FLAG_HIDE_SAFFRON_FAN_CLUB_ROCKER                  0x06D
#define FLAG_HIDE_SAFFRON_FAN_CLUB_WOMAN                   0x06E
#define FLAG_HIDE_SAFFRON_FAN_CLUB_BEAUTY                  0x06F
#define FLAG_HIDE_MG_DELIVERYMEN                           0x070
#define FLAG_HIDE_ONE_ISLAND_BILL                          0x071
#define FLAG_HIDE_ONE_ISLAND_POKECENTER_BILL               0x072
#define FLAG_HIDE_ONE_ISLAND_POKECENTER_CELIO              0x073
#define FLAG_HIDE_TWO_ISLAND_GAME_CORNER_BIKER             0x074
#define FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE          0x075
#define FLAG_HIDE_LOSTELLE_IN_HER_HOME                     0x076
#define FLAG_HIDE_LAVENDER_OUTSIDE_FUJI                    0x077
#define FLAG_HIDE_BATTLE_TOWER_OPPONENT                    0x078
#define FLAG_HIDE_THREE_ISLAND_BIKERS                      0x079
#define FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST                 0x07A
#define FLAG_HIDE_TWO_ISLAND_WOMAN                         0x07B
#define FLAG_HIDE_TWO_ISLAND_BEAUTY                        0x07C
#define FLAG_HIDE_TWO_ISLAND_SUPER_NERD                    0x07D
#define FLAG_HIDE_THREE_ISLAND_ANTIBIKERS                  0x07E
#define FLAG_HIDE_SCOTT                                    0x07F
#define FLAG_HIDE_ROUTE_16_SNORLAX                         0x080
#define FLAG_HIDE_MEWTWO                                   0x081
#define FLAG_HIDE_ARTICUNO                                 0x082
#define FLAG_HIDE_TOWER_ROCKET_2                           0x083
#define FLAG_HIDE_TOWER_ROCKET_3                           0x084
#define FLAG_HIDE_POWER_PLANT_ELECTRODE_1                  0x085
#define FLAG_HIDE_POWER_PLANT_ELECTRODE_2                  0x086
#define FLAG_HIDE_SS_ANNE                                  0x087
#define FLAG_HIDE_FIVE_ISLAND_ROCKETS                      0x088
#define FLAG_HIDE_MT_EMBER_EXTERIOR_ROCKETS                0x089
#define FLAG_HIDE_RUBY                                     0x08A
#define FLAG_HIDE_ICEFALL_CAVE_LORELEI                     0x08B
#define FLAG_HIDE_LORELEI_IN_HER_HOUSE                     0x08C
#define FLAG_HIDE_ICEFALL_CAVE_ROCKETS                     0x08D
#define FLAG_HIDE_RUIN_VALLEY_SCIENTIST                    0x08E
#define FLAG_HIDE_SAPPHIRE                                 0x08F
#define FLAG_HIDE_DOTTED_HOLE_SCIENTIST                    0x090
#define FLAG_HIDE_THREE_ISLAND_LONE_BIKER                  0x091
#define FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY            0x092
#define FLAG_HIDE_LOST_CAVE_SELPHY                         0x093
#define FLAG_HIDE_RESORT_GORGEOUS_SELPHY                   0x094
#define FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY            0x095
#define FLAG_HIDE_SELPHYS_BUTLER                           0x096
#define FLAG_HIDE_FOUR_ISLAND_RIVAL                        0x097
#define FLAG_HIDE_SIX_ISLAND_POKECENTER_RIVAL              0x098
#define FLAG_HIDE_DEOXYS                                   0x099
#define FLAG_HIDE_BIRTH_ISLAND_METEORITE                   0x09A
#define FLAG_HIDE_LUGIA                                    0x09B
#define FLAG_HIDE_HO_OH                                    0x09C
#define FLAG_HIDE_POSTGAME_GOSSIPERS                       0x09D
#define FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS              0x09E
#define FLAG_HIDE_FAME_CHECKER_KOGA_JOURNAL                0x09F
#define FLAG_HIDE_FAME_CHECKER_LT_SURGE_JOURNAL            0x0A0
#define FLAG_HIDE_VERMILION_CITY_OAKS_AIDE                 0x0A1
#define FLAG_HIDE_CINNABAR_POKECENTER_BILL                 0x0A2
#define FLAG_HIDE_CREDITS_RIVAL                            0x0A3
#define FLAG_HIDE_CREDITS_OAK                              0x0A4
#define FLAG_HIDE_LORELEI_HOUSE_MEOWTH_DOLL                0x0A5
#define FLAG_HIDE_LORELEI_HOUSE_CHANSEY_DOLL               0x0A6
#define FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_F_DOLL            0x0A7
#define FLAG_HIDE_LORELEI_HOUSE_JIGGLYPUFF_DOLL            0x0A8
#define FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_M_DOLL            0x0A9
#define FLAG_HIDE_LORELEIS_HOUSE_FEAROW_DOLL               0x0AA
#define FLAG_HIDE_LORELEIS_HOUSE_PIDGEOT_DOLL              0x0AB
#define FLAG_HIDE_LORELEIS_HOUSE_LAPRAS_DOLL               0x0AC
#define FLAG_HIDE_MISC_KANTO_ROCKETS                       0x0AD
#define FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS 0x0AE

// Cut Trees
#define FLAG_VIRIDIAN_CITY_NORTH_CUT_TREE     0x0AF
#define FLAG_VIRIDIAN_CITY_SOUTH_CUT_TREE     0x0B0
#define FLAG_ROUTE_2_CUT_TREE_1               0x0B1
#define FLAG_ROUTE_2_CUT_TREE_2               0x0B2
#define FLAG_ROUTE_2_CUT_TREE_3               0x0B3
#define FLAG_ROUTE_2_CUT_TREE_4               0x0B4
#define FLAG_PEWTER_CITY_CUT_TREE             0x0B5
#define FLAG_CERULEAN_CITY_CUT_TREE           0x0B6
#define FLAG_ROUTE_25_CUT_TREE                0x0B7
#define FLAG_VERMILION_CITY_CUT_TREE          0x0B8
#define FLAG_ROUTE_10_CUT_TREE_1              0x0B9
#define FLAG_ROUTE_10_CUT_TREE_2              0x0BA
#define FLAG_ROUTE_10_CUT_TREE_3              0x0BB
#define FLAG_ROUTE_10_CUT_TREE_4              0x0BC
#define FLAG_ROUTE_8_CUT_TREE_1               0x0BD
#define FLAG_ROUTE_8_CUT_TREE_2               0x0BE
#define FLAG_CELADON_CITY_NORTH_CUT_TREE      0x0BF
#define FLAG_CELADON_CITY_SOUTH_CUT_TREE      0x0C0
#define FLAG_ROUTE_16_CUT_TREE                0x0C1
#define FLAG_ROUTE_12_CUT_TREE_1              0x0C2
#define FLAG_ROUTE_12_CUT_TREE_2              0x0C3
#define FLAG_ROUTE_13_CUT_TREE                0x0C4
#define FLAG_ROUTE_14_CUT_TREE_1              0x0C5
#define FLAG_ROUTE_14_CUT_TREE_2              0x0C6
#define FLAG_ROUTE_14_CUT_TREE_3              0x0C7
#define FLAG_FUCHSIA_CITY_CUT_TREE_1          0x0C8
#define FLAG_FUCHSIA_CITY_CUT_TREE_2          0x0C9
#define FLAG_FUCHSIA_CITY_CUT_TREE_3          0x0CA
#define FLAG_FUCHSIA_CITY_CUT_TREE_4          0x0CB
#define FLAG_TWO_ISLAND_CUT_TREE              0x0CC
#define FLAG_THREE_ISLAND_CUT_TREE            0x0CD
#define FLAG_BOND_BRIDGE_CUT_TREE_1           0x0CE
#define FLAG_BOND_BRIDGE_CUT_TREE_2           0x0CF
#define FLAG_FIVE_ISLE_MEADOW_CUT_TREE_1      0x0D0
#define FLAG_FIVE_ISLE_MEADOW_CUT_TREE_2      0x0D1
#define FLAG_BERRY_FOREST_CUT_TREE_1          0x0D2
#define FLAG_BERRY_FOREST_CUT_TREE_2          0x0D3
#define FLAG_BERRY_FOREST_CUT_TREE_3          0x0D4
#define FLAG_BERRY_FOREST_CUT_TREE_4          0x0D5
#define FLAG_BERRY_FOREST_CUT_TREE_5          0x0D6
#define FLAG_BERRY_FOREST_CUT_TREE_6          0x0D7
#define FLAG_BERRY_FOREST_CUT_TREE_7          0x0D8
#define FLAG_BERRY_FOREST_CUT_TREE_8          0x0D9
#define FLAG_BERRY_FOREST_CUT_TREE_9          0x0DA
#define FLAG_BERRY_FOREST_CUT_TREE_10         0x0DB
#define FLAG_ROUTE_9_CUT_TREE                 0x0DC //forgot this one
#define FLAG_AUTO_RUN_TOGGLED                 0x0DD
#define FLAG_AUTO_RUN_EXPLAINED               0x0DE
#define FLAG_DONT_ADD_TMS                     0x0DF //Needed so the Teachy TV doesn't add TMs
#define FLAG_CELADON_GYM_LEFT_CUT_TREE        0x0E0 //forgot these...
#define FLAG_CELADON_GYM_BOTTOM_CUT_TREE      0x0E1 // ^
#define FLAG_CELADON_GYM_RIGHT_CUT_TREE       0x0E2 // ^
#define FLAG_BIKE_GEAR                        0x0E3 // Swaps between FRLG bike speed and Mach Bike speed

// Unused?
#define FLAG_HIDE_NATIONAL_DEX_AIDE           0x0E4
#define FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO   0x0E5
#define FLAG_DEFEATED_SUDOWOODO               0x0E6
#define FLAG_CAUGHT_SUDOWOODO                 0x0E7
#define FLAG_GIVEN_CORSOLA_EGG                0x0E8
#define FLAG_MASTER_TRAINER_BATTLE            0x0E9
#define FLAG_HIDE_MASTER_TRAINERS             0x0EA
#define FLAG_ITEM_ROUTE_121_CARBOS               0x0EB
#define FLAG_ITEM_ROUTE_121_REVIVE               0x0EC
#define FLAG_ITEM_ROUTE_121_ZINC                 0x0ED
#define FLAG_HIDDEN_ITEM_ROUTE_121_HP_UP         0x0EE
#define FLAG_HIDDEN_ITEM_ROUTE_121_NUGGET        0x0EF
#define FLAG_HIDDEN_ITEM_ROUTE_121_FULL_HEAL     0x0F0
#define FLAG_HIDDEN_ITEM_ROUTE_121_MAX_REVIVE    0x0F1
#define FLAG_ITEM_ROUTE_123_CALCIUM              0x0F2
#define FLAG_ITEM_ROUTE_123_ULTRA_BALL           0x0F3
#define FLAG_ITEM_ROUTE_123_ELIXIR               0x0F4
#define FLAG_ITEM_ROUTE_123_PP_UP                0x0F5
#define FLAG_ITEM_ROUTE_123_REVIVAL_HERB         0x0F6
#define FLAG_HIDDEN_ITEM_ROUTE_123_SUPER_REPEL   0x0F7
#define FLAG_HIDDEN_ITEM_ROUTE_123_REVIVE        0x0F8
#define FLAG_HIDDEN_ITEM_ROUTE_123_HYPER_POTION  0x0F9
#define FLAG_HIDDEN_ITEM_ROUTE_123_PP_UP         0x0FA
#define FLAG_HIDDEN_ITEM_ROUTE_123_RARE_CANDY    0x0FB
#define FLAG_ITEM_ROUTE_120_NUGGET               0x0FC
#define FLAG_ITEM_ROUTE_120_FULL_HEAL            0x0FD
#define FLAG_ITEM_ROUTE_120_NEST_BALL            0x0FE
#define FLAG_ITEM_ROUTE_120_HYPER_POTION         0x0FF
#define FLAG_ITEM_ROUTE_120_REVIVE               0x100
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_1  0x101
#define FLAG_HIDDEN_ITEM_ROUTE_120_REVIVE        0x102
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_2  0x103
#define FLAG_HIDDEN_ITEM_ROUTE_120_ZINC          0x104
#define FLAG_ITEM_ROUTE_119_SUPER_REPEL          0x105
#define FLAG_ITEM_ROUTE_119_ZINC                 0x106
#define FLAG_ITEM_ROUTE_119_ELIXIR_1             0x107
#define FLAG_ITEM_ROUTE_119_LEAF_STONE           0x108
#define FLAG_ITEM_ROUTE_119_RARE_CANDY           0x109
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_1       0x10A
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_2       0x10B
#define FLAG_ITEM_ROUTE_119_NUGGET               0x10C
#define FLAG_ITEM_ROUTE_119_ELIXIR_2             0x10D
#define FLAG_HIDDEN_ITEM_ROUTE_119_CALCIUM       0x10E
#define FLAG_HIDDEN_ITEM_ROUTE_119_ULTRA_BALL    0x10F
#define FLAG_HIDDEN_ITEM_ROUTE_119_FULL_HEAL     0x110
#define FLAG_HIDDEN_ITEM_ROUTE_119_MAX_ETHER     0x111
#define FLAG_ITEM_ROUTE_132_RARE_CANDY           0x112
#define FLAG_ITEM_ROUTE_132_PROTEIN              0x113
#define FLAG_ITEM_ROUTE_133_BIG_PEARL            0x114
#define FLAG_ITEM_ROUTE_133_STAR_PIECE           0x115
#define FLAG_ITEM_ROUTE_133_MAX_REVIVE           0x116
#define FLAG_ITEM_ROUTE_134_CARBOS               0x117
#define FLAG_ITEM_ROUTE_134_STAR_PIECE           0x118
#define FLAG_ITEM_ROUTE_113_MAX_ETHER            0x119
#define FLAG_ITEM_ROUTE_113_SUPER_REPEL          0x11A
#define FLAG_ITEM_ROUTE_113_HYPER_POTION         0x11B
#define FLAG_HIDDEN_ITEM_ROUTE_113_ETHER         0x11C
#define FLAG_HIDDEN_ITEM_ROUTE_113_TM_DOUBLE_TEAM 0x11D
#define FLAG_HIDDEN_ITEM_ROUTE_113_NUGGET        0x11E
#define FLAG_HIDDEN_ITEM_FALLARBOR_TOWN_NUGGET   0x11F
#define FLAG_ITEM_ROUTE_114_RARE_CANDY           0x120
#define FLAG_ITEM_ROUTE_114_PROTEIN              0x121
#define FLAG_ITEM_ROUTE_114_ENERGY_POWDER        0x122
#define FLAG_HIDDEN_ITEM_ROUTE_114_CARBOS        0x123
#define FLAG_HIDDEN_ITEM_ROUTE_114_REVIVE        0x124
#define FLAG_ITEM_ROUTE_115_SUPER_POTION         0x125
#define FLAG_ITEM_ROUTE_115_TM_FOCUS_PUNCH       0x126
#define FLAG_ITEM_ROUTE_115_IRON                 0x127
#define FLAG_ITEM_ROUTE_115_GREAT_BALL           0x128
#define FLAG_ITEM_ROUTE_115_PP_UP                0x129
#define FLAG_ITEM_ROUTE_115_HEAL_POWDER          0x12A
#define FLAG_HIDDEN_ITEM_ROUTE_115_HEART_SCALE   0x12B
#define FLAG_ITEM_RUSTBORO_CITY_X_DEFEND         0x12C
#define FLAG_ITEM_ROUTE_116_ETHER                0x12D
#define FLAG_ITEM_ROUTE_116_REPEL                0x12E
#define FLAG_ITEM_ROUTE_116_HP_UP                0x12F
#define FLAG_ITEM_ROUTE_116_X_SPECIAL            0x130
#define FLAG_ITEM_ROUTE_116_POTION               0x131
#define FLAG_HIDDEN_ITEM_ROUTE_116_SUPER_POTION  0x132
#define FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES 0x133
#define FLAG_ITEM_ROUTE_104_PP_UP                0x134
#define FLAG_ITEM_ROUTE_104_POKE_BALL            0x135
#define FLAG_ITEM_ROUTE_104_X_ACCURACY           0x136
#define FLAG_ITEM_ROUTE_104_POTION               0x137
#define FLAG_HIDDEN_ITEM_ROUTE_104_SUPER_POTION  0x138
#define FLAG_HIDDEN_ITEM_ROUTE_104_POKE_BALL     0x139
#define FLAG_HIDDEN_ITEM_ROUTE_104_POTION        0x13A
#define FLAG_HIDDEN_ITEM_ROUTE_104_ANTIDOTE      0x13B
#define FLAG_HIDDEN_ITEM_ROUTE_104_HEART_SCALE   0x13C
#define FLAG_ITEM_ROUTE_105_IRON                 0x13D
#define FLAG_HIDDEN_ITEM_ROUTE_105_HEART_SCALE   0x13E
#define FLAG_HIDDEN_ITEM_ROUTE_105_BIG_PEARL     0x13F
#define FLAG_ITEM_ROUTE_106_PROTEIN              0x140
#define FLAG_HIDDEN_ITEM_ROUTE_106_POKE_BALL     0x141
#define FLAG_HIDDEN_ITEM_ROUTE_106_STARDUST      0x142
#define FLAG_HIDDEN_ITEM_ROUTE_106_HEART_SCALE   0x143
#define FLAG_ITEM_PETALBURG_CITY_MAX_REVIVE      0x144
#define FLAG_ITEM_PETALBURG_CITY_ETHER           0x145
#define FLAG_HIDDEN_ITEM_PETALBURG_CITY_RARE_CANDY 0x146
#define FLAG_ITEM_ROUTE_102_POTION               0x147
#define FLAG_ITEM_ROUTE_103_GUARD_SPEC           0x148
#define FLAG_ITEM_ROUTE_103_PP_UP                0x149
#define FLAG_ITEM_ROUTE_118_HYPER_POTION         0x14A
#define FLAG_HIDDEN_ITEM_ROUTE_118_IRON          0x14B
#define FLAG_HIDDEN_ITEM_ROUTE_118_HEART_SCALE   0x14C
#define FLAG_ITEM_ROUTE_124_RED_SHARD            0x14D
#define FLAG_ITEM_ROUTE_124_BLUE_SHARD           0x14E
#define FLAG_ITEM_ROUTE_124_YELLOW_SHARD         0x14F
#define FLAG_ITEM_MOSSDEEP_CITY_NET_BALL         0x150
#define FLAG_ITEM_ROUTE_125_BIG_PEARL            0x151
#define FLAG_ITEM_ROUTE_127_ZINC                 0x152
#define FLAG_ITEM_ROUTE_127_CARBOS               0x153

// Item ball hide/show
#define FLAG_HIDE_ROUTE2_ETHER                                  0x154
#define FLAG_HIDE_ROUTE2_PARALYZE_HEAL                          0x155
#define FLAG_HIDE_VIRIDIAN_FOREST_POKE_BALL                     0x156
#define FLAG_HIDE_VIRIDIAN_FOREST_ANTIDOTE                      0x157
#define FLAG_HIDE_VIRIDIAN_FOREST_POTION                        0x158
#define FLAG_HIDE_MT_MOON_1F_PARALYZE_HEAL                      0x159
#define FLAG_HIDE_MT_MOON_1F_TM09                               0x15A
#define FLAG_HIDE_MT_MOON_1F_POTION                             0x15B
#define FLAG_HIDE_MT_MOON_1F_RARE_CANDY                         0x15C
#define FLAG_HIDE_MT_MOON_1F_ESCAPE_ROPE                        0x15D
#define FLAG_HIDE_MT_MOON_1F_MOON_STONE                         0x15E
#define FLAG_HIDE_MT_MOON_B2F_STAR_PIECE                        0x15F
#define FLAG_HIDE_MT_MOON_B2F_TM46                              0x160
#define FLAG_HIDE_ROUTE4_TM05                                   0x161
#define FLAG_HIDE_ROUTE24_TM45                                  0x162
#define FLAG_HIDE_ROUTE25_TM43                                  0x163
#define FLAG_HIDE_SSANNE_1F_ROOM2_TM31                          0x164
#define FLAG_HIDE_SSANNE_2F_ROOM2_STARDUST                      0x165
#define FLAG_HIDE_SSANNE_2F_ROOM4_X_ATTACK                      0x166
#define FLAG_HIDE_SSANNE_B1F_ROOM2_TM44                         0x167
#define FLAG_HIDE_SSANNE_B1F_ROOM3_ETHER                        0x168
#define FLAG_HIDE_SSANNE_B1F_ROOM5_SUPER_POTION                 0x169
#define FLAG_HIDE_SSANNE_KITCHEN_GREAT_BALL                     0x16A
#define FLAG_HIDE_ROUTE9_TM40                                   0x16B
#define FLAG_HIDE_ROCKET_HIDEOUT_B1F_ESCAPE_ROPE                0x16C
#define FLAG_HIDE_ROCKET_HIDEOUT_B1F_HYPER_POTION               0x16D
#define FLAG_HIDE_ROCKET_HIDEOUT_B2F_X_SPEED                    0x16E
#define FLAG_HIDE_ROCKET_HIDEOUT_B2F_MOON_STONE                 0x16F
#define FLAG_HIDE_ROCKET_HIDEOUT_B2F_TM12                       0x170
#define FLAG_HIDE_ROCKET_HIDEOUT_B2F_SUPER_POTION               0x171
#define FLAG_HIDE_ROCKET_HIDEOUT_B3F_RARE_CANDY                 0x172
#define FLAG_HIDE_ROCKET_HIDEOUT_B3F_TM21                       0x173
#define FLAG_HIDE_ROCKET_HIDEOUT_B4F_TM49                       0x174
#define FLAG_HIDE_ROCKET_HIDEOUT_B4F_MAX_ETHER                  0x175
#define FLAG_HIDE_ROCKET_HIDEOUT_B4F_CALCIUM                    0x176
#define FLAG_HIDE_POKEMON_TOWER_3F_ESCAPE_ROPE                  0x177
#define FLAG_HIDE_POKEMON_TOWER_4F_ELIXIR                       0x178
#define FLAG_HIDE_POKEMON_TOWER_4F_AWAKENING                    0x179
#define FLAG_HIDE_POKEMON_TOWER_4F_GREAT_BALL                   0x17A
#define FLAG_HIDE_POKEMON_TOWER_5F_NUGGET                       0x17B
#define FLAG_HIDE_POKEMON_TOWER_6F_RARE_CANDY                   0x17C
#define FLAG_HIDE_POKEMON_TOWER_6F_X_ACCURACY                   0x17D
#define FLAG_HIDE_ROUTE12_TM48                                  0x17E
#define FLAG_HIDE_ROUTE12_IRON                                  0x17F
#define FLAG_HIDE_ROUTE15_TM18                                  0x180
#define FLAG_HIDE_SAFARI_ZONE_CENTER_NUGGET                     0x181
#define FLAG_HIDE_SAFARI_ZONE_EAST_MAX_POTION                   0x182
#define FLAG_HIDE_SAFARI_ZONE_EAST_FULL_RESTORE                 0x183
#define FLAG_HIDE_SAFARI_ZONE_EAST_TM11                         0x184
#define FLAG_HIDE_SAFARI_ZONE_EAST_LEAF_STONE                   0x185
#define FLAG_HIDE_SAFARI_ZONE_NORTH_PROTEIN                     0x186
#define FLAG_HIDE_SAFARI_ZONE_NORTH_TM47                        0x187
#define FLAG_HIDE_SAFARI_ZONE_WEST_TM32                         0x188
#define FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH                   0x189
#define FLAG_HIDE_SAFARI_ZONE_WEST_MAX_POTION                   0x18A
#define FLAG_HIDE_SAFARI_ZONE_WEST_MAX_REVIVE                   0x18B
#define FLAG_HIDE_SILPH_CO_3F_HYPER_POTION                      0x18C
#define FLAG_HIDE_SILPH_CO_4F_MAX_REVIVE                        0x18D
#define FLAG_HIDE_SILPH_CO_4F_ESCAPE_ROPE                       0x18E
#define FLAG_HIDE_SILPH_CO_4F_FULL_HEAL                         0x18F
#define FLAG_HIDE_SILPH_CO_5F_PROTEIN                           0x190
#define FLAG_HIDE_SILPH_CO_5F_TM01                              0x191
#define FLAG_HIDE_SILPH_CO_5F_CARD_KEY                          0x192
#define FLAG_HIDE_SILPH_CO_6F_HP_UP                             0x193
#define FLAG_HIDE_SILPH_CO_6F_X_SPECIAL                         0x194
#define FLAG_HIDE_SILPH_CO_7F_CALCIUM                           0x195
#define FLAG_HIDE_SILPH_CO_7F_TM08                              0x196
#define FLAG_HIDE_SILPH_CO_10F_CARBOS                           0x197
#define FLAG_HIDE_SILPH_CO_10F_ULTRA_BALL                       0x198
#define FLAG_HIDE_SILPH_CO_10F_RARE_CANDY                       0x199
#define FLAG_HIDE_POWER_PLANT_MAX_POTION                        0x19A
#define FLAG_HIDE_POWER_PLANT_TM17                              0x19B
#define FLAG_HIDE_POWER_PLANT_TM25                              0x19C
#define FLAG_HIDE_POWER_PLANT_THUNDER_STONE                     0x19D
#define FLAG_HIDE_POWER_PLANT_ELIXIR                            0x19E
#define FLAG_HIDE_POKEMON_MANSION_1F_CARBOS                     0x19F
#define FLAG_HIDE_POKEMON_MANSION_1F_ESCAPE_ROPE                0x1A0
#define FLAG_HIDE_POKEMON_MANSION_2F_CALCIUM                    0x1A1
#define FLAG_HIDE_POKEMON_MANSION_3F_MAX_POTION                 0x1A2
#define FLAG_HIDE_POKEMON_MANSION_3F_IRON                       0x1A3
#define FLAG_HIDE_POKEMON_MANSION_B1F_TM14                      0x1A4
#define FLAG_HIDE_POKEMON_MANSION_B1F_FULL_RESTORE              0x1A5
#define FLAG_HIDE_SAFARI_ZONE_NORTHWEST_SUN_STONE               0x1A6 //New
#define FLAG_HIDE_POKEMON_MANSION_B1F_TM22                      0x1A7
#define FLAG_HIDE_POKEMON_MANSION_B1F_SECRET_KEY                0x1A8
#define FLAG_HIDE_VICTORY_ROAD_1F_RARE_CANDY                    0x1A9
#define FLAG_HIDE_VICTORY_ROAD_1F_TM02                          0x1AA
#define FLAG_HIDE_VICTORY_ROAD_2F_GUARD_SPEC                    0x1AB
#define FLAG_HIDE_VICTORY_ROAD_2F_TM07                          0x1AC
#define FLAG_HIDE_VICTORY_ROAD_2F_FULL_HEAL                     0x1AD
#define FLAG_HIDE_VICTORY_ROAD_2F_TM37                          0x1AE
#define FLAG_HIDE_VICTORY_ROAD_3F_MAX_REVIVE                    0x1AF
#define FLAG_HIDE_VICTORY_ROAD_3F_TM50                          0x1B0
#define FLAG_HIDE_CERULEAN_CAVE_1F_MAX_ELIXIR                   0x1B1
#define FLAG_HIDE_CERULEAN_CAVE_1F_NUGGET                       0x1B2
#define FLAG_HIDE_CERULEAN_CAVE_1F_FULL_RESTORE                 0x1B3
#define FLAG_HIDE_CERULEAN_CAVE_2F_FULL_RESTORE                 0x1B4
#define FLAG_HIDE_CERULEAN_CAVE_2F_PP_UP                        0x1B5
#define FLAG_HIDE_CERULEAN_CAVE_2F_ULTRA_BALL                   0x1B6
#define FLAG_HIDE_CERULEAN_CAVE_B1F_MAX_REVIVE                  0x1B7
#define FLAG_HIDE_CERULEAN_CAVE_B1F_ULTRA_BALL                  0x1B8
#define FLAG_HIDE_FUCHSIA_CITY_WARDENS_HOUSE_RARE_CANDY         0x1B9
#define FLAG_HIDE_TWO_ISLAND_REVIVE                             0x1BA
#define FLAG_HIDE_THREE_ISLAND_ZINC                             0x1BB
#define FLAG_HIDE_SAFARI_ZONE_NORTHWEST_RARE_CANDY              0x1BC //New
#define FLAG_HIDE_SAFARI_ZONE_NORTHWEST_KINGS_ROCK              0x1BD //New
#define FLAG_HIDE_VIRIDIAN_FOREST_POTION_2                      0x1BE
#define FLAG_HIDE_MT_MOON_B2F_REVIVE                            0x1BF
#define FLAG_HIDE_MT_MOON_B2F_ANTIDOTE                          0x1C0
#define FLAG_HIDE_ROUTE11_X_DEFEND                              0x1C1
#define FLAG_HIDE_ROUTE9_BURN_HEAL                              0x1C2
#define FLAG_HIDE_ROCK_TUNNEL_1F_REPEL                          0x1C3
#define FLAG_HIDE_ROCK_TUNNEL_1F_PEARL                          0x1C4
#define FLAG_HIDE_ROCK_TUNNEL_1F_ESCAPE_ROPE                    0x1C5
#define FLAG_HIDE_ROCK_TUNNEL_B1F_REVIVE                        0x1C6
#define FLAG_HIDE_ROCK_TUNNEL_B1F_MAX_ETHER                     0x1C7
#define FLAG_HIDE_SILPH_CO_8F_IRON                              0x1C8
#define FLAG_HIDE_SILPH_CO_11F_ZINC                             0x1C9
#define FLAG_HIDE_POKEMON_MANSION_1F_PROTEIN                    0x1CA
#define FLAG_HIDE_POKEMON_MANSION_2F_ZINC                       0x1CB
#define FLAG_HIDE_POKEMON_MANSION_2F_HP_UP                      0x1CC
#define FLAG_HIDE_VIRIDIAN_CITY_POTION                          0x1CD
#define FLAG_HIDE_ROUTE11_GREAT_BALL                            0x1CE
#define FLAG_HIDE_ROUTE11_AWAKENING                             0x1CF
#define FLAG_HIDE_POKEMON_TOWER_5F_CLEANSE_TAG                  0x1D0
#define FLAG_HIDE_CELADON_CITY_ETHER                            0x1D1
#define FLAG_HIDE_ROCKET_HIDEOUT_B3F_BLACK_GLASSES              0x1D2
#define FLAG_HIDE_SAFARI_ZONE_NORTH_QUICK_CLAW                  0x1D3
#define FLAG_HIDE_SEAFOAM_ISLANDS_1F_ICE_HEAL                   0x1D4
#define FLAG_HIDE_SEAFOAM_ISLANDS_B1F_WATER_STONE               0x1D5
#define FLAG_HIDE_SEAFOAM_ISLANDS_B1F_REVIVE                    0x1D6
#define FLAG_HIDE_SEAFOAM_ISLANDS_B2F_BIG_PEARL                 0x1D7
#define FLAG_HIDE_SEAFOAM_ISLANDS_B4F_ULTRA_BALL                0x1D8
#define FLAG_HIDE_FOUR_ISLAND_STAR_PIECE                        0x1D9
#define FLAG_HIDE_FOUR_ISLAND_STARDUST                          0x1DA
#define FLAG_HIDE_ONE_ISLAND_KINDLE_ROAD_ETHER                  0x1DB
#define FLAG_HIDE_ONE_ISLAND_KINDLE_ROAD_MAX_REPEL              0x1DC
#define FLAG_HIDE_ONE_ISLAND_KINDLE_ROAD_CARBOS                 0x1DD
#define FLAG_HIDE_FIVE_ISLAND_MEADOW_MAX_POTION                 0x1DE
#define FLAG_HIDE_FIVE_ISLAND_MEADOW_PP_UP                      0x1DF
#define FLAG_HIDE_FIVE_ISLAND_MEMORIAL_PILLAR_METAL_COAT        0x1E0
#define FLAG_HIDE_SIX_ISLAND_OUTCAST_ISLAND_PP_UP               0x1E1
#define FLAG_HIDE_SIX_ISLAND_WATER_PATH_ELIXIR                  0x1E2
#define FLAG_HIDE_SIX_ISLAND_WATER_PATH_DRAGON_SCALE            0x1E3
#define FLAG_HIDE_SIX_ISLAND_RUIN_VALLEY_FULL_RESTORE           0x1E4
#define FLAG_HIDE_SIX_ISLAND_RUIN_VALLEY_HP_UP                  0x1E5
#define FLAG_HIDE_SIX_ISLAND_RUIN_VALLEY_SUN_STONE              0x1E6
#define FLAG_HIDE_SEVEN_ISLAND_SEVAULT_CANYON_KINGS_ROCK        0x1E7
#define FLAG_HIDE_SEVEN_ISLAND_SEVAULT_CANYON_MAX_ELIXIR        0x1E8
#define FLAG_HIDE_SEVEN_ISLAND_SEVAULT_CANYON_NUGGET            0x1E9
#define FLAG_HIDE_THREE_ISLAND_BERRY_FOREST_MAX_ETHER           0x1EA
#define FLAG_HIDE_THREE_ISLAND_BERRY_FOREST_FULL_HEAL           0x1EB
#define FLAG_HIDE_THREE_ISLAND_BERRY_FOREST_MAX_ELIXIR          0x1EC
#define FLAG_HIDE_MT_EMBER_EXTERIOR_ULTRA_BALL                  0x1ED
#define FLAG_HIDE_MT_EMBER_EXTERIOR_FIRE_STONE                  0x1EE
#define FLAG_HIDE_MT_EMBER_EXTERIOR_DIRE_HIT                    0x1EF
#define FLAG_HIDE_FOUR_ISLAND_ICEFALL_CAVE_1F_ULTRA_BALL        0x1F0
#define FLAG_HIDE_FOUR_ISLAND_ICEFALL_CAVE_1F_HM07              0x1F1
#define FLAG_HIDE_FOUR_ISLAND_ICEFALL_CAVE_B1F_FULL_RESTORE     0x1F2
#define FLAG_HIDE_FOUR_ISLAND_ICEFALL_CAVE_B1F_NEVER_MELT_ICE   0x1F3
#define FLAG_HIDE_FIVE_ISLAND_ROCKET_WAREHOUSE_BIG_PEARL        0x1F4
#define FLAG_HIDE_FIVE_ISLAND_ROCKET_WAREHOUSE_TM36             0x1F5
#define FLAG_HIDE_FIVE_ISLAND_ROCKET_WAREHOUSE_PEARL            0x1F6
#define FLAG_HIDE_FIVE_ISLAND_ROCKET_WAREHOUSE_UP_GRADE         0x1F7
#define FLAG_HIDE_FIVE_ISLAND_LOST_CAVE_ROOM10_SILK_SCARF       0x1F8
#define FLAG_HIDE_FIVE_ISLAND_LOST_CAVE_ROOM11_LAX_INCENSE      0x1F9
#define FLAG_HIDE_FIVE_ISLAND_LOST_CAVE_ROOM12_SEA_INCENSE      0x1FA
#define FLAG_HIDE_FIVE_ISLAND_LOST_CAVE_ROOM13_MAX_REVIVE       0x1FB
#define FLAG_HIDE_FIVE_ISLAND_LOST_CAVE_ROOM14_RARE_CANDY       0x1FC
#define FLAG_HIDE_SEVEN_ISLAND_SEVAULT_CANYON_HOUSE_LUCKY_PUNCH 0x1FD
#define FLAG_HIDE_SILPH_CO_4F_TM41                              0x1FE
#define FLAG_HIDE_SAFARI_ZONE_NORTHWEST_PP_MAX                  0x1FF //New
#define FLAG_HIDE_SAFARI_ZONE_NORTHEAST_MAX_REVIVE              0x200 //New
#define FLAG_HIDE_SAFARI_ZONE_NORTHEAST_WHITE_HERB              0x201 //New
#define FLAG_HIDE_SAFARI_ZONE_NORTHEAST_GLITTER_MAIL            0x202 //New
#define FLAG_HIDE_ARTISAN_CAVE_B1F_HP_UP                        0x203 //New
#define FLAG_HIDE_ARTISAN_CAVE_B1F_CARBOS                       0x204 //New
#define FLAG_HIDE_CELADON_CITY_SUN_STONE                        0x205 //New

// Unused?
#define FLAG_ITEM_ROUTE_127_RARE_CANDY           0x206
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_1 0x207
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_2 0x208
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_3 0x209
#define FLAG_ITEM_ROUTE_126_GREEN_SHARD          0x20A
#define FLAG_ITEM_ROUTE_117_GREAT_BALL           0x20B
#define FLAG_ITEM_ROUTE_117_REVIVE               0x20C
#define FLAG_HIDDEN_ITEM_ROUTE_117_REPEL         0x20D
#define FLAG_ITEM_MAUVILLE_CITY_X_SPEED          0x20E
#define FLAG_ITEM_ROUTE_110_DIRE_HIT             0x20F
#define FLAG_ITEM_ROUTE_110_RARE_CANDY           0x210
#define FLAG_ITEM_ROUTE_110_ELIXIR               0x211
#define FLAG_HIDDEN_ITEM_ROUTE_110_REVIVE        0x212
#define FLAG_HIDDEN_ITEM_ROUTE_110_GREAT_BALL    0x213
#define FLAG_HIDDEN_ITEM_ROUTE_110_POKE_BALL     0x214
#define FLAG_HIDDEN_ITEM_ROUTE_110_FULL_HEAL     0x215
#define FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET      0x216
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_1_ORANGE_MAIL 0x217
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_WAVE_MAIL 0x218
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_HARBOR_MAIL 0x219
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_WOOD_MAIL 0x21A
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_SHADOW_MAIL 0x21B
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_4_MECH_MAIL 0x21C
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL 0x21D
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_7_TROPIC_MAIL 0x21E
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_8_BEAD_MAIL 0x21F
#define FLAG_ITEM_ROUTE_111_TM_SANDSTORM         0x220
#define FLAG_ITEM_ROUTE_111_STARDUST             0x221
#define FLAG_ITEM_ROUTE_111_HP_UP                0x222
#define FLAG_ITEM_ROUTE_111_ELIXIR               0x223
#define FLAG_HIDDEN_ITEM_ROUTE_111_STARDUST      0x224
#define FLAG_HIDDEN_ITEM_ROUTE_111_PROTEIN       0x225
#define FLAG_HIDDEN_ITEM_ROUTE_111_RARE_CANDY    0x226
#define FLAG_ITEM_ROUTE_112_NUGGET               0x227
#define FLAG_HIDDEN_ITEM_LAVARIDGE_TOWN_ICE_HEAL 0x228
#define FLAG_ITEM_ROUTE_108_STAR_PIECE           0x229

#define FLAG_HIDE_LATI                                   0x22A
#define FLAG_SHOWN_EON_TICKET                            0x22B
#define FLAG_DEFEATED_LATIAS                             0x22C
#define FLAG_DEFEATED_LATIOS                             0x22D
#define FLAG_CAUGHT_LATIAS                               0x22E
#define FLAG_CAUGHT_LATIOS                               0x22F

// Story flags
#define STORY_FLAGS_START 0x230
#define FLAG_GOT_POTION_ON_ROUTE_1                       0x230
#define FLAG_GOT_TM34_FROM_SURGE                         0x231
#define FLAG_GOT_FOSSIL_FROM_MT_MOON                     0x232
#define FLAG_HELPED_BILL_IN_SEA_COTTAGE                  0x233
#define FLAG_GOT_SS_TICKET                               0x234
#define FLAG_GOT_SS_TICKET_DUP                           0x235
#define FLAG_GOT_TM42_AT_MEMORIAL_PILLAR                 0x236
#define FLAG_GOT_HM01                                    0x237
#define FLAG_GOT_HM02                                    0x238
#define FLAG_GOT_HM03                                    0x239
#define FLAG_GOT_HM04                                    0x23A
#define FLAG_GOT_HM05                                    0x23B
#define FLAG_RESCUED_MR_FUJI                             0x23C
#define FLAG_GOT_POKE_FLUTE                              0x23D
#define FLAG_MET_DEVON_SPY                               0x23E
#define FLAG_GOT_TM28_FROM_ROCKET                        0x23F
#define FLAG_GOT_OLD_ROD                                 0x240
#define FLAG_GOT_BIKE_VOUCHER                            0x241
#define FLAG_DID_NINO_TRADE                              0x242
#define FLAG_GOT_COIN_CASE                               0x243
#define FLAG_GOT_GOOD_ROD                                0x244
#define FLAG_GOT_TM29_FROM_MR_PSYCHIC                    0x245
#define FLAG_GOT_LAPRAS_FROM_SILPH                       0x246
#define FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL       0x247
#define FLAG_DID_MIMIEN_TRADE                            0x248
#define FLAG_BOUGHT_MAGIKARP                             0x249
#define FLAG_DID_ZYNX_TRADE                              0x24A
#define FLAG_DID_MS_NIDO_TRADE                           0x24B
#define FLAG_DID_MR_NIDO_TRADE                           0x24C
#define FLAG_DID_CH_DING_TRADE                           0x24D
#define FLAG_GOT_TM38_FROM_BLAINE                        0x24E
#define FLAG_OAK_SKIP_22_RIVAL_CHECK                     0x24F
#define FLAG_GOT_MASTER_BALL_FROM_SILPH                  0x250
#define FLAG_DID_NINA_TRADE                              0x251
#define FLAG_GOT_ITEMFINDER                              0x252
#define FLAG_WOKE_UP_ROUTE_12_SNORLAX                    0x253
#define FLAG_GOT_TM39_FROM_BROCK                         0x254
#define FLAG_GOT_SUPER_ROD                               0x255
#define FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE                0x256
#define FLAG_DID_MARC_TRADE                              0x257
#define FLAG_BEAT_RIVAL_IN_OAKS_LAB                      0x258
#define FLAG_GOT_TM06_FROM_KOGA                          0x259
#define FLAG_WOKE_UP_ROUTE_16_SNORLAX                    0x25A //New
#define FLAG_GOT_TM27                                    0x25B
#define FLAG_ROUTE_12_SNORLAX_RETURNED_TO_MOUNTAINS      0x25C //New
#define FLAG_ROUTE_16_SNORLAX_RETURNED_TO_MOUNTAINS      0x25D //New
#define FLAG_GOT_OLD_AMBER                               0x25E
#define FLAG_MEWTWO_FLEW_AWAY                            0x25F //New
#define FLAG_ARTICUNO_FLEW_AWAY                          0x260 //New
#define FLAG_ZAPDOS_FLEW_AWAY                            0x261 //New
#define FLAG_MOLTRES_FLEW_AWAY                           0x262 //New
#define FLAG_GOT_EEVEE                                   0x263
#define FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES           0x264
#define FLAG_CINNABAR_GYM_QUIZ_1                         0x265
#define FLAG_PENDING_DAYCARE_EGG                         0x266
#define FLAG_CINNABAR_GYM_QUIZ_2                         0x267
#define FLAG_CINNABAR_GYM_QUIZ_3                         0x268
#define FLAG_CINNABAR_GYM_QUIZ_4                         0x269
#define FLAG_CINNABAR_GYM_QUIZ_5                         0x26A
#define FLAG_CINNABAR_GYM_QUIZ_6                         0x26B
#define FLAG_POKEMON_MANSION_SWITCH_STATE                0x26C
#define FLAG_OPENED_ROCKET_HIDEOUT                       0x26D
#define FLAG_GOT_10_COINS_FROM_GAMBLER                   0x26E
#define FLAG_GOT_20_COINS_FROM_GAMBLER                   0x26F
#define FLAG_GOT_20_COINS_FROM_GAMBLER_2                 0x270
#define FLAG_GOT_BICYCLE                                 0x271
#define FLAG_GOT_DOME_FOSSIL                             0x272
#define FLAG_GOT_HELIX_FOSSIL                            0x273
#define FLAG_DID_ESPHERE_TRADE                           0x274
#define FLAG_DID_TANGENY_TRADE                           0x275
#define FLAG_DID_SEELOR_TRADE                            0x276
#define FLAG_MT_EMBER_BOULDER_SHORTCUTS                  0x277
#define FLAG_GOT_HITMON_FROM_DOJO                        0x278
#define FLAG_SHOWN_COPPER_CARD_TO_NURSE                  0x279
#define FLAG_SILPH_2F_DOOR_1                             0x27A
#define FLAG_SILPH_2F_DOOR_2                             0x27B
#define FLAG_SILPH_3F_DOOR_1                             0x27C
#define FLAG_SILPH_3F_DOOR_2                             0x27D
#define FLAG_SILPH_4F_DOOR_1                             0x27E
#define FLAG_SILPH_4F_DOOR_2                             0x27F
#define FLAG_SILPH_5F_DOOR_1                             0x280
#define FLAG_SILPH_5F_DOOR_2                             0x281
#define FLAG_SILPH_5F_DOOR_3                             0x282
#define FLAG_SILPH_6F_DOOR                               0x283
#define FLAG_SILPH_7F_DOOR_1                             0x284
#define FLAG_SILPH_7F_DOOR_2                             0x285
#define FLAG_SILPH_7F_DOOR_3                             0x286
#define FLAG_SILPH_8F_DOOR                               0x287
#define FLAG_SILPH_9F_DOOR_1                             0x288
#define FLAG_SILPH_9F_DOOR_2                             0x289
#define FLAG_SILPH_9F_DOOR_3                             0x28A
#define FLAG_SILPH_9F_DOOR_4                             0x28B
#define FLAG_SILPH_10F_DOOR                              0x28C
#define FLAG_SILPH_11F_DOOR                              0x28D
#define FLAG_GOT_DAISY_STARTER                           0x28E
#define FLAG_SHOWN_OLD_SEA_MAP                           0x28F
#define FLAG_MET_STICKER_MAN                             0x290
#define FLAG_PALLET_LADY_NOT_BLOCKING_SIGN               0x291
#define FLAG_GOT_VS_SEEKER                               0x292
#define FLAG_GOT_TM19_FROM_ERIKA                         0x293
#define FLAG_GOT_TM33_FROM_THIRSTY_GIRL                  0x294
#define FLAG_GOT_TM20_FROM_THIRSTY_GIRL                  0x295
#define FLAG_GOT_TM16_FROM_THIRSTY_GIRL                  0x296
#define FLAG_GOT_TM03_FROM_MISTY                         0x297
#define FLAG_GOT_TM26_FROM_GIOVANNI                      0x298
#define FLAG_GOT_RIVAL_STARTER_EGG                       0x299
#define FLAG_GOT_TM04_FROM_SABRINA                       0x29A
#define FLAG_GOT_FAME_CHECKER                            0x29B
#define FLAG_GOT_RECORD_SETTING_MAGIKARP                 0x29C
#define FLAG_TWO_ISLAND_SHOP_INTRODUCED                  0x29D
#define FLAG_TWO_ISLAND_SHOP_EXPANDED_1                  0x29E
#define FLAG_TWO_ISLAND_SHOP_EXPANDED_2                  0x29F
#define FLAG_TWO_ISLAND_SHOP_EXPANDED_3                  0x2A0
#define FLAG_SEVII_DETOUR_FINISHED                       0x2A1
#define FLAG_VISITED_TWO_ISLAND                          0x2A2
#define FLAG_RESCUED_LOSTELLE                            0x2A3
#define FLAG_FOUGHT_MEW                                  0x2A4
#define FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT                 0x2A5
#define FLAG_GOT_TEA                                     0x2A6

#define FLAG_RECEIVED_AURORA_TICKET                      0x2A7
#define FLAG_RECEIVED_MYSTIC_TICKET                      0x2A8
#define FLAG_RECEIVED_OLD_SEA_MAP                        0x2A9
#define FLAG_WONDER_CARD_UNUSED_1                        0x2AA
#define FLAG_WONDER_CARD_UNUSED_2                        0x2AB
#define FLAG_WONDER_CARD_UNUSED_3                        0x2AC
#define FLAG_WONDER_CARD_UNUSED_4                        0x2AD
#define FLAG_WONDER_CARD_UNUSED_5                        0x2AE
#define FLAG_WONDER_CARD_UNUSED_6                        0x2AF
#define FLAG_WONDER_CARD_UNUSED_7                        0x2B0
#define FLAG_WONDER_CARD_UNUSED_8                        0x2B1
#define FLAG_WONDER_CARD_UNUSED_9                        0x2B2
#define FLAG_WONDER_CARD_UNUSED_10                       0x2B3
#define FLAG_WONDER_CARD_UNUSED_11                       0x2B4
#define FLAG_WONDER_CARD_UNUSED_12                       0x2B5
#define FLAG_WONDER_CARD_UNUSED_13                       0x2B6
#define FLAG_WONDER_CARD_UNUSED_14                       0x2B7
#define FLAG_WONDER_CARD_UNUSED_15                       0x2B8
#define FLAG_WONDER_CARD_UNUSED_16                       0x2B9
#define FLAG_WONDER_CARD_UNUSED_17                       0x2BA
#define NUM_WONDER_CARD_FLAGS                            (1 + FLAG_WONDER_CARD_UNUSED_17 - FLAG_RECEIVED_AURORA_TICKET)

#define FLAG_GOT_POWDER_JAR                              0x2BB
#define FLAG_FOUGHT_MEWTWO                               0x2BC
#define FLAG_FOUGHT_MOLTRES                              0x2BD
#define FLAG_FOUGHT_ARTICUNO                             0x2BE
#define FLAG_FOUGHT_ZAPDOS                               0x2BF
#define FLAG_TUTOR_DOUBLE_EDGE                           0x2C0
#define FLAG_TUTOR_THUNDER_WAVE                          0x2C1
#define FLAG_TUTOR_ROCK_SLIDE                            0x2C2
#define FLAG_TUTOR_EXPLOSION                             0x2C3
#define FLAG_TUTOR_MEGA_PUNCH                            0x2C4
#define FLAG_TUTOR_MEGA_KICK                             0x2C5
#define FLAG_TUTOR_DREAM_EATER                           0x2C6
#define FLAG_TUTOR_SOFT_BOILED                           0x2C7
#define FLAG_TUTOR_SUBSTITUTE                            0x2C8
#define FLAG_TUTOR_SWORDS_DANCE                          0x2C9
#define FLAG_TUTOR_SEISMIC_TOSS                          0x2CA
#define FLAG_TUTOR_COUNTER                               0x2CB
#define FLAG_TUTOR_METRONOME                             0x2CC
#define FLAG_TUTOR_MIMIC                                 0x2CD
#define FLAG_TUTOR_BODY_SLAM                             0x2CE
#define FLAG_VISITED_OAKS_LAB                            0x2CF
#define FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1              0x2D0
#define FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2              0x2D1
#define FLAG_STOPPED_SEAFOAM_B3F_CURRENT                 0x2D2
#define FLAG_STOPPED_SEAFOAM_B4F_CURRENT                 0x2D3
#define FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE           0x2D4
#define FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE               0x2D5
#define FLAG_UNLOCKED_ROCKET_WAREHOUSE                   0x2D6
#define FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR         0x2D7
#define FLAG_LEARNED_YES_NAH_CHANSEY                     0x2D8
#define FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1       0x2D9
#define FLAG_GOT_TOGEPI_EGG                              0x2DA
#define FLAG_NO_ROOM_FOR_TOGEPI_EGG                      0x2DB
#define FLAG_RECOVERED_SAPPHIRE                          0x2DC
#define FLAG_GOT_RUBY                                    0x2DD
#define FLAG_TUTOR_FRENZY_PLANT                          0x2DE
#define FLAG_TUTOR_BLAST_BURN                            0x2DF
#define FLAG_TUTOR_HYDRO_CANNON                          0x2E0
#define FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK             0x2E1
#define FLAG_GOT_NUGGET_FROM_DUNSPARCE_TUNNEL            0x2E2
#define FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE             0x2E3
#define FLAG_FOUGHT_DEOXYS                               0x2E4
#define FLAG_DEFEATED_MEW                                0x2E5
#define FLAG_MEW_FLEW_AWAY                               0x2E6
#define FLAG_HIDE_MEW                                    0x2E7
#define FLAG_CAUGHT_MEW                                  0x2E8
#define FLAG_CAUGHT_RAIKOU                               0x2E9
#define FLAG_CAUGHT_ENTEI                                0x2EA
#define FLAG_CAUGHT_SUICUNE                              0x2EB
#define FLAG_REVIVED_DOME                                0x2EC
#define FLAG_REVIVED_HELIX                               0x2ED
#define FLAG_REVIVED_AMBER                               0x2EE
#define FLAG_GOT_HM06                                    0x2EF
#define FLAG_SHOWN_MYSTIC_TICKET                         0x2F0
#define FLAG_SHOWN_AURORA_TICKET                         0x2F1
#define FLAG_FOUGHT_LUGIA                                0x2F2
#define FLAG_FOUGHT_HO_OH                                0x2F3
#define FLAG_OAK_SAW_DEX_COMPLETION                      0x2F4
#define FLAG_LUGIA_FLEW_AWAY                             0x2F5
#define FLAG_HO_OH_FLEW_AWAY                             0x2F6
#define FLAG_DEOXYS_FLEW_AWAY                            0x2F7
#define FLAG_TALKED_TO_TEA_LADY_AFTER_HOF                0x2F8
#define FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION            0x2F9
#define FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE                0x2FA
#define FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER      0x2FB
#define FLAG_GOT_FULL_RESTORE_FROM_THREE_ISLAND_DEFENDER 0x2FC
#define FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE              0x2FD
#define FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE   0x2FE
#define FLAG_OAKS_RATING_IS_VIA_PC                       0x2FF

// Nuzlocke Flags
#define NUZLOCKE_FLAGS_START 0x300

#define FLAG_NUZLOCKE_PALLET           0x300
#define FLAG_NUZLOCKE_VIRIDIAN         0x301
#define FLAG_NUZLOCKE_CERULEAN         0x302
#define FLAG_NUZLOCKE_VERMILION        0x303
#define FLAG_NUZLOCKE_CELADON          0x304
#define FLAG_NUZLOCKE_FUCHSIA          0x305
#define FLAG_NUZLOCKE_CINNABAR         0x306
#define FLAG_NUZLOCKE_R1               0x307
#define FLAG_NUZLOCKE_R2               0x308
#define FLAG_NUZLOCKE_R3               0x309
#define FLAG_NUZLOCKE_R4               0x30A
#define FLAG_NUZLOCKE_R5               0x30B
#define FLAG_NUZLOCKE_R6               0x30C
#define FLAG_NUZLOCKE_R7               0x30D
#define FLAG_NUZLOCKE_R8               0x30E
#define FLAG_NUZLOCKE_R9               0x30F
#define FLAG_NUZLOCKE_R10              0x310
#define FLAG_NUZLOCKE_R11              0x311
#define FLAG_NUZLOCKE_R12              0x312
#define FLAG_NUZLOCKE_R13              0x313
#define FLAG_NUZLOCKE_R14              0x314
#define FLAG_NUZLOCKE_R15              0x315
#define FLAG_NUZLOCKE_R16              0x316
#define FLAG_NUZLOCKE_R17              0x317
#define FLAG_NUZLOCKE_R18              0x318
#define FLAG_NUZLOCKE_R19              0x319
#define FLAG_NUZLOCKE_R20              0x31A
#define FLAG_NUZLOCKE_R21              0x31B
#define FLAG_NUZLOCKE_R22              0x31C
#define FLAG_NUZLOCKE_R23              0x31D
#define FLAG_NUZLOCKE_R24              0x31E
#define FLAG_NUZLOCKE_R25              0x31F
#define FLAG_NUZLOCKE_VIRIDIAN_FOREST  0x320
#define FLAG_NUZLOCKE_MT_MOON          0x321
#define FLAG_NUZLOCKE_SS_ANNE          0x322
#define FLAG_NUZLOCKE_DIGLETTS_CAVE    0x323
#define FLAG_NUZLOCKE_VICTORY_ROAD     0x324
#define FLAG_NUZLOCKE_POKEMON_MANSION  0x325
#define FLAG_NUZLOCKE_SAFARI_CENTER    0x326
#define FLAG_NUZLOCKE_ROCK_TUNNEL      0x327
#define FLAG_NUZLOCKE_SEAFOAM_ISLANDS  0x328
#define FLAG_NUZLOCKE_POKEMON_TOWER    0x329
#define FLAG_NUZLOCKE_CERULEAN_CAVE    0x32A
#define FLAG_NUZLOCKE_POWER_PLANT      0x32B
#define FLAG_NUZLOCKE_ONE_ISLAND       0x32C
#define FLAG_NUZLOCKE_FOUR_ISLAND      0x32D
#define FLAG_NUZLOCKE_FIVE_ISLAND      0x32E
#define FLAG_NUZLOCKE_KINDLE_ROAD      0x32F
#define FLAG_NUZLOCKE_TREASURE_BEACH   0x330
#define FLAG_NUZLOCKE_CAPE_BRINK       0x331
#define FLAG_NUZLOCKE_BOND_BRIDGE      0x332
#define FLAG_NUZLOCKE_THREE_ISLE_PORT  0x333
#define FLAG_NUZLOCKE_RESORT_GORGEOUS  0x334
#define FLAG_NUZLOCKE_WATER_LABYRINTH  0x335
#define FLAG_NUZLOCKE_FIVE_ISLE_MEADOW 0x336
#define FLAG_NUZLOCKE_MEMORIAL_PILLAR  0x337
#define FLAG_NUZLOCKE_OUTCAST_ISLAND   0x338
#define FLAG_NUZLOCKE_GREEN_PATH       0x339
#define FLAG_NUZLOCKE_WATER_PATH       0x33A
#define FLAG_NUZLOCKE_RUIN_VALLEY      0x33B
#define FLAG_NUZLOCKE_TRAINER_TOWER    0x33C
#define FLAG_NUZLOCKE_CANYON_ENTRANCE  0x33D
#define FLAG_NUZLOCKE_SEVAULT_CANYON   0x33E
#define FLAG_NUZLOCKE_TANOBY_RUINS     0x33F
#define FLAG_NUZLOCKE_NAVEL_ROCK       0x340
#define FLAG_NUZLOCKE_MT_EMBER         0x341
#define FLAG_NUZLOCKE_BERRY_FOREST     0x342
#define FLAG_NUZLOCKE_ICEFALL_CAVE     0x343
#define FLAG_NUZLOCKE_LOST_CAVE        0x344
#define FLAG_NUZLOCKE_PATTERN_BUSH     0x345
#define FLAG_NUZLOCKE_ALTERING_CAVE    0x346
#define FLAG_NUZLOCKE_MONEAN_CHAMBER   0x347
#define FLAG_NUZLOCKE_LIPTOO_CHAMBER   0x348
#define FLAG_NUZLOCKE_WEEPTH_CHAMBER   0x349
#define FLAG_NUZLOCKE_DILFORD_CHAMBER  0x34A
#define FLAG_NUZLOCKE_SCUFIB_CHAMBER   0x34B
#define FLAG_NUZLOCKE_RIXY_CHAMBER     0x34C
#define FLAG_NUZLOCKE_VIAPOIS_CHAMBER  0x34D
#define FLAG_NUZLOCKE_SAFARI_EAST      0x34E
#define FLAG_NUZLOCKE_SAFARI_NORTH     0x34F
#define FLAG_NUZLOCKE_SAFARI_WEST      0x350
#define FLAG_NUZLOCKE_SAFARI_NORTH_WEST 0x351
#define FLAG_NUZLOCKE_SAFARI_NORTH_EAST 0x352
#define FLAG_NUZLOCKE_ARTISAN_CAVE     0x353
#define FLAG_NUZLOCKE_SOUTHERN_ISLAND  0x354
#define FLAG_NUZLOCKE_BATTLE_FRONTIER  0x355

// Unused?
#define FLAG_HIDDEN_ITEM_ROUTE_108_RARE_CANDY    0x356
#define FLAG_ITEM_ROUTE_109_PP_UP                0x357
#define FLAG_ITEM_ROUTE_109_POTION               0x358
#define FLAG_HIDDEN_ITEM_ROUTE_109_REVIVE        0x359

#define FLAG_TOLD_SAFARI_EXPANSION     0x35A
#define FLAG_FOUR_ISLAND_SNOW          0x35B

// Unused?
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_1 0x35C
#define FLAG_HIDDEN_ITEM_ROUTE_109_GREAT_BALL    0x35D
#define FLAG_HIDDEN_ITEM_ROUTE_109_ETHER         0x35E
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_2 0x35F
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_3 0x360
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CARBOS   0x361
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_GREEN_SHARD 0x362
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_PEARL    0x363
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_BIG_PEARL 0x364
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_1 0x365
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CALCIUM  0x366
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_2 0x367
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_HEART_SCALE 0x368
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_ULTRA_BALL 0x369
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_STARDUST 0x36A
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_PEARL    0x36B
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_IRON     0x36C
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_YELLOW_SHARD 0x36D
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BIG_PEARL 0x36E
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BLUE_SHARD 0x36F
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_STAR_PIECE 0x370
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_HP_UP    0x371
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_HEART_SCALE 0x372
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_RED_SHARD 0x373
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PROTEIN  0x374
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PEARL    0x375
#define FLAG_ITEM_PETALBURG_WOODS_GREAT_BALL     0x376
#define FLAG_ITEM_PETALBURG_WOODS_X_ATTACK       0x377
#define FLAG_ITEM_PETALBURG_WOODS_ETHER          0x378
#define FLAG_ITEM_PETALBURG_WOODS_PARALYZE_HEAL  0x379
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POTION  0x37A
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_1 0x37B
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_2 0x37C
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POKE_BALL 0x37D
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1          0x37E
#define FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL       0x37F
#define FLAG_ITEM_RUSTURF_TUNNEL_MAX_ETHER       0x380
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2          0x381
#define FLAG_ITEM_GRANITE_CAVE_1F_ESCAPE_ROPE    0x382
#define FLAG_ITEM_GRANITE_CAVE_B1F_POKE_BALL     0x383
#define FLAG_ITEM_GRANITE_CAVE_B2F_REPEL         0x384
#define FLAG_ITEM_GRANITE_CAVE_B2F_RARE_CANDY    0x385
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_1 0x386
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_2 0x387
#define FLAG_ITEM_METEOR_FALLS_1F_1R_TM_IRON_TAIL 0x388
#define FLAG_ITEM_METEOR_FALLS_1F_1R_MOON_STONE  0x389
#define FLAG_ITEM_METEOR_FALLS_1F_1R_FULL_HEAL   0x38A
#define FLAG_ITEM_METEOR_FALLS_1F_1R_PP_UP       0x38B
#define FLAG_ITEM_METEOR_FALLS_B1F_2R_TM_DRAGON_CLAW 0x38C
#define FLAG_ITEM_JAGGED_PASS_BURN_HEAL          0x38D
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_FULL_HEAL   0x38E
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_GREAT_BALL  0x38F
#define FLAG_ITEM_FIERY_PATH_TM_TOXIC            0x390
#define FLAG_ITEM_FIERY_PATH_FIRE_STONE          0x391
#define FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY    0x392
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAX_ELIXIR 0x393
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_FULL_RESTORE 0x394
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_NUGGET     0x395
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_2R_PP_MAX     0x396
#define FLAG_ITEM_MAGMA_HIDEOUT_4F_MAX_REVIVE    0x397
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_3R_ECAPE_ROPE 0x398
#define FLAG_ITEM_NEW_MAUVILLE_ULTRA_BALL        0x399
#define FLAG_ITEM_NEW_MAUVILLE_ESCAPE_ROPE       0x39A
#define FLAG_ITEM_NEW_MAUVILLE_THUNDER_STONE     0x39B
#define FLAG_ITEM_NEW_MAUVILLE_FULL_HEAL         0x39C
#define FLAG_ITEM_NEW_MAUVILLE_PARALYZE_HEAL     0x39D
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_1F_HARBOR_MAIL 0x39E
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_ESCAPE_ROPE 0x39F
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_B1F_DIVE_BALL 0x3A0
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_TM_ICE_BEAM 0x3A1
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_REVIVE 0x3A2
#define FLAG_ITEM_ABANDONED_SHIP_CAPTAINS_OFFICE_STORAGE_KEY 0x3A3
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_6_LUXURY_BALL 0x3A4
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER 0x3A5
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_1_TM_RAIN_DANCE 0x3A6
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_3_WATER_STONE 0x3A7
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY 0x3A8
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY 0x3A9
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY 0x3AA
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY 0x3AB
#define FLAG_ITEM_MT_PYRE_2F_ULTRA_BALL          0x3AC
#define FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL         0x3AD
#define FLAG_ITEM_MT_PYRE_4F_SEA_INCENSE         0x3AE
#define FLAG_ITEM_MT_PYRE_5F_LAX_INCENSE         0x3AF
#define FLAG_ITEM_MT_PYRE_6F_TM_SHADOW_BALL      0x3B0
#define FLAG_ITEM_MT_PYRE_EXTERIOR_MAX_POTION    0x3B1
#define FLAG_ITEM_MT_PYRE_EXTERIOR_TM_SKILL_SWAP 0x3B2
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_ULTRA_BALL 0x3B3
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_MAX_ETHER 0x3B4
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_ZINC     0x3B5
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_RARE_CANDY 0x3B6
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MAX_ELIXIR    0x3B7
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL   0x3B8
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_NUGGET        0x3B9
#define FLAG_ITEM_AQUA_HIDEOUT_B2F_NEST_BALL     0x3BA
#define FLAG_ITEM_SHOAL_CAVE_ENTRANCE_BIG_PEARL  0x3BB
#define FLAG_ITEM_SHOAL_CAVE_INNER_ROOM_RARE_CANDY 0x3BC
#define FLAG_ITEM_SHOAL_CAVE_STAIRS_ROOM_ICE_HEAL 0x3BD
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_TM_HAIL    0x3BE
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_NEVER_MELT_ICE 0x3BF
#define FLAG_ITEM_SEAFLOOR_CAVERN_ROOM_9_TM_EARTHQUAKE 0x3C0
#define FLAG_ITEM_HOENN_VICTORY_ROAD_1F_MAX_ELIXIR 0x3C1
#define FLAG_ITEM_HOENN_VICTORY_ROAD_1F_PP_UP    0x3C2
#define FLAG_HIDDEN_ITEM_HOENN_VICTORY_ROAD_1F_ULTRA_BALL 0x3C3
#define FLAG_ITEM_HOENN_VICTORY_ROAD_B1F_TM_PSYCHIC 0x3C4
#define FLAG_ITEM_HOENN_VICTORY_ROAD_B1F_FULL_RESTORE 0x3C5
#define FLAG_ITEM_HOENN_VICTORY_ROAD_B2F_FULL_HEAL 0x3C6
#define FLAG_HIDDEN_ITEM_HOENN_VICTORY_ROAD_B2F_ELIXIR 0x3C7
#define FLAG_HIDDEN_ITEM_HOENN_VICTORY_ROAD_B2F_MAX_REPEL 0x3C8
#define FLAG_ITEM_SCORCHED_SLAB_TM_SUNNY_DAY     0x3C9
#define FLAG_ITEM_HOENN_SAFARI_ZONE_NORTH_WEST_TM_SOLAR_BEAM 0x3CA
#define FLAG_ITEM_HOENN_SAFARI_ZONE_NORTH_CALCIUM 0x3CB
#define FLAG_ITEM_HOENN_SAFARI_ZONE_SOUTH_WEST_MAX_REVIVE 0x3CC
#define FLAG_ITEM_HOENN_SAFARI_ZONE_NORTH_EAST_NUGGET 0x3CD
#define FLAG_HIDDEN_ITEM_HOENN_SAFARI_ZONE_NORTH_EAST_RARE_CANDY 0x3CE
#define FLAG_HIDDEN_ITEM_HOENN_SAFARI_ZONE_NORTH_EAST_ZINC 0x3CF
//New move tutors
#define FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER  0x3D0
#define FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT      0x3D1
#define FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH 0x3D2
#define FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK   0x3D3
#define FLAG_MOVE_TUTOR_TAUGHT_NIGHTMARE    0x3D4
#define FLAG_MOVE_TUTOR_TAUGHT_SELFDESTRUCT 0x3D5
#define FLAG_MOVE_TUTOR_TAUGHT_SKY_ATTACK   0x3D6
#define FLAG_MOVE_TUTOR_TAUGHT_SWAGGER      0x3D7
#define FLAG_MYSTERY_GIFT_DONE   0x3D8
#define FLAG_MYSTERY_GIFT_1      0x3D9
#define FLAG_MYSTERY_GIFT_2      0x3DA
#define FLAG_MYSTERY_GIFT_3      0x3DB
#define FLAG_MYSTERY_GIFT_4      0x3DC
#define FLAG_MYSTERY_GIFT_5      0x3DD
#define FLAG_MYSTERY_GIFT_6      0x3DE
#define FLAG_MYSTERY_GIFT_7      0x3DF
#define FLAG_MYSTERY_GIFT_8      0x3E0
#define FLAG_MYSTERY_GIFT_9      0x3E1
#define FLAG_MYSTERY_GIFT_10     0x3E2
#define FLAG_MYSTERY_GIFT_11     0x3E3
#define FLAG_MYSTERY_GIFT_12     0x3E4
#define FLAG_MYSTERY_GIFT_13     0x3E5
#define FLAG_MYSTERY_GIFT_14     0x3E6
#define FLAG_MYSTERY_GIFT_15     0x3E7

#define FLAG_HIDDEN_ITEMS_START 1000 // 0x3E8

#define FLAG_HIDDEN_ITEM_VIRIDIAN_FOREST_POTION                            (FLAG_HIDDEN_ITEMS_START +   0)
#define FLAG_HIDDEN_ITEM_VIRIDIAN_FOREST_ANTIDOTE                          (FLAG_HIDDEN_ITEMS_START +   1)
#define FLAG_HIDDEN_ITEM_MT_MOON_B2F_MOON_STONE                            (FLAG_HIDDEN_ITEMS_START +   2)
#define FLAG_HIDDEN_ITEM_MT_MOON_B2F_ETHER                                 (FLAG_HIDDEN_ITEMS_START +   3)
#define FLAG_HIDDEN_ITEM_ROUTE25_ELIXIR                                    (FLAG_HIDDEN_ITEMS_START +   4)
#define FLAG_HIDDEN_ITEM_ROUTE25_ETHER                                     (FLAG_HIDDEN_ITEMS_START +   5)
#define FLAG_HIDDEN_ITEM_ROUTE9_ETHER                                      (FLAG_HIDDEN_ITEMS_START +   6)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTHWEST_SHELL_BELL                  (FLAG_HIDDEN_ITEMS_START +   7) // New
#define FLAG_HIDDEN_ITEM_SSANNE_B1F_CORRIDOR_HYPER_POTION                  (FLAG_HIDDEN_ITEMS_START +   8)
#define FLAG_HIDDEN_ITEM_ROUTE10_SUPER_POTION                              (FLAG_HIDDEN_ITEMS_START +   9)
#define FLAG_HIDDEN_ITEM_ROUTE10_MAX_ETHER                                 (FLAG_HIDDEN_ITEMS_START +  10)
#define FLAG_HIDDEN_ITEM_ROCKET_HIDEOUT_B1F_PP_UP                          (FLAG_HIDDEN_ITEMS_START +  11)
#define FLAG_HIDDEN_ITEM_ROCKET_HIDEOUT_B3F_NUGGET                         (FLAG_HIDDEN_ITEMS_START +  12)
#define FLAG_HIDDEN_ITEM_ROCKET_HIDEOUT_B4F_NEST_BALL                      (FLAG_HIDDEN_ITEMS_START +  13)
#define FLAG_HIDDEN_ITEM_POKEMON_TOWER_5F_BIG_MUSHROOM                     (FLAG_HIDDEN_ITEMS_START +  14)
#define FLAG_HIDDEN_ITEM_ROUTE13_PP_UP                                     (FLAG_HIDDEN_ITEMS_START +  15)
#define FLAG_HIDDEN_ITEM_ROUTE20_UNDERWATER_BIG_PEARL                      (FLAG_HIDDEN_ITEMS_START +  16) // New
#define FLAG_HIDDEN_ITEM_ROUTE17_RARE_CANDY                                (FLAG_HIDDEN_ITEMS_START +  17)
#define FLAG_HIDDEN_ITEM_ROUTE17_FULL_RESTORE                              (FLAG_HIDDEN_ITEMS_START +  18)
#define FLAG_HIDDEN_ITEM_ROUTE17_PP_UP                                     (FLAG_HIDDEN_ITEMS_START +  19)
#define FLAG_HIDDEN_ITEM_ROUTE17_MAX_REVIVE                                (FLAG_HIDDEN_ITEMS_START +  20)
#define FLAG_HIDDEN_ITEM_ROUTE17_MAX_ELIXIR                                (FLAG_HIDDEN_ITEMS_START +  21)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_CENTER_LEAF_STONE                     (FLAG_HIDDEN_ITEMS_START +  22)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_WEST_REVIVE                           (FLAG_HIDDEN_ITEMS_START +  23)
#define FLAG_HIDDEN_ITEM_SILPH_CO_5F_ELIXIR                                (FLAG_HIDDEN_ITEMS_START +  24)
#define FLAG_HIDDEN_ITEM_SILPH_CO_9F_MAX_POTION                            (FLAG_HIDDEN_ITEMS_START +  25)
#define FLAG_HIDDEN_ITEM_SAFFRON_CITY_COPYCATS_HOUSE_2F_NUGGET             (FLAG_HIDDEN_ITEMS_START +  26)
#define FLAG_HIDDEN_ITEM_POWER_PLANT_MAX_ELIXIR                            (FLAG_HIDDEN_ITEMS_START +  27)
#define FLAG_HIDDEN_ITEM_POWER_PLANT_THUNDER_STONE                         (FLAG_HIDDEN_ITEMS_START +  28)
#define FLAG_HIDDEN_ITEM_SEAFOAM_ISLANDS_B3F_NUGGET                        (FLAG_HIDDEN_ITEMS_START +  29)
#define FLAG_HIDDEN_ITEM_SEAFOAM_ISLANDS_B4F_WATER_STONE                   (FLAG_HIDDEN_ITEMS_START +  30)
#define FLAG_HIDDEN_ITEM_POKEMON_MANSION_1F_MOON_STONE                     (FLAG_HIDDEN_ITEMS_START +  31)
#define FLAG_HIDDEN_ITEM_POKEMON_MANSION_3F_RARE_CANDY                     (FLAG_HIDDEN_ITEMS_START +  32)
#define FLAG_HIDDEN_ITEM_POKEMON_MANSION_B1F_ELIXIR                        (FLAG_HIDDEN_ITEMS_START +  33)
#define FLAG_HIDDEN_ITEM_ROUTE23_FULL_RESTORE                              (FLAG_HIDDEN_ITEMS_START +  34)
#define FLAG_HIDDEN_ITEM_ROUTE23_ULTRA_BALL                                (FLAG_HIDDEN_ITEMS_START +  35)
#define FLAG_HIDDEN_ITEM_ROUTE23_MAX_ETHER                                 (FLAG_HIDDEN_ITEMS_START +  36)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_1F_ULTRA_BALL                        (FLAG_HIDDEN_ITEMS_START +  37)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_1F_FULL_RESTORE                      (FLAG_HIDDEN_ITEMS_START +  38)
#define FLAG_HIDDEN_ITEM_CERULEAN_CAVE_1F_ULTRA_BALL                       (FLAG_HIDDEN_ITEMS_START +  39)
#define FLAG_HIDDEN_ITEM_ROUTE11_TAMATO_BERRY                              (FLAG_HIDDEN_ITEMS_START +  40) // New
#define FLAG_HIDDEN_ITEM_ROUTE11_ESCAPE_ROPE                               (FLAG_HIDDEN_ITEMS_START +  41)
#define FLAG_HIDDEN_ITEM_ROUTE12_HYPER_POTION                              (FLAG_HIDDEN_ITEMS_START +  42)
#define FLAG_HIDDEN_ITEM_CAPE_BRINK_GREPA_BERRY                            (FLAG_HIDDEN_ITEMS_START +  43) // New
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_PORT_TAMATO_BERRY                    (FLAG_HIDDEN_ITEMS_START +  44) // New
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_SITRUS_BERRY            (FLAG_HIDDEN_ITEMS_START +  45) // New
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_TAMATO_BERRY            (FLAG_HIDDEN_ITEMS_START +  46) // New
#define FLAG_HIDDEN_ITEM_CELADON_CITY_PP_UP                                (FLAG_HIDDEN_ITEMS_START +  47)
#define FLAG_HIDDEN_ITEM_VERMILION_CITY_MAX_ETHER                          (FLAG_HIDDEN_ITEMS_START +  48)
#define FLAG_HIDDEN_ITEM_CERULEAN_CITY_RARE_CANDY                          (FLAG_HIDDEN_ITEMS_START +  49)
#define FLAG_HIDDEN_ITEM_ROUTE4_GREAT_BALL                                 (FLAG_HIDDEN_ITEMS_START +  50)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS                    (FLAG_HIDDEN_ITEMS_START +  51)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_2                  (FLAG_HIDDEN_ITEMS_START +  52)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_3                  (FLAG_HIDDEN_ITEMS_START +  53)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_4                  (FLAG_HIDDEN_ITEMS_START +  54)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_5                  (FLAG_HIDDEN_ITEMS_START +  55)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_6                  (FLAG_HIDDEN_ITEMS_START +  56)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_7                  (FLAG_HIDDEN_ITEMS_START +  57)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_8                  (FLAG_HIDDEN_ITEMS_START +  58)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_9                  (FLAG_HIDDEN_ITEMS_START +  59)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_10                 (FLAG_HIDDEN_ITEMS_START +  60)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_11                 (FLAG_HIDDEN_ITEMS_START +  61)
#define FLAG_HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_12                 (FLAG_HIDDEN_ITEMS_START +  62)
#define FLAG_HIDDEN_ITEM_SEVEN_ISLAND_SEVAULT_CANYON_CHERI_BERRY           (FLAG_HIDDEN_ITEMS_START +  63)
#define FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TANOBY_RUINS_HEART_SCALE_4           (FLAG_HIDDEN_ITEMS_START +  64)
#define FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TANOBY_RUINS_HEART_SCALE             (FLAG_HIDDEN_ITEMS_START +  65)
#define FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TANOBY_RUINS_HEART_SCALE_2           (FLAG_HIDDEN_ITEMS_START +  66)
#define FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TANOBY_RUINS_HEART_SCALE_3           (FLAG_HIDDEN_ITEMS_START +  67)
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_ROCKET_WAREHOUSE_NEST_BALL            (FLAG_HIDDEN_ITEMS_START +  68)
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_ROCKET_WAREHOUSE_NET_BALL             (FLAG_HIDDEN_ITEMS_START +  69)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_POTION        (FLAG_HIDDEN_ITEMS_START +  70)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ANTIDOTE      (FLAG_HIDDEN_ITEMS_START +  71)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_PARALYZE_HEAL (FLAG_HIDDEN_ITEMS_START +  72)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_AWAKENING     (FLAG_HIDDEN_ITEMS_START +  73)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_BURN_HEAL     (FLAG_HIDDEN_ITEMS_START +  74)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ICE_HEAL      (FLAG_HIDDEN_ITEMS_START +  75)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ETHER         (FLAG_HIDDEN_ITEMS_START +  76)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_POTION          (FLAG_HIDDEN_ITEMS_START +  77)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ANTIDOTE        (FLAG_HIDDEN_ITEMS_START +  78)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_PARALYZE_HEAL   (FLAG_HIDDEN_ITEMS_START +  79)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_AWAKENING       (FLAG_HIDDEN_ITEMS_START +  80)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_BURN_HEAL       (FLAG_HIDDEN_ITEMS_START +  81)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ICE_HEAL        (FLAG_HIDDEN_ITEMS_START +  82)
#define FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ETHER           (FLAG_HIDDEN_ITEMS_START +  83)
#define FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM                         (FLAG_HIDDEN_ITEMS_START +  84)
#define FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_2                       (FLAG_HIDDEN_ITEMS_START +  85)
#define FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_3                       (FLAG_HIDDEN_ITEMS_START +  86)
#define FLAG_HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM                          (FLAG_HIDDEN_ITEMS_START +  87)
#define FLAG_HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM_2                        (FLAG_HIDDEN_ITEMS_START +  88)
#define FLAG_HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM_3                        (FLAG_HIDDEN_ITEMS_START +  89)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_POMEG_BERRY             (FLAG_HIDDEN_ITEMS_START +  90) // Changed from Razz
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_KELPSY_BERRY            (FLAG_HIDDEN_ITEMS_START +  91) // Changed from Bluk
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_QUALOT_BERRY            (FLAG_HIDDEN_ITEMS_START +  92) // Changed from Nanab
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_HONDEW_BERRY            (FLAG_HIDDEN_ITEMS_START +  93) // Changed from Wepear
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_ORAN_BERRY              (FLAG_HIDDEN_ITEMS_START +  94)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_CHERI_BERRY             (FLAG_HIDDEN_ITEMS_START +  95)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_CHESTO_BERRY            (FLAG_HIDDEN_ITEMS_START +  96)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_PECHA_BERRY             (FLAG_HIDDEN_ITEMS_START +  97)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_RAWST_BERRY             (FLAG_HIDDEN_ITEMS_START +  98)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_ASPEAR_BERRY            (FLAG_HIDDEN_ITEMS_START +  99)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_PERSIM_BERRY            (FLAG_HIDDEN_ITEMS_START + 100)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_GREPA_BERRY             (FLAG_HIDDEN_ITEMS_START + 101) // Changed from Pinap
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_LUM_BERRY               (FLAG_HIDDEN_ITEMS_START + 102)
#define FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_STARDUST                (FLAG_HIDDEN_ITEMS_START + 103)
#define FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_STARDUST_2              (FLAG_HIDDEN_ITEMS_START + 104)
#define FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_PEARL                   (FLAG_HIDDEN_ITEMS_START + 105)
#define FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_PEARL_2                 (FLAG_HIDDEN_ITEMS_START + 106)
#define FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_ULTRA_BALL              (FLAG_HIDDEN_ITEMS_START + 107)
#define FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_ULTRA_BALL_2            (FLAG_HIDDEN_ITEMS_START + 108)
#define FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_STAR_PIECE              (FLAG_HIDDEN_ITEMS_START + 109)
#define FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_BIG_PEARL               (FLAG_HIDDEN_ITEMS_START + 110)
#define FLAG_HIDDEN_ITEM_TWO_ISLAND_CAPE_BRINK_RARE_CANDY                  (FLAG_HIDDEN_ITEMS_START + 111)
#define FLAG_HIDDEN_ITEM_PEWTER_CITY_POKE_BALL                             (FLAG_HIDDEN_ITEMS_START + 112)
#define FLAG_HIDDEN_ITEM_ROUTE3_ORAN_BERRY                                 (FLAG_HIDDEN_ITEMS_START + 113)
#define FLAG_HIDDEN_ITEM_ROUTE4_PERSIM_BERRY                               (FLAG_HIDDEN_ITEMS_START + 114)
#define FLAG_HIDDEN_ITEM_ROUTE24_PECHA_BERRY                               (FLAG_HIDDEN_ITEMS_START + 115)
#define FLAG_HIDDEN_ITEM_ROUTE25_ORAN_BERRY                                (FLAG_HIDDEN_ITEMS_START + 116)
#define FLAG_HIDDEN_ITEM_ROUTE25_POMEG_BERRY                               (FLAG_HIDDEN_ITEMS_START + 117) // Changed from Bluk
#define FLAG_HIDDEN_ITEM_ROUTE6_SITRUS_BERRY                               (FLAG_HIDDEN_ITEMS_START + 118)
#define FLAG_HIDDEN_ITEM_ROUTE6_RARE_CANDY                                 (FLAG_HIDDEN_ITEMS_START + 119)
#define FLAG_HIDDEN_ITEM_SSANNE_KITCHEN_PECHA_BERRY                        (FLAG_HIDDEN_ITEMS_START + 120)
#define FLAG_HIDDEN_ITEM_SSANNE_KITCHEN_CHERI_BERRY                        (FLAG_HIDDEN_ITEMS_START + 121)
#define FLAG_HIDDEN_ITEM_SSANNE_KITCHEN_CHESTO_BERRY                       (FLAG_HIDDEN_ITEMS_START + 122)
#define FLAG_HIDDEN_ITEM_ROUTE9_RARE_CANDY                                 (FLAG_HIDDEN_ITEMS_START + 123)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTHWEST_LIECHI_BERRY                (FLAG_HIDDEN_ITEMS_START + 124) // New
#define FLAG_HIDDEN_ITEM_ROUTE10_PERSIM_BERRY                              (FLAG_HIDDEN_ITEMS_START + 125)
#define FLAG_HIDDEN_ITEM_ROUTE10_CHERI_BERRY                               (FLAG_HIDDEN_ITEMS_START + 126)
#define FLAG_HIDDEN_ITEM_ROUTE8_RAWST_BERRY                                (FLAG_HIDDEN_ITEMS_START + 127)
#define FLAG_HIDDEN_ITEM_ROUTE8_LUM_BERRY                                  (FLAG_HIDDEN_ITEMS_START + 128)
#define FLAG_HIDDEN_ITEM_ROUTE8_LEPPA_BERRY                                (FLAG_HIDDEN_ITEMS_START + 129)
#define FLAG_HIDDEN_ITEM_ROUTE12_RARE_CANDY                                (FLAG_HIDDEN_ITEMS_START + 130)
#define FLAG_HIDDEN_ITEM_ROUTE12_LEFTOVERS                                 (FLAG_HIDDEN_ITEMS_START + 131)
#define FLAG_HIDDEN_ITEM_ROUTE16_LEFTOVERS                                 (FLAG_HIDDEN_ITEMS_START + 132)
#define FLAG_HIDDEN_ITEM_FUCHSIA_CITY_MAX_REVIVE                           (FLAG_HIDDEN_ITEMS_START + 133)
#define FLAG_HIDDEN_ITEM_ROCKET_HIDEOUT_B4F_NET_BALL                       (FLAG_HIDDEN_ITEMS_START + 134)
#define FLAG_HIDDEN_ITEM_SILPH_CO_2F_ULTRA_BALL                            (FLAG_HIDDEN_ITEMS_START + 135)
#define FLAG_HIDDEN_ITEM_SILPH_CO_3F_PROTEIN                               (FLAG_HIDDEN_ITEMS_START + 136)
#define FLAG_HIDDEN_ITEM_SILPH_CO_4F_IRON                                  (FLAG_HIDDEN_ITEMS_START + 137)
#define FLAG_HIDDEN_ITEM_SILPH_CO_5F_PP_UP                                 (FLAG_HIDDEN_ITEMS_START + 138)
#define FLAG_HIDDEN_ITEM_SILPH_CO_6F_CARBOS                                (FLAG_HIDDEN_ITEMS_START + 139)
#define FLAG_HIDDEN_ITEM_SILPH_CO_7F_ZINC                                  (FLAG_HIDDEN_ITEMS_START + 140)
#define FLAG_HIDDEN_ITEM_SILPH_CO_8F_NUGGET                                (FLAG_HIDDEN_ITEMS_START + 141)
#define FLAG_HIDDEN_ITEM_SILPH_CO_9F_CALCIUM                               (FLAG_HIDDEN_ITEMS_START + 142)
#define FLAG_HIDDEN_ITEM_SILPH_CO_10F_HP_UP                                (FLAG_HIDDEN_ITEMS_START + 143)
#define FLAG_HIDDEN_ITEM_SILPH_CO_11F_REVIVE                               (FLAG_HIDDEN_ITEMS_START + 144)
#define FLAG_HIDDEN_ITEM_ROUTE23_LUM_BERRY                                 (FLAG_HIDDEN_ITEMS_START + 145)
#define FLAG_HIDDEN_ITEM_ROUTE23_SITRUS_BERRY                              (FLAG_HIDDEN_ITEMS_START + 146)
#define FLAG_HIDDEN_ITEM_ROUTE23_ASPEAR_BERRY                              (FLAG_HIDDEN_ITEMS_START + 147)
#define FLAG_HIDDEN_ITEM_ROUTE23_LEPPA_BERRY                               (FLAG_HIDDEN_ITEMS_START + 148)
#define FLAG_HIDDEN_ITEM_ROUTE14_ZINC                                      (FLAG_HIDDEN_ITEMS_START + 149)
#define FLAG_HIDDEN_ITEM_ROUTE9_CHESTO_BERRY                               (FLAG_HIDDEN_ITEMS_START + 150)
#define FLAG_HIDDEN_ITEM_ROUTE10_KELPSY_BERRY                              (FLAG_HIDDEN_ITEMS_START + 151) // Changed from Nanab
#define FLAG_HIDDEN_ITEM_ROUTE7_QUALOT_BERRY                               (FLAG_HIDDEN_ITEMS_START + 152) // Changed from Wepear
#define FLAG_HIDDEN_ITEM_ROUTE20_STARDUST                                  (FLAG_HIDDEN_ITEMS_START + 153)
#define FLAG_HIDDEN_ITEM_ROUTE21_NORTH_PEARL                               (FLAG_HIDDEN_ITEMS_START + 154)
#define FLAG_HIDDEN_ITEM_ROUTE23_MAX_ELIXIR                                (FLAG_HIDDEN_ITEMS_START + 155)
#define FLAG_HIDDEN_ITEM_ROUTE4_HONDEW_BERRY                               (FLAG_HIDDEN_ITEMS_START + 156) // Changed from Razz
#define FLAG_HIDDEN_ITEM_ROUTE14_GREPA_BERRY                               (FLAG_HIDDEN_ITEMS_START + 157) // Changed from Pinap
#define FLAG_HIDDEN_ITEM_MT_EMBER_EXTERIOR_FIRE_STONE                      (FLAG_HIDDEN_ITEMS_START + 158)
#define FLAG_HIDDEN_ITEM_POKEMON_TOWER_7F_SOOTHE_BELL                      (FLAG_HIDDEN_ITEMS_START + 159)
#define FLAG_HIDDEN_ITEM_NAVEL_ROCK_SUMMIT_SACRED_ASH                      (FLAG_HIDDEN_ITEMS_START + 160)
#define FLAG_HIDDEN_ITEM_TWO_ISLAND_CAPE_BRINK_PP_MAX                      (FLAG_HIDDEN_ITEMS_START + 161)
#define FLAG_HIDDEN_ITEM_MT_EMBER_EXTERIOR_ULTRA_BALL                      (FLAG_HIDDEN_ITEMS_START + 162)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_DUNSPARCE_TUNNEL_NUGGET              (FLAG_HIDDEN_ITEMS_START + 163)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_PP_UP                                (FLAG_HIDDEN_ITEMS_START + 164)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BOND_BRIDGE_MAX_REPEL                (FLAG_HIDDEN_ITEMS_START + 165)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BOND_BRIDGE_PEARL                    (FLAG_HIDDEN_ITEMS_START + 166)
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BOND_BRIDGE_STARDUST                 (FLAG_HIDDEN_ITEMS_START + 167)
#define FLAG_HIDDEN_ITEM_FOUR_ISLAND_PEARL                                 (FLAG_HIDDEN_ITEMS_START + 168)
#define FLAG_HIDDEN_ITEM_FOUR_ISLAND_ULTRA_BALL                            (FLAG_HIDDEN_ITEMS_START + 169)
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_MEMORIAL_PILLAR_BIG_PEARL             (FLAG_HIDDEN_ITEMS_START + 170)
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_MEMORIAL_PILLAR_POMEG_BERRY           (FLAG_HIDDEN_ITEMS_START + 171) // Changed from Razz
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_MEMORIAL_PILLAR_SITRUS_BERRY          (FLAG_HIDDEN_ITEMS_START + 172)
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_MEMORIAL_PILLAR_KELPSY_BERRY          (FLAG_HIDDEN_ITEMS_START + 173) // Changed from Bluk
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_RESORT_GORGEOUS_NEST_BALL             (FLAG_HIDDEN_ITEMS_START + 174)
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_RESORT_GORGEOUS_STARDUST              (FLAG_HIDDEN_ITEMS_START + 175)
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_RESORT_GORGEOUS_STAR_PIECE            (FLAG_HIDDEN_ITEMS_START + 176)
#define FLAG_HIDDEN_ITEM_FIVE_ISLAND_RESORT_GORGEOUS_STARDUST_2            (FLAG_HIDDEN_ITEMS_START + 177)
#define FLAG_HIDDEN_ITEM_SIX_ISLAND_OUTCAST_ISLAND_STAR_PIECE              (FLAG_HIDDEN_ITEMS_START + 178)
#define FLAG_HIDDEN_ITEM_SIX_ISLAND_OUTCAST_ISLAND_NET_BALL                (FLAG_HIDDEN_ITEMS_START + 179)
#define FLAG_HIDDEN_ITEM_SIX_ISLAND_GREEN_PATH_ULTRA_BALL                  (FLAG_HIDDEN_ITEMS_START + 180)
#define FLAG_HIDDEN_ITEM_SIX_ISLAND_WATER_PATH_ASPEAR_BERRY                (FLAG_HIDDEN_ITEMS_START + 181)
#define FLAG_HIDDEN_ITEM_SIX_ISLAND_WATER_PATH_ORAN_BERRY                  (FLAG_HIDDEN_ITEMS_START + 182)
#define FLAG_HIDDEN_ITEM_SIX_ISLAND_WATER_PATH_QUALOT_BERRY                (FLAG_HIDDEN_ITEMS_START + 183) // Changed from Pinap
#define FLAG_HIDDEN_ITEM_SIX_ISLAND_LEPPA_BERRY                            (FLAG_HIDDEN_ITEMS_START + 184)
#define FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TRAINER_TOWER_BIG_PEARL              (FLAG_HIDDEN_ITEMS_START + 185)
#define FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TRAINER_TOWER_PEARL                  (FLAG_HIDDEN_ITEMS_START + 186)
#define FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TRAINER_TOWER_HONDEW_BERRY           (FLAG_HIDDEN_ITEMS_START + 187) // Changed from Nanab
#define FLAG_HIDDEN_ITEM_SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE_RAWST_BERRY  (FLAG_HIDDEN_ITEMS_START + 188)
#define FLAG_HIDDEN_ITEM_VIRIDIAN_CITY_GYM_MACHO_BRACE                     (FLAG_HIDDEN_ITEMS_START + 189)
#define FLAG_HIDDEN_ITEM_SSANNE_EXTERIOR_LAVA_COOKIE                       (FLAG_HIDDEN_ITEMS_START + 190)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTHWEST_SITRUS_BERRY                (FLAG_HIDDEN_ITEMS_START + 191) // New
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTHEAST_SALAC_BERRY                 (FLAG_HIDDEN_ITEMS_START + 192) // New
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTHEAST_BRIGHTPOWDER                (FLAG_HIDDEN_ITEMS_START + 193) // New
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BOND_BRIDGE_UNDERWATER_DIVE_BALL     (FLAG_HIDDEN_ITEMS_START + 194) // New
#define FLAG_HIDDEN_ITEM_THREE_ISLAND_BOND_BRIDGE_UNDERWATER_HEART_SCALE   (FLAG_HIDDEN_ITEMS_START + 195) // New
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_ZINC                                 (FLAG_HIDDEN_ITEMS_START + 196)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_CALCIUM                              (FLAG_HIDDEN_ITEMS_START + 197)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_PROTEIN                              (FLAG_HIDDEN_ITEMS_START + 198)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_IRON                                 (FLAG_HIDDEN_ITEMS_START + 199)

// Boss clear flags, 1200
#define FLAG_DEFEATED_BROCK           0x4B0
#define FLAG_DEFEATED_MISTY           0x4B1
#define FLAG_DEFEATED_LT_SURGE        0x4B2
#define FLAG_DEFEATED_ERIKA           0x4B3
#define FLAG_DEFEATED_KOGA            0x4B4
#define FLAG_DEFEATED_SABRINA         0x4B5
#define FLAG_DEFEATED_BLAINE          0x4B6
#define FLAG_DEFEATED_LEADER_GIOVANNI 0x4B7
#define FLAG_DEFEATED_LORELEI         0x4B8
#define FLAG_DEFEATED_BRUNO           0x4B9
#define FLAG_DEFEATED_AGATHA          0x4BA
#define FLAG_DEFEATED_LANCE           0x4BB
#define FLAG_DEFEATED_CHAMP           0x4BC

// Unused?
#define FLAG_HIDDEN_ITEM_CAPE_BRINK_BIG_PEARL                              (FLAG_HIDDEN_ITEMS_START + 213) // continued from above numbering because of how these are set by GetHiddenItemAttr
// Hoenn (Lilycove), new. A hidden item flag must stay below FLAG_HIDDEN_ITEMS_START + 256 (0x4E8): its map event stores the offset in a byte.
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_HEART_SCALE                         (FLAG_HIDDEN_ITEMS_START + 214) // 0x4BE
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_PP_UP                               (FLAG_HIDDEN_ITEMS_START + 215) // 0x4BF
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_POKE_BALL                           (FLAG_HIDDEN_ITEMS_START + 216) // 0x4C0
#define FLAG_ITEM_HOENN_SAFARI_ZONE_SOUTH_EAST_BIG_PEARL 0x4C1
#define FLAG_HIDDEN_ITEM_HOENN_SAFARI_ZONE_SOUTH_EAST_PP_UP 0x4C2
#define FLAG_HIDDEN_ITEM_HOENN_SAFARI_ZONE_SOUTH_EAST_FULL_RESTORE 0x4C3
#define FLAG_HIDDEN_ITEM_SS_TIDAL_LOWER_DECK_LEFTOVERS 0x4C4
#define FLAG_0x4C5               0x4C5
#define FLAG_0x4C6               0x4C6
#define FLAG_0x4C7               0x4C7
#define FLAG_0x4C8               0x4C8
#define FLAG_0x4C9               0x4C9
#define FLAG_0x4CA               0x4CA
#define FLAG_0x4CB               0x4CB
#define FLAG_0x4CC               0x4CC
#define FLAG_0x4CD               0x4CD
#define FLAG_0x4CE               0x4CE
#define FLAG_0x4CF               0x4CF
#define FLAG_0x4D0               0x4D0
#define FLAG_0x4D1               0x4D1
#define FLAG_0x4D2               0x4D2
#define FLAG_0x4D3               0x4D3
#define FLAG_0x4D4               0x4D4
#define FLAG_0x4D5               0x4D5
#define FLAG_0x4D6               0x4D6
#define FLAG_0x4D7               0x4D7
#define FLAG_0x4D8               0x4D8
#define FLAG_0x4D9               0x4D9
#define FLAG_0x4DA               0x4DA
#define FLAG_0x4DB               0x4DB
#define FLAG_0x4DC               0x4DC
#define FLAG_0x4DD               0x4DD
#define FLAG_0x4DE               0x4DE
#define FLAG_0x4DF               0x4DF
#define FLAG_0x4E0               0x4E0
#define FLAG_0x4E1               0x4E1
#define FLAG_0x4E2               0x4E2
#define FLAG_0x4E3               0x4E3
#define FLAG_0x4E4               0x4E4
#define FLAG_0x4E5               0x4E5
#define FLAG_0x4E6               0x4E6
#define FLAG_0x4E7               0x4E7
// Hoenn (Lilycove), new; 0x4E8-0x4FF cannot be hidden item flags (see above)
#define FLAG_ITEM_LILYCOVE_CITY_MAX_REPEL        0x4E8
#define FLAG_RECEIVED_LILYCOVE_GENTLEMAN_BERRY   0x4E9
#define FLAG_RECEIVED_LILYCOVE_PECHA_BERRY       0x4EA
#define FLAG_RECEIVED_LILYCOVE_TM44              0x4EB
#define FLAG_0x4EC               0x4EC
#define FLAG_0x4ED               0x4ED
#define FLAG_0x4EE               0x4EE
#define FLAG_0x4EF               0x4EF
#define FLAG_0x4F0               0x4F0
#define FLAG_0x4F1               0x4F1
#define FLAG_0x4F2               0x4F2
#define FLAG_0x4F3               0x4F3
#define FLAG_0x4F4               0x4F4
#define FLAG_0x4F5               0x4F5
#define FLAG_0x4F6               0x4F6
#define FLAG_0x4F7               0x4F7
#define FLAG_0x4F8               0x4F8
#define FLAG_0x4F9               0x4F9
#define FLAG_0x4FA               0x4FA
#define FLAG_0x4FB               0x4FB
#define FLAG_0x4FC               0x4FC
#define FLAG_0x4FD               0x4FD
#define FLAG_0x4FE               0x4FE
#define FLAG_0x4FF               0x4FF

#define TRAINER_FLAGS_START      (FLAG_0x4FF + 1)
#define TRAINER_FLAGS_END        (TRAINER_FLAGS_START + MAX_TRAINERS_COUNT - 1) // 0x7FF

// SYSTEM FLAGS

#define SYS_FLAGS (TRAINER_FLAGS_END + 1) // 0x800

// Temporary system flags
#define FLAG_SYS_SAFARI_MODE                                        (SYS_FLAGS + 0x0)
#define FLAG_SYS_VS_SEEKER_CHARGING                                 (SYS_FLAGS + 0x1)
#define FLAG_SYS_CRUISE_MODE                                        (SYS_FLAGS + 0x2)
#define FLAG_SYS_WHITE_FLUTE_ACTIVE                                 (SYS_FLAGS + 0x3)
#define FLAG_SYS_BLACK_FLUTE_ACTIVE                                 (SYS_FLAGS + 0x4)
#define FLAG_SYS_USE_STRENGTH                                       (SYS_FLAGS + 0x5)
#define FLAG_SYS_FLASH_ACTIVE                                       (SYS_FLAGS + 0x6)
#define FLAG_SYS_SPECIAL_WILD_BATTLE                                (SYS_FLAGS + 0x7)

#define FLAG_SYS_QL_DEPARTED                                        (SYS_FLAGS + 0x8)
#define FLAG_SYS_IN_OPTIONS_MENU                                    (SYS_FLAGS + 0x9)
#define FLAG_0x80A                                                  (SYS_FLAGS + 0xA)
#define FLAG_0x80B                                                  (SYS_FLAGS + 0xB)
#define FLAG_0x80C                                                  (SYS_FLAGS + 0xC)
#define FLAG_0x80D                                                  (SYS_FLAGS + 0xD)
#define FLAG_0x80E                                                  (SYS_FLAGS + 0xE)
#define FLAG_0x80F                                                  (SYS_FLAGS + 0xF)
#define FLAG_0x810                                                  (SYS_FLAGS + 0x10)
#define FLAG_0x811                                                  (SYS_FLAGS + 0x11)
#define FLAG_0x812                                                  (SYS_FLAGS + 0x12)
#define FLAG_0x813                                                  (SYS_FLAGS + 0x13)
#define FLAG_0x814                                                  (SYS_FLAGS + 0x14)
#define FLAG_0x815                                                  (SYS_FLAGS + 0x15)
#define FLAG_0x816                                                  (SYS_FLAGS + 0x16)
#define FLAG_0x817                                                  (SYS_FLAGS + 0x17)
#define FLAG_0x818                                                  (SYS_FLAGS + 0x18)
#define FLAG_0x819                                                  (SYS_FLAGS + 0x19)
#define FLAG_0x81A                                                  (SYS_FLAGS + 0x1A)
#define FLAG_0x81B                                                  (SYS_FLAGS + 0x1B)
#define FLAG_0x81C                                                  (SYS_FLAGS + 0x1C)
#define FLAG_0x81D                                                  (SYS_FLAGS + 0x1D)
#define FLAG_0x81E                                                  (SYS_FLAGS + 0x1E)
#define FLAG_0x81F                                                  (SYS_FLAGS + 0x1F)

// Permanent system flags
#define PERMA_SYS_FLAGS_START                                       (FLAG_0x81F + 1)

#define FLAG_BADGE01_GET                                            (SYS_FLAGS + 0x20)
#define FLAG_BADGE02_GET                                            (SYS_FLAGS + 0x21)
#define FLAG_BADGE03_GET                                            (SYS_FLAGS + 0x22)
#define FLAG_BADGE04_GET                                            (SYS_FLAGS + 0x23)
#define FLAG_BADGE05_GET                                            (SYS_FLAGS + 0x24)
#define FLAG_BADGE06_GET                                            (SYS_FLAGS + 0x25)
#define FLAG_BADGE07_GET                                            (SYS_FLAGS + 0x26)
#define FLAG_BADGE08_GET                                            (SYS_FLAGS + 0x27)
#define NUM_BADGES                                                  (1 + FLAG_BADGE08_GET - FLAG_BADGE01_GET)

#define FLAG_SYS_POKEMON_GET                                        (SYS_FLAGS + 0x28)
#define FLAG_SYS_POKEDEX_GET                                        (SYS_FLAGS + 0x29)
#define FLAG_SYS_CTRL_OBJ_DELETE                                    (SYS_FLAGS + 0x2A)
#define FLAG_SYS_IS_LINKING                                         (SYS_FLAGS + 0x2B)
#define FLAG_SYS_GAME_CLEAR_OLD                                     (SYS_FLAGS + 0x2C)  // Needs to be set to link with XD. New FLAG_SYS_GAME_CLEAR (now used in scripts) is at the bottom.
#define FLAG_SYS_SET_TRAINER_CARD_PROFILE                           (SYS_FLAGS + 0x2D)
#define FLAG_0x82E                                                  (SYS_FLAGS + 0x2E)
#define FLAG_SYS_B_DASH                                             (SYS_FLAGS + 0x2F)
#define FLAG_SYS_ON_CYCLING_ROAD                                    (SYS_FLAGS + 0x30)
#define FLAG_SYS_RECEIVED_EXTENDED_DEX                              (SYS_FLAGS + 0x31)
#define FLAG_SYS_EXTENDED_DEX_TOGGLE                                (SYS_FLAGS + 0x32)
#define FLAG_SYS_ON_RESUME                                          (SYS_FLAGS + 0x33) // Cleared when an OnResume map script could fire
#define FLAG_SYS_NOT_SOMEONES_PC                                    (SYS_FLAGS + 0x34)
#define FLAG_0x835                                                  (SYS_FLAGS + 0x35)
#define FLAG_0x836                                                  (SYS_FLAGS + 0x36)
#define FLAG_SYS_RESET_RTC_ENABLE                                   (SYS_FLAGS + 0x37)
#define FLAG_0x838                                                  (SYS_FLAGS + 0x38) // Set, never read
#define FLAG_SYS_MYSTERY_GIFT_ENABLED                               (SYS_FLAGS + 0x39)
#define FLAG_0x83A                                                  (SYS_FLAGS + 0x3A)
#define FLAG_SYS_RIBBON_GET                                         (SYS_FLAGS + 0x3B)
#define FLAG_SYS_SAW_HELP_SYSTEM_INTRO                              (SYS_FLAGS + 0x3C)
#define FLAG_0x83D                                                  (SYS_FLAGS + 0x3D)
#define FLAG_OPENED_START_MENU                                      (SYS_FLAGS + 0x3E)
#define FLAG_0x83F                                                  (SYS_FLAGS + 0x3F)
#define FLAG_SYS_NATIONAL_DEX                                       (SYS_FLAGS + 0x40)
#define FLAG_SYS_PC_STORAGE_DISABLED                                (SYS_FLAGS + 0x41)
#define FLAG_SYS_INFORMED_OF_LOCAL_WIRELESS_PLAYER                  (SYS_FLAGS + 0x42)
#define FLAG_SHOWN_BOX_WAS_FULL_MESSAGE                             (SYS_FLAGS + 0x43)
#define FLAG_SYS_CAN_LINK_WITH_RS                                   (SYS_FLAGS + 0x44)
#define FLAG_SYS_SEVII_MAP_123                                      (SYS_FLAGS + 0x45)
#define FLAG_SYS_SEVII_MAP_4567                                     (SYS_FLAGS + 0x46)
#define FLAG_SYS_GOT_BERRY_POUCH                                    (SYS_FLAGS + 0x47)
#define FLAG_SYS_DEOXYS_AWAKENED                                    (SYS_FLAGS + 0x48)
#define FLAG_SYS_UNLOCKED_TANOBY_RUINS                              (SYS_FLAGS + 0x49)
#define FLAG_ENABLE_SHIP_NAVEL_ROCK                                 (SYS_FLAGS + 0x4A)
#define FLAG_ENABLE_SHIP_BIRTH_ISLAND                               (SYS_FLAGS + 0x4B)

// World Map Flags
#define FLAG_WORLD_MAP_PALLET_TOWN                                  (SYS_FLAGS + 0x90)
#define FLAG_WORLD_MAP_VIRIDIAN_CITY                                (SYS_FLAGS + 0x91)
#define FLAG_WORLD_MAP_PEWTER_CITY                                  (SYS_FLAGS + 0x92)
#define FLAG_WORLD_MAP_CERULEAN_CITY                                (SYS_FLAGS + 0x93)
#define FLAG_WORLD_MAP_LAVENDER_TOWN                                (SYS_FLAGS + 0x94)
#define FLAG_WORLD_MAP_VERMILION_CITY                               (SYS_FLAGS + 0x95)
#define FLAG_WORLD_MAP_CELADON_CITY                                 (SYS_FLAGS + 0x96)
#define FLAG_WORLD_MAP_FUCHSIA_CITY                                 (SYS_FLAGS + 0x97)
#define FLAG_WORLD_MAP_CINNABAR_ISLAND                              (SYS_FLAGS + 0x98)
#define FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR                      (SYS_FLAGS + 0x99)
#define FLAG_WORLD_MAP_SAFFRON_CITY                                 (SYS_FLAGS + 0x9A)
#define FLAG_WORLD_MAP_ONE_ISLAND                                   (SYS_FLAGS + 0x9B)
#define FLAG_WORLD_MAP_TWO_ISLAND                                   (SYS_FLAGS + 0x9C)
#define FLAG_WORLD_MAP_THREE_ISLAND                                 (SYS_FLAGS + 0x9D)
#define FLAG_WORLD_MAP_FOUR_ISLAND                                  (SYS_FLAGS + 0x9E)
#define FLAG_WORLD_MAP_FIVE_ISLAND                                  (SYS_FLAGS + 0x9F)
#define FLAG_WORLD_MAP_SEVEN_ISLAND                                 (SYS_FLAGS + 0xA0)
#define FLAG_WORLD_MAP_SIX_ISLAND                                   (SYS_FLAGS + 0xA1)
#define FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F                     (SYS_FLAGS + 0xA2)
#define FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F                    (SYS_FLAGS + 0xA3)
#define FLAG_WORLD_MAP_VIRIDIAN_FOREST                              (SYS_FLAGS + 0xA4)
#define FLAG_WORLD_MAP_MT_MOON_1F                                   (SYS_FLAGS + 0xA5)
#define FLAG_WORLD_MAP_SSANNE_EXTERIOR                              (SYS_FLAGS + 0xA6)
#define FLAG_WORLD_MAP_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL          (SYS_FLAGS + 0xA7)
#define FLAG_WORLD_MAP_UNDERGROUND_PATH_EAST_WEST_TUNNEL            (SYS_FLAGS + 0xA8)
#define FLAG_WORLD_MAP_DIGLETTS_CAVE_B1F                            (SYS_FLAGS + 0xA9)
#define FLAG_WORLD_MAP_VICTORY_ROAD_1F                              (SYS_FLAGS + 0xAA)
#define FLAG_WORLD_MAP_ROCKET_HIDEOUT_B1F                           (SYS_FLAGS + 0xAB)
#define FLAG_WORLD_MAP_SILPH_CO_1F                                  (SYS_FLAGS + 0xAC)
#define FLAG_WORLD_MAP_POKEMON_MANSION_1F                           (SYS_FLAGS + 0xAD)
#define FLAG_WORLD_MAP_SAFARI_ZONE_CENTER                           (SYS_FLAGS + 0xAE)
#define FLAG_WORLD_MAP_POKEMON_LEAGUE_LORELEIS_ROOM                 (SYS_FLAGS + 0xAF)
#define FLAG_WORLD_MAP_ROCK_TUNNEL_1F                               (SYS_FLAGS + 0xB0)
#define FLAG_WORLD_MAP_SEAFOAM_ISLANDS_1F                           (SYS_FLAGS + 0xB1)
#define FLAG_WORLD_MAP_POKEMON_TOWER_1F                             (SYS_FLAGS + 0xB2)
#define FLAG_WORLD_MAP_CERULEAN_CAVE_1F                             (SYS_FLAGS + 0xB3)
#define FLAG_WORLD_MAP_POWER_PLANT                                  (SYS_FLAGS + 0xB4)
#define FLAG_WORLD_MAP_NAVEL_ROCK_EXTERIOR                          (SYS_FLAGS + 0xB5)
#define FLAG_WORLD_MAP_MT_EMBER_EXTERIOR                            (SYS_FLAGS + 0xB6)
#define FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST                    (SYS_FLAGS + 0xB7)
#define FLAG_WORLD_MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE            (SYS_FLAGS + 0xB8)
#define FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE                 (SYS_FLAGS + 0xB9)
#define FLAG_WORLD_MAP_TRAINER_TOWER_LOBBY                          (SYS_FLAGS + 0xBA)
#define FLAG_WORLD_MAP_SIX_ISLAND_DOTTED_HOLE_1F                    (SYS_FLAGS + 0xBB)
#define FLAG_WORLD_MAP_FIVE_ISLAND_LOST_CAVE_ENTRANCE               (SYS_FLAGS + 0xBC)
#define FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH                      (SYS_FLAGS + 0xBD)
#define FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE                     (SYS_FLAGS + 0xBE)
#define FLAG_WORLD_MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER     (SYS_FLAGS + 0xBF)
#define FLAG_WORLD_MAP_THREE_ISLAND_DUNSPARCE_TUNNEL                (SYS_FLAGS + 0xC0)
#define FLAG_WORLD_MAP_SEVEN_ISLAND_SEVAULT_CANYON_TANOBY_KEY       (SYS_FLAGS + 0xC1)
#define FLAG_WORLD_MAP_BIRTH_ISLAND_EXTERIOR                        (SYS_FLAGS + 0xC2)

// Hoenn towns, in MAPSEC order (Fly), then Hoenn dungeons (Town Map icons): set on entering the section
#define FLAG_WORLD_MAP_LITTLEROOT_TOWN                              (SYS_FLAGS + 0xC3)
#define FLAG_WORLD_MAP_OLDALE_TOWN                                  (SYS_FLAGS + 0xC4)
#define FLAG_WORLD_MAP_DEWFORD_TOWN                                 (SYS_FLAGS + 0xC5)
#define FLAG_WORLD_MAP_LAVARIDGE_TOWN                               (SYS_FLAGS + 0xC6)
#define FLAG_WORLD_MAP_FALLARBOR_TOWN                               (SYS_FLAGS + 0xC7)
#define FLAG_WORLD_MAP_VERDANTURF_TOWN                              (SYS_FLAGS + 0xC8)
#define FLAG_WORLD_MAP_PACIFIDLOG_TOWN                              (SYS_FLAGS + 0xC9)
#define FLAG_WORLD_MAP_PETALBURG_CITY                               (SYS_FLAGS + 0xCA)
#define FLAG_WORLD_MAP_SLATEPORT_CITY                               (SYS_FLAGS + 0xCB)
#define FLAG_WORLD_MAP_MAUVILLE_CITY                                (SYS_FLAGS + 0xCC)
#define FLAG_WORLD_MAP_RUSTBORO_CITY                                (SYS_FLAGS + 0xCD)
#define FLAG_WORLD_MAP_FORTREE_CITY                                 (SYS_FLAGS + 0xCE)
#define FLAG_WORLD_MAP_LILYCOVE_CITY                                (SYS_FLAGS + 0xCF)
#define FLAG_WORLD_MAP_MOSSDEEP_CITY                                (SYS_FLAGS + 0xD0)
#define FLAG_WORLD_MAP_SOOTOPOLIS_CITY                              (SYS_FLAGS + 0xD1)
#define FLAG_WORLD_MAP_EVER_GRANDE_CITY                             (SYS_FLAGS + 0xD2)
#define FLAG_0x8D3                                                  (SYS_FLAGS + 0xD3)
#define FLAG_0x8D4                                                  (SYS_FLAGS + 0xD4)
#define FLAG_SYS_GAME_CLEAR                                         (SYS_FLAGS + 0xD5)
#define FLAG_WORLD_MAP_PETALBURG_WOODS                              (SYS_FLAGS + 0xD6)
#define FLAG_WORLD_MAP_RUSTURF_TUNNEL                               (SYS_FLAGS + 0xD7)
#define FLAG_WORLD_MAP_GRANITE_CAVE                                 (SYS_FLAGS + 0xD8)
#define FLAG_WORLD_MAP_METEOR_FALLS                                 (SYS_FLAGS + 0xD9)
#define FLAG_WORLD_MAP_MT_CHIMNEY                                   (SYS_FLAGS + 0xDA)
#define FLAG_WORLD_MAP_JAGGED_PASS                                  (SYS_FLAGS + 0xDB)
#define FLAG_WORLD_MAP_FIERY_PATH                                   (SYS_FLAGS + 0xDC)
#define FLAG_WORLD_MAP_MAGMA_HIDEOUT                                (SYS_FLAGS + 0xDD)
#define FLAG_WORLD_MAP_NEW_MAUVILLE                                 (SYS_FLAGS + 0xDE)
#define FLAG_WORLD_MAP_ABANDONED_SHIP                               (SYS_FLAGS + 0xDF)
#define FLAG_WORLD_MAP_MT_PYRE                                      (SYS_FLAGS + 0xE0)
#define FLAG_WORLD_MAP_AQUA_HIDEOUT                                 (SYS_FLAGS + 0xE1)
#define FLAG_WORLD_MAP_SHOAL_CAVE                                   (SYS_FLAGS + 0xE2)
#define FLAG_WORLD_MAP_SEAFLOOR_CAVERN                              (SYS_FLAGS + 0xE3)
#define FLAG_WORLD_MAP_CAVE_OF_ORIGIN                               (SYS_FLAGS + 0xE4)
#define FLAG_WORLD_MAP_VICTORY_ROAD                                 (SYS_FLAGS + 0xE5)
#define FLAG_WORLD_MAP_DESERT_RUINS                                 (SYS_FLAGS + 0xE6)
#define FLAG_WORLD_MAP_ISLAND_CAVE                                  (SYS_FLAGS + 0xE7)
#define FLAG_WORLD_MAP_ANCIENT_TOMB                                 (SYS_FLAGS + 0xE8)
#define FLAG_WORLD_MAP_SEALED_CHAMBER                               (SYS_FLAGS + 0xE9)
#define FLAG_WORLD_MAP_SKY_PILLAR                                   (SYS_FLAGS + 0xEA)
#define FLAG_WORLD_MAP_MIRAGE_TOWER                                 (SYS_FLAGS + 0xEB)
#define FLAG_WORLD_MAP_SCORCHED_SLAB                                (SYS_FLAGS + 0xEC)
#define FLAG_WORLD_MAP_DESERT_UNDERPASS                             (SYS_FLAGS + 0xED)
#define FLAG_WORLD_MAP_ALTERING_CAVE_E                              (SYS_FLAGS + 0xEE)
#define FLAG_0x8EF                                                  (SYS_FLAGS + 0xEF)
#define FLAG_0x8F0                                                  (SYS_FLAGS + 0xF0)
#define FLAG_0x8F1                                                  (SYS_FLAGS + 0xF1)
#define FLAG_0x8F2                                                  (SYS_FLAGS + 0xF2)
#define FLAG_0x8F3                                                  (SYS_FLAGS + 0xF3)
#define FLAG_0x8F4                                                  (SYS_FLAGS + 0xF4)
#define FLAG_0x8F5                                                  (SYS_FLAGS + 0xF5)
#define FLAG_0x8F6                                                  (SYS_FLAGS + 0xF6)
#define FLAG_0x8F7                                                  (SYS_FLAGS + 0xF7)
#define FLAG_0x8F8                                                  (SYS_FLAGS + 0xF8)
#define FLAG_0x8F9                                                  (SYS_FLAGS + 0xF9)
#define FLAG_0x8FA                                                  (SYS_FLAGS + 0xFA)
#define FLAG_0x8FB                                                  (SYS_FLAGS + 0xFB)
#define FLAG_0x8FC                                                  (SYS_FLAGS + 0xFC)
#define FLAG_0x8FD                                                  (SYS_FLAGS + 0xFD)
#define FLAG_0x8FE                                                  (SYS_FLAGS + 0xFE)
#define FLAG_0x8FF                                                  (SYS_FLAGS + 0xFF)

#define FLAGS_COUNT (FLAG_0x8FF + 1)

// Extended flags (RFVF+): SaveBlock2's extFlags, an old filler that is zero in every older save. Not saved in Quest Log scenes.
#define EXT_FLAGS_START          FLAGS_COUNT // 0x900
#define EXT_FLAGS_COUNT          0x2000
// Trainers past Kanto's MAX_TRAINERS_COUNT, in region blocks: Hoenn 768-1791 (0x900-0xCFF), Johto 1792-2815 (0xD00-0x10FF)
#define TRAINER_FLAGS_EXT_START  EXT_FLAGS_START
#define EXT_EVENT_FLAGS_START    (EXT_FLAGS_START + 0x800) // 0x1100-0x28FF: free for region events
#define TRAINER_FLAG(trainerId)  ((trainerId) < MAX_TRAINERS_COUNT ? TRAINER_FLAGS_START + (trainerId) : TRAINER_FLAGS_EXT_START + (trainerId) - MAX_TRAINERS_COUNT)

// Hoenn (Emerald's names; the badges are HOENN_ here, Kanto's keep FLAG_BADGE0X_GET)
#define FLAG_LANDMARK_POKEMON_LEAGUE      (EXT_EVENT_FLAGS_START + 0x00)
#define FLAG_HOENN_BADGE01_GET            (EXT_EVENT_FLAGS_START + 0x01)
#define FLAG_HOENN_BADGE02_GET            (EXT_EVENT_FLAGS_START + 0x02)
#define FLAG_HOENN_BADGE03_GET            (EXT_EVENT_FLAGS_START + 0x03)
#define FLAG_HOENN_BADGE04_GET            (EXT_EVENT_FLAGS_START + 0x04)
#define FLAG_HOENN_BADGE05_GET            (EXT_EVENT_FLAGS_START + 0x05)
#define FLAG_HOENN_BADGE06_GET            (EXT_EVENT_FLAGS_START + 0x06)
#define FLAG_HOENN_BADGE07_GET            (EXT_EVENT_FLAGS_START + 0x07)
#define FLAG_HOENN_BADGE08_GET            (EXT_EVENT_FLAGS_START + 0x08)
#define FLAG_DEFEATED_RUSTBORO_GYM        (EXT_EVENT_FLAGS_START + 0x09)
#define FLAG_DEFEATED_DEWFORD_GYM         (EXT_EVENT_FLAGS_START + 0x0A)
#define FLAG_DEFEATED_MAUVILLE_GYM        (EXT_EVENT_FLAGS_START + 0x0B)
#define FLAG_DEFEATED_LAVARIDGE_GYM       (EXT_EVENT_FLAGS_START + 0x0C)
#define FLAG_DEFEATED_PETALBURG_GYM       (EXT_EVENT_FLAGS_START + 0x0D)
#define FLAG_DEFEATED_FORTREE_GYM         (EXT_EVENT_FLAGS_START + 0x0E)
#define FLAG_DEFEATED_MOSSDEEP_GYM        (EXT_EVENT_FLAGS_START + 0x0F)
#define FLAG_DEFEATED_SOOTOPOLIS_GYM      (EXT_EVENT_FLAGS_START + 0x10)
#define FLAG_RECEIVED_TM_ROCK_TOMB        (EXT_EVENT_FLAGS_START + 0x11)
#define FLAG_RECEIVED_TM_BULK_UP          (EXT_EVENT_FLAGS_START + 0x12)
#define FLAG_RECEIVED_TM_SHOCK_WAVE       (EXT_EVENT_FLAGS_START + 0x13)
#define FLAG_RECEIVED_TM_OVERHEAT         (EXT_EVENT_FLAGS_START + 0x14)
#define FLAG_RECEIVED_TM_FACADE           (EXT_EVENT_FLAGS_START + 0x15)
#define FLAG_RECEIVED_TM_AERIAL_ACE       (EXT_EVENT_FLAGS_START + 0x16)
#define FLAG_RECEIVED_TM_CALM_MIND        (EXT_EVENT_FLAGS_START + 0x17)
#define FLAG_RECEIVED_TM_WATER_PULSE      (EXT_EVENT_FLAGS_START + 0x18)
#define FLAG_DEFEATED_ELITE_4_SIDNEY      (EXT_EVENT_FLAGS_START + 0x19)
#define FLAG_DEFEATED_ELITE_4_PHOEBE      (EXT_EVENT_FLAGS_START + 0x1A)
#define FLAG_DEFEATED_ELITE_4_GLACIA      (EXT_EVENT_FLAGS_START + 0x1B)
#define FLAG_DEFEATED_ELITE_4_DRAKE       (EXT_EVENT_FLAGS_START + 0x1C)
#define FLAG_ENTERED_ELITE_FOUR           (EXT_EVENT_FLAGS_START + 0x1D)
#define FLAG_HOENN_GAME_CLEAR             (EXT_EVENT_FLAGS_START + 0x1E) // Hoenn's Hall of Fame: gym leader rematches
#define FLAG_MAUVILLE_GYM_BARRIERS_STATE  (EXT_EVENT_FLAGS_START + 0x1F)
#define FLAG_MOSSDEEP_GYM_SWITCH_1        (EXT_EVENT_FLAGS_START + 0x20)
#define FLAG_MOSSDEEP_GYM_SWITCH_2        (EXT_EVENT_FLAGS_START + 0x21)
#define FLAG_MOSSDEEP_GYM_SWITCH_3        (EXT_EVENT_FLAGS_START + 0x22)
#define FLAG_MOSSDEEP_GYM_SWITCH_4        (EXT_EVENT_FLAGS_START + 0x23)
#define FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE   (EXT_EVENT_FLAGS_START + 0x24)
#define FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE   (EXT_EVENT_FLAGS_START + 0x25)
#define FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE   (EXT_EVENT_FLAGS_START + 0x26)
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1       (EXT_EVENT_FLAGS_START + 0x27)
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2       (EXT_EVENT_FLAGS_START + 0x28)
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3       (EXT_EVENT_FLAGS_START + 0x29)
#define FLAG_GOT_BASEMENT_KEY_FROM_WATTSON     (EXT_EVENT_FLAGS_START + 0x2A)
#define FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON   (EXT_EVENT_FLAGS_START + 0x2B)
#define FLAG_LANDMARK_NEW_MAUVILLE             (EXT_EVENT_FLAGS_START + 0x2C)
#define FLAG_LANDMARK_TRICK_HOUSE              (EXT_EVENT_FLAGS_START + 0x2D)
#define FLAG_HIDE_TRICK_HOUSE_ENTRANCE_MAN     (EXT_EVENT_FLAGS_START + 0x2E)
#define FLAG_HIDE_TRICK_HOUSE_END_MAN          (EXT_EVENT_FLAGS_START + 0x2F)
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1     (EXT_EVENT_FLAGS_START + 0x30)
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2     (EXT_EVENT_FLAGS_START + 0x31)
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3     (EXT_EVENT_FLAGS_START + 0x32)
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4     (EXT_EVENT_FLAGS_START + 0x33)
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5     (EXT_EVENT_FLAGS_START + 0x34)
#define FLAG_LANDMARK_WINSTRATE_FAMILY         (EXT_EVENT_FLAGS_START + 0x35)
#define FLAG_RECEIVED_MACHO_BRACE              (EXT_EVENT_FLAGS_START + 0x36)
#define FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE   (EXT_EVENT_FLAGS_START + 0x37)
#define FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE (EXT_EVENT_FLAGS_START + 0x38)
#define FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE     (EXT_EVENT_FLAGS_START + 0x39)
#define FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE    (EXT_EVENT_FLAGS_START + 0x3A)
#define FLAG_BIKE_UPGRADED                     (EXT_EVENT_FLAGS_START + 0x3B) // Rodolphe (Mauville): the Bicycle has the Mach and Acro moves (bike.c)
#define FLAG_RECEIVED_20_COINS                 (EXT_EVENT_FLAGS_START + 0x3C) // Mauville Game Corner (Emerald 0xE1)
#define FLAG_RECEIVED_STARTER_DOLL             (EXT_EVENT_FLAGS_START + 0x3D) // RFVF+: the girl gives a Hoenn starter, not a doll
// Hoenn gifts and trades (point 1 scripts, Emerald names)
#define FLAG_RECEIVED_POTION_OLDALE            (EXT_EVENT_FLAGS_START + 0x3E)
#define FLAG_RECEIVED_MIRACLE_SEED             (EXT_EVENT_FLAGS_START + 0x3F)
#define FLAG_RECEIVED_EXP_SHARE                (EXT_EVENT_FLAGS_START + 0x40)
#define FLAG_RECEIVED_PREMIER_BALL_RUSTBORO    (EXT_EVENT_FLAGS_START + 0x41)
#define FLAG_RUSTBORO_NPC_TRADE_COMPLETED      (EXT_EVENT_FLAGS_START + 0x42)
#define FLAG_RECEIVED_QUICK_CLAW               (EXT_EVENT_FLAGS_START + 0x43)
#define FLAG_RECEIVED_REVIVED_FOSSIL_MON       (EXT_EVENT_FLAGS_START + 0x44)
// Hoenn special scripts (tools/hoenn_import/scripts_speciaux.md), Emerald names: EXT_EVENT_FLAGS_START + 0x20B-0x23F and
// 0x2A0-0x3FF (0x200-0x20A belong to Johto's items, johto_flags.json; the 11 Hoenn flags first put there moved to 0x2A0)
// The FLAG_DAILY_* are never reset here: those NPCs give their berry the first time only (user's choice).
#define FLAG_RECEIVED_6_SODA_POP               (EXT_EVENT_FLAGS_START + 0x2A0)
#define FLAG_RECEIVED_BELDUM                   (EXT_EVENT_FLAGS_START + 0x2A1)
#define FLAG_RECEIVED_BLUE_SCARF               (EXT_EVENT_FLAGS_START + 0x2A2)
#define FLAG_RECEIVED_CASTFORM                 (EXT_EVENT_FLAGS_START + 0x2A3)
#define FLAG_RECEIVED_CHARCOAL                 (EXT_EVENT_FLAGS_START + 0x2A4)
#define FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104   (EXT_EVENT_FLAGS_START + 0x2A5)
#define FLAG_RECEIVED_GOOD_ROD                 (EXT_EVENT_FLAGS_START + 0x2A6)
#define FLAG_RECEIVED_GREEN_SCARF              (EXT_EVENT_FLAGS_START + 0x2A7)
#define FLAG_RECEIVED_KINGS_ROCK               (EXT_EVENT_FLAGS_START + 0x2A8)
#define FLAG_RECEIVED_LAVARIDGE_EGG            (EXT_EVENT_FLAGS_START + 0x2A9)
#define FLAG_RECEIVED_MENTAL_HERB              (EXT_EVENT_FLAGS_START + 0x2AA)
#define FLAG_RECEIVED_PINK_SCARF               (EXT_EVENT_FLAGS_START + 0x20B)
#define FLAG_RECEIVED_POWDER_JAR               (EXT_EVENT_FLAGS_START + 0x20C)
#define FLAG_RECEIVED_RED_SCARF                (EXT_EVENT_FLAGS_START + 0x20D)
#define FLAG_RECEIVED_SECRET_POWER             (EXT_EVENT_FLAGS_START + 0x20E)
#define FLAG_RECEIVED_SOFT_SAND                (EXT_EVENT_FLAGS_START + 0x20F)
#define FLAG_RECEIVED_SOOTHE_BELL              (EXT_EVENT_FLAGS_START + 0x210)
#define FLAG_RECEIVED_SUN_STONE_MOSSDEEP       (EXT_EVENT_FLAGS_START + 0x211)
#define FLAG_RECEIVED_SUPER_ROD                (EXT_EVENT_FLAGS_START + 0x212)
#define FLAG_RECEIVED_TM_ATTRACT               (EXT_EVENT_FLAGS_START + 0x213)
#define FLAG_RECEIVED_TM_BRICK_BREAK           (EXT_EVENT_FLAGS_START + 0x214)
#define FLAG_RECEIVED_TM_BULLET_SEED           (EXT_EVENT_FLAGS_START + 0x215)
#define FLAG_RECEIVED_TM_DIG                   (EXT_EVENT_FLAGS_START + 0x216)
#define FLAG_RECEIVED_TM_GIGA_DRAIN            (EXT_EVENT_FLAGS_START + 0x217)
#define FLAG_RECEIVED_TM_HIDDEN_POWER          (EXT_EVENT_FLAGS_START + 0x218)
#define FLAG_RECEIVED_TM_RETURN                (EXT_EVENT_FLAGS_START + 0x219)
#define FLAG_RECEIVED_TM_ROAR                  (EXT_EVENT_FLAGS_START + 0x21A)
#define FLAG_RECEIVED_TM_TORMENT               (EXT_EVENT_FLAGS_START + 0x21B)
#define FLAG_RECEIVED_WAILMER_PAIL             (EXT_EVENT_FLAGS_START + 0x21C)
#define FLAG_RECEIVED_WHITE_HERB               (EXT_EVENT_FLAGS_START + 0x21D)
#define FLAG_RECEIVED_YELLOW_SCARF             (EXT_EVENT_FLAGS_START + 0x21E)
#define FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK     (EXT_EVENT_FLAGS_START + 0x21F)
#define FLAG_MET_DIVING_TREASURE_HUNTER        (EXT_EVENT_FLAGS_START + 0x220)
#define FLAG_MET_FANCLUB_YOUNGER_BROTHER       (EXT_EVENT_FLAGS_START + 0x221)
#define FLAG_MET_HIDDEN_POWER_GIVER            (EXT_EVENT_FLAGS_START + 0x222)
#define FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN    (EXT_EVENT_FLAGS_START + 0x223)
#define FLAG_FORTREE_NPC_TRADE_COMPLETED       (EXT_EVENT_FLAGS_START + 0x224)
#define FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED    (EXT_EVENT_FLAGS_START + 0x225)
#define FLAG_DEFEATED_SEASHORE_HOUSE           (EXT_EVENT_FLAGS_START + 0x226)
#define FLAG_WINGULL_SENT_ON_ERRAND            (EXT_EVENT_FLAGS_START + 0x227)
#define FLAG_WINGULL_DELIVERED_MAIL            (EXT_EVENT_FLAGS_START + 0x228)
#define FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL (EXT_EVENT_FLAGS_START + 0x229)
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL (EXT_EVENT_FLAGS_START + 0x22A)
#define FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY  (EXT_EVENT_FLAGS_START + 0x22B)
#define FLAG_DAILY_ROUTE_111_RECEIVED_BERRY    (EXT_EVENT_FLAGS_START + 0x22C)
#define FLAG_DAILY_ROUTE_114_RECEIVED_BERRY    (EXT_EVENT_FLAGS_START + 0x22D)
#define FLAG_DAILY_ROUTE_120_RECEIVED_BERRY    (EXT_EVENT_FLAGS_START + 0x22E)
#define FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY (EXT_EVENT_FLAGS_START + 0x22F)
#define FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL (EXT_EVENT_FLAGS_START + 0x230)
#define FLAG_HIDE_ROUTE_116_DROPPED_GLASSES_MAN (EXT_EVENT_FLAGS_START + 0x231)
#define FLAG_EXCHANGED_SCANNER                 (EXT_EVENT_FLAGS_START + 0x232)
// Batch 2 (systems), Emerald names
#define FLAG_MET_PRETTY_PETAL_SHOP_OWNER       (EXT_EVENT_FLAGS_START + 0x233)
#define FLAG_RECEIVED_DOLL_LANETTE             (EXT_EVENT_FLAGS_START + 0x234)
#define FLAG_RECEIVED_WAILMER_DOLL             (EXT_EVENT_FLAGS_START + 0x235)
#define FLAG_DEWFORD_TRENDS_READY              (EXT_EVENT_FLAGS_START + 0x236) // RFVF+: dewfordTrends initialized
#define FLAG_SYS_CHANGED_DEWFORD_TREND         (EXT_EVENT_FLAGS_START + 0x237)
#define FLAG_UNLOCKED_TRENDY_SAYINGS           (EXT_EVENT_FLAGS_START + 0x238)
#define FLAG_RECEIVED_TM_SLUDGE_BOMB           (EXT_EVENT_FLAGS_START + 0x239)
#define FLAG_RECEIVED_SILK_SCARF               (EXT_EVENT_FLAGS_START + 0x23A)
// Batch 3 (dungeons), Emerald names. FLAG_DEFEATED_<legendary>: knocked out or fled, cleared by the next League win
// (EventScript_ResetHoennLegendaries, FRLG's rule); FLAG_CAUGHT_<legendary>: for good
#define FLAG_SYS_BRAILLE_DIG                   (EXT_EVENT_FLAGS_START + 0x2B0)
#define FLAG_REGI_DOORS_OPENED                 (EXT_EVENT_FLAGS_START + 0x2B1)
#define FLAG_SYS_REGIROCK_PUZZLE_COMPLETED     (EXT_EVENT_FLAGS_START + 0x2B2)
#define FLAG_SYS_BRAILLE_REGICE_COMPLETED      (EXT_EVENT_FLAGS_START + 0x2B3)
#define FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED    (EXT_EVENT_FLAGS_START + 0x2B4)
#define FLAG_DEFEATED_REGIROCK                 (EXT_EVENT_FLAGS_START + 0x2B5)
#define FLAG_DEFEATED_REGICE                   (EXT_EVENT_FLAGS_START + 0x2B6)
#define FLAG_DEFEATED_REGISTEEL                (EXT_EVENT_FLAGS_START + 0x2B7)
#define FLAG_DEFEATED_RAYQUAZA                 (EXT_EVENT_FLAGS_START + 0x2B8)
#define FLAG_DEFEATED_KYOGRE                   (EXT_EVENT_FLAGS_START + 0x2B9)
#define FLAG_DEFEATED_GROUDON                  (EXT_EVENT_FLAGS_START + 0x2BA)
#define FLAG_CAUGHT_REGIROCK                   (EXT_EVENT_FLAGS_START + 0x2BB)
#define FLAG_CAUGHT_REGICE                     (EXT_EVENT_FLAGS_START + 0x2BC)
#define FLAG_CAUGHT_REGISTEEL                  (EXT_EVENT_FLAGS_START + 0x2BD)
#define FLAG_CAUGHT_RAYQUAZA                   (EXT_EVENT_FLAGS_START + 0x2BE)
#define FLAG_CAUGHT_KYOGRE                     (EXT_EVENT_FLAGS_START + 0x2BF)
#define FLAG_CAUGHT_GROUDON                    (EXT_EVENT_FLAGS_START + 0x2C0)
#define FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT (EXT_EVENT_FLAGS_START + 0x2C1)
#define FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT (EXT_EVENT_FLAGS_START + 0x2C2)
#define FLAG_RECEIVED_SHOAL_SALT_1             (EXT_EVENT_FLAGS_START + 0x2C3) // the 8 salt/shell flags: cleared each day
#define FLAG_RECEIVED_SHOAL_SALT_2             (EXT_EVENT_FLAGS_START + 0x2C4)
#define FLAG_RECEIVED_SHOAL_SALT_3             (EXT_EVENT_FLAGS_START + 0x2C5)
#define FLAG_RECEIVED_SHOAL_SALT_4             (EXT_EVENT_FLAGS_START + 0x2C6)
#define FLAG_RECEIVED_SHOAL_SHELL_1            (EXT_EVENT_FLAGS_START + 0x2C7)
#define FLAG_RECEIVED_SHOAL_SHELL_2            (EXT_EVENT_FLAGS_START + 0x2C8)
#define FLAG_RECEIVED_SHOAL_SHELL_3            (EXT_EVENT_FLAGS_START + 0x2C9)
#define FLAG_RECEIVED_SHOAL_SHELL_4            (EXT_EVENT_FLAGS_START + 0x2CA)
#define FLAG_SYS_SHOAL_TIDE                    (EXT_EVENT_FLAGS_START + 0x2CB) // high tide (odd days)
#define FLAG_RECEIVED_FOCUS_BAND               (EXT_EVENT_FLAGS_START + 0x2CC)
#define FLAG_USED_STORAGE_KEY                  (EXT_EVENT_FLAGS_START + 0x2CD)
#define FLAG_USED_ROOM_1_KEY                   (EXT_EVENT_FLAGS_START + 0x2CE)
#define FLAG_USED_ROOM_2_KEY                   (EXT_EVENT_FLAGS_START + 0x2CF)
#define FLAG_USED_ROOM_4_KEY                   (EXT_EVENT_FLAGS_START + 0x2D0)
#define FLAG_USED_ROOM_6_KEY                   (EXT_EVENT_FLAGS_START + 0x2D1)
#define FLAG_CHOSE_ROOT_FOSSIL                 (EXT_EVENT_FLAGS_START + 0x2D2) // RFVF+: taken (both can be)
#define FLAG_CHOSE_CLAW_FOSSIL                 (EXT_EVENT_FLAGS_START + 0x2D3)
#define FLAG_RECEIVED_CLEANSE_TAG              (EXT_EVENT_FLAGS_START + 0x2D4)
#define FLAG_HIDE_ROUTE_111_PLAYER_DESCENT     (EXT_EVENT_FLAGS_START + 0x2D5) // the falling player of the tower's collapse
// Hoenn batches 4-5 (S.S. Tidal, Trainer Hill), Emerald names
#define FLAG_RECEIVED_TM_SNATCH                (EXT_EVENT_FLAGS_START + 0x2E0)
#define FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER  (EXT_EVENT_FLAGS_START + 0x2E1)
#define FLAG_DEFEATED_SS_TIDAL_TRAINERS        (EXT_EVENT_FLAGS_START + 0x2E2)
#define FLAG_MET_SCOTT_ON_SS_TIDAL             (EXT_EVENT_FLAGS_START + 0x2E3) // RFVF+: Scott's invite after the Hoenn League (lot 6)
// RFVF+: batch 6, Emerald's Battle Frontier (EXT_EVENT_FLAGS_START + 0x300..0x37F). The 14 symbols stay contiguous
// (silver/gold per facility, frontier_util.c adds 2 * facility).
#define FLAG_SYS_TOWER_SILVER                  (EXT_EVENT_FLAGS_START + 0x300)
#define FLAG_SYS_TOWER_GOLD                    (EXT_EVENT_FLAGS_START + 0x301)
#define FLAG_SYS_DOME_SILVER                   (EXT_EVENT_FLAGS_START + 0x302)
#define FLAG_SYS_DOME_GOLD                     (EXT_EVENT_FLAGS_START + 0x303)
#define FLAG_SYS_PALACE_SILVER                 (EXT_EVENT_FLAGS_START + 0x304)
#define FLAG_SYS_PALACE_GOLD                   (EXT_EVENT_FLAGS_START + 0x305)
#define FLAG_SYS_ARENA_SILVER                  (EXT_EVENT_FLAGS_START + 0x306)
#define FLAG_SYS_ARENA_GOLD                    (EXT_EVENT_FLAGS_START + 0x307)
#define FLAG_SYS_FACTORY_SILVER                (EXT_EVENT_FLAGS_START + 0x308)
#define FLAG_SYS_FACTORY_GOLD                  (EXT_EVENT_FLAGS_START + 0x309)
#define FLAG_SYS_PIKE_SILVER                   (EXT_EVENT_FLAGS_START + 0x30A)
#define FLAG_SYS_PIKE_GOLD                     (EXT_EVENT_FLAGS_START + 0x30B)
#define FLAG_SYS_PYRAMID_SILVER                (EXT_EVENT_FLAGS_START + 0x30C)
#define FLAG_SYS_PYRAMID_GOLD                  (EXT_EVENT_FLAGS_START + 0x30D)
#define FLAG_SYS_FRONTIER_PASS                 (EXT_EVENT_FLAGS_START + 0x30E)
#define FLAG_CANCEL_BATTLE_ROOM_CHALLENGE      (EXT_EVENT_FLAGS_START + 0x30F)
#define FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER   (EXT_EVENT_FLAGS_START + 0x310)
#define FLAG_HIDE_APPRENTICE                   (EXT_EVENT_FLAGS_START + 0x311)
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1 (EXT_EVENT_FLAGS_START + 0x312)
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2 (EXT_EVENT_FLAGS_START + 0x313)
#define FLAG_DAILY_APPRENTICE_LEAVES           (EXT_EVENT_FLAGS_START + 0x314) // cleared each Hoenn day (session 2)
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1 (EXT_EVENT_FLAGS_START + 0x315)
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2 (EXT_EVENT_FLAGS_START + 0x316)
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3 (EXT_EVENT_FLAGS_START + 0x317)
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4 (EXT_EVENT_FLAGS_START + 0x318)
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5 (EXT_EVENT_FLAGS_START + 0x319)
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6 (EXT_EVENT_FLAGS_START + 0x31A)
#define FLAG_HIDE_BATTLE_FRONTIER_RECEPTION_GATE_SCOTT (EXT_EVENT_FLAGS_START + 0x31B)
#define FLAG_LANDMARK_BATTLE_FRONTIER          (EXT_EVENT_FLAGS_START + 0x31C)
// temp flags of Island Cave's puzzle (Emerald's)
#define FLAG_TEMP_REGICE_PUZZLE_STARTED        FLAG_TEMP_2
#define FLAG_TEMP_REGICE_PUZZLE_FAILED         FLAG_TEMP_3

// Johto (tools/johto_import): EXT_EVENT_FLAGS_START + 0x80 + (map section - MAPSEC_NEW_BARK_TOWN) for its 39 sections
// (0x80-0xA6): the world map's visited flags (Fly, dungeon icons), set on entering any map of the section
// (SetHoennWorldMapFlag). Johto's item flags start at + 0x100 (johto_flags.json)
#define FLAG_WORLD_MAP_JOHTO(mapsec)           (EXT_EVENT_FLAGS_START + 0x80 + (mapsec) - MAPSEC_NEW_BARK_TOWN)

// BEGIN berry_trees.py (work/hoenn_scripts, lot 2)
// Hoenn's berry trees picked today (src/hoenn_specials.c clears them each day): + tree id (Emerald's)
#define FLAG_HOENN_BERRY_TREES_START (EXT_EVENT_FLAGS_START + 0x240)
#define FLAG_HOENN_BERRY_TREE_ROUTE_102_PECHA (FLAG_HOENN_BERRY_TREES_START + 1)
#define FLAG_HOENN_BERRY_TREE_ROUTE_102_ORAN (FLAG_HOENN_BERRY_TREES_START + 2)
#define FLAG_HOENN_BERRY_TREE_ROUTE_104_ORAN_1 (FLAG_HOENN_BERRY_TREES_START + 4)
#define FLAG_HOENN_BERRY_TREE_ROUTE_103_CHERI_1 (FLAG_HOENN_BERRY_TREES_START + 5)
#define FLAG_HOENN_BERRY_TREE_ROUTE_103_LEPPA (FLAG_HOENN_BERRY_TREES_START + 6)
#define FLAG_HOENN_BERRY_TREE_ROUTE_103_CHERI_2 (FLAG_HOENN_BERRY_TREES_START + 7)
#define FLAG_HOENN_BERRY_TREE_ROUTE_104_CHERI_1 (FLAG_HOENN_BERRY_TREES_START + 8)
#define FLAG_HOENN_BERRY_TREE_ROUTE_104_LEPPA (FLAG_HOENN_BERRY_TREES_START + 10)
#define FLAG_HOENN_BERRY_TREE_ROUTE_104_ORAN_2 (FLAG_HOENN_BERRY_TREES_START + 11)
#define FLAG_HOENN_BERRY_TREE_ROUTE_104_PECHA (FLAG_HOENN_BERRY_TREES_START + 13)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_QUALOT_1 (FLAG_HOENN_BERRY_TREES_START + 14)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_POMEG_1 (FLAG_HOENN_BERRY_TREES_START + 15)
#define FLAG_HOENN_BERRY_TREE_ROUTE_110_NANAB_1 (FLAG_HOENN_BERRY_TREES_START + 16)
#define FLAG_HOENN_BERRY_TREE_ROUTE_110_NANAB_2 (FLAG_HOENN_BERRY_TREES_START + 17)
#define FLAG_HOENN_BERRY_TREE_ROUTE_110_NANAB_3 (FLAG_HOENN_BERRY_TREES_START + 18)
#define FLAG_HOENN_BERRY_TREE_ROUTE_111_RAZZ_1 (FLAG_HOENN_BERRY_TREES_START + 19)
#define FLAG_HOENN_BERRY_TREE_ROUTE_111_RAZZ_2 (FLAG_HOENN_BERRY_TREES_START + 20)
#define FLAG_HOENN_BERRY_TREE_ROUTE_112_RAWST_1 (FLAG_HOENN_BERRY_TREES_START + 21)
#define FLAG_HOENN_BERRY_TREE_ROUTE_112_PECHA_1 (FLAG_HOENN_BERRY_TREES_START + 22)
#define FLAG_HOENN_BERRY_TREE_ROUTE_112_PECHA_2 (FLAG_HOENN_BERRY_TREES_START + 23)
#define FLAG_HOENN_BERRY_TREE_ROUTE_112_RAWST_2 (FLAG_HOENN_BERRY_TREES_START + 24)
#define FLAG_HOENN_BERRY_TREE_ROUTE_116_PINAP_1 (FLAG_HOENN_BERRY_TREES_START + 25)
#define FLAG_HOENN_BERRY_TREE_ROUTE_116_CHESTO_1 (FLAG_HOENN_BERRY_TREES_START + 26)
#define FLAG_HOENN_BERRY_TREE_ROUTE_117_WEPEAR_1 (FLAG_HOENN_BERRY_TREES_START + 27)
#define FLAG_HOENN_BERRY_TREE_ROUTE_117_WEPEAR_2 (FLAG_HOENN_BERRY_TREES_START + 28)
#define FLAG_HOENN_BERRY_TREE_ROUTE_117_WEPEAR_3 (FLAG_HOENN_BERRY_TREES_START + 29)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_POMEG_2 (FLAG_HOENN_BERRY_TREES_START + 30)
#define FLAG_HOENN_BERRY_TREE_ROUTE_118_SITRUS_1 (FLAG_HOENN_BERRY_TREES_START + 31)
#define FLAG_HOENN_BERRY_TREE_ROUTE_118_SITRUS_2 (FLAG_HOENN_BERRY_TREES_START + 33)
#define FLAG_HOENN_BERRY_TREE_ROUTE_119_POMEG_1 (FLAG_HOENN_BERRY_TREES_START + 34)
#define FLAG_HOENN_BERRY_TREE_ROUTE_119_POMEG_2 (FLAG_HOENN_BERRY_TREES_START + 35)
#define FLAG_HOENN_BERRY_TREE_ROUTE_119_POMEG_3 (FLAG_HOENN_BERRY_TREES_START + 36)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_ASPEAR_1 (FLAG_HOENN_BERRY_TREES_START + 37)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_ASPEAR_2 (FLAG_HOENN_BERRY_TREES_START + 38)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_ASPEAR_3 (FLAG_HOENN_BERRY_TREES_START + 39)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_PECHA_1 (FLAG_HOENN_BERRY_TREES_START + 40)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_PECHA_2 (FLAG_HOENN_BERRY_TREES_START + 41)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_PECHA_3 (FLAG_HOENN_BERRY_TREES_START + 42)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_RAZZ (FLAG_HOENN_BERRY_TREES_START + 43)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_NANAB (FLAG_HOENN_BERRY_TREES_START + 44)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_PINAP (FLAG_HOENN_BERRY_TREES_START + 45)
#define FLAG_HOENN_BERRY_TREE_ROUTE_120_WEPEAR (FLAG_HOENN_BERRY_TREES_START + 46)
#define FLAG_HOENN_BERRY_TREE_ROUTE_121_PERSIM (FLAG_HOENN_BERRY_TREES_START + 47)
#define FLAG_HOENN_BERRY_TREE_ROUTE_121_ASPEAR (FLAG_HOENN_BERRY_TREES_START + 48)
#define FLAG_HOENN_BERRY_TREE_ROUTE_121_RAWST (FLAG_HOENN_BERRY_TREES_START + 49)
#define FLAG_HOENN_BERRY_TREE_ROUTE_121_CHESTO (FLAG_HOENN_BERRY_TREES_START + 50)
#define FLAG_HOENN_BERRY_TREE_ROUTE_121_NANAB_1 (FLAG_HOENN_BERRY_TREES_START + 52)
#define FLAG_HOENN_BERRY_TREE_ROUTE_121_NANAB_2 (FLAG_HOENN_BERRY_TREES_START + 53)
#define FLAG_HOENN_BERRY_TREE_ROUTE_115_BLUK_1 (FLAG_HOENN_BERRY_TREES_START + 55)
#define FLAG_HOENN_BERRY_TREE_ROUTE_115_BLUK_2 (FLAG_HOENN_BERRY_TREES_START + 56)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_POMEG_3 (FLAG_HOENN_BERRY_TREES_START + 58)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_POMEG_4 (FLAG_HOENN_BERRY_TREES_START + 59)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_GREPA_1 (FLAG_HOENN_BERRY_TREES_START + 60)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_GREPA_2 (FLAG_HOENN_BERRY_TREES_START + 61)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_LEPPA_1 (FLAG_HOENN_BERRY_TREES_START + 62)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_LEPPA_2 (FLAG_HOENN_BERRY_TREES_START + 64)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_GREPA_3 (FLAG_HOENN_BERRY_TREES_START + 65)
#define FLAG_HOENN_BERRY_TREE_ROUTE_116_CHESTO_2 (FLAG_HOENN_BERRY_TREES_START + 66)
#define FLAG_HOENN_BERRY_TREE_ROUTE_116_PINAP_2 (FLAG_HOENN_BERRY_TREES_START + 67)
#define FLAG_HOENN_BERRY_TREE_ROUTE_114_PERSIM_1 (FLAG_HOENN_BERRY_TREES_START + 68)
#define FLAG_HOENN_BERRY_TREE_ROUTE_115_KELPSY_1 (FLAG_HOENN_BERRY_TREES_START + 69)
#define FLAG_HOENN_BERRY_TREE_ROUTE_115_KELPSY_2 (FLAG_HOENN_BERRY_TREES_START + 70)
#define FLAG_HOENN_BERRY_TREE_ROUTE_115_KELPSY_3 (FLAG_HOENN_BERRY_TREES_START + 71)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_GREPA_4 (FLAG_HOENN_BERRY_TREES_START + 72)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_QUALOT_2 (FLAG_HOENN_BERRY_TREES_START + 73)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_QUALOT_3 (FLAG_HOENN_BERRY_TREES_START + 74)
#define FLAG_HOENN_BERRY_TREE_ROUTE_104_CHERI_2 (FLAG_HOENN_BERRY_TREES_START + 76)
#define FLAG_HOENN_BERRY_TREE_ROUTE_114_PERSIM_2 (FLAG_HOENN_BERRY_TREES_START + 77)
#define FLAG_HOENN_BERRY_TREE_ROUTE_114_PERSIM_3 (FLAG_HOENN_BERRY_TREES_START + 78)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_QUALOT_4 (FLAG_HOENN_BERRY_TREES_START + 79)
#define FLAG_HOENN_BERRY_TREE_ROUTE_111_ORAN_1 (FLAG_HOENN_BERRY_TREES_START + 80)
#define FLAG_HOENN_BERRY_TREE_ROUTE_111_ORAN_2 (FLAG_HOENN_BERRY_TREES_START + 81)
#define FLAG_HOENN_BERRY_TREE_ROUTE_130_LIECHI (FLAG_HOENN_BERRY_TREES_START + 82)
#define FLAG_HOENN_BERRY_TREE_ROUTE_119_HONDEW_1 (FLAG_HOENN_BERRY_TREES_START + 83)
#define FLAG_HOENN_BERRY_TREE_ROUTE_119_HONDEW_2 (FLAG_HOENN_BERRY_TREES_START + 84)
#define FLAG_HOENN_BERRY_TREE_ROUTE_119_SITRUS (FLAG_HOENN_BERRY_TREES_START + 85)
#define FLAG_HOENN_BERRY_TREE_ROUTE_119_LEPPA (FLAG_HOENN_BERRY_TREES_START + 86)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_PECHA (FLAG_HOENN_BERRY_TREES_START + 87)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_SITRUS (FLAG_HOENN_BERRY_TREES_START + 88)
#define FLAG_HOENN_BERRY_TREE_ROUTE_123_RAWST (FLAG_HOENN_BERRY_TREES_START + 89)
#define FLAG_HOENN_BERRY_TREES_END (FLAG_HOENN_BERRY_TREES_START + 89)
// END berry_trees.py (work/hoenn_scripts, lot 2)
// Special Flags (Stored in EWRAM (sSpecialFlags, not in the SaveBlock)
#define SPECIAL_FLAGS_START           0x4000
#define FLAG_DONT_SHOW_MAP_NAME_POPUP (SPECIAL_FLAGS_START + 0x0)
#define FLAG_DONT_TRANSITION_MUSIC    (SPECIAL_FLAGS_START + 0x1)
#define FLAG_ENABLE_MULTI_CORRIDOR_DOOR (SPECIAL_FLAGS_START + 0x2) // RFVF+: Emerald's
#define FLAG_STORING_ITEMS_IN_PYRAMID_BAG (SPECIAL_FLAGS_START + 0x3) // RFVF+: Emerald's
// FLAG_SPECIAL_FLAG_0x4002 - 0x407F also exist and are unused
#define SPECIAL_FLAGS_END             (SPECIAL_FLAGS_START + 0x7F)

// BEGIN johto_import
// Johto's item balls, hidden items and obstacles (johto_flags.json: saved, never renumber)
#define FLAG_ITEM_VIOLET_CITY_PECHA_BERRY                (EXT_EVENT_FLAGS_START + 0x100)
#define FLAG_ITEM_VIOLET_CITY_HYPER_POTION               (EXT_EVENT_FLAGS_START + 0x101)
#define FLAG_ITEM_VIOLET_CITY_RARE_CANDY                 (EXT_EVENT_FLAGS_START + 0x102)
#define FLAG_ITEM_ECRUTEAK_RARE_CANDY                    (EXT_EVENT_FLAGS_START + 0x103)
#define FLAG_ITEM_OLIVINE_TM_CHARGEBEAM                  (EXT_EVENT_FLAGS_START + 0x104)
#define FLAG_ITEM_ROUTE_29_POTION                        (EXT_EVENT_FLAGS_START + 0x105)
#define FLAG_ITEM_ROUTE_31_POKEBALL                      (EXT_EVENT_FLAGS_START + 0x106)
#define FLAG_ITEM_ROUTE_31_ANTIDOE                       (EXT_EVENT_FLAGS_START + 0x107)
#define FLAG_ITEM_ROUTE_32_SUPERPOTION                   (EXT_EVENT_FLAGS_START + 0x108)
#define FLAG_ITEM_ROUTE_32_GREATBALL                     (EXT_EVENT_FLAGS_START + 0x109)
#define FLAG_ITEM_ROUTE32_TM_BULLET_SEED                 (EXT_EVENT_FLAGS_START + 0x10A)
#define FLAG_ITEM_ROUTE_32_GREATBALL2                    (EXT_EVENT_FLAGS_START + 0x10B)
#define FLAG_ITEM_ROUTE34_SOFTSAND                       (EXT_EVENT_FLAGS_START + 0x10C)
#define FLAG_ITEM_ROUTE34_RARECANDY                      (EXT_EVENT_FLAGS_START + 0x10D)
#define FLAG_ITEM_ROUTE34_TM_EMBARGO                     (EXT_EVENT_FLAGS_START + 0x10E)
#define FLAG_ITEM_ROUTE35_PAYBACK                        (EXT_EVENT_FLAGS_START + 0x10F)
#define FLAG_ITEM_ROUTE35_BIG_NUGGET                     (EXT_EVENT_FLAGS_START + 0x110)
#define FLAG_ITEM_ROUTE35_PARALYZE_HEAL                  (EXT_EVENT_FLAGS_START + 0x111)
#define FLAG_ITEM_ROUTE38_LAX_INCENSE                    (EXT_EVENT_FLAGS_START + 0x112)
#define FLAG_ITEM_ROUTE39_TM_DRAIN_PUNCH                 (EXT_EVENT_FLAGS_START + 0x113)
#define FLAG_ITEM_ROUTE39_NUGGET                         (EXT_EVENT_FLAGS_START + 0x114)
#define FLAG_ITEM_ROUTE42_SUPER_POTION                   (EXT_EVENT_FLAGS_START + 0x115)
#define FLAG_ITEM_ROUTE42_ULTRA_BALL                     (EXT_EVENT_FLAGS_START + 0x116)
#define FLAG_ITEM_ROUTE42_TM_SHADOW_CLAW                 (EXT_EVENT_FLAGS_START + 0x117)
#define FLAG_ITEM_ROUTE43_MAX_ETHER                      (EXT_EVENT_FLAGS_START + 0x118)
#define FLAG_ITEM_ROUTE44_ELIXIR                         (EXT_EVENT_FLAGS_START + 0x119)
#define FLAG_ITEM_ROUTE44_MAX_REPEL                      (EXT_EVENT_FLAGS_START + 0x11A)
#define FLAG_ITEM_ROUTE44_ULTRA_BALL                     (EXT_EVENT_FLAGS_START + 0x11B)
#define FLAG_ITEM_ROUTE45_FULL_HEAL                      (EXT_EVENT_FLAGS_START + 0x11C)
#define FLAG_ITEM_ROUTE45_NUGGET                         (EXT_EVENT_FLAGS_START + 0x11D)
#define FLAG_ITEM_ROUTE45_ELIXIR                         (EXT_EVENT_FLAGS_START + 0x11E)
#define FLAG_ITEM_ROUTE45_MAX_POTION                     (EXT_EVENT_FLAGS_START + 0x11F)
#define FLAG_ITEM_ROUTE46_REVIVE                         (EXT_EVENT_FLAGS_START + 0x120)
#define FLAG_ITEM_ROUTE47_REVIVE                         (EXT_EVENT_FLAGS_START + 0x121)
#define FLAG_ITEM_ROUTE47_WHITE_FLUTE                    (EXT_EVENT_FLAGS_START + 0x122)
#define FLAG_ITEM_ROUTE47_PEARL                          (EXT_EVENT_FLAGS_START + 0x123)
#define FLAG_ITEM_ROUTE47_STARDUST                       (EXT_EVENT_FLAGS_START + 0x124)
#define FLAG_ITEM_LUCKY_PUNCH                            (EXT_EVENT_FLAGS_START + 0x125)
#define FLAG_ITEM_ROUTE27_RARECANDY                      (EXT_EVENT_FLAGS_START + 0x126)
#define FLAG_ITEM_ROUTE27_MOONSTONE                      (EXT_EVENT_FLAGS_START + 0x127)
#define FLAG_ITEM_ROUTE27_DRAGONCLAW                     (EXT_EVENT_FLAGS_START + 0x128)
#define FLAG_ITEM_ROUTE27_DESTINY_KNOT                   (EXT_EVENT_FLAGS_START + 0x129)
#define FLAG_ITEM_ROUTE28_TM_FLAMETHROWER                (EXT_EVENT_FLAGS_START + 0x12A)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_COIN_CASE        (EXT_EVENT_FLAGS_START + 0x12B)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_PARALYZE_HEAL    (EXT_EVENT_FLAGS_START + 0x12C)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_ANTIDOTE         (EXT_EVENT_FLAGS_START + 0x12D)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_SUPER_POTION     (EXT_EVENT_FLAGS_START + 0x12E)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_REVIVE           (EXT_EVENT_FLAGS_START + 0x12F)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_MAX_POTION       (EXT_EVENT_FLAGS_START + 0x130)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_SMOKE_BALL       (EXT_EVENT_FLAGS_START + 0x131)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_ULTRA_BALL2      (EXT_EVENT_FLAGS_START + 0x132)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_MAX_ETHER        (EXT_EVENT_FLAGS_START + 0x133)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_TM_CALM_MIND     (EXT_EVENT_FLAGS_START + 0x134)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_AMULET_COIN      (EXT_EVENT_FLAGS_START + 0x135)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_ULTRA_BALL       (EXT_EVENT_FLAGS_START + 0x136)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_EXP_SHARE        (EXT_EVENT_FLAGS_START + 0x137)
#define FLAG_ITEM_GOLDENROD_UNDERGROUND_ETHER            (EXT_EVENT_FLAGS_START + 0x138)
#define FLAG_ITEM_BELLCHIME_BIG_MUSHROOM                 (EXT_EVENT_FLAGS_START + 0x139)
#define FLAG_ITEM_LIGHTHOUSE_PROTEIN                     (EXT_EVENT_FLAGS_START + 0x13A)
#define FLAG_ITEM_LIGHTHOUSE_HYPER_POTION                (EXT_EVENT_FLAGS_START + 0x13B)
#define FLAG_ITEM_OLIVINE_TM_SWAGGER                     (EXT_EVENT_FLAGS_START + 0x13C)
#define FLAG_ITEM_LIGHTHOUSE_RARE_CANDY                  (EXT_EVENT_FLAGS_START + 0x13D)
#define FLAG_ITEM_LIGHTHOUSE_ETHER                       (EXT_EVENT_FLAGS_START + 0x13E)
#define FLAG_ITEM_DARKCAVE1_POTION                       (EXT_EVENT_FLAGS_START + 0x13F)
#define FLAG_ITEM_DARKCAVE1_REVIVE                       (EXT_EVENT_FLAGS_START + 0x140)
#define FLAG_ITEM_DARKCAVE1_MAX_REVIVE                   (EXT_EVENT_FLAGS_START + 0x141)
#define FLAG_ITEM_DARKCAVE1_ELIXIR                       (EXT_EVENT_FLAGS_START + 0x142)
#define FLAG_ITEM_DARKCAVE2_BLACK_FLUTE                  (EXT_EVENT_FLAGS_START + 0x143)
#define FLAG_ITEM_DARKCAVE2_STAR_PIECE                   (EXT_EVENT_FLAGS_START + 0x144)
#define FLAG_ITEM_SPROUT_TOWER_PARALYZE_HEAL             (EXT_EVENT_FLAGS_START + 0x145)
#define FLAG_ITEM_SPROUT_TOWER_X_DEFEND                  (EXT_EVENT_FLAGS_START + 0x146)
#define FLAG_ITEM_SPROUT_TOWER_ESCAPE_ROPE               (EXT_EVENT_FLAGS_START + 0x147)
#define FLAG_ITEM_SPROUT_TOWER_POTION                    (EXT_EVENT_FLAGS_START + 0x148)
#define FLAG_ITEM_DOME_FOSSIL                            (EXT_EVENT_FLAGS_START + 0x149)
#define FLAG_ITEM_OLD_AMBER                              (EXT_EVENT_FLAGS_START + 0x14A)
#define FLAG_ITEM_HELIX_FOSSIL                           (EXT_EVENT_FLAGS_START + 0x14B)
#define FLAG_ITEM_RUINSOFALPH_LIFE_ORB                   (EXT_EVENT_FLAGS_START + 0x14C)
#define FLAG_ITEM_RUINSOFALPH_CHARCOAL                   (EXT_EVENT_FLAGS_START + 0x14D)
#define FLAG_ITEM_RUINSOFALPH_MAX_REVIVE_1               (EXT_EVENT_FLAGS_START + 0x14E)
#define FLAG_ITEM_RUINSOFALPH_SACRED_ASH                 (EXT_EVENT_FLAGS_START + 0x14F)
#define FLAG_ITEM_RUINSOFALPH_HEAL_POWDER_1              (EXT_EVENT_FLAGS_START + 0x150)
#define FLAG_ITEM_RUINSOFALPH_ENERGY_ROOT                (EXT_EVENT_FLAGS_START + 0x151)
#define FLAG_ITEM_RUINSOFALPH_SITRUS_BERRY_2             (EXT_EVENT_FLAGS_START + 0x152)
#define FLAG_ITEM_RUINSOFALPH_MOON_STONE                 (EXT_EVENT_FLAGS_START + 0x153)
#define FLAG_ITEM_RUINSOFALPH_PECHA_BERRY                (EXT_EVENT_FLAGS_START + 0x154)
#define FLAG_ITEM_RUINSOFALPH_ENERGY_POWDER              (EXT_EVENT_FLAGS_START + 0x155)
#define FLAG_ITEM_RUINSOFALPH_HEAL_POWDER_2              (EXT_EVENT_FLAGS_START + 0x156)
#define FLAG_ITEM_RUINSOFALPH_ORAN_BERRY                 (EXT_EVENT_FLAGS_START + 0x157)
#define FLAG_ITEM_RUINSOFALPH_WATER_STONE                (EXT_EVENT_FLAGS_START + 0x158)
#define FLAG_ITEM_RUINSOFALPH_STAR_PIECE                 (EXT_EVENT_FLAGS_START + 0x159)
#define FLAG_ITEM_RUINSOFALPH_STARDUST                   (EXT_EVENT_FLAGS_START + 0x15A)
#define FLAG_ITEM_RUINSOFALPH_LUM_BERRY_2                (EXT_EVENT_FLAGS_START + 0x15B)
#define FLAG_ITEM_UNION_CAVE_POTION                      (EXT_EVENT_FLAGS_START + 0x15C)
#define FLAG_ITEM_UNION_CAVE_AWAKENING                   (EXT_EVENT_FLAGS_START + 0x15D)
#define FLAG_ITEM_UNION_CAVE_GREAT_BALL                  (EXT_EVENT_FLAGS_START + 0x15E)
#define FLAG_ITEM_UNION_CAVE_X_ATTACK                    (EXT_EVENT_FLAGS_START + 0x15F)
#define FLAG_ITEM_UNION_CAVE_ROCK_TOMB                   (EXT_EVENT_FLAGS_START + 0x160)
#define FLAG_ITEM_UNION_CAVE_X_DEFEND                    (EXT_EVENT_FLAGS_START + 0x161)
#define FLAG_ITEM_UNION_CAVE_ETHER                       (EXT_EVENT_FLAGS_START + 0x162)
#define FLAG_ITEM_UNION_CAVE_MAXREVIVE                   (EXT_EVENT_FLAGS_START + 0x163)
#define FLAG_ITEM_UNION_CAVE_HYPERPOTION                 (EXT_EVENT_FLAGS_START + 0x164)
#define FLAG_ITEM_SLOWPOKE_WELL_SUPER_POTION             (EXT_EVENT_FLAGS_START + 0x165)
#define FLAG_ITEM_SLOWPOKE_WELL_SUPER_POTION2            (EXT_EVENT_FLAGS_START + 0x166)
#define FLAG_ITEM_SLOWPOKE_WELL_GREAT_BALL               (EXT_EVENT_FLAGS_START + 0x167)
#define FLAG_ITEM_SLOWPOKE_WELL_FULL_HEAL                (EXT_EVENT_FLAGS_START + 0x168)
#define FLAG_ITEM_SLOWPOKE_WELL_KINGS_ROCK               (EXT_EVENT_FLAGS_START + 0x169)
#define FLAG_ITEM_ILEX_FOREST_FULL_HEAL                  (EXT_EVENT_FLAGS_START + 0x16A)
#define FLAG_ITEM_ILEX_FOREST_ETHER                      (EXT_EVENT_FLAGS_START + 0x16B)
#define FLAG_ITEM_ILEX_FOREST_SUPER_POTION               (EXT_EVENT_FLAGS_START + 0x16C)
#define FLAG_ITEM_ILEX_FOREST_TM_FALSE_SWIPE             (EXT_EVENT_FLAGS_START + 0x16D)
#define FLAG_ITEM_NATIONAL_PARK_TM_DIG                   (EXT_EVENT_FLAGS_START + 0x16E)
#define FLAG_ITEM_NATIONAL_PARK_SOOTHE_BELL              (EXT_EVENT_FLAGS_START + 0x16F)
#define FLAG_ITEM_BURNED_TOWER_1F_HP_UP                  (EXT_EVENT_FLAGS_START + 0x170)
#define FLAG_ITEM_BURNED_TOWER_1F_ETHER                  (EXT_EVENT_FLAGS_START + 0x171)
#define FLAG_ITEM_BURNED_TOWER_B1F_ULTRA_BALL            (EXT_EVENT_FLAGS_START + 0x172)
#define FLAG_ITEM_BURNED_TOWER_B1F_TM_TAUNT              (EXT_EVENT_FLAGS_START + 0x173)
#define FLAG_ITEM_MTMORTAR1_ELIXIR                       (EXT_EVENT_FLAGS_START + 0x174)
#define FLAG_ITEM_MTMORTAR1_TM_AERIAL_ACE                (EXT_EVENT_FLAGS_START + 0x175)
#define FLAG_ITEM_MTMORTAR2_MAX_REPEL                    (EXT_EVENT_FLAGS_START + 0x176)
#define FLAG_ITEM_MTMORTAR2_ESCAPE_ROPE                  (EXT_EVENT_FLAGS_START + 0x177)
#define FLAG_ITEM_MTMORTAR2_ULTRA_BALL                   (EXT_EVENT_FLAGS_START + 0x178)
#define FLAG_ITEM_MTMORTAR2_PROTECTOR                    (EXT_EVENT_FLAGS_START + 0x179)
#define FLAG_ITEM_MTMORTAR2_MAX_POTION                   (EXT_EVENT_FLAGS_START + 0x17A)
#define FLAG_ITEM_MTMORTAR2_REVIVE                       (EXT_EVENT_FLAGS_START + 0x17B)
#define FLAG_ITEM_MTMORTAR2_KINGS_ROCK                   (EXT_EVENT_FLAGS_START + 0x17C)
#define FLAG_ITEM_MTMORTAR3_IRON                         (EXT_EVENT_FLAGS_START + 0x17D)
#define FLAG_ITEM_MTMORTAR3_MAX_REVIVE                   (EXT_EVENT_FLAGS_START + 0x17E)
#define FLAG_ITEM_MTMORTAR3_ETHER                        (EXT_EVENT_FLAGS_START + 0x17F)
#define FLAG_ITEM_MTMORTAR3_RARE_CANDY                   (EXT_EVENT_FLAGS_START + 0x180)
#define FLAG_ITEM_MTMORTAR3_DRAGON_SCALE                 (EXT_EVENT_FLAGS_START + 0x181)
#define FLAG_ITEM_MTMORTAR3_ELIXIR                       (EXT_EVENT_FLAGS_START + 0x182)
#define FLAG_ITEM_MTMORTAR4_PP_UP                        (EXT_EVENT_FLAGS_START + 0x183)
#define FLAG_ITEM_MTMORTAR4_MAX_REVIVE                   (EXT_EVENT_FLAGS_START + 0x184)
#define FLAG_ITEM_MTMORTAR4_CARBOS                       (EXT_EVENT_FLAGS_START + 0x185)
#define FLAG_ITEM_MTMORTAR4_MAX_ETHER                    (EXT_EVENT_FLAGS_START + 0x186)
#define FLAG_ITEM_MTMORTAR4_HYPER_POTION                 (EXT_EVENT_FLAGS_START + 0x187)
#define FLAG_ITEM_LAKEOFRAGE_FULL_RESTORE                (EXT_EVENT_FLAGS_START + 0x188)
#define FLAG_ITEM_LAKE_OF_RAGE_TM_SECRET_POWER           (EXT_EVENT_FLAGS_START + 0x189)
#define FLAG_ITEM_LAKEOFRAGE_RED_FLUTE                   (EXT_EVENT_FLAGS_START + 0x18A)
#define FLAG_ITEM_ICEPATH1_PP_UP                         (EXT_EVENT_FLAGS_START + 0x18B)
#define FLAG_ITEM_ICEPATH1_HM_WATERFALL                  (EXT_EVENT_FLAGS_START + 0x18C)
#define FLAG_ITEM_ICEPATH1_PROTEIN                       (EXT_EVENT_FLAGS_START + 0x18D)
#define FLAG_ITEM_ICEPATH2_IRON                          (EXT_EVENT_FLAGS_START + 0x18E)
#define FLAG_ITEM_ICEPATH2_REVIVE                        (EXT_EVENT_FLAGS_START + 0x18F)
#define FLAG_HIDE_ICEPATH_B1F_BOULDER1                   (EXT_EVENT_FLAGS_START + 0x190)
#define FLAG_HIDE_ICEPATH_B1F_BOULDER2                   (EXT_EVENT_FLAGS_START + 0x191)
#define FLAG_HIDE_ICEPATH_B1F_BOULDER3                   (EXT_EVENT_FLAGS_START + 0x192)
#define FLAG_HIDE_ICEPATH_B1F_BOULDER4                   (EXT_EVENT_FLAGS_START + 0x193)
#define FLAG_ITEM_ICEPATH3_MAX_POTION                    (EXT_EVENT_FLAGS_START + 0x194)
#define FLAG_ITEM_ICEPATH3_FULL_HEAL                     (EXT_EVENT_FLAGS_START + 0x195)
#define FLAG_ITEM_ICEPATH3_CARBOS                        (EXT_EVENT_FLAGS_START + 0x196)
#define FLAG_ITEM_ICEPATH3_NEVER_MELT_ICE                (EXT_EVENT_FLAGS_START + 0x197)
#define FLAG_ITEM_DRAGONSDEN2_PP_MAX                     (EXT_EVENT_FLAGS_START + 0x198)
#define FLAG_ITEM_DRAGONSDEN2_MAX_POTION                 (EXT_EVENT_FLAGS_START + 0x199)
#define FLAG_ITEM_DRAGONSDEN2_DRAGON_FANG                (EXT_EVENT_FLAGS_START + 0x19A)
#define FLAG_ITEM_WHIRL_ISLANDS_1F_RARE_CANDY            (EXT_EVENT_FLAGS_START + 0x19B)
#define FLAG_ITEM_WHIRL_ISLANDS_1F_GUARD_SPEC            (EXT_EVENT_FLAGS_START + 0x19C)
#define FLAG_ITEM_WHIRL_ISLANDS_1F_ULTRA_BALL            (EXT_EVENT_FLAGS_START + 0x19D)
#define FLAG_ITEM_WHIRL_ISLANDS_1F_FULL_RESTORE          (EXT_EVENT_FLAGS_START + 0x19E)
#define FLAG_ITEM_WHIRL_ISLANDS_B2F_BIG_NUGGET           (EXT_EVENT_FLAGS_START + 0x19F)
#define FLAG_ITEM_WHIRL_ISLANDS_B2F_FULL_RESTORE         (EXT_EVENT_FLAGS_START + 0x1A0)
#define FLAG_ITEM_WHIRL_ISLANDS_B2F_CARBOS               (EXT_EVENT_FLAGS_START + 0x1A1)
#define FLAG_ITEM_WHIRL_ISLANDS_B2F_ESCAPE_ROPE          (EXT_EVENT_FLAGS_START + 0x1A2)
#define FLAG_ITEM_WHIRL_ISLANDS_B2F_CALCIUM              (EXT_EVENT_FLAGS_START + 0x1A3)
#define FLAG_ITEM_WHIRL_ISLANDS_B1F_PP_MAX               (EXT_EVENT_FLAGS_START + 0x1A4)
#define FLAG_ITEM_WHIRL_ISLANDS_B1F_FULL_RESTORE         (EXT_EVENT_FLAGS_START + 0x1A5)
#define FLAG_ITEM_WHIRL_ISLANDS_B1F_MAX_REVIVE           (EXT_EVENT_FLAGS_START + 0x1A6)
#define FLAG_ITEM_TIN_TOWER_3F_FULL_HEAL                 (EXT_EVENT_FLAGS_START + 0x1A7)
#define FLAG_ITEM_TIN_TOWER_4F_MAX_POTION                (EXT_EVENT_FLAGS_START + 0x1A8)
#define FLAG_ITEM_TIN_TOWER_4F_ESCAPE_ROPE               (EXT_EVENT_FLAGS_START + 0x1A9)
#define FLAG_ITEM_TIN_TOWER_4F_ULTRA_BALL                (EXT_EVENT_FLAGS_START + 0x1AA)
#define FLAG_ITEM_TIN_TOWER_5F_RARE_CANDY                (EXT_EVENT_FLAGS_START + 0x1AB)
#define FLAG_ITEM_TIN_TOWER_5F_CARBOS                    (EXT_EVENT_FLAGS_START + 0x1AC)
#define FLAG_ITEM_TIN_TOWER_5F_MAX_POTION                (EXT_EVENT_FLAGS_START + 0x1AD)
#define FLAG_ITEM_TIN_TOWER_7F_MAX_REVIVE                (EXT_EVENT_FLAGS_START + 0x1AE)
#define FLAG_ITEM_TIN_TOWER_8F_FULL_RESTORE              (EXT_EVENT_FLAGS_START + 0x1AF)
#define FLAG_ITEM_TIN_TOWER_8F_MAX_ELIXIR                (EXT_EVENT_FLAGS_START + 0x1B0)
#define FLAG_ITEM_TIN_TOWER_8F_BIG_NUGGET                (EXT_EVENT_FLAGS_START + 0x1B1)
#define FLAG_ITEM_TOHJOFALLS_HEART_SCALE                 (EXT_EVENT_FLAGS_START + 0x1B2)
#define FLAG_ITEM_MTSILVER_SPELL_TAG                     (EXT_EVENT_FLAGS_START + 0x1B3)
#define FLAG_ITEM_MTSILVER_FULLRESTORE                   (EXT_EVENT_FLAGS_START + 0x1B4)
#define FLAG_ITEM_MTSILVER_MAXPOTION                     (EXT_EVENT_FLAGS_START + 0x1B5)
#define FLAG_ITEM_MTSILVER_DIREHIT                       (EXT_EVENT_FLAGS_START + 0x1B6)
#define FLAG_ITEM_MTSILVER_ULTRABALL                     (EXT_EVENT_FLAGS_START + 0x1B7)
#define FLAG_ITEM_MT_SILVER_CAVE_TM_STEALTH_ROCK         (EXT_EVENT_FLAGS_START + 0x1B8)
#define FLAG_ITEM_MTSILVER_RARECANDY                     (EXT_EVENT_FLAGS_START + 0x1B9)
#define FLAG_ITEM_MTSILVER_NERVERMELTICE                 (EXT_EVENT_FLAGS_START + 0x1BA)
#define FLAG_ITEM_ROCKETHIDEOUT1_HYPER_POTION            (EXT_EVENT_FLAGS_START + 0x1BB)
#define FLAG_ITEM_ROCKETHIDEOUT1_REVIVE                  (EXT_EVENT_FLAGS_START + 0x1BC)
#define FLAG_ITEM_ROCKETHIDEOUT1_BIG_NUGGET              (EXT_EVENT_FLAGS_START + 0x1BD)
#define FLAG_ITEM_ROCKETHIDEOUT2_TM_THIEF                (EXT_EVENT_FLAGS_START + 0x1BE)
#define FLAG_ITEM_ROCKETHIDEOUT3_PROTEIN                 (EXT_EVENT_FLAGS_START + 0x1BF)
#define FLAG_ITEM_ROCKETHIDEOUT3_ICE_HEAL                (EXT_EVENT_FLAGS_START + 0x1C0)
#define FLAG_ITEM_ROCKETHIDEOUT3_HYPER_POTION            (EXT_EVENT_FLAGS_START + 0x1C1)
#define FLAG_ITEM_ROCKETHIDEOUT3_GUARD_SPEC              (EXT_EVENT_FLAGS_START + 0x1C2)
#define FLAG_ITEM_ROCKETHIDEOUT3_FULL_HEAL               (EXT_EVENT_FLAGS_START + 0x1C3)
#define FLAG_HIDDEN_ITEM_NEWBARKTOWN_POTION              (EXT_EVENT_FLAGS_START + 0x1C4)
#define FLAG_HIDDEN_ITEM_CHERRYGROVE_NUGGET_1            (EXT_EVENT_FLAGS_START + 0x1C5)
#define FLAG_HIDDEN_ITEM_CHERRYGROVE_NUGGET_2            (EXT_EVENT_FLAGS_START + 0x1C6)
#define FLAG_HIDDEN_ITEM_AZALEA_FULL_HEAL                (EXT_EVENT_FLAGS_START + 0x1C7)
#define FLAG_HIDDEN_ITEM_OLIVINE_PROTEIN                 (EXT_EVENT_FLAGS_START + 0x1C8)
#define FLAG_HIDDEN_ITEM_CIANWOOD_HEART_SCALE            (EXT_EVENT_FLAGS_START + 0x1C9)
#define FLAG_HIDDEN_ITEM_ROUTE30_POTION_1                (EXT_EVENT_FLAGS_START + 0x1CA)
#define FLAG_HIDDEN_ITEM_ROUTE30_POTION_2                (EXT_EVENT_FLAGS_START + 0x1CB)
#define FLAG_ITEM_ROUTE_32_POTION                        (EXT_EVENT_FLAGS_START + 0x1CC)
#define FLAG_HIDDEN_ITEM_ROUTE32_HEART_SCALE             (EXT_EVENT_FLAGS_START + 0x1CD)
#define FLAG_HIDDEN_ITEM_ROUTE32_GREAT_BALL              (EXT_EVENT_FLAGS_START + 0x1CE)
#define FLAG_HIDDEN_ITEM_ROUTE32_SHELL_BELL              (EXT_EVENT_FLAGS_START + 0x1CF)
#define FLAG_ITEM_ROUTE34_SUPERPOTION                    (EXT_EVENT_FLAGS_START + 0x1D0)
#define FLAG_HIDDEN_ITEM_ROUTE34_RARE_CANDY              (EXT_EVENT_FLAGS_START + 0x1D1)
#define FLAG_HIDDEN_ITEM_ROUTE36_AWAKENING               (EXT_EVENT_FLAGS_START + 0x1D2)
#define FLAG_HIDDEN_ITEM_ROUTE38_HP_UP                   (EXT_EVENT_FLAGS_START + 0x1D3)
#define FLAG_HIDDEN_ITEM_ROUTE38_MAX_POTION              (EXT_EVENT_FLAGS_START + 0x1D4)
#define FLAG_HIDDEN_ITEM_ROUTE39_PP_UP                   (EXT_EVENT_FLAGS_START + 0x1D5)
#define FLAG_ITEM_ROUTE40_TM_PLUCK                       (EXT_EVENT_FLAGS_START + 0x1D6)
#define FLAG_HIDDEN_ITEM_ROUTE41_STARDUST_1              (EXT_EVENT_FLAGS_START + 0x1D7)
#define FLAG_HIDDEN_ITEM_ROUTE41_STARDUST_2              (EXT_EVENT_FLAGS_START + 0x1D8)
#define FLAG_ITEM_ROUTE42_MODEST_MINT                    (EXT_EVENT_FLAGS_START + 0x1D9)
#define FLAG_HIDDEN_ITEM_ROUTE42_DUBIOUS_DISC            (EXT_EVENT_FLAGS_START + 0x1DA)
#define FLAG_HIDDEN_ITEM_ROUTE42_MAX_POTION              (EXT_EVENT_FLAGS_START + 0x1DB)
#define FLAG_HIDDEN_ITEM_ROUTE44_ELIXIR                  (EXT_EVENT_FLAGS_START + 0x1DC)
#define FLAG_HIDDEN_ITEM_ROUTE45_PP_UP                   (EXT_EVENT_FLAGS_START + 0x1DD)
#define FLAG_HIDDEN_ITEM_ROUTE45_FULL_HEAL               (EXT_EVENT_FLAGS_START + 0x1DE)
#define FLAG_HIDDEN_ITEM_ROUTE47_LUCKY_EGG               (EXT_EVENT_FLAGS_START + 0x1DF)
#define FLAG_HIDDEN_ITEM_ROUTE47_WAVE_INCENSE            (EXT_EVENT_FLAGS_START + 0x1E0)
#define FLAG_HIDDEN_ITEM_ROUTE47_LAGGING_TAIL            (EXT_EVENT_FLAGS_START + 0x1E1)
#define FLAG_HIDDEN_ITEM_ROUTE47_PEARL                   (EXT_EVENT_FLAGS_START + 0x1E2)
#define FLAG_HIDDEN_ITEM_ROUTE26_TINY_MUSHROOM           (EXT_EVENT_FLAGS_START + 0x1E3)
#define FLAG_HIDDEN_ITEM_ROUTE27_REVIVE                  (EXT_EVENT_FLAGS_START + 0x1E4)
#define FLAG_HIDDEN_ITEM_OLIVINE_PEARL                   (EXT_EVENT_FLAGS_START + 0x1E5)
#define FLAG_HIDDEN_ITEM_DARKCAVE_SS_MAX_ETHER           (EXT_EVENT_FLAGS_START + 0x1E6)
#define FLAG_HIDDEN_ITEM_DARKCAVE_SS_BLACK_FLUTE         (EXT_EVENT_FLAGS_START + 0x1E7)
#define FLAG_HIDDEN_ITEM_DARKCAVE_NORTHSIDE_BIG_MUSHROOM (EXT_EVENT_FLAGS_START + 0x1E8)
#define FLAG_HIDDEN_ITEM_DARKCAVE_NORTHSIDE_REVIVE       (EXT_EVENT_FLAGS_START + 0x1E9)
#define FLAG_HIDDEN_ITEM_RUINSOFALPH_RARE_CANDY          (EXT_EVENT_FLAGS_START + 0x1EA)
#define FLAG_HIDDEN_ITEM_RUINSOFALPH_NUGGET              (EXT_EVENT_FLAGS_START + 0x1EB)
#define FLAG_HIDDEN_ITEM_UNIONCAVE1F_PARALYZE_HEAL       (EXT_EVENT_FLAGS_START + 0x1EC)
#define FLAG_HIDDEN_ITEM_UNIONCAVEB1F_REVIVE             (EXT_EVENT_FLAGS_START + 0x1ED)
#define FLAG_HIDDEN_ITEM_UNIONCAVEB2F_CALCIUM            (EXT_EVENT_FLAGS_START + 0x1EE)
#define FLAG_HIDDEN_ITEM_ILEX_TINY_MUSHROOM              (EXT_EVENT_FLAGS_START + 0x1EF)
#define FLAG_HIDDEN_ITEM_ILEX_ANTIDOTE                   (EXT_EVENT_FLAGS_START + 0x1F0)
#define FLAG_HIDDEN_ITEM_ILEX_BIG_MUSHROOM               (EXT_EVENT_FLAGS_START + 0x1F1)
#define FLAG_HIDDEN_ITEM_NATIONALPARK_FULL_HEAL          (EXT_EVENT_FLAGS_START + 0x1F2)
#define FLAG_HIDDEN_ITEM_MTMORTAR_1F_NORTH_NUGGET        (EXT_EVENT_FLAGS_START + 0x1F3)
#define FLAG_HIDDEN_ITEM_MTMORTAR_1F_NORTH_IRON_BALL     (EXT_EVENT_FLAGS_START + 0x1F4)
#define FLAG_HIDDEN_ITEM_MTMORTAR_2F_FULL_INCENSE        (EXT_EVENT_FLAGS_START + 0x1F5)
#define FLAG_HIDDEN_ITEM_MTMORTAR_2F_HP_UP               (EXT_EVENT_FLAGS_START + 0x1F6)
#define FLAG_ITEM_LAKEOFRAGE_MAX_REVIVE                  (EXT_EVENT_FLAGS_START + 0x1F7)
#define FLAG_HIDDEN_ITEM_LAKEOFRAGE_RARE_CANDY           (EXT_EVENT_FLAGS_START + 0x1F8)
#define FLAG_HIDDEN_ITEM_LAKEOFRAGE_MAX_POTION           (EXT_EVENT_FLAGS_START + 0x1F9)
#define FLAG_HIDDEN_ITEM_LAKEOFRAGE_CHOICE_SPECS         (EXT_EVENT_FLAGS_START + 0x1FA)
#define FLAG_HIDDEN_ITEM_LAKEOFRAGE_FULL_HEAL            (EXT_EVENT_FLAGS_START + 0x1FB)
#define FLAG_HIDDEN_ITEM_ICEPATH_1F_ICE_HEAL             (EXT_EVENT_FLAGS_START + 0x1FC)
#define FLAG_HIDDEN_ITEM_ICEPATH_1F_REVIVE               (EXT_EVENT_FLAGS_START + 0x1FD)
#define FLAG_HIDDEN_ITEM_ICEPATH_B4F_PROTEIN             (EXT_EVENT_FLAGS_START + 0x1FE)
#define FLAG_HIDDEN_ITEM_ICEPATH_B4F_CARBOS              (EXT_EVENT_FLAGS_START + 0x1FF)
#define FLAG_HIDDEN_ITEM_DRAGONSDEN_CAVERN_MAX_ELIXIR    (EXT_EVENT_FLAGS_START + 0x200)
#define FLAG_HIDDEN_ITEM_DRAGONSDEN_CAVERN_MAX_POTION    (EXT_EVENT_FLAGS_START + 0x201)
#define FLAG_HIDDEN_ITEM_WHIRLISLANDS_PEARL              (EXT_EVENT_FLAGS_START + 0x202)
#define FLAG_HIDDEN_ITEM_WHIRLISLANDS_FULL_RESTORE       (EXT_EVENT_FLAGS_START + 0x203)
#define FLAG_HIDDEN_ITEM_WHIRLISLANDS_B2F_REVIVE         (EXT_EVENT_FLAGS_START + 0x204)
#define FLAG_HIDDEN_ITEM_MT_SILVER_OUTSIDE_REAPER_CLOTH  (EXT_EVENT_FLAGS_START + 0x205)
#define FLAG_HIDDEN_ITEM_MT_SILVER_OUTSIDE_FULL_RESTORE  (EXT_EVENT_FLAGS_START + 0x206)
#define FLAG_HIDDEN_ITEM_MT_SILVER_1F_WATERFALL_ROOM_EXPERT_BELT (EXT_EVENT_FLAGS_START + 0x207)
#define FLAG_HIDDEN_ITEM_MT_SILVER_MOUNTAINSIDE_PROTEIN  (EXT_EVENT_FLAGS_START + 0x208)
#define FLAG_HIDDEN_ITEM_MT_SILVER_SNOW_PURE_INCENSE     (EXT_EVENT_FLAGS_START + 0x209)
#define FLAG_HIDDEN_ITEM_MT_SILVER_SNOW_DAWN_STONE       (EXT_EVENT_FLAGS_START + 0x20A)
// END johto_import
#endif // GUARD_CONSTANTS_FLAGS_H
