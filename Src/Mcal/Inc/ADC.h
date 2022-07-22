#ifndef ADC_H
#define ADC_H

#include "std_types.h" 
#include "ADC_types.h"

void ADC_voidInit(const ADC_DATA_Config *Copy_Channel);
u8 Is_ADC_u8FIFO_Full(const ADC_DATA_Config *Copy_Channel);
void ADC_voidSET_SAMPLE_SEQUENCER_PRIORITY(const ADC_DATA_Config *Copy_Channel,SAMPLE_SEQUENCER_PRIORITY_TYPE Copy_Priority);
void ADC_voidBegin_Sample_ON_SAMPLE_SEQUENCER(const ADC_DATA_Config *Copy_Channel);
void ADC_voidBegin_ALL_Sample(const ADC_DATA_Config *Copy_Channel);
u8 ADC_u8GET_FIFO_DATA(const ADC_DATA_Config *Copy_Channel);

#endif