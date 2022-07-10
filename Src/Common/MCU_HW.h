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
#include "std_types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEX_M4_BASE_ADDRESS      0xE000E000
#define SCB_BASE_ADDRESS            0x400FE000

#define APINT_REG                        *((volatile u32 *)(CORTEX_M4_BASE_ADDRESS+0xD0C))

#define SYS_CTRL_RCC_REG                 *((volatile u32 *)(SCB_BASE_ADDRESS+0x060))
#define SYS_CTRL_MOSC_REG                *((volatile u32 *)(SCB_BASE_ADDRESS+0x07C))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef struct{

    volatile u32 PRI[35];

}PRI_Int_Config_Reg;

#define PRI_REGS        ((PRI_Int_Config_Reg *)(CORTEX_M4_BASE_ADDRESS+0x400))

typedef struct{

    volatile u32 EN[5];

}EN_Int_Config_Reg;

#define  EN_REGs    ((EN_Int_Config_Reg *)(CORTEX_M4_BASE_ADDRESS+0x100))


typedef struct{

    volatile u32 SYS_CTRL_RESET_REGs[24];
    u32 Reserved_0[40];
    volatile u32 SYS_CTRL_RUN_MODE_GC_REGs[24];
    u32 Reserved_1[40];
    volatile u32 SYS_CTRL_SLEEP_MODE_GC_REGs[24];
    u32 Reserved_2[40];
    volatile u32 SYS_CTRL_DEEP_SLEEP_MODE_GC_REGs[24];
    u32 Reserved_3[104];
    volatile u32 SYS_CTRL_PERIPHERAL_READY_REGs[24];

}SYS_CTRL_config_REGs;
 
 #define SYS_CTRL_REGs         ((SYS_CTRL_config_REGs *)(SCB_BASE_ADDRESS+0x500))


 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/