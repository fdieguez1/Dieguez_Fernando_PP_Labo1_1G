#include <stdio.h>
#include <stdlib.h>
#include "juego.h"
#include "ui.h"
#include "inputs.h"
#include "categoria.h"
#include "cliente.h"
#include "alquiler.h"

#define SIZE_J 5
#define SIZE_C 5
#define SIZE_CLT 5
#define SIZE_A 5

int main()
{
    int juegosId = 1;
    int categoriasId = 1;
    int alquileresId = 1;
    int clientesId = 1;
    int continuar = 1;
    int opcion;
    int opcionOk;
    int confirm;
    int place;
    int id;
    int idOk;

    eJuego juegos[SIZE_J];
    eCategoria categorias[SIZE_C];
    eCliente clientes[SIZE_CLT];
    eCliente selectedCliente;
    eAlquiler alquileres[SIZE_A];

    hardcodeJuegos(juegos, SIZE_J, &juegosId, categoriasId);
    hardcodeCategorias(categorias, SIZE_C, &categoriasId);
    initializeClientes(clientes, SIZE_CLT);
    initializeAlquileres(alquileres,SIZE_A);

    while (continuar)
    {
        showMenu();
        opcionOk = utn_getNumero(&opcion,"Ingrese una opcion: ", "Error, opcion invalida ", 1,9,100);
        if (opcionOk)
        {
            system("cls");
            switch(opcion)
            {
            case 1: //MOSTRAR JUEGOS
                showJuegos(juegos, SIZE_J);
                break;
            case 2://MOSTRAR CATEGORIAS
                showCategorias(categorias, SIZE_C);
                break;
            case 3://Alta Cliente
                place = findPlaceInClienteArray(clientes, SIZE_CLT);
                if (place != -1)
                {
                    int addOk = addCliente(clientes, place, &clientesId);
                    if (addOk)
                    {
                        printf("Carga correcta de cliente correcta con id: %d \n", clientes[place].codigo);
                    }
                    else
                    {
                        showError("Fallo la carga de cliente");
                    }
                }
                else
                {
                    showError("No se encontro un lugar para la carga de cliente, verifique no estar superando el maximo de cargas");
                }
                break;
            case 4://Modificacion Cliente
                showClientes(clientes, SIZE_CLT);
                idOk = utn_getNumero(&id,"Ingrese el numero de empleado para la edicion", "Error al ingresar el numero", 1, 999999, 100);
                if (idOk)
                {
                    int editOk = editClienteById(clientes,SIZE_CLT,id, &selectedCliente,categorias, SIZE_C);
                    if (editOk)
                    {
                        printf("Edicion exitosa, id: %d\n", selectedCliente.codigo);
                    }
                    else
                    {
                        showError("Cliente no encontrado, revise el numero ingresado e intente nuevamente");
                    }
                }
                else
                {
                    showError("Demasiados intentos, abortando la operacion");
                }
                break;
            case 5://Baja Cliente
                showClientes(clientes, SIZE_CLT);
                idOk = utn_getNumero(&id,"Ingrese el numero de empleado para la baja", "Error al ingresar el numero", 1, 999999, 100);
                if (idOk)
                {
                    int deleteOk = deleteClienteById(clientes,SIZE_CLT,id, &selectedCliente);
                    if (deleteOk)
                    {
                        printf("Baja logica exitosa, id: %d\n", selectedCliente.codigo);
                    }
                    else
                    {
                        showError("Cliente no encontrado, revise el numero ingresado e intente nuevamente");
                    }
                }
                else
                {
                    showError("Demasiados intentos, abortando la operacion");
                }
                break;
            case 6://Listar Clientes por apellido y nombre
                orderByFullName(clientes,SIZE_CLT,0);
                showClientes(clientes, SIZE_CLT);
                break;
            case 7://Cargar alquileres
                place = findPlaceInAlquilerArray(alquileres, SIZE_A);
                if (place != -1)
                {
                    int addOk = addAlquiler(alquileres, place, &alquileresId, clientes, SIZE_C, juegos, SIZE_J);
                    if (addOk)
                    {
                        printf("Carga correcta de almuerzo correcta con id: %d \n", alquileres[place].id);
                    }
                    else
                    {
                        showError("Fallo la carga de almuerzo");
                    }
                }
                else
                {
                    showError("No se encontro un lugar para la carga de almuerzo, verifique no estar superando el maximo de cargas");
                }
                break;
            case 8:;//Listar alquileres
                showAlquileres(alquileres,SIZE_A);
                break;
            case 9://Salir
                confirm = showAlert("Esta seguro que desea salir?");
                if (confirm)
                {
                    continuar = 0;
                    printf("Programa finalizado\n");
                }
                break;
            }
        }
        else
        {
            showError("Demasiados intentos, cerrando programa");
            continuar = 0;
        }
        system("pause");
    }
    return 0;
}
