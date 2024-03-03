/*
 ===================================================================================================
 Module      : ADC
 File Name   : adc.c
 Author      : Mohamed Samy
 Date        : Feb 18, 2024
 ===================================================================================================
 */

/*******************************************************************************
 *                          Include Libraries                                 *
 *******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "common_macros.h"
#include "std_types.h"
#include "adc.h"
#include "gpio.h"

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*  Reference Selection Bits 	 */
	ADMUX &= ADC_REFERANCE_VOLTAGE_MASK; /* to clear the bit 7 & 6 in the ADMUX register */
	ADMUX |= ( ( Config_Ptr->ref_volt ) << 6 ); /* shift the value of  Reference voltage by 6 to but its value in the Bit 6&7*/

	uint8  channal_mask = 0b11100000;
	ADMUX &= channal_mask;
	/*	ADC Enable */
	SET_BIT(ADCSRA,ADEN);
	/*	ADC Interrupt disable */
	CLEAR_BIT(ADCSRA,ADIE);

	ADCSRA &= ADC_PRESCALER_DV_MASK;/* to clear the first 3 bits at  ADCSRA register */
	ADCSRA |= (Config_Ptr->prescaler);
}
uint16 ADC_readChannel(uint8 channal)
{
	uint8  channal_mask = 0b11100000;
	uint16 ADC_digital_value=0;


	if(channal <= 7)
	{
		/* select ADC channel	 */
		ADMUX &= channal_mask;
		ADMUX |= channal;
		/* sADC Start Conversion	 */
		SET_BIT(ADCSRA, ADSC);
		/* polling until ADIF =1		 */
		while(!  ( GET_BIT ( ADCSRA , ADIF ) ) );
		/* clear 	ADIF =0	 */
		SET_BIT(ADCSRA,ADIF);

		ADC_digital_value = ADC;
	}else
	{

	}

	return ADC_digital_value;
}
