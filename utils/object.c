/**
 * \file object.c
 * \brief Fichier source du type Object
 * \author Hedi Nasr
 * \version 0.2
 * \date 19 décembre 2016
 *
 * Fichier source contenant les définitions des fonctions et procédures du type
 * Object.
 */
#include "object.h"
#include <stdio.h>
#include <stdlib.h>

void afficheInt(Object e) {
  printf("%d ", *((int *)e));
}

void initInt(Object *e1, Object e2) {
  *e1 = malloc(sizeof(int));
  *((int *)*e1) = *((int *)e2);
}

int compareInt(Object e1, Object e2) {
  return *((int *)e1) - *((int *)e2);
}

void testamentInt(Object *e1) { free(*e1); }
