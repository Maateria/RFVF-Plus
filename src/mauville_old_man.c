#include "global.h"
#include "gflib.h"
#include "bard_music.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "easy_chat.h"
#include "event_data.h"
#include "field_message_box.h"
#include "mauville_old_man.h"
#include "m4a.h"
#include "menu.h"
#include "new_menu_helpers.h"
#include "overworld.h"
#include "random.h"
#include "sound.h"
#include "script.h"
#include "strings.h"
#include "task.h"
#include "constants/decorations.h"
#include "constants/easy_chat.h"
#include "constants/game_stat.h"
#include "constants/songs.h"

// RFVF+: Emerald's Mauville old man (mauville_old_man.c, trader.c) in Mauville's Pokémon Center. Emerald keeps one of
// the five for a whole game (the trainer ID's last digit) and only record mixing changes him; here a different one
// comes every day (1,000 steps, user's choice 2026-10-19), with his data reset (VAR_MAUVILLE_OLD_MAN_DAY).
// No record mixing, so no language fixes. Texts: official French Emerald.

// French Emerald's default song (the English one is SHAKE IT DO / THE DIET DANCE)
static const u16 sDefaultBardSongLyrics[NUM_BARD_SONG_WORDS] = {
    EC_WORD_FEELING, EC_WORD_DIET, EC_WORD_IT_S, EC_WORD_UNDEFINED, EC_WORD_COOL, EC_WORD_UNDEFINED
};

static const u8 *const sGiddyAdjectives[] = {
    GiddyText_SoPretty, GiddyText_SoDarling, GiddyText_SoRelaxed, GiddyText_SoSunny,
    GiddyText_SoDesirable, GiddyText_SoExciting, GiddyText_SoAmusing, GiddyText_SoMagical
};

// Non-random lines Giddy can say (the player gets a Yes/No prompt after each)
static const u8 *const sGiddyQuestions[GIDDY_MAX_QUESTIONS] = {
    GiddyText_ISoWantToGoOnAVacation, GiddyText_IBoughtCrayonsWith120Colors, GiddyText_WouldntItBeNiceIfWeCouldFloat,
    GiddyText_WhenYouWriteOnASandyBeach, GiddyText_WhatsTheBottomOfTheSeaLike, GiddyText_WhenYouSeeTheSettingSunDoesIt,
    GiddyText_LyingBackInTheGreenGrass, GiddyText_SecretBasesAreSoWonderful
};

// French Emerald's trader names (gText_Tristan, gText_Philip, gText_Dennis, gText_Roberto)
static const u8 sText_Tristan[] = _("FRANCK");
static const u8 sText_Philip[] = _("AYMERIC");
static const u8 sText_Dennis[] = _("GILLES");
static const u8 sText_Roberto[] = _("ROBERTO");
static const u8 sText_FiveMarks[] = _("?????");
static const u8 *const sDefaultTraderNames[NUM_TRADER_ITEMS] = {sText_Tristan, sText_Philip, sText_Dennis, sText_Roberto};
static const u8 sDefaultTraderDecorations[NUM_TRADER_ITEMS] = {
    DECOR_DUSKULL_DOLL, DECOR_BALL_CUSHION, DECOR_TIRE, DECOR_PRETTY_FLOWERS
};

static EWRAM_DATA struct BardSong sBardSong = {0};
static EWRAM_DATA u8 sSelectedStory = 0;
static EWRAM_DATA u8 sStorytellerWindowId = 0;

#define sStoryteller (&gSaveBlock1Ptr->oldMan.storyteller)

static void SetupBard(void)
{
    u16 i;
    struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;

    bard->id = MAUVILLE_MAN_BARD;
    bard->hasChangedSong = FALSE;
    bard->language = GAME_LANGUAGE;
    for (i = 0; i < NUM_BARD_SONG_WORDS; i++)
        bard->songLyrics[i] = sDefaultBardSongLyrics[i];
}

static void SetupHipster(void)
{
    struct MauvilleManHipster *hipster = &gSaveBlock1Ptr->oldMan.hipster;

    hipster->id = MAUVILLE_MAN_HIPSTER;
    hipster->taughtWord = FALSE;
    hipster->language = GAME_LANGUAGE;
}

static void SetupTrader(void)
{
    u8 i;
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;

    trader->id = MAUVILLE_MAN_TRADER;
    trader->alreadyTraded = FALSE;
    for (i = 0; i < NUM_TRADER_ITEMS; i++)
    {
        StringCopy(trader->playerNames[i], sDefaultTraderNames[i]);
        trader->decorations[i] = sDefaultTraderDecorations[i];
        trader->language[i] = GAME_LANGUAGE;
    }
}

