#ifndef RCC_interface_H
#define RCC_interface_H

void RCC_voidInitSysClock(void);

void RCC_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PerId);

void RCC_voidDisableClock (u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif
