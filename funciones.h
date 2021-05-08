#ifndef CODIGO_FUNCIONES_H
#define CODIGO_FUNCIONES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "estudiante.h"


string split(string word);
float calc_gral(float leng, float ing, float mat, float cien, float hist, float tecn, float arte, float edfis);
float calc_artistico(float arte, float edfis);
float calc_humanista(float leng, float hist);
float calc_tecnico(float mat, float cien,float tecn);
vector<estudiante> procesar_archivo(vector<estudiante> lista, string ruta);
void limpiar(vector<estudiante> lista);
string limpiar_ruta(string ruta);
bool validar_formato(string ruta, bool isCSV);
void crear_mejores(vector<estudiante> lista, string ruta);
void crear_artistico(vector<estudiante> lista, string ruta);
void crear_humanismo(vector<estudiante> lista, string ruta);
void crear_tecnicos(vector<estudiante> lista, string ruta);


#endif //CODIGO_FUNCIONES_H
