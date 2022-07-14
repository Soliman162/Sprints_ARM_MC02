


/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/

#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct 
{
    CHANNEL_ID_CONFIG Channel_ID;
    CHANNEL_MODE_CONFIG Channel_Mode;
    u8 Channel_MAX_BIT_NUM;//timer bit
    u8 Channel_MAX_Frequency;//shift
    void *func(void);
   
}GPT_CONFIG_TYPE;


typedef enum {

    GPT_1US_16BIT_TIMER=0,    
    GPT_1US_24BIT_TIMER,
    GPT_1US_32BIT_TIMER,
    GPT_100US_32BIT_TIMER

}GPT_TYPE_CONFIG;

typedef enum {

    CHANNEL_ID_0=0,
    CHANNEL_ID_1,
    CHANNEL_ID_2,
    CHANNEL_ID_3,
    CHANNEL_ID_4,
    CHANNEL_ID_5

}CHANNEL_ID_CONFIG;

typedef enum{

    GPT_MODE_ONE_SHOT=1,
    GPT_MODE_PERIODIC

}CHANNEL_MODE_CONFIG;



 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/

