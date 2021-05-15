#include <stdio.h>
#include <string.h>
#include "datawarehouse.h"
#include "categoria.h"
#include "inputs.h"
#include "ui.h"


int hardcodeCategorias(eCategoria categoriaArray[], int sizeS, int* categoriasId)
{
    int ret = 0;
    for (int i =0; i < sizeS; i++)
    {
        categoriaArray[i].id = *categoriasId;
        strcpy(categoriaArray[i].descripcion, descripcionCategorias[i]);
        ret = 1;
        (*categoriasId)++;
    }
    return ret;
}

int getCategoriaId(int *resultingId, eCategoria categorias[], int sizeS)
{
    int ret = 0;
    showCategorias(categorias, sizeS);
    utn_getNumero(resultingId, "Ingrese el ID de categoria: ", "Error, categoria invalido. ", 1, 999, 10);
    for(int i = 0; i < sizeS; i++)
    {
        if (*resultingId == categorias[i].id)
        {
            ret = 1;
            break;
        }
    }
    while(ret != 1)
    {
        showError("Error, categoria invalido. ");
    }
    return ret;
}


void showCategorias(eCategoria categorias[], int sizeS)
{
    showTitlesForCategorias();
    for(int i = 0; i < sizeS; i++)
    {
        showCategoria(categorias[i], 0);
    }
}
void showCategoria(eCategoria categoria, int showTitles)
{
    if (showTitles)
    {
        showTitlesForCategorias();
    }
    printf("%3d%20s\n", categoria.id, categoria.descripcion);

}
