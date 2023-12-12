/****************************************************
 * File name:adc.h
 * Created on: Oct 4, 2022
 *     Author: Mohamed Badr
 *description: Header file for atmega32 ADC driver
 ****************************************************/

#ifndef ADC_H_
#define ADC_H_
/************Common Header Files***************/
#include"std_types.h"

/**********************************************/

/*************Static Configurations***************/
#define ADC_MAX_DATA 1023
#define ADC_AREF_VALUE (2.56)
#define ADC_INTERRUPT 0
/*************************************************/

/************Definitions***************/
#define ADC_DATA_REG_RIGHT 0
#define ADC_DATA_REG_LEFT 1
/**************************************/

/***********User defined Data Types***************/
typedef enum
{
	AREF = 0, AVCC_5V = 1, INTERNAL_VOLT_2_56V = 3
} ADC_vRef;

typedef enum
{
	ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7
} ADC_channelNum;

typedef enum
{
	ADC_F_CPU_2_0,
	ADC_F_CPU_2_1,
	ADC_F_CPU_4,
	ADC_F_CPU_8,
	ADC_F_CPU_16,
	ADC_F_CPU_32,
	ADC_F_CPU_64,
	ADC_F_CPU_128
} ADC_clock;

typedef struct
{
	ADC_vRef ADC_inputVolt;
	ADC_channelNum ADC_channelNum;
	ADC_clock ADC_prescalerValue;
	uint8 ADC_dataRegPosition;
} ADC_config;   /*structure contain the dynamic configurations of the ADC*/
/*************************************************/

/**********Extern Public Global Variable************/
extern volatile uint16 g_ADC_data;
/***************************************************/

/***************Function Prototypes For Public Functions**********************/
/*
 * Description:Function to initialize ADC with the dynamic configurations mentioned in ADC_config structure
 */
void ADC_init (const ADC_config *ADC_config_Ptr);

/*
 * Description:Function to read the analog signal on the required channel and return the converted digital data
 */
uint16 ADC_readChannel (uint8 Ch_num);

/*
 * Description:Function to de-activate ADC
 */
void ADC_deInit (void);
/****************************************************************************/

/***********Macros***********/

/****************************/

#endif /* ADC_H_ */
