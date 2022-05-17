/*
 * Usuarios.h
 *
 *  Created on: 12 may. 2022
 *      Author: fserrano
 */

#ifndef USUARIOS_H_
#define USUARIOS_H_

#include "General.h"

#define IDUSUARIO_INICIAL 1
#define CANT_USUARIOS 100
#define ADMIN 0
#define USER 1
#define ACTIVO 1
#define LIBRE 0
#define BANEADO -1

//ESTRUCTURAS
typedef struct{
	int idUsuario;
	short int tipo;
	char email[41];
	char password[11];
	char direccion[51];
	int codPostal;
	short int isEmpty;
}eUsuario;

//PROTOTIPOS
int eUsuario_inicializar(eUsuario lista[], int tam);
void eUsuario_hardcodearUsuarios(eUsuario lista[], int tam);
int eUsuario_buscarEspacioLibre(eUsuario lista[], int tam);
eUsuario eUsuario_cargarUnUsuario(eUsuario lista[], int tam, int* rtn);
int eUsuario_alta(eUsuario lista[], int tam);
int eUsuario_buscarIndexPorIdDado(eUsuario lista[], int tam, int id);
int eUsuario_validarUsuario(eUsuario lista[], int tam, int* pIndex);
void eUsuario_listarUnUsuario(eUsuario u);
int eUsuario_listarTodosExceptoEstado(eUsuario lista[], int tam, int estado);
int eUsuario_darDeBajaUsuario(eUsuario* lista, int tam, int indexUsuarioActivo);

#endif /* USUARIOS_H_ */
