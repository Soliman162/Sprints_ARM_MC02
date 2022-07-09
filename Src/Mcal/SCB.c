
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SCB.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../Common/std_types.h"
#include "../Common/BIT_MATH.h"

#include "../Common/MCU_HW.h"
#include "Inc/SCB.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : void SCB_Init(void)                                      
* \Description     : initialize SCB\SCB Module by parsing the Configuration 
*                    into SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Init_voidSCB_Clock(void)
{
    /* Deep sleep or Run */
    
}

void SCB_voidReset(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    /* Set reset bit */
    SCB_REGs->SCB_RESET_REGs[Copy_enumModuleName] |= (1<<Copy_enumModuleIndex);
    /* clear reset bit*/
    SCB_REGs->SCB_RESET_REGs[Copy_enumModuleName] &= ~(1<<Copy_enumModuleIndex);
    /* wait the PERIPHERAL become ready */
    while(GET_BIT(SCB_REGs->SCB_PERIPHERAL_READY_REGs[Copy_enumModuleName],Copy_enumModuleIndex)==0);
}

void SCB_voidEnable_Clock_Run_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SCB_REGs->SCB_RUN_MODE_GC_REGs[Copy_enumModuleName] |= (1<<Copy_enumModuleIndex);
}
void SCB_voidDisable_Clock_Run_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SCB_REGs->SCB_RUN_MODE_GC_REGs[Copy_enumModuleName] &= ~(1<<Copy_enumModuleIndex);
}

void SCB_voidEnable_Clock_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SCB_REGs->SCB_SLEEP_MODE_GC_REGs[Copy_enumModuleName] |= (1<<Copy_enumModuleIndex);
}
void SCB_voidDisable_Clock_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SCB_REGs->SCB_SLEEP_MODE_GC_REGs[Copy_enumModuleName] &= ~(1<<Copy_enumModuleIndex);
}

void SCB_voidEnable_Clock_Deep_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SCB_REGs->SCB_DEEP_SLEEP_MODE_GC_REGs[Copy_enumModuleName] |= (1<<Copy_enumModuleIndex);
}
void SCB_voidDisable_Clock_Deep_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SCB_REGs->SCB_DEEP_SLEEP_MODE_GC_REGs[Copy_enumModuleName] &= ~(1<<Copy_enumModuleIndex);
}
/**********************************************************************************************************************
 *  END OF FILE: SCB.c
 *********************************************************************************************************************/
