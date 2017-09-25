#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void startStatus (EPersona persona[], int max)
{
    int i;
    for(i=0; i<max;i++)
    {
        persona[i].estado=0;
    }
}

int menu (void)
{
    int opcion;
    system("cls");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");
    scanf("%d",&opcion);
    return opcion;
}

int getIndexEmpty (EPersona persona[],int max)
{
    int retorno = -1;
    int i;
    for (i=0;i<max;i++)
    {
        if(persona[i].estado==0)
            return i;
    }
    printf("No hay mas espacio.");
    system("pause");
    return retorno;
}

void getPerson (EPersona persona[], int max)
{
    int indice = getIndexEmpty(persona,max);
    char aux[500];
    if(indice>=0)
    {
        system("cls");
        do{
        fflush(stdin);
        printf("Nombre: ");
        fflush(stdin);
        scanf("%[^\n]",aux);
        //fgets(aux,100,stdin);
        }while(!(verificarChar(aux,3,99)));
        strcpy(persona[indice].nombre,aux); //NAME
        persona[indice].edad=verificarNumber("Edad: ","edad valida: 1 al 150\n",1,150); //AGE
        persona[indice].dni= (long)verificarNumber("DNI: ", "DNI INVALIDO (tiene que llegar al millon)\n",1000000,999999999);//DNI
        persona[indice].estado=1;//STATUS
        system("cls");
        printf("REGISTRO COMPLETADO.\n");
        system("pause");
    }
}

int verificarChar (char cadena[],int desde, int hasta)
{
    int cantidadChar = (strlen(cadena)-1), retorno=0;

    if (cantidadChar>=desde && cantidadChar<=hasta)
    {
        retorno = 1;
    }
    else
    {
        system("cls");
        printf("ERROR, el ingreso es de %d a %d caracteres\n",desde,hasta);
    }
    return retorno;
}


int  verificarNumber (char mensaje[], char mensajeError [], int min, int max)
{
    int numero;
    do{
    printf("%s", mensaje);
    scanf("%d",&numero);
    if (numero>=min && numero<=max)
        return numero;
    else
        printf("%s",mensajeError);
    }while(1);
}

long mostrarPersona (EPersona persona[], int max)
{
    int i,flag=0;
    long dni=0;
    printf("DNI\t\tNombre\n");
    for(i=0;i<max;i++)
    {
        if(persona[i].estado==1)
        {
            printf("%ld\t%s\n",persona[i].dni,persona[i].nombre);
            flag++;
        }
    }
    if(flag>0)
    {
        printf("Ingrese DNI (0 para volver): ");
        scanf("%ld", &dni);
    }
    else
    {
        printf("No hay datos cargados\n ");
        system("pause");
    }
    return dni;
}

void removePerson (EPersona persona[], int max)
{
    int i,flag=0;
    system("cls");
    long dni=mostrarPersona(persona, max);

    if (dni==0)
        return;
    for(i=0;i<max;i++)
    {
        if (persona[i].dni==dni)
        {
            persona[i].estado=-1;
            printf("Persona eliminada\n");
            flag++;
            break;
        }
    }
    if (flag==0)
        printf("DNI INCORRECTO\n");
}

void printListOrdered (EPersona persona[], int max)
{
    EPersona aux;
    int i,j;

    for(i=0;i<max-1;i++)
    {
        for(j=i+1;j<max;j++)
        {
            if(strcmp(persona[i].nombre,persona[j].nombre)>0)
            {
                aux=persona[i];
                persona[i]=persona[j];
                persona[j]=aux;
            }

        }
    }
    system("cls");
    printf("Nombre\t\tedad\tDNI\n\n");
    for (i=0;i<max;i++)
    {
        if(persona[i].estado==1)
            printf("%s\t\t%d\t%ld\n",persona[i].nombre,persona[i].edad,persona[i].dni);
    }

}

void printGrafic (EPersona persona[], int max)
{
    int i,menor18=0,de19a35=0,mayorde35=0,mayor,auxMayor;

    for (i=0;i<max;i++)
    {
        if (persona[i].estado==1)
        {
            if (persona[i].edad<=18)
                menor18++;
            else if (persona[i].edad>=35)
                mayorde35++;
            else
                de19a35++;
        }
    }

    if (menor18>=de19a35 && menor18>=mayorde35)
        mayor=menor18;
    else if (de19a35>=mayorde35 && de19a35>=menor18)
        mayor=de19a35;
    else
        mayor=mayorde35;
    auxMayor=mayor;

    for(i=0;i<mayor;i++)
    {
        printf("\n|%d|",auxMayor);
        if (auxMayor==menor18)
        {
            printf("\t*");
            menor18--;
        }
        else
            printf("\t ");
        if (auxMayor==de19a35)
        {
            printf("\t*");
            de19a35--;
        }
        else
            printf("\t ");
        if (auxMayor==mayorde35)
        {
            printf("\t*");
            mayorde35--;
        }
        else
            printf("\t ");

        auxMayor--;
    }
    printf("\n\t<18\t19-34\t>35\n");


}


