
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
	
	#if CLOCK_SOURCE == MOSC_MAIN_OSCILLATOR_16_MHZ
        SCB_MOSC_REG &= ~(1<<2);
    /*Enable main oscillator */
		SCB_RCC_REG &= (u32)(~(1));
    /*Select main oscillator */
        SCB_RCC_REG &= (u32)(~((3)<<4));
    /* select crystal value */
        SCB_RCC_REG |=  CRYSTAL_VALUE<<6;
    #else 
        SCB_RCC_REG |= CLOCK_SOURCE<<4;
    #endif

    /* Deep sleep or Run */
    #if SLEEP_MODE_CONTROL == DEEP_SLEEP_MODE_CONTROL
        SCB_RCC_REG |= 1<<27;
    #elif   SLEEP_MODE_CONTROL == RUN_MODE_CLOCK_CONTROL
        SCB_RCC_REG &= ~(1<<27);
    #endif
    /*enable divisor*/
    #if DIVIDER_STATE == USED

        SCB_RCC_REG |= 1<<22;
        SCB_RCC_REG |= (SSDIV_DIVISOR<<23);
    #elif
        SCB_RCC_REG &= ~(1<<22);
    #endif
    #if PWM_CLOCK_DIVISOR_STATE == ENABLED
        SCB_RCC_REG |= 1<<20;
        SCB_RCC_REG |= PWM_CLOCK_DIVISOR<<17;
    #endif 

    #if PLL_STATE == USED

        CLR_BIT(SCB_RCC_REG,11);
        CLR_BIT(SCB_RCC_REG,13);

    #elif PLL_STATE == NOT_USED
				SCB_RCC_REG |= 1<<11;
    #endif


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
 *  END OF FILE: SYS_Ctrl.c
 *********************************************************************************************************************/
