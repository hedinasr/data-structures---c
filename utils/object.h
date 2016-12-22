/**
 * \file object.h
 * \brief Fichier d'en-tête pour le type Object
 * \author Hedi Nasr
 * \version 0.2
 * \date 19 décembre 2016
 *
 * Fichier d'en-tête contenant les prototypes des fonctions et procédures
 * manipulant le type Object.
 */
#ifndef _OBJECT
#define _OBJECT

/**
 * \typedef Object
 * \brief Object nous permettras de faire abstraction sur le type des éléments
 * manipulés.
 */
typedef void *Object;

/**
 * \struct ObjectPack
 * \brief Structure pack d'éléments
 *
 * ObjectPack est une structure de gestion d'éléments. Celle-ci nous permet de
 * manipuler
 * des "pack" d'éléments, afin d'avoir plus de fléxibilité pour la généricité.
 * Celle-ci
 * contient les pointeurs sur les différentes fonctions manipulant les éléments.
 */
typedef struct ObjectPack {
  void (*print)(Object);     /*!< Pointeur sur la procedure d'affichage. */
  void (*clear)(Object *); /*!< Pointeur sur la procedure de testament. */
  void (*init)(Object *,
               Object); /*!< Pointeur sur la procedure d'initialisation. */
  int (*compare)(Object,
                 Object); /*!< Pointeur sur la fonction de comparaison. */
} ObjectPack;

#endif
