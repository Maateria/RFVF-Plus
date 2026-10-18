#include "global.h"

static EWRAM_DATA struct {
    const u16 *src;
    u16 *dest;
    u16 size;
} sTilesetDMA3TransferBuffer[20] = {0};

static u8 sTilesetDMA3TransferBufferSize;
static u16 sPrimaryTilesetAnimCounter;
static u16 sPrimaryTilesetAnimCounterMax;
static u16 sSecondaryTilesetAnimCounter;
static u16 sSecondaryTilesetAnimCounterMax;
static void (*sPrimaryTilesetAnimCallback)(u16);
static void (*sSecondaryTilesetAnimCallback)(u16);

static void _InitPrimaryTilesetAnimation(void);
static void _InitSecondaryTilesetAnimation(void);

// palette: general 00
static const u16 sTilesetAnims_General_Flower_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/0.4bpp");
static const u16 sTilesetAnims_General_Flower_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/1.4bpp");
static const u16 sTilesetAnims_General_Flower_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/2.4bpp");
static const u16 sTilesetAnims_General_Flower_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/3.4bpp");
static const u16 sTilesetAnims_General_Flower_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/4.4bpp");

static const u16 *const sTilesetAnims_General_Flower[] = {
    sTilesetAnims_General_Flower_Frame0,
    sTilesetAnims_General_Flower_Frame1,
    sTilesetAnims_General_Flower_Frame2,
    sTilesetAnims_General_Flower_Frame3,
    sTilesetAnims_General_Flower_Frame4
};

// palette: general 04
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/0.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/1.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/2.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/3.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/4.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/5.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/6.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/7.4bpp");

static const u16 *const sTilesetAnims_General_Water_Current_LandWatersEdge[] = {
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame0,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame1,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame2,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame3,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame4,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame5,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame6,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame7
};

// palette: general 04
static const u16 sTilesetAnims_General_SandWatersEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/0.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/1.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/2.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/3.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/4.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/5.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/6.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/7.4bpp");

static const u16 *const sTilesetAnims_General_SandWatersEdge[] = {
    sTilesetAnims_General_SandWatersEdge_Frame0,
    sTilesetAnims_General_SandWatersEdge_Frame1,
    sTilesetAnims_General_SandWatersEdge_Frame2,
    sTilesetAnims_General_SandWatersEdge_Frame3,
    sTilesetAnims_General_SandWatersEdge_Frame4,
    sTilesetAnims_General_SandWatersEdge_Frame5,
    sTilesetAnims_General_SandWatersEdge_Frame6,
    sTilesetAnims_General_SandWatersEdge_Frame7
};

