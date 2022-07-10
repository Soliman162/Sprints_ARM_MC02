
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SCB.h
 *       Module:  SCB
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef SCB_H
#define SCB_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "SCB_types.h"

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

 
#endif /* SCB_H */

/**********************************************************************************************************************
 *  END OF FILE: SCB.h
 *********************************************************************************************************************/
