#ifndef __VIDEO_H__
#define __VIDEO_H__

#include "platform/architecture.h"
#include "platform/memory_map.h"
#include "platform/types.h"

#define SCREEN_W 240
#define SCREEN_H 160

#define REG_DISPCNT  *((v_u32 *) (IORAM))
#define REG_DISPSTAT (*(v_u16 *) (0x04000004)) // IORAM+0x4
#define REG_VCOUNT   (*(v_u16 *) (0x04000006)) // IORAM+0x6

// Video modes
#define MODE_0 0x0000 // Sprite 4 BG, no rotation, no scaling
#define MODE_1 0x0001 // Sprite 3 BG, one can be rotated and scaled
#define MODE_2 0x0002 // Sprite 2 BG both can be rotated and scaled
#define MODE_3 0x0003 // Bitmap 240x160, 16bpp, no page-flip
#define MODE_4 0x0004 // Bitmap 240x160, 8bpp, page-flip
#define MODE_5 0x0005 // Bitmap 160x128, 16bpp, page-flip

#define BGMODE_0 0x0100 // Enable BG 0
#define BGMODE_1 0x0200 // Enable BG 1
#define BGMODE_2 0x0400 // Enable BG 2
#define BGMODE_3 0x0800 // Enable BG 3

#define NB_BG 4

// ============ Bitmap Modes Macros ============
// Screenbuffer for bitmap modes
#define SCREENBUFFER ((u16 *) (VRAM))

// ============ Sprite modes Macros ============

// Sprite modes Registers
#define PAL_BG ((u16 *) (0x05000000)) // 256 entries of 15bit colors
#define PAL_SP ((u16 *) (0x05000200)) // 256 entries of 15bit colors

// Sprite modes Memory Adresses
#define TILE_MEM  ((CHARBLOCK *) (VRAM))
#define TILE8_MEM ((CHARBLOCK8 *) (VRAM))

// ====== Background ======
// === Background structs ===
typedef struct BG_OFFSET {
    s16 x;
    s16 y;
} __attribute__((aligned(4))) BG_OFFSET;
typedef u16 SCREENBLOCK[1024];

// Used for tilemaps
// SE_MEM[x] ranges from 0 to 1024
#define SE_MEM ((SCREENBLOCK *) VRAM)
// === Background registers ===
// Primary control registers; use REG_BGCNT[i] i:0-3
#define REG_BGCNT ((v_u16 *) 0x04000008)
// Scrolling registers; use REG_BG_OFF[i] i:0-3; /!\ read only
#define REG_BG_OFF ((BG_OFFSET *) 0x04000010)
// === Conrol register macros ===
// bg_mosaic
#define BG_NO_MOSAIC 0
#define BG_MOSAIC    0x0040
// bg_color_mode
#define BG_4BPP 0
#define BG_8BPP 0x0080
// bg_affine_wrapping
#define BG_NO_WRAP 0
#define BG_WRAP    0x2000
// bg_size
#define BG_REG_32x32   0      // 256x256p
#define BG_REG_64x32   0x4000 // 512x256p
#define BG_REG_32x64   0x8000 // 256x512p
#define BG_REG_64x64   0xc000 // 512x512p
#define BG_AFF_16x16   0      // 128x128p
#define BG_AFF_32x32   0x4000 // 256x256p
#define BG_AFF_64x64   0x8000 // 512x512p
#define BG_AFF_128x128 0xc000 // 1024x1024p
// bg_flip
#define BG_NO_FLIP 0
#define BG_HFLIP   0x0400
#define BG_VFLIP   0x0800
// === Global Variables ====

// ====== Sprites ======
// Sprite modes types
typedef struct {
    u32 data[8];
} TILE; // 8x8, 4bpp tile
typedef struct {
    u32 data[16];
} TILE8; // 8x8, 8bpp tile
typedef struct tagOBJ_ATTR {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    s16 fill;
} __attribute__((aligned(4))) OBJ_ATTR;
typedef struct OBJ_AFFINE {
    u16 fill0[3];
    s16 pa;
    u16 fill1[3];
    s16 pb;
    u16 fill2[3];
    s16 pc;
    u16 fill3[3];
    s16 pd;
} __attribute__((aligned(4))) OBJ_AFFINE;

// Tile blocks
// Used to store tile data
// CHARBLOCK[x] ranges from 0 to 3
typedef TILE CHARBLOCK[512];   // 32x16 tiles @ 4bpp
typedef TILE8 CHARBLOCK8[256]; // 16x16 tiles @ 8bpp

// Buffer of the OAM entries to avoid writting while OAM is locked
#define OBJ_BUFF_SIZE 128 // Max 128
extern OBJ_ATTR obj_buffer[OBJ_BUFF_SIZE];
extern OBJ_AFFINE *const obj_aff_buffer;

// ==== Sprite modes macros ====
#define SP_MAPPING_1D                                                          \
    0x0040 // Used in REG_DISPCNT to set the sprite's mapping mode to 1D
