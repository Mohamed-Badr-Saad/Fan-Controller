/****************************************************
 *    File name: dc-motor.c
 *   Created on: Oct 6, 2022
 *       Author: Mohamed Badr
 *  Description: Source file for DC-Motor driver
 ****************************************************/

/*******Module header file**********/
#include "dc-motor.h"
/***********************************/

/**********Other Modules header files used by this module*************/
#include "gpio.h"
#include "timer0.h"
/*****************************************************************/

/**********header files used by this module*************/
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
 * Description : Function to initialize pins direction and value of the DC-Motor
 */
void DcMotor_init (void)
{
	/*make PB1,PB2 output pins to determine the state of the motor*/
	GPIO_setupPinDirection(DC_MOTOR_INPUT1_PORT_ID, DC_MOTOR_INPUT1_PIN_ID,
			PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_INPUT2_PORT_ID, DC_MOTOR_INPUT2_PIN_ID,
			PIN_OUTPUT);
	/*********************************************************************/

	/*make the motor stops at the start*/
	GPIO_writePin(DC_MOTOR_INPUT1_PORT_ID, DC_MOTOR_INPUT1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_INPUT2_PORT_ID, DC_MOTOR_INPUT2_PIN_ID, LOGIC_LOW);
	/*********************************/
}

/*
 * Description : Function to set the motor rotation state and the to set the speed of the motor
 */
void DcMotor_Rotate (DcMotor_state state , uint8 speed)
{
	PORTB = (PORTB & 0xF9) | (state << 1);/*to set the rotation state of the motor*/
	PWM_Timer0_Start(speed);/*to set the speed of the motor*/
}

/*****************************************************************/
