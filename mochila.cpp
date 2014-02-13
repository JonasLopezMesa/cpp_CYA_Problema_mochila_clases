//
//  mochila.cpp
//  CYAFINAL_Clases
//
//  Created by Jonás López Mesa on 19/12/13.
//  Copyright (c) 2013 Jonás López Mesa. All rights reserved.
//

#include "mochila.h"

int Mochila::max (int a, int b){
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
void Mochila::print (){
    for (int i = 0; i < matriz_[0].size(); i++) {
        cout << i << "\t";
    }
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < matriz_.size(); i++) {
        for (int j = 0; j < matriz_[i].size(); j++) {
            cout << matriz_[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "RESULTADO: " << matriz_[n_objetos_-1][capacidad_] << endl;
}

Mochila::Mochila(){
    ifstream fichero ("datos.dt");
    if (fichero.is_open()) {
        fichero >> capacidad_;
        fichero >> n_objetos_;
        O_.resize(n_objetos_);
        for (int i = 0; i < n_objetos_; i++) {
            fichero >> O_[i].peso_ >> O_[i].valor_;
        }
    }
}
void Mochila::algoritmo(){
    matriz_.resize(n_objetos_);
    for (int i = 0; i < matriz_.size(); i++) {
        matriz_[i].resize(capacidad_+1);
    }
    for (int cap = 1; cap < capacidad_+1; cap++) {
        matriz_[0][cap] = 1;
    }
    for (int elem = 1; elem < n_objetos_; elem++ ) {
        matriz_[elem][0] = 0;
        for (int cap = 1; cap < capacidad_+1; cap++) {
            if (cap < O_[elem].peso_) {
                matriz_[elem][cap] = matriz_[elem-1][cap];
            } else {
                matriz_[elem][cap] = max(matriz_[elem-1][cap], O_[elem].valor_ + matriz_[elem-1][cap - O_[elem].peso_]);
            }
        }
    }
}