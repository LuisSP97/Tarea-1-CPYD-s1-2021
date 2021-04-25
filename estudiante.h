//
// Created by Luis Salinas on 24-04-21.
//
#include <string>
#include <utility>

#ifndef CODIGO_ESTUDIANTE_H
#define CODIGO_ESTUDIANTE_H

using namespace std;

class estudiante {

public:
    //Constructor
    estudiante(int id, string nombre, float prom_leng, float prom_ing, float prom_mat, float prom_cien, float prom_hist, float prom_tecn, float prom_arte, float prom_edfis) {}
    //Metodos set
    void setId(int num){id = num;}
    void setNombre(string name){nombre = name;}
    void setProm_leng(float leng){prom_leng = leng;}
    void setProm_ing(float ing){prom_ing = ing;}
    void setProm_mat(float mat){prom_mat = mat;}
    void setProm_cien(float cien){prom_cien = cien;}
    void setProm_hist(float hist){prom_hist = hist;}
    void setProm_tecn(float tecn){prom_tecn = tecn;}
    void setProm_arte(float arte){prom_arte = arte;}
    void setProm_edfis(float edfis){prom_edfis = edfis;}
    //void setProm_gral(float gral){prom_gral = gral;}
    //Metodos get
    const int getId(){return id;}
    const string getNombre(){return nombre;}
    const float getProm_leng(){return prom_leng;}
    const float getProm_ing(){return prom_ing;}
    const float getProm_mat(){return prom_mat;}
    const float getProm_cien(){return prom_cien;}
    const float getProm_hist(){return prom_hist;}
    const float getProm_tecn(){return prom_tecn;}
    const float getProm_arte(){return prom_arte;}
    const float getProm_edfis(){return prom_edfis;}
    //const float getProm_gral(){return prom_gral;}
    //Funciones
private:
    int id;
    string nombre;
    float prom_leng;
    float prom_ing;
    float prom_mat;
    float prom_cien;
    float prom_hist;
    float prom_tecn;
    float prom_arte;
    float prom_edfis;
    //float prom_gral;
};


#endif //CODIGO_ESTUDIANTE_H
