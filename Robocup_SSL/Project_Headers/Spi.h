/*
 * Spi.h
 *
 *  Created on: Mar 9, 2018
 *      Author: offou
 */

#ifndef SPI_H_
#define SPI_H_

#define NB_DATA 11
#define Ncs_1 PTCD_PTCD3
#define Ncs_2 PTCD_PTCD2
#define NULL ((void*)0)

enum spi_enable{disable, enable };
enum mode_spi{slave, master};
enum polarity {high, low};
enum phase {first_front, middle_front};
enum type_data {msb, lsb};
enum ssoe {manual, auto_};
enum modfen {disable_mode, enable_mode};
enum baudrate_divisor{rate_divisor_2,rate_divisor_4,rate_divisor_8,rate_divisor_16,rate_divisor_32,rate_divisor_64,rate_divisor_128,rate_divisor_256,rate_divisor_512}; 

typedef struct{
  unsigned char buffer[NB_DATA];
  unsigned char *p_write;
  unsigned char *p_read;
  unsigned char nb_data;
}spi;

void spi_init(enum spi_enable status_spi, enum mode_spi spi_mode, enum polarity tpolarity, enum phase tphase, 
    enum type_data tdata, enum slave_mode smode, enum master_mode mmode, enum baudrate speed);

void init_spi_buffer(spi *spi_buffer,unsigned char *buffer,unsigned char nb_data);
void spi_transfer(spi *spi_buffer);

#endif /* SPI_H_ */
