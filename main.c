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
		botao_led();
	}
	
	return 0;
}

void botao_led() {
	if (mcp23S17_le_pino(MCP_PIN_A0) == HIGH) {
		printf("Botao A0 em VCC\n");
		mcp23S17_escreve_pino(MCP_PIN_B0, HIGH);
	} else {
		printf("Botao A0 em GND\n");
		mcp23S17_escreve_pino(MCP_PIN_B0, LOW);
	}

	if (mcp23S17_le_pino(MCP_PIN_A1) == HIGH) {
		printf("Botao A1 em VCC\n");
		mcp23S17_escreve_pino(MCP_PIN_B1, HIGH);
	} else {
		printf("Botao A1 em GND\n");
		mcp23S17_escreve_pino(MCP_PIN_B1, LOW);
	}

	if (mcp23S17_le_pino(MCP_PIN_A2) == HIGH) {
		printf("Botao A2 em VCC\n");
		mcp23S17_escreve_pino(MCP_PIN_B2, HIGH);
	} else {
		printf("Botao A2 em GND\n");
		mcp23S17_escreve_pino(MCP_PIN_B2, LOW);
	}

	if (mcp23S17_le_pino(MCP_PIN_A3) == HIGH) {
		printf("Botao A3 em VCC\n");
		mcp23S17_escreve_pino(MCP_PIN_B3, HIGH);
	} else {
		printf("Botao A3 em GND\n");
		mcp23S17_escreve_pino(MCP_PIN_B3, LOW);
	}

	if (mcp23S17_le_pino(MCP_PIN_A4) == HIGH) {
		printf("Botao A4 em VCC\n");
		mcp23S17_escreve_pino(MCP_PIN_B4, HIGH);
	} else {
		printf("Botao A4 em GND\n");
		mcp23S17_escreve_pino(MCP_PIN_B4, LOW);
	}

	if (mcp23S17_le_pino(MCP_PIN_A5) == HIGH) {
		printf("Botao A5 em VCC\n");
		mcp23S17_escreve_pino(MCP_PIN_B5, HIGH);
	} else {
		printf("Botao A5 em GND\n");
		mcp23S17_escreve_pino(MCP_PIN_B5, LOW);
	}

	if (mcp23S17_le_pino(MCP_PIN_A6) == HIGH) {
		printf("Botao A6 em VCC\n");
		mcp23S17_escreve_pino(MCP_PIN_B6, HIGH);
	} else {
		printf("Botao A6 em GND\n");
		mcp23S17_escreve_pino(MCP_PIN_B6, LOW);
	}

	if (mcp23S17_le_pino(MCP_PIN_A7) == HIGH) {
		printf("Botao A7 em VCC\n");
		mcp23S17_escreve_pino(MCP_PIN_B7, HIGH);
	} else {
		printf("Botao A7 em GND\n");
		mcp23S17_escreve_pino(MCP_PIN_B7, LOW);
	}
}