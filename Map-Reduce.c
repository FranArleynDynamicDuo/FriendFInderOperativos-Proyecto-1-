/*
 * Map-Reduce.c
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
 */

#include <stdlib.h>
#include "Map-Reduce.h"
#include "ListaAmigos.h"
#include <string.h>
#include <stdio.h>
#include "TextInputOutput.h"

ListaMap *Mapeo(ListaUsuarios *base_Datos_Usuario,
		ListaMap *base_Mapeada)

/*base_Datos_Usuarios Nombre de la listas de listas*/

{
	Usuario *aux_Usuario;
	Amigo *aux_Amigo;
	Amigo *aux_Amigo_De_Amigo;
	base_Mapeada-> primero = NULL;
	base_Mapeada-> ultimo = NULL;
	Map *nuevo_Map;
	Map *aux_Comp;
	amigoM *new_Friend;

	char nombre_Comp[100];
	char nombre_MapAct[100];


	aux_Usuario = base_Datos_Usuario-> primerUsuario;

	while (aux_Usuario != NULL)
	{
		aux_Amigo = aux_Usuario->primerAmigo;

		while (aux_Amigo != NULL)
		{
			nuevo_Map = (Map *)malloc(sizeof(Map));
			nuevo_Map -> siguiente = NULL;
			nuevo_Map -> primer_Amigo_Map = NULL;
			nuevo_Map -> ultimo_Amigo_Map = NULL;


			if(base_Mapeada->primero != NULL)
			{
				aux_Comp = (Map *)malloc(sizeof(Map));
				aux_Comp = base_Mapeada -> primero;
				printf("aux_Comp: %s\n",aux_Comp ->UsuarioMap );
				printf("aux_Usuario: %s\n",aux_Usuario ->Nombre );


				strcpy(nombre_Comp,aux_Comp -> UsuarioMap);
				strcpy(nombre_MapAct,aux_Usuario -> Nombre);


				while((strcmp(nombre_Comp,nombre_MapAct) != 0) &&
						(aux_Comp -> siguiente != NULL) )

				{
//					if ((((strcmp(aux_Comp -> UsuarioMap,
//							aux_Amigo -> Nombre)) == 0)
//							&&
//							((strcmp(aux_Comp ->AmigoMap,
//									aux_Usuario ->Nombre)) == 0)))
//					{
//
//						while(aux_Amigo != NULL)
//						{
//							new_Friend  = (amigoM *)malloc(
//									sizeof(amigoM));
//							new_Friend ->siguiente = NULL;
//
//							new_Friend ->AmigoM = aux_Amigo->Nombre;
//							new_Friend->anterior =
//									aux_Comp -> ultimo_Amigo_Map;
//							aux_Comp ->ultimo_Amigo_Map ->siguiente =
//									new_Friend;
//							aux_Comp ->ultimo_Amigo_Map = new_Friend;
//							aux_Amigo = aux_Amigo -> siguiente;
//						}
//						break;
//					}
					if (aux_Comp->siguiente->siguiente == NULL)
					{
						printf("\n \nAux Comp es NULL y va a explotar!");
					}

					aux_Comp = aux_Comp -> siguiente;
					strcpy(nombre_Comp,aux_Comp ->UsuarioMap);

				}
			}

			aux_Amigo_De_Amigo = aux_Usuario->primerAmigo;
			nuevo_Map->UsuarioMap = aux_Usuario->Nombre;
			nuevo_Map->AmigoMap = aux_Amigo->Nombre;

			while (aux_Amigo_De_Amigo != NULL)
			{
				new_Friend  = (amigoM *)malloc(sizeof(amigoM));
				new_Friend->AmigoM = aux_Amigo_De_Amigo->Nombre;

				if (nuevo_Map ->primer_Amigo_Map == NULL)
				{
					nuevo_Map ->primer_Amigo_Map = new_Friend;
					nuevo_Map ->ultimo_Amigo_Map = new_Friend;
				}

				else
				{
					new_Friend->anterior =
							nuevo_Map -> ultimo_Amigo_Map;
					nuevo_Map ->ultimo_Amigo_Map ->siguiente =
							new_Friend;
					nuevo_Map ->ultimo_Amigo_Map = new_Friend;

				}

				aux_Amigo_De_Amigo = aux_Amigo_De_Amigo->siguiente;

				if (aux_Amigo_De_Amigo == NULL)
				{
					aux_Amigo = aux_Amigo->siguiente;
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
		}
		aux_Usuario = aux_Usuario->siguiente;
	}
	return base_Mapeada;
}

void Reduce()
{


}

