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
