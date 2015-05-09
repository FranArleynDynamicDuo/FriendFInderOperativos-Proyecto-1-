/*
 * TextInputOutput.h
 *
 *  Created on: May 8, 2015
 *      Author: franciscosucre
 */

#ifndef TEXTINPUTOUTPUT_H_
#define TEXTINPUTOUTPUT_H_

ListaUsuarios *Leer_BaseDeDatos(FILE *files,ListaUsuarios *base_Datos_Usuario);
void GuardarResultados(FILE *files,ListaUsuarios *base_Datos_Usuario);

#endif /* TEXTINPUTOUTPUT_H_ */
