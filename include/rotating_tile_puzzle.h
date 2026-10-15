#ifndef GUARD_ROTATING_TILE_PUZZLE_H
#define GUARD_ROTATING_TILE_PUZZLE_H

void InitRotatingTilePuzzle(bool8 isTrickHouse);
void FreeRotatingTilePuzzle(void);
u16 MoveRotatingTileObjects(u8 puzzleNumber);
void TurnRotatingTileObjects(void);
void ScriptSetMovingNpcId(u16 localId);

#endif // GUARD_ROTATING_TILE_PUZZLE_H