static void SetupStoryteller(void)
{
    sStoryteller->id = MAUVILLE_MAN_STORYTELLER;
}

static void SetupGiddy(void)
{
    struct MauvilleManGiddy *giddy = &gSaveBlock1Ptr->oldMan.giddy;

    giddy->id = MAUVILLE_MAN_GIDDY;
    giddy->taleCounter = 0;
    giddy->language = GAME_LANGUAGE;
}

static void (*const sSetupFuncs[])(void) = {
    [MAUVILLE_MAN_BARD] = SetupBard,
    [MAUVILLE_MAN_HIPSTER] = SetupHipster,
    [MAUVILLE_MAN_TRADER] = SetupTrader,
    [MAUVILLE_MAN_STORYTELLER] = SetupStoryteller,
    [MAUVILLE_MAN_GIDDY] = SetupGiddy,
};

// Today's old man, set up afresh on his first visit of the day
void Script_GetCurrentMauvilleMan(void)
{
    u16 day = VarGet(VAR_HOENN_DAY_COUNT);
    u8 man = day % ARRAY_COUNT(sSetupFuncs);

    if (VarGet(VAR_MAUVILLE_OLD_MAN_DAY) != (u16)(day + 1))
    {
        memset(&gSaveBlock1Ptr->oldMan, 0, sizeof(gSaveBlock1Ptr->oldMan));
        sSetupFuncs[man]();
        VarSet(VAR_MAUVILLE_OLD_MAN_DAY, day + 1);
    }
    gSpecialVar_Result = man;
}

// ---------------------------------------------------------------- the bard

void HasBardSongBeenChanged(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->oldMan.bard.hasChangedSong;
}

void SaveBardSongLyrics(void)
{
    u16 i;
    struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;

    StringCopy(bard->playerName, gSaveBlock2Ptr->playerName);
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        bard->playerTrainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];
    for (i = 0; i < NUM_BARD_SONG_WORDS; i++)
        bard->songLyrics[i] = bard->newSongLyrics[i];
    bard->hasChangedSong = TRUE;
}

// The words EASY_CHAT_TYPE_BARD_SONG edits: a copy of the current song
u16 *InitBardSongInput(void)
{
    u16 i;
    struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;

    for (i = 0; i < NUM_BARD_SONG_WORDS; i++)
        bard->newSongLyrics[i] = bard->songLyrics[i];
    return bard->newSongLyrics;
}

// The lyrics into gStringVar4, 2 paragraphs of 3 words (2 on the first line, 1 on the second); the spaces inside an
// easy chat word become CHAR_BARD_WORD_DELIMIT so the song knows where each word ends.
// gSpecialVar_0x8004: 0 = his current song, else the one the player wrote.
static void PrepareSongText(void)
{
    struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;
    u16 *lyrics = !gSpecialVar_0x8004 ? bard->songLyrics : bard->newSongLyrics;
    u8 *wordEnd = gStringVar4;
    u8 *str = wordEnd;
    u16 paragraphNum, word;

    for (paragraphNum = 0; paragraphNum < 2; paragraphNum++)
    {
        for (word = 0; word < 3; word++)
        {
            wordEnd = CopyEasyChatWord(wordEnd, *(lyrics++));
            while (wordEnd != str)
            {
                if (*str == CHAR_SPACE)
                    *str = CHAR_BARD_WORD_DELIMIT;
                str++;
            }
            if (word == 2)
                break;
            str++;
            *(wordEnd++) = word == 0 ? CHAR_SPACE : CHAR_NEWLINE;
        }
        if (paragraphNum == 0)
        {
            // erase the 1st paragraph for the 2nd
            *(wordEnd++) = EXT_CTRL_CODE_BEGIN;
            *(wordEnd++) = EXT_CTRL_CODE_FILL_WINDOW;
        }
    }
}

enum {
    BARD_STATE_INIT,
    BARD_STATE_WAIT_BGM,
    BARD_STATE_GET_WORD,
    BARD_STATE_HANDLE_WORD,
    BARD_STATE_WAIT_WORD,
    BARD_STATE_PAUSE,
};

#define tState              data[0]
#define tWordState          data[1]
#define tDelay              data[2]
#define tCharIndex          data[3]
#define tLyricsIndex        data[4]

// A value 0-4 (a pitch table) from an easy chat word, arbitrary
// Emerald's MOD: % by a power of 2 is a mask
#define WORD_TO_PITCH_TABLE_INDEX(a) (((a) & (NUM_BARD_PITCH_TABLES_PER_SIZE - 2)) + (((a) >> 3) & 1))

