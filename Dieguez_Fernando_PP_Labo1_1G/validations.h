#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

/** \brief valida que un entero se encuentre dentro de un rango de enteros
 *
 * \param value int valor a evaluar
 * \param minVal int valor minimo
 * \param MaxVal int valor maximo
 * \param includingMinMax int 0 para false, 1 para true, incluye(false) o excluye(true) a los maximos y minimos en la validacion de rango
 * \return int devuelve 0 si es false, 1 si es true
 *
 */
int validateInRange(int value, int minVal, int MaxVal, int includingMinMax);

/** \brief valida que un flotantes se encuentre dentro de un rango de flotantes
 *
 * \param value float valor a evaluar
 * \param minVal float valor minimo
 * \param MaxVal float valor maximo
 * \param includingMinMax int 0 para false, 1 para true, incluye(false) o excluye(true) a los maximos y minimos en la validacion de rango
 * \return int devuelve 0 si es false, 1 si es true
 *
 */
int validateInRangeFloat(float value, float minVal, float MaxVal, int includingMinMax);

#endif // VALIDATIONS_H_INCLUDED
