#ifndef MENU_H
#define MENU_H
#include "ArrayPrisionero.h"
#include "Usuario.h"
#include "Prisionero.h"
class Menu
{
    public:
        void MenuPrincipal();
        void MenuPrisionero();
        void MenuGuardia();
    private:
        ArrayPrisionero p;
        Prisionero prisionero;
        Usuario x;
        int opcion;
};

#endif // MENU_H
