#include <string.h>

#include "platform/interrupts.h"
#include "platform/video.h"

#include "backgrounds/background.h"
#include "maps/map.h"
#include "sprites/sprites.h"

#define CHARACTER_BASE_BLOCK 0
#define SCREEN_BASE_BLOCK    28

void init_screen(void) {
    // Init VSync
    register_vblank_isr();

    REG_DISPCNT = MODE_0 | BGMODE_0 | BGMODE_1 | ENABLE_OBJECTS | SP_MAPPING_1D;
}

void init_sprites(void) {
    // Copy sprite palette
    memcpy(PAL_SP, spritesPal, spritesPalLen);

    // Copy sprites
    memcpy(&TILE8_MEM[4][0], spritesTiles, spritesTilesLen);

    obj_buff_init();
}

void init_backgrounds(void) {
    // Copy background palette
    memcpy(PAL_BG, backgroundPal, backgroundPalLen);

    // Copy background tiles
    memcpy(&TILE_MEM[CHARACTER_BASE_BLOCK][0],
           backgroundTiles,
           backgroundTilesLen);

    // Copy background map
    memcpy(&SE_MEM[SCREEN_BASE_BLOCK][0], blankMap, blankMapLen);

    // Update bg info
    REG_BGCNT[0] = bg_control(1,
                              CHARACTER_BASE_BLOCK,
                              BG_NO_MOSAIC,
                              BG_8BPP,
                              SCREEN_BASE_BLOCK,
                              BG_NO_WRAP,
                              BG_REG_32x32);
}
