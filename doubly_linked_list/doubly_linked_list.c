#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

void init(DoublyLinkedList *l) {
  l->first = NULL;
  l->last = NULL;
}

int empty(const DoublyLinkedList *l) {
  if (l->first == NULL) {
    return 1;
  } else {
    return 0;
  }
}

unsigned int size(const DoublyLinkedList *l) {
  Node *c = l->first;
  unsigned int i = 0;

  if (empty(l) == 0) {
    while (c != NULL) {
      i++;
      c = c->next;
    }
    return i;
  }
  return 0;
}

int at(const DoublyLinkedList *l, unsigned int i) {
  Node *c = l->first;
  int j = 0;

  if (i < size(l)) {
    for (j = 0; j < i; j++) {
      c = c->next;
    }
  } else {
    printf("Erreur d'indice\n");
    return -1;
  }
  return c->info;
}

void update_at(const DoublyLinkedList *l, unsigned int i, int e) {
  Node *c = l->first;
  int j = 0;

  if (i < size(l)) {
    for (j = 0; j < i; j++) {
      c = c->next;
    }
  } else {
    printf("Erreur d'indice\n");
  }
  c->info = e;
}

Node *begin(const DoublyLinkedList *l) {
  if (empty(l)) {
    return NULL;
  } else {
    return l->first;
  }
}

Node *next(const Node *c, const DoublyLinkedList *l) {
  if (c->next == NULL) {
    return NULL;
  } else {
    return c->next;
  }
}

void print_left_right(const DoublyLinkedList *l) {
  Node *c = l->first;
  int i;

  printf("Affichage de gauche à droite:\n");
  for (i = 0; i < size(l); i++) {
    printf("Cellule [%d]: %d\n", i, c->info);
    c = c->next;
  }
}

void print_right_left(const DoublyLinkedList *l) {
  Node *c = l->last;
  int i;

  printf("Affichage de droite à gauche:\n");
  for (i = size(l) - 1; i >= 0; i--) {
    printf("Cellule [%d]: %d\n", i, c->info);
    c = c->pred;
  }
}

void ajouterEnTeteDoublyLinkedList(int e, DoublyLinkedList *l) {
  Node *c = (Node *)malloc(sizeof(Node));

  if (l->first == NULL) {
    l->first = c;
    l->first->pred = NULL;
    l->first->next = NULL;
    l->last = c;
    c->info = e;
  } else {
    l->first->pred = c;
    c->next = l->first;
    l->first = c;
    c->pred = NULL;
    c->info = e;
  }
}

void push_back(int e, DoublyLinkedList *l) {
  Node *c = (Node *)malloc(sizeof(Node));

  if (l->last == NULL) {
    l->last = c;
    l->last->pred = NULL;
    l->last->next = NULL;
    l->first = c;
    c->info = e;
  } else {
    l->last->next = c;
    c->pred = l->last;
    l->last = c;
    c->next = NULL;
    c->info = e;
  }
}

void supprimerTeteDoublyLinkedList(DoublyLinkedList *l) {
  if (empty(l) == 0) {
    if (l->first->next == NULL) {
      l->first = NULL;
      free(l->first);
    } else {
      Node *c = l->first->next;
      c->pred = NULL;
      free(l->first);
      l->first = c;
    }
  } else {
    printf("DoublyLinkedList vide !\n");
    exit(EXIT_FAILURE);
  }
}

void erase(DoublyLinkedList *l) {
  Node *c;
  int i;
  int _size = size(l);

  printf("Suppression:\n");
  for (i = 0; i < _size; i++) {
    c = l->first;
    l->first = c->next;
    printf("Cellule [%d]: %d supprimé.\n", i, c->info);
    c->pred = NULL;
    c->next = NULL;
    free(c);
  }
}

void clear(DoublyLinkedList *l) {
  erase(l);
  l->first = NULL;
  l->last = NULL;
}

void copy(DoublyLinkedList *l1, const DoublyLinkedList *l2) {
  int i;
  clear(l1);
  for (i = 0; i < size(l2); i++) {
    push_back(at(l2, i), l1);
  }
}
