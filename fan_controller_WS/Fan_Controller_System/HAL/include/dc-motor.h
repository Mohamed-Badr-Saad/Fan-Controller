/****************************************************
 *    File name: dc-motor.h
 *   Created on: Oct 6, 2022
 *       Author: Mohamed Badr
 *  Description: Header file for DC-Motor driver
 ****************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
/************Common Header Files***************/
#include "std_types.h"
/**********************************************/

/*************Static Configurations***************/
#define DC_MOTOR_INPUT1_PORT_ID PORTB_ID
#define DC_MOTOR_INPUT1_PIN_ID PIN1_ID

#define DC_MOTOR_INPUT2_PORT_ID PORTB_ID
#define DC_MOTOR_INPUT2_PIN_ID PIN2_ID

#define DC_MOTOR_ENABLE_PORT_ID PORTB_ID
#define DC_MOTOR_ENABLE_PIN_ID PIN3_ID
/*************************************************/

/************Definitions***************/


/**************************************/

/***********User defined Data Types***************/
typedef enum
{
	Stop, ClockWise, Anti_ClockWise
} DcMotor_state;
/*************************************************/

/**********Extern Public Global Variable************/

/***************************************************/

/***************Function Prototypes For Public Functions**********************/
/*
 * Description : Function to initialize pins direction and value of the DC-Motor
 */
void DcMotor_init (void);

/*
 * Description : Function to set the motor rotation state and the to set the speed of the motor
 */
void DcMotor_Rotate (DcMotor_state state , uint8 speed);
/****************************************************************************/

/***********Macros***********/

/****************************/

#endif /* DC_MOTOR_H_ */
