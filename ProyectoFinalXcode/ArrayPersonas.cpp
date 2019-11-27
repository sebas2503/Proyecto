//
//  ArrayPersonas.cpp
//  ProyectoFinalXcode
//
//  Created by Luis Sebastian Arroyo Pinto on 11/23/19.
//  Copyright © 2019 Luis Sebastian Arroyo Pinto. All rights reserved.
//
/*
#include <fstream>
#include <iostream>
#include "ArrayPersonas.h"
using namespace std;
template <typename L>
ArrayPersonas<L>::ArrayPersonas()
{
    tam=0;
    guardia = new L[tam];
}
template <typename L>
ArrayPersonas<L>::~ArrayPersonas()
{
    cout<<"Destructor invocado"<<endl;
    delete [] guardia;
}
template <typename L>
void ArrayPersonas<L>::RediArrPer(int x)
{
    tam=x;
    L *tmp = new L[tam];
    for(int i=0;i<tam;i++)
        tmp[i]=guardia[i];
    delete [] guardia;
    guardia=tmp;
}
template <typename L>
void ArrayPersonas<L>::AgregarPersona(L g)
{
    for(int i=0;i<tam;i++)
        while(guardia[i].GetCodigo()==g.GetCodigo())
        {
            cout<<"Ese codigo ya existe intente uno nuevo: ";
            string codigo;
            getline(cin,codigo);
            g.SetCodigo(codigo);
        }
    tam++;
    L *tmp= new L[tam];
    for(int i=0;i<tam-1;i++)
        tmp[i]=guardia[i];
    tmp[tam-1]=g;
    cout<<"\t\t\tRegistro Completado\t"<<endl;
    delete [] guardia;
    guardia=tmp;
}
template <typename L>
void ArrayPersonas<L>::EliminarPersona(string codigo)
{
    string verificador;
    string si("Si");
    for(int i=0;i<tam;i++)
    {
        if(guardia[i].GetCodigo() == codigo)
        {
            cout<<"Codigo: ";
            cout<<guardia[i].GetCodigo()<<endl;
            cout<<"Nombre: ";
            cout<<guardia[i].GetNombre()<<endl;
            cout<<"Apellido: ";
            cout<<guardia[i].GetApellido()<<endl;
            cout<<"Fecha de nacimiento: ";
            cout<<guardia[i].GetNacimiento()<<endl;
            cout<<"Dni: ";
            cout<<guardia[i].GetDni()<<endl;
            cout<<"Seccion: ";
            cout<<guardia[i].GetSeccion()<<endl;
            cout<<"Turno: ";
            cout<<guardia[i].GetTurno()<<endl;
            cout<<i<<endl;
            cout<<"Esta seguro que quiere eliminar a este guardia ";
            cout<<"Por favor ingrese un Si: ";
            getline(cin,verificador);
            if(verificador[0]==si[0] && verificador[1]==si[1])
            {
                for(int f=i;f<tam;f++)
                {
                    guardia[f]=guardia[f+1];
                }
                RediArrPer(--tam);
                cout<<"Guardia eliminado"<<endl;
            }
            else
                cout<<"Guardia no eliminado"<<endl;
        }
        else
        {
            cout<<"Ese codigo de guardia no existe"<<endl;
        }
    }
}
template <typename L>
void ArrayPersonas<L>::ModificarPersona(string codigo)
{
    bool encontrado=false;
    for(int i=0;i<tam;i++)
        if(guardia[i].GetCodigo() == codigo)
        {
            string nombre_;
            string apellido_;
            string nacimiento_;
            string dni_;
            string seccion_;
            string turno_;
            encontrado=true;
            cout<<"Ingrese el nuevo nombre del guardia: ";
            getline(cin,nombre_);
            cout<<"Ingrese el nuevo apellido del guardia: ";
            getline(cin,apellido_);
            cout<<"Ingrese la nueva fecha de nacimiento del guardia: ";
            getline(cin,nacimiento_);
            cout<<"Ingrese el nuevo dni del guardia: ";
            getline(cin,dni_);
            cout<<"Ingrese la nueva seccion del guardia: ";
            getline(cin,seccion_);
            cout<<"Ingrese el nuevo turno  del guardia: ";
            getline(cin,turno_);
            guardia[i].SetNombre(nombre_);
            guardia[i].SetApellido(apellido_);
            guardia[i].SetNacimiento(nacimiento_);
            guardia[i].Set(dni_);
            guardia[i].Set(seccion_);
            guardia[i].Set(turno_);
        }
        else
        {
            encontrado=false;
            cout<<"Ese codigo de guardia no existe"<<endl;
        }
}
template <typename L>
void ArrayPersonas<L>::MostrarArrPersona()
{
    if(tam==0)
    {
        cout<<"Array vacio"<<endl;
        return;
    }
    for(int i=0;i<tam;i++)
    {
        cout<<"Posicion: "<<i<<endl;
        cout<<"Codigo: ";
        cout<<guardia[i].GetCodigo()<<endl;
        cout<<"Nombre: ";
        cout<<guardia[i].GetNombre()<<endl;
        cout<<"Apellido: ";
        cout<<guardia[i].GetApellido()<<endl;
        cout<<"Fecha de nacimiento: ";
        cout<<guardia[i].GetNacimiento()<<endl;
        cout<<"Dni: ";
        cout<<guardia[i].GetDni()<<endl;
        cout<<"Seccion: ";
        cout<<guardia[i].GetSeccion()<<endl;
        cout<<"Turno: ";
        cout<<guardia[i].GetTurno()<<endl;
    }
}
template <typename L>
void ArrayPersonas<L>::SubiraFichero()
{
    ofstream archivo;
    archivo.open("/Users/luisarroyo/Desktop/XcodeProyecto/ProyectoFinalXcode/ProyectoFinalXcode/RegistroGuardia.txt",ios::trunc);
    if(archivo.is_open())
    {
        for(int i=0;i<tam;i++)
        {
            archivo<<guardia[i].GetCodigo()<<endl;
            archivo<<guardia[i].GetNombre()<<endl;
            archivo<<guardia[i].GetApellido()<<endl;
            archivo<<guardia[i].GetNacimiento()<<endl;
            archivo<<guardia[i].GetDni()<<endl;
            archivo<<guardia[i].GetSeccion()<<endl;
            archivo<<guardia[i].GetTurno()<<endl;
        }
        cout<<"Datos totalmente guardados"<<endl;
        archivo.close();
    }
    
}
template<typename L>
void ArrayPersonas<L>::LecturaArrPersona()
{
    string aux_codigo;
    string aux_nombre;
    string aux_apellido;
    string aux_nacimiento;
    string aux_dni;
    string aux_seccion;
    string aux_turno;
    ifstream lectura;
    lectura.open("/Users/luisarroyo/Desktop/XcodeProyecto/ProyectoFinalXcode/ProyectoFinalXcode/RegistroGuardia.txt",ios::in);
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
            getline(lectura,aux_seccion);
            getline(lectura,aux_turno);
            cout<<"Codigo: "<<aux_codigo<<endl;
            cout<<"Nombre: "<<aux_nombre<<endl;
            cout<<"Apellido: "<<aux_apellido<<endl;
            cout<<"Fecha de nacimiento: "<<aux_nacimiento<<endl;
            cout<<"Dni: "<<aux_dni<<endl;
            cout<<"Seccion: "<<aux_seccion<<endl;
            cout<<"Turno: "<<aux_turno<<endl;
            L a; a(aux_codigo,aux_nombre,aux_apellido,aux_nacimiento,aux_dni,aux_seccion,aux_turno);
            AgregarPersona(a);
            getline(lectura,aux_codigo);
        }
    }
    lectura.close();
}
template <typename L>
void ArrayPersonas<L>::OrdenarNombre()
{
    for(int i=0;i<tam-1;i++)
    {
        int f=0;
        int m=i;
        for(int j=i+1;j<tam;j++)
        {
            if (guardia[m].GetNombre() [f]>guardia[j].GetNombre() [f])
            {m=j;}
            L aux=guardia[m];
            guardia[m]=guardia[i];
            guardia[i]=aux;
            f++;
        }
    }
}
template <typename L>
void ArrayPersonas<L>::OrdenarApellido()
{
    for(int i=0;i<tam-1;i++)
    {
        int f=0;
        int x=i;
        for(int j=i+1;j<tam;j++)
        {
            if(guardia[x].GetApellido()[f]>guardia[j].GetApellido()[f])
                x=j;
            L aux= guardia[x];
            guardia[x]=guardia[i];
            guardia[i]=aux;
            f++;
        }
    }
}
template <typename L>
void ArrayPersonas<L>::BuscarPersona(string nombre)
{
    for(int i=0;i<tam;i++)
    {
        if(guardia[i].GetNombre().find(nombre)!=string::npos)
        {
            cout<<"\t\t\tPrisionero\t"<<endl;
            cout<<"Codigo: "<<guardia[i].GetCodigo()<<endl;
            cout<<"Nombre: "<<guardia[i].GetNombre()<<endl;
            cout<<"Apellido: "<<guardia[i].GetApellido()<<endl;
            cout<<"Fecha de nacimiento: "<<guardia[i].GetNacimiento()<<endl;
            cout<<"Dni: "<<guardia[i].GetDni()<<endl;
            cout<<"Seccion: "<<guardia[i].GetSeccion()<<endl;
            cout<<"Turno: "<<guardia[i].GetTurno()<<endl;
        }
    }
}
*/
