# include <linux/init.h>
# include <linux/kernel.h>
# include <linux/module.h>
# include <linux/sched.h>
# include <linux/list.h>

void DFS (struct task_struct *task)
{
    struct task_struct *currentTask;
    struct list_head *list;

    list_for_each (list, &task->children) {
        currentTask = list_entry(list, struct task_struct, sibling);
        printk(KERN_INFO "%i\t%d\t%s\n", (int)currentTask->pid, currentTask->state, currentTask->comm);

        if (currentTask != NULL)
             DFS (currentTask);
    }
}

int mod_init (void)
{
    printk(KERN_INFO "Loading module\n");
    printk(KERN_INFO "PID\tState\tName\n");

    DFS (&init_task);

    return 0;
}

void mod_rem (void)
{
    printk(KERN_INFO "Removing module P2\n");
}

module_init (mod_init);
module_exit (mod_rem);

MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("Iterate tasks");
MODULE_AUTHOR ("cha");
