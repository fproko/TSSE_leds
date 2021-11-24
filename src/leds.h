#include <stdint.h>
#include <stdbool.h>

void ledsConfig(uint16_t *puerto);
void ledsOn(int led);
void ledsOff(int led);
void ledsAllOn(void);
void ledsAllOff(void);
int ledsState(int led);
