
#include "IntCtrl.h"
#include "SYS_Ctrl.h"
#include "DIO.h"
#include "GPT.h"


GPT_CONFIG_TYPE TIMER_0 = {CHANNEL_ID_0,GPT_MODE_ONE_SHOT};
GPT_CONFIG_TYPE TIMER_1 = {CHANNEL_ID_1,GPT_MODE_ONE_SHOT};
PORT_CONFIG_TYPE LED_0  = {PIN_A1,GPIO_OUTPUT,PULL_UP,OUT_PUT_CURRENT_STREGNTH_8MA};

u16 ON_u16Time = 0;
u16 OFF_u16Time = 0;

void Led_voidCtrl(u16 ON_u16Time, u16 OFF_u16Time);

int main(void)
{
    DIO_voidInit_Pin(&LED_0);
    Init_voidGPT(&TIMER_0);

    GPT_voidEnableInterrupt(&TIMER_0);

    Led_voidCtrl( 3 , 1  );

    while (1)
    {
        /* code */
    }
	return 0;
}

void Led_voidCtrl(u16 Copy_u16ONTime, u16 Copy_u16OFFTime)
{
    OFF_u16Time = Copy_u16OFFTime;
    ON_u16Time = Copy_u16ONTime ;
    DIO_voidWriteChannel(LED_0.Pin_Number,DIO_HIGH);
    GPT_voidStart_Timer(&TIMER_0,ON_u16Time);
}

void Timer0_ISR(void)
{
    DIO_voidWriteChannel(LED_0.Pin_Number,DIO_LOW);
    GPT_voidStart_Timer(&TIMER_1,OFF_u16Time);
}

void Timer1_ISR(void)
{
    DIO_voidWriteChannel(LED_0.Pin_Number,DIO_HIGH);
    GPT_voidStart_Timer(&TIMER_0,ON_u16Time);

}