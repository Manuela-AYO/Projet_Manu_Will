#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chargement.h"
#include "type.h"
#include "listes.h"
#include "mon_erreur.h"
#include "allocation.h"

int main(int argc, char **argv)
{
	liste L=creer_liste_vide();

	srand(time(NULL));

	/*Génération de fichier*/
	if(argc != 5)
	{
		mon_erreur("Ce programme prend en arguments respectivement le nom du fichier à générer, le nombre de points à générer, la dimension et la classe des points\n");
	}

	genere_fichier(argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

	chargement_fichier(argv[1], L);

	/*Libération de la mémoire*/
	libere_mem(&L);

	return EXIT_SUCCESS;
}
