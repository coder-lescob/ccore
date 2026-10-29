#include <ccore.h>

void _start(void) {
  char str[] = "Hello, world!\n";
  write(1, str, sizeof(str));
  exit(0);
}
