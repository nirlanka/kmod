# include <linux/init.h>
# include <linux/kernel.h>
# include <linux/module.h>
# include <linux/sched.h>
# include <linux/list.h>

int mod_init (void)
{
    printk(KERN_INFO "PID\tStatus\tCmd\n");

    struct task_struct *task;
    for_each_process (task) {
        printk(KERN_INFO "%d\t%d\t%s\n", task->pid, (int)task->state, task->comm);
    }
    return 0;
}

void mod_rem (void)
{
    printk(KERN_INFO "Removing module P1\n");
}

module_init (mod_init);
module_exit (mod_rem);

MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("Iterate tasks");
MODULE_AUTHOR ("cha");
