#include "global.h"
#include "gflib.h"
#include "scanline_effect.h"
#include "task.h"
#include "m4a.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "party_menu.h"
#include "field_effect.h"
#include "new_menu_helpers.h"
#include "menu.h"
#include "strings.h"
#include "map_preview_screen.h"
#include "list_menu.h"
#include "menu_indicators.h"
#include "constants/songs.h"
#include "constants/region_map_sections.h"
#include "constants/heal_locations.h"
#include "constants/maps.h"

#define MAP_WIDTH 22  // FRLG's region layouts (region_map_layout_*.h)
#define MAP_HEIGHT 15

// One world map: the art and the map sections of every region on one tilemap (data/region_map/world_map.h, made by
// tools/worldmap/worldmap.py), seen through FRLG's map window. The cursor moves in world cells; near the window's
// edges the camera moves instead. BG0 is redrawn from the ROM tilemap when the camera crosses a cell.
#define VIEW_X 24        // the viewport (FRLG's map window), screen pixels
#define VIEW_Y 16
#define VIEW_W 24        // ... cells
#define VIEW_H 18
#define MARGIN_LEFT 2    // the camera moves instead of the cursor when the cursor would enter these viewport cells
#define MARGIN_RIGHT 2
#define MARGIN_TOP 4     // the name boxes
#define MARGIN_BOTTOM 2
#define CANCEL_BUTTON_X 22  // viewport cell of the cancel button: fixed, on BG3
#define CANCEL_BUTTON_Y 15
#define CANCEL_BUTTON_TILE 0x168  // its 9 tiles in BG3's charblock, after the windows'
#define SEA_TILE 0x003
#define MAX_HIDDEN_RECTS 8

#define TAG_FLY_ICON 10
#define TAG_DUNGEON_ICON 11
#define TAG_MAP_ICON_PAL 10
#define TAG_ARROWS_X 12
#define TAG_ARROWS_Y 13
#define TAG_ARROWS_PAL 12

enum {
    REGIONMAP_KANTO,
    REGIONMAP_SEVII123,
    REGIONMAP_SEVII45,
    REGIONMAP_SEVII67,
    REGIONMAP_HOENN,
    REGIONMAP_JOHTO, // art only, for now
    REGIONMAP_COUNT
};

enum {
    ICON_FLY,
    ICON_DUNGEON,
    ICON_DUNGEON_VISITED,
};

enum {
    MAPSECTYPE_NONE,
    MAPSECTYPE_ROUTE,
    MAPSECTYPE_VISITED,
    MAPSECTYPE_NOT_VISITED,
    MAPSECTYPE_UNKNOWN, // Checked but never used
};

enum {
    LAYER_MAP,
    LAYER_DUNGEON,
    LAYER_COUNT
};

enum {
    WIN_MAP_NAME,
    WIN_DUNGEON_NAME,
    WIN_MAP_PREVIEW,
    WIN_TOPBAR_LEFT,
    WIN_TOPBAR_RIGHT,
};

#define CLEAR_NAME 2

enum {
    MAP_INPUT_NONE,
    MAP_INPUT_MOVE_START,
    MAP_INPUT_MOVE_CONT,
    MAP_INPUT_MOVE_END,
    MAP_INPUT_A_BUTTON,
    MAP_INPUT_CANCEL
};

enum {
    MAPPERM_HAS_MAP_PREVIEW,
    MAPPERM_HAS_OPEN_ANIM,
    MAPPERM_HAS_FLY_DESTINATIONS,
    MAPPERM_COUNT
};

enum {
    MAPEDGE_TOP_LEFT,
    MAPEDGE_MID_LEFT,
    MAPEDGE_BOT_LEFT,
    MAPEDGE_TOP_RIGHT,
    MAPEDGE_MID_RIGHT,
    MAPEDGE_BOT_RIGHT,
};

#define FREE_IF_NOT_NULL(ptr) ({ \
    if (ptr) {                   \
        FREE_AND_SET_NULL(ptr);  \
    }                            \
})

struct RegionMap
{
    u8 mapName[19];
    u8 dungeonName[19];
    u16 bgTilemap[600]; // BG1 of the Fly and wall maps
    // Inefficiency: these should be u8 or have half the elements each
    u16 bgTilemapBuffers[3][BG_SCREEN_SIZE];
    u8 type; // REGIONMAP_TYPE_*
    bool8 permissions[MAPPERM_COUNT];
    u8 playersRegion;
    u8 ALIGNED(4) mainState;
    u8 ALIGNED(4) openState;
    u8 ALIGNED(4) loadGfxState;
    u16 dungeonWinLeft;   // Used by a field that's never read
    u16 dungeonWinTop;    // Never read
    u16 dungeonWinRight;  // Never read
    u16 dungeonWinBottom; // Never read
    u8 filler[6];
    TaskFunc mainTask;
    MainCallback savedCallback;
    // the world map
    u16 camX;             // camera, in cells (the edge arrows read these two)
    u16 camY;
    s16 camPx;            // camera, in pixels: 2 per frame while panning
    s16 camPy;
    s8 camMove[2];        // pixels per frame of the camera during the current cursor move
    u8 homeCam[2];        // camera at the opening (START goes back to it with the player icon)
    u8 camMin[2];         // camera range: the art of the shown regions
    u8 camMax[2];
    u8 cursorMin[2];      // cursor range: their map sections
    u8 cursorMax[2];
    u8 hidden[MAX_HIDDEN_RECTS][4]; // drawn as sea, no map section, no icon
    u8 numHidden;
    bool8 playerHidden;   // the player's map section is on no region's grid
    u8 arrowTaskIds[2];
};

struct GpuWindowParams
{
    u16 left;
    u16 top;
    u16 right;
    u16 bottom;
};

struct WorldRegion
{
    u8 art[4];             // x, y, width, height, in world cells
    u8 grid[4];            // where its map sections are
    u8 home[2];            // camera when the map opens there
    u16 flag;              // shows it (0: always)
    const u8 *sections;    // [LAYER_COUNT][grid height][grid width], or NULL
};

struct WorldMask
{
    u8 rect[4];
    u16 flag;              // shows it
};

struct WorldIcon
{
    u8 x;                  // world cell
    u8 y;
    s8 dx;                 // pixels from the cell's center
    s8 dy;
    u8 kind;               // ICON_*
};

#include "data/region_map/region_map_layout_kanto.h"
#include "data/region_map/world_map.h"

struct DungeonMapInfo
{
    u16 id;
    const u8 *name;
    const u8 *desc;
};

struct DungeonMapPreview
{
    u16 tiles[7200];
    u16 tilemap[640];
    const struct MapPreviewScreen * mapPreviewInfo;
    TaskFunc savedTask;
    u8 mainState;
    u8 drawState;
    u8 loadState;
    u8 updateCounter;
    u8 timer;
    u16 palette[0x30];
    u8 filler[0x60];
    u16 red;
    u16 green;
    u16 blue;
    u16 blendY;
    u16 left;
    u16 top;
    u16 right;
    u16 bottom;
    u16 leftIncrement;
    u16 topIncrement;
    u16 rightIncrement;
    u16 bottomIncrement;
}; // size = 0x3E28

struct MapEdge
{
    u16 tiles[0x200];
    struct Sprite *sprite;
    s16 x;
    s16 y;
    u16 tileTag;
    u16 palTag;
};

struct MapOpenCloseAnim
{
    struct MapEdge * mapEdges[6];
    u16 tiles[0x400];
    u16 tilemap[600];
    TaskFunc exitTask;
    u8 openState;
    u8 loadGfxState;
    u8 moveState;
    u8 closeState;
    u8 blendY;
}; // size = 0xCD4

struct MapCursor
{
    s16 x;
    s16 y;
    u16 spriteX;
    u16 spriteY;
    s16 horizontalMove;
    s16 verticalMove;
    u16 moveCounter;
    u8 snapId;
    u8 (*inputHandler)(void);
    u16 selectedMapsec;
    u16 selectedMapsecType;
    u16 selectedDungeonType;
    struct Sprite *sprite;
    u16 tileTag;
    u16 palTag;
    u16 tiles[0x80];
}; // size = 0x124

struct PlayerIcon
{
    s16 x;
    s16 y;
    struct Sprite *sprite;
    u16 tileTag;
    u16 palTag;
    bool8 hidden;
    u16 tiles[0x40];
};

// The icons of the shown regions; pools of sprites show those around the camera (OAM coordinates wrap)
struct MapIcons
{
    u8 dungeonIconTiles[0x40];
    u8 flyIconTiles[0x100];
    struct WorldIcon icons[MAX_WORLD_ICONS];
    struct Sprite *flySprites[NUM_FLY_ICON_SPRITES];
    struct Sprite *dungeonSprites[NUM_DUNGEON_ICON_SPRITES];
    u8 numIcons;
    bool8 hidden;
    u8 state;
    TaskFunc exitTask;
};

struct RegionMapGpuRegs
{
    u16 bldcnt;
    u16 bldy;
    u16 bldalpha;
    u16 winin;
    u16 winout;
    u16 win0h;
    u16 win1h;
    u16 win0v;
    u16 win1v;
};

struct FlyMap
{
    u8 state;
    u8 unused; // Never read
    bool8 selectedDestination;
};

static EWRAM_DATA struct RegionMap * sRegionMap = NULL;
static EWRAM_DATA struct DungeonMapPreview * sDungeonMapPreview = NULL;
static EWRAM_DATA struct MapOpenCloseAnim * sMapOpenCloseAnim = NULL;
static EWRAM_DATA struct MapCursor * sMapCursor = NULL;
static EWRAM_DATA struct PlayerIcon * sPlayerIcon = NULL;
static EWRAM_DATA struct MapIcons * sMapIcons = NULL;
static EWRAM_DATA struct RegionMapGpuRegs * sRegionMapGpuRegs[3] = {};
static EWRAM_DATA struct FlyMap * sFlyMap = NULL;

static void InitRegionMapType(void);
static void CB2_OpenRegionMap(void);
static bool8 LoadRegionMapGfx(void);
static void CreateMainMapTask(void);
static void Task_RegionMap(u8);
static void SaveMainMapTask(u8);
static void FreeRegionMap(u8);
static void CB2_RegionMap(void);
static void NullVBlankHBlankCallbacks(void);
static void SetRegionMapVBlankCB(void);
static void InitRegionMapBgs(void);
static void SetBgTilemapBuffers(void);
static void ResetOamForRegionMap(void);
static void SetBg0andBg3Hidden(bool8);
static void UpdateMapsecNameBox(void);
static void DisplayCurrentMapName(void);
static void DrawDungeonNameBox(void);
static void DisplayCurrentDungeonName(void);
static void UpdateNameBoxWindow(void);
static void DrawCancelButton(void);
static bool8 GetRegionMapPermission(u8);
static void InitWorldBounds(void);
static bool8 IsWorldCellHidden(s16, s16);
static void SetCamera(s16, s16);
static void DrawWorldView(void);
static void UpdateWorldSprites(void);
static void CreateEdgeArrows(void);
static void RemoveEdgeArrows(void);
static bool8 CanShowDungeonPreview(void);
static void InitDungeonMapPreview(u8, u8, TaskFunc);
static void Task_DungeonMapPreview(u8);
static void Task_DrawDungeonMapPreviewFlavorText(u8);
static void FreeDungeonMapPreview(u8);
static void InitScreenForDungeonMapPreview(void);
static void CopyMapPreviewTilemapToBgTilemapBuffer(u8, const u16 *);
static bool8 UpdateDungeonMapPreview(bool8);
static void InitMapOpenAnim(u8, TaskFunc);
static void InitScreenForMapOpenAnim(void);
static void Task_MapOpenAnim(u8);
static void FreeMapOpenCloseAnim(void);
static void FreeMapEdgeSprites(void);
static bool8 MoveMapEdgesOutward(void);
static void SetGpuWindowDimsToMapEdges(void);
static void DoMapCloseAnim(u8);
static void Task_MapCloseAnim(u8);
static bool8 MoveMapEdgesInward(void);
static void CreateMapCursor(u16, u16);
static void CreateMapCursorSprite(void);
static void SetMapCursorInvisibility(bool8);
static void ResetCursorSnap(void);
static void FreeMapCursor(void);
static u8 HandleRegionMapInput(void);
static u8 MoveMapCursor(void);
static u8 GetRegionMapInput(void);
static void SnapToIconOrButton(void);
static u16 GetMapCursorX(void);
static u16 GetMapCursorY(void);
static u16 GetMapsecUnderCursor(void);
static u16 GetDungeonMapsecUnderCursor(void);
static u8 GetMapsecType(u8);
static u8 GetDungeonMapsecType(u8);
static u8 GetSelectedMapsecType(u8);
static void UpdateSelectedMapsec(void);
static bool8 IsCursorOnCancel(void);
static s16 CellScreenX(s16);
static s16 CellScreenY(s16);
static void GetPlayerPositionOnRegionMap_HandleOverrides(void);
static u8 GetSelectedMapSection(u8, s16, s16);
static void CreatePlayerIcon(u16, u16);
static void CreatePlayerIconSprite(void);
static void SetPlayerIconInvisibility(bool8);
static void FreePlayerIcon(void);
static u16 GetPlayerIconX(void);
static u16 GetPlayerIconY(void);
static void InitMapIcons(u8, TaskFunc);
static void LoadMapIcons(u8);
static void FinishMapIconLoad(u8);
static void BuildWorldIcons(void);
static void CreateIconSprites(void);
static void SetMapIconsInvisibility(bool8);
static void FreeMapIcons(void);
static bool8 SaveRegionMapGpuRegs(u8);
static bool8 SetRegionMapGpuRegs(u8);
static void ResetGpuRegs(void);
static void SetBldCnt(u8, u16, u16);
static void SetBldY(u16);
static void SetBldAlpha(u16, u16);
static void SetWinIn(u16, u16);
static void SetWinOut(u16);
static void SetDispCnt(u8, bool8);
static void SetGpuWindowDims(u8, const struct GpuWindowParams *);
static void FreeAndResetGpuRegs(void);
static void PrintTopBarTextLeft(const u8 *);
static void PrintTopBarTextRight(const u8 *);
static void ClearOrDrawTopBar(bool8);
static void Task_FlyMap(u8);
static void InitFlyMap(void);
static void FreeFlyMap(u8);
static void SetFlyWarpDestination(u16);

#include "data/region_map/region_map_entry_strings.h"

static const u16 sTopBar_Pal[] = INCBIN_U16("graphics/region_map/top_bar.gbapal"); // Palette for the top bar and dynamic text color
static const u16 sMapCursor_Pal[] = INCBIN_U16("graphics/region_map/cursor.gbapal");
static const u16 sPlayerIcon_RedPal[] = INCBIN_U16("graphics/region_map/player_icon_red.gbapal");
static const u16 sPlayerIcon_LeafPal[] = INCBIN_U16("graphics/region_map/player_icon_leaf.gbapal");
static const u16 sMiscIcon_Pal[] = INCBIN_U16("graphics/region_map/misc_icon.gbapal"); // For dungeon and fly icons
static const u16 sRegionMap_Pal[] = INCBIN_U16("graphics/region_map/region_map.gbapal");
static const u16 sUnusedPalette[] = { RGB(0, 0, 31), RGB(0, 12, 31), RGB_WHITE, RGB_WHITE };
static const u16 sMapEdge_Pal[] = INCBIN_U16("graphics/region_map/map_edge.gbapal");
static const u32 sMapCursor_Gfx[] = INCBIN_U32("graphics/region_map/cursor.4bpp.lz");
static const u32 sPlayerIcon_Red[] = INCBIN_U32("graphics/region_map/player_icon_red.4bpp.lz");
static const u32 sPlayerIcon_Leaf[] = INCBIN_U32("graphics/region_map/player_icon_leaf.4bpp.lz");
static const u32 sRegionMap_Gfx[] = INCBIN_U32("graphics/region_map/region_map.4bpp.lz");
static const u32 sMapEdge_Gfx[] = INCBIN_U32("graphics/region_map/map_edge.4bpp.lz");
static const u32 sMapEdge_Tilemap[] = INCBIN_U32("graphics/region_map/map_edge.bin.lz");
static const u32 sMapEdge_TopLeft[] = INCBIN_U32("graphics/region_map/map_edge_top_left.4bpp.lz");
static const u32 sMapEdge_TopRight[] = INCBIN_U32("graphics/region_map/map_edge_top_right.4bpp.lz");
static const u32 sMapEdge_MidLeft[] = INCBIN_U32("graphics/region_map/map_edge_mid_left.4bpp.lz");
static const u32 sMapEdge_MidRight[] = INCBIN_U32("graphics/region_map/map_edge_mid_right.4bpp.lz");
static const u32 sMapEdge_BottomLeft[] = INCBIN_U32("graphics/region_map/map_edge_bottom_left.4bpp.lz");
static const u32 sMapEdge_BottomRight[] = INCBIN_U32("graphics/region_map/map_edge_bottom_right.4bpp.lz");
static const u32 sDungeonIcon[] = INCBIN_U32("graphics/region_map/dungeon_icon.4bpp.lz");
static const u32 sFlyIcon[] = INCBIN_U32("graphics/region_map/fly_icon.4bpp.lz");
static const u32 sBackground_Gfx[] = INCBIN_U32("graphics/region_map/background.4bpp.lz");
static const u32 sBackground_Tilemap[] = INCBIN_U32("graphics/region_map/background.bin.lz");
static const u16 sWorldTilemap[] = INCBIN_U16("graphics/region_map/world.bin");
static const u32 sWorldTiles[] = INCBIN_U32("graphics/region_map/world_tiles.4bpp");
static const u16 sWorld_Pal[] = INCBIN_U16("graphics/region_map/world.gbapal");
static const u32 sWhiteTile[8] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};

static const struct BgTemplate sRegionMapBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }
};

static const struct WindowTemplate sRegionMapWindowTemplates[] = {
    [WIN_MAP_NAME] = 
    {
        .bg = 3,
        .tilemapLeft = 3,
        .tilemapTop = 2,
        .width = 15,
        .height = 2,
        .paletteNum = 12,
        .baseBlock = 0x001
    }, 
    [WIN_DUNGEON_NAME] =
    {
        .bg = 3,
        .tilemapLeft = 3,
        .tilemapTop = 4,
        .width = 15,
        .height = 2,
        .paletteNum = 12,
        .baseBlock = 0x01f
    }, 
    [WIN_MAP_PREVIEW] =
    {
        .bg = 3,
        .tilemapLeft = 3,
        .tilemapTop = 6,
        .width = 25,
        .height = 11,
        .paletteNum = 12,
        .baseBlock = 0x03d
    },
    [WIN_TOPBAR_LEFT] = // 6 tiles wide as in the French FireRed: its texts are longer than the English ones
    {
        .bg = 3,
        .tilemapLeft = 18,
        .tilemapTop = 0,
        .width = 6,
        .height = 2,
        .paletteNum = 12,
        .baseBlock = 0x150
    }, 
    [WIN_TOPBAR_RIGHT] =
    {
        .bg = 3,
        .tilemapLeft = 24,
        .tilemapTop = 0,
        .width = 6,
        .height = 2,
        .paletteNum = 12,
        .baseBlock = 0x15c
    }, DUMMY_WIN_TEMPLATE
};

ALIGNED(4) const u8 sTextColor_White[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,       TEXT_COLOR_DARK_GRAY};
ALIGNED(4) const u8 sTextColor_Green[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GREEN, TEXT_COLOR_DARK_GRAY};
ALIGNED(4) const u8 sTextColor_Red[]   = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_1,   TEXT_COLOR_DARK_GRAY};

