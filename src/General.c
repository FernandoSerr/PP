/*
 * General.c
 *
 *  Created on: 12 may. 2022
 *      Author: fserrano
 */


#include "General.h"

//***FUNCIONES DE VALIDACIONES DE IMPUTS***

//FUNCI�N EST�TICA myGets
/// @fn int myGets(char[], int)
/// @brief 			Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado un cadena un m�ximo de 'longitud - 1' caracteres.
/// @param cadena 	Puntero al espacio de memoria en donde se copiar� la cadena obtenida
/// @param longitud	Define el tama�o de cadena
/// @return 		Retorna 1 (EXITO) si se obtiene una cadena,
/// 				retorna -1 (ERROR) si la cadena es igual a NULL,
/// 				retorna -2 (ERROR) si la longitud es igual o menor a cero y
/// 				retorna -3 (ERROR) si el fgets no asign� correctamente en la cadena
static int myGets(char cadena[], int longitud);
static int myGets(char cadena[], int longitud)
{
	int rtn = 0;

	fflush(stdin);
	if(cadena != NULL)
	{
		if(longitud > 0)
		{
			if(fgets(cadena, longitud, stdin) == cadena)
			{

				if(cadena[strlen(cadena) - 1] == '\n')
				{
					cadena[strlen(cadena) - 1] = '\0';
				}
				rtn = 1;
			}
			else{rtn = -3;}
		}
		else{rtn = -2;}
	}
	else{rtn = -1;}

	return rtn;
}

//FUNCION EST�TICA esNumerica
/// @fn int esNumerica(char[])
/// @brief 			Verifica si la cadena ingresada es numerica
/// @param cadena 	Cadena de caracteres a ser analizada
/// @return 		Retorna 1 (EXITO) si la cadena es num�rica,
///  				retorna -1 (ERROR) si cadena es igual a NULL,
/// 				retorna -2 (ERROR) si la longitud de cadena es menor o igual a cero y
/// 				retorna -3 (ERROR) si la cadena tiene alg�n componente no num�rico.
static int esNumerica(char cadena[]);
static int esNumerica(char cadena[])
{
	int rtn = 0;

	if(cadena != NULL)
	{
		if(strlen(cadena) > 0)
		{
			int i = 0;
			while(cadena[i] != '\0')
			{
				if(cadena[i] < '0' || cadena[i] > '9')
				{
					rtn = -3;
					break;
				}
				i++;
				rtn = 1;
			}
		}
		else{rtn = -2;}
	}
	else{rtn = -1;}

	return rtn;
}

//FUNCION EST�TICA esDecimal
/// @fn int esDecimal(char[])
/// @brief 			Verifica si la cadena ingresada es numerica decimal
/// @param cadena 	Cadena de caracteres a ser analizada
/// @return 		Retorna 1 (EXITO) si la cadena es num�rica decimal,
/// 				retorna -1 (ERROR) si cadena es igual a NULL,
/// 				retorna -2 (ERROR) si la longitud de cadena es menor o igual a cero y
/// 				retorna -3 (ERROR) si la cadena tiene alg�n componente no num�rico ni separador decimal.
static int esDecimal(char cadena[]);
static int esDecimal(char cadena[])
{
	int cantPuntos = 0;
	int rtn = 0;

	if(cadena != NULL)
	{
		if(strlen(cadena) > 0)
		{
			int i = 0;
			while(cadena[i] != '\0')
			{
				if(cadena[i] >= '0' && cadena[i] <= '9')
				{
				}
				else if(cadena[i] == '.' && cantPuntos < 1)
				{
					cantPuntos++;
				}
				else if(cadena[i] == '-' && i == 0)
				{
				}
				else
				{
					rtn = -3;
					break;
				}
				i++;
				rtn = 1;
			}
		}
		else{rtn = -2;}
	}
	else{rtn = -1;}

	return rtn;
}

//FUNCI�N EST�TICA esAlfabetica
/// @fn int esAlfabetica(char[])
/// @brief 			Verifica si la cadena ingresada es s�lo letras
/// @param cadena 	Cadena de caracteres a ser analizada
/// @return 		Retorna 1 (EXITO) si la cadena es s�lo letras,
/// 				retorna -1 (ERROR) si cadena es igual a NULL,
/// 				retorna -2 (ERROR) si la longitud de cadena es menor o igual a cero y
/// 				retorna -3 (ERROR) si la cadena tiene alg�n componente no alfab�tico.
static int esAlfabetica(char cadena[]);
static int esAlfabetica(char cadena[])
{
	int rtn = 0;

	if(cadena != NULL)
	{
		if(strlen(cadena) > 0)
		{
			int i = 0;
			while(cadena[i] != '\0')
			{
				if((cadena[i] >= 65 && cadena[i] <= 90) || (cadena[i] >= 97 && cadena[i] <= 122))
				{
					i++;
					rtn = 1;
				}
				else
				{
					rtn = -3;
					break;
				}
				//printf("entr�: %s", cadena); // desp borrar
			}
		}
		else{rtn = -2;}
	}
	else{rtn = -1;}

	return rtn;
}

