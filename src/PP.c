/*
 ============================================================================
 Name        : PP.c
 Author      : FSerrano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "General.h"
#include "Productos.h"
#include "Usuarios.h"
#include "Trackings.h"
#include "Relaciones.h"

//Usuarios harcodeados:
//email: garcos.malperin@lercadomibre.com   password: password   tipo: ADMIN
//email: ricardo_fort@yahoo.com   password: mamaaaa   tipo: USER
//email: diegoarmando@gmail.com   password: eeeeee   tipo: USER
//email: a@a.a   password: 1234   tipo: ADMIN
//email: u@u.u   password: 1234   tipo: USER

int main(void)
{
	setbuf(stdout,NULL);

	eUsuario usuarios[CANT_USUARIOS];
	eProducto productos[CANT_PRODUCTOS];
	eTracking trackings[CANT_TRACKINGS];
	int opcionIngreso;
	int opcionUser;
	char opcionAdmin;
	char opcionVentas;
	int opcionVender;
	int indexUsuarioActivo = -1;

	//Inicializaciones
	eUsuario_inicializar(usuarios, CANT_USUARIOS);
	eProducto_inicializar(productos, CANT_PRODUCTOS);
	eTracking_inicializar(trackings, CANT_TRACKINGS);

	do	//Bucle de menú de ingreso
	{
		menuIngreso();
		obtenerNumEntero(&opcionIngreso, "\nIngresar opción: ", "\nEntrada inválida",
				"\nDemasiados intentos fallidos, reiniciando.\n", 0, 2, 5);

		switch(opcionIngreso)
		{
		case 1:	//INGRESAR
			if(eUsuario_validarUsuario(usuarios, CANT_USUARIOS, &indexUsuarioActivo) == -1)
			{
				indexUsuarioActivo = -1;
			}
			break;
		case 2:	//REGISTRARSE
			indexUsuarioActivo = eUsuario_alta(usuarios, CANT_USUARIOS);
			break;
		case 0:	//SALIR
			puts("\nUsted ha salido del sistema exitosamente");
			break;
		}

		if(indexUsuarioActivo > -1 && opcionIngreso != 0)

		{
			printf("\n\n* Bienvenido/a %s *\n", usuarios[indexUsuarioActivo].email);
			if(usuarios[indexUsuarioActivo].tipo == ADMIN)
			{
				do	//Bucle de menú de Admin
				{
					menuAdmin();
					obtenerCaracterConExcepcion(&opcionAdmin, "\nIngresar opción: ", "\nEntrada inválida",
							"\nDemasiados intentos fallidos, reiniciando.\n", 'A', 'F', '0', 5);
					switch(opcionAdmin)
					{
					case 'A':	//LISTAR ESTADO DE TODOS LOS USUARIOS
						eUsuario_listarTodosExceptoEstado(usuarios, CANT_USUARIOS, LIBRE);
						break;
					case 'B':	//LISTAR TODOS LOS PRODUCTOS POR CATEGORÍA
						if(eProducto_buscarProductosPorEstado(productos, CANT_PRODUCTOS, EN_STOCK) == 1)
						{
							eProducto_ordenarPorNombre(productos, CANT_PRODUCTOS, -1);
							eProducto_listarTodos(productos, CANT_PRODUCTOS, EN_STOCK);
						}
						else
						{
							puts("\nNo hay productos con stock en el sistema.");
						}
						break;
					case 'C':	//BAJA DE UN PRODUCTO
						if(eProducto_buscarProductosPorEstado(productos, CANT_PRODUCTOS, EN_STOCK) == 1)
						{
							eProducto_darDeBajaProducto(productos, CANT_PRODUCTOS);
						}
						else
						{
							puts("\nNo hay productos activos para dar de baja.");
						}
						break;
					case 'D':	//BAJA DE UN USUARIO
						eUsuario_darDeBajaUsuario(usuarios, CANT_USUARIOS, indexUsuarioActivo);
						break;
					case 'E':	//VER TRACKING GLOBAL
						if(eTrackings_buscarTrackings(trackings, CANT_TRACKINGS) == 1)
						{
							rTP_listarTrackingGlobal(trackings, CANT_TRACKINGS, productos, CANT_TRACKINGS);
						}
						else
						{
							puts("\nAún no hay trackings en el sistema.");
						}
						break;
					case 'F':	//FILTRAR POR NOMBRE DE PRODUCTO
						eProducto_ordenarPorStock(productos, CANT_PRODUCTOS, DESCENDENTE);
						eProducto_listarTodosPorNombre(productos, CANT_PRODUCTOS);
						break;
					case '0':	//SALIR
						puts("\nVolviendo a Menú inicial...");
						break;
					}
				}
				while(opcionAdmin != '0');
			}
			else if(usuarios[indexUsuarioActivo].tipo == USER)
			{
				do	//Bucle de menú de User
				{
					menuUser();
					obtenerNumEntero(&opcionUser, "\nIngresar opción: ", "\nEntrada inválida",
							"\nDemasiados intentos fallidos, reiniciando.\n", 0, 4, 5);
					switch(opcionUser)
					{
					case 1:	//COMPRAR
						if(eProducto_buscarProductosPorEstado(productos, CANT_PRODUCTOS, EN_STOCK) == 1)
						{
							rPUT_comprarProducto(productos, CANT_PRODUCTOS, trackings, CANT_TRACKINGS,
									usuarios, CANT_USUARIOS, indexUsuarioActivo);
						}
						else
						{
							puts("\nNo hay productos con stock en venta en el sistema.");
						}
						break;
					case 2:	//VENDER
						menuVender();
						obtenerNumEntero(&opcionVender, "\nIngresar opción: ", "\nEntrada inválida",
								"\nDemasiados intentos fallidos, reiniciando.\n", 0, 2, 5);
						switch(opcionVender)
						{
						case 1:	//ALTA DE PRODUCTO
							rPU_altaDeProducto(usuarios, CANT_USUARIOS, productos, CANT_PRODUCTOS, indexUsuarioActivo);
							break;
						case 2:	//REPONER STOCK
							if(eProducto_buscarProductosPorEstadoPorVendedor(productos, CANT_PRODUCTOS,
									EN_STOCK, usuarios[indexUsuarioActivo].idUsuario) == 1)
							{
								rPU_listarProductosVendedor(productos, CANT_PRODUCTOS, usuarios,
										CANT_USUARIOS, EN_STOCK, indexUsuarioActivo);
								eProducto_reponerStock(productos, CANT_PRODUCTOS, usuarios[indexUsuarioActivo].idUsuario);
							}
							break;
						case 0:	//SALIR
							break;
						}
						break;
					case 3:	//ESTADO DE COMPRAS
						if (eTracking_buscarTrackingsPorIdComprador(trackings, CANT_TRACKINGS, usuarios[indexUsuarioActivo].idUsuario) == 1)
						{
							rTPU_listarTrackingsCompras(trackings, CANT_TRACKINGS, productos, CANT_PRODUCTOS, usuarios,
									CANT_USUARIOS, indexUsuarioActivo);
							if (consultarContinuar("\nIngrese 1 si desea cancelar un producto en viaje o 0 si desea salir: ",
									"Entrada invalida", '1', '0') == 1)
							{
								eTracking_cancelarTracking(trackings, CANT_TRACKINGS);
							}
						}
						else
						{
							puts("\nNo se registraron compras a su nombre.");
						}
						break;
					case 4:	//ESTADO DE VENTAS
						menuEstadoVentas();
						obtenerCaracterConExcepcion(&opcionVentas, "\nIngresar opción: ", "\nEntrada inválida",
								"\nDemasiados intentos fallidos, reiniciando.\n", 'A', 'B', '0', 5);
						switch(opcionVentas)
						{
						case 'A':	//LISTADO DE VENTAS FINALIZADAS
							if(rTP_buscarTrackingsPorIdVendedor(trackings, CANT_TRACKINGS, productos,
									CANT_PRODUCTOS, usuarios[indexUsuarioActivo].idUsuario) == 1)
							{
								rTPU_listarTrackingsVentasFinalizadas(trackings, CANT_TRACKINGS, productos,
										CANT_PRODUCTOS, usuarios, CANT_USUARIOS, indexUsuarioActivo);
							}
							else
							{
								puts("\nNo se registran ventas finalizadas a su nombre.");
							}
							break;
						case 'B':	//VER PRODUCTOS
							if(eProducto_buscarProductosPorEstadoPorVendedor(productos, CANT_PRODUCTOS,
									EN_STOCK, usuarios[indexUsuarioActivo].idUsuario) == 1)
							{
								rPU_listarProductosVendedor(productos, CANT_PRODUCTOS, usuarios,
										CANT_USUARIOS, EN_STOCK, indexUsuarioActivo);
							}
							else
							{
								puts("\nNo se registran productos en stock a su nombre.");
							}
							break;
						case '0':	//SALIR
							break;
						}
						break;
					case 0:	//SALIR
						puts("\nVolviendo a Menú inicial...");
						break;
					}
				}
				while(opcionUser != 0);
			}
		}
	}
	while(opcionIngreso != 0);

	return EXIT_SUCCESS;
}
