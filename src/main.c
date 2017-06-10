#include "config.h"

// ASF Headers
#include <port.h>
#include <ioport.h>
#include <delay.h>
#include <sleepmgr.h>
#include <system.h>
#include <stdio_usb.h>
#include <pinmux.h>
#include <spi.h>
#include <status_codes.h>
#include <extint.h>
#include <extint_callback.h>

// Standard Headers
#include <stdio.h>

#include "apa102c/apa102c.h"
#include "pattern/pattern.h"
#include "button/button.h"


extern struct spi_module spi_master;
extern struct spi_slave_inst spi_slave_dev;

button_controller btn_bright;
button_controller btn_pattern;

static void setup();
static void setup_spi();
static void setup_buttons();
static void button_callback_pattern();
static void button_callback_bright();
static void button_callback_bright_short();
static void button_callback_bright_long();

#define LED_PIN_IO IOPORT_CREATE_PIN(IOPORT_PORTA, LED_PIN)

int main() {
  setup();
  pattern_start();
  while(1) {
    ioport_toggle_pin_level(LED_PIN_IO);
    delay_ms(1000);
  }
}

static void setup() {
  system_init();
  irq_initialize_vectors();
  cpu_irq_enable();
  system_interrupt_enable_global();
  delay_init();
  sleepmgr_init();
  ioport_init();

  ioport_set_pin_dir(LED_PIN_IO, IOPORT_DIR_OUTPUT);

  // Redirect STDIO to the USB Port
  stdio_usb_init();
  // Disabled by default
  stdio_usb_disable();

  setup_spi();

  setup_buttons();
}

static void setup_spi() {
  // Setup SPI on SERCOM1 with the following settings:
  // MOSI = SERCOM1:PAD0
  // SCK = SERCOM1:PAD3
  // CS = SERCOM1:PAD2 (AKA PA18)

  struct spi_config cfg;
  struct spi_slave_inst_config slave_cfg;

  spi_slave_inst_get_config_defaults(&slave_cfg);
  slave_cfg.ss_pin = PIN_PA18;
  spi_attach_slave(&spi_slave_dev, &slave_cfg);

  spi_get_config_defaults(&cfg);
#if defined(XBOARD_SPARKFUN)
  cfg.mux_setting = SPI_SIGNAL_MUX_SETTING_N;
  cfg.pinmux_pad0 = PINMUX_PA16C_SERCOM1_PAD0;
  cfg.pinmux_pad1 = PINMUX_UNUSED;
  cfg.pinmux_pad2 = PINMUX_PA18C_SERCOM1_PAD2;
  cfg.pinmux_pad3 = PINMUX_PA19C_SERCOM1_PAD3;
#elif defined(XBOARD_TEST)
  cfg.mux_setting = SPI_SIGNAL_MUX_SETTING_D;
  cfg.pinmux_pad0 = PINMUX_PA16C_SERCOM1_PAD0;
  cfg.pinmux_pad1 = PINMUX_PA17C_SERCOM1_PAD1;
  cfg.pinmux_pad2 = PINMUX_PA18C_SERCOM1_PAD2;
  cfg.pinmux_pad3 = PINMUX_UNUSED;
#elif defined(XBOARD_XXV)
# error "Need mux settings."
#else
# error "Unknown board config."
#endif
  cfg.receiver_enable = false; // One way
  cfg.mode_specific.master.baudrate = 100000;  // 100k for now
  if (spi_init(&spi_master, SERCOM1, &cfg) != STATUS_OK )
  {
    printf("Failed to setup SPI instance.\r\n");
    return;
  }
  spi_enable(&spi_master);
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

static void setup_buttons() {
  struct extint_chan_conf config_int;

  // Setup pattern button
  extint_chan_get_config_defaults(&config_int);
  config_int.gpio_pin = PATTERN_BUTTON_PIN;
  config_int.gpio_pin_mux = PATTERN_BUTTON_MUX;
  config_int.gpio_pin_pull = EXTINT_PULL_UP;
  config_int.detection_criteria = EXTINT_DETECT_BOTH;
  extint_chan_set_config(PATTERN_BUTTON_PIN, &config_int);

  extint_register_callback(
      button_callback_pattern, PATTERN_BUTTON_PIN, EXTINT_CALLBACK_TYPE_DETECT);
  extint_chan_enable_callback(PATTERN_BUTTON_PIN, EXTINT_CALLBACK_TYPE_DETECT);

  button_debounce_default(&btn_pattern);
  btn_pattern.pin = PATTERN_BUTTON_PIN;
  btn_pattern.short_press_handler = pattern_next;
  btn_pattern.long_press_handler = pattern_off;

  // Setup brightness button
  extint_chan_get_config_defaults(&config_int);
  config_int.gpio_pin = BRIGHT_BUTTON_PIN;
  config_int.gpio_pin_mux = BRIGHT_BUTTON_MUX;
  config_int.gpio_pin_pull = EXTINT_PULL_UP;
  config_int.detection_criteria = EXTINT_DETECT_BOTH;
  extint_chan_set_config(BRIGHT_BUTTON_PIN, &config_int);

  extint_register_callback(
      button_callback_bright, BRIGHT_BUTTON_PIN, EXTINT_CALLBACK_TYPE_DETECT);
  extint_chan_enable_callback(BRIGHT_BUTTON_PIN, EXTINT_CALLBACK_TYPE_DETECT);

  button_debounce_default(&btn_bright);
  btn_bright.pin = BRIGHT_BUTTON_PIN;
  btn_bright.short_press_handler = button_callback_bright_short;
  btn_bright.long_press_handler = button_callback_bright_long;

  // Start the debounce clock
  button_debounce_clock_setup();
}

static void button_callback_pattern() {
  button_event_handler(&btn_pattern);
}

static void button_callback_bright() {
  button_event_handler(&btn_bright);
}

static void button_callback_bright_short() {
}

static void button_callback_bright_long() {
}
