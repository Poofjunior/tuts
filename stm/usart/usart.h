// usart.h
// Joshua Vasquez
// August 2, 2014
//
#ifndef USART_H
#define USART_H
#include <stm32f4xx_usart.h>
#include <stm32f4xx_gpio.h>

/// Function Prototypes:

/**
 * \fn void initUSART(void)
 * \brief enables USART1 on PB6, PB7
 */
void initUSART1(void);

/**
 * \fn putCharSerial(char someChar)
 * \brief sends a character through the USART1 peripheral
 * \details this function is blocking. It waits until the TX buffer is empty
 *          before loading a subsequent character into the TX buffer.
 */
void putCharSerial( char someChar);

/**
 * \fn putStrSerial(char* someStr)
 * \brief sends a character array through the USART1 peripheral
 * \details Like, putCharSeraial, this function is blocking.
 */
void putStrSerial( char* someStr);

#endif // USART_H
