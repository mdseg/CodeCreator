/*
 * Campo.h
 *
 *  Created on: 28 oct. 2020
 *      Author: marcos
 */

#ifndef CAMPO_H_
#define CAMPO_H_

typedef struct{
	int idCampo;
	char nombreCampo[55];
	char tipoCampo[55];
}Campo;

Campo* campo_new();
int campo_initCampo(Campo* list[], int len);
void campo_delete(Campo* this);
int campo_getIdCampo(Campo* this);
int campo_setIdCampo(Campo* this, int idCampo);
int isValidIdCampo(int idCampo);
int campo_setIdCampo(Campo* this, int idCampo);
char* campo_getNombreCampo(Campo* this);
int campo_setNombreCampo(Campo* this, char* nombreCampo);
int isValidNombreCampo(char* nombreCampo);
char* campo_getTipoCampo(Campo* this);
int campo_setTipoCampo(Campo* this, char* tipoCampo);
int isValidNombreCampo(char* nombreCampo);
int campo_addNewRegistry(Campo* list[], int len, char* campoIngresado, char* tipoCampoIngresado);

#endif /* CAMPO_H_ */
