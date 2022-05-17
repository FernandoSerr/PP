/*
 * Productos.c
 *
 *  Created on: 12 may. 2022
 *      Author: fserrano
 */

#include "Productos.h"

#define CANT_PRODUCTOS_HARDCODEADOS 5

int eProducto_inicializar(eProducto lista[], int tam)
{
	int rtn = 0;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = LIBRE;
		}
		rtn = 1;

		//HARDCODEO DE PRODUCTOS
		eProducto_hardcodearProductos(lista, tam);
	}
	else {rtn = -1;}

	return rtn;
}

void eProducto_hardcodearProductos(eProducto lista[], int tam)

{
	if (lista != NULL && tam > 0)
	{
		lista[0].idProducto = 1;
		lista[0].categoria = 1;
		strcpy(lista[0].nombreCategoria, "Tecnología");
		strcpy(lista[0].nombreProducto, "Auriculares");
		lista[0].precio = 5400.25;
		lista[0].stock = 7;
		lista[0].FK_idUsuarioVendedor = 2;
		lista[0].isEmpty = EN_STOCK;

		lista[1].idProducto = 2;
		lista[1].categoria = 2;
		strcpy(lista[1].nombreCategoria, "Moda");
		strcpy(lista[1].nombreProducto, "Mocasines");
		lista[1].precio = 6300;
		lista[1].stock = 0;
		lista[1].FK_idUsuarioVendedor = 3;
		lista[1].isEmpty = BAJA;

		lista[2].idProducto = 3;
		lista[2].categoria = 4;
		strcpy(lista[2].nombreCategoria, "Juguetes");
		strcpy(lista[2].nombreProducto, "Peluche");
		lista[2].precio = 2999.99;
		lista[2].stock = 25;
		lista[2].FK_idUsuarioVendedor = 2;
		lista[2].isEmpty = EN_STOCK;

		lista[3].idProducto = 4;
		lista[3].categoria = 6;
		strcpy(lista[3].nombreCategoria, "Otros");
		strcpy(lista[3].nombreProducto, "Entradas Prim Sound");
		lista[3].precio = 100000;
		lista[3].stock = 1;
		lista[3].FK_idUsuarioVendedor = 5;
		lista[3].isEmpty = EN_STOCK;

		lista[4].idProducto = 5;
		lista[4].categoria = 2;
		strcpy(lista[4].nombreCategoria, "Moda");
		strcpy(lista[4].nombreProducto, "Bufanda");
		lista[4].precio = 800;
		lista[4].stock = 33;
		lista[4].FK_idUsuarioVendedor = 5;
		lista[4].isEmpty = EN_STOCK;
	}
}

static int eProducto_obtenerIdUnico(void);
static int eProducto_obtenerIdUnico()
{
	static int idAutoincremental = IDPRODUCTO_INICIAL + CANT_PRODUCTOS_HARDCODEADOS;
	return idAutoincremental++;
}

int eProducto_buscarEspacioLibre(eProducto lista[], int tam)
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
			rtn = -2;
		}
	}
	else{rtn = -1;}

	return rtn;
}

eProducto eProducto_cargarUnProducto()
{
	eProducto p;

	p.idProducto = eProducto_obtenerIdUnico();

	obtenerNumEntero(&p.categoria, "\nIngrese categoría.\n\t1. Tecnología\n\t2. Moda\n\t3. Hogar\n\t4. Juguetes\n\t5. Perfumería\n\t6. Otros\n",
			"\nEntrada inválida.", "\nSe le han acabado los intentos", 1, 6, 4);
	obtenerCadenaAlfanumericaConEspaciosGuiones(p.nombreProducto, "\nIngrese nombre del producto: ",
			"\nEntrada inválida.", "\nSe le han acabado los intentos", 25, 4);
	obtenerNumDecimal(&p.precio, "\nIngrese precio unitario del producto: ", "\nEntrada inválida.",
			"\nSe le han acabado los intentos", 0, 1000000, 4);

	switch(p.categoria) //switch para cargar la categoria en un campo texto dentro de la estructura
	{
	case 1:
		strcpy(p.nombreCategoria, "Tecnología");
		break;
	case 2:
		strcpy(p.nombreCategoria, "Moda");
		break;
	case 3:
		strcpy(p.nombreCategoria, "Hogar");
		break;
	case 4:
		strcpy(p.nombreCategoria, "Juguetes");
		break;
	case 5:
		strcpy(p.nombreCategoria, "Perfumería");
		break;
	default:
		strcpy(p.nombreCategoria, "Otros");
		break;
	}

	obtenerNumEntero(&p.stock, "\nIngrese cantidad en stock: ", "\nEntrada inválida.",
			"\nSe le han acabado los intentos", 1, 999, 4);

	return p;
}

