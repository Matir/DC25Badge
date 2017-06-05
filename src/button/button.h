/**
 * Debounce buttons and handle short/long presses on release.
 * Button handlers must be registered externally with BOTH (rising/falling)
 * Call button_debounce_clock_setup() once.
 * Call button_event_handler() with a pointer to the button_controller on each
 * interrupt.
 */

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "../config.h"

#define DEBOUNCE_MILLIS 15
#define LONGPRESS_MILLIS 1000

typedef void (*button_handler)(void);

typedef struct {
  // Setup fields
  uint8_t pin;
  button_handler button_down_handler;
  button_handler short_press_handler;
  button_handler long_press_handler;
  // State fields
  int32_t state_begin;
  uint8_t state;
} button_controller;

void button_debounce_clock_setup();
void button_event_handler(button_controller*);

#endif // _BUTTON_H_
