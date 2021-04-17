#ifndef _AFFICHAGE_DES_MENUS_H_
#define _AFFICHAGE_DES_MENUS_H_

#include"bouton.h"


/*--affiche et affecte les dimensions des boutons passés en paramètre, il doivent être initialisers--*/
void afficher_les_boutons_clickables(bouton b_creation, bouton b_KPPV, bouton b_reinitialisation, bouton quitter, bouton b_effacer, bouton b_voisinage, bouton b_decision, bouton b_sauvegarde, bouton b_valeur_k, bouton b_classe, bouton b_chargement);


/*--Permet de passer du mode 'current_mode' au mode 'new_mode'--*/
void change_mode(bouton new_mode, bouton current_mode, bouton b_classe, bouton b_chargement);
  


/*  affiche une input box sur le bouton en paramètre
  et renvoie le text rentré par l'utilisateur
*/
char *demande_valeur(bouton b);

#endif
