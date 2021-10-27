#include "dataWarehouse.h"
#include "moto.h"
#include "trabajo.h"
#include <string.h>

char marcas[10][20] = {"Suzuki", "Zanella", "Suzuki", "Zanella", "Vespa", "Yamaha", "Suzuki", "Vespa", "Yamaha", "Suzuki"};

int idTipos[10] = {1000, 1000, 1003, 1003, 1002, 1000, 1001, 1002, 1001, 1003};

int idColores[10]= {10000, 10004, 10004, 10000, 10002, 10001, 10002, 10001, 10000, 10001};

int cilindradas[10] = {50, 50, 750, 500, 125, 500, 600, 750, 125, 125};

int puntajes[10] = {10, 10, 2, 5, 6, 1, 4, 9, 8, 5};



int idServicios[10] = {20000, 20000, 20003, 20003, 20001, 20001, 20003, 20003, 20001, 20001};

int dias[10] = {11, 4, 8, 28, 13, 18, 20, 21, 10, 5};

int meses[10] = {1, 5, 10, 12, 11, 6, 2, 1, 10, 9};

int anios[10] = {2020, 2020, 2021, 2021, 2019, 2021, 2020, 2020, 2021, 2019};

int idMoto[10] = {1000, 1001, 1000, 1002, 1003, 1008, 1005, 1004, 1006, 1000};


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

int hardcodearTrabajos(eTrabajo lista[], int tam, int cant, int* pId)
{
    int contador = -1;


    if(lista!=NULL && tam>0 && cant>=0 && cant<=tam && pId!=NULL)
    {
        contador = 0;
        for(int i=0; i<cant; i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            lista[i].idMoto = idMoto[i];
            lista[i].idServicio = idServicios[i];
            lista[i].fecha.dia = dias[i];
            lista[i].fecha.mes = meses[i];
            lista[i].fecha.anio = anios[i];
            lista[i].isEmpty = 0;

            contador++;
        }
    }
    return contador;
}
