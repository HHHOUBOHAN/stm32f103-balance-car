#include "stm32f10x.h"
#include "bat_test.h"
#include "app_bat.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
//	Bat_Test();
	App_Bat_Init();
	
	while(1)
	{
		App_Bat_Proc();
	}
}
