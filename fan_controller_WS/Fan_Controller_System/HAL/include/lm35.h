/***************************************************
 * File name: lm35.h
 * Created on: Oct 6, 2022
 *     Author: Mohamed Badr
 *Description: Header file for LM35 sensor driver
 ****************************************************/

#ifndef LM35_H_
#define LM35_H_
/************Common Header Files***************/
#include"std_types.h"

/**********************************************/

/*************Static Configurations***************/
#define LM35_TO_ADC_CHANNEL_ID 2
#define LM35_MAX_TEMPERATURE 150
#define LM35_MAX_VOLT 1.5
/*************************************************/

/************Definitions***************/

/**************************************/

/***********User defined Data Types***************/
/*
 * Description : Function to
 * 1-read the digital data(converted from analog signal coming from the sensor)
 * 2-return the temperature
 */
uint8 LM35_GetTemperature(void);
/*************************************************/

/**********Extern Public Global Variable************/

/***************************************************/

/***************Function Prototypes For Public Functions**********************/

/****************************************************************************/

/***********Macros***********/

/****************************/


#endif /* LM35_H_ */
