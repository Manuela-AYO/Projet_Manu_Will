/********************************************************
 * Contient les fonctions permettant de traiter les     *
 * évènements du programme = clique sur les boutons.    *
 * Ce module a pour but d'aléger la fonction main, et   *
 * de rendre le traitement des évènements plus lissible * 
 ********************************************************/
#include <MLV/MLV_all.h>
#include "../inc/affichage_des_menus.h" /* inclus bouton.h et type.h */
#include "../inc/afficher_resultat_input.h"
#include "../inc/allocation.h"
#include "../inc/fichier.h"
#include "../inc/coordonnees.h"
#include "../inc/dessiner_plan.h"
#include "../inc/dessiner_point.h"
#include "../inc/k_ppv.h" /* inclus liste.h */



#define NB_POINTS 50 /* pour définir le nbr de case allouées au tableau pour le mode création */
#define NB_POINTS_REALLOUER 25 /* défini le nbr de points réallouer si le tableau est plein */

/****
 * Traite les évènements spécifiques du mode création.
 ****/
void event_mode_creation(int x, int y, tableau_de_points *t, int *compteur)
{
    char *input_text=NULL; /* pour les boites de saisie */
    char *chemin, *nom;
    int classe, n=t->nb_points-1;

    /* ***** ON AJOUTE UN POINT ***** */
    if( est_clique(x, y, b_plan) )
    {
      if(t->tab == NULL)
	{
	  /*--il faut allouer le tableau--*/
	  t->tab= (point *) allocation_mem(NB_POINTS, sizeof(point));
	  t->taille= NB_POINTS;
	  t->nb_points= 0;
	}
      else if(t->nb_points == t->taille)
	{
	  /*--tab plein, il faut l'agrandir--*/
	  reallocation_mem( (void **) &(t->tab), t->taille + NB_POINTS_REALLOUER, sizeof(point) );
	  t->taille+= NB_POINTS_REALLOUER;
	}
      /*--ajout du point au tableau, et mise à jour des compteurs--*/
      n++;
      t->tab[n]= affiche_point_clique(x, y);
      (t->nb_points)++;
      (*compteur)++;
        
      /*--on affiche les coordonnées du point cliqué à coté du bouton effacer--*/
      afficher_coord_point_effacer(t->tab[n]);
        
      /*--on oblige l'utilisateur à rentrer une classe--*/
      x= b_classe->x +1;
      y= b_classe->y +1;
    }


    /* ***** ON DEMANDE LA CLASSE DU DERNIER POINT AJOUTE ***** */
    if(est_clique(x, y, b_classe))
      {
	/*--on vérifie d'abord que le tableau ne soit pas vide--*/
	if(t->nb_points != 0)
	  {
	    do{
	      input_text= demande_valeur(b_classe);
	      classe= atoi(input_text);
	      /*--test si la valeur est correcte--*/
	      if(classe <= 0  ||  classe > NB_CLASSES)
              {
                  fprintf(stderr, "Erreur de saisie pour la classe.\n");
              }
	      /*--si oui, alors on l'affiche et change la classe du point--*/
	      else{
                  afficher_classe_saisie(classe);
                  affiche_point_classe(t->tab[n], EFFACE);
                  t->tab[n].classe= classe;
                  affiche_point_classe(t->tab[n], AFFICHE);
              }
	      free(input_text);
	      /*si le point n'avais pas encore de classe (0) et la classe entrée est
		incorrecte, alors il faut redemander une classe */
	    }while(t->tab[n].classe == 0);
	  }
      }

    
    /* ***** ON EFFACE LE DERNIER POINT CLIQUE ***** */
    else if(est_clique(x, y, b_effacer)  &&  *compteur > 0)
      {
	if(t->nb_points != 0)
	  {
	    (t->nb_points)--;
	    (*compteur)--;
	    affiche_point_classe(t->tab[n], EFFACE);
	    /*--on change l'affichage des coordonnées du point qui peut être effacé--*/
	    if(*compteur != 0)
	      {
		afficher_coord_point_effacer(t->tab[n-1]);
	      }
            else{
                effacer_coord_point_effacer();
            }
	  }
      }

    
    /* ***** ON CHARGE UN FICHIER DE DONNEES ***** */
    else if(est_clique(x, y, b_chargement))
    {
        chemin= demande_valeur(b_chargement);
        if( !MLV_path_exists(chemin)  ||  !MLV_path_is_a_file(chemin) )
        {
            fprintf(stderr,"Erreur le chemin '%s' est invalide.\n", chemin);
             afficher_nom_fichier_saisie("fichier inexistant");
        }
        else{
            /*--sinon on affiche le nom du fichier--*/
            nom= MLV_get_base_name(chemin);
            afficher_nom_fichier_saisie(nom);
            free(nom);
            
            if(t->nb_points != 0)
            {
                /*on libère l'espace mémoire tu tableau de point */
                free(t->tab);
		t->taille= 0;
                /*on efface tout le plan*/
                afficher_plan_vide();
            }
            /*--on charge et affiche les points--*/
            chargement_fichier(chemin, t);
            afficher_tableau_de_points(*t);
        }
        free(chemin);
    }


    /* ***** ON SAUVEGARDE LE JEU DE DONNEES CREE ***** */
    else if(est_clique(x, y, b_sauvegarde))
    {
        /*on vérifie que l'on a ajouté des points manuellement*/
        if( (*compteur) > 0)
        {
        /*lancement de la fct sauvegarde dans un fichier*/
        }
    }

    /* ***** ON PASSE EN MODE KPPV ***** */
    else if(est_clique(x, y, b_KPPV)  &&  t->nb_points != 0)
    {
        change_mode(b_KPPV, b_creation);
    }
    
}


