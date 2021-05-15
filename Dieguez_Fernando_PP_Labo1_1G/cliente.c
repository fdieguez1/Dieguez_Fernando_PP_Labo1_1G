#include <ctype.h>
#include "datawarehouse.h"
#include "cliente.h"
#include "inputs.h"
#include "ui.h"
#include "categoria.h"

int initializeClientes(eCliente clientes[], int sizeCLT)
{
    int ret = 0;
    if (clientes != NULL && sizeCLT > 0)
    {
        for(int i = 0; i < sizeCLT; i++)
        {
            clientes[i].isEmpty = 1;
        }
        ret = 1;
    }
    return ret;
}

int findPlaceInClienteArray(eCliente clientes[], int sizeCLT )
{
    int ret = -1;
    if (clientes != NULL && sizeCLT > 0)
    {
        for(int i = 0; i < sizeCLT; i++)
        {
            if (clientes[i].isEmpty)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int addCliente(eCliente clientes[], int index, int *newId)
{
    int allOk = 0;
    char name[MAX_CLIENT_LENGTH];
    char lastname[MAX_CLIENT_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char sex;

    //Cargo ID
    clientes[index].codigo = *newId;
    //Pido el nombre
    int nameOk = askForString(name, "Ingrese un nombre: ", MAX_CLIENT_LENGTH);
    int lastnameOk = askForString(lastname, "Ingrese un apellido: ", MAX_CLIENT_LENGTH);
    int phoneOk = askForString(phone, "Ingrese un telefono: ", MAX_PHONE_LENGTH);
    //Pido el sexo
    int sexOk = askSex(&sex, "Ingrese un sexo m/f: ");

    if (nameOk && sexOk && lastnameOk && phoneOk )
    {
        clientes[index].codigo = *newId;
        strcpy(clientes[index].nombre, name);
        strcpy(clientes[index].apellido, lastname);
        strcpy(clientes[index].telefono, phone);
        clientes[index].isEmpty = 0;
        clientes[index].sex = sex;
        allOk = 1;
        (*newId)++;
    }
    else
    {
        showError("Error en uno o mas datos, abortando la carga de empleado");
    }
    return allOk;
}

void showClientes(eCliente clientes[],int sizeCLT)
{
    showTitlesForClientes();
    for(int i = 0; i < sizeCLT; i++)
    {
        if (!clientes[i].isEmpty)
        {
            showCliente(clientes[i], 0);
        }
    }
}
void showCliente(eCliente cliente, int showTitles)
{
    if (showTitles)
    {
        showTitlesForClientes();
    }
    printf("%3d\t%20s\t%20s\t",cliente.codigo, cliente.nombre, cliente.apellido);
    printf("%20s\t%c\n", cliente.telefono, cliente.sex);
}

/** \brief hardcodeo de empleados utilizando datawarehouse
 *
 * \param clienteArray[] eCliente
 * \param sizeCLT int
 * \param id int*
 * \return void
 *
 */
int hardcodeClientes(eCliente clienteArray[], int sizeCLT, int* id)
{
    int ret = 0;
    if (clienteArray != NULL && sizeCLT > 0 && id > 0)
    {
        ret = 1;
        for (int i =0; i < sizeCLT; i++)
        {
            clienteArray[i].codigo = *id;
            strcpy(clienteArray[i].nombre, names[i]);
            strcpy(clienteArray[i].apellido, lastnames[i]);
            strcpy(clienteArray[i].telefono, phones[i]);
            clienteArray[i].isEmpty = 0;
            clienteArray[i].sex = sexs[i];
            (*id)++;
        }
    }
    return ret;
}
int editClienteById(eCliente clientes[], int sizeCLT,int id, eCliente *resultingCliente, eCategoria categorias[], int sizeS)
{
    system("cls");
    int ret = -1;
    showEditOptions();

    char name[MAX_CLIENT_LENGTH];
    char lastname[MAX_CLIENT_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    int editOption;
    int nameOk;
    int lastnameOk;
    int phoneOk;


    int optionOk = utn_getNumero(&editOption, "Ingrese una opcion: ", "Error, opcion invalida", 1,6,100);
    if (optionOk)
    {
        if (clientes != NULL && sizeCLT > 0 && id > 0 && resultingCliente != NULL)
        {
            for(int i = 0; i < sizeCLT; i++)
            {
                int codigo = clientes[i].codigo;
                if (codigo == id)
                {
                    *resultingCliente = clientes[i];
                    if (!clientes[i].isEmpty)
                    {
                        switch(editOption)
                        {
                        case 1://Pido el nombre
                            nameOk = askForString(name, "Ingrese un nombre: ", MAX_CLIENT_LENGTH);
                            if (nameOk)
                            {
                                strcpy(clientes[i].nombre,name);
                            }
                            break;

                        case 2://Pido el apellido
                            lastnameOk= askForString(lastname, "Ingrese un apellido: ", MAX_CLIENT_LENGTH);
                            if (lastnameOk)
                            {
                                strcpy(clientes[i].apellido,lastname);
                            }
                            break;
                        case 3://Pido el telefono
                            phoneOk = askForString(phone, "Ingrese un telefono: ", MAX_PHONE_LENGTH);
                            if (phoneOk)
                            {
                                strcpy(clientes[i].telefono,phone);
                            }
                            break;
                        }
                        ret = 1;
                    }
                }
            }
        }
    }
    return ret;
}

int deleteClienteById(eCliente clientes[], int sizeCLT,int id, eCliente *resultingCliente)
{
    int ret = -1;
    if (clientes != NULL && sizeCLT > 0 && id > 0 && resultingCliente != NULL)
    {
        for(int i = 0; i < sizeCLT; i++)
        {
            int codigo = clientes[i].codigo;
            if (codigo == id)
            {
                *resultingCliente = clientes[i];
                if (!clientes[i].isEmpty)
                {
                    clientes[i].isEmpty = 1;
                    //Traer todos los alquileres relacionados a este cliente y hacen una eliminacion en cascada
                    ret = 1;
                }
                break;
            }
            ret = 0;
        }
    }
    return ret;
}

int findClienteById(eCliente clientes[], int sizeCLT,int id, eCliente *resultingCliente)
{
    int ret = -1;
    if (clientes != NULL && sizeCLT > 0 && id > 0)
    {
        for(int i = 0; i < sizeCLT; i++)
        {
            if (clientes[i].codigo == id)
            {
                *resultingCliente = clientes[i];
                ret = 1;
                break;
            }
            ret = 0;
        }
    }
    return ret;
}

int swapCliente(eCliente *clienteA, eCliente *clienteB)
{
    int ret = 0;
    if (clienteA != NULL && clienteB != NULL)
    {
        eCliente aux;
        aux = *clienteA;
        *clienteA = *clienteB;
        *clienteB = aux;
        ret = 1;
    }
    return ret;
}
int orderByFullName(eCliente clientes[], int sizeCLT, int descending)
{
    int ret = 0;
    if (clientes != NULL && sizeCLT > 0 && descending >= 0 && descending<= 1)
    {
        for(int i = 0; i < sizeCLT-1; i++)
        {
            for(int j = i+1; j < sizeCLT ; j++)
            {
                char nameA[MAX_CLIENT_LENGTH];
                strcpy(nameA,clientes[i].nombre);
                stringToLower(nameA);
                char nameB[MAX_CLIENT_LENGTH];
                strcpy(nameB,clientes[j].nombre);
                stringToLower(nameB);
                char lastnameA[MAX_CLIENT_LENGTH];
                strcpy(lastnameA,clientes[i].apellido);
                stringToLower(lastnameA);
                char lastnameB[MAX_CLIENT_LENGTH];
                strcpy(lastnameB,clientes[j].apellido);
                stringToLower(lastnameB);
                strcat(lastnameA, "");
                strcat(lastnameA, nameA);
                strcat(lastnameB, "");
                strcat(lastnameB, nameB);
                if (descending)
                {

                    if (strcmp(lastnameA,lastnameB) < 0)
                    {
                        swapCliente(&clientes[i],&clientes[j]);
                    }
                }
                else
                {
                    if (strcmp(lastnameA,lastnameB) > 0)
                    {
                        swapCliente(&clientes[i],&clientes[j]);
                    }
                }
            }
        }
        ret = 1;
    }
    return ret;
}


int getClienteId(int *resultingId, eCliente clientes[], int sizeCLT)
{
    int ret = 0;
    showClientes(clientes, sizeCLT);
    utn_getNumero(resultingId, "Ingrese el ID de empleado: ", "Error, empleado invalido. ", 1, 999, 10);
    for(int i = 0; i < sizeCLT; i++)
    {
        if (*resultingId == clientes[i].codigo)
        {
            ret = 1;
            break;
        }
    }
    while(ret != 1)
    {
        showError("Error, empleado invalido. ");
    }
    return ret;
}
