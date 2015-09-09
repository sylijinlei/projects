KERN_DIR = /work/sources/linux-3.0.86/ 
obj-m	+= myled.o
all:
	make -C $(KERN_DIR) M=`pwd` modules 

clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order

