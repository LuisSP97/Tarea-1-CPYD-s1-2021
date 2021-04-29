#include <iostream>
#include <vector>
#include "estudiante.h"
#include "funciones.h"
using namespace std;

int main() {
    vector<estudiante> lista;
    lista = procesar_archivo(lista);
//    ordenar(lista);
    cout << lista[15000].getProm_gral();
    return 0;
}