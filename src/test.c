#include<stdio.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define SCHK_MAGIC_NUMBER 's'
#define SCHK_ENABLE_HOOK _IOW(SCHK_MAGIC_NUMBER,0,pid_t)
#define SCHK_DISABLE_HOOK _IOW(SCHK_MAGIC_NUMBER,1,pid_t)
int main(){

    int fd=open("/dev/schk",O_RDONLY);
    if(fd<0)
        perror("open");
    int pid=getpid();
    printf("%d %d\n",fd,pid);
    if(ioctl(fd,SCHK_ENABLE_HOOK,&pid))
        perror("ioctl1");
    puts("hello world");
    if(ioctl(fd,SCHK_DISABLE_HOOK,&pid))
        perror("ioctl2");
    return 0;
}

/*
/ # insmod syscall_hook.ko 
[    4.504368] syscall_hook: loading out-of-tree module taints kernel.
[    4.508245] syscall_hook: module verification failed: signature and/or required key missing - tainting kernel
[    4.515121] 
[    4.515122] schk reigistered, minor 55
[    4.519114] 
[    4.520248] 
[    4.520248] prepare hooking
[    4.523130] 
[    4.524246] 
[    4.524246] kernel version found: 4.15.0-43-generic
[    4.527957] 
[    4.528980] 
[    4.528981] 
[    4.528981] Path /proc/kallsyms
[    4.532803] 
[    4.809155] 
[    4.809156] syscall table found: ffffffffbae001a0
[    4.812588] 
[    4.813465] 
[    4.813466] pte <ffff9f18c240feb8>
[    4.816245] 
[    4.817147] 
[    4.817147] pte <ffff9f18c240feb8>
[    4.820156] 
[    4.821186] 
[    4.821186] syscall hooked
[    4.822365] 
/ # ./test 
3 124
[    7.425710] 
[    7.425730] syscall hook enabled at pid 124
[    7.427078] 
[    7.431435] 
[    7.431436] post-syscall: 16 
[    7.432827] 
[    7.436340] 
[    7.436342] pre-syscall: 1 
[    7.437630] 
hello world
[    7.441196] 
[    7.441197] post-syscall: 1 
[    7.442502] 
[    7.446948] 
[    7.446951] pre-syscall: 16 
[    7.448481] 
[    7.451876] 
[    7.451878] syscall hook disabled at pid 124
[    7.454746] 
/ # 
*/