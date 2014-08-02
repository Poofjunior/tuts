// usart.c
// Joshua Vasquez
// August 2, 2014
//
// Source Code adapted from 
// http://amarkham.com/blog/wp-content/uploads/2012/04/main4.c
// and ST's default base code provided on the ST website.
// (You don't want to redo all of ST's hard work yourself...)

#include "usart.h"

/******************************************************************************
******************************************************************************/
void initUSART1(void){
    // Enable clocks for gpio and usart peripherals. 
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    // Map USART1 to B6, B7
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);

    GPIO_InitTypeDef GPIO_InitStructure;
    
    // Configure GPIOB bank: enabled pins, clk src speed, pinMode.
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    
    // Select Push-Pull mode.
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    // USART line is high by default.
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    USART_InitTypeDef USART_InitStructure;
    // InitUSART: 115200, 8bit wordlen, 1 stop bit, no parity, no hflow ctrl.
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = 
        USART_HardwareFlowControl_None;

    // Enable both transmit and receive.
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    // Apply configuration.
    USART_Init(USART1, &USART_InitStructure);   

    // Enable USART.
    USART_Cmd(USART1, ENABLE);
}


/******************************************************************************
******************************************************************************/
void putCharSerial(char someChar)
{
    // Wait until TX-buffer-empty flag has been set before loading new char.
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    USART_SendData(USART1, someChar);
}


/******************************************************************************
******************************************************************************/
void putStrSerial(char* someStr)
{
    uint16_t i = 0;
    // Strings are terminated by the null character. Print until finding it.
    while (someStr[i] != '\0')
    {
        putCharSerial(someStr[i]);
        ++i;
    }
}
