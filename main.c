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
#include "mcp23s17.h"

int main(void) {
	SystemInit();

	mcp23S17_init();
    mcp23S17_configura_pino(MCP_PIN_15, INPUT);
    mcp23S17_configura_pino(MCP_PIN_0 , OUTPUT);
	
	while(1) {
		mcp23S17_escreve_pino(MCP_PIN_0, HIGH);
		delay_ms(1000);
		mcp23S17_escreve_pino(MCP_PIN_0, LOW);
		delay_ms(1000);
		if (mcp23S17_le_pino(MCP_PIN_15) == HIGH) {
			printf("Botao em VCC\n");
		} else {
			printf("Botao em GND\n");
		}
	}
	
	return 0;
}