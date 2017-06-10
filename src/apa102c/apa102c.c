#include <spi.h>
#include <spi_interrupt.h>
#include "apa102c.h"

// These must be configured by a linked module
struct spi_module spi_master;
struct spi_slave_inst spi_slave_dev;

void spi_send(const uint8_t *buffer, uint16_t count);
void spi_send_async(const uint8_t *buffer, uint16_t count);

const uint8_t null_frame[] = {0,0,0,0};

int num_pixels = 0;

void apa102c_frame_begin(){
  num_pixels = 0;
  spi_select_slave(&spi_master, &spi_slave_dev, true);
  // Send start marker
  spi_send(null_frame, sizeof(pixel));
}

void apa102c_send_pixel(pixel *data){
  // Upper 3 bits must be 111 per datasheet
  static pixel local_copy;
  // Block before overwriting previous
  spi_get_job_status_wait(&spi_master);
  local_copy = *data;
  local_copy.brightness |= 0xe0;
  spi_send((uint8_t *)&local_copy, sizeof(pixel));
  num_pixels++;
}

void apa102c_frame_end(){
  // Send end marker, 1 bit per pixel
  int num_frames = (num_pixels + 31) >> 5;
  spi_select_slave(&spi_master, &spi_slave_dev, false);
  do {
    spi_send(null_frame, sizeof(pixel));
  } while(--num_frames);
}

inline void spi_send(const uint8_t *buffer, uint16_t count) {
  // Sync
  spi_get_job_status_wait(&spi_master);
  spi_write_buffer_wait(&spi_master, (uint8_t *)buffer, count);
}

inline void spi_send_async(const uint8_t *buffer, uint16_t count) {
  // Async
  spi_write_buffer_job(&spi_master, (uint8_t *)buffer, count);
}
