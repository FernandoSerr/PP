/*
 * Usuarios.c
 *
 *  Created on: 12 may. 2022
 *      Author: fserrano
 */

#include "Usuarios.h"

#define CANT_USUARIOS_HARDCODEADOS 5

int eUsuario_inicializar(eUsuario lista[], int tam)
{
	int rtn = 0;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = LIBRE;
		}
		rtn = 1;

		//HARDCODEO DE USUARIOS
		eUsuario_hardcodearUsuarios(lista, tam);
	}
	else {rtn = -1;}

	return rtn;
}

void eUsuario_hardcodearUsuarios(eUsuario lista[], int tam)

{
	if (lista != NULL && tam > 0)
	{
		lista[0].idUsuario = 1;
		lista[0].tipo = ADMIN;
		strcpy(lista[0].email, "garcos.malperin@lercadomibre.com");
		strcpy(lista[0].password, "password");
		strcpy(lista[0].direccion, "Paseo Culon 100");
		lista[0].codPostal = 1870;
		lista[0].isEmpty = ACTIVO;

		lista[1].idUsuario = 2;
		lista[1].tipo = USER;
		strcpy(lista[1].email, "ricardo_fort@yahoo.com");
		strcpy(lista[1].password, "mamaaaa");
		strcpy(lista[1].direccion, "Maiame 69");
		lista[1].codPostal = 7570;
		lista[1].isEmpty = ACTIVO;

		lista[2].idUsuario = 3;
		lista[2].tipo = USER;
		strcpy(lista[2].email, "diegoarmando@gmail.com");
		strcpy(lista[2].password, "eeeeee");
		strcpy(lista[2].direccion, "Segurola y Habana");
		lista[2].codPostal = 1010;
		lista[2].isEmpty = ACTIVO;

		lista[3].idUsuario = 4;
		lista[3].tipo = ADMIN;
		strcpy(lista[3].email, "a@a.a");
		strcpy(lista[3].password, "1234");
		strcpy(lista[3].direccion, "25 de Mayo 25");
		lista[3].codPostal = 5002;
		lista[3].isEmpty = ACTIVO;

		lista[4].idUsuario = 5;
		lista[4].tipo = USER;
		strcpy(lista[4].email, "u@u.u");
		strcpy(lista[4].password, "1234");
		strcpy(lista[4].direccion, "9 de Julio 9");
		lista[4].codPostal = 100;
		lista[4].isEmpty = ACTIVO;
	}
}

static int eUsuario_obtenerIdUnico(void);
static int eUsuario_obtenerIdUnico()
{
	static int idAutoincremental = IDUSUARIO_INICIAL + CANT_USUARIOS_HARDCODEADOS; //sumo los usuarios harcodeados
	return idAutoincremental++;
}

int eUsuario_buscarEspacioLibre(eUsuario lista[], int tam)
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

		if (flag == 0) //no se halló index
		{
			rtn = -1;
		}
	}
	else{rtn = -3;}

	return rtn;
}

eUsuario eUsuario_cargarUnUsuario(eUsuario lista[], int tam, int* rtn)
{
	eUsuario u;
	int rtnEmail;
	int auxContinuar;
	int i;
	*rtn = 0;

	do
	{
		u.tipo = 1; //Un usuario que se da de alta por si mismo siempre es tipo USER

		//Pido el email
		rtnEmail = obtenerEmail(u.email, "\nIngrese email: ", "\nEntrada inválida.",
				"\nSe le han acabado los intentos.", 40, 4);
		for(i = 0; i < tam; i++)
		{
			if(strcmp(u.email, lista[i].email) == 0) //Reviso si el email se encuentra actualmente registrago o baneado
			{
				rtnEmail = -1;
				*rtn = -1;
				auxContinuar = consultarContinuar("\nEmail ya registrado. Pulse 1 si quiere registrarse con otro email "
						"o 0 si quiere volver al menú inicial: ", "\nEntrada inválida.", '1', '0');
			}
		}

		if(rtnEmail == 1) //si el email es correcto y no esta registrado/baneado, pido datos
		{
			if(obtenerPassword(u.password, "\nIngrese password: ", "\nEntrada inválida.",
					"\nSe le han acabado los intentos.", 4, 10, 4) == 1
					&& obtenerCadenaAlfanumericaConEspaciosGuiones(u.direccion, "\nIngrese domicilio: ",
							"\nEntrada inválida.", "\nSe le han acabado los intentos", 50, 4) == 1
					&& obtenerNumEntero(&u.codPostal, "\nIngrese código postal: ", "\nEntrada inválida.",
							"\nSe le han acabado los intentos", 1, 9999, 4) == 1)
			{
				*rtn = 1;
			}
			else
			{
				*rtn = -1;
			}
		}
	}
	while(rtnEmail == -1 && auxContinuar == 1); //mientras que el email sea inválido o registrado y el usuario quiera volver a intentarlo

	return u;
}

