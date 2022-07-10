

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SCB_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SCB_CFG_H
#define SCB_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SCB_types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
    -MOSC_MAIN_OSCILLATOR_16_MHZ
    -PIOSC_PRECISION_INTERNAL_OSCILLATOR
    -PIOSC_4_PRECISION_INTERNALL_OSCILLATOR
    -LIFOSC_LOW_FREQ_INTERNAL_OSCILLATOR
*/
#define CLOCK_SOURCE    MOSC_MAIN_OSCILLATOR_16_MHZ

/*
    CRYSTAL_VALUE_4_MHz
    CRYSTAL_VALUE_4_096_MHz 
    CRYSTAL_VALUE_4_9152_MHz 
    CRYSTAL_VALUE_5_MHz_USB
    CRYSTAL_VALUE_5_12_MHz
    CRYSTAL_VALUE_6_MHz_USB
    CRYSTAL_VALUE_6_144_MHz
    CRYSTAL_VALUE_7_3728_MHz
    CRYSTAL_VALUE_8_MHz_USB
    CRYSTAL_VALUE_8_192_MHz
    CRYSTAL_VALUE_10_MHz_USB
    CRYSTAL_VALUE_12_MHz_USB
    CRYSTAL_VALUE_12_288_MHz
    CRYSTAL_VALUE_13_56_MHz
    CRYSTAL_VALUE_14_31818_MHz
    CRYSTAL_VALUE_16_MHz_USB
    CRYSTAL_VALUE_16_384_MHz
    CRYSTAL_VALUE_18_MHz_USB
    CRYSTAL_VALUE_20_MHz _USB
    CRYSTAL_VALUE_24_MHz_USB
    CRYSTAL_VALUE_25_MHz_USB
*/
#define CRYSTAL_VALUE       CRYSTAL_VALUE_16_MHz_USB
/*
    -RUN_MODE_CLOCK_CONTROL
    -DEEP_SLEEP_MODE_CONTROL
*/
#define SLEEP_MODE_CONTROL   RUN_MODE_CLOCK_CONTROL

/*
    -USED
    -NOT_USED
*/
#define DIVIDER_STATE   USED

#define PLL_STATE   NOT_USED

#if DIVIDER_STATE == USED
/*

    -SYSDIV_DIVISOR_1
    -SYSDIV_DIVISOR_2
    -SYSDIV_DIVISOR_3
    -SYSDIV_DIVISOR_4
    -SYSDIV_DIVISOR_5
    -SYSDIV_DIVISOR_6
    -SYSDIV_DIVISOR_7
    -SYSDIV_DIVISOR_8
    -SYSDIV_DIVISOR_9
    -SYSDIV_DIVISOR_10
    -SYSDIV_DIVISOR_11
    -SYSDIV_DIVISOR_12
    -SYSDIV_DIVISOR_13
    -SYSDIV_DIVISOR_14
    -SYSDIV_DIVISOR_15
    -SYSDIV_DIVISOR_16

*/
#define SSDIV_DIVISOR       SYSDIV_DIVISOR_1
#endif

/*
    -DISABLED
    -ENABLED
*/
#define PWM_CLOCK_DIVISOR_STATE     DISABLED

#if PWM_CLOCK_DIVISOR_STATE == ENABLED

/*
    -PWM_CLOCK_DIVISOR_2
    -PWM_CLOCK_DIVISOR_4
    -PWM_CLOCK_DIVISOR_8
    -PWM_CLOCK_DIVISOR_16
    -PWM_CLOCK_DIVISOR_32
    -PWM_CLOCK_DIVISOR_64
*/
#define PWM_CLOCK_DIVISOR   PWM_CLOCK_DIVISOR_2
#endif
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
#endif  /* SCB_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: SCB_Cfg.h
 *********************************************************************************************************************/
