# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h -Os

LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as



all: main.elf



#additional rules for files

main.elf: ${COMMON_OBJECTS} main.o led.o switches.o statemachines.o buzzer.o wdInterrupthandler.o p2_interrupt_handler.o p1_interrupt_handler.o draw.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd



load:  main.elf
      msp430loader.sh 



clean:

	rm -f *.o *.elf *~
