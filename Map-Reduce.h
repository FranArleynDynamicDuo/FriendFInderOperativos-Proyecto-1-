/*
 * Map-Reduce.h
 *
 *  Created on: May 8, 2015
 *      Author: franciscosucre
 */

#ifndef MAP_REDUCE_H_
#define MAP_REDUCE_H_
#include "ListaAmigos.h"

typedef struct amigoM

{
	char* AmigoM;
	struct amigoM *siguiente;
	struct amigoM *anterior;

} amigoM;


typedef struct Map

{
	char* UsuarioMap;
	char* AmigoMap;
	struct Map *siguiente;
	struct Map *anterior;
	amigoM *primer_Amigo_Map;
	amigoM *ultimo_Amigo_Map;

} Map;

typedef struct ListaMap

{
	Map *primero;
	Map *ultimo;

} ListaMap;

ListaMap *Mapeo(ListaUsuarios *base_Datos_Usuario,
		ListaMap *base_Mapeada);

ListaMap *Reduce(ListaMap *base_Mapeada, ListaMap *base_Reduce);


#endif /* MAP_REDUCE_H_ */
