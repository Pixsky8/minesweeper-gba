#ifndef __ARCHITECTURE_H__
#define __ARCHITECTURE_H__

#define ARM       __attribute__((__target__("arm")))
#define THUMB     __attribute__((__target__("thumb")))
#define IWRAM_ARM __attribute__((section(".iwram"), target("arm"), long_call))

#endif
