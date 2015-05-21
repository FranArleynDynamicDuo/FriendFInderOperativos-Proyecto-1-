#include <stdlib.h>
#include "Map-Reduce.h"
#include "ListaAmigos.h"
#include <string.h>
#include <stdio.h>
#include "TextInputOutput.h"

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

				if (strcmp(aux_Map_Amigo,aux_Map_Amigo2) == 0)
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
				else
				{
					aux_Map_Amigo2 = aux_Map_Amigo2 -> siguiente;
				}
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


