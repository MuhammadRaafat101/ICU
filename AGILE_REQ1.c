/*
 * ICU_ULTRASONIC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */







#include "EXINT.h"
#include "Timers.h"
#include"LCD.h"


int main(void)
{
	uint16_t distance;

	DDRD|=1<<7;     //active trigger pin as output

	SREG  |= (1<<7);//enable global interrupts in MC by setting the I-Bit.

	LCD_init();
	timer_init();
	EX_INT_init(); //start the timer.



	INT2_to_timer_CallBack(ICU_SW_EX_INT2);

	//Wait_Trigger to trigger  ;

	PORTD|=(1<<7);
	Delay_ms(1,T2);
	PORTD&=~(1<<7);

	while(1)
	{
		LCD_displayStrRowCol(0,0,"Dis=");
		LCD_displayStrRowCol(0,11,"cm");



		LCD_gotoRawCol(0,5);
		distance=(Time_Diff*2.17);

		LCD_IntToStr(distance);

		Delay_ms(50,T2);


		LCD_clearScreen();
		/*Trigger again to renew the distance */

		PORTD|=(1<<7);
		Delay_ms(1,T2);
		PORTD&=~(1<<7);




	}
}



