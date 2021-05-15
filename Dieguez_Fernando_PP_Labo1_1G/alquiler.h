#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"
#include "cliente.h"
#include "juego.h"

typedef struct {
    int id;
    int clienteId;
    int juegoId;
    eDate date;
    int isEmpty;
}
eAlquiler;

/** \brief inicializa el arreglo de almuerzos cargandolos como vacios
 *
 * \param alquileres[] eAlquiler arreglo de almuerzos
 * \param sizeA int tamaño del arreglo
 * \return int devuelve 1 si pudo inicializar, 0 si no pudo
 *
 */
int initializeAlquileres(eAlquiler alquileres[], int sizeA);

/** \brief busca un lugar en el arreglo para la carga de un almuerzo
 *
 * \param alquileres[] eAlquiler arreglo de almuerzos
 * \param sizeA int tamaño del arreglo
 * \return int devuelve -1 si hubo error o 0/sizeA representando el indice donde se encontro un lugar.
 *
 */
int findPlaceInAlquilerArray(eAlquiler alquileres[], int sizeA );

/** \brief pide datos y carga un almuerzo en el indice indicado
 *
 * \param alquileres[] eAlquiler arreglo de almuerzos
 * \param index int posicion en el arreglo para el nuevo almuerzo
 * \param newId int nuevo id a ser asignado a la alta, direccion en memoria para autoincrementar
 * \return int devuelve 0 si no logro realizar la carga, 1 si lo logro
 *
 */
int addAlquiler(eAlquiler alquileres[], int index, int *alquilerId, eCliente clientes[], int sizeE, eJuego juegos[], int sizeF);

/** \brief muestra la lista de almuerzos con titulos para los campos
 *
 * \param alquileres[] eAlquiler arreglo de almuerzos
 * \return void
 * \param sizeA int tamaño de arreglo
 *
 */
void showAlquileres(eAlquiler alquileres[], int sizeA);


/** \brief muestra un almuerzo con opcion a mostrar titulos para los campos
 *
 * \param alquiler eAlquiler
 * \param showTitles int
 * \return void
 *
 */
void showAlquiler(eAlquiler alquiler, int showTitles);


/** \brief realiza una carga de eAlquiler en un arreglo dado, utilizando datos de datawarehouse
 *
 * \param alquilerArray[] eAlquiler arreglo de almuerzos
 * \param sizeA int tamaño del arreglo
 * \param id int* id inicial autoincremental
 * \param clientes eCliente[] arreglo de empleados para los id
 * \param juegos eJuego[] arreglo de juegos para los id
 * \return int 0 si hubo error 1 si pudo mostrarlos
 *
 */
int hardcodeAlquileres(eAlquiler alquilerArray[], int sizeA, int* id, eCliente clientes[], eJuego juegos[]);

#endif // ALQUILER_H_INCLUDED
