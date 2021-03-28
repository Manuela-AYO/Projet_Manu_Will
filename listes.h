#ifndef _LISTES_H
#define _LISTES_H

/*Génération d'une liste vide*/
liste creer_liste_vide();

/*Cette fonction renvoie 1 si la liste est vide et 0 sinon*/
int est_liste_vide(liste L);

/*Insertion d'un point dans la liste*/
liste inserer_point(liste l, point pt);

/*Affichage des éléments de la liste*/
void afficher(liste);
#endif