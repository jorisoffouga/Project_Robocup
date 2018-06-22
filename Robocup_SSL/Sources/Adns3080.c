/*
 * Adns3080.c
 *
 *  Created on: Mar 9, 2018
 *      Author: offou
 */

#include "Adns3080.h"
#include "FP3.h"

static void adns3080_write(adns3080 *sensor,unsigned char *data,unsigned char n);
static void adns3080_read(adns3080 *sensor,unsigned char reg,unsigned char n); 

void adns3080_init(adns3080 *sensor){
  unsigned char config[2]={0x8A,0x19};
  adns3080_write(sensor,config,2);

}
void adns3080_get_device(adns3080 *sensor){
  adns3080_read(sensor,Adns3080_product_id,1);
  sensor->product_id=sensor->adns3080.buffer[6];

}

void update_sensor(adns3080 *sensor){
  adns3080_read(sensor,MOTION,1);
  sensor->motion=sensor->adns3080.buffer[6];
  if (sensor->motion & 0x80) {
      sensor->overflow_status=no_overflow;
      adns3080_read(sensor,Adns3080_x,1);
      sensor->dx=sensor->adns3080.buffer[6];
      adns3080_read(sensor,Adns3080_y,1);
      sensor->dy=sensor->adns3080.buffer[6];
  } 
  else if(sensor->motion & 0x10) {
      sensor->overflow_status=overlflow;
  }
}

void update_burst(adns3080 *sensor){
  adns3080_read(sensor,MOTION_BURST,3);
  sensor->motion=sensor->adns3080.buffer[6];
  if (sensor->motion & 0x80) {
      sensor->overflow_status=no_overflow;
      sensor->dx=sensor->adns3080.buffer[7];
      sensor->dy=sensor->adns3080.buffer[8];
  }
  else if(sensor->motion & 0x10){
      sensor->overflow_status=overlflow;
  }
}
static void adns3080_write(adns3080 *sensor,unsigned char *data,unsigned char n){
  init_spi_buffer(&sensor->adns3080,data,n);
  spi_transfer(&sensor->adns3080);
}
static void adns3080_read(adns3080 *sensor,unsigned char reg,unsigned char n){
  unsigned char buffer[5]={0x00,0x00,0x00,0x00,0x00};
  buffer[0]=reg;
  n++;
  init_spi_buffer(&sensor->adns3080,buffer,n);
  spi_transfer(&sensor->adns3080);
}


