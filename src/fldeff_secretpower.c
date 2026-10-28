#include "global.h"
#include "gflib.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "metatile_behavior.h"
#include "party_menu.h"
#include "script.h"
#include "event_object_movement.h"
#include "strings.h"
#include "task.h"
#include "secret_base.h"
#include "constants/field_effects.h"
#include "constants/metatile_behaviors.h"
#include "constants/metatile_labels.h"
#include "constants/songs.h"

// RFVF+: Emerald's Secret Power (fldeff_misc.c): the field move opens a secret base entrance (a cave's indent, a
// tree's vine, a shrub), and the base PC's turn on / off effects.

#define MAPGRID_IMPASSABLE (1 << MAPGRID_COLLISION_SHIFT) // Emerald's

static void SpriteCB_CaveEntranceInit(struct Sprite *);
static void SpriteCB_CaveEntranceOpen(struct Sprite *);
static void SpriteCB_CaveEntranceEnd(struct Sprite *);
static void SpriteCB_TreeEntranceInit(struct Sprite *);
static void SpriteCB_TreeEntranceOpen(struct Sprite *);
static void SpriteCB_TreeEntranceEnd(struct Sprite *);
static void SpriteCB_ShrubEntranceInit(struct Sprite *);
static void SpriteCB_ShrubEntranceOpen(struct Sprite *);
static void SpriteCB_ShrubEntranceEnd(struct Sprite *);

static const u8 sSecretPowerCave_Gfx[] = INCBIN_U8("graphics/field_effects/pics/secret_power_cave.4bpp");
static const u16 sSecretPowerCave_Pal[] = INCBIN_U16("graphics/field_effects/palettes/secret_power_cave.gbapal");
static const u8 sSecretPowerShrub_Gfx[] = INCBIN_U8("graphics/field_effects/pics/secret_power_shrub.4bpp");
static const u8 sSecretPowerTree_Gfx[] = INCBIN_U8("graphics/field_effects/pics/secret_power_tree.4bpp");
static const u16 sSecretPowerPlant_Pal[] = INCBIN_U16("graphics/field_effects/palettes/secret_power_plant.gbapal");

static const struct OamData sOam_SecretPower =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2,
};

static const union AnimCmd sAnim_Open[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineRiseLeft[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineDropRight[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineRiseRight[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_Open[] = {sAnim_Open};
static const union AnimCmd *const sAnimTable_SecretPowerTree[] =
{
    sAnim_Open, // the vine drops, left
    sAnim_VineRiseLeft,
    sAnim_VineDropRight,
    sAnim_VineRiseRight,
};

static const struct SpriteFrameImage sPicTable_SecretPowerCave[] =
{
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 0),
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 1),
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 2),
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 3),
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 4),
};

static const struct SpriteFrameImage sPicTable_SecretPowerTree[] =
{
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 0),
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 1),
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 2),
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 3),
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 4),
    // a 6th frame exists but is never shown: the vine metatile takes over
};

static const struct SpriteFrameImage sPicTable_SecretPowerShrub[] =
{
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 0),
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 1),
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 2),
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 3),
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 4),
};

static const struct SpriteTemplate sSpriteTemplate_SecretPowerCave =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SECRET_POWER_TREE,
    .oam = &sOam_SecretPower,
    .anims = sAnimTable_Open,
    .images = sPicTable_SecretPowerCave,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CaveEntranceInit,
};

static const struct SpriteTemplate sSpriteTemplate_SecretPowerTree =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SECRET_POWER_PLANT,
    .oam = &sOam_SecretPower,
    .anims = sAnimTable_SecretPowerTree,
    .images = sPicTable_SecretPowerTree,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TreeEntranceInit,
};

static const struct SpriteTemplate sSpriteTemplate_SecretPowerShrub =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SECRET_POWER_PLANT,
    .oam = &sOam_SecretPower,
    .anims = sAnimTable_Open,
    .images = sPicTable_SecretPowerShrub,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ShrubEntranceInit,
};

const struct SpritePalette gSpritePalette_SecretPower_Cave = {sSecretPowerCave_Pal, FLDEFF_PAL_TAG_SECRET_POWER_TREE};
const struct SpritePalette gSpritePalette_SecretPower_Plant = {sSecretPowerPlant_Pal, FLDEFF_PAL_TAG_SECRET_POWER_PLANT};

