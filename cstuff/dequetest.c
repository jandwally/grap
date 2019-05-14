#include <stdlib.h>
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
  return addh_deque(d, (void *)a);
}

int addti_deque(Deque *d, int i) {
  int *a = &i;
  return addt_deque(d, (void *)a);
}

int gethi_deque(Deque *d) {
  void *a = geth_deque(d);
  int i = *(int *)a;
  free(a);
  return i;
}

int getti_deque(Deque *d) {
  void *a = gett_deque(d);
  int i = *(int *)a;
  free(a);
  return i;
}

int equals_vv(void *a, void *b) {
  int i = *(int *)a;
  int j = *(int *)b;
  return (i == j);
}

int findi_deque(Deque *d, int b) {
  return find_deque(d, &equals_vv, (void *)&b);
}

int main() {
  Deque *d = make_deque(sizeof(int), NULL);
  printf("made deque\n");
  fwprinti_deque(d);
  bkprinti_deque(d);
  addhi_deque(d, 3);
  addti_deque(d, 5);
  addti_deque(d, 8);
  addhi_deque(d, 2);
  addti_deque(d, 9);
  printf("addh 3, addt 5, addt 8, addh 2, addt 9\n");
  printf("length: %d\n",len_deque(d));
  printf("geth: %d, gett: %d\n",gethi_deque(d),getti_deque(d));
  int a = 2, b = 13;
  printf("findi %d: %d, cont &%d: %d\n", a, findi_deque(d,a), a, cont_deque(d,&a));
  printf("findi %d: %d, cont &%d: %d\n", b, findi_deque(d,b), b, cont_deque(d,&b));
  fwprinti_deque(d);
  bkprinti_deque(d);
  remh_deque(d);
  remh_deque(d);
  remt_deque(d);
  printf("remh, remh, remt\n");
  printf("length: %d\n",len_deque(d));
  printf("geth: %d, gett: %d\n",gethi_deque(d),getti_deque(d));
  fwprinti_deque(d);
  bkprinti_deque(d);
  remh_deque(d);
  remh_deque(d);
  remh_deque(d);
  remt_deque(d);
  printf("remh, remh, remh, remt\n");
  printf("length: %d\n",len_deque(d));
  fwprinti_deque(d);
  bkprinti_deque(d);
  addti_deque(d, 7);
  printf("addt 7\n");
  printf("length: %d\n",len_deque(d));
  printf("geth: %d, gett: %d\n",gethi_deque(d),getti_deque(d));
  b = 7;
  printf("findi %d: %d, cont &%d: %d\n", a, findi_deque(d,a), a, cont_deque(d,&a));
  printf("findi %d: %d, cont &%d: %d\n", b, findi_deque(d,b), b, cont_deque(d,&b));
  fwprinti_deque(d);
  bkprinti_deque(d);
  remh_deque(d);
  printf("remh\n");
  printf("length: %d\n",len_deque(d));
  fwprinti_deque(d);
  bkprinti_deque(d);
  addti_deque(d, 51);
  addti_deque(d, 88);
  addhi_deque(d, 12);
  addti_deque(d, 931);
  printf("addt 51, addt 88, addh 12, addt 931\n");
  printf("length: %d\n",len_deque(d));
  printi_deque(d);
  delete_deque(d);
  printf("sizeof(int): %lu\n",sizeof(int));
  printf("sizeof(Deque): %lu\n",sizeof(Deque));
  printf("sizeof(Deque *): %lu\n",sizeof(Deque *));
  printf("sizeof(DNode): %lu\n",sizeof(DNode));
  printf("sizeof(size_t): %lu\n",sizeof(size_t));
  return 0;
}
