/*
 * EXINT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */

#ifndef EXINT_H_
#define EXINT_H_

#include "EXINT_Config.h"

extern float Time_Diff;
extern uint8_t Trigger_flag;



void EX_INT_init(void);
void ICU_SW_EX_INT2(void);
void INT2_to_timer_CallBack(void (*ptr)(void));
void EX_INT2_Sensing_Ctrl(EX_INT_Sense_CTRL Ctrl);

#endif /* EXINT_H_ */
