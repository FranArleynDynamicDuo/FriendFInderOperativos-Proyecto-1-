/*
 * friendfind.c
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
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
	ListaMap *base_mapeada = (ListaMap *)malloc(sizeof(ListaUsuarios));
	entrada = fopen(argv[1], "r");
	ListaUsuarios *base_Datos_Usuario =
			(ListaUsuarios *)malloc(sizeof(ListaUsuarios));
	base_Datos_Usuario -> primerUsuario = NULL;
	base_Datos_Usuario-> ultimoUsuario = NULL;
	Leer_BaseDeDatos(entrada,base_Datos_Usuario);
	output = fopen(argv[2], "w");
	printf("LECTURA \n \n");
	printf("Primer Usuario: %s\n",
			base_Datos_Usuario->primerUsuario->Nombre);
	printf("Ultimo Usuario: %s \n \n",
			base_Datos_Usuario->ultimoUsuario->Nombre);
	ListaMap *base_Mapeada = (ListaMap *)malloc(sizeof(ListaMap));
	base_Mapeada -> primero = NULL;
	base_Mapeada-> ultimo = NULL;
	Mapeo(base_Datos_Usuario,base_Mapeada);
	printf("MAP \n \n");
	printf("Primer Usuario: %s\n",
			base_Mapeada -> primero -> UsuarioMap);
	printf("Primer Amigo: %s\n \n",
			base_Mapeada -> primero -> AmigoMap);
	printf("Ultimo Usuario: %s \n",
			base_Mapeada -> ultimo-> UsuarioMap);
	printf("Ultimo Amigo: %s \n \n",
			base_Mapeada -> ultimo-> AmigoMap);

	return 0;
}

