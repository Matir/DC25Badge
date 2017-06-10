#ifndef _PATTERN_H_
#define _PATTERN_H_

#include "../config.h"
#include "../apa102c/apa102c.h"

#include <compiler.h>

#define FRAME_NUM_MAX 4800

// TODO: compute this from prescaler
#define US_PER_FRAME 32768

// Multiply two uint8_t and get top 8 bits.
#define MULTIPLY_SCALE(x, y)  (uint8_t)(((uint16_t)(x) * (uint16_t)(y)) >> 8)

typedef void(*pattern_update_func)(uint16_t, uint8_t, pixel *);
#define PATTERN_UPDATE_FUNC(x) void x(uint16_t, uint8_t, pixel *)

typedef struct {
  const char *name;
  pattern_update_func pixel_update;
} pattern_def;

// Consts for patterns
extern const uint16_t consts_num_steps;
extern const uint16_t consts_resolution;
extern const uint8_t sin_table[];
extern const uint8_t gamma_table[];

// Start the pattern engine
void pattern_start();

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
PATTERN_UPDATE_FUNC(pattern_chase_white);
PATTERN_UPDATE_FUNC(pattern_chase_red);
PATTERN_UPDATE_FUNC(pattern_chase_blue);
PATTERN_UPDATE_FUNC(pattern_bright);
PATTERN_UPDATE_FUNC(pattern_bright_half);
PATTERN_UPDATE_FUNC(pattern_bright_pwm);
PATTERN_UPDATE_FUNC(pattern_ripple);

#endif // _PATTERN_H_
