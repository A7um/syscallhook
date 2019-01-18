#include <linux/init.h>
#include <linux/miscdevice.h>  
#include <linux/ioctl.h>  
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
#include "asm.h"
#include "debug.h"
#include "schk_ioctl.h"

void *syscall_table;
void *syscall_table_backup;
int sys_found = 0;
void *(g_ret_addr[65537]);
int g_syscall_num[65537];
unsigned long g_syscall_argv[65537][7];
int g_schk_flag[65537];
unsigned long g_retval[65537];
void* presyscall_hook_addr;
void* postsyscall_hook_addr;
int make_rw(void* address) {
	unsigned int level;
	pte_t *pte = lookup_address((long unsigned int)address, &level);
	dbg_info("pte <%lx>\n", (unsigned long)pte);

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

	dbg_info("pte <%lx>\n", (unsigned long)pte);

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

	dbg_info("\nPath %s\n", filename);

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
int do_something_enable(pid_t pid){
	//do something here
	dbg_info("syscall hook enabled at pid %d",pid);
    return 0;
}
int do_something_disable(pid_t pid){
	//do something here
    dbg_info("syscall hook disabled at pid %d",pid);
	return 0;
}
int do_something_pre(void){
	//do something here
	dbg_info("pre-syscall: %d ", g_syscall_num[current->pid]);
	return 0;    
}
int do_something_post(void){
	//do something here
	dbg_info("post-syscall: %d ", g_syscall_num[current->pid]);
	if((g_syscall_num[current->pid]==__NR_exit || g_syscall_num[current->pid]==__NR_exit)){
		g_schk_flag[current->pid]=0;
		do_something_disable(current->pid);
	}
	else if((g_syscall_num[current->pid]==__NR_fork || g_syscall_num[current->pid]==__NR_vfork|| g_syscall_num[current->pid]==__NR_clone)){
		if((int)g_retval[current->pid]>0&&g_schk_flag[current->pid]&SCHK_FLAG_INHERIT){
			g_schk_flag[g_retval[current->pid]]|=SCHK_FLAG_ENABLE;
			g_schk_flag[g_retval[current->pid]]|=SCHK_FLAG_INHERIT;
			do_something_enable(g_retval[current->pid]);
		}
	}
	else if((g_syscall_num[current->pid]==__NR_execve&&g_schk_flag[current->pid]&SCHK_FLAG_ENABLE_ON_EXEC)){
		g_schk_flag[current->pid]|=SCHK_FLAG_ENABLE;
		do_something_enable(g_retval[current->pid]);

	}
	return 0;    
}
asmlinkage void syscall_landingboard(void){
	LANDING_BOARD
}

asmlinkage void postsyscall_hook(void){
	unsigned long retval;
	void* ret_addr;
	HOOK_START_POSTSYSCALL
		g_retval[current->pid]=retval;
	if(g_schk_flag[current->pid]){
		do_something_post();
	}
	ret_addr=g_ret_addr[current->pid];
	g_ret_addr[current->pid]=0;
	HOOK_END_POSTSYSCALL
}
asmlinkage void presyscall_hook(void){
	int syscall_num;
	void* syscall_addr;
	void* ret_addr;
	unsigned long syscall_argv[7];
	HOOK_START_PRESYSCALL
		memcpy(g_syscall_argv[current->pid],syscall_argv,sizeof(syscall_argv));
	if(g_schk_flag[current->pid]){
		g_ret_addr[current->pid]=ret_addr;
		g_syscall_num[current->pid]=syscall_num;
		ret_addr=postsyscall_hook_addr;
		do_something_pre();
	}
	HOOK_END_PRESYSCALL

}

static int install_hook(void){

	char *kern_ver;
	char *buf;
	int i,tmp;
	unsigned entry_index[SYSCALL_MAX];


	buf = kmalloc(MAX_LEN, GFP_KERNEL);
	if ( buf == NULL ) {
		sys_found = 1;
		return -1;
	}

	dbg_info("prepare hooking\n");

	kern_ver = search_file(buf);

	if ( kern_ver == NULL ) {
		sys_found = 1;
		return -1;
	}

	dbg_info("kernel version found: %s\n", kern_ver);

	if ( find_sys_call_table(kern_ver) == -1 ) {
		sys_found = 1;
		return -1;
	}

	sys_found = 0;
	dbg_info("syscall table found: %lx\n", (unsigned long)syscall_table);

	make_rw(syscall_table);

	syscall_table_backup = (void*) kmalloc(SYSCALL_MAX*sizeof(void*), GFP_KERNEL);

	memcpy(syscall_table_backup, syscall_table, SYSCALL_MAX*sizeof(void*));

	tmp=0;
	for(i = 0 ; tmp < SYSCALL_MAX; i++){
		if(!memcmp((char *)syscall_landingboard+i,"\x90\x90\x90\x90",4)){
			entry_index[tmp++] = i + 4;
			i += 4;
		}
	}
	for (i = 0; i < SYSCALL_MAX; i++) {
		((void **)syscall_table)[i] = (void *)((char *)syscall_landingboard+entry_index[i]);
	}

	presyscall_hook_addr=presyscall_hook;
	postsyscall_hook_addr=postsyscall_hook;
	while(memcmp(presyscall_hook_addr,"\x90\x90\x90\x90",4)) presyscall_hook_addr=(char*)presyscall_hook_addr+4;
	while(memcmp(postsyscall_hook_addr,"\x90\x90\x90\x90",4)) postsyscall_hook_addr=(char*)postsyscall_hook_addr+4;
	dbg_info("presyscall_hook_addr = %lx %lx" ,(unsigned long)presyscall_hook_addr,(unsigned long)presyscall_hook);
	dbg_info("postsyscall_hook_addr = %lx %lx" ,(unsigned long)postsyscall_hook_addr,(unsigned long)postsyscall_hook);

	make_ro(syscall_table);
	dbg_info("syscall hooked");
	kfree(buf);
	return 0;
}


static long schk_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)  
{  
	unsigned long long config=0;
	unsigned long long flag=0;
	pid_t pid=0;
	
	switch(cmd){
		case SCHK_CMD_SET_FLAG:
			copy_from_user(&config,(void*)arg,sizeof(unsigned long long));
			pid=config&0xffff;
			flag=config>>16;
			if(pid>65536)
				return EINVAL;
			if((g_schk_flag[pid]&1)==0&&(flag&1)){
            	g_schk_flag[pid]=flag;
				do_something_enable(pid);
			}
			else if((g_schk_flag[pid]&1)&&(flag&1==0)){
				g_schk_flag[pid]=flag;
				do_something_disable(pid);
			}
			break;
		case SCHK_CMD_GET_FLAG:
			copy_from_user(&config,(void*)arg,sizeof(unsigned long long));
			pid=config&0xffff;
			if(pid>65536)
				return EINVAL;
			config=(g_schk_flag[pid]<<16|pid);
			copy_to_user((void*)arg,&config,sizeof(unsigned long long));
			break;
		default:
			dbg_err("unknown ioctl command");
	}
	return 0;  
}  

