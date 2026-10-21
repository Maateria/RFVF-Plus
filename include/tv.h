#ifndef GUARD_TV_H
#define GUARD_TV_H

// RFVF+: there is no TV here. The Battle Frontier code (Emerald's) feeds TV shows through these: they do nothing.
#define TryPutFrontierTVShowOnAir(winStreak, facilityAndMode) ((void)0)
#define ShouldAirFrontierTVShow() FALSE
#define TryPutSpotTheCutiesOnAir(mon, ribbon) ((void)0)
#define HideBattleTowerReporter() ((void)0)
#define IncrementDailyBattlePoints(delta) ((void)0)

#define NUM_CUTIES_RIBBONS 4

u8 GetRibbonCount(struct Pokemon *pokemon);

#endif // GUARD_TV_H
