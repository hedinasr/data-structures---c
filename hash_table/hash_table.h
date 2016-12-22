#ifndef _HASH_TABLE
#define _HASH_TABLE

#include "../utils/object.h"

typedef struct Case {
  char* key; /* indice de la case */
  Object value; /* valeur de la case */
  unsigned int init; /* case vide ou pas ? */
} Case;

typedef struct HashTable {
  Case* array; /* Tableau statique qu'on pourra modifié par une autre structure de donnée */
  int size;
  ObjectPack pack;
} HashTable;

/*************************************************************************************/
/* Résultat: retourne un entier correspondant à la chaîne de caractère en paramètre. */
/*************************************************************************************/
int hash(char* c, int size);

/*************************************************************************************/
/* Fonction de hachage utilisant le nombre d'or.                                     */
/* Résultat: retourne un entier correspondant à la chaîne de caractère en paramètre. */
/*************************************************************************************/
int golden_hash(char *c, int size);

/************************************************************/
/* Précondition(s): t non initialisé et taille valide (> 0) */
/* Post-condition(s): t initialisé                          */
/************************************************************/
void init(HashTable *t, int size, ObjectPack pack);

/********************************************************************************/
/* Précondition(s): t initialisé.                                               */
/* Résultat: retourn l'adresse de e si e est dans la table, renvoie NULL sinon. */
/********************************************************************************/
Object* search(const HashTable *t, char *key);

/***********************************************************************/
/* Précondition(s): t initialisé et e contient l'adresse d'un élément. */
/* Post-condition(s): e est haché et ajouté dans la table.             */
/***********************************************************************/
void add(HashTable *t, Object e, char *key);

/**********************************************************************/
/* Précondition(s): t initialisé.                                     */
/* Résultat: la table de hachage est affichée sur la sortie standard. */
/**********************************************************************/
void print(const HashTable *t);

/***********************************************/
/* Précondition(s): t initialisé.              */
/* Post-condition(s): t est libéré proprement. */
/***********************************************/
void clear(HashTable *t);

#endif
