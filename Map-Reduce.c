/*
 * Map-Reduce.c
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
 */

#include <stdlib.h>
#include "Map-Reduce.h"
#include "ListaAmigos.h"

ListaMap *Mapeo(Usuario *base_Datos_Usuario) /*base_Datos_Usuarios Nombre de la listas de listas*/

{
	Usuario *aux;
	Amigo *auxx;
	Amigo *auxxx;

	Map *auxMap;
	aux = base_Datos_Usuario->primerUsuario;


	while (aux != NULL)

	{

		auxx = aux->primerAmigo;
		while (auxx != NULL)

		{
			Map *nuevo = (Map *)malloc(sizeof(Map));
			auxMap = nuevo;
			auxxx = aux->primerAmigo;
			nuevo->UsuarioMap = aux->Nombre;
			nuevo->AmigoMap = auxx->Nombre;

			while (auxxx != NULL)
			{
				amigoM *new  = (new *)malloc(sizeof(new));
				new->AmigoM = auxxx->Nombre;
				auxMap->siguiente= new;
				auxMap = new;
				auxxx = auxxx->siguiente;
				if (auxxx == NULL)
				{
					auxx = auxx->siguiente;
				}
			}

		}

		aux = aux->siguiente;
	}


