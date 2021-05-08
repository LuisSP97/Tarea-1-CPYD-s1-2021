#include "estudiante.h"

//Funcion que retorna el indice del pivote para realizar el QuickSort de los promedios generales
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

//Funcion para ordenar los datos mediante QuickSort segun el promedio general
void quicksortGral(vector<estudiante> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionGral(values, left, right);
        quicksortGral(values, left, pivotIndex - 1);
        quicksortGral(values, pivotIndex, right);
    }
}

//Funcion que retorna el indice del pivote para realizar el QuickSort del perfil artistico
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

//Funcion para ordenar los datos mediante QuickSort segun el perfil artistico
void quicksortArt(vector<estudiante> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionArt(values, left, right);
        quicksortArt(values, left, pivotIndex - 1);
        quicksortArt(values, pivotIndex, right);
    }
}

//Funcion que retorna el indice del pivote para realizar el QuickSort del perfil humanista
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

//Funcion para ordenar los datos mediante QuickSort segun el perfil humanista
void quicksortHum(vector<estudiante> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionHum(values, left, right);
        quicksortHum(values, left, pivotIndex - 1);
        quicksortHum(values, pivotIndex, right);
    }
}

//Funcion que retorna el indice del pivote para realizar el QuickSort del perfil tecnico
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

//Funcion para ordenar los datos mediante QuickSort segun el perfil tecnico
void quicksortTec(vector<estudiante> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionTec(values, left, right);
        quicksortTec(values, left, pivotIndex - 1);
        quicksortTec(values, pivotIndex, right);
    }
}