//FUNCI�N EST�TICA esAlfanumerica
/// @fn int esAlfanumerica(char[])
/// @brief 			Verifica si la cadena ingresada es s�lo letras y n�meros
/// @param cadena 	Cadena de caracteres a ser analizada
/// @return 		Retorna 1 (EXITO) si la cadena es s�lo letras o n�meros,
/// 				retorna -1 (ERROR) si cadena es igual a NULL,
/// 				retorna -2 (ERROR) si la longitud de cadena es menor o igual a cero y
/// 				retorna -3 (ERROR) si la cadena tiene alg�n componente no alfab�tico ni num�rico.
static int esAlfanumerica(char cadena[]);
static int esAlfanumerica(char cadena[])
{
	int rtn = 0;

	if(cadena != NULL)
	{
		if(strlen(cadena) > 0)
		{
			int i = 0;
			while(cadena[i] != '\0')
			{
				if((cadena[i] >= 65 && cadena[i] <= 90) || (cadena[i] >= 97 && cadena[i] <= 122)|| (cadena[i] >= 48 && cadena[i] <= 57))
				{
					i++;
					rtn = 1;
				}
				else
				{
					rtn = -3;
					break;
				}
			}
		}
		else{rtn = -2;}
	}
	else{rtn = -1;}

	return rtn;
}

//FUNCI�N EST�TICA esAlfanumericaConEspaciosGuiones
/// @fn int esAlfanumericaConEspaciosGuiones(char[])
/// @brief 			Verifica si la cadena ingresada es s�lo letras, n�meros, guiones o espacios
/// @param cadena 	Cadena de caracteres a ser analizada
/// @return 		Retorna 1 (EXITO) si la cadena es s�lo letras, n�meros, espacios y/o guiones,
/// 				retorna -1 (ERROR) si cadena es igual a NULL,
/// 				retorna -2 (ERROR) si la longitud de cadena es menor o igual a cero y
/// 				retorna -3 (ERROR) si la cadena tiene alg�n componente que no es letra, n�mero, gui�n o espacio.
static int esAlfanumericaConEspaciosGuiones(char cadena[]);
static int esAlfanumericaConEspaciosGuiones(char cadena[])
{
	int rtn = 0;

	if(cadena != NULL)
	{
		if(strlen(cadena) > 0)
		{
			int i = 0;
			while(cadena[i] != '\0')
			{
				if((cadena[i] >= 65 && cadena[i] <= 90) || (cadena[i] >= 97 && cadena[i] <= 122)|| (cadena[i] >= 48 && cadena[i] <= 57) || cadena[i] == 32 || cadena[i] == 45)
				{
					i++;
					rtn = 1;
				}
				else
				{
					rtn = -3;
					break;
				}
			}
		}
		else{rtn = -2;}
	}
	else{rtn = -1;}

	return rtn;
}

//FUNCI�N EST�TICA esEmail
/// @fn int esEmail(char[])
/// @brief 			Verifica si la cadena ingresada es un email
/// @param cadena 	Cadena de caracteres a ser analizada
/// @return 		Retorna 1 (EXITO) si la cadena es un email,
/// 				retorna -1 (ERROR) si cadena es igual a NULL,
/// 				retorna -2 (ERROR) si la longitud de cadena es menor o igual a cero,
/// 				retorna -3 (ERROR) si la cadena tiene alg�n componente no permitido en emails,
/// 				retorna -4 (ERROR) si la cadena comienza con un arroba o tiene dos puntos seguidos despu�s de la arroba o si tiene alg�n caracter no permitido post arroba,
///					retorna -5 (ERROR) si la cadena termina en punto y
/// 				retorna -6 (ERROR) si no hay ninguna arroba o si hay m�s de una.
static int esEmail(char cadena[]);
static int esEmail(char cadena[])
{
	int rtn = 0;
	int banderaArroba = 0;
	int contadorPuntosPostArroba = 0;
	int banderaPuntoUltimoCaracter = 0;

	if(cadena != NULL)
	{
		if(strlen(cadena) > 0)
		{
			int i = 0;
			while(cadena[i] != '\0')
			{
				if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == '@' || cadena[i] == '_' || cadena[i] == '-' || cadena[i] == '.')
				{
					rtn = 1;
					if(cadena[i] == '@' && banderaArroba == 0)
					{
						banderaArroba = 1;
						if(i == 0)
						{
							rtn = -4;
							break;
						}
					}
					else
					{
						if(banderaArroba == 1)
						{
							if(cadena[i] == '.')
							{
								contadorPuntosPostArroba++;
								banderaPuntoUltimoCaracter = 1;
								if(cadena[i - 1] == '.' || cadena[i - 1] == '@')
								{
									rtn = -4;
									break;
								}
							}
							else
							{
								banderaPuntoUltimoCaracter = 0;
								if(cadena[i] == '_' || cadena[i] == '-' || cadena[i] == '@' || (cadena[i] >= '0' && cadena[i] <= '9'))
								{
									rtn =-4;
									break;
								}
							}
						}
					}
				}
				else
				{
					rtn = -3;
					break;
				}
				i++;

			}//fin del while

			if(rtn == 1 && banderaPuntoUltimoCaracter == 1)
			{
				rtn = -5;
			}

			if(rtn == 1 && (contadorPuntosPostArroba > 2 || contadorPuntosPostArroba < 1))
			{
				rtn = -6;
			}
		}
		else{rtn = -2;}
	}
	else{rtn = -1;}

	return rtn;
}

//FUNCI�N EST�TICA getInt
/// @fn int getInt(int*)
/// @brief 				Copia del stdin una cadema y verifica si la misma es num�rica
/// @param pResultado 	Puntero al espacio de memoria donde se dejara el resultado de la funci�n.
/// @return 			Retorna 1 (EXITO) si se obtiene un numero entero,
/// 					retorna -1 (ERROR) si hubo problemas en la funci�n myGets y
/// 					retorna -2 (ERROR) si hubo problemas en la funci�n esNumerica.
static int getInt(int* pResultado);
static int getInt(int* pResultado)
{
	int rtn = 0;
	char bufferInt[64];

	if(pResultado != NULL)
	{
		if(myGets(bufferInt, sizeof(bufferInt)) == 1)
		{
			if(esNumerica(bufferInt) == 1)
			{
				*pResultado = atoi(bufferInt); //atoi es como parseInt
				rtn = 1;
			}
			else{rtn = -2;}
		}
		else{rtn = -1;}
	}

	return rtn;
}

