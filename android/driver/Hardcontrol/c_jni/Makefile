CC=arm-linux-gcc
all:
	$(CC) -I/usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ -shared -fPIC  -o libled.so led.c   -llog 
	cp libled.so ../libs/armeabi/
