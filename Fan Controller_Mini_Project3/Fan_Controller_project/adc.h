/*
 ===================================================================================================
 Module      : ADC
 File Name   : adc.h
 Author      : Mohamed Samy
 Date        : Feb 18, 2024
 ===================================================================================================
 */
#ifndef ADC_H_
#define ADC_H_

/*******************************************************************************
 *                          Include Libraries                                 *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE   		 1023
#define ADC_REF_VOLT_VALUE  		 2.56
#define ADC_REFERANCE_VOLTAGE_MASK   0x3F /* to clear the bit 7 & 6 in the register*/
#define ADC_PRESCALER_DV_MASK		 0xF8 /*clear first 3 bits at register*/
/*******************************************************************************
 *                       ADC Configurations                                     *
 *******************************************************************************/

typedef enum
{    AVCC     = 0,
	 AREF_PIN = 1,
	 ADC__2V5 = 3
}ADC_ReferenceVolatge;

/* Enum to  Select division factor   */
typedef enum
{
	ADC_PRESCALER_DV_2 =1,
	ADC_PRESCALER_DV_4,
	ADC_PRESCALER_DV_8,
	ADC_PRESCALER_DV_16,
	ADC_PRESCALER_DV_32	,
	ADC_PRESCALER_DV_64	,
	ADC_PRESCALER_DV_128
}ADC_Prescaler;

/* struct LIst to configure the ADC */
typedef struct
{
	  ADC_ReferenceVolatge ref_volt;
	  ADC_Prescaler       prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description : Synchronous function
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description : Synchronous function
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channal);

#endif /* ADC_H_ */
