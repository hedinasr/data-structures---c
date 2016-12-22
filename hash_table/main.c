#include <stdio.h>
#include "hash_table.h"
#include "../utils/date.h"

int main() {
  Object *e = NULL;
  Date h = {24, 9, 1994};
  Date s = {1, 6, 1996};
  Date o = {13, 9, 2003};
  HashTable a;

  init(&a, 2, date_pack);

  add(&a, &h, "hedi");
  add(&a, &s, "sarra");
  add(&a, &o, "omar");

  e = search(&a, "omaur");
  if (e)
    printf("omar est la\n");

  e = NULL;
  e = search(&a, "sarra");
  if (e)
    printf("Sarra est la\n");

  print(&a);
  printf("\n");
  clear(&a);
  return 0;
}