static int schk_open(struct inode *inode, struct file *filp)  
{  
	return 0;  
}  
static int schk_release(struct inode *inode, struct file *filp)  
{  
	return 0;  
}  

static struct file_operations schk_fops = {

	.owner = THIS_MODULE,
	.unlocked_ioctl = schk_ioctl,
	.open = schk_open,
	.release = schk_release
};
static struct miscdevice schk = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "schk",
	.fops = &schk_fops,
};

static int __init syscall_hook_init(void) {
	int retval;
	retval = misc_register(&schk);
	if(retval)
		return retval;
	dbg_info("schk reigistered, minor %i\n",schk.minor);
	retval = install_hook(); 
	if(retval){
		misc_deregister(&schk);
		return retval;
	}  
	return 0;

}


static void __exit syscall_hook_exit(void) {
	misc_deregister(&schk);
	if ( sys_found == 0 ) {
		make_rw(syscall_table);
		memcpy(syscall_table, syscall_table_backup, SYSCALL_MAX*sizeof(void*));
		dbg_info("syscall table restored.");
		kfree(syscall_table_backup);
		dbg_info("backup syscall table freed.");
		make_ro(syscall_table);
	}
	dbg_info("\nsyscall unhooked\n");
	return;
}


module_init(syscall_hook_init);
module_exit(syscall_hook_exit);

MODULE_LICENSE("GPL");

