/*
 * bsp.h
 *
 *  Created on: Oct 6, 2017
 *      Author: JorisJunior
 */

#ifndef BSP_H_
#define BSP_H_
#include "IO_Map.h"

#define Hauteur (24)
#define Largeur (80)
#define VT100_ESC       (27)
#define VT100_FORM_FEED (12)
#define putc(ch) {while (SCI1S1_TDRE == 0); SCI1D = (ch);}
void move (unsigned char x, unsigned char y);
void clear_screen(void);
void putcsch(unsigned char data);
void put_number(unsigned char binary,unsigned char x, unsigned char y);
void put_message(unsigned char x, unsigned char y, const unsigned char *message, unsigned char lenth);
#endif /* BSP_H_ */