static void DisableTextPrinters(struct TextPrinterTemplate *printer, u16 renderCmd)
{
    gDisableTextPrinters = TRUE;
}

static void DrawSongTextWindow(const u8 *str)
{
    DrawDialogueFrame(0, FALSE);
    AddTextPrinterParameterized(0, FONT_NORMAL, str, 0, 1, 1, DisableTextPrinters);
    gDisableTextPrinters = TRUE;
    CopyWindowToVram(0, COPYWIN_FULL);
}

#define BARD_SONG_BASE_VOLUME 0x100
#define BARD_SONG_BASE_PITCH  0x200

enum {
    SOUND_STATE_START,
    SOUND_STATE_PLAY,
    SOUND_STATE_SET_BASE,
    SOUND_STATE_END,
    SOUND_STATE_WAIT,
};

// One frame of singing; Task_BardSong changes the states
static void BardSing(struct Task *task, struct BardSong *song)
{
    switch (task->tState)
    {
    case BARD_STATE_INIT:
    {
        struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;
        u16 *lyrics = !gSpecialVar_0x8004 ? bard->songLyrics : bard->newSongLyrics;
        s32 i;

        for (i = 0; i < NUM_BARD_SONG_WORDS; i++)
            song->lyrics[i] = lyrics[i];
        song->lyricsIndex = 0;
        break;
    }
    case BARD_STATE_GET_WORD:
    {
        u16 easyChatWord = song->lyrics[song->lyricsIndex];

        song->soundTemplates = GetWordSoundTemplates(easyChatWord);
        CalcWordSounds(song, WORD_TO_PITCH_TABLE_INDEX(easyChatWord));
        song->lyricsIndex++;
        if (song->soundTemplates[0].songId != PHONEME_ID_NONE)
        {
            song->state = SOUND_STATE_START;
        }
        else
        {
            song->state = SOUND_STATE_END;
            song->timer = 2;
        }
        break;
    }
    case BARD_STATE_HANDLE_WORD:
    case BARD_STATE_WAIT_WORD:
    {
        const struct BardSoundTemplate *template = &song->soundTemplates[song->soundIndex];

        switch (song->state)
        {
        case SOUND_STATE_START:
            song->timer = song->sounds[song->soundIndex].length;
            // only the PH_*_HELD song of each phoneme triplet plays; the others only change the length
            if (template->songId < NUM_PHONEME_SONGS)
                m4aSongNumStart((FIRST_PHONEME_SONG + 1) + (template->songId / 3) * 3);
            song->state = SOUND_STATE_SET_BASE;
            song->timer--;
            break;
        case SOUND_STATE_SET_BASE:
            song->state = SOUND_STATE_PLAY;
            if (template->songId < NUM_PHONEME_SONGS)
            {
                song->volume = BARD_SONG_BASE_VOLUME + template->volume * 16;
                m4aMPlayVolumeControl(&gMPlayInfo_SE2, TRACKS_ALL, song->volume);
                song->pitch = BARD_SONG_BASE_PITCH + song->sounds[song->soundIndex].pitch;
                m4aMPlayPitchControl(&gMPlayInfo_SE2, TRACKS_ALL, song->pitch);
            }
            break;
        case SOUND_STATE_PLAY:
            // a little vibrato
            if (song->voiceInflection > 10)
                song->volume -= 2;
            if (song->voiceInflection & 1)
                song->pitch += 64;
            else
                song->pitch -= 64;
            m4aMPlayVolumeControl(&gMPlayInfo_SE2, TRACKS_ALL, song->volume);
            m4aMPlayPitchControl(&gMPlayInfo_SE2, TRACKS_ALL, song->pitch);
            song->voiceInflection++;
            if (--song->timer == 0)
            {
                if (++song->soundIndex != MAX_BARD_SOUNDS_PER_WORD && song->soundTemplates[song->soundIndex].songId != PHONEME_ID_NONE)
                {
                    song->state = SOUND_STATE_START;
                }
                else
                {
                    song->state = SOUND_STATE_END;
                    song->timer = 2;
                }
            }
            break;
        case SOUND_STATE_END:
            if (--song->timer == 0)
            {
                m4aMPlayStop(&gMPlayInfo_SE2);
                song->state = SOUND_STATE_WAIT;
            }
            break;
        }
        break;
    }
    }
}

