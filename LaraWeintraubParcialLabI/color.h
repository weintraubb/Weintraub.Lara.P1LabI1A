#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;


#endif // COLOR_H_INCLUDED
/** \brief muestra un color
 *
 * \param color eColor color a mostrar
 * \return void
 *
 */
void mostrarColor(eColor color);

/** \brief muestra listado de colores
 *
 * \param lista[] eColor listado de colores
 * \param tam int tamaño del array lista
 * \return int
 *
 */
int mostrarColores(eColor lista[], int tam);

/** \brief valida si el id del color existe
 *
 * \param colores[] eColor listado de colores
 * \param tam int tamaño del array colores
 * \param id int id a validar
 * \return int
 *
 */
int validarIdColor(eColor colores[], int tam, int id);

/** \brief carga la descripcion de un color
 *
 * \param colores[] eColor listado de colores
 * \param tam int tamaño del array colores
 * \param idColor int id del color a cargar
 * \param descripcion[] char se almacena la descripcion
 * \return int
 *
 */
int cargarDescripcionColor(eColor colores[], int tam, int idColor, char descripcion[]);
