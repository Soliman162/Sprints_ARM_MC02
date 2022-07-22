
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "BIT_MATH.h"
#include "MCU_HW.h"
#include "DIO_types.h"
#include "DIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
GPIO_CONFIG_REGs *GPIO_ARR[6] = {GPIO_A_PRE,GPIO_B_PRE,GPIO_C_PRE,GPIO_D_PRE,GPIO_E_PRE,GPIO_F_PRE};

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void DIO_voidInit_Pin(const PORT_CONFIG_TYPE * Copy_Pin)
{
    GPIO_ARR[Copy_Pin->Pin_Number/8]->GPIODIR |= (u32)Copy_Pin->Pin_Direction<<(Copy_Pin->Pin_Number%8);
    GPIO_ARR[Copy_Pin->Pin_Number/8]->GPIODR_2_4_8_R[Copy_Pin->Pin_OutPut_Current] |= 1<<(Copy_Pin->Pin_Number%8);
    GPIO_ARR[Copy_Pin->Pin_Number/8]->GPIO_OD_PU_PD_SL_R[Copy_Pin->Pin_InternalAttach] |= 1<<(Copy_Pin->Pin_Number%8);
    GPIO_ARR[Copy_Pin->Pin_Number/8]->GPIODEN |= 1<<(Copy_Pin->Pin_Number%8); 
}
void DIO_voidWriteChannel(DIO_CHANNEL_TYPE Copy_enumChannel, DIO_LEVEL_TYPE Copy_enumLevel_type)
{
	if(Copy_enumLevel_type == DIO_HIGH)
	{
		GPIO_ARR[Copy_enumChannel/8]->GPIODATA[255] |= (u32)(1<<(Copy_enumChannel%8));
	}else if( Copy_enumLevel_type == DIO_LOW)
	{
		GPIO_ARR[Copy_enumChannel/8]->GPIODATA[255] &= (u32)(~(1<<(Copy_enumChannel%8)));
	}
}

DIO_LEVEL_TYPE DIO_voidReadChannel(DIO_CHANNEL_TYPE Copy_enumChannel)
{
    return 	GET_BIT( (u32)(GPIO_ARR[Copy_enumChannel/8]->GPIODATA[255]),Copy_enumChannel%8);
}

void DIO_voidWritePort(DIO_PORT_TYPE COPY_enumPort,u8 Copy_enumLevelType )
{
    GPIO_ARR[COPY_enumPort]->GPIODATA[255] = Copy_enumLevelType;
}

u8 DIO_voidReadPort(DIO_PORT_TYPE COPY_enumPort)
{
    return  (u8)GPIO_ARR[COPY_enumPort]->GPIODATA[255];
}

void DIO_voidFlip_Channel(DIO_CHANNEL_TYPE  Copy_enumChannel )
{
    GPIO_ARR[Copy_enumChannel/8]->GPIODATA[255] ^= (1<<Copy_enumChannel%8);
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/





















