/******************************************************************************
 *
 * Module: dc-motor
 *
 * File Name: dc-motor.c
 *
 * Description: Source file for the dc-motor driver
 *
 * Author: Toka Mohamed
 *
 *******************************************************************************/

#include"dc-motor.h"
#include "common_macros.h"
#include "gpio.h"
#include"PWM.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description:
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver
 * Stop at the DC-Motor at the beginning through the GPIO driver
 */
void DcMotor_Init(void)
{
	/* configure pin PB0 and PB1 as output pins */
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_HIGH);
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_HIGH);

	/* Motor is stop at the beginning */
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_LOW);
}

/*
 * Description:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value
 * Send the required duty cycle to the PWM driver based on the required speed value
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/*
	 * send the compare match value to the function according to the required speed
	 */
	switch(speed)
	{
	case 0:
		PWM_Timer0_Start(0);
		break;
	case 25:
		PWM_Timer0_Start(64);
		break;
	case 50:
		PWM_Timer0_Start(128);
		break;
	case 75:
		PWM_Timer0_Start(192);
		break;
	case 100:
		PWM_Timer0_Start(255);
		break;
	}
    /*
     * configure the input pins of the motor according to the required state
     */
	if(state == stop)
	{
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_LOW);
	}
	else if(state == CW)
	{
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_LOW);
	}
	else
	{
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_HIGH);
	}

}

