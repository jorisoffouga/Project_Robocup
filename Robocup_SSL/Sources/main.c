/* ###################################################################
 **     Filename    : main.c
 **     Project     : Robocup_SSL
 **     Processor   : MC9S08QE16CLC
 **     Version     : Driver 01.12
 **     Compiler    : CodeWarrior HCS08 C Compiler
 **     Date/Time   : 2018-06-12, 10:38, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.12
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "SCI1.h"
#include "CI2C1.h"
#include "TPM1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "FP3.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
mpu6050_t mpu6050;
adns3080 sensor_1;
adns3080 sensor_2;
extern uart_type uart_isr;
//static float angleX=0,angleY=0,angleZ=0;
//static unsigned short ay=0,az=0,ax=0,gx=0,gy=0,gz=0;

ISR(isr_update){
 
  Ncs_1=0;
  update_sensor(&sensor_1);
  Ncs_1=1;
  uart_send(&sensor_1.dx,1);
  uart_send(&sensor_1.dy,1);

  Ncs_2=0;
  update_sensor(&sensor_2);
  Ncs_2=1;
  uart_send(&sensor_2.dx,1);
  uart_send(&sensor_2.dy,1);

  mpu6050_update(&mpu6050);
  uart_send(&mpu6050.ax,2);
  uart_send(&mpu6050.ay,2);
  uart_send(&mpu6050.az,2);
  uart_send(&mpu6050.gx,2);
  uart_send(&mpu6050.gy,2);
  uart_send(&mpu6050.gz,2);
  uart_send('\r',1);
  /*
   angleX = angleX + mpu6050.gx *10.17e-3;
   angleY = angleY + mpu6050.gy *10.17e-3;
   angleZ = angleZ + mpu6050.gz *10.17e-3;
   ax=mpu6050.ax;
   ay=mpu6050.ay;
   az=mpu6050.az;
   gx=mpu6050.gx;
   gy=mpu6050.gy;
   gz=mpu6050.gz;
   filter(ax,ay,az,gx,gy,gz,&angleX,&angleY,&angleZ);
   */

  TPM1C0SC_CH0F = 0;

}

void main(void){
  /* Write your local variable definition here */
  unsigned char *message = "MPU6050\r";
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  uart_init(9024, huit_bits, off_pe, on_te, on_re);
  spi_init(enable, master, low, middle_front, msb, manual, i_o, rate_divisor_8);
  mpu6050_init();
  mpu6050_get_device(&mpu6050);
  adns3080_init(&sensor_1);
  adns3080_init(&sensor_2);
  adns3080_get_device(&sensor_1);
  adns3080_get_device(&sensor_2);

  for (;;){
      //uart_send(message,9);
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
  PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.3 [05.09]
 **     for the Freescale HCS08 series of microcontrollers.
 **
 ** ###################################################################
 */
