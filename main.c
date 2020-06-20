#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"

void password();



int main()
{
    //clave: gisela

    password();

    return 0;
}



void password()
{
    char contra[10] = {"gisela"}, intento[10];

    printf("\n- INGRESE LA CONTRASE%cA PARA INGRESAR AL SISTEMA -\n\n",165);
    printf("\tClave: ");
    fflush(stdin);
    gets(intento);

    while(strcmp(intento,contra) != 0)
    {
        system("cls");
        printf("\nLa clave ingresada es incorrecta. Intente nuevamente: ");
        fflush(stdin);
        gets(intento);
    }

    system("cls");
    Sleep(1000);
    printf("\nAccediendo...\n\n\n\n\n\n\n");
    Sleep(800);
    system("pause");
    system("cls");

    menuPrincipal();
}
