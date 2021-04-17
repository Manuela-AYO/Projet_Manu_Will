#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<MLV/MLV_all.h>
#include"dessiner_plan.h"
#include"bouton.h"

/*--affiche et affecte les dimensions des boutons passés en paramètre, il doivent être initialisers--*/
void afficher_les_boutons_clickables(bouton b_creation, bouton b_KPPV, bouton b_reinitialisation, bouton b_quitter, bouton b_effacer, bouton b_voisinage, bouton b_decision, bouton b_sauvegarde, bouton b_valeur_k, bouton b_classe, bouton b_chargement) {
    
    int interligne=4; /* distance entre le texte et les bords */
    int xcadre, ycadre, widthcadre, heightcadre;


    /* *********** 
     *  -On affecte au bouton ses coordonnées (x,y) Nord-Ouest et 
     *  ses dimensions à ses champs respectifs,
     *  -On afficher le bouton.
     * ********** */
  

    /* ***** BOUTON CREATION ***** */
    
    MLV_get_size_of_adapted_text_box(b_creation->name,
                                     interligne,
                                     &(b_creation->width),
                                     &(b_creation->height));

    b_creation->x= DROITE_PLAN + PADDING + 2; /* sur le cote droit du plan */
    b_creation->y= HAUT_PLAN - PADDING; /* aligne avec le haut du cadre */
  
    afficher_bouton(b_creation, NULL);


    /* ***** BOUTON K-PPV ***** */
      
    b_KPPV->x= b_creation->x + b_creation->width + 5;/*a cote du bouton creation */
    b_KPPV->y= b_creation->y; 

    MLV_get_size_of_adapted_text_box(b_KPPV->name,
                                     interligne,
                                     &(b_KPPV->width),
                                     &(b_KPPV->height));
  
    afficher_bouton(b_KPPV, NULL);


    /* ***** BOUTON VALEUR DE K ***** */
    
    b_valeur_k->x= b_KPPV->x + b_KPPV->width + 5;/*a cote du bouton KPPV */
    b_valeur_k->y= b_KPPV->y; 

    MLV_get_size_of_adapted_text_box(b_valeur_k->name,
                                     interligne,
                                     &(b_valeur_k->width),
                                     &(b_valeur_k->height));
    b_valeur_k->width+= 10;
    
    afficher_bouton(b_valeur_k, NULL);
    

    /* ***** BOUTON QUITTER ***** */
    
     MLV_get_size_of_adapted_text_box(b_quitter->name,
                                     interligne,
                                     &(b_quitter->width),
                                     &(b_quitter->height));
  
    /*--coller au bord en haut à droite--*/
    b_quitter->x= WIDTH - b_quitter->width;
    b_quitter->y= 0;
  
    afficher_bouton(b_quitter, "MLV_COLOR_RED");

    /* ***** BOUTON REINITIALISATION DE LA FENETRE ***** */
  
    MLV_get_size_of_adapted_text_box(b_reinitialisation->name,
                                     interligne,
                                     &(b_reinitialisation->width),
                                     &(b_reinitialisation->height));
  
    /*--coller au bord en haut à droite en dessous de quitter--*/
    b_reinitialisation->x= WIDTH - b_reinitialisation->width;
    b_reinitialisation->y= b_quitter->height + 2;
  
    afficher_bouton(b_reinitialisation, NULL);
    
    
    /* ***** BOUTON EFFACER ***** */

    MLV_get_size_of_adapted_text_box(b_effacer->name,
                                     interligne,
                                     &(b_effacer->width),
                                     &( b_effacer->height));
  
    /*--en dessous du bouton creation--*/
    b_effacer->x= DROITE_PLAN + PADDING + 2;
    b_effacer->y= b_creation->y + b_creation->height + 20; 
  
    afficher_bouton(b_effacer, NULL);


    /* ***** BOUTON CLASSE ***** */

    MLV_get_size_of_adapted_text_box(b_classe->name,
                                     interligne,
                                     &(b_classe->width),
                                     &(b_classe->height));
    b_classe->width+= 15;
    
    /*--en dessous du bouton effacer--*/
    b_classe->x= DROITE_PLAN + PADDING + 2;
    b_classe->y= b_effacer->y + b_effacer->height + 5; 
  
    afficher_bouton(b_classe, NULL);
    
    /* ***** OPTIONS D'AFFICHAGE ***** */

    /* ** VOISINAGE / AVEC PRISE DE DECISION ** */
  
    MLV_get_size_of_adapted_text_box(b_voisinage->name,
                                     interligne,
                                     &(b_voisinage->width),
                                     &(b_voisinage->height));

    MLV_get_size_of_adapted_text_box(b_decision->name,
                                     interligne,
                                     &(b_decision->width),
                                     &(b_decision->height));

    /* coller au bord droit, environ milieu vertical */
    b_voisinage->x= WIDTH - 40 - b_decision->width;
    b_voisinage->y= HEIGHT/2;
    b_decision->x= b_voisinage->x;
    b_decision->y= b_voisinage->y + b_voisinage->height + 2 ;

    afficher_bouton(b_voisinage, NULL);
    afficher_bouton(b_decision, NULL);
   
    /* ** CADRE OPTIONS D'AFFICHAGE ** */
    xcadre= b_voisinage->x -20 ;
    ycadre= b_voisinage->y - 30;
    widthcadre= b_decision->width + 60;
    heightcadre= b_voisinage->height + b_decision->height + 50;
       
    MLV_draw_rectangle(xcadre,
                       ycadre,
                       widthcadre,
                       heightcadre,
                       MLV_COLOR_WHITE);

    MLV_draw_text(xcadre,
                  ycadre + 5,
                  "     OPTIONS D'AFFICHAGE",
                  MLV_COLOR_WHITE);
    MLV_actualise_window();
    
    
    /* ***** BOUTON SAUVEGARDE DES DONNEES ENTREES ***** */
    
    MLV_get_size_of_adapted_text_box(b_sauvegarde->name,
                                     interligne,
                                     &(b_sauvegarde->width),
                                     &(b_sauvegarde->height));

    /*--en bas à droite dans le coin--*/
    b_sauvegarde->x= WIDTH - b_sauvegarde->width;
    b_sauvegarde->y= HEIGHT - b_sauvegarde->height;

    afficher_bouton(b_sauvegarde, NULL);


    /* ***** BOUTON CHARGEMENT D'UN FICHIER ***** */
    
    MLV_get_size_of_adapted_text_box(b_chargement->name,
                                     interligne,
                                     &(b_chargement->width),
                                     &(b_chargement->height));
    b_chargement->width+= 50;
    
    /*--au dessus du bouton sauvegarde--*/
    b_chargement->x= b_sauvegarde->x;
    b_chargement->y= b_sauvegarde->y - 2 * b_chargement->height -5;
    afficher_bouton(b_chargement, NULL);
}



