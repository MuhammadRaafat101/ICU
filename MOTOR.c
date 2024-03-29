/*
 * MOTOR.c
 *
 * Created: 9/26/2019 6:46:40 PM
 *  Author: M_Moawad
 */ 

#include "MOTOR.h"

/*Std_Func_t motor_On(uint8_t motor_num, uint8_t motor_direction,uint8_t speed)*/
Std_Func_t motor_On(uint8_t motor_num, uint8_t motor_direction)
{
	Std_Func_t retval = OK;
	
	switch (motor_num)
	{
		case LEFT_MOTOR:
			
			
			if (motor_direction == FORWARD)
			{
				DIO_write(LEFT_MOTOR_PORT,LEFT_PIN_A,HIGH);
				DIO_write(LEFT_MOTOR_PORT,LEFT_PIN_B,LOW);
			}
			else if (motor_direction == BACKWARD)
			{
				DIO_write(LEFT_MOTOR_PORT,LEFT_PIN_A,LOW);
				DIO_write(LEFT_MOTOR_PORT,LEFT_PIN_B,HIGH);
				
			}
			else
			{
				retval = NOK;
			}
			break;
			
		case RIGHT_MOTOR:
			if (motor_direction == FORWARD)
			{
				DIO_write(RIGHT_MOTOR_PORT,RIGHT_PIN_A,HIGH);
				DIO_write(RIGHT_MOTOR_PORT,RIGHT_PIN_B,LOW);
			}
			else if (motor_direction == BACKWARD)
			{
				DIO_write(RIGHT_MOTOR_PORT,RIGHT_PIN_A,LOW);
				DIO_write(RIGHT_MOTOR_PORT,RIGHT_PIN_B,HIGH);
				
			}
			else
			{
				retval = NOK;
			}
			break;
		
			
		default:
			retval = NOK;
			break;
	}
	
	return retval;
}


Std_Func_t motor_Off(uint8_t motor_num)
{
	Std_Func_t retval = OK;
	
	switch (motor_num)
	{
		case LEFT_MOTOR:

			DIO_write(LEFT_MOTOR_PORT,LEFT_PIN_A,LOW);
			DIO_write(LEFT_MOTOR_PORT,LEFT_PIN_B,LOW);
	
		break;
		
		case RIGHT_MOTOR:
		
			DIO_write(RIGHT_MOTOR_PORT,RIGHT_PIN_A,LOW);
			DIO_write(RIGHT_MOTOR_PORT,RIGHT_PIN_B,LOW);

		break;
		
		default:
		retval = NOK;
	
	}

	return retval;
		
}