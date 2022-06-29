/*
	Sistemas Digitais Embarcados - UFSC 2022.1
	Trabalho 1: Expansor de I/O
	Igor Enrick e Leonardo Coelho

    Arquivo: mcp23s17.cpp (Implementa as funções para o CI).

	Funções:
	mcp23S17_init();
	mcp23S17_configura_pino(MCP_PIN_X, INPUT ou OUTPUT);
	mcp23S17_escreve_pino(MCP_PIN_X, HIGH ou LOW);
	mcp23S17_le_pino(MCP_PIN_X);
*/

#include "mcp23s17.h"

void mcp23S17_init() {
    spi_configura (PIN_4_28, PIN_3_25, PIN_3_26, PIN_4_29);

    uint8_t GPIOB_atual = 0x00;
    spi_desabilita();
    spi_write(OPCODE_ESCRITA);
    spi_write(IODIRB);
    spi_write(GPIOB_atual);
    spi_habilita();

    uint8_t IODIRB_atual = 0x00;
    spi_desabilita();
    spi_write(OPCODE_ESCRITA);
    spi_write(IODIRB);
    spi_write(IODIRB_atual);
    spi_habilita();

    uint8_t GPIOA_atual = 0xFF;
    spi_desabilita();
    spi_write(OPCODE_ESCRITA);
    spi_write(IODIRA);
    spi_write(GPIOA_atual);
    spi_habilita();

    uint8_t IODIRA_atual = 0x00;
    spi_desabilita();
    spi_write(OPCODE_ESCRITA);
    spi_write(IODIRA);
    spi_write(IODIRA_atual);
    spi_habilita();
    
    spi_desabilita();
    spi_write(OPCODE_ESCRITA);
    spi_write(GPPUB); //pull up
    spi_write(0xFF);
    spi_habilita();
}

void mcp23S17_configura_pino(uint8_t pin, uint8_t mode) {
    if(mode == 0x40) { //escrita
        if(pin > 7) {
            pin = get_pino_b(pin);
            uint8_t IODIRB_atual = 0xFF;
            spi_desabilita();
            spi_write(OPCODE_ESCRITA);
            spi_write(IODIRB);
            IODIRB_atual |= (1 << pin);
            spi_write(IODIRB_atual);
            spi_habilita();
        } else {
            uint8_t IODIRA_atual = 0x00;
            spi_desabilita();
            spi_write(OPCODE_ESCRITA);
            spi_write(IODIRA); 
            IODIRA_atual &= ~(1 << pin);
            spi_write(IODIRA_atual);
            spi_habilita();
        }
    }

    if(mode == 0X41) { //leitura
        if(pin > 7) {
            pin = get_pino_b(pin);
            uint8_t IODIRB_atual = 0xFF;
            spi_desabilita();
            spi_write(OPCODE_LEITURA);
            spi_write(IODIRB);
            IODIRB_atual |= (1 << pin);
            spi_write(IODIRB_atual);
            spi_habilita();
        } else {
            uint8_t IODIRA_atual = 0x00;
            spi_desabilita();
            spi_write(OPCODE_LEITURA);
            spi_write(IODIRA); 
            IODIRA_atual &= ~(1 << pin);
            spi_write(IODIRA_atual);
            spi_habilita();
        }
    }
}

void mcp23S17_escreve_pino(uint8_t pin, uint8_t value) {
    if(pin > 7) {
        pin = get_pino_b(pin);
        uint8_t GPIOB_atual = 0xFF;
        if (value == 1) {
            GPIOB_atual |= (1 << pin);
        } else if (value == 0) { 
            GPIOB_atual &= ~(1 << pin);
        }
        spi_desabilita();
        spi_write(OPCODE_ESCRITA);
        spi_write(GPIOB);
        uint8_t b = spi_write(GPIOB_atual);
        spi_habilita();
        return (uint8_t)0;
    } else {
        uint8_t GPIOA_atual = 0xFF;
        if (value == 1) {
            GPIOA_atual |= (1 << pin);
        } else if (value == 0) { 
            GPIOA_atual &= ~(1 << pin);
        }
        spi_desabilita();
        spi_write(OPCODE_ESCRITA);
        spi_write(GPIOA);
        uint8_t b = spi_write(GPIOA_atual);
        spi_habilita();
        return (uint8_t)0;
    }
}

uint8_t mcp23S17_le_pino(uint8_t pin) {
    if(pin > 7) {
        pin = get_pino_b(pin);
        uint8_t GPIOB_atual = 0x00;
        GPIOB_atual |= (1 << pin);
        
        spi_desabilita();
        spi_write(OPCODE_LEITURA);
        spi_write(GPIOB);
        uint8_t b = spi_write(GPIOB_atual);
        spi_habilita();
        return (b >> pin) & 1;
    } else {
        uint8_t GPIOA_atual = 0x00;
        GPIOA_atual |= (1 << pin);
        
        spi_desabilita();
        spi_write(OPCODE_LEITURA);
        spi_write(GPIOA);
        uint8_t b = spi_write(GPIOA_atual);
        spi_habilita();
        return (b >> pin) & 1;
    }
}

u_int8_t get_pino_b(uint8_t pin) {
    if(pin == 8) return 0;
    if(pin == 9) return 1;
    if(pin == 10) return 2;
    if(pin == 11) return 3;
    if(pin == 12) return 4;
    if(pin == 13) return 5;
    if(pin == 14) return 6;
    if(pin == 15) return 7;
}