#include "../Header/Uart.h"

#define UART0DR *((vuint32*)(0x101f1000))

void Uart_Send(char_t* Uart_tx_Str)
{
    while(*Uart_tx_Str != '\0')
    {
        UART0DR = (uint32)(*Uart_tx_Str);
        Uart_tx_Str++;
    }
}
