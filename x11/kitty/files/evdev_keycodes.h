/*
 * On linux use the linux codes, otherwise fudge them.
 */

#pragma once

#if defined(__has_include)
#  if __has_include(<linux/input-event-codes.h>)
#    include <linux/input-event-codes.h>
#  endif
#endif

#ifndef BTN_LEFT
#define BTN_LEFT        0x110
#endif

#ifndef BTN_RIGHT
#define BTN_RIGHT       0x111
#endif

#ifndef BTN_MIDDLE
#define BTN_MIDDLE      0x112
#endif

#ifndef BTN_SIDE
#define BTN_SIDE        0x113
#endif

#ifndef BTN_EXTRA
#define BTN_EXTRA       0x114
#endif

#ifndef BTN_FORWARD
#define BTN_FORWARD     0x115
#endif

#ifndef BTN_BACK
#define BTN_BACK        0x116
#endif

#ifndef BTN_TASK
#define BTN_TASK        0x117
#endif
