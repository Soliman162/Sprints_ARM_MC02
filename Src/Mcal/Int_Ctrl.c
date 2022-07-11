
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
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
#include "IntCtrl_types.h"
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"
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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Init_voidIntCtrl(void)
{
    u8 LOC_i_u8;
    u8 LOC_j_u8;
    u8 LOC_N_u8;

    /* set group_priorty / subgroub priority APINT in SCB*/
    SCB_REGs->APINT |= (0x05FA0000|(GROUP_PRIORITY_X_SUBPRIORITY_X<<8));

    /* set group_priorty / subgroub priority in NVIC */
    for(LOC_i_u8=0;LOC_i_u8<MAX_INTRRUPT_NUMBER;LOC_i_u8++)
    {
        LOC_N_u8 = (Intrrupt_u8SET[LOC_i_u8][0])/4;
        LOC_j_u8 = (Intrrupt_u8SET[LOC_i_u8][0]) - 4*LOC_N_u8;

        PRI_REGS->PRI[LOC_N_u8] |= (Intrrupt_u8SET[LOC_i_u8][1]<<(LOC_j_u8*8+5)) ;
    }
    
    /* Enable/disable IRQ */
    for(LOC_i_u8=0;LOC_i_u8<MAX_INTRRUPT_NUMBER;LOC_i_u8++)
    {
        LOC_N_u8 = Intrrupt_u8SET[LOC_i_u8][0]/32;
        LOC_j_u8 = (Intrrupt_u8SET[LOC_i_u8][0])%32;
        EN_REGs->EN[LOC_N_u8] |= 1<<( LOC_j_u8 ) ;
    }

}

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
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/





















