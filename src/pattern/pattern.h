#include "../apa102c/apa102c.h"

#include <compiler.h>

#define FRAME_NUM_MAX 4800
#ifndef NUM_PIXELS
#  define NUM_PIXELS 48
#endif

typedef struct {
  const char *name;
  void (*pixel_update)(uint16_t, uint8_t, pixel*);
} pattern_def;

// Change patterns
void pattern_next();

// Go to the next frame
void frame_next();

// Turn off all pixels
void pattern_off();

// Get pixel position information
uint8_t pixel_get_row(uint8_t num);
uint8_t pixel_get_col_coarse(uint8_t num);
uint8_t pixel_get_col_fine(uint8_t num);

/* Define prototypes here */
