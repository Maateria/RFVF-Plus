#ifndef GUARD_BATTLE_UTIL2_H
#define GUARD_BATTLE_UTIL2_H

#include "global.h"

void AllocateBattleResources(void);
void FreeBattleResources(void);
void AdjustFriendshipOnBattleFaint(u8 bank);
u32 BattlePalace_TryEscapeStatus(u8 battler);

#endif // GUARD_BATTLE_UTIL_H
