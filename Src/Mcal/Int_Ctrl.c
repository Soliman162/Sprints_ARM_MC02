
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller \ system control block Driver
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
#include "IntCtrl_types.h"
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define NMI_INT_BIT     31
#define ISR_PED_CHECK_BIT   22

#define USAGE_FAULT_ENABLE_BIT  18
#define BUS_FAULT_ENABLE_BIT    17
#define MEMORY_MANAGMEDNT_FAULT_ENABLE_BIT  16

#define SVC_CALL_PENDING_BIT    15
#define BUS_FAULT_PENDING_BIT   14
#define MEMORY_MANAGMENT_FAULT_PENDING_BIT  13
#define USAGE_FAULT_PENDING_BIT             12

#define SYSTEM_RESET_BIT    2

#define APINT_REG_KEY       0x05FA0000

#define SV_INT_SET_PED_BIT  28
#define SV_INT_CLR_PED_BIT  27

#define SYS_TICK_SET_PED_BIT    26
#define SYS_TICK_CLR_PED_BIT    25

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

void Init_voidIntCtrl(void)
{
    u8 LOC_i_u8;
    u8 LOC_j_u8;
    u8 LOC_N_u8;

    /* set group_priorty / subgroub priority APINT in SCB*/
    SCB_REGs->APINT = (APINT_REG_KEY|(GROUP_PRIORITY_X_SUBPRIORITY_X<<8));

    /* set group_priorty / subgroub priority in NVIC */
    for(LOC_i_u8=0;LOC_i_u8<MAX_INTRRUPT_NUMBER;LOC_i_u8++)
    {
        LOC_N_u8 = (Intrrupt_u8SET[LOC_i_u8][0])/4;
        LOC_j_u8 = (Intrrupt_u8SET[LOC_i_u8][0]) - 4*LOC_N_u8;

        NVIC_REGS->PRI[LOC_N_u8] |= (Intrrupt_u8SET[LOC_i_u8][1]<<(LOC_j_u8*8+5)) ;
    }
    
    /* Enable/disable IRQ */
    for(LOC_i_u8=0;LOC_i_u8<MAX_INTRRUPT_NUMBER;LOC_i_u8++)
    {
        LOC_N_u8 = Intrrupt_u8SET[LOC_i_u8][0]/32;
        LOC_j_u8 = (Intrrupt_u8SET[LOC_i_u8][0])%32;
        NVIC_REGS->EN[LOC_N_u8] = 1<<( LOC_j_u8 ) ;

    }

        //SCB_REGs->APINT |= APINT_REG_KEY;
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
    #if SW_UNPREVILLEDGE_ACCESS == ENABLE
        SCB_REGs->CFGCTRL |= 1<<1;
    #endif
}

void Enable_voidINT(INTRRUPTS_Types Copy_enumINT)
{
    NVIC_REGS->EN[Copy_enumINT/32] = 1<<(Copy_enumINT%32);
}

void Disable_voidINT(INTRRUPTS_Types Copy_enumINT)
{
    NVIC_REGS->DIS[Copy_enumINT/32] = 1<<(Copy_enumINT%32);
}

void SET_voidPENDING_INT(INTRRUPTS_Types Copy_enumINT)
{
    NVIC_REGS->SET_PED[Copy_enumINT/32] = 1<<(Copy_enumINT%32);
}

void CLR_voidPENDING_INT(INTRRUPTS_Types Copy_enumINT)
{
    NVIC_REGS->CLR_PED[Copy_enumINT/32] = 1<<(Copy_enumINT%32);
}

u8 Is_u8INT_Active(INTRRUPTS_Types Copy_enumINT)
{
    return GET_BIT( NVIC_REGS->ACT_INT[Copy_enumINT/32], Copy_enumINT%32 );
}


void NMI_voidSET_PENDING(void)
{
    SET_BIT(SCB_REGs->INTCTRL , NMI_INT_BIT);
}

