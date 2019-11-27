//
//  Visitas.hpp
//  ProyectoFinalXcode
//
//  Created by Luis Sebastian Arroyo Pinto on 11/25/19.
//  Copyright © 2019 Luis Sebastian Arroyo Pinto. All rights reserved.
//

#ifndef Visitas_hpp
#define Visitas_hpp
#include <iostream>
#include <stdio.h>
using namespace std;
class Visitas
{
private:
    string codigo;
    bool encontrado=false;
public:
    Visitas();
    ~Visitas();
    //void BuscarPrisionero();
    void AsignarGuardia();
    void RegistrarVisitas();
    
};
#endif /* Visitas_hpp */
