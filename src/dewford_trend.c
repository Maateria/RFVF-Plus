#include "global.h"
#include "dewford_trend.h"
#include "easy_chat.h"
#include "event_data.h"
#include "random.h"
#include "string_util.h"
#include "constants/easy_chat.h"

// RFVF+: Emerald's Dewford trend (dewford_trend.c) without record mixing nor the TV. SAVED_TRENDS_COUNT phrases (4, 5
// in Emerald: the save block only had room for 4), sorted from the trendiest; [0] is Dewford's trendy phrase and its
// rand seeds the Route 119 Feebas spots (wild_encounter.c). Trendiness moves once a day (1,000 steps here).
// Older saves never wrote dewfordTrends: FLAG_DEWFORD_TRENDS_READY makes the first use initialize them.

static EWRAM_DATA u16 sInputPhrase[2] = {};

// Emerald's SORT_MODE_NORMAL (the others served record mixing)
static bool8 CompareTrends(struct DewfordTrend *a, struct DewfordTrend *b)
{
    if (a->trendiness != b->trendiness)
        return a->trendiness > b->trendiness;
    if (a->maxTrendiness != b->maxTrendiness)
        return a->maxTrendiness > b->maxTrendiness;
    return Random() & 1;
}

static void SortTrends(struct DewfordTrend *trends)
{
    u16 i, j;
    struct DewfordTrend temp;

    for (i = 0; i < SAVED_TRENDS_COUNT; i++)
    {
        for (j = i + 1; j < SAVED_TRENDS_COUNT; j++)
        {
            if (CompareTrends(&trends[j], &trends[i]))
                SWAP(trends[j], trends[i], temp);
        }
    }
}

static void SeedTrendRng(struct DewfordTrend *trend)
{
    u16 rand = Random() % 98;

    if (rand > 50)
    {
        rand = Random() % 98;
        if (rand > 80)
            rand = Random() % 98;
    }
    trend->maxTrendiness = rand + 30;
    trend->trendiness = (Random() % (rand + 1)) + 30;
    trend->rand = Random();
}

static struct DewfordTrend *GetTrends(void)
{
    u16 i;
    struct DewfordTrend *trends = gSaveBlock1Ptr->dewfordTrends;

    if (!FlagGet(FLAG_DEWFORD_TRENDS_READY))
    {
        FlagSet(FLAG_DEWFORD_TRENDS_READY);
        for (i = 0; i < SAVED_TRENDS_COUNT; i++)
        {
            trends[i].words[0] = GetRandomEasyChatWordFromGroup(EC_GROUP_CONDITIONS);
            trends[i].words[1] = GetRandomEasyChatWordFromGroup((Random() & 1) ? EC_GROUP_LIFESTYLE : EC_GROUP_HOBBIES);
            trends[i].gainingTrendiness = Random() & 1;
            SeedTrendRng(&trends[i]);
        }
        SortTrends(trends);
    }
    return trends;
}

void UpdateDewfordTrendPerDay(u16 days)
{
    u16 i;
    struct DewfordTrend *trends = GetTrends();

    if (days == 0)
        return;
    for (i = 0; i < SAVED_TRENDS_COUNT; i++)
    {
        u32 trendiness;
        u32 rand = days * 5;
        struct DewfordTrend *trend = &trends[i];

        if (!trend->gainingTrendiness)
        {
            if (trend->trendiness >= (u16)rand)
            {
                trend->trendiness -= rand;
                if (trend->trendiness == 0)
                    trend->gainingTrendiness = TRUE;
                continue;
            }
            rand -= trend->trendiness;
            trend->trendiness = 0;
            trend->gainingTrendiness = TRUE;
        }
        trendiness = trend->trendiness + rand;
        if ((u16)trendiness > trend->maxTrendiness)
        {
            u32 newTrendiness = trendiness % trend->maxTrendiness;
            trend->gainingTrendiness = (trendiness / trend->maxTrendiness) ^ 1;
            if (trend->gainingTrendiness)
                trend->trendiness = newTrendiness;
            else
                trend->trendiness = trend->maxTrendiness - newTrendiness;
        }
        else
        {
            trend->trendiness = trendiness;
            if (trend->trendiness == trend->maxTrendiness)
                trend->gainingTrendiness = FALSE;
        }
    }
    SortTrends(trends);
}

// TRUE if the phrase became Dewford's trendy phrase
static bool8 TrySetTrendyPhrase(u16 *phrase)
{
    struct DewfordTrend trend = {0};
    struct DewfordTrend *trends = GetTrends();
    u16 i, j;

    for (i = 0; i < SAVED_TRENDS_COUNT; i++)
    {
        if (trends[i].words[0] == phrase[0] && trends[i].words[1] == phrase[1])
            return FALSE;
    }
    if (!FlagGet(FLAG_SYS_CHANGED_DEWFORD_TREND))
    {
        // the first phrase the player gives replaces the initial random one
        FlagSet(FLAG_SYS_CHANGED_DEWFORD_TREND);
        trends[0].words[0] = phrase[0];
        trends[0].words[1] = phrase[1];
        return TRUE;
    }
    trend.words[0] = phrase[0];
    trend.words[1] = phrase[1];
    trend.gainingTrendiness = TRUE;
    SeedTrendRng(&trend);
    for (i = 0; i < SAVED_TRENDS_COUNT; i++)
    {
        if (CompareTrends(&trend, &trends[i]))
        {
            for (j = SAVED_TRENDS_COUNT - 1; j > i; j--)
                trends[j] = trends[j - 1];
            trends[i] = trend;
            return i == 0;
        }
    }
    trends[SAVED_TRENDS_COUNT - 1] = trend;
    return FALSE;
}

// The words EASY_CHAT_TYPE_TRENDY_PHRASE edits: a copy of the trendy phrase
u16 *InitTrendyPhraseInput(void)
{
    sInputPhrase[0] = GetTrends()[0].words[0];
    sInputPhrase[1] = GetTrends()[0].words[1];
    return sInputPhrase;
}

// After the easy chat screen: STR_VAR_2 = the phrase given, gSpecialVar_0x8004 = whether it is the new trend
void SubmitTrendyPhraseInput(void)
{
    ConvertEasyChatWordsToString(gStringVar2, sInputPhrase, 2, 1);
    gSpecialVar_0x8004 = TrySetTrendyPhrase(sInputPhrase);
}

void BufferTrendyPhraseString(void)
{
    ConvertEasyChatWordsToString(gStringVar1, GetTrends()[gSpecialVar_0x8004].words, 2, 1);
}

void IsTrendyPhraseBoring(void)
{
    struct DewfordTrend *trends = GetTrends();

    gSpecialVar_Result = trends[0].trendiness - trends[1].trendiness <= 1
                      && !trends[0].gainingTrendiness
                      && trends[1].gainingTrendiness;
}

void GetDewfordHallPaintingNameIndex(void)
{
    struct DewfordTrend *trends = GetTrends();

    gSpecialVar_Result = (trends[0].words[0] + trends[0].words[1]) & 7;
}

u16 GetDewfordTrendRand(void)
{
    return GetTrends()[0].rand;
}