void SV_voidSET_PENDING(void)
{
    SET_BIT( SCB_REGs->INTCTRL  , SV_INT_SET_PED_BIT); 
}

void SV_void_CLR_PENDING(void)
{
    SET_BIT( SCB_REGs->INTCTRL  , SV_INT_CLR_PED_BIT); 
}

void SYS_TICK_voidSET_PENDING(void)
{
    SET_BIT(SCB_REGs->INTCTRL , SYS_TICK_SET_PED_BIT);
}

void SYS_TICK_voidCLR_PENDING(void)
{
    SET_BIT(SCB_REGs->INTCTRL , SYS_TICK_CLR_PED_BIT);
}

u8 IS_u8INT_PENDING(void)
{
    return GET_BIT(SCB_REGs->INTCTRL, ISR_PED_CHECK_BIT);
}

void GENERATE_voidGenerated_INTRRUPT(INTRRUPTS_Types Copy_enumINT)
{
    NVIC_REGS->SWTRIG = Copy_enumINT;
}

void USAGE_FAULT_voidENABLE(void)
{
    SET_BIT(SCB_REGs->SYSHNDCTRL, USAGE_FAULT_ENABLE_BIT );
}

void BUS_FAULT_voidENABLE(void)
{
    SET_BIT(SCB_REGs->SYSHNDCTRL, BUS_FAULT_ENABLE_BIT );
}

void MEMORY_MANAGMEDNT_FAULT_voidENABLE(void)
{
    SET_BIT(SCB_REGs->SYSHNDCTRL, MEMORY_MANAGMEDNT_FAULT_ENABLE_BIT );
}

void USAGE_FAULT_voidDISABLE(void)
{
    CLR_BIT(SCB_REGs->SYSHNDCTRL, USAGE_FAULT_ENABLE_BIT );
}

void BUS_FAULT_voidDISABLE(void)
{
    CLR_BIT(SCB_REGs->SYSHNDCTRL, BUS_FAULT_ENABLE_BIT );
}

void MEMORY_MANAGMEDNT_FAULT_voidDISABLE(void)
{
    CLR_BIT(SCB_REGs->SYSHNDCTRL, MEMORY_MANAGMEDNT_FAULT_ENABLE_BIT );
}

void SVC_CALL_voidSET_PENDING(void)
{
    SET_BIT(SCB_REGs->SYSHNDCTRL, SVC_CALL_PENDING_BIT);
}

void BUS_FAULT_voidSET_PENDING(void)
{
    SET_BIT(SCB_REGs->SYSHNDCTRL, BUS_FAULT_PENDING_BIT);
}

void MEMORY_MANAGMENT_FAULT_voidSET_PENDING(void)
{
    SET_BIT(SCB_REGs->SYSHNDCTRL, MEMORY_MANAGMENT_FAULT_PENDING_BIT);
}

void USAGE_FAULT_voidSET_PENDING(void)
{
    SET_BIT(SCB_REGs->SYSHNDCTRL, USAGE_FAULT_PENDING_BIT);
}


void SVC_CALL_voidCLR_PENDING(void)
{
    CLR_BIT(SCB_REGs->SYSHNDCTRL, SVC_CALL_PENDING_BIT);
}

void BUS_FAULT_voidCLR_PENDING(void)
{
    CLR_BIT(SCB_REGs->SYSHNDCTRL, BUS_FAULT_PENDING_BIT);
}

void MEMORY_MANAGMENT_FAULT_voidCLR_PENDING(void)
{
    CLR_BIT(SCB_REGs->SYSHNDCTRL, MEMORY_MANAGMENT_FAULT_PENDING_BIT);
}

void USAGE_FAULT_voidCLR_PENDING(void)
{
    CLR_BIT(SCB_REGs->SYSHNDCTRL, USAGE_FAULT_PENDING_BIT);
}

void RESET_voidSystem(void)
{
    SET_BIT(SCB_REGs->APINT, SYSTEM_RESET_BIT);  
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

