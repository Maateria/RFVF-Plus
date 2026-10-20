#include "global.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "constants/decorations.h"

// Emerald's sizes: desks, chairs, plants, ornaments, mats, posters, dolls, cushions
static const u8 sCategoryStart[DECORCAT_COUNT + 1] = {0, 10, 20, 30, 60, 90, 100, 140, DECOR_INVENTORY_SIZE};

u8 *GetDecorationInventory(u8 category, u8 *size)
{
    *size = sCategoryStart[category + 1] - sCategoryStart[category];
    return &gSaveBlock1Ptr->decorations[sCategoryStart[category]];
}

static s8 FindDecorSlot(u8 category, u8 decor)
{
    u8 i, size;
    u8 *items = GetDecorationInventory(category, &size);

    for (i = 0; i < size; i++)
    {
        if (items[i] == decor)
            return i;
    }
    return -1;
}

bool8 CheckHasDecoration(u8 decor)
{
    return decor != DECOR_NONE && FindDecorSlot(gDecorations[decor].category, decor) != -1;
}

bool8 DecorationCheckSpace(u8 decor)
{
    return decor != DECOR_NONE && FindDecorSlot(gDecorations[decor].category, DECOR_NONE) != -1;
}

bool8 DecorationAdd(u8 decor)
{
    u8 size;

    if (!DecorationCheckSpace(decor))
        return FALSE;
    GetDecorationInventory(gDecorations[decor].category, &size)[FindDecorSlot(gDecorations[decor].category, DECOR_NONE)] = decor;
    return TRUE;
}

// Removes one, then sorts the category by id with the empty slots last (Emerald's CondenseDecorationsInCategory)
s8 DecorationRemove(u8 decor)
{
    u8 i, j, tmp, size, category = gDecorations[decor].category;
    u8 *items = GetDecorationInventory(category, &size);
    s8 slot = FindDecorSlot(category, decor);

    if (decor == DECOR_NONE || slot == -1)
        return 0;
    items[slot] = DECOR_NONE;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (items[j] != DECOR_NONE && (items[i] == DECOR_NONE || items[i] > items[j]))
            {
                tmp = items[i];
                items[i] = items[j];
                items[j] = tmp;
            }
        }
    }
    return 1;
}

u8 GetNumOwnedDecorationsInCategory(u8 category)
{
    u8 i, size, count = 0;
    u8 *items = GetDecorationInventory(category, &size);

    for (i = 0; i < size; i++)
    {
        if (items[i] != DECOR_NONE)
            count++;
    }
    return count;
}
