/*
 * Relaciones.c
 *
 *  Created on: 13 may. 2022
 *      Author: fserrano
 */

#include "Relaciones.h"


int rPU_altaDeProducto(eUsuario arrayUsuarios[], int tamUsuarios,
		eProducto arrayProductos[], int tamProductos, int indexVendedor)
{
	int rtn = 0;
	int indexLibreProducto;
	eProducto bufferProducto;

	if (arrayUsuarios != NULL && arrayProductos != NULL && tamUsuarios > 0 && tamProductos > 0 && indexVendedor >= 0)
	{
		indexLibreProducto = eProducto_buscarEspacioLibre(arrayProductos, tamProductos); //busco index libre

		if (indexLibreProducto > -1) //si se halló index
		{
			if (indexVendedor > -1)
			{
				bufferProducto = eProducto_cargarUnProducto(); //cargo datos generales
				bufferProducto.FK_idUsuarioVendedor = arrayUsuarios[indexVendedor].idUsuario; //genero la FK del id del vendedor
				bufferProducto.isEmpty = EN_STOCK; // cambio estado

				arrayProductos[indexLibreProducto] = bufferProducto;

				rtn = 1;
			}
			else {rtn = -3;}
		}
		else {rtn = -2;}
	}
	else {rtn = -1;}

	return rtn;
}

int rTU_altaDeTracking(eTracking arrayTrackings[], int tamTrackings,
		eUsuario arrayUsuarios[], int tamUsuarios, int indexUsuario, int idProducto, int cantComprada)
{
	int rtn = 0;
	int indexLibreTracking;
	int bufferId;
	int bufferCodPostal;
	eTracking auxiliarTracking;


	if (arrayTrackings != NULL && arrayUsuarios != NULL && tamTrackings > 0 &&
			tamUsuarios > 0 && idProducto > 0 && cantComprada > 0)
	{
		indexLibreTracking = eTracking_altaDeId(arrayTrackings, tamTrackings, &bufferId); //busco index libre

		if (indexLibreTracking >= 0) //si se halló index
		{
			//cargo datos
			auxiliarTracking.idTracking = bufferId;
			auxiliarTracking.cantidad = cantComprada;
			auxiliarTracking.FK_idProducto = idProducto;
			auxiliarTracking.FK_idUsuarioComprador = arrayUsuarios[indexUsuario].idUsuario;
			bufferCodPostal = arrayUsuarios[indexUsuario].codPostal;

			//calculo distanciaKm mediante código postal
			if(bufferCodPostal >= 1000)
			{
				auxiliarTracking.distanciaKm = 20;
			}
			else if(bufferCodPostal >= 3000)
			{
				auxiliarTracking.distanciaKm = 30;
			}
			else if(bufferCodPostal >= 5000)
			{
				auxiliarTracking.distanciaKm = 50;
			}
			else if(bufferCodPostal >= 8000)
			{
				auxiliarTracking.distanciaKm = 80;
			}
			else if(bufferCodPostal >= 9999)
			{
				auxiliarTracking.distanciaKm = 150;
			}

			auxiliarTracking.horaLlegada = time_add(auxiliarTracking.distanciaKm * 2); //calculo horario de llegada con funcion time_add

			auxiliarTracking.isEmpty = EN_VIAJE; //cambio estado

			arrayTrackings[indexLibreTracking] = auxiliarTracking;
			rtn = indexLibreTracking; // retorno index
		}
		else{rtn = -2;}
	}
	else{rtn = -1;}

	return rtn;
}

