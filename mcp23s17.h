/*
	Sistemas Digitais Embarcados - UFSC 2022.1
	Trabalho 1: Expansor de I/O
	Igor Enrick e Leonardo Coelho
	
	Arquivo: mcp23s17.h (Cabeçalho das funções).

	Funções:
	mcp23S17_init();
	mcp23S17_configura_pino(MCP_PIN_X, INPUT ou OUTPUT);
	mcp23S17_escreve_pino(MCP_PIN_X, HIGH ou LOW);
	mcp23S17_le_pino(MCP_PIN_X);
*/

#include "LPC17xx.h"
#include <stdbool.h>
#include "spi.h"
#include "digital.h"

void _le(char end);
void _escreve(char end, int dado);
bool mcp23S17_init();
bool mcp23S17_configura_pino(uint8_t pin, uint8_t mode);
bool mcp23S17_escreve_pino(uint8_t pin, uint8_t value);
uint8_t mcp23S17_le_pino(uint8_t pin);