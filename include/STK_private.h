#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H



#define BASE_ADDRESS 0xE000E010

#define STK_CTRL     *((volatile u32*)(BASE_ADDRESS+0x00))
#define STK_LOAD     *((volatile u32*)(BASE_ADDRESS+0x04))
#define STK_VAL      *((volatile u32*)(BASE_ADDRESS+0x08))
#define STK_CALIB    *((volatile u32*)(BASE_ADDRESS+0x0C))



#define AHB   0
#define AHB_DIV_8 1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1


#endif
