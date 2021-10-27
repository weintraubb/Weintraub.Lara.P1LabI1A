#include "moto.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int menu()
{
    int opcion;
    system("cls");
    printf("    *** MENU DE OPCIONES ***\n\n");
    printf("    1. Alta moto\n");
    printf("    2. Modificar moto\n");
    printf("    3. Baja moto\n");
    printf("    4. Listar motos\n");
    printf("    5. Listar tipos\n");
    printf("    6. Listar colores\n");
    printf("    7. Listar servicios\n");
    printf("    8. Alta trabajo\n");
    printf("    9. Listar trabajos\n");
    printf("    10. MENU DE INFORMES\n");
    printf("    11. SALIR\n\n");
    opcion = getValidInt("    Seleccione una opcion: ", "OPCION INVALIDA\n ");

    return opcion;
}

int inicializarMotos(eMoto lista[], int tam)
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

int buscarLibreMoto(eMoto lista[], int tam)
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

int altaMoto(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, int* pId)
{
    int retorno = 0;
    eMoto auxMoto;
    int indice = -1;

    if(lista!=NULL && tam>0 && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0 && pId!=NULL)
    {
        system("cls");
        printf("   *** ALTA MOTO ***\n\n");
        indice = buscarLibreMoto(lista, tam);
        if(indice == -1)
        {
            printf("No hay espacio en el sistema\n");
        }
        else
        {
            auxMoto.id = *pId;
            (*pId)++;
            mostrarTipos(tipos, tamTipos);
            printf("\n");
            auxMoto.idTipo = getValidInt("Ingrese id del tipo: ", "ID INVALIDO - ");
            while(!validarIdTipo(tipos, tamTipos, auxMoto.idTipo))
            {
                auxMoto.idTipo = getValidInt("ID INVALIDO - Ingrese id del tipo: ", "");
            }

            printf("\n");
            getString("Ingrese marca: ", "MARCA INVALIDA - ", auxMoto.marca, 20);

            printf("\n");
            auxMoto.cilindrada = getValidInt("Ingrese cilindrada (50/125/500/600/750): ", "CILINDRADA INVALIDA - ");
            while(auxMoto.cilindrada != 50 && auxMoto.cilindrada != 125 && auxMoto.cilindrada != 500 && auxMoto.cilindrada != 600 && auxMoto.cilindrada != 750)
            {
                auxMoto.cilindrada = getValidInt("CILINDRADA INVALIDA - Ingrese cilindrada (50/125/500/600/750): ", "");
            }

            mostrarColores(colores, tamColores);
            printf("\n");
            auxMoto.idColor = getValidInt("Ingrese id del color: ", "ID INVALIDO - ");
            while(!validarIdColor(colores, tamColores, auxMoto.idColor))
            {
                auxMoto.idColor = getValidInt("ID INVALIDO - Ingrese id del color: ", "");
            }

            auxMoto.puntaje = getValidInt("Ingrese puntaje (1-10): ", "PUNTAJE INVALIDO - ");
            while(auxMoto.puntaje <1 || auxMoto.puntaje >10)
            {
                auxMoto.puntaje = getValidInt("PUNTAJE INVALIDO - Ingrese puntaje (1-10): ", "");
            }

            auxMoto.isEmpty = 0;

            lista[indice] = auxMoto;
            retorno = 1;
        }
    }
    return retorno;
}

int buscarMotoId(eMoto lista[], int tam, int id)
{
    int indice = -1;
    if(lista!=NULL && tam>0)
    {
        for (int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].id==id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void mostrarMoto(eMoto unaMoto, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    char descTipo[20];
    char descColor[20];
    cargarDescripcionTipo(tipos, tamTipos, unaMoto.idTipo, descTipo);
    cargarDescripcionColor(colores, tamColores, unaMoto.idColor, descColor);
    printf(" %d    %9s      %9s        %6s          %d           %d\n", unaMoto.id, unaMoto.marca, descTipo, descColor, unaMoto.cilindrada, unaMoto.puntaje);
}

int ordenarMotos(eMoto lista[], int tam)
{
    int retorno = 0;
    eMoto auxMoto;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((lista[i].idTipo == lista[j].idTipo && lista[i].id > lista[j].id) || (lista[i].idTipo!=lista[j].idTipo && lista[i].idTipo>lista[j].idTipo))
                {
                    auxMoto = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMoto;
                }
            }
        }
        retorno = 1;
    }
    return retorno;
}

