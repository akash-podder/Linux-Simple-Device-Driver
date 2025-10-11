#include<linux/init.h>
#include<linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Akash Podder - Ramos Fan");
MODULE_DESCRIPTION("Akash's First Ever DEVICE Driver Code");

static struct proc_dir_entry *custom_proc_node;

static ssize_t ramos_read(
                    struct file* file_pointer,
                    char* user_space_buffer,
                    size_t count,
                    loff_t* offset)
{
    char msg[] = "Acknowledge Sergio Ramos!\n";
    size_t len = strlen(msg);

    printk("Ramos Device Driver Read called by User-Space Code\n");

    if(*offset >= len){
        return 0; // that means this Code block won't be executed
    }

    int result;
    result = copy_to_user(user_space_buffer, msg, len);

    *offset+=len;

    // As we return anython GREATED THAN 0, so, this "ramos_read(...)" function code will be again executed
    return len;
}

struct proc_ops my_driver_proc_ops = {
    .proc_read = ramos_read
};

// Constructor
static int ramos_module_init(void) {
    printk("ramos_module_init: Entry\n");
    
    custom_proc_node = proc_create(
                            "ramos_driver",
                            0,
                            NULL,
                            &my_driver_proc_ops
                        );

    printk("ramos_module_init: Exit\n");
    return 0;
}


// Destructor
static void ramos_module_exit(void) {
    printk("ramos_module_exit: Entry\n");

    printk("ramos_module_exit: Exit\n");
}

module_init(ramos_module_init);
module_exit(ramos_module_exit);