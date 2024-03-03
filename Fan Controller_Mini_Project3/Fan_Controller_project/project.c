/*
 ===================================================================================================
 Module      : PROJECT
 File Name   : project.c
 Author      : Mohamed Samy
 Date        : Feb 20, 2024
 Description : Fan Controller system
 ===================================================================================================
 */

/*******************************************************************************
 *                          Include Libraries                                 *
 *******************************************************************************/
#include <avr/io.h>
#include "std_types.h"
#include "common_macros.h"
#include "gpio.h"
#include "timer0.h"
#include "dc_motor.h"
#include "adc.h"
#include "lm35.h"
#include "lcd.h"

/*******************************************************************************
 *                         Code of The Application                             *
 *******************************************************************************/
int main()
{
	uint8  tempValue=0;
	/*Define The Prescalar And The Reference Voltage We Want To Use In The In The Project  */
	ADC_ConfigType ADC_Configurations = {ADC_PRESCALER_DV_8,ADC__2V5};
	LCD_init();
	DcMotor_Init();
	ADC_init(&ADC_Configurations);
	LCD_moveCursor(0,4);
	LCD_displayString("FAN IS OFF");
	LCD_moveCursor(1,4);
	LCD_displayString("TEMP=    C");
	while(1)
	{
		tempValue = LM35_getTemperature();

		/* Speed motor according temperature value*/
		if(tempValue < 30)
		{
			LCD_moveCursor(0,11);
			LCD_displayString("OFF");
			LCD_moveCursor(1,10);
			LCD_intgerToString(tempValue);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(STOP_MOTOR,0);

		}else if(tempValue >= 30 && tempValue < 60)
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(tempValue);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(RUN_MOTOR_CW,25);

		}else if(tempValue >= 60  && tempValue < 90)
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(tempValue);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(RUN_MOTOR_CW,50);
		}else if(tempValue >= 90 && tempValue < 120)
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(tempValue);
			if(tempValue >= 90 && tempValue < 100)
			{
				LCD_displayCharacter(' ');
			}

			DcMotor_Rotate(RUN_MOTOR_CW,75);
		}else
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(tempValue);
			DcMotor_Rotate(RUN_MOTOR_CW,100);
		}
	}


return 0;
}

