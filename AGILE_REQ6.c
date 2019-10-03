/*
 * Motor_test.c
 *
 * Created: 10/2/2019 12:22:14 PM
 * Author : Raafat
 */

#include <avr/io.h>

#include "EXINT.h"
#include "Timers.h"
#include "LCD.h"
#include "DIO.h"

int main(void)
{
	uint16_t distance;

	uint16_t count=0;
	DDRD|=(1<<7);
	DDRB|=(1<<3);

	sei();//enable global interrupts in MC by setting the I-Bit.
	DIO_init();
	LCD_init();
	timer_init();
	EX_INT_init(); //start the timer.



	INT2_to_timer_CallBack(ICU_SW_EX_INT2);
	PORTD|=(1<<7);
	Delay_ms(1,T2);
	PORTD&=~(1<<7);


	//Wait_Trigger();
	//DDRB|=1<<4;

	LCD_displayStrRowCol(0,0,"Dis=");
	LCD_displayStrRowCol(0,9,"cm");

	while(1)
	{

		LCD_displayStrRowCol(0,5,"    ");
		LCD_gotoRawCol(0,5);
		distance=(Time_Diff*2.17);
		LCD_IntToStr(distance);

		LCD_displayStrRowCol(1,8,"     ");
		LCD_gotoRawCol(1,8);
		LCD_IntToStr(count);




		//LCD_clearScreen();
		//Wait_Trigger();
		PORTD|=(1<<7);
		Delay_ms(1,T2);
		PORTD&=~(1<<7);

		if(distance <= 40 && distance > 0)
		{

			PORTB|=(1<<3);
			Delay_ms(distance*10,T2);

			PORTB&=~(1<<3);
		}


	}
}