void eProducto_listarUnoParaCompra(eProducto p)
{
	printf("%12s%5d%25s%12.2f%8d\n",
			p.nombreCategoria, p.idProducto, p.nombreProducto, p.precio, p.stock);
}

int eProducto_listarTodosPorCategoria(eProducto lista[], int tam, int estado, int categoria)
{
	int rtn = 0;
	int i;

	if (lista != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty == estado && lista[i].categoria == categoria)
			{
				eProducto_listarUnoParaCompra(lista[i]);
			}
			rtn = 1;
		}
	}
	else{rtn = -1;}

	return rtn;
}

void eProducto_listarTodos(eProducto lista[], int tam, int estado)
{
	if(lista != NULL && tam > 0)
	{
		cabeceraListadoProductosCompra();
		eProducto_listarTodosPorCategoria(lista, tam, estado, CAT_TECNOLOGIA);
		eProducto_listarTodosPorCategoria(lista, tam, estado, CAT_MODA);
		eProducto_listarTodosPorCategoria(lista, tam, estado, CAT_HOGAR);
		eProducto_listarTodosPorCategoria(lista, tam, estado, CAT_JUGUETES);
		eProducto_listarTodosPorCategoria(lista, tam, estado, CAT_PERFUMERIA);
		eProducto_listarTodosPorCategoria(lista, tam, estado, CAT_OTROS);
		puts("**************************************************************");
	}
}

int eProducto_buscarIndexPorId(eProducto lista[], int tam)
{
	int rtn = 0;
	int flag = 0;
	int i;
	int idBuscada;

	if (lista != NULL && tam > 0)
	{
		eProducto_listarTodos(lista, tam, EN_STOCK);

		obtenerNumEntero(&idBuscada, "\nIngrese ID: ", "\nEntrada inválida.",
				"\nSe le han acabado los intentos", IDPRODUCTO_INICIAL, 1000, 10);

		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty == EN_STOCK)
			{
				if (lista[i].idProducto == idBuscada)
				{
					flag = 1;
					rtn = i; //retorno index
					break;
				}
			}
		}

		if (flag == 0) //no se halló el id
		{
			rtn = -2;
		}
	}
	else{rtn = -1;}

	return rtn;
}

int eProducto_buscarIndexPorIdDado(eProducto lista[], int tam, int id)
{
	int rtn = 0;
	int flag = 0;
	int i;

	if (lista != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty == EN_STOCK)
			{
				if (lista[i].idProducto == id)
				{
					flag = 1;
					rtn = i; //retorno index
					break;
				}
			}
		}

		if (flag == 0) // no se halló id
		{
			rtn = -2;
		}
	}
	else{rtn = -1;}

	return rtn;
}

int eProducto_disminuirStock(eProducto lista[], int tam, int index, int cantCompra)
{
	int rtn = 0;

	if(lista != NULL && tam > 0 && index >= 0 && cantCompra > 0)
	{
		lista[index].stock -= cantCompra; //disminuyo stock cuando genero tracking de una compra

		if(lista[index].stock == 0) //si el stock cae a cero
		{
			lista[index].isEmpty = BAJA; //cambia el estado de EN_STOCK a BAJA
		}
	}
	else{rtn = -1;}

	return rtn;
}

