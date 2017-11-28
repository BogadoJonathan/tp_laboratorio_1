#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int listSize=2;
    int index=0;
    eMovie movies;
    eMovie *pMovies = (eMovie*)malloc((listSize)*sizeof(eMovie));
    if(pMovies==NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }

    while(1)
    {
        switch(menu())
        {
        case 1:
            crearMovie(movies,pMovies,&listSize,&index);
            break;
        case 2:
            borrarMovie(pMovies,index);
            system("pause");
            break;
        case 3:
            modificarMovie(pMovies,index);
            system("pause");
            break;
        case 4:
            generarMovi(pMovies,index);
            system("pause");
            break;
        case 5:
            free(pMovies);
            exit(1);
            break;

            printf("Opcion no valida.\n");
            break;
        }
        system("cls");
    }
    return 0;
}
