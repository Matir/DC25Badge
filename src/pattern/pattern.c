#include "pattern.h"

uint16_t pattern_num = 0;
uint16_t frame_num = 0;

pattern_def defined_patterns[] = {
};

void pattern_next() {
}

void frame_next() {
  pixel px;
  uint8_t pos;
  apa102c_frame_begin();
  for (pos=0;pos<NUM_PIXELS;pos++) {
    defined_patterns[pattern_num].pixel_update(frame_num, pos, &px);
    apa102c_send_pixel(&px);
  }
  apa102c_frame_end();
  frame_num++;
  if (frame_num >= FRAME_NUM_MAX)
    frame_num -= FRAME_NUM_MAX;
}

void pattern_off() {
  // Turn off all the pixels
  int i;
  pixel empty = {0,0,0,0};
  apa102c_frame_begin();
  for (i=0;i<NUM_PIXELS;i++)
    apa102c_send_pixel(&empty);
  apa102c_frame_end();
  frame_num = 0;
}

/* Position information for XXV */
uint8_t pixel_get_row(uint8_t num) {
  num &= 0xF;
  if (num < 8)
    return num;
  return (7 - (num & 7));
}

uint8_t pixel_get_col_coarse(uint8_t num) {
  return (num >> 3);
}

uint8_t pixel_get_col_fine(uint8_t num) {
  uint8_t block;

  // The V
  if (num > 31)
    return (num - 0x10);

  // First or 2nd X?
  block = (num & 0x10) >> 1;
  num &= 0xF;
  // Flip top and bottom
  if (num & 0x4)
    num ^= 0x7;
  if (num < 8)
    return num + block;
  return (7 - (num & 7)) + block;
}