#define ENABLE_OBJECTS 0x1000 // Used in REG_DISPCNT to enable objects
// == Sprite's attr0 macros ==
// Object mode
#define ATTR0_NOR     0x0000 // Normal rendering
#define ATTR0_AFF     0x0100 // Sprite is affine, will use affine matrix from attr1
#define ATTR0_HIDE    0x0200 // Hide sprite
#define ATTR0_AFF_DBL 0x0300 // Affine sprite with double rendering area
// Gfx mode
#define ATTR0_GFX_NOR 0x0000 // Normal rendering
#define ATTR0_BLEND   0x0400 // Enables blending
#define ATTR0_WIN     0x0800 // Obj is part of obj window
// Mosaic
#define ATTR0_NO_MOSAIC 0x0000 // No Mosaic effect
#define ATTR0_MOSAIC    0x1000 // Enables mosaic effect
// Color mode
#define ATTR0_4BPP 0x0000
#define ATTR0_8BPP 0x2000
// Shape
#define ATTR0_SQUARE 0x0000
#define ATTR0_WIDE   0x4000
#define ATTR0_TALL   0x8000
// == Sprite's attr1 macros ==
// Flipping
#define ATTR1_NO_FLIP 0x0000
#define ATTR1_HFLIP   0x1000
#define ATTR1_VFLIP   0x2000
// Size
#define ATTR1_S  0x0000
#define ATTR1_M  0x4000
#define ATTR1_L  0x8000
#define ATTR1_XL 0xc000

// Sprite Functions

/**
** @brief Get attribute 0 value corresponding to the arguments
** @param y The y coordonate of the top of sprite (0 is the top of the screen)
** @param obj_mode Change the rendering mode of the sprite (see Object Modes Mac)
** @param obj_gfx_mode Change the special effects (see Gfx Modes Macros)
** @param obj_mosaic Enable / Disable Mosaic Effect (see Mosaic Macros)
** @param obj_color_mode Change the color mode (see Color Modes Macros)
** @param obj_shape Change the shape of the sprite (see Shape Macros)
*/
u16 set_obj_attr0(u16 y,
                  u16 obj_mode,
                  u16 obj_gfx_mode,
                  u16 obj_mosaic,
                  u16 obj_color_mode,
                  u16 obj_shape);

/**
** @brief Get attribute 1 value when the sprite is not affine
** @param x The x coordonate of the left of the sprite (0 is the left of the screen)
** @param obj_horiz_flip Flip the sprite (see Flipping Macros)
** @param obj_verti_flip Flip the sprite (see Flipping Macros)
** @param obj_size Change the size of the sprite (see Size Macros)
*/
u16 set_obj_attr1(u16 x, u16 obj_horiz_flip, u16 obj_verti_flip, u16 obj_size);

/**
** @brief Get attribute 1 value when the sprite is affine
** @param x The x coordonate of the left of the sprite (0 is the left of the screen)
** @param obj_affine_index Index of the sprite's affine entry
** @param obj_size Change the size of the sprite (see Size Macros)
*/
u16 set_obj_attr1_affine(u16 x, u16 obj_affine_index, u16 obj_size);

/**
** @brief Get attribute 2 value
** @param tile_index The index of the tile the sprite should use
** @param priority The height of the sprite (compared to others)
** @param palette_bnk The index of the palette (only used in 4BPP color mode)
*/
u16 set_obj_attr2(u16 tile_index, u8 priority, u8 palette_bnk);

/**
** @brief Set all values in the object buffer to 0
*/
void obj_buff_init();

/**
** @brief Copy object buffer to OAM space
** @param size the size of the buffer
*/
void obj_buff_to_oam(u16 size);

/**
** @brief Copy single entry of the object buffer
** @param i The index of the object in the object buffer
*/
void obj_to_oam(u16 i);

// Background Functions
u16 bg_control(u16 priority,
               u16 character_base_block,
               u16 bg_mosaic,
               u16 bg_color_mode,
               u16 screen_base_block,
               u16 bg_affine_wrapping,
               u16 bg_size);

/**
** @brief Hide the sprite
*/
static inline void hide_sprite(u16 obj_buff_index) {
    obj_buffer[obj_buff_index].attr0 = ATTR0_HIDE;
    obj_to_oam(obj_buff_index);
}

/**
** @brief Display the sprite, does not update OAM
*/
static inline void display_sprite(u16 obj_buff_index) {
    obj_buffer[obj_buff_index].attr0 &= 0xfcff;
}

/**
** @brief Change the sprite's x
*/
static inline void sprite_set_x(u16 obj_buff_index, s16 x) {
    u16 x_masked = x & 0x01ff;
    obj_buffer[obj_buff_index].attr1 &= 0xfe00;
    obj_buffer[obj_buff_index].attr1 |= x_masked;
}

/**
** @brief Change the sprite's y
*/
static inline void sprite_set_y(u16 obj_buff_index, s16 y) {
    u16 y_masked = y & 0x00ff;
    obj_buffer[obj_buff_index].attr0 &= 0xff00;
    obj_buffer[obj_buff_index].attr0 |= y_masked;
}

/**
** @brief Change the sprite's tile index
*/
static inline void sprite_change_tile(u16 obj_buff_index, u16 tile_index) {
    u16 tile_masked = tile_index & 0x03ff;
    obj_buffer[obj_buff_index].attr2 &= 0xfc00;
    obj_buffer[obj_buff_index].attr2 |= tile_masked;
}

#endif
