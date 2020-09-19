/*
 * STK_program.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Sara Said
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

static void (*Callback) (void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

/* choose clock from STK_config , disable interrupt and sysytic*/
void MSTK_voidInit(void){

#if STK_CLK == AHB_DIV_8

	STK_CTRL=0;
	/*CLR_BIT(STK_CTRL,2);
	CLR_BIT(STK_CTRL,1);
	CLR_BIT(STK_CTRL,0);*/

#elif STK_CLK == AHB

	STK_CTRL=0x00000004;

	/*SET_BIT(STK_CTRL,2);
	CLR_BIT(STK_CTRL,1);
	CLR_BIT(STK_CTRL,0);*/
#endif
}

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks){

	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL,0);

	while ( (GET_BIT(STK_CTRL,16))== 0);
	//stop timer
	CLR_BIT(STK_CTRL,0);
	STK_LOAD = 0;
	STK_VAL = 0;
}

void MSTK_voidSetIntervalSingle (u32 Copy_u32Ticks, void (*ptr)(void)){
	STK_LOAD=Copy_u32Ticks;

	SET_BIT(STK_CTRL,0);
	Callback=ptr;
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	//enable interrupt
	SET_BIT(STK_CTRL,1);

}

void MSTK_voidSetIntervalPeriodic (u32 Copy_u32Ticks, void (*ptr)(void)){
	STK_LOAD=Copy_u32Ticks;
	SET_BIT(STK_CTRL,1);
	SET_BIT(STK_CTRL,0);
	Callback=ptr;
	/* Set Mode to Periodic */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
}

void MSTK_voidStopInterval(void){
	//Disable interrupt
	CLR_BIT(STK_CTRL,1);
	//Disable Timer
	CLR_BIT(STK_CTRL,0);

	STK_LOAD=0;
	STK_VAL=0;
}

u32 MSTK_u32GetElapsedTime (void){


	u32 Elapsed=STK_LOAD-STK_VAL;
	return Elapsed;
}

u32 MSTK_u32GetRemainingTime (void){

	u32 Remaining= STK_VAL;
	return Remaining;
}
void SysTick_Handler(void)
{
	u8 Local_u8Temporary;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK_CTRL,1);;

		/* Stop Timer */
		CLR_BIT(STK_CTRL,0);

		STK_LOAD=0;
		STK_VAL=0;
	}

	/* Callback notification */
	Callback();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK_CTRL,16);
}
