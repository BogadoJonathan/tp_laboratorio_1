#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float getNumber (char message[])
{
    float number;
    printf("%s",message);
    scanf("%f",&number);
    return number;
}

int menu (int i, int j, float a, float b)
{
    int opcion;
     if (i==0 && j==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else if (i>0 && j>0)
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n",a);
            printf("2- Ingresar 2do operando (B=%.2f)\n",b);
        }
        else if (i>0 && j==0)
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n",a);
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=%.2f)\n",b);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        scanf("%d",&opcion);
        return opcion;
}

void sum (float number1,float number2)
{
    printf("La suma es: %.2f\n",number1+number2);
    system("pause");
}

int check (int i, int j)
{
    int retorno=0;
    if (i>0 && j>0)
        retorno=1;
    else
        {
            printf("Debe ingresar valores a ambos operandos antes de realizar esta operacion\n\n");
            system("pause");
        }

    return retorno;
}

void subtraction (float number1, float number2)
{
    printf("La resta es: %.2f\n",number1-number2);
    system("pause");
}

void division (float number1, float number2)
{
    if (number2!=0)
        printf("La division es: %.2f\n",number1/number2);
    else
    {
        printf("No se puede dividir por 0\n");
    }
    system("pause");

}

void multiply (float number1, float number2)
{
    printf("La multiplicacion es: %.2f\n",number1*number2);
    system("pause");
}

void factorial (float number1)
{
    int factorial = (int)number1;
    int resultado=1;

    if (factorial==0)
        printf("El factorial de 0 es 1\n");
    else
    {
        while (factorial>1)
        {
            resultado=resultado*factorial;
            factorial--;
        }
        printf("el factorial de %d es: %d\n",(int)number1, resultado);
    }

    system("pause");
}



