#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int numeroA=0,numeroB=0;

    while(seguir=='s')
    {
        switch(menu(numeroA,numeroB))
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
            system("pause");
            break;

        case 4:

            funRestar(numeroA,numeroB);
            system("pause");
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

            system("pause");
            break;

        case 6:

            funMultiplicacion(numeroA,numeroB);
            system("pause");
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

            system("pause");
            break;

        case 8:

            todasLasOperaciones(numeroA,numeroB);
            system("pause");
            break;

        case 9:

            seguir = 'n';
            break;

        }

    }

    return 0;
}