//FUNCI�N EST�TICA getFloat
/// @fn int getFloat(float*)
/// @brief  			Copia del stdin una cadema y verifica si la misma es num�rica decimal.
/// @param pResultado 	Puntero al espacio de memoria donde se dejara el resultado de la funci�n.
/// @return 			Retorna 1 (EXITO) si se obtiene un numero decimal,
/// 					retorna -1 (ERROR) si hubo problemas en la funci�n myGets y
/// 					retorna -2 (ERROR) si hubo problemas en la funci�n esDecimal.
static int getFloat(float* pResultado);
static int getFloat(float* pResultado)
{
	int rtn = 0;
	char bufferFloat[64];

	if(pResultado != NULL)
	{
		if(myGets(bufferFloat, sizeof(bufferFloat)) == 1)
		{
			if(esDecimal(bufferFloat) == 1)
			{
				*pResultado = atof(bufferFloat); //atof es como parseFloat
				rtn = 1;
			}
			else{rtn = -2;}
		}
		else{rtn = -1;}
	}

	return rtn;
}

//FUNCI�N EST�TICA getChar
/// @fn int getChar(char*)
/// @brief 				Copia del stdin una cadena y obtiene un caracter.
/// @param pResultado 	Puntero al espacio de memoria donde se dejara el resultado de la funci�n.
/// @return 			Retorna 1 (EXITO) si se obtiene un caracter y
/// 					retorna -1 (ERROR) si hubo problemas en la funci�n myGets.
static int getChar(char* pResultado);
static int getChar(char* pResultado)
{
	int rtn = 0;
	char bufferChar[2];

	if(pResultado != NULL)
	{
		if(myGets(bufferChar, sizeof(bufferChar)) == 1)
		{
			*pResultado = bufferChar[0];
			rtn = 1;
		}
		else{rtn = -1;}
	}

	return rtn;
}

//FUNCI�N EST�TICA getString
/// @fn int getString(char*, int)
/// @brief 				Copia del stdin una cadena y verifica su longitud.
/// @param pResultado 	Copia del stdin una cadena y obtiene un caracter.
/// @param longitud 	Longitud de la cadena.
/// @return 			Retorna 1 (EXITO) si se obtiene una cadena y
/// 					retorna -1 (ERROR) si hubo problemas en la funci�n myGets.
static int getString(char* pResultado, int longitud);
static int getString(char* pResultado, int longitud)
{
	int rtn = 0;
	char bufferString[1024];

	if(pResultado != NULL && longitud > 0)
	{
		if(myGets(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pResultado,bufferString,longitud);
			rtn = 1;
		}
		else{rtn = -1;}
	}
	return rtn;
}

//FUNCION obtenerNumEntero
/// @fn int obtenerNumEntero(int*, char[], char[], char[], int, int, int)
/// @brief 						Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los intentos permitidos
/// @param minimo				Es el n�mero entero m�nimo a ser aceptado
/// @param maximo				Es el n�mero entero m�ximo a ser aceptado
/// @param intentos				Cantidad m�xima de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener el n�mero entero,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getInt,
/// 							retorna -3 (ERROR) si el n�mero ingresado no se encuentra entre el m�ximo y m�nimo permitido y
/// 							retorna -4 (ERROR) si se acaban los intentos.
int obtenerNumEntero(int* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int minimo, int maximo, int intentos)
{
	int rtn = 0;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && maximo >= minimo && intentos > 0)
	{
		while(intentos > 0)
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 1)
			{
				if(bufferInt <= maximo && bufferInt >= minimo)
				{
					*pResultado = bufferInt;
					rtn = 1;
					break;
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}

			intentos--;
			printf("%s", mensajeError);
		}
	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -4;
	}

	return rtn;
}

//FUNCION obtenerNumDecimal
/// @fn int obtenerNumDecimal(float*, char[], char[], char[], int, int, int)
/// @brief 						Solicita un numero entero o decimal al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado 			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje 				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError 		Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param minimo 				Es el n�mero entero o decimal m�nimo a ser aceptado
/// @param maximo 				Es el n�mero entero o decimal m�ximo a ser aceptado
/// @param intentos 			Cantidad de intentos permitidos
/// @return 					Retorna 1 (EXITO) si se logr� obtener el n�mero decimal,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getFloat,
/// 							retorna -3 (ERROR) si el n�mero ingresado no se encuentra entre el m�ximo y m�nimo permitido y
/// 							retorna -4 (ERROR) si se acaban los intentos.
int obtenerNumDecimal(float* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], float minimo, float maximo, int intentos)
{
	int rtn = 0;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && maximo >= minimo && intentos > 0)
	{
		while(intentos > 0)
		{
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 1)
			{
				if(bufferFloat <= maximo && bufferFloat >= minimo)
				{
					*pResultado = bufferFloat;
					rtn = 1;
					break;
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}

			intentos--;
			printf("%s", mensajeError);
		}
	}
	else{rtn =-1;}


	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -4;
	}

	return rtn;
}

