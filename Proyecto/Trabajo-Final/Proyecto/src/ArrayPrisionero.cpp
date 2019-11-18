#include "ArrayPrisionero.h"
#include <fstream>
#include <iostream>
using namespace std;
ArrayPrisionero::ArrayPrisionero()
{
    size1=0;
    arr= new Prisionero[size1];
}
ArrayPrisionero::ArrayPrisionero(Prisionero p[],int size1)
{
    this->size1=size1;
    arr= new Prisionero[size1];
    for(int i=0;i<size1;i++)
        arr[i]=p[i];
}
ArrayPrisionero::ArrayPrisionero(ArrayPrisionero &p)
{
    size1=p.size1;
    arr= new Prisionero[p.size1];
    for(int i=0;i<p.size1;i++)
        arr[i]=p.arr[i];
}
ArrayPrisionero::~ArrayPrisionero()
{
    cout<<"Destructor Invocado"<<endl;
    delete [] arr;
}
int ArrayPrisionero::GetSize()
{
    return size1;
}
void ArrayPrisionero::RediArrP(int x)
{
    size1=x;
    Prisionero *aux= new Prisionero[size1];
    for(int i=0;i<size1;i++)
        aux[i]=arr[i];
    delete [] arr;
    arr=aux;
}
void ArrayPrisionero::AgregarPrisionero(Prisionero x)
{
    RediArrP(++size1);
    arr[size1-1]=x;
}
void ArrayPrisionero::EliminarPrisionero(string aux_codigo)
{
    string verificacion;
    string si("Si");
    for(int i=0;i<size1;i++)
    {
        if(arr[i].GetCodigo() == aux_codigo)
        {
            cout<<"Codigo: ";
            cout<<arr[i].GetCodigo()<<endl;
            cout<<"Nombre: ";
            cout<<arr[i].GetNombre()<<endl;
            cout<<"Apellido: ";
            cout<<arr[i].GetApellido()<<endl;
            cout<<"Fecha de nacimiento: ";
            cout<<arr[i].GetNacimiento()<<endl;
            cout<<"Dni: ";
            cout<<arr[i].GetDni()<<endl;
            cout<<"Nivel de peligro: ";
            cout<<arr[i].GetNivelPeligro()<<endl;
            cout<<"Condena: ";
            cout<<arr[i].GetCondena()<<endl;
            cout<<"Esta seguro que quiere eliminar a este prisionero ";
            cout<<"Por favor ingrese un Si: ";
            getline(cin,verificacion);
            if(verificacion[0]==si[0] && verificacion[1]==si[1])
            {
                cout<<"Prisionero eliminado"<<endl;
                for(int f=i;f<size1;f++)
                {
                    arr[f]=arr[f+1];
                }
                RediArrP(--size1);
            }
            else
            {
                cout<<"Prisionero no eliminado"<<endl;
            }
        }
        else
        {
            cout<<"Ese codigo de prisionero no existe"<<endl;
        }
    }
}
void ArrayPrisionero::ModificarPrisionero(string codigo_)
{
    bool encontrado=false;
    for(int i=0;i<size1;i++)
        if(arr[i].GetCodigo() == codigo_)
        {
            string nombre_;
            string apellido_;
            string nacimiento_;
            string dni_;
            string nivelPeligro_;
            string condena_;
            encontrado=true;
            cout<<"Ingrese el nuevo nombre del prisionero: ";
            getline(cin,nombre_);
            cout<<"Ingrese el nuevo apellido del prisionero: ";
            getline(cin,apellido_);
            cout<<"Ingrese la nueva fecha de nacimiento del prisionero: ";
            getline(cin,nacimiento_);
            cout<<"Ingrese el nuevo dni del prisionero: ";
            getline(cin,dni_);
            cout<<"Ingrese el nuevo nivel de peligro del prisionero: ";
            getline(cin,nivelPeligro_);
            cout<<"Ingrese la nueva condena del prisionero: ";
            getline(cin,condena_);
            arr[i].SetNombre(nombre_);
            arr[i].SetApellido(apellido_);
            arr[i].SetNacimiento(nacimiento_);
            arr[i].SetDni(dni_);
            arr[i].SetNivelPeligro(nivelPeligro_);
            arr[i].SetCondena(condena_);
        }
        else
        {
            encontrado=false;
            cout<<"Ese codigo de prisionero no existe"<<endl;
        }
}
void ArrayPrisionero::MostrarArrPrisionero()
{
    if(size1==0)
    {
        cout<<"Array vacio"<<endl;
        return;
    }
    for(int i=0;i<size1;i++)
    {
        cout<<"Posicion: "<<i<<endl;
        cout<<"Codigo: ";
        cout<<arr[i].GetCodigo()<<endl;
        cout<<"Nombre: ";
        cout<<arr[i].GetNombre()<<endl;
        cout<<"Apellido: ";
        cout<<arr[i].GetApellido()<<endl;
        cout<<"Fecha de nacimiento: ";
        cout<<arr[i].GetNacimiento()<<endl;
        cout<<"Dni: ";
        cout<<arr[i].GetDni()<<endl;
        cout<<"Nivel de peligro: ";
        cout<<arr[i].GetNivelPeligro()<<endl;
        cout<<"Condena: ";
        cout<<arr[i].GetCondena()<<endl;
    }
}
void ArrayPrisionero::SubiraFichero()
{
    ofstream archivo;
    archivo.open("/Users/luisarroyo/Documents/Proyecto/Trabajo-Final/Proyecto/RegistroPrisionero.txt",ios::trunc);
    for(int i=0;i<size1;i++)
    {
        archivo<<arr[i].GetCodigo()<<endl;
        archivo<<arr[i].GetNombre()<<endl;
        archivo<<arr[i].GetApellido()<<endl;
        archivo<<arr[i].GetNacimiento()<<endl;
        archivo<<arr[i].GetDni()<<endl;
        archivo<<arr[i].GetNivelPeligro()<<endl;
        archivo<<arr[i].GetCondena()<<endl;
    }
    archivo.close();
}
void ArrayPrisionero::LecturaArrPrisionero()
{
    string codigo;
    ifstream lectura;
    lectura.open("/Users/luisarroyo/Documents/Proyecto/Trabajo-Final/Proyecto/RegistroPrisionero.txt",ios::in);
    if(lectura.is_open())
    {
        while(!lectura.eof())
        {
            lectura>>codigo;
            cout<<codigo<<endl;
        }
    }
    lectura.close();
}
