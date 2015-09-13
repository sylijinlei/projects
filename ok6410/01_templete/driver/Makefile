src = $(shell ls *.c)
objs := $(patsubst %.c,%.o,$(src))
libdriver.a: $(objs)
	${AR} -r -o $@ $^

%.o : %.c
	${CC} $(CPPFLAGS) $(CFLAGS) $(INCLUDEDIR)  -c -o $@ $<
clean:
	rm -f libdriver.a *.o		