int eUsuario_alta(eUsuario lista[], int tam)
{
	int rtn = 0;
	int indexLibre;
	int validacionCarga;
	eUsuario auxiliarUsuario;

	indexLibre = eUsuario_buscarEspacioLibre(lista, tam);

	if (lista != NULL && tam > 0)
	{
		if (indexLibre >= 0) //index inválido (si error en buscarEspacioLibre)
		{
			auxiliarUsuario = eUsuario_cargarUnUsuario(lista, tam, &validacionCarga);

			if(validacionCarga == 1) //(si error en cargarUnUsuario)
			{
				auxiliarUsuario.idUsuario = eUsuario_obtenerIdUnico();
				auxiliarUsuario.isEmpty = ACTIVO;

				lista[indexLibre] = auxiliarUsuario;
				rtn = indexLibre;

			}
			else{rtn = -3;}
		}
		else{rtn = -2;}
	}
	else{rtn = -1;}

	return rtn;
}

int eUsuario_buscarIndexPorIdDado(eUsuario lista[], int tam, int id)
{
	int rtn = 0;
	int flag = 0;
	int i;

	if (lista != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty == ACTIVO)
			{
				if (lista[i].idUsuario == id)
				{
					flag = 1;
					rtn = i; //retorno index
					break;
				}
			}
		}

		if (flag == 0) //no se halló id
		{
			rtn = -2;
		}
	}
	else{rtn = -1;}

	return rtn;
}

int eUsuario_validarUsuario(eUsuario lista[], int tam, int* pIndex)
{
	int rtn = 0;
	int i, j;
	int flag = 0;
	char bufferEmail[31];
	char bufferPassword[11];

	if(lista != NULL && tam > 0 && pIndex != NULL)
	{
		if(obtenerEmail(bufferEmail, "\nIngrese su email: ", "\nEmail no registrado, intentelo nuevamente.",
				"\nDemasiados intentos fallidos.", 40, 3) == 1) //si email ingresado es válido
		{
			for(i = 0; i < tam; i++)
			{
				if(strcmp(bufferEmail, lista[i].email) == 0 && lista[i].isEmpty != BANEADO) //chequeo que el email se encuentre registrado y no baneado
				{
					*pIndex = i;
					flag = 1;
					break;
				}
				else
				{
					rtn = -1;
				}
			}
		}

		if(flag == 1) //si el email es válido, registrado y no baneado
		{
			for(j=0; j<3; j++) //3 intentos
			{
				if(obtenerPassword(bufferPassword, "\nIngrese su contraseña: ", "\nContraseña incorrecta. ",
						"", 4, 10, 1) == 1)
				{
					if(strcmp(bufferPassword, lista[i].password) == 0) //chequeo que la password ingresada coincida
					{
						rtn = 1;
						break;
					}
					else
					{
						puts("\nContraseña incorrecta. ");
						rtn = -1;
					}
				}
			}
			if(rtn == -1)
			{
				puts("Reiniciando sistema.");
			}
		}
		else
		{
			puts("\nEmail no registrado. Registrese en opción 2.");
			rtn = -1;
		}
	}
	else {rtn = -1;}

	return rtn;
}

void eUsuario_listarUnUsuario(eUsuario u)
{
	char textoEstado[10];

	switch(u.isEmpty) //switch para listar el estado como texto
	{
	case 1:
		strcpy(textoEstado, "Activo");
		break;
	case -1:
		strcpy(textoEstado, "Dado de baja");
		break;
	default:
		strcpy(textoEstado, "Libre");
	}

	printf("%6d%40s%15s\n", u.idUsuario, u.email, textoEstado);
}

int eUsuario_listarTodosExceptoEstado(eUsuario lista[], int tam, int estado)
{
	int rtn = 0;
	int i;

	if (lista != NULL && tam > 0)
	{
		cabeceraListadoUsuarios();

		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty != estado)
			{
				eUsuario_listarUnUsuario(lista[i]);
			}
			rtn = 1;
		}
		puts("*************************************************************");
	}
	else{rtn = -1;}

	return rtn;
}

int eUsuario_darDeBajaUsuario(eUsuario* lista, int tam, int indexUsuarioActivo)
{
	int rtn = 0;
	int bufferIndex;
	int bufferId;

	if(lista != NULL && tam > 0 && indexUsuarioActivo >= 0)
	{
		obtenerNumEntero(&bufferId, "\nIngresar el Id del usuario que quiere dar de baja: ", "\nEntrada inválida",
				"\nDemasiados intentos fallidos, reiniciando.", IDUSUARIO_INICIAL, IDUSUARIO_INICIAL + CANT_USUARIOS -1 , 5);

		bufferIndex = eUsuario_buscarIndexPorIdDado(lista, tam, bufferId);
		if(bufferIndex < 0 || lista[bufferIndex].isEmpty != ACTIVO) //compruebo que el index sea válido y sea ACTIVO
		{
			rtn = -1;
			puts("\nEl ID ingresado no pertenece a un usuario registrado.");
		}
		else if(bufferId == lista[indexUsuarioActivo].idUsuario) //Si el ID ingresado coincide con el usuario activo
		{
			rtn = -1;
			puts("\nNo puedes dar de baja tu propio usuario.");
		}
		else
		{
			if(consultarContinuar("\nEstá seguro de que quiere dar de baja este usuario? Si está seguro ingrese S, si no ingrese N.",
					"\nEntrada inválida", 'S', 'N') == 1) //Consulto si está seguro
			{
				lista[bufferIndex].isEmpty = BANEADO; //cambio de estado
			}
			else{rtn = -1;}
		}
	}
	else{rtn = -1;}

	return rtn;
}
