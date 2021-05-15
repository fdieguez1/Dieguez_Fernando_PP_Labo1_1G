#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLIENT_LENGTH 51
#define MAX_PHONE_LENGTH 21
#include "date.h"
#include "categoria.h"

typedef struct
{
    int codigo;
    char nombre[MAX_CLIENT_LENGTH];
    char apellido[MAX_CLIENT_LENGTH];
    char telefono[MAX_PHONE_LENGTH];
    int isEmpty;
    char sex;
} eCliente;

/** \brief inicializa el arreglo de clientes cargandolos como vacios
 *
 * \param clientes[] eCliente arreglo de clientes
 * \param sizeCLT int tama�o del arreglo
 * \return int devuelve 1 si pudo inicializar, 0 si no pudo
 *
 */
int initializeClientes(eCliente clientes[], int sizeCLT);

/** \brief busca un lugar en el arreglo para la carga de un cliente
 *
 * \param clientes[] eCliente arreglo de clientes
 * \param sizeCLT int tama�o del arreglo
 * \return int devuelve -1 si hubo error o 0/sizeCLT representando el indice donde se encontro un lugar.
 *
 */
int findPlaceInClienteArray(eCliente clientes[], int sizeCLT );

/** \brief pide datos y carga un cliente en el indice indicado
 *
 * \param clientes[] eCliente arreglo de clientes
 * \param index int posicion en el arreglo para el nuevo cliente
 * \param newId int nuevo id a ser asignado a la alta, direccion en memoria para autoincrementar
 * \return int devuelve 0 si no logro realizar la carga, 1 si lo logro
 *
 */
int addCliente(eCliente clientes[], int index, int *newId);

/** \brief muestra la lista de clientes con titulos para los campos
 *
 * \param clientes[] eCliente arreglo de clientes
 * \return void
 * \param sizeCLT int tama�o de arreglo
 *
 */
void showClientes(eCliente clientes[], int sizeCLT);


/** \brief muestra un cliente con opcion a mostrar titulos para los campos
 *
 * \param cliente eCliente
 * \param showTitles int
 * \return void
 *
 */
void showCliente(eCliente cliente, int showTitles);


/** \brief realiza una carga de eCliente en un arreglo dado, utilizando datos de datawarehouse
 *
 * \param clienteArray[] eCliente arreglo de clientes
 * \param sizeCLT int tama�o del arreglo
 * \param id int* id inicial autoincremental
 * \return int 0 si hubo error 1 si pudo mostrarlos
 *
 */
int hardcodeClientes(eCliente clienteArray[], int sizeCLT, int* id);

/** \brief editado de cliente por id
 *
 * \param clientes[] eCliente arreglo de clientes
 * \param sizeCLT int tama�o del arreglo del clientes
 * \param id int id del cliente
 * \param resultingCliente eCliente* clienteresultante
 * \return int 1 si logro la edicion, 0 si hubo error
 *
 */
int editClienteById(eCliente clientes[], int sizeCLT,int id, eCliente *resultingCliente, eCategoria categorias[], int sizeS);
/** \brief baja logica de un cliente
 *
 * \param clientes[] eCliente arreglo de clientes
 * \param sizeCLT int tama�o del arreglo
 * \param id int id buscado
 * \param resultingCliente eCliente* cliente resultante
 * \return int 1 si logro la baja, 0 si no lo logro
 *
 */
int deleteClienteById(eCliente clientes[], int sizeCLT,int id, eCliente *resultingCliente);

/** \brief busca un cliente en un arreglo de clientes pasando su id de legajo
 *
 * \param clientes[] eCliente arreglo de clientes
 * \param sizeCLT int tama�o del arreglo
 * \param id int id buscado
 * \param resultingCliente eCliente* resultado de la busqueda
 * \return int -1 si hubo error, 0 si no lo encontro, 1 si logro encontrarlo
 *
 */
int findClienteById(eCliente clientes[], int sizeCLT,int id, eCliente *resultingCliente);

/** \brief orderna por nombre
 *
 * \param clientes[] eCliente eCliente arreglo de clientes
 * \param sizeCLT int tama�o del arreglo
 * \param descending int si es 1 entonces el ordenamiento es descendiente, sino ascendente
 * \return int
 *
 */
int orderByFullName(eCliente clientes[], int sizeCLT, int descending);

/** \brief muestra los clientees y le pide al usuario que ingrese un cliente
 *
 * \param resultingId int* puntero para guardar el resultado
 * \param clientes[] eCliente arreglo de clientees
 * \param sizeS int tama�o del arreglo
 * \return int devuelve 1 si encontro el cliente 0 si no lo encontro
 *
 */
int getClienteId(int *resultingId, eCliente clientes[], int sizeCLT);

/** \brief devuelve el cliente pasando un id
 *
 * \param clientes eCliente arreglo de clientes
 * \param sizeCLT int tama�o del arreglo
 * \param id int id del cliente
 * \return eCliente devuelve la estructura del cliente
 *
 */
int getClienteById(eCliente clientes[], int sizeCLT,int id, eCliente* resultingCliente);
#endif // CLIENTE_H_INCLUDED
