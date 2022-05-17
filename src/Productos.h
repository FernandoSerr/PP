/*
 * Productos.h
 *
 *  Created on: 12 may. 2022
 *      Author: fserrano
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#include "General.h"

#define IDPRODUCTO_INICIAL 1
#define CANT_PRODUCTOS 300
#define EN_STOCK 1
#define LIBRE 0
#define BAJA -1
#define CAT_TECNOLOGIA 1
#define CAT_MODA 2
#define CAT_HOGAR 3
#define CAT_JUGUETES 4
#define CAT_PERFUMERIA 5
#define CAT_OTROS 6


// ESTRUCTURAS
typedef struct{
	int idProducto;
	char nombreProducto[26];
	float precio;
	int categoria;
	char nombreCategoria[12];
	int stock;
	int FK_idUsuarioVendedor;
	short int isEmpty;
}eProducto;

//PROTOTIPOS
int eProducto_inicializar(eProducto lista[], int tam);
int eProducto_buscarEspacioLibre(eProducto lista[], int tam);
eProducto eProducto_cargarUnProducto();
void eProducto_listarUnoParaCompra(eProducto p);
int eProducto_listarTodosPorCategoria(eProducto lista[], int tam, int estado, int categoria);
void eProducto_listarTodos(eProducto lista[], int tam, int estado);
int eProducto_buscarIndexPorId(eProducto lista[], int tam);
int eProducto_buscarIndexPorIdDado(eProducto lista[], int tam, int id);
int eProducto_disminuirStock(eProducto lista[], int tam, int index, int cantCompra);
int eProducto_ordenarPorNombre(eProducto* lista, int tam, int orden);
int eProducto_ordenarPorId(eProducto* lista, int tam, int orden);
int eProducto_darDeBajaProducto(eProducto* lista, int tam);
int eProducto_buscarProductosPorEstado(eProducto lista[], int tam, int estado);
int eProducto_buscarProductosPorEstadoPorVendedor(eProducto lista[], int tam, int estado, int idVendedor);
int eProducto_reponerStock(eProducto lista[], int tam, int idVendedor);
int eProducto_ordenarPorStock(eProducto* lista, int tam, int orden);
int eProducto_listarTodosPorNombre(eProducto lista[], int tam);

#endif /* PRODUCTOS_H_ */
