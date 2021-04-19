#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MLV/MLV_all.h>
#include "type.h"
#include "bouton.h"
#include "dessiner_plan.h"
#include "listes.h"
#include "allocation.h"
#include "k_ppv.h"
#include "coordonnees.h"

/*Fonction qui affiche le symbole d'un point suivant sa classe*/
void affiche_point_classe(int x, int y,unsigned int classe)
{
  if(classe == 1)
    {
      MLV_draw_line(x-2,
		    y,
		    x+2,
		    y,
		    MLV_COLOR_BLUE);
    }

  else if(classe == 2)
    {
      /* ***Ligne horizontale du '+'*** */
      MLV_draw_line(x-2,
		    y,
		    x+2,
		    y,
		    MLV_COLOR_RED);

      /* ***Ligne verticale du '+'*** */
      MLV_draw_line(x,
		    y-2,
		    x,
		    y+2,
		    MLV_COLOR_RED);
    }

  else
    MLV_draw_filled_circle(x,
		    y,
		    RADIUS,
		    MLV_COLOR_WHITE);
}

/* ***Fonction d'affichage du point sélectionné par l'utilisateur***
   ***Cette fonction retourne aussi les coordonnées du point cliqué par l'utilisateur pour les utiliser plus tard dans les modes K-PPV*** */
point affiche_point(int x, int y)
{
  point pt;
  pt.classe=0;

  affiche_point_classe(x,y, pt.classe);

  MLV_actualise_window();

  /* ***conversion des coordonnées entières du point en coordonnées réelles *** */
  pt.x = coordx_to_point(x);
  pt.y = coordy_to_point(y);

  return pt;
} 

/*Fonction d'implémentation du k_ppv sans décision*/
liste_div kppv_sans_decision(liste l, point pt, int k)
{
	liste_div ld=creer_liste_div_vide();
	int taille,i;
	
	/*Génération de la liste_div de points*/
	ld = genere_liste_div(l, pt);
	
	/*Tri de la liste_div*/
	ld = tri_liste_div(ld);
	
	/*A l'issue de cette étape, on a dans ld la liste triée des points suivant leur distance euclidienne*/
	
	/*Suppression des éléments de la fin jusqu'à k+1*/
	taille = taille_liste_div(ld);
	
	for(i=1; i<=taille-k; i++)
		ld = supprime_dernier_liste_div(ld);
		
	return ld;
}

/*Fonction de mise en avant des k_ppv*/
void mise_en_avant_k_ppv(liste l, point pt, int k)
{
	liste_div ld, ld1;
	
	/*Appel de la fonction kppv_sans_decision pour avoir la liste_div*/
	ld = kppv_sans_decision(l, pt, k);
	ld1 = ld;
	
	while(!est_liste_div_vide(ld1))
	{
	  affiche_point_classe(coordx_to_MLV(ld1->pt), coordy_to_MLV(ld1->pt), ld1 -> pt.classe);
		ld1 = ld1 -> suivant;
	}
	
	MLV_actualise_window();
}

/*Fonction d'implémentation du k_ppv avec prise de décision*/
void kppv_decision(liste l, point pt, int k)
{

	liste_div ld, ld1;
	int cptG=0, cptD=0;
	
	/*Appel de la fonction kppv_sans_decision pour avoir la liste_div*/
	ld = kppv_sans_decision(l, pt, k);
	ld1 = ld;
  	
	while(!est_liste_div_vide(ld1))
	{
	   if(ld1 -> pt.classe == 1)
		cptG ++;

	   else
		cptD ++;

	   ld1 = ld1 -> suivant;

	 }

	 if(cptG >= cptD)
	    pt.classe = 1;

	 else
	    pt.classe = 2;

  	/*Affichage du point*/
	 affiche_point_classe(coordx_to_MLV(pt), coordy_to_MLV(pt),pt.classe);
  
  	MLV_actualise_window();

}
