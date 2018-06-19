# Project_Robocup
 
 # Compile Application Host on linux
 Lauch command `make ` for compile 
 Exemple : `$ sudo ./main /dev/ttyUSB0 9600`

 # Run MCU : MC9S08QE16 
 Use the MCU with  [CodeWarrior IDE](https://www.nxp.com/support/developer-resources/software-development-tools/codewarrior-development-tools/codewarrior-legacy/codewarrior-development-studios/codewarrior-for-microcontrollers/codewarrior-for-mcus-eclipse-ide-coldfire-56800-e-dsc-kinetis-qorivva-56xx-rs08-s08-s12z-v11.0:CW-MCU10)

# Hardware 
MCU architecture CISC NXP family 

USBDM base on HCS08 device [UBSDM](https://github.com/podonoghue/usbdm-hcs08) is integrated directly on board

View [Projet_MCU_Calculator](https://github.com/jorisoffouga/Project_Robocup/tree/master/Project_MCU_Calculator) for hardware design. Open this project with Altium Designer

# Sensors
IMU : MPU6050 on module GY-521

Mouse Optical Sensor : ADNS3080 on module CJMCU  