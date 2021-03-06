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

/* @Nombre: Mapeo
 * @Funcion: Junta los amigos de dos personas en una unica lista,
 * 			 resultado en una lista Mapeada
 * @Entrada: *base_Mapeada base de datos a mapear
 * @Salida: *base_Mapeada Base de datos mapeada
 */

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
			nuevo_Map = (Map *)malloc(sizeof(Map));
			nuevo_Map -> siguiente = NULL;
			nuevo_Map -> primer_Amigo_Map = NULL;
			nuevo_Map -> ultimo_Amigo_Map = NULL;
			nuevo_Map-> UsuarioMap = aux_Usuario->Nombre;
			nuevo_Map-> AmigoMap = aux_Amigo->Nombre;

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

				while((strcmp(usuario_Comp,nombre_MapAct) != 0) &&
						(aux_Comp != NULL) )

				{

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
						free(nuevo_Map);
						sem = 1;
						break;
					}

					aux_Comp = aux_Comp -> siguiente;
					if (aux_Comp != NULL)
					{
						strcpy(usuario_Comp,aux_Comp -> UsuarioMap);
						strcpy(amigo_Comp,aux_Comp -> AmigoMap);
					}
				}
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

			if ((base_Mapeada -> primero == NULL) && (sem == 0))
					{
						base_Mapeada -> primero = nuevo_Map;
						base_Mapeada -> ultimo = nuevo_Map;
					}

			else if ((base_Mapeada -> primero != NULL) && (sem == 0))
					{
						base_Mapeada -> ultimo -> siguiente =
								nuevo_Map;
						base_Mapeada -> ultimo = nuevo_Map;
					}
		}
		aux_Usuario = aux_Usuario->siguiente;
	}
	return base_Mapeada;
}

/* @Nombre: Reduce
 * @Funcion: Busca los amigos repetidos en las listas mapeadas, estos
 * 			 son los amigos en comun entre las 2 personas
 * @Entrada: *base_Mapeada base de datos mapeada
 * 			 *base_Reduce base de datos a reducir
 * @Salida: *base_Reduce Base de datos reducida
 */

ListaMap *Reduce(ListaMap *base_Mapeada, ListaMap *base_Reduce)

{
	Map *aux_Map_Usuario;
	amigoM *aux_Map_Amigo;
	amigoM *aux_Map_Amigo2;
	base_Reduce -> primero = NULL;
	base_Reduce -> ultimo = NULL;
	Map *nuevo_Reduce;
	amigoM *new_Reduce;

	char nombre_Com[100];
	char nombre_Com2[100];

	aux_Map_Usuario = base_Mapeada -> primero;

	while (aux_Map_Usuario != NULL)
	{
		nuevo_Reduce = (Map *)malloc(sizeof(Map));
		nuevo_Reduce -> siguiente = NULL;
		nuevo_Reduce -> primer_Amigo_Map = NULL;
		nuevo_Reduce -> ultimo_Amigo_Map = NULL;

		nuevo_Reduce -> UsuarioMap = aux_Map_Usuario -> UsuarioMap;
		nuevo_Reduce -> AmigoMap   = aux_Map_Usuario -> AmigoMap;

		aux_Map_Amigo = aux_Map_Usuario -> primer_Amigo_Map;


		while (aux_Map_Amigo != NULL)
		{
			aux_Map_Amigo2 = aux_Map_Amigo -> siguiente;
			while (aux_Map_Amigo2 != NULL)
			{

				strcpy(nombre_Com,aux_Map_Amigo->AmigoM);
				strcpy(nombre_Com2,aux_Map_Amigo2->AmigoM);


				if (strcmp(nombre_Com,nombre_Com2) == 0)
				{
					new_Reduce = (amigoM *)malloc(sizeof(amigoM));
					new_Reduce -> AmigoM = aux_Map_Amigo -> AmigoM;

					if (nuevo_Reduce -> primer_Amigo_Map == NULL)
					{
						nuevo_Reduce -> primer_Amigo_Map = new_Reduce;
						nuevo_Reduce -> ultimo_Amigo_Map = new_Reduce;
					}
					else
					{
						nuevo_Reduce -> ultimo_Amigo_Map ->siguiente =
								new_Reduce;
						nuevo_Reduce ->ultimo_Amigo_Map = new_Reduce;
					}
				}

				aux_Map_Amigo2 = aux_Map_Amigo2 -> siguiente;
			}

			aux_Map_Amigo = aux_Map_Amigo -> siguiente;
		}

		if (base_Reduce -> primero == NULL)
		{
			base_Reduce -> primero = nuevo_Reduce;
			base_Reduce -> ultimo = nuevo_Reduce;
		}
		else
		{
			base_Reduce -> ultimo -> siguiente = nuevo_Reduce;
			base_Reduce -> ultimo = nuevo_Reduce;
		}

		aux_Map_Usuario = aux_Map_Usuario -> siguiente;

	}
	return base_Reduce;
}