int mostrarMotos(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int retorno = 0;
    int flag = 1;
    if(lista!=NULL && tipos!=NULL && colores!=NULL && tam>0 && tamTipos>0 && tamColores>0)
    {
        printf("                      *** Listado de Motos ***\n\n");
        printf("  Id        Marca           Tipo          Color      Cilindrada     Puntaje\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarMoto(lista[i], tipos, tamTipos, colores, tamColores);
                flag=0;
            }
        }
        printf("--------------------------------------------------------------------------------\n");
        retorno = 1;
        if(flag)
        {
            printf("No hay motos para mostrar\n");
        }
    }
    return retorno;
}

int menuModificacion()
{
    int opcion;

    printf("1. Modificar color\n");
    printf("2. Modificar puntaje\n");
    printf("3. Salir\n\n");
    opcion = getInt("Ingrese opcion: ", 1, 3);

    return opcion;
}

int modificarMoto(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int retorno = 0;
    int indice;
    int id;
    int flag = 0;
    char confirma;
    int auxColor;
    float auxPuntaje;

    if(lista!=NULL && tipos!=NULL && tam>0 && tamTipos>0)
    {
        system("cls");
        printf("                            MODIFICACION\n\n");
        mostrarMotos(lista, tam, tipos, tamTipos, colores, tamColores);
        printf("\n");
        id = getValidInt("Ingrese id de la moto a modificar: ", "ID INVALIDO - ");
        indice = buscarMotoId(lista, tam, id);
        while(indice == -1)
        {
            id = getValidInt("ID INVALIDO - Ingrese id de la moto a modificar: ", "");
            indice = buscarMotoId(lista, tam, id);
        }

        printf("Confirma modificacion? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
        while(confirma!='s' && confirma!='n')
        {
            printf("\nRESPUESTA INVALIDA - Confirma modificacion? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
        }

        while(confirma=='s')
        {
            system("cls");
            printf("                       MODIFICACION\n\n");
            mostrarMotos(lista, tam, tipos, tamTipos, colores, tamColores);
            printf("\n\n");
            switch(menuModificacion())
            {
            case 1:
            mostrarColores(colores, tamColores);
            auxColor = getValidInt("Ingrese id del nuevo color: ", "ID INVALIDO - ");
            while(!validarIdColor(colores, tamColores, auxColor))
            {
                auxColor = getValidInt("ID INVALIDO - Ingrese id del nuevo color: ", "");
            }
            lista[indice].idColor = auxColor;
            flag = 1;
            break;
        case 2:
            auxPuntaje = getValidInt("Ingrese nuevo puntaje (1-10): ", "PUNTAJE INVALIDO - ");
            while(auxPuntaje <1 || auxPuntaje >10)
            {
                auxPuntaje = getValidInt("PUNTAJE INVALIDO - Ingrese nuevo puntaje (1-10): ", "");
            }
            lista[indice].puntaje = auxPuntaje;
            flag = 1;
            break;
        case 3:
            if(flag)
            {
                printf("\nModificacion exitosa.\n");
            }
            confirma = 'n';
            break;
        default:
            printf("\nOpcion invalida.");
            break;
            }
        }
        if(confirma=='n' && !flag)
        {
            printf("\nSe ha cancelado la modificacion\n");
        }
        retorno = 1;
    }
    return retorno;
}

int bajaMoto(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int retorno = 0;
    int id;
    int indice;
    char confirma;
    if(lista!=NULL && tipos!=NULL && colores!=NULL && tam>0 && tamTipos>0 && tamColores>0)
    {
        system("cls");
        printf("                      *** BAJA ***\n\n");
        mostrarMotos(lista, tam, tipos, tamTipos, colores, tamColores);
        id = getValidInt("Ingrese id de la moto a dar de baja: ", "ID INVALIDO - ");
        indice = buscarMotoId(lista, tam, id);
        while(indice == -1)
        {
            id = getValidInt("ID INVALIDO - Ingrese id de la bicicleta a dar de baja: ", "");
            indice = buscarMotoId(lista, tam, id);
        }

        printf("\nDesea dar de baja? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
        while(confirma!='s' && confirma!='n')
        {
            printf("\nRESPUESTA INVALIDA - Desea dar de baja? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
        }

        if(confirma=='s')
        {
            lista[indice].isEmpty = 1;
            printf("\nBaja exitosa!\n\n");
            retorno = 1;
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }
    return retorno;
}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("    MENU DE INFORMES\n\n");
    printf("    1. Mostrar motos del color seleccionado\n");
    printf("    2. Mostrar el promedio de puntaje de un tipo seleccionado\n");
    printf("    3. Informar las motos de mayor cilindrada\n");
    printf("    4. Mostrar un listado de motos separadas por tipo\n");
    printf("    5. Contar cuantas motos hay de un color y un tipo\n");
    printf("    6. Mostrar el/los color/es mas elegido/s por los clientes\n");
    printf("    7. Mostrar todos los trabajos que se le hicieron a una moto\n");
    printf("    8. Mostrar la suma de los importes que se le hicieron a una moto\n");
    printf("    9. Mostrar motos que se realizaron un servicio elegido\n");
    printf("    10. Mostrar todos los servicios realizados en una fecha\n");
    printf("    11. SALIR\n\n");
    opcion = getValidInt("Ingrese una opcion: ", "OPCION INVALIDA - ");
    return opcion;
}

int mostrarMotosColor(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int retorno = 0;
    int flag = 1;
    int idColor;
    char color[20];
    mostrarColores(colores, tamColores);
    idColor = getValidInt("Ingrese el id del color a mostrar: ", "ID INVALIDO - ");
    while(!validarIdColor(colores, tamColores, idColor))
    {
        idColor = getValidInt("ID INVALIDO - Ingrese el id del color a mostrar: ", "");
    }
    cargarDescripcionColor(colores, tamColores, idColor, color);
    if(lista!=NULL && tipos!=NULL && colores!=NULL && tam>0 && tamTipos>0 && tamColores>0)
    {
        system("cls");
        printf("                         *** Motos de Color %s ***\n\n", color);
        printf("  Id        Marca           Tipo          Color      Cilindrada     Puntaje\n");
        printf("---------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].idColor==idColor)
            {
                mostrarMoto(lista[i], tipos, tamTipos, colores, tamColores);
                flag=0;
            }
        }
        printf("---------------------------------------------------------------------------\n");
        retorno = 1;
        if(flag)
        {
            printf("No hay motos para mostrar\n");
        }
    }
    return retorno;
}

int informarPromedio(eMoto lista[], int tam, eTipo tipos[], int tamTipos)
{
    int retorno = 0;
    int idTipo;
    char descTipo[20];
    int contador = 0;
    int acumulador = 0;
    float promedio;

    if(lista!=NULL && tipos!=NULL && tam>0 && tamTipos>0)
    {
        mostrarTipos(tipos, tamTipos);
        idTipo = getValidInt("Ingrese id de un tipo: ", "ID INVALIDO - ");
        while(!validarIdTipo(tipos, tamTipos, idTipo))
        {
           idTipo = getValidInt("ID INVALIDO - Ingrese id de un tipo: ", "");
        }
        cargarDescripcionTipo(tipos, tamTipos, idTipo, descTipo);
        for(int i=0; i<tam; i++)
        {
            if(lista[i].idTipo==idTipo)
            {
                acumulador+=lista[i].puntaje;
                contador++;
            }
        }
        promedio = (float)acumulador/contador;
        printf("\n El promedio de puntaje de las motos de tipo %s es: %.2f\n\n", descTipo, promedio);
        retorno = 1;
    }
    return retorno;
}

int mayorCilindrada(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int retorno = 0;
    int mayorCilindrada;
    int flag=0;
    if(lista!=NULL && tam>0)
    {
        system("cls");
        printf("Mayor Cilindrada:  \n\n");
        for(int i=0; i<tam; i++)
        {
            if((!lista[i].isEmpty && lista[i].cilindrada>mayorCilindrada) || (!flag))
            {
                mayorCilindrada = lista[i].cilindrada;
                flag = 1;
            }
        }
        printf("  Id        Marca           Tipo          Color      Cilindrada     Puntaje\n");
        printf("---------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].cilindrada == mayorCilindrada)
            {
                mostrarMoto(lista[i], tipos, tamTipos, colores, tamColores);
            }
        }
        printf("---------------------------------------------------------------------------\n");

    }
    return retorno;
}

int ordenarMotosTipo(eMoto lista[], int tam)
{
    int retorno = 0;
    eMoto aux;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
               if(lista[i].idTipo > lista[j].idTipo)
               {
                   aux = lista[i];
                   lista[i] = lista[j];
                   lista[j] = aux;
               }
            }
        }
        retorno = 1;
    }
    return retorno;
}

int colorMasElegido(eMoto lista[], int tam, eColor colores[], int tamColores)
{
    int retorno = 0;
    int contador[4] = {0};
    int colorMayor;
    if(lista!=NULL && colores !=NULL && tam>0 && tamColores>0)
    {
        system("cls");
        printf("\nCOLOR/ES MAS ELEGIDO/S:\n\n");
        for(int i=0; i<tamColores; i++)
        {
            for(int j=0; j<tam; j++)
            {
                if(lista[j].idColor == colores[i].id)
                {
                    contador[i]++;
                }
            }
        }
        for(int i=0; i<tamColores; i++)
        {
            if(i==0 || colorMayor<contador[i])
            {
                colorMayor= contador[i];
            }
        }
        for(int i=0; i<tamColores; i++)
        {
            if(contador[i] == colorMayor)
            {
                printf("- %s\n", colores[i].nombreColor);
            }
        }
        printf("\n");
    }

    return retorno;
}

int contarMotosColorTipo(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int retorno = 0;
    int idColor;
    int idTipo;
    int contador = 0;
    char color[20];
    char tipo[20];
    if(lista!=NULL && tipos!=NULL && colores!=NULL && tam>0 && tamColores>0 && tamTipos>0)
    {
        mostrarColores(colores, tamColores);
        idColor = getValidInt("Ingrese id del color: ", "ID INVALIDO - ");
        while(!validarIdColor(colores, tamColores, idColor))
        {
           idColor = getValidInt("ID INVALIDO - Ingrese id del color: ", "");
        }
        mostrarTipos(tipos, tamTipos);
        idTipo = getValidInt("Ingrese id del tipo: ", "ID INVALIDO - ");
        while(!validarIdTipo(tipos, tamTipos, idTipo))
        {
            idTipo = getValidInt("ID INVALIDO - Ingrese id del tipo: ", "");
        }

        for(int i=0; i<tam; i++)
        {
            if(lista[i].idTipo == idTipo && lista[i].idColor == idColor)
            {
                contador++;
            }
        }
        cargarDescripcionColor(colores, tamColores, idColor, color);
        strlwr(color);
        cargarDescripcionTipo(tipos, tamTipos, idTipo, tipo);
        if(idTipo!=1003)
        {
          strlwr(tipo);
        }
        system("cls");
        printf("\nHay %d moto/s de color %s y tipo %s.\n\n", contador, color, tipo);

        retorno = 1;
    }

    return retorno;
}
