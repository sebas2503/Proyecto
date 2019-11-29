#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string.h>
#include "Guardia.h"
#include "ArrayPersonas.h"
#include "Prisionero.h"
using namespace std;
class Usuario
{
    public:
        //Prisionero
        Prisionero PedirDatosPrisionero();
        string ModificarDatosPrisionero();
        string EliminarDatosPrisionero();
        string BuscarPrisionero();
        //Persona(Guardia)
        Guardia PedirDatosPersona();
        string BuscarPersona();
        string EliminarPersona();
        string ModificarPersona();

    private:
        Guardia g;
        Prisionero y;
        string nombre;
        string apellido;
        string nacimiento;
        string dni;
        string nivelPeligro;
        string condena;
        string codigo;
        string seccion;
        string turno;
};

#endif // USUARIO_H
