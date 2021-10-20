#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "servicio.h"
#include "moto.h"
#include "trabajo.h"
#include "validaciones.h"

int inicializarTrabajos(eTrabajo lista[], int tam)
{
    int retorno = 0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int buscarLibreTrabajo(eTrabajo lista[], int tam)
{
    int indice = -1;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaTrabajo(eTrabajo lista[], int tam, eMoto motos[], int tamMoto, int* pId, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, eServicio servicios[], int tamServicios)
{
    int retorno = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(lista!=NULL && motos!=NULL && pId!=NULL && tam>0 && tamMoto>0)
    {
        system("cls");
        printf("      *** Alta Trabajo ***\n\n");
        indice = buscarLibreTrabajo(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxTrabajo.id = *pId;
            (*pId)++;
            mostrarMotos(motos, tamMoto, tipos, tamTipos, colores, tamColores);

            auxTrabajo.idMoto = getValidInt("Ingrese id de la moto: ", "ID INVALIDO - ");
            indice = buscarMotoId(motos, tamMoto, auxTrabajo.idMoto);
            while(indice == -1)
            {
                auxTrabajo.idMoto = getValidInt("ID INVALIDO - Ingrese id de la moto: ", "");
                indice = buscarMotoId(motos, tamMoto, auxTrabajo.idMoto);
            }
            mostrarServicios(servicios, tamServicios);
            auxTrabajo.idServicio = getValidInt("Ingrese id del servicio: ", "ID INVALIDO - ");
            while(!validarIdServicio(servicios, tamServicios, auxTrabajo.idServicio))
            {
                auxTrabajo.idServicio = getValidInt("ID INVALIDO - Ingrese id del servicio: ", "");
            }

            system("cls");
            printf("FECHA: \n");
            auxTrabajo.fecha.dia = getValidInt("Ingrese el dia: ", "DIA INVALIDO - ");
            auxTrabajo.fecha.mes = getValidInt("Ingrese el mes: ", "MES INVALIDO - ");
            auxTrabajo.fecha.anio = getValidInt("Ingrese el anio: ", "ANIO INVALIDO - ");

            while(!validarFecha(auxTrabajo.fecha))
            {
                system("cls");
                printf("FECHA INVALIDA - Ingrese nuevamente: \n");
                auxTrabajo.fecha.dia = getValidInt("Ingrese el dia: ", "DIA INVALIDO - ");
                auxTrabajo.fecha.mes = getValidInt("Ingrese el mes: ", "MES INVALIDO - ");
                auxTrabajo.fecha.anio = getValidInt("Ingrese el anio: ", "ANIO INVALIDO - ");
            }
            auxTrabajo.isEmpty = 0;

            lista[indice] = auxTrabajo;
            retorno = 1;
        }
    }
    return retorno;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServicios)
{
    char descServicio[20];
    cargarDescripcionServicio(servicios, tamServicios, trabajo.idServicio, descServicio);
    printf("  %d         %d           %6s       %d/%d/%d\n", trabajo.id, trabajo.idMoto, descServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}

int mostrarTrabajos(eTrabajo lista[], int tam, eServicio servicios[], int tamServicios)
{
    int retorno = 0;

    if(lista!=NULL && tam>0)
    {
        system("cls");
        printf("                *** Listado de trabajos ***\n\n");
        printf("   Id         Id Moto         Servicio         Fecha\n");
        printf("-------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarTrabajo(lista[i], servicios, tamServicios);
            }
        }
        printf("-------------------------------------------------------------\n");
        retorno = 1;
    }
    return retorno;
}
