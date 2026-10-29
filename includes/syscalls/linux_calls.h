#ifndef __linux__
#error "this file is for the linux syscall only"
#endif /* __linux__ */

#ifndef __CCORE_LINUX_H
#define __CCORE_LINUX_H

#include <ccore_types/types.h>

/**
 * reads at most count characters/bytes from a file descriptor
 * returns the number of characters/bytes read
 */
isize read(u32 fd, const char *buf, usize count);

/**
 * write at most count characters/bytes to a file descriptor
 * returns the number of characters/bytes written
 */
isize write(u32 fd, const char *buf, usize count);

/**
 * exits the program with the code code
 */
void exit(u8 code);

#endif /* __CCORE_LINUX_H */
