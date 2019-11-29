//
//  ArrayPersonas.h
//  ProyectoFinalXcode
//
//  Created by Luis Sebastian Arroyo Pinto on 11/23/19.
//  Copyright © 2019 Luis Sebastian Arroyo Pinto. All rights reserved.
//

#ifndef ArrayPersonas_h
#define ArrayPersonas_h
#include <fstream>
#include <iostream>
#include <string.h>
#include "Guardia.h"
#include "Persona.h"
using namespace std;
template <class L>
class ArrayPersonas
{
    public:
        ArrayPersonas();
        ~ArrayPersonas();
        ArrayPersonas(ArrayPersonas &);
        //Parte Getter
        int GetTam();
        //Metodos
        void AgregarPersona(L);
        void EliminarPersona(string);
        void ModificarPersona(string);
        void SubiraFichero();
        void MostrarArrPersona();
        void LecturaArrPersona();
        void OrdenarNombre();
        void OrdenarApellido();
        void BuscarPersona(string);
    protected:
        int tam;
        L *guarpri;
        void RediArrPer(int);
};
template <typename L>
ArrayPersonas<L>::ArrayPersonas()
{
    tam=0;
    guarpri = new L[tam];
}
template <typename L>
ArrayPersonas<L>::~ArrayPersonas()
{
    cout<<"Destructor invocado"<<endl;
    delete [] guarpri;
}
template <typename L>
void ArrayPersonas<L>::RediArrPer(int x)
{
    tam=x;
    L *tmp = new L[tam];
    for(int i=0;i<tam;i++)
        tmp[i]=guarpri[i];
    delete [] guarpri;
    guarpri=tmp;
}
template <typename L>
void ArrayPersonas<L>::AgregarPersona(L g)
{
    for(int i=0;i<tam;i++)
        while(guarpri[i].GetCodigo()==g.GetCodigo())
        {
            cout<<"Ese codigo ya existe intente uno nuevo: ";
            string codigo;
            getline(cin,codigo);
            g.SetCodigo(codigo);
        }
    tam++;
    L *tmp= new L[tam];
    for(int i=0;i<tam-1;i++)
        tmp[i]=guarpri[i];
    tmp[tam-1]=g;
    delete [] guarpri;
    guarpri=tmp;
}
template <typename L>
void ArrayPersonas<L>::EliminarPersona(string codigo)
{
    string verificador;
    string si("Si");
    for(int i=0;i<tam;i++)
    {
        if(guarpri[i].GetCodigo() == codigo)
        {
            guarpri[i].MostrarDatos();
            cout<<"Esta seguro que quiere eliminar a este guardia ";
            cout<<"Por favor ingrese un Si: ";
            getline(cin,verificador);
            if(verificador[0]==si[0] && verificador[1]==si[1])
            {
                for(int f=i;f<tam;f++)
                {
                    guarpri[f]=guarpri[f+1];
                }
                RediArrPer(--tam);
                cout<<"Guardia eliminado"<<endl;
            }
            else
                cout<<"Guardia no eliminado"<<endl;
        }
    }
}
template <typename L>
void ArrayPersonas<L>::ModificarPersona(string codigo)
{
    bool encontrado=false;
    for(int i=0;i<tam;i++)
        if(guarpri[i].GetCodigo() == codigo)
        {
            encontrado=true;
            guarpri[i].SetDatos();
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
    cout<<"Datos"<<endl;
    for(int i=0;i<tam;i++)
    {
        guarpri[i].MostrarDatos();
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
            archivo<<guarpri[i].GetCodigo()<<endl;
            archivo<<guarpri[i].GetNombre()<<endl;
            archivo<<guarpri[i].GetApellido()<<endl;
            archivo<<guarpri[i].GetNacimiento()<<endl;
            archivo<<guarpri[i].GetDni()<<endl;
            archivo<<guarpri[i].GetSeccion()<<endl;
            archivo<<guarpri[i].GetTurno()<<endl;
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
            L x(aux_codigo,aux_nombre,aux_apellido,aux_nacimiento,aux_dni,aux_seccion,aux_turno);
            AgregarPersona(x);
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
            if (guarpri[m].GetNombre() [f]>guarpri[j].GetNombre() [f])
            {m=j;}
            L aux=guarpri[m];
            guarpri[m]=guarpri[i];
            guarpri[i]=aux;
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
            if(guarpri[x].GetApellido()[f]>guarpri[j].GetApellido()[f])
                x=j;
            L aux= guarpri[x];
            guarpri[x]=guarpri[i];
            guarpri[i]=aux;
            f++;
        }
    }
}
template <typename L>
void ArrayPersonas<L>::BuscarPersona(string nombre)
{
    for(int i=0;i<tam;i++)
    {
        if(guarpri[i].GetNombre().find(nombre)!=string::npos)
        {
            guarpri[i].MostrarDatos();
        }
    }
}
#endif /* ArrayPersonas_h */
