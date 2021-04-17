#include<stdio.h>
#include<stdlib.h>
#include<MLV/MLV_all.h>
#include"dessiner_plan.h"
#include"affichage_des_menus.h"/* qui inclus "bouton.h" */

typedef enum{CREATION, KPPV} mode;

int main(){
    /*--variables pour les options proposés à l'utilisateur--*/
    bouton  b_creation, b_KPPV, b_reinitialisation, b_quitter, b_effacer, b_voisinage, b_decision, b_sauvegarde, b_valeur_k, b_classe, b_chargement ;
    
    /*--variables pour les évènements--*/
    MLV_Event event;
    char *input_text=NULL;/* pour les boites de saisie, allocation fait par MLV,
                          mais on doit libérer la mémoire */
    int x, y;
    double x2, y2;
    MLV_Button_state state;
    
    /*--autres--*/
    bouton b_plan=NULL;
    int continuer=1;

    MLV_create_window("K-PPV", "K-PPV",WIDTH,HEIGHT);

    
    /* ********** ON CREE LE PLAN ********** */
    dessiner_plan_2_dimensions();
    
    /*on fait un bouton "spécial" pour le plan afin d' utiliser la fonction 
      "est_clique(x,y,bouton)" pour savoir si la souris est dans le plan */
    b_plan= creer_bouton("plan");
    /* la graduation est decale de 10 par rapport au début/fin axe pour un aspect estétique.
       ensuite on ajoute un -1 car la fct est_clique utilise des inégalités strictes, et nous on veut 
       inclure les points de coord x=1, x=-1 y=1, y=-1*/
    b_plan->x= GAUCHE_PLAN + 9;
    b_plan->y= HAUT_PLAN + 9;
    b_plan->width= LONGUEUR_AXE_X -18;
    b_plan->height= LONGUEUR_AXE_Y -18;
    
    
    /* *********** CREATION DES BOUTONS ********** */
    
    /*--initialisation--*/
    b_creation= creer_bouton("mode création");
    b_KPPV= creer_bouton("mode K-PPV");
    b_reinitialisation= creer_bouton("reinitialisation de\nla fenêtre");
    b_quitter= creer_bouton("Quitter");
    b_effacer= creer_bouton("effacer le\ndernier point");
    b_voisinage= creer_bouton("voisinage");
    b_decision= creer_bouton("avec prise de décision");
    b_sauvegarde= creer_bouton("Sauvegarde des données\nentrées");
    b_valeur_k= creer_bouton("k= ");
    b_classe= creer_bouton("classe : ");
    b_chargement= creer_bouton("chemin fihier : ");
    
    /*--affichage et affectation des dimensions des boutons--*/
    afficher_les_boutons_clickables(b_creation, b_KPPV, b_reinitialisation, b_quitter, b_effacer, b_voisinage, b_decision, b_sauvegarde, b_valeur_k, b_classe, b_chargement);
    

    
    /* ********** MODE CREATION PAR DEFAUT ********** */
    change_mode(b_creation, b_KPPV, b_classe, b_chargement);


    /* ********** ON TRAITE LES EVENEMENTS ********** */
    while(continuer == 1){
      
        event= MLV_get_event(NULL, NULL, NULL, NULL,
                             NULL, &x, &y, NULL,  &state);

        switch(event){

	case MLV_MOUSE_BUTTON:
	  if(est_clique(x, y, b_valeur_k)){
	    input_text= demande_valeur(b_valeur_k);
	    MLV_draw_text(b_valeur_k->x + b_valeur_k->width +2, b_valeur_k->y+2, "%s", MLV_COLOR_GREEN, input_text);
	  }
	  
            /*--On test si l'utilisateur à cliqué sur un bouton--*/
	  if(b_creation->active == 1){
            if( est_clique(x, y, b_plan)){
              /*lancer la fonction ajouter point*/
	      printf("clique plan\n");
            }
            else if(est_clique(x, y, b_effacer)){
	      /*fonction pour effacer le dernier point ajouté*/
	      printf("effacer\n");
            }
	    else if(est_clique(x, y, b_classe)){
	      printf("Classe\n");
	      input_text= demande_valeur(b_classe);
	      MLV_draw_text(b_classe->x + b_classe->width,
			    b_classe->y + b_classe->height,
			    input_text,
			    MLV_COLOR_WHITE);
	      /*rajouté la classe au point*/
	      free(input_text);
	      input_text= NULL;
	    }
	    else if(est_clique(x, y, b_chargement)){
	      printf("sauvegarde");
	      input_text= demande_valeur(b_chargement);
	      /*fct de sauvegarde des données entrées*/
	      free(input_text);
	      input_text= NULL;
	    }
	    else if(est_clique(x, y, b_KPPV)){
	      change_mode(b_KPPV, b_creation, b_classe, b_chargement);
	    }
	  }
	  else{
	    if(est_clique(x, y, b_creation)){
	      printf("change mode\n");
	      change_mode(b_creation, b_KPPV, b_classe, b_chargement);
            }
	  }
          if(est_clique(x, y, b_voisinage)){
	    printf("clique voisinage\n");
	    /*fct pour tracer le cercle de voisinage*/
	  }
	  else if(est_clique(x, y, b_valeur_k)){
	    printf("valeur_k\n");
	    input_text= demande_valeur(b_valeur_k);
	    /*traitement de l'input*/
	    free(input_text);
	    input_text= NULL;
	  }
	  else if(est_clique(x, y, b_decision)){
	    printf("clique decision\n");
	  }
	  else if(est_clique(x, y, b_sauvegarde)){
	    printf("clique sauvegarde\n");

	  }
	  else if(est_clique(x, y, b_reinitialisation)){
	    printf("clique reinitialisation\n");
	  }
	  else if(est_clique(x, y, b_quitter)){
	    continuer= 0;
	  }
	  break;
	
	case MLV_MOUSE_MOTION:
	  /*--on regarde si la souris survole le plan--*/
	  if(est_clique(x, y, b_plan)){
	    x2=(x-MILIEU_HORIZONTAL)/UNITE_X;
	    y2=(MILIEU_VERTICAL-y)/UNITE_Y;
	    /*fonction pour afficher les coord en bas à droite du plan
	      à faire*/
	    printf("x-MILIEU_HORIZONTAL+10 : %d\n", x-MILIEU_HORIZONTAL);
	    printf("cordonées du clique (%f, %f)\n",x2,y2);
	  }
	  break;

	default:
	  break;
	}
    }
    
    MLV_actualise_window();
    MLV_wait_seconds(5);
    MLV_free_window();

  exit(0);

}
