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
#include "EInt1.h"
#include "PWM1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "FP3.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
mpu6050_t mpu6050;
const float timer=20.35e-3;
static unsigned short ay,az,ax,gx,gy,gz,angleX,angleY,angleZ;



ISR(ISR_IMU){
  mpu6050_update(&mpu6050);
  ax=mpu6050.ax;
  ay=mpu6050.ay;
  az=mpu6050.az;
  gx=mpu6050.gx;
  gy=mpu6050.gy;
  gz=mpu6050.gz;
  //filter(ax,ay,az,gx,gy,gz,timer,&angleX,&angleY,&angleZ); 
  TPM1C0SC_CH0F = 0;
  
}

extern uart_type uart_isr;
void main(void)
{
  /* Write your local variable definition here */
  //unsigned char update_imu=1;
  adns3080 sensor;
  mpu6050_t mpu6050;
  unsigned char message[2]={0xAA,0x55};
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  uart_init(115200,huit_bits,off_pe,on_te,on_re);
  spi_init(enable,master,low,middle_front,msb,manual,i_o,rate_divisor_8);
  mpu6050_init();
  mpu6050_get_device(&mpu6050);
  //adns3080_init(&sensor);
  //adns3080_get_device(&sensor);
  //clear_screen();
  for(;;){
      //mpu6050_update(&mpu6050);
      //put_message(4,5,message,8);
      //put_number((100*100/255),4,5);
      uart_send(message,2); 
      //update_sensor(&sensor);
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
  PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
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
