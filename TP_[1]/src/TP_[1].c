/*
 ============================================================================
 Name        : Trabajo pratico N°1
 Author      : Taboada Ezequiel
 ============================================================================
 */

#include "biblioteca.h"
#define MAX 10000000
#define MIN -10000000
int main(void) {
	setbuf(stdout, NULL);
	float numeroUno;
	float numeroDos;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	int factoUno;
    int factoDos;
	int flagPrimerOperando;
	int flagSegundoOperando;
	int flagOperaciones;
	int respuestaUno;
	int respuestaDos;
	char salir;
	flagPrimerOperando = 0;
	flagSegundoOperando = 0;
	flagOperaciones = 0;
	do {
		switch (ING_menuPrincipal(flagPrimerOperando, flagSegundoOperando,
				numeroUno, numeroDos)) {
		case 1:
			ING_imprimirTitulo("Ingresar 1er operando");
			if(ING_NumeroFloatEnRango(&numeroUno,15 ,"\nIngrese el primer operando: ",
					"Dato Incorrecto", MIN, MAX)){
				puts("** error al utilizar la funcion ING_NumeroFloatEnRango **");
			}
			respuestaUno=CAL_esEntero(numeroUno);
			flagPrimerOperando = 1;
			break;
		case 2:
			ING_imprimirTitulo("Ingresar 2do operando");
			if (flagPrimerOperando) {
				if(ING_NumeroFloatEnRango(&numeroDos,15,
						"\nIngrese el segundo operando: ", "Dato Incorrecto",
						MIN, MAX)){
					puts("** error al utilizar la funcion ING_NumeroFloatEnRango **");
				}
				respuestaDos=CAL_esEntero(numeroDos);
				flagSegundoOperando = 1;
			} else {
				puts("\n** Primero debe ingresar el primer operando **\n");

				system("pause");
			}
			break;
		case 3:
			ING_imprimirTitulo("Calcular todas las operaciones");
			if (!flagPrimerOperando) {
				puts("\n** Primero debe ingresar los operandos **\n");
			} else {
				if (!flagSegundoOperando) {
					puts("\n** Falta ingresar el segundo operando **\n");
				} else {
					if (OP_dividir(&division, numeroUno, numeroDos)) {
						puts("** error al utilizar la funcion OP_dividir **");
					}
					if (OP_multiplicar(&multiplicacion, numeroUno, numeroDos)) {
						puts("** error al utilizar la funcion OP_multiplicar **");
					}
					if (OP_restar(&resta, numeroUno, numeroDos)) {
						puts("** error al utilizar la funcion OP_restar **");
					}
					if (OP_sumar(&suma, numeroUno, numeroDos)) {
						puts("** error al utilizar la funcion OP_sumar **");
					}
					if (OP_factorizar(&factoUno, numeroUno)) {
						puts("** error al utilizar la funcion OP_factorizar **");
					}
					if (OP_factorizar(&factoDos, numeroDos)) {
						puts("** error al utilizar la funcion OP_factorizar **");
					}
					flagOperaciones = 1;
					puts("\n Operaciones calculadas con exito.\n");
				}
			}
			system("pause");
			break;
		case 4:
			ING_imprimirTitulo("Informar resultados");
			if (flagOperaciones) {
				printf("El resultado de %.2f + %.2f es: %.2f \n", numeroUno,
						numeroDos, suma);
				printf("El resultado de %.2f - %.2f es: %.2f \n", numeroUno,
						numeroDos, resta);
/// el divisor no puede ser 0.
				if (numeroDos!=0) {
					printf("El resultado de %.2f / %.2f es: %.2f \n", numeroUno,
							numeroDos, division);
				} else {
					printf(" error no se puede dividir por 0 \n");
				}
				printf("El resultado de %.2f * %.2f es: %.2f \n", numeroUno,
						numeroDos, multiplicacion);
/// el factorial debe ser entero, positivo y menor a 13.
				if (respuestaUno && respuestaDos && numeroUno > -1 && numeroUno < 13 && numeroDos > -1
						&& numeroDos <13) {
					printf("El factorial de %.0f es: %d y el factorial de %.0f es: %d\n",
									numeroUno, factoUno, numeroDos, factoDos);
				} else {
					if ((respuestaUno && !respuestaDos && numeroUno > -1 && numeroUno < 13)||
							(respuestaUno && respuestaDos && numeroUno > -1 && numeroUno < 13
									&& (numeroDos < 0 || numeroDos > 12) )) {
						printf("El factorial de %.0f es %d y no es posible calcular el factorial de %.2f\n",
									numeroUno, factoUno, numeroDos);
					} else {
						if ((!respuestaUno && respuestaDos && numeroDos > -1
								&& numeroDos < 13)||
								(respuestaUno && respuestaDos && numeroDos > -1 && numeroDos < 13
										&& (numeroUno < 0 || numeroUno > 12) )) {
							printf("No es posible calcular el factorial de %.2f y el factorial de %.0f es %d.\n",
									numeroUno, numeroDos, factoDos);
						} else {
							puts("No es posible calcular los factoriales.\n");
						}
					}
				}
				flagPrimerOperando = 0;
				flagSegundoOperando = 0;
				flagOperaciones = 0;
			} else {
				if (!flagPrimerOperando) {
					puts("\n** Primero debe ingresar los operandos **\n");
				} else {
					if (!flagSegundoOperando) {
						puts("\n** Falta ingresar el segundo operando **\n");
					} else {
						puts("\n** Primero debe realizar los calculos **\n");
					}
				}
			}
			system("pause");
			break;
		case 5:
			ING_imprimirTitulo("Salir");
			salir = ING_confirmar("Desea salir?", "opcion incorrecta\n");
			break;
		}
		system("cls");
	} while (salir != 's');
	puts("fin del programa\n");
	system("pause");
	return 0;
}
