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
