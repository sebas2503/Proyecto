#ifndef ARRAYPRISIONERO_H
#define ARRAYPRISIONERO_H
#include <Prisionero.h>
class ArrayPrisionero
{
    public:
        ArrayPrisionero();
        ArrayPrisionero(Prisionero[],int);
        ~ArrayPrisionero();
        ArrayPrisionero(ArrayPrisionero &a);
        //Parte Getters
        int GetSize();
        void APrisionero(Prisionero);
        void EPrisionero(int);
        void MPrisionero(int);
        void MostrarArrP();
    private:
        Prisionero *arr;
        int size1;
        void RediArrP(int);
};

#endif // ARRAYPRISIONERO_H
