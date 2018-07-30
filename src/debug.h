#ifndef __DEBUG_H__ 
#define __DEBUG_H__


#define ULL     unsigned long long
#define SYSNO   unsigned int


#define KERNEL

#ifdef KERNEL
#include <linux/kernel.h>
#include <asm/unistd.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/list.h>
#else
#include <stdio.h>
#endif


/********** Finished Handle Debug info **********/
#define DBG
#ifdef DBG
#ifdef KERNEL
#define dbg_err(msg...) do {		\
	printk(KERN_INFO "\033[1;31m");		\
	printk(KERN_INFO msg);				\
	printk(KERN_INFO "\033[0m\n");		\
} while(0)
#define dbg_info(msg...) do {		\
	printk(KERN_INFO "\033[1;32m");		\
	printk(KERN_INFO msg);				\
	printk(KERN_INFO "\033[0m\n");		\
} while(0)
#else
#define dbg_err(msg...) do {		\
	printf("\033[1;31m");		\
	printf(msg);				\
	printf("\033[0m\n");		\
} while(0)
#define dbg_info(msg...) do {		\
	printf("\033[1;32m");		\
	printf(msg);				\
	printf("\033[0m\n");		\
} while(0)
#endif
#else
#define dbg_err(msg...) do{} while(0)
#define dbg_info(msg...) do{} while(0)
#endif

#ifdef KERNEL
#define SRC char
#define DST unsigned char
#define COPY(src, dst, size) (memcpy(src, dst, size))
#define malloc(sz) (kmalloc(sz, GFP_KERNEL))
#define realloc(ptr, sz) (krealloc(ptr, sz, GFP_KERNEL))
#define FREE(sz) kfree(sz)
#else
#include <memory.h>
#include <stdlib.h>
#define SRC unsigned char
#define DST unsigned char
#define COPY(src, dst, size) (memcpy(src, dst, size))
#define FREE(sz) free(sz)
#endif

#endif // end define __DEBUG_H__
