/*
 * Spi.c
 *
 *  Created on: Mar 9, 2018
 *      Author: offou
 */

#include "Spi.h"
#include "IO_Map.h"

extern void delai(unsigned short time);

void spi_init(enum spi_enable status_spi, enum mode_spi spi_mode, enum polarity tpolarity, enum phase tphase, 
    enum type_data tdata, enum ssoe smode, enum ss mmode, enum baudrate speed){
  SPIBR=speed;
  SPIC2_MODFEN=mmode;
  SPIC1_SSOE=smode;
  SPIC1_CPHA=tphase;
  SPIC1_CPOL=tpolarity;
  SPIC1_LSBFE=tdata;
  SPIC1_MSTR=spi_mode;
  SPIC1_SPE=status_spi;
  PTCDD_PTCDD2=1;
  PTCDD_PTCDD3=1;
  PTADD_PTADD2=1;
  PTBPE_PTBPE4=1;
  PTCD_PTCD2=1;
  PTCD_PTCD3=1;
  /*
  PTBDD_PTBDD5=1;
  PTADD_PTADD2=1;
  SPIBR=0x02;
  SPIC2_MODFEN=0;
  SPIC1_SSOE=0;
  SPIC1_CPHA=1;
  SPIC1_CPOL=1;
  SPIC1_MSTR=1;
  SPIC1_SPE=1;
  PTBPE_PTBPE4=1;
  PTBD_PTBD5=1;
   */
  //Ncs_1=1;
  //Ncs_2=1;
}

void init_spi_buffer(spi *spi_buffer,unsigned char *buffer,unsigned char nb_data){
  unsigned char i=0;
  spi_buffer->p_read=NULL;
  spi_buffer->p_write=NULL;
  for (i = 0; i < NB_DATA; ++i) {
      spi_buffer->buffer[i]=0;
  }
  for (i=0; i<nb_data; ++i) {
      spi_buffer->buffer[i]=buffer[i];
  }
  spi_buffer->p_read=spi_buffer->buffer;
  spi_buffer->p_write=&(spi_buffer->buffer[5]);
  spi_buffer->nb_data=nb_data;
}


void spi_transfer(spi *spi_buffer){
  //PTBD_PTBD5=0;
  while (spi_buffer->nb_data!=0){
      if (SPIS_SPTEF) {
          SPID=*spi_buffer->p_read;
          delai(35);
      }
      if((spi_buffer->p_read++)==(&spi_buffer->buffer[NB_DATA-7])){
          spi_buffer->p_read=spi_buffer->buffer;
      }
      if (SPIS_SPRF) {
          *spi_buffer->p_write=SPID;
      }
      if((spi_buffer->p_write++)==(&spi_buffer->buffer[NB_DATA-1])){
          spi_buffer->p_write=spi_buffer->buffer;
      }

      spi_buffer->nb_data--;
  }
  //PTBD_PTBD5=1;
}





