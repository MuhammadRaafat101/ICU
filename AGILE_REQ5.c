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
	uint16_t distance=0,confirm=0;

	uint16_t count=0;
	DDRD|=(1<<7);


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
	LCD_displayStrRowCol(1,0,"Objects=");
	while(1)
	{

		LCD_displayStrRowCol(0,5,"    ");
		LCD_gotoRawCol(0,5);
		distance=(Time_Diff*2.17);
		LCD_IntToStr(distance);

		LCD_displayStrRowCol(1,8,"     ");
		LCD_gotoRawCol(1,8);
		LCD_IntToStr(count);


Delay_ms(100,T2);

		//LCD_clearScreen();
		//Wait_Trigger();
		PORTD|=(1<<7);
		Delay_ms(1,T2);
		PORTD&=~(1<<7);

		if(distance <=20 && distance > 0)
		{
			LCD_gotoRawCol(0,5);
			confirm=(Time_Diff*2.17);
			Delay_ms(500,T2);

			if(confirm>30)
			{

			DIO_write(PORT_B,PIN4,HIGH);
			count++;
		    }
		}


	}
}


