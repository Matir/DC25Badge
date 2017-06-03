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
    printf("Hello.\r\n");
  }
}

static void setup() {
  system_init();
  irq_initialize_vectors();
  cpu_irq_enable();
  delay_init();
  sleepmgr_init();
  ioport_init();

  ioport_set_pin_dir(LED_PIN, IOPORT_DIR_OUTPUT);

  // Redirect STDIO to the USB Port
  stdio_usb_init();
  // Disabled by default
  stdio_usb_disable();
}

void discard_stdin() {
  // Sigh, apparently the CDC mode is blocking.
  // This runs from interrupt context
  while (udi_cdc_is_rx_ready())
    getchar();
}

void terminal_connected(bool set) {
  // This is used to prevent blocking with a full buffer.
  // Requires a terminal with DTR capabilities
  if (set)
    stdio_usb_enable();
  else
    stdio_usb_disable();
}
