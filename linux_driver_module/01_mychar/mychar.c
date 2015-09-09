#include<linux/init.h> 
#include<linux/module.h> 
#include<linux/fs.h> 
#include<linux/cdev.h> 
#include<linux/device.h>
#include<linux/slab.h>
#include <linux/gpio.h>
#include <mach/gpio.h>
#include <plat/gpio-cfg.h>

#define     MYCHAR_DEV_NAME   "mychar_dev"               //在/dev目录下创建的设备节点名
static  int   mychar_major  = 0;                      //0表示动态申请设备号，可以设置成未被申请的设备号
struct mychar_dev{                           
	struct cdev cdev;                              //定义cdev结构  
	dev_t dev_num;                                //设备号
	struct class *class;									
	struct device *device;                         //类class和device用于动态创建设备节点
};
static struct mychar_dev   *mychar_dev;              //定义设备结构体的全局指针，在加载驱动的时候动态申请

//打开设备，对应用户空间的open系统调用
static int mychar_open(struct inode *inode, struct file *file)
{	
	//可以进行一些初始化设置,资源的申请
    return 0;
}

//关闭设备 ，对应用户空间的close系统调用
static int mychar_close(struct inode *inode, struct file *file)
{
	//可以进行一些资源的释放
	return 0;
}

  //读设备，对应用户空间的read系统调用
static ssize_t mychar_read(struct file *file, char __user *buff,
        size_t count, loff_t * loff)
{
    return 0;
}

//写设备，对应用户空间的write系统调用
static ssize_t mychar_write(struct file *file, const char __user *buff,
        size_t count, loff_t *loff)
{
    return 0;
}

//实现主控功能，对应用户空间的ioctl系统调用
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

//设备初始化
static int __init mychar_init(void)                  
{  
	int ret;
	
	int i;
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
     
	
	for (i = 0; i < 4; i++)
    {
		s3c_gpio_cfgpin(led_gpios[i], S3C_GPIO_OUTPUT);
    }
	
    pio_set_value(led_gpios[0], 1);
	gpio_set_value(led_gpios[1], 0);
	gpio_set_value(led_gpios[2], 0);
	gpio_set_value(led_gpios[3], 1);
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

//设备注销，要注意资源注销的顺序，先申请的后注销
static void __exit mychar_exit(void)                           
{  
	device_destroy(mychar_dev->class, mychar_dev->dev_num);            //设备销毁
	class_destroy(mychar_dev->class);																//类的注销
	cdev_del(&mychar_dev->cdev);																		//字符设备的注销
	unregister_chrdev_region(mychar_dev->dev_num,1);							//设备号的注销
	kfree(mychar_dev);                                            //释放设备结构体内存
}  
  
module_init(mychar_init);  
module_exit(mychar_exit);
MODULE_LICENSE("Dual BSD/GPL");     //不可省略，否则加载会报错

