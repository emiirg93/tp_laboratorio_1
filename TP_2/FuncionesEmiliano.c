#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "FuncionesEmiliano.h"

int menu()
{
    char opcion[10];
    int datoInt;

    system("cls");

    printf("-------Bienvenidos-------\n\n");
    printf("1- Agregar Persona.\n");
    printf("2- Borrar Persona.\n");
    printf("3- Imprimir Lista Ordenada Por Nombre\n");
    printf("4- Imprimir Grafico De Edades\n\n");
    printf("5- Salir.\n\n");

    printf("Ingrese Respuesta: ");

    scanf("%s",opcion);

    while (validarLetra(opcion)== 1)
    {
        printf("Usted no puede ingresar un caracter!\nIngrese un numero ente 1 y 5 :");
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

void inicializarStruct(ePersona persona[],int tam)
{
    int i;

    for (i=0; i<tam; i++)
    {
        persona[i].estado = 0;
        persona[i].edad = 0;
        persona[i].dni = 0;
        strcpy(persona[i].nombre,"NADA");
    }
}

void inicializarPersona(ePersona persona[],int indice)
{
    persona[indice].estado = 0;
    persona[indice].edad = 0;
    persona[indice].dni = 0;
    strcpy(persona[indice].nombre,"NADA");
}

void mostrarPersonas(ePersona persona[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado == 1)
        {
            printf("Nombre : %s | Dni: %ld | Edad : %d \n",persona[i].nombre,persona[i].dni,persona[i].edad);
        }
    }
}

int buscarLibre (ePersona persona[],int tam)
{
    int i,lugarLibre=-1;

    for(i=0; i<tam; i++)
    {
        if (persona[i].estado == 0)
        {
            lugarLibre = i;
            break;
        }
    }

    return lugarLibre;
}

void alta(ePersona persona[],int tam)
{
    int indice,i;
    long int auxDni;
    ePersona aux;

    indice = buscarLibre(persona,tam);

    if (indice != -1)
    {
        printf("Ingrese DNI : ");
        scanf("%ld",&auxDni);

        for(i=0; i<tam; i++)
        {
            while(auxDni == persona[i].dni)
            {
                printf("El DNI ya esta ingresado en el sistema\nIngrese un nuevo DNI : ");
                scanf("%ld",&auxDni);
            }
        }

        aux.dni = auxDni;

        printf("Ingrese Nombre : ");
        fflush(stdin);
        gets (aux.nombre);

        aux.edad = edadConValidacion();

        aux.estado = 1;

        persona[indice]= aux;
    }
    else
    {
        printf("No hay mas espacio.");
        system("pause");
    }
}

int edadConValidacion ()
{
    int edad;

    printf("Ingresa Edad : ");
    scanf("%d",&edad);

    while(edad < -1 || edad > 120)
    {
        printf("ha ingresado una edad no valida\nPor favor, vuelva a ingresar la edad : ");
        scanf("%d",&edad);
    }

    return edad;
}

void borrarPersona(ePersona persona[],int tam)
{
    int indice;
    char respuesta;

    indice = buscarPersona(persona,tam);

    if(indice != -1)
    {
        mostrarPersona(persona,tam,indice);
        printf("\nEsta seguro que desea dar de baja a esta Persona? Se borraran sus datos. [s/n]\nRespuesta : ");
        respuesta = getch();

        respuesta = tolower(respuesta);

        if(respuesta == 's')
        {
            inicializarPersona(persona,indice);
            printf("Se ha dado de baja con exito.\n");
        }
        else
        {
            printf("Se ha cancelado la operacion.\n");
        }


    }
    else
    {
        printf("No se encontro el DNI ingresado.\n");
    }
}

int buscarPersona(ePersona persona[],int tam)
{

    long int auxDni;
    int flag = -1;
    int i;

    printf("Ingrese DNI : ");
    scanf("%ld",&auxDni);

    for(i=0; i<tam; i++)
    {
        if(auxDni == persona[i].dni)
        {
            flag = i;
            break;
        }
    }

    return flag;

}
void mostrarPersona (ePersona persona[],int tam,int indice)
{
    printf("Nombre : %s | Dni: %ld | Edad : %d \n",persona[indice].nombre,persona[indice].dni,persona[indice].edad);
}

void ordenarLista (ePersona persona[],int tam)
{
    ePersona aux;
    int i,j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(stricmp(persona[i].nombre,persona[j].nombre)>0)
            {
                aux = persona[i];
                persona[i] = persona[j];
                persona[j] = aux;
            }
        }
    }

    mostrarPersonas(persona,tam);
}

void graficoEdades(ePersona persona[],int tam)
{
    int i,contMenores=0,contHastaTC=0,contMasTC=0,max;
    system("cls");
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado != 0 && persona[i].edad < 18)
        {
            contMenores++;
        }
        if(persona[i].estado != 0 && persona[i].edad >= 18 && persona[i].edad <= 35)
        {
            contHastaTC++;
        }
        if(persona[i].estado != 0 && persona[i].edad >35)
        {
            contMasTC++;
        }
    }

    if(contMenores > contHastaTC && contMenores > contMasTC)
    {
        max = contMenores;
    }
    else if(contHastaTC > contMasTC)
        max = contHastaTC;
    else
        max = contMasTC;

    for(i=max; i>0; i--)
    {
        if(i <= contMenores)
        {
            printf("  *");
        }

        if(i <= contHastaTC)
        {
            printf("\t  *");
        }
        else
        {
            printf("\t");
        }

        if(i <= contMasTC)
        {
            printf("\t *");
        }

        printf("\n");
    }
    printf(" <18 \t18-35\t>35\n");
}
