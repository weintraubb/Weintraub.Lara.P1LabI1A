#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
  int dia;
  int mes;
  int anio;
}eFecha;

#endif // FECHA_H_INCLUDED
/** \brief valida que la fecha sea valida
 *
 * \param fecha eFecha fecha ingresada
 * \return int retorna si es valido (1)
 *
 */
int validarFecha(eFecha fecha);
