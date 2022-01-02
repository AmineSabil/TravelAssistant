all : main clear

clear:
	rm *.o

debug:
	valgrind --leak-check=full ./main

Trajet.o : Trajet.cpp Trajet.h
	g++ -c Trajet.cpp -ansi -pedantic -Wall -std=c++11 -g -DMAP

TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h
	g++  -c TrajetSimple.cpp -ansi -pedantic -Wall -std=c++11 -g -DMAP

TrajetComposee.o : TrajetComposee.cpp TrajetComposee.h
	g++ -c TrajetComposee.cpp -ansi -pedantic -Wall -std=c++11 -g -DMAP

Case.o : Case.cpp Case.h
	g++ -c Case.cpp -ansi -pedantic -Wall -std=c++11 -g -DMAP

Catalogue.o : Catalogue.cpp Catalogue.h
	g++ -c Catalogue.cpp -ansi -pedantic -Wall -std=c++11 -g -DMAP

ListeChainee.o : ListeChainee.cpp ListeChainee.h
	g++ -c ListeChainee.cpp -ansi -pedantic -Wall -std=c++11 -g -DMAP

main.o :  main.cpp
	g++ -c main.cpp -ansi -pedantic -Wall -std=c++11 -g -DMAP

main : main.o Case.o Trajet.o ListeChainee.o TrajetSimple.o TrajetComposee.o Catalogue.o
	g++ -o main main.o Case.o Trajet.o ListeChainee.o TrajetSimple.o TrajetComposee.o Catalogue.o -g
