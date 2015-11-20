#include "stm32f4xx.h"
#include "RNG.h"
#include "Rcc.h"
#include <stdint.h>

void rngUnresetEnableClock(){
	RccType *Rcc= (RccType *)0x40023800;
	Rcc->RCC_AHB2RSTR = 0x00000000;
	Rcc->RCC_AHB2ENR=0x00000040;
}

int readyToRead(){
	RNG_REG->SR &= 0x111;
	if(RNG_REG->SR==0x1)
		return 1;
	else {
		return 0;
	}
}

void enableRngReg(){
	RNG_REG->CR=((uint32_t)(0x4));
}

/*
void HASH_RNG_IRQHandler(){
	int status = RNG_reg->RNG_SR;
	if(status == 1)
		randomValue = RNG_REG->RNG_DR;
	else
		RNG_REG->RNG_SR = 0;

	entered++;
}
*/

int main (){
	rngUnresetEnableClock();
	enableRngReg();

	HAL_NVIC_EnableIRQ(HASH_RNG_IRQn);

	uint32_t randomVal;

	while(1){
		if(readyToRead()){
			randomVal=RNG_REG->DR;
		}
	}
}
