#include <stdlib.h>
#include <stdio.h>

typedef struct DNode {
  int val;
  struct DNode *prev;
  struct DNode *next;
} DNode;

typedef struct {
  DNode *head;
  DNode *tail;
  int len;
} Deque;

// Deque constructor
Deque *make_deque() {
  Deque *d = malloc(sizeof(Deque));
  d -> len = 0;
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
int addh_deque(Deque *d, int val) {
  if (d == NULL) return -1;
  DNode *n = malloc(sizeof(DNode));
  n -> val = val;
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
int addt_deque(Deque *d, int val) {
  if (d == NULL) return -1;
  DNode *n = malloc(sizeof(DNode));
  n -> val = val;
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
  free(n);
  d -> len--;
  return 0;
}

// get the value of the head, 0 if impossible
int geth_deque(Deque *d) {
  if (d == NULL || d -> head == NULL) return 0;
  return d -> head -> val;
}

// get the value of the tail, 0 if impossible
int gett_deque(Deque *d) {
  if (d == NULL || d -> tail == NULL) return 0;
  return d -> tail -> val;
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

// utility function for printing
void print_deque(Deque *d) {
  if (d == NULL) return;
  DNode *n = d -> head;
  printf("()");
  if (d -> tail == NULL) {
    printf("\n");
    return;
  }
  while (n != NULL) {
    printf("<-[%d]->", n -> val);
    n = n -> next;
  }
  printf("()\n");
}

void fwprint_deque(Deque *d) {
  if (d == NULL) return;
  DNode *n = d -> head;
  while (n != NULL) {
    printf("[%d]->", n -> val);
    n = n -> next;
  }
  printf("()\n");
}

void bkprint_deque(Deque *d) {
  if (d == NULL) return;
  DNode *n = d -> tail;
  while (n != NULL) {
    printf("[%d]->", n -> val);
    n = n -> prev;
  }
  printf("()\n");
}
