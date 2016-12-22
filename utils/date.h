#ifndef _DATE_
#define _DATE_

#include "object.h"

typedef struct Date {
  unsigned int j; /* jour */
  unsigned int m; /* mois */
  unsigned int a; /* année */
} Date;

void print_date(Object e);
void init_date(Object *e1, Object e2);
int compare_date(Object e1, Object e2);
void clear_date(Object *e1);

static const ObjectPack date_pack = {print_date, clear_date, init_date,
                                     compare_date};

#endif
