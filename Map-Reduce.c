/*
 * Map-Reduce.c
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
 */

#include <stdlib.h>
#include "Map-Reduce.h"
#include "ListaAmigos.h"

ListaMap *Mapeo(ListaUsuarios *base_Datos_Usuario,
		ListaMap *base_Mapeada)

/*base_Datos_Usuarios Nombre de la listas de listas*/

{
	Usuario *aux_Usuario;
	Amigo *aux_Amigo;
	Amigo *auxxx;
	base_Mapeada-> primero = NULL;
	base_Mapeada-> ultimo = NULL;
	Map *nuevo_Map;
	amigoM *new_Friend;

	Map *auxMap;
	aux_Usuario = base_Datos_Usuario->primerUsuario;

	while (aux_Usuario != NULL)
	{
		aux_Amigo = aux_Usuario->primerAmigo;

		while (aux_Amigo != NULL)
		{
			nuevo_Map = (Map *)malloc(sizeof(Map));
			nuevo_Map ->siguiente = NULL;
			nuevo_Map ->primer_Amigo_Map = NULL;
			nuevo_Map ->ultimo_Amigo_Map = NULL;

			//auxMap = nuevo;

			auxxx = aux_Usuario->primerAmigo;
			nuevo_Map->UsuarioMap = aux_Usuario->Nombre;
			nuevo_Map->AmigoMap = aux_Amigo->Nombre;

			while (auxxx != NULL)
			{
				new_Friend  = (amigoM *)malloc(sizeof(amigoM));
				new_Friend->AmigoM = auxxx->Nombre;
				//auxMap->siguiente= new_Friend;
				//auxMap = new_Friend;
				auxxx = auxxx->siguiente;
				if (auxxx == NULL)
				{
					aux_Amigo = aux_Amigo->siguiente;
				}
			}

		}

		if (base_Mapeada -> primero == NULL)
		{
			base_Mapeada -> primero = nuevo_Map;
			base_Mapeada -> ultimo = nuevo_Map;
		}

		else
		{
			//nuevo_Map-> anterior =
			//		base_Mapeada -> ultimo;
			base_Mapeada -> ultimo -> siguiente =
					nuevo_Map;
			base_Mapeada -> ultimo = nuevo_Map;
		}
		aux_Usuario = aux_Usuario->siguiente;
	}
	return base_Mapeada;
}
