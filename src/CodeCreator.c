/*
 ============================================================================
 Name        : CodeCreator.c
 Author      : Marcos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Entidad.h"
#include "Campo.h"

#define CANT_CAMPOS 20


int main(void) {

	char tipoEstructura[50] = "Persona";
	char campoIngresado[50] = "nombre";
	char tipoCampoIngresado[50] = "char*";
/*
	print_estructura_new(tipoEstructura);
	print_estructura_delete(tipoEstructura);
	print_estructura_getCampo(tipoEstructura, campoIngresado,tipoCampoIngresado);
	print_estructura_setCampoUniversal(tipoEstructura, campoIngresado, tipoCampoIngresado);
	print_estructura_setCampoString(tipoEstructura, campoIngresado, tipoCampoIngresado);
	print_estructura_isValidCampo(campoIngresado, tipoCampoIngresado);
	print_estructura_initEstructura(tipoEstructura);
	print_estructura_checkActiveEstructura(tipoEstructura);
	print_estructura_findEstructuraById(tipoEstructura);
	print_estructura_searchFreeIndex(tipoEstructura);

*/
	Campo* listadoCampos[CANT_CAMPOS];
	campo_initCampo(listadoCampos, CANT_CAMPOS);
	campo_addNewRegistry(listadoCampos, CANT_CAMPOS, "nombre", "char*");
	campo_addNewRegistry(listadoCampos, CANT_CAMPOS, "nombre", "char*");
	campo_addNewRegistry(listadoCampos, CANT_CAMPOS, "nombre", "int");
	campo_addNewRegistry(listadoCampos, CANT_CAMPOS, "nombre", "int");
	print_cFile(tipoEstructura,listadoCampos);
	print_hFile(tipoEstructura, campoIngresado, tipoCampoIngresado, listadoCampos);

	return EXIT_SUCCESS;
}



