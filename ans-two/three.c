
# include <linux/init.h>
# include <linux/kernel.h>
# include <linux/module.h>

# include <linux/sched.h>
# include <linux/list.h>

# define STRLEN 256

void
DFS (struct task_struct *t)
{
    struct task_struct *curr;
    struct list_head *l;

    list_for_each (l, &t->children)
    {
        curr = list_entry(l, struct task_struct, sibling);
        printk(KERN_INFO "[nir] %i\t%d\t%s\n",
            (int)curr->pid,
            curr->state,
            curr->comm
        );

        if (curr!=NULL)
        {
             DFS (curr);
        }
    }
}
int
_init_mod (void)
{
    printk(KERN_INFO "[nir] Loading module\n");
    printk(KERN_INFO "[nir] PID\tState\tName\n");

    DFS (&init_task);

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
MODULE_DESCRIPTION ("Task List DFS Tree");
MODULE_AUTHOR ("nir3al");
