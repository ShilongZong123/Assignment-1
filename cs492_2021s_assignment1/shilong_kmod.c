#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h> 
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ShilongZong");
MODULE_DESCRIPTION("A Simple Hello World module for Assignment 1");

static int __init hello_init(void)
{
    printk(KERN_INFO "Hello World from ShilongZong (10428524)\n");
    return 0;
}

static void __exit hello_cleanup(void)
{
    int pid = task_pid_nr(current);
    const char* name = current->comm;
    printk(KERN_INFO "The process id is %d \n", pid);
    printk("The process name is \"%s\" \n", name);
}

module_init(hello_init);
module_exit(hello_cleanup);