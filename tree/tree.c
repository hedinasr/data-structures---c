#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void 
init(Tree * A)
{
	A->root = NULL;
	A->size = 0;
}

static void 
insererintpartirDeNode(int e, Node ** c)
{

	if (*c == NULL) {
		*c = (Node *) malloc(sizeof(Node));
		(*c)->data = e;
		(*c)->left = NULL;
		(*c)->right = NULL;
	} else {
		if (e != (*c)->data) {
			if ((*c)->data < e) {
				insererintpartirDeNode(e, &(*c)->right);
			} else {
				insererintpartirDeNode(e, &(*c)->left);
			}
		}
	}
}

static void 
afficherTreeApartirDeNode(const Node * c)
{
	if (c != NULL) {
		afficherTreeApartirDeNode(c->left);
    printf("%d ", c->data);
		afficherTreeApartirDeNode(c->right);
	}
}

static void 
rechercherintpartirDeNode(int e, const Node * c, int *trouve, int *nb_visites)
{
	*trouve = -1;
	*nb_visites = 0;
	if (c != NULL) {
		if (e == c->data) {
			*trouve = 1;
			(*nb_visites)++;
		} else {
			if (e < c->data) {
				rechercherintpartirDeNode(e, c->left, trouve, nb_visites);
				(*nb_visites)++;
			} else {
				rechercherintpartirDeNode(e, c->right, trouve, nb_visites);
				(*nb_visites)++;
			}
		}
	}
}

static void 
viderApartirDeNode(Node * c)
{
	if (c != NULL) {
		viderApartirDeNode(c->left);
		viderApartirDeNode(c->right);
		free(c);
	}
}

static int 
hauteurApartirDeNode(Node * c)
{
	int		hd        , hg;
	if (c == NULL)
		return -1;
	hd = hauteurApartirDeNode(c->right);
	hg = hauteurApartirDeNode(c->left);
	if (hd > hg)
		return hd + 1;
	return hg + 1;
}

void 
insert(int e, Tree * A)
{
	insererintpartirDeNode(e, &A->root);
	A->size++;
}

void 
afficherTreeParcoursInfixe(const Tree * A)
{
	afficherTreeApartirDeNode(A->root);

}

void 
search(int e, const Tree * A, int *trouve, int *nb_visites)
{
	rechercherintpartirDeNode(e, A->root, trouve, nb_visites);

}

void 
erase(Tree * A)
{
	viderApartirDeNode(A->root);
	A->size = 0;
}

void 
clear(Tree * A)
{
	erase(A);
	A->root = NULL;

}

int 
hauteurTree(const Tree * A)
{
	if (A->root != NULL)
		return hauteurApartirDeNode(A->root);
	return -1;
}
