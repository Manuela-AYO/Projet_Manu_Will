#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include "type.h"
#include "allocation.h"

/* ***Génération d'une liste vide*** */
liste creer_liste_vide()
{
	return NULL;
}

/*Cette fonction renvoie 1 si la liste est vide et 0 sinon*/
int est_liste_vide(liste L)
{
	if(L == creer_liste_vide())
		return 1;

	return 0;
}

/*Insertion d'un point dans la liste*/
liste inserer_point(liste l, point pt)
{
	liste lnew=(liste)allocation_mem(1, sizeof(element));
	lnew -> courant.x = pt.x;
	lnew -> courant.y = pt.y;
	lnew -> courant.classe = pt.classe;
	lnew -> suivant = l;

	return lnew;
}

/*Affichage des éléments de la liste*/
void afficher(liste l)
{
	if(l == creer_liste_vide())
		printf("La liste est vide");

	else
	{
		while(l != creer_liste_vide() )
		{
			
			printf("x=%f y=%f c=%d", l -> courant.x, l -> courant.y, l -> courant.classe);
			
			if(l -> suivant != NULL)
				printf(" -> ");
			
			l = l -> suivant;

		}
	}
}

/* ***Fonctions sur le type liste_div *** */

/*Fonction de calcul de la distance euclidienne*/
float distance_euclidienne(point pt1, point pt2)
{
  return sqrt(pow(pt2.x-pt1.x,2)+pow(pt2.y-pt1.y,2));
}

/* renvoie la liste_div vide */
liste_div creer_liste_div_vide()
{
  return NULL;
}

/* teste si une liste_div est vide */
int est_liste_div_vide(liste_div l)
{
  if(l == creer_liste_div_vide())
    return 1;

  return 0;
}

/* ***Fonction qui renvoie la taille de la liste_div*** */
int taille_liste_div(liste_div ld)
{
	liste_div temp=ld;
	int cpt=0;
	
	while(!est_liste_div_vide(temp))
	{
		cpt ++;
		temp = temp -> suivant;
	}
		
	return cpt;
}

/* ***Fonction d'insertion d'un point au début de la liste_div*** */
liste_div insere_liste_div(liste_div ld, point pt, float distance)
{
  liste_div l = (liste_div)allocation_mem(1, sizeof(struct_element));
  l -> pt.x = pt.x;
  l -> pt.y = pt.y;
  l -> pt.classe = pt.classe;
  l -> distance = distance;
  l -> suivant = ld;

  return l;
}

/* ***fonction qui génère une liste_div*** */
liste_div genere_liste_div(liste l, point pt)
{
  liste temp = l;
  float distance;
  liste_div ld = creer_liste_div_vide();

  while(!est_liste_vide(temp))
    {
      distance = distance_euclidienne(pt, temp->courant);
      ld = insere_liste_div(ld, temp->courant, distance);
      temp = temp -> suivant;
    }
    
  return ld;
}

/* ***Fonction d'affichage de la liste_div*** */
void affiche_liste_div(liste_div ld)
{
  liste_div temp = ld;
  
  while(!est_liste_div_vide(temp))
    {
      printf("Abs:%f Ord:%f Classe:%d distance:%f\n", temp->pt.x, temp->pt.y, temp->pt.classe, temp->distance);
      temp = temp -> suivant;
    }
    
}

/* ***Fonction de tri de la liste_div*** */
liste_div tri_liste_div(liste_div ld)
{
	liste_div temp, l;
	temp = ld;
	float distance;
	point pt;
	
	while(!est_liste_div_vide(temp->suivant))
	{
		l = temp -> suivant;
		while(!est_liste_div_vide(l))
		{
			if(l->distance < temp ->distance)
			{
				pt = l->pt;
				distance = l->distance;
				l->distance = temp->distance;
				l->pt = temp->pt;
				temp->pt = pt;
				temp->distance = distance;
			}
			
			l = l->suivant;
		}
		temp = temp -> suivant;
	}
	return ld;
}

/* ***Fonction de suppression du dernier élément de la liste_div *** */
liste_div supprime_dernier_liste_div(liste_div ld)
{
	liste_div temp = ld, l1;
	
	while(!est_liste_div_vide(temp -> suivant->suivant))
	 temp = temp -> suivant;
	 
	 l1 = temp -> suivant;
	 temp -> suivant = NULL;
	 
	 libere_mem((void**)&l1);
	 
	 return ld;
}
