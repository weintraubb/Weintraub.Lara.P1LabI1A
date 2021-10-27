#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
#include "tipo.h"
#include "color.h"

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int puntaje;
    int isEmpty;
}eMoto;

#endif // MOTO_H_INCLUDED
/** \brief menu de opciones
 *
 * \return int
 *
 */
int menu();

/** \brief inicializa isEmpty en 1
 *
 * \param lista[] eMoto listado de motos
 * \param tam int tañano del array lista
 * \return int
 *
 */
int inicializarMotos(eMoto lista[], int tam);

/** \brief busca espacio libre en el sistema
 *
 * \param lista[] eMoto listado de motos
 * \param tam int tamaño del array lista
 * \return int
 *
 */
int buscarLibreMoto(eMoto lista[], int tam);

/** \brief dar de alta una moto
 *
 * \param lista[] eMoto listado de motos
 * \param tam int tamaño del listado de motos
 * \param tipos[] eTipo listado de tipos
 * \param tamTipos int tamaño del listado de tipos
 * \param colores[] eColor listado de colores
 * \param tamColores int tamaño del listado de colores
 * \param pId int* id de la moto
 * \return int
 *
 */
int altaMoto(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, int* pId);

/** \brief busca una moto por id
 *
 * \param lista[] eMoto listado de motos
 * \param tam int tamaño del array lista
 * \param id int id ingresado
 * \return int
 *
 */
int buscarMotoId(eMoto lista[], int tam, int id);

/** \brief muestra una moto
 *
 * \param unaMoto eMoto moto a mostrar
 * \param tipos[] eTipo listado de tipos
 * \param tamTipos int tamaño del array tipos
 * \param colores[] eColor listado de colores
 * \param tamColores int tamaño del array colores
 * \return void
 *
 */
void mostrarMoto(eMoto unaMoto, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

/** \brief ordena las motos por tipo y id
 *
 * \param lista[] eMoto listado de motos
 * \param tam int tamaño del array lista
 * \return int
 *
 */
int ordenarMotos(eMoto lista[], int tam);

/** \brief muestra todas las motos
 *
 * \param lista[] eMoto listado de motos
 * \param tam int tamaño del array lista
 * \param tipos[] eTipo listado de tipos
 * \param tamTipos int tamaño del array tipos
 * \param colores[] eColor listado de colores
 * \param tamColores int tamaño del array colores
 * \return int
 *
 */
int mostrarMotos(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

/** \brief permite modificar una moto
 *
 * \param lista[] eMoto listado de motos
 * \param tam int tamaño del array lista
 * \param tipos[] eTipo listado de tipos
 * \param tamTipos int tamaño del array tipos
 * \param colores[] eColor listado de colores
 * \param tamColores int tamaño del array colores
 * \return int
 *
 */
int modificarMoto(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

/** \brief menu de modificacion
 *
 * \return int
 *
 */
int menuModificacion();

/** \brief cambia isEmpty a 1
 *
 * \param lista[] eMoto listado de motos
 * \param tam int tamaño del array lista
 * \param tipos[] eTipo listado de tipos
 * \param tamTipos int tamaño del array tipos
 * \param colores[] eColor listado de colores
 * \param tamColores int tamaño del arrray colores
 * \return int
 *
 */
int bajaMoto(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

int menuInformes();

int mostrarMotosColor(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

int informarPromedio(eMoto lista[], int tam, eTipo tipos[], int tamTipos);

int mayorCilindrada(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

int mostrarMotosUnTipo(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);

int ordenarMotosTipo(eMoto lista[], int tam);

int colorMasElegido(eMoto lista[], int tam, eColor colores[], int tamColores);

int contarMotosColorTipo(eMoto lista[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);
