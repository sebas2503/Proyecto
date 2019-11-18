#include "Menu.h"
#include <stdlib.h>
void Menu::MenuPrisionero()
{
    do
    {
        cout<<"\t\t\tAccediendo a Prisioneros\t\n"<<endl;
        cout<<"1. Registrar"<<endl;
        cout<<"2. Modificar"<<endl;
        cout<<"3. Eliminar"<<endl;
        cout<<"4. Mostrar lista"<<endl;
        cout<<"5. Volver al menu principal"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch(opcion)
        {
            default:
            {
                system("clear");
                cout<<"Opcion invalida"<<endl;
                break;
            }
            case 1:
            {
                system("clear");
                p.AgregarPrisionero(x.PedirDatosPrisionero());
                break;
            }
            case 2:
            {
                system("clear");
                p.ModificarPrisionero(x.ModificarDatosPrisionero());
                break;
            }
            case 3:
            {
                system("clear");
                p.EliminarPrisionero(x.EliminarDatosPrisionero());
                break;
            }
            case 4:
            {
                system("clear");
                p.MostrarArrPrisionero();
                break;
            }
            case 5:
            {
                system("clear");
                p.LecturaArrPrisionero();
                break;
            }
        }
    }
    while(opcion !=5);
}
void Menu::MenuGuardia()
{
    cout<<"No funciona no entiendes bro"<<endl;
}
void Menu::MenuPrincipal()
{
    do
    {
        cout<<"\t\t\tBienvenido a Arkham\t\n"<<endl;
        cout<<"1. Prisioneros"<<endl;
        cout<<"2. Guardia//De momento sin funcionar"<<endl;
        cout<<"3. Salir\n"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch(opcion)
        {
            default:
            {
                system("clear");
                cout<<"Opcion invalida"<<endl;
                break;
            }
            case 1:
            {
                system("clear");
                MenuPrisionero();
                break;
            }
            case 2:
            {
                system("clear");
                MenuGuardia();
                break;
            }
            case 3:
            {
                system("clear");
                cout<<"\t\t\tGracias por usar Arkham\t\n\n";
                break;
            }
        }

    }
    while(opcion !=3);
}
