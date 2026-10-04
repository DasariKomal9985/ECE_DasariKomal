#include<linux/module.h>
#include<linux/kernel.h>

static int __init my_driverinit(void)
{
	printk(KERN_INFO"My Driver Loaded");
	pr_info("driver loaded");
	return 0;
}

static void __exit my_driverexit(void)
{
	printk(KERN_INFO"My Driver Exit");
	pr_info("driver exit");
}

module_init(my_driverinit);
module_exit(my_driverexit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KOMAL");
MODULE_DESCRIPTION("Basic Kernel Linux Module");
