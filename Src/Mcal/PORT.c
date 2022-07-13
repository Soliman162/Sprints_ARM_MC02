
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT.c
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
#include "PORT_types.h"
#include "PORT.h"
#include "PORT_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern GPIO_CONFIG_REGs *GPIO_ARR[6];

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

void PORT_voidInit(const PORT_CONFIG_TYPE *Config_ptr)
{
    for(u8 i=0;i<ACTIVE_PIN_NUMBER;i++)
    {
        /*Diorection*/
        GPIO_ARR[Config_ptr->Pin_Mode_Number/8]->GPIODIR = Config_ptr->Pin_Direction << (Config_ptr->Pin_Mode_Number%8);
        if( (Config_ptr[i].Pin_Mode == I2C) || (Config_ptr[i].Pin_Mode == CAN) || (Config_ptr[i].Pin_Mode == UART) )
        {
            GPIO_ARR[Config_ptr->Pin_Mode_Number/8]->GPIOAFSEL |= 1<<(Config_ptr->Pin_Mode_Number%8);
            GPIO_ARR[Config_ptr->Pin_Mode_Number/8]->GPIOPCTL  |= Config_ptr->Pin_Mode<<((Config_ptr->Pin_Mode_Number%8)*4);
        }else if (Config_ptr[i].Pin_Mode == DIO)
        {
            GPIO_ARR[Config_ptr->Pin_Mode_Number/8]->GPIODEN |= 1<<(Config_ptr->Pin_Mode_Number%8);
        }else if (Config_ptr[i].Pin_Mode == ADC)
        {
            GPIO_ARR[Config_ptr->Pin_Mode_Number/8]->GPIOADCCTL |= 1<<(Config_ptr->Pin_Mode_Number%8); 
            GPIO_ARR[Config_ptr->Pin_Mode_Number/8]->GPIOAMSEL |= 1<<(Config_ptr->Pin_Mode_Number%8);

        }else if (Config_ptr[i].Pin_Mode == EXTI)
        {
            
        }else if (DMA)
        {
            GPIO_ARR[Config_ptr->Pin_Mode_Number/8]->GPIODMACTL |= 1<<(Config_ptr->Pin_Mode_Number%8); 
        }

        GPIO_ARR[Config_ptr->Pin_Mode_Number/8]->GPIODR_2_4_8_R[Config_ptr->Pin_OutPut_Current] |= 1<<(Config_ptr->Pin_Mode_Number%8);
        GPIO_ARR[Config_ptr->Pin_Mode_Number/8]->GPIO_OD_PU_PD_SL_R[Config_ptr->Pin_InternalAttach] |= 1<<(Config_ptr->Pin_Mode_Number%8);
    }
}

/**********************************************************************************************************************
 *  END OF FILE: PORT.c
 *********************************************************************************************************************/

