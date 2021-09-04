#include "platform/video.h"

OBJ_ATTR obj_buffer[OBJ_BUFF_SIZE];
OBJ_AFFINE *const obj_aff_buffer = (OBJ_AFFINE *) obj_buffer;

BG_OFFSET bg_reg_offset[NB_BG];

// ======== Sprites ========

u16 set_obj_attr0(u16 y,
                  u16 obj_mode,
                  u16 obj_gfx_mode,
                  u16 obj_mosaic,
                  u16 obj_color_mode,
                  u16 obj_shape) {
    return (y & 0x00ff) |              //
           (obj_mode & 0x0300) |       //
           (obj_gfx_mode & 0x0c00) |   //
           (obj_mosaic & 0x1000) |     //
           (obj_color_mode & 0x2000) | //
           (obj_shape & 0xc000);
}

u16 set_obj_attr1(u16 x, u16 obj_horiz_flip, u16 obj_verti_flip, u16 obj_size) {
    return (x & 0x01ff) |              //
           (obj_horiz_flip & 0x1000) | //
           (obj_verti_flip & 0x2000) | //
           (obj_size & 0xc000);
}

u16 set_obj_attr1_affine(u16 x, u16 affine_index, u16 obj_size) {
    return (x & 0x01ff) |                   //
           ((affine_index << 9) & 0x3e00) | //
           (obj_size & 0xc000);
}

u16 set_obj_attr2(u16 tile_index, u8 priority, u8 palette_bnk) {
    return (tile_index & 0x03ff) |     //
           ((priority & 0x03) << 10) | //
           ((palette_bnk & 0x0f) << 12);
}

void obj_buff_init() {
    u32 *buffer = ((u32 *) obj_buffer);
    u32 i = OBJ_BUFF_SIZE;
    while (i) {
        *buffer++ = ATTR0_HIDE;
        *buffer++ = 0;
        i--;
    }
}

void obj_buff_to_oam(u16 size) {
    OBJ_ATTR *oam_buff = ((OBJ_ATTR *) OAM);
    OBJ_ATTR *obj_buff_ptr = obj_buffer;
    while (size) {
        *oam_buff = *obj_buff_ptr;
        oam_buff++;
        obj_buff_ptr++;
        size--;
    }
}

void obj_to_oam(u16 i) {
    OBJ_ATTR *oam_buff = ((OBJ_ATTR *) OAM);
    OBJ_ATTR *obj_buff_ptr = obj_buffer;
    oam_buff[i] = obj_buff_ptr[i];
}

// ======== Backgrounds ========

u16 bg_control(u16 priority,
               u16 character_base_block, // 0-3
               u16 bg_mosaic,
               u16 bg_color_mode,
               u16 screen_base_block, // 0-31
               u16 bg_affine_wrapping,
               u16 bg_size) {
    return (priority & 0x03) |                    //
           ((character_base_block & 0x03) << 2) | //
           bg_mosaic |                            //
           bg_color_mode |                        //
           ((screen_base_block & 0x1f) << 8) |    //
           bg_affine_wrapping |                   //
           bg_size;
}

u16 bg_screen_entry(u16 tile_index,
                    u16 bg_horizon_flip,
                    u16 bg_vertical_flip,
                    u16 palette_bank) {
    return (tile_index & 0x3ff) | //
           bg_horizon_flip |      //
           bg_vertical_flip |     //
           ((palette_bank & 0x00f) << 12);
}
