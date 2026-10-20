#ifndef GUARD_DEWFORD_TREND_H
#define GUARD_DEWFORD_TREND_H

void UpdateDewfordTrendPerDay(u16 days);
u16 *InitTrendyPhraseInput(void);
void SubmitTrendyPhraseInput(void);
void BufferTrendyPhraseString(void);
void IsTrendyPhraseBoring(void);
void GetDewfordHallPaintingNameIndex(void);
u16 GetDewfordTrendRand(void);

#endif // GUARD_DEWFORD_TREND_H
