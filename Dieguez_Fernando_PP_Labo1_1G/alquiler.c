#include "alquiler.h"
#include "datawarehouse.h"
#include "ui.h"


int initializeAlquileres(eAlquiler alquileres[], int sizeA)
{
    int ret = 0;
    if (alquileres != NULL && sizeA > 0)
    {
        for(int i = 0; i < sizeA; i++)
        {
            alquileres[i].isEmpty = 1;
        }
        ret = 1;
    }
    return ret;
}

int findPlaceInAlquilerArray(eAlquiler alquileres[], int sizeA )
{
    int ret = -1;
    if (alquileres != NULL && sizeA > 0)
    {
        for(int i = 0; i < sizeA; i++)
        {
            if (alquileres[i].isEmpty)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int addAlquiler(eAlquiler alquileres[], int index, int *alquilerId, eCliente clientes[], int sizeE, eJuego juegos[], int sizeF)
{
    int allOk = 0;
    eDate date;
    int clienteId;
    int juegoId;
    //Cargo ID
    alquileres[index].id = *alquilerId;
    //Pido la fecha de almuerzo
    int dateOk = getDate(&date) == -1 ? 0 : 1;
    //Pido el clienteId
    int clienteIdOk = getClienteId(&clienteId, clientes, sizeE);
    int foodOk = getJuegoId(&juegoId, juegos, sizeF);
    if (dateOk && clienteIdOk && foodOk)
    {
        alquileres[index].id = *alquilerId;
        alquileres[index].isEmpty = 0;
        alquileres[index].date = date;
        alquileres[index].clienteId = clienteId;
        alquileres[index].juegoId = juegoId;
        allOk = 1;
        (*alquilerId)++;
    }
    else
    {
        showError("Error en uno o mas datos, abortando la carga de almuerzo");
    }
    return allOk;
}

void showAlquileres(eAlquiler alquileres[],int sizeA)
{
    showTitlesForAlquileres();
    for(int i = 0; i < sizeA; i++)
    {
        if (!alquileres[i].isEmpty)
        {
            showAlquiler(alquileres[i], 0);
        }
    }
}
void showAlquiler(eAlquiler alquiler, int showTitles)
{
    if (showTitles)
    {
        showTitlesForAlquileres();
    }
    printf("%3d\t\t%d\t%d\t",alquiler.id,alquiler.clienteId, alquiler.juegoId);
    printDate(alquiler.date.day,alquiler.date.month,alquiler.date.year );
    printf("\n");
}

/** \brief hardcodeo de almuerzos utilizando datawarehouse
 *
 * \param alquilerArray[] eAlquiler
 * \param sizeA int
 * \param id int*
 * \return void
 *
 */
int hardcodeAlquileres(eAlquiler alquilerArray[], int sizeA, int* id, eCliente clientes[], eJuego juegos[])
{
    int ret = 0;
    if (alquilerArray != NULL && sizeA > 0 && id > 0)
    {
        ret = 1;
        for (int i =0; i < sizeA; i++)
        {
            alquilerArray[i].id = *id;
            alquilerArray[i].date = dates[i];
            alquilerArray[i].isEmpty = 0;
            alquilerArray[i].clienteId = clientes[i].codigo;
            alquilerArray[i].juegoId = juegos[i].codigo;
            (*id)++;
        }
    }
    return ret;
}
