/*
 * Uart.h
 *
 *  Created on: May 31, 2018
 *      Author: offou
 */

#ifndef UART_H_
#define UART_H_
#define NULL ((void*)0)

#define NB_DATA_ 10

enum data{huit_bits=0,neuf_bits};
enum parite{off_pe,on_even=2,on_odd};
enum transmission{off_te=0,on_te};
enum reception{off_re=0,on_re};

void uart_init(unsigned short baudrate,enum data nbdata,enum parite nparite,enum transmission nte,enum reception nre);

typedef struct {
  unsigned char buffer[NB_DATA_];
  unsigned char *p_write;
  unsigned char nb_data;
}uart_type;
void init_buffer_uart(uart_type *uart,unsigned char *data,unsigned char nb_data);
void uart_send( uart_type *uart);

#endif /* UART_H_ */
