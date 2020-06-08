#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientesYmascotas.h"
#include "utn.h"

/*2-Tenemos un listado de mascotas(hasta 20 mascotas)(nombre,tipo{gato,perro,raro},raza,edad,peso,sexo) ( en el listado por pantalla debería aparecer el
nombre del dueño)*/
/** \brief Muestra las mascotas con sus dueños
 * \param listadoClientes[]
 * \param listadoMascotas[]
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */
int mostrarMascotas(sCliente listadoClientes[],sMascota listadoMascotas[], int sizeMascota, int sizeCliente)
{
    int ret = -1;
    int i;//clientes
    int j;//mascotas

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        for(j=0; j<sizeMascota; j++)
        {
            if(j==0)
            {
                printf("\n%9s  | %9s  | %9s      | %9s       | %5s  | %5s   | %5s  |  %5s  |  %5s\n","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO","ID MASCOTA","DUENO");
            }
            if(listadoMascotas[j].isEmpty == 1)
            {
                mostrarUnaMascota(listadoMascotas,j);

                for(i=0; i<sizeCliente; i++)
                {
                    if(listadoClientes[i].isEmpty == 1 && listadoClientes[i].idCliente == listadoMascotas[j].idCliente)
                    {
                        printf(" %5s \n",listadoClientes[i].nombre);
                    }

                }
            }

        }

        ret = 0;
    }
    return ret;
}

//3-Tenemos un listado de clientes con mascota , que muestra a los clientes con su listado de mascotas
/** \brief Muestra toda la informacion de los clientes, y el nombre de la mascota que poseen
 * \param listadoClientes
 * \param listadoMascotas
 * \param sizeMascota
 * \param sizeCliente
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */
int mostrarClientesConTodasSusMascotas(sCliente listadoClientes[],sMascota listadoMascotas[], int sizeMascota, int sizeCliente)
{
    int ret = -1;
    int i;
    int j;

    if(listadoClientes != NULL && listadoMascotas != NULL && sizeCliente >= 0 && sizeMascota >= 0)
    {
        for(j=0; j<sizeCliente; j++)
        {
            if(j==0)
            {
                printf("\n%8s | %10s  | %10s  | %15s    | %10s    | %5s  | %8s  |  %8s\n","IDCLIENTE","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO","MASCOTA");
            }
            if(listadoClientes[j].isEmpty == 1)
            {

                mostrarUnCliente(listadoClientes,j);
            }

            for(i=0; i<sizeMascota; i++)
            {
                if(listadoMascotas[i].isEmpty == 1 && listadoClientes[j ].isEmpty == 1 && listadoMascotas[i].idCliente == listadoClientes[j].idCliente)
                {
                    printf("%5s /",listadoMascotas[i].nombre);
                }

            }
            printf("\n");
        }
        ret = 0;
    }
    return ret;
}

//8-Borrado de dueño en cascada

/** \brief Borrar las mascotas del idCliente pasado por parametro
 * \param listadoMascotas
 * \param listadoMascotas
 * \param sizeMascota
 * \param sizeMascota
 * \return
 *
 */
int borrarMascotas(sMascota listadoMascotas[], sCliente listadoClientes[], int sizeMascota, int sizeCliente, int index)
{
    int ret = -1;
    int i;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        for(i=0;i<sizeMascota;i++)
        {
            if(listadoMascotas[i].isEmpty == 1 && listadoMascotas[i].idCliente == listadoClientes[index].idCliente)
            {
                listadoMascotas[i].isEmpty = 0;
            }
        }
        ret = 0;
    }
    return ret;
}

/** \brief Borra un dueño y todas las mascotas de él/ella
 * \param listadoMascotas
 * \param listadoClientes
 * \param sizeMascota
 * \param sizeCliente
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */
int borrarDuenoYsusMascotas(sCliente listadoClientes[], sMascota listadoMascota[], int sizeCliente, int sizeMascota)
{
    int ret = -1;
    int auxID;
    int i;

    if(listadoClientes != NULL && listadoMascota != NULL && sizeCliente >= 0 && sizeMascota >= 0)
    {
        mostrarClientesConTodasSusMascotas(listadoClientes, listadoMascota, sizeMascota, sizeCliente);
        utn_getInt(&auxID,"\nIngrese el ID del cliente a eliminar: ","\nError, reingrese: ",0,10);
        for(i=0;i<sizeCliente;i++)
        {
            if(auxID == listadoClientes[i].idCliente && listadoClientes[i].isEmpty == 1)
            {
                listadoClientes[i].isEmpty = 0;
                borrarMascotas(listadoMascota,listadoClientes,sizeMascota,sizeCliente,i);
                printf("\nCliente eliminado Exitosamente\n");
            }
        }
        ret = 0;
    }
    return ret;
}

/** \brief LISTAR LOS CLIENTES CON MAS DE UNA MASCOTA
 * \param listadoClientes
 * \param listadoMascotas
 * \param sizeCliente
 * \param sizeMascota
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */

