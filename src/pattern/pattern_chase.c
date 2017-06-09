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

void pattern_chase_wrapped(uint16_t frame, uint8_t pxnum, pixel *px,
    uint8_t r, uint8_t g, uint8_t b) {
  int16_t cmp;

  // Slow things down
  frame >>= 4;
  cmp = abs((int16_t)frame - (int16_t)pxnum) % NUM_PIXELS;

  CLEAR_PIXEL(*px);
  if (cmp > 1)
    return;
  px->red = r;
  px->green = g;
  px->blue = b;
  if (cmp == 1) {
    px->brightness = 5;
  } else {
    px->brightness = 10;
  }
}
