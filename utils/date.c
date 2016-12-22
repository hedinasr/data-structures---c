#include "date.h"
#include <stdio.h>
#include <stdlib.h>

void print_date(Object e) {
  Date a = *((Date *)e);
  printf("%d/%d/%d ", a.j, a.m, a.a);
}

void init_date(Object *e1, Object e2) {
  *e1 = malloc(sizeof(Date));
  *((Date *)*e1) = *((Date *)e2);
}

void clear_date(Object *e1) { free(*e1); }

int compare_date(Object e1, Object e2) { return -1; }
