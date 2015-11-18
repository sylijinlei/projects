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
	{ 0xa89a4edf, "platform_device_register" },
	{ 0xf1aec9be, "platform_device_unregister" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xea147363, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "E28B707A6C5EBF0788B9F3F");
