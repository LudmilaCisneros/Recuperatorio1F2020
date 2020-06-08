#ifndef RAZA_H_INCLUDED
#define RAZA_H_INCLUDED

 typedef struct{
int idLocalidad;//(PK)
char provincia[51];
int codigoPostal;
char descripcion[51];
int idCliente;//FK
int isEmpty;

}sLocalidad;

int hardcodeoLocalidad(sLocalidad listadoLocalidades[], int sizeLocalidad);

#endif // RAZA_H_INCLUDED
