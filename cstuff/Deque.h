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

Deque *make_deque();
int len_deque(Deque *d);
int addh_deque(Deque *d, void *val, size_t sz);
int addt_deque(Deque *d, void *val, size_t sz);
int remh_deque(Deque *d);
int remt_deque(Deque *d);
void *geth_deque(Deque *d);
void *gett_deque(Deque *d);
int delete_deque(Deque *d);
int find_deque(Deque *d, int (*fptr)(void *));
void print_deque(Deque *d, void (*fptr)(void *));
void fwprint_deque(Deque *d, void (*fptr)(void *));
void bkprint_deque(Deque *d, void (*fptr)(void *));
