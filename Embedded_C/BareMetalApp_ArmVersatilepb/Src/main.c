#include "../Header/Uart.h"

char_t Str[] = "Learn-In-Depth: Mohamed Hosny";

int main(void)
{
    Uart_Send(Str);
    return 0;
}