static void SetCurrentSecretBase(void)
{
    SetCurSecretBaseIdFromPosition(&gPlayerFacingPosition, gMapHeader.events);
    TrySetCurSecretBaseIndex();
}

// The sprite's offset from the player's, by facing direction (field effect arguments 5, 6). Emerald switches on
// argument 1, which holds the Pokemon's OT id by then (FldEff_FieldMoveShowMonInit): the facing direction is meant.
static void AdjustSecretPowerSpritePixelOffsets(void)
{
    bool8 onBike = (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE)) != 0;

    switch (GetPlayerFacingDirection())
    {
    case DIR_SOUTH:
        gFieldEffectArguments[5] = onBike ? 16 : 8;
        gFieldEffectArguments[6] = 40;
        break;
    case DIR_NORTH:
        gFieldEffectArguments[5] = onBike ? 16 : 8;
        gFieldEffectArguments[6] = 8;
        break;
    case DIR_WEST:
        gFieldEffectArguments[5] = -8;
        gFieldEffectArguments[6] = 24;
        break;
    case DIR_EAST:
        gFieldEffectArguments[5] = 24;
        gFieldEffectArguments[6] = 24;
        break;
    }
}

static void FieldCallback_SecretBaseCave(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(SecretBase_EventScript_CaveUseSecretPower);
}

static void FieldCallback_SecretBaseTree(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(SecretBase_EventScript_TreeUseSecretPower);
}

static void FieldCallback_SecretBaseShrub(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(SecretBase_EventScript_ShrubUseSecretPower);
}

// The party menu's FORCE CACHEE: facing north a free entrance, no base yet (the A button asks to move one)
bool8 SetUpFieldMove_SecretPower(void)
{
    u8 mb;

    CheckPlayerHasSecretBase();
    if (gSpecialVar_Result == 1 || GetPlayerFacingDirection() != DIR_NORTH)
        return FALSE;

    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    mb = MapGridGetMetatileBehaviorAt(gPlayerFacingPosition.x, gPlayerFacingPosition.y);
    if (MetatileBehavior_IsSecretBaseCave(mb) == TRUE)
        gPostMenuFieldCallback = FieldCallback_SecretBaseCave;
    else if (MetatileBehavior_IsSecretBaseTree(mb) == TRUE)
        gPostMenuFieldCallback = FieldCallback_SecretBaseTree;
    else if (MetatileBehavior_IsSecretBaseShrub(mb) == TRUE)
        gPostMenuFieldCallback = FieldCallback_SecretBaseShrub;
    else
        return FALSE;
    SetCurrentSecretBase();
    gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
    return TRUE;
}

static void StartSecretBaseCaveFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_CAVE);
    FieldEffectStart(FLDEFF_SECRET_POWER_CAVE);
}

static void StartSecretBaseTreeFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_TREE);
    FieldEffectStart(FLDEFF_SECRET_POWER_TREE);
}

static void StartSecretBaseShrubFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_SHRUB);
    FieldEffectStart(FLDEFF_SECRET_POWER_SHRUB);
}

// The Pokemon shows up (CreateFieldEffectShowMon), then the entrance opens
bool8 FldEff_UseSecretPowerCave(void)
{
    u8 taskId = CreateFieldEffectShowMon();
    FLDEFF_SET_FUNC_TO_DATA(StartSecretBaseCaveFieldEffect);
    return FALSE;
}

bool8 FldEff_UseSecretPowerTree(void)
{
    u8 taskId = CreateFieldEffectShowMon();
    FLDEFF_SET_FUNC_TO_DATA(StartSecretBaseTreeFieldEffect);
    return FALSE;
}

bool8 FldEff_UseSecretPowerShrub(void)
{
    u8 taskId = CreateFieldEffectShowMon();
    FLDEFF_SET_FUNC_TO_DATA(StartSecretBaseShrubFieldEffect);
    return FALSE;
}

static void CreateSecretPowerSprite(const struct SpriteTemplate *template)
{
    AdjustSecretPowerSpritePixelOffsets();
    CreateSprite(template, gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6], 148);
}

bool8 FldEff_SecretPowerCave(void)
{
    CreateSecretPowerSprite(&sSpriteTemplate_SecretPowerCave);
    return FALSE;
}

