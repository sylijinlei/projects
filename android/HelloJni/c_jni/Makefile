#BOARD = 4412
SRC=$(shell ls *.c)
OBJ=$(patsubst %.c,lib%.so,$(SRC))

ifeq ($(BOARD),4412)
CC=arm-linux-gcc
$(OBJ): $(SRC)
	@echo src == $(SRC)
	@echo obj == $(OBJ)
	$(CC)  -shared -fpic  -o $@ $<   -llog   
	#arm-linux-ar -rc -o $@ $< -llog
	cp $@ ../libs/armeabi/
else

CC=arm-linux-androideabi-gcc
$(OBJ): $(SRC)
	@echo src == $(SRC)
	@echo src == $(SRC)
	@echo obj == $(OBJ)
	$(CC) -shared -fPIC  -o $@ $(SRC)  --sysroot=$(SYS_ROOT) -llog 
	cp $@ ../libs/armeabi/

endif
clean:
	rm $(OBJ) ../libs/armeabi/$(OBJ)

