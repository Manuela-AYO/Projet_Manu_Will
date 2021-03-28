CC=gcc
EXEC=test
OPTIONS=-Wall -O3

test : test.o chargement.o listes.o allocation.o mon_erreur.o
	$(CC) -o $@ $^

test.o : test.c type.h
	$(CC) $(OPTIONS) -c $^

chargement.o : chargement.c type.h
	$(CC) $(OPTIONS) -c $^

listes.o : listes.c
	$(CC) $(OPTIONS) -c $^

allocation.o : allocation.c
	$(CC) $(OPTIONS) -c $^

mon_erreur.o : mon_erreur.c
	$(CC) $(OPTIONS) -c $^

clean :
	rm -rf $(EXEC) *.o