/*
 * Map-Reduce.h
 *
 *  Created on: May 8, 2015
 *      Author: franciscosucre
 */

#ifndef MAP_REDUCE_H_
#define MAP_REDUCE_H_
#include "ListaAmigos.h"

typedef struct map

{
	char* UsuarioMap;
	char* AmigoMap;
	struct AmigoM *siguiente;
	struct AmigoM *anterior;

} Map;

typedef struct amigoM

{
	char* AmigoM;
	struct Amigo *siguiente;
	struct Amigo *anterior;

} amigoM;

typedef struct listaMap

{
	Map *primero;
	Map *ultimo;

} ListaMap;

ListaMap *Mapeo(ListaUsuarios *base_Datos_Usuario,
		ListaMap *base_Mapeada);


#endif /* MAP_REDUCE_H_ */
