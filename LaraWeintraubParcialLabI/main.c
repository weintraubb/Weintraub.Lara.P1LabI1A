#include <stdio.h>
#include <stdlib.h>
#include "moto.h"
#include "tipo.h"
#include "trabajo.h"
#include "servicio.h"
#include "color.h"
#include "dataWarehouse.h"

#define TAM 10
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_TR 10

int main()
{
    eTipo tipos[TAM_T] = {{1000, "Enduro"}, {1001, "Chopera"}, {1002, "Scooter"}, {1003, "Vintage"}};
    eColor colores[TAM_C] = {{10000, "Gris"}, {10001, "Negro"}, {10002, "Blanco"}, {10003, "Azul"}, {10004, "Rojo"}};
    eServicio servicios[TAM_S] = {{20000, "Limpieza", 450}, {20001, "Ajuste", 300}, {20002, "Balanceo", 150}, {20003, "Cadena", 390}};
    eMoto motos[TAM];
    eTrabajo trabajos[TAM_TR];

    char seguir = 's';
    char seguirInformes = 's';
    int nextId = 1000;
    int nextIdTrabajo = 5000;
    int flagTrabajo = 1;
    int contadorMotos = 0;

    if(!inicializarMotos(motos, TAM))
    {
        printf("Hubo un problema al inicializar motos\n");
    }

    if(!inicializarTrabajos(trabajos, TAM_TR))
    {
        printf("Hubo un problema al inicializar trabajos\n");
    }

    hardcodearMotos(motos, TAM, 9, &nextId);
    hardcodearTrabajos(trabajos, TAM_TR, 9, &nextIdTrabajo);
    do
    {
        switch(menu())
        {
        case 1:
            altaMoto(motos, TAM, tipos, TAM_T, colores, TAM_C, &nextId);
            contadorMotos++;
            break;
        case 2:
            if(contadorMotos>=1)
            {
                modificarMoto(motos, TAM, tipos, TAM_T, colores, TAM_C);
            }
            else
            {
                printf("\nPrimero debe registrar una moto.\n");
            }
            break;
        case 3:
            if(contadorMotos>=1)
            {
               bajaMoto(motos, TAM, tipos, TAM_T, colores, TAM_C);
               contadorMotos--;
            }
            else
            {
                printf("\nPrimero debe registrar una moto.\n");
            }
            break;
        case 4:
            if(contadorMotos>=1)
            {
                system("cls");
                ordenarMotos(motos, TAM);
                mostrarMotos(motos, TAM, tipos, TAM_T, colores, TAM_C);
            }
            else
            {
                printf("\nPrimero debe registrar una moto.\n");
            }
            break;
        case 5:
            mostrarTipos(tipos, TAM_T);
            break;
        case 6:
            mostrarColores(colores, TAM_C);
            break;
        case 7:
            mostrarServicios(servicios, TAM_S);
            break;
        case 8:
            if(contadorMotos>=1)
            {
                altaTrabajo(trabajos, TAM_TR, motos, TAM, &nextIdTrabajo, tipos, TAM_T, colores, TAM_C, servicios, TAM_S);
                flagTrabajo=1;
            }
            else
            {
                printf("\nPrimero debe registrar una moto.\n");
            }
            break;
        case 9:
            if(flagTrabajo)
            {
                mostrarTrabajos(trabajos, TAM_TR, servicios, TAM_S);
            }
            else
            {
                printf("\nPrimero debe registrar un trabajo\n");
            }
            break;
        case 10:
            if(contadorMotos)
            {
                do
                {
                    switch(menuInformes())
                    {
                    case 1:
                        mostrarMotosColor(motos, TAM, tipos, TAM_T, colores, TAM_C);
                        break;
                    case 2:
                        informarPromedio(motos, TAM, tipos, TAM_T);
                        break;
                    case 3:
                        mayorCilindrada(motos, TAM, tipos, TAM_T, colores, TAM_C);
                        break;
                    case 4:
                        system("cls");
                        ordenarMotosTipo(motos, TAM);
                        mostrarMotos(motos, TAM, tipos, TAM_T, colores, TAM_C);
                        break;
                    case 5:
                        contarMotosColorTipo(motos, TAM, tipos, TAM_T, colores, TAM_C);
                        break;
                    case 6:
                        colorMasElegido(motos, TAM, colores, TAM_C);
                        break;
                    case 7:
                        trabajosMoto(motos, TAM, trabajos, TAM_TR, tipos, TAM_T, colores, TAM_C, servicios, TAM_S);
                        break;
                    case 8:
                        importesMoto(motos, TAM, tipos, TAM_T, colores, TAM_C, trabajos, TAM_TR, servicios, TAM_S);
                        break;
                    case 9:
                        mostrarMotosServicio(motos, TAM, tipos, TAM_T, colores, TAM_C, servicios, TAM_S, trabajos, TAM_T);
                        break;
                    case 10:
                        mostrarServiciosFecha(trabajos, TAM_TR, servicios, TAM_S);
                        break;
                    case 11:
                        seguirInformes = 'n';
                        break;
                    default:
                        printf("\nPor favor ingrese una opcion valida\n");
                        break;
                    }
                    system("pause");
                }while (seguirInformes=='s');
            }
            else
            {
                printf("\nPrimero debe ingresar una moto\n");
            }
            break;
        case 11:
            seguir = 'n';
            break;
        default:
            printf("\nPor favor ingrese una opcion valida\n");
            break;
        }
        system("pause");
    }while(seguir=='s');
    return 0;
}
