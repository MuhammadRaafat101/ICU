#ifndef INT_CONFIG_H_
#define INT_CONFIG_H_

#include "MICRO_setting.h"
/*#include "std_types.h"*/
/*#define EX_INT0 0
#define EX_INT1 2*/
#define NA    0xFF
#define NULL_PTR    ((void*)0)
typedef enum
{
	EX_INT0,EX_INT1,EX_INT2,NumberOfExternalInterrupts
}EX_INT_type;




typedef enum
{
	Low_LVL,Any_Logic,INT_Falling,INT_Rising
}EX_INT_Sense_CTRL;


typedef struct
{
	EX_INT_type        INT_type;
	EX_INT_Sense_CTRL  INT_ctrl;

}EX_INT;


extern EX_INT INT_Setup[NumberOfExternalInterrupts];
#endif /* INT_CONFIG_H_ */
