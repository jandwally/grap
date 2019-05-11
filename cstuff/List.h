typedef struct {
  int val;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int len;
} List;

// list constructor
List *make_list();

// returns integer length or -1 if error
int len_list(List * list);

// insert head node with value val if possible, -1 if error
int insert_list(List *list, int val);

int remove_list(List *list);

int get_list(List *list);

int delete_list(List *list);

void print_list(List *list);
