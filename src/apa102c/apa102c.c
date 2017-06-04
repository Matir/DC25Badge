#include <spi.h>
#include "apa102c.h"

// These must be configured by a linked module
struct spi_module spi_master;
struct spi_slave_inst spi_slave_dev;

static void spi_send(const uint8_t *buffer, const uint16_t count);

const uint8_t null_frame[] = {0,0,0,0};

int num_pixels = 0;

void apa102c_frame_begin(){
  num_pixels = 0;
  spi_select_slave(&spi_master, &spi_slave_dev, true);
  // Send start marker
  spi_send(null_frame, 4);
}

void apa102c_send_pixel(pixel *data){
  // Upper 3 bits must be 111 per datasheet
  data->brightness |= 0xe0;
  spi_send((uint8_t *)data, 4);
  num_pixels++;
}

void apa102c_frame_end(){
  // Send end marker, 1 bit per pixel
  int num_frames = (num_pixels + 31) >> 5;
  spi_select_slave(&spi_master, &spi_slave_dev, false);
  do {
    spi_send(null_frame, 4);
  } while(--num_frames);
}

static void spi_send(const uint8_t *buffer, const uint16_t count) {
  // This is a blocking write.  For higher performance,
  // we could use a callback-based write.
  spi_write_buffer_wait(&spi_master, buffer, count);
}
