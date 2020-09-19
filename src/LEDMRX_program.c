/*
 * LEDMRX_program.c
 *
 *  Created on: Sep 13, 2020
 *      Author: Sara Said
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"


void HLEDMRX_voidInit(void){

	MGPIO_VoidSetPinDirection (LEDMRX_ROW0_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_ROW1_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_ROW2_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_ROW3_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_ROW4_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_ROW5_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_ROW6_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_ROW7_PIN, OUTPUT_2MHZ_PP);

	MGPIO_VoidSetPinDirection (LEDMRX_COL0_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_COL1_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_COL2_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_COL3_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_COL4_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_COL5_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_COL6_PIN, OUTPUT_2MHZ_PP);
	MGPIO_VoidSetPinDirection (LEDMRX_COL7_PIN, OUTPUT_2MHZ_PP);


}

void HLEDMRX_voidDisplay(u8 *copy_u8Data){
	while(1){
		/*Disable all Columns*/
		HLEDMRX__voidDisableAllCol();
		HLEDMRX__voidSetRowValue(copy_u8Data[0]);
		/*Enable Column 0*/
		MGPIO_VoidSetPinValue (LEDMRX_COL0_PIN, GPIO_LOW);
		//delay 2.5 MSEC
		MSTK_voidSetBusyWait(2500);
		//disable Col0

		/*Column 1 */
		HLEDMRX__voidDisableAllCol();
		HLEDMRX__voidSetRowValue(copy_u8Data[1]);
		MGPIO_VoidSetPinValue (LEDMRX_COL1_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		/*Column 2 */
		HLEDMRX__voidDisableAllCol();
		HLEDMRX__voidSetRowValue(copy_u8Data[2]);
		MGPIO_VoidSetPinValue (LEDMRX_COL2_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		/*Column 3 */
		HLEDMRX__voidDisableAllCol();
		HLEDMRX__voidSetRowValue(copy_u8Data[3]);
		MGPIO_VoidSetPinValue (LEDMRX_COL3_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		/*Column 4 */
		HLEDMRX__voidDisableAllCol();
		HLEDMRX__voidSetRowValue(copy_u8Data[4]);
		MGPIO_VoidSetPinValue (LEDMRX_COL4_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		/*Column 5 */
		HLEDMRX__voidDisableAllCol();
		HLEDMRX__voidSetRowValue(copy_u8Data[5]);
		MGPIO_VoidSetPinValue (LEDMRX_COL5_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		/*Column 6 */
		HLEDMRX__voidDisableAllCol();
		HLEDMRX__voidSetRowValue(copy_u8Data[6]);
		MGPIO_VoidSetPinValue (LEDMRX_COL6_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);


		/*Column 7 */
		HLEDMRX__voidDisableAllCol();
		HLEDMRX__voidSetRowValue(copy_u8Data[7]);
		MGPIO_VoidSetPinValue (LEDMRX_COL7_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
	}
}

static void HLEDMRX__voidDisableAllCol(void){

	MGPIO_VoidSetPinValue (LEDMRX_COL0_PIN, GPIO_HIGH);
	MGPIO_VoidSetPinValue (LEDMRX_COL1_PIN, GPIO_HIGH);
	MGPIO_VoidSetPinValue (LEDMRX_COL2_PIN, GPIO_HIGH);
	MGPIO_VoidSetPinValue (LEDMRX_COL3_PIN, GPIO_HIGH);
	MGPIO_VoidSetPinValue (LEDMRX_COL4_PIN, GPIO_HIGH);
	MGPIO_VoidSetPinValue (LEDMRX_COL5_PIN, GPIO_HIGH);
	MGPIO_VoidSetPinValue (LEDMRX_COL6_PIN, GPIO_HIGH);
	MGPIO_VoidSetPinValue (LEDMRX_COL7_PIN, GPIO_HIGH);
}

static void HLEDMRX__voidSetRowValue(u8 copy_u8DataValue){
	
	u8 Local_u8BIT[8]={0};
	for(u8 index=0; index<8 ; index++){
		Local_u8BIT[index] = GET_BIT(copy_u8DataValue,index);

	}
	MGPIO_VoidSetPinValue (LEDMRX_ROW0_PIN, Local_u8BIT[0]);
	MGPIO_VoidSetPinValue (LEDMRX_ROW1_PIN, Local_u8BIT[1]);
	MGPIO_VoidSetPinValue (LEDMRX_ROW2_PIN, Local_u8BIT[2]);
	MGPIO_VoidSetPinValue (LEDMRX_ROW3_PIN, Local_u8BIT[3]);
	MGPIO_VoidSetPinValue (LEDMRX_ROW4_PIN, Local_u8BIT[4]);
	MGPIO_VoidSetPinValue (LEDMRX_ROW5_PIN, Local_u8BIT[5]);
	MGPIO_VoidSetPinValue (LEDMRX_ROW6_PIN, Local_u8BIT[6]);
	MGPIO_VoidSetPinValue (LEDMRX_ROW7_PIN, Local_u8BIT[7]);

	
}

