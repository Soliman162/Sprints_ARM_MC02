#ifndef ADC_TYPES_H
#define ADC_TYPES_H

typedef enum{

    ADC_CHANNEL_0=0,
    ADC_CHANNEL_1, 
    ADC_CHANNEL_2, 
    ADC_CHANNEL_3, 
    ADC_CHANNEL_8, 
    ADC_CHANNEL_9, 

    ADC_CHANNEL_4, 
    ADC_CHANNEL_5, 
    ADC_CHANNEL_6, 
    ADC_CHANNEL_7, 

    ADC_CHANNEL_10,
    ADC_CHANNEL_11

}ADC_CHANNEL_TYPE;

/**************************************************************************************************************************************************/

typedef enum{

    ADC_SAMPLE_SEQUENCER_0=0,
    ADC_SAMPLE_SEQUENCER_1,
    ADC_SAMPLE_SEQUENCER_2,
    ADC_SAMPLE_SEQUENCER_3,
    ADC_SAMPLE_SEQUENCER_NOT_USED

}SAMPLE_SEQUENCER_TYPE;

/**************************************************************************************************************************************************/

typedef enum{

    ADC_0=0,
    ADC_1

}ADC_PORT_TYPE;

/**************************************************************************************************************************************************/

typedef enum{

    SAMPLE_SEQUENCER_PRIORITY_0=0,
    SAMPLE_SEQUENCER_PRIORITY_1,
    SAMPLE_SEQUENCER_PRIORITY_2,
    SAMPLE_SEQUENCER_PRIORITY_3

}SAMPLE_SEQUENCER_PRIORITY_TYPE;

/**************************************************************************************************************************************************/

typedef enum{

    EVENT=0,
    ANALOG_COMPARATOR_0,
    ANALOG_COMPARATOR_1,
    EXTERNAL_GPIO_PIN=4

}SAMPLE_SEQUENCER_TRIGGER_SOURCE;
/**************************************************************************************************************************************************/
/*

FOR (SAMPLE SEQUENCER 0) WE HAVE 8 MUX 
    *SAMPLE_SEQUENCER_MUX_NUM_0
    *SAMPLE_SEQUENCER_MUX_NUM_1
    *SAMPLE_SEQUENCER_MUX_NUM_2
    *SAMPLE_SEQUENCER_MUX_NUM_3
    *SAMPLE_SEQUENCER_MUX_NUM_4
    *SAMPLE_SEQUENCER_MUX_NUM_5
    *SAMPLE_SEQUENCER_MUX_NUM_6
    *SAMPLE_SEQUENCER_MUX_NUM_7

FOR (SAMPLE SEQUENCER 1) WE HAVE 4 MUX 
    *SAMPLE_SEQUENCER_MUX_NUM_0
    *SAMPLE_SEQUENCER_MUX_NUM_1
    *SAMPLE_SEQUENCER_MUX_NUM_2
    *SAMPLE_SEQUENCER_MUX_NUM_3

FOR (SAMPLE SEQUENCER 2) WE HAVE 4 MUX 
    *SAMPLE_SEQUENCER_MUX_NUM_0
    *SAMPLE_SEQUENCER_MUX_NUM_1
    *SAMPLE_SEQUENCER_MUX_NUM_2
    *SAMPLE_SEQUENCER_MUX_NUM_3

FOR (SAMPLE SEQUENCER 2) WE HAVE 1 MUX 
    *SAMPLE_SEQUENCER_MUX_NUM_0

*/

typedef enum{

    SAMPLE_SEQUENCER_MUX_NUM_0=0,
    SAMPLE_SEQUENCER_MUX_NUM_1,
    SAMPLE_SEQUENCER_MUX_NUM_2,
    SAMPLE_SEQUENCER_MUX_NUM_3,
    SAMPLE_SEQUENCER_MUX_NUM_4,
    SAMPLE_SEQUENCER_MUX_NUM_5,
    SAMPLE_SEQUENCER_MUX_NUM_6,
    SAMPLE_SEQUENCER_MUX_NUM_7

}SAMPLE_SEQUENCER_MUX_NUM;

/**************************************************************************************************************************************************/

typedef enum{

    SAMPLE_SEQUENCER_END_MUX_NUM_0=0,
    SAMPLE_SEQUENCER_END_MUX_NUM_1,
    SAMPLE_SEQUENCER_END_MUX_NUM_2,
    SAMPLE_SEQUENCER_END_MUX_NUM_3,
    SAMPLE_SEQUENCER_END_MUX_NUM_4,
    SAMPLE_SEQUENCER_END_MUX_NUM_5,
    SAMPLE_SEQUENCER_END_MUX_NUM_6,
    SAMPLE_SEQUENCER_END_MUX_NUM_7

}SAMPLE_SEQUENCER_END_MUX_NUM;

/**************************************************************************************************************************************************/

typedef struct{

    ADC_CHANNEL_TYPE Channel_Num;
    ADC_PORT_TYPE ADC_port;

    SAMPLE_SEQUENCER_TYPE Sample_Sequencer;
    SAMPLE_SEQUENCER_PRIORITY_TYPE Sample_Sequencer_Priority;
    SAMPLE_SEQUENCER_TRIGGER_SOURCE Sample_Sequencer_Priority_Trigger_Source;
    SAMPLE_SEQUENCER_MUX_NUM Mux_Num;
    SAMPLE_SEQUENCER_END_MUX_NUM End_Mux_Num;

}ADC_DATA_Config;


#endif