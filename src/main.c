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

// Standard Headers
#include <stdio.h>

#include "apa102c/apa102c.h"


extern struct spi_module spi_master;
extern struct spi_slave_inst spi_slave_dev;

static void setup();
static void setup_spi();

#define LED_PIN IOPORT_CREATE_PIN(IOPORT_PORTA, 27)

int main() {
  int i, k;
  pixel px;
  setup();
  while(1) {
    ioport_toggle_pin_level(LED_PIN);
    // TODO, move this off to a clock
    // draw a sample
    for(i=0; i<8; i++) {
      apa102c_frame_begin();
      for(k=0;k<8;k++) {
        px.brightness = 16;
        if(i==k)
          px.red = 127;
        else
          px.red = 0;
        px.blue = 0;
        px.green = 0;
        apa102c_send_pixel(&px);
      }
      apa102c_frame_end();
      delay_ms(500);
      ioport_set_pin_dir(LED_PIN, IOPORT_DIR_OUTPUT);
    }
  }
}

static void setup() {
  system_init();
  irq_initialize_vectors();
  cpu_irq_enable();
  delay_init();
  sleepmgr_init();
  ioport_init();

  // Redirect STDIO to the USB Port
  stdio_usb_init();
  // Disabled by default
  stdio_usb_disable();

  setup_spi();
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
  cfg.mux_setting = SPI_SIGNAL_MUX_SETTING_N;
  cfg.receiver_enable = false; // One way
  cfg.pinmux_pad0 = PINMUX_PA16C_SERCOM1_PAD0;
  cfg.pinmux_pad1 = PINMUX_UNUSED;
  cfg.pinmux_pad2 = PINMUX_PA18C_SERCOM1_PAD2;
  cfg.pinmux_pad3 = PINMUX_PA19C_SERCOM1_PAD3;
  cfg.mode_specific.master.baudrate = 100000;  // 100k for now
  if (spi_init(&spi_master, SERCOM1, &cfg) != STATUS_OK )
  {
    printf("Failed to setup SPI instance.\n");
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
