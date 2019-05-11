#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int len;
} List;

// list constructor
List *make_list() {
  List *list = malloc(sizeof(List));
  list -> len = 0;
  list -> head = NULL;
  return list;
}

// returns integer length or -1 if error
int len_list(List * list) {
  if (list == NULL) return -1;
  return list -> len;
};

// insert head node with value val if possible, -1 if error
int insert_list(List *list, int val) {
  if (list == NULL) return -1;
  Node *node = malloc(sizeof(Node));
  node -> val = val;
  node -> next = list -> head;
  list -> head = node;
  list -> len++;
  return 0;
}

int remove_list(List *list) {
  if (list == NULL || list -> head == NULL) return -1;
  Node *node = list -> head;
  list -> head = node -> next;
  free(node);
  list -> len--;
  return 0;
}

int get_list(List *list) {
  if (list == NULL || list -> head == NULL) return 0;
  return list -> head -> val;
}

int delete_list(List *list) {
  if (list == NULL) return -1;
  while (list -> head != NULL) {
    remove_list(list);
  }
  free(list);
  return 0;
}

void print_list(List *list) {
  if (list == NULL) return;
  Node *node = list -> head;
  while (node != NULL) {
    printf("[%d]->", node -> val);
    node = node -> next;
  }
  printf("()\n");
}
