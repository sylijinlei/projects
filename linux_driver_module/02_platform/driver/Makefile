KERN_DIR = /work/sources/ok6410/linux-2.6.36.2-v1.05/ 
obj-m	+= mychar.o
all:
	make -C $(KERN_DIR) M=`pwd` modules 

clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order

