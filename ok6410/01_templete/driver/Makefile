objs := led.o nand.o
libdriver.a: $(objs)
	${AR} -r -o $@ $^

%.o : %.c
	${CC} $(CPPFLAGS) $(CFLAGS) $(INCLUDEDIR)  -c -o $@ $<
clean:
	rm -f libdriver.a *.o		
