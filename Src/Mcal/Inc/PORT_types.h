/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/

#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "DIO_types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum{

    DIO=0,
    UART=1,
    ADC=2,
    I2C=3,
    DMA=5,
    CAN=8

}PIN_MODE_TYPE;

typedef enum{

    UART0_A0_RX=PIN_A0,
    UART0_A1_TX=PIN_A1,

    UART1_B0_RX=PIN_B0,
    UART1_B1_TX=PIN_B1,

    UART4_C4_RX=PIN_C4,
    UART4_C5_TX=PIN_C5,

    UART3_C6_RX=PIN_C6,
    UART3_C7_TX=PIN_C7,

    UART6_D4_RX=PIN_D4,
    UART6_D5_TX=PIN_D5,

    UART2_D6_RX=PIN_D6,
    UART2_D7_TX=PIN_D7,

    UART7_E0_RX=PIN_E0,
    UART7_E1_TX=PIN_E1,

    UART5_E4_RX=PIN_E4,
    UART5_E5_TX=PIN_E5,

    CAN1_A0_RX=PIN_A0,
    CAN1_A1_TX=PIN_A1,

    CAN0_B4_RX=PIN_B4,
    CAN0_B5_TX=PIN_B5,

    CAN0_E4_RX=PIN_E4,
    CAN0_E5_TX=PIN_E5,

    I2C1_A6_SCL=PIN_A6,
    I2C1_A7_SDA=PIN_A7,

    I2C0_B2_SCL=PIN_B2,
    I2C0_B3_SDA=PIN_B3,


    I2C3_D0_SCL=PIN_D0,
    I2C3_D1_SDA=PIN_D1,

    I2C2_E4_SCL=PIN_E4,
    I2C2_E5_SDA=PIN_E5

}PIN_MODE_CONFIG_TYPE;

typedef enum{

    OUT_PUT_CURRENT_STREGNTH_2MA=0,
    OUT_PUT_CURRENT_STREGNTH_4MA,
    OUT_PUT_CURRENT_STREGNTH_8MA

}PIN_OUTPUT_CURRENT;

typedef enum{

    GPIO_INPUT=0,
    GPIO_OUTPUT

}PIN_DIRECTION_TYPE;

typedef enum{

    OPEN_DRAIN=0,
    PULL_UP,
    PULL_DOWN,
    SLEW_RATE


}PIN_INTERNAL_ATTACHMENT_TYPE;

 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT_Types.h
 *********************************************************************************************************************/

