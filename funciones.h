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

string split(string word){
    //Funcion que elimina las comillas dobles de la palabra
    word.erase(remove(word.begin(), word.end(),'"'), word.end());
    return word;
}

float calc_gral(float leng, float ing, float mat, float cien, float hist, float tecn, float arte, float edfis){
    return ((leng + ing + mat + cien + hist + tecn + arte + edfis)/8);
}

vector<estudiante> procesar_archivo(vector<estudiante> lista){
    string ruta;
    cout<<"Ingrese la ruta donde se encuentra el archivo con los datos de los estudiantes:"<<endl;
    cin >> ruta;
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
            float lengV, ingV, matV, cienV, histV, tecnV, arteV, edfisV, gral;
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
            estudiante reg(idV,nombreV,lengV,ingV,matV,cienV,histV,tecnV,arteV,edfisV,gral);
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
            lista.push_back(reg);
        }
        archivo.close();
    }
    else{cout<<"El archivo no se abrio!, deberia estar en la carpeta CMake :c";}
    return lista;
}

vector<estudiante> ordenar_mejores(vector<estudiante> lista){
    vector<estudiante> aux;
    for(int i = 0; i < lista.size(); i++){
        for(int j = 0; j < lista.size(); j++){
            if(lista[i].getProm_gral() > lista[j].getProm_gral()){
                aux.push_back(lista[i]);
                lista[i] = lista[j];
                lista[j] = aux[0];
                aux.pop_back();
            }
        }
    }
    return lista;
};

vector<estudiante> ordenar_artistico(vector<estudiante> lista){
    vector<estudiante> aux;
    for(int i = 0; i < lista.size(); i++) {
        for (int j = 0; j < lista.size(); j++) {
            float prom_i = (lista[i].getProm_arte() + lista[i].getProm_edfis()) / 2;
            float prom_j = (lista[j].getProm_arte() + lista[j].getProm_edfis()) / 2;
            if (prom_i > prom_j) {
                aux.push_back(lista[i]);
                lista[i] = lista[j];
                lista[j] = aux[0];
                aux.pop_back();
            }
        }
    }
    return lista;
}

vector<estudiante> ordenar_humanismo(vector<estudiante> lista){
    vector<estudiante> aux;
    for(int i = 0; i < lista.size(); i++){
        for(int j = 0; j < lista.size(); j++){
            float prom_i = (lista[i].getProm_leng()+lista[i].getProm_hist())/2;
            float prom_j = (lista[j].getProm_leng()+lista[j].getProm_hist())/2;
            if(prom_i > prom_j){
                aux.push_back(lista[i]);
                lista[i] = lista[j];
                lista[j] = aux[0];
                aux.pop_back();
            }
        }
    }
    return lista;
}

vector<estudiante> ordenar_tecnicos(vector<estudiante> lista){
    vector<estudiante> aux;
    for(int i = 0; i < lista.size(); i++){
        for(int j = 0; j < lista.size(); j++){
            float prom_i = (lista[i].getProm_mat()+lista[i].getProm_cien()+lista[i].getProm_tecn())/3;
            float prom_j = (lista[j].getProm_mat()+lista[j].getProm_cien()+lista[j].getProm_tecn())/3;
            if(prom_i > prom_j){
                aux.push_back(lista[i]);
                lista[i] = lista[j];
                lista[j] = aux[0];
                aux.pop_back();
            }
        }
    }
    return lista;
}

vector<estudiante> limpiar(vector<estudiante> lista){
    lista.erase(lista.begin(),lista.begin()+99);
    return lista;
}


void crear_mejores(vector<estudiante> lista){
    ofstream archivo;
    archivo.open("maximos.csv");
    for(int i = 0; i < 100 ; i++){
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<lista[i].getProm_gral()<<endl;
    }
    archivo.close();
}

void crear_artistico(vector<estudiante> lista){
    float prom;
    ofstream archivo;
    archivo.open("artistico.csv");
    for(int i = 0; i < 100; i++){
        prom = (lista[i].getProm_arte()+lista[i].getProm_edfis())/2;
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<prom<<endl;
    }
    archivo.close();
}

void crear_humanismo(vector<estudiante> lista){
    float prom;
    ofstream archivo;
    archivo.open("humanismo.csv");
    for(int i = 0; i < 100; i++){
        prom = (lista[i].getProm_leng()+lista[i].getProm_hist())/2;
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<prom<<endl;
    }
    archivo.close();
}

void crear_tecnicos(vector<estudiante> lista){
    float prom;
    ofstream archivo;
    archivo.open("tecnicos.csv");
    for(int i = 0; i < 100; i++){
        prom = (lista[i].getProm_mat()+lista[i].getProm_cien()+lista[i].getProm_tecn())/3;
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<prom<<endl;
    }
    archivo.close();
}
#endif //CODIGO_FUNCIONES_H
