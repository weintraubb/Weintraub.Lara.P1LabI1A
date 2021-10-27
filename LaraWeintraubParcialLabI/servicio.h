#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;


#endif // SERVICIO_H_INCLUDED
/** \brief muestra un servicio
 *
 * \param servicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief muestra todos los servicios
 *
 * \param lista[] eServicio
 * \param tam int
 * \return int
 *
 */
int mostrarServicios(eServicio lista[], int tam);

/** \brief valida si el id del servicio existe
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarIdServicio(eServicio servicios[], int tam, int id);

/** \brief muestra la descripcion del servicio segun su id
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param idServicio int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tam, int idServicio, char descripcion[]);

float cargarPrecioServicio(eServicio servicios[], int tam, int idServicio);
