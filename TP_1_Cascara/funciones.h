#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief muestra el menu de opciones.
 *
 * \param parametro A para mostrar en el menu una vez ingresado el punto 1.
 * \param parametro B para mostrar en el menu una vez ingresado el punto 2.
 * \return la opcion elegida.
 *
 */
int menu(int a,int b);
/** \brief permite ingresar un numero por el usuario.
 *
 * \param orden a realizar.
 * \return el numero ingresado.
 *
 */
int ingresarNumero (char texto[]);
/** \brief permite ingresar un nuevo numero.
 *
 * \param el numero a cambiar.
 * \param orden a realizar
 * \return el nuevo numero ingresado.
 *
 */
int funIngresarNuevo(int b,char texto[]);
/** \brief permite sumar dos numeros.
 *
 * \param primer numero a sumar.
 * \param segundo numero a sumar.
 *
 */
void funSumar(int a,int b);
/** \brief permite restar dos numeros.
 *
 * \param primer numero a restar.
 * \param segundo numero a restar.
 *
 */
void restar(int a,int b);
/** \brief permite dividir dos numeros
 *
 * \param dividendo.
 * \param divisor.
 *
 */
void funDividir(int a,int b);
/** \brief permite multiplicar dos numeros.
 *
 * \param primer numero a multiplicar.
 * \param segundo numero a multiplicar.
 *
 */
void funMultiplicacion (int a,int b);
/** \brief permite calcular el factoreal de un numero.
 *
 * \param numero a sacar su factorial.
 *
 */
void funFactorial (int a);
/** \brief permite realizar todas las operaciones de la calculadora.
 *
 * \param primer numero necesario para realizar las operaciones.
 * \param segundo numero necesario para realizar las operaciones.
 *
 */
void todasLasOperaciones(int a,int b);


#endif // FUNCIONES_H_INCLUDED
