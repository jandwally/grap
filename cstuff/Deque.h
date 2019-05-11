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
int addh_deque(Deque *d, int val);
int addt_deque(Deque *d, int val);
int remh_deque(Deque *d);
int remt_deque(Deque *d);
int geth_deque(Deque *d);
int gett_deque(Deque *d);
int delete_deque(Deque *d);
void print_deque(Deque *d);
void fwprint_deque(Deque *d);
void bkprint_deque(Deque *d);