int rPUT_comprarProducto(eProducto arrayProductos[], int tamProductos, eTracking arrayTrackings[], int tamTrackings,
		eUsuario arrayUsuarios[], int tamUsuarios, int indexUsuario)
{
	int rtn = 0;
	int bufferIdProducto;
	int bufferIndexProducto;
	int bufferCantCompra;
	int bufferStock;
	float bufferPrecioTotal;
	int indexTracking;

	if(arrayProductos != NULL && tamProductos > 0 && arrayTrackings != NULL && tamTrackings > 0 &&
			arrayUsuarios != NULL && tamUsuarios > 0 && indexUsuario >= 0)
	{
		eProducto_ordenarPorId(arrayProductos, tamProductos, -1); //ordeno por id
		eProducto_listarTodos(arrayProductos, tamProductos, EN_STOCK); //listo agrupados por categoría
		obtenerNumEntero(&bufferIdProducto, "\nIngresar ID del producto a comprar: ",
				"\nEntrada inválida", "\nDemasiados intentos fallidos, reiniciando.", 1, tamProductos, 5); //pido id al usuario

		bufferIndexProducto = eProducto_buscarIndexPorIdDado(arrayProductos, tamProductos, bufferIdProducto); //busco index asociado

		bufferStock = arrayProductos[bufferIndexProducto].stock; //busco stock del producto

		obtenerNumEntero(&bufferCantCompra, "\nIngresar cantidad de unidades a comprar: ",
				"\nEntrada inválida o superior a la cantidad en stock.", "\nDemasiados intentos fallidos, reiniciando.",
				1, bufferStock, 5); //pido cant a comprar

		bufferPrecioTotal = multiplicar(bufferCantCompra, arrayProductos[bufferIndexProducto].precio); //calculo precio final

		printf("\nResumen del pedido:\n\tProducto: %s\n\tCantidad: %d\n\tPrecio total: $%.2f",
				arrayProductos[bufferIndexProducto].nombreProducto, bufferCantCompra, bufferPrecioTotal); //resumen del pedido

		if(consultarContinuar("\nDesea confirmar su compra? Ingrese S por sí y N por no: ",
				"\nEntrada inválida", 'S', 'N') == 1) //pido confirmación
		{
			eProducto_disminuirStock(arrayProductos, tamProductos, bufferIndexProducto, bufferCantCompra); //bajo el stock en el producto

			indexTracking = rTU_altaDeTracking(arrayTrackings, tamTrackings, arrayUsuarios, tamUsuarios, indexUsuario,
					bufferIdProducto, bufferCantCompra); //genero un tracking

			printf("\nCompra realizada exitosamente.\n\tNúmero de tracking: %d\n", arrayTrackings[indexTracking].idTracking); //mensaje compra exitosa

			rtn = 1;
		}
		else
		{
			puts("\nNo se ha realizado la compra."); //mensaje compra fallida
		}
	}
	else{rtn = -1;}

	return rtn;
}

int rTP_listarTrackingGlobal(eTracking* arrayTrackings, int tamTrackings, eProducto arrayProductos[], int tamProductos)
{
	int rtn = 0;
	int i;
	int bufferIndexProducto;
	double diferenciaHoraria;
	char textoEstado[10];

	if (arrayTrackings != NULL && arrayProductos != NULL && tamTrackings > 0 && tamProductos > 0)
	{
		cabeceraListadoTrackingGlobal();

		for (i = 0; i < tamTrackings; i++)
		{
			if (arrayTrackings[i].isEmpty != LIBRE) //dejo afuera los index libres
			{
				if(arrayTrackings[i].isEmpty == EN_VIAJE) //analizo los en viaje
				{
					diferenciaHoraria = difftime(arrayTrackings[i].horaLlegada, time_current());
					if(diferenciaHoraria <= 0) //si la hora de llegada supera a la actual
					{
						arrayTrackings[i].isEmpty = ENTREGADO; // cambio de estado
					}
				}

				switch(arrayTrackings[i].isEmpty) //switch para incluir estado como texto en listado
				{
				case 1:
					strcpy(textoEstado, "En viaje");
					break;
				case 2:
					strcpy(textoEstado, "Entregado");
					break;
				case -1:
					strcpy(textoEstado, "Cancelado");
					break;
				default:
					strcpy(textoEstado, "Libre");
				}

				bufferIndexProducto = eProducto_buscarIndexPorIdDado(arrayProductos, tamProductos,
						arrayTrackings[i].FK_idProducto); //busco index de producto para listar el id del vendedor asociado

				printf("%15d%15s%15d%15d\n", arrayTrackings[i].idTracking, textoEstado,
						arrayTrackings[i].FK_idUsuarioComprador, arrayProductos[bufferIndexProducto].FK_idUsuarioVendedor); //listo
			}
			rtn = 1;
		}
		puts("************************************************************");
	}
	else{rtn = -1;}

	return rtn;
}

