#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"
#include "ui.h"

void showMenu()
{
    system("cls");//sacar para ver los hardcodeos, limpia los residuos de ejecuciones anteriores
    printf("\n--- Gestion ---\n\n");
    printf("1-Mostrar juegos\n");
    printf("2-Mostrar categorias\n");
    printf("3-Alta Cliente\n");
    printf("4-Modificacion Cliente\n");
    printf("5-Baja Cliente\n");
    printf("6-Listar Clientes\n");
    printf("7-Cargar alquileres\n");
    printf("8-Listar alquileres\n");
    printf("9-Salir\n");
}

void showError(char errorMsg[])
{
    printf("\n\nERROR\n%s\n", errorMsg);
}

int showAlert(char alertMsg[])
{
    int ret = 0;
    char input;
    printf("\n\nAVISO\n%s\n", alertMsg);
    printf("Si: S \t No: N \n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &input);
    if (input == 's' || input == 'S')
    {
        ret = 1;
    }
    return ret;
}

void showTitlesForJuegos(){
    printf("Codigo\t\tDescripcion\tImporte\tCategoria\n\n");
}
void showTitlesForClientes(){
    printf("Codigo\t\tNombre\t\t\tApellido\tTelefono\tSexo\n\n");
}
void showTitlesForCategorias(){
    printf("Id\t\tDescripcion\n\n");
}
void showTitlesForAlquileres(){
    printf("Id\tCliente\tJuego\tFecha\n\n");
}

void showEditOptions(){
    printf("--- Edicion de Cliente---\n\n");
    printf("1-Editar nombre\n");
    printf("2-Editar apellido\n");
    printf("3-Editar telefono\n");
}
