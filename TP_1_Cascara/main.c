#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    int numeroA = 0,numeroB = 0;
    int salir = 0;

    do
    {
        switch(menuPrincipal(numeroA,numeroB))
        {

        case 1:

            numeroA=ingresarNumero("Ingrese el primer numero : ");
            if(numeroA == 0)
            {
                numeroB=funIngresarNuevo(numeroB,"Usted ha ingresado el numero 0.\nTenga en cuenta que si deja este numero no podra realizar la operacion 8(factorial).\n\n");
            }
            break;

        case 2:

            numeroB=ingresarNumero("Ingrese el segundo numero : ");
            if(numeroB == 0)
            {
                numeroB=funIngresarNuevo(numeroB,"Usted ha ingresado el numero 0.\nTenga en cuenta que si deja este numero no podra realizar la operacion 5(division).\n\n");
            }
            break;

        case 3:

            funSumar(numeroA,numeroB);
            getch();
            break;

        case 4:

            funRestar(numeroA,numeroB);
            getch();
            break;

        case 5:

            if(numeroB != 0)
            {
                funDividir(numeroA,numeroB);
            }
            else
            {
                printf("No se puede realizar esta operacion.");
            }

            getch();
            break;

        case 6:

            funMultiplicacion(numeroA,numeroB);
            getch();
            break;

        case 7:

            if(numeroA != 0)
            {
                funFactorial(numeroA);
            }
            else
            {
                printf("No se puede realizar esta operacion.");
            }

            getch();
            break;

        case 8:

            todasLasOperaciones(numeroA,numeroB);
            getch();
            break;

        case 9:

            salir = 1;
            break;

        default :

            printf("Ingrese una opcion entre 1 y 9\n");
            system("pause");
            break;

        }

    }while(salir != 1);

    return 0;
}