static const u8 sSeviiMapsecs[3][30] = {
    [REGIONMAP_SEVII123 - 1] =
    {
        MAPSEC_ONE_ISLAND,
        MAPSEC_TWO_ISLAND,
        MAPSEC_THREE_ISLAND,
        MAPSEC_KINDLE_ROAD,
        MAPSEC_TREASURE_BEACH,
        MAPSEC_CAPE_BRINK,
        MAPSEC_BOND_BRIDGE,
        MAPSEC_THREE_ISLE_PORT,
        MAPSEC_MT_EMBER,
        MAPSEC_BERRY_FOREST,
        MAPSEC_THREE_ISLE_PATH,
        MAPSEC_EMBER_SPA,
        MAPSEC_NONE
    }, 
    [REGIONMAP_SEVII45 - 1] =
    {
        MAPSEC_FOUR_ISLAND,
        MAPSEC_FIVE_ISLAND,
        MAPSEC_SEVII_ISLE_6,
        MAPSEC_SEVII_ISLE_7,
        MAPSEC_SEVII_ISLE_8,
        MAPSEC_SEVII_ISLE_9,
        MAPSEC_RESORT_GORGEOUS,
        MAPSEC_WATER_LABYRINTH,
        MAPSEC_FIVE_ISLE_MEADOW,
        MAPSEC_MEMORIAL_PILLAR,
        MAPSEC_NAVEL_ROCK,
        MAPSEC_ICEFALL_CAVE,
        MAPSEC_ROCKET_WAREHOUSE,
        MAPSEC_LOST_CAVE,
        MAPSEC_NONE
    }, 
    [REGIONMAP_SEVII67 - 1] = 
    {
        MAPSEC_SEVEN_ISLAND,
        MAPSEC_SIX_ISLAND,
        MAPSEC_OUTCAST_ISLAND,
        MAPSEC_GREEN_PATH,
        MAPSEC_WATER_PATH,
        MAPSEC_RUIN_VALLEY,
        MAPSEC_TRAINER_TOWER,
        MAPSEC_CANYON_ENTRANCE,
        MAPSEC_SEVAULT_CANYON,
        MAPSEC_TANOBY_RUINS,
        MAPSEC_SEVII_ISLE_22,
        MAPSEC_SEVII_ISLE_23,
        MAPSEC_SEVII_ISLE_24,
        MAPSEC_TRAINER_TOWER_2,
        MAPSEC_DOTTED_HOLE,
        MAPSEC_PATTERN_BUSH,
        MAPSEC_ALTERING_CAVE,
        MAPSEC_TANOBY_CHAMBERS,
        MAPSEC_TANOBY_KEY,
        MAPSEC_BIRTH_ISLAND,
        MAPSEC_MONEAN_CHAMBER,
        MAPSEC_LIPTOO_CHAMBER,
        MAPSEC_WEEPTH_CHAMBER,
        MAPSEC_DILFORD_CHAMBER,
        MAPSEC_SCUFIB_CHAMBER,
        MAPSEC_RIXY_CHAMBER,
        MAPSEC_VIAPOIS_CHAMBER,
        MAPSEC_NONE
    }
};

ALIGNED(4) static const bool8 sRegionMapPermissions[REGIONMAP_TYPE_COUNT][MAPPERM_COUNT] = {
    [REGIONMAP_TYPE_NORMAL] = 
    {
        [MAPPERM_HAS_MAP_PREVIEW]      = TRUE, 
        [MAPPERM_HAS_OPEN_ANIM]        = TRUE, 
        [MAPPERM_HAS_FLY_DESTINATIONS] = FALSE
    },
    [REGIONMAP_TYPE_WALL] = 
    {
        [MAPPERM_HAS_MAP_PREVIEW]      = FALSE, 
        [MAPPERM_HAS_OPEN_ANIM]        = FALSE, 
        [MAPPERM_HAS_FLY_DESTINATIONS] = FALSE
    },
    [REGIONMAP_TYPE_FLY] = 
    {
        [MAPPERM_HAS_MAP_PREVIEW]      = FALSE, 
        [MAPPERM_HAS_OPEN_ANIM]        = FALSE, 
        [MAPPERM_HAS_FLY_DESTINATIONS] = TRUE 
    },
};

static const struct GpuWindowParams sMapsecNameWindowDims[3] = {
    [WIN_MAP_NAME]     = {.left = 24, .top = 16, .right = 144, .bottom = 32},
    [WIN_DUNGEON_NAME] = {.left = 24, .top = 32, .right = 144, .bottom = 48},
    [CLEAR_NAME]       = {.left =  0, .top =  0, .right =   0, .bottom =  0}
};

static const u8 sMapsecName_VIRIDIANFOREST[] = _("FORET DE JADE");
static const u8 sMapsecName_MTMOON[] = _("MONT SELENITE");
static const u8 sMapsecName_DIGLETTSCAVE[] = _("CAVE TAUPIQUEUR");
static const u8 sMapsecName_VICTORYROAD[] = _("ROUTE VICTOIRE");
static const u8 sMapsecName_POKMONMANSION[] = _("MANOIR POKéMON");
static const u8 sMapsecName_SAFARIZONE[] = _("PARC SAFARI");
static const u8 sMapsecName_ROCKTUNNEL[] = _("GROTTE");
static const u8 sMapsecName_SEAFOAMISLANDS[] = _("ILES ECUMES");
static const u8 sMapsecName_POKMONTOWER[] = _("TOUR POKéMON");
static const u8 sMapsecName_CERULEANCAVE[] = _("GROTTE AZUREE");
static const u8 sMapsecName_POWERPLANT[] = _("CENTRALE");
static const u8 sMapsecName_MTEMBER[] = _("MONT BRAISE");
static const u8 sMapsecName_BERRYFOREST[] = _("BOIS BAIES");
static const u8 sMapsecName_ICEFALLCAVE[] = _("GROTTE DE GLACE");
static const u8 sMapsecName_LOSTCAVE[] = _("GROTTE PERDUE");
static const u8 sMapsecName_TANOBYCHAMBERS[] = _("CHAMBRES TANOBY");
static const u8 sMapsecName_ALTERINGCAVE[] = _("GROTTE METAMO");
static const u8 sMapsecName_PATTERNBUSH[] = _("FORBUISSONS");
static const u8 sMapsecName_DOTTEDHOLE[] = _("TROU PERCE");

static const struct DungeonMapInfo sDungeonInfo[] = {
    {
        .id = MAPSEC_VIRIDIAN_FOREST,
        .name = sMapsecName_VIRIDIANFOREST,
        .desc = gText_RegionMap_AreaDesc_ViridianForest
    }, {
        .id = MAPSEC_MT_MOON,
        .name = sMapsecName_MTMOON,
        .desc = gText_RegionMap_AreaDesc_MtMoon
    }, {
        .id = MAPSEC_DIGLETTS_CAVE,
        .name = sMapsecName_DIGLETTSCAVE,
        .desc = gText_RegionMap_AreaDesc_DiglettsCave
    }, {
        .id = MAPSEC_KANTO_VICTORY_ROAD,
        .name = sMapsecName_VICTORYROAD,
        .desc = gText_RegionMap_AreaDesc_VictoryRoad
    }, {
        .id = MAPSEC_POKEMON_MANSION,
        .name = sMapsecName_POKMONMANSION,
        .desc = gText_RegionMap_AreaDesc_PokemonMansion
    }, {
        .id = MAPSEC_KANTO_SAFARI_ZONE,
        .name = sMapsecName_SAFARIZONE,
        .desc = gText_RegionMap_AreaDesc_SafariZone
    }, {
        .id = MAPSEC_ROCK_TUNNEL,
        .name = sMapsecName_ROCKTUNNEL,
        .desc = gText_RegionMap_AreaDesc_RockTunnel
    }, {
        .id = MAPSEC_SEAFOAM_ISLANDS,
        .name = sMapsecName_SEAFOAMISLANDS,
        .desc = gText_RegionMap_AreaDesc_SeafoamIslands
    }, {
        .id = MAPSEC_POKEMON_TOWER,
        .name = sMapsecName_POKMONTOWER,
        .desc = gText_RegionMap_AreaDesc_PokemonTower
    }, {
        .id = MAPSEC_CERULEAN_CAVE,
        .name = sMapsecName_CERULEANCAVE,
        .desc = gText_RegionMap_AreaDesc_CeruleanCave
    }, {
        .id = MAPSEC_POWER_PLANT,
        .name = sMapsecName_POWERPLANT,
        .desc = gText_RegionMap_AreaDesc_PowerPlant
    }, {
        .id = MAPSEC_MT_EMBER,
        .name = sMapsecName_MTEMBER,
        .desc = gText_RegionMap_AreaDesc_MtEmber
    }, {
        .id = MAPSEC_BERRY_FOREST,
        .name = sMapsecName_BERRYFOREST,
        .desc = gText_RegionMap_AreaDesc_BerryForest
    }, {
        .id = MAPSEC_ICEFALL_CAVE,
        .name = sMapsecName_ICEFALLCAVE,
        .desc = gText_RegionMap_AreaDesc_IcefallCave
    }, {
        .id = MAPSEC_LOST_CAVE,
        .name = sMapsecName_LOSTCAVE,
        .desc = gText_RegionMap_AreaDesc_LostCave
    }, {
        .id = MAPSEC_TANOBY_CHAMBERS,
        .name = sMapsecName_TANOBYCHAMBERS,
        .desc = gText_RegionMap_AreaDesc_TanobyRuins
    }, {
        .id = MAPSEC_ALTERING_CAVE,
        .name = sMapsecName_ALTERINGCAVE,
        .desc = gText_RegionMap_AreaDesc_AlteringCave
    }, {
        .id = MAPSEC_PATTERN_BUSH,
        .name = sMapsecName_PATTERNBUSH,
        .desc = gText_RegionMap_AreaDesc_PatternBush
    }, {
        .id = MAPSEC_DOTTED_HOLE,
        .name = sMapsecName_DOTTEDHOLE,
        .desc = gText_RegionMap_AreaDesc_DottedHole
    }
};

static const struct OamData sOamData_MapEdge = {
    .shape = SPRITE_SHAPE(32x64),
    .size = SPRITE_SIZE(32x64)
};

