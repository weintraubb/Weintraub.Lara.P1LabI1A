#include "dataWarehouse.h"
#include "moto.h"
#include <string.h>

char marcas[10][20] = {"Culo", "Orto", "Ano", "Culo", "Culo", "Ano", "Ano", "Orto", "Orto", "Culo"};

int idTipos[10] = {1000, 1000, 1003, 1003, 1002, 1000, 1001, 1002, 1001, 1003};

int idColores[10]= {10000, 10004, 10004, 10000, 10002, 10001, 10002, 10001, 10000, 10001};

int cilindradas[10] = {50, 50, 750, 500, 125, 500, 600, 750, 125, 125};

int puntajes[10] = {10, 10, 2, 5, 6, 1, 4, 9, 8, 5};


int hardcodearMotos(eMoto lista[], int tam, int cant, int* pId)
{
    int contador = -1;

    if(lista!=NULL && tam>0 && cant>=0 && cant<=tam && pId!=NULL)
    {
        contador = 0;
        for(int i=0; i<cant; i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            strcpy(lista[i].marca, marcas[i]);
            lista[i].idTipo = idTipos[i];
            lista[i].idColor = idColores[i];
            lista[i].cilindrada = cilindradas[i];
            lista[i].puntaje = puntajes[i];
            lista[i].isEmpty = 0;

            contador++;
        }
    }
    return contador;
}