/****
 * Actualise l'affichage, après que des modifications d'options on été faites.
 ****/

static void actualiser_affichage_kppv(int old_k, int k, point *p_clique, liste_KPPV l, tableau_de_points t)
{
    static liste_KPPV l2; /* conserve le pointeur sur le k voisin comme ça si on rappelle
la fonction avec un k>old_k on na reparcours pas les old_k premiers de la liste */ 
    
    /*--mise à jour de l'affichage, si on a une liste de KPPV--*/
    if( !est_liste_vide(l) )
    {
        if(old_k == 0)
        {
            /*--on met en valeur les k-ppv sans rafraichir le plan--*/
            l2= mise_en_avant_k_ppv(k, l);
        }
        else if(k > old_k)
        {
            /*--on met en valeur les voisins qui ne l'étaient pas--*/
            l2= mise_en_avant_k_ppv(k - old_k, l2);
        }
        else{
            /*--k < old_k ou old_k == k (desactivé le cercle de voisinage)
              il faut donc rafraichir le plan--*/
            afficher_plan_vide();
            afficher_tableau_de_points(t);
            
            /*--on met en valeur les KPPV--*/
            l2= mise_en_avant_k_ppv(k, l);
            /*--on affiche les éventuelles options d'affichages sélectionnées--*/
            if(b_voisinage->etat == ACTIF)
            {
                affiche_cercle_voisinage(k, *p_clique, l);
            }
            if(b_decision->etat == ACTIF)
            {
                /*--on attribut une classe au point clique--*/
                kppv_decision(l, p_clique, k);
            }
            affiche_point_classe(*p_clique, AFFICHE);
        }
    }
    else{
        /*--on efface les coord du point, k, le plan et réaffiche les points--*/
        effacer_valeur_k_saisie();
        effacer_coord_point_effacer();
        afficher_plan_vide();
        afficher_tableau_de_points(t);
    }
}

/****
 * Taite les évènements en mode KPPV
 ****/