static const union AnimCmd sAnim_MapEdge[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_MapEdge[] = {
    sAnim_MapEdge
};

static const u8 sViewMargins[2][2] = {{MARGIN_LEFT, MARGIN_RIGHT}, {MARGIN_TOP, MARGIN_BOTTOM}};

static const struct GpuWindowParams sMapWindowDim = {
    .left = 24, 
    .top = 16, 
    .right = 216, 
    .bottom = 160
};

static const struct OamData sOamData_MapCursor = {
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2
};

static const union AnimCmd sAnim_MapCursor[] = {
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_MapCursor[] = {
    sAnim_MapCursor
};

static const struct OamData sOamData_PlayerIcon = {
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2
};

static const union AnimCmd sAnim_PlayerIcon[] = {
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_PlayerIcon[] = {
    sAnim_PlayerIcon
};

static const struct OamData sOamData_FlyIcon = {
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2
};

static const struct OamData sOamData_DungeonIcon = {
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .priority = 2
};

static const union AnimCmd sAnim_FlyIcon[] = {
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(4, 60),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_DungeonIconVisited[] = {
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_DungeonIconNotVisited[] = {
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_FlyIcon[] = {
    sAnim_FlyIcon
};

static const union AnimCmd *const sAnims_DungeonIcon[] = {
    sAnim_DungeonIconVisited,
    sAnim_DungeonIconNotVisited
};

static const struct SpriteTemplate sFlyIconSpriteTemplate = {
    .tileTag = TAG_FLY_ICON,
    .paletteTag = TAG_MAP_ICON_PAL,
    .oam = &sOamData_FlyIcon,
    .anims = sAnims_FlyIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sDungeonIconSpriteTemplate = {
    .tileTag = TAG_DUNGEON_ICON,
    .paletteTag = TAG_MAP_ICON_PAL,
    .oam = &sOamData_DungeonIcon,
    .anims = sAnims_DungeonIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const u16 sWinFlags[] = {
    DISPCNT_WIN0_ON,
    DISPCNT_WIN1_ON
};

static const u8 sWinRegs[][2] = {
    {REG_OFFSET_WIN0V, REG_OFFSET_WIN0H},
    {REG_OFFSET_WIN1V, REG_OFFSET_WIN1H}
};

static const u8 sTextColors[] = {TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

#include "data/region_map/region_map_entries.h"

static const u8 sMapFlyDestinations[][3] = {
    [MAPSEC_LITTLEROOT_TOWN     ] = {MAP(LITTLEROOT_TOWN),                       SPAWN_LITTLEROOT_TOWN_BRENDANS_HOUSE},
    [MAPSEC_OLDALE_TOWN         ] = {MAP(OLDALE_TOWN),                           SPAWN_OLDALE_TOWN},
    [MAPSEC_DEWFORD_TOWN        ] = {MAP(DEWFORD_TOWN),                          SPAWN_DEWFORD_TOWN},
    [MAPSEC_LAVARIDGE_TOWN      ] = {MAP(LAVARIDGE_TOWN),                        SPAWN_LAVARIDGE_TOWN},
    [MAPSEC_FALLARBOR_TOWN      ] = {MAP(FALLARBOR_TOWN),                        SPAWN_FALLARBOR_TOWN},
    [MAPSEC_VERDANTURF_TOWN     ] = {MAP(VERDANTURF_TOWN),                       SPAWN_VERDANTURF_TOWN},
    [MAPSEC_PACIFIDLOG_TOWN     ] = {MAP(PACIFIDLOG_TOWN),                       SPAWN_PACIFIDLOG_TOWN},
    [MAPSEC_PETALBURG_CITY      ] = {MAP(PETALBURG_CITY),                        SPAWN_PETALBURG_CITY},
    [MAPSEC_SLATEPORT_CITY      ] = {MAP(SLATEPORT_CITY),                        SPAWN_SLATEPORT_CITY},
    [MAPSEC_MAUVILLE_CITY       ] = {MAP(MAUVILLE_CITY),                         SPAWN_MAUVILLE_CITY},
    [MAPSEC_RUSTBORO_CITY       ] = {MAP(RUSTBORO_CITY),                         SPAWN_RUSTBORO_CITY},
    [MAPSEC_FORTREE_CITY        ] = {MAP(FORTREE_CITY),                          SPAWN_FORTREE_CITY},
    [MAPSEC_LILYCOVE_CITY       ] = {MAP(LILYCOVE_CITY),                         SPAWN_LILYCOVE_CITY},
    [MAPSEC_MOSSDEEP_CITY       ] = {MAP(MOSSDEEP_CITY),                         SPAWN_MOSSDEEP_CITY},
    [MAPSEC_SOOTOPOLIS_CITY     ] = {MAP(SOOTOPOLIS_CITY),                       SPAWN_SOOTOPOLIS_CITY},
    [MAPSEC_EVER_GRANDE_CITY    ] = {MAP(EVER_GRANDE_CITY),                      SPAWN_EVER_GRANDE_CITY},
    [MAPSEC_PALLET_TOWN         ] = {MAP(PALLET_TOWN),                           SPAWN_PALLET_TOWN},
    [MAPSEC_VIRIDIAN_CITY       ] = {MAP(VIRIDIAN_CITY),                         SPAWN_VIRIDIAN_CITY},
    [MAPSEC_PEWTER_CITY         ] = {MAP(PEWTER_CITY),                           SPAWN_PEWTER_CITY},
    [MAPSEC_CERULEAN_CITY       ] = {MAP(CERULEAN_CITY),                         SPAWN_CERULEAN_CITY},
    [MAPSEC_LAVENDER_TOWN       ] = {MAP(LAVENDER_TOWN),                         SPAWN_LAVENDER_TOWN},
    [MAPSEC_VERMILION_CITY      ] = {MAP(VERMILION_CITY),                        SPAWN_VERMILION_CITY},
    [MAPSEC_CELADON_CITY        ] = {MAP(CELADON_CITY),                          SPAWN_CELADON_CITY},
    [MAPSEC_FUCHSIA_CITY        ] = {MAP(FUCHSIA_CITY),                          SPAWN_FUCHSIA_CITY},
    [MAPSEC_CINNABAR_ISLAND     ] = {MAP(CINNABAR_ISLAND),                       SPAWN_CINNABAR_ISLAND},
    [MAPSEC_INDIGO_PLATEAU      ] = {MAP(INDIGO_PLATEAU_EXTERIOR),               SPAWN_INDIGO_PLATEAU},
    [MAPSEC_SAFFRON_CITY        ] = {MAP(SAFFRON_CITY),                          SPAWN_SAFFRON_CITY},
    [MAPSEC_ROUTE_4_POKECENTER  ] = {MAP(ROUTE4),                                SPAWN_ROUTE4},
    [MAPSEC_ROUTE_10_POKECENTER ] = {MAP(ROUTE10),                               SPAWN_ROUTE10},
    [MAPSEC_ROUTE_1             ] = {MAP(ROUTE1),                                0},
    [MAPSEC_ROUTE_2             ] = {MAP(ROUTE2),                                0},
    [MAPSEC_ROUTE_3             ] = {MAP(ROUTE3),                                0},
    [MAPSEC_ROUTE_4             ] = {MAP(ROUTE4),                                0},
    [MAPSEC_ROUTE_5             ] = {MAP(ROUTE5),                                0},
    [MAPSEC_ROUTE_6             ] = {MAP(ROUTE6),                                0},
    [MAPSEC_ROUTE_7             ] = {MAP(ROUTE7),                                0},
    [MAPSEC_ROUTE_8             ] = {MAP(ROUTE8),                                0},
    [MAPSEC_ROUTE_9             ] = {MAP(ROUTE9),                                0},
    [MAPSEC_ROUTE_10            ] = {MAP(ROUTE10),                               0},
    [MAPSEC_ROUTE_11            ] = {MAP(ROUTE11),                               0},
    [MAPSEC_ROUTE_12            ] = {MAP(ROUTE12),                               0},
    [MAPSEC_ROUTE_13            ] = {MAP(ROUTE13),                               0},
    [MAPSEC_ROUTE_14            ] = {MAP(ROUTE14),                               0},
    [MAPSEC_ROUTE_15            ] = {MAP(ROUTE15),                               0},
    [MAPSEC_ROUTE_16            ] = {MAP(ROUTE16),                               0},
    [MAPSEC_ROUTE_17            ] = {MAP(ROUTE17),                               0},
    [MAPSEC_ROUTE_18            ] = {MAP(ROUTE18),                               0},
    [MAPSEC_ROUTE_19            ] = {MAP(ROUTE19),                               0},
    [MAPSEC_ROUTE_20            ] = {MAP(ROUTE20),                               0},
    [MAPSEC_ROUTE_21            ] = {MAP(ROUTE21_NORTH),                         0},
    [MAPSEC_ROUTE_22            ] = {MAP(ROUTE22),                               0},
    [MAPSEC_ROUTE_23            ] = {MAP(ROUTE23),                               0},
    [MAPSEC_ROUTE_24            ] = {MAP(ROUTE24),                               0},
    [MAPSEC_ROUTE_25            ] = {MAP(ROUTE25),                               0},
    [MAPSEC_VIRIDIAN_FOREST     ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_MT_MOON             ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_S_S_ANNE            ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_UNDERGROUND_PATH    ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_UNDERGROUND_PATH_2  ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_DIGLETTS_CAVE       ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_KANTO_VICTORY_ROAD  ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_ROCKET_HIDEOUT      ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_SILPH_CO            ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_POKEMON_MANSION     ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_KANTO_SAFARI_ZONE   ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_POKEMON_LEAGUE      ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_ROCK_TUNNEL         ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_SEAFOAM_ISLANDS     ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_POKEMON_TOWER       ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_CERULEAN_CAVE       ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_POWER_PLANT         ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_ONE_ISLAND          ] = {MAP(ONE_ISLAND),                            SPAWN_ONE_ISLAND},
    [MAPSEC_TWO_ISLAND          ] = {MAP(TWO_ISLAND),                            SPAWN_TWO_ISLAND},
    [MAPSEC_THREE_ISLAND        ] = {MAP(THREE_ISLAND),                          SPAWN_THREE_ISLAND},
    [MAPSEC_FOUR_ISLAND         ] = {MAP(FOUR_ISLAND),                           SPAWN_FOUR_ISLAND},
    [MAPSEC_FIVE_ISLAND         ] = {MAP(FIVE_ISLAND),                           SPAWN_FIVE_ISLAND},
    [MAPSEC_SEVEN_ISLAND        ] = {MAP(SEVEN_ISLAND),                          SPAWN_SEVEN_ISLAND},
    [MAPSEC_SIX_ISLAND          ] = {MAP(SIX_ISLAND),                            SPAWN_SIX_ISLAND},
    [MAPSEC_KINDLE_ROAD         ] = {MAP(ONE_ISLAND_KINDLE_ROAD),                0},
    [MAPSEC_TREASURE_BEACH      ] = {MAP(ONE_ISLAND_TREASURE_BEACH),             0},
    [MAPSEC_CAPE_BRINK          ] = {MAP(TWO_ISLAND_CAPE_BRINK),                 0},
    [MAPSEC_BOND_BRIDGE         ] = {MAP(THREE_ISLAND_BOND_BRIDGE),              0},
    [MAPSEC_THREE_ISLE_PORT     ] = {MAP(THREE_ISLAND_PORT),                     0},
    [MAPSEC_SEVII_ISLE_6        ] = {MAP(PROTOTYPE_SEVII_ISLE_6),                0},
    [MAPSEC_SEVII_ISLE_7        ] = {MAP(PROTOTYPE_SEVII_ISLE_7),                0},
    [MAPSEC_SEVII_ISLE_8        ] = {MAP(PROTOTYPE_SEVII_ISLE_8),                0},
    [MAPSEC_SEVII_ISLE_9        ] = {MAP(PROTOTYPE_SEVII_ISLE_9),                0},
    [MAPSEC_RESORT_GORGEOUS     ] = {MAP(FIVE_ISLAND_RESORT_GORGEOUS),           0},
    [MAPSEC_WATER_LABYRINTH     ] = {MAP(FIVE_ISLAND_WATER_LABYRINTH),           0},
    [MAPSEC_FIVE_ISLE_MEADOW    ] = {MAP(FIVE_ISLAND_MEADOW),                    0},
    [MAPSEC_MEMORIAL_PILLAR     ] = {MAP(FIVE_ISLAND_MEMORIAL_PILLAR),           0},
    [MAPSEC_OUTCAST_ISLAND      ] = {MAP(SIX_ISLAND_OUTCAST_ISLAND),             0},
    [MAPSEC_GREEN_PATH          ] = {MAP(SIX_ISLAND_GREEN_PATH),                 0},
    [MAPSEC_WATER_PATH          ] = {MAP(SIX_ISLAND_WATER_PATH),                 0},
    [MAPSEC_RUIN_VALLEY         ] = {MAP(SIX_ISLAND_RUIN_VALLEY),                0},
    [MAPSEC_TRAINER_TOWER       ] = {MAP(SEVEN_ISLAND_TRAINER_TOWER),            0},
    [MAPSEC_CANYON_ENTRANCE     ] = {MAP(SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE),  0},
    [MAPSEC_SEVAULT_CANYON      ] = {MAP(SEVEN_ISLAND_SEVAULT_CANYON),           0},
    [MAPSEC_TANOBY_RUINS        ] = {MAP(SEVEN_ISLAND_TANOBY_RUINS),             0},
    [MAPSEC_SEVII_ISLE_22       ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_SEVII_ISLE_23       ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_SEVII_ISLE_24       ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_NAVEL_ROCK          ] = {MAP(NAVEL_ROCK_EXTERIOR),                   0},
    [MAPSEC_MT_EMBER            ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_BERRY_FOREST        ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_ICEFALL_CAVE        ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_ROCKET_WAREHOUSE    ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_TRAINER_TOWER_2     ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_DOTTED_HOLE         ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_LOST_CAVE           ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_PATTERN_BUSH        ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_ALTERING_CAVE       ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_TANOBY_CHAMBERS     ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_THREE_ISLE_PATH     ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_TANOBY_KEY          ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_BIRTH_ISLAND        ] = {MAP(BIRTH_ISLAND_EXTERIOR),                 0},
    [MAPSEC_MONEAN_CHAMBER      ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_LIPTOO_CHAMBER      ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_WEEPTH_CHAMBER      ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_DILFORD_CHAMBER     ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_SCUFIB_CHAMBER      ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_RIXY_CHAMBER        ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_VIAPOIS_CHAMBER     ] = {MAP(PALLET_TOWN),                           0},
    [MAPSEC_EMBER_SPA           ] = {MAP(PALLET_TOWN),                           0},
};

static void RegionMap_DarkenPalette(u16 *pal, u16 size, u16 tint)
{
    int i;
    int r, g, b;

    for (i = 0; i < size; i++)
    {
        r = (*pal) & 0x1F;
        g = ((*pal) >> 5) & 0x1F;
        b = ((*pal) >> 10) & 0x1F;

        r = (((r << 8) / 100) * tint) >> 8;
        g = (((g << 8) / 100) * tint) >> 8;
        b = (((b << 8) / 100) * tint) >> 8;

        *pal = RGB2(r, g, b);
        pal++;
    }
}

static void TintMapEdgesPalette(void)
{
    u16 mapEdgesPal[16];
    CpuCopy16(&sRegionMap_Pal[0x20], mapEdgesPal, sizeof(mapEdgesPal));
    RegionMap_DarkenPalette(mapEdgesPal, NELEMS(mapEdgesPal), 95);
    LoadPalette(mapEdgesPal, BG_PLTT_ID(2), sizeof(mapEdgesPal));
    LoadPalette(&sRegionMap_Pal[0x2F], BG_PLTT_ID(2) + 15, PLTT_SIZEOF(1));
}

static void InitRegionMap(u8 type)
{
    sRegionMap = AllocZeroed(sizeof(struct RegionMap));
    if (sRegionMap == NULL)
    {
        SetMainCallback2(CB2_ReturnToField);
    }
    else
    {
        gExitStairsMovementDisabled = TRUE;
        sRegionMap->type = type;
        sRegionMap->mainState = 0;
        sRegionMap->openState = 0;
        sRegionMap->loadGfxState = 0;
        InitRegionMapType();
        SetMainCallback2(CB2_OpenRegionMap);
    }
}

void InitRegionMapWithExitCB(u8 type, MainCallback cb)
{
    sRegionMap = AllocZeroed(sizeof(struct RegionMap));
    if (sRegionMap == NULL)
    {
        SetMainCallback2(CB2_ReturnToField);
    }
    else
    {
        gExitStairsMovementDisabled = TRUE;
        sRegionMap->type = type;
        sRegionMap->mainState = 0;
        sRegionMap->openState = 0;
        sRegionMap->loadGfxState = 0;
        sRegionMap->savedCallback = cb;
        InitRegionMapType();
        SetMainCallback2(CB2_OpenRegionMap);
    }
}

// Emerald's map sections are on Hoenn's grid, Emerald's own ones (MAPSEC_AQUA_HIDEOUT..MAPSEC_TRAINER_HILL) included,
// except those FRLG-Plus's own maps use: they keep the Kanto/Sevii regions.
static bool8 IsHoennMapsec(u16 mapsec)
{
    switch (mapsec)
    {
    case MAPSEC_UNDERWATER_124: // Three Island's Bond Bridge underwater
    case MAPSEC_BATTLE_FRONTIER:
    case MAPSEC_ARTISAN_CAVE:
    case MAPSEC_SOUTHERN_ISLAND:
    case MAPSEC_FARAWAY_ISLAND:
        return FALSE;
    }
    return mapsec <= MAPSEC_SKY_PILLAR || (mapsec >= MAPSEC_AQUA_HIDEOUT && mapsec < MAPSEC_NONE);
}

// MAPSEC_UNDERWATER_124 is Three Island's Bond Bridge underwater, and Hoenn's Route 124 underwater
static bool8 IsHoennRoute124Underwater(void)
{
    return gMapHeader.regionMapSectionId == MAPSEC_UNDERWATER_124
        && !(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(THREE_ISLAND_BOND_BRIDGE_UNDERWATER)
          && gSaveBlock1Ptr->location.mapNum == MAP_NUM(THREE_ISLAND_BOND_BRIDGE_UNDERWATER));
}

static void InitRegionMapType(void)
{
    u32 i;
    u32 j;
    u8 region;

    switch (sRegionMap->type)
    {
    default:
    case REGIONMAP_TYPE_NORMAL:
    case REGIONMAP_TYPE_WALL:
        sRegionMap->mainTask = Task_RegionMap;
        break;
    case REGIONMAP_TYPE_FLY:
        sRegionMap->mainTask = Task_FlyMap;
        break;
    }
    for (i = 0; i < MAPPERM_COUNT; i++)
    {
        sRegionMap->permissions[i] = sRegionMapPermissions[sRegionMap->type][i];
    }
    region = REGIONMAP_KANTO;
    j = REGIONMAP_KANTO;
    if (gMapHeader.regionMapSectionId >= MAPSECS_SEVII_123 && gMapHeader.regionMapSectionId != MAPSEC_FARAWAY_ISLAND)
    {
        // Mapsec is in Sevii Islands, determine which map to use. Emerald's own mapsecs (0xC5-0xD4) are in no row:
        // the search stops after the last one instead of reading past the table (crash or hang)
        while (region == REGIONMAP_KANTO && j < NELEMS(sSeviiMapsecs))
        {
            for (i = 0; sSeviiMapsecs[j][i] != MAPSEC_NONE; i++)
            {
                if (gMapHeader.regionMapSectionId == sSeviiMapsecs[j][i])
                {
                    region = j + 1;
                    break;
                }
            }
            j++;
        }
    }
    if(gMapHeader.regionMapSectionId == MAPSEC_UNDERWATER_124)
    {
        region = IsHoennRoute124Underwater() ? REGIONMAP_HOENN : REGIONMAP_SEVII123;
    }
    if (IsHoennMapsec(gMapHeader.regionMapSectionId))
    {
        region = REGIONMAP_HOENN;
    }
    if(gMapHeader.regionMapSectionId == MAPSEC_BATTLE_FRONTIER || gMapHeader.regionMapSectionId == MAPSEC_ARTISAN_CAVE || gMapHeader.regionMapSectionId == MAPSEC_SOUTHERN_ISLAND)
    {
        region = REGIONMAP_KANTO;
    }
    sRegionMap->playersRegion = region;
    sRegionMap->arrowTaskIds[0] = sRegionMap->arrowTaskIds[1] = TASK_NONE;
    InitWorldBounds();
}

// What the shown regions span: the camera's range (their art and home views: a Sevii group is lower than the viewport)
// and the cursor's (their map sections). A region shows once its flag is set, or while the player is in it; a hidden
// one is sea, as Navel Rock and Birth Island are until visited, and has no map section and no icon. On a Sevii group
// before Celio's map page, only that group shows, as in FRLG (no SWITCH then): Fly can't leave the islands before the
// story brings the player back to Kanto
static void InitWorldBounds(void)
{
    u32 i, k;
    struct RegionMap *rm = sRegionMap;
    bool32 seviiOnly = rm->playersRegion >= REGIONMAP_SEVII123 && rm->playersRegion <= REGIONMAP_SEVII67
                    && !FlagGet(FLAG_SYS_SEVII_MAP_123);

    rm->numHidden = 0;
    for (k = 0; k < 2; k++)
    {
        rm->camMin[k] = rm->cursorMin[k] = 0xFF;
        rm->camMax[k] = rm->cursorMax[k] = 0;
    }
    for (i = 0; i < REGIONMAP_COUNT; i++)
    {
        const struct WorldRegion *r = &sWorldRegions[i];

        if (i != rm->playersRegion && (seviiOnly || (r->flag != 0 && !FlagGet(r->flag))))
        {
            memcpy(rm->hidden[rm->numHidden++], r->art, 4);
            continue;
        }
        for (k = 0; k < 2; k++)
        {
            rm->camMin[k] = min(rm->camMin[k], min(r->art[k], r->home[k]));
            rm->camMax[k] = max(rm->camMax[k], max(r->art[k] + r->art[k + 2] - (k ? VIEW_H : VIEW_W), r->home[k]));
            if (r->sections != NULL)
            {
                rm->cursorMin[k] = min(rm->cursorMin[k], r->grid[k]);
                rm->cursorMax[k] = max(rm->cursorMax[k], r->grid[k] + r->grid[k + 2] - 1);
            }
        }
    }
    for (i = 0; i < NELEMS(sWorldMasks); i++)
    {
        if (!FlagGet(sWorldMasks[i].flag))
            memcpy(rm->hidden[rm->numHidden++], sWorldMasks[i].rect, 4);
    }
}

static bool8 IsWorldCellHidden(s16 x, s16 y)
{
    u32 i;

    if (x < 0 || y < 0 || x >= WORLD_WIDTH || y >= WORLD_HEIGHT)
        return TRUE;
    for (i = 0; i < sRegionMap->numHidden; i++)
    {
        const u8 *r = sRegionMap->hidden[i];

        if (x >= r[0] && x < r[0] + r[2] && y >= r[1] && y < r[1] + r[3])
            return TRUE;
    }
    return FALSE;
}

static s16 CellScreenX(s16 x)
{
    return 8 * x - sRegionMap->camPx + VIEW_X + 4;
}

static s16 CellScreenY(s16 y)
{
    return 8 * y - sRegionMap->camPy + VIEW_Y + 4;
}

// The viewport's cells and those around it, where a 16x16 icon still overhangs into the viewport
static bool8 IsCellAroundView(s16 x, s16 y)
{
    s16 sx = CellScreenX(x);
    s16 sy = CellScreenY(y);

    return sx > VIEW_X - 12 && sx < VIEW_X + 8 * VIEW_W + 12 && sy > VIEW_Y - 12 && sy < VIEW_Y + 8 * VIEW_H + 12;
}

static void SetWorldViewScroll(void)
{
    ChangeBgX(0, (sRegionMap->camPx & 7) << 8, BG_COORD_SET);
    ChangeBgY(0, (sRegionMap->camPy & 7) << 8, BG_COORD_SET);
}

// BG0 = the viewport's cells of the world tilemap, plus one column and one row for the fine scroll
static void DrawWorldView(void)
{
    s32 i, j;
    s16 x, y;
    u16 *buffer = sRegionMap->bgTilemapBuffers[0];

    sRegionMap->camX = sRegionMap->camPx >> 3;
    sRegionMap->camY = sRegionMap->camPy >> 3;
    for (j = 0; j <= VIEW_H; j++)
    {
        for (i = 0; i <= VIEW_W; i++)
        {
            x = sRegionMap->camX + i;
            y = sRegionMap->camY + j;
            buffer[(VIEW_Y / 8 + j) * 32 + VIEW_X / 8 + i] = IsWorldCellHidden(x, y) ? SEA_TILE : sWorldTilemap[y * WORLD_WIDTH + x];
        }
    }
    CopyBgTilemapBufferToVram(0);
    SetWorldViewScroll();
}

static void SetCamera(s16 x, s16 y)
{
    sRegionMap->camPx = 8 * x;
    sRegionMap->camPy = 8 * y;
    DrawWorldView();
    UpdateWorldSprites();
}

// One frame of a camera move: BG0 is redrawn when the camera crosses a cell, the icons follow
static void MoveCamera(void)
{
    sRegionMap->camPx += sRegionMap->camMove[0];
    sRegionMap->camPy += sRegionMap->camMove[1];
    if ((sRegionMap->camPx >> 3) != sRegionMap->camX || (sRegionMap->camPy >> 3) != sRegionMap->camY)
        DrawWorldView();
    else
        SetWorldViewScroll();
    UpdateWorldSprites();
}

// The opening view: the home view of the player's region (FRLG's own screen for Kanto, the whole group for a Sevii
// group), moved only to show a player beyond it (Hoenn is wider than the viewport)
static void InitWorldCamera(void)
{
    u32 k;
    s16 cam, pos, size;

    for (k = 0; k < 2; k++)
    {
        cam = sWorldRegions[sRegionMap->playersRegion].home[k];
        pos = k ? sMapCursor->y : sMapCursor->x;
        size = k ? VIEW_H : VIEW_W;
        if (pos < cam)
            cam = pos - sViewMargins[k][0];
        else if (pos >= cam + size)
            cam = pos - (size - 1 - sViewMargins[k][1]);
        if (cam > sRegionMap->camMax[k])
            cam = sRegionMap->camMax[k];
        if (cam < sRegionMap->camMin[k])
            cam = sRegionMap->camMin[k];
        sRegionMap->homeCam[k] = cam;
    }
    SetCamera(sRegionMap->homeCam[0], sRegionMap->homeCam[1]);
}

// Red arrows on the sides where the camera can still go (menu_indicators' scroll arrows, shown and hidden by their
// task from the camera's cell)
static void CreateEdgeArrows(void)
{
    struct ScrollArrowsTemplate arrows = {
        .firstArrowType = SCROLL_ARROW_LEFT,
        .firstX = VIEW_X + 8,
        .firstY = VIEW_Y + 72,
        .secondArrowType = SCROLL_ARROW_RIGHT,
        .secondX = VIEW_X + 8 * VIEW_W - 8,
        .secondY = VIEW_Y + 72,
        .fullyUpThreshold = sRegionMap->camMin[0],
        .fullyDownThreshold = sRegionMap->camMax[0],
        .tileTag = TAG_ARROWS_X,
        .palTag = TAG_ARROWS_PAL,
    };

    sRegionMap->arrowTaskIds[0] = AddScrollIndicatorArrowPair(&arrows, &sRegionMap->camX);
    arrows.firstArrowType = SCROLL_ARROW_UP;
    arrows.firstX = VIEW_X + 160; // right of the name boxes
    arrows.firstY = VIEW_Y + 8;
    arrows.secondArrowType = SCROLL_ARROW_DOWN;
    arrows.secondX = VIEW_X + 96;
    arrows.secondY = VIEW_Y + 8 * VIEW_H - 8;
    arrows.fullyUpThreshold = sRegionMap->camMin[1];
    arrows.fullyDownThreshold = sRegionMap->camMax[1];
    arrows.tileTag = TAG_ARROWS_Y;
    sRegionMap->arrowTaskIds[1] = AddScrollIndicatorArrowPair(&arrows, &sRegionMap->camY);
}

static void RemoveEdgeArrows(void)
{
    u32 i;

    for (i = 0; i < NELEMS(sRegionMap->arrowTaskIds); i++)
    {
        if (sRegionMap->arrowTaskIds[i] != TASK_NONE)
            RemoveScrollIndicatorArrowPair(sRegionMap->arrowTaskIds[i]);
        sRegionMap->arrowTaskIds[i] = TASK_NONE;
    }
}

static void CB2_OpenRegionMap(void)
{
    switch (sRegionMap->openState)
    {
    case 0:
        NullVBlankHBlankCallbacks();
        break;
    case 1:
        InitRegionMapBgs();
        break;
    case 2:
        ResetOamForRegionMap();
        break;
    case 3:
        if (!LoadRegionMapGfx())
            return;
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(1);
        break;
    case 5:
        // BG0 is drawn with the cursor, at the camera that shows the player
        if (sRegionMap->type != REGIONMAP_TYPE_NORMAL)
        {
            CopyToBgTilemapBufferRect(1, sRegionMap->bgTilemap, 0, 0, 30, 20);
            CopyBgTilemapBufferToVram(1);
        }
        break;
    case 6:
        DisplayCurrentMapName();
        PutWindowTilemap(WIN_MAP_NAME);
        break;
    case 7:
        DisplayCurrentDungeonName();
        PutWindowTilemap(WIN_DUNGEON_NAME);
        break;
    case 8:
        if (GetRegionMapPermission(MAPPERM_HAS_OPEN_ANIM) == TRUE)
            SetBg0andBg3Hidden(TRUE);
        break;
    default:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        CreateMainMapTask();
        SetRegionMapVBlankCB();
        break;
    }
    sRegionMap->openState++;
}

static bool8 LoadRegionMapGfx(void)
{
    switch (sRegionMap->loadGfxState)
    {
    case 0:
        LoadPalette(sTopBar_Pal, BG_PLTT_ID(12), sizeof(sTopBar_Pal));
        break;
    case 1:
        LoadPalette(sRegionMap_Pal, BG_PLTT_ID(0), sizeof(sRegionMap_Pal));
        LoadPalette(sWorld_Pal, BG_PLTT_ID(WORLD_FIRST_PAL), WORLD_NUM_PALS * PLTT_SIZE_4BPP);
        TintMapEdgesPalette();
        if (sRegionMap->type != REGIONMAP_TYPE_NORMAL)
        {
            LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(0), sizeof(sTopBar_Pal[15]));
            LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(1), sizeof(sTopBar_Pal[15]));
            LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(2), sizeof(sTopBar_Pal[15]));
            LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(3), sizeof(sTopBar_Pal[15]));
            LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(4), sizeof(sTopBar_Pal[15]));
        }
        break;
    case 2:
        ResetTempTileDataBuffers();
        break;
    case 3:
        DecompressAndCopyTileDataToVram(0, sRegionMap_Gfx, 0, 0, 0);
        LoadBgTiles(0, sWorldTiles, WORLD_TILES_LOW * TILE_SIZE_4BPP, 320);
        if (WORLD_NUM_TILES > WORLD_TILES_LOW) // BG0 tiles 512-575 are BG1's
            LoadBgTiles(0, (const u8 *)sWorldTiles + WORLD_TILES_LOW * TILE_SIZE_4BPP, (WORLD_NUM_TILES - WORLD_TILES_LOW) * TILE_SIZE_4BPP, 576);
        if (sRegionMap->type != REGIONMAP_TYPE_NORMAL)
        {
            DecompressAndCopyTileDataToVram(1, sBackground_Gfx, 0, 0, 0);
            LoadBgTiles(1, sWhiteTile, sizeof(sWhiteTile), 14); // the frame's white columns (on BG0 before the world map)
        }
        break;
    case 4:
        if (FreeTempTileDataBuffersIfPossible() == TRUE)
            return FALSE;
        break;
    case 5:
        // The cancel button: Kanto's tiles, copied to BG3, which does not scroll
        LoadBgTiles(3, (const void *)(BG_VRAM + 0xF0 * TILE_SIZE_4BPP), 3 * TILE_SIZE_4BPP, CANCEL_BUTTON_TILE);
        LoadBgTiles(3, (const void *)(BG_VRAM + 0x120 * TILE_SIZE_4BPP), 3 * TILE_SIZE_4BPP, CANCEL_BUTTON_TILE + 3);
        LoadBgTiles(3, (const void *)(BG_VRAM + 0x130 * TILE_SIZE_4BPP), 3 * TILE_SIZE_4BPP, CANCEL_BUTTON_TILE + 6);
        break;
    default:
        LZ77UnCompWram(sBackground_Tilemap, sRegionMap->bgTilemap);
        return TRUE;
    }
    sRegionMap->loadGfxState++;
    return FALSE;
}

static void CreateMainMapTask(void)
{
    CreateTask(sRegionMap->mainTask, 0);
    SetMainCallback2(CB2_RegionMap);
}

static bool32 SelectedMapsecSEEnabled(void)
{
    if (GetSelectedMapSection(LAYER_MAP, GetMapCursorX(), GetMapCursorY()) == MAPSEC_ROUTE_4_POKECENTER)
        return FALSE;
    else
        return TRUE;
}

static void PlaySEForSelectedMapsec(void)
{
    if (SelectedMapsecSEEnabled())
    {
        if ((GetSelectedMapsecType(LAYER_MAP) != MAPSECTYPE_ROUTE && GetSelectedMapsecType(LAYER_MAP) != MAPSECTYPE_NONE) 
         || (GetSelectedMapsecType(LAYER_DUNGEON) != MAPSECTYPE_ROUTE && GetSelectedMapsecType(LAYER_DUNGEON) != MAPSECTYPE_NONE))
            PlaySE(SE_DEX_SCROLL);
        if (IsCursorOnCancel())
            PlaySE(SE_M_SPIT_UP);
    }
}

static void Task_RegionMap(u8 taskId)
{
    switch (sRegionMap->mainState)
    {
    case 0:
        InitMapIcons(taskId, sRegionMap->mainTask);
        CreateMapCursor(0, 0);
        CreatePlayerIcon(1, 1);
        sRegionMap->mainState++;
        break;
    case 1:
        if (sRegionMap->permissions[MAPPERM_HAS_OPEN_ANIM] == TRUE)
        {
            InitMapOpenAnim(taskId, sRegionMap->mainTask);
        }
        else
        {
            ShowBg(0);
            ShowBg(3);
            ShowBg(1);
            PrintTopBarTextLeft(gText_RegionMap_DPadMove);
            PrintTopBarTextRight(gText_RegionMap_Space);
            ClearOrDrawTopBar(FALSE);
            SetPlayerIconInvisibility(FALSE);
            SetMapCursorInvisibility(FALSE);
            SetMapIconsInvisibility(FALSE);
        }
        sRegionMap->mainState++;
        break;
    case 2:
        if (!gPaletteFade.active && !IsDma3ManagerBusyWithBgCopy())
        {
            DisplayCurrentMapName();
            PutWindowTilemap(WIN_MAP_NAME);
            DisplayCurrentDungeonName();
            PutWindowTilemap(WIN_DUNGEON_NAME);
            CreateEdgeArrows();
            sRegionMap->mainState++;
        }
        break;
    case 3:
        switch (GetRegionMapInput())
        {
        case MAP_INPUT_MOVE_START:
            ResetCursorSnap();
            break;
        case MAP_INPUT_MOVE_CONT:
            break;
        case MAP_INPUT_MOVE_END:
            DisplayCurrentMapName();
            DisplayCurrentDungeonName();
            DrawDungeonNameBox();
            PlaySEForSelectedMapsec();
            if (GetDungeonMapsecUnderCursor() != MAPSEC_NONE)
            {
                if (GetRegionMapPermission(MAPPERM_HAS_MAP_PREVIEW) == TRUE)
                {
                    if (CanShowDungeonPreview())
                    {
                        PrintTopBarTextRight(gText_RegionMap_AButtonGuide);
                    }
                    else
                    {
                        PrintTopBarTextRight(gText_RegionMap_Space);
                    }
                }
            }
            else
            {
                if (IsCursorOnCancel())
                {
                    PrintTopBarTextRight(gText_RegionMap_AButtonCancel);
                }
                else
                {
                    PrintTopBarTextRight(gText_RegionMap_Space);
                }
            }
            break;
        case MAP_INPUT_A_BUTTON:
            if (CanShowDungeonPreview())
                InitDungeonMapPreview(0, taskId, SaveMainMapTask);
            break;
        case MAP_INPUT_CANCEL:
            RemoveEdgeArrows();
            sRegionMap->mainState++;
            break;
        }
        break;
    case 4:
        if (GetRegionMapPermission(MAPPERM_HAS_OPEN_ANIM) == TRUE)
        {
            DoMapCloseAnim(taskId);
            // FIXME: goto required to match
            // sRegionMap->mainState++;
            goto INCREMENT_MAIN_STATE_AND_BREAK;
        }
        else
        {
            sRegionMap->mainState++;
        }
        break;
    case 5:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    INCREMENT_MAIN_STATE_AND_BREAK:
        sRegionMap->mainState++;
        break;
    default:
        if (!gPaletteFade.active)
        {
            FreeRegionMap(taskId);
        }
        break;
    }
}

// Unused
static void SetMainMapTask(TaskFunc taskFunc)
{
    sRegionMap->mainTask = taskFunc;
}

static TaskFunc GetMainMapTask(void)
{
    return sRegionMap->mainTask;
}

static void SaveMainMapTask(u8 taskId)
{
    gTasks[taskId].func = sRegionMap->mainTask;
}

static void FreeRegionMap(u8 taskId)
{
    RemoveEdgeArrows();
    if (GetRegionMapPermission(MAPPERM_HAS_OPEN_ANIM) == TRUE)
        FreeMapOpenCloseAnim();
    FreeMapIcons();
    FreeMapCursor();
    FreePlayerIcon();
    FreeAndResetGpuRegs();
    DestroyTask(taskId);
    FreeAllWindowBuffers();
    if (sRegionMap->savedCallback == NULL)
        SetMainCallback2(gMain.savedCallback);
    else
        SetMainCallback2(sRegionMap->savedCallback);
    FREE_IF_NOT_NULL(sRegionMap);
}

static void FreeRegionMapForFlyMap(void)
{
    FREE_IF_NOT_NULL(sRegionMap);
}

static void CB2_RegionMap(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_RegionMap(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void NullVBlankHBlankCallbacks(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void SetRegionMapVBlankCB(void)
{
    SetVBlankCallback(VBlankCB_RegionMap);
}

static void InitRegionMapBgs(void)
{
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaFill32Defvars(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16Defvars(3, 0, (void *)PLTT, PLTT_SIZE);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ResetBgsAndClearDma3BusyFlags(FALSE);
    InitBgsFromTemplates(0, sRegionMapBgTemplates, NELEMS(sRegionMapBgTemplates));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    InitWindows(sRegionMapWindowTemplates);
    DeactivateAllTextPrinters();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
    SetBgTilemapBuffers();
    DrawCancelButton();
    UpdateMapsecNameBox();
}

// The cancel button stays at the viewport's bottom right while the map pans under it
static void DrawCancelButton(void)
{
    u32 i;

    for (i = 0; i < 3; i++)
        WriteSequenceToBgTilemapBuffer(3, CANCEL_BUTTON_TILE + 3 * i, VIEW_X / 8 + CANCEL_BUTTON_X - 1, VIEW_Y / 8 + CANCEL_BUTTON_Y - 1 + i, 3, 1, 3, 1);
    CopyBgTilemapBufferToVram(3);
}

static void SetBgTilemapBuffers(void)
{
    SetBgTilemapBuffer(0, sRegionMap->bgTilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRegionMap->bgTilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRegionMap->bgTilemapBuffers[2]);
}

static void ResetOamForRegionMap(void)
{
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetTasks();
    ScanlineEffect_Stop();
}

static void SetBg0andBg3Hidden(bool8 hide)
{
    switch (hide)
    {
    case FALSE:
        ShowBg(0);
        ShowBg(3);
        break;
    case TRUE:
        HideBg(0);
        HideBg(3);
        break;
    }
}

// The window setup of the map: BG0 and the sprites only inside the viewport (WIN1, it hides what the camera pans out),
// the name boxes darkened (WIN0), the frame (BG1), the text and the cancel button (BG3) everywhere
static void UpdateMapsecNameBox(void)
{
    ResetGpuRegs();
    SetBldCnt(0, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_OBJ, BLDCNT_EFFECT_DARKEN);
    SetBldY(BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2);
    SetWinIn(
        (WININ_WIN0_BG0 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR),
        (WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG3 | WININ_WIN1_OBJ) >> 8);
    SetWinOut(WINOUT_WIN01_BG1 | WINOUT_WIN01_BG3);
    SetGpuWindowDims(1, &sMapWindowDim);
    SetDispCnt(0, FALSE);
    SetDispCnt(1, FALSE);
    UpdateNameBoxWindow();
}

// WIN0 = the map name box and/or the dungeon name box below it
static void UpdateNameBoxWindow(void)
{
    struct GpuWindowParams box = sMapsecNameWindowDims[WIN_MAP_NAME];

    if (GetDungeonMapsecUnderCursor() != MAPSEC_NONE)
        box.bottom = sMapsecNameWindowDims[WIN_DUNGEON_NAME].bottom;
    if (GetMapsecUnderCursor() == MAPSEC_NONE)
        box.top = sMapsecNameWindowDims[WIN_DUNGEON_NAME].top;
    if (box.top == box.bottom)
        box = sMapsecNameWindowDims[CLEAR_NAME];
    SetGpuWindowDims(0, &box);
}

static void DisplayCurrentMapName(void)
{
    ClearWindowTilemap(WIN_MAP_NAME);
    FillWindowPixelBuffer(WIN_MAP_NAME, PIXEL_FILL(0));
    if (GetMapsecUnderCursor() != MAPSEC_NONE)
    {
        GetMapName(sRegionMap->mapName, GetMapsecUnderCursor(), 0);
        AddTextPrinterParameterized3(WIN_MAP_NAME, FONT_NORMAL, 2, 2, sTextColor_White, 0, sRegionMap->mapName);
        PutWindowTilemap(WIN_MAP_NAME);
        CopyWindowToVram(WIN_MAP_NAME, COPYWIN_GFX);
    }
    UpdateNameBoxWindow();
}

static void DrawDungeonNameBox(void)
{
    UpdateNameBoxWindow();
}

static void DisplayCurrentDungeonName(void)
{
    u16 mapsecId;
    u16 descOffset;
    sRegionMap->dungeonWinTop = FALSE;
    sRegionMap->dungeonWinRight = 24;
    sRegionMap->dungeonWinBottom = 32;
    ClearWindowTilemap(WIN_DUNGEON_NAME);
    mapsecId = GetDungeonMapsecUnderCursor();
    if (mapsecId != MAPSEC_NONE)
    {
         descOffset = mapsecId;
         sRegionMap->dungeonWinTop = TRUE;
         sRegionMap->dungeonWinLeft = StringLength(sMapNames[descOffset]);
         sRegionMap->dungeonWinRight = sRegionMap->dungeonWinLeft * 10 + 50;
         sRegionMap->dungeonWinBottom = 48;
         FillWindowPixelBuffer(WIN_DUNGEON_NAME, PIXEL_FILL(0));
         StringCopy(sRegionMap->dungeonName, sMapNames[descOffset]);
         AddTextPrinterParameterized3(WIN_DUNGEON_NAME, FONT_NORMAL, 12, 2, GetSelectedMapsecType(LAYER_DUNGEON) == MAPSECTYPE_VISITED ? sTextColor_Green : sTextColor_Red, 0, sRegionMap->dungeonName);
         PutWindowTilemap(WIN_DUNGEON_NAME);
         CopyWindowToVram(WIN_DUNGEON_NAME, COPYWIN_FULL);
    }
    UpdateNameBoxWindow();
}

static void ClearMapsecNameText(void)
{
    FillWindowPixelBuffer(WIN_MAP_NAME, PIXEL_FILL(0));
    CopyWindowToVram(WIN_MAP_NAME, COPYWIN_FULL);
    FillWindowPixelBuffer(WIN_DUNGEON_NAME, PIXEL_FILL(0));
    CopyWindowToVram(WIN_DUNGEON_NAME, COPYWIN_FULL);
}

static bool8 GetRegionMapPermission(u8 attr)
{
    return sRegionMap->permissions[attr];
}

static const u8 *GetDungeonFlavorText(u16 mapsec)
{
    u32 i;
    for (i = 0; i < NELEMS(sDungeonInfo); i++)
    {
        if (sDungeonInfo[i].id == mapsec)
            return sDungeonInfo[i].desc;
    }
    return gText_RegionMap_NoData;
}

static const u8 *GetDungeonName(u16 mapsec)
{
    u32 i;
    for (i = 0; i < NELEMS(sDungeonInfo); i++)
    {
        if (sDungeonInfo[i].id == mapsec)
            return sDungeonInfo[i].name;
    }
    return gText_RegionMap_NoData;
}

static void InitDungeonMapPreview(u8 unused, u8 taskId, TaskFunc taskFunc)
{
    u8 mapsec;
    sDungeonMapPreview = AllocZeroed(sizeof(struct DungeonMapPreview));
    mapsec = GetDungeonMapsecUnderCursor();
    if (mapsec == MAPSEC_TANOBY_CHAMBERS)
        mapsec = MAPSEC_MONEAN_CHAMBER;
    sDungeonMapPreview->mapPreviewInfo = GetDungeonMapPreviewScreenInfo(mapsec);
    if (sDungeonMapPreview->mapPreviewInfo == NULL)
        sDungeonMapPreview->mapPreviewInfo = GetDungeonMapPreviewScreenInfo(MAPSEC_ROCK_TUNNEL);
    sDungeonMapPreview->mainState = 0;
    sDungeonMapPreview->loadState = 0;
    sDungeonMapPreview->savedTask = taskFunc;
    sDungeonMapPreview->blendY = 0;
    RemoveEdgeArrows(); // they would show darkened beside the preview
    SaveRegionMapGpuRegs(0);
    ResetGpuRegs();
    ClearMapsecNameText();
    gTasks[taskId].func = Task_DungeonMapPreview;
}

static bool8 LoadMapPreviewGfx(void)
{
    switch (sDungeonMapPreview->loadState)
    {
    case 0:
        LZ77UnCompWram(sDungeonMapPreview->mapPreviewInfo->tilesptr, sDungeonMapPreview->tiles);
        break;
    case 1:
        LZ77UnCompWram(sDungeonMapPreview->mapPreviewInfo->tilemapptr, sDungeonMapPreview->tilemap);
        break;
    case 2:
        LoadBgTiles(2, sDungeonMapPreview->tiles, sizeof(sDungeonMapPreview->tiles), 0);
        break;
    case 3:
        LoadPalette(sDungeonMapPreview->mapPreviewInfo->palptr, BG_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);
        break;
    default:
        return TRUE;
    }
    sDungeonMapPreview->loadState++;
    return FALSE;
}

static void Task_DungeonMapPreview(u8 taskId)
{
    switch (sDungeonMapPreview->mainState)
    {
    case 0:
        NullVBlankHBlankCallbacks();
        sDungeonMapPreview->mainState++;
        break;
    case 1:
        if (LoadMapPreviewGfx() == TRUE)
            sDungeonMapPreview->mainState++;
        break;
    case 2:
        InitScreenForDungeonMapPreview();
        PrintTopBarTextRight(gText_RegionMap_AButtonCancel2);
        sDungeonMapPreview->mainState++;
        break;
    case 3:
        CopyMapPreviewTilemapToBgTilemapBuffer(2, sDungeonMapPreview->tilemap);
        CopyBgTilemapBufferToVram(2);
        sDungeonMapPreview->mainState++;
        break;
    case 4:
        ShowBg(2);
        sDungeonMapPreview->mainState++;
        break;
    case 5:
        SetRegionMapVBlankCB();
        sDungeonMapPreview->mainState++;
        break;
    case 6:
        if (UpdateDungeonMapPreview(FALSE) == TRUE)
            sDungeonMapPreview->mainState++;
        break;
    case 7:
        gTasks[taskId].func = Task_DrawDungeonMapPreviewFlavorText;
        break;
    case 8:
        if (UpdateDungeonMapPreview(TRUE) == TRUE)
        {
            sDungeonMapPreview->mainState++;
        }
        break;
    case 9:
        FreeDungeonMapPreview(taskId);
        sDungeonMapPreview->mainState++;
        break;
    }
}

// Tints the dungeon preview image in the background and overlays the name and description of the dungeon
static void Task_DrawDungeonMapPreviewFlavorText(u8 taskId)
{
    switch (sDungeonMapPreview->drawState)
    {
    case 0:
        sDungeonMapPreview->red = 0x0133;
        sDungeonMapPreview->green = 0x0100;
        sDungeonMapPreview->blue = 0x00F0;
        sDungeonMapPreview->drawState++;
        break;
    case 1:
        // Delay
        if (sDungeonMapPreview->timer++ > 40)
        {
            sDungeonMapPreview->timer = 0;
            sDungeonMapPreview->drawState++;
        }
        break;
    case 2:
        FillWindowPixelBuffer(WIN_MAP_PREVIEW, PIXEL_FILL(0));
        CopyWindowToVram(WIN_MAP_PREVIEW, COPYWIN_FULL);
        PutWindowTilemap(WIN_MAP_PREVIEW);
        sDungeonMapPreview->drawState++;
        break;
    case 3:
        // Draw text
        if (sDungeonMapPreview->timer > 25)
        {
            AddTextPrinterParameterized3(WIN_MAP_PREVIEW, FONT_NORMAL, 4, 0, sTextColor_Green, -1, GetDungeonName(GetDungeonMapsecUnderCursor()));
            AddTextPrinterParameterized3(WIN_MAP_PREVIEW, FONT_NORMAL, 2, 14, sTextColor_White, -1, GetDungeonFlavorText(GetDungeonMapsecUnderCursor()));
            CopyWindowToVram(WIN_MAP_PREVIEW, COPYWIN_FULL);
            sDungeonMapPreview->drawState++;
        }
        // Tint image
        else if (sDungeonMapPreview->timer > 20)
        {
            sDungeonMapPreview->red -= 6;
            sDungeonMapPreview->green -= 5;
            sDungeonMapPreview->blue -= 5;
            CpuCopy16(sDungeonMapPreview->mapPreviewInfo->palptr, sDungeonMapPreview->palette, 0x60);
            TintPalette_CustomTone(sDungeonMapPreview->palette, 48, sDungeonMapPreview->red, sDungeonMapPreview->green, sDungeonMapPreview->blue);
            LoadPalette(sDungeonMapPreview->palette, BG_PLTT_ID(13), sizeof(sDungeonMapPreview->palette));
        }
        sDungeonMapPreview->timer++;
        break;
    case 4:
        if (JOY_NEW(B_BUTTON) || JOY_NEW(A_BUTTON))
        {
            FillWindowPixelBuffer(WIN_MAP_PREVIEW, PIXEL_FILL(0));
            CopyWindowToVram(WIN_MAP_PREVIEW, COPYWIN_FULL);
            sDungeonMapPreview->mainState++;
            sDungeonMapPreview->drawState++;
        }
        break;
    default:
        gTasks[taskId].func = Task_DungeonMapPreview;
        break;
    }
}

static void FreeDungeonMapPreview(u8 taskId)
{
    gTasks[taskId].func = sDungeonMapPreview->savedTask;
    HideBg(2);
    DrawCancelButton(); // the preview's window covered its top row
    SetRegionMapGpuRegs(0);
    DisplayCurrentMapName();
    DisplayCurrentDungeonName();
    UpdateMapsecNameBox();
    DrawDungeonNameBox();
    PrintTopBarTextRight(gText_RegionMap_AButtonGuide);
    CreateEdgeArrows();
    FREE_IF_NOT_NULL(sDungeonMapPreview);
}

static void CopyMapPreviewTilemapToBgTilemapBuffer(u8 bgId, const u16 * tilemap)
{
    CopyToBgTilemapBufferRect(2, tilemap, 0, 0, 32, 20);
}

static void InitScreenForDungeonMapPreview(void)
{
    u16 x;
    u16 y;
    ResetGpuRegs();
    SetBldCnt(0, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_OBJ, BLDCNT_EFFECT_DARKEN);
    SetBldY(sDungeonMapPreview->blendY);
    // WIN0 = the preview growing over the map, WIN1 = the viewport, darkened around it. The frame outside them shows
    // no BG0: the world map's extra column (for the fine scroll) would cover its right column
    SetWinIn(WININ_WIN0_BG0 | WININ_WIN0_BG2 | WININ_WIN0_BG3,
             (WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG3 | WININ_WIN1_OBJ | WININ_WIN1_CLR) >> 8);
    SetWinOut(WINOUT_WIN01_BG1 | WINOUT_WIN01_BG3);
    SetGpuWindowDims(1, &sMapWindowDim);
    SetDispCnt(0, FALSE);
    SetDispCnt(1, FALSE);
    x = CellScreenX(GetMapCursorX()) - 4;
    y = CellScreenY(GetMapCursorY()) - 4;
    sDungeonMapPreview->left = x;
    sDungeonMapPreview->top = y - 8;
    sDungeonMapPreview->right = sDungeonMapPreview->left + 8;
    sDungeonMapPreview->bottom = sDungeonMapPreview->top + 8;
    sDungeonMapPreview->leftIncrement = (16 - sDungeonMapPreview->left) / 8;
    sDungeonMapPreview->topIncrement = (32 - sDungeonMapPreview->top) / 8;
    sDungeonMapPreview->rightIncrement = (224 - sDungeonMapPreview->right) / 8;
    sDungeonMapPreview->bottomIncrement = (136 - sDungeonMapPreview->bottom) / 8;
}

static bool8 UpdateDungeonMapPreview(bool8 closing)
{
    struct GpuWindowParams data;

    if (!closing)
    {
        if (sDungeonMapPreview->updateCounter < 8)
        {
            sDungeonMapPreview->left += sDungeonMapPreview->leftIncrement;
            sDungeonMapPreview->top += sDungeonMapPreview->topIncrement;
            sDungeonMapPreview->right += sDungeonMapPreview->rightIncrement;
            sDungeonMapPreview->bottom += sDungeonMapPreview->bottomIncrement;
            sDungeonMapPreview->updateCounter++;
            if (sDungeonMapPreview->blendY < 6)
                sDungeonMapPreview->blendY++;
        }
        else
        {
            return TRUE;
        }
    }
    else
    {
        if (sDungeonMapPreview->updateCounter == 0)
        {
            return TRUE;
        }
        else
        {
            sDungeonMapPreview->left -= sDungeonMapPreview->leftIncrement;
            sDungeonMapPreview->top -= sDungeonMapPreview->topIncrement;
            sDungeonMapPreview->right -= sDungeonMapPreview->rightIncrement;
            sDungeonMapPreview->bottom -= sDungeonMapPreview->bottomIncrement;
            sDungeonMapPreview->updateCounter--;
            if (sDungeonMapPreview->blendY > 0)
                sDungeonMapPreview->blendY--;
        }
    }
    data.left = sDungeonMapPreview->left;
    data.top = sDungeonMapPreview->top;
    data.right = sDungeonMapPreview->right;
    data.bottom = sDungeonMapPreview->bottom;
    SetGpuWindowDims(0, &data);
    SetBldY(sDungeonMapPreview->blendY);
    return FALSE;
}

static void SpriteCB_MapEdge(struct Sprite *sprite)
{
}

static void CreateMapEdgeSprite(u8 mapEdgeNum, u8 tileTag, u8 palTag)
{
    u8 spriteId;
    struct SpriteSheet spriteSheet = {
        .data = sMapOpenCloseAnim->mapEdges[mapEdgeNum],
        .size = 0x400,
        .tag = tileTag
    };
    struct SpritePalette spritePalette = {
        .data = sMapEdge_Pal,
        .tag = palTag
    };
    struct SpriteTemplate template = {
        .tileTag = tileTag,
        .paletteTag = palTag,
        .oam = &sOamData_MapEdge,
        .anims = sAnims_MapEdge,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_MapEdge
    };

    sMapOpenCloseAnim->mapEdges[mapEdgeNum]->tileTag = tileTag;
    sMapOpenCloseAnim->mapEdges[mapEdgeNum]->palTag = palTag;
    LoadSpriteSheet(&spriteSheet);
    LoadSpritePalette(&spritePalette);
    spriteId = CreateSprite(&template, sMapOpenCloseAnim->mapEdges[mapEdgeNum]->x, sMapOpenCloseAnim->mapEdges[mapEdgeNum]->y, 0);
    sMapOpenCloseAnim->mapEdges[mapEdgeNum]->sprite = &gSprites[spriteId];
    gSprites[spriteId].invisible = TRUE;
}

static void InitMapOpenAnim(u8 taskId, TaskFunc taskFunc)
{
    u32 i;

    sMapOpenCloseAnim = AllocZeroed(sizeof(struct MapOpenCloseAnim));
    for (i = 0; i < NELEMS(sMapOpenCloseAnim->mapEdges); i++)
    {
        sMapOpenCloseAnim->mapEdges[i] = AllocZeroed(sizeof(struct MapEdge));
        sMapOpenCloseAnim->mapEdges[i]->x = 32 * (i / 3) + 104;
        sMapOpenCloseAnim->mapEdges[i]->y = 64 * (i % 3) + 40;
    }
    SaveRegionMapGpuRegs(0);
    ResetGpuRegs();
    InitScreenForMapOpenAnim();
    SetBg0andBg3Hidden(TRUE);
    sMapOpenCloseAnim->exitTask = taskFunc;
    gTasks[taskId].func = Task_MapOpenAnim;
}

static void SetMapEdgeInvisibility(u8 mapEdgeNum, bool8 invisible)
{
    u32 i;
    if (mapEdgeNum == NELEMS(sMapOpenCloseAnim->mapEdges))
    {
        for (i = 0; i < NELEMS(sMapOpenCloseAnim->mapEdges); i++)
        {
            sMapOpenCloseAnim->mapEdges[i]->sprite->invisible = invisible;
        }
    }
    else
    {
        sMapOpenCloseAnim->mapEdges[mapEdgeNum]->sprite->invisible = invisible;
    }
}

static bool8 LoadMapEdgeGfx(void)
{
    switch (sMapOpenCloseAnim->loadGfxState)
    {
    case 0:
        LZ77UnCompWram(sMapEdge_TopLeft, sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->tiles);
        CreateMapEdgeSprite(MAPEDGE_TOP_LEFT, 4, 4);
        break;
    case 1:
        LZ77UnCompWram(sMapEdge_MidLeft, sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->tiles);
        CreateMapEdgeSprite(MAPEDGE_MID_LEFT, 5, 5);
        break;
    case 2:
        LZ77UnCompWram(sMapEdge_BottomLeft, sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->tiles);
        CreateMapEdgeSprite(MAPEDGE_BOT_LEFT, 6, 6);
        break;
    case 3:
        LZ77UnCompWram(sMapEdge_TopRight, sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->tiles);
        CreateMapEdgeSprite(MAPEDGE_TOP_RIGHT, 7, 7);
        break;
    case 4:
        LZ77UnCompWram(sMapEdge_MidRight, sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->tiles);
        CreateMapEdgeSprite(MAPEDGE_MID_RIGHT, 8, 8);
        break;
    case 5:
        LZ77UnCompWram(sMapEdge_BottomRight, sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->tiles);
        CreateMapEdgeSprite(MAPEDGE_BOT_RIGHT, 9, 9);
        break;
    case 6:
        LZ77UnCompWram(sMapEdge_Gfx, sMapOpenCloseAnim->tiles);
        break;
    case 7:
        LZ77UnCompWram(sMapEdge_Tilemap, sMapOpenCloseAnim->tilemap);
        break;
    case 8:
        LoadBgTiles(1, sMapOpenCloseAnim->tiles, BG_SCREEN_SIZE, 0);
        break;
    default:
        return TRUE;
    }
    sMapOpenCloseAnim->loadGfxState++;
    return FALSE;
}

static void InitScreenForMapOpenAnim(void)
{
    struct GpuWindowParams data;
    data.left = sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->x + 8;
    data.top = 16;
    data.right = sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->x - 8;
    data.bottom = 160;
    SetBldCnt(0, BLDCNT_TGT1_BG1, BLDCNT_EFFECT_NONE);
    SetWinIn((WININ_WIN0_BG1 | WININ_WIN0_OBJ), 0);
    SetWinOut(WINOUT_WIN01_OBJ);
    SetGpuWindowDims(0, &data);
    SetDispCnt(0, FALSE);
}

// The fades of the open and close animations. WIN0 = the viewport, with BG3 for the cancel button (FRLG faded it with
// BG0; the names on BG3 come after the fade, as there); WIN1 = the frame and the top bar, without the icons beyond
// the viewport; outside them the map edges
static void SetGpuRegsToFadeMapToWhite(void)
{
    struct GpuWindowParams data = sMapWindowDim;
    struct GpuWindowParams frame = {.left = 16, .top = 0, .right = 224, .bottom = 160};

    ResetGpuRegs();
    ClearMapsecNameText();
    SetBldCnt(BLDCNT_TGT2_BG1 >> 8, (BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_BD), BLDCNT_EFFECT_LIGHTEN);
    SetBldY(sMapOpenCloseAnim->blendY);
    SetWinIn(WININ_WIN0_ALL, WININ_WIN1_BG1 >> 8);
    SetWinOut(WINOUT_WIN01_BG1 | WINOUT_WIN01_OBJ);
    SetGpuWindowDims(0, &data);
    SetGpuWindowDims(1, &frame);
    SetDispCnt(0, FALSE);
    SetDispCnt(1, FALSE);
}

static void FinishMapOpenAnim(u8 taskId)
{
    gTasks[taskId].func = sMapOpenCloseAnim->exitTask;
}

static void FreeMapOpenCloseAnim(void)
{
    u32 i;
    FreeMapEdgeSprites();
    for (i = 0; i < NELEMS(sMapOpenCloseAnim->mapEdges); i++)
    {
        FREE_IF_NOT_NULL(sMapOpenCloseAnim->mapEdges[i]);
    }
    FREE_IF_NOT_NULL(sMapOpenCloseAnim);
}

static void FreeMapEdgeSprites(void)
{
    u32 i;
    for (i = 0; i < NELEMS(sMapOpenCloseAnim->mapEdges); i++)
    {
        sMapOpenCloseAnim->mapEdges[i]->x = sMapOpenCloseAnim->mapEdges[i]->sprite->x;
        sMapOpenCloseAnim->mapEdges[i]->y = sMapOpenCloseAnim->mapEdges[i]->sprite->y;
        if (sMapOpenCloseAnim->mapEdges[i]->sprite != NULL)
        {
            DestroySprite(sMapOpenCloseAnim->mapEdges[i]->sprite);
            FreeSpriteTilesByTag(sMapOpenCloseAnim->mapEdges[i]->tileTag);
            FreeSpritePaletteByTag(sMapOpenCloseAnim->mapEdges[i]->palTag);
        }
    }
}

static void Task_MapOpenAnim(u8 taskId)
{
    switch (sMapOpenCloseAnim->openState)
    {
    case 0:
        NullVBlankHBlankCallbacks();
        sMapOpenCloseAnim->openState++;
        break;
    case 1:
        if (LoadMapEdgeGfx() == TRUE)
            sMapOpenCloseAnim->openState++;
        break;
    case 2:
        CopyToBgTilemapBufferRect(1, sMapOpenCloseAnim->tilemap, 0, 0, 30, 20);
        sMapOpenCloseAnim->openState++;
        break;
    case 3:
        CopyBgTilemapBufferToVram(1);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetRegionMapVBlankCB();
        sMapOpenCloseAnim->openState++;
        break;
    case 4:
        ShowBg(0);
        ShowBg(3);
        ShowBg(1);
        SetMapEdgeInvisibility(NELEMS(sMapOpenCloseAnim->mapEdges), FALSE);
        SetGpuWindowDimsToMapEdges();
        sMapOpenCloseAnim->openState++;
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            sMapOpenCloseAnim->openState++;
            PlaySE(SE_CARD_OPEN);
        }
        break;
    case 6:
        if (MoveMapEdgesOutward() == TRUE)
            sMapOpenCloseAnim->openState++;
        break;
    case 7:
        SetPlayerIconInvisibility(FALSE);
        SetMapCursorInvisibility(FALSE);
        sMapOpenCloseAnim->openState++;
        break;
    case 8:
        sMapOpenCloseAnim->blendY = 15;
        SetGpuRegsToFadeMapToWhite();
        SetBg0andBg3Hidden(FALSE);
        SetMapIconsInvisibility(FALSE);
        sMapOpenCloseAnim->openState++;
        break;
    case 9:
        PrintTopBarTextLeft(gText_RegionMap_DPadMove);
        if (!CanShowDungeonPreview())
            PrintTopBarTextRight(gText_RegionMap_Space);
        else
            PrintTopBarTextRight(gText_RegionMap_AButtonGuide);
        ClearOrDrawTopBar(FALSE);
        sMapOpenCloseAnim->openState++;
        break;
    case 10:
        LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(0), sizeof(sTopBar_Pal[15]));
        LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(1), sizeof(sTopBar_Pal[15]));
        LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(2), sizeof(sTopBar_Pal[15]));
        LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(3), sizeof(sTopBar_Pal[15]));
        LoadPalette(&sTopBar_Pal[15], BG_PLTT_ID(4), sizeof(sTopBar_Pal[15]));
        sMapOpenCloseAnim->openState++;
        break;
    case 11:
        FillBgTilemapBufferRect(1, 0x002, 0, 1, 1, 1, 2);
        FillBgTilemapBufferRect(1, 0x003, 1, 1, 1, 1, 2);
        FillBgTilemapBufferRect(1, 0x03E, 28, 1, 1, 1, 2);
        FillBgTilemapBufferRect(1, 0x03F, 29, 1, 1, 1, 2);
        FillBgTilemapBufferRect(1, 0x03D, 2, 1, 26, 1, 2);
        CopyBgTilemapBufferToVram(1);
        m4aSongNumStop(SE_CARD_OPEN);
        PlaySE(SE_ROTATING_GATE);
        sMapOpenCloseAnim->openState++;
        break;
    case 12:
        if (sMapOpenCloseAnim->blendY == 2)
        {
            SetMapEdgeInvisibility(NELEMS(sMapOpenCloseAnim->mapEdges), TRUE);
            sMapOpenCloseAnim->openState++;
            SetBldY(0);
        }
        else
        {
            sMapOpenCloseAnim->blendY--;
            SetBldY(sMapOpenCloseAnim->blendY);
        }
        break;
    case 13:
        SetRegionMapGpuRegs(0);
        UpdateMapsecNameBox(); // the anim's windows replaced the map's
        DisplayCurrentMapName();
        DisplayCurrentDungeonName();
        sMapOpenCloseAnim->openState++;
        break;
    default:
        FreeMapEdgeSprites();
        FinishMapOpenAnim(taskId);
        break;
    }
}

static bool8 MoveMapEdgesOutward(void)
{
    SetGpuWindowDimsToMapEdges();
    if (sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x == 0)
    {
        return TRUE;
    }
    else if (sMapOpenCloseAnim->moveState > 17)
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x -= 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x -= 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x -= 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x += 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x += 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x += 1;
    }
    else if (sMapOpenCloseAnim->moveState > 14)
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x -= 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x -= 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x -= 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x += 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x += 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x += 2;
    }
    else if (sMapOpenCloseAnim->moveState > 10)
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x -= 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x -= 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x -= 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x += 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x += 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x += 3;
    }
    else if (sMapOpenCloseAnim->moveState > 6)
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x -= 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x -= 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x -= 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x += 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x += 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x += 5;
    }
    else
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x -= 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x -= 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x -= 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x += 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x += 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x += 8;
    }
    sMapOpenCloseAnim->moveState++;
    return FALSE;
}

