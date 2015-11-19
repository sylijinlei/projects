KERN_DIR = /work/work_source/real4418/kernel-3.4.39/
obj-m += gt9xx_drv.o
gt9xx_drv-objs :=  gt9xx_update.o goodix_tool.o  gt9xx.o
all:
	make -C $(KERN_DIR) M=`pwd` modules 

clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order

