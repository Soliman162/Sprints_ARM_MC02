/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SCB_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/

#ifndef SCB_TYPES_H
#define SCB_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/MCU_HW.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef enum{

    SYSDIV_DIVISOR_1=0,
    SYSDIV_DIVISOR_2,
    SYSDIV_DIVISOR_3,
    SYSDIV_DIVISOR_4,
    SYSDIV_DIVISOR_5,
    SYSDIV_DIVISOR_6,
    SYSDIV_DIVISOR_7,
    SYSDIV_DIVISOR_8,
    SYSDIV_DIVISOR_9,
    SYSDIV_DIVISOR_10,
    SYSDIV_DIVISOR_11,
    SYSDIV_DIVISOR_12,
    SYSDIV_DIVISOR_13,
    SYSDIV_DIVISOR_14,
    SYSDIV_DIVISOR_15,
    SYSDIV_DIVISOR_16

}SYSDIV_DIVISOR;

typedef enum{

    MOSC_MAIN_OSCILLATOR_16_MHZ,
    PIOSC_PRECISION_INTERNAL_OSCILLATOR,
    PIOSC_4_PRECISION_INTERNALL_OSCILLATOR,
    LIFOSC_LOW_FREQ_INTERNAL_OSCILLATOR

}CLOCK_SOURCE;

typedef enum{

    RUN_MODE_CLOCK_CONTROL=0,
    DEEP_SLEEP_MODE_CONTROL

}SLEEP_MODE_REG_CONTROL;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
typedef enum{

    WATCH_DOG_TIMER = 0,//0
    GENERAL_PURPOUSE_TIMER_16_32=1,//1
    GENERAL_PURPOUSE_INPUT_OUTPUT=2,//2
    MICRO_DIRECT_MEMORY_ACCESS=3,//3
    HIB=5,//5
    UART=6,//6
    SSI=7,//7
    I2C=8,//8
    USB=10,//10
    CAN=13,//13
    ADC=14,//14
    ACMP=15,//15
    PWM=16,//16
    QEI=17,//17
    EEPROM=22,//22
    WTIMER_32_64=23//23

}MODULES_NAME;

typedef enum{

    MODULE_0,
    MODULE_1,
    MODULE_2,
    MODULE_3,
    MODULE_4,
    MODULE_5,
    MODULE_6,
    MODULE_7

}MODULE_INDEX;

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 
#endif  /* SCB_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SCB_Types.h
 *********************************************************************************************************************/
