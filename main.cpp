#include <iostream>
#include <vector>
#include <stdlib.h>
#include "funciones.h"

using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2 || argc > 3){
        cout << "Ups!, olvidaste ingresar la ruta al archivo o ingresaste parametros extra." << endl;
    }
    else{
        //Variables de validacion de formato y parametros.
        string ruta = argv[1];
        bool isCSV = false;
        isCSV = validar_formato(ruta, isCSV);

        if(isCSV == true){
            //Variables y funcion para medir tiempo de ejecucion.
            unsigned t0, t1;
            t0 = clock();

            //Variables para ejecutar las funciones principales
            int auxizq,auxder;
            vector<estudiante> lista,lista2;
            vector<int> prueba;

            //Se abre el archivo y se almacenan sus datos en un vector.
            lista = procesar_archivo(lista, ruta);

            //Se ordenan desde el peor promedio al mejor todos los datos.
            auxizq=0;
            auxder=lista.size()-1;
            quicksortGral(lista,auxizq,auxder);

            //Se limpia la ruta para poder guardar los archivos generados en la ruta del archivo "estudiantes.csv".
            ruta = limpiar_ruta(ruta);

            //Se genera el archivo con los 100 mejores promedios.
            crear_mejores(lista, ruta);

            //Se limpian los 100 primeros datos (0 al 99).
            limpiar(lista);

            //Se ordenan los datos de menor a mayor, segun el promedio de las notas de Arte y Ed. Fisica.
            auxizq=0;
            auxder=lista.size()-1;
            quicksortArt(lista,auxizq,auxder);

            //Se genera el archivo con los 100 mejores promedios de las notas del perfil artistico.
            crear_artistico(lista, ruta);

            //Se limpian los 100 primeros datos (0 al 99).
            limpiar(lista);

            //Se ordenan los datos de menor a mayor, segun el promedio de las notas de Lengua e Historia.
            auxizq=0;
            auxder=lista.size()-1;
            quicksortHum(lista,auxizq,auxder);

            //Se genera el archivo con los 100 mejores promedios de las notas del perfil Humanista.
            crear_humanismo(lista, ruta);

            //Se limpian los 100 primeros datos (0 al 99).
            limpiar(lista);

            //Se ordenan los datos de menor a mayor, segun el promedio de las notas de Tecnologia, Matematica y Ciencias naturales.
            auxizq=0;
            auxder=lista.size()-1;
            quicksortTec(lista,auxizq,auxder);

            //Se genera el archivo con los 100 mejores promedios de las notas del perfil Tecnico.
            crear_tecnicos(lista, ruta);

            //Se finaliza el contador de tiempo de ejecucion.
            t1 = clock();
            double time = (double(t1-t0)/CLOCKS_PER_SEC);
            cout << "Tiempo de ejecucion:" << time << endl;
            cout << "----------------" << endl;
            cout << "=== Integrantes ===" << endl;
            cout << "Luis Salinas Poblete" << endl;
            cout << "Cristobal Sanchez Orellana" << endl;
            cout << "Ariel Painenao Pincheira" << endl;
            cout << "----------------" << endl;
        }
        else{
            cout << "El formato del archivo ingresado no es compatible con el programa." << endl;
        }

    }
    
    return 0;
}