#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "platform/types.h"
#include <stdbool.h>

#include "engine/board.h"

#define SCREEN_BASE_BLOCK   28
#define SCREEN_BORDER_BLOCK 29
#define SCREEN_INFO_BLOCK   30

#define CURSOR_SPRITE_INDEX 0

void init_renderer(void);
void close_renderer(void);

/**
 * @brief Display new_type sprite on the screen at specified location
 */
void display_square(int x, int y, enum BOARD_TYPE new_type);

/**
 * @brief Check if a square has already been revealed
 */
bool is_revealed(int x, int y);

/**
 * @brief Check if a square is a flag
 */
bool is_flagged(int x, int y);

/**
 * @brief Display a flag on the screen
 */
void display_flag_square(int x, int y, bool put_flag);

/**
 * @brief Change the cursor's sprite to the location (screen coords)
 *
 * The sprite index is defined by CURSOR_SPRITE_INDEX
 * X & Y are usually bitshifted to the left 3 times
 */
void set_cursor_position(s16 x, s16 y);

#endif
