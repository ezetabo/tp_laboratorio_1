#include "biblioteca.h"

int OP_dividir(float *pResultado, float dividendo, float divisor) {
	int retorno;
	retorno = -1;
	if (pResultado != NULL) {
		*pResultado = dividendo / divisor;
		retorno = 0;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int OP_factorizar(int *pResultado, int numero) {
	int factorizaciones;
	int i;
	long long int retorno;
	retorno = -1;
	factorizaciones = numero - 1;
	if (pResultado != NULL) {
		if (numero == 0) {
			numero = 1;
			*pResultado = numero;
			retorno = 0;
		} else {
			for (i = factorizaciones; i > 0; i--) {
				numero *= i;
			}
			*pResultado = numero;
			retorno = 0;
		}
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int OP_sumar(float *pResultado, float numeroUno, float numeroDos) {
	int retorno;
	retorno = -1;
	if (pResultado != NULL) {
		*pResultado = numeroUno + numeroDos;
		retorno = 0;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int OP_restar(float *pResultado, float numeroUno, float numeroDos) {
	int retorno;
	retorno = -1;
	if (pResultado != NULL) {
		*pResultado = numeroUno - numeroDos;
		retorno = 0;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int OP_multiplicar(float *pResultado, float numeroUno, float numeroDos) {
	int retorno;
	retorno = -1;
	if (pResultado != NULL) {
		*pResultado = numeroUno * numeroDos;
		retorno = 0;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ING_myGets(char *cadena, int dimension) {
	int retorno;
	char *auxCadena;
	auxCadena = (char*) malloc(sizeof(char) * dimension);
	retorno = -1;
	if (cadena != NULL && dimension > 0) {
		fflush(stdin);
		fgets(auxCadena, dimension, stdin);
		if (auxCadena[strlen(auxCadena) - 1] == '\n') {
			auxCadena[strlen(auxCadena) - 1] = '\0';
		}
		if (strnlen(auxCadena, sizeof(auxCadena)) <= dimension) {
			strncpy(cadena, auxCadena, dimension);
			retorno = 0;
		}
	}
	free(auxCadena);
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CAL_esFloat(char *cadena, int dimension) {
	int retorno;
	int i;
	int contadorPunto;
	contadorPunto = 0;
	retorno = 1;
	for (i = 0; i < dimension && (*(cadena + i)) != '\0'; i++) {
		if (i == 0 && ((*(cadena + i)) == '-' || (*(cadena + i)) == '+')) {
			continue;
		}
		if (!isdigit((*(cadena + i)))) {
			if ((*(cadena + i)) == '.') {
				contadorPunto++;
				if (contadorPunto > 1) {
					retorno = 0;
					break;
				}
			} else {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ING_getFloat(float *pResultado, int dimension) {
	int retorno;
	char *auxiliar;
	auxiliar = (char*) malloc(sizeof(char) * dimension);
	retorno = -1;
	if (pResultado != NULL && !ING_myGets(auxiliar, dimension)
			&& CAL_esFloat(auxiliar, dimension)) {
		*pResultado = atof(auxiliar);
		retorno = 0;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ING_NumeroFloatEnRango(float *pResultado, int digitos, char *mensaje,
		char *mensajeError, float minimo, float maximo) {
	int retorno;
	float numero;
	int r;
	retorno = -1;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo) {
		printf("%s", mensaje);
		fflush(stdin);
		r = ING_getFloat(&numero, digitos);
		while (r != 0 || numero < minimo || numero > maximo) {
			printf("%s\n%s", mensajeError, mensaje);
			fflush(stdin);
			r = ING_getFloat(&numero, digitos);
		}
		*pResultado = numero;
		retorno = 0;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char ING_confirmar(char *mensaje, char *mensajeError) {
	char seguir;
	printf("\n%s: [S/N] ", mensaje);
	fflush(stdin);
	scanf("%c", &seguir);
	seguir = tolower(seguir);
	while (seguir != 's' && seguir != 'n') {
		printf("\n** %s **\n%s: [S/N]  ", mensajeError, mensaje);
		fflush(stdin);
		scanf("%c", &seguir);
		seguir = tolower(seguir);
	}
	return seguir;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ING_menuPrincipal(int flagUno, int flagDos, float numeroUno,
		float numeroDos) {
	int opcion;
	ING_imprimirTitulo("Menu");
	if (flagUno) {
		printf("\n 1.Ingresar 1er operando (A = %.2f)", numeroUno);
	} else {
		printf("\n 1.Ingresar 1er operando (A = x)");
	}
	if (flagDos) {
		printf("\n 2.Ingresar 2do operando (B = %.2f)", numeroDos);
	} else {
		printf("\n 2.Ingresar 2do operando (B = y)");
	}
	printf("\n 3.Calcular todas las operaciones.");
	printf("\n 4.Informar resultados.");
	printf("\n 5.Salir.\n");
	ING_NumeroEnRango(&opcion, 3, "\n elija una opcion: ",
			"\nopcion incorrecta\n", 1, 5);
	return opcion;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CAL_esEntero(float numero) {
	int retorno;
	int parteEntera;
	float decimal;
	int resultado;
	retorno = 0;
	parteEntera = (int) numero;
	decimal = numero - parteEntera;
	resultado = decimal * 100;
	if (!resultado) {
		retorno = 1;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ING_imprimirTitulo(char *mensaje) {
	printf("\n********** %s **********\n", mensaje);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ING_NumeroEnRango(int *pResultado, int digitos, char *mensaje,
		char *mensajeError, int minimo, int maximo) {
	int retorno;
	int numero;
	int r;
	retorno = -1;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo) {
		printf("%s", mensaje);
		fflush(stdin);
		r = ING_getInt(&numero, digitos);
		while (r != 0 || numero < minimo || numero > maximo) {
			printf("%s\n%s", mensajeError, mensaje);
			r = ING_getInt(&numero, digitos);
		}
		*pResultado = numero;
		retorno = 0;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ING_getInt(int *pResultado, int dimension) {
	int retorno;
	char *auxiliar;
	auxiliar = (char*) malloc(sizeof(char) * dimension);
	retorno = -1;
	if (pResultado != NULL && !ING_myGets(auxiliar, dimension)
			&& CAL_esNumerico(auxiliar, dimension)) {
		*pResultado = atoi(auxiliar);
		retorno = 0;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CAL_esNumerico(char *cadena, int dimension) {
	int retorno;
	int i;
	retorno = 1;
	for (i = 0; i < dimension && (*(cadena + i)) != '\0'; i++) {
		if (i == 0 && ((*(cadena + i)) == '-' || (*(cadena + i)) == '+')) {
			continue;
		}
		if (!isdigit((*(cadena + i)))) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