static void SpriteCB_CaveEntranceInit(struct Sprite *sprite)
{
    PlaySE(SE_M_ROCK_THROW);
    sprite->data[0] = 0;
    sprite->callback = SpriteCB_CaveEntranceOpen;
}

static void SpriteCB_CaveEntranceOpen(struct Sprite *sprite)
{
    if (sprite->data[0] < 40)
    {
        if (++sprite->data[0] == 20)
            ToggleSecretBaseEntranceMetatile();
    }
    else
    {
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_CaveEntranceEnd;
    }
}

static void SpriteCB_CaveEntranceEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_CAVE);
    ScriptContext_Enable();
}

// Argument 7: the vine's animation (0 = drops on the left, 2 = on the right)
bool8 FldEff_SecretPowerTree(void)
{
    s16 mb = MapGridGetMetatileBehaviorAt(gPlayerFacingPosition.x, gPlayerFacingPosition.y);

    if (mb == MB_SECRET_BASE_SPOT_TREE_LEFT)
        gFieldEffectArguments[7] = 0;
    if (mb == MB_SECRET_BASE_SPOT_TREE_RIGHT)
        gFieldEffectArguments[7] = 2;
    CreateSecretPowerSprite(&sSpriteTemplate_SecretPowerTree);
    if (gFieldEffectArguments[7] == 1 || gFieldEffectArguments[7] == 3)
        ToggleSecretBaseEntranceMetatile();
    return FALSE;
}

static void SpriteCB_TreeEntranceInit(struct Sprite *sprite)
{
    PlaySE(SE_M_SCRATCH);
    sprite->animNum = gFieldEffectArguments[7];
    sprite->data[0] = 0;
    sprite->callback = SpriteCB_TreeEntranceOpen;
}

static void SpriteCB_TreeEntranceOpen(struct Sprite *sprite)
{
    if (++sprite->data[0] >= 40)
    {
        if (gFieldEffectArguments[7] == 0 || gFieldEffectArguments[7] == 2)
            ToggleSecretBaseEntranceMetatile();
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_TreeEntranceEnd;
    }
}

static void SpriteCB_TreeEntranceEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_TREE);
    ScriptContext_Enable();
}

bool8 FldEff_SecretPowerShrub(void)
{
    CreateSecretPowerSprite(&sSpriteTemplate_SecretPowerShrub);
    return FALSE;
}

static void SpriteCB_ShrubEntranceInit(struct Sprite *sprite)
{
    PlaySE(SE_M_POISON_POWDER);
    sprite->data[0] = 0;
    sprite->callback = SpriteCB_ShrubEntranceOpen;
}

static void SpriteCB_ShrubEntranceOpen(struct Sprite *sprite)
{
    if (sprite->data[0] < 40)
    {
        if (++sprite->data[0] == 20)
            ToggleSecretBaseEntranceMetatile();
    }
    else
    {
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_ShrubEntranceEnd;
    }
}

static void SpriteCB_ShrubEntranceEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_SHRUB);
    ScriptContext_Enable();
}

#define tX     data[0]
#define tY     data[1]
#define tState data[2]

static void Task_SecretBasePCTurnOn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 4:
    case 12:
        MapGridSetMetatileIdAt(tX, tY, METATILE_HoennSecretBase_PC_On);
        CurrentMapDrawMetatileAt(tX, tY);
        break;
    case 8:
    case 16:
        MapGridSetMetatileIdAt(tX, tY, METATILE_HoennSecretBase_PC);
        CurrentMapDrawMetatileAt(tX, tY);
        break;
    case 20:
        MapGridSetMetatileIdAt(tX, tY, METATILE_HoennSecretBase_PC_On);
        CurrentMapDrawMetatileAt(tX, tY);
        FieldEffectActiveListRemove(FLDEFF_PCTURN_ON);
        ScriptContext_Enable();
        DestroyTask(taskId);
        return;
    }
    tState++;
}

bool8 FldEff_SecretBasePCTurnOn(void)
{
    s16 x, y;
    u8 taskId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    taskId = CreateTask(Task_SecretBasePCTurnOn, 0);
    gTasks[taskId].tX = x;
    gTasks[taskId].tY = y;
    gTasks[taskId].tState = 0;
    return FALSE;
}

