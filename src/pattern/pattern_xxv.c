/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
