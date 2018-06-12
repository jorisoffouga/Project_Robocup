/*
 * Adns3080.h
 *
 *  Created on: Mar 9, 2018
 *      Author: offou
 */

#ifndef ADNS3080_H_
#define ADNS3080_H_

#include "Spi.h"

#define Adns3080_product_id 0x00
#define Adns3080_product_id_value 0x17
#define Adns3080_x 0x03
#define Adns3080_y 0x04
#define MOTION 0x02
#define Adns3080_config 0x0A
#define MOTION_BURST 0x50

typedef enum {overlflow,no_overflow}status;

typedef struct{
  unsigned char product_id;
  signed char dx;
  signed char dy;
  unsigned char motion;
  spi adns3080;
  status overflow_status;
}adns3080;


void adns3080_get_device(adns3080 *sensor);
void adns3080_init(adns3080 *sensor);
void update_sensor(adns3080 *sensor);
void update_burst(adns3080 *sensor);
#endif /* ADNS3080_H_ */
