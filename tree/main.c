#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ElementA.h"
#include "Arbre.h"

#define VALEUR_MAX 100000
#define VALEUR_MIN 0

int main()
{
  int alea1,alea2,i; Arbre a; int trouve,nb_visites;
  initialiserArbre(&a);
  srand((unsigned) time(NULL));
  for(i=0;i<255;i++)
    {
alea1 = (rand()%(VALEUR_MAX - VALEUR_MIN + 1)) + VALEUR_MIN;
       insererElementArbre(alea1,&a);
     }
  for(i=0;i<1000000;i++)
    {
      alea2 = (rand()%(VALEUR_MAX - VALEUR_MIN + 1)) + VALEUR_MIN;
rechercherElementArbre(alea2,&a,&trouve,&nb_visites);
 if(nb_visites == 1) printf("trouve\n");
    }
  testamentArbre(&a);
  return 0;
}
