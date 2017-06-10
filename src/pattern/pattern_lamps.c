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
  px->brightness = 0xf;
}

void pattern_ripple(uint16_t frame, uint8_t u_pxnum, pixel *px) {
  px->red = frame & 0xff;
  px->green = (frame >> 4) & 0xff;
  px->blue = (frame >> 8) & 0xff;
}
