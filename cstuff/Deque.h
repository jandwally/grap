typedef struct DNode {
  void *val;            // pointer to data of some unknown type
  struct DNode *prev;   // previous node
  struct DNode *next;   // next node
} DNode;

typedef int (*comparison)(void *, void *);

typedef struct {
  int len;              // number of nodes in deque
  comparison eql;       // equality function for nodes
  size_t sz;            // promised size of datatype pointed to in nodes
  DNode *head;          // head of the deque
  DNode *tail;          // tail of the deque
} Deque;

Deque *make_deque(size_t sz, comparison f); 
int len_deque(Deque *d);
int addh_deque(Deque *d, void *val);
int addt_deque(Deque *d, void *val);
int remh_deque(Deque *d);
int remt_deque(Deque *d);
void *geth_deque(Deque *d);
void *gett_deque(Deque *d);
int delete_deque(Deque *d);
int find_deque(Deque *d, comparison f, void *b);
int cont_deque(Deque *d, void *a);
void print_deque(Deque *d, void (*fptr)(void *));
void fwprint_deque(Deque *d, void (*fptr)(void *));
void bkprint_deque(Deque *d, void (*fptr)(void *));
