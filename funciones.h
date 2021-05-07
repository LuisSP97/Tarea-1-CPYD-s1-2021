#ifndef CODIGO_FUNCIONES_H
#define CODIGO_FUNCIONES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "estudiante.h"
#include "estudiante.cpp"


//Funcion que elimina las comillas dobles de la palabra.
string split(string word){
    word.erase(remove(word.begin(), word.end(),'"'), word.end());
    return word;
}

float calc_gral(float leng, float ing, float mat, float cien, float hist, float tecn, float arte, float edfis){
    return ((leng + ing + mat + cien + hist + tecn + arte + edfis)/8);
}
float calc_artistico(float arte, float edfis){
    return ((arte + edfis)/2);
}
float calc_humanista(float leng, float hist){
    return ((leng  + hist )/2);
}
float calc_tecnico(float mat, float cien,float tecn){
    return ((mat + cien + tecn)/3);
}
//Funcion para leer el archivo linea por linea y almacenar los datos en un vector del tipo de la clase "estudiante" creada.
vector<estudiante> procesar_archivo(vector<estudiante> lista, string ruta){
    ifstream archivo(ruta);
    string linea;
    char delimitador = ';';
    if(archivo.is_open()){
        cout<<"Se abrio el archivo con exito!"<<endl;
        while(getline(archivo, linea)){
            stringstream stream(linea);
            //variables para almacenar datos del archivo
            string id, nombre, leng, ing, mat, cien, hist, tecn, arte, edfis;
            //Variables para almacenar datos del archivo en vector
            int idV;
            string nombreV;
            float lengV, ingV, matV, cienV, histV, tecnV, arteV, edfisV, gral,artistico,humanista,tecnico;
            gral = 0,artistico=0,humanista=0,tecnico=0;
            //
            getline(stream, id, delimitador);
            getline(stream, nombre, delimitador);
            getline(stream, leng, delimitador);
            getline(stream, ing, delimitador);
            getline(stream, mat, delimitador);
            getline(stream, cien, delimitador);
            getline(stream, hist, delimitador);
            getline(stream, tecn, delimitador);
            getline(stream, arte, delimitador);
            getline(stream, edfis, delimitador);
            // Elimino comillas dobles y se cambian tipos de variables
            idV = stoi(split(id));
            nombreV = split(nombre);
            lengV = stof(split(leng));
            ingV = stof(split(ing));
            matV = stof(split(mat));
            cienV = stof(split(cien));
            histV = stof(split(hist));
            tecnV = stof(split(tecn));
            arteV = stof(split(arte));
            edfisV = stof(split(edfis));
            // Crea registro estudiante, asigna valores y realiza push a lista que se debe retornar
            estudiante reg(idV,nombreV,lengV,ingV,matV,cienV,histV,tecnV,arteV,edfisV,gral,artistico,humanista,tecnico);
            reg.setId(idV);
            reg.setNombre(nombreV);
            reg.setProm_leng(lengV);
            reg.setProm_ing(ingV);
            reg.setProm_mat(matV);
            reg.setProm_cien(cienV);
            reg.setProm_hist(histV);
            reg.setProm_tecn(tecnV);
            reg.setProm_arte(arteV);
            reg.setProm_edfis(edfisV);
            reg.setProm_gral(calc_gral(lengV, ingV, matV, cienV, histV, tecnV, arteV, edfisV));
            reg.setProm_artistico(calc_artistico(arteV,edfisV));
            reg.setProm_humanista(calc_humanista(lengV,histV));
            reg.setProm_tecnico(calc_tecnico(matV,cienV,tecnV));
            lista.push_back(reg);
        }
        archivo.close();
    }
    else{cout<<"¡Ups!, el archivo no se abrio :c";}
    return lista;
}

int partitionGral(vector<estudiante> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    float pivotValue = values[pivotIndex].getProm_gral();
    int i = left, j = right;
    vector<estudiante> temp;
    while(i <= j) {
        while(values[i].getProm_gral() < pivotValue) {
            i++;
        }
        while(values[j].getProm_gral() > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp.push_back(values[i]);
            values[i] = values[j];
            values[j] = temp[0];
            i++;
            j--;
            temp.pop_back();
        }
    }
    return i;
}
void quicksortGral(vector<estudiante> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionGral(values, left, right);
        quicksortGral(values, left, pivotIndex - 1);
        quicksortGral(values, pivotIndex, right);
    }
}

