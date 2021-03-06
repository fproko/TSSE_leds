/*=====[leds.h]===============================================================
 * Fernando Andres Prokopiuk <fernandoprokopiuk@gmail.com>
 * Version: 1.0
 * Fecha de creacion: 24/11/2021
 */

/*=====[Evitar inclusion multiple comienzo]==================================*/

#ifndef _LEDS_H_
#define _LEDS_H_

/*=====[Inclusiones de dependencias de funciones publicas]===================*/

#include <stdint.h>
#include <stdbool.h>

/*=====[Macros de definición de constantes publicas]=========================*/

#define LED_ON_STATE 1
#define LED_OFF_STATE 0
#define ERROR_LED_RANGE -1

/*=====[Prototipos de funciones publicas]====================================*/

/**
 * @brief Inicializa los leds.
 * 
 * @param puerto Puntero a dirección de memoria donde están mapeados los leds.
 */
void ledsConfig(uint16_t *puerto);

/**
 * @brief Enciende un led.
 * 
 * @param led Led a encender.
 */
void ledsOn(int led);

/**
 * @brief Apaga un led.
 * 
 * @param led Led a apagar.
 */
void ledsOff(int led);

/**
 * @brief Enciende todos los leds.
 * 
 */
void ledsAllOn(void);

/**
 * @brief Apaga todos los leds.
 * 
 */
void ledsAllOff(void);

/**
 * @brief Consulta el estado de un led.
 * 
 * @param led Led que se desea saber el estado.
 * @return int  1: LED_ON_STATE.
 * @return int  0: LED_OFF_STATE.
 * @return int -1: ERROR_LED_RANGE.
 */
int ledsState(int led);

/*=====[Evitar inclusion multiple fin]=======================================*/

#endif /* _LEDS_H_ */
