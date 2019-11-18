#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string.h>
#include <Prisionero.h>
using namespace std;
class Usuario
{
    public:
        Prisionero PedirDatosPrisionero();
        string ModificarDatosPrisionero();
        string EliminarDatosPrisionero();
    private:
        string codigo;
        string nombre;
        string apellido;
        string nacimiento;
        string dni;
        string nivelPeligro;
        string condena;
};

#endif // USUARIO_H
