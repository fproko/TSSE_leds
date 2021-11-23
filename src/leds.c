#include "leds.h"

#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON 0xFFFF
#define LED_ON_STATE 1
#define LED_OFFSET 1
#define LED_TO_MASK(x) (LED_ON_STATE << (x - LED_OFFSET))

static uint16_t *puerto; //Se declara variable global estática

void ledsConfig(uint16_t *direccion)
{
	puerto = direccion;		//Se guarda en variable global la dirección de puerto recibida
	*puerto = ALL_LEDS_OFF; //Retorno harcodeado 0x0000 para que test pase.
}

void ledsOn(int led)
{
	*puerto |= LED_TO_MASK(led);
}

void ledsOff(int led)
{
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