static void Task_BardSong(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    BardSing(task, &sBardSong);
    switch (task->tState)
    {
    case BARD_STATE_INIT:
        PrepareSongText();
        DrawSongTextWindow(gStringVar4);
        task->tWordState = 0;
        task->tDelay = 0;
        task->tCharIndex = 0;
        task->tLyricsIndex = 0;
        FadeOutBGMTemporarily(4);
        task->tState = BARD_STATE_WAIT_BGM;
        break;
    case BARD_STATE_WAIT_BGM:
        if (IsBGMPausedOrStopped())
            task->tState = BARD_STATE_GET_WORD;
        break;
    case BARD_STATE_GET_WORD:
    {
        u8 *str = &gStringVar4[task->tCharIndex];
        u16 wordLen = 0;

        while (*str != CHAR_SPACE && *str != CHAR_NEWLINE && *str != EXT_CTRL_CODE_BEGIN && *str != EOS)
        {
            str++;
            wordLen++;
        }
        sBardSong.length /= wordLen ? wordLen : 1;
        if (sBardSong.length <= 0)
            sBardSong.length = 1;
        task->tLyricsIndex++;
        task->tState = task->tDelay == 0 ? BARD_STATE_HANDLE_WORD : BARD_STATE_PAUSE;
        task->tWordState = 0;
        break;
    }
    case BARD_STATE_PAUSE:
        if (task->tDelay == 0)
            task->tState = BARD_STATE_HANDLE_WORD;
        else
            task->tDelay--;
        break;
    case BARD_STATE_HANDLE_WORD:
        if (gStringVar4[task->tCharIndex] == EOS)
        {
            FadeInBGM(6);
            m4aMPlayFadeOutTemporarily(&gMPlayInfo_SE2, 2);
            ScriptContext_Enable();
            DestroyTask(taskId);
        }
        else if (gStringVar4[task->tCharIndex] == CHAR_SPACE)
        {
            gDisableTextPrinters = FALSE;
            task->tCharIndex++;
            task->tState = BARD_STATE_GET_WORD;
            task->tDelay = 0;
        }
        else if (gStringVar4[task->tCharIndex] == CHAR_NEWLINE)
        {
            task->tCharIndex++;
            task->tState = BARD_STATE_GET_WORD;
            task->tDelay = 0;
        }
        else if (gStringVar4[task->tCharIndex] == EXT_CTRL_CODE_BEGIN)
        {
            // the paragraph break: a short pause
            task->tCharIndex += 2;
            task->tState = BARD_STATE_GET_WORD;
            task->tDelay = 8;
        }
        else if (gStringVar4[task->tCharIndex] == CHAR_BARD_WORD_DELIMIT)
        {
            gStringVar4[task->tCharIndex] = CHAR_SPACE;
            gDisableTextPrinters = FALSE;
            task->tCharIndex++;
            task->tDelay = 0;
        }
        else
        {
            switch (task->tWordState)
            {
            case 0:
                gDisableTextPrinters = FALSE;
                task->tWordState++;
                break;
            case 1:
                task->tWordState++;
                break;
            case 2:
                task->tCharIndex++;
                task->tWordState = 0;
                task->tDelay = sBardSong.length;
                task->tState = BARD_STATE_WAIT_WORD;
                break;
            }
        }
        break;
    case BARD_STATE_WAIT_WORD:
        if (--task->tDelay == 0)
            task->tState = BARD_STATE_HANDLE_WORD;
        break;
    }
    RunTextPrinters_CheckPrinter0Active();
}

void PlayBardSong(void)
{
    CreateTask(Task_BardSong, 80);
    ScriptContext_Stop();
}

// ---------------------------------------------------------------- the hipster

void HasHipsterTaughtWord(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->oldMan.hipster.taughtWord;
}

void SetHipsterTaughtWord(void)
{
    gSaveBlock1Ptr->oldMan.hipster.taughtWord = TRUE;
}

void HipsterTryTeachWord(void)
{
    u16 word = UnlockRandomTrendySaying();

    gSpecialVar_Result = word != EC_WORD_UNDEFINED;
    if (gSpecialVar_Result)
        CopyEasyChatWord(gStringVar1, word);
}

// ---------------------------------------------------------------- Giddy

void GiddyShouldTellAnotherTale(void)
{
    struct MauvilleManGiddy *giddy = &gSaveBlock1Ptr->oldMan.giddy;

    if (giddy->taleCounter == GIDDY_MAX_TALES)
    {
        gSpecialVar_Result = FALSE;
        giddy->taleCounter = 0;
    }
    else
    {
        gSpecialVar_Result = TRUE;
    }
}

static void InitGiddyTaleList(void)
{
    struct MauvilleManGiddy *giddy = &gSaveBlock1Ptr->oldMan.giddy;
    u16 wordGroupsAndCount[][2] = {
        {EC_GROUP_POKEMON,   0},
        {EC_GROUP_LIFESTYLE, 0},
        {EC_GROUP_HOBBIES,   0},
        {EC_GROUP_MOVE_1,    0},
        {EC_GROUP_MOVE_2,    0},
        {EC_GROUP_POKEMON_2, 0}
    };
    u16 i, totalWords, temp, var;

    for (i = 0; i < GIDDY_MAX_QUESTIONS; i++)
        giddy->questionList[i] = i;
    for (i = 0; i < GIDDY_MAX_QUESTIONS; i++)
    {
        var = Random() % (i + 1);
        SWAP(giddy->questionList[i], giddy->questionList[var], temp);
    }
    totalWords = 0;
    for (i = 0; i < ARRAY_COUNT(wordGroupsAndCount); i++)
    {
        wordGroupsAndCount[i][1] = EasyChat_GetNumWordsInGroup(wordGroupsAndCount[i][0]);
        totalWords += wordGroupsAndCount[i][1];
    }
    giddy->questionNum = 0;
    temp = 0;
    for (i = 0; i < GIDDY_MAX_TALES; i++)
    {
        var = Random() % 10;
        if (var < 3 && temp < GIDDY_MAX_QUESTIONS)
        {
            // 30%: one of his questions
            giddy->randomWords[i] = EC_WORD_UNDEFINED;
            temp++;
        }
        else
        {
            s16 randWord = Random() % totalWords;
            for (var = 0; var < ARRAY_COUNT(wordGroupsAndCount); var++)
            {
                if ((randWord -= wordGroupsAndCount[var][1]) <= 0)
                    break;
            }
            if (var == ARRAY_COUNT(wordGroupsAndCount))
                var = 0;
            giddy->randomWords[i] = GetRandomWordFromAnyGroup(wordGroupsAndCount[var][0]);
        }
    }
}

// gStringVar4: "{random word} is so {adjective}! Don't you agree?" or one of his questions
void GenerateGiddyLine(void)
{
    struct MauvilleManGiddy *giddy = &gSaveBlock1Ptr->oldMan.giddy;

    if (giddy->taleCounter == 0)
        InitGiddyTaleList();
    if (giddy->randomWords[giddy->taleCounter] != EC_WORD_UNDEFINED)
    {
        u8 *stringPtr = CopyEasyChatWord(gStringVar4, giddy->randomWords[giddy->taleCounter]);
        stringPtr = StringCopy(stringPtr, GiddyText_Is);
        stringPtr = StringCopy(stringPtr, sGiddyAdjectives[Random() % ARRAY_COUNT(sGiddyAdjectives)]);
        StringCopy(stringPtr, GiddyText_DontYouAgree);
    }
    else
    {
        StringCopy(gStringVar4, sGiddyQuestions[giddy->questionList[giddy->questionNum++]]);
    }
    // 10% chance to stop
    if (!(Random() % 10))
        giddy->taleCounter = GIDDY_MAX_TALES;
    else
        giddy->taleCounter++;
    gSpecialVar_Result = TRUE;
}

// ---------------------------------------------------------------- the trader (Emerald's trader.c)

#define tWindowId data[3]

static void Task_HandleGetDecorationMenuInput(u8 taskId)
{
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;
    s8 input = Menu_ProcessInput();
    u8 decor;

    if (input == MENU_NOTHING_CHOSEN)
        return;
    PlaySE(SE_SELECT);
    if (input == MENU_B_PRESSED || input == NUM_TRADER_ITEMS)
    {
        decor = 0;
    }
    else
    {
        gSpecialVar_0x8005 = input;
        StringCopy(gStringVar1, trader->playerNames[input]);
        decor = trader->decorations[input];
    }
    gSpecialVar_0x8004 = decor > NUM_DECORATIONS ? 0xFFFF : decor;
    ClearStdWindowAndFrameToTransparent(gTasks[taskId].tWindowId, FALSE);
    ClearWindowTilemap(gTasks[taskId].tWindowId);
    RemoveWindow(gTasks[taskId].tWindowId);
    ScheduleBgCopyTilemapToVram(0);
    DestroyTask(taskId);
    ScriptContext_Enable();
}

