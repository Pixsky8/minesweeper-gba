#include <string.h>

#include "platform/interrupts.h"
#include "platform/video.h"

#include "backgrounds/unified.h"
#include "engine/renderer.h"
#include "global.h"
#include "platform/video.h"
#include "sprites/sprites.h"
#include "tools/memory.h"

void init_screen(void) {
    // Init VSync
    register_vblank_isr();

    REG_DISPCNT = MODE_0 | ENABLE_BG_0 | ENABLE_BG_1 | ENABLE_BG_2 |
                  ENABLE_OBJECTS | SP_MAPPING_1D;
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
    memcpy(PAL_BG, unifiedPal, unifiedPalLen);

    // Copy background tiles
    memcpy(&TILE_MEM[CHARACTER_BASE_BLOCK][0], unifiedTiles, unifiedTilesLen);
}
