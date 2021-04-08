#include<stdio.h>
#include<stdlib.h>
#include<MLV/MLV_all.h>
#include"dessine_plan.h"
#include"affichage_des_menus.h"/* qui inclus "bouton.h" */

typedef enum{CREATION, KPPV} mode;

int main(){
    /*--variables pour les options proposés à l'utilisateur--*/
    bouton  b_creation, b_KPPV, b_reinitialisation, b_effacer, b_voisinage, b_decision, b_sauvegarde;
    MLV_Input_box *ib_valeur_de_k=NULL, *ib_classe_du_point=NULL, *ib_chargement_fichier_donnees=NULL;
    
    /*--variables pour les évènements--*/
    MLV_Event event;
    char *input_texte=NULL;/* pour les boites de saisie, allocation fait par MLV,
                          mais on doit libérer la mémoire */
    MLV_Input_box *ib_event=NULL;
    int x, y;
    MLV_Button_state state;
    
    /*--autres--*/
    bouton b_plan=NULL;
    mode mode_actif;
    int continuer=1;

    
    MLV_create_window("K-PPV", "K-PPV",WIDTH,HEIGHT);

    
    printf("/* ***** ON CREE LE PLAN ***** */\n");
    dessiner_plan_2_dimensions();
    
    /*on fait un bouton "spécial" pour le plan afin d' utiliser la fonction 
      "est_clique(x,y,bouton)" pour savoir si on a cliqué dans le plan */
    b_plan= creer_bouton("plan");
    /* la graduation est decale de 10 par rapport au début/fin axe pour un aspect estétique*/
    b_plan->x= GAUCHE_PLAN + 10;
    b_plan->y= HAUT_PLAN + 10;
    b_plan->width= LONGUEUR_AXE_X -20;
    b_plan->height= LONGUEUR_AXE_Y -20;
    
    
    printf("/* ****** CREATION DES BOUTONS ***** */\n");
    
    /*--initialisation--*/
    b_creation= creer_bouton("mode création");
    b_KPPV= creer_bouton("mode K-PPV");
    b_reinitialisation= creer_bouton("reinitialisation de\nla fenêtre");
    b_effacer= creer_bouton("effacer le dernier point");
    b_voisinage= creer_bouton("voisinage");
    b_decision= creer_bouton("avec prise de décision");
    b_sauvegarde= creer_bouton("Sauvegarde des données\nentrées");
    
    /*--affichage et affectation des dimensions--*/
    afficher_les_boutons_clickables(b_creation, b_KPPV, b_reinitialisation, b_effacer, b_voisinage, b_decision, b_sauvegarde);
    if(b_creation == NULL){
      printf("ERREUR DE DEBUTANT\n");
    }
    
    printf("/* ***** CREATION DES BOITES DE SAISIE ***** */\n");
    creer_les_boites_de_saisies(&ib_valeur_de_k, &ib_classe_du_point, &ib_chargement_fichier_donnees,  b_KPPV, b_sauvegarde, b_sauvegarde);

    
    printf("/* ***** MODE CREATION PAR DEFAUT ***** */\n");
    afficher_mode_creation(b_creation, b_KPPV, ib_classe_du_point, ib_chargement_fichier_donnees);
    mode_actif= CREATION;


    printf("/* ***** ON TRAITE LES EVENEMENTS ***** */\n");
    while(continuer == 1){

        event= MLV_get_event(NULL,
                             NULL,
                             NULL,
                             &input_texte,
                             &ib_event,
                             &x,
                             &y,
                             NULL,
                             &state);

        switch(event){
        case MLV_INPUT_BOX:
            break;
        case MLV_MOUSE_BUTTON:
            if(mode_actif == CREATION  &&  est_clique(x, y, b_plan)){
                /*lancer la fonction ajouter point*/
            }
            else if(mode_actif == CREATION  && est_clique(x, y, b_effacer)){
            }
            else if(est_clique(x, y, b_reinitialisation)){
            }

            else if(mode_actif == CREATION  && est_clique(x, y, b_KPPV)){
	      afficher_mode_KPPV(b_KPPV, b_creation, ib_classe_du_point, ib_chargement_fichier_donnees);
                mode_actif= KPPV;
            }
            else if(mode_actif == KPPV  &&  est_clique(x, y, b_creation)){
	      afficher_mode_creation(b_creation, b_KPPV, ib_classe_du_point, ib_chargement_fichier_donnees);
                mode_actif= CREATION;
            }
            else if(est_clique(x, y, b_voisinage)){
            }
            else if(est_clique(x, y, b_decision)){
            }
            else if(est_clique(x, y, b_sauvegarde)){
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
