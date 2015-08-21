
# include <linux/init.h>
# include <linux/kernel.h>
# include <linux/module.h>

# include <linux/sched.h>
# include <linux/list.h>

int
_init_mod (void)
{
    printk(KERN_INFO "[nir] Loading module\n");

    printk(KERN_INFO "S\tPID\tName\n");

    struct task_struct *task;
    for_each_process (task)
    {
        printk(KERN_INFO "%d\t%d\t%s \n",
            (int)task->state,
            task->pid,
            task->comm
        );
    }

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
