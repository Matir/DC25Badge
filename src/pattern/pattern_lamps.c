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

void pattern_bright(uint16_t u_frame, uint8_t u_pxnum, pixel *px) {
  px->red = 0xff;
  px->green = 0xff;
  px->blue = 0xff;
  px->brightness = BRIGHT_MAX;
}

void pattern_bright_half(uint16_t u_frame, uint8_t u_pxnum, pixel *px) {
  px->red = 0x7f;
  px->green = 0x7f;
  px->blue = 0x7f;
  px->brightness = BRIGHT_MAX;
}

void pattern_bright_pwm(uint16_t u_frame, uint8_t u_pxnum, pixel *px) {
  px->red = 0xff;
  px->green = 0xff;
  px->blue = 0xff;
  // gamma adjusted
  px->brightness = 0x5;
}

void pattern_strobe(uint16_t frame, uint8_t u_pxnum, pixel *px) {
  px->red = (frame & 1) ? 0xFF : 0;
  px->green = (frame & 1) ? 0xFF : 0;
  px->blue = (frame & 1) ? 0xFF : 0;
}
