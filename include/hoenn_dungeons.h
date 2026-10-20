#ifndef GUARD_HOENN_DUNGEONS_H
#define GUARD_HOENN_DUNGEONS_H

bool8 ShouldDoBrailleDigEffect(void);
void DoBrailleDigEffect(void);
bool8 ShouldDoBrailleRegirockEffect(void);
bool8 ShouldDoBrailleRegisteelEffect(void);
void FieldCallback_UseTombPuzzle(void);
bool8 ShouldDoBrailleRegicePuzzle(void);
bool8 AbnormalWeatherHasExpired(void);
void CreateAbnormalWeatherEvent(void);

#endif // GUARD_HOENN_DUNGEONS_H
