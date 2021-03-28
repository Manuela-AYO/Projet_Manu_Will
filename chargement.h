#ifndef _CHARGEMENT_H
#define _CHARGEMENT_H

#include "type.h"
#include "listes.h"

/*Fonction de chargement des points dans la liste des points*/
/*Elle prend en paramètres le nom fichier à partir duquel seront chargés les points
et la liste dans laquelle seront chargés ces points*/
void chargement_fichier(char * , liste);

/*Cette fonction génère un fichier à partir des infos rentrées par l'utilisateur*/
void genere_fichier(char *s, int n, int d, int c);

#endif