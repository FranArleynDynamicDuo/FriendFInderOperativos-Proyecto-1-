/*
 * friendfind.c
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
 *      		arleyn
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaAmigos.h"
#include "Map-Reduce.h"
#include "TextInputOutput.h"

int main(int argc,char *argv[])
{
	FILE *entrada;
	FILE *output;
	ListaMap *base_mapeada;
	base_mapeada = (ListaMap *)malloc(sizeof(ListaMap));
	entrada = fopen(argv[1], "r");
	ListaUsuarios *base_Datos_Usuario =
			(ListaUsuarios *)malloc(sizeof(ListaUsuarios));
	base_Datos_Usuario -> primerUsuario = NULL;
	base_Datos_Usuario-> ultimoUsuario = NULL;
	Leer_BaseDeDatos(entrada,base_Datos_Usuario);
	output = fopen(argv[2], "w+");

	ListaMap *base_Mapeada = (ListaMap *)malloc(sizeof(ListaMap));
	base_Mapeada -> primero = NULL;
	base_Mapeada-> ultimo = NULL;
	Mapeo(base_Datos_Usuario,base_Mapeada);

	ListaMap *base_Reduce = (ListaMap *)malloc(sizeof(ListaMap));
	base_Reduce -> primero = NULL;
	base_Reduce-> ultimo = NULL;
	Reduce(base_Mapeada,base_Reduce);

	GuardarResultados(output,base_Reduce);

	return 0;
}
