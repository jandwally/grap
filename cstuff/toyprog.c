#include <stdlib.h>
#include <stdio.h>

void rand_print(int x, double y) {
  printf("you gave me an int %d and double %f\n",x,y);
}

int abf(int a, int b, int (*funp)(int,int)) {
  return (*funp)(a,b);
}

int sum(int a, int b) {
  return a+b;
}

int main() {
  void (*fptr)(int,double) = &rand_print;
  (*fptr)(3,4.13);
  printf("size of void *: %lu\n",sizeof(void *));
  printf("size of char: %lu\n",sizeof(char));
  (*fptr)(abf(3,5,sum),3.14);
}
