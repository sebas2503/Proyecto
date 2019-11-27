#ifndef MENU_H
#define MENU_H
#include "ArrayPersonas.h"
#include "ArrayPrisionero.h"
#include "Usuario.h"
#include "Prisionero.h"
#include "Guardia.h"
class Menu
{
    public:
        void MenuPrincipal();
        void MenuPrisionero();
        void MenuGuardia();
    private:
        typedef ArrayPersonas<Guardia> gp;
        gp gx;
        ArrayPrisionero p;
        Prisionero prisionero;
        Guardia guar;
        Usuario x;
        int opcion;
};

#endif // MENU_H
