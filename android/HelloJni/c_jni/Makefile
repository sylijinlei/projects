#BOARD = 4412
SRC=$(shell ls *.c)
OBJ=$(patsubst %.c,lib%.so,$(SRC))

ifeq ($(BOARD),4412)
CC=arm-linux-gcc
$(OBJ):
	@echo src == $(SRC)
	@echo obj == $(OBJ)
	$(CC)  -shared -fpic  -o libled.so $(SRC)   -llog   
	cp libled.so ../libs/armeabi/
else

CC=arm-linux-androideabi-gcc
$(OBJ):
	@echo src == $(SRC)
	@echo obj == $(OBJ)
	$(CC) -shared -fPIC  -o $@ $(SRC)  --sysroot=$(SYS_ROOT) -llog 
	cp $@ ../libs/armeabi/

endif
clean:
	rm $(OBJ) ../libs/armeabi/$(OBJ)

