/*
 * General.h
 *
 *  Created on: 12 may. 2022
 *      Author: fserrano
 */

#ifndef GENERAL_H_
#define GENERAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DESCENDENTE 1
#define ASCENDENTE -1

//VALIDACIONES DE IMPUTS
int obtenerNumEntero(int* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int minimo, int maximo, int intentos);
int obtenerNumDecimal(float* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], float minimo, float maximo, int intentos);
int obtenerCaracter(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], char minimo, char maximo, int intentos);
int obtenerCadenaAlfabetica(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos);
int obtenerCadenaNumerica(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos);
int obtenerCadenaAlfanumerica(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos);
int obtenerCadenaAlfanumericaConEspaciosGuiones(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos);
int obtenerEmail(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitud, int intentos);
int obtenerPassword(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], int longitudMinima, int longitudMaxima, int intentos);
int obtenerCaracterDosOpciones(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], char opcionA, char opcionB, int intentos);
int obtenerCaracterTresOpciones(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], char opcionA, char opcionB, char opcionC, int intentos);
int obtenerCaracterConExcepcion(char* pResultado, char mensaje[], char mensajeError[], char mensajeSinIntentos[], char minimo, char maximo, char excepcion, int intentos);
int consultarContinuar(char mensaje[], char mensajeError[], char opcionSi, char opcionNo);

//OPERACIONES MATEMÁTICAS
float sumar(float n1, float n2);
float restar(float n1, float n2);
float multiplicar(float n1, float n2);
float dividir(float dividendo, float divisor);
float potencia(float base, int exponente);
float calcularMontoConDescuento(float monto, float descuento);
float calcularMontoConInteres(float monto, float interes);
int buscarMaxIntArray(int lista[], int tam, int *maximo, int *indexMaximo);
int buscarMinIntArray(int lista[], int tam, int *minimo, int *indexMinimo);
int buscarMaxFloatArray(float lista[], int tam, float *maximo, int *indexMaximo);
int buscarMinFloatArray(float lista[], int tam, float *minimo, int *indexMinimo);
int calcularPromIntArray(int array[], int tam, int *promedio);
int calcularPromFloatArray(float array[], int tam, float *promedio);

//FUNCIONES DE TIEMPO
long int time_current(void);
long int time_add(double secondsAdd);

//MENÚES
void menuIngreso(void);
void menuUser(void);
void menuAdmin(void);
void menuEstadoVentas(void);
void menuVender(void);
void cabeceraListadoProductosCompra(void);
void cabeceraListadoProductosVenta(void);
void cabeceraListadoUsuarios(void);
void cabeceraListadoTrackingsCompras(void);
void cabeceraListadoTrackingsVentas(void);
void cabeceraListadoTrackingGlobal(void);

#endif /* GENERAL_H_ */