void event_mode_KPPV(int x, int y, int *k, point *p_clique, tableau_de_points t, liste_KPPV *l)
{
    int old_k= (*k);
    char *input_text;

    /*printf("yes\n");*/

    /* si la liste des KPPV a été créée (=un point à été cliqué)*/
    if( !est_liste_vide(*l) )
    {
        /* ***** ON CHANGE LA VALEUR DE K ***** */ 
        if(est_clique(x, y, b_valeur_k))
        {
            input_text= demande_valeur(b_valeur_k);
            (*k)= atoi(input_text);
            
            if(*k <= 0  ||  *k > t.nb_points)
            {
                fprintf(stderr, "Erreur de saisie pour k.\n");
                (*k)= old_k;
            }
            else{
                /*--on met à jour l'affichage--*/
	      afficher_valeur_k_saisie(*k);
	      actualiser_affichage_kppv(old_k, *k, p_clique, *l,  t);
            }
            free(input_text);
        }


        /* ***** ON AFFICHE/EFFACE LE CERCLE DE VOISINAGE ***** */
        else if(est_clique(x, y, b_voisinage))
	  {
            if(b_voisinage->etat == ACTIF)
	      {
                /*--on désactive le bouton et efface le cercle--*/
                b_voisinage->etat= VISIBLE;
                actualiser_affichage_kppv(old_k, *k, p_clique, *l, t);
	      }
            else{
	      /*--on l'active et affiche le cercle--*/
	      b_voisinage->etat= ACTIF;
	      affiche_cercle_voisinage(*k, *p_clique, *l);
            }
            afficher_bouton(b_voisinage);
	  }
   

        /* ***** ON CHANGE L'AFFICHAGE DU POINT CLIQUE ***** */
        else if(est_clique(x, y, b_decision))
        {
            /*--on efface le point cliqué--*/
            affiche_point_classe(*p_clique, EFFACE);
            
            if(b_decision->etat == ACTIF)
            {
                /*--on le désactive et supprime la classe du point donnée--*/
                b_decision->etat= VISIBLE;
                p_clique->classe= 0;
            }
            else{
                /*--on l'active et donne une classe au point--*/
                b_decision->etat= ACTIF;
                kppv_decision(*l, p_clique, *k);
            }

            /*--on affiche les changements effectués--*/
            affiche_point_classe(*p_clique, AFFICHE);
            afficher_bouton(b_decision);
        }
        
        /* ***** ON EFFACE LE POINT ET LA LISTE DES KPPV ***** */
        else if(est_clique(x, y, b_effacer))
        {
            /*--on supprime la liste des KPPV, et  la valeur de k puis,
              on met à jour l'affichage--*/
            detruire_liste(*l);
            (*l)= liste_vide();
            (*k)= 0;
	    effacer_valeur_k_saisie();
            actualiser_affichage_kppv(old_k, *k, p_clique, *l, t);

        }
    }

    /* ***** SINON AUCUN POINT CLIQUE ***** */
    
    /* ***** ON A CLIQUE SUR LE PLAN ***** */
    else if(est_clique(x, y, b_plan))
    {
        /*--on affiche le point clique et ces coordonnées--*/
        (*p_clique)= affiche_point_clique(x, y);
        afficher_coord_point_effacer(*p_clique);
        
        /*--on crée la liste des voisins--*/
        (*l)= creer_liste_voisins(t, *p_clique);
        
        /*--on met à jour l'affichage--*/
        if(*k == 0)
        {
            /*--on demande à l'utilisateur une valeur--*/
            event_mode_KPPV(b_valeur_k->x + 1, b_valeur_k->y + 1, k, p_clique, t, l);
            
        }
        else{
            actualiser_affichage_kppv(old_k, *k, p_clique, *l, t);
        }
    }

    /* ***** ON PASSE EN MODE CREATION ***** */
    else if(est_clique(x, y, b_creation))
    {
        change_mode(b_creation, b_KPPV);
    }
}
