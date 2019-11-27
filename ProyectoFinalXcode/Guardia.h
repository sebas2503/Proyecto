#ifndef GUARDIA_H
#define GUARDIA_H
#include "Persona.h"
#include <iostream>
#include <string.h>
using namespace std;
class Guardia : public Persona
{
    public:
        Guardia();
        Guardia(string,string,string,string,string,string,string);
        //Parte Setters
        void SetSeccion(string);
        void SetTurno(string);
        //Parte Getters
        string GetSeccion();
        string GetTurno();
    private:
    string seccion,turno;
};

#endif // GUARDIA_H
