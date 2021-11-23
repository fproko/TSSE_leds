/*
 * Test 4: se pueden prender y apagar múltiples LED’s.
 * Test 5: se pueden prender todos los LEDs de una vez.
 * Test 6: se pueden apagar todos los LEDs de una vez.
 * Test 7: se puede consultar el estado de un LED.
 * Test 8: revisar limites de los parametros.
 * Test 9: revisar parámetros fuera de los limites.
 */
#include "unity.h"
#include "leds.h"

#define LED 3
#define LED_BIT(x) (1 << (x - 1))
#define ALL_LEDS_OFF 0x0000

static uint16_t puertoVirtual;

/* Seteo de precondiciones globales para todas las pruebas */
void setUp()
{
	ledsConfig(&puertoVirtual); //Se llama a ledsConfig antes de cada prueba.
}

/* Test 1: después de la inicialización todos los LEDs deben quedar apagados. */
void test_todos_los_leds_inician_apagados(void)
{
	uint16_t puertoVirtual = 0xFFFF; //Variable local que suplanta el puerto.
	ledsConfig(&puertoVirtual);
	TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual); //puertoVirtual debe quedar en 0.
}

/* Test 2: se puede prender un LED individual. */
void test_prender_un_led(void)
{
	ledsOn(LED);
	TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED), puertoVirtual); //puertoVirtual debe quedar en 0x0004.
}

/* Test 3: se puede apagar un LED individual. */
void test_apagar_un_led(void)
{
	ledsOn(LED); //Se prende para iniciar y luego se lo apaga.
	ledsOff(LED);
	TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, puertoVirtual);
}