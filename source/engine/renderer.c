#include "engine/board.h"
#include "global.h"
#include "platform/video.h"
#include "engine/renderer.h"
#include "tools/basic_matrix.h"

#define SCREEN_BASE_BLOCK 28
#define BG_REVEALED       2

#define FLAG_SPRITE_TILE  16

void reveal_square(int x, int y, enum BOARD_TYPE new_type) {
    unsigned int sprite_id = x + y * MAX_SQUARE_SIDE;
    unsigned int sprite_tile = (new_type - 1) << 1;

    unsigned int bg_tile = BG_REVEALED;
    matrix_ushort_set(&SE_MEM[SCREEN_BASE_BLOCK][0], x, y, MAX_SQUARE_SIDE, bg_tile);

    sprite_change_tile(sprite_id, sprite_tile);
    display_sprite(sprite_id);
}

void flag_square(int x, int y, bool put_flag) {
    unsigned int sprite_id = x + y * MAX_SQUARE_SIDE;

    if (put_flag) {
        sprite_change_tile(sprite_id, FLAG_SPRITE_TILE);
        display_sprite(sprite_id);
    }
    else
        hide_sprite(sprite_id);
}
