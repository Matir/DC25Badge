#include "config.h"

// ASF Headers
#include <port.h>
#include <delay.h>
#include <sleepmgr.h>
#include <system.h>
#include <stdio_usb.h>

// Standard Headers
#include <stdio.h>

static void setup();

int main() {
  setup();
  while(1) {
    delay_ms(100);
    printf("Hello.\n");
  }
}

static void setup() {
  system_init();
  irq_initialize_vectors();
  delay_init();
  sleepmgr_init();

  // Redirect STDIO to the USB Port
  stdio_usb_init();
}
