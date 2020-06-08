#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utn.h"
#include "clientes.h"

/** \brief Hardcodeo de clientes para pruebas
 * \param  recibe la lista de clientes
 * \param recibe el tamaño del array
 * \return (-1) si esta mal (0) si esta ok
 */
int hardcodeoClientes(sCliente listadoClientes[], int sizeCliente)
{
    int ret = -1;

    int idCliente[10]={0,1,2,3,4};
    char nombre[10][51] = {"juana","pedro","liliana","matias","julio"};
    char apellido[10][51] = {"rodriguez","argento","lopez","alfonzo","diaz"};
    char localidad[10][51] = {"lanus","lomas de zamora","caba","temperley","escalada"};
    long telefono[10] = {46357168,46051798,46048963,46859324,89634752};
    int edad[10] = {18,21,25,30,50};
    char sexo[10] = {'f','m','f','m','m'};
    int isEmpty[10]= {1,1,1,1,1};
    int i;

    if(listadoClientes != NULL && sizeCliente >= 0)
    {
        for(i=0; i<sizeCliente; i++)
        {
            listadoClientes[i].idCliente = idCliente[i];
            strcpy(listadoClientes[i].nombre, nombre[i]);
            strcpy(listadoClientes[i].apellido, apellido[i]);
            strcpy(listadoClientes[i].localidad, localidad[i]);
            listadoClientes[i].telefono = telefono[i];
            listadoClientes[i].edad = edad[i];
            listadoClientes[i].sexo = sexo[i];
            listadoClientes[i].isEmpty = isEmpty[i];
        }
        ret = 0;

    }

    return ret;
}

/** \brief Para indicar que todas las posiciones del array estan vacias
 *         esta funcion pone la bandera (isEmpty) en TRUE en todas las posiciones del array
 * \param listadoClientes[] el array de clientes
 * \param len es el tamaño del array de clientes
 * \return int return En caso de que no haya clientes, el array apunte a NULL o el len sea menor a 0 (-1) o (0) si esta ok.
 */
int initClientes(sCliente listadoClientes[], int sizeCliente)
{
    int ret = -1;
    int i;

    if(listadoClientes != NULL && sizeCliente >= 0)
    {
        for(i=0;i<sizeCliente;i++)
        {
            listadoClientes[i].isEmpty = 0;
        }
        ret = 0;
    }

    return ret;
}

/** \brief Muestra un cliente con sus campos
 * \param sCliente listadoClientes
 * \param int index
 * \return (-1) si esta mal (0) si esta ok
 */
int mostrarUnCliente(sCliente listadoClientes[], int i)
{
    int ret = -1;

    if(listadoClientes != NULL)
    {
        printf("%8d  | %10s  | %10s  | %15s    | %10ld    | %5d  | %8c  |",listadoClientes[i].idCliente,
                                                                        listadoClientes[i].nombre,
                                                                        listadoClientes[i].apellido,
                                                                        listadoClientes[i].localidad,
                                                                        listadoClientes[i].telefono,
                                                                        listadoClientes[i].edad,
                                                                        listadoClientes[i].sexo);

        ret = 0;
    }
    return ret;
}

//1-Tenemos un listado de clientes(nombre, apellido,localidad,teléfono,edad,sexo) .
/** \brief Muestra todos los clientes con sus campos
 * \param sCliente listadoClientes
 * \param int sizeCliente
 * \return (-1) si esta mal (0) si esta ok
 */
int mostrarClientes(sCliente listadoClientes[], int sizeCliente)
{
    int ret = -1;
    int i;
    int flag = 0;

    if(listadoClientes != NULL && sizeCliente >= 0)
    {
        for(i=0;i<sizeCliente;i++)
        {
            if(i==0 && flag == 0)
            {
                printf("\n%8s | %10s  | %10s  | %15s    | %10s    | %5s  | %8s  |\n","IDCLIENTE","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");
            }
              if(listadoClientes[i].isEmpty == 1)
              {
                  mostrarUnCliente(listadoClientes,i);
                  printf("\n");
                  flag = 1;
              }
        }
    }
    return ret;
}

//7-Alta dueño
/** \brief Genera los ids.
 * \return el proximo id ha utilizar
 */
static int idCliente= 0;

static int autoIncrementIdClient(void)
{

    return idCliente++;
}

/** \brief Busca un lugar libre en el array de lista mascotas
 * \param recibe el array mascotas
 * \param recibe el len
 * \return (-1) En caso de error. (index) si esta ok.
 *
 */
int buscarLibre(sCliente listadoClientes[], int sizeCliente)
{
    int index = -1;
    int i;

    if(listadoClientes != NULL && sizeCliente >= 0)
    {
        for(i=0;i<sizeCliente;i++)
        {
            if(listadoClientes[i].isEmpty == 0)
            {
                index = i;
            }
        }
        if(index == -1)
        {
            printf("\nNo hay espacio");
        }
    }
    return index;
}
/** \brief Da de alta un dueño
 * \param listadoClientes
 * \param sizeClientes
 * \return int return En caso de que no haya clientes, el array apunte a NULL o el len sea menor a 0 (-1) o (0) si esta ok.
 *
 */
