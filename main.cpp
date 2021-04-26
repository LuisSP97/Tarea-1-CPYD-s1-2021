#include <iostream>
#include <vector>
#include "estudiante.h"
#include "funciones.h"
using namespace std;

int main() {
    vector<estudiante> lista;
    lista = procesar_archivo(lista);
    cout << lista[0].getNombre();
    return 0;
}