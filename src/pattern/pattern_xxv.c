#include "pattern.h"

void pattern_letters(uint16_t frame, uint8_t pxnum, pixel *px) {
  uint8_t letter = pixel_get_col_coarse(pxnum) >> 1;
  frame >>= 5;
  frame += letter;
  frame %= 3;
  switch (frame) {
    case 0:
      px->red = 0xff;
      break;
    case 1:
      px->green = 0xff;
      break;
    case 2:
      px->blue = 0xff;
      break;
  }
}

void pattern_wave_colors(uint16_t frame, uint8_t pxnum, pixel *px) {
  uint8_t col = pixel_get_col_fine(pxnum);
  unsigned int index = (frame * 5 + col * consts_resolution) % consts_num_steps;
  struct_rgb color = colorwheel[index];
  px->red = color.red;
  px->green = color.green;
  px->blue = color.blue;
}
