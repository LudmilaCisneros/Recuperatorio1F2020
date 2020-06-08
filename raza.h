#ifndef RAZA_H_INCLUDED
#define RAZA_H_INCLUDED

 typedef struct{
int idRaza;//(PK)
char nombreRaza[51];
char pais[51];
int isEmpty;

}sRaza;

int hardcodeoRazas(sRaza listadoRazas[], int sizeRazas);

#endif // RAZA_H_INCLUDED
