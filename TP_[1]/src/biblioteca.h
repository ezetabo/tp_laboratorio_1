#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/**
 * @brief recibe dos numeros flotantes, realiza la division y retorna el resultado por puntero.
 *
 * @param pResultado: puntero a float con el resultado de la division.
 * @param dividendo: numero a dividir.
 * @param divisor: numero por el que se desea dividir.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int OP_dividir(float *pResultado, float dividendo, float divisor);

/**
 * @brief recibe un entero, realiza el factoria de dicho numero y retorna el resultado por puntero.
 *
 * @param pResultado: puntero con el resultado de la factorizacion.
 * @param numero: entero positivo que se desea factorizar.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int OP_factorizar(int *pResultado, int numero);

/**
 * @brief recibe dos numeros flotantes, realiza la suma y retorna el resultado por puntero.
 *
 * @param pResultado: puntero a float con el resultado de la suma.
 * @param numeroUno: primer numero ingresado.
 * @param numeroDos: segundo numero ingresado.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int OP_sumar(float *pResultado, float numeroUno, float numeroDos);

/**
 * @brief recibe dos numeros flotantes, realiza la resta y retorna el resultado por puntero.
 *
 * @param pResultado: puntero a float con el resultado de la resta.
 * @param numeroUno: primer numero ingresado.
 * @param numeroDos: segundo numero ingresado.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int OP_restar(float *pResultado, float numeroUno, float numeroDos);

/**
 * @brief recibe dos numeros flotantes, realiza la multiplicacion y retorna el resultado por puntero.
 *
 * @param pResultado: puntero a float con el resultado de la multiplicacion.
 * @param numeroUno: primer numero ingresado.
 * @param numeroDos: segundo numero ingresado.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int OP_multiplicar(float *pResultado, float numeroUno, float numeroDos);

/**
 * @brief recibe un dato del tipo float y evalua si el numero es un entero o flotante.
 *
 * @param numero: numero a evaluar.
 * @return "0" si es flotante / "1" si es entero.
 */int CAL_esEntero(float numero);

/**
 * @brief recibe una cadena de caracteres y verifica que todos sean numericos.
 *
 * @param cadena: cadena a evaluar.
 * @param dimension: largo de la cadena.
 * @return "0" si es falso / "1" si es verdadero.
 */int CAL_esNumerico(char *cadena, int dimension);

/**
 * @brief recibe una cadena de caracteres y verifica que todos sean numericos y que no haya mas de 1 punto.
 *
 * @param cadena: cadena a evaluar.
 * @param dimension: largo de la cadena.
 * @return "0" si es falso / "1" si es verdadero.
 */int CAL_esFloat(char *cadena, int dimension);

/**
 * @brief realiza una lectura del bufer de entrada, valida que todos los caracteres sean numericos,
 * lo convierte a flotante y retorna el resultado por puntero.
 *
 * @param pResultado: puntero a float con el dato validado.
 * @param dimension: tamaño de la cadena de caracteres.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int ING_getFloat(float *pResultado, int dimension);

/**
 * @brief pide el ingreso de un numero flotante en un rango a eleccion y retorna el resultado por puntero.
 *
 * @param pResultado: puntero a float con el numero validado.
 * @param digitos: cantidad de digitos que componen el rango del numero deseado.
 * @param mensaje: literal para pedir el ingreso del numero deseado.
 * @param mensajeError: literal para informar que el dato ingresado no es el deseado.
 * @param minimo: valor minimo inclusive del rango.
 * @param maximo: valor maximo inclusive del rango.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int ING_NumeroFloatEnRango(float *pResultado,int digitos ,char *mensaje, char *mensajeError,
		float minimo, float maximo);

/**
 * @brief recibe un mensaje literal para validar por los caracteres 'S' o 'N'.
 *
 * @param mensaje: literal que se desea mostrar.
 * @param mensajeError: literal para informar que el dato ingresado no son los caracteres 'S' o 'N'.
 * @return retorna el caracter elegido: 'S' o 'N'.
 */char ING_confirmar(char *mensaje, char *mensajeError);

/**
 * @brief imprime el menu de opciones para el programa "Trabajo Practico 1", pide el ingreso
 * de un numero dentro del rango de opciones y lo retorna.
 *
 * @param flagUno: bandera de ingreso del primer operando.
 * @param flagDos: bandera de ingreso del segundo operando.
 * @param numeroUno: primer operando.
 * @param numeroDos: segundo operando.
 * @return int con el numero de opcion elegida.
 */int ING_menuPrincipal(int flagUno, int flagDos, float numeroUno,
		float numeroDos);

/**
 * @brief realiza una lectura del bufer de entrada, lo guarda como cadena de caracteres y lo retorna por puntero.
 *
 * @param cadena: cadena con el el dato leido.
 * @param dimension: tamaño de la cadena.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int ING_myGets(char *cadena, int dimension);

/**
 * @brief recibe un literal y lo imprime a modo de titulo.
 *
 * @param mensaje: mensaje que se desea mostar.
 */void ING_imprimirTitulo(char *mensaje);

/**
 * @brief pide el ingreso de un numero entero en un rango a eleccion y retorna el resultado por puntero.
 *
 * @param pResultado: puntero a int con el numero validado.
 * @param digitos: cantidad de digitos que componen el rango del numero deseado.
 * @param mensaje: literal para pedir el ingreso del numero deseado.
 * @param mensajeError: literal para informar que el dato ingresado no es el deseado.
 * @param minimo: valor minimo inclusive del rango.
 * @param maximo: valor maximo inclusive del rango.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int ING_NumeroEnRango(int *pResultado,int digitos ,char *mensaje, char *mensajeError,
		int minimo, int maximo);

/**
 * @brief realiza una lectura del bufer de entrada, valida que todos los caracteres sean numericos,
 * lo convierte a entero y retorna el resultado por puntero.
 *
 * @param pResultado: puntero a int con el dato validado.
 * @param dimension: tamaño de la cadena de caracteres.
 * @return "0" si la operacion es exitosa / "-1" en caso de error.
 */int ING_getInt(int *pResultado,int dimension);


#endif /* BIBLIOTECA_H_ */
