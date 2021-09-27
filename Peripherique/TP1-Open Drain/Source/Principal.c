#include "stm32f10x.h"
int main(void)
{
RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01<< 4) ;
	
//	Configuration du BP externe - input 
	//mise à 0 tous les bits b3 b2 b1 b0
	GPIOC -> CRH &= ~(0xF << 0);
	//mise à 1 le bit b2
	GPIOC -> CRH |= (0x1<<2);

// Configuration du LED externe - Output Open Drain
	//mise à 0 tous les bits b11 b10 b9 b8
	GPIOC -> CRH &= ~(0xF << 8);
	//mise à 1 les bit b10 b8
	GPIOC -> CRH |= (0x1<<10)|(0x1<<8);

while(1) {
	//Code pour allumer la LED en apuyant le BP externe	
	if (GPIOC -> IDR & (0x1 << 8)) {

			GPIOC -> ODR |= (0x1 << 10);
		
	}else { 
			GPIOC -> ODR &= ~(0x1 << 10);
		}
}
}


