#ifndef _INT_
#define _INT_

#include "object.h"

/**
 * \fn void afficheInt(Object e);
 * \brief Affiche l'élément sur la sortie standard
 *
 * \param e l'élément à afficher
 * Précondition(s): e initialisé et manipulé uniquement a travers les fonctions
 * du
 * module.
 */
void print_int(Object e);

/**
 * \fn void initInt(Object * e1, Object e2);
 * \brief e1 clone de l'element correspondant a e2
 *
 * \param [in] e2 initialise de type effectif int ou bien e2 adresse d'une
 * variable de type int
 * \param [in,out] e1
 */
void init_int(Object *e1, Object e2);

/**
 * \fn int compareInt(Object e1, Object e2);
 * \brief Si e1 > e2 retourne 1, 0 sinon
 *
 * \param e1 initialise
 * \param e2 initialise
 */
int compare_int(Object e1, Object e2);

/**
 * \fn void testamentInt(Object *e1);
 * \brief e1 libere et detruit
 *
 * \param e1 initialise et manipule uniquement à travers le module
 */
void clear_int(Object *e1);

static const ObjectPack Int = {print_int, clear_int, init_int, compare_int};

#endif
