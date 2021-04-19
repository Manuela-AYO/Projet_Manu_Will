#ifndef _TYPE_H
#define _TYPE_H

/*Structure de point*/
typedef struct{
	float x;
	float y;
	unsigned int classe;
}point;

/*Un point dans la liste sera un élément constitué de sa valeur et d'un pointeur
vers le prochain point*/
typedef struct element{
	point courant;
	struct element *suivant;	
}element;

typedef element *liste;

typedef struct elem{
  point pt;
  float distance;
  struct elem *suivant;
}struct_element;

typedef struct_element *liste_div;

#endif
