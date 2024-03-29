#include "Guardia.h"

Guardia::Guardia() : Persona()
{
    seccion="seccion";
    turno = "turno";
}
Guardia::Guardia(string codigo,string nombre,string apellido,string nacimiento,string dni,string seccion ,string turno) : Persona(codigo,nombre,apellido,nacimiento,dni)
{
    this->seccion=seccion;
    this->turno=turno;
}
string Guardia::GetSeccion()
{
    return seccion;
}
string Guardia::GetTurno()
{
    return turno;
}
void Guardia::SetTurno(string turno)
{
    this->turno=turno;
}
void Guardia::SetSeccion(string seccion)
{
    this->seccion=seccion;
}
void Guardia::MostrarDatos()
{
    Persona::MostarDatos();
    cout<<"Seccion: "<<seccion<<endl;
    cout<<"Turno: "<<turno<<endl;
}
void Guardia::SetDatos()
{
    Persona::SetDatos();
    cout<<"Nueva seccion: ";
    getline(cin,seccion);
    cout<<"Nuevo turno: ";
    getline(cin,turno);
}