int altaCliente(sCliente listadoClientes[], int sizeCliente)
{
    int ret = -1;
    int index;

    if(listadoClientes != NULL && sizeCliente >= 0)
    {

        index = buscarLibre(listadoClientes,sizeCliente);
        if(index != -1)
        {
            utn_getString(listadoClientes[index].nombre,"\nIngrese el nombre: ","\nError, reingrese: ",0,51,3);
            utn_getString(listadoClientes[index].apellido,"\nIngrese el apellido: ","\nError, reingrese: ",0,51,3);
            utn_getString(listadoClientes[index].localidad,"\nIngrese localidad: ","\nError, reingrese: ",0,51,3);
            utn_getLong(&listadoClientes[index].telefono,"\nIngrese telefono de contacto: ","\nError, reingrese: ",LONG_MIN,LONG_MAX);
            utn_getInt(&listadoClientes[index].edad,"\nIngrese la edad: ","\nError, reingrese: ",18,100);
            utn_getChar(&listadoClientes[index].sexo,"\nIngrese el sexo: ","\nError, reingrese: ",'f','m');
            listadoClientes[index].idCliente = autoIncrementIdClient();
            listadoClientes[index].isEmpty = 1;

            printf("\nAlta Exitosa\n");
            ret = 0;
        }

    }
    return ret;
}
/** \brief Busca si el ID pasado por parametro existe
 * \param listadoClientes
 * \param sizeCliente
 * \return int return En caso de que no haya ninguna mascota con ese index, el array apunte a NULL, o el size sea menor o igual a 0 (-1) o (0) si el index existe en el array.
 *
 */
int existenciaDeIDCliente(sCliente listadoClientes[], int sizeCliente,int index)
{
    int ret = -1;
    int i;

    if(listadoClientes != NULL && sizeCliente >= 0 && index >= 0)
    {
        for(i=0;i<sizeCliente;i++)
        {
            if(index == listadoClientes[i].idCliente)
            {
                ret = 0;
            }
        }
    }
    return ret;
}
//10-MODIFICAR DUEÑO

/** \brief Modificar dueño
 * \param listadoClientes
 * \param sizeCliente
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */
int modificarCliente(sCliente listadoClientes[], int sizeCliente)
{
    int ret = -1;
    int i;
    int atributo;

    if(listadoClientes != NULL && sizeCliente >= 0)
    {
        mostrarClientes(listadoClientes,sizeCliente);
        utn_getInt(&i,"\nIngrese el ID del cliente a modificar: ","\nError, reingrese: ",0,10);
        while(existenciaDeIDCliente(listadoClientes,sizeCliente,i) == -1)
        {
            printf("\nEl ID es erroneo.. ");
            utn_getInt(&i,"\nIngrese el ID del cliente a modificar: ","\nError, reingrese: ",0,10);
        }
        printf("\n1.NOMBRE");
        printf("\n2.APELLIDO");
        printf("\n3.LOCALIDAD");
        printf("\n4.TELEFONO");
        printf("\n5.EDAD");
        printf("\n6.SEXO");

        utn_getInt(&atributo,"\nQue campo desea cambiar?: ","\nError, reingrese: ",0,6);
        switch(atributo)
        {
            case 1://NOMBRE
                if(utn_getString(listadoClientes[i].nombre,"\nIngrese el nuevo nombre: ","\nError, reingrese: ",0,51,3) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 2://APELLIDO
                if(utn_getString(listadoClientes[i].apellido,"\nIngrese el nuevo apellido: ","\nError, reingrese: ",0,51,3) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 3://LOCALIDAD
                if(utn_getString(listadoClientes[i].localidad,"\nIngrese la nueva localidad: ","\nError, reingrese: ",0,51,3) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 4://TELEFONO
                if(utn_getLong(&listadoClientes[i].telefono,"\nIngrese el nuevo telefono: ","\nError, reingrese: ",0,LONG_MAX) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 5://EDAD
                if(utn_getInt(&listadoClientes[i].edad,"\nIngrese la nueva edad: ","\nError, reingrese: ",18,100) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 6://SEXO
                if(utn_getChar(&listadoClientes[i].sexo,"\nIngrese el nuevo sexo: ","\nError, reingrese: ",'f','m') == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            default:
                printf("\nOpcion Inexistente\n");
                break;

        }
        ret = 0;
    }
    return ret;
}

//18-EL PROMEDIO QUE TENGO ENTRE VARONES Y MUJERES DE MIS CLIENTES
/** \brief Saca el promedio de mujeres y varones
 * \param listadoClientes
 * \param sizeCliente
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */
int sacarPorcentajeMujeres(sCliente listadoClientes[], int sizeCliente)
{
    int ret = -1;
    int i;
    int contador = 0;
    int contadorMujeres = 0;
    float porcentajeMujeres;

    if(listadoClientes != NULL && sizeCliente >= 0)
    {
        for(i=0; i<sizeCliente; i++)
        {
            if(listadoClientes[i].isEmpty == 1)
            {
                contador++;
                if(listadoClientes[i].sexo == 'f')
                {
                    contadorMujeres++;
                }

            }
        }
        if(contador == 0)
        {
            printf("\nNo hay clientes cargados");
        }
        porcentajeMujeres = (float)contadorMujeres/contador*100;

        printf("\nEl porcentaje de las mujeres es: %.2f ",porcentajeMujeres);
        ret = 0;
    }
    return ret;
}




