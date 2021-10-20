#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

void mostrarTipo(eTipo tipo)
{
    printf("  %d         %5s\n", tipo.id, tipo.descripcion);
}

int mostrarTipos(eTipo lista[], int tam)
{
    int retorno = 0;

    if(lista!=NULL && tam>0)
    {
        system("cls");
        printf("    *** TIPOS ***\n\n");
        printf("   Id           Tipo\n");
        printf("-----------------------\n");
        for(int i=0; i<tam; i++)
        {
            mostrarTipo(lista[i]);
        }
        printf("-----------------------\n");
        retorno = 1;
    }

    return retorno;
}

int validarIdTipo(eTipo tipos[], int tam, int id)
{
    int existe = 0;
    if(tipos!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id == id)
            {
                existe = 1;
                break;
            }
        }
    }
    return existe;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int idTipo, char descripcion[])
{
    int retorno = 0;

    if(tipos!=NULL && tam>0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id == idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}
