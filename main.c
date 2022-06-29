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
#include "digital.h"
#include <stdint.h>
#include <stdio.h>
#include "delay.h"
#include "mcp23s17.h"

int main(void) {
	SystemInit();
    delay_init();
	mcp23S17_init();

    mcp23S17_configura_pino(MCP_PIN_A0, INPUT);
	mcp23S17_configura_pino(MCP_PIN_A1, INPUT);
	mcp23S17_configura_pino(MCP_PIN_A2, INPUT);
	mcp23S17_configura_pino(MCP_PIN_A3, INPUT);
	mcp23S17_configura_pino(MCP_PIN_A4, INPUT);
	mcp23S17_configura_pino(MCP_PIN_A5, INPUT);
	mcp23S17_configura_pino(MCP_PIN_A6, INPUT);
	mcp23S17_configura_pino(MCP_PIN_A7, INPUT);

    mcp23S17_configura_pino(MCP_PIN_B0 , OUTPUT);
	mcp23S17_configura_pino(MCP_PIN_B1 , OUTPUT);
	mcp23S17_configura_pino(MCP_PIN_B2 , OUTPUT);
	mcp23S17_configura_pino(MCP_PIN_B3 , OUTPUT);
	mcp23S17_configura_pino(MCP_PIN_B4 , OUTPUT);
	mcp23S17_configura_pino(MCP_PIN_B5 , OUTPUT);
	mcp23S17_configura_pino(MCP_PIN_B6 , OUTPUT);
	mcp23S17_configura_pino(MCP_PIN_B7 , OUTPUT);
	
	while(1) {
		mcp23S17_escreve_pino(MCP_PIN_B0, HIGH);
		delay_ms(1000);
		mcp23S17_escreve_pino(MCP_PIN_B0, LOW);
		delay_ms(1000);
		if (mcp23S17_le_pino(MCP_PIN_A0) == HIGH) {
			printf("Botao em VCC\n");
		} else {
			printf("Botao em GND\n");
		}
	}
	
	return 0;
}