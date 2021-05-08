#include "funciones.h"


//Funcion para eliminar las comillas dobles de los datos
string split(string word){
    word.erase(remove(word.begin(), word.end(),'"'), word.end());
    return word;
}

//Funcion que calcula el promedio general
float calc_gral(float leng, float ing, float mat, float cien, float hist, float tecn, float arte, float edfis){
    return ((leng + ing + mat + cien + hist + tecn + arte + edfis)/8);
}

//Funcion que calcula el promedio del perfil artistico
float calc_artistico(float arte, float edfis){
    return ((arte + edfis)/2);
}

//Funcion que calcula el promedio del perfil humanista
float calc_humanista(float leng, float hist){
    return ((leng  + hist )/2);
}

//Funcion que calcula el promedio del perfil tecnico
float calc_tecnico(float mat, float cien,float tecn){
    return ((mat + cien + tecn)/3);
}

//Funcion para leer el archivo linea por linea y almacenar los datos en un vector del tipo de la clase "estudiante" creada.
vector<estudiante> procesar_archivo(vector<estudiante> lista, string ruta){
    ifstream archivo(ruta);
    string linea;
    char delimitador = ';';
    if(archivo.is_open()){
        cout << "Se abrio el archivo con exito!" << endl;
        while(getline(archivo, linea)){
            stringstream stream(linea);
            //variables para almacenar datos del archivo
            string id, nombre, leng, ing, mat, cien, hist, tecn, arte, edfis;
            //Variables para almacenar datos del archivo en vector
            int idV;
            string nombreV;
            float lengV, ingV, matV, cienV, histV, tecnV, arteV, edfisV, gral,artistico,humanista,tecnico;
            gral = 0, artistico = 0, humanista = 0, tecnico = 0;
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
    else{
        cout << "¡Ups!, el archivo no se abrio :c" << endl;
        }
    return lista;
}

//Funcion que elimina 100 ultimos registros del vector estudiante.
vector<estudiante> limpiar(vector<estudiante> lista){
    for(int i = 0; i < 100; i++){
        lista.pop_back();
    }
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

//Funcion para validar que el formato del archivo sea ".csv"
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