int rTPU_listarTrackingsCompras(eTracking* arrayTrackings, int tamTrackings, eProducto arrayProductos[], int tamProductos,
		eUsuario arrayUsuarios[], int tamUsuarios,int usuarioActivo)
{
	int rtn = 0;
	int i;
	int bufferIndexProducto;
	int bufferIdUsuarioActivo;
	double diferenciaHoraria;
	char textoEstado[10];
	float bufferPrecioTotal;
	char bufferNombreProducto[26];

	if (arrayTrackings != NULL && arrayProductos != NULL && arrayUsuarios != NULL &&
			tamTrackings > 0 && tamProductos > 0 && tamUsuarios > 0 && usuarioActivo >= 0)
	{
		cabeceraListadoTrackingsCompras();

		for (i = 0; i < tamTrackings; i++)
		{
			if (arrayTrackings[i].isEmpty != LIBRE) //dejo afuera los index libres
			{
				if(arrayTrackings[i].isEmpty == EN_VIAJE) //analizo los en viaje
				{
					diferenciaHoraria = difftime(arrayTrackings[i].horaLlegada, time_current());
					if(diferenciaHoraria <= 0) //si la hora de llegada supera a la actual
					{
						arrayTrackings[i].isEmpty = ENTREGADO; // cambio de estado
					}
				}

				switch(arrayTrackings[i].isEmpty) //switch para incluir estado como texto en listado
				{
				case 1:
					strcpy(textoEstado, "En viaje");
					break;
				case 2:
					strcpy(textoEstado, "Entregado");
					break;
				case -1:
					strcpy(textoEstado, "Cancelado");
					break;
				default:
					strcpy(textoEstado, "Libre");
				}

				bufferIdUsuarioActivo  = arrayUsuarios[usuarioActivo].idUsuario; //busco id
				if(bufferIdUsuarioActivo == arrayTrackings[i].FK_idUsuarioComprador) //listo solo los asociados al id del comprador
				{
					bufferIndexProducto = eProducto_buscarIndexPorIdDado(arrayProductos, tamProductos,
							arrayTrackings[i].FK_idProducto);

					strcpy(bufferNombreProducto, arrayProductos[bufferIndexProducto].nombreProducto);

					bufferPrecioTotal = multiplicar(arrayTrackings[i].cantidad, arrayProductos[bufferIndexProducto].precio); //calculo precio total de compra

					printf("%12d%25s%10d%15.2f%12s%12d\n", arrayTrackings[i].idTracking, bufferNombreProducto, arrayTrackings[i].cantidad,
							bufferPrecioTotal, textoEstado, arrayProductos[bufferIndexProducto].FK_idUsuarioVendedor); //listo
				}
				else{rtn = -1;}
			}
			rtn = 1;
		}
		puts("**************************************************************************************");
	}
	else{rtn = -1;}

	return rtn;
}

