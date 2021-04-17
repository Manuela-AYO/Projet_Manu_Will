/********************************************************
 * Déclartion des fonctions permettant de convertir les *
 * coordonnées double du point en coordonnées entières  *
 * de MLV et inversement.                               *
 ********************************************************/

#ifndef _COORDONNEES_H_
#define _COORDONNEES_H_

/*--Convertie la coordonnée x ou y et la renvoie--*/
int coordx_to_MLV(point p);
int coordy_to_MLV(point p);


/*--Converti la coordonnée x ou y en double--*/
double coordx_to_point(int x);
double coordy_to_point(int y);

#endif