// palette: general 00
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/0.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/1.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame2[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/2.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame3[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/3.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame4[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/4.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Empty[16] = {};

static const u16 *const sTilesetAnims_CeladonCity_Fountain[] = {
    sTilesetAnims_CeladonCity_Fountain_Frame0,
    sTilesetAnims_CeladonCity_Fountain_Frame1,
    sTilesetAnims_CeladonCity_Fountain_Frame2,
    sTilesetAnims_CeladonCity_Fountain_Frame3,
    sTilesetAnims_CeladonCity_Fountain_Frame4
};

static const u16 sTilesetAnims_SilphCo_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/0.4bpp");
static const u16 sTilesetAnims_SilphCo_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/1.4bpp");
static const u16 sTilesetAnims_SilphCo_Fountain_Frame2[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/2.4bpp");
static const u16 sTilesetAnims_SilphCo_Fountain_Frame3[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/3.4bpp");
static const u16 sTilesetAnims_SilphCo_Fountain_Empty[16] = {};

static const u16 *const sTilesetAnims_SilphCo_Fountain[] = {
    sTilesetAnims_SilphCo_Fountain_Frame0,
    sTilesetAnims_SilphCo_Fountain_Frame1,
    sTilesetAnims_SilphCo_Fountain_Frame2,
    sTilesetAnims_SilphCo_Fountain_Frame3
};

static const u16 sTilesetAnims_MtEmber_Steam_Frame0[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/0.4bpp");
static const u16 sTilesetAnims_MtEmber_Steam_Frame1[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/1.4bpp");
static const u16 sTilesetAnims_MtEmber_Steam_Frame2[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/2.4bpp");
static const u16 sTilesetAnims_MtEmber_Steam_Frame3[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/3.4bpp");

static const u16 *const sTilesetAnims_MtEmber_Steam[] = {
    sTilesetAnims_MtEmber_Steam_Frame0,
    sTilesetAnims_MtEmber_Steam_Frame1,
    sTilesetAnims_MtEmber_Steam_Frame2,
    sTilesetAnims_MtEmber_Steam_Frame3
};

static const u16 sTilesetAnims_VermilionGym_MotorizedDoor_Frame0[] = INCBIN_U16("data/tilesets/secondary/vermilion_gym/anim/motorizeddoor/0.4bpp");
static const u16 sTilesetAnims_VermilionGym_MotorizedDoor_Frame1[] = INCBIN_U16("data/tilesets/secondary/vermilion_gym/anim/motorizeddoor/1.4bpp");

static const u16 *const sTilesetAnims_VermilionGym_MotorizedDoor[] = {
    sTilesetAnims_VermilionGym_MotorizedDoor_Frame0,
    sTilesetAnims_VermilionGym_MotorizedDoor_Frame1
};

static const u16 sTilesetAnims_CeladonGym_Flowers_Frame0[] = INCBIN_U16("data/tilesets/secondary/celadon_gym/anim/flowers/0.4bpp");
static const u16 sTilesetAnims_CeladonGym_Flowers_Frame1[] = INCBIN_U16("data/tilesets/secondary/celadon_gym/anim/flowers/1.4bpp");
static const u16 sTilesetAnims_CeladonGym_Flowers_Frame2[] = INCBIN_U16("data/tilesets/secondary/celadon_gym/anim/flowers/2.4bpp");

static const u16 *const sTilesetAnims_CeladonGym_Flowers[] = {
    sTilesetAnims_CeladonGym_Flowers_Frame0,
    sTilesetAnims_CeladonGym_Flowers_Frame1,
    sTilesetAnims_CeladonGym_Flowers_Frame2,
    sTilesetAnims_CeladonGym_Flowers_Frame1
};

static const u16 gTilesetAnims_Underwater_Seaweed_Frame0[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/0.4bpp");
static const u16 gTilesetAnims_Underwater_Seaweed_Frame1[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/1.4bpp");
static const u16 gTilesetAnims_Underwater_Seaweed_Frame2[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/2.4bpp");
static const u16 gTilesetAnims_Underwater_Seaweed_Frame3[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/3.4bpp");

static const u16 *const gTilesetAnims_Underwater_Seaweed[] = {
    gTilesetAnims_Underwater_Seaweed_Frame0,
    gTilesetAnims_Underwater_Seaweed_Frame1,
    gTilesetAnims_Underwater_Seaweed_Frame2,
    gTilesetAnims_Underwater_Seaweed_Frame3
};

const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flag/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flag/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flag/2.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideWest_Flag[] = {
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame0,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame1,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame2,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame3
};

const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flag/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flag/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flag/2.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideEast_Flag[] = {
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame0,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame1,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame2,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame3
};

const u16 gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame0[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flower/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame1[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flower/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame2[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flower/2.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideWest_Flower[] = {
    gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame0,
    gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame1,
    gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame0,
    gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame2
};

const u16 gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame0[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flower/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame1[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flower/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame2[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flower/2.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideEast_Flower[] = {
    gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame0,
    gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame1,
    gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame0,
    gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame2
};

static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame0[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/0.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame1[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/1.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame2[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/2.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame3[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/3.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame4[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/4.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame5[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/5.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame6[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/6.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame7[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/7.4bpp");

static const u16 *const gTilesetAnims_Mossdeep_Tree_Base[] = {
    gTilesetAnims_Mossdeep_Tree_Base_Frame0,
    gTilesetAnims_Mossdeep_Tree_Base_Frame1,
    gTilesetAnims_Mossdeep_Tree_Base_Frame2,
    gTilesetAnims_Mossdeep_Tree_Base_Frame3,
    gTilesetAnims_Mossdeep_Tree_Base_Frame4,
    gTilesetAnims_Mossdeep_Tree_Base_Frame5,
    gTilesetAnims_Mossdeep_Tree_Base_Frame6,
    gTilesetAnims_Mossdeep_Tree_Base_Frame7
};

// Hoenn General primary tileset: frames and sequences copied 1:1 from pokeemerald's General.
static const u16 sTilesetAnims_HoennGeneral_Flower_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/flower/0.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Flower_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/flower/1.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Flower_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/flower/2.4bpp");

static const u16 *const sTilesetAnims_HoennGeneral_Flower[] = {
    sTilesetAnims_HoennGeneral_Flower_Frame0,
    sTilesetAnims_HoennGeneral_Flower_Frame1,
    sTilesetAnims_HoennGeneral_Flower_Frame0,
    sTilesetAnims_HoennGeneral_Flower_Frame2
};

static const u16 sTilesetAnims_HoennGeneral_Water_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/0.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Water_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/1.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Water_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/2.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Water_Frame3[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/3.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Water_Frame4[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/4.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Water_Frame5[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/5.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Water_Frame6[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/6.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Water_Frame7[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/7.4bpp");

static const u16 *const sTilesetAnims_HoennGeneral_Water[] = {
    sTilesetAnims_HoennGeneral_Water_Frame0,
    sTilesetAnims_HoennGeneral_Water_Frame1,
    sTilesetAnims_HoennGeneral_Water_Frame2,
    sTilesetAnims_HoennGeneral_Water_Frame3,
    sTilesetAnims_HoennGeneral_Water_Frame4,
    sTilesetAnims_HoennGeneral_Water_Frame5,
    sTilesetAnims_HoennGeneral_Water_Frame6,
    sTilesetAnims_HoennGeneral_Water_Frame7
};

static const u16 sTilesetAnims_HoennGeneral_SandWaterEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/0.4bpp");
static const u16 sTilesetAnims_HoennGeneral_SandWaterEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/1.4bpp");
static const u16 sTilesetAnims_HoennGeneral_SandWaterEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/2.4bpp");
static const u16 sTilesetAnims_HoennGeneral_SandWaterEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/3.4bpp");
static const u16 sTilesetAnims_HoennGeneral_SandWaterEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/4.4bpp");
static const u16 sTilesetAnims_HoennGeneral_SandWaterEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/5.4bpp");
static const u16 sTilesetAnims_HoennGeneral_SandWaterEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/6.4bpp");

static const u16 *const sTilesetAnims_HoennGeneral_SandWaterEdge[] = {
    sTilesetAnims_HoennGeneral_SandWaterEdge_Frame0,
    sTilesetAnims_HoennGeneral_SandWaterEdge_Frame1,
    sTilesetAnims_HoennGeneral_SandWaterEdge_Frame2,
    sTilesetAnims_HoennGeneral_SandWaterEdge_Frame3,
    sTilesetAnims_HoennGeneral_SandWaterEdge_Frame4,
    sTilesetAnims_HoennGeneral_SandWaterEdge_Frame5,
    sTilesetAnims_HoennGeneral_SandWaterEdge_Frame6,
    sTilesetAnims_HoennGeneral_SandWaterEdge_Frame0
};

static const u16 sTilesetAnims_HoennGeneral_Waterfall_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/waterfall/0.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Waterfall_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/waterfall/1.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Waterfall_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/waterfall/2.4bpp");
static const u16 sTilesetAnims_HoennGeneral_Waterfall_Frame3[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/waterfall/3.4bpp");

static const u16 *const sTilesetAnims_HoennGeneral_Waterfall[] = {
    sTilesetAnims_HoennGeneral_Waterfall_Frame0,
    sTilesetAnims_HoennGeneral_Waterfall_Frame1,
    sTilesetAnims_HoennGeneral_Waterfall_Frame2,
    sTilesetAnims_HoennGeneral_Waterfall_Frame3
};

static const u16 sTilesetAnims_HoennGeneral_LandWaterEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/land_water_edge/0.4bpp");
static const u16 sTilesetAnims_HoennGeneral_LandWaterEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/land_water_edge/1.4bpp");
static const u16 sTilesetAnims_HoennGeneral_LandWaterEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/land_water_edge/2.4bpp");
static const u16 sTilesetAnims_HoennGeneral_LandWaterEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/land_water_edge/3.4bpp");

static const u16 *const sTilesetAnims_HoennGeneral_LandWaterEdge[] = {
    sTilesetAnims_HoennGeneral_LandWaterEdge_Frame0,
    sTilesetAnims_HoennGeneral_LandWaterEdge_Frame1,
    sTilesetAnims_HoennGeneral_LandWaterEdge_Frame2,
    sTilesetAnims_HoennGeneral_LandWaterEdge_Frame3
};

// Hoenn InsideBuilding primary tileset: pokeemerald's Building TV (turned on), frames copied 1:1.
static const u16 sTilesetAnims_HoennInsideBuilding_TvTurnedOn_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_inside_building/anim/tv_turned_on/0.4bpp");
static const u16 sTilesetAnims_HoennInsideBuilding_TvTurnedOn_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_inside_building/anim/tv_turned_on/1.4bpp");

static const u16 *const sTilesetAnims_HoennInsideBuilding_TvTurnedOn[] = {
    sTilesetAnims_HoennInsideBuilding_TvTurnedOn_Frame0,
    sTilesetAnims_HoennInsideBuilding_TvTurnedOn_Frame1
};

static void ResetTilesetAnimBuffer(void)
{
    sTilesetDMA3TransferBufferSize = 0;
    CpuFill32(0, sTilesetDMA3TransferBuffer, sizeof sTilesetDMA3TransferBuffer);
}

static void AppendTilesetAnimToBuffer(const u16 *src, u16 *dest, u16 size)
{
    if (sTilesetDMA3TransferBufferSize < 20)
    {
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].src = src;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].dest = dest;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].size = size;
        sTilesetDMA3TransferBufferSize++;
    }
}

void TransferTilesetAnimsBuffer(void)
{
    int i;

    for (i = 0; i < sTilesetDMA3TransferBufferSize; i++)
        DmaCopy16(3, sTilesetDMA3TransferBuffer[i].src, sTilesetDMA3TransferBuffer[i].dest, sTilesetDMA3TransferBuffer[i].size);

    sTilesetDMA3TransferBufferSize = 0;
}

void InitTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    _InitPrimaryTilesetAnimation();
    _InitSecondaryTilesetAnimation();
}

void InitSecondaryTilesetAnimation(void)
{
    _InitSecondaryTilesetAnimation();
}

void UpdateTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    if (++sPrimaryTilesetAnimCounter >= sPrimaryTilesetAnimCounterMax)
        sPrimaryTilesetAnimCounter = 0;
    if (++sSecondaryTilesetAnimCounter >= sSecondaryTilesetAnimCounterMax)
        sSecondaryTilesetAnimCounter = 0;

    if (sPrimaryTilesetAnimCallback)
        sPrimaryTilesetAnimCallback(sPrimaryTilesetAnimCounter);
    if (sSecondaryTilesetAnimCallback)
        sSecondaryTilesetAnimCallback(sSecondaryTilesetAnimCounter);
}

static void _InitPrimaryTilesetAnimation(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 0;
    sPrimaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->primaryTileset && gMapHeader.mapLayout->primaryTileset->callback)
        gMapHeader.mapLayout->primaryTileset->callback();
}

static void _InitSecondaryTilesetAnimation(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 0;
    sSecondaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->secondaryTileset && gMapHeader.mapLayout->secondaryTileset->callback)
        gMapHeader.mapLayout->secondaryTileset->callback();
}

static void QueueAnimTiles_General_Flower(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_General_Flower[timer % ARRAY_COUNT(sTilesetAnims_General_Flower)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(508)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_Water_Current_LandWatersEdge(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_General_Water_Current_LandWatersEdge[timer % ARRAY_COUNT(sTilesetAnims_General_Water_Current_LandWatersEdge)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(416)), 48 * TILE_SIZE_4BPP);
    AppendTilesetAnimToBuffer(gTilesetAnims_Mossdeep_Tree_Base[timer % ARRAY_COUNT(gTilesetAnims_Mossdeep_Tree_Base)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(492)), 0x80);
}

static void QueueAnimTiles_General_SandWatersEdge(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_General_SandWatersEdge[timer % ARRAY_COUNT(sTilesetAnims_General_SandWatersEdge)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(464)), 18 * TILE_SIZE_4BPP);
}

static void TilesetAnim_General(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_General_SandWatersEdge(timer / 8);
    if (timer % 16 == 1)
        QueueAnimTiles_General_Water_Current_LandWatersEdge(timer / 16);
    if (timer % 16 == 2)
        QueueAnimTiles_General_Flower(timer / 16);
}

void InitTilesetAnim_General(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 640;
    sPrimaryTilesetAnimCallback = TilesetAnim_General;
}

// Same schedule as pokeemerald's TilesetAnim_General / QueueAnimTiles_General_*.
static void TilesetAnim_HoennGeneral(u16 timer)
{
    u16 i = timer / 16;

    switch (timer % 16)
    {
    case 0:
        AppendTilesetAnimToBuffer(sTilesetAnims_HoennGeneral_Flower[i % ARRAY_COUNT(sTilesetAnims_HoennGeneral_Flower)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(508)), 4 * TILE_SIZE_4BPP);
        break;
    case 1:
        AppendTilesetAnimToBuffer(sTilesetAnims_HoennGeneral_Water[i % ARRAY_COUNT(sTilesetAnims_HoennGeneral_Water)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(432)), 30 * TILE_SIZE_4BPP);
        break;
    case 2:
        AppendTilesetAnimToBuffer(sTilesetAnims_HoennGeneral_SandWaterEdge[i % ARRAY_COUNT(sTilesetAnims_HoennGeneral_SandWaterEdge)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(464)), 10 * TILE_SIZE_4BPP);
        break;
    case 3:
        AppendTilesetAnimToBuffer(sTilesetAnims_HoennGeneral_Waterfall[i % ARRAY_COUNT(sTilesetAnims_HoennGeneral_Waterfall)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(496)), 6 * TILE_SIZE_4BPP);
        break;
    case 4:
        AppendTilesetAnimToBuffer(sTilesetAnims_HoennGeneral_LandWaterEdge[i % ARRAY_COUNT(sTilesetAnims_HoennGeneral_LandWaterEdge)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(480)), 10 * TILE_SIZE_4BPP);
        break;
    }
}

void InitTilesetAnim_HoennGeneral(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 256;
    sPrimaryTilesetAnimCallback = TilesetAnim_HoennGeneral;
}

// Same schedule as pokeemerald's TilesetAnim_Building / QueueAnimTiles_Building_TVTurnedOn.
static void TilesetAnim_HoennInsideBuilding(u16 timer)
{
    if (timer % 8 == 0)
        AppendTilesetAnimToBuffer(sTilesetAnims_HoennInsideBuilding_TvTurnedOn[(timer / 8) % ARRAY_COUNT(sTilesetAnims_HoennInsideBuilding_TvTurnedOn)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(496)), 4 * TILE_SIZE_4BPP);
}

void InitTilesetAnim_HoennInsideBuilding(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 256;
    sPrimaryTilesetAnimCallback = TilesetAnim_HoennInsideBuilding;
}

// Emerald's secondary tileset animations (pokeemerald src/tileset_anims.c: same frames, sequences and schedules) for
// the Hoenn secondaries of tools/hoenn_import. The tool keeps each animated range of an Emerald tileset whole and
// contiguous (hoenn_import.py ANIMATED_TILES), at a tile that depends on the FRLG tileset: the InitTilesetAnim_Hoenn*
// it generates (src/data/tilesets/hoenn_anims.h) point sHoennAnimRanges to that tileset's ranges, so the schedules
// below name a destination by its Emerald tile (NUM_TILES_IN_PRIMARY + n in Emerald -> n here).
struct HoennAnimRange
{
    u16 first; // Emerald secondary tiles first...
    u16 count; // ...to first + count - 1 (what Emerald's tiles.png holds of the range)
    u16 tile;  // are at this VRAM tile here
};

static const struct HoennAnimRange *sHoennAnimRanges;

static void QueueHoennAnim(const u16 *src, u16 emeraldTile, u16 numTiles)
{
    const struct HoennAnimRange *range;

    for (range = sHoennAnimRanges; range->count != 0; range++)
    {
        if (emeraldTile >= range->first && emeraldTile < range->first + range->count)
        {
            if (numTiles > range->first + range->count - emeraldTile) // never past the range: other tiles follow it here
                numTiles = range->first + range->count - emeraldTile;
            AppendTilesetAnimToBuffer(src, (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(range->tile + emeraldTile - range->first)), numTiles * TILE_SIZE_4BPP);
            return;
        }
    }
}

static const u16 sTilesetAnims_HoennRustboro_WindyWater_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/0.4bpp");
static const u16 sTilesetAnims_HoennRustboro_WindyWater_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/1.4bpp");
static const u16 sTilesetAnims_HoennRustboro_WindyWater_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/2.4bpp");
static const u16 sTilesetAnims_HoennRustboro_WindyWater_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/3.4bpp");
static const u16 sTilesetAnims_HoennRustboro_WindyWater_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/4.4bpp");
static const u16 sTilesetAnims_HoennRustboro_WindyWater_Frame5[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/5.4bpp");
static const u16 sTilesetAnims_HoennRustboro_WindyWater_Frame6[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/6.4bpp");
static const u16 sTilesetAnims_HoennRustboro_WindyWater_Frame7[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/7.4bpp");

static const u16 *const sTilesetAnims_HoennRustboro_WindyWater[] = {
    sTilesetAnims_HoennRustboro_WindyWater_Frame0,
    sTilesetAnims_HoennRustboro_WindyWater_Frame1,
    sTilesetAnims_HoennRustboro_WindyWater_Frame2,
    sTilesetAnims_HoennRustboro_WindyWater_Frame3,
    sTilesetAnims_HoennRustboro_WindyWater_Frame4,
    sTilesetAnims_HoennRustboro_WindyWater_Frame5,
    sTilesetAnims_HoennRustboro_WindyWater_Frame6,
    sTilesetAnims_HoennRustboro_WindyWater_Frame7
};

static const u16 sTilesetAnims_HoennRustboro_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/fountain/0.4bpp");
static const u16 sTilesetAnims_HoennRustboro_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/fountain/1.4bpp");

static const u16 *const sTilesetAnims_HoennRustboro_Fountain[] = {
    sTilesetAnims_HoennRustboro_Fountain_Frame0,
    sTilesetAnims_HoennRustboro_Fountain_Frame1
};

static const u16 sTilesetAnims_HoennSlateport_Balloons_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_slateport/anim/balloons/0.4bpp");
static const u16 sTilesetAnims_HoennSlateport_Balloons_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_slateport/anim/balloons/1.4bpp");
static const u16 sTilesetAnims_HoennSlateport_Balloons_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_slateport/anim/balloons/2.4bpp");
static const u16 sTilesetAnims_HoennSlateport_Balloons_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_slateport/anim/balloons/3.4bpp");

static const u16 *const sTilesetAnims_HoennSlateport_Balloons[] = {
    sTilesetAnims_HoennSlateport_Balloons_Frame0,
    sTilesetAnims_HoennSlateport_Balloons_Frame1,
    sTilesetAnims_HoennSlateport_Balloons_Frame2,
    sTilesetAnims_HoennSlateport_Balloons_Frame3
};

static const u16 sTilesetAnims_HoennMauville_Flower1_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/0.4bpp");
static const u16 sTilesetAnims_HoennMauville_Flower1_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/1.4bpp");
static const u16 sTilesetAnims_HoennMauville_Flower1_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/2.4bpp");
static const u16 sTilesetAnims_HoennMauville_Flower1_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/3.4bpp");
static const u16 sTilesetAnims_HoennMauville_Flower1_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/4.4bpp");
static const u16 sTilesetAnims_HoennMauville_Flower2_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/0.4bpp");
static const u16 sTilesetAnims_HoennMauville_Flower2_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/1.4bpp");
static const u16 sTilesetAnims_HoennMauville_Flower2_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/2.4bpp");
static const u16 sTilesetAnims_HoennMauville_Flower2_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/3.4bpp");
static const u16 sTilesetAnims_HoennMauville_Flower2_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/4.4bpp");

static const u16 *const sTilesetAnims_HoennMauville_Flower1[] = {
    sTilesetAnims_HoennMauville_Flower1_Frame0,
    sTilesetAnims_HoennMauville_Flower1_Frame0,
    sTilesetAnims_HoennMauville_Flower1_Frame1,
    sTilesetAnims_HoennMauville_Flower1_Frame2,
    sTilesetAnims_HoennMauville_Flower1_Frame3,
    sTilesetAnims_HoennMauville_Flower1_Frame3,
    sTilesetAnims_HoennMauville_Flower1_Frame3,
    sTilesetAnims_HoennMauville_Flower1_Frame3,
    sTilesetAnims_HoennMauville_Flower1_Frame3,
    sTilesetAnims_HoennMauville_Flower1_Frame3,
    sTilesetAnims_HoennMauville_Flower1_Frame2,
    sTilesetAnims_HoennMauville_Flower1_Frame1
};

static const u16 *const sTilesetAnims_HoennMauville_Flower2[] = {
    sTilesetAnims_HoennMauville_Flower2_Frame0,
    sTilesetAnims_HoennMauville_Flower2_Frame0,
    sTilesetAnims_HoennMauville_Flower2_Frame1,
    sTilesetAnims_HoennMauville_Flower2_Frame2,
    sTilesetAnims_HoennMauville_Flower2_Frame3,
    sTilesetAnims_HoennMauville_Flower2_Frame3,
    sTilesetAnims_HoennMauville_Flower2_Frame3,
    sTilesetAnims_HoennMauville_Flower2_Frame3,
    sTilesetAnims_HoennMauville_Flower2_Frame3,
    sTilesetAnims_HoennMauville_Flower2_Frame3,
    sTilesetAnims_HoennMauville_Flower2_Frame2,
    sTilesetAnims_HoennMauville_Flower2_Frame1
};

static const u16 *const sTilesetAnims_HoennMauville_Flower1_B[] = {
    sTilesetAnims_HoennMauville_Flower1_Frame0,
    sTilesetAnims_HoennMauville_Flower1_Frame0,
    sTilesetAnims_HoennMauville_Flower1_Frame4,
    sTilesetAnims_HoennMauville_Flower1_Frame4
};

static const u16 *const sTilesetAnims_HoennMauville_Flower2_B[] = {
    sTilesetAnims_HoennMauville_Flower2_Frame0,
    sTilesetAnims_HoennMauville_Flower2_Frame0,
    sTilesetAnims_HoennMauville_Flower2_Frame4,
    sTilesetAnims_HoennMauville_Flower2_Frame4
};

static const u16 sTilesetAnims_HoennLavaridge_Steam_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_lavaridge/anim/steam/0.4bpp");
static const u16 sTilesetAnims_HoennLavaridge_Steam_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_lavaridge/anim/steam/1.4bpp");
static const u16 sTilesetAnims_HoennLavaridge_Steam_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_lavaridge/anim/steam/2.4bpp");
static const u16 sTilesetAnims_HoennLavaridge_Steam_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_lavaridge/anim/steam/3.4bpp");

static const u16 *const sTilesetAnims_HoennLavaridge_Steam[] = {
    sTilesetAnims_HoennLavaridge_Steam_Frame0,
    sTilesetAnims_HoennLavaridge_Steam_Frame1,
    sTilesetAnims_HoennLavaridge_Steam_Frame2,
    sTilesetAnims_HoennLavaridge_Steam_Frame3
};

// Emerald's Lavaridge and Cave lava (gTilesetAnims_Lavaridge_Cave_Lava: frames 4-7 of its folder are unused)
static const u16 sTilesetAnims_HoennCave_Lava_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/0.4bpp");
static const u16 sTilesetAnims_HoennCave_Lava_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/1.4bpp");
static const u16 sTilesetAnims_HoennCave_Lava_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/2.4bpp");
static const u16 sTilesetAnims_HoennCave_Lava_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/3.4bpp");

static const u16 *const sTilesetAnims_HoennCave_Lava[] = {
    sTilesetAnims_HoennCave_Lava_Frame0,
    sTilesetAnims_HoennCave_Lava_Frame1,
    sTilesetAnims_HoennCave_Lava_Frame2,
    sTilesetAnims_HoennCave_Lava_Frame3
};

static const u16 sTilesetAnims_HoennEverGrande_Flowers_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/0.4bpp");
static const u16 sTilesetAnims_HoennEverGrande_Flowers_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/1.4bpp");
static const u16 sTilesetAnims_HoennEverGrande_Flowers_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/2.4bpp");
static const u16 sTilesetAnims_HoennEverGrande_Flowers_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/3.4bpp");
static const u16 sTilesetAnims_HoennEverGrande_Flowers_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/4.4bpp");
static const u16 sTilesetAnims_HoennEverGrande_Flowers_Frame5[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/5.4bpp");
static const u16 sTilesetAnims_HoennEverGrande_Flowers_Frame6[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/6.4bpp");
static const u16 sTilesetAnims_HoennEverGrande_Flowers_Frame7[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/7.4bpp");

static const u16 *const sTilesetAnims_HoennEverGrande_Flowers[] = {
    sTilesetAnims_HoennEverGrande_Flowers_Frame0,
    sTilesetAnims_HoennEverGrande_Flowers_Frame1,
    sTilesetAnims_HoennEverGrande_Flowers_Frame2,
    sTilesetAnims_HoennEverGrande_Flowers_Frame3,
    sTilesetAnims_HoennEverGrande_Flowers_Frame4,
    sTilesetAnims_HoennEverGrande_Flowers_Frame5,
    sTilesetAnims_HoennEverGrande_Flowers_Frame6,
    sTilesetAnims_HoennEverGrande_Flowers_Frame7
};

static const u16 sTilesetAnims_HoennPacifidlog_LogBridges_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/log_bridges/0.4bpp");
static const u16 sTilesetAnims_HoennPacifidlog_LogBridges_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/log_bridges/1.4bpp");
static const u16 sTilesetAnims_HoennPacifidlog_LogBridges_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/log_bridges/2.4bpp");

static const u16 *const sTilesetAnims_HoennPacifidlog_LogBridges[] = {
    sTilesetAnims_HoennPacifidlog_LogBridges_Frame0,
    sTilesetAnims_HoennPacifidlog_LogBridges_Frame1,
    sTilesetAnims_HoennPacifidlog_LogBridges_Frame2,
    sTilesetAnims_HoennPacifidlog_LogBridges_Frame1
};

static const u16 sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/0.4bpp");
static const u16 sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/1.4bpp");
static const u16 sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/2.4bpp");
static const u16 sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/3.4bpp");
static const u16 sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/4.4bpp");
static const u16 sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame5[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/5.4bpp");
static const u16 sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame6[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/6.4bpp");
static const u16 sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame7[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/7.4bpp");

static const u16 *const sTilesetAnims_HoennPacifidlog_WaterCurrents[] = {
    sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame0,
    sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame1,
    sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame2,
    sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame3,
    sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame4,
    sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame5,
    sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame6,
    sTilesetAnims_HoennPacifidlog_WaterCurrents_Frame7
};

static const u16 sTilesetAnims_HoennSootopolis_StormyWater_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/0_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/0_groudon.4bpp");
static const u16 sTilesetAnims_HoennSootopolis_StormyWater_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/1_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/1_groudon.4bpp");
static const u16 sTilesetAnims_HoennSootopolis_StormyWater_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/2_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/2_groudon.4bpp");
static const u16 sTilesetAnims_HoennSootopolis_StormyWater_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/3_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/3_groudon.4bpp");
static const u16 sTilesetAnims_HoennSootopolis_StormyWater_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/4_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/4_groudon.4bpp");
static const u16 sTilesetAnims_HoennSootopolis_StormyWater_Frame5[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/5_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/5_groudon.4bpp");
static const u16 sTilesetAnims_HoennSootopolis_StormyWater_Frame6[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/6_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/6_groudon.4bpp");
static const u16 sTilesetAnims_HoennSootopolis_StormyWater_Frame7[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/7_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/7_groudon.4bpp");

static const u16 *const sTilesetAnims_HoennSootopolis_StormyWater[] = {
    sTilesetAnims_HoennSootopolis_StormyWater_Frame0,
    sTilesetAnims_HoennSootopolis_StormyWater_Frame1,
    sTilesetAnims_HoennSootopolis_StormyWater_Frame2,
    sTilesetAnims_HoennSootopolis_StormyWater_Frame3,
    sTilesetAnims_HoennSootopolis_StormyWater_Frame4,
    sTilesetAnims_HoennSootopolis_StormyWater_Frame5,
    sTilesetAnims_HoennSootopolis_StormyWater_Frame6,
    sTilesetAnims_HoennSootopolis_StormyWater_Frame7
};

// Emerald's side waterfall (+496) is beyond its tiles.png, so no tileset here keeps it: only the front one is ported.
static const u16 sTilesetAnims_HoennSootopolisGym_FrontWaterfall_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis_gym/anim/front_waterfall/0.4bpp");
static const u16 sTilesetAnims_HoennSootopolisGym_FrontWaterfall_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis_gym/anim/front_waterfall/1.4bpp");
static const u16 sTilesetAnims_HoennSootopolisGym_FrontWaterfall_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis_gym/anim/front_waterfall/2.4bpp");

static const u16 *const sTilesetAnims_HoennSootopolisGym_FrontWaterfall[] = {
    sTilesetAnims_HoennSootopolisGym_FrontWaterfall_Frame0,
    sTilesetAnims_HoennSootopolisGym_FrontWaterfall_Frame1,
    sTilesetAnims_HoennSootopolisGym_FrontWaterfall_Frame2
};

static const u16 sTilesetAnims_HoennEliteFour_FloorLight_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/floor_light/0.4bpp");
static const u16 sTilesetAnims_HoennEliteFour_FloorLight_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/floor_light/1.4bpp");
static const u16 sTilesetAnims_HoennEliteFour_WallLights_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/wall_lights/0.4bpp");
static const u16 sTilesetAnims_HoennEliteFour_WallLights_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/wall_lights/1.4bpp");
static const u16 sTilesetAnims_HoennEliteFour_WallLights_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/wall_lights/2.4bpp");
static const u16 sTilesetAnims_HoennEliteFour_WallLights_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/wall_lights/3.4bpp");

static const u16 *const sTilesetAnims_HoennEliteFour_FloorLight[] = {
    sTilesetAnims_HoennEliteFour_FloorLight_Frame0,
    sTilesetAnims_HoennEliteFour_FloorLight_Frame1
};

static const u16 *const sTilesetAnims_HoennEliteFour_WallLights[] = {
    sTilesetAnims_HoennEliteFour_WallLights_Frame0,
    sTilesetAnims_HoennEliteFour_WallLights_Frame1,
    sTilesetAnims_HoennEliteFour_WallLights_Frame2,
    sTilesetAnims_HoennEliteFour_WallLights_Frame3
};

static const u16 sTilesetAnims_HoennMauvilleGym_ElectricGates_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville_gym/anim/electric_gates/0.4bpp");
static const u16 sTilesetAnims_HoennMauvilleGym_ElectricGates_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville_gym/anim/electric_gates/1.4bpp");

static const u16 *const sTilesetAnims_HoennMauvilleGym_ElectricGates[] = {
    sTilesetAnims_HoennMauvilleGym_ElectricGates_Frame0,
    sTilesetAnims_HoennMauvilleGym_ElectricGates_Frame1
};

static const u16 sTilesetAnims_HoennBikeShop_BlinkingLights_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_bike_shop/anim/blinking_lights/0.4bpp");
static const u16 sTilesetAnims_HoennBikeShop_BlinkingLights_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_bike_shop/anim/blinking_lights/1.4bpp");

static const u16 *const sTilesetAnims_HoennBikeShop_BlinkingLights[] = {
    sTilesetAnims_HoennBikeShop_BlinkingLights_Frame0,
    sTilesetAnims_HoennBikeShop_BlinkingLights_Frame1
};

static const u16 sTilesetAnims_HoennBattlePyramid_Torch_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/torch/0.4bpp");
static const u16 sTilesetAnims_HoennBattlePyramid_Torch_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/torch/1.4bpp");
static const u16 sTilesetAnims_HoennBattlePyramid_Torch_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/torch/2.4bpp");

static const u16 *const sTilesetAnims_HoennBattlePyramid_Torch[] = {
    sTilesetAnims_HoennBattlePyramid_Torch_Frame0,
    sTilesetAnims_HoennBattlePyramid_Torch_Frame1,
    sTilesetAnims_HoennBattlePyramid_Torch_Frame2
};

static const u16 sTilesetAnims_HoennBattlePyramid_StatueShadow_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/statue_shadow/0.4bpp");
static const u16 sTilesetAnims_HoennBattlePyramid_StatueShadow_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/statue_shadow/1.4bpp");
static const u16 sTilesetAnims_HoennBattlePyramid_StatueShadow_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/statue_shadow/2.4bpp");

static const u16 *const sTilesetAnims_HoennBattlePyramid_StatueShadow[] = {
    sTilesetAnims_HoennBattlePyramid_StatueShadow_Frame0,
    sTilesetAnims_HoennBattlePyramid_StatueShadow_Frame1,
    sTilesetAnims_HoennBattlePyramid_StatueShadow_Frame2
};

// The schedules: pokeemerald's TilesetAnim_<Emerald tileset> and QueueAnimTiles_*, one call per Emerald copy.
static void TilesetAnim_HoennRustboro(u16 timer)
{
    u16 i = timer / 8 - timer % 8; // QueueAnimTiles_Rustboro_WindyWater: u16 wrap, 8 frames

    QueueHoennAnim(sTilesetAnims_HoennRustboro_WindyWater[i % ARRAY_COUNT(sTilesetAnims_HoennRustboro_WindyWater)], 128 + 4 * (timer % 8), 4);
    if (timer % 8 == 0)
        QueueHoennAnim(sTilesetAnims_HoennRustboro_Fountain[(timer / 8) % ARRAY_COUNT(sTilesetAnims_HoennRustboro_Fountain)], 448, 4);
}

static void TilesetAnim_HoennSlateport(u16 timer)
{
    if (timer % 16 == 0)
        QueueHoennAnim(sTilesetAnims_HoennSlateport_Balloons[(timer / 16) % ARRAY_COUNT(sTilesetAnims_HoennSlateport_Balloons)], 224, 4);
}

static void TilesetAnim_HoennMauville(u16 timer)
{
    u16 i = timer / 8 - timer % 8; // QueueAnimTiles_Mauville_Flowers
    u16 dest = 4 * (timer % 8);

    if (i < ARRAY_COUNT(sTilesetAnims_HoennMauville_Flower1))
    {
        QueueHoennAnim(sTilesetAnims_HoennMauville_Flower1[i], 96 + dest, 4);
        QueueHoennAnim(sTilesetAnims_HoennMauville_Flower2[i], 128 + dest, 4);
    }
    else
    {
        i %= ARRAY_COUNT(sTilesetAnims_HoennMauville_Flower1_B);
        QueueHoennAnim(sTilesetAnims_HoennMauville_Flower1_B[i], 96 + dest, 4);
        QueueHoennAnim(sTilesetAnims_HoennMauville_Flower2_B[i], 128 + dest, 4);
    }
}

static void TilesetAnim_HoennLavaridge(u16 timer)
{
    u8 i = timer / 16;

    if (timer % 16 == 0)
    {
        QueueHoennAnim(sTilesetAnims_HoennLavaridge_Steam[i % ARRAY_COUNT(sTilesetAnims_HoennLavaridge_Steam)], 288, 4);
        QueueHoennAnim(sTilesetAnims_HoennLavaridge_Steam[(i + 2) % ARRAY_COUNT(sTilesetAnims_HoennLavaridge_Steam)], 292, 4);
    }
    if (timer % 16 == 1)
        QueueHoennAnim(sTilesetAnims_HoennCave_Lava[i % ARRAY_COUNT(sTilesetAnims_HoennCave_Lava)], 160, 4);
}

static void TilesetAnim_HoennEverGrande(u16 timer)
{
    u16 i = timer / 8 - timer % 8; // QueueAnimTiles_EverGrande_Flowers: u16 wrap, 8 frames

    QueueHoennAnim(sTilesetAnims_HoennEverGrande_Flowers[i % ARRAY_COUNT(sTilesetAnims_HoennEverGrande_Flowers)], 224 + 4 * (timer % 8), 4);
}

static void TilesetAnim_HoennPacifidlog(u16 timer)
{
    if (timer % 16 == 0)
        QueueHoennAnim(sTilesetAnims_HoennPacifidlog_LogBridges[(timer / 16) % ARRAY_COUNT(sTilesetAnims_HoennPacifidlog_LogBridges)], 464, 30);
    if (timer % 16 == 1)
        QueueHoennAnim(sTilesetAnims_HoennPacifidlog_WaterCurrents[(timer / 16) % ARRAY_COUNT(sTilesetAnims_HoennPacifidlog_WaterCurrents)], 496, 8);
}

static void TilesetAnim_HoennSootopolis(u16 timer)
{
    if (timer % 16 == 0)
        QueueHoennAnim(sTilesetAnims_HoennSootopolis_StormyWater[(timer / 16) % ARRAY_COUNT(sTilesetAnims_HoennSootopolis_StormyWater)], 240, 96);
}

static void TilesetAnim_HoennUnderwater(u16 timer)
{
    if (timer % 16 == 0) // Emerald's seaweed frames are FRLG-Plus's own (same PNGs)
        QueueHoennAnim(gTilesetAnims_Underwater_Seaweed[(timer / 16) % ARRAY_COUNT(gTilesetAnims_Underwater_Seaweed)], 496, 4);
}

static void TilesetAnim_HoennSootopolisGym(u16 timer)
{
    if (timer % 8 == 0)
        QueueHoennAnim(sTilesetAnims_HoennSootopolisGym_FrontWaterfall[(timer / 8) % ARRAY_COUNT(sTilesetAnims_HoennSootopolisGym_FrontWaterfall)], 464, 20);
}

static void TilesetAnim_HoennCave(u16 timer)
{
    if (timer % 16 == 1)
        QueueHoennAnim(sTilesetAnims_HoennCave_Lava[(timer / 16) % ARRAY_COUNT(sTilesetAnims_HoennCave_Lava)], 416, 4);
}

static void TilesetAnim_HoennEliteFour(u16 timer)
{
    if (timer % 64 == 1)
        QueueHoennAnim(sTilesetAnims_HoennEliteFour_FloorLight[(timer / 64) % ARRAY_COUNT(sTilesetAnims_HoennEliteFour_FloorLight)], 480, 4);
    if (timer % 8 == 1)
        QueueHoennAnim(sTilesetAnims_HoennEliteFour_WallLights[(timer / 8) % ARRAY_COUNT(sTilesetAnims_HoennEliteFour_WallLights)], 504, 1);
}

static void TilesetAnim_HoennMauvilleGym(u16 timer)
{
    if (timer % 2 == 0)
        QueueHoennAnim(sTilesetAnims_HoennMauvilleGym_ElectricGates[(timer / 2) % ARRAY_COUNT(sTilesetAnims_HoennMauvilleGym_ElectricGates)], 144, 16);
}

static void TilesetAnim_HoennBikeShop(u16 timer)
{
    if (timer % 4 == 0)
        QueueHoennAnim(sTilesetAnims_HoennBikeShop_BlinkingLights[(timer / 4) % ARRAY_COUNT(sTilesetAnims_HoennBikeShop_BlinkingLights)], 496, 9);
}

static void TilesetAnim_HoennBattlePyramid(u16 timer)
{
    if (timer % 8 == 0)
    {
        QueueHoennAnim(sTilesetAnims_HoennBattlePyramid_Torch[(timer / 8) % ARRAY_COUNT(sTilesetAnims_HoennBattlePyramid_Torch)], 151, 8);
        QueueHoennAnim(sTilesetAnims_HoennBattlePyramid_StatueShadow[(timer / 8) % ARRAY_COUNT(sTilesetAnims_HoennBattlePyramid_StatueShadow)], 135, 8);
    }
}

static void QueueAnimTiles_CeladonCity_Fountain(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_CeladonCity_Fountain[timer % ARRAY_COUNT(sTilesetAnims_CeladonCity_Fountain)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(744)), 8 * TILE_SIZE_4BPP);
}

static void TilesetAnim_CeladonCity(u16 timer)
{
    if (timer % 12 == 0)
        QueueAnimTiles_CeladonCity_Fountain(timer / 12);
}

void InitTilesetAnim_CeladonCity(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 120;
    sSecondaryTilesetAnimCallback = TilesetAnim_CeladonCity;
}

static void QueueAnimTiles_SilphCo_Fountain(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_SilphCo_Fountain[timer % ARRAY_COUNT(sTilesetAnims_SilphCo_Fountain)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(976)), 8 * TILE_SIZE_4BPP);
}

static void TilesetAnim_SilphCo(u16 timer)
{
    if (timer % 10 == 0)
        QueueAnimTiles_SilphCo_Fountain(timer / 10);
}

void InitTilesetAnim_SilphCo(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 160;
    sSecondaryTilesetAnimCallback = TilesetAnim_SilphCo;
}

static void QueueAnimTiles_MtEmber_Steam(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_MtEmber_Steam[timer % ARRAY_COUNT(sTilesetAnims_MtEmber_Steam)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(896)), 8 * TILE_SIZE_4BPP);
}

static void TilesetAnim_MtEmber(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_MtEmber_Steam(timer / 16);
}

void InitTilesetAnim_MtEmber(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_MtEmber;
}

static void QueueAnimTiles_VermilionGym_MotorizedDoor(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(sTilesetAnims_VermilionGym_MotorizedDoor);

    AppendTilesetAnimToBuffer(sTilesetAnims_VermilionGym_MotorizedDoor[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(880)), 7 * TILE_SIZE_4BPP);
}

static void TilesetAnim_VermilionGym(u16 timer)
{
    if (timer % 2 == 0)
        QueueAnimTiles_VermilionGym_MotorizedDoor(timer / 2);
}

void InitTilesetAnim_VermilionGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 240;
    sSecondaryTilesetAnimCallback = TilesetAnim_VermilionGym;
}

static void QueueAnimTiles_CeladonGym_Flowers(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(sTilesetAnims_CeladonGym_Flowers);
    
    AppendTilesetAnimToBuffer(sTilesetAnims_CeladonGym_Flowers[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(739)), 4 * TILE_SIZE_4BPP);
}

static void TilesetAnim_CeladonGym(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_CeladonGym_Flowers(timer / 16);
}

void InitTilesetAnim_CeladonGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_CeladonGym;
}

static void QueueAnimTiles_Underwater_Seaweed(u8 timer)
{
    u8 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Underwater_Seaweed[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x2B5)), 0x80);
}

static void TilesetAnim_Underwater(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Underwater_Seaweed(timer >> 4);
}

void InitTilesetAnim_Underwater(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 128;
    sSecondaryTilesetAnimCallback = TilesetAnim_Underwater;
}

static void QueueAnimTiles_BattleFrontierOutsideWest_Flag(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideWest_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x300)), 0xC0);
}

static void QueueAnimTiles_BattleFrontierOutsideEast_Flag(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideEast_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x300)), 0xC0);
}

static void QueueAnimTiles_BattleFrontierOutsideWest_Flower(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideWest_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x312)), 0x80);
}

static void QueueAnimTiles_BattleFrontierOutsideEast_Flower(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideEast_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x312)), 0x80);
}

static void TilesetAnim_BattleFrontierOutsideWest(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_BattleFrontierOutsideWest_Flower(timer >> 4);
    if (timer % 8 == 0)
        QueueAnimTiles_BattleFrontierOutsideWest_Flag(timer >> 3);
}

static void TilesetAnim_BattleFrontierOutsideEast(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_BattleFrontierOutsideEast_Flower(timer >> 4);
    if (timer % 8 == 0)
        QueueAnimTiles_BattleFrontierOutsideEast_Flag(timer >> 3);
}

void InitTilesetAnim_BattleFrontierOutsideWest(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleFrontierOutsideWest;
}

void InitTilesetAnim_BattleFrontierOutsideEast(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleFrontierOutsideEast;
}

static void QueueAnimTiles_SeviiIslands67_Flower(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideEast_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x377)), 0x80);
}

static void TilesetAnim_SeviiIslands67(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_SeviiIslands67_Flower(timer >> 4);
}

void InitTilesetAnim_SeviiIslands67(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_SeviiIslands67;
}

static void QueueAnimTiles_SeviiIslands5_ShortGrassFlower(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_General_Flower[timer % NELEMS(sTilesetAnims_General_Flower)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x324)), 0x80);
}

static void TilesetAnim_SeviiIslands5(u16 timer)
{
    if (timer % 16 == 2)
        QueueAnimTiles_SeviiIslands5_ShortGrassFlower(timer >> 4);
}

void InitTilesetAnim_SeviiIslands5(void)
{
    sSecondaryTilesetAnimCounter = sPrimaryTilesetAnimCounter;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_SeviiIslands5;
}

// Generated: InitTilesetAnim_Hoenn* of the Hoenn secondaries (tools/hoenn_import register_anims)
#include "data/tilesets/hoenn_anims.h"

// Generated: PokemonHnS's tile animations of the Johto tilesets (tools/johto_import plan_anims)
#include "data/tilesets/johto_anims.h"
