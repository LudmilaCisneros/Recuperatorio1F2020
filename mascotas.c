#include <stdio.h>
#include <string.h>
#include "utn.h"
#include "mascotas.h"


/** \brief Hardcodeo de mascotas para pruebas
 * \param  recibe la lista de mascotad
 * \param recibe el tamaño del array
 * \return (-1) si esta mal (0) si esta ok
 */
int hardcodeoMascotas(sMascota listadoMascotas[], int sizeMascota)
{
    int ret = -1;

    int idCliente[11]={0,0,1,1,1,2,2,3,4,4,4};
    int idMascota[11]={0,1,2,3,4,5,6,7,8,9,10};
    char nombre[11][51] = {"PUPPY","LINO","PIPO","BLUE","SASHA","NINO","PICHU","SOF","FLOKY","LOK","COCO"};
    char tipo[11][25] = {"gato","gato","perro","perro","gato","raro","perro","perro","gato","gato","perro"};
    char raza[11][25] = {"callejero","callejero","callejero","callejero","callejero","iguana","pitbull","labrador","callejero","callejero","bulldog"};
    char pais[11][25] = {"Argentina","Argentina","Argentina","Argentina","Argentina","Tailandesa","Irlandes","Senegales","Argentina","Argentina","Francia"};
    int edad[11]= {4,6,1,5,8,10,7,15,3,2,6};
    float peso[11]= {4.5,6.5,1.5,5.2,8.8,10.6,7.3,15.8,20.4,2.4,10.5};
    char sexo[11]={'f','f','m','m','m','m','m','m','m','f','m'};
    int isEmpty[11]= {1,1,1,1,1,1,1,1,1,1,1};
    int i;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        for(i=0; i<sizeMascota; i++)
        {
            listadoMascotas[i].idCliente = idCliente[i];
            listadoMascotas[i].idMascota = idMascota[i];
            strcpy(listadoMascotas[i].nombre, nombre[i]);
            strcpy(listadoMascotas[i].tipo, tipo[i]);
            strcpy(listadoRazas[i].nombreRaza, raza[i]);
            strcpy(listadoRazas[i].pais, pais[i]);
            listadoMascotas[i].edad = edad[i];
            listadoMascotas[i].peso = peso[i];
            listadoMascotas[i].sexo = sexo[i];
            listadoMascotas[i].isEmpty = isEmpty[i];
        }
        ret = 0;

    }

    return ret;
}

/** \brief Para indicar que todas las posiciones del array estan vacias
 *         esta funcion pone la bandera (isEmpty) en TRUE en todas las posiciones del array
 * \param listadoMascotas[] el array de mascotas
 * \param len es el tamaño del array de mascotas
 * \return int return En caso de que no haya mascotas, el array apunte a NULL o el size sea menor a 0 (-1) o (0) si esta ok.
 */
int initMascotas(sMascota listadoMascotas[], int sizeMascota)
{
    int ret = -1;
    int i;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        for(i=0;i<sizeMascota;i++)
        {
            listadoMascotas[i].isEmpty = 0;
        }
        ret = 0;
    }

    return ret;
}

/** \brief Busca si el ID pasado por parametro existe
 * \param listadoMascotas
 * \param sizeMascota
 * \return int return En caso de que no haya ninguna mascota con ese index, el array apunte a NULL, o el size sea menor o igual a 0 (-1) o (0) si el index existe en el array.
 *
 */
