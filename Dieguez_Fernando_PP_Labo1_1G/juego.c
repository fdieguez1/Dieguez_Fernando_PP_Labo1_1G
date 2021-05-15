#include "juego.h"
#include "datawarehouse.h"

int hardcodeJuegos(eJuego juegoArray[], int sizeJ, int* juegoId, int categoriaId)
{
    int ret = 0;
    int catId = categoriaId;
    for (int i =0; i < sizeJ; i++)
    {
        juegoArray[i].codigo = *juegoId;
        strcpy(juegoArray[i].descripcion, descripcionJuegos[i]);
        juegoArray[i].idCategoria = catId;
        juegoArray[i].importe = foodprices[i];
        catId++;
        ret = 1;
        (*juegoId)++;
    }
    return ret;
}

int getJuegoId(int *resultingId, eJuego juegos[], int sizeJ)
{
    int ret = 0;
    showJuegos(juegos, sizeJ);
    utn_getNumero(resultingId, "Ingrese el codigo de juego: ", "Error, juego invalido. ", 1, 999, 10);
    for(int i = 0; i < sizeJ; i++)
    {
        if (*resultingId == juegos[i].codigo)
        {
            ret = 1;
            break;
        }
    }
    while(ret != 1)
    {
        showError("Error, juego invalido. ");
    }
    return ret;
}


void showJuegos(eJuego juegos[], int sizeJ)
{
    showTitlesForJuegos();
    for(int i = 0; i < sizeJ; i++)
    {
        showJuego(juegos[i], 0);
    }
}
void showJuego(eJuego juego, int showTitles)
{
    if (showTitles)
    {
        showTitlesForJuegos();
    }
    printf("%3d\t%20s\t%3.2f\t%3d\n", juego.codigo, juego.descripcion, juego.importe, juego.idCategoria);

}
