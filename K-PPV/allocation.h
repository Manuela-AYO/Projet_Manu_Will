#ifndef _ALLOCATION_H_
#define _ALLOCATION_H_


void * allocation_mem(size_t nobjets, size_t taille);

void * allocation_mem_init0(size_t nobjets, size_t taille);

/*passer l'adresse du pointeur en param pour les 2 fct suivantes*/
void * reallocation_mem(void * *pt, size_t nobjets, size_t taille);

void libere_mem(void *pt);


#endif