/**
 * @file activity1.c
 * @author Meda Meghana (meghanameda862k@gmail.com)
 * @brief Activity 1- Turning on LED based on occupancy and heater input
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "activity1.h"


void peripheral_init(void)
{	
	DDRB |= (1<<PB0); // set PB0=1 for LED
    DDRD &= ~(1<<PD0); //clear bit
    PORTD |= (1<<PD0); //set bit PD0 for SeatSwitch
    DDRD &= ~(1<<PD1); //clear bit
    PORTD |= (1<<PD1); //set bit PD0 for HeaterSwitch
}

void TurnLED_ON(){
    LED_PORT |= (1<<LED_PIN); 
}

void TurnLED_OFF(){
    LED_PORT &= ~(1<<LED_PIN);
}

int led_status=0;
int LED(void)
{
       peripheral_init();
        if(!(PIND&(1<<BUTTON_SENSOR )) && !(PIND&(1<<TEMP_SENSOR))) //both the switches are pressed
        { 
            led_status=1;
        }
	else if(!(PIND&(1<<BUTTON_SENSOR )) && (PIND&(1<<TEMP_SENSOR))) //button is pressed but temperature is not pressed
        { 
            led_status=0;
        }
	else if((PIND&(1<<BUTTON_SENSOR )) && !(PIND&(1<<TEMP_SENSOR))) //temperature is pressed but button sensor is not pressed
        { 
            led_status=0;
        }
	else if((PIND&(1<<BUTTON_SENSOR )) && (PIND&(1<<TEMP_SENSOR))) //both the switches are not pressed
        { 
            led_status=0;
        }
        else  //in all other cases
        {
            led_status=0;
        }
    return led_status;
}
