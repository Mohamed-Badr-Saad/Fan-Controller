/*****************************************************
 * File name: lm35.c
 * Created on: Oct 6, 2022
 *     Author: Mohamed Badr
 *Description: Source file for LM35 sensor driver
 ****************************************************/

/*******Module header file**********/
#include "lm35.h"

/***********************************/

/**********Other Modules header files used by this module*************/
#include "adc.h"
/*****************************************************************/

/*******Global variables***********/

/***********************************/

/*********Interrupt Service Routine**********/

/********************************************/

/***************Function Prototypes For private Functions**********************/

/******************************************************************************/

/*************************Functions definitions**************************/
/*
 * Description : Function to
 * 1-read the digital data(converted from analog signal coming from the sensor)
 * 2-return the temperature
 */
uint8 LM35_GetTemperature (void)
{
	uint8 temperature = 0;
	uint16 ADC_data = 0;
	ADC_data = ADC_readChannel(LM35_TO_ADC_CHANNEL_ID);
	temperature = (uint8) ( ((uint32) ADC_data * LM35_MAX_TEMPERATURE
			* ADC_AREF_VALUE) / (LM35_MAX_VOLT * ADC_MAX_DATA));
	return temperature;
}
/**********************************************************************/
