#ifndef pokemon_H_INCLUDED
#define pokemon_H_INCLUDED
#include "LinkedList.h"
typedef struct
{

    int numero;
    char nombre[51];
    char ataqueCargado[51];
    char tamanio[10];
    char tipo[51];
    int valorAtaque;
    int esVariocolor;
}Pokemon;



Pokemon* pokemon_new();


Pokemon* pokemon_newParametros(char* numeroStr,char* nombreStr,char* tipoStr, char* tamanioStr, char* AtaqueCargadoStr, char* valorAtaqueStr, char* esVariocolorStr);


void pokemon_delete(Pokemon* this);




int pokemon_setNombre(Pokemon* this,char* nombre);


int pokemon_getNombre(Pokemon* this,char* nombre);




int pokemon_getValorAtaque(Pokemon* this, int* valorAtaque);
int pokemon_setValorAtaque(Pokemon* this, int valorAtaque);

int pokemon_getNumero(Pokemon* this, int* numero);
int pokemon_setNumero(Pokemon* this, int numero);

int pokemon_getEsVariocolor(Pokemon* this, int* esVariocolor);
int pokemon_setEsVariocolor(Pokemon* this, int esVariocolor);

int pokemon_getAtaqueCargado(Pokemon* this, char* ataqueCargado);
int pokemon_setAtaqueCargado(Pokemon* this, char* ataqueCargado);

int pokemon_getTamanio(Pokemon* this, char* tamanio);
int pokemon_setTamanio(Pokemon* this, char* tamanio);

int pokemon_getTipo(Pokemon* this, char* tipo);
int pokemon_setTipo(Pokemon* this, char* tipo);


void printPokemon(Pokemon* pokemon);
void listAllPokemon(LinkedList* pokemon);

int pokemon_loadFromText(char* path, LinkedList* pArrayListEmployee);
int pokemon_ParserFromText(char* path, LinkedList* pArrayListPokemon);

int pokemon_eliminar(LinkedList* pArrayListPokemon);
int pokemon_FiltrarAguaShiny(void* pElement);
int pokemon_GuardarPokemonesAguaShiny(LinkedList* listaPokemones, char* path);

int pokemon_mapearAtaqueCargado(void* pElement);

#endif // pokemon_H_INCLUDED
