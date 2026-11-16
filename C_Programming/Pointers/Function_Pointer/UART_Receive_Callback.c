Concept:
uart_receive() simulates UART data reception.
uart_callback() processes the received character.
The receiving function calls the callback after receiving data.
In a real UART driver, the callback would be invoked when the hardware reports a reception event, rather than immediately after assigning a sample character





#include <stdio.h>

void uart_callback(char data)
{
    printf("Received Data = %c\n", data);
}

void uart_receive(void (*callback)(char))
{
    char data = 'A';

    printf("UART Receiving...\n");

    callback(data);
}

int main(void)
{
    uart_receive(uart_callback);

    return 0;
}