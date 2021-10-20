#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;


#endif // TIPO_H_INCLUDED
/** \brief muestra un tipo de moto
 *
 * \param tipo eTipo listado de tipos
 * \return void
 *
 */
void mostrarTipo(eTipo tipo);

/** \brief muestra todos los tipos de motos
 *
 * \param lista[] eTipo listado de tipos
 * \param tam int tamaño del array lista
 * \return int
 *
 */
int mostrarTipos(eTipo lista[], int tam);

/** \brief informa si el id de un tipo existe
 *
 * \param tipos[] eTipo listado de tipos
 * \param tam int tamaño del array lista
 * \param id int id ingresado
 * \return int
 *
 */
int validarIdTipo(eTipo tipos[], int tam, int id);

/** \brief carga la descripcion del tipo segun su id
 *
 * \param tipos[] eTipo listado de tipos
 * \param tam int tamaño del array lista
 * \param idTipo int id del tipo a cargar
 * \param descripcion[] char se almacena la descripcion
 * \return int
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tam, int idTipo, char descripcion[]);
