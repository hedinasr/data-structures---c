#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tree.h"

#define VALEUR_MAX 100000
#define VALEUR_MIN 0

int
main ()
{
  int alea1, alea2, i;
  Tree a;
  int trouve, nb_visites;
  init (&a);
  srand ((unsigned) time (NULL));
  for (i = 0; i < 255; i++)
    {
      alea1 = (rand () % (VALEUR_MAX - VALEUR_MIN + 1)) + VALEUR_MIN;
      insert (alea1, &a);
    }
  for (i = 0; i < 1000000; i++)
    {
      alea2 = (rand () % (VALEUR_MAX - VALEUR_MIN + 1)) + VALEUR_MIN;
      search (alea2, &a, &trouve, &nb_visites);
      if (nb_visites == 1)
	printf ("trouve\n");
    }
  clear (&a);
  return 0;
}
