/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "button.h"

#include <string.h>

#include <tc.h>
#include <port.h>

struct tc_module button_tc_instance;

void button_debounce_default(button_controller *ctrl) {
  memset(ctrl, 0, sizeof(button_controller));
}

void button_debounce_clock_setup() {
  // This is a stupid clock to count in 1-millisecond intervals.
  struct tc_config config_tc;

  tc_get_config_defaults(&config_tc);

  config_tc.clock_source = GCLK_GENERATOR_1; // 1MHz clock
  config_tc.counter_size = TC_COUNTER_SIZE_32BIT;
  config_tc.clock_prescaler = TC_CLOCK_PRESCALER_DIV1024;
  config_tc.run_in_standby = true;
  tc_init(&button_tc_instance, DEBOUNCE_TC, &config_tc);
  tc_enable(&button_tc_instance);
}

void button_event_handler(button_controller *ctrl) {
  // This is an approximation.  1MHz/1024 ~= 1ms
  uint32_t millis, elapsed;
  // Inverted because this is high when not presed
  uint8_t state = !port_pin_get_input_level(ctrl->pin);

  // Nothing doing if state is unchanged
  if (state == ctrl->state)
    return;

  millis = tc_get_count_value(&button_tc_instance);
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
