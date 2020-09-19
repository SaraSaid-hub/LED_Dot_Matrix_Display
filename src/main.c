#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "RCC_config.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"



//u8 DataArray[8]={0,132,138,146,162,66,0,0};
u8 DataArray[8]={0,38,73,73,73,50,0,0};
u8 FullNameArray[32]={0, 38, 73, 73, 73, 50, 0, 0, 126, 9, 9, 126, 0, 0, 0, 0, 127, 17, 17, 17, 110, 0, 0, 0, 126, 9, 9, 126, 0, 0, 0, 0};
u8 FullNameArray2[32]={0, 38, 73, 73, 73, 50, 0, 0, 126, 9, 9, 126, 0, 0, 127, 17, 17, 17, 110, 0, 0, 126, 9, 9, 126, 0, 0, 0, 0, 0, 0, 0};

void main (void){


	RCC_voidInitSysClock();
	//PORTA
	RCC_voidEnableClock (RCC_APB2, 2);
	//PORTB
	RCC_voidEnableClock (RCC_APB2, 3);

	MSTK_voidInit();
	HLEDMRX_voidInit();
	// send data array to led matrix
	//HLEDMRX_voidDisplay(DataArray);
	HLEDMRX_voidFullDisplay(FullNameArray2);
	// MGPIO_VoidSetPinValue (GPIOA, PIN0, 1);

	while(1){



	}
}
