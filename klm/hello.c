#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

// notice that prefix different from module, just to show this is possible
static int helloKernel_init(void) {
    printk(KERN_INFO "Hello from kernel space!\n");
    return 0;
}

static void helloKernel_exit(void) {
    printk(KERN_INFO "Goodbye, kernel!\n");
}

// these macros allow you to specify init and exit functions (a change from
// early linux practice that imposed a naming convention
module_init(helloKernel_init);
module_exit(helloKernel_exit);
