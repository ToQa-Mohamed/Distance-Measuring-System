/******************************************************************************
 *
 * Module: dc-motor
 *
 * File Name: dc-motor.h
 *
 * Description: Header file for the dc-motor driver
 *
 * Author: Toka Mohamed
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* DC MOTOR HW Ports and Pins Ids */
#define MOTOR_PORT_ID PORTB_ID
#define MOTOR_PIN1_ID PIN0_ID
#define MOTOR_PIN2_ID PIN1_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	stop,CW,A_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver
 * Stop at the DC-Motor at the beginning through the GPIO driver
 */
void DcMotor_Init(void);
/*
 * Description:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value
 * Send the required duty cycle to the PWM driver based on the required speed value
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /*DC_MOTOR_H_*/


