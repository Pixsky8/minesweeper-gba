#include "engine/board.h"
#include "global.h"
#include "platform/video.h"
#include "tools/basic_matrix.h"

#define SCREEN_BASE_BLOCK 28
#define BG_REVEALED       2

void update_square(int x, int y, enum BOARD_TYPE new_type) {
    unsigned int sprite_id = x + y * game_board_side;
    unsigned int sprite_tile = (new_type - 1) << 1;

    unsigned int bg_tile = BG_REVEALED;
    matrix_ushort_set(&SE_MEM[SCREEN_BASE_BLOCK][0], x, y, 32, bg_tile);

    sprite_set_x(sprite_id, x * 8);
    sprite_set_y(sprite_id, y * 8);
    sprite_change_tile(sprite_id, sprite_tile);
    display_sprite(sprite_id);
}
