#include <stdio.h>
#include <string.h>
#include "utn.h"
#include "raza.h"

int hardcodeoRazas(sRaza listadoRazas[], int sizeRazas)
{
    int i;

    int idRaza[5]={0,1,2,3,4};
    char paisRazas[5][25]= {"Argentina","Tailandesa","Irlandes","Senegales","Frances"};
    char nombreRazas[5][25]= {"pastor Aleman","Frances","siames","persa","Frances"};
    int isEmpty[5]={1,1,1,1,1};

    for(i=0; i<QTY_RAZAS; i++)
    {
        strcpy(listadoRazas[i].nombreRaza, nombreRazas[i]);
        strcpy(listadoRazas[i].pais, paisRazas[i]);
        listadoRazas[i].isEmpty = isEmpty[i];
        listadoRazas[i].idRaza = idRaza[i];
    }
    return 0;
}
