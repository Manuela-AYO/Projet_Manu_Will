#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "type.h"
#include "allocation.h"

/*Génération d'une liste vide*/
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