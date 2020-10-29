#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include <stdio.h>
#include <string.h>
#include "Campo.h"



static int campo_searchFreeIndex(Campo* list[],int* pIndex, int len);
static int generateNewId(void);


Campo* campo_new()
{
	return (Campo*)malloc(sizeof(Campo));
}
void campo_delete(Campo* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
int campo_getIdCampo(Campo* this)
{

	if(this != NULL)
	{
		return this->idCampo;
	}
	else
	{
		return -1;
	}

}
int campo_setIdCampo(Campo* this, int idCampo)
{
	int retorno =-1;
	if(this !=NULL && isValidIdCampo(idCampo)==1)
	{
		this->idCampo = idCampo;
		retorno = 0;
	}
	return retorno;
}
int isValidIdCampo(int idCampo)
{
	return 1;
}
char* campo_getNombreCampo(Campo* this)
{
	if(this != NULL)
	{
		return this->nombreCampo;
	}
	else
	{
   	return NULL;
    }
}
int campo_setNombreCampo(Campo* this, char* nombreCampo)
{
	int retorno =-1;
	if(this !=NULL && isValidNombreCampo(nombreCampo)==1)
	{
		strncpy(this->nombreCampo,nombreCampo,sizeof(this->nombreCampo));
		retorno = 0;
	}
	return retorno;
}
int isValidNombreCampo(char* nombreCampo)
{
	return 1;
}
char* campo_getTipoCampo(Campo* this)
{
	if(this != NULL)
	{
		return this->tipoCampo;
	}
	else
	{
   	return NULL;
    }
}
int campo_setTipoCampo(Campo* this, char* tipoCampo)
{
	int retorno =-1;
	if(this !=NULL && isValidTipoCampo(tipoCampo)==1)
	{
		strncpy(this->tipoCampo,tipoCampo,sizeof(this->tipoCampo));
		retorno = 0;
	}
	return retorno;
}
int isValidTipoCampo(char* tipoCampo)
{
	return 1;
}

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
int campo_addNewRegistry(Campo* list[], int len, char* campoIngresado, char* tipoCampoIngresado)
{
	int retorno = -1;
	int index;
	int id;
	Campo* campo;
	if(campo_searchFreeIndex(list, &index, len) == 0)
	{
		campo = (Campo*)malloc(sizeof(Campo));
		if (campo != NULL)
		{
			id = generateNewId();
			campo_setIdCampo(campo, id);
			campo_setNombreCampo(campo, campoIngresado);
			campo_setTipoCampo(campo, tipoCampoIngresado);
			list[index] = campo;
			retorno = 0;
		}
	}
	return retorno;
}

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



int campo_findCampoById(Campo* list[], int len,int id)
{
	int i = 0;
	int retorno = -1;
	int idCampoActual;
	Campo* bufferCampo = NULL;
		if(list != NULL && len > 0 && id > 0)
		{
			for ( i = 0; i < len; i++)
			{
				bufferCampo = list[i];
				idCampoActual = campo_getIdCampo(bufferCampo);
				if(idCampoActual == id)
				{
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}


static int campo_searchFreeIndex(Campo* list[],int* pIndex, int len)
{
	int retorno = -1;
		int i;
			if(list != NULL && len > 0)
			{
				for(i = 0;i<len;i++)
				{
					if(list[i] == NULL)
					{
						*pIndex = i;
						retorno = 0;
						break;
					}
				}
			}
		return retorno;
}
static int generateNewId(void)
{
	static int id= 0;
	id = id+1;
	return id;
}
