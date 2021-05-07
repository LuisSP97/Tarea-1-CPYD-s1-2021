#ifndef CODIGO_FUNCIONES_H
#define CODIGO_FUNCIONES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "estudiante.h"

using namespace std;

string split(string word);
vector<estudiante> limpiar(vector<estudiante> lista);
string limpiar_ruta(string ruta);
bool validar_formato(string ruta, bool isCSV);
void crear_mejores(vector<estudiante> lista, string ruta);
void crear_artistico(vector<estudiante> lista, string ruta);
void crear_humanismo(vector<estudiante> lista, string ruta);
void crear_tecnicos(vector<estudiante> lista, string ruta);

#endif //CODIGO_FUNCIONES_H
