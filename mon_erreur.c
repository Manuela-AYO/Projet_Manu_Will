/***************************************************************************/
/***	fichier : mon_erreur.c 											***/
/*** Historique :														***/
/*** Création : 10/03/2021 par Manuela AYO								***/
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void mon_erreur(char *format, ...)
{
  va_list arg;
  
  va_start(arg,format);

  fprintf(stderr,"Erreur - ");
  
  vfprintf(stderr,format,arg);/*affichage de la chaine format*/

  va_end(arg);

  exit(EXIT_FAILURE);/*on sort de l'application, on utilise exit ici*/
}
