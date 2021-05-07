#include <iostream>
#include <vector>
#include "estudiante.h"
#include "funciones.h"
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
    unsigned t0, t1;
    t0 = clock();
    int auxizq,auxder,auxizq1,auxder1;
    string ruta;
    vector<estudiante> lista,lista2;
    vector<int> testvect;
    for(int i=30;i>20;i--){
        testvect.push_back(i);
    }
    for(int i=0;i<10;i++){
        cout<<testvect[i]<<" ; ";
    }
    cout<<endl;
    auxizq1=0;
    auxder1=9;
    testvect = ordenar1(testvect,auxizq1,auxder1);
    for(int i=0;i<10;i++){
        cout<<testvect[i]<<" ; ";
    }
    ruta = argv[1];
    //Se abre el archivo y se almacenan sus datos en un vector.
    lista = procesar_archivo(lista, ruta);
    //Se ordenan desde el mejor promedio al peor todos los datos.
    auxizq=0;
    auxder=lista.size()-1;
    lista=ordenar(lista,auxizq,auxder);
    //Se limpia la ruta para poder guardar los archivos generados en la ruta del archivo "estudiantes.csv".
    ruta = limpiar_ruta(ruta);
    //Se genera el archivo con los 100 mejores promedios.
    crear_mejores(lista, ruta);
    //Se limpian los 100 primeros datos (0 al 99).
    limpiar(lista);
    //Se ordenan los datos de mayor a menor, segun el promedio de las notas de Arte y Ed. Fisica.
    /*lista = ordenar_artistico(lista);
    //Se genera el archivo con los 100 mejores promedios de las notas del perfil artistico.
    crear_artistico(lista, ruta);
    //Se limpian los 100 primeros datos (0 al 99).
    limpiar(lista);
    //Se ordenan los datos de mayor a menor, segun el promedio de las notas de Lengua e Historia.
    lista = ordenar_humanismo(lista);
    //Se genera el archivo con los 100 mejores promedios de las notas del perfil Humanista.
    crear_humanismo(lista, ruta);
    //Se limpian los 100 primeros datos (0 al 99).
    limpiar(lista);
    //Se ordenan los datos de mayor a menor, segun el promedio de las notas de Tecnologia, Matematica y Ciencias naturales.
    lista = ordenar_tecnicos(lista);
    //Se genera el archivo con los 100 mejores promedios de las notas del perfil Tecnico.
    crear_tecnicos(lista, ruta);
    */
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion:" << time << endl;
    return 0;
}