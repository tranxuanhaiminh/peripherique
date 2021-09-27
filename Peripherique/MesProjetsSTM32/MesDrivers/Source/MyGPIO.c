#include "MyGPIO.h"

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr )	
{
    RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01<< 4) ;
		
		if (GPIOStructPtr -> GPIO_Pin <= 7 ){
			GPIOStructPtr -> GPIO -> CRL  &= ~(0xF << (GPIOStructPtr -> GPIO_Pin*4));
			
			if ((GPIOStructPtr -> GPIO_Conf) == In_Floating){
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)+2));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == In_PullDown){
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)+3));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == In_PullUp){
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)+3));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == Out_Ppull){
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == Out_OD){
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)));
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)+2));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == AltOut_Ppull){
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)));
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)+3));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == AltOut_OD){
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)));
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)+3));
				GPIOStructPtr -> GPIO -> CRL |= (0x1<<((GPIOStructPtr -> GPIO_Pin*4)+2));
			}
		}
		
		if (GPIOStructPtr -> GPIO_Pin > 7 && GPIOStructPtr -> GPIO_Pin <= 15){
			GPIOStructPtr -> GPIO -> CRH  &= ~(0xF << ((GPIOStructPtr -> GPIO_Pin-8)*4));
			
				if ((GPIOStructPtr -> GPIO_Conf) == In_Floating){
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)+2));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == In_PullDown){
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)+3));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == In_PullUp){
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)+3));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == Out_Ppull){
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == Out_OD){
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)));
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)+2));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == AltOut_Ppull){
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)));
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)+3));
			}
			if ((GPIOStructPtr -> GPIO_Conf) == AltOut_OD){
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)));
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)+3));
				GPIOStructPtr -> GPIO -> CRH |= (0x1<<(((GPIOStructPtr -> GPIO_Pin-8)*4)+2));
			}
		}
}
			

int MyGPIO_Read(GPIO_TypeDef * GPIO ,char GPIO_Pin ){
  //  renvoie 0 ou autre  chose  different de 0
		if((GPIO -> IDR) == (0x01 << GPIO_Pin)){
			return 1;
		}else{
			return 0;
		}
}

void MyGPIO_Set(GPIO_TypeDef * GPIO ,char GPIO_Pin ) 
{
		GPIO -> ODR |= (0x01 << GPIO_Pin);
}


void MyGPIO_Reset(GPIO_TypeDef * GPIO ,char GPIO_Pin ) 
{
	 GPIO -> BRR &= ~(0xF << GPIO_Pin);
}


void MyGPIO_Toggle(GPIO_TypeDef * GPIO ,char GPIO_Pin )
{
	if(MyGPIO_Read(GPIO,GPIO_Pin) == 0){
		MyGPIO_Set(GPIO,GPIO_Pin);
	}else if(MyGPIO_Read(GPIO,GPIO_Pin) == 1){
		MyGPIO_Reset(GPIO,GPIO_Pin);
		
	}
}


