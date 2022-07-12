#include "Pokemon.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pokemon.h"
#include "Input.h"



Pokemon* pokemon_new()
{
	Pokemon* unPokemon = NULL;
	unPokemon = (Pokemon*) malloc (sizeof(Pokemon));
	return unPokemon;
}
Pokemon* pokemon_newParametros(char* numeroStr,char* nombreStr,char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, char* valorAtaqueStr, char* esVariocolorStr)
{
	int numero;
	int esVariocolor;
	int valorAtaque;
	Pokemon* unPokemon = NULL;
	unPokemon = pokemon_new();
	if(unPokemon != NULL)
	{


		numero=atoi(numeroStr);
		valorAtaque=atoi(valorAtaqueStr);
		esVariocolor=atoi(esVariocolorStr);
		pokemon_setNumero(unPokemon, numero);
		pokemon_setTipo(unPokemon, tipoStr);
		pokemon_setNombre(unPokemon, nombreStr);
		pokemon_setTamanio(unPokemon, tamanioStr);
		pokemon_setAtaqueCargado(unPokemon, ataqueCargadoStr);
		pokemon_setValorAtaque(unPokemon, valorAtaque);
		pokemon_setEsVariocolor(unPokemon, esVariocolor);
	}
	return unPokemon;
}

int pokemon_setNumero(Pokemon* this,int numero)
{
	int ret= 0;

	if(this != NULL)
	{
		this->numero=numero;
		ret = 1;
	}
	return ret;
}

int pokemon_setNombre(Pokemon* this,char* nombre)
{
	int ret=0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		ret=1;
	}

	return ret;
}

int pokemon_setTipo(Pokemon* this,char* tipo)
{
	int ret=0;

	if(this!=NULL)
	{
		strcpy(this->tipo,tipo);
		ret=1;
	}
	return ret;
}

int pokemon_setTamanio(Pokemon* this,char* tamanio)
{
	int ret=0;
	if(this!=NULL)
	{
		strcpy(this->tamanio,tamanio);
		ret=1;
	}
	return ret;
}


int pokemon_setAtaqueCargado(Pokemon* this,char* ataqueCargado)
{
	int ret=0;

	if(this != NULL && ataqueCargado != NULL)
	{
		strcpy(this->ataqueCargado,ataqueCargado);
		ret=1;
	}

	return ret;
}

int pokemon_setValorAtaque(Pokemon* this,int valorAtaque)
{
	int ret=0;

	if(this!=NULL)
	{
		this->valorAtaque=valorAtaque;
		ret=1;
	}
	return ret;
}

int pokemon_setEsVariocolor(Pokemon* this,int esVariocolor)
{
	int ret=0;
	if(this!=NULL)
	{
		this->esVariocolor=esVariocolor;
		ret=1;
	}
	return ret;
}
/////////////
int pokemon_getNombre(Pokemon* this,char* nombre)
{
	int ret=1;
	if(this != NULL)
	{
		strcpy(nombre,this->nombre);
		ret=0;
	}
	return ret;
}
int pokemon_getNumero(Pokemon* this,int* numero)
{
	int ret=1;
	if(this != NULL && numero != NULL)
	{
		*numero=this->numero;
		ret=0;
	}
	return ret;
}

int pokemon_getTipo(Pokemon* this,char* tipo)
{
	int ret=1;
	if(this != NULL)
	{
		strcpy(tipo,this->tipo);
		ret=0;
	}
	return ret;
}

int pokemon_getAtaqueCargado(Pokemon* this,char* ataqueCargado)
{
	int ret=1;
	if(this != NULL)
	{
		strcpy(ataqueCargado,this->ataqueCargado);
		ret=0;
	}
	return ret;
}

int pokemon_getTamanio(Pokemon* this,char* tamanio)
{
	int ret=1;
	if(this != NULL)
	{
		strcpy(tamanio,this->tamanio);
		ret=0;
	}
	return ret;
}

