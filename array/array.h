/////////////////////////////////////////////////////////////////////////////
// array.h                                                                 //
//                                                                         //
// Ce module implémente la structure de donnée tableau dynamique en C.     //
// Il fournit les fonctions et procédures nécessaires pour la manipulation //
// de tableau.                                                             //
/////////////////////////////////////////////////////////////////////////////
#ifndef _ARRAY
#define _ARRAY

/**
 * -- Données membres --
 * (ne sont pas censées être connues par l'utilisateur d'un module :
 * SI ON AVAIT PU NE PAS LES FAIRE FIGURER DANS L'INTERFACE, on l'aurait fait!)
*/
typedef struct Array {
  unsigned int capacity;
  unsigned int size;
  int *array;
} Array;

/**
 * Pré-condition : t non préalablement initialisé
 * Post-condition : t initialisé à une alveole vide (taille utilisée nulle)
 */
void init(Array *t);

/**
 * Pré-condition : t préalablement initialisé
 * Post-condition : t prêt a disparaître. La mémoire allouée dynamiquement
 * est libérée. On ne pourra plus appeler les sous-programmes qui nécessitent
 * que t soit initialisé.
 */
void clear(Array *t);

/**
 * Pré-condition : t1 et t2 initialisés
 * Postcondition : l'ancien contenu de t1 est perdu. t1 et t2 contiennent
 * des sequences d'ElementTD identiques (t1 correspond a une copie de t2,
 * les 2 tableaux ont meme capacite, meme taille utilisee, mais sont
 * independants).
 */
void copy(Array *t1, const Array *t2);

/**
 * Pré-condition : t préalablement initialisé
 * Résultat : nombre d'ElementTDs stockés dans t
 */
unsigned int size(const Array *t);

/**
 * Pré-condition : t préalablement initialisé, 0 <= i < tailleUtilisee(t)
 * Resultat : retourne l'élément à l'indice i de t
 */
int at(const Array *t, unsigned int i);

/**
 * Pré-condition : t préalablement initialisé
 * Post-condition : Les éléments du tableau sont affichés sur la sortie
 * standard en utilisant la procédure d'affichage définie dans le module
 * ElementTD.
 */
void print(const Array *t);

/**
 * Pré-condition : t préalablement initialisé
 * Post-condition : L'élément e est ajouté dans la première alvéole inutilisée
 * du tableau, la taille utilisée est incrementée de 1. Doublement de la
 * capacité de t, si nécessaire.
 */
void push_back(Array *t, int e);

/**
 * Pré-condition : t préalablement initialisé et non vide, et 0 <= position <=
 * t->taille_utilisee - 1
 * Post-condition : la taille utilisée du tableau est decrémentée de 1. Si
 * tailleUtilisee < capacite/3, alors on divise la capacité par 2.
 */
void delete (Array *t, int position);

/**
 * Pré-condition : t préalablement initialisé et 0 <= i < tailleUtilisee(t).
 * Post-condition : l'élément à l'incide i de t vaut e.
 */
void updateAt(Array *t, int e, unsigned int i);

/**
 * Precondition : t prealablement initialise et 0 <= i < tailleUtilisee(t)
 * Postcondition : e est insere dans la case d'indice i et tailleUtilisee est
 * incrementee de 1
 */
void insert(Array *t, int e, unsigned int i);

/**
 * Precondition : t prealablement initialise
 * Postcondition : t est trie dans l'ordre croissant
 */
void sort(Array *t);

/**
 * Precondition : t prealablement initialise et trie dans l'ordre croissant
 * Resultat : numero de l'alveole (ou l'une des alveoles) qui contient un
 * ElementTD egal a e, ou bien -1 si t ne contient pas d'element egal a e
 */
int search(const Array *t, int e);

void concat(const Array *a, const Array *b, Array *result);

#endif
