#include <stdlib.h>
#include <stdio.h>
#include "HashMap.h"
#include "Deque.h"

// keys have to be unique
// user must promise that input hash function agrees with input equality
const float loadfactor = 0.75;
const int initcap = 16;

typedef int (*hash)(void *);

typedef struct {
  size_t sz;        // size of data pointed to by k
  void *k;          // key struct pointer
  void *v;          // value struct pointer
} KVPair

typedef struct {
  Deque **tbl;      // the table itself
  hash h;           // hash function given by user
  int numbkts;      // number of buckets in the list
  int len;          // number of elements currently hashed
  size_t sz;        // size of key data in kv pair
} HashMap;

// creates a HashMap which has hash function h consisting of Deques with equality 
// function eql (on the keys, not KVPairs) and promised size sz of things pointed to by k
HashMap *make_hashmap(size_t sz, comparison eql, hash h) {
  HashMap *hm = malloc(sizeof(HashMap));
  hm -> tbl = malloc(initcap * sizeof(Deque *));
  hm -> numbkts = initcap;
  hm -> len = 0;
  if (eql == NULL || hash == NULL) {
    hm -> h = NULL;
    for (int i = 0; i < initcap; i++) {
      hm -> tbl[i] = make_deque(sizeof(KVPair), &default_eql);
    }
  } else {
    hm -> h = h;
    for (int i = 0; i < initcap; i++) {
      hm -> tbl[i] = make_deque(sizeof(KVPair), eql);
    }
  }
}

// default equality input into deque
int default_eql(void *a, void *b) {
  void *k1 = (KVPair *)a -> k;
  void *k2 = (KVPair *)b -> k;
  int bl = 1;
  for (int i = 0; i < (KVPair *)a -> sz && bl; i++) {
    bl = bl && (*(char *)(k1 + i) == *(char *)(k2 + i));
  }
  return bl;
}

// add a pair with key k and value v to hm, only works if k is promised size
int add_hashmap(HashMap *hm, void *k, void *v) {
  if (hm == NULL || k == NULL) return -1;
  // TODO : finish by hashing k, modding by size of the table, and adding a kv pair to that deque
}