//FUNCI�N obtenerCaracter
/// @fn int obtenerCaracter(char*, char[], char[], char[], char, char, int)
/// @brief 						Solicita un caracter al usuario dentro de un rango, luego de verificarlo devuelve el resultado
/// @param pResultado 			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError 		Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos 	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param minimo 				Es el car�cter m�nimo (en tabla ASCII) a ser aceptado
/// @param maximo 				Es el car�cter m�ximo (en tabla ASCII) a ser aceptado
/// @param intentos 			Cantidad de intentos permitidos
/// @return 					Retorna 1 (EXITO) si se logr� obtener el caracter,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getChar,
/// 							retorna -3 (ERROR) si el char ingresado no se encuentra entre el m�ximo y m�nimo permitido y
/// 							retorna -4 (ERROR) si se acaban los intentos.
int obtenerCaracter(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], char minimo, char maximo, int intentos)
{
	int rtn = 0;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && minimo <= maximo && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s", mensaje);
			if(getChar(&bufferChar) == 1)
			{
				if(bufferChar <= maximo && bufferChar >= minimo)
				{
					*pResultado = bufferChar;
					rtn = 1;
					break;
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}
			intentos--;
			printf("%s", mensajeError);
		}

	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -4;
	}

	return rtn;
}

//FUNCI�N obtenerCaracterDosOpciones
/// @fn int obtenerCaracterDosOpciones(char*, char[], char[], char[], char, char, int)
/// @brief 						Solicita un caracter al usuario entre dos opciones, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param opcionA				Es una de las opciones de caracteres permitida
/// @param opcionB				Es una de las opciones de caracteres permitida
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener el caracter,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getChar,
/// 							retorna -3 (ERROR) si el char ingresado no se encuentra entre los caracteres permitidos y
/// 							retorna -4 (ERROR) si se acaban los intentos.
int obtenerCaracterDosOpciones(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], char opcionA, char opcionB, int intentos)
{
	int rtn = 0;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s", mensaje);
			if(getChar(&bufferChar) == 1)
			{
				if(bufferChar == opcionA || bufferChar == opcionB)
				{
					*pResultado = bufferChar;
					rtn = 1;
					break;
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}
			intentos--;
			printf("%s", mensajeError);
		}

	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -4;
	}

	return rtn;
}

//FUNCI�N obtenerCaracterDosOpciones
/// @fn int obtenerCaracterTresOpciones(char*, char[], char[], char[], char, char, char, int)
/// @brief 						Solicita un caracter al usuario entre tres opciones, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param opcionA				Es una de las opciones de caracteres permitida
/// @param opcionB				Es una de las opciones de caracteres permitida
/// @param opcionC				Es una de las opciones de caracteres permitida
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener el caracter,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getChar,
/// 							retorna -3 (ERROR) si el char ingresado no se encuentra entre los caracteres permitidos y
/// 							retorna -4 (ERROR) si se acaban los intentos.
int obtenerCaracterTresOpciones(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], char opcionA, char opcionB, char opcionC, int intentos)
{
	int rtn = 0;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s", mensaje);
			if(getChar(&bufferChar) == 1)
			{
				if(bufferChar == opcionA || bufferChar == opcionB || bufferChar == opcionC)
				{
					*pResultado = bufferChar;
					rtn = 1;
					break;
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}
			intentos--;
			printf("%s", mensajeError);
		}

	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -4;
	}

	return rtn;
}

//FUNCI�N obtenerCaracterConExcepcion
/// @fn int obtenerCaracterConExcepcion(char*, char[], char[], char[], char, char, char, int)
/// @brief						Solicita un caracter al usuario dentro de un rango con una excepci�n, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param minimo				Es el car�cter m�nimo (en tabla ASCII) a ser aceptado
/// @param maximo				Es el car�cter m�ximo (en tabla ASCII) a ser aceptado
/// @param excepcion			Es el caracter fuera del rango que tambi�n es aceptado
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener el caracter,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getChar,
/// 							retorna -3 (ERROR) si el char ingresado no se encuentra entre el m�ximo y m�nimo permitido y
/// 							retorna -4 (ERROR) si se acaban los intentos.
int obtenerCaracterConExcepcion(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], char minimo, char maximo, char excepcion, int intentos)
{
	int rtn = 0;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && minimo <= maximo && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s", mensaje);
			if(getChar(&bufferChar) == 1)
			{
				if((bufferChar <= maximo && bufferChar >= minimo) || bufferChar == excepcion)
				{
					*pResultado = bufferChar;
					rtn = 1;
					break;
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}
			intentos--;
			printf("%s", mensajeError);
		}

	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -4;
	}

	return rtn;
}

//FUNCI�N obtenerCadena
/// @fn int obtenerCadena(char*, char[], char[], char[], int, int)
/// @brief						Solicita una cadena al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param longitud				Es la longitud m�xima permitida para la cadena
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener la cadena,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getString,
/// 							retorna -3 (ERROR) si la cadena ingresada supera la longitud m�xima permitida y
/// 							retorna -4 (ERROR) si se acaban los intentos.
int obtenerCadena(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos)
{
	char bufferString[1024];
	int rtn = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && longitud > 1 && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s",mensaje);
			if(getString(bufferString,sizeof(bufferString)) == 1)
			{
				if(strnlen(bufferString,sizeof(bufferString)) < longitud)
				{
					strncpy(pResultado, bufferString, longitud);
					rtn = 1;
					break;
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}

			intentos--;
			printf("%s",mensajeError);
		}
	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -4;
	}

	return rtn;
}

