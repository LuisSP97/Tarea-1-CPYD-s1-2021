//
// Created by Luis Salinas on 24-04-21.
//

#include "estudiante.h"
#include "funciones.h"

float calc_gral(float leng, float ing, float mat, float cien, float hist, float tecn, float arte, float edfis){
    return ((leng + ing + mat + cien + hist + tecn + arte + edfis)/8);
}

//Funcion para leer el archivo linea por linea y almacenar los datos en un vector del tipo de la clase "estudiante" creada.
vector<estudiante> procesar_archivo(vector<estudiante> lista, string ruta){
    ifstream archivo(ruta);
    string linea;
    char delimitador = ';';
    if(archivo.is_open()){
        cout<<"Se abrio el archivo con exito!" << endl;
        cout << "Procesando datos del archivo..." << endl;
        while(getline(archivo, linea)){
            stringstream stream(linea);
            //variables para almacenar datos del archivo
            string id, nombre, leng, ing, mat, cien, hist, tecn, arte, edfis;
            //Variables para almacenar datos del archivo en vector
            int idV;
            string nombreV;
            float lengV, ingV, matV, cienV, histV, tecnV, arteV, edfisV, gral;
            gral = 0;
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
    else{
        cout<<"¡Ups!, no se encontro un archivo valido en la ruta indicada :c" << endl;
        exit(0);
        }
    return lista;
}
//Funcion que ordena los mejores promedios generales de mayor a menor.
vector<estudiante> ordenar_mejores(vector<estudiante> lista){
    cout << "Ordenando los mejores promedios generales..." << endl;
    vector<estudiante> aux;
    int tamano_lista = lista.size();
    for(int i = 0; i < tamano_lista; i++){
        for(int j = 0; j < tamano_lista; j++){
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

//Funcion que ordena los mejores promedios Artisticos de mayor a menor.
vector<estudiante> ordenar_artistico(vector<estudiante> lista){
    cout << "Ordenando los mejores promedios artisticos..." << endl;
    vector<estudiante> aux;
    int tamano_lista = lista.size();
    for(int i = 0; i < tamano_lista; i++) {
        for (int j = 0; j < tamano_lista; j++) {
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

//Funcion que ordena los mejores promedios Humanistas de mayor a menor.
vector<estudiante> ordenar_humanismo(vector<estudiante> lista){
    cout << "Ordenando los mejores promedios humanistas..." << endl;
    vector<estudiante> aux;
    int tamano_lista = lista.size();
    for(int i = 0; i < tamano_lista; i++){
        for(int j = 0; j < tamano_lista; j++){
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

//Funcion que ordena los mejores promedios Tecnicos de mayor a menor.
vector<estudiante> ordenar_tecnicos(vector<estudiante> lista){
    cout << "Ordenando los mejores promedios tecnicos..." << endl;
    vector<estudiante> aux;
    int tamano_lista = lista.size();
    for(int i = 0; i < tamano_lista; i++){
        for(int j = 0; j < tamano_lista; j++){
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


