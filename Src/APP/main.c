#include "IntCtrl.h"
#include "SYS_Ctrl.h"
#include "DIO.h"
#include "GPT.h"

static GPT_CONFIG_TYPE TIMER_0 = {CHANNEL_ID_0,GPT_MODE_PERIODIC};
static GPT_CONFIG_TYPE TIMER_1 = {CHANNEL_ID_1,GPT_MODE_PERIODIC};

static PORT_CONFIG_TYPE LED_0  = {PIN_F1,GPIO_OUTPUT,PULL_UP,OUT_PUT_CURRENT_STREGNTH_8MA};

static u32 ON_u32Time = 0;
static u32 OFF_u32Time = 0;

void Led_voidCtrl(u16 ON_u16Time, u16 OFF_u16Time);

void Timer_0A_ISR(void);
void Timer_1A_ISR(void);

	
int main(void)
{
	/*
	
	SYS_Ctrl:-
		0x400FE000, 0x400FEA5C
	
	GPT:-
		 16/32-bit Timer 0: 0x40030000,	0x40030FC0	
		 16/32-bit Timer 1: 0x40031000,	0x40031FC0
		 16/32-bit Timer 2: 0x40032000,	0x40032FC0
		 16/32-bit Timer 3: 0x40033000,	0x40033FC0
		 16/32-bit Timer 4: 0x40034000,	0x40034FC0
		 16/32-bit Timer 5: 0x40035000,	0x40035FC0
	
	GPIO:-
		0x40000000, 0x4000FFFF
	
	*/
	Init_voidIntCtrl();

	 Init_voidSYS_Ctrl_Clock();
	 SYS_Ctrl_voidEnable_Clock_Run_Mode( GENERAL_PURPOUSE_INPUT_OUTPUT,  MODULE_5);
	 SYS_Ctrl_voidEnable_Clock_Run_Mode( GENERAL_PURPOUSE_TIMER_16_32,  MODULE_0);
	 SYS_Ctrl_voidEnable_Clock_Run_Mode( GENERAL_PURPOUSE_TIMER_16_32,  MODULE_1);
	
    DIO_voidInit_Pin(&LED_0);
	
    Init_voidGPT(&TIMER_0);
		Init_voidGPT(&TIMER_1);
/*
    GPT_voidEnableInterrupt(&TIMER_0);
	  GPT_voidEnableInterrupt(&TIMER_1);
*/
		Led_voidCtrl( 3 , 1  );
		
    while (1)
    {
			Timer_1A_ISR();
			
			Timer_0A_ISR();
			

			/*
       if(GET_voidRemainingTime(&TIMER_0)==0)
			 {
				  DIO_voidWriteChannel(LED_0.Pin_Number,DIO_LOW);
				 GPT_voidStop_Timer(&TIMER_0);
					GPT_voidStart_Timer(&TIMER_1,OFF_u32Time);
				 
			 }else if(GET_voidRemainingTime(&TIMER_1) == 0)
			 {
				     DIO_voidWriteChannel(LED_0.Pin_Number,DIO_HIGH);
				 				 GPT_voidStop_Timer(&TIMER_1);
						 GPT_voidStart_Timer(&TIMER_0,ON_u32Time);
			 }
				 */
    }
		
		return 0;
		
}

void Timer_0A_ISR(void)
{
		DIO_voidWriteChannel(LED_0.Pin_Number,DIO_LOW);
		GPT_voidStart_Timer(&TIMER_1,OFF_u32Time );
		while(Is_u8Timer_Finish(&TIMER_1) != 1);
		GPT_voidStop_Timer(&TIMER_1);
		CLR_voidInterrupt_Flag(&TIMER_1);
}
void Timer_1A_ISR(void)
{
    DIO_voidWriteChannel(LED_0.Pin_Number,DIO_HIGH);
    GPT_voidStart_Timer(&TIMER_0,ON_u32Time);
		while(Is_u8Timer_Finish(&TIMER_0) != 1);
		GPT_voidStop_Timer(&TIMER_0);
		CLR_voidInterrupt_Flag(&TIMER_0);
}

void Led_voidCtrl(u16 Copy_u16ONTime, u16 Copy_u16OFFTime)
{
    OFF_u32Time = Copy_u16OFFTime*1000;
    ON_u32Time = Copy_u16ONTime*1000 ;
}






