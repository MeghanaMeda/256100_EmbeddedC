#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

int main(void)
{
    uint16_t temp;
    
    while(1)
    {
        if(LED()==1) //Check if both the switches are pressed
        {
           
            TurnLED_ON();//Turn LED ON
            temp=GetADC(); //Get the ADC value
            PWM(temp); //PWM output based on temperature
		    USARTWrite(temp); //Print Temperature using USART protocol
            

        }
        else  //in all other cases
        {
            TurnLED_OFF();//Turn LED OFF
		    _delay_ms(200);
        }

    }
    return 0;
}
