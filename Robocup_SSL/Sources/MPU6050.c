/*
 * MPU6050.c
 *
 *  Created on: Mar 20, 2018
 *      Author: offou
 */

#include "FP3.h"
#include "MPU6050.h"
#include "CI2C1.h"
#include <math.h>

static signed short forme_value(unsigned char val_h, unsigned char val_l);
union{
  unsigned short data;
  struct {
    unsigned char val_h :8;
    unsigned char val_l :8;
  }value_bit;
}value;

unsigned char dummy=0;

void mpu6050_get_device(mpu6050_t *mpu6050){
  MPU6050_read(MPU6050_WHO_AM_I,&mpu6050->who_am_i);
  if(mpu6050->who_am_i == MPU6050_ADDRESS){ // function for verify connection to sensor 
      mpu6050->mpu6050_status=connected;
  }else {
      mpu6050->mpu6050_status=no_connected;
  }
}

unsigned char mpu6050_get_config(void){
  unsigned char config=0x00;
  MPU6050_read(MPU6050_CONFIG,&config);
  return config;
}

void mpu6050_init(void){
 
  unsigned short config_global=0x6B00; // configure register of PMW for enable mpu6050, select PPL of mpu6050 with X axis gyroscope reference 
  unsigned short config_accel=0x1B00; // configure range for accelerometer 0 for ±2g, 1 for ±4g , 
  //2 for ±8g, 3 for ±16g see MPU6050.h for select correct sensibility  
  unsigned short config_gyro=0x1C00; //  configure range for accelerometer 0 for ± 250 °/s, 1 for ± 500 °/s, 
  //2 for ± 1000 °/s, 3 for ± 2000 °/s see MPU6050.h for select correct sensibility 
  
  MPU6050_write(&config_global);
  MPU6050_write(&config_gyro);
  MPU6050_write(&config_accel);
}

void mpu6050_get_acceleration(mpu6050_t *mpu6050){
  unsigned char val_h=0,val_l=0;
  // Reception  register accelerometer X 
  MPU6050_read(MPU6050_ACCEL_XH,&val_h);
  MPU6050_read(MPU6050_ACCEL_XL,&val_l);
  mpu6050->ax=forme_value(val_h,val_l);
  mpu6050->ax=mpu6050->ax / SENSITIVITY_ACCEL;

  // Reception register d'accelerometer Y 
  MPU6050_read(MPU6050_ACCEL_YH,&val_h);
  MPU6050_read(MPU6050_ACCEL_YL,&val_l);
  mpu6050->ay=forme_value(val_h,val_l);
  mpu6050->ay=mpu6050->ay / SENSITIVITY_ACCEL;
  
  // Reception register accelerometer Z 
  MPU6050_read(MPU6050_ACCEL_ZH,&val_h);
  MPU6050_read(MPU6050_ACCEL_ZL,&val_l);
  mpu6050->az=forme_value(val_h,val_l);
  mpu6050->az=mpu6050->az / SENSITIVITY_ACCEL;

}

void mpu6050_get_gyro(mpu6050_t *mpu6050){
  unsigned char val_h,val_l=0;
  // Reception register  gyroscope X 
  MPU6050_read(MPU6050_GYRO_XH,&val_h);
  MPU6050_read(MPU6050_GYRO_XL,&val_l);
  mpu6050->gx=forme_value(val_h,val_l);
  mpu6050->gx=mpu6050->gx / SENSITIVITY_GYRO;

  // Reception register gyroscope Y 
  MPU6050_read(MPU6050_GYRO_YH,&val_h);
  MPU6050_read(MPU6050_GYRO_YL,&val_l);
  mpu6050->gy=forme_value(val_h,val_l);
  mpu6050->gy=mpu6050->gy / SENSITIVITY_GYRO;

  // Reception register gyroscope Z 
  MPU6050_read(MPU6050_GYRO_ZH,&val_h);
  MPU6050_read(MPU6050_GYRO_ZH,&val_l);
  mpu6050->gz=forme_value(val_h,val_l);
  mpu6050->gz=mpu6050->gz / SENSITIVITY_GYRO;
  
}

void mpu6050_get_temp(mpu6050_t *mpu6050){
  signed short val;
  unsigned char val_h=0,val_l=0;
  // Reception register temperature 
  MPU6050_read(MPU6050_TEMP_H,&val_h);
  MPU6050_read(MPU6050_TEMP_L,&val_l);
  val=forme_value(val_h,val_l);
  mpu6050->temp=((float)val /340.0)+ 36,53;
  //return mpu6050->temp_value;

}

void MPU6050_read(unsigned char reg, unsigned char *data){
  dummy=CI2C1_SelectSlave(MPU6050_ADDRESS);
  dummy=CI2C1_SendBlock(&reg,1,&CI2C1_SndRcvTemp);
  dummy=CI2C1_SelectSlave(MPU6050_ADDRESS);
  dummy=CI2C1_RecvBlock(data,1,&CI2C1_SndRcvTemp);

}

void MPU6050_write(unsigned short *data){
  dummy=CI2C1_SelectSlave(MPU6050_ADDRESS);
  dummy=CI2C1_SendBlock(data,2,&CI2C1_SndRcvTemp);
}

void mpu6050_update(mpu6050_t *mpu6050){
  mpu6050_get_acceleration(mpu6050);
  mpu6050_get_gyro(mpu6050);
  mpu6050_get_temp(mpu6050);
  
}

//Formating function 
static signed short forme_value(unsigned char val_h, unsigned char val_l){
  value.value_bit.val_h=val_h;
  value.value_bit.val_l=val_l;
  return value.data;

}


