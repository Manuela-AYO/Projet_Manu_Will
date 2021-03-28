/***************************************************************************
 *Programme permettant de générer des fichiers dans le format suivant :    *
 *                                                                         *
 *  -La première ligne contient 3 entiers positifs séparés par un espace : *
 *      >le nombre de points n contenus dans le fichier,                   *
 *      >la dimension d des données                                        *
 *      >et le nombre de classe c.                                         *
 *                                                                         *
 *    -Les n lignes restantes du fichier sont de la forme :                *
 *      >classe coord_1 coord_2 ... coord_d,                               *
 * où classe est un entier compris entre 1 et c et les coordonnées sont    *
 * des réelscompris entre -1 et 1.                                         *
 *                                                                         *
 *Prend 4 arguments (dans cet ordre) :                                     *
 *  -nom du fichier                                                        *
 *  -nombre de points à générer                                            *
 *  -nombre de classes                                                     *
 *  -nombre de dimensions (défaut 2)                                       *
 *                                                                         *
 ***************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void usage(char *s){
    fprintf(stderr, "Arguments du programme invalides.\n");
    printf("usage %s : <nom_fichier> <nombre_points> <nombre_calsses> <dimension=2>\n", s);
    printf("<nom_fichier> : nom du fichier généré\n");
    printf("<nombre_points> : nombre de points à générer\n");
    printf("<nombre_classes> : nombre de classes\n");
    printf("<dimension> : nombre de dimensions, par défaut 2\n\n");
}


int main(int argc, char **argv){
    int nb_points, nb_classes, nb_dimensions;
    char *nom_fichier;
    FILE *file=NULL;
    int i, j;
    float coord;
    unsigned int erreur= 0;

    
    /*_____On récupère les arguments et on test si ils conviennent_____*/
    if(argc < 4){
        usage(argv[0]);
        exit(-1);
    }

    nom_fichier= argv[1];
    nb_points= atoi(argv[2]);
    nb_classes= atoi(argv[3]);
    if(argc == 3){
        nb_dimensions= 2;
    }
    else{
        nb_dimensions= atoi(argv[4]);
    }

    if(nb_points < 0  ||  nb_classes < 2 || nb_dimensions < 1){
        usage(argv[0]);
        exit(-1);
    }


    /*_____Ouverture du fichier_____*/
    file= fopen(nom_fichier, "w");
    if(file == NULL){
        printf("Imposible de créer le fichier %s.\n", nom_fichier);
        exit(-1);
    }


    /*_____Remplissage du fichier_____*/
    srand(time(NULL));
    
    /*--1ière ligne--*/
    if(fprintf(file, "%d %d %d\n", nb_points, nb_dimensions, nb_classes) < 3){
        fprintf(stderr, "Erreur d'écriture dans la première ligne du fichier\n");
        erreur++;
    }
    
    /*--n lignes suivantes--*/
    for(i=1; i<=nb_points; i++){
        
        if(fprintf(file, "%d ", rand() % nb_classes + 1) < 1){
            fprintf(stderr, "Erreur d'écriture dans le fichier %s, pour la valeur de la classe à la ligne %d.\n", nom_fichier, i);
            erreur++;
        }
        
        for(j=0; j<nb_dimensions; j++){  
            coord= rand() / ((float) RAND_MAX);           
            if(fprintf(file,"%f ", coord) < 1){
                fprintf(stderr, "Erreur d'écriture dans le fichier %s, pour la valeur de la %d coordonnée à la %d ligne.\n", nom_fichier, j, i);
                erreur++;
            }
            
        }
        
        if(fputc('\n', file) != '\n'){
            fprintf(stderr,"Erreur d'écriture dans le fichier %s, saut de ligne à la fin de la %d ligne manquant.\n", nom_fichier, i);
            erreur++;
        }       
    }

    
    /*_____Confirmation de la création du fichier, et fermeture de ce dernier_____*/
    fclose(file);
    if(erreur == 0){
        printf("Création du fichier %s avec succès.\n", nom_fichier);
        exit(1);
    }
    printf("Création du fichier avec %hd erreurs, veuillez consulter le canal d'erreur pour plus d'informations.\n", erreur);
    exit(0);
}