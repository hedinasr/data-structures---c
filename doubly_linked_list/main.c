#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main() {
  DoublyLinkedList l;
  init(&l);

  ajouterEnTeteDoublyLinkedList(15, &l);
  ajouterEnTeteDoublyLinkedList(14, &l);
  ajouterEnTeteDoublyLinkedList(11, &l);

  push_back(44, &l);

  print_left_right(&l);

  printf("Empty = %d\n", empty(&l));
  printf("Size = %d\n", size(&l));
  clear(&l);
  return 0;
}
