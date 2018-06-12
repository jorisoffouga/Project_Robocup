CC=gcc
CFLAGS=-lm
LDFLAGS=
EXEC=main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

main: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: serial.h move.h  

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o $(EXEC) 

mrproper: clean
	@rm -rf $(EXEC) *.o
