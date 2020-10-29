/*
 ============================================================================
 Name        : clase_18b.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Plantillas ABM memorias dinamicas
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include <stdio.h>
#include <string.h>
#include "Campo.h"


//Estructura tipo
typedef struct{
	char name[55];
	int fileNumber;
	char cuit[55];
	int id;
}Estructura;


//UNA SOLA VEZ:
//new
//newParametros
//delete

//POR CADA CAMPO:
//get
//set
//isValid

//new

int prepareInput(char* input, char* inputMayus, char* inputMinus);
int create_entity(char* tipoEstructura, Campo* campoList[]);


int print_estructura_new(char* tipoEstructura)
{
	int retorno = -1;
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];

	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);


	printf("%s* %s_new()\n"
			"{\n"
			"	return (%s*)malloc(sizeof(%s));\n"
			"}\n",inputEstructuraMayus,inputEstructuraMinus,inputEstructuraMayus,inputEstructuraMayus);
	retorno = 0;
	return retorno;
}
Estructura* estructura_new()
{
	return (Estructura*) malloc(sizeof(Estructura));
}

//newParametros
/*
Estructura* estructura_newParametros(tipoCampo1 campo1, tipoCampoN campoN)
{
	Estructura* this = estructura_new();
	if(this!=NULL)
	{
		if(estructura_setCampo1(this,campo1)!=-1 &&
	       estructura_setCampoN(this,campoN)!=-1)
		{
			return this;
		}
	}
	return -1;
}
*/
//delete

int print_estructura_delete(char* tipoEstructura)
{
	int retorno = -1;
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];
	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);

	printf("void %s_delete(%s* this)\n"
	"{\n"
	"	if(this != NULL)\n"
	"	{\n"
	"		free(this);\n"
	"	}\n"
	"}\n",inputEstructuraMinus,inputEstructuraMayus);
	retorno = 0;
	return retorno;

}
void estructura_delete(Estructura* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int print_estructura_getCampo(char* tipoEstructura, char* campoIngresado, char* tipoCampoIngresado)
{
	int retorno = -1;
	char inputCampoMayus[50];
	char inputCampoMinus[50];
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];
	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);
	prepareInput(campoIngresado,inputCampoMayus,inputCampoMinus);
	printf("%s %s_get%s(%s* this)\n"
	"{\n"
	"	if(this != NULL)\n"
	"	{\n"
	"		return this->%s;\n"
	"	}\n"
	"	else"
	"   {\n"
	"   	return NULL;\n"
	"   }\n"
	"}\n",tipoCampoIngresado,inputEstructuraMinus,inputCampoMayus,inputEstructuraMayus,
	inputCampoMinus);
	retorno = 0;
	return retorno;

}
//get
/*
Estructura* estructura_getCampo(Estructura* this)
{
	if(this!=NULL)
	{
		return this->campo;
	}
	return -1;
}
*/


int print_estructura_setCampoUniversal(char* tipoEstructura, char* campoIngresado, char* tipoCampoIngresado)
{
	int retorno = -1;
	char inputCampoMayus[50];
	char inputCampoMinus[50];
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];
	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);
	prepareInput(campoIngresado,inputCampoMayus,inputCampoMinus);


	printf("int %s_set%sUniversal(%s* this, %s %s)\n"
	"{\n"
	"	int retorno =-1;\n"
	"	if(this !=NULL && isValid%s(%s)==1)\n"
	"	{\n"
	"		this->%s = %s;\n"
	"		retorno = 0;\n"
	"	}\n"
	"	return retorno;\n"
	"}\n",inputEstructuraMinus, inputEstructuraMayus, inputEstructuraMayus, inputCampoMayus, inputCampoMinus,inputCampoMayus,inputCampoMinus,inputCampoMinus,inputCampoMinus );


	retorno = 0;
	return retorno;

}
//set universal
/*
int estructura_setCampo(Estructura* this, tipoCampo campo)
{
	int retorno =-1;
	if(this !=NULL && isValidCampo(campo)==1)
	{
		this->campo =campo;
		retorno = 0;
	}
	return retorno;
}
*/

