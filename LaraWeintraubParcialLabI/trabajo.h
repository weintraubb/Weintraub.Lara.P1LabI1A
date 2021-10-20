#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicio.h"

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED
/** \brief inicializa isEmpty en 1
 *
 * \param lista[] eTrabajo listado de trabajos
 * \param tam int tamaño del array lista
 * \return int
 *
 */
int inicializarTrabajos(eTrabajo lista[], int tam);

/** \brief busca espacio libre en el sistema
 *
 * \param lista[] eTrabajo listado de trabajos
 * \param tam int tamaño del array lista
 * \return int
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam);

/** \brief permite registrar un trabajo
 *
 * \param lista[] eTrabajo listado de trabajos
 * \param tam int tamaño del array lista
 * \param motos[] eMoto listado de motos
 * \param tamMoto int tamaño del array motos
 * \param pId int* id del trabajo
 * \param tipos[] eTipo listado de tipos
 * \param tamTipos int tamaño del array tipos
 * \param colores[] eColor listado de colores
 * \param tamColores int tamaño del array colores
 * \param servicios[] eServicio listado de servicios
 * \param tamServicios int tamaño del array servicios
 * \return int
 *
 */
int altaTrabajo(eTrabajo lista[], int tam, eMoto motos[], int tamMoto, int* pId, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, eServicio servicios[], int tamServicios);

/** \brief muestra un trabajo
 *
 * \param trabajo eTrabajo trabajo a mostrar
 * \param servicios[] eServicio listado de servicios
 * \param tamServicios int tamaño del array servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServicios);

/** \brief muestra todos los trabajos
 *
 * \param lista[] eTrabajo listado de trabajos
 * \param tam int tamaño del array lista
 * \param servicios[] eServicio listado de servicios
 * \param tamServicios int tamaño del array servicios
 * \return int
 *
 */
int mostrarTrabajos(eTrabajo lista[], int tam, eServicio servicios[], int tamServicios);
