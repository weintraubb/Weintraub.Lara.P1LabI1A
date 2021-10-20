#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief valida que sea un numero
 *
 * \param mensaje[] char mensaje para ingresar
 * \param error[] char mensaje de error
 * \return int
 *
 */
int getValidInt(char mensaje[], char error[]);

/** \brief valida que sea flotante
 *
 * \param mensaje[] char mensaje para ingresar
 * \param error[] char mensaje de error
 * \return float
 *
 */
float getValidFloat(char mensaje[], char error[]);

/** \brief permite pedir un entero
 *
 * \param mensaje[] char mensaje para ingresar
 * \param min int minimo
 * \param max int maximo
 * \return int
 *
 */
int getInt(char mensaje[],int min,int max);

/** \brief permite pedir un flotante
 *
 * \param mensaje[] char mensaje para pedir
 * \param min int minimo
 * \param max int maximo
 * \return float
 *
 */
float getFloat(char mensaje[],int min,int max);

/** \brief permite pedir string
 *
 * \param
 * \param
 * \return
 *
 */
void getString (char mensaje [], char error[], char cadena[],int tam);

/** \brief corrige string
 *
 * \param cadena[] char
 * \return void
 *
 */
void corregirString(char cadena[]);