int eProducto_ordenarPorNombre(eProducto* lista, int tam, int orden)
{
	int rtn = 0;
	int i;
	int auxTam;
	int flagSwap;
	eProducto auxProducto;

	if (lista != NULL && tam > 0 && (orden == ASCENDENTE || orden == DESCENDENTE))
	{
		switch (orden) //switch para ver orden ascendente o descendente y ejecutar burbujeo optimizado
		{
		case ASCENDENTE:
			auxTam = tam - 1;
			do
			{
				flagSwap = 0;
				for(i=0; i< auxTam; i++)
				{
					if(strcmp(lista[i].nombreProducto, lista[i+1].nombreProducto) > 0)
					{
						flagSwap = 1;
						auxProducto = lista[i];
						lista[i] = lista[i+1];
						lista[i+1] = auxProducto;
					}
				}
				auxTam--;
			}while(flagSwap == 1);
			rtn = 1;
			break;
		case DESCENDENTE:
			auxTam = tam - 1;
				do
				{
					flagSwap = 0;
					for(i=0; i< auxTam; i++)
					{
						if(strcmp(lista[i].nombreProducto, lista[i+1].nombreProducto) < 0)
						{
							flagSwap = 1;
							auxProducto = lista[i];
							lista[i] = lista[i+1];
							lista[i+1] = auxProducto;
						}
					}
					auxTam--;
				}while(flagSwap == 1);
			rtn = 1;
			break;
		default:
			rtn = -1;
			break;
		}
	}
	return rtn;
}

int eProducto_ordenarPorId(eProducto* lista, int tam, int orden)
{
	int rtn = 0;
	int i;
	int auxTam;
	int flagSwap;
	eProducto auxProducto;

	if (lista != NULL && tam > 0 && (orden == ASCENDENTE || orden == DESCENDENTE))
	{
		switch (orden) //switch para ver orden ascendente o descendente y ejecutar burbujeo optimizado
		{
		case ASCENDENTE:
			auxTam = tam - 1;
			do
			{
				flagSwap = 0;
				for(i=0; i< auxTam; i++)
				{
					if(lista[i].nombreProducto > lista[i+1].nombreProducto)
					{
						flagSwap = 1;
						auxProducto = lista[i];
						lista[i] = lista[i+1];
						lista[i+1] = auxProducto;
					}
				}
				auxTam--;
			}while(flagSwap == 1);
			rtn = 1;
			break;
		case DESCENDENTE:
			auxTam = tam - 1;
				do
				{
					flagSwap = 0;
					for(i=0; i< auxTam; i++)
					{
						if(lista[i].nombreProducto < lista[i+1].nombreProducto)
						{
							flagSwap = 1;
							auxProducto = lista[i];
							lista[i] = lista[i+1];
							lista[i+1] = auxProducto;
						}
					}
					auxTam--;
				}while(flagSwap == 1);
			rtn = 1;
			break;
		default:
			rtn = -1;
			break;
		}
	}
	return rtn;
}

int eProducto_darDeBajaProducto(eProducto* lista, int tam)
{
	int rtn = 0;
	int bufferIndex;
	int bufferId;

	if(lista != NULL && tam > 0)
	{
		obtenerNumEntero(&bufferId, "\nIngresar el Id del usuario que quiere dar de baja: ", "\nEntrada inválida",
				"\nDemasiados intentos fallidos, reiniciando.", IDPRODUCTO_INICIAL, IDPRODUCTO_INICIAL + CANT_PRODUCTOS -1 , 5);
		bufferIndex = eProducto_buscarIndexPorIdDado(lista, tam, bufferId);

		if(bufferIndex < 0 || lista[bufferIndex].isEmpty != EN_STOCK) //si el index no es valido o el producto no tenga estado EN_STOCK
		{
			rtn = -1;
			puts("\nNo se ha realizado la baja por ID erróneo.");
		}
		else
		{
			if(consultarContinuar("\nEstá seguro de que quiere dar de baja este producto? Si está seguro ingrese S, si no ingrese N.",
					"\nEntrada inválida", 'S', 'N') == 1) //pedido de confirmación
			{
				lista[bufferIndex].isEmpty = BAJA; //cambio de estado
			}
			else{rtn = -1;}
		}
	}
	else{rtn = -1;}

	return rtn;
}

int eProducto_buscarProductosPorEstado(eProducto lista[], int tam, int estado)
{
	int rtn = -1;
	int i;

	if(lista != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == estado)
			{
				rtn = 1; //retorno 1 si existe algún producto con estado dado
				break;
			}
		}
	}

	return rtn;
}

