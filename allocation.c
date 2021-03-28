/***************************************************************************/
/***	fichier : allocation.c 											***/
/*** Historique :														***/
/*** Création : 10/03/2021 par Manuela AYO								***/
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#include "mon_erreur.h"

void *allocation_mem(size_t nobjects, size_t taille)
{

  void *pt;

  pt = malloc(nobjects*taille);

  if(pt==NULL)
    mon_erreur("Impossible d'allouer la mémoire %d %d\n", nobjects, taille);

  return pt;
}

void *allocation_mem_null(size_t nobjects, size_t taille)
{
	void *pt;

	pt = calloc(taille, nobjects);

	/*Controle*/
	if(pt == NULL)
		mon_erreur("Allocation Impossible %d %d\n", nobjects, taille);

	return pt;
}

void libere_mem(void *pt)
{
	void **adr = (void **)pt;/*Adresse du pointeur*/

	if(*adr != NULL)
		free(*adr);/*Libération de *pt*/

	*adr = NULL;/* *pt pointe maintenant sur NULL*/
}


