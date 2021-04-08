CC= gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3
LEFTFLAG= -W -Wall -std=c89 -pedantic -O3 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
RIGHTFLAG=`pkg-config --libs-only-l MLV`

OBJETS= dessiner_plan.o affichage_des_menus.o bouton.o allocation.o

main: $(OBJETS) main.c
	@$(CC) $(LEFTFLAG) $(OBJETS) main.c $(RIGHTFLAG) -o bin/main

dessiner_plan.o: dessiner_plan.c 
	@$(CC) $(LEFTFLAG) -c dessiner_plan.c $(RIGHTFLAG) 

affichage_des_menus.o: affichage_des_menus.c
	@$(CC) $(LEFTFLAG) -c affichage_des_menus.c $(RIGHTFLAG)

bouton.o: bouton.c bouton.h
	@$(CC) $(LEFTFLAG) -c bouton.c $(RIGHTFLAG)

clean:
	@rm -f *.o *~ 
