/**
 * @file activity4.h
 * @author Meda Meghana (meghanameda862k@gmail.com)
 * @brief Header for USART
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ACTIVITY_4_H__
#define __ACTIVITY_4_H__

/**
 * Macro Definitions
 */
#define F_CPU 16000000UL /**< Clock Frequency of MCU is 16 MHz */
#define USART_BAUDRATE 9600 /**< Baud rate for serial communication  */
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) /**< Formula to calculate UBRR value */

/**
 * Include files
 */ 
#include <util/delay.h>
#include <avr/io.h>

/**
 * Function Definitions
 */

/**
 * @brief Setting Baud rate and Enabling Rx and Tx 
 * 
 */
void USARTInit();

/**
 * @brief Reading data
 * 
 * @return int The read data
 */
int USARTRead();

/**
 * @brief Writing data to view in serial monitor
 * 
 * @param[in] temp The ADC value
 */
void USARTWrite(uint16_t temp);

#endif /* __ACTIVITY_4_H__ */