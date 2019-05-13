#include <stdio.h>
#include <string.h>
#include "Deque.h"

void print_int(void *iptr) {
  int i = *(int *)iptr;
  printf("%d",i);
}

void fwprinti_deque(Deque *d) {
  fwprint_deque(d, &print_int);
}

void bkprinti_deque(Deque *d) {
  bkprint_deque(d, &print_int);
}

void printi_deque(Deque *d) {
  print_deque(d, &print_int);
}

int addhi_deque(Deque *d, int i) {
  int *a = &i;
  return addh_deque(d, (void *)a, sizeof(int));
}

int addti_deque(Deque *d, int i) {
  int *a = &i;
  return addt_deque(d, (void *)a, sizeof(int));
}

int main() {
  Deque *d = make_deque();
  printf("made deque\n");
  fwprinti_deque(d);
  bkprinti_deque(d);
  addhi_deque(d, 3);
  addti_deque(d, 5);
  addti_deque(d, 8);
  addhi_deque(d, 2);
  addti_deque(d, 9);
  printf("addh 3, addt 5, addt 8, addh 2, addt 9\n");
  fwprinti_deque(d);
  bkprinti_deque(d);
  remh_deque(d);
  remh_deque(d);
  remt_deque(d);
  printf("remh, remh, remt\n");
  fwprinti_deque(d);
  bkprinti_deque(d);
  remh_deque(d);
  remh_deque(d);
  remh_deque(d);
  remt_deque(d);
  printf("remh, remh, remh, remt\n");
  fwprinti_deque(d);
  bkprinti_deque(d);
  addti_deque(d, 7);
  printf("addt 7\n");
  fwprinti_deque(d);
  bkprinti_deque(d);
  remh_deque(d);
  printf("remh\n");
  fwprinti_deque(d);
  bkprinti_deque(d);
  addti_deque(d, 51);
  addti_deque(d, 88);
  addhi_deque(d, 12);
  addti_deque(d, 931);
  printf("addt 51, addt 88, addh 12, addt 931\n");
  printi_deque(d);
  delete_deque(d);
  printf("sizeof(int): %lu\n",sizeof(int));
  printf("sizeof(Deque): %lu\n",sizeof(Deque));
  printf("sizeof(Deque *): %lu\n",sizeof(Deque *));
  return 0;
}
