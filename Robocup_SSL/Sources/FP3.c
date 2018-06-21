/*
 * FP3.c
 *
 *  Created on: Mar 9, 2018
 *      Author: offou
 */


#include "FP3.h"

void filter (unsigned short ax, unsigned short ay, unsigned short az, unsigned short gx, 
    unsigned short gy, unsigned short gz, float *anglex, float *angley, float *anglez){
    
    static float angle_gx=0,angle_gy=0,angle_gz=0;
    float temp=0,angle_ax=0, angle_ay=0,angle_az=0;
    const float timer=10.17e-3;
    const float rad_to_degres = 180/3.14;
    
    temp = az*az;
    temp+=ax*ax;
    temp = sqrtf(temp);
    angle_ax=(atan2f(ay,temp))*rad_to_degres;
    
    temp = az*az;
    temp += ay*ay;
    temp = sqrtf(temp);
    angle_ay = (atan2f(ax,temp))*rad_to_degres;
    
    temp = ax*ax;
    temp += ay*ay;
    temp = sqrtf(temp);
    angle_az = (atan2f(temp,az))*rad_to_degres;
    
    angle_gx = angle_gx + gx*timer;
    angle_gy = angle_gy + gy*timer;
    angle_gz = angle_gz + gz*timer;
    
    *anglex = ((0.96*angle_gx) + (0.04*angle_ax));
    *angley = ((0.96*angle_gy) + (0.04*angle_ay));
    *anglez = ((0.96*angle_gz) + (0.04*angle_az));
    
  
}









void delai(unsigned short time){
  unsigned short i;
  for (i = time; i > 0; i--) {
    
  }
}
