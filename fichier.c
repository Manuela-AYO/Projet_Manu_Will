/***************************************************************************
 * Ce module implémente toutes les fonctions relatives aux fichiers à      *
 * savoir :                                                                *
 *   ->le chargement d'un fichier dans un tableau de points                *
 *   ->la sauvegarde dans un fichier d'un tableau de points                *
 *                                                                         *
 * Le chargement d'un fichier dans un tableau de points se fait dans le    *
 * format suivant :                                                        * 
 *                                                                         *
 *  -La première ligne contient 3 entiers positifs séparés par un espace : *
 *      >le nombre de points n contenus dans le fichier,                   *
 *      >la dimension d des données                                        *
 *      >et le nombre de classe c.                                         *
 *                                                                         *
 *    -Les n lignes restantes du fichier sont de la forme :                *
 *      >classe coord_1 coord_2 ... coord_d,                               *
 * où classe est un entier compris entre 1 et c et les coordonnées sont    *
 * des réelscompris entre -1 et 1.                                         *
 *                                                                         *
 * La sauvegarde dans un fichier d'un tableau de points avec un point par  * 
 * ligne se fait suivant le format :                                       *
 *                                                                         *
 *     >Abscisse_point Ordonnée_point Classe_point                         *
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "../inc/fichier.h"
#include "../inc/type.h"
#include "../inc/allocation.h"


/* *** Fonction de chargement des points dans le tableau de points *** */
/* t doit pointer sur une structure existante 'vide' */
void chargement_fichier(char *chemin, tableau_de_points *t)
{

    /*--Déclaration des variables--*/
    int n, d, c; /*nombre de : point, dimension, classes*/
    FILE *fichier=NULL;
    point p;
    int i;

    /*--Ouverture du fichier en mode lecture--*/
    fichier = fopen(chemin, "r");

    /*--Vérification de l'existence du fichier--*/
    if(fichier == NULL)
    {
        fprintf(stderr, "Fichier '%s' inexistant\n", chemin);
    }
    else{
      /*--Récupération des données sur la dimension, la classe et le nombre de points--*/
      if(fscanf(fichier, "%d %d %d", &n, &d, &c) != EOF){

	/*--vérification des valeurs de la première ligne--*/
	assert(n>0);
	assert(d>0);
	assert(c>0);

	/*--initialisation du tableau de points--*/
	t->tab= (point *) allocation_mem(n, sizeof(point));
	t->nb_points= 0;
	t->taille= n;
	
	/*--Lecture des points--*/
	for(i=0; i<n; i++)
	  {
	    if(fscanf(fichier, "%u %f %f", &p.classe, &p.x, &p.y) != EOF)
	      {
		t -> tab[i].x = p.x;
		t -> tab[i].y = p.y;
		t -> tab[i].classe = p.classe;
		t -> nb_points++;
	      }
	  }
      }

      /*Fermeture du fichier*/
      fclose(fichier);
    }
}

/* *** Fonction de sauvegarde *** */
int sauvegarde_fichier(tableau_de_points t, char *chemin_fichier)
{
  /*--Déclaration des variables*/
  FILE *fichier;
  int i;

  fichier = fopen(chemin_fichier, "w");

  if(fichier == NULL)
    {
      printf("Impossible de créer le fichier\n");
      return 0;/*Retour de sauvegarde échouée*/
    }

  for(i=0; i<t.nb_points; i++)
    fprintf(fichier,"%f %f %d\n", t.tab[i].x, t.tab[i].y, t.tab[i].classe);

  fclose(fichier);

  /*--Si sauvegarde réussie--*/
  return 1;
}

