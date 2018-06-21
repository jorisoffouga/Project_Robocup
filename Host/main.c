#include <stdio.h>  // Standard input/output definitions
#include <unistd.h> // UNIX standard function definitions
#include <fcntl.h>  // File control definitions
#include <errno.h>  // Error number definitions
#include <string.h> // String function definitions
#include <stdint.h> // Standard types
#include <stdlib.h>
#include "move.h"
#include "serial.h"

void display_help(const char *arg)
{
    fprintf(stderr, "Usage: %s \n", arg);
    fprintf(stderr, "Example: %s sudo /dev/ttyUSB0 9600\n", arg);
}

int main(int argc, char *agrv[])
{
    int i, fd = 0;
    char buffer[100];
    double angleX,angle,Y,angleZ;
    char *message="MPU6050 \r";

    if (argc < 3)
    {
        display_help(agrv[0]);
        return -1;
    }

    fd = open_serial(agrv[1], atoi(agrv[2]));

    if (fd < 0)
    {
        return -1;
    }

    for (;;)
    {

        read_serial(fd, buffer, '\r', 9,1000);
        printf("%s ", buffer);
        //scanf("%10s", message);
        //write_serial(fd,message);
        //printf("%s",message);

        fflush(stdout);
        //usleep(100);
    }

    close_serial(fd);

    return 0;
}
