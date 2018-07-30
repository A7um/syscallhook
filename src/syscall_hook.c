#include "asm.h"
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/syscalls.h>
#include <linux/kallsyms.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/unistd.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>
#include <linux/version.h>
#include <linux/syscalls.h>
#include <linux/slab.h>

#include <linux/dcache.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/seq_file.h>
#include <asm/mmu.h>
#include <linux/list.h>

#include "debug.h"

void *syscall_table;
void *syscall_table_backup;
int sys_found = 0;
int make_rw(void* address) {
    unsigned int level;
    pte_t *pte = lookup_address((long unsigned int)address, &level);
    printk(KERN_INFO "pte <%p>\n", pte);

    if (!pte) { /* NULL pointer error. */
        return 1;
    }

    if (pte->pte & ~_PAGE_RW)
        pte->pte |= _PAGE_RW;

    return 0;
}

int make_ro(void* address) {
    unsigned int level;
    pte_t *pte = lookup_address((long unsigned int)address, &level);

    if (!pte) { /* NULL pointer error. */
        return 1;
    }

    printk(KERN_INFO "pte <%p>\n", pte);

    pte->pte &= ~_PAGE_RW;

    return 0;
}

char *search_file(char *buf) {

    struct file *f;
    char *ver;
    mm_segment_t oldfs;

    oldfs = get_fs();
    set_fs (KERNEL_DS);

    f = filp_open(PROC_V, O_RDONLY, 0);

    if ( IS_ERR(f) || ( f == NULL )) {

        return NULL;

    }

    memset(buf, 0, MAX_LEN);

    vfs_read(f, buf, MAX_LEN, &f->f_pos);

    ver = strsep(&buf, " ");
    ver = strsep(&buf, " ");
    ver = strsep(&buf, " ");

    filp_close(f, 0);
    set_fs(oldfs);

    return ver;

}

static int find_sys_call_table (char *kern_ver) {

    char buf[MAX_LEN];
    int i = 0;
    char *filename;
    char *p;
    struct file *f = NULL;

    mm_segment_t oldfs;

    oldfs = get_fs();
    set_fs (KERNEL_DS);


#ifdef BOOT_PATH
    filename = kmalloc(strlen(kern_ver)+strlen(BOOT_PATH)+1, GFP_KERNEL);
    if ( filename == NULL ) {
        return -1;
    }

    memset(filename, 0, strlen(BOOT_PATH)+strlen(kern_ver)+1);
    strncpy(filename, BOOT_PATH, strlen(BOOT_PATH));
    strncat(filename, kern_ver, strlen(kern_ver));
#else
    filename = KALLSYMS;
#endif

    printk(KERN_ALERT "\nPath %s\n", filename);

    f = filp_open(filename, O_RDONLY, 0);

    if ( IS_ERR(f) || ( f == NULL )) {
        return -1;
    }

    memset(buf, 0x0, MAX_LEN);

    p = buf;
    while (vfs_read(f, p+i, 1, &f->f_pos) == 1) {
        if ( p[i] == '\n' || i == 255 ) {
            i = 0;
            if ( (strstr(p, "sys_call_table")) != NULL ) {
                char *sys_string;
                sys_string = kmalloc(MAX_LEN, GFP_KERNEL);
                if ( sys_string == NULL ) {
                    filp_close(f, 0);
                    set_fs(oldfs);
                    kfree(filename);
                    return -1;
                }
                memset(sys_string, 0, MAX_LEN);
                strncpy(sys_string, strsep(&p, " "), MAX_LEN);
                syscall_table = (void *) simple_strtoll(sys_string, NULL, 16);
                kfree(sys_string);
                break;
            }
            memset(buf, 0x0, MAX_LEN);
            continue;
        }
        i++;
    }

    filp_close(f, 0);
    set_fs(oldfs);

#ifdef BOOT_PATH
    kfree(filename);
#endif

    return 0;
}
int do_something(int syscall_num){
    //do something here
    	
    dbg_info("Catch syscall: %d", syscall_num);
    return 0;    
}

asmlinkage void syscall_springboard(void){
    SPRING_BOARD
}

asmlinkage void syscall_loader(void){
    int syscall_num;
    int e;
    //char *s;
    void* syscall_addr;
    HOOK_START

    //printk(KERN_ALERT "%d\n",syscall_num);
    //dbg_info("Catch syscall: %d", syscall_num);
    e = do_something(syscall_num);
    //s = get_proc_path();
    //printk("%s\n", s);
    //e = collect(syscall_num);

    HOOK_END
    
}



static int __init syscall_hook_init(void) {
    char *kern_ver;
    char *buf;
    void* springboard;
    int i;

    buf = kmalloc(MAX_LEN, GFP_KERNEL);
    if ( buf == NULL ) {
        sys_found = 1;
        return -1;
    }

    printk(KERN_ALERT "prepare hooking\n");

    kern_ver = search_file(buf);

    if ( kern_ver == NULL ) {
        sys_found = 1;
        return -1;
    }

    printk(KERN_ALERT "kernel version found: %s\n", kern_ver);

    if ( find_sys_call_table(kern_ver) == -1 ) {
        sys_found = 1;
        return -1;
    }

    sys_found = 0;
    printk(KERN_ALERT "syscall table found: %p\n", syscall_table);

    make_rw(syscall_table);

    syscall_table_backup = (void*) kmalloc(SYSCALL_MAX*sizeof(void*), GFP_KERNEL);

    memcpy(syscall_table_backup, syscall_table, SYSCALL_MAX*sizeof(void*));

    springboard = (void*) syscall_springboard;
    springboard += 0x9;
    printk(KERN_INFO "springboard at <%p>", springboard);

    for (i = 0; i < SYSCALL_MAX; i++) {
        if (i<=0x80)
            ((void **)syscall_table)[i] = (void *)(springboard+i*0x10);
        else
            ((void **)syscall_table)[i] = (void *)(springboard+0x800+0x13*(i-0x80));
    }
    make_ro(syscall_table);
    printk(KERN_INFO "syscall hooked");
    kfree(buf);
    return 0;
}


static void __exit syscall_hook_exit(void) {

    if ( sys_found == 0 ) {
        make_rw(syscall_table);
        memcpy(syscall_table, syscall_table_backup, SYSCALL_MAX*sizeof(void*));
        printk(KERN_INFO "syscall table restored.");
        kfree(syscall_table_backup);
        printk(KERN_INFO "backup syscall table freed.");
        make_ro(syscall_table);
    }
    printk(KERN_ALERT "\nsyscall unhooked\n");
    return;
}


module_init(syscall_hook_init);
module_exit(syscall_hook_exit);

MODULE_LICENSE("GPL");

