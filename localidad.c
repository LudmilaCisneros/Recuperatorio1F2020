#include <stdio.h>
#include <string.h>
#include "utn.h"
#include "localidad.h"

int hardcodeoLocalidad(sLocalidad listadoLocalidades[], int sizeLocalidad)
{
    int i;

    int idLocalidad[5]={0,1,2};
    char provincia[3][51]= {"Buenos Aires","Santa Fe","La pampa"};
    char localidad[5][51]= {"quilmes","Rosario","Santa Rosa"};
    int isEmpty[3]={1,1,1};
    int idCliente[3]={0,1,2};

    for(i=0; i<sizeLocalidad; i++)
    {
        listadoLocalidades[i].idLocalidad = idLocalidad[i];
        strcpy(listadoLocalidades[i].provincia, provincia[i]);
        strcpy(listadoLocalidades[i].localidad, localidad[i]);
        listadoLocalidades[i].isEmpty = isEmpty[i];
        listadoLocalidades[i].idCliente = idCliente[i];
    }
    return 0;
}
