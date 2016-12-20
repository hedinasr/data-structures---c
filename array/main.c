#include "array.h"
#include <stdio.h>

int main() {
  Array a, b, result;

  init(&a);
  init(&b);

  push_back(&a, 17);
  push_back(&a, 16);
  push_back(&a, 14);

  push_back(&b, 9);
  push_back(&b, 6);
  push_back(&b, 4);

  printf("tableau a:\n");
  print(&a);
  printf("tableau b:\n");
  print(&b);

  concat(&a, &b, &result);

  printf("tableau result:\n");
  print(&result);

  clear(&a);
  clear(&b);
  clear(&result);

  return 0;
}
