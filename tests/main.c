#include <ccore.h>

void _start(void) {
  char str[] = "hello, world!\n";
  write(1, str, sizeof(str));
  exit(63);
}
