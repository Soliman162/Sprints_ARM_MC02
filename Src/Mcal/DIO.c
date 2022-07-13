
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


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into DIO registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void DIO_voidWriteChannel(DIO_CHANNEL_TYPE Copy_enumChannel, DIO_LEVEL_TYPE Copy_enumLevel_type)
{
    GPIO_ARR[Copy_enumChannel/8]->GPIODATA[1<<(Copy_enumChannel%8)] = (Copy_enumLevel_type<<(Copy_enumChannel%8));
}

DIO_LEVEL_TYPE DIO_voidReadChannel(DIO_CHANNEL_TYPE Copy_enumChannel)
{
    return GPIO_ARR[Copy_enumChannel/8]->GPIODATA[1<<(Copy_enumChannel%8)];
}

void DIO_voidWritePort(DIO_PORT_TYPE COPY_enumPort,u8 Copy_enumLevelType )
{
    GPIO_ARR[COPY_enumPort]->GPIODATA[255] = Copy_enumLevelType;
}

u8 DIO_voidReadPort(DIO_PORT_TYPE COPY_enumPort)
{
    return  GPIO_ARR[COPY_enumPort]->GPIODATA[255];
}

void DIO_voidFlip_Channel(DIO_CHANNEL_TYPE  Copy_enumChannel )
{
    GPIO_ARR[Copy_enumChannel/8]->GPIODATA[1<<Copy_enumChannel] ^= (1<<Copy_enumChannel);
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/





















