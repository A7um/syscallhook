#include<stdio.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include <pthread.h>

#include<string.h>
#include "schk_ioctl.h"


#if defined(__i386__)

static __inline__ unsigned long long rdtsc(void)
{
	unsigned long long int x;
	__asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
	return x;
}
#elif defined(__x86_64__)


static __inline__ unsigned long long rdtsc(void)
{
	unsigned hi, lo;
	__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
	return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

#elif defined(__powerpc__)


static __inline__ unsigned long long rdtsc(void)
{
	unsigned long long int result=0;
	unsigned long int upper, lower,tmp;
	__asm__ volatile(
			"0:                  \n"
			"\tmftbu   %0           \n"
			"\tmftb    %1           \n"
			"\tmftbu   %2           \n"
			"\tcmpw    %2,%0        \n"
			"\tbne     0b         \n"
			: "=r"(upper),"=r"(lower),"=r"(tmp)
			);
	result = upper;
	result = result<<32;
	result = result|lower;

	return(result);
}

#endif
int has_debugger() 
{
    char buff1[24], buff2[16];
    FILE* f;
 
    snprintf(buff1, 24, "/proc/%d/status", getppid());
    f = fopen(buff1, "r");
    // the first line in status is name
    fgets(buff2, 16, f);
    fclose(f);
 
    int has_gdb = (strstr(buff2, "gdb") || strstr(buff2, "rr") || strstr(buff2, "strace"));
    if (has_gdb == 0) {
        printf("no debugger is attached\n");
    } else {
        printf("debugger attached!\n");
    }
    return has_gdb;
}

void * print_a(void *a){
    char buf[100];

    int fr=open("/dev/urandom",O_RDONLY);
    read(fr,buf,100);
    close(fr);
	for(int i = 0;i < 10; i++){

		if(has_debugger())
			puts("thread_a: debugger found");
		else
			puts("thread_a: good job");
		printf("thread_a: time = %llx\n",rdtsc());
	}
	return NULL;

}

// 线程B 方法
void * print_b(void *b){
    char buf[100];
    int fr=open("/dev/urandom",O_RDONLY);
    read(fr,buf,100);
    close(fr);
	for(int i=0;i<10;i++){

		if(has_debugger())
			puts("thread_b: debugger found");
		else
			puts("thread_b: good job");
		printf("thread_b time = %llx\n",rdtsc());
	}
	return NULL;
}
int main(){
    char buf[100];
    int fd=open("/dev/schk",O_RDONLY);
    if(fd<0)
        perror("open");
    int pid=getpid();
    printf("%d %d\n",fd,pid);
    unsigned long long config=(SCHK_FLAG_INHERIT|SCHK_FLAG_ENABLE)<<16 | pid;
    if(ioctl(fd,SCHK_CMD_SET_FLAG,&config))
        perror("ioctl1");
    int fr=open("/dev/urandom",O_RDONLY);
    read(fr,buf,100);

	pthread_t t0;
	pthread_t t1;
//	cpu_set_t set;
//	CPU_SET(0,&set);
//	if (sched_setaffinity(getpid(), sizeof(set), &set) == -1)
//		perror("sched_setaffinity");
//
	// 创建线程A
	if(pthread_create(&t0, NULL, print_a, NULL) == -1){
		puts("fail to create pthread t0");
		exit(1);
	}

	if(pthread_create(&t1, NULL, print_b, NULL) == -1){
		puts("fail to create pthread t1");
		exit(1);
	}

	// 等待线程结束
	void * result;
	if(pthread_join(t0, &result) == -1){
		puts("fail to recollect t0");
		exit(1);
	}

	if(pthread_join(t1, &result) == -1){
		puts("fail to recollect t1");
		exit(1);
	}



    puts("hello world");
    config=pid;
    if(ioctl(fd,SCHK_CMD_SET_FLAG,&config))
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
