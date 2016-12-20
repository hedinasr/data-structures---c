#include "skip_list.h"
#include <stdio.h>
#include <stdlib.h>

int
main()
{
  int j;
  SkipList sl;

  init(&sl, Int);

  for (j = 0; j < 80; j++) {
    int r = rand() % 1000;
    push_back(&sl, &r);
  }

  printf("Level: %d\n", sl.level);

  print(&sl);
  clear(&sl);

  return 0;
}
