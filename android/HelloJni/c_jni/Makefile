CC=arm-linux-androideabi-gcc
all:
	$(CC) -shared -fPIC  -o libhello.so hello.c  --sysroot=$(SYS_ROOT) -llog 
	cp libhello.so ../libs/armeabi/
