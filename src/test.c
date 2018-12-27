#include<stdio.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define SCHK_MAGIC_NUMBER 's'
#define SCHK_ENABLE_HOOK _IOW(SCHK_MAGIC_NUMBER,0,pid_t)
#define SCHK_DISABLE_HOOK _IOW(SCHK_MAGIC_NUMBER,1,pid_t)
int main(){
    char buf[100];
    int fd=open("/dev/schk",O_RDONLY);
    if(fd<0)
        perror("open");
    int pid=getpid();
    printf("%d %d\n",fd,pid);

    if(ioctl(fd,SCHK_ENABLE_HOOK,&pid))
        perror("ioctl1");
    int fr=open("/dev/urandom",O_RDONLY);
    read(fr,buf,100);
    puts("hello world");
    if(ioctl(fd,SCHK_DISABLE_HOOK,&pid))
        perror("ioctl2");
    return 0;
}

/*
/ # insmod syscall_hook.ko 
[    6.401017] syscall_hook: loading out-of-tree module taints kernel.
[    6.405587] syscall_hook: module verification failed: signature and/or required key missing - tainting kernel
[    6.413057] 
[    6.413058] schk reigistered, minor 55
[    6.416447] 
[    6.417535] 
[    6.417536] prepare hooking
[    6.420714] 
[    6.423289] 
[    6.423290] kernel version found: 4.15.0-43-generic
[    6.427783] 
[    6.429013] 
[    6.429014] 
[    6.429014] Path /proc/kallsyms
[    6.432904] 
[    6.711773] 
[    6.711774] syscall table found: ffffffff878001a0
[    6.715132] 
[    6.715974] 
[    6.715975] pte <ffff94974240f1e0>
[    6.718716] 
[    6.719615] 
[    6.719616] pte <ffff94974240f1e0>
[    6.722563] 
[    6.723790] 
[    6.723791] syscall hooked
[    6.725171] 
/ # ./test 
[    8.659927] 
[    8.659929] syscall hook enabled at pid 123
[    8.661545] 
[    8.665216] 
[    8.665218] post-syscall: 16 
[    8.666509] 
[    8.670673] 
[    8.670675] pre-syscall: 257 
[    8.672980] 
[    8.677343] 
[    8.677345] post-syscall: 257 
[    8.678425] 
[    8.681005] 
[    8.681006] pre-syscall: 0 
[    8.682062] 
[    8.684639] random: test: uninitialized urandom read (100 bytes read)
[    8.690408] 
[    8.690410] post-syscall: 0 
[    8.692296] 
[    8.698876] 
[    8.709584] pre-syscall: 1 
[    8.710733] 
hello world
[    8.713972] 
[    8.713973] post-syscall: 1 
[    8.715102] 
[    8.718263] 
[    8.718268] pre-syscall: 16 
[    8.720754] 
[    8.724030] 
[    8.724032] syscall hook disabled at pid 123
[    8.725843]  
/ # 
*/