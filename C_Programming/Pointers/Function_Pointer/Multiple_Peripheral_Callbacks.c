Concept: One common event handler executes different functions depending on which callback is passed.




#include <stdio.h>

void uart_callback(void)
{
    printf("UART Data Received\n");
}

void spi_callback(void)
{
    printf("SPI Transfer Completed\n");
}

void adc_callback(void)
{
    printf("ADC Conversion Completed\n");
}

void event_handler(int event, void (*callback)(void))
{
    printf("Event %d Occurred\n", event);

    callback();
}

int main(void)
{
    event_handler(1, uart_callback);

    event_handler(2, spi_callback);

    event_handler(3, adc_callback);

    return 0;
}