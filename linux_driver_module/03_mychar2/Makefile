KERN_DIR = ~/sources/repo-client/Android/linux/kernel/kernel-3.4.39/
obj-m	+= mychar.o
all:
	make -C $(KERN_DIR) M=`pwd` modules 

clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order

