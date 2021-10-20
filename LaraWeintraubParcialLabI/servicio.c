#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicio.h"

void mostrarServicio(eServicio servicio)
{
    printf("  %d       %8s        $%.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

int mostrarServicios(eServicio lista[], int tam)
{
    int retorno = 0;

    if(lista!=NULL && tam>0)
    {
        system("cls");
        printf("          *** SERVICIOS ***\n\n");
        printf("   Id         Servicio         Precio\n");
        printf("-----------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            mostrarServicio(lista[i]);
        }
        printf("-----------------------------------------\n");
        printf("\n");
        retorno = 1;
    }
    return retorno;
}

int validarIdServicio(eServicio servicios[], int tam, int id)
{
    int existe = 0;
    if(servicios!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id == id)
            {
                existe = 1;
                break;
            }
        }
    }
    return existe;
}

int cargarDescripcionServicio(eServicio servicios[], int tam, int idServicio, char descripcion[])
{
    int retorno = 0;

    if(servicios!=NULL && tam>0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id == idServicio)
            {
                strcpy(descripcion, servicios[i].descripcion);
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}
