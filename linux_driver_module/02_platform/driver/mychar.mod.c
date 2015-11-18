#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x680d4942, "module_layout" },
	{ 0x15577af9, "platform_driver_register" },
	{ 0x4aabc7c4, "__tracepoint_kmalloc" },
	{ 0xac4487ae, "kmalloc_caches" },
	{ 0x562c075b, "dev_get_drvdata" },
	{ 0x9dfe54f7, "platform_get_resource" },
	{ 0xd401528c, "device_create" },
	{ 0x6d196b36, "__class_create" },
	{ 0x8c70d576, "cdev_add" },
	{ 0xfbd4afbb, "cdev_init" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0x445ad2b1, "kmem_cache_alloc_notrace" },
	{ 0x37a0cba, "kfree" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xc706d1d4, "cdev_del" },
	{ 0xd2187ea7, "class_destroy" },
	{ 0x475be915, "device_destroy" },
	{ 0xed5bfa7b, "platform_driver_unregister" },
	{ 0xea147363, "printk" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "16720DF6B787E7F3B5654CB");
