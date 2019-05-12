#include "Deque.h"

typedef struct {
  Deque **adj_list;
  int n;
  int m;
} Digraph;

// make digraph witn n nodes
Digraph *make_digraph(int n);
int delete_digraph(Digraph *dg);
