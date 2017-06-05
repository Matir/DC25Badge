#include "pattern.h"

#include <stdlib.h>

void pattern_chase_white(uint16_t frame, uint8_t pxnum, pixel *px) {
  int16_t cmp;

  // Slow things down
  frame >>= 4;
  cmp = abs((int16_t)frame - (int16_t)pxnum) % NUM_PIXELS;

  CLEAR_PIXEL(*px);
  if (cmp > 1)
    return;
  px->red = 0xFF;
  px->blue = 0xFF;
  px->green = 0xFF;
  if (cmp == 1) {
    px->brightness = 5;
  } else {
    px->brightness = 10;
  }
}