int rTPU_listarTrackingsVentasFinalizadas(eTracking arrayTrackings[], int tamTrackings, eProducto arrayProductos[], int tamProductos,
		eUsuario arrayUsuarios[], int tamUsuarios,int usuarioActivo)
{
	int rtn = 0;
	int i;
	int bufferIndexProducto;
	int bufferIdUsuarioActivo;
	double diferenciaHoraria;
	char textoEstado[10];
	float bufferPrecioTotal;
	char bufferNombreProducto[26];

	if (arrayTrackings != NULL && arrayProductos != NULL && arrayUsuarios != NULL &&
			tamTrackings > 0 && tamProductos > 0 && tamUsuarios > 0 && usuarioActivo >= 0)
	{
		cabeceraListadoTrackingsCompras();

		for (i = 0; i < tamTrackings; i++)
		{
			if (arrayTrackings[i].isEmpty != LIBRE) //dejo afuera los index libres
			{
				if(arrayTrackings[i].isEmpty == EN_VIAJE) //analizo los en viaje
				{
					diferenciaHoraria = difftime(arrayTrackings[i].horaLlegada, time_current());
					if(diferenciaHoraria <= 0) //si la hora de llegada supera a la actual
					{
						arrayTrackings[i].isEmpty = ENTREGADO; // cambio de estado
					}
				}

				if (arrayTrackings[i].isEmpty == ENTREGADO || arrayTrackings[i].isEmpty == CANCELADO) //solo listo entregados y cancelados
				{
					switch(arrayTrackings[i].isEmpty) //switch para incluir estado como texto en listado
					{
					case 2:
						strcpy(textoEstado, "Entregado");
						break;
					case -1:
						strcpy(textoEstado, "Cancelado");
						break;
					default:
						strcpy(textoEstado, "Libre");
					}

					bufferIndexProducto = eProducto_buscarIndexPorIdDado(arrayProductos, tamProductos,
							arrayTrackings[i].FK_idProducto);

					bufferIdUsuarioActivo  = arrayUsuarios[usuarioActivo].idUsuario;
					if(bufferIdUsuarioActivo == arrayProductos[bufferIndexProducto].FK_idUsuarioVendedor) //listo solo los asociados al id del vendedor
					{
						strcpy(bufferNombreProducto, arrayProductos[bufferIndexProducto].nombreProducto);

						bufferPrecioTotal = multiplicar(arrayTrackings[i].cantidad, arrayProductos[bufferIndexProducto].precio); //calculo precio total de compra

						printf("%12d%25s%10d%15.2f%12s%13d\n", arrayTrackings[i].idTracking, bufferNombreProducto, arrayTrackings[i].cantidad,
								bufferPrecioTotal, textoEstado, arrayTrackings[i].FK_idUsuarioComprador); //listo
					}
					else{rtn = -1;}
				}
			}
			rtn = 1;
		}
		puts("***************************************************************************************");
	}
	else{rtn = -1;}

	return rtn;
}

int rPU_listarProductosVendedor(eProducto arrayProductos[], int tamProductos,
		eUsuario arrayUsuarios[], int tamUsuarios, int estado, int usuarioActivo)
{
	int rtn = 0;
	int i;
	int bufferIdUsuarioActivo;

	if (arrayProductos != NULL && tamProductos > 0 && arrayUsuarios != NULL && tamUsuarios > 0 && usuarioActivo >= 0)
	{
		cabeceraListadoProductosVenta();

		for (i = 0; i < tamProductos; i++)
		{
			bufferIdUsuarioActivo  = arrayUsuarios[usuarioActivo].idUsuario;//busco id de usuario activo

			if (arrayProductos[i].isEmpty == estado &&
					arrayProductos[i].FK_idUsuarioVendedor == bufferIdUsuarioActivo) //si el estado es igual al dado y el id vendedor es igual al activo
			{
				printf("%5d%25s%12.2f%8d%12s\n",
						arrayProductos[i].idProducto, arrayProductos[i].nombreProducto, arrayProductos[i].precio,
						arrayProductos[i].stock, arrayProductos[i].nombreCategoria); //listo
			}
			rtn = 1;
		}
		puts("**************************************************************");
	}
	else{rtn = -1;}

	return rtn;
}

int rTP_buscarTrackingsPorIdVendedor(eTracking arrayTrackings[], int tamTrackings,
		eProducto arrayProductos[], int tamProductos, int idVendedor)
{
	int rtn = -1;
	int i;
	int bufferIndexProducto;

	for(i=0; i<tamTrackings; i++)
	{
		bufferIndexProducto = eProducto_buscarIndexPorIdDado(arrayProductos, tamProductos, arrayTrackings[i].FK_idProducto);//busco id de usuario activo

		if(arrayTrackings[i].isEmpty != LIBRE &&
				arrayProductos[bufferIndexProducto].FK_idUsuarioVendedor == idVendedor) //si el estado es distinto de libre y el id vendedor es igual al activo
		{
			rtn = 1; //retorno 1 si existe al menos un tracking con id del usuario activo
			break;
		}
	}

	return rtn;
}

