#include <stdio.h>
#include <stdlib.h>

void menu()
{
    char opcion;
    int numeroA=0,numeroB=0;
    int salir=0;

    do
    {

        system("cls");

        printf("1- Ingresar 1er operando (A=%d)\n",numeroA);
        printf("2- Ingresar 2do operando (B=%d)\n",numeroB);
        printf("3- Calcular la suma (%d+%d)\n",numeroA,numeroB);
        printf("4- Calcular la resta (%d-%d)\n",numeroA,numeroB);
        printf("5- Calcular la division (%d/%d)\n",numeroA,numeroB);
        printf("6- Calcular la multiplicacion (%d*%d)\n",numeroA,numeroB);
        printf("7- Calcular el factorial (%d!)\n",numeroA);
        printf("8- Calcular todas las operaciones.\n");
        printf("9- Salir\n\nIngrese una opcion : ");

        scanf("%s",&opcion);

        switch(opcion)
        {

        case '1':

            numeroA=ingresarNumero("Ingrese el primer numero : ");
            if(numeroA == 0)
            {
                numeroB=funIngresarNuevo(numeroB,"Usted ha ingresado el numero 0.\nTenga en cuenta que si deja este numero no podra realizar la operacion 8(factorial).\n\n");
            }
            break;

        case '2':

            numeroB=ingresarNumero("Ingrese el segundo numero : ");
            if(numeroB == 0)
            {
                numeroB=funIngresarNuevo(numeroB,"Usted ha ingresado el numero 0.\nTenga en cuenta que si deja este numero no podra realizar la operacion 5(division).\n\n");
            }
            break;

        case '3':

            funSumar(numeroA,numeroB);
            getch();
            break;

        case '4':

            funRestar(numeroA,numeroB);
            getch();
            break;

        case '5':

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

        case '6':

            funMultiplicacion(numeroA,numeroB);
            getch();
            break;

        case '7':

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

        case '8':

            todasLasOperaciones(numeroA,numeroB);
            getch();
            break;
        case '9':

            salir = 1;
            break;


        default:
            printf("Ingreso una opcion incorrecta.");
            getch();
            break;
        }

    }
    while(salir != 1);

}

int ingresarNumero (char texto[])
{
    int numero;

    system("cls");

    printf(texto);
    scanf("%d",&numero);

    return numero;
}

void funSumar(int a,int b)
{
    int resultado;

    resultado=a+b;

    printf("El resultado de la suma entre %d+%d es : %d\n",a,b,resultado);
}

void funRestar(int a,int b)
{
    int resultado;

    resultado=a-b;

    printf("El resultado de la resta entre %d-%d es : %d\n",a,b,resultado);
}
void funDividir(int a,int b)
{
    float resultado;

    resultado=(float)a/b;
    printf("El Resultado de la division entre %d/%d es : %.2f\n",a,b,resultado);
}

int funIngresarNuevo(int b,char texto[])
{
    char respuesta;
    system("cls");
    printf(texto);
    printf("Desea cambiar el numero [s/n] ? :");
    scanf("%s",&respuesta);

    if(respuesta=='s')
    {
        system("cls");
        printf("Ingrese el nuevo numero : ");
        scanf("%d",&b);

        while(b == 0)
        {
            system("cls");
            printf("ha vuelto a ingresar 0.\n");
            printf("Ingrese otro numero diferente a 0 : ");
            scanf("%d",&b);
        }

    }
    else
    {
        printf("ha decidido no realizar la operacion.\n");
    }

    system("pause");
    return b;

}

void funMultiplicacion (int a,int b)
{
    int resultado;

    resultado=a*b;

    printf("La multiplicacion entre %d y %d es : %d\n",a,b,resultado);

}

void funFactorial (int a)
{
    long int resultado = 1;
    int i;

    for(i=a; i>1 ; i--)
    {
        resultado=resultado*i;
    }

    printf("El factorial de %d es : %li \n",a,resultado);

}

void todasLasOperaciones(int a,int b)
{
    funSumar(a,b);
    funRestar(a,b);
    if(b != 0)
    {
        funDividir(a,b);
    }
    funMultiplicacion(a,b);
    if(a > 0)
    {
        funFactorial(a);
    }

}

