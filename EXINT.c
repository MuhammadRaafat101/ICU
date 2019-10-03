/*
 * EXINT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */


#include"EXINT.h"

uint8_t INT2_Flag=0 ;
float Time_Start=0;
float Time_End=0;
float Time_Diff=0;

uint8_t Trigger_flag=0;




static volatile void (*INT2_TO_timer)(void) = NULL_PTR;





ISR(INT2_vect)
{
    //PORTC=1;
	if(INT2_TO_timer != NULL_PTR)
	{

		(*INT2_TO_timer)();

	}

   // PORTC=2;


}




void INT2_to_timer_CallBack(void (*ptr)(void))
{
	INT2_TO_timer=ptr;

}


void ICU_SW_EX_INT2(void)
{


	if(INT2_Flag==0)
	{
		EX_INT2_Sensing_Ctrl(INT_Falling);
		TCNT0=0;
		Time_Start=TCNT0;
		INT2_Flag=1;
		Trigger_flag=0;
		//PORTC=3;

	}
	else if (INT2_Flag==1)
	{
		EX_INT2_Sensing_Ctrl(INT_Rising);
		Time_End=TCNT0;
		Time_Diff=Time_End-Time_Start;
		//LCD_IntToStr(Time_End);
		INT2_Flag=0;
		Trigger_flag=1;
	}





}

void EX_INT_init(void)
{
	uint8_t loop_index;
	for(loop_index=0;loop_index<NumberOfExternalInterrupts;loop_index++)
	{
		switch(INT_Setup[loop_index].INT_type)
		{
		case EX_INT0:

			MCUCR|=(INT_Setup[loop_index].INT_ctrl);
			GICR|=(!(INT_Setup[loop_index].INT_type)<<6);
			DDRD  &= (~(1<<PD2));
			break;

		case EX_INT1:
			MCUCR|=(INT_Setup[loop_index].INT_ctrl<<2);
			GICR|=(INT_Setup[loop_index].INT_type<<7);
			 DDRD  &= (~(1<<PD3));
			break;
		case EX_INT2:

			GICR|=(INT_Setup[loop_index].INT_type<<4);
			DDRB  &= (~(1<<PB2));
			break;

		default:
			break;

		}
	}


}





void EX_INT2_Sensing_Ctrl(volatile EX_INT_Sense_CTRL Ctrl)
{
	if(Ctrl== INT_Rising)
	{
		MCUCSR|=(1<<ISC2) ;//int2
		//MCUCR |= (1<<ISC00) | (1<<ISC01);//int0
	}
	else if(Ctrl== INT_Falling)
	{
		MCUCSR&=~(1<<ISC2);//int2
		//MCUCR |= (1<<ISC01);              //int0
	}

}