// His four decorations: gSpecialVar_0x8004 = the one picked (0 none, 0xFFFF an empty slot), 0x8005 its slot
void TraderMenuGetDecoration(void)
{
    u8 i, taskId = CreateTask(Task_HandleGetDecorationMenuInput, 0);
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;
    s32 width = GetStringWidth(FONT_NORMAL, gOtherText_Exit, 0);
    struct WindowTemplate template;
    u8 windowId;

    for (i = 0; i < NUM_TRADER_ITEMS; i++)
    {
        s32 curWidth = GetStringWidth(FONT_NORMAL, trader->decorations[i] > NUM_DECORATIONS ? sText_FiveMarks : gDecorations[trader->decorations[i]].name, 0);
        if (curWidth > width)
            width = curWidth;
    }
    template = SetWindowTemplateFields(0, 1, 1, (width + 9) / 8, (NUM_TRADER_ITEMS + 1) * 2, 15, 0x38);
    windowId = gTasks[taskId].tWindowId = AddWindow(&template);
    SetStdWindowBorderStyle(windowId, FALSE);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    for (i = 0; i < NUM_TRADER_ITEMS; i++)
        AddTextPrinterParameterized(windowId, FONT_NORMAL, trader->decorations[i] > NUM_DECORATIONS ? sText_FiveMarks : gDecorations[trader->decorations[i]].name, 8, 16 * i + 1, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gOtherText_Exit, 8, 16 * i + 1, TEXT_SKIP_DRAW, NULL);
    Menu_InitCursor(windowId, FONT_NORMAL, 0, 1, 16, NUM_TRADER_ITEMS + 1, 0);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

void GetTraderTradedFlag(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->oldMan.trader.alreadyTraded;
}

void DoesPlayerHaveNoDecorations(void)
{
    u8 i;

    gSpecialVar_Result = TRUE;
    for (i = 0; i < DECORCAT_COUNT; i++)
    {
        if (GetNumOwnedDecorationsInCategory(i))
            gSpecialVar_Result = FALSE;
    }
}

// TRUE (STR_VAR_2 = its category) if the decoration he gives has no room
void IsDecorationCategoryFull(void)
{
    gSpecialVar_Result = FALSE;
    if (gDecorations[gSpecialVar_0x8004].category != gDecorations[gSpecialVar_0x8006].category
     && !DecorationCheckSpace(gSpecialVar_0x8004))
    {
        CopyDecorationCategoryName(gStringVar2, gDecorations[gSpecialVar_0x8004].category);
        gSpecialVar_Result = TRUE;
    }
}

// The player's decoration to give: gSpecialVar_0x8006 (0 if none)
void TraderShowDecorationMenu(void)
{
    CreateTask(ShowDecorationCategoriesWindow, 0);
}

void TraderDoDecorationTrade(void)
{
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;

    DecorationRemove(gSpecialVar_0x8006);
    DecorationAdd(gSpecialVar_0x8004);
    StringCopy(trader->playerNames[gSpecialVar_0x8005], gSaveBlock2Ptr->playerName);
    trader->decorations[gSpecialVar_0x8005] = gSpecialVar_0x8006;
    trader->language[gSpecialVar_0x8005] = GAME_LANGUAGE;
    trader->alreadyTraded = TRUE;
}

// ---------------------------------------------------------------- the storyteller

struct Story
{
    u8 stat;
    u8 minVal;
    const u8 *title;
    const u8 *action;
    const u8 *fullText;
};

#define STORY(stat, minVal, name) {stat, minVal, MauvilleCity_PokemonCenter_1F_Text_##name##Title, \
    MauvilleCity_PokemonCenter_1F_Text_##name##Action, MauvilleCity_PokemonCenter_1F_Text_##name##Story}

// Emerald's; 50 stands for GAME_STAT_SAVED_GAME (0 marks an empty slot)
static const struct Story sStorytellerStories[] = {
    STORY(50, 1, SavedGame),
    STORY(GAME_STAT_STARTED_TRENDS, 1, TrendsStarted),
    STORY(GAME_STAT_PLANTED_BERRIES, 1, BerriesPlanted),
    STORY(GAME_STAT_TRADED_BIKES, 1, BikeTrades),
    STORY(GAME_STAT_GOT_INTERVIEWED, 1, Interviews),
    STORY(GAME_STAT_TRAINER_BATTLES, 1, TrainerBattles),
    STORY(GAME_STAT_POKEMON_CAPTURES, 1, PokemonCaught),
    STORY(GAME_STAT_FISHING_CAPTURES, 1, FishingPokemonCaught),
    STORY(GAME_STAT_HATCHED_EGGS, 1, EggsHatched),
    STORY(GAME_STAT_EVOLVED_POKEMON, 1, PokemonEvolved),
    STORY(GAME_STAT_USED_POKECENTER, 1, UsedPokemonCenter),
    STORY(GAME_STAT_RESTED_AT_HOME, 1, RestedAtHome),
    STORY(GAME_STAT_ENTERED_SAFARI_ZONE, 1, SafariGames),
    STORY(GAME_STAT_USED_CUT, 1, UsedCut),
    STORY(GAME_STAT_USED_ROCK_SMASH, 1, UsedRockSmash),
    STORY(GAME_STAT_MOVED_SECRET_BASE, 1, MovedBases),
    STORY(GAME_STAT_USED_SPLASH, 1, UsedSplash),
    STORY(GAME_STAT_USED_STRUGGLE, 1, UsedStruggle),
    STORY(GAME_STAT_SLOT_JACKPOTS, 1, SlotJackpots),
    STORY(GAME_STAT_CONSECUTIVE_ROULETTE_WINS, 2, RouletteWins),
    STORY(GAME_STAT_ENTERED_BATTLE_TOWER, 1, BattleTowerChallenges),
    STORY(GAME_STAT_POKEBLOCKS, 1, MadePokeblocks),
    STORY(GAME_STAT_ENTERED_CONTEST, 1, EnteredContests),
    STORY(GAME_STAT_WON_CONTEST, 1, WonContests),
    STORY(GAME_STAT_SHOPPED, 1, TimesShopped),
    STORY(GAME_STAT_USED_ITEMFINDER, 1, UsedItemFinder),
    STORY(GAME_STAT_GOT_RAINED_ON, 1, TimesRained),
    STORY(GAME_STAT_CHECKED_POKEDEX, 1, CheckedPokedex),
    STORY(GAME_STAT_RECEIVED_RIBBONS, 1, ReceivedRibbons),
    STORY(GAME_STAT_JUMPED_DOWN_LEDGES, 1, LedgesJumped),
    STORY(GAME_STAT_WATCHED_TV, 1, TVWatched),
    STORY(GAME_STAT_CHECKED_CLOCK, 1, CheckedClock),
    STORY(GAME_STAT_WON_POKEMON_LOTTERY, 1, WonLottery),
    STORY(GAME_STAT_USED_DAYCARE, 1, UsedDaycare),
    STORY(GAME_STAT_RODE_CABLE_CAR, 1, RodeCableCar),
    STORY(GAME_STAT_ENTERED_HOT_SPRINGS, 1, HotSprings),
};

static u32 StorytellerGetGameStat(u8 stat)
{
    return GetGameStat(stat == 50 ? GAME_STAT_SAVED_GAME : stat);
}

static const struct Story *GetStoryByStat(u32 stat)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sStorytellerStories); i++)
    {
        if (sStorytellerStories[i].stat == stat)
            return &sStorytellerStories[i];
    }
    return &sStorytellerStories[ARRAY_COUNT(sStorytellerStories) - 1];
}

