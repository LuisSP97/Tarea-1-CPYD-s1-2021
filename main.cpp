#include <iostream>
#include <vector>
#include "estudiante.h"
#include "funciones.h"
using namespace std;

int main(int argc, char *argv[]) {
    if(argv[1]){
        unsigned t0, t1;
        t0 = clock();  
        string ruta;
        vector<estudiante> lista;
        ruta = argv[1];
        //Se abre el archivo y se almacenan sus datos en un vector.
        lista = procesar_archivo(lista, ruta);
        cout << "----------------" << endl;
        //Se ordenan desde el mejor promedio al peor todos los datos.
        lista = ordenar_mejores(lista);
        //Se limpia la ruta para poder guardar los archivos generados en la ruta del archivo "estudiantes.csv".
        ruta = limpiar_ruta(ruta);
        //Se genera el archivo con los 100 mejores promedios.
        crear_mejores(lista, ruta);
        //Se limpian los 100 primeros datos (0 al 99).
        lista = limpiar(lista);
        cout << "----------------" << endl;
        //Se ordenan los datos de mayor a menor, segun el promedio de las notas de Arte y Ed. Fisica.
        lista = ordenar_artistico(lista);
        //Se genera el archivo con los 100 mejores promedios de las notas del perfil artistico.
        crear_artistico(lista, ruta);
        //Se limpian los 100 primeros datos (0 al 99).
        lista = limpiar(lista);
        cout << "----------------" << endl;
        //Se ordenan los datos de mayor a menor, segun el promedio de las notas de Lengua e Historia.
        lista = ordenar_humanismo(lista);
        //Se genera el archivo con los 100 mejores promedios de las notas del perfil Humanista.
        crear_humanismo(lista, ruta);
        //Se limpian los 100 primeros datos (0 al 99).
        lista = limpiar(lista);
        cout << "----------------" << endl;
        //Se ordenan los datos de mayor a menor, segun el promedio de las notas de Tecnologia, Matematica y Ciencias naturales.
        lista = ordenar_tecnicos(lista);
        //Se genera el archivo con los 100 mejores promedios de las notas del perfil Tecnico.
        crear_tecnicos(lista, ruta);
        cout << "----------------" << endl;
        cout << "=== Integrantes ===" << endl;
        cout << "Luis Salinas Poblete" << endl;
        cout << "Cristobal Sanchez Orellana" << endl;
        cout << "Ariel Painenao Pincheira" << endl;
        cout << "----------------" << endl;
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Tiempo de ejecucion:" << time << endl;
    }
    else{
        cout << "Ups, no has indicado la ruta del archivo :c" << endl;
    }
    return 0;
}