#undef tX
#undef tY
#undef tState

void DoSecretBasePCTurnOffEffect(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    PlaySE(SE_PC_OFF);
    MapGridSetMetatileIdAt(x, y, METATILE_HoennSecretBase_PC | MAPGRID_IMPASSABLE);
    CurrentMapDrawMetatileAt(x, y);
}

// --- The decorations' effects (Emerald's fldeff_misc.c): balloons, breakable door, note mats, glitter mat, sand
// ornament, shields and toy TVs

static void DoBalloonSoundEffect(s16 metatileId)
{
    switch (metatileId)
    {
    case METATILE_HoennSecretBase_RedBalloon:
        PlaySE(SE_BALLOON_RED);
        break;
    case METATILE_HoennSecretBase_BlueBalloon:
        PlaySE(SE_BALLOON_BLUE);
        break;
    case METATILE_HoennSecretBase_YellowBalloon:
        PlaySE(SE_BALLOON_YELLOW);
        break;
    case METATILE_HoennSecretBase_MudBall:
        PlaySE(SE_MUD_BALL);
        break;
    }
}

// The balloon's next 3 metatiles: popping, popped
static void Task_PopSecretBaseBalloon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[3] == 6)
        data[3] = 0;
    else
        data[3]++;

    if (data[3] == 0)
    {
        if (data[4] == 2)
            DoBalloonSoundEffect(data[0]);
        MapGridSetMetatileIdAt(data[1], data[2], data[0] + data[4]);
        CurrentMapDrawMetatileAt(data[1], data[2]);
        if (data[4] == 3)
            DestroyTask(taskId);
        else
            data[4]++;
    }
}

void PopSecretBaseBalloon(s16 metatileId, s16 x, s16 y)
{
    u8 taskId = CreateTask(Task_PopSecretBaseBalloon, 0);

    gTasks[taskId].data[0] = metatileId;
    gTasks[taskId].data[1] = x;
    gTasks[taskId].data[2] = y;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = 1;
}

static void DoSecretBaseBreakableDoorEffect(s16 x, s16 y)
{
    PlaySE(SE_BREAKABLE_DOOR);
    MapGridSetMetatileIdAt(x, y, METATILE_HoennSecretBase_BreakableDoor_BottomOpen);
    MapGridSetMetatileIdAt(x, y - 1, METATILE_HoennSecretBase_BreakableDoor_TopOpen);
    CurrentMapDrawMetatileAt(x, y);
    CurrentMapDrawMetatileAt(x, y - 1);
}

static void Task_ShatterSecretBaseBreakableDoor(u8 taskId)
{
    if (gTasks[taskId].data[0] == 7)
    {
        DoSecretBaseBreakableDoorEffect(gTasks[taskId].data[1], gTasks[taskId].data[2]);
        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[0]++;
    }
}

void ShatterSecretBaseBreakableDoor(s16 x, s16 y)
{
    u8 dir = GetPlayerFacingDirection();

    if (dir == DIR_SOUTH)
    {
        DoSecretBaseBreakableDoorEffect(x, y);
    }
    else if (dir == DIR_NORTH)
    {
        u8 taskId = CreateTask(Task_ShatterSecretBaseBreakableDoor, 5);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = x;
        gTasks[taskId].data[2] = y;
    }
}

#define tMetatileID data[0]
static void Task_SecretBaseMusicNoteMatSound(u8 taskId)
{
    if (gTasks[taskId].data[1] == 7)
    {
        switch (gTasks[taskId].tMetatileID)
        {
        case METATILE_HoennSecretBase_NoteMat_C_Low:
            PlaySE(SE_NOTE_C);
            break;
        case METATILE_HoennSecretBase_NoteMat_D:
            PlaySE(SE_NOTE_D);
            break;
        case METATILE_HoennSecretBase_NoteMat_E:
            PlaySE(SE_NOTE_E);
            break;
        case METATILE_HoennSecretBase_NoteMat_F:
            PlaySE(SE_NOTE_F);
            break;
        case METATILE_HoennSecretBase_NoteMat_G:
            PlaySE(SE_NOTE_G);
            break;
        case METATILE_HoennSecretBase_NoteMat_A:
            PlaySE(SE_NOTE_A);
            break;
        case METATILE_HoennSecretBase_NoteMat_B:
            PlaySE(SE_NOTE_B);
            break;
        case METATILE_HoennSecretBase_NoteMat_C_High:
            PlaySE(SE_NOTE_C_HIGH);
            break;
        }
        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[1]++;
    }
}

