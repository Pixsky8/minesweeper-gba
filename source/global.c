#include "global.h"

char g_board[BOARD_SIZE] = { 0 };

// This value has to be inferior or equal to 8
int g_game_board_side = 16;

int g_bomb_number = 20;

int g_cursor_x = 0;
int g_cursor_y = 0;

enum GAME_STATE g_game_state = MAIN_MENU;
