#ifndef __CCORE_H
#define __CCORE_H

#include <ccore_types/types.h>

#ifdef __linux__
  #include <syscalls/calls.h>
#else
#error "only linux is supported yet, feel free to open pull request"
#endif

#endif /* __CCORE_H */
