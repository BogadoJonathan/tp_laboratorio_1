#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX 20


int main()
{
    char seguir='s';
    EPersona persona[MAX];

    startStatus(persona, MAX);

    while(seguir=='s')
    {
        switch(menu())
        {
            case 1:
                getPerson(persona,MAX);
                break;
            case 2:
                removePerson(persona,MAX);
                system("pause");
                break;
            case 3:
                printListOrdered(persona,MAX);
                system("pause");
                break;
            case 4:
                system("cls");
                printGrafic(persona,MAX);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta");
                system("pause");
        }
    }
    return 0;
}
