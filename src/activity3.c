/**
 * @file activity3.c
 * @author Meda Meghana (meghanameda862k@gmail.com)
 * @brief Modulate the width of pulse using temperature
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "activity3.h"
#include "activity2.h"

void InitTimer()
{
    TCCR1A |= (1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<WGM12)|(1<<CS11)|(1<<CS10);
    DDRB |=(1<<PB1);
}

void PWM(uint16_t temp)
{
    InitTimer();
    if(temp<=200){
            OCR1A = PWM_20_PERCENT;
            _delay_ms(200);
        }
        else if(temp>=210 && temp<=410){
             OCR1A = PWM_40_PERCENT;
            _delay_ms(200);
        }
        else if(temp>=411 && temp<=717){
             OCR1A = PWM_70_PERCENT;
            _delay_ms(200);
        }
        else if(temp>=718 && temp<=1024){
             OCR1A = PWM_90_PERCENT;
            _delay_ms(200);
        }
        else{
            OCR1A=0;
            _delay_ms(200);
        }

}
