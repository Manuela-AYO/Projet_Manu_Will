#ifndef TYPE_H
#define TYPE_H

/*Structure de point*/
typedef struct{
	float x;
	float y;
	int classe;
}point;

/*Un point dans la liste sera un élément constitué de sa valeur et d'un pointeur
vers le prochain point*/
typedef struct
{
	point courant;
	point *suivant;	
}element;

/*Structure de liste de points constituée du nombre de points et 
du 1er point sauvegardé dans la liste*/
struct liste_point{
	int nb_element;
	element *premier;
};

typedef struct liste_point liste;

#endif