/*
 * Map-Reduce.c
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
 */
/*
 * Nuevo.c
 *
 *  Created on: 20/5/2015
 *      Author: personal
 */
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

	int sem;
	char usuario_Comp[100];
	char nombre_MapAct[100];
	char amigo_MapAct[100];
	char amigo_Comp[100];

	aux_Usuario = base_Datos_Usuario-> primerUsuario;

	while (aux_Usuario != NULL)
	{
		aux_Amigo = aux_Usuario->primerAmigo;

		while (aux_Amigo != NULL)
		{
			aux_Amigo_De_Amigo = aux_Usuario->primerAmigo;
			sem = 0;

			if(base_Mapeada->primero != NULL)
			{
				aux_Comp = (Map *)malloc(sizeof(Map));
				aux_Comp = base_Mapeada -> primero;

				strcpy(usuario_Comp,aux_Comp -> UsuarioMap);
				strcpy(amigo_Comp,aux_Comp -> AmigoMap);
				strcpy(nombre_MapAct,aux_Usuario -> Nombre);
				strcpy(amigo_MapAct,aux_Amigo -> Nombre);
//
//				printf("usuario_Comp: %s \n",usuario_Comp);
//				printf("amigo_Comp: %s \n",amigo_Comp);
//				printf("nombre_MapAct: %s \n",nombre_MapAct);
//				printf("amigo_MapAct: %s \n\n",amigo_MapAct);

				while((strcmp(usuario_Comp,nombre_MapAct) != 0) &&
						(aux_Comp -> siguiente != NULL) )

				{
//					printf("usuario_Comp: %s \n",usuario_Comp);
//					printf("amigo_Comp: %s \n",amigo_Comp);
//					printf("nombre_MapAct: %s \n",nombre_MapAct);
//					printf("amigo_MapAct: %s \n\n",amigo_MapAct);

					if ((((strcmp(nombre_MapAct,amigo_Comp)) == 0)
							&&
							((strcmp(usuario_Comp,amigo_MapAct)) == 0)))
					{

						aux_Amigo_De_Amigo = aux_Usuario->primerAmigo;

						while(aux_Amigo_De_Amigo != NULL)
						{
							new_Friend  = (amigoM *)malloc(
									sizeof(amigoM));
							new_Friend ->siguiente = NULL;

							new_Friend ->AmigoM =
									aux_Amigo_De_Amigo->Nombre;
							new_Friend->anterior =
									aux_Comp -> ultimo_Amigo_Map;
							aux_Comp ->ultimo_Amigo_Map ->siguiente =
									new_Friend;
							aux_Comp ->ultimo_Amigo_Map = new_Friend;
							aux_Amigo_De_Amigo =
									aux_Amigo_De_Amigo -> siguiente;
						}
						sem = 1;
						break;
					}

					aux_Comp = aux_Comp -> siguiente;
					strcpy(usuario_Comp,aux_Comp -> UsuarioMap);
					strcpy(amigo_Comp,aux_Comp -> AmigoMap);
				}
			}

			if (sem == 0)
			{
				nuevo_Map = (Map *)malloc(sizeof(Map));
				nuevo_Map -> siguiente = NULL;
				nuevo_Map -> primer_Amigo_Map = NULL;
				nuevo_Map -> ultimo_Amigo_Map = NULL;
				nuevo_Map->UsuarioMap = aux_Usuario->Nombre;
				nuevo_Map->AmigoMap = aux_Amigo->Nombre;
			}

			if (sem == 1)
			{
				aux_Amigo = aux_Amigo -> siguiente;
			}

			while ((aux_Amigo_De_Amigo != NULL) && (sem == 0))
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
