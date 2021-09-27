#include "MyTimer.h"


void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer1)
{

	if (Timer1->Timer == (TIM1)){
		
		//Brancher les horloges CLK = 1 <=> TIM1
			RCC->APB2ENR |=  (0x01 <<11);
		
	}else if (Timer1->Timer == (TIM2)){
		//Brancher les horloges CLK = 1 <=> TIM2
			RCC->APB1ENR |=  (0x01 <<0);
		
	}else if (Timer1->Timer == (TIM3)){
		//Brancher les horloges CLK = 1 <=> TIM3
			RCC->APB1ENR |=  (0x01 <<1);
		
	}else if (Timer1->Timer == (TIM4)){
		//Brancher les horloges CLK = 1 <=> TIM4
			RCC->APB1ENR |=  (0x01 <<2);
	}
			
	//Asigner les valeur pour ARR et PSC
		
	Timer1->Timer->ARR = Timer1->ARR ;
	Timer1->Timer->PSC = Timer1->PSC;
				
}

void MyTimer_ActiveIT ( TIM_TypeDef  * Timer , char Prio, void (*IT_function) (void)) 
{
    
  //Autorisation de l’interruption
	// On met en 1 le bit0 (UIE) du registre DIER
	Timer->DIER |= TIM_DIER_UIE;
	
	if (Timer == TIM1){
		
		//Configuration de l’interruption sur le coeur
		NVIC->ISER[0] |= NVIC_ISER_SETENA_25;
		NVIC->IP[25] |= (Prio << 4);
		
	}else if (Timer == TIM2){
		
		//Configuration de l’interruption sur le coeur
		NVIC->ISER[0] |= NVIC_ISER_SETENA_28;
		NVIC->IP[28] |= (Prio << 4);
		
	}else if (Timer == TIM3){
		
		//Configuration de l’interruption sur le coeur
		NVIC->ISER[0] |= NVIC_ISER_SETENA_29;
		NVIC->IP[29] |= (Prio << 4);
		
	}else if (Timer == TIM4){
		
		//Configuration de l’interruption sur le coeur
		NVIC->ISER[0] |= NVIC_ISER_SETENA_30;
		NVIC->IP[30] |= (Prio << 4);
	}

}

void TIM1_UP_IRQHandler(void) { 
	
    //Si il y a un débordement -> On éteint le bit UIF
    if (TIM1->SR & TIM_SR_UIF) {
        TIM1->SR &= ~TIM_SR_UIF;
    }
}

void TIM2_IRQHandler(void) { 
	
    //Si il y a un débordement -> On éteint le bit UIF
    if (TIM2->SR & TIM_SR_UIF) {
        TIM2->SR &= ~TIM_SR_UIF;
    }
}

void TIM3_IRQHandler(void) { 
	
    //Si il y a un débordement	-> On éteint le bit UIF
    if (TIM3->SR & TIM_SR_UIF) {
        TIM3->SR &= ~TIM_SR_UIF;
    }
}

void TIM4_IRQHandler(void) { 
	
    //Si il y a un débordement -> On éteint le bit UIF
    if (TIM4->SR & TIM_SR_UIF) {
        TIM4->SR &= ~TIM_SR_UIF;
    }
}

