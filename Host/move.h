#ifndef MOVE_H_
#define MOVE_H_


#define Modulo 1000
/*vector of motor 1 */
#define vector_m1x (float)(-0.3655*Modulo)
#define vector_m1y (float)(0.9371*Modulo)

/*vector of motor 2 */
#define vector_m2x (float)(-0.3685*Modulo)
#define vector_m2y (float)(-0.9296*Modulo)

/*vector of motor 3 */

#define vector_m3x (float)(0.7051*Modulo)
#define vector_m3y (float)(-0.7091*Modulo)

/* vector of motor 4 */
#define vector_m4x (float)(0.7074*Modulo)
#define vector_m4y (float)(0.7068*Modulo) 

typedef struct {
	signed char x;
	signed char y;
	unsigned char speed_robot;
}Direction;

typedef struct{
	float dmx;
	float dmy;
	float dmv;
	unsigned short speed_motor;
	unsigned char sens;
}motor_type;

typedef struct{
	motor_type motor_1;
	motor_type motor_2;
	motor_type motor_3;
	motor_type motor_4;
	unsigned char speed_robot;
}robot_type;

void get_direction(robot_type *robot,signed char x, signed char y, unsigned char speed);
void calcul_speed_motor(robot_type *robot);
void move(robot_type *robot);
void filter(unsigned short ax, unsigned short ay, unsigned short az, unsigned short gx, unsigned short gy, unsigned short gz, float dt, 
    double *angleX, double *angleY, double *angleZ);



#endif /* MOVE */