void PlaySecretBaseMusicNoteMatSound(s16 metatileId)
{
    u8 taskId = CreateTask(Task_SecretBaseMusicNoteMatSound, 5);

    gTasks[taskId].tMetatileID = metatileId;
    gTasks[taskId].data[1] = 0;
}
#undef tMetatileID

// Emerald's gFieldEffectObjectTemplate_Sparkle (FRLG's FLDEFFOBJ_SPARKLE is NULL)
extern const struct OamData gObjectEventBaseOam_16x16;
static const u8 sSparkle_Gfx[] = INCBIN_U8("graphics/field_effects/pics/sparkle.4bpp");

static const struct SpriteFrameImage sPicTable_Sparkle[] =
{
    {sSparkle_Gfx + 0 * 0x80, 0x80},
    {sSparkle_Gfx + 1 * 0x80, 0x80},
    {sSparkle_Gfx + 2 * 0x80, 0x80},
    {sSparkle_Gfx + 3 * 0x80, 0x80},
    {sSparkle_Gfx + 4 * 0x80, 0x80},
    {sSparkle_Gfx + 5 * 0x80, 0x80},
};

static const union AnimCmd sAnim_Sparkle[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_LOOP(0),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_LOOP(3),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_Sparkle[] = { sAnim_Sparkle };

static const struct SpriteTemplate sSpriteTemplate_Sparkle =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_Sparkle,
    .images = sPicTable_Sparkle,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static void SpriteCB_GlitterMatSparkle(struct Sprite *sprite)
{
    sprite->data[0]++;
    if (sprite->data[0] == 8)
        PlaySE(SE_M_HEAL_BELL);
    if (sprite->data[0] >= 32)
        DestroySprite(sprite);
}

void DoSecretBaseGlitterMatSparkle(void)
{
    s16 x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    s16 y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    u8 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 4);
    spriteId = CreateSpriteAtEnd(&sSpriteTemplate_Sparkle, x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].oam.priority = 1;
        gSprites[spriteId].oam.paletteNum = 5;
        gSprites[spriteId].callback = SpriteCB_GlitterMatSparkle;
        gSprites[spriteId].data[0] = 0;
    }
}

// Sand ornament: the player breaks it (FLDEFF_SAND_PILLAR, SecretBase_EventScript_SandOrnament)
static void SpriteCB_SandPillar_BreakTop(struct Sprite *sprite);
static void SpriteCB_SandPillar_BreakBase(struct Sprite *sprite);
static void SpriteCB_SandPillar_End(struct Sprite *sprite);

static const u8 sSandPillar0_Gfx[] = INCBIN_U8("graphics/field_effects/pics/sand_pillar/0.4bpp");
static const u8 sSandPillar1_Gfx[] = INCBIN_U8("graphics/field_effects/pics/sand_pillar/1.4bpp");
static const u8 sSandPillar2_Gfx[] = INCBIN_U8("graphics/field_effects/pics/sand_pillar/2.4bpp");

static const struct OamData sOam_SandPillar =
{
    .x = 0,
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 2,
};

static const union AnimCmd sAnim_SandPillar[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_SandPillar[] = { sAnim_SandPillar };

static const struct SpriteFrameImage sPicTable_SandPillar[] =
{
    {sSandPillar0_Gfx, sizeof(sSandPillar0_Gfx)},
    {sSandPillar1_Gfx, sizeof(sSandPillar1_Gfx)},
    {sSandPillar2_Gfx, sizeof(sSandPillar2_Gfx)},
};

static const struct SpriteTemplate sSpriteTemplate_SandPillar =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SAND_PILLAR,
    .oam = &sOam_SandPillar,
    .anims = sAnimTable_SandPillar,
    .images = sPicTable_SandPillar,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SandPillar_BreakTop,
};

extern const u16 gTilesetPalettes_HoennSecretBase[][16];
const struct SpritePalette gSpritePalette_SandPillar = {gTilesetPalettes_HoennSecretBase[5], FLDEFF_PAL_TAG_SAND_PILLAR};

