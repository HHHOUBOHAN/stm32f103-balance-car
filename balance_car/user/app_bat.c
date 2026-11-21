#include "app_bat.h"

//
//@简介：对电池电压检测模块进行初始化
//

void App_Bat_Init(void)
{
	//1. 初始化TIM2_TRGO 每10ms产生一个脉冲
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//开启定时器2的时钟

	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct = {0};
	
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 9999;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 71;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	
	TIM_SelectOutputTrigger(TIM2,TIM_TRGOSource_Update);//主机模式选择UPDATE模式
	
	TIM_Cmd(TIM2,ENABLE);//开启TIM2的开关
	
	//2. 对ADC进行初始化（分频器 初始化IO引脚 ）
	RCC_ADCCLKConfig()
	//引脚初始化
	//ADC初始化
	//注入序列初始化
	
	
	
	
	
	
	
	
	
	
	//2. 对ADC进行初始化
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//ADC的分频系数设置为六分频
	
	//初始化ADC  左对齐 右对齐（常用）
	
	
	// 常规序列的外部触发    注入序列的外部触发 软件触发  ADC模式 双ADC模式  扫描模式  通道数
	
	//注入序列 外部触发信号 注入序列的外部触发信号的开关
	//通道8 填入注入序列通道中  通道号  优先级 采样时间 
	
}











































