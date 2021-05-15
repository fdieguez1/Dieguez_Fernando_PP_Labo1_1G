#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

/** \brief muestra un menu de opciones
 *
 * \return void
 *
 */
void showMenu();

/** \brief muestra un titulo de error y luego el mensaje proporcionado
 *
 * \param errorMsg[] char mensaje a mostrar
 * \return void
 *
 */
void showError(char errorMsg[]);

/** \brief muestra una alerta con opcion de confirmar o cancelar y devuelve la opcion elegida
 *
 * \param alertMsg[] char el mensaje a mostrar
 * \return int devuelve 1 si eligio confirmar, 0 si eligio cualquier otra cosa
 *
 */
int showAlert(char alertMsg[]);

/** \brief muestra titulos para el listado de empleados
 *
 * \return void
 *
 */
void showTitlesForEmployees();

/** \brief muestra titulos para el listado de sectores
 *
 * \return void
 *
 */
void showTitlesForSectors();

/** \brief muestra titulos para el listado de comidas
 *
 * \return void
 *
 */
void showTitlesForFoods();

/** \brief muestra titulos para el listado de almuerzos
 *
 * \return void
 *
 */
void showTitlesForLunchs();

/** \brief muestra opciones para la edicion de un empleado
 *
 * \return void
 *
 */

void showEditOptions();

/** \brief muestra opciones para el ordenamiento de empleados
 *
 * \return void
 *
 */
void showOrderOptions();

/** \brief muestra titulos para el listado de juegos
 *
 * \return void
 *
 */
void showTitlesForJuegos();

/** \brief muestra titulos para el listado de categorias
 *
 * \return void
 *
 */
void showTitlesForCategorias();

/** \brief muestra titulos para el listado de clientes
 *
 * \return void
 *
 */
void showTitlesForClientes();


/** \brief muestra titulos para el listado de alquileres
 *
 * \return void
 *
 */
void showTitlesForAlquileres();

#endif // UI_H_INCLUDED
