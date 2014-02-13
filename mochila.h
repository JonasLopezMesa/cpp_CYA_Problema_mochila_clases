//
//  mochila.h
//  CYAFINAL_Clases
//
//  Created by Jonás López Mesa on 19/12/13.
//  Copyright (c) 2013 Jonás López Mesa. All rights reserved.
//

#ifndef __CYAFINAL_Clases__mochila__
#define __CYAFINAL_Clases__mochila__

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct OBJETOS { //estructura para almacenar el peso y el valor de los objetos.
    int peso_;
    int valor_;
};

class Mochila {
    int capacidad_; //Almacena la capacidad de la mochila
    int n_objetos_; //Almacena el número de objetos que se quieren introducir en la mochila
    vector<vector<int> > matriz_; //Matriz donde se almacenan las capacidades resultantes
    vector<OBJETOS> O_; //vector que almacena los objetos
    
    int max (int a, int b); //Método que calcula el máximo
    
public:
    Mochila(); //Constructor de la clase

    void print (); //Método que imprime por pantalla el resultado
    void algoritmo(); //Método que pone en marcha el algoritmo para resolver el problema
};
#endif /* defined(__CYAFINAL_Clases__mochila__) */
