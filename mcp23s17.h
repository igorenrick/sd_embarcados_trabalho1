/*
	Sistemas Digitais Embarcados - UFSC 2022.1
	Trabalho 1: Expansor de I/O
	Igor Enrick e Leonardo Coelho
	
	Arquivo: mcp23s17.h (Cabeçalho das funções).

	Funções:
	mcp23S17_init();
	mcp23S17_configura_pino(MCP_PIN_X, INPUT ou OUTPUT);
	mcp23S17_escreve_pino(MCP_PIN_X, HIGH ou LOW);
	mcp23S17_le_pino(MCP_PIN_X, HIGH ou LOW);
*/

#ifndef _mcp23s17_
#define _mcp23s17_

#include <inttypes.h>
#include "spi.h"
#include "digital.h"
#include "delay.h"
#include "LPC17xx.h"

#define OPCODE_ESCRITA   0x40
#define OPCODE_LEITURA   0X41
#define IODIRA    		 0x00 
#define IODIRB    		 0x10
#define GPPUA    		  0x0C //pull up
#define GPPUB     		 0x16 //pull up
#define GPIOA     		 0x12 
#define GPIOB     		 0x13

#define MCP_PIN_A0 0
#define MCP_PIN_A1 1
#define MCP_PIN_A2 2
#define MCP_PIN_A3 3
#define MCP_PIN_A4 4
#define MCP_PIN_A5 5
#define MCP_PIN_A6 6
#define MCP_PIN_A7 7

#define MCP_PIN_B0 0
#define MCP_PIN_B1 1
#define MCP_PIN_B2 2
#define MCP_PIN_B3 3
#define MCP_PIN_B4 4
#define MCP_PIN_B5 5
#define MCP_PIN_B6 6
#define MCP_PIN_B7 7

#define WRITE 0
#define READ 1

void mcp23S17_init();
void mcp23S17_configura_pino(uint8_t pin, uint8_t mode);
void mcp23S17_escreve_pino(uint8_t pin, uint8_t value);
uint8_t mcp23S17_le_pino(uint8_t pin);

#endif