
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
#include "std_types.h"
#include "BIT_MATH.h"
#include "MCU_HW.h"

#include "SYS_Ctrl_types.h"
#include "SYS_Ctrl_Cfg.h"
#include "SYS_Ctrl.h"

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
* \Syntax          : void SYS_Ctrl_Init(void)                                      
* \Description     : initialize SYS_Ctrl\SYS_Ctrl Module by parsing the Configuration 
*                    into SYS_Ctrl registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Init_voidSCB_Clock(void)
{
    SYS_CTRL_RCC_REG->bit.ACG = 0;
    SYS_CTRL_RCC_REG->bit.SYSDIV = SSDIV_DIVISOR;
    SYS_CTRL_RCC_REG->bit.USESYSDIV = 1;
    SYS_CTRL_RCC_REG->bit.USEPWMDIV = 0;
    SYS_CTRL_RCC_REG->bit.PWRDN = 1;
    while(GET_BIT(SYS_CTRL_PLL_STAT,0)!=1);
    SYS_CTRL_RCC_REG->bit.BYPASS = 1;
    SYS_CTRL_RCC_REG->bit.XTAL = 0x15;
    SYS_CTRL_RCC_REG->bit.OSCSRC = 0;
    SYS_CTRL_RCC_REG->bit.MOSCDIS = 0;

}

void SCB_voidReset(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    /* Set reset bit */
    SYS_CTRL_REGs->SYS_CTRL_RESET_REGs[Copy_enumModuleName] |= (1<<Copy_enumModuleIndex);
    /* clear reset bit*/
    SYS_CTRL_REGs->SYS_CTRL_RESET_REGs[Copy_enumModuleName] &= ~(1<<Copy_enumModuleIndex);
    /* wait the PERIPHERAL become ready */
    while(GET_BIT(SYS_CTRL_REGs->SYS_CTRL_PERIPHERAL_READY_REGs[Copy_enumModuleName],Copy_enumModuleIndex)==0);
}

void SCB_voidEnable_Clock_Run_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SYS_CTRL_REGs->SYS_CTRL_RUN_MODE_GC_REGs[Copy_enumModuleName] |= (1<<Copy_enumModuleIndex);
}
void SCB_voidDisable_Clock_Run_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SYS_CTRL_REGs->SYS_CTRL_RUN_MODE_GC_REGs[Copy_enumModuleName] &= ~(1<<Copy_enumModuleIndex);
}

void SCB_voidEnable_Clock_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SYS_CTRL_REGs->SYS_CTRL_SLEEP_MODE_GC_REGs[Copy_enumModuleName] |= (1<<Copy_enumModuleIndex);
}
void SCB_voidDisable_Clock_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SYS_CTRL_REGs->SYS_CTRL_SLEEP_MODE_GC_REGs[Copy_enumModuleName] &= ~(1<<Copy_enumModuleIndex);
}

void SCB_voidEnable_Clock_Deep_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SYS_CTRL_REGs->SYS_CTRL_DEEP_SLEEP_MODE_GC_REGs[Copy_enumModuleName] |= (1<<Copy_enumModuleIndex);
}
void SCB_voidDisable_Clock_Deep_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SYS_CTRL_REGs->SYS_CTRL_DEEP_SLEEP_MODE_GC_REGs[Copy_enumModuleName] &= ~(1<<Copy_enumModuleIndex);
}


/**********************************************************************************************************************
 *  END OF FILE: SYS_Ctrl.c
 *********************************************************************************************************************/
