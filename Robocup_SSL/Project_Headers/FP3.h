/*
 * FP3.h
 *
 *  Created on: Mar 9, 2018
 *      Author: offou
 */

#ifndef FP3_H_
#define FP3_H_

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Adns3080.h"
#include "MPU6050.h"
#include "bsp.h"
#include "math.h"
#include "Uart.h"


#define NULL ((void*)0)
#define LOW 0
#define HIGH 1
extern void delai(unsigned short time);
void filter (unsigned short ax, unsigned short ay, unsigned short az, unsigned short gx, 
    unsigned short gy, unsigned short gz, float *anglex, float *angley, float *anglez);

#endif /* FP3_H_ */
