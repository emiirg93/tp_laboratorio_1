#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "FuncionesEmiliano.h"
#define CANT 20

int main()
{
    ePersona persona[CANT];
    inicializarStruct(persona,CANT);

    int salir = 0;

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            alta(persona,CANT);
            break;
        case 2:
            system("cls");
            borrarPersona(persona,CANT);
            getch();
            break;
        case 3:
            system("cls");
            ordenarLista(persona,CANT);
            getch();
            break;
        case 4:
            system("cls");
            graficoEdades(persona,CANT);
            getch();
            break;
        case 5:
            salir = 1;
            break;
        default:
            printf("Ingrese una opcion entre 1 y 5\n");
            system("pause");
            break;
        }
    }while(salir == 0);

    return 0;
}

