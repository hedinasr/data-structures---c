#include <stdio.h>
#include <stdlib.h>
#include "ElementA.h"
#include "Arbre.h"

void initialiserArbre(Arbre * A)
{
  A->adRacine = NULL;
  A->nbElemDansArbre = 0;
}

/* =============FONCTIONS RECURSIVE============= */
static void insererElementApartirDeNoeud(ElementA e, Noeud **c)
{
  
  if(*c == NULL)
    {
      *c = (Noeud *)malloc(sizeof(Noeud));
      (*c)->info = e;
      (*c)->fg = NULL;
      (*c)->fd = NULL;
    }
  else
    {
      if(e != (*c)->info)
	{
	  if((*c)->info < e)
	    {
	      insererElementApartirDeNoeud(e,&(*c)->fd);
	    }
	  else
	    {
	      insererElementApartirDeNoeud(e,&(*c)->fg);
	    }
	}
    }
}

static void afficherArbreApartirDeNoeud(const Noeud * c)
{
  if(c!=NULL)
    {
      afficherArbreApartirDeNoeud(c->fg);
      afficherElementA(c->info);
      afficherArbreApartirDeNoeud(c->fd);
    }
}

static void rechercherElementApartirDeNoeud(ElementA e, const Noeud *c, int *trouve, int *nb_visites)
{
  *trouve = -1;
  *nb_visites = 0;
  if(c != NULL)
    {
      if(e == c->info)
	{
	  *trouve = 1;
	  (*nb_visites)++;
	}
      else
	{
	  if(e<c->info)
	    {
	      rechercherElementApartirDeNoeud(e,c->fg,trouve,nb_visites);
	      (*nb_visites)++;
	    }
	  else
	    {
	      rechercherElementApartirDeNoeud(e,c->fd,trouve,nb_visites);    
	      (*nb_visites)++;
	    }
	}
    }
}

static void viderApartirDeNoeud(Noeud *c)
{
  if(c != NULL)
    {
      viderApartirDeNoeud(c->fg);
      viderApartirDeNoeud(c->fd);
      free(c);
    }
}

static int hauteurApartirDeNoeud(Noeud *c)
{
  int hd,hg;
  if(c == NULL) return -1;
  hd = hauteurApartirDeNoeud(c->fd);
  hg = hauteurApartirDeNoeud(c->fg);
  if(hd>hg) return hd+1;
  return hg+1;
}

/* =============FONCTIONS RECURSIVE============= */
 
void insererElementArbre(ElementA e, Arbre *A)
/* Precondition : *A est un arbre binaire de recherche initialise
   Postcondition : si e n'existait pas deja dans l'arbre *A, alors
   un nouveau noeud contenant e est insere aux feuilles de *A. 
   Si au contraire e existait deja dans l'arbre, alors l'arbre est
   inchange. */
{
  insererElementApartirDeNoeud(e,&A->adRacine);
      A->nbElemDansArbre++;
}

void afficherArbreParcoursInfixe(const Arbre * A)
{
  afficherArbreApartirDeNoeud(A->adRacine);

}

void rechercherElementArbre(ElementA e, const Arbre *A, int * trouve, int * nb_visites)
{
  rechercherElementApartirDeNoeud(e,A->adRacine,trouve,nb_visites);

}

void viderArbre(Arbre *A)
{
  viderApartirDeNoeud(A->adRacine);
  A->nbElemDansArbre = 0;
}

void testamentArbre(Arbre *A)
{
  viderArbre(A);
  A->adRacine = NULL;

}

int hauteurArbre(const Arbre * A)
{
  if(A->adRacine != NULL)  return hauteurApartirDeNoeud(A->adRacine);
  return -1;
}
