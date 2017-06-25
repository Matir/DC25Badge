#ifndef _PATTERN_H_
#define _PATTERN_H_

#include "../config.h"
#include "../apa102c/apa102c.h"

#include <compiler.h>

#define FRAME_NUM_MAX 4800

// TODO: compute this from prescaler
#define US_PER_FRAME    32768
#define MS_PER_FRAME    (US_PER_FRAME / 1000)
#define FRAMES_PER_SEC  (1000000 / US_PER_FRAME)

// Multiply two uint8_t and get top 8 bits.
#define MULTIPLY_SCALE(x, y)  (uint8_t)(((uint16_t)(x) * (uint16_t)(y)) >> 8)
#define BRIGHTNESS_SCALE(x)   (uint8_t)(((uint16_t)(x) * (uint16_t)(brightness_factor)) >> 4)

typedef void(*pattern_update_func)(uint16_t, uint8_t, pixel *);
#define PATTERN_UPDATE_FUNC(x) void x(uint16_t, uint8_t, pixel *)

typedef struct {
  const char *name;
  pattern_update_func pixel_update;
} pattern_def;

typedef struct {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} struct_rgb;

// Consts for patterns
extern const uint16_t consts_num_steps;
extern const uint16_t consts_resolution;
extern const uint8_t sin_table[];
extern const uint8_t gamma_table[];
extern const uint8_t gamma_min_idx;
extern const struct_rgb colorwheel[];

// Setup the pattern engine
void pattern_setup();

// Run the pattern engine forever
void pattern_start();

// Change patterns
void pattern_next();

// Turn off all pixels
void pattern_shutdown();

// Adjust brightness
void pattern_bright_cycle();

// Make it blinding
void pattern_blind_toggle();

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
PATTERN_UPDATE_FUNC(pattern_strobe);
PATTERN_UPDATE_FUNC(pattern_letters);
PATTERN_UPDATE_FUNC(pattern_wave_colors);

#endif // _PATTERN_H_
