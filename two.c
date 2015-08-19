
# include <linux/init.h>
# include <linux/kernel.h>
# include <linux/module.h>

# include <linux/sched.h>
# include <linux/list.h>

int
_init_mod (void)
{
    printk(KERN_INFO "[nir] Loading module\n");
    return 0;
}

void
_exit_mod (void)
{
    printk(KERN_INFO "[nir] Removing module\n");
}

module_init (_init_mod);
module_exit (_exit_mod);

MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("Module one");
MODULE_AUTHOR ("nir3al");
