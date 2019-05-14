#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

// Deque constructor, input is promised size of data types to be in deque and equality fn
Deque *make_deque(size_t sz, comparison f) {
  Deque *d = malloc(sizeof(Deque));
  d -> sz = sz;
  d -> len = 0;
  d -> eql = f;
  d -> tail = NULL;
  d -> head = NULL;
  return d;
}

// returns integer length or -1 if error
int len_deque(Deque *d) {
  if (d == NULL) return -1;
  return d -> len;
}

// insert head node with value val if possible, -1 if error
int addh_deque(Deque *d, void *val) {
  if (d == NULL || val == NULL) return -1;
  DNode *n = malloc(sizeof(DNode));
  n -> val = malloc(d -> sz);
  for (int i = 0; i < d -> sz; i++) {
    *(char *)(n -> val + i) = *(char *)(val + i); //copying val's bytes into node val
  }
  n -> prev = NULL;
  n -> next = d -> head;
  d -> head = n;
  if (n -> next == NULL) {
    d -> tail = n;
  } else {
    n -> next -> prev = n;
  }
  d -> len++;
  return 0;
}

// insert tail node with value val if possible, -1 if error
int addt_deque(Deque *d, void *val) {
  if (d == NULL) return -1;
  DNode *n = malloc(sizeof(DNode));
  n -> val = malloc(d -> sz);
  for (int i = 0; i < d -> sz; i++) {
    *(char *)(n -> val + i) = *(char *)(val + i); //copying val's bytes into node val
  }
  n -> prev = d -> tail;
  n -> next = NULL;
  d -> tail = n;
  if (n -> prev == NULL) {
    d -> head = n;
  } else {
    n -> prev -> next = n;
  }
  d -> len++;
  return 0;
}

// remove head if possible, -1 if error
int remh_deque(Deque *d) {
  if (d == NULL || d -> head == NULL) return -1;
  DNode *n = d -> head;
  d -> head = n -> next;
  if (d -> head == NULL) {
    d -> tail = NULL;
  } else {
    d -> head -> prev = NULL;
  }
  free(n -> val);
  free(n);
  d -> len--;
  return 0;
}

// remove tail if possible, -1 if error
int remt_deque(Deque *d) {
  if (d == NULL || d -> tail == NULL) return -1;
  DNode *n = d -> tail;
  d -> tail = n -> prev;
  if (d -> tail == NULL) {
    d -> head = NULL;
  } else {
    d -> tail -> next = NULL;
  }
  free(n -> val);
  free(n);
  d -> len--;
  return 0;
}

// returns a pointer to a copy of the data at head, NULL otherwise
void *geth_deque(Deque *d) {
  if (d == NULL || d -> head == NULL) return NULL;
  void *val = malloc(d -> sz);  // (!) user will be responsibe for freeing this (!)
  for (int i = 0; i < d -> sz; i++) {
    *(char *)(val + i) = *(char *)(d -> head -> val + i);
  }
  return val;
}

// returns a pointer to a copy of the data at tail, NULL otherwise
void *gett_deque(Deque *d) {
  if (d == NULL || d -> tail == NULL) return NULL;
  void *val = malloc(d -> sz);  // (!) user will be responsibe for freeing this (!)
  for (int i = 0; i < d -> sz; i++) {
    *(char *)(val + i) = *(char *)(d -> tail -> val + i);
  }
  return val;
}

// delete all elements of Deque and free, -1 if impossible
int delete_deque(Deque *d) {
  if (d == NULL) return -1;
  while (d -> head != NULL) {
    remh_deque(d);
  }
  free(d);
  return 0;
}

/* returns 1 if there's a node for which function evalutes to true when 
   applied to it and b, 0 otherwise */
int find_deque(Deque *d, comparison f, void *b) {
  if (d == NULL) return 0;
  DNode *n = d -> head;
  while (n != NULL) {
    if (f(n -> val,b)) return 1;
    n = n -> next;
  }
  return 0;
}

// checks "structural equality" of *a and *val (assumes a same type as vals in d)
// (!) will segfault if size of *a is greater than sz (!)
// works if *a is a basic type or a struct of basic types
// not in the h file as this is the default equality if given eql is NULL
int struct_cont(Deque *d, void *a) {
  if (d == NULL) return 0;
  DNode *n = d -> head;
  while (n != NULL) {
    int bl = 1;
    for (int i = 0; i < d -> sz && bl; i++) {
      bl = bl && (*(char *)(n -> val + i) == *(char *)(a + i));
    }
    if (bl) return 1;
    n = n -> next;
  }
  return 0;
}

// does the deque contain a value equal to a, uses structural equality by default
int cont_deque(Deque *d, void *a) {
  if (d == NULL) return 0;
  if (d -> eql == NULL) return struct_cont(d, a);
  return find_deque(d, d -> eql, a);
}

// utility function for printing
void print_deque(Deque *d, void (*fptr)(void *)) {
  if (d == NULL) return;
  DNode *n = d -> head;
  printf("()");
  if (d -> tail == NULL) {
    printf("\n");
    return;
  }
  while (n != NULL) {
    printf("<-[");
    (*fptr)(n -> val);
    printf("]->");
    n = n -> next;
  }
  printf("()\n");
}

void fwprint_deque(Deque *d, void (*fptr)(void *)) {
  if (d == NULL) return;
  DNode *n = d -> head;
  while (n != NULL) {
    printf("[");
    (*fptr)(n -> val);
    printf("]->");
    n = n -> next;
  }
  printf("()\n");
}

void bkprint_deque(Deque *d, void (*fptr)(void *)) {
  if (d == NULL) return;
  DNode *n = d -> tail;
  while (n != NULL) {
    printf("[");
    (*fptr)(n -> val);
    printf("]->");
    n = n -> prev;
  }
  printf("()\n");
}
