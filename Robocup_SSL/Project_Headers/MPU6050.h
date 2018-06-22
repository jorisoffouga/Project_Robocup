/*
 * MPU6050.h
 *
 *  Created on: Mar 20, 2018
 *      Author: offou
 */

#ifndef MPU6050_H_
#define MPU6050_H_

// Address if AD0=GND or no connected 
#define MPU6050_ADDRESS  0x68
// register who am i 
#define MPU6050_WHO_AM_I 0x75
// register configuration 
#define MPU6050_CONFIG 0x1A
#define MPU6050_CONFIG_GYRO 0x1B
#define MPU6050_CONFIG_ACCEL 0x1C
#define MPU6050_RA_PWR_MGMT_1 0x6B
// Register accelerometer 
#define MPU6050_ACCEL_XH 0x3B
#define MPU6050_ACCEL_XL 0x3C
#define MPU6050_ACCEL_YH 0x3D
#define MPU6050_ACCEL_YL 0x3E
#define MPU6050_ACCEL_ZH 0x3F
#define MPU6050_ACCEL_ZL 0x40
// Register gyroscope
#define MPU6050_GYRO_XH  0x43
#define MPU6050_GYRO_XL  0x44
#define MPU6050_GYRO_YH  0x45
#define MPU6050_GYRO_YL  0x46
#define MPU6050_GYRO_ZH  0x47
#define MPU6050_GYRO_ZL  0x48
// Register temperature
#define MPU6050_TEMP_H 0x41
#define MPU6050_TEMP_L 0x42
//Sensibility define for sensibility change if you change value in function mpu6050_init
#define SENSITIVITY_ACCEL 16384 //0 for 16384 LSB/g, 1 for 8192 LSB/g, 2 for 4096 LSB/g, 3 for 2048 LSB/g
#define SENSITIVITY_GYRO 131 // 0 for 131 LSB/°/s, 1 for 65.5 LSB/°/s, 2 for 32.8 LSB/°/s, 3  for 16.4 LSB/°/s

typedef enum {no_connected,connected}status;
typedef struct {
  signed short ax;
  signed short ay;
  signed short az;
  signed short gx;
  signed short gy;
  signed short gz;
  float temp;
  uint8_t who_am_i;
  status mpu6050_status;
}mpu6050_t;


void mpu6050_init(void);
unsigned char mpu6050_get_config(void);
void mpu6050_get_device(mpu6050_t *mpu6050);
void mpu6050_get_acceleration(mpu6050_t *mpu6050);
void mpu6050_get_gyro(mpu6050_t *mpu6050);
void mpu6050_update(mpu6050_t *mpu6050);
void mpu6050_get_temp(mpu6050_t *mpu6050);
void MPU6050_write(unsigned short*data);
void MPU6050_read(unsigned char reg, unsigned char *data);

#endif /* MPU6050_H_ */
