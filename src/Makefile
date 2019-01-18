obj-m += schk.o
schk-objs += syscall_hook.o base64.o
KERNELDR := /usr/src/linux-headers-$(shell uname -r)

PWD := $(shell pwd)  

modules:  
	$(MAKE) -C $(KERNELDR) M=$(PWD) modules  

moduels_install:  
	$(MAKE) -C $(KERNELDR) M=$(PWD) modules_install  

test:
	gcc --static  -otest test.c -lpthread
clean:  
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.symvers *.o.ur-detected *.order .cache.mk test
  