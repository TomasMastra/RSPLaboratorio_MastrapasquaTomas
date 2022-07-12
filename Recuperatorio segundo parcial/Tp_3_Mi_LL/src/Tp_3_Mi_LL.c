#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Input.h"
#include "Pokemon.h"
//Mastrapasqua Tomas B


int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int flag = 0;

    LinkedList* listaPokemones = ll_newLinkedList();
    LinkedList* listaPokemonesAguaShiny=NULL;

    do{

    			getInt(&option,  "**************************************\n"
								"MENU\n"
								"**************************************\n"
								"1. Cargar los datos de los pokemones\n"
								"2. Eliminar un pokemon\n"
								"3. Imprimir pokemones\n"
								"4. Filtrar de tipo agua variocolor\n"
								"5. Mapear ataque cargado (aumenta un 10% si es de fuego, tierra o planta)\n"
								"6. Salir\n"
								"**************************************\n"
								"Ingrese una opcion: ",

								"**************************************\n"
								"MENU\n"
								"**************************************\n"
								"1. Cargar los datos de los pokemones\n"
								"2. Eliminar un Pokemon\n"
								"3. Imprimir pokemones\n"
								"4. Filtrar de tipo agua y variocolor\n"
								"5. Mapear ataque cargado (aumenta un 10% si es de fuego, tierra o planta)\n"
								"6. Salir\n"
								"**************************************\n"
								"Opcion invalida, reingrese: ", 1, 6);

        switch(option)
        {
            case 1:
            	if(flag == 0)
            	{
            	pokemon_loadFromText("Data_Pokemones.csv", listaPokemones);
            	flag = 1;
            	}else
            	{
            		printf("Ya cargo los pokemones\n");
            	}
            	break;

            case 2:
            	if(flag == 1)
            	{
            	 pokemon_eliminar(listaPokemones);
            	}else
            	{
            		printf("No cargo los pokemones\n");
            	}
            	break;

            case 3:
            	if(flag == 1)
            	{
            	 listAllPokemon(listaPokemones);
            	}else
            	{
            		printf("No cargo los pokemones\n");
            	}
                break;

            case 4:
            	if(flag == 1)
            	{
            	listaPokemonesAguaShiny = ll_filter(listaPokemones, pokemon_FiltrarAguaShiny);
            	pokemon_GuardarPokemonesAguaShiny(listaPokemonesAguaShiny, "Lista_PokemonesAguaShiny.csv");
            	//controller_ListEmployee(listaPokemonesAguaShiny);
            	}
            	else
            	{
            	    printf("No cargo los pokemones\n");
            	}
            	break;

            case 5:
            	if(flag == 1)
            	{
            	ll_map(listaPokemones, pokemon_mapearAtaqueCargado);
            	}else
            	{
            		printf("No cargo los pokemones\n");
            	}
            	break;
        }
    }while(option != 6);

    return 0;
}

