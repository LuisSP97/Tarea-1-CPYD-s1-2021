#include "funciones.h"


//Funcion que elimina las comillas dobles de la palabra.
string split(string word){
    word.erase(remove(word.begin(), word.end(),'"'), word.end());
    return word;
}



//Funcion que elimina los primeros 100 registros del vector estudiante.
vector<estudiante> limpiar(vector<estudiante> lista){
    lista.erase(lista.begin(),lista.begin()+99);
    return lista;
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

//Funcion para comprobar que el formato del archivo sea "csv".
bool validar_formato(string ruta, bool isCSV){
    int tamano = ruta.size()-1;
    int aux = ruta.size()-4;
    string formato;
    for(int i = tamano; i > aux; i--){
        formato.push_back(ruta[i]);
        ruta.pop_back();
    }
    if(formato == "vsc"){
        return true;
    }
    return false;
}

//Funcion para generar el archivo con los 100 mejores promedios generales.
void crear_mejores(vector<estudiante> lista, string ruta){
    ofstream archivo;
    ruta.append("maximos.csv");
    cout << "Generando archivo: maximos.csv, en la ruta: " << ruta << endl;
    archivo.open(ruta);
    for(int i = 0; i < 100 ; i++){
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<lista[i].getProm_gral()<<endl;
    }
    archivo.close();
}

//Funcion para generar el archivo con los 100 mejores promedios Artisticos.
void crear_artistico(vector<estudiante> lista, string ruta){
    float prom;
    ruta.append("artistico.csv");
    cout << "Generando archivo: artistico.csv, en la ruta: " << ruta << endl;
    ofstream archivo;
    archivo.open(ruta);
    for(int i = 0; i < 100; i++){
        prom = (lista[i].getProm_arte()+lista[i].getProm_edfis())/2;
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<prom<<endl;
    }
    archivo.close();
}

//Funcion para generar el archivo con los 100 mejores promedios Humanistas.
void crear_humanismo(vector<estudiante> lista, string ruta){
    float prom;
    ruta.append("humanismo.csv");
    cout << "Generando archivo: humanismo.csv, en la ruta: " << ruta << endl;
    ofstream archivo;
    archivo.open(ruta);
    for(int i = 0; i < 100; i++){
        prom = (lista[i].getProm_leng()+lista[i].getProm_hist())/2;
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<prom<<endl;
    }
    archivo.close();
}

//Funcion para generar el archivo con los 100 mejores promedios Tecnicos.
void crear_tecnicos(vector<estudiante> lista, string ruta){
    float prom;
    ruta.append("tecnicos.csv");
    cout << "Generando archivo: tencnicos.csv, en la ruta: " << ruta << endl;
    ofstream archivo;
    archivo.open(ruta);
    for(int i = 0; i < 100; i++){
        prom = (lista[i].getProm_mat()+lista[i].getProm_cien()+lista[i].getProm_tecn())/3;
        archivo<<lista[i].getId()<<";"<<lista[i].getNombre()<<";"<<prom<<endl;
    }
    archivo.close();
}
