/*
 * Map-Reduce.c
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
 */

#include <stdlib.h>
#include "Map-Reduce.h"
#include "ListaAmigos.h"

ListaMap *Mapeo(ListaUsuarios *base_Datos_Usuario) /*base_Datos_Usuarios Nombre de la listas de listas*/

{
	ListaMap *ListaMapeada = (ListaMap *)malloc(sizeof(ListaMap));
	ListaMapeada->primero = NULL;
	ListaMapeada->ultimo = NULL;

	Usuario *aux;
	Amigo *auxx;
	Amigo *auxxx;
	AmigoM *auxMap;
	Map *auxxMap;

	aux = base_Datos_Usuario->primerUsuario;

	while (aux != NULL)

	{
		auxx = aux->primerAmigo;
		while (auxx != NULL)

		{
			Map *nuevo = (Map *)malloc(sizeof(Map));
			nuevo->siguiente = NULL;
			nuevo->primerAmigoMap = NULL;
			nuevo->ultimoAmigoMap = NULL;

			auxxx = aux->primerAmigo;
			nuevo->UsuarioMap = aux->Nombre;
			nuevo->AmigoMap = auxx->Nombre;

			if (ListaMapeada->primero == NULL)

			{
				ListaMapeada->primero = nuevo;
				ListaMapeada->ultimo = nuevo;
				auxxMap = nuevo;
			}

			else if (ListaMapeada->primero != NULL)

			{
				auxxMap->siguiente = nuevo;
				ListaMapeada->ultimo;
				auxxMap = auxxMap->siguiente;
			}

			while (auxxx != NULL)

			{
				AmigoM *new  = (AmigoM *)malloc(sizeof(AmigoM));
				new->siguiente = NULL;

				new->AmigoM = auxxx->Nombre;


				if (nuevo->primerAmigoMap == NULL)
				{
					nuevo->primerAmigoMap = new;
					nuevo->ultimoAmigoMap = new;
					auxMap = new;
				}

				else if (nuevo->primerAmigoMap != NULL)
				{
					auxMap->siguiente = new;
					nuevo->ultimoAmigoMap = new;
					auxMap = auxMap->siguiente;
				}

				auxxx = auxxx->siguiente;

				if (auxxx == NULL)
				{
					auxx = auxx->siguiente;
				}
			}

		}
		aux = aux->siguiente;
	}
}


