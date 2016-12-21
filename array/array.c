#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

void init(Array *t) {
  t->array = (int *)malloc(sizeof(int));
  t->capacity = 1;
  t->size = 0;
}

void clear(Array *t) {
  free(t->array);
  t->capacity = 0;
  t->size = 0;
}

void push_back(Array *t, int e) {
  if (t->capacity == t->size) {
    int *newTab =
        (int *)malloc(2 * t->capacity * sizeof(int));
    // On double la capacité du tableau
    t->capacity *= 2;
    for (int i = 0; i < t->size; i++) {
      newTab[i] = t->array[i];
    }
    free(t->array);
    t->array = newTab;
  }

  t->array[t->size] = e;
  t->size++;
}

int at(const Array *t, unsigned int i) {
  if (i < t->size) {
    return t->array[i];
  } else {
    return -1;
  }
}

void updateAt(Array *t, int e, unsigned int i) {
  if (i < t->size) {
    t->array[i] = e;
  }
}

void print(const Array *t) {
  int i;
  for (i = 0; i < t->size; i++) {
    printf("%d\n", t->array[i]);
  }
}

void delete (Array *t, int position) {
  int i;
  int *p;

  if (t->size < t->capacity / 3) {
    p = malloc((t->capacity / 2) * sizeof(int));
    t->capacity /= 2;
  } else {
    p = malloc(t->capacity * sizeof(int));
  }

  for (i = 0; i < t->size - 1; i++) {
    if (i >= position) {
      p[i] = t->array[i + 1];
    } else {
      p[i] = t->array[i];
    }
  }
  free(t->array);
  t->array = p;
  t->size = t->size - 1;
}

void copy(Array *t1, const Array *t2) {
  int i;
  clear(t1);
  t1->array = malloc(t2->capacity * sizeof(int));
  t1->size = t2->size;
  t1->capacity = t2->capacity;
  for (i = 0; i < t2->size; i++) {
    t1->array[i] = t2->array[i];
  }
}

void insert(Array *t, int e, unsigned int i) {
  int j;
  int *temp;
  if (i >= t->size)
    /* Si on place l'élement après le dernier */
    push_back(t, e);
  else {
    if (t->size == t->capacity) {
      printf("Cas ou il ne reste plus de place dans mon tableau\n");
      temp = t->array;
      t->array = malloc(2 * t->capacity * sizeof(int));
      /* Il faut rajouter une condition pour i = 0 */
      if (i == 0) {
        updateAt(t, e, i);
        /*On remplit le tableau jusqu'a la ième position - 1*/
        for (j = 1; j < t->size; j++) {
          updateAt(t, temp[j], j);
        }
        t->capacity = 2 * t->capacity;
        free(temp);
      } else {
        /*On remplit le tableau jusqu'a la ième position - 1*/
        for (j = 0; j < i - 1; j++) {
          updateAt(t, temp[j], j);
        }
        updateAt(t, e, i);
        for (j = i; j < t->size; j++) {
          updateAt(t, temp[j + 1], j + 1);
        }
        t->capacity = 2 * t->capacity;
        free(temp);
      }
    } else {
      /* Dans le cas ou il reste de la place dans le tableau pour placé mon
         élément */
      printf("Cas ou il reste de la place dans le tableau\n");
      for (j = t->size - 1; j > i; j--) {
        updateAt(t, t->array[j], j + 1);
      }
      updateAt(t, e, i);
    }
    t->size++;
  }
}

void concat(const Array *a, const Array *b, Array *result) {
  int i = 0;
  init(result);
  for (i = 0; i < a->size; i++) {
    push_back(result, at(a, i));
  }
  for (i = 0; i < b->size; i++) {
    push_back(result, at(b, i));
  }
}
