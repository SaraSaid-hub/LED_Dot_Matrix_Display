
#ifndef RCC_config_H
#define RCC_config_H

/* Options:    RCC_HSE_CRYSTAL
               RCC_HSE_RC
               RCC_HSI
               RCC_PLL			   */
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL

/* Options:     RCC_HSI_DIV_2
                RCC_HSE_DIV_2
				RCC_HSE      */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT     RCC_HSE_DIV_2
#endif


/* Options: 2 to 16 */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL   4
#endif
//Bus ID
#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

#endif