//FUNCI�N obtenerCadenaAlfabetica
/// @fn int obtenerCadenaAlfabetica(char*, char[], char[], char[], int, int)
/// @brief 						Solicita una cadena de letras al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param longitud				Es la longitud m�xima permitida para la cadena
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener la cadena,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getString,
/// 							retorna -3 (ERROR) si la cadena ingresada supera la longitud m�xima permitida,
/// 							retorna -4 (ERROR) si hubo alg�n problema en la funci�n esAlfabetica y
/// 							retorna -5 (ERROR) si se acaban los intentos.
int obtenerCadenaAlfabetica(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos)
{
	char bufferString[1024];
	int rtn = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && longitud > 1 && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s",mensaje);
			if(getString(bufferString,sizeof(bufferString)) == 1)
			{
				if(strnlen(bufferString,sizeof(bufferString)) < longitud)
				{
					if(esAlfabetica(bufferString) == 1)
					{
						strncpy(pResultado, bufferString, longitud);
						rtn = 1;
						break;
					}
					else{rtn = -4;}
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}

			intentos--;
			printf("%s",mensajeError);
		}
	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -5;
	}

	return rtn;
}

//FUNCION obtenerCadenaNumerica
/// @fn int obtenerCadenaNumerica(char*, char[], char[], char[], int, int)
/// @brief 						Solicita una cadena de n�meros al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param longitud				Es la longitud m�xima permitida para la cadena
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener la cadena,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getString,
/// 							retorna -3 (ERROR) si la cadena ingresada supera la longitud m�xima permitida,
/// 							retorna -4 (ERROR) si hubo alg�n problema en la funci�n esNumerica y
/// 							retorna -5 (ERROR) si se acaban los intentos.
int obtenerCadenaNumerica(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos)
{
	char bufferString[1024];
	int rtn = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && longitud > 1 && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s",mensaje);
			if(getString(bufferString,sizeof(bufferString)) == 1)
			{
				if(strnlen(bufferString,sizeof(bufferString)) < longitud)
				{
					if(esNumerica(bufferString) == 1)
					{
						strncpy(pResultado, bufferString, longitud);
						rtn = 1;
						break;
					}
					else{rtn = -4;}
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}

			intentos--;
			printf("%s",mensajeError);
		}
	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -5;
	}

	return rtn;
}

//FUNCI�N obtenerCadenaAlfanumerica
/// @fn int obtenerCadenaAlfanumerica(char*, char[], char[], char[], int, int)
/// @brief						Solicita una cadena de letras y n�meros al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param longitud				Es la longitud m�xima permitida para la cadena
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener la cadena,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getString,
/// 							retorna -3 (ERROR) si la cadena ingresada supera la longitud m�xima permitida,
/// 							retorna -4 (ERROR) si hubo alg�n problema en la funci�n esAlfanumerica y
/// 							retorna -5 (ERROR) si se acaban los intentos.
int obtenerCadenaAlfanumerica(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos)
{
	char bufferString[1024];
	int rtn = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && longitud > 1 && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s",mensaje);
			if(getString(bufferString,sizeof(bufferString)) == 1)
			{
				if(strnlen(bufferString,sizeof(bufferString)) < longitud)
				{
					if(esAlfanumerica(bufferString) == 1)
					{
						strncpy(pResultado, bufferString, longitud);
						rtn = 1;
						break;
					}
					else{rtn = -4;}
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}

			intentos--;
			printf("%s",mensajeError);
		}
	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -5;
	}

	return rtn;
}

//FUNCI�N obtenerCadenaAlfanumericaConEspaciosGuiones
/// @fn int obtenerCadenaAlfanumericaConEspaciosGuiones(char*, char[], char[], char[], int, int)
/// @brief						Solicita una cadena de letras, n�meros, espacios o guiones al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param longitud				Es la longitud m�xima permitida para la cadena
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener la cadena,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getString,
/// 							retorna -3 (ERROR) si la cadena ingresada supera la longitud m�xima permitida,
/// 							retorna -4 (ERROR) si hubo alg�n problema en la funci�n esAlfanumericaConEspaciosGuiones y
/// 							retorna -5 (ERROR) si se acaban los intentos.
int obtenerCadenaAlfanumericaConEspaciosGuiones(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos)
{
	char bufferString[1024];
	int rtn = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && longitud > 1 && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s",mensaje);
			if(getString(bufferString,sizeof(bufferString)) == 1)
			{
				if(strnlen(bufferString,sizeof(bufferString)) < longitud)
				{
					if(esAlfanumericaConEspaciosGuiones(bufferString) == 1)
					{
						strncpy(pResultado, bufferString, longitud);
						rtn = 1;
						break;
					}
					else{rtn = -4;}
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}

			intentos--;
			printf("%s",mensajeError);
		}
	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -5;
	}

	return rtn;
}

//FUNCI�N obtenerEmail
/// @fn int obtenerEmail(char*, char[], char[], char[], int, int)
/// @brief 						Solicita un email al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param longitud				Es la longitud m�xima permitida para la cadena
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener la cadena,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getString,
/// 							retorna -3 (ERROR) si la cadena ingresada supera la longitud m�xima permitida,
/// 							retorna -4 (ERROR) si hubo alg�n problema en la funci�n esEmail y
/// 							retorna -5 (ERROR) si se acaban los intentos.
//FUNCI�N esEmail
int obtenerEmail(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos)
{
	char bufferString[1024];
	int rtn = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && longitud > 1 && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s",mensaje);
			if(getString(bufferString,sizeof(bufferString)) == 1)
			{
				if(strnlen(bufferString,sizeof(bufferString)) < longitud)
				{
					if(esEmail(bufferString) == 1)
					{
						strncpy(pResultado, bufferString, longitud);
						rtn = 1;
						break;
					}
					else{rtn = -4;}
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}

			intentos--;
			printf("%s",mensajeError);
		}
	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -5;
	}

	return rtn;
}

