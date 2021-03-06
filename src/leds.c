/*=====[leds.c]===============================================================
 * Fernando Andres Prokopiuk <fernandoprokopiuk@gmail.com>
 * Version: 1.0
 * Fecha de creacion: 24/11/2021
 */

/*=====[Inclusion de su propia cabecera]=====================================*/

#include "leds.h"

/*=====[Inclusiones de dependencias de funciones]============================*/

#include "errores.h"

/*=====[Macros de definición de constantes privadas]=========================*/

#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON 0xFFFF
#define LED_OFFSET 1
#define LED_TO_MASK(x) (LED_ON_STATE << (x - LED_OFFSET))
#define FIRST_LED 1
#define LAST_LED 16
#define ERROR_LED_NUMBER "Número de led invalido"
#define ASSERT_LED_IS_VALID(led, error)                                \
	if (!ledsRange(led))                                               \
	{                                                                  \
		RegistrarMensaje(0, __FUNCTION__, __LINE__, ERROR_LED_NUMBER); \
		return error;                                                  \
	}

/*=====[Definiciones de variables globales privadas]=========================*/

static uint16_t *puerto; //Se declara variable global estática.

/*=====[Prototipos de funciones privadas]====================================*/

static bool ledsRange(int led);

/*=====[Implementaciones de funciones publicas]==============================*/

void ledsConfig(uint16_t *direccion)
{
	puerto = direccion;		//Se guarda en variable global la dirección de puerto recibida
	*puerto = ALL_LEDS_OFF; //Retorno harcodeado 0x0000 para que test pase.
}

void ledsOn(int led)
{
	ASSERT_LED_IS_VALID(led, );
	*puerto |= LED_TO_MASK(led);
}

void ledsOff(int led)
{
	ASSERT_LED_IS_VALID(led, );
	*puerto &= ~LED_TO_MASK(led);
}

void ledsAllOn(void)
{
	*puerto = ALL_LEDS_ON;
}

void ledsAllOff(void)
{
	*puerto = ALL_LEDS_OFF;
}

int ledsState(int led)
{
	ASSERT_LED_IS_VALID(led, ERROR_LED_RANGE);

	//AND de *puerto con led bit, y luego corrimiento a la derecha de led bit - 1
	return (*puerto & LED_TO_MASK(led)) >> (led - LED_OFFSET);
}

/*=====[Implementaciones de funciones privadas]==============================*/

static bool ledsRange(int led)
{
	if ((led >= FIRST_LED) && (led <= LAST_LED))
	{
		return true;
	}
	else
	{
		return false;
	}
}