#ifndef _KPPV_H
#define _KPPV_H

#include <MLV/MLV_all.h>

#define RADIUS 3
#define NB_COULEURS 3

/*const char *tab_couleur[NB_COULEURS] = {"MLV_COLOR_WHITE", "MLV_COLOR_BLUE", "MLV_COLOR_RED"};

MLV_Color couleur[NB_COULEURS] = {MLV_COLOR_WHITE,
				  MLV_COLOR_BLUE,
				  MLV_COLOR_RED};*/

/*Fonction qui affiche le symbole d'un point suivant sa classe*/
void affiche_point_classe(int , int , unsigned int);

/*Fonction d'affichage du point sélectionné par l'utilisateur*/
/*Cette fonction retourne aussi les coordonnées du point cliqué par l'utilisateur pour l'utiliser plus tard dans les modes K-PPV*/
point affiche_point(int x, int y);

/*Fonction d'implémentation du k_ppv sans décision*/
liste_div kppv_sans_decision(liste l, point pt, int k); 

/* /\*Fonction de mise en avant des k_ppv*\/ */
/* void mise_en_avant_k_ppv(liste l, point pt, int k); */

/* /\*Fonction d'implémentation du k_ppv avec prise de décision*\/ */
/* void kppv_decision(liste l, point pt, int k); */
#endif