//FUNCI�N obtenerPassword
/// @fn int obtenerPassword(char*, char[], char[], char[], int, int, int)
/// @brief 						Solicita una contrase�a alfanumerica al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado			Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
/// @param mensaje				Es el mensaje a ser mostrado en el cual se solicita al usuario el ingreso
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param mensajeSinIntentos	Es el mensaje de error a ser mostrado al acabarse los reintentos
/// @param longitudMinima		Es la longitud m�nima permitida para la cadena
/// @param longitudMaxima		Es la longitud m�xima permitida para la cadena
/// @param intentos				Cantidad de intentos permitidos
/// @return						Retorna 1 (EXITO) si se logr� obtener la cadena,
/// 							retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n,
/// 							retorna -2 (ERROR) si hubo un problema con la funci�n getString,
/// 							retorna -3 (ERROR) si la cadena ingresada supera la longitud m�xima permitida,
/// 							retorna -4 (ERROR) si hubo alg�n problema en la funci�n esAlfanumerica y
/// 							retorna -5 (ERROR) si se acaban los intentos.
int obtenerPassword(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitudMinima, int longitudMaxima, int intentos)
{
	char bufferString[1024];
	int rtn = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeSinIntentos != NULL && longitudMinima > 1 && longitudMaxima >= longitudMinima && intentos >= 1)
	{
		while(intentos > 0)
		{
			printf("%s",mensaje);
			if(getString(bufferString,sizeof(bufferString)) == 1)
			{
				if(strnlen(bufferString,sizeof(bufferString)) <= longitudMaxima && strnlen(bufferString,sizeof(bufferString)) >= longitudMinima)
				{
					if(esAlfanumerica(bufferString) == 1)
					{
						strncpy(pResultado, bufferString, longitudMaxima);
						rtn = 1;
						break;
					}
					else{rtn = -4;}
				}
				else{rtn = -3;}
			}
			else{rtn = -2;}

			intentos--;
			printf("%s",mensajeError);
		}
	}
	else{rtn = -1;}

	if(intentos == 0)
	{
		printf("%s", mensajeSinIntentos);
		rtn = -5;
	}

	return rtn;
}

//FUNCI�N consultarContinuar
/// @fn int consultarContinuar(char[], char[], char[], char, char, int)
/// @brief 						Consulta al usuario si desa continuar
/// @param mensaje				Es el mensaje a ser mostrado en el cual se consulta al usuario si desea continuar
/// @param mensajeError			Es el mensaje de error a ser mostrado ante una entrada inv�lida
/// @param opcionSi				Caracter de respuesta afirmativa
/// @param opcionNo				Caracter de respuesta negativa
/// @return						Retorna 1 si el usuario desea continuar
/// 							y retorna -1 si el usuario no desea continuar.
int consultarContinuar(char mensaje[], char mensajeError[], char opcionSi, char opcionNo)
{
	int rtn = 0;
	char opcion;

	obtenerCaracterDosOpciones(&opcion, mensaje, mensajeError, "\n", opcionSi, opcionNo, 9999);

	if(opcion == opcionSi)
	{
		rtn = 1;
	}
	else{rtn = -1;}

	return rtn;
}


//***FUNCIONES DE OPERACIONES MATEM�TICAS***

//FUNCI�N sumar
/// @fn float sumar(float, float)
/// @brief 		Funci�n que suma dos flotantes
/// @param n1	Flotante al que se le suma
/// @param n2	Flotante a ser sumado
/// @return		Retorna el resultado de la suma
float sumar(float n1, float n2)
{
	float rtn;
	rtn = n1 + n2;

	return rtn;
}

//FUNCI�N restar
/// @fn float restar(float, float)
/// @brief 		Funci�n que resta dos flotantes
/// @param n1	Flotante al que se resta
/// @param n2	Flotante a ser restado
/// @return		Retorna el resultado de la resta
float restar(float n1, float n2)
{
	float rtn;

	rtn = n1 - n2;

	return rtn;
}

//FUNCI�N multiplicar
/// @fn float multiplicar(float, float)
/// @brief 		Funci�n que multiplica dos flotantes
/// @param n1	Flotante al que se multiplica
/// @param n2	Flotante a multiplicar
/// @return		Retorna el resultado de la multiplicaci�n
float multiplicar(float n1, float n2)
{
	float rtn;
	rtn = n1 * n2;

	return rtn;
}

//FUNCI�N dividir
/// @fn float dividir(float, float)
/// @brief				Funci�n que divide dos flotantes
/// @param dividendo	Flotante al que se divide
/// @param divisor		Flotante a ser dividido
/// @return				Retorna el resultado de la divisi�n o 0 si el divisor es igual a 0
float dividir(float dividendo, float divisor)
{
	float rtn = 0;

	if(divisor != 0){
		rtn = dividendo / divisor;
	}

	return rtn;
}

//FUNCI�N potencia
/// @fn float potencia(float, int)
/// @brief 				Calcula la potencia de un flotante frente a un exponente dado
/// @param base			Es el flotante al que se le calcula la potencia
/// @param exponente	Es el exponente de la potencia a calcularse
/// @return				Retorna el resultado de la potencia
float potencia(float base, int exponente)
{
	float rtn = 1;

	if(exponente != 0)
	{
		int i = 0;
		while(i < exponente)
		{
			rtn = rtn * base;
			i++;
		}
	}

	return rtn;
}

//FUNCI�N calcularMontoConDescuento
/// @fn float calcularMontoConDescuento(float, float)
/// @brief 				Calcula un monto con un descuento incluido
/// @param monto		Es el monto bruto sin descuento
/// @param descuento	Es la tasa de descuento a ser aplicada (base 100)
/// @return				Retorna el monto con el descuento incluido
float calcularMontoConDescuento(float monto, float descuento)
{
	float rtn;
	rtn = monto * (100 - descuento)/100;

	return rtn;
}