static void SetGpuWindowDimsToMapEdges(void)
{
    struct GpuWindowParams data;
    data.left = sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x;
    data.top = 16;
    data.right = sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x;
    data.bottom = 160;
    SetGpuWindowDims(0, &data);
}

static void InitScreenForMapCloseAnim(void)
{
    struct GpuWindowParams data;
    data.left = sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->x + 16;
    data.top = 16;
    data.right = sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->x - 16;
    data.bottom = 160;
    SetBldCnt(0, BLDCNT_TGT1_BG1, BLDCNT_EFFECT_NONE);
    SetWinIn((WININ_WIN0_BG1 | WININ_WIN0_OBJ), 0);
    SetWinOut(WINOUT_WIN01_OBJ);
    SetGpuWindowDims(0, &data);
    SetDispCnt(0, FALSE);
    SetDispCnt(1, TRUE); // the fade's frame window would hide the edges coming in
}

static void DoMapCloseAnim(u8 taskId)
{
    gTasks[taskId].func = Task_MapCloseAnim;
}

static void CreateMapEdgeSprites(void)
{
    CreateMapEdgeSprite(0, 4, 4);
    CreateMapEdgeSprite(1, 5, 5);
    CreateMapEdgeSprite(2, 6, 6);
    CreateMapEdgeSprite(3, 7, 7);
    CreateMapEdgeSprite(4, 8, 8);
    CreateMapEdgeSprite(5, 9, 9);
}

