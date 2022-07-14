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
#include "std_types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern u8 Intrrupt_u8SET[MAX_INTRRUPT_NUMBER][2];

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void Init_voidIntCtrl(void);

void Enable_voidINT(INTRRUPTS_Types Copy_enumINT);
void Disable_voidINT(INTRRUPTS_Types Copy_enumINT);

void SET_voidPENDING_INT(INTRRUPTS_Types Copy_enumINT);
void CLR_voidPENDING_INT(INTRRUPTS_Types Copy_enumINT);

u8 Is_u8INT_Active(INTRRUPTS_Types Copy_enumINT);
void NMI_voidSET_PENDING(void);

void SV_voidSET_PENDING(void);
void SV_void_CLR_PENDING(void);

void SYS_TICK_voidSET_PENDING(void);
void SYS_TICK_voidCLR_PENDING(void);

u8 IS_u8INT_PENDING(void);

void USAGE_FAULT_voidENABLE(void);
void BUS_FAULT_voidENABLE(void);
void MEMORY_MANAGMEDNT_FAULT_voidENABLE(void);

void USAGE_FAULT_voidDISABLE(void);
void BUS_FAULT_voidDISABLE(void);
void MEMORY_MANAGMEDNT_FAULT_voidDISABLE(void);

void SVC_CALL_voidSET_PENDING(void);
void BUS_FAULT_voidSET_PENDING(void);
void MEMORY_MANAGMENT_FAULT_voidSET_PENDING(void);
void USAGE_FAULT_voidSET_PENDING(void);

void SVC_CALL_voidCLR_PENDING(void);
void BUS_FAULT_voidCLR_PENDING(void);
void MEMORY_MANAGMENT_FAULT_voidCLR_PENDING(void);
void USAGE_FAULT_voidCLR_PENDING(void);


void GENERATE_voidGenerated_INTRRUPT(INTRRUPTS_Types Copy_enumINT);

void DEEP_SLEEP_voidEnable(void);
void DEEP_SLEEP_voidDisable(void);
void RESET_voidSystem(void);




 
#endif /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
