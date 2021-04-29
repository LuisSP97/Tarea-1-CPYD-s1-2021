#include <iostream>
#include <vector>
#include "estudiante.h"
#include "funciones.h"
using namespace std;

int main() {
    vector<estudiante> lista;
    lista = procesar_archivo(lista);
    lista = ordenar_mejores(lista);
    //AQUI: GENERAR ARCHIVO
    limpiar(lista);
    lista = ordenar_artistico(lista);
    //AQUI: GENERAR ARCHIVO
    limpiar(lista);
    lista = ordenar_humanismo(lista);
    limpiar(lista);
    //AQUI: GENERAR ARCHIVO
    lista = ordenar_tecnicos(lista);
    return 0;
}