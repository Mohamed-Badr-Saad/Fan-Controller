/****************************************************
 * File name:adc.c
 * Created on: Oct 4, 2022
 *     Author: Mohamed Badr
 *description: Source file for atmega32 ADC driver
 ****************************************************/

/*******Module header file**********/
#include "adc.h"
/***********************************/

/**********header files used by this module*************/
#include "common_macros.h"
#include<avr/io.h>
#include <avr/interrupt.h> /* For ADC ISR */
/*****************************************************************/

/*******Global variables***********/
#if ADC_INTERRUPT==1
volatile uint16 g_ADC_data = 0;
#endif
/***********************************/

/*********Interrupt Service Routine**********/
#if ADC_INTERRUPT==1
ISR(ADC_vect)
{
	g_ADC_data = ADC;
}
#endif
/********************************************/

/***************Function Prototypes For private Functions**********************/

/******************************************************************************/

/*************************Functions definitions**************************/
/*
 * Description:Function to initialize ADC with the dynamic configurations mentioned in ADC_config structure
 * to configure ADC (input voltage/digital data storage position in ADC register)
 */
void ADC_init (const ADC_config *ADC_config_Ptr)
{
	ADMUX = (ADMUX & 0x3F) | ( (ADC_config_Ptr->ADC_inputVolt) << 6); /*set the required input voltage to ADC*/

	/***set the required position where the converted data will be stored in ADC register***/
	ADMUX = (ADMUX & 0xDF) | ( (ADC_config_Ptr->ADC_dataRegPosition) << 5);
	/****************************************************************************/
	ADCSRA |= (1 << ADEN); /*to enable ADC*/

#if ADC_INTERRUPT==1
	ADCSRA |= (1 << ADIE); /*to enable ADC interrupt*/
#endif
	ADCSRA = (ADCSRA & 0xF8) | (ADC_config_Ptr->ADC_prescalerValue);/*set the required prescaler value*/

}
/*
 * Description:Function to read the analog signal on the required channel and return the converted digital data
 */
uint16 ADC_readChannel (uint8 Ch_num)
{
	ADMUX = (ADMUX & 0xF8) | (Ch_num);/*set the required channel number to be converted*/
	SET_BIT(ADCSRA, ADSC);/*to start ADC conversion*/
#if ADC_INTERRUPT==0
	while (! (ADCSRA & (1 << ADIF)))/*polling until  the ADIF flag is raised*/
	{
	}
	SET_BIT(ADCSRA, ADIF);/*to clear interrupt flag*/
#endif
	return ADC;/*return the converted digital data*/

}

/*
 * Description:Function to de-activate ADC
 */
void ADC_deInit (void)
{
	ADMUX = 0;
	ADCSRA = 0;
}
/*****************************************************************/
