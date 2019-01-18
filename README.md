# Linux system call hook framework

## How it works
The framework hook system call by rewriting system call table(for pre-syscall hooking) and return address of system call(for post-syscall hooking).

The framework is well tested unber ubuntu, imagine that the newest commit is made under the newest ubuntu18.04 with this system call hook framework installed

## Usage
put your own thing into do_something_enable/do_something_disable/do_something_pre/do_something_post function to perform pre&post system call hooking.

## knwon issue
Kernel crash if you remove the kernel module while a system call is ungoing.
This is due to the return address of system call has been modified for hooking, if the module unload, the return address of ungoing system call will be a unmapped address which will lead to a crash. This bug will not affect the usage of the framework, so I decide to work out this issue in the future.