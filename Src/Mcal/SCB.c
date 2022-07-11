
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

#include "SCB_types.h"
#include "SCB_Cfg.h"
#include "SCB.h"

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
*                    into SYS_Ctrl registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Init_voidSCB(void)
{
    #if WAKE_UP_ON_PENDING == ENABLE
        SCB_REGs->SYSCTRL |= 16;
    #endif

    #if SLEEP_ONISR_EXIT == ENABLE
        SCB_REGs->SYSCTRL |= 2;
    #endif
    #if STACK_ALIGNMENT_ON_EXCEPTION_ENTRY == STACK_8_BYTE_ALIGNED
        SCB_REGs->CFGCTRL |= 1<<9;
    #endif
    #if TRAP_DIV_BY_0 == ENABLE
        SCB_REGs->CFGCTRL |= 1<<4;
    #endif

    #if TRAP_ON_UNALIGNED_ACCESS == ENABLE
        SCB_REGs->CFGCTRL |= 1<<3 ;
    #endif
}

void Enable_voidFault(u8 Copy_u8Fault)
{
    SCB_REGs->SYSHNDCTRL |= 1<<Copy_u8Fault;
}
void Disable_voidFault(u8 Copy_u8Fault)
{
    SCB_REGs->SYSHNDCTRL &= ~(1<<Copy_u8Fault);
}
void SET_voidFAULT_PENDING(u8 Copy_u8Fault)
{
    SCB_REGs->SYSHNDCTRL |= 1<<Copy_u8Fault;
}
void CLR_voidFAULT_PENDING(u8 Copy_u8Fault)
{
    SCB_REGs->SYSHNDCTRL &= ~(1<<Copy_u8Fault);
}
void SET_voidINTERRUPT_PENDING(u8 Copy_u8Eception)
{
    SCB_REGs->INTCTRL |= 1<<Copy_u8Eception;
}
void CLEAR_voidINTERRUPT_PENDING(u8 Copy_u8Eception)
{
    SCB_REGs->INTCTRL |= 1<<(Copy_u8Eception-1);
}
void RESET_voidSystem(void)
{
    SCB_REGs->APINT |= 4;
}
void DEEP_SLEEP_voidEnable(void)
{
    SCB_REGs->SYSCTRL |= 4;
}
void DEEP_SLEEP_voidDisable(void)
{
    SCB_REGs->SYSCTRL &= ~4;
}
/**********************************************************************************************************************
 *  END OF FILE: SCB.c
 *********************************************************************************************************************/
