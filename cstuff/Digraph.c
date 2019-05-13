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

// can insert edge u->v where u,v are in the range [0,n)
int adde_digraph(Digraph *dg, int u, int v) {
  if (dg == NULL || u < 0 || v < 0 || u >= dg -> n || v >= dg -> n || u == v) return -1;
  // not going to check if adj_list exists or if adj_list entries exist
  if (find_deque(dg -> adj_list[u],v)) return -1;
  addt_deque(dg -> adj_list[u], v);
  dg -> m++;
  return 0; 
}

// dfs returns a dfs tree of the graph exploration starting at node u
Digraph *dfs_digraph(Digraph *dg, int v) {
  if (dg == NULL || v < 0 || v >= dg -> n) return NULL;
  Digraph *out = make_digraph(dg -> n);
  Deque *d = make_deque();// TODO : finish
}

// delete the digraph if possible, -1 if error
int delete_digraph(Digraph *dg) {
  if (dg == NULL) return -1;
  for (int i = 0; i < dg -> n; i++) {
    delete_deque(dg -> adj_list[i]);
  }
  free(dg -> adj_list);
  free(dg);
  return 0;
}

void print_digraph(Digraph *dg) {
  if (dg == NULL) return;
  for (int i = 0; i < dg -> n; i++) {
    printf("[%d] : ", i);
    print_deque(dg -> adj_list[i]);
  }
}
