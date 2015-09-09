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
	{ 0xf7bbbc07, "module_layout" },
	{ 0x638e5b40, "cdev_del" },
	{ 0xe1cca45, "class_destroy" },
	{ 0xeea5a92e, "device_destroy" },
	{ 0xa49366f, "kmalloc_caches" },
	{ 0x37a0cba, "kfree" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x27e1a049, "printk" },
	{ 0x856da6f4, "device_create" },
	{ 0xf1b8e7d1, "__class_create" },
	{ 0xfad699db, "cdev_add" },
	{ 0x7fd8505b, "cdev_init" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xec14d3d2, "kmem_cache_alloc_trace" },
	{ 0x432fd7f6, "__gpio_set_value" },
	{ 0x6d4d6df5, "s3c_gpio_cfgpin" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