bool8 FldEff_SandPillar(void)
{
    s16 x, y;

    LockPlayerFieldControls();
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    gFieldEffectArguments[5] = x;
    gFieldEffectArguments[6] = y;
    switch (GetPlayerFacingDirection())
    {
    case DIR_SOUTH:
        CreateSprite(&sSpriteTemplate_SandPillar, gSprites[gPlayerAvatar.spriteId].oam.x + 8, gSprites[gPlayerAvatar.spriteId].oam.y + 32, 0);
        break;
    case DIR_NORTH:
        CreateSprite(&sSpriteTemplate_SandPillar, gSprites[gPlayerAvatar.spriteId].oam.x + 8, gSprites[gPlayerAvatar.spriteId].oam.y, 148);
        break;
    case DIR_WEST:
        CreateSprite(&sSpriteTemplate_SandPillar, gSprites[gPlayerAvatar.spriteId].oam.x - 8, gSprites[gPlayerAvatar.spriteId].oam.y + 16, 148);
        break;
    case DIR_EAST:
        CreateSprite(&sSpriteTemplate_SandPillar, gSprites[gPlayerAvatar.spriteId].oam.x + 24, gSprites[gPlayerAvatar.spriteId].oam.y + 16, 148);
        break;
    }
    return FALSE;
}

static void SpriteCB_SandPillar_BreakTop(struct Sprite *sprite)
{
    PlaySE(SE_M_ROCK_THROW);
    if (MapGridGetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1) == METATILE_HoennSecretBase_SandOrnament_TopWall)
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, METATILE_HoennSecretBase_Wall_TopMid | MAPGRID_IMPASSABLE);
    else
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, METATILE_HoennSecretBase_SandOrnament_BrokenTop);
    MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], METATILE_HoennSecretBase_Ground);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);
    sprite->data[0] = 0;
    sprite->callback = SpriteCB_SandPillar_BreakBase;
}

static void SpriteCB_SandPillar_BreakBase(struct Sprite *sprite)
{
    if (sprite->data[0] < 18)
    {
        sprite->data[0]++;
    }
    else
    {
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], METATILE_HoennSecretBase_SandOrnament_BrokenBase | MAPGRID_IMPASSABLE);
        CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_SandPillar_End;
    }
}

static void SpriteCB_SandPillar_End(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SAND_PILLAR);
    ScriptContext_Enable();
}

// SecretBase_EventScript_ShieldOrToyTV: gSpecialVar_Result 0 shield (STR_VAR_1 wins, STR_VAR_2 metal), 1-3 a TV.
// Emerald's also records it for the TV when in another player's base: no other bases here.
void InteractWithShieldOrTVDecoration(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch (MapGridGetMetatileIdAt(x, y))
    {
    case METATILE_HoennSecretBase_GoldShield_Base1:
        ConvertIntToDecimalStringN(gStringVar1, 100, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringCopy(gStringVar2, gText_Gold);
        gSpecialVar_Result = 0;
        break;
    case METATILE_HoennSecretBase_SilverShield_Base1:
        ConvertIntToDecimalStringN(gStringVar1, 50, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringCopy(gStringVar2, gText_Silver);
        gSpecialVar_Result = 0;
        break;
    case METATILE_HoennSecretBase_TV:
        gSpecialVar_Result = 1;
        break;
    case METATILE_HoennSecretBase_RoundTV:
        gSpecialVar_Result = 2;
        break;
    case METATILE_HoennSecretBase_CuteTV:
        gSpecialVar_Result = 3;
        break;
    }
}

// The sand ornament's and the breakable door's halves (Emerald: fieldmap.c LoadSavedMapView never restores a half).
// As opposed to a small one (single metatile) like the balloons
bool8 IsLargeBreakableDecoration(u16 metatileId, bool8 checkBase)
{
    if (!CurMapIsSecretBase())
        return FALSE;
    if (!checkBase)
        return metatileId == METATILE_HoennSecretBase_SandOrnament_Top || metatileId == METATILE_HoennSecretBase_SandOrnament_TopWall
            || metatileId == METATILE_HoennSecretBase_BreakableDoor_TopClosed;
    return metatileId == METATILE_HoennSecretBase_SandOrnament_Base1 || metatileId == METATILE_HoennSecretBase_BreakableDoor_BottomClosed;
}
