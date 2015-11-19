KERN_DIR = /work/work_source/real4418/kernel-3.4.39/
obj-m	+= mydevice.o
all:
	make -C $(KERN_DIR) M=`pwd` modules 

clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order

