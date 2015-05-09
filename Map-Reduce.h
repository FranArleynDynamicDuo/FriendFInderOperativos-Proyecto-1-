/*
 * Map-Reduce.h
 *
 *  Created on: May 8, 2015
 *      Author: franciscosucre
 */

#ifndef MAP_REDUCE_H_
#define MAP_REDUCE_H_

typedef struct map

{
	char UsuarioMap[30];
	char AmigoMap[30];
	struct AmigoM *siguiente;
	struct AmigoM *anterior;

} Map

typedef struct amigoM

{
	char AmigoM[30];
	struct Amigo *siguiente;
	struct Amigo *anterior;

} amigoM;

typedef struct listaMap

{
	Map *primero;
	Map *ultimo;

} ListaMap;


#endif /* MAP_REDUCE_H_ */
