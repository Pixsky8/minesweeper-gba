#ifndef GLOBAL_H
#define GLOBAL_H

#define BOARD_WIDTH 16
#define BOARD_SIZE  512

#define CHARACTER_BASE_BLOCK 0

enum GAME_STATE {
    MAIN_MENU = 0,
    IN_GAME,
};

extern char g_board[BOARD_SIZE];

extern int g_game_board_side;
extern int g_bomb_number;

extern int g_cursor_x, g_cursor_y;

extern enum GAME_STATE g_game_state;

#endif
