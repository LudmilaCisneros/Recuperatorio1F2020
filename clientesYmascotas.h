#ifndef CLIENTESYMASCOTAS_H_INCLUDED
#define CLIENTESYMASCOTAS_H_INCLUDED
#include "mascotas.h"
#include "clientes.h"


int mostrarMascotas(sCliente listadoClientes[],sMascota listadoMascota[], int sizeMascota, int sizeCliente);
int mostrarClientesConTodasSusMascotas(sCliente listadoClientes[],sMascota listadoMascotas[], int sizeMascota, int sizeCliente);
int borrarMascotas(sMascota listadoMascotas[], sCliente listadoClientes[], int sizeMascota, int sizeCliente, int index);
int borrarDuenoYsusMascotas(sCliente listadoClientes[], sMascota listadoMascota[], int sizeCliente, int sizeMascota);
int listarClientesMasdeUnaMascota(sCliente listadoClientes[], sMascota listadoMascotas[],int sizeCliente,int sizeMascota);
int listarMascotasMasDe3anos(sCliente listadoClientes[], sMascota listadoMascotas[], int sizeCliente, int sizeMascota);
void swapClientes(sCliente listadoClientes[], int i);
int ordenarDuenosPorCantMascotas(sCliente listadoClientes[], sMascota listadoMascotas[], int sizeCliente, int sizeMascota);
int imprimirClientesOrdenados(sCliente listadoClientes[],sMascota listadoMascotas[],int sizeCliente,int sizeMascota);
//int ordenarDuenosNombre(sCliente listadoClientes[], int sizeCliente);

#endif // CLIENTESYMASCOTAS_H_INCLUDED
