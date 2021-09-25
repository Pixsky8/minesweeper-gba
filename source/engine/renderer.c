#include "engine/board.h"
#include "global.h"
#include "platform/video.h"
#include "engine/renderer.h"
#include "tools/basic_matrix.h"

#define BG_REVEALED       2
#define NUMBER_SPRITE_OFFSET 16
#define FLAG_TILE_ID 24

void reveal_square(int x, int y, enum BOARD_TYPE new_type) {
    unsigned int bg_id = x + y * MAX_SQUARE_SIDE;
    unsigned int bg_tile = NUMBER_SPRITE_OFFSET + (new_type - 1);

    SE_MEM[SCREEN_BASE_BLOCK][bg_id] = BG_REVEALED;
    SE_MEM[SCREEN_INFO_BLOCK][bg_id] = bg_tile;
}

void flag_square(int x, int y, bool put_flag) {
    unsigned int bg_id = x + y * MAX_SQUARE_SIDE;

    if (put_flag)
        SE_MEM[SCREEN_INFO_BLOCK][bg_id] = FLAG_TILE_ID;
    else
        SE_MEM[SCREEN_INFO_BLOCK][bg_id] = 0;
}
