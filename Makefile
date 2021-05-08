CXX=g++
CXXFLAGS=-Wall -g3
LDFLAGS=-lm
OBJECTS=funciones.o estudiante.o

main: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o main main.cpp $(OBJECTS) $(LDFLAGS)

estudiante.o: estudiante.h estudiante.cpp
	$(CXX) $(CXXFLAGS) -c estudiante.cpp

funciones.o: funciones.h funciones.cpp
	$(CXX) $(CXXFLAGS) -c funciones.cpp

.PHONY: clean
clean:
	rm -fr *.0 main