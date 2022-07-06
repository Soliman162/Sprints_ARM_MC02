/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct{

    volatile u32 PRI[35];

}PRI_Int_Config_Reg;

#define PRI_REGS        ((PRI_Int_Config_Reg *)(CORTEX_M4_BASE_ADDRESS+0x400))

typedef struct{

    volatile u32 EN[5];

}EN_Int_Config_Reg;

#define  EN_REGs    ((EN_Int_Config_Reg *)CORTEX_M4_BASE_ADDRESS+0x100)

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEX_M4_BASE_ADDRESS      0xE000E000
#define APINT_REG                   *((volatile u32 *)(CORTEX_M4_BASE_ADDRESS+0xD0C))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/