#include "stm32f10x.h"
#include "MyTimer.h"
#include "MyGPIO.h"

u16 var;


	void IT_function (void)
	{

	}
	
	
int main(void)
{

	MyTimer_Struct_TypeDef Timer_Struct = {TIM2, 0xFFAD, 0x0225};
	
	MyTimer_Base_Init(&Timer_Struct);
	MyTimer_Base_Start(Timer_Struct.Timer);
	MyTimer_ActiveIT(Timer_Struct.Timer,7,(*IT_function));
	

while(1) {

	var = Timer_Struct.Timer->CNT;

		}

}


