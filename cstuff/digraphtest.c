#include <stdio.h>
#include <string.h>
#include "Digraph.h"

int main() {
  Digraph *dg = make_digraph(6);
  adde_digraph(dg, 0, 1);
  adde_digraph(dg, 0, 2);
  adde_digraph(dg, 0, 3);
  adde_digraph(dg, 0, 5);
  adde_digraph(dg, 1, 2);
  adde_digraph(dg, 2, 3);
  adde_digraph(dg, 3, 4);
  adde_digraph(dg, 3, 5);
  print_digraph(dg);
  delete_digraph(dg);
  return 0;
}
