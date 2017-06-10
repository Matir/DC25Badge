#ifndef _APA102C_H_
#define _APA102C_H_

#include <compiler.h>

#define BRIGHT_MASK   0x1f
#define BRIGHT_MAX    BRIGHT_MASK
#define CLEAR_PIXEL(x) (x) = ((pixel){BRIGHT_MAX, 0, 0, 0})

COMPILER_PACK_SET(1)
COMPILER_ALIGNED(4)
typedef struct {
  uint8_t brightness;
  uint8_t blue;
  uint8_t green;
  uint8_t red;
} pixel;
COMPILER_PACK_RESET()

void apa102c_frame_begin();
void apa102c_send_pixel(pixel *data);
void apa102c_frame_end();

#endif // _APA102C_H_
