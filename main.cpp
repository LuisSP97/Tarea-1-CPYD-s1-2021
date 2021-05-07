#include <iostream>
#include <vector>
#include "estudiante.h"
#include "funciones.h"
#include <stdlib.h>
using namespace std;

vector<int> mifunc(vector<int> prueba){
    for(int i=0;i<15000;i++){
        prueba.push_back((rand()%200)+1);
    }
    return prueba;
    
}

int main(int argc, char *argv[]) {
    unsigned t0, t1;
    t0 = clock();
    int auxizq,auxder;
    string ruta;
    vector<estudiante> lista,lista2;
    vector<int> prueba;
    ruta = argv[1];
    //Se abre el archivo y se almacenan sus datos en un vector.
   
    lista = procesar_archivo(lista, ruta);
    //Se ordenan desde el mejor promedio al peor todos los datos.
    auxizq=0;
    auxder=lista.size()-1;
    quicksortGral(lista,auxizq,auxder);
    //Se limpia la ruta para poder guardar los archivos generados en la ruta del archivo "estudiantes.csv".
    ruta = limpiar_ruta(ruta);
    //Se genera el archivo con los 100 mejores promedios.
    crear_mejores(lista, ruta);
    //Se limpian los 100 primeros datos (0 al 99).
    limpiar(lista);
    //Se ordenan los datos de mayor a menor, segun el promedio de las notas de Arte y Ed. Fisica.
    auxizq=0;
    auxder=lista.size()-1;
    quicksortArt(lista,auxizq,auxder);
    //Se genera el archivo con los 100 mejores promedios de las notas del perfil artistico.
    crear_artistico(lista, ruta);
    //Se limpian los 100 primeros datos (0 al 99).
    limpiar(lista);
    //Se ordenan los datos de mayor a menor, segun el promedio de las notas de Lengua e Historia.
    auxizq=0;
    auxder=lista.size()-1;
    quicksortHum(lista,auxizq,auxder);
    //Se genera el archivo con los 100 mejores promedios de las notas del perfil Humanista.
    crear_humanismo(lista, ruta);
    //Se limpian los 100 primeros datos (0 al 99).
    limpiar(lista);
    //Se ordenan los datos de mayor a menor, segun el promedio de las notas de Tecnologia, Matematica y Ciencias naturales.
    auxizq=0;
    auxder=lista.size()-1;
    quicksortTec(lista,auxizq,auxder);
    //Se genera el archivo con los 100 mejores promedios de las notas del perfil Tecnico.
    crear_tecnicos(lista, ruta);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion:" << time << endl;
    return 0;
}