int pokemon_getValorAtaque(Pokemon* this,int* valorAtaque)
{
	int ret=1;
	if(this != NULL && valorAtaque)
	{
		*valorAtaque=this->valorAtaque;
		ret=0;
	}
	return ret;
}
int pokemon_getEsVariocolor(Pokemon* this,int* esVariocolor)
{
	int ret=1;
	if(this!=NULL && esVariocolor!=NULL)
	{
		*esVariocolor=this->esVariocolor;
		ret=0;
	}
	return ret;
}
void pokemon_delete(Pokemon* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

void printPokemon(Pokemon* unPokemon)
{
	int numero;
	char nombre[51];
	char tamanio[21];
	char tipo[21];
	char ataqueCargado[21];
	int valorAtaque;
	int esVariocolor;
	if(unPokemon!=NULL)
	{
		pokemon_getNumero(unPokemon, &numero);
		pokemon_getNombre(unPokemon, nombre);
		pokemon_getTipo(unPokemon, tipo);
		pokemon_getTamanio(unPokemon, tamanio);
		pokemon_getAtaqueCargado(unPokemon, ataqueCargado);
		pokemon_getValorAtaque(unPokemon, &valorAtaque);
		pokemon_getEsVariocolor(unPokemon, &esVariocolor);


		printf("%-5d %-20s %-10s %-10s %-10s %-10d %-10d\n",numero,nombre,tipo,tamanio, ataqueCargado, valorAtaque, esVariocolor);
	}

}

void listAllPokemon(LinkedList* pokemon)
{
	Pokemon* unPokemon=NULL;
	int len;

	if(pokemon != NULL)
	{
		len = ll_len(pokemon);

		for(int i=0;i<len;i++)
		{
			unPokemon=ll_get(pokemon, i);


			 	printPokemon(unPokemon);



		}
	}





}

int pokemon_loadFromText(char* path, LinkedList* pArrayListPokemon)
{
	int ret=1;

		if(path!=NULL && pArrayListPokemon!=NULL)
		{

			ret = pokemon_ParserFromText(path, pArrayListPokemon);

		}

	    return ret;
}

int pokemon_ParserFromText(char* path, LinkedList* pArrayListPokemon)
{
	Pokemon* unPokemon;
	int ret=1;
	char numero[21];
	char nombre[21];
	char tipo[21];
	char tamanio[20];
	char ataqueCargado[21];
	char valorAtaque[21];
	char esVariocolor[20];
	int cantidad;
	FILE* pFile= fopen(path,"r");
		if(pFile != NULL && pArrayListPokemon != NULL)
		{
			while(!feof(pFile))
			{
				cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);

				if(cantidad == 7)
				{
				unPokemon =pokemon_newParametros(numero, nombre, tipo,tamanio, ataqueCargado,valorAtaque,esVariocolor);
				ll_add(pArrayListPokemon, unPokemon);
				}
			}
			fclose(pFile);
			pFile=NULL;
			ret=0;
		}
	    return ret;



}

int pokemon_eliminar(LinkedList* pArrayListPokemon)
{
	int numero;
	int index = -1;
	int len;
	int ret;
	int confirm;
	Pokemon* unPokemon;


	   if(pArrayListPokemon!=NULL)
	   {

		   getInt(&numero, "Ingrese el numero del pokemon para eliminar: ", "ERROR, Ingrese el numero del pokemon para eliminar: ",1, 200);
		   len=ll_len(pArrayListPokemon);
		   ret = 1;

		   for(int i=0;i<len;i++)
		   {
				unPokemon=(Pokemon*)ll_get(pArrayListPokemon, i);
				if(unPokemon->numero == numero)
				{
					index = i;
				}

		   }

		   getInt(&confirm, "Estas seguro? (1 = si / 2 = no): ","ERROR, Estas seguro? (1 = si / 2 = no)",1,2);
		   if(index!= -1 && confirm == 1)
		   {
			   ll_remove(pArrayListPokemon, index);
			   unPokemon = NULL;
			   printf("Se elimo el pokemon nº %d\n", numero);
		   }else
		   {
			   printf("No se encontro el pokemon nº %d\n", numero);
		   }
	   }

		return ret;


}

/*
 * -1 error
 * 1 se agrega a la lista
 * 0 no se agrega
 */
int pokemon_FiltrarAguaShiny(void* pElement)
{
	int ret = -1;
	Pokemon* unPokemon;
	unPokemon =(Pokemon*)pElement;


	if(pElement != NULL)
	{

		if(strcmp(unPokemon->tipo, "Water") == 0 && unPokemon->esVariocolor == 1)
		{
			ret = 1;

		}else
		{
			ret = 0;
		}
	}

	return ret;
}

int pokemon_GuardarPokemonesAguaShiny(LinkedList* pArrayListPokemon, char* path)
{
	int ret=1;
		int len;
		Pokemon* unPokemon=NULL;

		FILE* pFile= fopen(path,"w");

		if(path!=NULL && pArrayListPokemon!=NULL)
		{
			len=ll_len(pArrayListPokemon);
			if(pFile!=NULL)
			{
				printf("Pokemones de tipo agua y shiny:\n");
				for(int i=0;i<len;i++)
				{

					unPokemon=(Pokemon*)ll_get(pArrayListPokemon, i);
					fprintf(pFile, "%d,%s,%s,%s,%s,%d,%d\n", unPokemon->numero,unPokemon->nombre,unPokemon->tipo,unPokemon->tamanio,unPokemon->ataqueCargado,unPokemon->valorAtaque,unPokemon->esVariocolor);
					printPokemon(unPokemon);
				}

				fclose(pFile);
				pFile=NULL;
				unPokemon=NULL;
			}
			else
			{
				printf("ERROR, no se pudo crear el archivo\n");
			}

			ret=0;
		}

	    return ret;

}

int pokemon_mapearAtaqueCargado(void* pElement)
{

	int ret = 1;
	int resultado;
	int valorAtaque;
	Pokemon* unPokemon = NULL;

		if(pElement != NULL)
		{
			unPokemon = (Pokemon*) pElement;
			pokemon_getValorAtaque(unPokemon, &valorAtaque);

			if((strcmp(unPokemon->tipo, "Fire")==0) || (strcmp(unPokemon->tipo, "Ground")==0) || (strcmp(unPokemon->tipo, "Grass")==0))
			{
			resultado =  valorAtaque * 1.1;
			pokemon_setValorAtaque(unPokemon, resultado);
			printPokemon(unPokemon);
			ret = 0;
			unPokemon = NULL;
			}
		}
		return ret;


}