int existenciaDeIDMascota(sMascota listadoMascotas[], int sizeMascota,int index)
{
    int ret = -1;
    int i;

    if(listadoMascotas != NULL && sizeMascota >= 0 && index >= 0)
    {
        for(i=0;i<sizeMascota;i++)
        {
            if(index == listadoMascotas[i].idMascota)
            {
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Muestra una mascota con sus campos
 * \param sMascota listadoMascotas
 * \param int index
 * \return int return En caso de que no haya mascotas, el array apunte a NULL(-1) o (0) si esta ok.
 */
int mostrarUnaMascota(sMascota listadoMascotas[], int i)
{
    int ret = -1;

    if(listadoMascotas != NULL)
    {
        printf("%9s  | %9s  | %9s  | %10s      | %5d  | %5.2f   | %5c  |  %5d       |"  ,listadoMascotas[i].nombre,
                                                                                        listadoMascotas[i].tipo,
                                                                                        listadoRazas[i].nombreRaza,
                                                                                        listadoRazas[i].pais,
                                                                                        listadoMascotas[i].edad,
                                                                                        listadoMascotas[i].peso,
                                                                                        listadoMascotas[i].sexo,
                                                                                        listadoMascotas[i].idMascota);

        ret = 0;
    }
    return ret;
}

//4-Alta de mascota, se pueden cargar todos los datos y se debe mostrar el listado de dueños disponibles

/** \brief Genera los ids.
 * \return el proximo id ha utilizar
 */
static int idMascota= 0;

static int autoIncrementIdPet(void)
{

    return idMascota++;
}

/** \brief Busca un lugar libre en el array de lista mascotas
 * \param recibe el array mascotas
 * \param recibe el len
 * \return (-1) En caso de error. (index) si esta ok.
 *
 */
int buscarLibreMascota(sMascota listadoMascotas[], int sizeMascota)
{
    int index = -1;
    int i;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        for(i=0;i<sizeMascota;i++)
        {
            if(listadoMascotas[i].isEmpty == 0)
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
void mostrarRazas(sRaza listadoRazas[], int sizeRazas)
{
    int i;

    for(i=0;i<sizeRazas;i++)
    {
        printf("%d.%s /%s\n",i,listadoRazas[i].nombreRaza,listadoRazas[i].pais);
    }

}
/** \brief Alta de una mascota con todos sus datos
 * \param listadoMascotas
 * \param listadoClientes
 * \param sizeMascota
 * \param sizeCliente
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */
int altaMascota(sMascota listadoMascotas[], int sizeMascota,sRaza listadoRazas[],int sizeRazas)
{
    int ret = -1;
    int index;
    int auxIdCliente;
    int indexRaza;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {

        utn_getInt(&auxIdCliente, "\nDe que cliente es? (ID): ","\nError, reingrese: ",0,10);
        index = buscarLibreMascota(listadoMascotas,sizeMascota);
        if(index != -1)
        {
            listadoMascotas[index].idCliente = auxIdCliente;
            utn_getString(listadoMascotas[index].nombre,"\nIngrese el nombre de la mascota: ","\nError, reingrese: ",0,51,3);
            utn_getString(listadoMascotas[index].tipo,"\nIngrese el tipo/especie: ","\nError, reingrese: ",0,51,3);

            mostrarRazas(listadoRazas,sizeRazas);
            utn_getInt(&indexRaza,"\nIngrese numero de raza: ","Error.",0,sizeRazas-1);
            listadoMascotas[index].raza = listadoRazas[indexRaza];

            //utn_getString(listadoMascotas[index].raza.nombreRaza,"\nIngrese la raza: ","\nError, reingrese: ",0,51,3);
            //utn_getString(listadoMascotas[index].raza.pais,"\nIngrese el pais de la raza: ","\nError, reingrese: ",0,51,3);

            utn_getInt(&listadoMascotas[index].edad,"\nIngrese la edad: ","\nError, reingrese: ",0,200);
            utn_getFloat(&listadoMascotas[index].peso,"\nIngrese el peso: ","\nError, reingrese: ",0,100);
            utn_getChar(&listadoMascotas[index].sexo,"\nIngrese sexo (f/m): ","\nError, reingrese: ",'f','m');
            listadoMascotas[index].idMascota = autoIncrementIdPet();
            listadoMascotas[index].isEmpty = 1;

            printf("\nAlta Exitosa\n");
            ret = 0;
        }

    }
    return ret;
}
//5-Baja de mascota, es lógica, y queda el lugar disponible para otra mascota.
/** \brief Baja de una mascota
 * \param listadoMascotas
 * \param sizeMascota
 * \return int return En caso de que no haya mascotas, el array apunte a NULL o el size sea menor a 0 (-1) o (0) si esta ok.
 *
 */
int bajaMascota(sMascota listadoMascotas[], int sizeMascota)
{
    int ret = -1;
    int index;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        utn_getInt(&index,"\nIngrese el ID de la mascota a eliminar: ","\nError, reingrese: ",0,20);
        if(existenciaDeIDMascota(listadoMascotas,sizeMascota,index) == 0)
        {
            listadoMascotas[index].isEmpty = 0;
            printf("\nBaja Exitosa\n");
            ret = 0;
        }
        else{
            printf("\nEl id no existe\n");
        }
    }
    return ret;
}

//6-Modificar mascota , todo menos el dueño.

/** \brief Modificar mascota
 * \param listadoMascotas
 * \param sizeMascota
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */
int modificarMascota(sMascota listadoMascotas[], int sizeMascota)
{
    int ret = -1;
    int i;
    int atributo;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        utn_getInt(&i,"\nIngrese el ID de la mascota a modificar: ","\nError, reingrese: ",0,20);
        while(existenciaDeIDMascota(listadoMascotas,sizeMascota,i) == -1)
        {
            printf("\nEl ID es erroneo.. ");
            utn_getInt(&i,"\nIngrese el ID de la mascota a modificar: ","\nError, reingrese: ",0,20);
        }
        printf("\n1.NOMBRE DE LA MASCOTA");
        printf("\n2.TIPO/ESPECIE");
        printf("\n3.RAZA");
        printf("\n4.EDAD");
        printf("\n5.PESO");
        printf("\n6.SEXO");

        utn_getInt(&atributo,"\nQue campo desea cambiar?: ","\nError, reingrese: ",0,6);
        switch(atributo)
        {
            case 1://NOMBRE
                if(utn_getString(listadoMascotas[i].nombre,"\nIngrese el nuevo nombre: ","\nError, reingrese: ",0,51,3) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 2://TIPO
                if(utn_getString(listadoMascotas[i].tipo,"\nIngrese el nuevo tipo/especie: ","\nError, reingrese: ",0,51,3) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 3://RAZA
                if(utn_getString(listadoMascotas[i].raza.nombreRaza,"\nIngrese la nueva raza: ","\nError, reingrese: ",0,51,3) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 4://EDAD
                if(utn_getInt(&listadoMascotas[i].edad,"\nIngrese la nueva edad: ","\nError, reingrese: ",0,150) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 5://PESO
                if(utn_getFloat(&listadoMascotas[i].peso,"\nIngrese el nuevo peso: ","\nError, reingrese: ",0,150) == 0)
                {
                    printf("\nModificacion Exitosa\n");
                }
                break;

            case 6://SEXO
                if(utn_getChar(&listadoMascotas[i].sexo,"\nIngrese el nuevo sexo: ","\nError, reingrese: ",'f','m') == 0)
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

//9-ORDENAR LAS MASCOTAS POR TIPO Y LISTARLAS CON SUS DUEÑOS

/** \brief swapea 2 mascotas
 * \param listMascota[]
 * \param posicion del array i
 * \return void
 */
void swapMascotas(sMascota listadoMascotas[], int i)
{
    sMascota auxMascota;

    auxMascota = listadoMascotas[i];
    listadoMascotas[i] = listadoMascotas[i+1];
    listadoMascotas[i+1] = auxMascota;

}
/** \brief Ordena las mascotas por tipo
 * \param listadoMascotas
 * \param sizeMascota
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok
 *
 */
int ordenarMascotasPorTipo(sMascota listadoMascotas[],int sizeMascota)
{
    int ret = -1;
    int i;
    int flagSwap;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        do
        {
            flagSwap = 0;

            for(i=0; i<sizeMascota-1; i++)
            {
                if(strcmp(listadoMascotas[i].tipo, listadoMascotas[i+1].tipo) > 0)//A-Z
                {
                    swapMascotas(listadoMascotas,i);
                    flagSwap=1;
                }

            }

        }
        while(flagSwap);

        ret = 0;
    }

    return ret;
}

//LISTAR LAS MASCOTAS POR UN TIPO EN PARTICULAR(PERRO,GATO,RARO)
/** \brief Recibe un tipo/especie de mascota por parametro y lo lista
 * \param listadoMascotas
 * \param sizeMascota
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok.
 *
 */
int listarPorCriterio(sMascota listadoMascotas[], int sizeMascota, char* criterio)
{
    int ret = -1;
    int i;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        for(i=0; i<sizeMascota; i++)
        {
            if(i==0)
            {
                printf("\n%9s  | %9s  | %9s  | %5s  | %5s   | %5s  |  %5s\n","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO","ID MASCOTA");
                ret = 0;
            }
            if(listadoMascotas[i].isEmpty == 1 && strcmp(criterio, listadoMascotas[i].tipo) == 0)
            {
                mostrarUnaMascota(listadoMascotas,i);
                printf("\n");
            }
        }
    }
    if(ret == -1)
    {
        printf("\nNo hay mascotas con ese criterio");
    }
    return ret;
}
/** \brief El usuario decide por cual tipo quiere ver/listar mascotas
 * \param listadoMascotas
 * \param sizeMascota
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok.
 *
 */
int listarMascotasSegunCriterioTipo(sMascota listadoMascotas[], int sizeMascota)
{
    int ret = -1;
    int opcionTipo;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        printf("\nPOR CUAL TIPO QUIERE LISTAR?\n");
        printf("\n1.PERROS");
        printf("\n2.GATOS");
        printf("\n3.RARO");
        utn_getInt(&opcionTipo,"\nIngrese la opcion: ","\nError, reingrese: ",0,10);
        switch(opcionTipo)
        {
            case 1:
            listarPorCriterio(listadoMascotas,sizeMascota,"perro");
            break;

            case 2:
            listarPorCriterio(listadoMascotas,sizeMascota,"gato");
            break;

            case 3:
            listarPorCriterio(listadoMascotas,sizeMascota,"raro");
            break;

            default:
                printf("\nOpcion Inexistente\n");
                break;
        }
        ret = 0;
    }
    return ret;
}

//16-EL PROMEDIO DE EDAD ENTRE LAS MASCOTAS
/** \brief Saca el promedio de todas las mascotas
 * \param listadoMascotas
 * \param sizeMascota
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok.
 *
 */
int promedioTodasLasMascotas(sMascota listadoMascotas[], int sizeMascota)
{
    int ret = -1;
    int i;
    int contadorMascotas;
    int acumuladorEdad;
    float promedioTotal;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        contadorMascotas = 0;
        acumuladorEdad = 0;

        for(i=0;i<sizeMascota;i++)
        {
            if(listadoMascotas[i].isEmpty == 1)
            {
                contadorMascotas++;
                acumuladorEdad += listadoMascotas[i].edad;
            }
        }
        promedioTotal = (float)(acumuladorEdad/contadorMascotas);
        printf("\nEl promedio de edad de todas las mascotas es: %.2f\n",promedioTotal);
        ret = 0;
    }
    return ret;
}

//17-EL PROMEDIO DE EDAD ENTRE LAS MASCOTAS, POR TIPO
/** \brief Muestra el promedio de edad entre las mascotas por tipo
 * \param listadoMascotas
 * \param sizeMascota
 * \return (-1) en el caso de que el array este apuntando a NULL o el size sea menor o igual a 0. (0) en el caso que este ok.
 *
 */
int promedioEdadMascotasTipo(sMascota listadoMascotas[],int sizeMascota)
{
    int ret = -1;
    char atributo[51];
    int auxOpcion;
    int i;
    int acumuladorEdad = 0;
    int contador = 0;
    float promedioEdad;

    if(listadoMascotas != NULL && sizeMascota >= 0)
    {
        printf("\n1.PERRO");
        printf("\n2.GATO");
        printf("\n3.RARO\n");
        utn_getInt(&auxOpcion,"\nEl promedio de que tipo/especie?: ","\nError, reingrese: ",1,3);
        switch(auxOpcion)
        {
            case 1:
            strncpy(atributo,"perro",sizeof(atributo));
            break;

            case 2:
            strncpy(atributo,"gato",sizeof(atributo));
            break;

            case 3:
            strncpy(atributo,"raro",sizeof(atributo));
            break;
        }

        for(i=0;i<sizeMascota;i++)
        {
            if(listadoMascotas[i].isEmpty == 1 && strcmp(atributo, listadoMascotas[i].tipo) == 0)
            {
                contador++;
                acumuladorEdad += listadoMascotas[i].edad;
            }
        }
        promedioEdad = (float)(acumuladorEdad/contador);
        printf("\nEl promedio de edad para el tipo %s es %.2f",atributo,promedioEdad);
        ret = 0;
    }
    return ret;
}



int cantidadDeMascotas(sMascota listadoMascotas[], int sizeMascota, int idCliente)
{
    int ret = 0;
    int i;

    for(i=0; i<sizeMascota; i++)
    {
        if(listadoMascotas[i].isEmpty == 1){
        if(listadoMascotas[i].idCliente == idCliente)
        {
            ret++;
        }

        }
    }
    return ret;
}









