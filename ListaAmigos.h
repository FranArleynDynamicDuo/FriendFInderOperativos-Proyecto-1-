/*
 * ListaAmigos.h
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
 */

#ifndef LISTAAMIGOS_H_
#define LISTAAMIGOS_H_

typedef struct Amigo

{
	char* Nombre;
	struct Amigo *siguiente;
	struct Amigo *anterior;

} Amigo;

typedef struct Usuario

{
	char* Nombre;
	struct Usuario *siguiente;
	struct Usuario *anterior;
	Amigo *primerAmigo;
	Amigo *ultimoAmigo;

} Usuario;

typedef struct ListaUsuarios

{
	Usuario *primerUsuario;
	Usuario *ultimoUsuario;

} ListaUsuarios;

#endif /* LISTAAMIGOS_H_ */
