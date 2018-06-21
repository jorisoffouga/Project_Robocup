# Project_Robocup
 
 # Documentation 
 All datasheet of sensor and mcu and Report of projet 
 # Compile Application Host on linux
 Host / contains source codes to be used on PC

 Lauch command `make ` for compile 
 Exemple : `$ sudo ./main /dev/ttyUSB0 9600`

 # Robocup_SSL : Run with MC9S08QE16 
 Use the MCU with  [CodeWarrior IDE](https://www.nxp.com/support/developer-resources/software-development-tools/codewarrior-development-tools/codewarrior-legacy/codewarrior-development-studios/codewarrior-for-microcontrollers/codewarrior-for-mcus-eclipse-ide-coldfire-56800-e-dsc-kinetis-qorivva-56xx-rs08-s08-s12z-v11.0:CW-MCU10)


IMU Driver: [MPU6050.c](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Sources/Adns3080.c)  [MPU6050.h](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Project_Headers/MPU6050.h)

Optcal Sensor Driver: [Adns3080.c](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Sources/Adns3080.c)  [Adns3080.h](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Project_Headers/Adns3080.h)

SPI Driver: [SPI.c](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Sources/Spi.c) [SPI.h](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Project_Headers/Spi.h)

UART Driver: [Uart.c](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Sources/Uart.c) [Uart.h](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Sources/Move_ssl.c)

PID implementation: [PID.c](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Sources/PID.c) [PID.h](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Project_Headers/PID.h)

Robots Movements: [Move_ssl.c]() [Move_ssl.h](https://github.com/jorisoffouga/Project_Robocup/blob/master/Robocup_SSL/Project_Headers/Move_ssl.h)

# Hardware 
MCU architecture CISC NXP family 

USBDM base on HCS08 device [UBSDM](https://github.com/podonoghue/usbdm-hcs08) is integrated directly on board

View [Projet_MCU_Calculator](https://github.com/jorisoffouga/Project_Robocup/tree/master/Project_MCU_Calculator) for hardware design. Open this project with Altium Designer

# Sensors
IMU : MPU6050 on module GY-521
Angular Sensor : 
Mouse Optical Sensor : ADNS3080 on module CJMCU  