/*--Permet de passer du mode 'current_mode' au mode 'new_mode'--*/
void change_mode(bouton new_mode, bouton current_mode, bouton b_classe, bouton b_chargement){
  
  /* ***** activation/désactivation + changement d'affichage des modes ***** */
  current_mode->active= 0;
  afficher_bouton(current_mode, NULL);
  new_mode->active= 1;
  afficher_bouton(new_mode, "MLV_COLOR_GREEN");

  /* ***** Suivant le mode que l'on active, on affiche/efface les 2 boutons en paramètre ***** */
  if( strcmp(new_mode->name, "mode création") == 0 ){
    b_classe->active= 1;
    b_chargement->active= 1;
    afficher_bouton(b_classe, NULL);
    afficher_bouton(b_chargement, NULL);
  }
  else{
    b_classe->active= 0;
    b_chargement->active= 0;
    afficher_bouton(b_classe, "MLV_COLOR_BLACK");
    afficher_bouton(b_chargement, "MLV_COLOR_BLACK");
  }
}


/*
  Affiche une input box sur le bouton en paramètre
  et renvoie le text rentré par l'utilisateur.
*/
char *demande_valeur(bouton b){
  char *s;
  
  MLV_wait_input_box(b->x, b->y,
		     b->width, b->height,
		     MLV_COLOR_RED, MLV_COLOR_WHITE,
		     MLV_COLOR_BLACK, b->name,
		     &s);

  return s;
}