static void Task_MapCloseAnim(u8 taskId)
{
    switch (sMapOpenCloseAnim->closeState)
    {
    case 0:
        ClearOrDrawTopBar(TRUE);
        CopyWindowToVram(WIN_TOPBAR_LEFT, COPYWIN_FULL);
        CopyWindowToVram(WIN_TOPBAR_RIGHT, COPYWIN_FULL);
        sMapOpenCloseAnim->closeState++;
        break;
    case 1:
        CreateMapEdgeSprites();
        sMapOpenCloseAnim->closeState++;
        break;
    case 2:
        LoadPalette(sRegionMap_Pal, BG_PLTT_ID(0), sizeof(sRegionMap_Pal));
        sMapOpenCloseAnim->closeState++;
        break;
    case 3:
        SetMapEdgeInvisibility(NELEMS(sMapOpenCloseAnim->mapEdges), FALSE);
        SetPlayerIconInvisibility(TRUE);
        SetMapCursorInvisibility(TRUE);
        SetMapIconsInvisibility(TRUE);
        sMapOpenCloseAnim->moveState = 0;
        sMapOpenCloseAnim->blendY = 0;
        sMapOpenCloseAnim->closeState++;
        break;
    case 4:
        SetGpuRegsToFadeMapToWhite();
        sMapOpenCloseAnim->closeState++;
        break;
    case 5:
        if (sMapOpenCloseAnim->blendY == 15)
        {
            SetBldY(sMapOpenCloseAnim->blendY);
            sMapOpenCloseAnim->closeState++;
        }
        else
        {
            sMapOpenCloseAnim->blendY++;
            SetBldY(sMapOpenCloseAnim->blendY);
        }
        break;
    case 6:
        InitScreenForMapCloseAnim();
        SetGpuWindowDimsToMapEdges();
        PlaySE(SE_CARD_FLIPPING);
        sMapOpenCloseAnim->closeState++;
        break;
    case 7:
        if (MoveMapEdgesInward() == TRUE)
            sMapOpenCloseAnim->closeState++;
        break;
    default:
        gTasks[taskId].func = sMapOpenCloseAnim->exitTask;
        break;
    }
}