int eProducto_buscarProductosPorEstadoPorVendedor(eProducto lista[], int tam, int estado, int idVendedor)
{
	int rtn = -1;
	int i;

	if(lista != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == estado && lista[i].FK_idUsuarioVendedor == idVendedor)
			{
				rtn = 1; //retorno 1 si existe algún producto con estado dado vendidos por el usuario activo
				break;
			}
		}
	}

	return rtn;
}

int eProducto_reponerStock(eProducto lista[], int tam, int idVendedor)
{
	int rtn = 0;
	int bufferIndexProducto;
	int bufferIdProducto;
	int bufferStockActual;
	int bufferAumentoStock;

	if (lista != NULL && tam > 0 && idVendedor >= 0)
	{

		obtenerNumEntero(&bufferIdProducto, "\nIngresar Id del producto del que desea reponer stock: ", "\nEntrada inválida",
				"\nDemasiados intentos fallidos, reiniciando.\n", 0, tam, 5);

		bufferIndexProducto = eProducto_buscarIndexPorIdDado(lista, tam, bufferIdProducto);

		if(idVendedor == lista[bufferIndexProducto].FK_idUsuarioVendedor)
		{
			bufferStockActual = lista[bufferIndexProducto].stock;
			if(bufferStockActual >= 999)
			{
				puts("\nEl producto está en su máximo stock.");
				rtn = -1;
			}
			else
			{
				obtenerNumEntero(&bufferAumentoStock, "\nIngresar cuántas unidades quiere ingresar a stock: ", "\nEntrada inválida (stock máximo: 999 unidades)",
						"\nDemasiados intentos fallidos, reiniciando.\n", 0, 999 - bufferStockActual, 5);

				lista[bufferIndexProducto].stock += bufferAumentoStock;

				lista[bufferIndexProducto].isEmpty = EN_STOCK;

				rtn = 1;
			}
		}
		else
		{
			puts("\nEl Id no pertenece a un producto en venta por usted.");
			rtn = -1;
		}
	}
	else {rtn = -1;}

	return rtn;
}

int eProducto_ordenarPorStock(eProducto* lista, int tam, int orden)
{
	int rtn = 0;
	int i;
	int auxTam;
	int flagSwap;
	eProducto auxProducto;

	if (lista != NULL && tam > 0 && (orden == ASCENDENTE || orden == DESCENDENTE))
	{
		switch (orden) //switch para ver orden ascendente o descendente y ejecutar burbujeo optimizado
		{
		case ASCENDENTE:
			auxTam = tam - 1;
			do
			{
				flagSwap = 0;
				for(i=0; i< auxTam; i++)
				{
					if(lista[i].stock > lista[i+1].stock)
					{
						flagSwap = 1;
						auxProducto = lista[i];
						lista[i] = lista[i+1];
						lista[i+1] = auxProducto;
					}
				}
				auxTam--;
			}while(flagSwap == 1);
			rtn = 1;
			break;
		case DESCENDENTE:
			auxTam = tam - 1;
				do
				{
					flagSwap = 0;
					for(i=0; i< auxTam; i++)
					{
						if(lista[i].stock < lista[i+1].stock)
						{
							flagSwap = 1;
							auxProducto = lista[i];
							lista[i] = lista[i+1];
							lista[i+1] = auxProducto;
						}
					}
					auxTam--;
				}while(flagSwap == 1);
			rtn = 1;
			break;
		default:
			rtn = -1;
			break;
		}
	}
	return rtn;
}

int eProducto_listarTodosPorNombre(eProducto lista[], int tam)
{
	int rtn = 0;
	int i;
	char bufferNombre[26];

	if (lista != NULL && tam > 0)
	{
		obtenerCadenaAlfanumericaConEspaciosGuiones(bufferNombre, "\nIngrese nombre del producto por el que quiere filtrar: ",
				"\nEntrada inválida", "\nDemasiados intentos fallidos.", 26, 5);

		cabeceraListadoProductosCompra();
		for (i = 0; i < tam; i++)
		{
			if (strcmp(lista[i].nombreProducto, bufferNombre) == 0)
			{
				eProducto_listarUnoParaCompra(lista[i]);
			}
			rtn = 1;
		}
		puts("**************************************************************");
	}
	else{rtn = -1;}

	return rtn;
}
