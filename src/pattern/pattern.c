#include "pattern.h"

#include <tc.h>
#include <tc_interrupt.h>
#include <stdio.h>

struct tc_module tc_instance;

#define STATE_RUNNING   0
#define STATE_STOPPING  1
#define STATE_STOPPED   2

// brightness options out of 0x10
#define NUM_BRIGHTNESS_OPTIONS 4
#define BRIGHTNESS_DEFAULT 0x10
const uint8_t brightness_options[NUM_BRIGHTNESS_OPTIONS] =
  {BRIGHTNESS_DEFAULT, 0x0a, 0x8, 0x4};

volatile uint16_t pattern_num = 0;
volatile uint16_t frame_num = 0;
volatile uint8_t global_brightness_scale = 3; // use global
volatile uint8_t brightness_factor = BRIGHTNESS_DEFAULT;
volatile uint8_t pattern_state = STATE_RUNNING;
volatile uint8_t pattern_tick = 0;

const pattern_def defined_patterns[] = {
  {"White Chase", pattern_chase_white},
  {"Red Chase", pattern_chase_red},
  {"Blue Chase", pattern_chase_blue},
  // {"Max Bright", pattern_bright},  // Causes reset due to voltage drop
  {"50%", pattern_bright_half},
  // {"50% PWM", pattern_bright_pwm}, // Only needed for current testing
  {"Letters", pattern_letters},
  {"Color Wave", pattern_wave_colors},
  {NULL, NULL},
};

static void frame_next_tick(struct tc_module *);
static void frame_next();
static void pattern_off();

void pattern_setup() {
  // Start periodic interrupts to call frame_next.
  // An 1MHz GCLK with a 256 prescaler into an 7-bit counter = 32.768ms
  struct tc_config config_tc;
  tc_get_config_defaults(&config_tc);

  config_tc.counter_size = TC_COUNTER_SIZE_8BIT;
  config_tc.clock_source = GCLK_GENERATOR_1;
  config_tc.clock_prescaler = TC_CLOCK_PRESCALER_DIV256;
  config_tc.run_in_standby = true;
  config_tc.counter_8_bit.period = 128;

  // Start things up
  tc_init(&tc_instance, PATTERN_TC, &config_tc);
  tc_register_callback(&tc_instance, frame_next_tick, TC_CALLBACK_OVERFLOW);
  tc_enable_callback(&tc_instance, TC_CALLBACK_OVERFLOW);
  tc_enable(&tc_instance);
}

void pattern_start() {
  int idle = 0;
  while(1) {
    while (pattern_state == STATE_STOPPED){
      pattern_tick = 0;
    }

    // Stop if needed
    if (pattern_state == STATE_STOPPING) {
      pattern_off();
      pattern_state = STATE_STOPPED;
      continue;
    }

    if (pattern_tick > 1) {
      printf("Pattern overflow!\r\n");
    }
    frame_next();
    pattern_tick--;
    // TODO: standby mode
    while(!pattern_tick){
      idle++;
    }
    if ((frame_num & 0xff) == 0) {
      printf("Idle: %d\r\n", idle);
      idle = 0;
    }
  }
}

void pattern_next() {
  if (pattern_state == STATE_STOPPED) {
    pattern_state = STATE_RUNNING;
    pattern_tick = 1;
    frame_num = 0;
    return;
  }
  if (defined_patterns[pattern_num+1].pixel_update != NULL) {
    pattern_num++;
  } else {
    pattern_num = 0;
  }
  frame_num = 0;
  printf("Pattern changed to %s\r\n", defined_patterns[pattern_num].name);
}

void pattern_shutdown() {
  pattern_state = STATE_STOPPING;
}

void pattern_bright_cycle() {
  int i=0;
  for(i=0;i<NUM_BRIGHTNESS_OPTIONS-1;i++) {
    if (brightness_factor == brightness_options[i]) {
      brightness_factor = brightness_options[i+1];
      return;
    }
  }
  brightness_factor = brightness_options[0];
}

/* Position information for XXV */
uint8_t pixel_get_row(uint8_t num) {
  num &= 0xF;
  if (num < 8)
    return num;
  return (7 - (num & 7));
}

uint8_t pixel_get_col_coarse(uint8_t num) {
  return (num >> 3);
}

uint8_t pixel_get_col_fine(uint8_t num) {
  uint8_t block;

  // The V
  if (num > 31)
    return (num - 0x10);

  // First or 2nd X?
  block = (num & 0x10) >> 1;
  num &= 0xF;
  // Flip top and bottom
  if (num & 0x4)
    num ^= 0x7;
  if (num < 8)
    return num + block;
  return (7 - (num & 7)) + block;
}

/* Internal implementation details */

static void frame_next_tick(struct tc_module *unused_module) {
  pattern_tick++;
}


static void pattern_off() {
  // Turn off all the pixels
  int i;
  printf("Pattern off\r\n");
  pixel empty = {0,0,0,0};
  apa102c_frame_begin();
  for (i=0;i<NUM_PIXELS;i++)
    apa102c_send_pixel(&empty);
  apa102c_frame_end();
  frame_num = 0;
}

static void frame_next() {
  pixel px;
  uint8_t pos;
  pattern_update_func update_func = defined_patterns[pattern_num].pixel_update;

  apa102c_frame_begin();
  for (pos=0;pos<NUM_PIXELS;pos++) {
    CLEAR_PIXEL(px);
    update_func(frame_num, pos, &px);
#ifndef DISABLE_GAMMA_CORRECT
    px.red = gamma_table[BRIGHTNESS_SCALE(px.red)];
    px.green = gamma_table[BRIGHTNESS_SCALE(px.green)];
    px.blue = gamma_table[BRIGHTNESS_SCALE(px.blue)];
#else
    px.red = BRIGHTNESS_SCALE(px.red);
    px.green = BRIGHTNESS_SCALE(px.green);
    px.blue = BRIGHTNESS_SCALE(px.blue);
#endif
    px.brightness = (px.brightness & BRIGHT_MASK) >> global_brightness_scale;
    apa102c_send_pixel(&px);
  }
  apa102c_frame_end();
  frame_num++;
  if (frame_num >= FRAME_NUM_MAX)
    frame_num -= FRAME_NUM_MAX;
}
