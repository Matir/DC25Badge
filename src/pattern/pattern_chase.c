#include "pattern.h"

void pattern_chase_white(uint16_t frame, uint8_t pxnum, pixel *px) {
  int16_t cmp;

  // Slow things down
  frame >>= 4;
  cmp = ((int16_t)(frame % NUM_PIXELS) - (int16_t)pxnum);

  CLEAR_PIXEL(*px);
  if (cmp > 1)
    return;
  px->red = 0xFF;
  px->blue = 0xFF;
  px->green = 0xFF;
  if (cmp == 1) {
    px->brightness = 5;
  }
}
