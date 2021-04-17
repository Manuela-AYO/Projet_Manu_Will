/*****************************************************
 * Fichier qui contient les déclarations suivantes   *
 * -type bouton                                      *
 * -fonctions de manipulation de ce type             *
 *****************************************************/
#ifndef _BOUTON_H_
#define _BOUTON_H_

/* ***** DEFINITION DU TYPE BOUTON ***** */
struct struct_bouton{
  int x, y, width, height;
  char *name;
  unsigned short int active;
};
typedef struct struct_bouton *bouton;

/*_______________________________________*/


/*--Fonction qui créer un bouton "name", sans initialiser ces dimensions--*/
bouton creer_bouton(char *name);


/*--Fonction qui affiche un bouton dont les champs ont tous étés initialisés
   couleur permet de changer la couleur du cadre et du texte
   si couleur=NULL alors la couleur sera MLV_COLOR_WHITE
--*/
void afficher_bouton(bouton b, char *couleur);


/*--Fonction qui renvoie 1 si les coordonnées (x,y) sont situe dans le bouton, 
0 sinon--*/
int est_clique(int x, int y, bouton b);

/*--Fonction qui libère la mémoire occupé par un bouton--*/
void supprimer_bouton(bouton *b);


#endif
