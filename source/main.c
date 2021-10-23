#include "init.h"
#include "menu/main_menu.h"
#include "platform/input.h"
#include "platform/interrupts.h"
#include "platform/video.h"
#include "state_handler.h"
#include "tools/rng.h"

int main(void) {
    init_screen();
    init_sprites();
    init_backgrounds();

    init_main_menu();

    while (1) {
        refresh_input_buffers();

        update();

        obj_buff_to_oam(OBJ_BUFF_SIZE);
        random();
        vblank_inter_wait();
    }
}
