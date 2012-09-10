CFLAGS = -Wall -Werror -g

all: mcu

mcu: mcu.o derv.o

clean:
	-rm -rf mcu *.o
