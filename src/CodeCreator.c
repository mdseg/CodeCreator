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


	Campo* listadoCampos[CANT_CAMPOS];
	campo_initCampo(listadoCampos, CANT_CAMPOS);
	campo_addNewRegistry(listadoCampos, CANT_CAMPOS, "nombre", "char*");
	campo_addNewRegistry(listadoCampos, CANT_CAMPOS, "nombre", "char*");
	campo_addNewRegistry(listadoCampos, CANT_CAMPOS, "nombre", "int");
	campo_addNewRegistry(listadoCampos, CANT_CAMPOS, "nombre", "int");
	print_cFile(tipoEstructura,listadoCampos);
	print_hFile(tipoEstructura,listadoCampos);

	return EXIT_SUCCESS;
}



