CC= gcc
LEFTFLAG= -W -Wall -std=c89 -pedantic -O3 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
RIGHTFLAG=`pkg-config --libs-only-l MLV`
LDLIBS = `pkg-config --libs-only-l MLV`

test: test_taille_fenetre.c
	$(CC) $(LEFTFLAG) test_taille_fenetre.c $(RIGHTFLAG) -o bin/test 

clean:
	rm -f *.o *~ 
