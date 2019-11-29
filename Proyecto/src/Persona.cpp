#include "Persona.h"
#include <fstream>
Persona::Persona()
{
    codigo="Codigo";
    nombre="Nombre";
    apellido="Apellido";
    nacimiento="Fecha Nacimiento";
    dni="Dni";
}
Persona::Persona(string codigo,string nombre,string apellido,string nacimiento,string dni)
{
    this->codigo=codigo;
    this->nombre=nombre;
    this->apellido=apellido;
    this->nacimiento=nacimiento;
    this->dni=dni;
}
Persona::Persona(Persona &copia)
{
    codigo=copia.codigo;
    nombre=copia.nombre;
    apellido=copia.apellido;
    nacimiento=copia.nacimiento;
    dni=copia.dni;
}
//Parte Setters
void Persona::SetCodigo(string codigo)
{
    this->codigo=codigo;
}
void Persona::SetNombre(string nombre)
{
    this->nombre=nombre;
}
void Persona::SetApellido(string apellido)
{
    this->apellido=apellido;
}
void Persona::SetNacimiento(string nacimiento)
{
    this->nacimiento=nacimiento;
}
void Persona::SetDni(string dni)
{
    this->dni=dni;
}
//Parte Getters
string Persona::GetCodigo()
{
    return codigo;
}
string Persona::GetNombre()
{
    return nombre;
}
string Persona::GetApellido()
{
    return apellido;
}
string Persona::GetNacimiento()
{
    return nacimiento;
}
string Persona::GetDni()
{
    return dni;
}
void Persona::MostarDatos()
{
    cout<<"Codigo: "<<codigo<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Fecha de Nacimiento: "<<nacimiento<<endl;
    cout<<"Dni: "<<dni<<endl;
}
void Persona::SetDatos()
{
    cout<<"Nuevo nombre: ";
    getline(cin,nombre);
    cout<<"Nuevo apellido: ";
    getline(cin, apellido);
    cout<<"Nueva fecha de nacimiento: ";
    getline(cin,nacimiento);
    cout<<"Nuevo dni: ";
    getline(cin,dni);
}