int print_estructura_setCampoString(char* tipoEstructura, char* campoIngresado, char* tipoCampoIngresado)
{
	int retorno = -1;
	char inputCampoMayus[50];
	char inputCampoMinus[50];
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];

	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);
	prepareInput(campoIngresado,inputCampoMayus,inputCampoMinus);


	printf("int %s_set%sString(%s* this, %s %s)\n"
	"{\n"
	"	int retorno =-1;\n"
	"	if(this !=NULL && isValid%s(%s)==1)\n"
	"	{\n"
	"		strncpy(this->%s,%s,sizeof(this->%s));\n"
	"		retorno = 0;\n"
	"	}\n"
	"	return retorno;\n"
	"}\n",inputEstructuraMinus, inputCampoMayus, inputEstructuraMayus, tipoCampoIngresado, inputCampoMinus,inputCampoMayus,inputCampoMinus,inputCampoMinus,inputCampoMinus,inputCampoMinus );


	retorno = 0;
	return retorno;

}
//set especifico para strings
/*
int estructura_setCampo(Estructura* this, tipoCampo campo)
{
	int retorno =-1;
		if(this !=NULL && isValidCampo(campo)==1)
		{
			strncpy(this->campo,campo,sizeof(this->campo));
			retorno = 0;
		}
		return retorno;
}
*/

int print_estructura_isValidCampo(char* campoIngresado, char* tipoCampoIngresado)
{
	int retorno = -1;
	char inputCampoMayus[50];
	char inputCampoMinus[50];
	prepareInput(campoIngresado,inputCampoMayus,inputCampoMinus);
	printf(
	"int isValid%s(%s %s)\n"
	"{\n"
	"	return 1;\n"
	"}\n",inputCampoMayus,tipoCampoIngresado, inputCampoMinus);


	retorno = 0;
	return retorno;
}

int prepareInput(char* input, char* inputMayus, char* inputMinus)
{
	int retorno = -1;
	if(input != NULL && inputMayus != NULL && inputMinus != NULL)
	{
		strncpy(inputMayus,input,sizeof(inputMayus));
		strncpy(inputMinus,input,sizeof(inputMinus));
		utn_upperOnlyFirstCharArray(inputMayus);
		utn_lowerOnlyFirstCharArray(inputMinus);
		retorno = 0;
	}

	return retorno;
}
//isValid
/*
isValidCampo(tipoCampo campo)
{
	return 1;
}
*/

int print_estructura_initEstructura(char* tipoEstructura)
{
	int retorno = -1;
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];
	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);
	printf(
	"int %s_init%s(%s* list[], int len)\n"
	"{\n"
	"	int retorno = -1;\n"
	"	int i;\n"
	"	if(list != NULL && len > 0)\n"
	"    {\n"
	"		for(i = 0;i<len;i++)\n"
	"		{\n"
	"			list[i] = NULL;\n"
	"		}\n"
	"		retorno = 0;\n"
	"	}\n"
	"	return retorno;\n"
	"}\n",inputEstructuraMinus,inputEstructuraMayus,inputEstructuraMayus);
	return retorno;
}

/*
int campo_initCampo(Campo* list[], int len)
{
	int retorno = -1;
	int i;
		if(list != NULL && len > 0)
		{
			for(i = 0;i<len;i++)
			{
			list[i] = NULL;
			//*(list+i) = NULL;
			}
			retorno = 0;
		}
		return retorno;
}
*/

