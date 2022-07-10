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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
#define     DISABLED		0
#define     ENABLED			1

#define  NOT_USED		0
#define  USED				1

#define    MOSC_MAIN_OSCILLATOR_16_MHZ						0
#define    PIOSC_PRECISION_INTERNAL_OSCILLATOR		1
#define 	 PIOSC_4_PRECISION_INTERNALL_OSCILLATOR 2
#define    LIFOSC_LOW_FREQ_INTERNAL_OSCILLATOR		3

#define    RUN_MODE_CLOCK_CONTROL		0
#define    DEEP_SLEEP_MODE_CONTROL	1

typedef enum{

    CRYSTAL_VALUE_4_MHz=6, 
    CRYSTAL_VALUE_4_096_MHz, 
    CRYSTAL_VALUE_4_9152_MHz, 
    CRYSTAL_VALUE_5_MHz_USB,
    CRYSTAL_VALUE_5_12_MHz,
    CRYSTAL_VALUE_6_MHz_USB,
    CRYSTAL_VALUE_6_144_MHz,
    CRYSTAL_VALUE_7_3728_MHz,
    CRYSTAL_VALUE_8_MHz_USB,
    CRYSTAL_VALUE_8_192_MHz,
    CRYSTAL_VALUE_10_MHz_USB,
    CRYSTAL_VALUE_12_MHz_USB,
    CRYSTAL_VALUE_12_288_MHz,
    CRYSTAL_VALUE_13_56_MHz,
    CRYSTAL_VALUE_14_31818_MHz,
    CRYSTAL_VALUE_16_MHz_USB,
    CRYSTAL_VALUE_16_384_MHz,
    CRYSTAL_VALUE_18_MHz_USB,
    CRYSTAL_VALUE_20_MHz_USB,
    CRYSTAL_VALUE_24_MHz_USB,
    CRYSTAL_VALUE_25_MHz_USB

}CRYSTAL_VALUE_CONFIG;

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

    PWM_CLOCK_DIVISOR_2=0,
    PWM_CLOCK_DIVISOR_4,
    PWM_CLOCK_DIVISOR_8,
    PWM_CLOCK_DIVISOR_16,
    PWM_CLOCK_DIVISOR_32,
    PWM_CLOCK_DIVISOR_64

}PWM_CLOCK_DIVISOR_config;


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
    USB_SCB=10,//10
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
