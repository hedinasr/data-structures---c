/**
 * \file skip_list.h
 * \brief Fichier d'en-tête pour le type SkipList
 * \author Hedi Nasr
 * \version 0.2
 * \date 19 décembre 2016
 *
 * Fichier d'en-tête contenant les prototypes des fonctions et
 * procédures manipulant le type SkipList.
 *
 * Inclusion des modules utilisés par le module SkipList
 * (A l'exclusion de ceux qui sont seulement utilises dans l'implantation:
 * ceux la sont inclus dans le fichier d'implantation)
 */
#ifndef _SKIP_LIST
#define _SKIP_LIST

#include "../utils/object.h"

/**
 * \struct Cellule
 * \brief Structure Cellule (entitée de la liste)
 */
typedef struct Cellule {
  Object data;             /*!< Datarmation contenue dans la Cellule */
  struct Cellule *suivant; /*!< Pointeur sur la Cellule suivante */
  struct Cellule *dessous; /*!< Pointeur sur la Cellule d'en dessous */
} Cellule;

/**
 * \struct SkipList
 * \brief Structure representant la SkipList
 */
typedef struct SkipList {
  Cellule *dummy;  /*!< Pointeur sur la Cellule bidon */
  ObjectPack pack; /*!< Indique le type d'élément de la SkipList */
  int size;        /*!< Nombre d'élement(s) de la SkipList */
  int level;       /*!< Nombre de niveau(x) de la SkipList */
} SkipList;

/**
 * \fn void init(SkipList *list, ObjectPack pack);
 * \brief initialise la liste list
 *
 * \param *list  non préalablement initialisée
 * \param pack indique le type d'élément de la SkipList
 *
 */
void init(SkipList *list, ObjectPack pack);

/**
 * \fn void clear(SkipList *l);
 * \brief *l prête à être détruite
 * \param *l préalablement initialisée et manipulée uniquement à travers les
 * opérations du module.
 */
void clear(SkipList *l);

/**
 * \fn int empty(const SkipList *l);
 * \brief retourne 1 si l est vide, 0 sinon
 * \param l préalablement initialisée et manipulée uniquement à travers les
 * opérations du module.
 */
int empty(const SkipList *l);

/**
 * \fn void print(const SkipList *l);
 * \brief Affichage exhaustif de tous les éléments de l
 * \param l initialisée et manipulée uniquement à travers les opérations du
 * module.
 */
void print(const SkipList *l);

/**
 * \fn void push_back(SkipList *l, Object e);
 * \brief L'Object e est ajouté en tête de *l
 * \param *l initialisé et manipulé uniquement à travers les opérations du
 * module
 * \param e initialisé et manipulé uniquement à travers les opérations du
 * module
 */
void push_back(SkipList *l, Object e);

/**
 * \fn Cellule * search(const SkipList *l, Object e);
 * \brief retourne l'élément si celui-ci à été trouvé
 * \param *l initialisé et manipulé uniquement à travers les opérations du
 * module
 * \param e initialisé et manipulé uniquement à travers les opérations du
 * module
 */
Cellule *search(const SkipList *l, Object e);

/**
 * \fn void delete(SkipList *l, Object e);
 * \brief toutes les occurrences de e sont supprimées
 * \param *l initialisé et manipulé uniquement à travers les opérations du
 * module
 * \param e initialisé et manipulé uniquement à travers les opérations du
 * module
 */
void delete (SkipList *l, Object e);

#endif
