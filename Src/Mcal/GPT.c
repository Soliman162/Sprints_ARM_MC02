
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
#include "GPT_types.h"
#include "GPT_Cfg.h"
#include "GPT.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define TAEN_BIT    0
//#define TBEN_BIT    8

#define TIMER_A     0
#define TIMER_B     1


#define TIMER_COUNTING_DIRECTION_DOWN   0    

#define TIMER_A0_32_VECTOR_TABLE_ADDRESS    *((volatile U32 *)0x0000008C)
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static GPT_REGs_CONFIG *GPT_ARR[6] = {  GPT0_16_32_BIT_REGs,GPT1_16_32_BIT_REGs,
                                        GPT2_16_32_BIT_REGs,GPT3_16_32_BIT_REGs
                                        ,GPT4_16_32_BIT_REGs,GPT5_16_32_BIT_REGs};

static u32 Timer_u32Init_Counter =0;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void Init_voidGPT(const GPT_CONFIG_TYPE *Copy_type)
{
    /*disable timer*/
    GPT_ARR[Copy_type->Channel_ID]->GPTMCTL &= ~(1<<TAEN_BIT);
    
    GPT_ARR[Copy_type->Channel_ID]->GPTMCFG = 0x00000000;
    /*periodic or oneshot*/
    GPT_ARR[Copy_type->Channel_ID]->GPTMT_A_B_MR[TIMER_A] |= Copy_type->Channel_Mode;   
}
void GPT_voidStart_Timer(const GPT_CONFIG_TYPE *Copy_type, u32 Copy_u32Start_Value)
{
    /*load start value*/
    GPT_ARR[Copy_type->Channel_ID]->GPTMT_A_B_ILR[TIMER_A] = Copy_u32Start_Value;
    Timer_u32Init_Counter = Copy_u32Start_Value;
    /*enable timer*/
    GPT_ARR[Copy_type->Channel_ID]->GPTMCTL |= (1<<TAEN_BIT);
}
void GPT_voidStop_Timer(const GPT_CONFIG_TYPE *Copy_type)
{
    GPT_ARR[Copy_type->Channel_ID]->GPTMCTL &= ~(1<<TAEN_BIT);
    Timer_u32Init_Counter = 0;
}

void GPT_voidEnableInterrupt(const GPT_CONFIG_TYPE *Copy_type)
{
    GPT_ARR[Copy_type->Channel_ID]->GPTMIMR |= 1;
}
void GPT_voidDisableInterrupt(const GPT_CONFIG_TYPE *Copy_type)
{
    GPT_ARR[Copy_type->Channel_ID]->GPTMIMR &= ~1;
}

u32 GET_voidElapsed_Time(const GPT_CONFIG_TYPE *Copy_type)
{
   return (Timer_u32Init_Counter - GPT_ARR[Copy_type->Channel_ID]->GPTMT_A_B_V[TIMER_A]) ;
}
u32 GET_voidRemainingTime(const GPT_CONFIG_TYPE *Copy_type)
{
    return GPT_ARR[Copy_type->Channel_ID]->GPTMT_A_B_V[TIMER_A];
}
void CLR_voidInterrupt_Flag(const GPT_CONFIG_TYPE *Copy_type)
{
    GPT_ARR[Copy_type->Channel_ID]->GPTMICR |= 1;
}

u8 Check_u8Timer_State(const GPT_CONFIG_TYPE *Copy_type)
{
	return (GET_BIT(GPT_ARR[Copy_type->Channel_ID]->GPTMRIS,0)); 
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/





















