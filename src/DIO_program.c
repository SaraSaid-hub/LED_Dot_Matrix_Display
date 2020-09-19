#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"



void MGPIO_VoidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode){

	switch(copy_u8PORT){


	case GPIOA:
		if(copy_u8PIN<=7){

			//clear
			GPIOA_CRL &= ~ ( (0b1111) << (copy_u8PIN*4));
			//Then set the mode
			GPIOA_CRL |= (copy_u8Mode) << (copy_u8PIN*4);


		}else if (copy_u8PIN<=15){
			copy_u8PIN = copy_u8PIN - 8;
			//clear
			GPIOA_CRH &= ~ ( (0b1111) << (copy_u8PIN*4) );
			//Then set the mode
			GPIOA_CRH |= (copy_u8Mode) << (copy_u8PIN*4);

		}
		break;
	case GPIOB:
		if(copy_u8PIN<=7){

		//clear
		GPIOB_CRL &= ~((0b1111)<<(copy_u8PIN*4));
		//Then set the mode
		GPIOB_CRL |= ((copy_u8Mode)<<(copy_u8PIN*4));

		}
		else if (copy_u8PIN<=15){
		copy_u8PIN=copy_u8PIN-8;
		//clear
		GPIOB_CRH &= ~((0b1111)<<(copy_u8PIN*4));
		//Then set the mode
		GPIOB_CRH |= ((copy_u8Mode)<<(copy_u8PIN*4));

		}
		break;
	case GPIOC:
		if(copy_u8PIN<=7){

		//clear
		GPIOC_CRL &= ~((0b1111)<<(copy_u8PIN*4));
		//Then set the mode
		GPIOC_CRL |= ((copy_u8Mode)<<(copy_u8PIN*4));
		}
		else if (copy_u8PIN<=15){
		copy_u8PIN=copy_u8PIN-8;
		//clear
		GPIOC_CRH &= ~((0b1111)<<(copy_u8PIN*4));
		//Then set the mode
		GPIOC_CRH |= ((copy_u8Mode)<<(copy_u8PIN*4));

	  }
	break;
	}
}



void MGPIO_VoidSetPinValue (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value){

	switch(copy_u8PORT){


		case GPIOA:
			if(copy_u8Value == GPIO_HIGH){

				SET_BIT(GPIOA_ODR,copy_u8PIN);
			}
			else if (copy_u8Value == GPIO_LOW){
				CLR_BIT(GPIOA_ODR,copy_u8PIN);
			}
			break;

		case GPIOB:
			if(copy_u8Value==GPIO_HIGH){

			SET_BIT(GPIOB_ODR,copy_u8PIN);
			}
		    else if (copy_u8Value==GPIO_LOW){
			CLR_BIT(GPIOB_ODR,copy_u8PIN);
	        }
	       break;

		case GPIOC:
			if(copy_u8Value==GPIO_HIGH){

			SET_BIT(GPIOC_ODR,copy_u8PIN);
		}
		else if (copy_u8Value==GPIO_LOW){
	    CLR_BIT(GPIOC_ODR,copy_u8PIN);

		}
		break;
}

}

u8 MGPIO_u8GetPinValue (u8 copy_u8PORT, u8 copy_u8PIN){

	u8 value=0;
	switch(copy_u8PORT){


			case GPIOA:
				value=GET_BIT(GPIOA_IDR,copy_u8PIN) ; break;
			case GPIOB:
					value=GET_BIT(GPIOB_IDR,copy_u8PIN) ;break;
			case GPIOC:
				value=GET_BIT(GPIOC_IDR,copy_u8PIN) ;  break;

	}
	return value;
}