static bool8 MoveMapEdgesInward(void)
{
    SetGpuWindowDimsToMapEdges();
    if (sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x == 104)
    {
        return TRUE;
    }
    else if (sMapOpenCloseAnim->moveState > 17)
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x += 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x += 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x += 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x -= 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x -= 1;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x -= 1;
    }
    else if (sMapOpenCloseAnim->moveState > 14)
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x += 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x += 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x += 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x -= 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x -= 2;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x -= 2;
    }
    else if (sMapOpenCloseAnim->moveState > 10)
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x += 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x += 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x += 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x -= 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x -= 3;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x -= 3;
    }
    else if (sMapOpenCloseAnim->moveState > 6)
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x += 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x += 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x += 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x -= 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x -= 5;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x -= 5;
    }
    else
    {
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_LEFT]->sprite->x += 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_LEFT]->sprite->x += 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_LEFT]->sprite->x += 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_TOP_RIGHT]->sprite->x -= 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_MID_RIGHT]->sprite->x -= 8;
        sMapOpenCloseAnim->mapEdges[MAPEDGE_BOT_RIGHT]->sprite->x -= 8;
    }
    sMapOpenCloseAnim->moveState++;
    return FALSE;
}

// The cursor's sprite moves 2 pixels a frame, or the camera does (the cursor then stays on its screen cell)
static void SpriteCB_MapCursor(struct Sprite *sprite)
{
    if (sMapCursor->moveCounter != 0)
    {
        sprite->x += sMapCursor->horizontalMove;
        sprite->y += sMapCursor->verticalMove;
        if (sRegionMap->camMove[0] != 0 || sRegionMap->camMove[1] != 0)
            MoveCamera();
        sMapCursor->moveCounter--;
    }
    else
    {
        sMapCursor->sprite->x = CellScreenX(sMapCursor->x);
        sMapCursor->sprite->y = CellScreenY(sMapCursor->y);
    }
    // Over the cancel button (on BG3 now) as it was over the map, but under the name boxes (BG3 too)
    sprite->oam.priority = (sprite->x + 8 > VIEW_X + 8 * (CANCEL_BUTTON_X - 1) && sprite->y + 8 > VIEW_Y + 8 * (CANCEL_BUTTON_Y - 1)) ? 0 : 2;
}

static void CreateMapCursor(u16 tileTag, u16 palTag)
{
    sMapCursor = AllocZeroed(sizeof(struct MapCursor));
    LZ77UnCompWram(sMapCursor_Gfx, sMapCursor->tiles);
    sMapCursor->tileTag = tileTag;
    sMapCursor->palTag = palTag;
    GetPlayerPositionOnRegionMap_HandleOverrides();
    InitWorldCamera();
    sMapCursor->spriteX = CellScreenX(sMapCursor->x);
    sMapCursor->spriteY = CellScreenY(sMapCursor->y);
    sMapCursor->inputHandler = HandleRegionMapInput;
    UpdateSelectedMapsec();
    CreateMapCursorSprite();
}

static void CreateMapCursorSprite(void)
{
    u8 spriteId;
    struct SpriteSheet spriteSheet = {
        .data = sMapCursor->tiles,
        .size = sizeof(sMapCursor->tiles),
        .tag = sMapCursor->tileTag
    };
    struct SpritePalette spritePalette = {
        .data = sMapCursor_Pal,
        .tag = sMapCursor->palTag
    };
    struct SpriteTemplate template = {
        .tileTag = sMapCursor->tileTag,
        .paletteTag = sMapCursor->palTag,
        .oam = &sOamData_MapCursor,
        .anims = sAnims_MapCursor,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_MapCursor
    };

    LoadSpriteSheet(&spriteSheet);
    LoadSpritePalette(&spritePalette);
    spriteId = CreateSprite(&template, sMapCursor->spriteX, sMapCursor->spriteY, 0);
    sMapCursor->sprite = &gSprites[spriteId];
    SetMapCursorInvisibility(TRUE);
}

static void SetMapCursorInvisibility(bool8 invisibile)
{
    sMapCursor->sprite->invisible = invisibile;
}

static void ResetCursorSnap(void)
{
    sMapCursor->snapId = 0;
}

static void FreeMapCursor(void)
{
    if (sMapCursor->sprite != NULL)
    {
        DestroySprite(sMapCursor->sprite);
        FreeSpriteTilesByTag(sMapCursor->tileTag);
        FreeSpritePaletteByTag(sMapCursor->palTag);
    }
    FREE_IF_NOT_NULL(sMapCursor);
}

// One cell along an axis (0: x, 1: y) toward dir: the cursor moves, or the camera when the cursor would enter a margin
// of the viewport and the camera can still go that way. FALSE at the edge of the shown regions' map sections.
static bool8 StartCursorMove(u8 axis, s8 dir)
{
    s16 pos = (axis ? sMapCursor->y : sMapCursor->x) + dir;
    s16 cam = axis ? sRegionMap->camY : sRegionMap->camX;
    s16 inView = pos - cam;
    s16 *cursorMove = axis ? &sMapCursor->verticalMove : &sMapCursor->horizontalMove;

    if (pos < sRegionMap->cursorMin[axis] || pos > sRegionMap->cursorMax[axis])
        return FALSE;
    if ((dir < 0 && inView < sViewMargins[axis][0] && cam > sRegionMap->camMin[axis])
     || (dir > 0 && inView >= (axis ? VIEW_H : VIEW_W) - sViewMargins[axis][1] && cam < sRegionMap->camMax[axis]))
    {
        sRegionMap->camMove[axis] = 2 * dir;
        *cursorMove = 0;
    }
    else
    {
        sRegionMap->camMove[axis] = 0;
        *cursorMove = 2 * dir;
    }
    return TRUE;
}

static u8 HandleRegionMapInput(void)
{
    u8 input = MAP_INPUT_NONE;
    sMapCursor->horizontalMove = 0;
    sMapCursor->verticalMove = 0;
    sRegionMap->camMove[0] = 0;
    sRegionMap->camMove[1] = 0;

    if (JOY_HELD(DPAD_UP) && StartCursorMove(1, -1))
        input = MAP_INPUT_MOVE_START;
    if (JOY_HELD(DPAD_DOWN) && StartCursorMove(1, 1))
        input = MAP_INPUT_MOVE_START;
    if (JOY_HELD(DPAD_RIGHT) && StartCursorMove(0, 1))
        input = MAP_INPUT_MOVE_START;
    if (JOY_HELD(DPAD_LEFT) && StartCursorMove(0, -1))
        input = MAP_INPUT_MOVE_START;
    if (JOY_NEW(A_BUTTON))
    {
        input = MAP_INPUT_A_BUTTON;
        if (IsCursorOnCancel())
        {
            PlaySE(SE_M_HYPER_BEAM2);
            input = MAP_INPUT_CANCEL;
        }
    }
    else if (!JOY_NEW(B_BUTTON))
    {
        if (JOY_REPT(START_BUTTON))
        {
            SnapToIconOrButton();
            UpdateSelectedMapsec();
            return MAP_INPUT_MOVE_END;
        }
        else if (JOY_NEW(SELECT_BUTTON) && sRegionMap->savedCallback == CB2_ReturnToField)
        {
            input = MAP_INPUT_CANCEL;
        }
    }
    else
    {
        input = MAP_INPUT_CANCEL;
    }
    if (input == MAP_INPUT_MOVE_START)
    {
        sMapCursor->moveCounter = 4;
        sMapCursor->inputHandler = MoveMapCursor;
    }
    else
    {
        sRegionMap->camMove[0] = 0; // a move given up for A, B or START
        sRegionMap->camMove[1] = 0;
    }
    return input;
}

static u8 MoveMapCursor(void)
{
    if (sMapCursor->moveCounter != 0)
        return MAP_INPUT_MOVE_CONT;
    if (sMapCursor->horizontalMove > 0 || sRegionMap->camMove[0] > 0)
        sMapCursor->x++;
    if (sMapCursor->horizontalMove < 0 || sRegionMap->camMove[0] < 0)
        sMapCursor->x--;
    if (sMapCursor->verticalMove > 0 || sRegionMap->camMove[1] > 0)
        sMapCursor->y++;
    if (sMapCursor->verticalMove < 0 || sRegionMap->camMove[1] < 0)
        sMapCursor->y--;
    sRegionMap->camMove[0] = 0;
    sRegionMap->camMove[1] = 0;
    UpdateSelectedMapsec();
    sMapCursor->inputHandler = HandleRegionMapInput;
    return MAP_INPUT_MOVE_END;
}

static u8 GetRegionMapInput(void)
{
    return sMapCursor->inputHandler();
}

// Pressing Start on the map snaps the cursor to the Buttons / Player Icon
// Pressing repeatedly cycles between them
// Pressing Start on the map snaps the cursor to the player icon (with the opening camera) or the cancel button
// Pressing repeatedly cycles between them
static void SnapToIconOrButton(void)
{
    sMapCursor->snapId++;
    sMapCursor->snapId %= 2;
    switch (sMapCursor->snapId)
    {
    case 0:
    default:
        sMapCursor->x = GetPlayerIconX();
        sMapCursor->y = GetPlayerIconY();
        SetCamera(sRegionMap->homeCam[0], sRegionMap->homeCam[1]);
        break;
    case 1:
        sMapCursor->y = sRegionMap->camY + CANCEL_BUTTON_Y;
        sMapCursor->x = sRegionMap->camX + CANCEL_BUTTON_X;
        break;
    }
    sMapCursor->sprite->x = CellScreenX(sMapCursor->x);
    sMapCursor->sprite->y = CellScreenY(sMapCursor->y);
}

static bool8 IsCursorOnCancel(void)
{
    return sMapCursor->x - sRegionMap->camX == CANCEL_BUTTON_X && sMapCursor->y - sRegionMap->camY == CANCEL_BUTTON_Y;
}

static void UpdateSelectedMapsec(void)
{
    sMapCursor->selectedMapsec = GetMapsecUnderCursor();
    sMapCursor->selectedMapsecType = GetMapsecType(sMapCursor->selectedMapsec);
    sMapCursor->selectedDungeonType = GetDungeonMapsecType(GetDungeonMapsecUnderCursor());
}

static u16 GetMapCursorX(void)
{
    return sMapCursor->x;
}

static u16 GetMapCursorY(void)
{
    return sMapCursor->y;
}

// No cursor yet while the map opens; nothing under the cancel button
static u16 GetMapsecUnderCursor(void)
{
    if (sMapCursor == NULL || IsCursorOnCancel())
        return MAPSEC_NONE;
    return GetSelectedMapSection(LAYER_MAP, sMapCursor->x, sMapCursor->y);
}

static u16 GetDungeonMapsecUnderCursor(void)
{
    u8 mapsec;
    if (sMapCursor == NULL || IsCursorOnCancel())
        return MAPSEC_NONE;

    mapsec = GetSelectedMapSection(LAYER_DUNGEON, sMapCursor->x, sMapCursor->y);
    if (mapsec == MAPSEC_CERULEAN_CAVE && !FlagGet(FLAG_SYS_CAN_LINK_WITH_RS))
        mapsec = MAPSEC_NONE;
    return mapsec;
}

// The dungeon preview of the A button: FRLG's dungeons only
static bool8 CanShowDungeonPreview(void)
{
    u8 mapsec = GetDungeonMapsecUnderCursor();

    if (mapsec == MAPSEC_TANOBY_CHAMBERS)
        mapsec = MAPSEC_MONEAN_CHAMBER;
    return GetRegionMapPermission(MAPPERM_HAS_MAP_PREVIEW) == TRUE && GetSelectedMapsecType(LAYER_DUNGEON) == MAPSECTYPE_VISITED
        && GetDungeonMapPreviewScreenInfo(mapsec) != NULL;
}

static u8 GetMapsecType(u8 mapsec)
{
    switch (mapsec)
    {
    case MAPSEC_PALLET_TOWN:
        return FlagGet(FLAG_WORLD_MAP_PALLET_TOWN) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_VIRIDIAN_CITY:
        return FlagGet(FLAG_WORLD_MAP_VIRIDIAN_CITY) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_PEWTER_CITY:
        return FlagGet(FLAG_WORLD_MAP_PEWTER_CITY) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_CERULEAN_CITY:
        return FlagGet(FLAG_WORLD_MAP_CERULEAN_CITY) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_LAVENDER_TOWN:
        return FlagGet(FLAG_WORLD_MAP_LAVENDER_TOWN) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_VERMILION_CITY:
        return FlagGet(FLAG_WORLD_MAP_VERMILION_CITY) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_CELADON_CITY:
        return FlagGet(FLAG_WORLD_MAP_CELADON_CITY) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_FUCHSIA_CITY:
        return FlagGet(FLAG_WORLD_MAP_FUCHSIA_CITY) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_CINNABAR_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_CINNABAR_ISLAND) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_INDIGO_PLATEAU:
        return FlagGet(FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_SAFFRON_CITY:
        return FlagGet(FLAG_WORLD_MAP_SAFFRON_CITY) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_ONE_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_ONE_ISLAND) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_TWO_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_TWO_ISLAND) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_THREE_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_THREE_ISLAND) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_FOUR_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_FOUR_ISLAND) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_FIVE_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_FIVE_ISLAND) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_SEVEN_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_SEVEN_ISLAND) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_SIX_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_SIX_ISLAND) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_ROUTE_4_POKECENTER:
        if (!GetRegionMapPermission(MAPPERM_HAS_FLY_DESTINATIONS))
            return MAPSECTYPE_NONE;
        return FlagGet(FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_ROUTE_10_POKECENTER:
        return FlagGet(FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_NONE:
        return MAPSECTYPE_NONE;
    default:
        if (mapsec <= MAPSEC_EVER_GRANDE_CITY) // Hoenn's towns
            return FlagGet(FLAG_WORLD_MAP_LITTLEROOT_TOWN + mapsec) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
        return MAPSECTYPE_ROUTE;
    }
}

