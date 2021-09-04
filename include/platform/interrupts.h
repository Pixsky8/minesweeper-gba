#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

#include "platform/architecture.h"
#include "platform/types.h"
#include "platform/video.h"

// Master interrupt control: enabled:1 ; disabled:0
#define REG_IME (*(v_u16 *) (0x4000208))
// Interrupt expected
#define REG_IE (*(v_u16 *) (0x4000200))
// Interrupt fired
#define REG_IF (*(v_u16 *) (0x4000202))
// Interrupt service routine pointer
#define REG_ISR_MAIN (*(fnptr *) (0x3007FFC))
// Used to informs the bios that any interrupts it was expecting have been dealt with.
#define REG_IFBIOS (*(v_u16 *) (0x3007FF8))

// interrupts
#define IRQ_VBLANK  0x0001
#define IRQ_HBLANK  0x0002
#define IRQ_VCOUNT  0x0004
#define IRQ_TIMER0  0x0008
#define IRQ_TIMER1  0x0010
#define IRQ_TIMER2  0x0020
#define IRQ_TIMER3  0x0040
#define IRQ_COM     0x0080
#define IRQ_DMA0    0x0100
#define IRQ_DMA1    0x0200
#define IRQ_DMA2    0x0400
#define IRQ_DMA3    0x0800
#define IRQ_KEYPAD  0x1000
#define IRQ_GAMEPAK 0x2000

#define VID_VBL_IRQ 0x0008
#define VID_VHB_IRQ 0x0010
#define VID_VCT_IRQ 0x0020

void vblank_inter_wait();
ARM void interrupt_handler();
void register_vblank_isr();

#endif