//FUNCI�N calcularMontoConInteres
/// @fn float calcularMontoConInteres(float, float)
/// @brief 			Calcula un monto con un inter�s incluido
/// @param monto	Es el monto bruto sin inter�s
/// @param interes	Es la tasa de inter�s a ser aplicada (base 100)
/// @return			Retorna el monto con el descuento incluido
float calcularMontoConInteres(float monto, float interes)
{
	float rtn;
	rtn = monto * (100 + interes)/100;

	return rtn;
}

//FUNCI�N buscarMaxIntArray
/// @fn int buscarMaxIntArray(int[], int, int*, int*)
/// @brief 				Busca un m�ximo en un arrays de Ints
/// @param lista		Array en el que se buscar� el m�ximo
/// @param tam			Tama�o del array
/// @param maximo		Puntero al espacio de memoria en el que se guardar� el valor m�ximo
/// @param indexMaximo	Puntero al espacio de memoria en el que se guardar� el index del m�ximo
/// @return				Retorna 1 (EXITO) si se hall� m�ximo y
/// 					retona -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n
int buscarMaxIntArray(int lista[], int tam, int *maximo, int *indexMaximo)
{
	int rtn = 0;
	int i;
	int maximoIngresado;

	if(lista != NULL && tam > 0 && maximo != NULL && indexMaximo != NULL)
	{
		for(i=0 ; i<tam ; i++)
		{
			if(lista[i]>maximoIngresado || i==0)
			{
				maximoIngresado = lista[i];
				*indexMaximo = i;
			}
			rtn = 1;
		}
	}
	else{rtn = -1;}

	*maximo = maximoIngresado;

	return rtn;
}

//FUNCI�N buscarMinIntArray
/// @fn int buscarMinIntArray(int[], int, int*, int*)
/// @brief 				Busca un m�nimo en un arrays de Ints
/// @param lista		Array en el que se buscar� el m�nimo
/// @param tam			Tama�o del array
/// @param minimo		Puntero al espacio de memoria en el que se guardar� el valor m�nimo
/// @param indexMinimo	Puntero al espacio de memoria en el que se guardar� el index del m�nimo
/// @return				Retorna 1 (EXITO) si se hall� m�nimo y
/// 					retona -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n
int buscarMinIntArray(int lista[], int tam, int *minimo, int *indexMinimo)
{
	int rtn = 0;
	int i;
	int minimoIngresado;

	if(lista != NULL && tam > 0 && minimo != NULL && indexMinimo != NULL)
	{
		for(i=0 ; i<tam ; i++)
		{
			if(lista[i]<minimoIngresado || i==0)
			{
				minimoIngresado = lista[i];
				*indexMinimo = i;
			}
			rtn = 1;
		}
	}
	else{rtn = -1;}

	*minimo = minimoIngresado;

	return rtn;
}

//FUNCI�N buscarMaxFloatArray
/// @fn int buscarMaxFloatArray(float[], int, float*, int*)
/// @brief 				Busca un m�ximo en un arrays de Floats
/// @param lista		Array en el que se buscar� el m�ximo
/// @param tam			Tama�o del array
/// @param maximo		Puntero al espacio de memoria en el que se guardar� el valor m�ximo
/// @param indexMaximo	Puntero al espacio de memoria en el que se guardar� el index del m�ximo
/// @return				Retorna 1 (EXITO) si se hall� m�ximo y
/// 					retona -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n
int buscarMaxFloatArray(float lista[], int tam, float *maximo, int *indexMaximo)
{
	int rtn = 0;
	int i;
	float maximoIngresado;

	if(lista != NULL && tam > 0 && maximo != NULL && indexMaximo != NULL)
	{
		for(i=0 ; i<tam ; i++)
		{
			if(lista[i]>maximoIngresado || i==0)
			{
				maximoIngresado = lista[i];
				*indexMaximo = i;
			}
			rtn = 1;
		}
	}
	else{rtn = -1;}

	*maximo = maximoIngresado;

	return rtn;
}

//FUNCI�N buscarMinFloatArray
/// @fn int buscarMinFloatArray(float[], int, float*, int*)
/// @brief 				Busca un m�nimo en un arrays de Floats
/// @param lista		Array en el que se buscar� el m�nimo
/// @param tam			Tama�o del array
/// @param minimo		Puntero al espacio de memoria en el que se guardar� el valor m�nimo
/// @param indexMinimo	Puntero al espacio de memoria en el que se guardar� el index del m�nimo
/// @return				Retorna 1 (EXITO) si se hall� m�nimo y
/// 					retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n
int buscarMinFloatArray(float lista[], int tam, float *minimo, int *indexMinimo)
{
	int rtn = 0;
	int i;
	float minimoIngresado;

	if(lista != NULL && tam > 0 && minimo != NULL && indexMinimo != NULL)
	{
		for(i=0 ; i<tam ; i++)
		{
			if(lista[i]<minimoIngresado || i==0)
			{
				minimoIngresado = lista[i];
				*indexMinimo = i;
			}
			rtn = 1;
		}
	}
	else{rtn = -1;}

	*minimo = minimoIngresado;

	return rtn;
}

