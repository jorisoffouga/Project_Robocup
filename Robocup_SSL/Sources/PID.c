/*
 * PID.c
 *
 *  Created on: Jun 11, 2018
 *      Author: offou
 */
#include "IO_Map.h"

#define diametre_wheels 0.6
#define pi 3.14

#define kp 0
#define ki 0
#define kd 0

void asservissement (unsigned int consigne, unsigned int speed_moteur){
  static float error,error_p,s_error,d_error,speed_tr;
  static unsigned int cmd;
  
  speed_tr = ((60*speed_moteur)/(diametre_wheels*pi));
  
  error = consigne - speed_tr;
  
  d_error = error - error_p;
  
  s_error += error;
  
  cmd = kp*error + ki*s_error + kd * d_error;
  
  error_p = error;
  
  if (cmd > 0) {
    cmd = 0;
  }else if(cmd >65536){
      cmd = 65536;
  }
  TPM1C1V = cmd;
  
}