static u8 GetDungeonMapsecType(u8 mapsec)
{
    u32 i;

    switch (mapsec)
    {
    case MAPSEC_NONE:
        return MAPSECTYPE_NONE;
    case MAPSEC_VIRIDIAN_FOREST:
        return FlagGet(FLAG_WORLD_MAP_VIRIDIAN_FOREST) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_MT_MOON:
        return FlagGet(FLAG_WORLD_MAP_MT_MOON_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_S_S_ANNE:
        return FlagGet(FLAG_WORLD_MAP_SSANNE_EXTERIOR) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_UNDERGROUND_PATH:
        return FlagGet(FLAG_WORLD_MAP_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_UNDERGROUND_PATH_2:
        return FlagGet(FLAG_WORLD_MAP_UNDERGROUND_PATH_EAST_WEST_TUNNEL) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_DIGLETTS_CAVE:
        return FlagGet(FLAG_WORLD_MAP_DIGLETTS_CAVE_B1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_KANTO_VICTORY_ROAD:
        return FlagGet(FLAG_WORLD_MAP_VICTORY_ROAD_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_ROCKET_HIDEOUT:
        return FlagGet(FLAG_WORLD_MAP_ROCKET_HIDEOUT_B1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_SILPH_CO:
        return FlagGet(FLAG_WORLD_MAP_SILPH_CO_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_POKEMON_MANSION:
        return FlagGet(FLAG_WORLD_MAP_POKEMON_MANSION_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_KANTO_SAFARI_ZONE:
        return FlagGet(FLAG_WORLD_MAP_SAFARI_ZONE_CENTER) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_POKEMON_LEAGUE:
        return FlagGet(FLAG_WORLD_MAP_POKEMON_LEAGUE_LORELEIS_ROOM) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_ROCK_TUNNEL:
        return FlagGet(FLAG_WORLD_MAP_ROCK_TUNNEL_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_SEAFOAM_ISLANDS:
        return FlagGet(FLAG_WORLD_MAP_SEAFOAM_ISLANDS_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_POKEMON_TOWER:
        return FlagGet(FLAG_WORLD_MAP_POKEMON_TOWER_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_CERULEAN_CAVE:
        return FlagGet(FLAG_WORLD_MAP_CERULEAN_CAVE_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_POWER_PLANT:
        return FlagGet(FLAG_WORLD_MAP_POWER_PLANT) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_NAVEL_ROCK:
        return FlagGet(FLAG_WORLD_MAP_NAVEL_ROCK_EXTERIOR) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_MT_EMBER:
        return FlagGet(FLAG_WORLD_MAP_MT_EMBER_EXTERIOR) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_BERRY_FOREST:
        return FlagGet(FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_ICEFALL_CAVE:
        return FlagGet(FLAG_WORLD_MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_ROCKET_WAREHOUSE:
        return FlagGet(FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_TRAINER_TOWER_2:
        return FlagGet(FLAG_WORLD_MAP_TRAINER_TOWER_LOBBY) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_DOTTED_HOLE:
        return FlagGet(FLAG_WORLD_MAP_SIX_ISLAND_DOTTED_HOLE_1F) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_LOST_CAVE:
        return FlagGet(FLAG_WORLD_MAP_FIVE_ISLAND_LOST_CAVE_ENTRANCE) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_PATTERN_BUSH:
        return FlagGet(FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_ALTERING_CAVE:
        return FlagGet(FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_TANOBY_CHAMBERS:
        return FlagGet(FLAG_WORLD_MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_THREE_ISLE_PATH:
        return FlagGet(FLAG_WORLD_MAP_THREE_ISLAND_DUNSPARCE_TUNNEL) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_TANOBY_KEY:
        return FlagGet(FLAG_WORLD_MAP_SEVEN_ISLAND_SEVAULT_CANYON_TANOBY_KEY) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    case MAPSEC_BIRTH_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_BIRTH_ISLAND_EXTERIOR) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
    default:
        for (i = 0; i < NELEMS(sHoennDungeonFlags); i++)
        {
            if (sHoennDungeonFlags[i][0] == mapsec)
                return FlagGet(sHoennDungeonFlags[i][1]) ? MAPSECTYPE_VISITED : MAPSECTYPE_NOT_VISITED;
        }
        return MAPSECTYPE_ROUTE;
    }
}

// The visited flags of Hoenn's towns (Fly) and dungeons (icons), set on entering any map of the section, as
// setworldmapflag in FRLG's map scripts does for Kanto's
void SetHoennWorldMapFlag(u16 mapsec)
{
    u32 i;

    if (mapsec <= MAPSEC_EVER_GRANDE_CITY)
        FlagSet(FLAG_WORLD_MAP_LITTLEROOT_TOWN + mapsec);
    for (i = 0; i < NELEMS(sHoennDungeonFlags); i++)
    {
        if (sHoennDungeonFlags[i][0] == mapsec)
            FlagSet(sHoennDungeonFlags[i][1]);
    }
}

static u8 GetSelectedMapsecType(u8 layer)
{
    switch (layer)
    {
    default:
        return sMapCursor->selectedMapsecType;
    case LAYER_MAP:
        return sMapCursor->selectedMapsecType;
    case LAYER_DUNGEON:
        return sMapCursor->selectedDungeonType;
    }
}

static u16 GetPlayerCurrentMapSectionId(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->regionMapSectionId;
}

static void GetPlayerPositionOnRegionMap(void)
{
    u16 width;
    u32 divisor;
    u16 height;
    u16 x;
    u16 y;

    const struct MapHeader * mapHeader;
    struct WarpData * warp;

    switch (GetMapTypeByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
    default:
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
    case MAP_TYPE_UNDERWATER:
    case MAP_TYPE_OCEAN_ROUTE:
        sMapCursor->selectedMapsec = gMapHeader.regionMapSectionId;
        if (IsHoennRoute124Underwater())
            sMapCursor->selectedMapsec = MAPSEC_ROUTE_124; // where Route 124 is on Hoenn's grid
        width = gMapHeader.mapLayout->width;
        height = gMapHeader.mapLayout->height;
        x = gSaveBlock1Ptr->pos.x;
        y = gSaveBlock1Ptr->pos.y;
        break;
    case MAP_TYPE_UNDERGROUND:
    case MAP_TYPE_UNKNOWN:
        mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->escapeWarp.mapGroup, gSaveBlock1Ptr->escapeWarp.mapNum);
        sMapCursor->selectedMapsec = mapHeader->regionMapSectionId;
        width = mapHeader->mapLayout->width;
        height = mapHeader->mapLayout->height;
        x = gSaveBlock1Ptr->escapeWarp.x;
        y = gSaveBlock1Ptr->escapeWarp.y;
        break;
    case MAP_TYPE_SECRET_BASE:
        mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->dynamicWarp.mapGroup, gSaveBlock1Ptr->dynamicWarp.mapNum);
        sMapCursor->selectedMapsec = mapHeader->regionMapSectionId;
        width = mapHeader->mapLayout->width;
        height = mapHeader->mapLayout->height;
        x = gSaveBlock1Ptr->dynamicWarp.x;
        y = gSaveBlock1Ptr->dynamicWarp.y;
        break;
    case MAP_TYPE_INDOOR:
        if ((sMapCursor->selectedMapsec = gMapHeader.regionMapSectionId) != MAPSEC_SPECIAL_AREA)
        {
            warp = &gSaveBlock1Ptr->escapeWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
        }
        else
        {
            warp = &gSaveBlock1Ptr->dynamicWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
            sMapCursor->selectedMapsec = mapHeader->regionMapSectionId;
        }
        width = mapHeader->mapLayout->width;
        height = mapHeader->mapLayout->height;
        x = warp->x;
        y = warp->y;
        break;
    }

    sMapCursor->selectedMapsec;
    divisor = width / sMapSectionDimensions[sMapCursor->selectedMapsec][0];
    if (divisor == 0)
        divisor = 1;
    x /= divisor;
    if (x >= sMapSectionDimensions[sMapCursor->selectedMapsec][0])
        x = sMapSectionDimensions[sMapCursor->selectedMapsec][0] - 1;
    divisor = height / sMapSectionDimensions[sMapCursor->selectedMapsec][1];
    if (divisor == 0)
        divisor = 1;
    y /= divisor;
    if (y >= sMapSectionDimensions[sMapCursor->selectedMapsec][1])
        y = sMapSectionDimensions[sMapCursor->selectedMapsec][1] - 1;
    if (sMapCursor->selectedMapsec == MAPSEC_ROUTE_114 && y != 0)
        x = 0; // Emerald: below its top row, Route 114's rectangle is only its west column
    sMapCursor->x = x + sMapSectionTopLeftCorners[sMapCursor->selectedMapsec][0];
    sMapCursor->y = y + sMapSectionTopLeftCorners[sMapCursor->selectedMapsec][1];
}

static void GetPlayerPositionOnRegionMap_HandleOverrides(void)
{
    switch (GetPlayerCurrentMapSectionId())
    {
    case MAPSEC_KANTO_SAFARI_ZONE:
        sMapCursor->x = 12;
        sMapCursor->y = 12;
        break;
    case MAPSEC_SILPH_CO:
        sMapCursor->x = 14;
        sMapCursor->y = 6;
        break;
    case MAPSEC_POKEMON_MANSION:
        sMapCursor->x = 4;
        sMapCursor->y = 14;
        break;
    case MAPSEC_POKEMON_TOWER:
        sMapCursor->x = 18;
        sMapCursor->y = 6;
        break;
    case MAPSEC_POWER_PLANT:
        sMapCursor->x = 18;
        sMapCursor->y = 4;
        break;
    case MAPSEC_S_S_ANNE:
        sMapCursor->x = 14;
        sMapCursor->y = 9;
        break;
    case MAPSEC_POKEMON_LEAGUE:
        sMapCursor->x = 2;
        sMapCursor->y = 3;
        break;
    case MAPSEC_ROCKET_HIDEOUT:
        sMapCursor->x = 11;
        sMapCursor->y = 6;
        break;
    case MAPSEC_UNDERGROUND_PATH:
        sMapCursor->x = 14;
        sMapCursor->y = 7;
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(UNDERGROUND_PATH_NORTH_ENTRANCE))
        {
            sMapCursor->x = 14; // optimized out but required to match
            sMapCursor->y = 5;
        }
        break;
    case MAPSEC_UNDERGROUND_PATH_2:
        sMapCursor->x = 12;
        sMapCursor->y = 6;
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(UNDERGROUND_PATH_EAST_ENTRANCE))
        {
            sMapCursor->x = 15;
            sMapCursor->y = 6; // optimized out but required to match
        }
        break;
    case MAPSEC_BIRTH_ISLAND:
        sMapCursor->x = 18;
        sMapCursor->y = 13;
        break;
    case MAPSEC_NAVEL_ROCK:
        sMapCursor->x = 10;
        sMapCursor->y = 8;
        break;
    case MAPSEC_TRAINER_TOWER_2:
        sMapCursor->x = 5;
        sMapCursor->y = 6;
        break;
    case MAPSEC_MT_EMBER:
        sMapCursor->x = 2;
        sMapCursor->y = 3;
        break;
    case MAPSEC_BERRY_FOREST:
        sMapCursor->x = 14;
        sMapCursor->y = 12;
        break;
    case MAPSEC_PATTERN_BUSH:
        sMapCursor->x = 17;
        sMapCursor->y = 3;
        break;
    case MAPSEC_ROCKET_WAREHOUSE:
        sMapCursor->x = 17;
        sMapCursor->y = 11;
        break;
    case MAPSEC_DILFORD_CHAMBER:
    case MAPSEC_LIPTOO_CHAMBER:
    case MAPSEC_MONEAN_CHAMBER:
    case MAPSEC_RIXY_CHAMBER:
    case MAPSEC_SCUFIB_CHAMBER:
    case MAPSEC_TANOBY_CHAMBERS:
    case MAPSEC_VIAPOIS_CHAMBER:
    case MAPSEC_WEEPTH_CHAMBER:
        sMapCursor->x = 9;
        sMapCursor->y = 12;
        break;
    case MAPSEC_DOTTED_HOLE:
        sMapCursor->x = 16;
        sMapCursor->y = 8;
        break;
    case MAPSEC_VIRIDIAN_FOREST:
        sMapCursor->x = 4;
        sMapCursor->y = 6;
        break;
    case MAPSEC_ROUTE_2:
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PALLET_TOWN))
        {
            sMapCursor->x = 4;
            sMapCursor->y = 7;
        }
        else if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(CERULEAN_CITY))
        {
            sMapCursor->x = 4;
            sMapCursor->y = 5;
        }
        else
        {
            GetPlayerPositionOnRegionMap();
        }
        break;
    case MAPSEC_ROUTE_21:
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE21_NORTH))
        {
            sMapCursor->x = 4;
            sMapCursor->y = 12;
        }
        else if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE21_SOUTH))
        {
            sMapCursor->x = 4;
            sMapCursor->y = 13;
        }
        break;
    case MAPSEC_ROUTE_5:
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(VIRIDIAN_CITY))
        {
            sMapCursor->x = 14;
            sMapCursor->y = 5;
        }
        else
        {
            GetPlayerPositionOnRegionMap();
        }
        break;
    case MAPSEC_ROUTE_6:
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PALLET_TOWN))
        {
            sMapCursor->x = 14;
            sMapCursor->y = 7;
        }
        else
        {
            GetPlayerPositionOnRegionMap();
        }
        break;
    case MAPSEC_ROUTE_7:
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PALLET_TOWN))
        {
            sMapCursor->x = 13;
            sMapCursor->y = 6;
        }
        else
        {
            GetPlayerPositionOnRegionMap();
        }
        break;
    case MAPSEC_ROUTE_8:
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PALLET_TOWN))
        {
            sMapCursor->x = 15;
            sMapCursor->y = 6;
        }
        else
        {
            GetPlayerPositionOnRegionMap();
        }
        break;
    case MAPSEC_FARAWAY_ISLAND:
    case MAPSEC_ARTISAN_CAVE:
    case MAPSEC_BATTLE_FRONTIER:
    case MAPSEC_SOUTHERN_ISLAND:
        // On no region's grid: the player icon stays hidden, the cursor starts at Kanto's corner
        sMapCursor->x = 0;
        sMapCursor->y = 0;
        sRegionMap->playerHidden = TRUE;
        break;
    case MAPSEC_JAGGED_PASS:
        // On its icon, Emerald's second Jagged Pass cell (worldmap.py): the first one is Magma Hideout's
        sMapCursor->x = sMapSectionTopLeftCorners[MAPSEC_JAGGED_PASS2][0];
        sMapCursor->y = sMapSectionTopLeftCorners[MAPSEC_JAGGED_PASS2][1];
        break;
    case MAPSEC_MARINE_CAVE:
    case MAPSEC_UNDERWATER_MARINE_CAVE:
        // ponytail: Emerald's default spot (Route 105, north); port GetMarineCaveCoords with VAR_ABNORMAL_WEATHER_LOCATION
        sMapCursor->x = 0;
        sMapCursor->y = 10;
        break;
    default:
        GetPlayerPositionOnRegionMap();
        break;
    }
    // FRLG's cell -> the world: the region's grid, and on the Sevii Islands the rows its island moved
    if (sRegionMap->playersRegion >= REGIONMAP_SEVII123 && sRegionMap->playersRegion <= REGIONMAP_SEVII67)
        sMapCursor->y += sSeviiRowShifts[sRegionMap->playersRegion - REGIONMAP_SEVII123][sMapCursor->y][sMapCursor->x];
    sMapCursor->x += sWorldRegions[sRegionMap->playersRegion].grid[0];
    sMapCursor->y += sWorldRegions[sRegionMap->playersRegion].grid[1];
}

// The map section of a world cell: the grid of the shown region that has it
static u8 GetSelectedMapSection(u8 layer, s16 x, s16 y)
{
    u32 i;

    if (IsWorldCellHidden(x, y))
        return MAPSEC_NONE;
    for (i = 0; i < REGIONMAP_COUNT; i++)
    {
        const struct WorldRegion *r = &sWorldRegions[i];

        if (r->sections != NULL && x >= r->grid[0] && x < r->grid[0] + r->grid[2] && y >= r->grid[1] && y < r->grid[1] + r->grid[3])
            return r->sections[(layer * r->grid[3] + y - r->grid[1]) * r->grid[2] + x - r->grid[0]];
    }
    return MAPSEC_NONE;
}

static void CreatePlayerIcon(u16 tileTag, u16 palTag)
{
    sPlayerIcon = AllocZeroed(sizeof(struct PlayerIcon));
    if (gSaveBlock2Ptr->playerGender == FEMALE)
        LZ77UnCompWram(sPlayerIcon_Leaf, sPlayerIcon->tiles);
    else
        LZ77UnCompWram(sPlayerIcon_Red, sPlayerIcon->tiles);
    sPlayerIcon->tileTag = tileTag;
    sPlayerIcon->palTag = palTag;
    sPlayerIcon->x = GetMapCursorX();
    sPlayerIcon->y = GetMapCursorY();
    CreatePlayerIconSprite();
}

static void CreatePlayerIconSprite(void)
{
    u8 spriteId;
    struct SpriteSheet spriteSheet = {
        .data = sPlayerIcon->tiles,
        .size = sizeof(sPlayerIcon->tiles),
        .tag = sPlayerIcon->tileTag
    };
    struct SpritePalette spritePalette = {
        .data = sPlayerIcon_RedPal,
        .tag = sPlayerIcon->palTag
    };
    struct SpriteTemplate template = {
        .tileTag = sPlayerIcon->tileTag,
        .paletteTag = sPlayerIcon->palTag,
        .oam = &sOamData_PlayerIcon,
        .anims = sAnims_PlayerIcon,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    };

    if (gSaveBlock2Ptr->playerGender == FEMALE)
        spritePalette.data = sPlayerIcon_LeafPal;

    LoadSpriteSheet(&spriteSheet);
    LoadSpritePalette(&spritePalette);
    spriteId = CreateSprite(&template, CellScreenX(sPlayerIcon->x), CellScreenY(sPlayerIcon->y), 2);
    sPlayerIcon->sprite = &gSprites[spriteId];
    SetPlayerIconInvisibility(TRUE);
}

static void SetPlayerIconInvisibility(bool8 invisible)
{
    sPlayerIcon->hidden = invisible || sRegionMap->playerHidden;
    UpdateWorldSprites();
}

static void FreePlayerIcon(void)
{
    if (sPlayerIcon->sprite != NULL)
    {
        DestroySprite(sPlayerIcon->sprite);
        FreeSpriteTilesByTag(sPlayerIcon->tileTag);
        FreeSpritePaletteByTag(sPlayerIcon->palTag);
    }
    FREE_IF_NOT_NULL(sPlayerIcon);
}

static u16 GetPlayerIconX(void)
{
    return sPlayerIcon->x;
}

static u16 GetPlayerIconY(void)
{
    return sPlayerIcon->y;
}

static void InitMapIcons(u8 taskId, TaskFunc taskFunc)
{
    sMapIcons = AllocZeroed(sizeof(struct MapIcons));
    sMapIcons->exitTask = taskFunc;
    sMapIcons->hidden = TRUE;
    LZ77UnCompWram(sDungeonIcon, sMapIcons->dungeonIconTiles);
    LZ77UnCompWram(sFlyIcon, sMapIcons->flyIconTiles);
    gTasks[taskId].func = LoadMapIcons;
}

static void LoadMapIcons(u8 taskId)
{
    switch (sMapIcons->state)
    {
    case 0:
        NullVBlankHBlankCallbacks();
        sMapIcons->state++;
        break;
    case 1:
        BuildWorldIcons();
        sMapIcons->state++;
        break;
    case 2:
        CreateIconSprites();
        sMapIcons->state++;
        break;
    case 3:
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        sMapIcons->state++;
        break;
    case 4:
        SetRegionMapVBlankCB();
        sMapIcons->state++;
        break;
    default:
        SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) | DISPCNT_OBJ_ON);
        FinishMapIconLoad(taskId);
        break;
    }
}

static void FinishMapIconLoad(u8 taskId)
{
    gTasks[taskId].func = sMapIcons->exitTask;
}

// Dungeon icons on each dungeon cell (pushed to the corner of a town's cell), one fly icon on each visited town,
// centered on its cells
static void BuildWorldIcons(void)
{
    u32 i;
    s16 x, y, w, h;
    u8 mapsec, dungeon;
    struct WorldIcon *icon;

    for (i = 0; i < REGIONMAP_COUNT; i++)
    {
        const struct WorldRegion *r = &sWorldRegions[i];

        if (r->sections == NULL)
            continue;
        for (y = r->grid[1]; y < r->grid[1] + r->grid[3]; y++)
        {
            for (x = r->grid[0]; x < r->grid[0] + r->grid[2]; x++)
            {
                mapsec = GetSelectedMapSection(LAYER_MAP, x, y);
                dungeon = GetSelectedMapSection(LAYER_DUNGEON, x, y);
                if (dungeon != MAPSEC_NONE && !(dungeon == MAPSEC_CERULEAN_CAVE && !FlagGet(FLAG_SYS_CAN_LINK_WITH_RS))
                 && sMapIcons->numIcons < MAX_WORLD_ICONS)
                {
                    icon = &sMapIcons->icons[sMapIcons->numIcons++];
                    icon->x = x;
                    icon->y = y;
                    icon->dx = icon->dy = 0;
                    if ((GetMapsecType(mapsec) == MAPSECTYPE_VISITED || GetMapsecType(mapsec) == MAPSECTYPE_NOT_VISITED) && mapsec != MAPSEC_ROUTE_10_POKECENTER)
                        icon->dx = icon->dy = 2;
                    icon->kind = GetDungeonMapsecType(dungeon) == MAPSECTYPE_VISITED ? ICON_DUNGEON_VISITED : ICON_DUNGEON;
                }
                if (GetRegionMapPermission(MAPPERM_HAS_FLY_DESTINATIONS) && GetMapsecType(mapsec) == MAPSECTYPE_VISITED
                 && GetSelectedMapSection(LAYER_MAP, x - 1, y) != mapsec && GetSelectedMapSection(LAYER_MAP, x, y - 1) != mapsec
                 && sMapIcons->numIcons < MAX_WORLD_ICONS)
                {
                    for (w = 1; GetSelectedMapSection(LAYER_MAP, x + w, y) == mapsec; w++)
                        ;
                    for (h = 1; GetSelectedMapSection(LAYER_MAP, x, y + h) == mapsec; h++)
                        ;
                    icon = &sMapIcons->icons[sMapIcons->numIcons++];
                    icon->x = x;
                    icon->y = y;
                    icon->dx = 4 * (w - 1);
                    icon->dy = 4 * (h - 1);
                    icon->kind = ICON_FLY;
                }
            }
        }
    }
}