int print_estructura_checkActiveEstructura(char* tipoEstructura)
{
	int retorno = -1;
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];
	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);
	printf(
	"int %s_checkActive%s(%s* list[], int len)\n"
	"{\n"
	"	int retorno = -1;\n"
	"	int i;\n"
	"	if(list != NULL && len > 0)\n"
	"    {\n"
	"		for(i = 0;i<len;i++)\n"
	"		{\n"
	"			if(list[i] != NULL)\n"
	"			{\n"
	"				retorno = 0;\n"
	"				break;\n"
	"			}\n"
	"		}\n"
	"	}\n"
	"	return retorno;\n"
	"}\n",inputEstructuraMinus,inputEstructuraMayus,inputEstructuraMayus);
	return retorno;
}
/*
int campo_checkActiveCampo(Campo* list[], int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0;i<len;i++)
		{
			if(list[i] != NULL)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
*/
int print_estructura_findEstructuraById(char* tipoEstructura)
{
	int retorno = -1;
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];
	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);
	printf(
	"int %s_find%sById(%s* list[], int len, int id)\n" //1-3
	"{\n"
	"	int retorno = -1;\n"
	"	int i;\n"
	"	int id%sActual;\n" //4
	"	if(list != NULL && len > 0 && id > 0)\n"
	"    {\n"
	"		for(i = 0;i<len;i++)\n"
	"		{\n"
	"			buffer%s = list[i];\n" //5
	"			id%sActual = %s_getId%s(buffer%s);\n" // 6-7-8-9
	"			if(id%sActual == id)\n" //10
	"			{\n"
	"				retorno = i;\n"
	"				break;\n "
	"			}\n"
	"		}\n"
	"	}\n"
	"	return retorno;\n"
	"}\n",inputEstructuraMinus,inputEstructuraMayus,
	inputEstructuraMayus,inputEstructuraMayus,
	inputEstructuraMayus,inputEstructuraMayus,inputEstructuraMinus,
	inputEstructuraMayus,inputEstructuraMayus,inputEstructuraMayus);
	return retorno;
}

void print_estructura_generateId(void)
{
	printf(
	"static int generateNewId(void)\n"
	"{\n"
	"	static int id= 0;\n"
	"	id = id+1;\n"
	"	return id;\n"
	"}\n");
}

int print_estructura_searchFreeIndex(char* tipoEstructura)
{
	int retorno = -1;
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];
	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);
	printf(
	"static int %s_searchFreeIndex(%s* list[],int* pIndex, int len)\n"
	"{\n"
	"	int retorno = -1;\n"
	"	int i;\n"
	"	if(list != NULL && len > 0)\n"
	"	{\n"
	"		for(i = 0;i<len;i++)\n"
	"		{\n"
	"			if(list[i] == NULL)\n"
	"			{\n"
	"				*pIndex = i;\n"
	"				retorno = 0;\n"
	"				break;\n"
	"			}\n"
	"		}\n"
	"	}\n"
	"	return retorno;\n"
	"}\n"
	,
	inputEstructuraMinus,inputEstructuraMayus
	);
	return retorno;
}

void print_cFile(char* tipoEstructura, Campo* campoList[])
{
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];
	char inputTipoCampo[50];
	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);

	printf("Comienzo .c\n");
	printf("--------------------------------------------\n");
	printf(
	"#include <stdio_ext.h>\n"
	"#include <stdlib.h>\n"
	"#include 'utn.h'\n"
	"#include <stdio.h>\n"
	"#include <string.h>\n"
	"#include '%s.h'\n", inputEstructuraMayus
	);
	printf(
	"static int %s_searchFreeIndex(%s* list[],int* pIndex, int len);\n"
	"static int generateNewId(void);\n;",inputEstructuraMinus,inputEstructuraMayus);
	create_entity(tipoEstructura, campoList);
	printf("\n--------Fin del .c file-------\n");

	/*Campo* campo_new();
	int campo_initCampo(Campo* list[], int len);
	void campo_delete(Campo* this);
	int campo_addNewRegistry(Campo* list[], int len, char* campoIngresado, char* tipoCampoIngresado);
*/
}

