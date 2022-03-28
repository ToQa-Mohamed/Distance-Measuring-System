/*
 *  miniproject3.c
 *  Created on: Oct 15, 2021
 *  Author: Toka Mohamed
 */
#include "lcd.h"
#include "adc.h"
#include"dc-motor.h"
#include "lm35_sensor.h"


int main(void)
{
	ADC_ConfigType adc_config={INTERNAL,F_CPU_8}; /*choose the internal Vref 2.56 and prescaler Fcpu/8*/
	uint8 temp;  /*to get the digital value of the temperature*/
	DcMotor_State state;
	uint8 speed;
	LCD_init(); /* initialize LCD driver */
	ADC_init(&adc_config); /* initialize ADC driver */
	DcMotor_Init();/* initialize dc-motor driver */

	/* Display this string only once on LCD */
	LCD_moveCursor(0,5);
	LCD_displayString("FAN is ");
	LCD_moveCursor(1,5);
	LCD_displayString("Temp =    C");
	while(1)
	    {
	    	temp = LM35_getTemperature();
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,12);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
                /*from 100->99 or from 10->9 the last number"0" is replaced by space*/
				LCD_displayCharacter(' ');
			}

			if(temp<30)
			{
				state=stop; /*stop the motor*/
				speed=0; /*speed is 0% of the max speed*/
				LCD_displayStringRowColumn(0,12,"OFF");
				DcMotor_Rotate(state,speed);
			}
			else if(temp>=30 && temp<60)
			{
				state=CW; /*rotate the motor in clockwise direction*/
				speed=25; /*speed is 25% of the max speed*/
				LCD_displayStringRowColumn(0,12,"ON ");
				DcMotor_Rotate(state,speed);
			}
			else if(temp>=60 && temp<90)
			{
				state=CW; /*rotate the motor in clockwise direction*/
				speed=50; /*speed is 50% of the max speed*/
				LCD_displayStringRowColumn(0,12,"ON ");
				DcMotor_Rotate(state,speed);
			}
			else if(temp>=90 && temp<120)
			{
				state=CW; /*rotate the motor in clockwise direction*/
				speed=75; /*speed is 75% of the max speed*/
				LCD_displayStringRowColumn(0,12,"ON ");
				DcMotor_Rotate(state,speed);
			}
			else
			{
				state=CW;  /*rotate the motor in clockwise direction*/
				speed=100; /*speed is 100% of the max speed*/
				LCD_displayStringRowColumn(0,12,"ON ");
				DcMotor_Rotate(state,speed);
			}

	    }

}







