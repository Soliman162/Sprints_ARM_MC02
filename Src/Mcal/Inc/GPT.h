/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_H
#define INTCTRL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "GPT_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ********************************************************************************************************************/
extern GPT_CONFIG_TYPE GPT_config_arr[6] ;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void Init_voidGPT(const GPT_CONFIG_TYPE *Copy_type);

void GPT_voidStart_Timer(const GPT_CONFIG_TYPE *Copy_type, u32 Copy_u32Start_Value);
void GPT_voidStop_Timer(const GPT_CONFIG_TYPE *Copy_type);

void GPT_voidEnableInterrupt(const GPT_CONFIG_TYPE *Copy_type);
void GPT_voidDisableInterrupt(const GPT_CONFIG_TYPE *Copy_type);

//void GPT_voidSET_IRQ_Function(void *Func(void));

u32 GET_voidElapsed_Time(const GPT_CONFIG_TYPE *Copy_type);
u32 GET_voidRemainingTime(const GPT_CONFIG_TYPE *Copy_type);

void CLR_voidInterrupt_Flag(const GPT_CONFIG_TYPE *Copy_type);
 
#endif /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