static u8 GetFreeStorySlot(void)
{
    u8 i;

    for (i = 0; i < NUM_STORYTELLER_TALES; i++)
    {
        if (sStoryteller->gameStatIDs[i] == 0)
            break;
    }
    return i;
}

static u32 StorytellerGetRecordedTrainerStat(u32 trainer)
{
    u8 *ptr = sStoryteller->statValues[trainer];

    return ptr[0] | (ptr[1] << 8) | (ptr[2] << 16) | (ptr[3] << 24);
}

static void StorytellerRecordNewStat(u32 player, u32 stat)
{
    u8 *ptr = sStoryteller->statValues[player];
    u32 val = StorytellerGetGameStat(stat);

    sStoryteller->gameStatIDs[player] = stat;
    memset(sStoryteller->trainerNames[player], EOS, PLAYER_NAME_LENGTH);
    memcpy(sStoryteller->trainerNames[player], gSaveBlock2Ptr->playerName, PLAYER_NAME_LENGTH);
    ptr[0] = val;
    ptr[1] = val >> 8;
    ptr[2] = val >> 16;
    ptr[3] = val >> 24;
    ConvertIntToDecimalStringN(gStringVar1, val, STR_CONV_MODE_LEFT_ALIGN, 10);
    StringCopy(gStringVar2, GetStoryByStat(stat)->action);
    sStoryteller->language[player] = GAME_LANGUAGE;
}

