/*
 * kalman.c
 *
 *  Created on: May 22, 2018
 *      Author: offou
 */

#include "kalman.h"
#include "FP3.h"


void filter(unsigned short ax, unsigned short ay, unsigned short az, unsigned short gx, unsigned short gy, unsigned short gz, unsigned short dt, 
    unsigned short *angleX, unsigned short *angleY, unsigned short *angleZ){
  unsigned short  aX,aY,aZ;
  unsigned short gX,gY,gZ;
  
  aX=(unsigned short)sqrt((ay*ay) + (az*az));
  aX=(unsigned short)58* atan2(ax,aX);

  aY=(unsigned short)sqrt((ax*ax)+ (az*az));
  aY=(unsigned short)58* atan2(ay,aY);

  aZ=(unsigned short)sqrt((ay*ay)+ (az*az));
  aZ=(unsigned short)58* atan2(aZ,az);
  
  gX= gX + (dt* (unsigned short)gx);
  gY= gY + (dt* (unsigned short)gy);
  gZ= gZ + (dt* (unsigned short)gz);
  
  
  *angleX=(0.04*aX)+(0.96*gX);
  *angleY=(0.04*aY)+(0.96*gY);
  *angleZ=(0.04*aZ)+(0.96*gZ);
  
  
}

