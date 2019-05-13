#include "Deque.h"

typedef struct {
  Deque **adj_list;
  int n;
  int m;
} Digraph;

// make digraph witn n nodes
Digraph *make_digraph(int n);
int adde_digraph(Digraph *dg, int u, int v);
int delete_digraph(Digraph *dg);
void print_digraph(Digraph *dg);
