/*
 * Entidad.h
 *
 *  Created on: 27 oct. 2020
 *      Author: marcos
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_

#include "Campo.h"

int print_estructura_new(char* tipoEstructura);
int print_estructura_delete(char* tipoEstructura);
int print_estructura_setCampoUniversal(char* tipoEstructura, char* campoIngresado, char* tipoCampoIngresado);
int print_estructura_getCampo(char* tipoEstructura, char* campoIngresado, char* tipoCampoIngresado);
int print_estructura_setCampoString(char* tipoEstructura, char* campoIngresado, char* tipoCampoIngresado);
int print_estructura_isValidCampo(char* campoIngresado, char* tipoCampoIngresado);
int print_estructura_checkActiveEstructura(char* tipoEstructura);
int print_estructura_initEstructura(char* tipoEstructura);
int print_estructura_findEstructuraById(char* tipoEstructura);
int print_estructura_searchFreeIndex(char* tipoEstructura);
void print_cFile(char* tipoEstructura, Campo* campoList[]);
void print_hFile(char* tipoEstructura, Campo* campoList[]);
void print_estructura_generateId(void);


#endif /* ENTIDAD_H_ */
