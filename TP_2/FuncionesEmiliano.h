#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    char nombre[20];
    int edad;
    long int dni;
    int estado;
}ePersona;

/** \brief Menu del programa con validacion.
 *
 * \return La opcion ingresada.
 *
 */
int menu();
/** \brief Valida si el usuario ingresa una o mas letras.
 *
 * \param Lo que ingresa el usuario.
 * \return 0 si no encuentra una letra 1 si encuentra.
 *
 */
int validarLetra(char opcion[]);
/** \brief Inicializa los campos de la estructura.
 *
 * \param La estructura a inicializar.
 * \param La cantidad de personas.
 * \return void
 *
 */
void inicializarStruct(ePersona persona[],int tam);
/** \brief Inicializa una sola persona.
 *
 * \param La estructura a inicializar
 * \param La ubicacion en donde inicializar los datos.
 * \return void
 *
 */
void inicializarPersona(ePersona persona[],int indice);
/** \brief Muestra todas las personas ingresadas.
 *
 * \param La estructura a mostrar.
 * \param La cantidad de personas.
 * \return void
 *
 */
void mostrarPersonas(ePersona persona[],int tam);
/** \brief Busca si hay espacio libre para ingresar mas datos.
 *
 * \param La estructura en donde buscar el espacio.
 * \param La cantidad de personas.
 * \return La ubicacion en donde esta libre.
 *
 */
int buscarLibre (ePersona persona[],int tam);
/** \brief Permite ingresar los datos de una persona.
 *
 * \param La estructura en donde ingresar los datos.
 * \param La cantidad de personas.
 * \return void
 *
 */
void alta(ePersona persona[],int tam);
/** \brief Permite validad la edad mediante un rango.
 *
 * \return La edad validada.
 *
 */
int edadConValidacion ();
/** \brief Permite eliminar una persona del sistema.
 *
 * \param La estructura en donde buscar la persona a eliminar.
 * \param La cantidad de personas.
 * \return void
 *
 */
void borrarPersona(ePersona persona[],int tam);
/** \brief Permite buscar una persona ya ingresada.
 *
 * \param La estructura en donde buscar la persona.
 * \param La cantidad de personas.
 * \return -1 si no encontro la persona, sino devulve la posicion en donde se encuentra.
 *
 */
int buscarPersona(ePersona persona[],int tam);
/** \brief Permite mostrar una sola persona.
 *
 * \param La estructura en donde se encuentra la persona.
 * \param La cantidad de personas.
 * \return void.
 *
 */
void mostrarPersona (ePersona persona[],int tam,int indice);
/** \brief Permite odenar alfabeticamente la lista de personas.
 *
 * \param La estructura en donde se encuentran las personas.
 * \param La cantidad de personas.
 * \return void.
 *
 */
void ordenarLista (ePersona persona[],int tam);
/** \brief Permite realizar un grafico segun las edades.
 *
 * \param La estructura en donde se encuentran los datos.
 * \param La cantidad de personas.
 * \return void
 *
 */
void graficoEdades(ePersona persona[],int tam);

#endif // FUNCIONES_H_INCLUDED
