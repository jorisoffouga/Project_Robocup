
#include <stdio.h>   // Standard input/output definitions
#include <unistd.h>  // UNIX standard function definitions
#include <fcntl.h>   // File control definitions
#include <errno.h>   // Error number definitions
#include <termios.h> // POSIX terminal control definitions
#include <string.h>  // String function definitions
#include <sys/ioctl.h>
#include <stdint.h> // Standard types
#include "serial.h"

int open_serial(const char *portname,int baudrate)
{
	int fd;
	struct termios tty_settings;
	speed_t baud;

	//fd=open(portname,O_RDWR | O_NOCTTY | O_NDELAY);
	fd = open(portname, O_RDWR | O_NONBLOCK);

	if (fd == -1)
	{
		printf("Opening Failed in %s !! \n", portname);
		return -1;
	}
	else
	{
		printf("Successful opening  in %s !! \n", portname);
	}
	if (tcgetattr(fd, &tty_settings) < 0)
	{
		perror("open_serial: don't get attributes");
		return -1;
	}
	
	switch (baudrate)
	{
		case 9600:
			baud=B9600;
			break;
		case 115200:
			baud=B115200;
		default:
			break;
	}

	cfsetispeed(&tty_settings, baud); /* Set Read  Speed as 9600 */
	cfsetospeed(&tty_settings, baud); /* Set Write Speed as 9600 */
	tty_settings.c_cflag &= ~PARENB;   /* No Parity */
	tty_settings.c_cflag &= ~CSTOPB;   /* 1 Stop bit */
	tty_settings.c_cflag &= ~CSIZE;
	tty_settings.c_cflag |= CS8; /* Set 8 bits data */
	tty_settings.c_cflag &= ~CRTSCTS;
	tty_settings.c_cflag |= (CREAD | CLOCAL);
	tty_settings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG); /* Non Cannonical mode */
	tty_settings.c_oflag &= ~OPOST;
	tty_settings.c_cc[VMIN] = 0;
	tty_settings.c_cc[VTIME] = 0;
	tcsetattr(fd, TCSANOW, &tty_settings);
	if (tcsetattr(fd, TCSAFLUSH, &tty_settings) < 0)
	{ /* Save Configuration */
		printf("Configuration failed !!\n");
		return -1;
	}
	else
	{
		printf("Configuration Succes !! \n");
	}
	tcflush(fd, TCIFLUSH);
	return fd;
}

int write_serial(int fd, char *data)
{
	int len = strlen(data);
	if (write(fd, data, len) < len)
	{
		//printf("transmit failed !! \n");

		return -1;
	}
	return 0;
}

int read_serial(int fd, char *data, char until, char nb_data,int timeout)
{
	char buffer[1];
	int i = 0;
	fcntl(fd, F_SETFL, 10); /*Blocking mode for the read function, the program will wait for the reception of a character*/
	do
	{
		int temp = read(fd, buffer, 1);
		if (temp == -1) return -1;
		if(temp==0){
			usleep(1*1000);
			timeout--;
			if(timeout== 0) return -2;
			continue;

		}
		data[i] = buffer[0];
		i++;
	} while (buffer[0] != until && i < nb_data );

	/*for (i = 0; data[i] != until && i < nb_data+1; i++); /* delete end of string character */
	//data[i]=0;
	
	

	return 0;
}

int close_serial(int fd)
{
	sleep(2);
	tcflush(fd, TCIOFLUSH);
	if (close(fd) < 0)
	{
		printf(" Failed close serial port !! ");
		return -1;
	}
	return 0;
}
