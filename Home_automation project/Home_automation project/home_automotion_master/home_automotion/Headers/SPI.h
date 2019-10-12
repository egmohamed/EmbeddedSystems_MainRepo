#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
typedef unsigned short u16;
typedef unsigned char u8;
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7
void SPI_vMasterInit();
void SPI_vSlaveInit();
void SPI_vMasterWrite(u8 data);
u8 SPI_u8SlaveRead();
#endif