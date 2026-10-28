#ifndef GUARD_SECRET_BASE_H
#define GUARD_SECRET_BASE_H

// RFVF+: Emerald's (src/secret_base.c)
void ClearSecretBases(void);
void TrySetCurSecretBaseIndex(void);
void CheckPlayerHasSecretBase(void);
void GetSecretBaseTypeInFrontOfPlayer(void);
void ToggleSecretBaseEntranceMetatile(void);
void SetPlayerSecretBase(void);
void SetOccupiedSecretBaseEntranceMetatiles(const struct MapEvents *events);
void EnterSecretBase(void);
bool8 SecretBaseMapPopupEnabled(void);
void EnterNewlyCreatedSecretBase(void);
bool8 CurMapIsSecretBase(void);
void InitSecretBaseAppearance(bool8 hidePC);
void SetCurSecretBaseIdFromPosition(const struct MapPosition *position, const struct MapEvents *events);
void WarpIntoSecretBase(const struct MapPosition *position, const struct MapEvents *events);
bool8 TrySetCurSecretBase(void);
u8 *GetSecretBaseMapName(u8 *dest);
void GetSecretBaseNearbyMapName(void);
void ClearAndLeaveSecretBase(void);
void MoveOutOfSecretBase(void);
void MoveOutOfSecretBaseFromOutside(void);
void ShowSecretBaseDecorationMenu(void);
bool8 UsesDecorationObjects(void);
u8 GetDecorationSpotBehaviorAt(s16 x, s16 y);
void InitSecretBaseDecorationSprites(void);
void HideSecretBaseDecorationSprites(void);
void SecretBasePerStepCallback(u8 taskId);

#endif // GUARD_SECRET_BASE_H
