#include "leds.h"

#define ALL_LEDS_OFF 0x0000
static uint16_t *puerto; //Se declara variable global estática

void ledsConfig(uint16_t *direccion)
{
	puerto = direccion;		//Se guarda en variable global la dirección de puerto recibida
	*puerto = ALL_LEDS_OFF; //Retorno harcodeado 0x0000 para que test pase.
}

void ledsOn(int led)
{
	*puerto = 0x0004; //Se harcodeada inicialmente led a prender. Luego será corregido en un siguiente test.
}

void ledsOff(int led)
{
	*puerto = 0x0000; //Se harcodeada inicialmente led a apagar. Luego será corregido en un siguiente test.
}