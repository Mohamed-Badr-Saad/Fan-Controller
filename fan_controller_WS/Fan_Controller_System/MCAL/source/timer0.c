/****************************************************
 *    File name: timer0.c
 *   Created on: Oct 6, 2022
 *       Author: Mohamed Badr
 *  Description: Source file for atmega32 TIMER0 driver
 ****************************************************/

/*******Module header file**********/
#include "timer0.h"
/***********************************/

/**********Other Module header files used by this module*************/
#include "gpio.h"
#include <avr/io.h>

/*****************************************************************/

/*******Global variables***********/

/***********************************/

/*********Interrupt Service Routine**********/

/********************************************/

/***************Function Prototypes For private Functions**********************/

/******************************************************************************/

/*************************Functions definitions**************************/
/*
 * Description :Function to initialize timer0 in PWM mode
 * 	TIMER0 CONFIGURATION
 *
 * PWM MODE ==>  FOC0=0,WGM00=1,WGM01=1
 * NON-INVERTING MODE ==> COM00=0,COM01=1
 * Ftimer0=Fcpu/256*N
 * N=8 ==> CS00=0,CS01=1,CS02=0
 */

void PWM_Timer0_Start (uint8 dutyCycle)
{
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01);/*PWM/non-inverting mode*/
	TCCR0 = (TCCR0 & 0xF8) | (TIMER0_CLOCK_PRESCALER);/*prescaler = 8*/
	TCNT0 = 0; /*timer0 initial  value*/
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);/*make PB3(OC0) output PIN */
	if (dutyCycle == 100)
	{
		OCR0 = 255;/*maximum generated voltage*/
	}
	else
	{
		OCR0 = dutyCycle * 256 / 100;
	}
}

/*****************************************************************/
