#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validarFecha(eFecha fecha)
{
    int retorno = 0;

        if(fecha.dia >=1 && fecha.dia<=31 && (fecha.mes>=1 && fecha.mes<=12) && (fecha.anio>=2010 && fecha.anio<=2021))
        {
            switch(fecha.mes)
            {
            case 2:
                if(fecha.dia<=28)
                {
                    retorno = 1;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(fecha.dia<=30)
                {
                    retorno = 1;
                }
            default:
            retorno = 1;
            break;
            }
        }
    return retorno;
}