int partitionArt(vector<estudiante> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    float pivotValue = values[pivotIndex].getProm_artistico();
    int i = left, j = right;
    vector<estudiante> temp;
    while(i <= j) {
        while(values[i].getProm_artistico() < pivotValue) {
            i++;
        }
        while(values[j].getProm_artistico() > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp.push_back(values[i]);
            values[i] = values[j];
            values[j] = temp[0];
            i++;
            j--;
            temp.pop_back();
        }
    }
    return i;
}
void quicksortArt(vector<estudiante> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionArt(values, left, right);
        quicksortArt(values, left, pivotIndex - 1);
        quicksortArt(values, pivotIndex, right);
    }
}

int partitionHum(vector<estudiante> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    float pivotValue = values[pivotIndex].getProm_humanista();
    int i = left, j = right;
    vector<estudiante> temp;
    while(i <= j) {
        while(values[i].getProm_humanista() < pivotValue) {
            i++;
        }
        while(values[j].getProm_humanista() > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp.push_back(values[i]);
            values[i] = values[j];
            values[j] = temp[0];
            i++;
            j--;
            temp.pop_back();
        }
    }
    return i;
}
void quicksortHum(vector<estudiante> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionHum(values, left, right);
        quicksortHum(values, left, pivotIndex - 1);
        quicksortHum(values, pivotIndex, right);
    }
}
int partitionTec(vector<estudiante> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    float pivotValue = values[pivotIndex].getProm_tecnico();
    int i = left, j = right;
    vector<estudiante> temp;
    while(i <= j) {
        while(values[i].getProm_tecnico() < pivotValue) {
            i++;
        }
        while(values[j].getProm_tecnico() > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp.push_back(values[i]);
            values[i] = values[j];
            values[j] = temp[0];
            i++;
            j--;
            temp.pop_back();
        }
    }
    return i;
}
void quicksortTec(vector<estudiante> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionTec(values, left, right);
        quicksortTec(values, left, pivotIndex - 1);
        quicksortTec(values, pivotIndex, right);
    }
}


//Funcion que elimina los primeros 100 registros del vector estudiante.
/*vector<estudiante> limpiar(vector<estudiante> lista){
    lista.erase(lista.end()-100,lista.end());
    return lista;
}*/
void limpiar(vector<estudiante> lista){
    for(int i=0;i<100;i++){
        lista.pop_back();
    }
}

//Funcion para eliminar "estudiantes.csv" de la ruta.
string limpiar_ruta(string ruta){
    int tamano = ruta.size()-1;
    int aux = ruta.size()-16;
    for(int i = tamano; i > aux; i--){
        ruta.pop_back();
    }
    return ruta;
}

//Funcion para generar el archivo con los 100 mejores promedios generales.
void crear_mejores(vector<estudiante> lista, string ruta){
    ofstream archivo;
    int aux;
    ruta.append("maximos.csv");
    cout << "Generando archivo: maximos.csv, en la ruta: " << ruta << endl;
    archivo.open(ruta);
    aux=lista.size()-1;
    for(int i = aux; i > (aux-100) ; i--){
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<lista[i].getProm_gral()<<endl;
    }
    archivo.close();
}

//Funcion para generar el archivo con los 100 mejores promedios Artisticos.
void crear_artistico(vector<estudiante> lista, string ruta){
    int aux;
    ruta.append("artistico.csv");
    cout << "Generando archivo: artistico.csv, en la ruta: " << ruta << endl;
    ofstream archivo;
    archivo.open(ruta);
    aux=lista.size()-1;
    for(int i = aux; i > (aux-100) ; i--){
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<lista[i].getProm_artistico()<<endl;
    }
    archivo.close();
}

//Funcion para generar el archivo con los 100 mejores promedios Humanistas.
void crear_humanismo(vector<estudiante> lista, string ruta){
    int aux;
    ruta.append("humanismo.csv");
    cout << "Generando archivo: humanismo.csv, en la ruta: " << ruta << endl;
    ofstream archivo;
    archivo.open(ruta);
    aux=lista.size()-1;
    for(int i = aux; i > (aux-100) ; i--){
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<lista[i].getProm_humanista()<<endl;
    }
    archivo.close();
}

//Funcion para generar el archivo con los 100 mejores promedios Tecnicos.
void crear_tecnicos(vector<estudiante> lista, string ruta){
    int aux;
    ruta.append("tecnicos.csv");
    cout << "Generando archivo: tencnicos.csv, en la ruta: " << ruta << endl;
    ofstream archivo;
    archivo.open(ruta);
    aux=lista.size()-1;
    for(int i = aux; i > (aux-100) ; i--){
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<lista[i].getProm_tecnico()<<endl;
    }
    archivo.close();
}
#endif //CODIGO_FUNCIONES_H
