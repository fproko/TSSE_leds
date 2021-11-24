/*=====[errores.h]===============================================================
 * Fernando Andres Prokopiuk <fernandoprokopiuk@gmail.com>
 * Version: 1.0
 * Fecha de creacion: 24/11/2021
 */

/*=====[Evitar inclusion multiple comienzo]==================================*/

#ifndef _ERRORES_H_
#define _ERRORES_H_

/*=====[Prototipos de funciones publicas]====================================*/

void RegistrarMensaje(int gravedad, const char *funcion, int linea, const char *mensaje);

/*=====[Evitar inclusion multiple fin]=======================================*/

#endif /* _ERRORES_H_ */
