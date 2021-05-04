#include <iostream>
#include <vector>
#include "estudiante.h"
#include "funciones.h"
using namespace std;

int main() {
    string ruta;
    vector<estudiante> lista;
    lista = procesar_archivo(lista);
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