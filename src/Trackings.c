/*
 * Trackings.c
 *
 *  Created on: 12 may. 2022
 *      Author: fserrano
 */

#include "Trackings.h"

int eTracking_inicializar(eTracking lista[], int tam)
{
	int rtn = 0;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = LIBRE;
		}
		rtn = 1;
	}
	else {rtn = -1;}

	return rtn;
}

static int eTracking_obtenerIdUnico(void);
static int eTracking_obtenerIdUnico()
{
	static int idAutoincremental = IDTRACKING_INICIAL;
	return idAutoincremental++;
}

int eTracking_buscarEspacioLibre(eTracking lista[], int tam)
{
	int rtn = 0;
	int flag = 0;
	int i;

	if (lista != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty == LIBRE)
			{
				flag = 1;
				rtn = i; //retorno index
				break;
			}
		}

		if (flag == 0) //si no se hall� index
		{
			rtn = -2;
		}
	}
	else{rtn = -1;}

	return rtn;
}

int eTracking_altaDeId(eTracking lista[], int tam, int* id)
{
	int rtn = 0;
	int indexLibre;

	if (lista != NULL && tam > 0 && id != NULL)
	{
		indexLibre = eTracking_buscarEspacioLibre(lista, tam);

		if (indexLibre >= 0) //si index v�lido
		{
			*id = eTracking_obtenerIdUnico(); //guardo id en puntero *id

			rtn = indexLibre; // retorno index
		}
		else{rtn = -1;}
	}
	else{rtn = -1;}

	return rtn;
}

int eTrackings_buscarTrackings(eTracking lista[], int tam)
{
	int rtn = -1;
	int i;

	if(lista != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			if(lista[i].isEmpty != LIBRE)
			{
				rtn = 1; //retorno 1 si existe alg�n tracking creado
				break;
			}
		}
	}

	return rtn;
}

int eTracking_buscarTrackingsPorIdComprador(eTracking lista[], int tam, int idComprador)
{
	int rtn = -1;
	int i;

	if(lista != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			if(lista[i].isEmpty != LIBRE && lista[i].FK_idUsuarioComprador == idComprador)
			{
				rtn = 1; //retorno 1 si existe alg�n tracking creado, con id de usuario comprador igual al dado
				break;
			}
		}
	}

	return rtn;
}

int eTracking_buscarIndexPorIdDado(eTracking lista[], int tam, int id, int estado)
{
	int rtn = 0;
	int flag = 0;
	int i;

	if (lista != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty == estado)
			{
				if (lista[i].idTracking == id)
				{
					flag = 1;
					rtn = i; //retorno index
					break;
				}
			}
		}

		if (flag == 0) //si no se hall� el id
		{
			rtn = -1;
		}
	}
	else{rtn = -3;}

	return rtn;
}

int eTracking_cancelarTracking(eTracking* lista, int tam)
{
	int rtn = 0;
	int bufferIndex;
	int bufferId;

	if(lista != NULL && tam > 0)
	{
		obtenerNumEntero(&bufferId, "\nIngresar el Id del tracking de la compra que quiere cancelar: ", "\nEntrada inv�lida",
				"\nDemasiados intentos fallidos, reiniciando.", IDTRACKING_INICIAL, IDTRACKING_INICIAL + CANT_TRACKINGS -1 , 5);
		bufferIndex = eTracking_buscarIndexPorIdDado(lista, tam, bufferId, EN_VIAJE);

		if(bufferIndex < 0 || lista[bufferIndex].isEmpty != EN_VIAJE) //si el index es inv�lido o el tracking no est� en viaje
		{
			rtn = -1;
			puts("\nNo se ha realizado la baja por ID err�neo.");
		}
		else
		{
			if(consultarContinuar("\nEst� seguro de que quiere dar de baja esta compra? Si est� seguro ingrese S, si no ingrese N.",
					"\nEntrada inv�lida", 'S', 'N') == 1) //pido confirmaci�n a usuario
			{
				lista[bufferIndex].isEmpty = CANCELADO; //cambio estado
			}
			else{rtn = -1;}
		}
	}
	else{rtn = -1;}

	return rtn;
}
