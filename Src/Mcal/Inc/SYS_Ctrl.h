
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYS_Ctrl.h
 *       Module:  SYS_Ctrl
 *
 *  Description:  header file for SYS_Ctrl Module    
 *  
 *********************************************************************************************************************/
#ifndef SYS_CTRL_H
#define SYS_CTRL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "SYS_Ctrl_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void SCB_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Init_voidSCB_Clock(void);

void SCB_voidReset(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex);

void SCB_voidEnable_Clock_Run_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex);
void SCB_voidDisable_Clock_Run_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex);

void SCB_voidEnable_Clock_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex);
void SCB_voidDisable_Clock_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex);

void SCB_voidEnable_Clock_Deep_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex);
void SCB_voidDisable_Clock_Deep_Sleep_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex);

 
#endif /* SYS_Ctrl_h */

/**********************************************************************************************************************
 *  END OF FILE: SYS_Ctrl.h
 *********************************************************************************************************************/
