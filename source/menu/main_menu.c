#include "engine/logic.h"
#include "engine/renderer.h"
#include "global.h"
#include "platform/input.h"
#include "platform/video.h"

#define CURSOR_SPRITE_INDEX   0
#define CURSOR_SPRITE_TILE_ID 20

enum MENU_ITEM_LIST {
    MENU_PLAY = 0,
    MENU_NUMBER_OF_ELEMENT, // Last element, only used to get the number of elements
};

static inline void set_sprite_y_from_index(enum MENU_ITEM_LIST index) {
    int sprite_y = 0;
    switch (index) {
    case MENU_PLAY:
        sprite_y = 80;
        break;
    }

    obj_buffer[CURSOR_SPRITE_INDEX].attr0 = set_obj_attr0(sprite_y,
                                                          ATTR0_NOR,
                                                          ATTR0_GFX_NOR,
                                                          ATTR0_NO_MOSAIC,
                                                          ATTR0_8BPP,
                                                          ATTR0_SQUARE);
}

void init_main_menu(void) {
    g_cursor_y = 0;
    set_sprite_y_from_index(0);
    obj_buffer[CURSOR_SPRITE_INDEX].attr1 =
        set_obj_attr1(g_cursor_x, 0, 0, ATTR1_S);
    obj_buffer[CURSOR_SPRITE_INDEX].attr2 =
        set_obj_attr2(CURSOR_SPRITE_TILE_ID, 0, 0);
}

void close_main_menu(void) {}

static inline void update_menu_index(void) {
    if (key_positive_edge(KEY_DOWN)) {
        g_cursor_y++;
        g_cursor_y %= MENU_NUMBER_OF_ELEMENT;
        set_sprite_y_from_index(g_cursor_y);
    }
    else if (key_positive_edge(KEY_UP)) {
        g_cursor_y--;
        if (g_cursor_y < 0)
            g_cursor_y = MENU_NUMBER_OF_ELEMENT - 1;
        set_sprite_y_from_index(g_cursor_y);
    }
}

void main_menu_update(void) {
    update_menu_index();

    if (key_positive_edge(KEY_A)) {
        switch (g_cursor_y) {
        case MENU_PLAY:
            g_game_state = IN_GAME;
            close_main_menu();
            init_game();
            break;
        }
    }
}
