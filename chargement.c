#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "chargement.h"
#include "type.h"
#include "listes.h"

/*Fonction de chargement des points dans la liste des points*/
/*Elle prend en paramètres le fichier à partir duquel seront chargés les points
et la liste dans laquelle seront chargés ces points*/
void chargement_fichier(char *s, liste Liste){

	/*Déclaration des variables*/
	int n, d, c;
	FILE *fichier;
	point p;

	/*Ouverture du fichier en mode lecture*/
	fichier = fopen(s, "r");

	/*Vérification de l'existence du fichier*/
	if(fichier == NULL)
	{
		fprintf(stderr, "Fichier inexistant\n");
		exit(EXIT_FAILURE);
	}

	/*Récupération des données sur la dimension, la classe et le nombre de points*/
	if(fscanf(fichier, "%d %d %d", &n, &d, &c) != EOF){

		/*Test sur la récup des données*/
		fprintf(stdout, "Nombre de points : %d\nDimension : %dd\nNombre de classes : %d\n",n,d,c );	
	
		/*Lecture des points*/
		while(fscanf(fichier, "%d %f %f", &p.classe, &p.x, &p.y) != EOF)
		{
			Liste = inserer_point(Liste, p);
		}
	}

	/*Affichage de la liste*/
	afficher(Liste);

	/*Fermeture du fichier*/
	fclose(fichier);

}

/*Cette fonction génère un fichier à partir des infos rentrées par l'utilisateur*/
void genere_fichier(char *s, int n, int d, int c){

	FILE *fichier;
	int cpt = 0, classe;
	float x, y;

	assert(n>=0);
	assert(d>=0);
	assert(c>=0);

	/*Ouverture en mode lecture + création du fichier*/
	fichier = fopen(s, "w");

	if(fichier != NULL){

		/*Infos de 1ère ligne du fichier*/
		fprintf(fichier, "%d %d %d\n", n, d, c);

		/*Génération des points de façon aléatoire*/
		while(cpt != n)//Tant qu'on n'a pas généré tous les points	
		{
			classe = rand()%c+1;
			x = ((float)rand()/(float)(RAND_MAX)) * 2.0 - 1.0;
			y = ((float)rand()/(float)(RAND_MAX)) * 2.0 - 1.0;

			fprintf(fichier, "%d %f %f\n", classe, x, y);

			cpt ++;
		}

	}

	fclose (fichier);
}