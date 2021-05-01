/***********************************************
 * Module de chargement des données du fichier *
 * dans un tableau de points  et de sauvegarde *
 * d'un tableau de points dans un fichier      *
 ***********************************************/
#ifndef _FICHIER_H
#define _FICHIER_H

#include "type.h"

#define TAILLE_MAX 100


/* ***Fonction de chargement des points dans le tableau de points** */
void chargement_fichier(char *s, tableau_de_points *t);

/* *** Fonction de sauvegarde *** */
int sauvegarde_fichier(tableau_de_points t, char *chemin_fichier);

#endif
