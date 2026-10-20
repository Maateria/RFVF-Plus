#ifndef GUARD_DECORATION_INVENTORY_H
#define GUARD_DECORATION_INVENTORY_H

// RFVF+: Emerald's decoration inventory, one array in SaveBlock1 cut by category (no pointers to move with the save block)
u8 *GetDecorationInventory(u8 category, u8 *size);
bool8 CheckHasDecoration(u8 decor);
bool8 DecorationAdd(u8 decor);
bool8 DecorationCheckSpace(u8 decor);
s8 DecorationRemove(u8 decor);
u8 GetNumOwnedDecorationsInCategory(u8 category);

#endif // GUARD_DECORATION_INVENTORY_H
