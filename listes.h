#ifndef _LISTES_H
#define _LISTES_H

#include "type.h"

/*Génération d'une liste vide*/
liste creer_liste_vide();

/*Cette fonction renvoie 1 si la liste est vide et 0 sinon*/
int est_liste_vide(liste L);

/*Insertion d'un point dans la liste*/
liste inserer_point(liste l, point pt);

/*Affichage des éléments de la liste*/
void afficher(liste);



/* ***Fonctions sur le type liste_div*** */

/* ***Fonction qui renvoie la taille de la liste_div*** */
int taille_liste_div(liste_div ld);

/*Fonction de calcul de la distance euclidienne*/
float distance_euclidienne(point pt1, point pt2);

/* renvoie la liste_div vide */
liste_div creer_liste_div_vide();

/* teste si une liste_div est vide */
int est_liste_div_vide(liste_div l);

/* ***Fonction d'insertion d'un point au début de la liste_div*** */
liste_div insere_liste_div(liste_div ld, point pt, float distance);

/* ***fonction qui génère une liste_div*** */
liste_div genere_liste_div(liste l, point pt);

/* ***Fonction d'affichage de la liste_div*** */
void affiche_liste_div(liste_div);

/* ***Fonction de tri de la liste_div*** */
liste_div tri_liste_div(liste_div ld);

/* ***Fonction de suppression du dernier élément de la liste_div *** */
liste_div supprime_dernier_liste_div(liste_div ld);	

#endif
