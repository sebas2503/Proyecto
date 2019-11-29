#include "Prisionero.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
Prisionero::Prisionero() : Persona()
{
    nivelPeligro="Nivel de Peligro";
    condena="Condena";
}
Prisionero::Prisionero(string codigo,string nombre,string apellido,string nacimiento,string dni,string nivelPeligro,string condena) : Persona(codigo,nombre,apellido,nacimiento,dni)
{
    this->nivelPeligro=nivelPeligro;
    this->condena=condena;
}
//Parte Setters
void Prisionero::SetNivelPeligro(string nivelPeligro)
{
    this->nivelPeligro=nivelPeligro;
}
void Prisionero::SetCondena(string condena)
{
    this->condena=condena;
}
//Parte Getters
string Prisionero::GetNivelPeligro()
{
    return nivelPeligro;
}
string Prisionero::GetCondena()
{
    return condena;
}
void Prisionero::MostarDatos()
{
    Persona::MostarDatos();
    cout<<"Nivel de Peligro: "<<nivelPeligro<<endl;
    cout<<"Condena: "<<condena<<endl;
}
void Prisionero::SetDatos()
{
    Persona::SetDatos();
    cout<<"Nuevo nivel de peligro: ";
    getline(cin,nivelPeligro);
    cout<<"Nueva condena: ";
    getline(cin,condena);
}
