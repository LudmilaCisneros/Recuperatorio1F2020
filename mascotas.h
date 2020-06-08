#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

#include "raza.h"

typedef struct{

int idCliente;//(PK)
char nombre[51];
char tipo[51];
int edad;
float peso;
char sexo;
int idMascota;
int idRaza;//FK
int isEmpty;

}sMascota;



int hardcodeoMascotas(sMascota listadoMascotas[], int sizeMascota);
int buscarLibreMascota(sMascota listadoMascotas[], int sizeMascota);
int initMascotas(sMascota listadoMascotas[], int sizeMascota);
int existenciaDeIDMascota(sMascota listadoMascotas[], int sizeMascota,int index);
int mostrarUnaMascota(sMascota listadoMascotas[], int index);
int altaMascota(sMascota listadoMascotas[], int sizeMascota,sRaza listadoRazas[],int sizeRaza);
int bajaMascota(sMascota listadoMascotas[], int sizeMascota);
int modificarMascota(sMascota listadoMascotas[], int sizeMascota);
void swapMascotas(sMascota listadoMascotas[], int i);
int ordenarMascotasPorTipo(sMascota listadoMascotas[],int sizeMascota);
int listarPorCriterio(sMascota listadoMascotas[], int sizeMascota, char* criterio);
int listarMascotasSegunCriterioTipo(sMascota listadoMascotas[], int sizeMascota);
int promedioTodasLasMascotas(sMascota listadoMascotas[], int sizeMascota);
int promedioEdadMascotasTipo(sMascota listadoMascotas[],int sizeMascota);
int cantidadDeMascotas(sMascota listadoMascotas[], int sizeMascota, int idCliente);

void mostrarRazas(sRaza listadoRazas[], int sizeRazas);


#endif // MASCOTAS_H_INCLUDED
