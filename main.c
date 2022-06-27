/*
	Sistemas Digitais Embarcados - UFSC 2022.1
	Trabalho 1: Expansor de I/O
	Igor Enrick e Leonardo Costa
	
	Para Compilar: make
	Para Gravar na Placa (usando o bootloader): lpc21isp -control -bin main.bin /dev/ttyUSB0 115200 12000
	Para gravar na placa (usando o JTAG): openocd -f lpc1768.cfg
	Abrir outro shell: telnet localhost 4444 > reset halt > flash write_image erase main.bin 0x0 bin

	Funções:
	mcp23S17_init();
	mcp23S17_configura_pino(MCP_PIN_X, INPUT ou OUTPUT);
	mcp23S17_escreve_pino(MCP_PIN_X, HIGH ou LOW);
	mcp23S17_le_pino(MCP_PIN_X);
*/

#include "LPC17xx.h"
#include <stdbool.h>

bool mcp23S17_init();
bool mcp23S17_configura_pino(uint8_t pin, uint8_t mode);
bool mcp23S17_escreve_pino(uint8_t pin, uint8_t value);
uint8_t mcp23S17_le_pino(uint8_t pin);

int main(void) {
	SystemInit();

	while(1) {}
	
	return 0;
}

bool mcp23S17_init() {

}

bool mcp23S17_configura_pino(uint8_t pin, uint8_t mode) {

}

bool mcp23S17_escreve_pino(uint8_t pin, uint8_t value) {

}

uint8_t mcp23S17_le_pino(uint8_t pin) {
	
}