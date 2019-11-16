#include "ArrayPrisionero.h"
#include <iostream>
using namespace std;
ArrayPrisionero::ArrayPrisionero()
{
    size1=0;
    arr= new Prisionero[0];
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
void ArrayPrisionero::APrisionero(Prisionero x)
{
    RediArrP(++size1);
    arr[size1-1]=x;
}
void ArrayPrisionero::EPrisionero(int pos)
{
    for(int i=pos;i<size1;i++)
        {
            arr[i]=arr[i+1];
        }
    RediArrP(--size1);
}
void ArrayPrisionero::MPrisionero(int pos)
{
    arr[pos].SetNombre("Pedro");
}
void ArrayPrisionero::MostrarArrP()
{
    for(int i=0;i<size1;i++)
        cout<<arr[i].GetNombre()<<endl;
}
