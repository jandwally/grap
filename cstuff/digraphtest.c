#include <stdio.h>
#include <string.h>
#include "Digraph.h"

int main() {
  Digraph *dg = make_digraph(13);
  delete_digraph(dg);
  return 0;
}
