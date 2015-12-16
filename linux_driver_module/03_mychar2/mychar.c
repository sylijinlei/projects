#include<linux/init.h> 
#include<linux/module.h> 
#include<linux/fs.h> 
#include<linux/cdev.h> 
#include<linux/device.h>
#include<linux/slab.h>
#include <linux/gpio.h>

#define     DEV_NAME   "mychar"               //在/dev目录下创建的设备节点名
#define MINOR_COUNT 1
static  int   dev_major  = 0;                      //0表示动态申请设备号，可以设置成未被申请的设备号
static  int   dev_num  = 0;                      

struct mychar_dev{                           
	struct cdev cdev;                              //定义cdev结构  
	struct class *class;									
	struct device *device[MINOR_COUNT];                         //类class和device用于动态创建设备节点
};
static struct mychar_dev   *mychar_dev;              //定义设备结构体的全局指针，在加载驱动的时候动态申请
static struct file_operations test_fops;

//打开设备，对应用户空间的open系统调用
static int test_close(struct inode *inode, struct file *file)
{
	//可以进行一些资源的释放
    printk("%s\n", __func__);
	return 0;
}
static int test_open(struct inode *inode, struct file *file)
{	
    printk("%s\n", __func__);
    return 0;
}
static int mychar_open(struct inode *inode, struct file *file)
{	
	//可以进行一些初始化设置,资源的申请
    printk("%s\n", __func__);
    /*inode->i_cdev->ops = &test_fops;*/
    /*file->f_op = &test_fops;*/
    /*file->f_op->open(inode, file);*/
    /*printk("dev_num = %d\n", mychar_dev->dev_num);*/
    /*printk("major = %d\n", MAJOR(mychar_dev->dev_num));*/
    /*printk("minor= %d\n", MINOR(mychar_dev->dev_num));*/
    printk("dev_num = %d\n", inode->i_rdev);
    printk("inode major = %d\n", MAJOR(inode->i_rdev));
    printk("inode minor= %d\n", MINOR(inode->i_rdev));
    printk("inode dev count= %d\n", inode->i_cdev->count);
    return 0;
}

//关闭设备 ，对应用户空间的close系统调用
static int mychar_close(struct inode *inode, struct file *file)
{
	//可以进行一些资源的释放
    printk("%s\n", __func__);
	return 0;
}

  //读设备，对应用户空间的read系统调用
static ssize_t mychar_read(struct file *file, char __user *buff,
        size_t count, loff_t * loff)
{
    printk("%s\n", __func__);
    return 0;
}

//写设备，对应用户空间的write系统调用
static ssize_t mychar_write(struct file *file, const char __user *buff,
        size_t count, loff_t *loff)
{
    printk("%s\n", __func__);
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
static struct file_operations test_fops = {
    .owner = THIS_MODULE,
    .open = test_open,
    .read = mychar_read,
    .write = mychar_write,
    .unlocked_ioctl = mychar_ioctl,
    .release = test_close,
};

//设备初始化
static int __init mychar_init(void)                  
{  
    int ret;

    int minor;
    mychar_dev   = (struct mychar_dev *)kmalloc(sizeof(struct mychar_dev),GFP_KERNEL);   //为设备结构体动态申请内存
    if(mychar_dev == NULL)
        goto fail_kmalloc;                                               //申请内存失败

    if(dev_major)
    {
        ret = register_chrdev_region(MKDEV(dev_major, 0), MINOR_COUNT, DEV_NAME"_devno");	       //静态申请设备号，1是申请的设备号数
    }
    else 
    {
        ret = alloc_chrdev_region(&dev_num, 0, 5, DEV_NAME"_devno");     //动态申请设备号， 0表示起始次设备号
        if (ret < 0)
            goto fail_register;                     //若申请设备号失败
        dev_major = MAJOR(dev_num);
    }

    cdev_init(&mychar_dev->cdev, &mychar_fops);                 //设备初始化，和file_operations结构体绑定                      
    mychar_dev->cdev.owner = THIS_MODULE;
    ret = cdev_add(&mychar_dev->cdev, dev_num, MINOR_COUNT);  //向内核添加设备，1表示添加的设备号数,这里绑定了minor_count个
    if(ret)
        goto fail_add;

    mychar_dev->class = class_create(THIS_MODULE, DEV_NAME"_class");

    for(minor = 0; minor < MINOR_COUNT; minor++)
    {
        mychar_dev->device[minor] = device_create(mychar_dev->class, NULL, MKDEV(dev_major, minor), NULL, DEV_NAME"-%d", minor);     //创建class类和设备，自动创建设备节点
    }

    return ret;

fail_add:
    printk("driver: fail add cdev\n");
    unregister_chrdev_region(dev_num, MINOR_COUNT);  
fail_register:
    printk("driver: fail register mychar dev\n");
    unregister_chrdev_region(dev_num, minor);  
    kfree(mychar_dev);
fail_kmalloc:
    printk("driver: fail kmalloc!\n");
    return 0;  
} 

//设备注销，要注意资源注销的顺序，先申请的后注销
static void __exit mychar_exit(void)                           
{  
    int minor;
    for(minor = 0; minor < MINOR_COUNT; minor++)
    {
        device_destroy(mychar_dev->class, MKDEV(dev_major, minor));            //设备销毁
    }
    class_destroy(mychar_dev->class);																//类的注销
    cdev_del(&mychar_dev->cdev);																		//字符设备的注销
    unregister_chrdev_region(dev_num, MINOR_COUNT);							//设备号的注销
    kfree(mychar_dev);                                            //释放设备结构体内存
}  

module_init(mychar_init);  
module_exit(mychar_exit);
MODULE_LICENSE("Dual BSD/GPL");     //不可省略，否则加载会报错
