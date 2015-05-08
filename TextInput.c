/*
 * TextInput.c
 *
 *  Created on: May 5, 2015
 *      Author: franciscosucre
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaAmigos.h"

ListaUsuarios *Leer_BaseDeDatos(FILE *files,ListaUsuarios *baseDatos)
{

	if (files == NULL)
	{
	   perror ("Error al abrir fichero.txt");
	}

	Usuario *AmigoNueva;
}
