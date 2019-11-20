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
        cout<<"5. Guardar datos"<<endl;
        cout<<"6. Mostrar los datos en el archivo"<<endl;
        cout<<"7. Ordenar(Apellido)"<<endl;
        cout<<"8. Salir"<<endl;
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
                prisionero=x.PedirDatosPrisionero();
                p.AgregarPrisionero(prisionero);
                break;
            }
            case 2:
            {
                system("clear");
                string aux=x.ModificarDatosPrisionero();
                p.ModificarPrisionero(aux);
                break;
            }
            case 3:
            {
                system("clear");
                string aux=x.EliminarDatosPrisionero();
                p.EliminarPrisionero(aux);
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
                p.SubiraFichero();
                break;
            }
            case 6:
            {
                system("clear");
                p.LecturaArrPrisionero();
                break;
            }
            case 7:
            {
                p.OrdenarApellido();
                break;
            }
            case 8:
            {
                system("clear");
                p.SubiraFichero();
                break;
            }
        }
    }
    while(opcion !=8);
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
