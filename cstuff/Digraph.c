#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

typedef struct {
  Deque **adj_list;
  int n;
  int m;
} Digraph;

// make digraph witn n nodes
Digraph *make_digraph(int n) {
  if (n < 1) return NULL;
  Digraph *digraph = malloc(sizeof(Digraph));
  digraph -> adj_list = malloc(n * sizeof(Deque *));
  for (int i = 0; i < n; i++) {
    digraph -> adj_list[i] = make_deque();
  }
  digraph -> n = n;
  digraph -> m = 0;
  return digraph;
}

int delete_digraph(Digraph *dg) {
  if (dg == NULL) return -1;
  for (int i = 0; i < dg -> n; i++) {
    delete_deque(dg -> adj_list[i]);
  }
  free(dg -> adj_list);
  free(dg);
  return 0;
}
