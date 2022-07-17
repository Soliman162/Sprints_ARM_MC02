
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "BIT_MATH.h"
#include "MCU_HW.h"
#include "WDT_types.h"
#include "WDT_Cfg.h"   
#include "WDT.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
WDT_REGs_CONFIG *WDT_arr[2] = {WDT0_REGs,WDT1_REGs}; 
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void WDT_voidInit(void)
{
    /*Load init value*/
    WDT_arr[WDT_MODULE_INDEX]->WDTLOAD = WDT_INIT_TIME_OUT_M_SEC;
        /*wait until write finished*/
    #if WDT_MODULE_INDEX == WDT_INDEX_1
        while(GET_BIT( WDT_arr[WDT_MODULE_INDEX]->WDTCTL , 31)!=1);
    #endif
    /*enable/disable reset*/
    #if     WDT_RESET_STATE == ENABLED
        WDT_arr[WDT_MODULE_INDEX]->WDTCTL |= 2;
    #elif   WDT_RESET_STATE == DISABLED
        WDT_arr[WDT_MODULE_INDEX]->WDTCTL &= ~2;
    #endif
    /*wait until write finished*/
    #if WDT_MODULE_INDEX == WDT_INDEX_1
        while(GET_BIT( WDT_arr[WDT_MODULE_INDEX]->WDTCTL , 31)!=1);
    #endif
    /*determine intrrupt type*/
    #if WDT_INTRRUPT_TYPE == WDT_STANDARD_INTRRUPT
        WDT_arr[WDT_MODULE_INDEX]->WDTCTL &= ~1<<2;
    #elif   WDT_INTRRUPT_TYPE == WDT_NMI
        WDT_arr[WDT_MODULE_INDEX]->WDTCTL |= 1<<2;
    #endif
    /*wait until write finished*/
    #if WDT_MODULE_INDEX == WDT_INDEX_1
        while(GET_BIT( WDT_arr[WDT_MODULE_INDEX]->WDTCTL , 31)!=1);
    #endif
    /*Enable intrrupt ,WDT*/
    WDT_arr[WDT_MODULE_INDEX]->WDTCTL |= 1;

}
void WDT_voidSet_Trigger_Conditon(u16 Copy_u16timeout)
{
   WDT_arr[WDT_MODULE_INDEX]->WDTLOAD = Copy_u16timeout;
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/





















