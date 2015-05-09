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


ListaUsuarios *Leer_BaseDeDatos(FILE *files,ListaUsuarios *base_Datos_Usuario)
{

	if (files == NULL)
	{
	   perror ("Error al abrir fichero.txt");
	}

	Usuario *usuario_Nuevo;
	Amigo *amigo_Nuevo;

	char linea[1] = {"\n"};
	char verf_Linea;

	// Se leera la lista de usuarios

	while (feof(files) == 0)
	{
		printf("PRIMER CICLO \n \n");
		usuario_Nuevo = (Usuario *)malloc(sizeof(Usuario));
		usuario_Nuevo->anterior = NULL;
		usuario_Nuevo->primerAmigo = NULL;
		usuario_Nuevo->siguiente = NULL;
		usuario_Nuevo->ultimoAmigo = NULL;
		fscanf(files,"%s -> ",usuario_Nuevo -> Nombre);
		fflush(stdin);
		printf("%s \n\n",usuario_Nuevo ->Nombre);

		// En este ciclo se leeran los amigos, leyendo un string y
		// luego un caracter, el string se guarda y luego se verifica
		// si el caracter es \n o " "

		while (verf_Linea != '\n')
		{

			printf("SEGUNDO CICLO \n \n");
			amigo_Nuevo = (Amigo *)malloc(sizeof(Amigo));
			amigo_Nuevo ->anterior = NULL;
			amigo_Nuevo ->siguiente = NULL;
			fscanf(files,"%s",amigo_Nuevo -> Nombre);
			fflush(stdin);
			fscanf(files,"%c",&verf_Linea);
			fflush(stdin);
			printf("%s \n",usuario_Nuevo -> Nombre);
			printf("%s \n \n",amigo_Nuevo -> Nombre);

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

void GuardarResultados(FILE *files,ListaUsuarios *base_Datos_Usuario)
{

	return;

}
