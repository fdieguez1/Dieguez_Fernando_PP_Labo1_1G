#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED
#define MAX_CLIENT_LENGTH 51

typedef struct {
    int id;
    char descripcion[MAX_CLIENT_LENGTH];
} eCategoria;

/** \brief carga automatica de sectores
 *
 * \param sectorArray[] eCategoria arreglo de sectores
 * \param sizeS int tamaño sectores
 * \param int* categoriasId puntero al autoincremental para categorias
 * \return int 0 si hubo error, 1 si logro hardcodear
 *
 */
int hardcodeCategorias(eCategoria sectorArray[], int sizeS, int* categoriasId);


/** \brief muestra los sectores y le pide al usuario que ingrese un sector
 *
 * \param resultingId int* puntero para guardar el resultado
 * \param sectors[] eCategoria arreglo de sectores
 * \param sizeS int tamaño del arreglo
 * \return int devuelve 1 si encontro el sector 0 si no lo encontro
 *
 */
int getCategoriaId(int *resultingId, eCategoria sectors[], int sizeS);


/** \brief muestra un listado de sectores
 *
 * \param sectors[] eCategoria listado de sectores
 * \param sizeS int tamaño del listado
 * \return void
 *
 */
void showCategorias(eCategoria sectors[], int sizeS);
/** \brief muestra un sector
 *
 * \param sector eCategoria sector
 * \param showTitles int para mostrar o no los titulos
 * \return void
 *
 */
void showCategoria(eCategoria sector, int showTitles);

#endif // CATEGORIA_H_INCLUDED
