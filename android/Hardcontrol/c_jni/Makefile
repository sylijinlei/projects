#BOARD = 4412
SRC=$(shell ls *.c)

ifeq ($(BOARD),4412)
CC=arm-linux-gcc
all:
	$(CC)  -shared -fpic  -o libled.so $(SRC)   -llog   
	cp libled.so ../libs/armeabi/

else
CC=arm-linux-androideabi-gcc
all:
	$(CC) -shared -fPIC  -o libhello.so $(SRC)  --sysroot=$(SYS_ROOT) -llog 
	cp libled.so ../libs/armeabi/
endif

