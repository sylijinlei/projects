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
struct mychar_platform_data mychar_data = 
{
    .name = "jacky lee"
};
void mydevice_release(struct device *dev)
{
    printk("mydevice release!\n");
}
static struct resource mydevice_resource[] = {
[0] = {
    .start = 0x01,
    .end = 0x02,
    .flags = IORESOURCE_MEM,
},
[1] = {
    .start = 0x03,
    .end = 0x04,
    .flags = IORESOURCE_IRQ,
},
};
static struct platform_device mydevice_device = {
    .name = "mychar",
   .id = -1,
   .dev = {
     .release = mydevice_release,
     .p->driver_data= &mychar_data,
   },
   .num_resources = ARRAY_SIZE(mydevice_resource),
    .resource = mydevice_resource,

};
static int __init mydevice_init(void)                  
{  
    printk("mydevice driver init!\n");
    platform_device_register(&mydevice_device);
    return 0;  
} 

static void __exit mydevice_exit(void)                           
{  
    printk("mydevice driver exit!\n");
    platform_device_unregister(&mydevice_device);
}  
  
module_init(mydevice_init);  
module_exit(mydevice_exit);
MODULE_LICENSE("Dual BSD/GPL");     //不可省略，否则加载会报错
MODULE_AUTHOR("lijinlei<sylijinlei@163.com>");

