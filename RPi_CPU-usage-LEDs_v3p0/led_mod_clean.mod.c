#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xae9bea50, "module_layout" },
	{ 0x3cf24f26, "class_destroy" },
	{ 0xc317df93, "device_destroy" },
	{ 0xdd4de1a9, "device_remove_file" },
	{ 0xfe990052, "gpio_free" },
	{ 0xdba8efda, "device_create_file" },
	{ 0x470aa305, "device_create" },
	{ 0xfbde855f, "__class_create" },
	{ 0x34576e8f, "gpiod_direction_output_raw" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x7c32d0f0, "printk" },
	{ 0xf46fef7a, "filp_close" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0xa0d3b0c7, "gpiod_set_raw_value" },
	{ 0x788ec59, "gpio_to_desc" },
	{ 0x11a13e31, "_kstrtol" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "0464CB7EEB3C1C67A24CC31");
