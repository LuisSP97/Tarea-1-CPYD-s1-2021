#include <iostream>
#include <vector>
#include "estudiante.h"
#include "funciones.h"
using namespace std;

int main(int argc, char *argv[]) {
    string ruta;
    vector<estudiante> lista;
    ruta = argv[1];
    cout << ruta;
    lista = procesar_archivo(lista, ruta);
    lista = ordenar_mejores(lista);
    crear_mejores(lista);
    limpiar(lista);
    lista = ordenar_artistico(lista);
    crear_artistico(lista);
    limpiar(lista);
    lista = ordenar_humanismo(lista);
    crear_humanismo(lista);
    limpiar(lista);
    lista = ordenar_tecnicos(lista);
    crear_tecnicos(lista);
    return 0;
}