void print_hFile(char* tipoEstructura, Campo* campoList[])
{
	char inputCampoMayus[50];
	char inputCampoMinus[50];
	char inputEstructuraMayus[50];
	char inputEstructuraMinus[50];
	char inputTipoCampo[50];
	Campo* bufferCampo;
	int i;
	prepareInput(tipoEstructura,inputEstructuraMayus,inputEstructuraMinus);

	printf("Comienzo .h\n");
	printf("--------------------------------------------\n");
	printf(
	"#ifndef CAMPO_H_\n"
	"#define CAMPO_H_\n"
	);
	printf("typedef struct{\n");
	for(i = 0; campoList[i] != NULL; i++)
	{
		bufferCampo = campoList[i];
		printf("    %s %s;\n",campo_getTipoCampo(bufferCampo),campo_getNombreCampo(bufferCampo));
	}
	printf("}%s;\n",inputEstructuraMayus);
	printf(
	"%s* %s_new();\n"
	"int %s_init%s(%s* list[], int len);\n"
	"void %s_delete(%s* this);\n"
	,inputEstructuraMayus,inputEstructuraMinus,
	inputEstructuraMinus,inputEstructuraMayus,inputEstructuraMayus,
	inputEstructuraMinus,inputEstructuraMayus
	);
	for(i = 0; campoList[i] != NULL; i++)
		{
		bufferCampo = campoList[i];
		prepareInput(campo_getNombreCampo(bufferCampo),inputCampoMayus,inputCampoMinus);
		printf(
		"%s %s_get%s(%s* this);\n"
		"int %s_set%sUniversal(%s* this, %s %s);\n"
		"int %s_set%sString(%s* this, %s %s);\n"
		"int isValid%s(%s %s);\n"
		,inputCampoMinus,inputEstructuraMinus,inputCampoMayus,inputEstructuraMayus
		,inputEstructuraMinus, inputEstructuraMayus, inputEstructuraMayus, inputCampoMayus, inputCampoMinus
		,inputEstructuraMinus, inputEstructuraMayus, inputEstructuraMayus, inputCampoMayus, inputCampoMinus
		,inputCampoMayus,campo_getTipoCampo(bufferCampo), inputCampoMinus
		);
		}

	/*
	"%s %s_get%s(%s* this)\n"
	"int %s_set%s(%s* this, %s %s)\n"
	"int %s_set%s(%s* this, %s %s)\n"
	"int isValid%s(%s %s)\n"
	*/

	/*

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

	*/
	printf("\n--------Fin del .h file-------\n");

	/*Campo* campo_new();
	int campo_initCampo(Campo* list[], int len);
	void campo_delete(Campo* this);
	int campo_addNewRegistry(Campo* list[], int len, char* campoIngresado, char* tipoCampoIngresado);
*/
}


int create_entity(char* tipoEstructura, Campo* campoList[])
{
	int retorno = -1;
	//int index;
	int i;
	Campo* bufferCampo;
	if (tipoEstructura != NULL && campoList != NULL)
	{
		print_estructura_new(tipoEstructura);
		print_estructura_delete(tipoEstructura);
		print_estructura_initEstructura(tipoEstructura);
		print_estructura_checkActiveEstructura(tipoEstructura);
		print_estructura_findEstructuraById(tipoEstructura);
		print_estructura_searchFreeIndex(tipoEstructura);
		for(i = 0; campoList[i] != NULL; i++)
		{
			bufferCampo = campoList[i];
			print_estructura_getCampo(tipoEstructura,campo_getNombreCampo(bufferCampo),campo_getTipoCampo(bufferCampo));
			print_estructura_setCampoUniversal(tipoEstructura,campo_getNombreCampo(bufferCampo),campo_getTipoCampo(bufferCampo));
			print_estructura_setCampoString(tipoEstructura,campo_getNombreCampo(bufferCampo),campo_getTipoCampo(bufferCampo));
			print_estructura_isValidCampo(campo_getNombreCampo(bufferCampo),campo_getTipoCampo(bufferCampo));

		}
	}


	return retorno;
}




