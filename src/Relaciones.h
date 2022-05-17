/*
 * Relaciones.h
 *
 *  Created on: 13 may. 2022
 *      Author: fserrano
 */

#ifndef RELACIONES_H_
#define RELACIONES_H_

#include "General.h"
#include "Productos.h"
#include "Usuarios.h"
#include "Trackings.h"

int rPU_altaDeProducto(eUsuario arrayUsuarios[], int tamUsuarios, eProducto arrayProductos[], int tamProductos, int indexVendedor);
int rTU_altaDeTracking(eTracking arrayTrackings[], int tamTrackings, eUsuario arrayUsuarios[], int tamUsuarios, int indexUsuario, int idProducto, int cantComprada);
int rPUT_comprarProducto(eProducto arrayProductos[], int tamProductos, eTracking arrayTrackings[], int tamTrackings, eUsuario arrayUsuarios[], int tamUsuarios, int indexUsuario);
int rTP_listarTrackingGlobal(eTracking* arrayTrackings, int tamTrackings, eProducto arrayProductos[], int tamProductos);
int rTPU_listarTrackingsCompras(eTracking* arrayTrackings, int tamTrackings, eProducto arrayProductos[], int tamProductos, eUsuario arrayUsuarios[], int tamUsuarios,int usuarioActivo);
int rTPU_listarTrackingsVentasFinalizadas(eTracking* arrayTrackings, int tamTrackings, eProducto arrayProductos[], int tamProductos, eUsuario arrayUsuarios[], int tamUsuarios,int usuarioActivo);
int rPU_listarProductosVendedor(eProducto arrayProductos[], int tamProductos, eUsuario arrayUsuarios[], int tamUsuarios, int estado, int usuarioActivo);
int rTP_buscarTrackingsPorIdVendedor(eTracking arrayTrackings[], int tamTrackings, eProducto arrayProductos[], int tamProductos, int idVendedor);

#endif /* RELACIONES_H_ */
