#include<stdio.h>
#include<stdlib.h>
#include<MLV/MLV_all.h>
#include"dessine_plan.h"


void dessiner_plan_2_dimensions ()
{
  int i, taille_graduation, position_graduation;
  
  MLV_clear_window(MLV_COLOR_BLACK);
  
  /* ***** On dessine l'axe y ***** */
  /*--axe--*/
  MLV_draw_line(MILIEU_HORIZONTAL,
		HAUT_PLAN,
		MILIEU_HORIZONTAL,
		BAS_PLAN,
	        MLV_COLOR_WHITE);
  
  /*--flèche--*/
  MLV_draw_line(MILIEU_HORIZONTAL - 5,
		HAUT_PLAN,
		MILIEU_HORIZONTAL,
		HAUT_PLAN - 5,
		MLV_COLOR_WHITE);
  
  MLV_draw_line(MILIEU_HORIZONTAL,
		HAUT_PLAN - 5,
		MILIEU_HORIZONTAL +5,
		HAUT_PLAN,
		MLV_COLOR_WHITE);

  
   /* ***** On dessine l'axe y ***** */
  /*--axe--*/
  MLV_draw_line(GAUCHE_PLAN,
		MILIEU_VERTICAL,
		DROITE_PLAN,
		MILIEU_VERTICAL,
		MLV_COLOR_WHITE);
  
  /* flèche */
  MLV_draw_line(DROITE_PLAN,
		MILIEU_VERTICAL- 5,
		DROITE_PLAN + 5,
		MILIEU_VERTICAL,
		MLV_COLOR_WHITE);
  
  MLV_draw_line(DROITE_PLAN + 5,
		MILIEU_VERTICAL,
		DROITE_PLAN,
		MILIEU_VERTICAL + 5,
		MLV_COLOR_WHITE);

  /* ***** On dessine le cadre autour du plan ***** */

  MLV_draw_rectangle(GAUCHE_PLAN - PADDING, /*x Nord Ouest*/
		     HAUT_PLAN - PADDING,  /*y N Ouest*/
		     DROITE_PLAN - GAUCHE_PLAN + 2*PADDING,/*width*/
		     HAUT_PLAN - BAS_PLAN + 2*PADDING, /*heigth*/
		     MLV_COLOR_WHITE);

  /* *********** La graduation horizontale ********** */

  /*--initialisation des variables--*/
  taille_graduation= (DROITE_PLAN - GAUCHE_PLAN -20) / NB_GRADUATIONS;
  /*un decalage de -10 est pris en compte (des deux cotés)
    pour ne pas commencer la graduation au début de la ligne mais un peu après*/
  position_graduation= GAUCHE_PLAN + 10;

  /*--on place l'échelle--*/
  MLV_draw_text(position_graduation - 10,
		MILIEU_VERTICAL + 5,
		VALEUR_MIN_X,
		MLV_COLOR_WHITE);

  MLV_draw_text(DROITE_PLAN - 15,
		MILIEU_VERTICAL + 5,
		VALEUR_MAX_X,
		MLV_COLOR_WHITE);

  for(i=0; i<=NB_GRADUATIONS; i++)
    {
      if(position_graduation != MILIEU_VERTICAL)
	{
	  MLV_draw_line(position_graduation,
			MILIEU_VERTICAL,
			position_graduation,
			MILIEU_VERTICAL + 2,
			MLV_COLOR_WHITE);
	}
      position_graduation += taille_graduation;
    }

  
  /* ********** La graduation verticale ********** */
  
  /*--initialisation des variables-- */
  taille_graduation= (BAS_PLAN - HAUT_PLAN - 20) / NB_GRADUATIONS;
  position_graduation= HAUT_PLAN + 10;

  /*--on place l'échelle--*/
  MLV_draw_text(MILIEU_HORIZONTAL - 10,
		position_graduation - 10,
		VALEUR_MAX_Y,
		MLV_COLOR_WHITE);

  MLV_draw_text(MILIEU_HORIZONTAL - 15,
		BAS_PLAN - 15,
		VALEUR_MIN_Y,
		MLV_COLOR_WHITE);

  for(i=0; i<=NB_GRADUATIONS; i++)
    {
      if(position_graduation != MILIEU_HORIZONTAL)
	{
	  MLV_draw_line(MILIEU_HORIZONTAL,
			position_graduation,
			MILIEU_HORIZONTAL + 2,
			position_graduation,
			MLV_COLOR_WHITE);
	}
      position_graduation += taille_graduation;
    }

  MLV_actualise_window();

}
