#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int i=0,j=0;
    float a, b;

    while(seguir=='s')
    {
        switch(menu(i,j,a,b))
        {
        case 1:
            a=getNumber("Ingrese primer operando: ");
            i++;
            break;
        case 2:
            b=getNumber("Ingrese segundo operando: ");
            j++;
            break;
        case 3:
            if (check(i,j))
                sum(a,b);
            break;
        case 4:
            if (check(i,j))
                subtraction(a,b);
            break;
        case 5:
            if (check(i,j))
                division(a,b);
            break;
        case 6:
            if (check(i,j))
                multiply(a,b);
            break;
        case 7:
            if (check(i,1))
                factorial(a);
            break;
        case 8:
            if (check(i,j))
            {
                sum(a,b);
                subtraction(a,b);
                division(a,b);
                multiply(a,b);
                factorial(a);
            }
            break;
        case 9:
            seguir = 'n';
            break;
        }
        system("cls");
    }

    return 0;
}
