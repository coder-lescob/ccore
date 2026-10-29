#ifndef __CCORE_LINUX_ABI_H
#define __CCORE_LINUX_ABI_H

#define SYSN "rax"
#define RETR "a"
#define ARG1 "rdi"
#define ARG2 "rsi"
#define ARG3 "rdx"
#define ARG4 "r10"
#define ARG5 "r8"
#define ARG6 "r9"

// Instruction that trigger syscall
#define SYSCALL_INSTR "syscall"
#define CLOBBER_LIST  "rcx","r11","memory"

#endif /* __CCORE_LINUX_ABI_H */
