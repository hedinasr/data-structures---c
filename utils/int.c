/**
 * \file int.c
 * \brief Fichier source du type Int
 * \author Hedi Nasr
 * \version 0.1
 * \date 22 décembre 2016
 *
 * Fichier source contenant les définitions des fonctions et procédures du type
 * Int.
 */
#include "int.h"
#include <stdio.h>
#include <stdlib.h>

void print_int(Object e) { printf("%d ", *((int *)e)); }

void init_int(Object *e1, Object e2) {
  *e1 = malloc(sizeof(int));
  *((int *)*e1) = *((int *)e2);
}

int compare_int(Object e1, Object e2) { return *((int *)e1) - *((int *)e2); }

void clear_int(Object *e1) { free(*e1); }
