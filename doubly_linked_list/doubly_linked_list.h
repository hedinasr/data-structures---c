/////////////////////////////////////////////////////////////////////////////////
// doubly_linked_list.h                                                        //
//                                                                             //
// Ce module implémente la structure de données liste doublement chaînée en C. //
// Il fournit les fonctions et procédures nécessaires pour la manipulation de  //
// liste.                                                                      //
/////////////////////////////////////////////////////////////////////////////////
#ifndef _DOUBLY_LINKED_LIST
#define _DOUBLY_LINKED_LIST

typedef struct Node
{
  int info;
  struct Node *next;
  struct Node *pred;
} Node;

typedef struct DoublyLinkedList
{
  Node *first;
  Node *last;
} DoublyLinkedList;

/////////////////////////////////////////////////////////
// Précondition(s): l non préalablement initialisé.    //
// Post-condition(s): la liste l initialisée est vide. //
/////////////////////////////////////////////////////////
void init(DoublyLinkedList * l);

/////////////////////////////////////////
// Résultat: 1 si l est vide, 0 sinon. //
/////////////////////////////////////////
int empty(const DoublyLinkedList * l);


//////////////////////////////////////////////////////////////////////
// Résultat: retourne le nombre d'élément(s) contenu dans la liste. //
//////////////////////////////////////////////////////////////////////
unsigned int size(const DoublyLinkedList * l);


////////////////////////////////////////////////////////////////////
// Précondition(s): l n'est pas vide, et 0 <= i < size(l).        //
// Résultat: valeur du i-ème élément de la liste, sachant que les //
//           éléments sont numérotés à partir de 0.               //
////////////////////////////////////////////////////////////////////
int at(const DoublyLinkedList * l, unsigned int i);

/////////////////////////////////////////////////////////////////////////////////
// Précondition(s): l n'est pas vide, et 0 <= i < size(l).                     //
// Post-condition(s): e remplace le i-ème élément de la liste, sachant que les //
//                    éléments sont numérotés à partir de 0.                   //
/////////////////////////////////////////////////////////////////////////////////
void update_at(const DoublyLinkedList * l, unsigned int i, int e);

////////////////////////////////////////////////////////////////////////
// Résultat: retourne l'adresse de la première cellule si l non vide, //
//           NULL sinon.                                              //
// Attention: la liste l pourra ensuite être modifiée à travers la    //
//            connaissance de l'adresse de sa première cellule.       //
////////////////////////////////////////////////////////////////////////
Node* begin(const DoublyLinkedList * l);

/////////////////////////////////////////////////////////////////////////////////////
// Précondition(s): c adresse valide d'une cellule de la liste l.                  //
// Résultat: retourne l'adresse de la cellule suivante si elle existe, NULL sinon. //
// Attention: la liste l pourra ensuite être modifiée à travers la connaissance    //
//            de l'adresse d'une de ses cellules.                                  //
/////////////////////////////////////////////////////////////////////////////////////
Node * next(const Node *c, const DoublyLinkedList * l);

/////////////////////////////////////////////////////////////////////////////
// Résultat: affiche tous les éléments de l, en commencant par le premier. //
/////////////////////////////////////////////////////////////////////////////
void print_left_right(const DoublyLinkedList * l);

////////////////////////////////////////////////////////////////////////////////
// Résultat: affiche de tous les éléments de l, en commencant par le dernier. //
////////////////////////////////////////////////////////////////////////////////
void print_right_left(const DoublyLinkedList * l);


void ajouterEnTeteDoublyLinkedList(int e,DoublyLinkedList * l);
/* Precondition : l et e initialises et manipules uniquement a travers les
                  operations de leurs modules respectifs
   Postcondition : e est ajoute en tete de l */

////////////////////////////////////////////////////////////
// Post-condition(s): e est ajouté à la fin de la liste l. //
////////////////////////////////////////////////////////////
void push_back(int e, DoublyLinkedList * l);


void supprimerTeteDoublyLinkedList(DoublyLinkedList * l);
/* Precondition : l n'est pas vide
   Postcondition : la liste l perd son premier element */


///////////////////////////////////////////////////////////
// Post-condition(s): l ne contient plus aucune cellule. //
///////////////////////////////////////////////////////////
void erase(DoublyLinkedList * l);

/////////////////////////////////////////////////
// Post-condition(s): l prête à être détruite. //
/////////////////////////////////////////////////
void clear(DoublyLinkedList * l);

/////////////////////////////////////////////////////////////////////////////////////
// Post-condition(s): la liste l1 correspond à une copie de l2 (mais               //
//                    les 2 listes sont totalement indépendantes l'une de l'autre) //
/////////////////////////////////////////////////////////////////////////////////////
void copy(DoublyLinkedList * l1, const DoublyLinkedList * l2);

/////////////////////////////////////////////////////////////////////////////////////////
// Résultat: retourne la position de la première occurrence de e dans la liste (en     //
// partant de la gauche), -1 si e n'est pas dans la liste. Les cellules sont           //
// numerotées de 0 a n-1, donc une valeur de retour égale à 0 signifie que la première //
// occurrence de e se trouve dans la première cellule de la liste.                     //
/////////////////////////////////////////////////////////////////////////////////////////
int search(int e, const DoublyLinkedList *l);

//////////////////////////////////////////////////////////////////////////////////////
// Précondition(s): l initialisé et manipulé uniquement à travers les oéerations    //
//                  du module, 0 <= position <= size(l)                             //
// Post-condition(s): une copie indépendante de e est insérée de sorte à ce qu'elle //
//                    occupe la position indiquée dans la liste l (les positions    //
//                    étant numérotées à partir de 0).                              //
//////////////////////////////////////////////////////////////////////////////////////
void insert(int e, DoublyLinkedList * l, unsigned int position);

#endif
