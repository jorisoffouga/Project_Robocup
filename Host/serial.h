#ifndef SERIAL_H_
#define SERIAL_H_

int open_serial(const char *portname, int baudrate);
int write_serial(int fd,char *data);
int read_serial(int fd,char *data, char until, char nb_data);
int close_serial(int fd);

#endif /*SERIAL_H_ */
