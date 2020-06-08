#include <stdio.h>
#include <stdlib.h>
#include "clientesYmascotas.h"
#include "utn.h"
#include "raza.h"
#include "localidad.h"
#include <string.h>

#define QTY_CLIENTES 10
#define QTY_MASCOTAS 20
#define QTY_RAZAS 5
#define QTY_LOCALIDAD 3

int main()
{
    sCliente listadoClientes[QTY_CLIENTES];
    sMascota listadoMascotas[QTY_MASCOTAS];
    sRaza listadoRazas[QTY_RAZAS];
    sLocalidad listadoLocalidades[QTY_LOCALIDAD];


    int opcion;

    hardcodeoClientes(listadoClientes,QTY_CLIENTES);
    hardcodeoMascotas(listadoMascotas,QTY_MASCOTAS);
    hardcodeoRazas(listadoRazas,QTY_RAZAS);

    do
    {
        printf("\n\n1.MOSTRAR LISTADO DE CLIENTES");
        printf("\n2.MOSTRAR LISTADO DE MASCOTAS");
        printf("\n3.MOSTRAR LISTADO DE CLIENTES CON MASCOTA");
        printf("\n4.DAR ALTA MASCOTA");
        printf("\n5.DAR BAJA MASCOTA");
        printf("\n6.MODIFICAR MASCOTA");
        printf("\n7.ALTA DUENO");
        printf("\n8.BORRADO DE DUENO EN CASCADA");
        printf("\n9.ORDENAR LAS MASCOTAS POR TIPO Y LISTARLAS CON SUS DUEÑOS");
        printf("\n10.MODIFICAR DUENO");
        printf("\n11.LISTAR LOS CLIENTES CON MAS DE UNA MASCOTA");
        printf("\n12.LISTAR LAS MASCOTAS DE MAS DE TRES ANOS, CON SUS RESPECTIVOS DUENOS");
        printf("\n13.LISTAR LAS MASCOTAS POR UN TIPO EN PARTICULAR(PERRO,GATO,RARO)");
        printf("\n14.ORDENAR A LOS DUENOS POR CANTIDADES DE MASCOTAS Y MOSTRARLOS");
        printf("\n15.ORDENAR A LOS DUENOS POR CANTIDADES DE MASCOTAS Y POR ORDEN ALFABETICO DE LOS NOMBRES Y MOSTRAR");
        printf("\n16.EL PROMEDIO DE EDAD ENTRE LAS MASCOTAS");
        printf("\n17.EL PROMEDIO DE EDAD ENTRE LAS MASCOTAS, POR TIPO");
        printf("\n18.el porcentaje que tengo de mujeres sobre el total de clientes.");
        printf("\n19.Salir\n");
        utn_getInt(&opcion,"\nIngrese la opcion: ","\nError, reingrese: ",1,19);

        switch(opcion)
        {
        case 1:
            mostrarClientes(listadoClientes,QTY_CLIENTES);
            break;

        case 2:
            mostrarMascotas(listadoClientes,listadoMascotas,QTY_MASCOTAS,QTY_CLIENTES);
            break;

        case 3:
            mostrarClientesConTodasSusMascotas(listadoClientes,listadoMascotas,QTY_MASCOTAS,QTY_CLIENTES);
            break;

        case 4:
            mostrarClientes(listadoClientes,QTY_CLIENTES);
            altaMascota(listadoMascotas,QTY_MASCOTAS,listadoRazas,QTY_RAZAS);
            break;

        case 5:
            mostrarMascotas(listadoClientes,listadoMascotas,QTY_MASCOTAS,QTY_CLIENTES);
            bajaMascota(listadoMascotas, QTY_MASCOTAS);
            break;

        case 6:
            mostrarMascotas(listadoClientes,listadoMascotas,QTY_MASCOTAS,QTY_CLIENTES);
            modificarMascota(listadoMascotas,QTY_MASCOTAS);
            break;

        case 7:
            altaCliente(listadoClientes, QTY_CLIENTES);
            break;

        case 8:
            borrarDuenoYsusMascotas(listadoClientes,listadoMascotas,QTY_CLIENTES,QTY_MASCOTAS);
            break;

        case 9:
            ordenarMascotasPorTipo(listadoMascotas,QTY_MASCOTAS);
            mostrarMascotas(listadoClientes,listadoMascotas,QTY_MASCOTAS,QTY_CLIENTES);
            break;

        case 10:
            modificarCliente(listadoClientes,QTY_CLIENTES);
            break;

        case 11:
            listarClientesMasdeUnaMascota(listadoClientes,listadoMascotas,QTY_CLIENTES,QTY_MASCOTAS);
            break;

        case 12:
            listarMascotasMasDe3anos(listadoClientes,listadoMascotas,QTY_CLIENTES,QTY_MASCOTAS);
            break;

        case 13:
            listarMascotasSegunCriterioTipo(listadoMascotas,QTY_MASCOTAS);
            break;

        case 14:
            ordenarDuenosPorCantMascotas(listadoClientes,listadoMascotas,QTY_CLIENTES,QTY_MASCOTAS);
            break;

        case 15:
            //ordenarDuenosNombre(listadoClientes,QTY_CLIENTES);
            ordenarDuenosPorCantMascotas(listadoClientes,listadoMascotas,QTY_CLIENTES,QTY_MASCOTAS);
            break;

        case 16:
            promedioTodasLasMascotas(listadoMascotas, QTY_MASCOTAS);
            break;

        case 17:
            promedioEdadMascotasTipo(listadoMascotas,QTY_MASCOTAS);
            break;

        case 18:
            sacarPorcentajeMujeres(listadoClientes, QTY_CLIENTES);
            break;

        default:
            printf("\nOpcion inexistente");
        }
    }
    while(opcion != 19);

    return 0;
}
