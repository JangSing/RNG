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
	RNG->SR &= 0x111;
	if(RNG->SR==0x1)
		return 1;
	else {
		return 0;
	}
}

void enableRngReg(){
	RNG->CR=((uint32_t)(0x4));
}

int main (){
	rngUnresetEnableClock();
	enableRngReg();


	uint32_t randomVal;

	while(1){
		if(readyToRead()){
			randomVal=RNG->DR;
		}
	}
}
