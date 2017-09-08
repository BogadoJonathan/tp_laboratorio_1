#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 * \brief Solicita un numero al usuario
 * \param recibe mensaje a imprimir
 * \return Devuelve el numero que ingreso el usuario
 *
 */
float getNumber (char message[]);

/**
 * \brief Muestra el menu al usuario
 * \param recibe contador i para saber si el primer operando ya se ingreso;
 * \param recibe contador j, para saber si el segundo operando ya se ingreso;
 * \return Devuelve la opcion que puso el usuario
 *
 */
int menu (int i, int j, float a, float b);

/**
 * \brief Verifica si el usuario ingreso valor a ambos operandos
 * \param recibe contador i para saber si el primer operando ya se ingreso;
 * \param recibe contador j, para saber si el segundo operando ya se ingreso;
 * \return devuelve 0 si el usuario no ingreso valor a ambos operandos, de lo contrario devuelve 1
 *
 */
int check (int i, int j);

/**
 * \brief Suma ambos operando y muestra resultado
 * \param recibe primer operando
 * \param recibe segundo operando
 * \return void
 *
 */
void sum (float number1,float number2);

/**
 * \brief resta ambos operando y muestra resultado
 * \param recibe primer operando
 * \param recibe segundo operando
 * \return void
 *
 */
void subtraction (float number1, float number2);

/**
 * \brief divide ambos operando y muestra resultado
 * \param recibe primer operando
 * \param recibe segundo operando
 * \return void
 *
 */
void division (float number1, float number2);

/**
 * \brief Multiplica ambos operando y muestra resultado
 * \param recibe primer operando
 * \param recibe segundo operando
 * \return void
 *
 */
void multiply (float number1, float number2);

/**
 * \brief Muestra el valor factorial del primer operando
 * \param recibe primer operando
 * \return void
 *
 */
void factorial (float number1);

#endif // FUNCIONES_H_INCLUDED
