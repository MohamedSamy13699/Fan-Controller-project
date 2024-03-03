/*
 ===================================================================================================
 Module      : LM35
 File Name   : lm35.c
 Author      : Mohamed Samy
 ===================================================================================================
 */

/*******************************************************************************
 *                          Include Libraries                                 *
 *******************************************************************************/
#include <avr/io.h>
#include "lm35.h"
#include "std_types.h"
#include "adc.h"

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
uint8 LM35_getTemperature(void)
{
	uint8 Temp_SensorValue =0;
	uint16 ADC_digitalValue=0;
	ADC_digitalValue = ADC_readChannel(SENSOR_CHANNEL_ID);

	Temp_SensorValue = (uint8)( ( (uint32)ADC_digitalValue * SENSOR_MAX_TEMPERATURE * ADC_REF_VOLT_VALUE )/(SENSOR_MAX_VOLT_VALUE * ADC_MAXIMUM_VALUE) );
	return Temp_SensorValue;
}
