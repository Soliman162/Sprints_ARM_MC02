
#include "std_types.h"
#include "BIT_MATH.h"
#include "MCU_HW.h"

#include "DIO_types.h"
#include "ADC_types.h"
#include "ADC.h" 

extern GPIO_CONFIG_REGs *GPIO_ARR[6] ;
static ADC_REGs_CONFIG  *ADC_arr[2] = {ADC0_REGs,ADC1_REGs};
const static u8 ADC_Channel_Arr[12] ={PIN_E3,PIN_E2,PIN_E1,PIN_E0,PIN_E5,PIN_E4,PIN_D3,PIN_D2,PIN_D1,PIN_D0,PIN_B4,PIN_B5};

void ADC_voidInit(const ADC_DATA_Config *Copy_Channel)
{
    /*Set AFSEL BIT*/
    GPIO_ARR[ADC_Channel_Arr[Copy_Channel->Channel_Num]/8]->GPIOAFSEL |= 1<<(Copy_Channel->Channel_Num%8);
    /*config analog input*/
    GPIO_ARR[ADC_Channel_Arr[Copy_Channel->Channel_Num]/8]->GPIODEN &= ~(1<<(Copy_Channel->Channel_Num%8));
    /*disable analog isolation circuit*/
    GPIO_ARR[ADC_Channel_Arr[Copy_Channel->Channel_Num]/8]->GPIOAMSEL |= 1<<(Copy_Channel->Channel_Num%8); 

    /*sample sequencer*/
    if(Copy_Channel->Sample_Sequencer != ADC_SAMPLE_SEQUENCER_NOT_USED )
    {
        /*Disable sample sequencer*/
        ADC_arr[Copy_Channel->ADC_port]->ADCACTSS &= ~(1<<Copy_Channel->Sample_Sequencer);
        /*configure the trigger event for the sample sequenser */
        ADC_arr[Copy_Channel->ADC_port]->ADCEMUX |= Copy_Channel->Sample_Sequencer_Priority_Trigger_Source<<(Copy_Channel->Sample_Sequencer*4);
        /* configre the input source */
        ADC_arr[Copy_Channel->ADC_port]->ADCSS_MUX_CTL_FIFO_FSTAT_OP_DC_0_1_2_3[Copy_Channel->Sample_Sequencer*8] |= Copy_Channel->Channel_Num<<(Copy_Channel->Mux_Num*4);
        ADC_arr[Copy_Channel->ADC_port]->ADCSS_MUX_CTL_FIFO_FSTAT_OP_DC_0_1_2_3[Copy_Channel->Sample_Sequencer*8+1] |= 1<<(Copy_Channel->Mux_Num*4);  
        /*The LAST SAMPLE OF THE SEQUENCE*/
        ADC_arr[Copy_Channel->ADC_port]->ADCSS_MUX_CTL_FIFO_FSTAT_OP_DC_0_1_2_3[Copy_Channel->Sample_Sequencer*8+1] |= 1<<(Copy_Channel->End_Mux_Num+1);  
        /*Sample sequencer*/
        ADC_arr[Copy_Channel->ADC_port]->ADCACTSS |= (1<<Copy_Channel->Sample_Sequencer);
    }

}
u8 Is_ADC_u8FIFO_Full(const ADC_DATA_Config *Copy_Channel)
{
    return (GET_BIT(ADC_arr[Copy_Channel->ADC_port]->ADCOSTAT,Copy_Channel->Sample_Sequencer));
}
void ADC_voidSET_SAMPLE_SEQUENCER_PRIORITY(const ADC_DATA_Config *Copy_Channel,SAMPLE_SEQUENCER_PRIORITY_TYPE Copy_Priority)
{
    ADC_arr[Copy_Channel->ADC_port]->ADCSSPRI = Copy_Priority<<(Copy_Channel->Sample_Sequencer*4);
}
void ADC_voidBegin_Sample_ON_SAMPLE_SEQUENCER(const ADC_DATA_Config *Copy_Channel)
{
    ADC_arr[Copy_Channel->ADC_port]->ADCPSSI = 1<<(Copy_Channel->Sample_Sequencer);
}
void ADC_voidBegin_ALL_Sample(const ADC_DATA_Config *Copy_Channel)
{
    ADC_arr[Copy_Channel->ADC_port]->ADCPSSI = 1<<31;
}
u8 ADC_u8GET_FIFO_DATA(const ADC_DATA_Config *Copy_Channel)
{
    return ADC_arr[Copy_Channel->ADC_port]->ADCSS_MUX_CTL_FIFO_FSTAT_OP_DC_0_1_2_3[Copy_Channel->Sample_Sequencer*8+2];
}