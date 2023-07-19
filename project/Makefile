COMMON_OBJECTS = led.o switches.o buzzer.o
CPU            = msp430g2553
CFLAGS         = -mmcu=${CPU} -I../project/h
LDFLAGS        = -L/opt/ti/msp430_gcc/include

CC             = msp430-elf-gcc
AS             = msp430-elf-as

# Add the new header and source files for each module
COMMON_OBJECTS += led.o switches.o buzzer.o
SOURCE_FILES += toy.c toy.s ${COMMON_OBJECTS} ../demos/lib/libTimer.a

all: toy.elf load

toy.elf: ${SOURCE_FILES}
	@${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

load: toy.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf


