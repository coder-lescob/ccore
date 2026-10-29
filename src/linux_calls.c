#include <ccore_types/types.h>
#include <syscalls/linux_calls.h>
#include <sys_linux/linux.h>

/**
 * reads at most count characters/bytes from a file descriptor
 * returns the number of characters/bytes read
 */
isize read(u32 fd, const char *buf, usize count) {
  // inputs through register vars, likely opimized as nothing...
  register u32     sys_num  __asm__(SYSN) = SYS_READ_NUM;
  register u32         _fd  __asm__(ARG1) = fd;
  register const char *_buf __asm__(ARG2) = buf;
  register usize     _count __asm__(ARG3) = count;

  isize ret;
  __asm__ volatile (
    SYSCALL_INSTR
    : "=" RETR (ret)
    : "r" (sys_num),
      "r" (_fd),
      "r" (_buf),
      "r" (_count)
    : CLOBBER_LIST
  );
  return ret;
}

/**
 * write at most count characters/bytes to a file descriptor
 * returns the number of characters/bytes written
 */
isize write(u32 fd, const char *buf, usize count) {
  // inputs through register vars, likely opimized as nothing...
  register u32     sys_num  __asm__(SYSN) = SYS_WRITE_NUM;
  register u32         _fd  __asm__(ARG1) = fd;
  register const char *_buf __asm__(ARG2) = buf;
  register usize     _count __asm__(ARG3) = count;

  isize ret;
  __asm__ volatile (
    SYSCALL_INSTR
    : "=" RETR (ret)
    : "r" (sys_num),
      "r" (_fd),
      "r" (_buf),
      "r" (_count)
    : CLOBBER_LIST
  );
  return ret;
}

/**
 * exits the program with the code code
 */
void exit(u8 code) {
  register u32 sys_num   __asm__(SYSN) = SYS_EXIT_NUM;
  register u8  exit_code __asm__(ARG1) = code;

  __asm__ volatile (
    SYSCALL_INSTR
    :: "r"(sys_num), "r"(sys_num)
    : CLOBBER_LIST
  );
}
