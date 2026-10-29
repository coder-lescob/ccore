#ifndef __CCORE_SYS_LINUX_H
#define __CCORE_SYS_LINUX_H

/**
 * see https://syscalls.mebeim.net/ for the full syscall table
 */

#if defined(__x86_64__) || defined(_M_X64)
  #include <sys_linux/syscalls_num/X86_64.h>
  #include <sys_linux/abi/X86_64.h>
#elif defined(__i386__) || defined(_M_IX86)
  #include <sys_linux/syscalls_num/X86_32.h>
  #include <sys_linux/abi/X86_32.h>
#elif defined(__aarch64__) || defined(_M_ARM64)
  #include <sys_linux/syscalls_num/ARM64.h>
  #include <sys_linux/abi/ARM64.h>
#elif defined(__arm__) || defined(_M_ARM)
  #include <sys_linux/syscalls_num/ARM32.h>
  #include <sys_linux/abi/ARM32.h>
#else
#error "architecture not supported, feel free to add support"
#endif

#endif /* __CCORE_SYS_LINUX_H */
