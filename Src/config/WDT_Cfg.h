/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef WDT_CFG_H
#define WDT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "WDT_types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*****************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#define WDT_MAX_TIME_OUT_M_SEC      10000
#define WDT_INIT_TIME_OUT_M_SEC     5000

/*
    -WDT_INDEX_0
    -WDT_INDEX_1
*/
#define     WDT_MODULE_INDEX    WDT_INDEX_0

/*
    -ENABLED          
    -DISABLED     
*/
#define WDT_RESET_STATE     ENABLED

#define WDT_INTRRUPT_TYPE   WDT_STANDARD_INTRRUPT


#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
