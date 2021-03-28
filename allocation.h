/***************************************************************************/
/***	fichier : allocation.h 											***/
/*** Historique :														***/
/*** Création : 10/03/2021 par Manuela AYO								***/
/**************************************************************************/

#ifndef ALLOCATION_H
#define ALLOCATION_H

void *allocation_mem(size_t nobjects, size_t taille);

void *allocation_mem_null(size_t nobjects, size_t taille);

void libere_mem(void *pt);

#endif
