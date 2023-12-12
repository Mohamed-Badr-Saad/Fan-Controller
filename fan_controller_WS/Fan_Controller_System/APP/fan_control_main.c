/****************************************************
 *    File name: fan_control.c
 *   Created on: Oct 6, 2022
 *       Author: Mohamed Badr
 *  Description: Program to
 *  1-control the the speed of the fan according to temperature
 *  2-show the fan status and the temperature on LCD
 ****************************************************/

/**********Include the modules header files required by this program*********/
#include "lcd.h"
#include "adc.h"
#include "lm35.h"
#include "dc-motor.h"
#include "timer0.h"
/****************************************************************/

/*/**********Other header files used by this program*************/
#include <avr/io.h>
/****************************************************************/

typedef enum
{
	OFF, ON
} FAN_stateType;

int main (void)
{
	int temperature = 0;
	FAN_stateType FAN_state = OFF; /*make the fan in OFF state at the start */
	/*****Set ADC configurations******/
	ADC_config ADC_configurations;
	ADC_configurations.ADC_channelNum = ADC2; /*make the ADC works on channel 2*/
	ADC_configurations.ADC_dataRegPosition = ADC_DATA_REG_RIGHT;/*make the converted data stored in the right part in ADC register*/
	ADC_configurations.ADC_inputVolt = INTERNAL_VOLT_2_56V;/*make the input voltage to the ADC = 2.56v*/
	ADC_configurations.ADC_prescalerValue = ADC_F_CPU_8; /*  make the input frequency to ADC = F_CPU/8 = 125KHz   */
	/**********************************/
	ADC_init(&ADC_configurations); /*initialize ADC driver*/

	LCD_init();/*initialize LCD to operate in 2 lines 8 bit mode */

	DcMotor_init();/*initialize pins direction in the micro-controller to make the motor operate in the required state*/

	while (1)
	{
		/******Display the state of the Fan******/
		LCD_moveCursor(0, 3);
		FAN_state == OFF ?
				LCD_diplaystring("Fan is OFF") : LCD_diplaystring("Fan is ON ");
		/*****************************************/

		temperature = LM35_GetTemperature();/*read the temperature from the sensor*/

		/**************Display the temperature**************/
		LCD_moveCursor(1, 3);/*make the cursor of the LCD in the second column*/
		LCD_diplaystring("Temp = ");
		LCD_integerToString(temperature);/*display the temperature on LCD*/
		LCD_diplaystring(" C ");
		/**************************************************/
		if (temperature < 30)
		{
			FAN_state = OFF; /*Fan will turn OFF*/
			DcMotor_Rotate(Stop, 0);
		}
		else if (temperature >= 30 && temperature < 60)
		{
			FAN_state = ON; /*Fan will turn ON*/
			DcMotor_Rotate(ClockWise, 25); /*Fan will rotate with 25% of its maximum speed*/
		}
		else if (temperature >= 60 && temperature < 90)
		{
			FAN_state = ON; /*Fan will turn ON*/
			DcMotor_Rotate(ClockWise, 50); /*Fan will rotate with 50% of its maximum speed*/
		}
		else if (temperature >= 90 && temperature < 120)
		{
			FAN_state = ON; /*Fan will turn ON*/
			DcMotor_Rotate(ClockWise, 75); /*Fan will rotate with 75% of its maximum speed*/
		}
		else
		{
			FAN_state = ON; /*Fan will turn ON*/
			DcMotor_Rotate(ClockWise, 100); /*Fan will rotate with 100% of its maximum speed*/
		}

	}

}

