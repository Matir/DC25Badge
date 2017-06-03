#include "config.h"

// ASF Headers
#include <port.h>
#include <ioport.h>
#include <delay.h>
#include <sleepmgr.h>
#include <system.h>
#include <stdio_usb.h>
#include <pinmux.h>

// Standard Headers
#include <stdio.h>

#define LED_PIN IOPORT_CREATE_PIN(IOPORT_PORTA, 27)

static void setup();

int main() {
  setup();
  while(1) {
    ioport_toggle_pin_level(LED_PIN);
    delay_ms(1000);
    //printf("Hello.\n");
  }
}

static void setup() {
  system_init();
  irq_initialize_vectors();
  cpu_irq_enable();
  delay_init();
  //sleepmgr_init();
  ioport_init();

  ioport_set_pin_dir(LED_PIN, IOPORT_DIR_OUTPUT);

  // Redirect STDIO to the USB Port
  //stdio_usb_init();
}


