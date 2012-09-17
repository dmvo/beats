CFLAGS = -Wall -Werror -g
LDFLAGS = -lm

TESTS = testderv

all: mcu

check: $(TESTS)

testderv: testderv.o derv.o

mcu: mcu.o derv.o

clean:
	-rm -rf mcu *.o
