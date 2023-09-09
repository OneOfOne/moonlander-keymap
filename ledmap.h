#pragma once

#include "color.h"

#define RED { HSV_RED }
#define WHIT { HSV_WHITE }
#define GREN { HSV_GREEN }
#define MEDSEA { 139,215,169 }
#define TEAL { HSV_TEAL }
#define GOLD { HSV_GOLD }
#define ORNG { HSV_ORANGE }
#define BLCK { HSV_BLACK }

#define KEYS_TO_LEDS( \
	k00, k05, k10, k15, k20, k25, k29,         k65, k61, k56, k51, k46, k41, k36, \
	k01, k06, k11, k16, k21, k26, k30,         k66, k62, k57, k52, k47, k42, k37, \
	k02, k07, k12, k17, k22, k27, k31,         k67, k63, k58, k53, k48, k43, k38, \
	k03, k08, k13, k18, k23, k28,                   k64, k59, k54, k49, k44, k39, \
	k04, k09, k14, k19, k24,      k35,         k71,      k60, k55, k50, k45, k40, \
	                    k32, k33, k34,         k70, k69, k68                      \
) \
{ \
	k00, k01, k02, k03, k04, k05, k06,         k07, k08, k09, k10, k11, k12, k13, \
	k14, k15, k16, k17, k18, k19, k20,         k21, k22, k23, k24, k25, k26, k27, \
	k28, k29, k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, k40, k41, \
	k42, k43, k44, k45, k46, k47,                   k48, k49, k50, k51, k52, k53, \
	k54, k55, k56, k57, k58,      k59,         k60,      k61, k62, k63, k64, k65, \
	                    k66, k67, k68,         k69, k70, k71                      \
}


/* RGB LED map appears to number keys thusly
src: https://www.reddit.com/r/ergodox/comments/sq1bn7/moonlander_rgb_led_map_indexing/
0 5 10 15 20 25 29         65 61 56 51 46 41 36
1 6 11 16 21 26 30         66 62 57 52 47 42 37
2 7 12 17 22 27 31         67 63 58 53 48 43 38
3 8 13 18 23 28               64 59 54 49 44 39
4 9 14 19 24    35         71    60 55 50 45 40
             32 33 34   70 69 68
 */
