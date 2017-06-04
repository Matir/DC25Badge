#include <compiler.h>

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
