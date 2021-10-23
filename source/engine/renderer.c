#include <string.h>

#include "engine/board.h"
#include "engine/renderer.h"
#include "global.h"
#include "platform/video.h"
#include "tools/basic_matrix.h"
#include "tools/memory.h"

#define BG_REVEALED           2
#define NUMBER_SPRITE_OFFSET  16
#define FLAG_TILE_ID          24
#define CURSOR_SPRITE_TILE_ID 22

void init_renderer(void) {
    obj_buffer[CURSOR_SPRITE_INDEX].attr0 = set_obj_attr0(g_cursor_y,
                                                          ATTR0_NOR,
                                                          ATTR0_GFX_NOR,
                                                          ATTR0_NO_MOSAIC,
                                                          ATTR0_8BPP,
                                                          ATTR0_SQUARE);
    obj_buffer[CURSOR_SPRITE_INDEX].attr1 =
        set_obj_attr1(g_cursor_x, 0, 0, ATTR1_S);
    obj_buffer[CURSOR_SPRITE_INDEX].attr2 =
        set_obj_attr2(CURSOR_SPRITE_TILE_ID, 0, 0);

    // Set background map
    short_memset(&SE_MEM[SCREEN_BASE_BLOCK][0], 1, 1024);

    // Update bg info
    REG_BGCNT[0] = bg_control(2,
                              CHARACTER_BASE_BLOCK,
                              BG_NO_MOSAIC,
                              BG_8BPP,
                              SCREEN_BASE_BLOCK,
                              BG_NO_WRAP,
                              BG_REG_32x32);

    // Square borders
    REG_BGCNT[1] = bg_control(1,
                              CHARACTER_BASE_BLOCK,
                              BG_NO_MOSAIC,
                              BG_8BPP,
                              SCREEN_BORDER_BLOCK,
                              BG_NO_WRAP,
                              BG_REG_32x32);

    // Square information (flag, adj bombs, etc.)
    REG_BGCNT[2] = bg_control(0,
                              CHARACTER_BASE_BLOCK,
                              BG_NO_MOSAIC,
                              BG_8BPP,
                              SCREEN_INFO_BLOCK,
                              BG_NO_WRAP,
                              BG_REG_32x32);
}

void reset_renderer(void) {
    short_memset(&SE_MEM[SCREEN_BASE_BLOCK][0], 1, 1024);
    // Remove every info sprites
    short_memset(&SE_MEM[SCREEN_INFO_BLOCK][0], 0, 1024);
}

void close_renderer(void) {
    hide_sprite(CURSOR_SPRITE_INDEX);
}

void display_square(int x, int y, enum BOARD_TYPE new_type) {
    unsigned int bg_id = x + y * MAX_SQUARE_SIDE;
    unsigned int bg_tile = NUMBER_SPRITE_OFFSET + new_type - 1;

    SE_MEM[SCREEN_BASE_BLOCK][bg_id] = BG_REVEALED;
    SE_MEM[SCREEN_INFO_BLOCK][bg_id] = bg_tile;
}

bool is_revealed(int x, int y) {
    unsigned int bg_id = x + y * MAX_SQUARE_SIDE;

    return SE_MEM[SCREEN_BASE_BLOCK][bg_id] == BG_REVEALED;
}

bool is_flagged(int x, int y) {
    unsigned int bg_id = x + y * MAX_SQUARE_SIDE;

    return SE_MEM[SCREEN_INFO_BLOCK][bg_id] == FLAG_TILE_ID;
}

void display_flag_square(int x, int y, bool put_flag) {
    unsigned int bg_id = x + y * MAX_SQUARE_SIDE;

    if (put_flag)
        SE_MEM[SCREEN_INFO_BLOCK][bg_id] = FLAG_TILE_ID;
    else
        SE_MEM[SCREEN_INFO_BLOCK][bg_id] = 0;
}

void set_cursor_position(s16 x, s16 y) {
    sprite_set_x(CURSOR_SPRITE_INDEX, x);
    sprite_set_y(CURSOR_SPRITE_INDEX, y);
}
