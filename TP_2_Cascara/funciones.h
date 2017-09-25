#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long dni;

}EPersona;


/**
 * Inicia los estados de la estructura en 0
 * @param lista el array se pasa como parametro.
 * @param se pasa el maximo para recorrer el for
 * @return void
 */
void startStatus (EPersona persona[], int max);

/**
 * Imprime el menu
 * @return devuelve la opcion que ingreso el usuario
 */
int menu (void);

/**
 * Busca entre las estructuras el primer estado en 0
 * @param lista el array se pasa como parametro.
 * @param se pasa el maximo para recorrer el for
 * @return El indice donde se encuentra la primer estructura vacia.
 */
int getIndexEmpty (EPersona persona[], int max);

/**
 * da de alta una persona
 * @param lista el array se pasa como parametro.
 * @param se pasa el maximo para pasarle como parametro a la funcion getIndexEmpty
 * @return void
 */
void getPerson (EPersona persona[], int max);

/**
 * Verifica que el usuario haya ingresado caracteres y la cantidad justa
 * @param lista el array se pasa como parametro.
 * @param se pasa la cantidad minima de caractere
 * @param se pasa la cantidad maxima de caracteres
 * @return retorna 0 si no cumple la cantidad adecuada, de lo contrario devuelve 1
 */
int verificarChar (char cadena[],int desde, int hasta);

/**
 * Verifica que el usuario haya ingresado numeros y la cifra adecuada
 * @param se pasa un mensaje para que el usuario ingrese el valor.
 * @param se pasa un mensaje de error en el caso que el usuario se equivoque.
 * @param se pasa la cifra minima permitida
 * @param se pasa la cifra maxima permitida
 * @return void
 */
int  verificarNumber (char mensaje[], char mensajeError [], int min, int max);

/**
 * Muestra una lista de personas y le pide al usuario el DNI de dicha persona para luego eliminar
 * @param lista el array se pasa como parametro.
 * @param se pasa el maximo para recorrer el for
 * @return devuelve el DNI que ingreso el usuario
 */
long mostrarPersona (EPersona persona[], int max);

/**
 * Busca el DNI entre las estructuras y cambia el estado de la persona en -1
 * @param lista el array se pasa como parametro.
 * @param se pasa el maximo para pasarle como parametro a la funcion mostrarPersona y para hacer un for
 * @return void
 */
void removePerson (EPersona persona[], int max);

/**
 * Muestra una lista ordena de personas de la A a la Z
 * @param lista el array se pasa como parametro.
 * @param se pasa el maximo para recorrer dicha lista
 * @return void
 */
void printListOrdered (EPersona persona[], int max);

/**
 * Imprime un grafico de edades
 * @param lista el array se pasa como parametro.
 * @param se pasa el maximo para utilizar un for
 * @return void
 */
void printGrafic (EPersona persona[], int max);




#endif // FUNCIONES_H_INCLUDED
