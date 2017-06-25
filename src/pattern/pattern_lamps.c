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
