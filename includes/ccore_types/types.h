#ifndef __CCORE_TYPES_H
#define __CCORE_TYPES_H

// 64-bits UNIX like system (e.i. linux, macOS, BSD)
#if defined(__LP64__) || defined(_LP64)
  #include <ccore_types/LP64.h>

// 64-bits windows system
#elif defined(_WIN64) || defined(_M_X86) || defined(_M_ARM64)
  #include <ccore_types/LLP64.h>

// any 32-bits system (universal data model)
#elif defined(__ILP32__) || defined(_ILP32) || defined(_WIN32)
  #include <ccore_type/Universal32.h>
#else
  #error "Unknown data model, feel free to add you own"
#endif

#endif /* __CCORE_TYPES_H */
