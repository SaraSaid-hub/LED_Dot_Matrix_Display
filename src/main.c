/*********************************************************/
/* Author      : Sara Said                               */
/* Date        : 17 SEPT 2020                            */
/* Version     : V01                                     */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "RCC_config.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"

u8 DataArray[8]={0,38,73,73,73,50,0,0};

void main (void){

        // Initialize System CLK
	RCC_voidInitSysClock();
	// Enable PORTA
	RCC_voidEnableClock (RCC_APB2, 2);
	//Enable PORTB
	RCC_voidEnableClock (RCC_APB2, 3);

	MSTK_voidInit();
	HLEDMRX_voidInit();
	// Send data array to led matrix
	HLEDMRX_voidDisplay(DataArray);

	while(1){

	}
}
