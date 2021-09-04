#include "platform/interrupts.h"

void vblank_inter_wait() {
    asm volatile("swi 0x05");
}

IWRAM_ARM void interrupt_handler() {
    REG_IF = IRQ_VBLANK;
    REG_IFBIOS |= IRQ_VBLANK;
}

void register_vblank_isr() {
    REG_IME = 0;                              // disable interrupt mgr
    REG_ISR_MAIN = (fnptr) interrupt_handler; // set register interrupt f°
    REG_DISPSTAT |= VID_VBL_IRQ;              // fire VB
    REG_IE |= IRQ_VBLANK;                     // catch VB
    REG_IME = 1;                              // enable interrupt mgr
}
