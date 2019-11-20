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
    cout<<"\t\t\tRegistro completado\t"<<endl;
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
