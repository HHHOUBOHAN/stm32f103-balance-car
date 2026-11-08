#include "stm32f10x.h"
#include "bat_test.h"
#include "app_bat.h"
#include "app_button.h"
#include "app_pwm.h"
#include "pwm_test.h"
#include "encoder_test.h"
#include "mpu6050_test.h"
#include "qmath_test.h"
#include "app_encoder.h"
#include "app_motor.h"
#include "delay.h"
#include "app_usart2.h"

static float targetOmega = 0.0f;

static void USART2_Proc(void);

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
//	QMath_Test();
//	MPU6050_EularAngleTest();
//	MPU6050_Test();
//	Encoder_T_Method_Test();
//	Encoder_M_Method_Test();
//	Encoder_Test();
//	Bat_Test();
//	PWM_Test();
	App_USART2_Init();
	App_Button_Init();
	App_Encoder_Init();
	App_PWM_Init();
	App_Bat_Init();
	App_Motor_Init();
	
	while(1)
	{
		targetOmega = (GetTick() / 1000) % 10 * 2.0f;
		
		App_Motor_SetOmega_L(targetOmega);
		App_Motor_SetOmega_R(targetOmega);
		
		App_Bat_Proc();
		App_Button_Proc();
		App_Motor_Proc();
		USART2_Proc();
	}
}

static void USART2_Proc(void)
{
	float omega_l = App_Encoder_GetSpeed_L();
	float omega_r = App_Encoder_GetSpeed_R();
	
	My_USART_Printf(USART2, "%.3f,%.3f,%.3f\n", targetOmega, omega_l, omega_r);
}
