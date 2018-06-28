#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int menuPrincipal(int numeroA,int numeroB)
{
    char opcion[10];
    int datoInt;

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

    scanf("%s",opcion);

    while (validarLetra(opcion)== 1)
    {
        printf("Usted no puede ingresar un caracter!\nIngrese un numero ente 1 y 9 :");
        scanf("%s",opcion);
    }

    datoInt = atoi(opcion);

    return datoInt;
}

int validarLetra(char opcion[])
{
    int flag = 0,cant,i;

    cant = strlen(opcion);

    for(i=0; i<cant; i++)
    {
        if(!isdigit(opcion[i]))
        {
            flag = 1;
            break;
        }
    }

    return flag;
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

