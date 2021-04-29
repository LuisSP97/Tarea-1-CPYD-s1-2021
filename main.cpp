#include <iostream>
#include <vector>
#include "estudiante.h"
#include "funciones.h"
using namespace std;

int main() {
    vector<estudiante> lista;
    lista = procesar_archivo(lista);
    lista = ordenar_mejores(lista);
    cout << lista[0].getProm_arte() << endl;
    limpiar(lista);
    lista = ordenar_artistico(lista);
    cout << lista[0].getProm_arte();
    ordenar_humanismo(lista);
    return 0;
}