/*
 * uart.c
 *
 *  Created on: May 30, 2018
 *      Author: offou
 */

#include "IO_Map.h"
#include "SCI1.h"
#include "Uart.h"
#define FBUS 25165824 //25165824 if not ppl fbus is 4194304
uart_type uart_isr;

ISR( isr_uart_rx){
  if (SCI1S1_RDRF == 1) {
      *uart_isr.p_write=SCI1D;
      uart_isr.buffer[uart_isr.nb_data]=*uart_isr.p_write;
      if ((uart_isr.p_write++)==(&uart_isr.buffer[NB_DATA_-1])) {
          uart_isr.p_write=uart_isr.buffer;
      }
      uart_isr.nb_data++;
  }
}

void uart_init(unsigned short baudrate,enum data nbdata,enum parite nparite,enum transmission nte,enum reception nre){
  SCI1BD=(unsigned int)((FBUS/(16.0*(float)baudrate))+0.5);//Calcul du Baudrate
  SCI1C1_M=nbdata;       //Selection configuration format data
  SCI1C1_PT=nparite;     //selection parité pair ou impair
  SCI1C2_TE=nte;         //activation ou désactivation de l'émission
  SCI1C2_RE=nre;         //activation ou désactivation de la réception 
  SCI1C2_RIE=1;

}

void uart_send(unsigned char *data,unsigned char nb_data){
  uart_type uart;
  unsigned char i=0;
  uart.p_write=NULL;
  for (i = 0; i < NB_DATA_; ++i) {
      uart.buffer[i]=0;
  }

  for (i = 0; i < nb_data; ++i) {
      uart.buffer[i]=data[i];
  }
  uart.p_write=uart.buffer;
  uart.nb_data=nb_data;

  while(uart.nb_data!=0){
      if (SCI1S1_TDRE) {
          SCI1D=*uart.p_write;
      }
      if ((uart.p_write++)==(&uart.buffer[NB_DATA_-1])) {
          uart.p_write=uart.buffer;
      }
      uart.nb_data--;
  }
}
