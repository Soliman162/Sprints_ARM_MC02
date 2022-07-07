/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../Common/std_types.h"
#include "../Common/MCU_HW.h"
#include "../Mcal/Inc/IntCtrl_types.h"
#include "../Mcal/Inc/IntCtrl.h"
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
u8 Intrrupt_u8SET[MAX_INTRRUPT_NUMBER][2] = {
                                                {UART0,GROUP_PRIORITY_0_SUBPRIORITY_0},
                                                {ADC0_Sequence_0,GROUP_PRIORITY_1_SUBPRIORITY_0}, 
                                            };


/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
