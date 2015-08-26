CC      = arm-linux-gcc
LD      = arm-linux-ld
AR      = arm-linux-ar
OBJCOPY = arm-linux-objcopy
OBJDUMP = arm-linux-objdump
INCLUDEDIR 	:= -I$(shell pwd)/include -I$(shell pwd)/driver
CFLAGS 		:= -Wall -Os -fno-builtin-printf 
CPPFLAGS   	:= -nostdinc -nostdlib -fno-builtin 
export 	CC AR LD OBJCOPY OBJDUMP INCLUDEDIR CFLAGS CPPFLAGS 

main.bin: start.o main.o uart.o clock.o sdram.o math.o driver/libdriver.a  lib/libc.a
	arm-linux-ld -Tmain.lds -o main.elf $^
	arm-linux-objcopy -O binary main.elf main.bin
	arm-linux-objdump -D main.elf > main.dis


%.o : %.S
	${CC} $(CPPFLAGS) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

%.o : %.c
	${CC} $(CPPFLAGS) $(CFLAGS) $(INCLUDEDIR)  -c -o $@ $<
	
.PHONY : lib/libc.a
lib/libc.a:
	cd lib; make ; cd ..
	
.PHONY : driver/libdriver.a
driver/libdriver.a:
	cd driver; make; cd ..

clean:
	make  clean -C driver
	make  clean -C lib
	rm *.o main.elf main.bin main.dis
