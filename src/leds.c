#include "leds.h"
#include "errores.h"

#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON 0xFFFF
#define LED_ON_STATE 1
#define LED_OFFSET 1
#define LED_TO_MASK(x) (LED_ON_STATE << (x - LED_OFFSET))
#define FIRST_LED 1
#define LAST_LED 16

static uint16_t *puerto; //Se declara variable global estática
static bool ledsRange(int led);

void ledsConfig(uint16_t *direccion)
{
	puerto = direccion;		//Se guarda en variable global la dirección de puerto recibida
	*puerto = ALL_LEDS_OFF; //Retorno harcodeado 0x0000 para que test pase.
}

void ledsOn(int led)
{
	if (ledsRange(led))
	{
		*puerto |= LED_TO_MASK(led);
	}
	else
	{
		RegistrarMensaje(0, __FUNCTION__, __LINE__, "Número de led invalido");
	}
}

void ledsOff(int led)
{
	if (ledsRange(led))
	{
		*puerto &= ~LED_TO_MASK(led);
	}
	else
	{
		RegistrarMensaje(0, __FUNCTION__, __LINE__, "Número de led invalido");
	}
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
	if (ledsRange(led))
	{
		//AND de *puerto con led bit, y luego corrimiento a la derecha de led bit - 1
		return (*puerto & LED_TO_MASK(led)) >> (led - LED_OFFSET);
	}
	else
	{
		RegistrarMensaje(0, __FUNCTION__, __LINE__, "Número de led invalido");
		return -1;
	}
}

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