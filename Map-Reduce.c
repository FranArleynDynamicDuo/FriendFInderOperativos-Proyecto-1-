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
	Usuario *aux;
	Amigo *auxx;
	Amigo *auxxx;
	base_Mapeada-> primero = NULL;
	base_Mapeada-> ultimo = NULL;

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
				amigoM *new  = (amigoM *)malloc(sizeof(new));
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

		if (base_Mapeada->primero == NULL)
		{
			base_Mapeada->primero = aux;
			base_Mapeada -> ultimo = aux;
		}

		else
		{
			aux -> anterior =
					base_Mapeada -> ultimo;
			base_Mapeada -> ultimo -> siguiente =
					aux;
			base_Mapeada -> ultimo = aux;
		}
		aux = aux->siguiente;
	}
	return base_Mapeada;
}
