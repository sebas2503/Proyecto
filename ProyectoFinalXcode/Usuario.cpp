#include "Usuario.h"
Prisionero Usuario::PedirDatosPrisionero()
{
    cin.ignore();
    cout<<"\t\t\tRegistrando Prisionero\t"<<endl;
    cout<<"Codigo: ";
    getline(cin,codigo);
    cout<<"Nombre: ";
    getline(cin,nombre);
    cout<<"Apellido: ";
    getline(cin,apellido);
    cout<<"Fecha de Nacimiento: ";
    getline(cin,nacimiento);
    cout<<"Dni: ";
    getline(cin,dni);
    cout<<"Nivel de Peligro: ";
    getline(cin,nivelPeligro);
    cout<<"Condena: ";
    getline(cin,condena);
    Prisionero y(codigo,nombre,apellido,nacimiento,dni,nivelPeligro,condena);
    return y;
}
string Usuario::ModificarDatosPrisionero()
{
    string codigo_;
    cout<<"Ingrese el codigo del prisionero que quiera modificar: ";
    cin.ignore();
    getline(cin,codigo_);
    return codigo_;
}
string Usuario::EliminarDatosPrisionero()
{
    string aux_codigo;
    cin.ignore();
    cout<<"Ingrese el codigo del prisionero a eliminar: ";
    getline(cin,aux_codigo);
    return aux_codigo;
}
string Usuario::BuscarPrisionero()
{
    string aux_nombre;
    cin.ignore();
    cout<<"Ingrese el nombre del prisionero: ";
    getline(cin,aux_nombre);
    return aux_nombre;
}
Guardia Usuario::PedirDatosPersona()
{
    cin.ignore();
    cout<<"\t\t\tRegistrando Guardia\t"<<endl;
    cout<<"Codigo: ";
    getline(cin,codigo);
    cout<<"Nombre: ";
    getline(cin,nombre);
    cout<<"Apellido: ";
    getline(cin,apellido);
    cout<<"Fecha de Nacimiento: ";
    getline(cin,nacimiento);
    cout<<"Dni: ";
    getline(cin,dni);
    cout<<"Seccion: ";
    getline(cin,seccion);
    cout<<"Turno: ";
    getline(cin,turno);
    Guardia g(codigo,nombre,apellido,nacimiento,dni,seccion,turno);
    return g;
}
string Usuario::BuscarPersona()
{
    string aux_nombre;
    cin.ignore();
    cout<<"Ingrese el nombre de la persona: ";
    getline(cin,aux_nombre);
    return aux_nombre;
}
string Usuario::ModificarPersona()
{
    string aux_codigo;
    cin.ignore();
    cout<<"Ingrese el codigo de la persona: ";
    getline(cin,aux_codigo);
    return aux_codigo;
}
string Usuario::EliminarPersona()
{
    string aux_codigo;
    cin.ignore();
    cout<<"Ingrese el codigo de la persona: ";
    getline(cin,aux_codigo);
    return aux_codigo;
}
