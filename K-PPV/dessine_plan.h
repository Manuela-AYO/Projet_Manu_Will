#ifndef _DESSINE_PLAN_H_
#define _DESSINE_PLAN_H_

/*dimensions de la fenêtre*/
#define WIDTH 1200
#define HEIGHT 700

/*Macro pour les tailles limites du plan et la graduation*/
/*à modifier si l'on veut changer l'échelle*/
#define PADDING 10 /* espace entre le plan et le cadre*/
#define LONGUEUR_AXE_Y HEIGHT - 2 * PADDING /* plan sur tout la hauteur*/
#define LONGUEUR_AXE_X LONGUEUR_AXE_Y /*pour avoir un plan normé*/
#define VALEUR_MIN_X "-1"
#define VALEUR_MAX_X "1"
#define VALEUR_MIN_Y "-1"
#define VALEUR_MAX_Y "1"
#define NB_GRADUATIONS 20
#define GAUCHE_PLAN PADDING /*le cadre sera coller au bord*/
#define HAUT_PLAN PADDING /* idem */

/*ne pas changer, macros utilisées pour placer les points*/
#define DROITE_PLAN GAUCHE_PLAN + LONGUEUR_AXE_X
#define BAS_PLAN HAUT_PLAN + LONGUEUR_AXE_Y
#define MILIEU_HORIZONTAL (DROITE_PLAN+GAUCHE_PLAN)/2
#define MILIEU_VERTICAL (BAS_PLAN+HAUT_PLAN)/2


/* fonction qui affiche le plan */
void dessiner_plan_2_dimensions();

#endif
