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
	//FILE *output;
	ListaMap *base_mapeada;
	base_mapeada = (ListaMap *)malloc(sizeof(ListaMap));
	entrada = fopen(argv[1], "r");
	ListaUsuarios *base_Datos_Usuario =
			(ListaUsuarios *)malloc(sizeof(ListaUsuarios));
	base_Datos_Usuario -> primerUsuario = NULL;
	base_Datos_Usuario-> ultimoUsuario = NULL;
	Leer_BaseDeDatos(entrada,base_Datos_Usuario);
	//output = fopen(argv[2], "w");

//	printf("LECTURA \n \n");
//	printf("Primer Usuario: %s\n",
//			base_Datos_Usuario->primerUsuario->Nombre);
//	printf("Ultimo Usuario: %s \n \n",
//			base_Datos_Usuario->ultimoUsuario->Nombre);

	ListaMap *base_Mapeada = (ListaMap *)malloc(sizeof(ListaMap));
	base_Mapeada -> primero = NULL;
	base_Mapeada-> ultimo = NULL;
	Mapeo(base_Datos_Usuario,base_Mapeada);

	ListaMap *base_Reduce = (ListaMap *)malloc(sizeof(ListaMap));
	base_Reduce -> primero = NULL;
	base_Reduce-> ultimo = NULL;
	Reduce(base_Mapeada,base_Reduce);




	Map *aux_Imprimir;
	aux_Imprimir = base_Mapeada ->primero;
	amigoM *aux_Imprimir_Amigos;

//	printf("MAP \n \n");
//
//	while(aux_Imprimir != NULL)
//	{
//		printf("Caja Nueva \n \n");
//		printf("Usuario %s \n", aux_Imprimir ->UsuarioMap);
//		printf("Amigo: %s \n \n",aux_Imprimir ->AmigoMap);
//		aux_Imprimir_Amigos = aux_Imprimir ->primer_Amigo_Map;
//		printf("AMIGOS EN CAJA \n \n");
//
//		while(aux_Imprimir_Amigos)
//		{
//			printf("%s \n",aux_Imprimir_Amigos ->AmigoM);
//			aux_Imprimir_Amigos = aux_Imprimir_Amigos ->siguiente;
//		}
//
//		printf("\n");
//		aux_Imprimir = aux_Imprimir -> siguiente;
//
//	}

	printf("REDUCE \n \n");
	aux_Imprimir = base_Reduce ->primero;

	while(aux_Imprimir != NULL)
	{
		printf("Caja Nueva \n \n");
		printf("Usuario %s \n", aux_Imprimir ->UsuarioMap);
		printf("Amigo: %s \n \n",aux_Imprimir ->AmigoMap);
		aux_Imprimir_Amigos = aux_Imprimir ->primer_Amigo_Map;
		printf("AMIGOS EN CAJA \n \n");

		while(aux_Imprimir_Amigos)
		{
			printf("%s \n",aux_Imprimir_Amigos ->AmigoM);
			aux_Imprimir_Amigos = aux_Imprimir_Amigos ->siguiente;
		}

		printf("\n");
		aux_Imprimir = aux_Imprimir -> siguiente;

	}

	return 0;
}