static void CreateIconSprites(void)
{
    u32 i;
    struct SpriteSheet sheet = {sMapIcons->flyIconTiles, sizeof(sMapIcons->flyIconTiles), TAG_FLY_ICON};
    struct SpritePalette palette = {sMiscIcon_Pal, TAG_MAP_ICON_PAL};

    LoadSpriteSheet(&sheet);
    sheet.data = sMapIcons->dungeonIconTiles;
    sheet.size = sizeof(sMapIcons->dungeonIconTiles);
    sheet.tag = TAG_DUNGEON_ICON;
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    for (i = 0; i < NUM_FLY_ICON_SPRITES; i++)
        sMapIcons->flySprites[i] = &gSprites[CreateSprite(&sFlyIconSpriteTemplate, 0, 0, 1)];
    for (i = 0; i < NUM_DUNGEON_ICON_SPRITES; i++)
        sMapIcons->dungeonSprites[i] = &gSprites[CreateSprite(&sDungeonIconSpriteTemplate, 0, 0, 3)];
    UpdateWorldSprites();
}

// The pooled sprites go to the icons around the camera (OAM coordinates wrap: the others are hidden); the player icon
// follows the camera too
static void UpdateWorldSprites(void)
{
    u32 i, numFly = 0, numDungeon = 0;
    struct Sprite *sprite;
    const struct WorldIcon *icon;

    if (sMapIcons != NULL && sMapIcons->dungeonSprites[NUM_DUNGEON_ICON_SPRITES - 1] != NULL) // pools created
    {
        for (i = 0; i < sMapIcons->numIcons; i++)
        {
            icon = &sMapIcons->icons[i];
            if (!IsCellAroundView(icon->x, icon->y))
                continue;
            if (icon->kind == ICON_FLY)
            {
                if (numFly == NUM_FLY_ICON_SPRITES)
                    continue;
                sprite = sMapIcons->flySprites[numFly++];
            }
            else
            {
                if (numDungeon == NUM_DUNGEON_ICON_SPRITES)
                    continue;
                sprite = sMapIcons->dungeonSprites[numDungeon++];
                StartSpriteAnimIfDifferent(sprite, icon->kind == ICON_DUNGEON_VISITED ? 0 : 1);
            }
            sprite->x = CellScreenX(icon->x) + icon->dx;
            sprite->y = CellScreenY(icon->y) + icon->dy;
            sprite->invisible = sMapIcons->hidden;
        }
        while (numFly < NUM_FLY_ICON_SPRITES)
            sMapIcons->flySprites[numFly++]->invisible = TRUE;
        while (numDungeon < NUM_DUNGEON_ICON_SPRITES)
            sMapIcons->dungeonSprites[numDungeon++]->invisible = TRUE;
    }
    if (sPlayerIcon != NULL && sPlayerIcon->sprite != NULL)
    {
        sPlayerIcon->sprite->x = CellScreenX(sPlayerIcon->x);
        sPlayerIcon->sprite->y = CellScreenY(sPlayerIcon->y);
        sPlayerIcon->sprite->invisible = sPlayerIcon->hidden || !IsCellAroundView(sPlayerIcon->x, sPlayerIcon->y);
    }
}

static void SetMapIconsInvisibility(bool8 invisible)
{
    sMapIcons->hidden = invisible;
    UpdateWorldSprites();
}

static void FreeMapIcons(void)
{
    u32 i;
    for (i = 0; i < NUM_FLY_ICON_SPRITES; i++)
    {
        if (sMapIcons->flySprites[i] != NULL)
            DestroySprite(sMapIcons->flySprites[i]);
    }
    for (i = 0; i < NUM_DUNGEON_ICON_SPRITES; i++)
    {
        if (sMapIcons->dungeonSprites[i] != NULL)
            DestroySprite(sMapIcons->dungeonSprites[i]);
    }
    FreeSpriteTilesByTag(TAG_FLY_ICON);
    FreeSpriteTilesByTag(TAG_DUNGEON_ICON);
    FreeSpritePaletteByTag(TAG_MAP_ICON_PAL);
    FREE_IF_NOT_NULL(sMapIcons);
}

static bool8 SaveRegionMapGpuRegs(u8 idx)
{
    if (sRegionMapGpuRegs[idx] != NULL)
        return FALSE;
    sRegionMapGpuRegs[idx] = AllocZeroed(sizeof(struct RegionMapGpuRegs));
    sRegionMapGpuRegs[idx]->bldcnt = GetGpuReg(REG_OFFSET_BLDCNT);
    sRegionMapGpuRegs[idx]->bldy = GetGpuReg(REG_OFFSET_BLDY);
    sRegionMapGpuRegs[idx]->bldalpha = GetGpuReg(REG_OFFSET_BLDALPHA);
    sRegionMapGpuRegs[idx]->winin = GetGpuReg(REG_OFFSET_WININ);
    sRegionMapGpuRegs[idx]->winout = GetGpuReg(REG_OFFSET_WINOUT);
    sRegionMapGpuRegs[idx]->win0h = GetGpuReg(REG_OFFSET_WIN0H);
    sRegionMapGpuRegs[idx]->win1h = GetGpuReg(REG_OFFSET_WIN1H);
    sRegionMapGpuRegs[idx]->win0v = GetGpuReg(REG_OFFSET_WIN0V);
    sRegionMapGpuRegs[idx]->win1v = GetGpuReg(REG_OFFSET_WIN1V);
    return TRUE;
}

static bool8 SetRegionMapGpuRegs(u8 idx)
{
    if (sRegionMapGpuRegs[idx] == NULL)
        return FALSE;
    SetGpuReg(REG_OFFSET_BLDCNT, sRegionMapGpuRegs[idx]->bldcnt);
    SetGpuReg(REG_OFFSET_BLDY, sRegionMapGpuRegs[idx]->bldy);
    SetGpuReg(REG_OFFSET_BLDALPHA, sRegionMapGpuRegs[idx]->bldalpha);
    SetGpuReg(REG_OFFSET_WININ, sRegionMapGpuRegs[idx]->winin);
    SetGpuReg(REG_OFFSET_WINOUT, sRegionMapGpuRegs[idx]->winout);
    SetGpuReg(REG_OFFSET_WIN0H, sRegionMapGpuRegs[idx]->win0h);
    SetGpuReg(REG_OFFSET_WIN1H, sRegionMapGpuRegs[idx]->win1h);
    SetGpuReg(REG_OFFSET_WIN0V, sRegionMapGpuRegs[idx]->win0v);
    SetGpuReg(REG_OFFSET_WIN1V, sRegionMapGpuRegs[idx]->win1v);
    FREE_IF_NOT_NULL(sRegionMapGpuRegs[idx]);
    return TRUE;
}

static void FreeRegionMapGpuRegs(void)
{
    u32 i;
    for (i = 0; i < NELEMS(sRegionMapGpuRegs); i++)
        FREE_IF_NOT_NULL(sRegionMapGpuRegs[i]);
}

static void ResetGpuRegs(void)
{
    struct GpuWindowParams data = {};
    SetBldCnt(0, 0, BLDCNT_EFFECT_NONE);
    SetBldY(0);
    SetGpuWindowDims(0, &data);
    SetGpuWindowDims(1, &data);
    SetWinIn(0, 0);
    SetDispCnt(0, TRUE);
    SetDispCnt(1, TRUE);
}

static void SetBldCnt(u8 tgt2, u16 tgt1, u16 effect)
{
    u16 regval = tgt2 << 8;
    regval |= tgt1;
    regval |= effect;
    SetGpuReg(REG_OFFSET_BLDCNT, regval);
}

static void SetBldY(u16 tgt)
{
    SetGpuReg(REG_OFFSET_BLDY, tgt);
}

static void SetBldAlpha(u16 tgt2, u16 tgt1)
{
    u16 regval = tgt2 << 8;
    regval |= tgt1;
    SetGpuReg(REG_OFFSET_BLDALPHA, regval);
}

static void SetWinIn(u16 b, u16 a)
{
    u16 regval = a << 8;
    regval |= b;
    SetGpuReg(REG_OFFSET_WININ, regval);
}

static void SetWinOut(u16 regval)
{
    SetGpuReg(REG_OFFSET_WINOUT, regval);
}

static void SetDispCnt(u8 idx, bool8 clear)
{
    u16 data[sizeof(sWinFlags) / 2];
    memcpy(data, sWinFlags, sizeof(sWinFlags));
    switch (clear)
    {
    case FALSE:
        SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) | data[idx]);
        break;
    case TRUE:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, data[idx]);
        break;
    }
}

static void SetGpuWindowDims(u8 winIdx, const struct GpuWindowParams *data)
{
    SetGpuReg(sWinRegs[winIdx][0], WIN_RANGE(data->top, data->bottom));
    SetGpuReg(sWinRegs[winIdx][1], WIN_RANGE(data->left, data->right));
}

static void FreeAndResetGpuRegs(void)
{
    FreeRegionMapGpuRegs();
    ResetGpuRegs();
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
}

static bool32 IsCeladonDeptStoreMapsec(u16 mapsec)
{
    if (sRegionMap != NULL)
        return FALSE;
    if (mapsec != MAPSEC_CELADON_CITY)
        return FALSE;
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(CELADON_CITY_DEPARTMENT_STORE_1F))
        return FALSE;
    if (gSaveBlock1Ptr->location.mapNum != MAP_NUM(CELADON_CITY_DEPARTMENT_STORE_1F)
     && gSaveBlock1Ptr->location.mapNum != MAP_NUM(CELADON_CITY_DEPARTMENT_STORE_2F)
     && gSaveBlock1Ptr->location.mapNum != MAP_NUM(CELADON_CITY_DEPARTMENT_STORE_3F)
     && gSaveBlock1Ptr->location.mapNum != MAP_NUM(CELADON_CITY_DEPARTMENT_STORE_4F)
     && gSaveBlock1Ptr->location.mapNum != MAP_NUM(CELADON_CITY_DEPARTMENT_STORE_5F)
     && gSaveBlock1Ptr->location.mapNum != MAP_NUM(CELADON_CITY_DEPARTMENT_STORE_ROOF)
     && gSaveBlock1Ptr->location.mapNum != MAP_NUM(CELADON_CITY_DEPARTMENT_STORE_ELEVATOR))
        return FALSE;
    return TRUE;
}

u8 *GetMapName(u8 *dst0, u16 mapsec, u16 fill)
{
    u8 *dst;
    u32 i;
    u16 idx;
    if ((idx = mapsec) < MAPSEC_NONE )
    {
        if (IsCeladonDeptStoreMapsec(mapsec) == TRUE)
            dst = StringCopy(dst0, sMapsecName_CENTCOMMERCIAL);
        else
            dst = StringCopy(dst0, sMapNames[idx]);
    }
    else
    {
        if (fill == 0)
            fill = 18;
        return StringFill(dst0, CHAR_SPACE, fill);
    }
    if (fill != 0)
    {
        for (i = dst - dst0; i < fill; i++)
            *dst++ = CHAR_SPACE;
        *dst = EOS;
    }
    return dst;
}

u8 *GetMapNameGeneric(u8 *dest, u16 mapsec)
{
    return GetMapName(dest, mapsec, 0);
}

// Unclear why this function is used over GetMapNameGeneric
u8 *GetMapNameGeneric_(u8 *dest, u16 mapsec)
{
    return GetMapNameGeneric(dest, mapsec);
}

static void PrintTopBarTextLeft(const u8 *str)
{
    if (sRegionMap->permissions[MAPPERM_HAS_OPEN_ANIM] == TRUE)
        FillWindowPixelBuffer(WIN_TOPBAR_LEFT, PIXEL_FILL(0));
    else
        FillWindowPixelBuffer(WIN_TOPBAR_LEFT, PIXEL_FILL(15));
    AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_SMALL, 0, 0, sTextColors, 0, str);
    CopyWindowToVram(WIN_TOPBAR_LEFT, COPYWIN_GFX);
}

static void PrintTopBarTextRight(const u8 *str)
{
    if (sRegionMap->permissions[MAPPERM_HAS_OPEN_ANIM] == TRUE)
        FillWindowPixelBuffer(WIN_TOPBAR_RIGHT, PIXEL_FILL(0));
    else
        FillWindowPixelBuffer(WIN_TOPBAR_RIGHT, PIXEL_FILL(15));
    AddTextPrinterParameterized3(WIN_TOPBAR_RIGHT, FONT_SMALL, 0, 0, sTextColors, 0, str);
    CopyWindowToVram(WIN_TOPBAR_RIGHT, COPYWIN_FULL);
}

static void ClearOrDrawTopBar(bool8 clear)
{
    if (!clear)
    {
        PutWindowTilemap(WIN_TOPBAR_LEFT);
        PutWindowTilemap(WIN_TOPBAR_RIGHT);
    }
    else
    {
        ClearWindowTilemap(WIN_TOPBAR_LEFT);
        ClearWindowTilemap(WIN_TOPBAR_RIGHT);
    }
}

void CB2_OpenFlyMap(void)
{
    InitFlyMap();
    InitRegionMap(REGIONMAP_TYPE_FLY);
}

static void Task_FlyMap(u8 taskId)
{
    switch (sFlyMap->state)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        InitMapIcons(taskId, GetMainMapTask());
        CreateMapCursor(0, 0);
        CreatePlayerIcon(1, 1);
        SetMapCursorInvisibility(FALSE);
        SetPlayerIconInvisibility(FALSE);
        sFlyMap->state++;
        break;
    case 1:
        if (GetRegionMapPermission(MAPPERM_HAS_OPEN_ANIM) == TRUE)
        {
            InitMapOpenAnim(taskId, GetMainMapTask());
        }
        else
        {
            ShowBg(0);
            ShowBg(3);
            ShowBg(1);
            PrintTopBarTextLeft(gText_RegionMap_DPadMove);
            SetMapIconsInvisibility(FALSE);
        }
        sFlyMap->state++;
        break;
    case 2:
        PrintTopBarTextRight(gText_RegionMap_AButtonOK);
        ClearOrDrawTopBar(FALSE);
        sFlyMap->state++;
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            DisplayCurrentMapName();
            PutWindowTilemap(WIN_MAP_NAME);
            DisplayCurrentDungeonName();
            PutWindowTilemap(WIN_DUNGEON_NAME);
            CreateEdgeArrows();
            sFlyMap->state++;
        }
        break;
    case 4:
        switch (GetRegionMapInput())
        {
        case MAP_INPUT_MOVE_START:
        case MAP_INPUT_MOVE_CONT:
            break;
        case MAP_INPUT_CANCEL:
            RemoveEdgeArrows();
            sFlyMap->state = 6;
            break;
        case MAP_INPUT_MOVE_END:
            if (GetSelectedMapsecType(LAYER_MAP) == MAPSECTYPE_VISITED)
                PlaySE(SE_DEX_PAGE);
            else
                PlaySEForSelectedMapsec();
            ResetCursorSnap();
            DisplayCurrentMapName();
            DisplayCurrentDungeonName();
            DrawDungeonNameBox();
            if (IsCursorOnCancel())
            {
                PlaySE(SE_M_SPIT_UP);
                PrintTopBarTextRight(gText_RegionMap_AButtonCancel);
            }
            else if (GetSelectedMapsecType(LAYER_MAP) == MAPSECTYPE_VISITED || GetSelectedMapsecType(LAYER_MAP) == MAPSECTYPE_UNKNOWN)
            {
                PrintTopBarTextRight(gText_RegionMap_AButtonOK);
            }
            else
            {
                PrintTopBarTextRight(gText_RegionMap_Space);
            }
            break;
        case MAP_INPUT_A_BUTTON:
            if ((GetSelectedMapsecType(LAYER_MAP) == MAPSECTYPE_VISITED || GetSelectedMapsecType(LAYER_MAP) == MAPSECTYPE_UNKNOWN) && GetRegionMapPermission(MAPPERM_HAS_FLY_DESTINATIONS) == TRUE)
            {
                switch (GetMapTypeByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
                {
                case MAP_TYPE_UNDERGROUND:
                case MAP_TYPE_INDOOR:
                    sFlyMap->selectedDestination = FALSE;
                    sFlyMap->state++;
                    break;
                default:
                    PlaySE(SE_USE_ITEM);
                    RemoveEdgeArrows();
                    sFlyMap->selectedDestination = TRUE;
                    sFlyMap->state++;
                    break;
                }
            }
            break;
        }
        break;
    case 5:
        if (GetRegionMapPermission(MAPPERM_HAS_OPEN_ANIM) == TRUE)
            DoMapCloseAnim(taskId);
        sFlyMap->state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sFlyMap->state++;
        break;
    default:
        if (!gPaletteFade.active)
        {
            if (sFlyMap->selectedDestination == TRUE)
                SetFlyWarpDestination(GetMapsecUnderCursor());
            FreeFlyMap(taskId);
        }
        break;
    }
}

static void InitFlyMap(void)
{
    sFlyMap = AllocZeroed(sizeof(struct FlyMap));
    sFlyMap->state = 0;
    sFlyMap->unused = 0;
}

static void FreeFlyMap(u8 taskId)
{
    RemoveEdgeArrows();
    if (GetRegionMapPermission(MAPPERM_HAS_OPEN_ANIM) == TRUE)
        FreeMapOpenCloseAnim();
    FreeMapIcons();
    FreeMapCursor();
    FreePlayerIcon();
    FreeAndResetGpuRegs();
    FreeRegionMapForFlyMap();
    DestroyTask(taskId);
    FreeAllWindowBuffers();
    if (sFlyMap->selectedDestination == TRUE)
        SetMainCallback2(CB2_ReturnToField);
    else
        SetMainCallback2(CB2_ReturnToPartyMenuFromFlyMap);
    FREE_IF_NOT_NULL(sFlyMap);
}

static void SetFlyWarpDestination(u16 mapsec)
{
    u16 idx = mapsec;
    if (mapsec == MAPSEC_LITTLEROOT_TOWN && gSaveBlock2Ptr->playerGender == FEMALE)
    {
        // in front of the player's house, as in Emerald
        SetWarpDestinationToHealLocation(SPAWN_LITTLEROOT_TOWN_MAYS_HOUSE);
        SetUsedFlyQuestLogEvent(sMapFlyDestinations[idx]);
    }
    else if (sMapFlyDestinations[idx][2])
    {
        SetWarpDestinationToHealLocation(sMapFlyDestinations[idx][2]);
        SetUsedFlyQuestLogEvent(sMapFlyDestinations[idx]);
    }
    else
    {
        SetWarpDestinationToMapWarp(sMapFlyDestinations[idx][0], sMapFlyDestinations[idx][1], -1);
    }
    ReturnToFieldFromFlyMapSelect();
}
