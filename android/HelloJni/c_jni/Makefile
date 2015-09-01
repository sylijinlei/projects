CC=arm-linux-androideabi-gcc
all:
	$(CC) -shared -fPIC  -o libhello.so hello.c  --sysroot=$(SYS_ROOT) /usr/local/android-ndk-r10//platforms/android-19/arch-arm/usr/lib/liblog.so 
	cp libhello.so ../libs/armeabi/
