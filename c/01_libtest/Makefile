INCLUDEDIR = -I$(shell pwd)/include 
export INCLUDEDIR
objs=main.o 
main.bin: $(objs) libmyc.so libmyc.a
	gcc  $(INCLUDEDIR)   -o $@  $(objs)  -L$(shell pwd)/lib -lmyc 

.PHONY:libmyc.a
libmyc.a:
	cd lib; make libmyc.a; cd ..
.PHONY:libmyc.so
libmyc.so:
	cd lib; make libmyc.so; cd ..
%.o : %.c
	gcc $(INCLUDEDIR) -c -o $@ $< 
clean:
	rm -rf main.bin *.o
	make clean -C lib