// Emerald's: a random stat the player has done, not already a tale
bool8 Script_StorytellerInitializeRandomStat(void)
{
    u8 storyIds[ARRAY_COUNT(sStorytellerStories)];
    s32 i, j;
    u8 temp;

    for (i = 0; i < ARRAY_COUNT(storyIds); i++)
        storyIds[i] = i;
    for (i = 0; i < ARRAY_COUNT(storyIds); i++)
    {
        u32 a = Random() % ARRAY_COUNT(storyIds);
        u32 b = Random() % ARRAY_COUNT(storyIds);
        SWAP(storyIds[a], storyIds[b], temp);
    }
    for (i = 0; i < ARRAY_COUNT(storyIds); i++)
    {
        u8 stat = sStorytellerStories[storyIds[i]].stat;

        for (j = 0; j < NUM_STORYTELLER_TALES; j++)
        {
            if (sStoryteller->gameStatIDs[j] == stat)
                break;
        }
        if (j == NUM_STORYTELLER_TALES && StorytellerGetGameStat(stat) >= sStorytellerStories[storyIds[i]].minVal)
        {
            sStoryteller->alreadyRecorded = TRUE;
            StorytellerRecordNewStat(GetFreeStorySlot() == NUM_STORYTELLER_TALES ? sSelectedStory : GetFreeStorySlot(), stat);
            return TRUE;
        }
    }
    return FALSE;
}

void Script_StorytellerDisplayStory(void)
{
    u8 stat = sStoryteller->gameStatIDs[sSelectedStory];

    ConvertIntToDecimalStringN(gStringVar1, StorytellerGetRecordedTrainerStat(sSelectedStory), STR_CONV_MODE_LEFT_ALIGN, 10);
    StringCopy(gStringVar2, GetStoryByStat(stat)->action);
    memset(gStringVar3, EOS, PLAYER_NAME_LENGTH + 1);
    memcpy(gStringVar3, sStoryteller->trainerNames[sSelectedStory], PLAYER_NAME_LENGTH);
    ShowFieldMessage(GetStoryByStat(stat)->fullText);
}

static void Task_StoryListMenu(u8 taskId)
{
    s8 selection = Menu_ProcessInput();

    if (selection == MENU_NOTHING_CHOSEN)
        return;
    if (selection == MENU_B_PRESSED || selection == GetFreeStorySlot())
    {
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
        sSelectedStory = selection;
    }
    ClearStdWindowAndFrameToTransparent(sStorytellerWindowId, TRUE);
    RemoveWindow(sStorytellerWindowId);
    DestroyTask(taskId);
    ScriptContext_Enable();
}

// gSpecialVar_Result = TRUE if the player picked a tale
void StorytellerStoryListMenu(void)
{
    s32 i, width = GetStringWidth(FONT_NORMAL, gOtherText_Exit, 0);
    struct WindowTemplate template;

    for (i = 0; i < GetFreeStorySlot(); i++)
    {
        s32 curWidth = GetStringWidth(FONT_NORMAL, GetStoryByStat(sStoryteller->gameStatIDs[i])->title, 0);
        if (curWidth > width)
            width = curWidth;
    }
    template = SetWindowTemplateFields(0, 1, 1, (width + 9) / 8, GetFreeStorySlot() * 2 + 2, 15, 0x38);
    sStorytellerWindowId = AddWindow(&template);
    SetStdWindowBorderStyle(sStorytellerWindowId, FALSE);
    FillWindowPixelBuffer(sStorytellerWindowId, PIXEL_FILL(1));
    for (i = 0; i < GetFreeStorySlot(); i++)
        AddTextPrinterParameterized(sStorytellerWindowId, FONT_NORMAL, GetStoryByStat(sStoryteller->gameStatIDs[i])->title, 8, 16 * i + 1, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(sStorytellerWindowId, FONT_NORMAL, gOtherText_Exit, 8, 16 * i + 1, TEXT_SKIP_DRAW, NULL);
    Menu_InitCursor(sStorytellerWindowId, FONT_NORMAL, 0, 1, 16, GetFreeStorySlot() + 1, 0);
    CopyWindowToVram(sStorytellerWindowId, COPYWIN_FULL);
    CreateTask(Task_StoryListMenu, 80);
}

u8 StorytellerGetFreeStorySlot(void)
{
    return GetFreeStorySlot();
}

// TRUE if the player did more of the chosen tale's stat than the recorded trainer
bool8 StorytellerUpdateStat(void)
{
    u8 stat = sStoryteller->gameStatIDs[sSelectedStory];

    if (StorytellerGetGameStat(stat) > StorytellerGetRecordedTrainerStat(sSelectedStory))
    {
        StorytellerRecordNewStat(sSelectedStory, stat);
        return TRUE;
    }
    return FALSE;
}

bool8 HasStorytellerAlreadyRecorded(void)
{
    return sStoryteller->alreadyRecorded;
}
