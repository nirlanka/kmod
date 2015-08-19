
# include <linux/init.h>
# include <linux/kernel.h>
# include <linux/module.h>

// on load of module
int
one_init (void)
{
    printk(KERN_INFO "Loading module\n");
    return 0;
}

// on removal of module
void
one_exit (void)
{
    printk(KERN_INFO "Removing module\n");
}

// register entry and exit points
module_init (one_init);
module_exit (one_exit);

MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("Module one");
MODULE_AUTHOR ("nir3al");
