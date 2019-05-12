#include <stdio.h>
#include <string.h>
#include "Deque.h"

int main() {
  Deque *d = make_deque();
  printf("made deque\n");
  fwprint_deque(d);
  bkprint_deque(d);
  addh_deque(d, 3);
  addt_deque(d, 5);
  addt_deque(d, 8);
  addh_deque(d, 2);
  addt_deque(d, 9);
  printf("addh 3, addt 5, addt 8, addh 2, addt 9\n");
  fwprint_deque(d);
  bkprint_deque(d);
  remh_deque(d);
  remh_deque(d);
  remt_deque(d);
  printf("remh, remh, remt\n");
  fwprint_deque(d);
  bkprint_deque(d);
  remh_deque(d);
  remh_deque(d);
  remh_deque(d);
  remt_deque(d);
  printf("remh, remh, remh, remt\n");
  fwprint_deque(d);
  bkprint_deque(d);
  addt_deque(d, 7);
  printf("addt 7\n");
  fwprint_deque(d);
  bkprint_deque(d);
  remh_deque(d);
  printf("remh\n");
  fwprint_deque(d);
  bkprint_deque(d);
  addt_deque(d, 51);
  addt_deque(d, 88);
  addh_deque(d, 12);
  addt_deque(d, 931);
  printf("addt 51, addt 88, addh 12, addt 931\n");
  print_deque(d);
  delete_deque(d);
  printf("sizeof(int): %lu\n",sizeof(int));
  printf("sizeof(Deque): %lu\n",sizeof(Deque));
  printf("sizeof(Deque *): %lu\n",sizeof(Deque *));
  return 0;
}
