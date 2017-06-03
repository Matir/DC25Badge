#ifdef __SAMD21G18A__
#include <samd21g18a.h>
#endif

#include <port.h>
#include <delay.h>

static void setup();

int main() {
  setup();
  while(1) {
    delay_ms(100);
  }
}

static void setup() {
  system_clock_init();
  delay_init();
}
