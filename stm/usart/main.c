#include "usart.h"
#include <stm32f4xx_usart.h>

int main(void)
{
    initUSART1();    
    putCharSerial('Y');
    char* myStr = "o Dawg! \r\n";
    
    putStrSerial(myStr);
    
    return 0; 
}
