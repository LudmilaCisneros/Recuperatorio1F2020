#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{

int idCliente;//(FK)
char nombre[51];
char apellido[51];
char localidad[51];
long int telefono;
int edad;
char sexo;
int isEmpty;

}sCliente;

int hardcodeoClientes(sCliente listadoClientes[], int sizeCliente);
int initClientes(sCliente listadoClientes[], int sizeCliente);
int mostrarUnCliente(sCliente listadoClientes[],int index);
int mostrarClientes(sCliente listadoClientes[], int sizeCliente);
int buscarLibre(sCliente listadoClientes[], int sizeCliente);
int altaCliente(sCliente listadoClientes[], int sizeCliente);
int modificarCliente(sCliente listadoClientes[], int sizeCliente);
int existenciaDeIDCliente(sCliente listadoClientes[], int sizeCliente,int index);
int sacarPorcentajeMujeres(sCliente listadoClientes[], int sizeCliente);

#endif // CLIENTES_H_INCLUDED
