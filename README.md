# Linux system call hook framework

## How it works

The framework hook system call by rewriting system call table(for pre-syscall hooking) and return address of system call(for post-syscall hooking).

The framework is well tested unber ubuntu, imagine that the newest commit is made under the newest ubuntu18.04 with this system call hook framework installed

## Usage
put your own thing into do_something_pre and do_something_post function to perform pre&post system call hooking.