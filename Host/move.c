#include <math.h>
#include "move.h"

void get_direction(robot_type *robot, signed char x, signed char y, unsigned char speed)
{

	robot->speed_robot = speed;

	robot->motor_1.dmx = (float)(x * vector_m1x);
	robot->motor_1.dmy = (float)(y * vector_m1y);
	robot->motor_1.dmv = robot->motor_1.dmx + robot->motor_1.dmy;

	robot->motor_2.dmx = (float)(x * vector_m2x);
	robot->motor_2.dmy = (float)(y * vector_m2y);
	robot->motor_2.dmv = robot->motor_2.dmx + robot->motor_2.dmy;

	robot->motor_3.dmx = (float)(x * vector_m3x);
	robot->motor_3.dmy = (float)(y * vector_m3y);
	robot->motor_3.dmv = robot->motor_3.dmx + robot->motor_3.dmy;

	robot->motor_4.dmx = (float)(x * vector_m4x);
	robot->motor_4.dmy = (float)(y * vector_m4y);
	robot->motor_4.dmv = robot->motor_4.dmx + robot->motor_4.dmy;
}

void calcul_speed_motor(robot_type *robot)
{

	robot->motor_1.speed_motor = (unsigned short)(((float)(60 * robot->speed_robot * robot->motor_1.dmv)) / 0.1884);
	robot->motor_2.speed_motor = (unsigned short)(((float)(60 * robot->speed_robot * robot->motor_2.dmv)) / 0.1884);
	robot->motor_3.speed_motor = (unsigned short)(((float)(60 * robot->speed_robot * robot->motor_3.dmv)) / 0.1884);
	robot->motor_4.speed_motor = (unsigned short)(((float)(60 * robot->speed_robot * robot->motor_4.dmv)) / 0.1884);
}
/*
void filter(unsigned short ax, unsigned short ay, unsigned short az, unsigned short gx, unsigned short gy, unsigned short gz, float dt,
			double *angleX, double *angleY, double *angleZ)
{
	double aX, aY, aZ;
	double gX, gY, gZ;

	aX = sqrt((ay * ay) + (az * az));
	aX = 58 * atan2(ax, aX);

	aY = sqrt((ax * ax) + (az * az));
	aY = 58 * atan2(ay, aY);

	aZ = sqrt((ay * ay) + (az * az));
	aZ = 58 * atan2(aZ, az);

	gX = gX + (dt * gx);
	gY = gY + (dt * gy);
	gZ = gZ + (dt * gz);

	*angleX = (0.04 * aX) + (0.96 * gX);
	*angleY = (0.04 * aY) + (0.96 * gY);
	*angleZ = (0.04 * aZ) + (0.96 * gZ);
}
*/