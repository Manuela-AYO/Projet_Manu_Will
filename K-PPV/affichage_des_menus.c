#include<stdio.h>
#include<stdlib.h>
#include<MLV/MLV_all.h>
#include"dessine_plan.h"
#include"bouton.h"

/* affiche et affecte les dimensions des boutons passés en paramètre, il doivent être initialisers */
void afficher_les_boutons_clickables(bouton b_creation, bouton b_KPPV, bouton b_reinitialisation, bouton b_effacer, bouton b_voisinage, bouton b_decision, bouton b_sauvegarde) {
    
    int interligne=4; /* distance entre le texte et les bords */
    int xcadre, ycadre, widthcadre, heightcadre;


    /* *********** 
       -On affecte au bouton ses coordonnées (x,y) Nord-Ouest et 
       ses dimensions à ses champs respectifs,
       -On afficher le bouton.
       ********** */
  

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

  
    /* ***** BOUTON REINITIALISATION DE LA FENETRE ***** */
  
    MLV_get_size_of_adapted_text_box(b_reinitialisation->name,
                                     interligne,
                                     &(b_reinitialisation->width),
                                     &(b_reinitialisation->height));
  
    /*--coller au bord en haut à droite--*/
    b_reinitialisation->x= WIDTH - b_reinitialisation->width;
    b_reinitialisation->y= 0;
  
    afficher_bouton(b_reinitialisation, NULL);

  
    /* ***** BOUTON EFFACER ***** */

    MLV_get_size_of_adapted_text_box(b_effacer->name,
                                     interligne,
                                     &(b_effacer->width),
                                     &( b_effacer->height));
  
    /*--en dessous du bouton creation--*/
    b_effacer->x= DROITE_PLAN + PADDING + 2;
    b_effacer->y= b_creation->y + 20; 
  
    afficher_bouton(b_creation, NULL);
  
  
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
    b_voisinage->x= WIDTH - 50 - b_decision->width;
    b_voisinage->y= HEIGHT/2;
    b_decision->x= b_voisinage->x;
    b_decision->y= b_voisinage->y + b_voisinage->height + 2 ;

    afficher_bouton(b_voisinage, NULL);
    afficher_bouton(b_decision, NULL);
   
    /* ** CADRE OPTIONS D'AFFICHAGE ** */
    xcadre= b_voisinage->x - 10;
    ycadre= b_voisinage->y - 30;
    widthcadre= b_decision->width + 50;
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

    
    /* ***** SAUVEGARDE DES DONNEES ENTREES ***** */
    
    MLV_get_size_of_adapted_text_box(b_sauvegarde->name,
                                     interligne,
                                     &(b_sauvegarde->width),
                                     &(b_sauvegarde->height));

    b_sauvegarde->x= WIDTH - b_sauvegarde->width;
    b_sauvegarde->y= HEIGHT - b_sauvegarde->height;

    afficher_bouton(b_sauvegarde, NULL);
}


/* Crée les boites de saisies 
   Les boutons en paramètres servent a positionner ces boites */
void creer_les_boites_de_saisies(MLV_Input_box **ib_valeur_de_k, MLV_Input_box **ib_classe_du_point, MLV_Input_box **ib_chargement_fichier_donnees, bouton b_KPPV, bouton b_sauvegarde, bouton b_effacer){
  
  fprintf(stderr,"/* ***** VALEUR DE K ***** */\n");
    /*-- a cote du bouton mode KPPV (en haut a droite du plan)--*/
  *(ib_valeur_de_k)= MLV_create_input_box(b_KPPV->x + b_KPPV->width + 5,
                                         b_KPPV->y,
                                         b_KPPV->width,
                                         b_KPPV->height,
                                         MLV_COLOR_WHITE,
                                         MLV_COLOR_WHITE,
                                         MLV_COLOR_BLACK,
                                         "Valeur de k\n");

  fprintf(stderr,"/* ***** CLASSE DU POINT ***** */\n");
  /*--en dessous du bouton effacer point--*/
  *(ib_classe_du_point)= MLV_create_input_box(b_effacer->x,
					   b_effacer->y + b_effacer->height + 10,
					   b_effacer->width,
					   b_effacer->height,
					   MLV_COLOR_WHITE,
					   MLV_COLOR_WHITE,
					   MLV_COLOR_BLACK,
					   "Classe du point\n");

  fprintf(stderr,"/* ***** CHARGEMENT FICHIER DONNEES ***** */\n");
  /*--au dessus du bouton sauvegarde--*/
  *(ib_chargement_fichier_donnees)= MLV_create_input_box(b_sauvegarde->x,
                                                        b_sauvegarde->y - b_sauvegarde->height - 10,
                                                        b_sauvegarde->width,
                                                        b_sauvegarde->height,
                                                        MLV_COLOR_WHITE,
                                                        MLV_COLOR_WHITE,
                                                        MLV_COLOR_BLACK,
                                                        "Chargement d'un fichier\nde données\n");


    /* ***** AFFICHAGE ***** */
    MLV_draw_all_input_boxes();
}






/* Affiche le bouton creation en vert 
   et réaffiche les boites de saisies desactivées en mode KPPV*/
void afficher_mode_creation(bouton b_creation, bouton b_KPPV, MLV_Input_box *ib_classe_du_point, MLV_Input_box *ib_chargement_fichier_donnees){

    /*--on passse le bouton en vert--*/
    afficher_bouton(b_creation, "MLV_COLOR_GREEN");
    /*--on passe le bouton KPPV en mode normal--*/
    afficher_bouton(b_KPPV, NULL);
    /*--on réafiche les boites de saisies--*/
    MLV_change_input_box_colors(ib_classe_du_point,
                                MLV_COLOR_WHITE,
                                MLV_COLOR_WHITE,
                                MLV_COLOR_BLACK);
    MLV_draw_input_box(ib_classe_du_point);
    
    MLV_change_input_box_colors(ib_chargement_fichier_donnees,
                                MLV_COLOR_WHITE,
                                MLV_COLOR_WHITE,
                                MLV_COLOR_BLACK);
    MLV_draw_input_box(ib_chargement_fichier_donnees); 
}

/* Affiche le bouton KPPV en vert 
   et efface les boites de saisies du  mode création*/
void afficher_mode_KPPV(bouton b_KPPV, bouton b_creation, MLV_Input_box *ib_classe_du_point, MLV_Input_box *ib_chargement_fichier_donnees){

    /*--on passse le bouton KPPV en vert--*/
    afficher_bouton(b_KPPV, "MLV_COLOR_GREEN");
    /*--on passe le bouton creation en mode normal--*/
    afficher_bouton(b_creation, NULL);
    /*--on rend invisibles les boites de saisies--*/
    MLV_change_input_box_colors(ib_classe_du_point,
                                MLV_COLOR_BLACK,
                                MLV_COLOR_BLACK,
                                MLV_COLOR_BLACK);
    MLV_draw_input_box(ib_classe_du_point);
    
    MLV_change_input_box_colors(ib_chargement_fichier_donnees,
                                MLV_COLOR_BLACK,
                                MLV_COLOR_BLACK,
                                MLV_COLOR_BLACK);
    MLV_draw_input_box(ib_chargement_fichier_donnees);
}
