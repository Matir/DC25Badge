#include "pattern.h"

#include <stdlib.h>

static void pattern_chase_wrapped(
    uint16_t, uint8_t, pixel *, uint8_t, uint8_t, uint8_t);
#define PATTERN_CHASE_COLOR(color, r, g, b) void pattern_chase_ ## color \
    (uint16_t frame, uint8_t pxnum, pixel *px) { \
          pattern_chase_wrapped(frame, pxnum, px, r, g, b); \
    }

PATTERN_CHASE_COLOR(red, 0xFF, 0x00, 0x00);
PATTERN_CHASE_COLOR(white, 0xFF, 0xFF, 0xFF);
PATTERN_CHASE_COLOR(blue, 0x00, 0x00, 0xFF);
PATTERN_CHASE_COLOR(green, 0x00, 0xFF, 0x00);

void pattern_chase_wrapped(uint16_t frame, uint8_t pxnum, pixel *px,
    uint8_t r, uint8_t g, uint8_t b) {
  int16_t pos;
  uint8_t sin_value;

  pos = ((frame * 4 + (pxnum * consts_resolution))) % consts_num_steps;
  sin_value = sin_table[pos];

  px->red = MULTIPLY_SCALE(r, sin_value);
  px->green = MULTIPLY_SCALE(g, sin_value);
  px->blue = MULTIPLY_SCALE(b, sin_value);
}
