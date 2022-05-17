/*
 * Trackings.h
 *
 *  Created on: 12 may. 2022
 *      Author: fserrano
 */

#ifndef TRACKINGS_H_
#define TRACKINGS_H_

#include "General.h"

#define IDTRACKING_INICIAL 1000
#define CANT_TRACKINGS 1000
#define LIBRE 0
#define EN_VIAJE 1
#define ENTREGADO 2
#define CANCELADO -1

//ESTRUCTURAS
typedef struct{
	int idTracking;
	int FK_idProducto;
	int FK_idUsuarioComprador;
	int cantidad;
	int distanciaKm;
	long int horaLlegada;
	short int isEmpty;
}eTracking;

//PROTOTIPOS
int eTracking_inicializar(eTracking lista[], int tam);
int eTracking_buscarEspacioLibre(eTracking lista[], int tam);
int eTracking_altaDeId(eTracking lista[], int tam, int* id);
int eTrackings_buscarTrackings(eTracking lista[], int tam);
int eTracking_buscarTrackingsPorIdComprador(eTracking lista[], int tam, int idComprador);
int eTracking_buscarIndexPorIdDado(eTracking lista[], int tam, int id, int estado);
int eTracking_cancelarTracking(eTracking* lista, int tam);

#endif /* TRACKINGS_H_ */
