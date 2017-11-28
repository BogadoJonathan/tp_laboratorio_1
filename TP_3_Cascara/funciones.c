#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int menu (void)
{
    printf("1 - Agregar pelicula.\n");
    printf("2 - Borrar pelicula.\n");
    printf("3 - Modificar pelicula.\n");
    printf("4 - Generar pagina web.\n");
    printf("5 - Salir.\n");

    return ingresarNumero("Ingrese numero: ",1,5);
}

int ingresarNumero(char mensaje[100], int minimo, int maximo)
{
    int retorno=0;
    int i;
    char numero[300];
    int numeroVerdadero;
    do
    {
        do
        {
            printf("%s", mensaje);
            scanf("%s",numero);
            retorno=1;
            int cantidad=strlen(numero);
            for (i=0; i<cantidad; i++)
            {
                if(isalpha(numero[i]))
                {
                    printf("No puede ingresar letra/s\n");
                    system("pause");
                    retorno=0;
                    break;
                }
            }
        }
        while(retorno==0);
        numeroVerdadero=atoi(numero);
        if (numeroVerdadero>=minimo && numeroVerdadero<=maximo)
            retorno=1;
        else
        {
            retorno=0;
            printf("Tiene que ingresar un numero desde el %d hasta el %d\n",minimo,maximo);
            system("pause");
        }
    }
    while(retorno==0);

    return numeroVerdadero;
}

void ingresarTexto(char mensaje[100],char *Destino,int desde, int hasta,char ingresarNumeros)
{
    int cantidad;
    int verificacion=1;
    int i;
    char texto[hasta];

    do
    {
        printf("\n%s",mensaje);
        fflush(stdin);
        fgets(texto,hasta+1,stdin);
        for(i=0; i<=hasta; i++)
        {
            if(texto[i]=='\n')
                texto[i]='\0';
        }
        cantidad=strlen(texto);
        if(cantidad>=desde && cantidad<=hasta)
        {
            verificacion=0;
            if(ingresarNumeros=='n'){
            for(i=0; i<cantidad; i++)
            {
                if(isdigit(texto[i]))
                {
                    printf("no puede ingresar numeros\n");
                    verificacion=1;
                    break;
                }
            }
            }
        }
        else
        {
            printf("supero el limite de caracteres permitidos o no ingreso nada\n");
        }
    }while(verificacion);
    strcpy(Destino,texto);
}

void crearMovie(eMovie movie,eMovie *pMovie, int *contador, int *index)
{
  ingresarTexto("Ingrese titulo: ",movie.titulo,1,MAX_TITULO,'s');
  ingresarTexto("Ingrese genero: ",movie.genero,3,MAX_GENERO,'n');
  movie.duracion=ingresarNumero("Ingrese minutos de duracion): ",1,400);
  ingresarTexto("Ingrese descripcion: ",movie.descripcion,1,MAX_DESCRIPCION,'s');
  movie.puntaje= ingresarNumero("Ingrese un puntaje (1-100)",1,100);
  ingresarTexto("Ingrese link de la imagen: ",movie.linkImagen,1,MAX_LINKIMAGEN,'s');
  movie.id=(*index)+1;
  movie.estado=1;

        pMovie[*index]=movie;
        (*index)++;

    if((*index)>=*contador)
    {
        (*contador)+=2;
        pMovie=(eMovie*)realloc(pMovie,sizeof(eMovie)*(*contador));
    }

}

void printlistMovie (eMovie *movie,int index)
{
    int i;
    for(i=0;i<index;i++)
    {
        if(movie[i].estado==1)
        printf("%d - %s\n",movie[i].id,movie[i].titulo);
    }
}

void borrarMovie (eMovie *movie, int index)
{
    int opcion,i,flag=1;
    printlistMovie(movie,index);
    opcion=ingresarNumero("Ingrese opcion: (0 para salir)",0,index+1);
    if(opcion==0)
    {
        return;
    }
    else
    {
        for(i=0;i<index;i++)
        {
            if(opcion==movie[i].id && movie[i].estado==1)
            {
                flag=0;
                movie[i].estado=0;
                printf("Pelicula eliminada\n");
                break;
            }
        }
        if(flag)
            printf("ID incorrecta \n");
    }
}

void modificarMovie (eMovie *movie, int index)
{
    int opcion,i,flag=1;
    printlistMovie(movie,index);
    opcion=ingresarNumero("Ingrese opcion: (0 para salir)",0,index+1);
    if(opcion==0)
    {
        return;
    }
    else
    {
        for(i=0;i<index;i++)
        {
            if(opcion==movie[i].id && movie[i].estado==1)
            {
                flag=0;
                printf("Que desea modificar?: \n");
                printf("1 - Titulo\n");
                printf("2 - Genero\n");
                printf("3 - Duracion\n");
                printf("4 - puntuacion\n");
                printf("5 - link de imagen\n");
                printf("6 - descripcion\n");
                opcion=ingresarNumero("Ingrese la opcion a modificar: ",1,6);

                switch(opcion)
                {
                    case 1: ingresarTexto("Ingrese titulo: ",movie[i].titulo,1,MAX_TITULO,'s');
                        break;
                    case 2:  ingresarTexto("Ingrese genero: ",movie[i].genero,3,MAX_GENERO,'n');
                        break;
                    case 3: movie[i].duracion=ingresarNumero("Ingrese minutos de duracion): ",1,400);
                        break;
                    case 4:   movie[i].puntaje=ingresarNumero("Ingrese un puntaje (1-100)",1,100);
                        break;
                    case 5:  ingresarTexto("Ingrese link de la imagen: ",movie[i].linkImagen,1,MAX_LINKIMAGEN,'s');
                        break;
                    case 6:  ingresarTexto("Ingrese descripcion: ",movie[i].descripcion,1,MAX_DESCRIPCION,'s');
                        break;
                }
                break;
            }
        }
        if(flag)
            printf("ID incorrecta \n");
    }
}

void generarMovi (eMovie *movie, int index)
{
    int i;
    FILE* html;
    html=fopen("template/index.html","w");
    if(html==NULL)
    {
        printf("No se pudo crear el archivo");
        exit(1);
    }

    fprintf(html,HTML_INICIAL);
    for(i=0;i<index+1;i++){
            if(movie[i].estado==1)
            {
                fprintf(html,ARTICLE_INICIO);
                fprintf(html,ARTICLE_LINK,movie[i].linkImagen);
                fprintf(html,ARTICLE_TITULO,movie[i].titulo);
                fprintf(html,ARTICLE_LISTA,movie[i].genero,movie[i].puntaje,movie[i].duracion);
                fprintf(html,ARTICLE_DESCRIPCION,movie[i].descripcion);
                fprintf(html,ARTICLE_CIERRE);
            }
    }
    fprintf(html,HTML_FINAL);
    printf("Pelicula generada");
    fclose(html);

}
