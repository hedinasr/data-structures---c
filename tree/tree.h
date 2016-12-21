#ifndef _ARBRE
#define _ARBRE

#include "ElementA.h" 


struct sNoeud {
  ElementA info;
  struct sNoeud * fg;
  struct sNoeud * fd;
};
typedef struct sNoeud Noeud;


struct sArbre {
  Noeud * adRacine; 
  int nbElemDansArbre;
};
typedef struct sArbre Arbre;


void initialiserArbre(Arbre * A);
/* Precondition : *A non prealablement initialise
   Postcondition : *A est initialise vide */


void testamentArbre(Arbre *A);
/* Precondition : *A prealablement initialise
   Postcondition : *A pret a disparaitre (ne doit plus etre utilise) */


void affecterArbre(Arbre *A, const Arbre * B);
/* Precondition : *A et B prealablement initialises 
   Postcondition : *A et B correspondent a des arbres identiques
   (mais ils sont totalement independants l'un de l'autre)
   (*A est une copie de B) */


int testArbreVide(const Arbre * A);
/* Precondition : *A initialise
   Resultat : 1 si *A est vide, 0 sinon */


void afficherArbreParcoursInfixe(const Arbre * A);
/* Precondition : *A initialise
   Postcondition : Affichage infixe de tous les elements de *A */

void affichageArborescent(const Arbre * A);

void viderArbre(Arbre *A);
/* Precondition : *A initialise 
   Postcondition : *A est vide */


void insererElementArbre(ElementA e, Arbre *A);
/* Precondition : *A est un arbre binaire de recherche initialise
   Postcondition : si e n'existait pas deja dans l'arbre *A, alors
   un nouveau noeud contenant e est insere aux feuilles de *A. 
   Si au contraire e existait deja dans l'arbre, alors l'arbre est
   inchange. */


void rechercherElementArbre(ElementA e, const Arbre *A, int * trouve, int * nb_visites);
/* Precondition : *A initialise
   Postcondition : si aucun noeud de l'arbre *A ne contient la valeur e passee
   en parametre, l'entier *trouve vaut 0. Si au contraire on a trouve un
   noeud avec le e demande, alors *trouve vaut 1. Dans les deux cas, *nb_visites
   contient le nombre de comparaisons d'Elements effectuees lors de cette 
   recherche. */


/*******************************************************************/
/*           Partie specifique aux groupes A, B, C (lundi)         */          
/*******************************************************************/


/* Fait en TD... */
int hauteurArbre(const Arbre * A);
/* Precondition : *A initialise
   Résultat : renvoie la hauteur de l'arbre (longueur de sa plus
   longue branche), ou -1 s'il est vide */

double profondeurMoyenneArbre(const Arbre * A);
/* Precondition : a initialise
   Resultat : somme des profondeurs de tous les noeuds de l'arbre, 
   divisee par le nombre de noeuds. La profondeur de la racine est 0,
   celle des fils de la racine est 1, celle des fils des fils de la
   racine est 2, etc. */




/*******************************************************************/
/*           Partie specifique aux groupes D, E (vendredi)         */          
/*******************************************************************/

int desequilibreTotalArbre(const Arbre * A);
/* Precondition : *A initialise et non vide.
   Resultat : Somme des desequilibres de tous les noeuds de l'arbre. 
   Le desequilibre d'un noeud est la valeur absolue de la difference
   entre le nombre de noeuds dans son sous-arbre gauche et le nombre
   de noeuds dans son sous-arbre droit. */  

/* Compte la racine */
int nbElementsDansSousArbre(Noeud *pN);

#endif