int listarClientesMasdeUnaMascota(sCliente listadoClientes[], sMascota listadoMascotas[],int sizeCliente,int sizeMascota)
{
    int ret = -1;
    int i;
    int j;
    int contadorMascotas;

    if(listadoClientes != NULL && listadoMascotas != NULL && sizeCliente >= 0 && sizeMascota >= 0)
    {
        for(i=0;i<sizeCliente;i++)
        {
            contadorMascotas = 0;
            for(j=0;j<sizeMascota;j++)
            {
                if(listadoMascotas[j].isEmpty == 1 && listadoClientes[i].isEmpty == 1 && listadoMascotas[j].idCliente == listadoClientes[i].idCliente)
                {
                    contadorMascotas++;
                }
            }
            if(i==0)
            {
                printf("\n%8s | %10s  | %10s  | %15s    | %10s    | %5s  | %8s  |\n","IDCLIENTE","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");
            }
            if(contadorMascotas > 1)
            {
                mostrarUnCliente(listadoClientes,i);
                printf("\n");
            }
        }
        ret = 0;
    }
    return ret;
}

//12- Listar las mascotas de más de tres años, con respectivos dueños.
/** \brief Listar las mascotas de más de tres años, con respectivos dueños
 * \param listadoClientes
 * \param listadoMascotas
 * \param sizeCliente
 * \param sizeMascota
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */
int listarMascotasMasDe3anos(sCliente listadoClientes[], sMascota listadoMascotas[], int sizeCliente, int sizeMascota)
{
    int ret = -1;
    int i;
    int j;
    int flagEdad = 0;

    if(listadoClientes != NULL && listadoMascotas != NULL && sizeCliente >= 0 && sizeMascota >=0)
    {
        for(i=0; i<sizeCliente; i++)
        {
            if(i==0)
            {
                printf("\n%9s  | %9s  | %9s  | %5s  | %5s   | %5s  |  %5s  |  %5s\n","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO","ID MASCOTA","DUENO");
            }

            for(j=0; j<sizeMascota; j++)
            {
                flagEdad = 0;
                if(listadoMascotas[j].edad > 3 && listadoMascotas[j].isEmpty == 1 && listadoClientes[i].isEmpty == 1 && listadoMascotas[j].idCliente == listadoClientes[i].idCliente)
                {
                    flagEdad = 1;
                }

                if(flagEdad == 1)
                {
                    mostrarUnaMascota(listadoMascotas,j);
                    printf(" %5s \n",listadoClientes[i].nombre);
                }
            }

        }
        ret = 0;
    }
    return ret;
}

//14-ORDENAR A LOS DUENOS POR CANTIDADES DE MASCOTAS Y MOSTRARLOS

/** \brief swapea 2 clientes
 * \param listadoClientes[]
 * \param posicion del array i
 * \return void
 */
void swapClientes(sCliente listadoClientes[], int i)
{
    sCliente auxCliente;

    auxCliente = listadoClientes[i];
    listadoClientes[i] = listadoClientes[i+1];
    listadoClientes[i+1] = auxCliente;

}

/** \brief Ordena a los dueños por cantidades de mascotas y los imprime
 * \param listadoClientes
 * \param listadoMascotas
 * \param sizeCliente
 * \param sizeMascota
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok.
 *
 */
int ordenarDuenosPorCantMascotas(sCliente listadoClientes[], sMascota listadoMascotas[], int sizeCliente, int sizeMascota)
{
    int ret = -1;
    int i;
    int flag;

    if(listadoClientes != NULL && listadoMascotas != NULL && sizeCliente >= 0 && sizeMascota >= 0)
    {
        do
        {
            flag = 0;
            for(i=0; i<sizeCliente-1; i++)
            {
                if(cantidadDeMascotas(listadoMascotas,sizeMascota,listadoClientes[i].idCliente) < cantidadDeMascotas(listadoMascotas,sizeMascota,listadoClientes[i+1].idCliente ))
                {
                    swapClientes(listadoClientes,i);
                    flag=1;
                }
                if(cantidadDeMascotas(listadoMascotas,sizeMascota,listadoClientes[i].idCliente) == cantidadDeMascotas(listadoMascotas,sizeMascota,listadoClientes[i+1].idCliente ))
                {
                    if(strcmp(listadoClientes[i].nombre,listadoClientes[i+1].nombre)>0)
                    {
                        swapClientes(listadoClientes,i);

                    }

                }
            }
        }
        while(flag);
        imprimirClientesOrdenados(listadoClientes,listadoMascotas,sizeCliente,sizeMascota);
        ret = 0;
    }

    return ret;
}

int imprimirClientesOrdenados(sCliente listadoClientes[],sMascota listadoMascotas[],int sizeCliente,int sizeMascota)
{
    int ret = -1;
    int i;
    int cantidadMascotas;

    if(listadoClientes != NULL && sizeCliente >= 0)
    {
        printf("\n%8s | %10s  | %10s  | %15s    | %10s    | %5s  | %8s  | %8s  \n","IDCLIENTE","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO","CANTIDAD MASCOTAS");
        for(i=0;i<sizeCliente;i++)
        {
            if(listadoClientes[i].isEmpty == 1)
            {
                mostrarUnCliente(listadoClientes,i);
                cantidadMascotas = cantidadDeMascotas(listadoMascotas,sizeMascota,listadoClientes[i].idCliente);
                printf(" %d\n",cantidadMascotas);
            }
        }
        ret = 0;
    }
    return ret;
}

/*int ordenarDuenosNombre(sCliente listadoClientes[], int sizeCliente)
{
    int ret = -1;
    int i;
    int flag;

    if(listadoClientes != NULL && sizeCliente >= 0)
    {
        do
        {
            flag = 0;
            for(i=0; i<sizeCliente-1; i++)
            {
                if(strcmp(listadoClientes[i].nombre,listadoClientes[i+1].nombre)>0)
                {
                    swapClientes(listadoClientes,i);
                    flag=1;
                }
            }
        }while(flag);

        ret = 0;
    }

    return ret;
}*/