//FUNCI�N calcularPromIntArray
/// @fn int calcularPromIntArray(int[], int, float*)
/// @brief 			Calcula el promedio en un array de Ints
/// @param array	Array del que se calcular� el promedio
/// @param tam		Tama�o del array
/// @param promedio	Puntero al espacio de memoria en el que se guardar� el valor promedio
/// @return			Retorna 1 (EXITO) si se pudo calcular el promedio y
/// 				retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n
int calcularPromIntArray(int array[], int tam, int *promedio)
{
	int rtn = 0;
	int acumulador = 0;
	int i;

	if(array != NULL && tam > 0 && promedio != NULL)
	{
		for(i=0 ; i<tam ; i++)
		{
			acumulador += array[i];
		}
		rtn = 1;
	}
	else{rtn = -1;}

	*promedio = acumulador / tam;

	return rtn;
}

//FUNCI�N calcularPromFloatArray
/// @fn int calcularPromFloatArray(float[], int, float*)
/// @brief 			Calcula el promedio en un array de Floats
/// @param array	Array del que se calcular� el promedio
/// @param tam		Tama�o del array
/// @param promedio	Puntero al espacio de memoria en el que se guardar� el valor promedio
/// @return			Retorna 1 (EXITO) si se pudo calcular el promedio y
/// 				retorna -1 (ERROR) si fall� alguna de las validaciones de los argumentos de la funci�n
int calcularPromFloatArray(float array[], int tam, float *promedio)
{
	int rtn = 0;
	float acumulador = 0;
	int i;

	if(array != NULL && tam > 0 && promedio != NULL)
	{
		for(i=0 ; i<tam ; i++)
		{
			acumulador += array[i];
		}
		rtn = 1;
	}
	else{rtn = -1;}

	*promedio = acumulador / tam;

	return rtn;
}


//***FUNCIONES DE TIEMPO***

//FUNCI�N time_current
/// @fn long int time_current(void)
/// @brief 	Funci�n que devuelve la hora actual en segundos
/// @return	Retorna un long int con la hora actual en segundos.
long int time_current(void)
{
	return time(NULL);
}

//FUNCI�N time_add
/// @fn long int time_add(double)
/// @brief 				Funci�n que devuelve la hora actual en segundos, despues de sumarle segundos por par�metro
/// @param secondsAdd	Segundos a sumar a la hora actual
/// @return				Retorna un long int con la hora estimada en segundos.
long int time_add(double secondsAdd)
{
	return secondsAdd + time_current();
}


//***FUNCIONES DE MEN�***

void menuIngreso(void)
{
	puts("\n***************************");
	puts("** 1er EXAMEN LAB I - 1H **");
	puts("***************************");
	puts("");
	puts("1) INGRESAR");
	puts("2) REGISTRARSE");
	puts("");
	puts("0) SALIR");
}

void menuUser(void)
{
	puts("\n***************************");
	puts("** 1er EXAMEN LAB I - 1H **");
	puts("**********USUARIO**********");
	puts("***************************");
	puts("");
	puts("1) COMPRAR");
	puts("2) VENDER");
	puts("3) ESTADO DE COMPRAS");
	puts("4) ESTADO DE VENTAS");
	puts("");
	puts("0) SALIR");
}

void menuAdmin(void)
{
	puts("\n***************************");
	puts("** 1er EXAMEN LAB I - 1H **");
	puts("***********ADMIN***********");
	puts("***************************");
	puts("");
	puts("****GESTI�N E INFORMES*****");
	puts("");
	puts("A) LISTAR ESTADO DE TODOS LOS USUARIOS");
	puts("B) LISTAR TODOS LOS PRODUCTOS POR CATEGORIA");
	puts("C) BAJA DE UN PRODUCTO");
	puts("D) BAJA DE UN USUARIO");
	puts("E) VER TRACKING GLOBAL");
	puts("F) FILTRAR POR NOMBRE DE PRODUCTO");
	puts("");
	puts("0) SALIR");
}

void menuEstadoVentas(void)
{
	puts("\n****GESTI�N E INFORMES*****");
	puts("");
	puts("A) LISTADO DE VENTAS FINALIZADAS");
	puts("B) VER PRODUCTOS");
	puts("");
	puts("0) SALIR");
}

void menuVender(void)
{
	puts("\n******VENDER*******");
	puts("");
	puts("1) ALTA DE PRODUCTO");
	puts("2) REPONER STOCK");
	puts("");
	puts("0) SALIR");
}

void cabeceraListadoProductosCompra(void)
{
	puts("\n**************************************************************");
	puts("   CATEGORIA   ID                   NOMBRE      PRECIO   STOCK");
	puts("--------------------------------------------------------------");
}

void cabeceraListadoProductosVenta(void)
{
	puts("\n**************************************************************");
	puts("   ID                   NOMBRE      PRECIO   STOCK   CATEGORIA");
	puts("--------------------------------------------------------------");
}

void cabeceraListadoUsuarios(void)
{
	puts("\n*************************************************************");
	puts("    ID                                   EMAIL         ESTADO");
	puts("-------------------------------------------------------------");
}

void cabeceraListadoTrackingsCompras(void)
{
	puts("***************************************************************************************");
	puts(" ID.TRACKING          NOMBRE.PRODUCTO  CANTIDAD   PRECIO.TOTAL      ESTADO ID.COMPRADOR");
	puts("---------------------------------------------------------------------------------------");
}

void cabeceraListadoTrackingsVentas(void)
{
	puts("**************************************************************************************");
	puts(" ID.TRACKING          NOMBRE.PRODUCTO  CANTIDAD   PRECIO.TOTAL      ESTADO ID.VENDEDOR");
	puts("--------------------------------------------------------------------------------------");
}

void cabeceraListadoTrackingGlobal(void)
{
	puts("\n************************************************************");
	puts("    ID.TRACKING         ESTADO   ID.COMPRADOR    ID.VENDEDOR");
	puts("------------------------------------------------------------");
}

