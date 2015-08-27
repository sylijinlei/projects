objs = hello.o
src = $(shell ls *.c)
libmyc.a:$(objs)
	ar -rc -o  $@ $^
libmyc.so:$(src)
	gcc $(INCLUDEDIR) -fPIC -shared -o $@ $<
%.o:%.c
	gcc $(INCLUDEDIR) -c -o $@ $<
clean:
	rm *.o *.a *.so
	
