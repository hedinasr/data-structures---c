#ifndef _TREE
#define _TREE

typedef struct Node {
	int		data;
	struct Node  *left;	/* fils gauche */
	struct Node  *right;	/* file droit */
}	Node;

typedef struct Tree {
	Node  *root;
	int		size;
}	Tree;

/*
 * Precondition : *A non prealablement initialise Postcondition : *A est
 * initialise vide
 */
void		init(Tree * A);

/*
 * Precondition : *A prealablement initialise Postcondition : *A pret a
 * disparaitre (ne doit plus etre utilise)
 */
void		clear(Tree * A);

/*
 * Precondition : *A et B prealablement initialises Postcondition : *A et B
 * correspondent a des arbres identiques (mais ils sont totalement
 * independants l'un de l'autre) (*A est une copie de B)
 */
void		copy(Tree * A, const Tree * B);

/*
 * Precondition : *A initialise Resultat : 1 si *A est vide, 0 sinon
 */
int		empty(const Tree * A);

/*
 * Precondition : *A initialise Postcondition : Affichage infixe de tous les
 * elements de *A
 */
void		afficherTreeParcoursInfixe(const Tree * A);

void		affichageArborescent(const Tree * A);

/*
 * Precondition : *A initialise Postcondition : *A est vide
 */
void		erase(Tree * A);

/*
 * Precondition : *A est un arbre binaire de recherche initialise
 * Postcondition : si e n'existait pas deja dans l'arbre *A, alors un nouveau
 * noeud contenant e est insere aux feuilles de *A. Si au contraire e
 * existait deja dans l'arbre, alors l'arbre est inchange.
 */
void		insert(int e, Tree * A);

/*
 * Precondition : *A initialise Postcondition : si aucun noeud de l'arbre *A
 * ne contient la valeur e passee en parametre, l'entier *trouve vaut 0. Si
 * au contraire on a trouve un noeud avec le e demande, alors *trouve vaut 1.
 * Dans les deux cas, *nb_visites contient le nombre de comparaisons
 * d'Elements effectuees lors de cette recherche.
 */
void
search(int e, const Tree * A, int *trouve,
		       int *nb_visites);

/*
 * Precondition : *A initialise Résultat : renvoie la hauteur de l'arbre
 * (longueur de sa plus longue branche), ou -1 s'il est vide
 */
int		hauteurTree(const Tree * A);

/*
 * Precondition : a initialise Resultat : somme des profondeurs de tous les
 * noeuds de l'arbre, ivisee par le nombre de noeuds. La profondeur de la
 * racine est 0, celle des fils de la racine est 1, celle des fils des fils
 * de la racine est 2, etc.
 */
double		profondeurMoyenneTree(const Tree *);

/*
 * Precondition : *A initialise et non vide. Resultat : Somme des
 * desequilibres de tous les noeuds de l'arbre. e desequilibre d'un noeud est
 * la valeur absolue de la difference entre le nombre de noeuds dans son
 * sous-arbre gauche et le nombre de noeuds dans son sous-arbre droit.
 */
int		desequilibreTotalTree(const Tree *);

/* Compte la racine */
int		nbElementsDansSousTree(Node * pN);

#endif
