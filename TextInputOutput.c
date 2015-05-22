/*
 * TextInput.c
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaAmigos.h"
#include "Map-Reduce.h"


ListaUsuarios *Leer_BaseDeDatos(FILE *files,ListaUsuarios *base_Datos_Usuario)
{

	if (files == NULL)
	{
	   perror ("Error al abrir fichero.txt");
	}

	Usuario *usuario_Nuevo;
	Amigo *amigo_Nuevo;
	char nombre_Local[100];

	char linea = '\n';
	char verf_Linea;

	// Se leera la lista de usuarios

	while (feof(files) == 0)
	{
		usuario_Nuevo = (Usuario *)malloc(sizeof(Usuario));
		usuario_Nuevo->anterior = NULL;
		usuario_Nuevo->primerAmigo = NULL;
		usuario_Nuevo->siguiente = NULL;
		usuario_Nuevo->ultimoAmigo = NULL;
		fscanf(files,"%s -> ",nombre_Local);
		fflush(stdin);
		usuario_Nuevo -> Nombre =
				malloc(strlen(nombre_Local) + 1);
		usuario_Nuevo -> Nombre =
				strcat(usuario_Nuevo -> Nombre,nombre_Local);

		printf("%s \n\n",usuario_Nuevo ->Nombre);
		fflush(stdin);
		verf_Linea = '\0';

		// En este ciclo se leeran los amigos, leyendo un string y
		// luego un caracter, el string se guarda y luego se verifica
		// si el caracter es \n o " "

		while (verf_Linea != linea)
		{
			amigo_Nuevo = (Amigo *)malloc(sizeof(Amigo));
			amigo_Nuevo ->anterior = NULL;
			amigo_Nuevo ->siguiente = NULL;
			fscanf(files,"%s",nombre_Local);
			fflush(stdin);
			amigo_Nuevo -> Nombre =
							malloc(strlen(nombre_Local) + 1);
			amigo_Nuevo -> Nombre =
					strcat(amigo_Nuevo -> Nombre,nombre_Local);
			fscanf(files,"%c",&verf_Linea);
			fflush(stdin);

			if (usuario_Nuevo -> primerAmigo == NULL)
			{
				usuario_Nuevo -> primerAmigo = amigo_Nuevo;
				usuario_Nuevo -> ultimoAmigo = amigo_Nuevo;
			}

			else
			{
				amigo_Nuevo -> anterior = usuario_Nuevo ->ultimoAmigo;
				usuario_Nuevo -> ultimoAmigo -> siguiente =
						amigo_Nuevo;
				usuario_Nuevo -> ultimoAmigo = amigo_Nuevo;
			}

			if (feof(files) != 0){break;}

		}

		if (base_Datos_Usuario -> primerUsuario == NULL)
		{
			base_Datos_Usuario -> primerUsuario = usuario_Nuevo;
			base_Datos_Usuario -> ultimoUsuario = usuario_Nuevo;
		}

		else
		{
			usuario_Nuevo -> anterior =
					base_Datos_Usuario -> ultimoUsuario;
			base_Datos_Usuario -> ultimoUsuario -> siguiente =
					usuario_Nuevo;
			base_Datos_Usuario -> ultimoUsuario = usuario_Nuevo;


		}
	}
	return base_Datos_Usuario;
}

void GuardarResultados(FILE *files,ListaMap *base_Reduce)
{
	Map *aux_Imprimir;
	aux_Imprimir = base_Reduce ->primero;
	amigoM *aux_Imprimir_Amigos;

	while(aux_Imprimir != NULL)
		{
			fprintf(files,"(%s %s) -> ", aux_Imprimir ->UsuarioMap,
					aux_Imprimir ->AmigoMap);
			aux_Imprimir_Amigos = aux_Imprimir ->primer_Amigo_Map;

			while(aux_Imprimir_Amigos)
			{
				fprintf(files,"%s ",aux_Imprimir_Amigos ->AmigoM);
				aux_Imprimir_Amigos =
						aux_Imprimir_Amigos -> siguiente;
			}

			fprintf(files,"\n");
			aux_Imprimir = aux_Imprimir -> siguiente;

		}

	return;

}
