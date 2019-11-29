#include "Menu.h"
#include <stdlib.h>
void Menu::MenuPrisionero()
{
    p.LecturaArrPrisionero();
    do
    {
        cout<<"\t\t\tAccediendo a Prisioneros\t\n"<<endl;
        cout<<"1. Registrar"<<endl;
        cout<<"2. Modificar"<<endl;
        cout<<"3. Eliminar"<<endl;
        cout<<"4. Mostrar lista"<<endl;
        cout<<"5. Guardar datos"<<endl;
        cout<<"6. Ordenar"<<endl;
        cout<<"7. Buscar Prisionero"<<endl;
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
                SubMenuPrisionero();
                break;
            }
            case 7:
            {
                system("clear");
                string aux=x.BuscarPrisionero();
                p.BuscarPrisionero(aux);
                break;
            }
            case 8:
            {
                p.SubiraFichero();
                break;
            }
        }
    }
    while(opcion !=8);
}
void Menu::MenuGuardia()
{
    gx.LecturaArrPersona();
    do
    {
        cout<<"\t\t\tAcceciendo Guardias\t\n"<<endl;
        cout<<"1. Registrar"<<endl;
        cout<<"2. Modificar"<<endl;
        cout<<"3. Eliminar"<<endl;
        cout<<"4. Mostrar lista"<<endl;
        cout<<"5. Guardar datos"<<endl;
        cout<<"6. Ordenar"<<endl;
        cout<<"7. Buscar Guardia"<<endl;
        cout<<"8. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch (opcion)
        {
            default:
            {
                cout<<"Opcion invalida"<<endl;
                break;
            }
            case 1:
            {
                system("clear");
                guar=x.PedirDatosPersona();
                gx.AgregarPersona(guar);
                break;
            }
            case 2:
            {
                system("clear");
                string aux=x.ModificarPersona();
                gx.ModificarPersona(aux);
                break;
            }
            case 3:
            {
                system("clear");
                string aux=x.EliminarPersona();
                gx.EliminarPersona(aux);
                break;
            }
            case 4:
            {
                system("clear");
               gx.MostrarArrPersona();
                break;
            }
            case 5:
            {
                system("clear");
                gx.SubiraFichero();
                break;
            }
            case 6:
            {
                system("clear");
                SubMenuGuardia();
                break;
            }
            case 7:
            {
                system("clear");
                string aux=x.BuscarPersona();
                gx.BuscarPersona(aux);
                break;
            }
            case 8:
            {
                gx.SubiraFichero();
                break;
            }
        }
    }
    while(opcion!=8);
}
void Menu::SubMenuGuardia()
{
    do
    {
        cout<<"1. Por nombre"<<endl;
        cout<<"2. Por apellido"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch (opcion) {
            case 1:
            {
                system("clear");
                gx.OrdenarNombre();
                gx.MostrarArrPersona();
                break;
            }
            case 2:
            {
                system("clear");
                gx.OrdenarApellido();
                gx.MostrarArrPersona();
            }
            case 3:
            {
                break;
            }
            default:
            {
                cout<<"Opcion invalida"<<endl;
                break;
            }
        }
    }
    while(opcion!=3);
}
void Menu::SubMenuPrisionero()
{
    do
    {
        cout<<"1. Por nombre"<<endl;
        cout<<"2. Por apellido"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch (opcion)
        {
            case 1:
            {
                system("clear");
                p.OrdenarNombre();
                p.MostrarArrPrisionero();
                break;
            }
            case 2:
            {
                system("clear");
                p.OrdenarApellido();
                p.MostrarArrPrisionero();
            }
            case 3:
            {
                break;
            }
            default:
            {
                cout<<"Opcion invalida"<<endl;
                break;
            }
        }
    }
    while(opcion!=3);
}
void Menu::MenuPrincipal()
{
    do
    {
        cout<<"\t\t\tBienvenido a Arkham\t\n"<<endl;
        cout<<"1. Prisioneros"<<endl;
        cout<<"2. Guardias"<<endl;
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
