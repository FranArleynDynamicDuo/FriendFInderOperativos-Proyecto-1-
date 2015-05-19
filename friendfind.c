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

	Map *aux_Imprimir;
	aux_Imprimir = base_Mapeada ->primero;
	amigoM *aux_Imprimir_Amigos;

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

//	printf("Primer Usuario: %s\n",
//			base_Mapeada -> primero -> UsuarioMap);
//	printf("Primer Amigo: %s\n",
//			base_Mapeada -> primero -> AmigoMap);
//	printf("Primer Amigo de primer Amigo: %s\n",
//				base_Mapeada -> primero ->primer_Amigo_Map ->AmigoM);
//	printf("Ultimo Amigo de primer Amigo: %s\n \n",
//				base_Mapeada -> primero ->ultimo_Amigo_Map->AmigoM);
//
//
//	printf("Ultimo Usuario: %s \n",
//			base_Mapeada -> ultimo-> UsuarioMap);
//	printf("Ultimo Amigo: %s \n",
//			base_Mapeada -> ultimo-> AmigoMap);
//	printf("Primer Amigo de Ultimo Amigo: %s\n",
//				base_Mapeada ->ultimo ->primer_Amigo_Map ->AmigoM);
//	printf("Ultimo Amigo de Ultimo Amigo: %s\n \n",
//				base_Mapeada ->ultimo ->ultimo_Amigo_Map->AmigoM);

	return 0;
}

