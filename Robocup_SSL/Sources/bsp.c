/*
 * bsp.c
 *
 *  Created on: Oct 6, 2017
 *      Author: JorisJunior
 */

#include "bsp.h"



void move (unsigned char x, unsigned char y){
  putc(VT100_ESC);
  putc('[');
  putc('0' + (y / 100));
  putc('0' + ((y / 10) % 10));
  putc('0' + (y % 10));
  putc(';');
  putc('0' + (x / 100));
  putc('0' + ((x / 10) % 10));
  putc('0' + (x % 10));
  putc('H');
}

void clear_screen(void){
  putc(VT100_ESC);
  putc('[');
  putc('2');
  putc('J');
  putc(VT100_ESC);
  putc('[');
  putc('?');
  putc('2');
  putc('5');
  putc('l');
}

void putcsch(unsigned char data){
  const unsigned char tab[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  if (data & 0x80) {
      putc('-');
      data=~data;
      data++;
  }else{
      putc('+');
  }
  putc(tab[data>>4]);
  putc(' ');
  putc(tab[data & 0x0F]);
  putc('\r');
  putc('\n');
}

void put_message(unsigned char x, unsigned char y, const unsigned char *message, unsigned char lenth){
  unsigned char i=0;
  for(i=0; i<lenth; i++){
      move((x+i),y);
      putc(message[i]);
  }
}

void put_number(unsigned char binary,unsigned char x, unsigned char y){
  unsigned char i=0;
  unsigned char dec[3]={0,0,0};
  dec[2] = (binary % 10);             //calcul des unités
  binary = binary - dec[2];             //suppression des unités
  dec[1] = ((binary % 100)/10); //calcul des dizaines
  binary = binary - dec[1];             //suppression des dizaines
  dec[0] = ((binary % 1000)/100);       //calcul des centaines
  /*
  dec[0] += 0x30;                       //Ajustement ASCII
  dec[1] += 0x30;
  dec[2] += 0x30;
  */
  for (i = 0; i < 3; ++i) {
    dec[i]+=0x30;
  }
  for (i = 0; i < 3; ++i) {
      move((x+i), y);
      putc(dec[i]);
  }
}



