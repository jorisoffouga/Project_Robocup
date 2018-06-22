#include <stdio.h>  // Standard input/output definitions
#include <unistd.h> // UNIX standard function definitions
#include <fcntl.h>  // File control definitions
#include <errno.h>  // Error number definitions
#include <string.h> // String function definitions
#include <stdint.h> // Standard types
#include <stdlib.h>
#include "move.h"
#include "serial.h"

union{
  unsigned short data;
  struct {
    unsigned char val_h :8;
    unsigned char val_l :8;
  }value_bit;
}value;

static signed short forme_value(unsigned char val_h, unsigned char val_l){
  value.value_bit.val_h=val_h;
  value.value_bit.val_l=val_l;
  return value.data;

}
void display_help(const char *arg)
{
    fprintf(stderr, "Usage: %s \n", arg);
    fprintf(stderr, "Example: %s sudo /dev/ttyUSB0 9600\n", arg);
}

int main(int argc, char *agrv[])
{
    int i, fd = 0;
    char buffer[100];
    double angleX,angle,Y,angleZ;
    mouse_sensor sensor_1;
    mouse_sensor sensor_2;
    imu_sensor mpu6050;
    char *message="MPU6050 \r";

    if (argc < 3)
    {
        display_help(agrv[0]);
        return -1;
    }

    fd = open_serial(agrv[1], atoi(agrv[2]));

    if (fd < 0)
    {
        return -1;
    }

    for (;;)
    {

        read_serial(fd, buffer, '\r', 15,100);
        sensor_1.dx=buffer[0];
        sensor_1.dy=buffer[1];
        sensor_2.dx=buffer[2];
        sensor_2.dy=buffer[3];
        mpu6050.ax=forme_value(buffer[4],buffer[5]);
        mpu6050.ay=forme_value(buffer[6],buffer[7]);
        mpu6050.az=forme_value(buffer[8],buffer[9]);
        mpu6050.gx=forme_value(buffer[10],buffer[11]);
        mpu6050.gy=forme_value(buffer[12],buffer[13]);
        mpu6050.gz=forme_value(buffer[14],buffer[15]);

        printf("Action des Capteurs Optiques \n");
        printf("Capteur Optique 1 : \n \t");
        printf("%c \n \t",sensor_1.dx);
        printf("%c\n \t",sensor_1.dy);
        printf("|=================================================================|\n");

        printf("Capteur Optique 2 : \n \t");
        printf("%c \n \t",sensor_2.dx);
        printf("%c\n \t",sensor_2.dy);
        printf("|=================================================================|\n");

        printf("IMU \n");
        printf("Axe accélero X %d \n \t",mpu6050.ax);
        printf("Axe accéléro Y %d \n \t",mpu6050.ay);
        printf("Axe accéléro Z %d \n \t",mpu6050.az);
        printf("Axe gryo X %d \n \t",mpu6050.gx);
        printf("Axe gyro Y %d \n \t",mpu6050.gy);
        printf("Axe gyro Z %d \n \t",mpu6050.gz);
        printf("|=================================================================|\n");

        fflush(stdout);
        usleep(100000);
    }

    close_serial(fd);

    return 0;
}
