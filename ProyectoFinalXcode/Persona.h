#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;
#include <string.h>
class Persona
{
    public:
        Persona();
        Persona(string,string,string,string,string);
        Persona(Persona &copia);
        //Parte Setters
        void SetCodigo(string);
        void SetNombre(string);
        void SetApellido(string);
        void SetNacimiento(string);
        void SetDni(string);
        //Parte Getters
        string GetCodigo();
        string GetNombre();
        string GetApellido();
        string GetNacimiento();
        string GetDni();
    protected:
        string codigo;
        string nombre;
        string apellido;
        string nacimiento;
        string dni;
};

#endif // PERSONA_H
