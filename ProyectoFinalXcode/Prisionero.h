#ifndef PRISIONERO_H
#define PRISIONERO_H
#include <iostream>
#include <string.h>
#include "Persona.h"
using namespace std;
class Prisionero : public Persona
{
    public:
        Prisionero();
        Prisionero(string,string,string,string,string,string,string);
        Prisionero(Prisionero &copia) : Persona(copia)
        {
            nivelPeligro=copia.nivelPeligro;
            condena=copia.condena;
        }
        //Parte Setters
        void SetNivelPeligro(string);
        void SetCondena(string);
        //Parte Getters
        string GetNivelPeligro();
        string GetCondena();
        //Parte Metodo
        void MostarDatos();
        void SetDatos();
        void SubiraFichero();
    private:
        string nivelPeligro;
        string condena;
};

#endif // PRISIONERO_H
