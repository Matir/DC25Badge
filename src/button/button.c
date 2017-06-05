#include "button.h"

#include <tc.h>
#include <port.h>

struct tc_module button_tc_instance;

void button_debounce_clock_setup() {
  // This is a stupid clock to count in 128-microsecond intervals.
  struct tc_config config_tc;

  tc_get_config_defaults(&config_tc);

  config_tc.counter_size = TC_COUNTER_SIZE_32BIT;
  config_tc.clock_prescaler = TC_CLOCK_PRESCALER_DIV1024;
  config_tc.run_in_standby = true;
  tc_init(&button_tc_instance, DEBOUNCE_TC, &config_tc);
}

void button_event_handler(button_controller *ctrl) {
  // This is an approximation.  .128ms*8 ~= 1ms
  uint32_t millis, elapsed;
  // Inverted because this is high when not presed
  uint8_t state = !port_pin_get_input_level(ctrl->pin);

  // Nothing doing if state is unchanged
  if (state == ctrl->state)
    return;

  millis = tc_get_count_value(&button_tc_instance) >> 3;
  // Theoretically, this could wrap, but I doubt the battery will last that
  // long.
  elapsed = millis - ctrl->state_begin;

  // Still in debounce phase
  if (elapsed < DEBOUNCE_MILLIS)
    return;

  // We have a state transition
  ctrl->state = state;
  ctrl->state_begin = millis;

  if (state) {
    // Button pressed
    if (ctrl->button_down_handler)
      ctrl->button_down_handler();
  } else {
    // Button released
    if (elapsed > LONGPRESS_MILLIS) {
      if (ctrl->long_press_handler)
        ctrl->long_press_handler();
    } else {
      if (ctrl->short_press_handler)
        ctrl->short_press_handler();
    }
  }
}
