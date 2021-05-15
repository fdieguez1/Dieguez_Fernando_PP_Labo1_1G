#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#define LARGO_MAX_NOMBRE 20

typedef struct {
    int codigo;
    char descripcion[LARGO_MAX_NOMBRE];
    float importe;
    int idCategoria;
} eJuego;

/** \brief carga automatica de juegos
 *
 * \param juegoArray[] eJuego arreglo de juegos
 * \param sizeS int tamaño juegos
 * \param int* juegoId puntero del autoincremental de id de juego
 * \param int primera categoria cargada
 * \return int 0 si hubo error, 1 si logro hardcodear
 *
 */
int hardcodeJuegos(eJuego juegoArray[], int sizeS, int* juegoId, int categoriaId);

/** \brief muestra los juegos y le pide al usuario que ingrese un juego
 *
 * \param resultingId int* puntero para guardar el resultado
 * \param juegos[] eJuego arreglo de juegos
 * \param sizeS int tamaño del arreglo
 * \return int devuelve 1 si encontro el juego 0 si no lo encontro
 *
 */
int getJuegoId(int *resultingId, eJuego juegos[], int sizeS);

/** \brief muestra un listado de juegos
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeS int tamaño del listado
 * \return void
 *
 */
void showJuegos(eJuego juegos[], int sizeS);
/** \brief muestra un juego
 *
 * \param juego eJuego juego
 * \param showTitles int para mostrar o no los titulos
 * \return void
 *
 */
void showJuego(eJuego juego, int showTitles);

#endif // JUEGO_H_INCLUDED
