#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "color.h"

void mostrarColor(eColor color)
{
    printf("  %d         %3s\n", color.id, color.nombreColor);
}

int mostrarColores(eColor lista[], int tam)
{
    int retorno = 0;

    if(lista!=NULL && tam>0)
    {
        system("cls");
        printf("    *** COLORES ***\n\n");
        printf("   Id          Color\n");
        printf("-----------------------\n");
        for(int i=0; i<tam; i++)
        {
            mostrarColor(lista[i]);
        }
        printf("-----------------------\n");
        printf("\n");
        retorno = 1;
    }
    return retorno;
}

int validarIdColor(eColor colores[], int tam, int id)
{
    int existe = 0;
    if(colores!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(colores[i].id == id)
            {
                existe = 1;
                break;
            }
        }
    }
    return existe;
}


int cargarDescripcionColor(eColor colores[], int tam, int idColor, char descripcion[])
{
    int retorno = 0;

    if(colores!=NULL && tam>0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(colores[i].id == idColor)
            {
                strcpy(descripcion, colores[i].nombreColor);
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}
