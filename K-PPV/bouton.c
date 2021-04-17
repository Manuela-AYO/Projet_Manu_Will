/*****************************************************
 * Fichier qui contient les fonctions permettant de  *
 * -creer un bouton                                  *
 * -afficher un bouton avec MLV                      *
 * -dire si un bouton est cliqué                     *
 * -supprimer un bouton                              *
 *****************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<MLV/MLV_all.h>
#include"bouton.h"
#include"allocation.h"


/******
 * Fonction qui créer un bouton "name", sans initialiser ces dimensions
 ******/
bouton creer_bouton(char *name){
    bouton b;
  
    /* ***** Reservation memoire ***** */
    /*--d'une strcut bouton--*/
    b= (bouton) allocation_mem(1, sizeof(struct struct_bouton));
    /*--du nom--*/
    b->name= (char *) allocation_mem(strlen(name)+1, sizeof(char));
    strcpy(b->name, name);
    /*--inactif--*/
    b->active= 0;
    
    return b;
}



/******
 * Fonction qui affiche un bouton dont les champs ont tous étés initialisés
 * couleur permet de changer la couleur du cadre et du texte
 * si couleur=NULL alors la couleur sera MLV_COLOR_WHITE
 ******/
void afficher_bouton(bouton b, char *couleur){
  MLV_Color c;

  if(couleur != NULL){
    c= MLV_convert_string_to_color(couleur);
  }
  else{
    c= MLV_COLOR_WHITE;
  }
  MLV_draw_adapted_text_box(b->x,
			    b->y,
			    b->name,
			    4,
			    c,
			    c,
			    MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER);

  MLV_actualise_window();
}


/******
 * Fonction qui renvoie 1 si les coordonnées (x,y) sont situe dans le bouton,
 * 0 sinon
 ******/
int est_clique(int x, int y, bouton b){
    int xmax= b->x + b->width;
    int ymax= b->y + b->height;
    
    if( (x > b->x  &&  x < xmax) && (y > b->y  &&  y < ymax) ){
        return 1;
    }
    return 0;
}


/*****
 * Fonction qui libère la mémoire occupé par un bouton
 *****/
void supprimer_bouton(bouton *b){
  free((*b)->name);
  free(*b);
  *b=NULL;
}
