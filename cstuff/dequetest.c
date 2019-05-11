#include <stdio.h>
#include <string.h>
#include "Deque.h"

int main() {
  Deque *d = make_deque();
  printf("made deque\n");
  fwprint_deque(d);
  bkprint_deque(d);
  delete_deque(d);
  return 0;
}
