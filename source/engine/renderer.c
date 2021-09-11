#include "engine/board.h"
#include "global.h"
#include "platform/video.h"
#include "tools/basic_matrix.h"

#define SCREEN_BASE_BLOCK 28
#define BG_REVEALED       2

void update_square(int x, int y, enum BOARD_TYPE new_type) {
    unsigned int sprite_id = x + y * game_board_side;
    unsigned int sprite_tile = 2 << (new_type - 1);

    unsigned int bg_tile = BG_REVEALED;
    matrix_short_set(&SE_MEM[SCREEN_BASE_BLOCK][0], x, y, 32, bg_tile);
}
