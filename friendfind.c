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
	entrada = fopen(argv[1], "r");
	ListaUsuarios *base_Datos_Usuario =
			(ListaUsuarios *)malloc(sizeof(ListaUsuarios));
	base_Datos_Usuario -> primerUsuario = NULL;
	base_Datos_Usuario-> ultimoUsuario = NULL;
	Leer_BaseDeDatos(entrada,base_Datos_Usuario);
	output = fopen(argv[2], "w");
	printf("Primer Usuario: %s\n \n",
			base_Datos_Usuario->primerUsuario->Nombre);
	printf("Ultimo Usuario: %s \n \n",
			base_Datos_Usuario->ultimoUsuario->Nombre);


	return 0;
}

