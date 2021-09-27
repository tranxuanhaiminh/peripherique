#include "stm32f10x.h"              
#include "MyGPIO.h"
int main(void)
{
MyGPIO_Struct_TypeDef GPIO_Struct;
MyGPIO_Struct_TypeDef GPIO_Struct2;
	
GPIO_Struct.GPIO=GPIOC;
GPIO_Struct.GPIO_Pin=8;
GPIO_Struct.GPIO_Conf = In_Floating;
	
GPIO_Struct2.GPIO=GPIOC;
GPIO_Struct2.GPIO_Pin=10;
GPIO_Struct2.GPIO_Conf = Out_Ppull;
	
MyGPIO_Init(& GPIO_Struct);
MyGPIO_Init(& GPIO_Struct2);
	


while(1) {
	//Code pour allumer la LED en apuyant le BP externe	
	MyGPIO_Read(GPIO_Struct.GPIO,GPIO_Struct.GPIO_Pin);
	MyGPIO_Set(GPIO_Struct2.GPIO,GPIO_Struct2.GPIO_Pin);
		
	
	
}
}


