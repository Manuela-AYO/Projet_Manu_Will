/********************************************************
 * Déclartion des fonctions permettant de convertir les *
 * coordonnées double du point en coordonnées entières  *
 * de MLV et inversement.                               *
 ********************************************************/
#include"dessine_plan.h"
#include"type.h"

/* *****
 * Convertie la coordonnée x ou y et la renvoie
 ***** */
int coordx_to_MLV(double x){
  return (int) p.x * UNITE_X;
}
int coordy_to_MLV(double y){
  return (int) p.x * UNITE_Y;
}
/* *****
 * Converti la coordonnée x ou y en double
 ***** */
double coordx_to_point(int x){
  return (x-MILIEU_HORIZONTAL)/UNITE_X;
}
double coordy_to_point(int y){
  return (MILIEU_VERTICAL-y)/ UNITE_Y;
}
