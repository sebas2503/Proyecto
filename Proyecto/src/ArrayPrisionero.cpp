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
    for(int i=0;i<size1;i++)
        while(arr[i].GetCodigo()==x.GetCodigo())
        {
            cout<<"Ese codigo ya existe intente uno nuevo: ";
            string codigo;
            getline(cin,codigo);
            x.SetCodigo(codigo);
        }
    size1++;
    Prisionero *tmp= new Prisionero[size1];
    for(int i=0;i<size1-1;i++)
        tmp[i]=arr[i];
    tmp[size1-1]=x;
    delete [] arr;
    arr=tmp;
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
                for(int f=i;f<size1;f++)
                {
                    arr[f]=arr[f+1];
                }
                RediArrP(--size1);
                cout<<"Prisionero eliminado"<<endl;
            }
            else
                cout<<"Prisionero no eliminado"<<endl;
        }
    }
}
void ArrayPrisionero::ModificarPrisionero(string codigo_)
{
    bool encontrado=false;
    for(int i=0;i<size1;i++)
        if(arr[i].GetCodigo() == codigo_)
        {
            encontrado=true;
            arr[i].SetDatos();
        }
}
void ArrayPrisionero::MostrarArrPrisionero()
{
    if(size1==0)
    {
        cout<<"Array vacio"<<endl;
        return;
    }
    cout<<"Datos"<<endl;
    for(int i=0;i<size1;i++)
    {
        arr[i].MostarDatos();
    }
}
void ArrayPrisionero::SubiraFichero()
{
    ofstream archivo;
    archivo.open("RegistroPrisionero.txt",ios::trunc);
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
    cout<<"Datos totalmente guardados"<<endl;
    archivo.close();
}
void ArrayPrisionero::LecturaArrPrisionero()
{
    string aux_codigo;
    string aux_nombre;
    string aux_apellido;
    string aux_nacimiento;
    string aux_dni;
    string aux_nivelPeligro;
    string aux_condena;
    ifstream lectura;
    lectura.open("RegistroPrisionero.txt",ios::in);
    if(lectura.is_open())
    {
        lectura.seekg(0);
        getline(lectura,aux_codigo);
        while(!lectura.eof())
        {
            getline(lectura,aux_nombre);
            getline(lectura,aux_apellido);
            getline(lectura,aux_nacimiento);
            getline(lectura,aux_dni);
            getline(lectura,aux_nivelPeligro);
            getline(lectura,aux_condena);
            Prisionero prisionero(aux_codigo,aux_nombre,aux_apellido,aux_nacimiento,aux_dni,aux_nivelPeligro,aux_condena);
            AgregarPrisionero(prisionero);
            getline(lectura,aux_codigo);
        }
    }
    lectura.close();
}
void ArrayPrisionero::OrdenarNombre()
{
    for(int i=0;i<size1-1;i++)
    {
        int f=0;
        int m=i;
        for(int j=i+1;j<size1;j++)
        {
            if (arr[m].GetNombre() [f]>arr[j].GetNombre() [f])
            {m=j;}
            Prisionero aux=arr[m];
            arr[m]=arr[i];
            arr[i]=aux;
            f++;
        }
    }
}
void ArrayPrisionero::OrdenarApellido()
{
    for(int i=0;i<size1-1;i++)
    {
        int f=0;
        int x=i;
        for(int j=i+1;j<size1;j++)
        {
            if(arr[x].GetApellido()[f]>arr[j].GetApellido()[f])
                x=j;
            Prisionero aux= arr[x];
            arr[x]=arr[i];
            arr[i]=aux;
            f++;
        }
    }
}
void ArrayPrisionero::BuscarPrisionero(string nombre)
{
    for(int i=0;i<size1;i++)
    {
        if(arr[i].GetNombre().find(nombre)!=string::npos)
        {
            arr[i].MostarDatos();
        }
    }
}
