#ifndef GUARD_HOENN_SPECIALS_H
#define GUARD_HOENN_SPECIALS_H

void HoennDays_OnStep(void);
void HoennBerryGifts_OnTrainerBattleWon(u16 trainerId);
void Bike_TryAdvanceCyclingRoadCollisions(void);
bool32 CountSSTidalStep(u16 delta);
u8 GetSSTidalLocation(s8 *mapGroup, s8 *mapNum, s16 *x, s16 *y);

#endif // GUARD_HOENN_SPECIALS_H
