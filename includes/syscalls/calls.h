#ifndef __CCORE_SYSCALLS_H
#define __CCORE_SYSCALLS_H

#ifdef __linux__
  #include <syscalls/linux_calls.h>
#else
#error "linux is the only supported os yet, if you want to extend that feel free to leave a pull request"
#endif

#endif /* __CCORE_SYSCALLS_H */
