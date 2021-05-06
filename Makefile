estudiante.o: estudiante.h estudiante.cpp
	g++ -Wall -g3 -c estudiante.h

funciones.o: funciones.h
	g++ -Wall -g3 -c funciones.h
	
main: main.cpp funciones.o
	g++ -Wall -g3 -o main main.cpp -lm
