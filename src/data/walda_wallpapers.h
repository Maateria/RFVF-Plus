// Walda's wallpapers (Emerald's src/data/wallpapers.h and src/graphics.c): the 17th wallpaper, WALLPAPER_FRIENDS.
// Its pattern, icon and two colors come from the phrase given to Walda's father (src/walda_phrase.c).
#define WALLPAPER_ENTRY(name) {sWallpaperTiles_##name, sWallpaperTilemap_##name, sWallpaperPalettes_##name[0]}

static const u32 sWallpaperIcon_Cross[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/cross.4bpp.lz");
static const u32 sWallpaperIcon_Bolt[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/bolt.4bpp.lz");
static const u32 sWallpaperIcon_Plusle[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/plusle.4bpp.lz");

static const u16 sWallpaperPalettes_Horizontal[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/horizontal/bg.gbapal"),
};

static const u32 sWallpaperTiles_Horizontal[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/horizontal/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Horizontal[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/horizontal/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Ribbon[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/ribbon/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/ribbon/bg.gbapal"),
};

static const u32 sWallpaperTiles_Ribbon[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/ribbon/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Ribbon[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/ribbon/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Zigzagoon[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/zigzagoon/bg.gbapal"),
};
static const u32 sWallpaperTiles_Zigzagoon[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/zigzagoon/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Zigzagoon[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/zigzagoon/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Screen[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/screen/bg.gbapal"),
};
static const u32 sWallpaperTiles_Screen[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/screen/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Screen[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/screen/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Diagonal[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/diagonal/bg.gbapal"),
};
static const u32 sWallpaperTiles_Diagonal[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/diagonal/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Diagonal[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/diagonal/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Block[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/block/bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/block/bg.gbapal"),
};
static const u32 sWallpaperTiles_Block[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/block/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Block[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/block/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Pokecenter2[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter2/bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter2/bg.gbapal"),
};
static const u32 sWallpaperTiles_Pokecenter2[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter2/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Pokecenter2[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter2/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Frame[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/frame/bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/frame/bg.gbapal"),
};
static const u32 sWallpaperTiles_Frame[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/frame/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Frame[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/frame/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Blank[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/zigzagoon/bg.gbapal"),
};
static const u32 sWallpaperTiles_Blank[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/blank/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Blank[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/blank/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Circles[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/circles/bg.gbapal"),
};
static const u32 sWallpaperTiles_Circles[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/circles/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Circles[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/circles/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Azumarill[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/azumarill/bg.gbapal"),
};
static const u32 sWallpaperTiles_Azumarill[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/azumarill/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Azumarill[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/azumarill/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Pikachu[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pikachu/bg.gbapal"),
};
static const u32 sWallpaperTiles_Pikachu[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/pikachu/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Pikachu[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/pikachu/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Legendary[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/legendary/bg.gbapal"),
};
static const u32 sWallpaperTiles_Legendary[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/legendary/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Legendary[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/legendary/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Dusclops[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/dusclops/bg.gbapal"),
};
static const u32 sWallpaperTiles_Dusclops[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/dusclops/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Dusclops[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/dusclops/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Ludicolo[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/ludicolo/bg.gbapal"),
};
static const u32 sWallpaperTiles_Ludicolo[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/ludicolo/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Ludicolo[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/ludicolo/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Whiscash[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/whiscash/bg.gbapal"),
};
static const u32 sWallpaperTiles_Whiscash[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/whiscash/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Whiscash[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/whiscash/tilemap.bin.lz");

static const u32 sWallpaperIcon_Aqua[]         = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/aqua.4bpp.lz");
static const u32 sWallpaperIcon_Heart[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/heart.4bpp.lz");
static const u32 sWallpaperIcon_FiveStar[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/five_star.4bpp.lz");
static const u32 sWallpaperIcon_Brick[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/brick.4bpp.lz");
static const u32 sWallpaperIcon_FourStar[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/four_star.4bpp.lz");
static const u32 sWallpaperIcon_Asterisk[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/asterisk.4bpp.lz");
static const u32 sWallpaperIcon_Dot[]          = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/dot.4bpp.lz");
static const u32 sWallpaperIcon_LineCircle[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/line_circle.4bpp.lz");
static const u32 sWallpaperIcon_PokeBall[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/pokeball.4bpp.lz");
static const u32 sWallpaperIcon_Maze[]         = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/maze.4bpp.lz");
static const u32 sWallpaperIcon_Footprint[]    = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/footprint.4bpp.lz");
static const u32 sWallpaperIcon_BigAsterisk[]  = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/big_asterisk.4bpp.lz");
static const u32 sWallpaperIcon_Circle[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/circle.4bpp.lz");
static const u32 sWallpaperIcon_Koffing[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/koffing.4bpp.lz");
static const u32 sWallpaperIcon_Ribbon[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/ribbon.4bpp.lz");
static const u32 sWallpaperIcon_FourCircles[]  = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/four_circles.4bpp.lz");
static const u32 sWallpaperIcon_Lotad[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/lotad.4bpp.lz");
static const u32 sWallpaperIcon_Crystal[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/crystal.4bpp.lz");
static const u32 sWallpaperIcon_Pichu[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/pichu.4bpp.lz");
static const u32 sWallpaperIcon_Diglett[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/diglett.4bpp.lz");
static const u32 sWallpaperIcon_Luvdisc[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/luvdisc.4bpp.lz");
static const u32 sWallpaperIcon_StarInCircle[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/star_in_circle.4bpp.lz");
static const u32 sWallpaperIcon_Spinda[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/spinda.4bpp.lz");
static const u32 sWallpaperIcon_Latis[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/latis.4bpp.lz");
static const u32 sWallpaperIcon_Minun[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/minun.4bpp.lz");
static const u32 sWallpaperIcon_Togepi[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/togepi.4bpp.lz");
static const u32 sWallpaperIcon_Magma[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/magma.4bpp.lz");

static const struct Wallpaper sWaldaWallpapers[] =
{
    WALLPAPER_ENTRY(Zigzagoon),
    WALLPAPER_ENTRY(Screen),
    WALLPAPER_ENTRY(Horizontal),
    WALLPAPER_ENTRY(Diagonal),
    WALLPAPER_ENTRY(Block),
    WALLPAPER_ENTRY(Ribbon),
    WALLPAPER_ENTRY(Pokecenter2),
    WALLPAPER_ENTRY(Frame),
    WALLPAPER_ENTRY(Blank),
    WALLPAPER_ENTRY(Circles),
    WALLPAPER_ENTRY(Azumarill),
    WALLPAPER_ENTRY(Pikachu),
    WALLPAPER_ENTRY(Legendary),
    WALLPAPER_ENTRY(Dusclops),
    WALLPAPER_ENTRY(Ludicolo),
    WALLPAPER_ENTRY(Whiscash),
};

static const u32 *const sWaldaWallpaperIcons[] =
{
    sWallpaperIcon_Aqua,
    sWallpaperIcon_Heart,
    sWallpaperIcon_FiveStar,
    sWallpaperIcon_Brick,
    sWallpaperIcon_FourStar,
    sWallpaperIcon_Asterisk,
    sWallpaperIcon_Dot,
    sWallpaperIcon_Cross,
    sWallpaperIcon_LineCircle,
    sWallpaperIcon_PokeBall,
    sWallpaperIcon_Maze,
    sWallpaperIcon_Footprint,
    sWallpaperIcon_BigAsterisk,
    sWallpaperIcon_Circle,
    sWallpaperIcon_Koffing,
    sWallpaperIcon_Ribbon,
    sWallpaperIcon_Bolt,
    sWallpaperIcon_FourCircles,
    sWallpaperIcon_Lotad,
    sWallpaperIcon_Crystal,
    sWallpaperIcon_Pichu,
    sWallpaperIcon_Diglett,
    sWallpaperIcon_Luvdisc,
    sWallpaperIcon_StarInCircle,
    sWallpaperIcon_Spinda,
    sWallpaperIcon_Latis,
    sWallpaperIcon_Plusle,
    sWallpaperIcon_Minun,
    sWallpaperIcon_Togepi,
    sWallpaperIcon_Magma,
};
