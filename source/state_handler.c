#include "engine/logic.h"
#include "global.h"
#include "menu/main_menu.h"

void update(void) {
    switch (g_game_state) {
    case IN_GAME:
        game_update();
        break;
    case MAIN_MENU:
        main_menu_update();
        break;
    }
}
