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

void _le(char end) {
	/*
char MCP23S17::_read(char address)                         
    {
        _nCs = 0;
        _spi.write(_readopcode);
        _spi.write(address);
        char response = _spi.write(0xFF);                      // 0xFF data to get response
        _nCs = 1;
        return response;
    }
*/
}

void _escreve(char end, int dado) {
	spi_write(1);
	spi_write(end);
	spi_write(dado);
	/*
                                    
    void MCP23S17::_write(char address, char data)             
    {
        _nCs = 0;
        _spi.write(_writeopcode);
        _spi.write(address);
        _spi.write(data);
        _nCs = 1;
    }
*/
}

bool mcp23S17_init() {
	spi_configura(PIN_7, PIN_1, PIN_2, PIN_8);
	_escreve();
/*
void MCP23S17::_initialization()
    {
        _write(IOCON_ADDR, 0x2a); // 0x2a setup af control register (BANK = 0, MIRROR = 0, SEQOP = 1, DISSLW = 0, HAEN = 1, ODR = 0, INTPOL = 1, NC = 0)
        _nCs = 1; 
    }

	void MCP23S17::_init() {
    _write(IOCON, (IOCON_BYTE_MODE | IOCON_HAEN )); // Hardware addressing on, operations toggle between A and B registers
}
*/
}
 
    
bool mcp23S17_configura_pino(uint8_t pin, uint8_t mode) {
	/*

	void MCP23S17::bit(char reg_address, int bitnumber, bool high_low)
    {
        char i; 
        
        if(bitnumber >= 1 || bitnumber <= 8)
        {
            if(high_low == 1)
            {
                i = _read(reg_address); 
                i = i | (0x01 << (bitnumber-1));
                _write(reg_address, i);
            }
            if(high_low == 0)
            {
                i = _read(reg_address);
                i = i & ~(0x01 << (bitnumber-1));
                _write(reg_address, i);    
            } 
        }
    }

	*/

}

bool mcp23S17_escreve_pino(uint8_t pin, uint8_t value) {
	/*
	void MCP23S17::write(char reg_address, char data)
    {
        _write(reg_address, data);    
    }*/

}

uint8_t mcp23S17_le_pino(uint8_t pin) {
	/*

	char MCP23S17::read(char reg_address)
    {
        return _read(reg_address);    
    }
	*/
}