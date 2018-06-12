/*
 * kalman.h
 *
 *  Created on: May 22, 2018
 *      Author: offou
 */

#ifndef KALMAN_H_
#define KALMAN_H_

void filter(unsigned short ax, unsigned short ay, unsigned short az, unsigned short gx, unsigned short gy, unsigned short gz, unsigned short dt, 
    unsigned short *angleX, unsigned short *angleY, unsigned short *angleZ);


#endif /* KALMAN_H_ */
