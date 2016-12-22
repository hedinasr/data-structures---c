#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

void init(HashTable *t, int size, ObjectPack pack) {
  int i;
  t->array = (Case *)malloc(sizeof(Case) * size);
  t->size = size;
  t->pack = pack;
  for (i = 0; i < size; i++) {
    t->array[i].key = NULL;
    t->array[i].value = NULL;
    t->array[i].init = 0;
  }
}

void clear(HashTable *t) {
  int i;
  for (i = 0; i < t->size; i++)
    if (t->array[i].init == 1)
      t->pack.clear(&(t->array[i].value));
  free(t->array);
  t->size = 0;
}

void print(const HashTable *t) {
  int i;
  for (i = 0; i < t->size; i++)
    if (t->array[i].init == 1) {
      printf("%s : ", t->array[i].key);
      t->pack.print(t->array[i].value);
    }
}

int hash(char *c, int size) {
  int i, hash = 0;

  for (i = 0; c[i] != '\0'; i++)
    hash += c[i];
  hash %= size;

  return hash;
}

static int rehash(char *c, int size, int i) {
  return (hash(c, size) + (i - 1) * (i - 1)) % size;
}

static int vide(const HashTable *t, int i) {
  if (t->array[i].init == 0)
    return 1;
  return 0;
}

void add(HashTable *t, Object e, char *key) {
  int i = 0, v;
  Object d;
  t->pack.init(&d, e);
  do {
    v = rehash(key, t->size, i);
    i++;
  } while (vide(t, v) == 0 && t->array[v].key != key && i < t->size);
  if (t->array[v].key == key) {
    printf("%s deja present\n", key);
    t->pack.clear(&d);
  } else {
    if (vide(t, v) == 1) {
      t->array[v].key = key;
      t->array[v].value = d;
      t->array[v].init = 1;
    } else {
      printf("La case est remplit\n");
      t->pack.clear(&d);
    }
  }
}

Object *search(const HashTable *t, char *key) {
  int h = hash(key, t->size);
  if (vide(t, h) == 1)
    return NULL;
  else
    return t->array[h].value;
}
