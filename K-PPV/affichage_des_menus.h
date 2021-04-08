#ifndef _AFFICHAGE_DES_MENUS_H_
#define _AFFICHAGE_DES_MENUS_H_

#include"bouton.h"


/* affiche les boutons passés en paramètre, il doivent être initialisers */
void afficher_les_boutons_clickables(bouton b_creation, bouton b_KPPV, bouton b_reinitialisation, bouton b_effacer, bouton b_voisinage, bouton b_decision, bouton b_sauvegarde);

/* Crée les boites de saisies 
   Les boutons en paramètres servent a positionner ces boites */
void creer_les_boites_de_saisies(MLV_Input_box **valeur_de_k, MLV_Input_box **classe_du_point, MLV_Input_box **chargement_fichier_donnees, bouton b_KPPV, bouton b_sauvegarde, bouton b_effacer);


/* Affiche le bouton creation en vert 
   et réaffiche les boites de saisies desactivées en mode KPPV*/
void afficher_mode_creation(bouton b_creation, bouton b_KPPV, MLV_Input_box *ib_classe_du_point, MLV_Input_box *ib_chargement_fichier_donnees);


/* Affiche le bouton KPPV en vert 
   et efface les boites de saisies du  mode création*/
void afficher_mode_KPPV(bouton b_KPPV, bouton creation, MLV_Input_box *ib_classe_du_point, MLV_Input_box *ib_chargement_fichier_donnees);


#endif
