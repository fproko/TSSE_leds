/*
 * Test 8: revisar limites de los parametros.
 * Test 9: revisar parámetros fuera de los limites.
 */
#include "unity.h"
#include "leds.h"

#define LED_2 2
#define LED_3 3
#define LED_5 5
#define LED_6 6
#define LED_BIT(x) (1 << (x - 1))
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON 0xFFFF

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
	ledsOn(LED_3);
	TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED_3), puertoVirtual); //puertoVirtual debe quedar en 0x0004.
}

/* Test 3: se puede apagar un LED individual. */
void test_apagar_un_led(void)
{
	ledsOn(LED_3); //Se prende un led para iniciar y luego se lo apaga.
	ledsOff(LED_3);
	TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, puertoVirtual);
}

/* Test 4: se pueden prender y apagar múltiples LED’s. */
void test_prender_y_apagar_multiples_leds(void)
{
	ledsOn(LED_2);
	ledsOn(LED_3);
	ledsOn(LED_6);
	ledsOff(LED_3);
	TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED_2) + LED_BIT(LED_6), puertoVirtual);
}

/* Test 5: se pueden prender todos los LEDs de una vez. */
void test_prender_todos_los_led(void)
{
	ledsAllOn();
	TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_ON, puertoVirtual);
}

/* Test 6: se pueden apagar todos los LEDs de una vez. */
void test_apagar_todos_los_led(void)
{
	ledsAllOn();
	ledsAllOff();
	TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, puertoVirtual);
}

/* Test 7: se puede consultar el estado de un LED. */
void test_estado_de_led(void)
{
	ledsOn(LED_5); //Se prende un led para verificar su estado.
	TEST_ASSERT_EQUAL(LED_ON_STATE, ledsState(LED_5));

	ledsOff(LED_5); //Se apaga el mismo led para verificar su estado.
	TEST_ASSERT_EQUAL(LED_OFF_STATE, ledsState(LED_5));
}