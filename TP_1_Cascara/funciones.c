#include <stdio.h>
#include <stdlib.h>

int menu(int a,int b)
{
    int opcion;

    system("cls");

    printf("1- Ingresar 1er operando (A=%d)\n",a);
    printf("2- Ingresar 2do operando (B=%d)\n",b);
    printf("3- Calcular la suma (%d+%d)\n",a,b);
    printf("4- Calcular la resta (%d-%d)\n",a,b);
    printf("5- Calcular la division (%d/%d)\n",a,b);
    printf("6- Calcular la multiplicacion (%d*%d)\n",a,b);
    printf("7- Calcular el factorial (%d!)\n",a);
    printf("8- Calcular todas las operaciones.\n");
    printf("9- Salir\n\nIngrese una opcion : ");

    scanf("%d",&opcion);

    while(opcion<1 ||opcion>9)
    {
        printf("Ingreso una opcion incorrecta!!\n\nIngrese una opcion entre 1/9 : ");
        scanf("%d",&opcion);
    }

    return opcion;
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

