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
	char comilla[1] = {"\""};
	char espacio = {" "};
	char linea = {"\n"};
	char verf_Linea;

	// Se leera la lista de usuarios

	while (feof(files) == 0)
	{
		usuario_Nuevo = (Usuario *)malloc(sizeof(Usuario));
		fscanf(files,"%s -> ",&usuario_Nuevo -> Nombre);
		fflush(stdin);

		// En este ciclo se leeran los amigos, leyendo un string y
		// luego un caracter, el string se guarda y luego se verifica
		// si el caracter es \n o " "

		while (verf_Linea != linea)
		{
			amigo_Nuevo = (Amigo *)malloc(sizeof(Amigo));
			fscanf(files,"%s",&amigo_Nuevo -> Nombre);
			fflush(stdin);
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
