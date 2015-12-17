#include<linux/init.h> 
#include<linux/module.h> 
#include<linux/fs.h> 
#include<linux/cdev.h> 
#include<linux/device.h>
#include<linux/slab.h>
#include <linux/gpio.h>
#include <linux/platform_device.h>

struct mychar_platform_data{
    char *name;
};
#define     MYCHAR_DEV_NAME   "mychar_dev"               //在/dev目录下创建的设备节点名
static  int   mychar_major  = 0;                      //0表示动态申请设备号，可以设置成未被申请的设备号
struct mychar_dev{                           
	struct cdev cdev;                              //定义cdev结构  
	dev_t dev_num;                                //设备号
	struct class *class;									
	struct device *device;                         //类class和device用于动态创建设备节点
    struct resource *res_irq;
    struct mychar_platform_data *mychar_data;
};
static struct mychar_dev   *mychar_dev;              //定义设备结构体的全局指针，在加载驱动的时候动态申请

const struct platform_device_id mychar_dev_id[]={
    {"mychar", 1},
    {"mychar2", 1},
};

static int mychar_open(struct inode *inode, struct file *file)
{	
    return 0;
}

static int mychar_close(struct inode *inode, struct file *file)
{
	return 0;
}

static ssize_t mychar_read(struct file *file, char __user *buff,
        size_t count, loff_t * loff)
{
    return 0;
}

static ssize_t mychar_write(struct file *file, const char __user *buff,
        size_t count, loff_t *loff)
{
    return 0;
}

static long mychar_ioctl(struct file *file, 
	unsigned int cmd, unsigned long arg)
{
	return 0;
}

static struct file_operations mychar_fops = {
    .owner = THIS_MODULE,
    .open = mychar_open,
    .read = mychar_read,
    .write = mychar_write,
    .unlocked_ioctl = mychar_ioctl,
    .release = mychar_close,
};
static int mychar_probe(struct platform_device *pdev)
{
	int ret;
    printk("mychar driver probe!\n");
    /*printk("driver name = %s\n", dev->id_entry->name);*/
    
	mychar_dev   = (struct mychar_dev *)kmalloc(sizeof(struct mychar_dev),GFP_KERNEL);   //为设备结构体动态申请内存
	if(mychar_dev == NULL)
		 goto fail_kmalloc;                                               //申请内存失败
   
	 if(mychar_major)
	 {
		 mychar_dev->dev_num = MKDEV(mychar_major, 0);     //将主次编号组合为dev_t类型
		 ret = register_chrdev_region(mychar_dev->dev_num, 1, "mychar_devno");	       //静态申请设备号，1是申请的设备号数
	 }
	 else 
	{
		 ret = alloc_chrdev_region(&mychar_dev->dev_num, 0, 1, "mychar_dev");     //动态申请设备号， 0表示次设备号
	 }
	 if (ret < 0)
		 goto fail_register;                     //若申请设备号失败
	 
	 cdev_init(&mychar_dev->cdev, &mychar_fops);                 //设备初始化，和file_operations结构体绑定                      
	 mychar_dev->cdev.owner = THIS_MODULE;
	 ret = cdev_add(&mychar_dev->cdev, mychar_dev->dev_num, 1);  //向内核添加设备，1表示添加的设备号数
	 if(ret)
		 goto fail_add;
	 
	 mychar_dev->class = class_create(THIS_MODULE, "mychar");
	 mychar_dev->device = device_create(mychar_dev->class, NULL, mychar_dev->dev_num, NULL, MYCHAR_DEV_NAME);     //创建class类和设备，自动创建设备节点

     /****************************************************添加功能代码********************************************************************************************/
     mychar_dev->res_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
     mychar_dev->mychar_data = pdev->dev.platform_data;

     printk("platform_data name = %s\n", mychar_dev->mychar_data->name);
     
     
     /****************************************************添加功能代码********************************************************************************************/

    return ret;
     
	 fail_add:
		 printk("driver: fail add cdev\n");
		 unregister_chrdev_region(mychar_dev->dev_num, 1);  
	 fail_register:
		 printk("driver: fail register mychar dev1\n");
		 kfree(mychar_dev);
	 fail_kmalloc:
		 printk("driver: fail kmalloc!\n");
    return 0;
}
static int mychar_remove(struct platform_device *dev)
{
    printk("mychar driver remove!\n");
	device_destroy(mychar_dev->class, mychar_dev->dev_num);            //设备销毁
	class_destroy(mychar_dev->class);																//类的注销
	cdev_del(&mychar_dev->cdev);																		//字符设备的注销
	unregister_chrdev_region(mychar_dev->dev_num,1);							//设备号的注销
	kfree(mychar_dev);                                            //释放设备结构体内存
    return 0;
}
static struct platform_driver mychar_driver={
    .probe = mychar_probe,
    .remove = mychar_remove,
    .id_table = mychar_dev_id,
    .driver = {
        .name = "mychar",
        .owner = THIS_MODULE,
    },
};
static int __init mychar_init(void)                  
{  
    printk("mychar driver init!\n");
    platform_driver_register(&mychar_driver);
    return 0;  
} 

static void __exit mychar_exit(void)                           
{  
    printk("mychar driver exit!\n");
    platform_driver_unregister(&mychar_driver);
}  
  
module_init(mychar_init);  
module_exit(mychar_exit);
MODULE_LICENSE("Dual BSD/GPL");     //不可省略，否则加载会报错
MODULE_AUTHOR("lijinlei <sylijinlei@163.com>");

