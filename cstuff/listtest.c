#include <stdio.h>
#include <string.h>
#include "List.h"

int main() {
  List *list = make_list();
  printf("made list\n");
  print_list(list);
  remove_list(list);
  printf("removed from list\n");
  print_list(list);
  insert_list(list, 3);
  insert_list(list, 5);
  insert_list(list, 9);
  insert_list(list, 8);
  printf("added 3, 5, 9, 8 to list\n");
  print_list(list);
  remove_list(list);
  remove_list(list);
  printf("removed from list twice\n");
  printf("list size: %d\n",len_list(list));
  print_list(list);
  delete_list(list);
  return 0;
}
