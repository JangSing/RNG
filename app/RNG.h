#ifndef __RNG_H__
#define __RNG_H__

#include <stdint.h>

typedef struct RNGtype_t RNGtype;
struct RNGtype_t{
	uint32_t CR;
	uint32_t SR;
	uint32_t DR;
};

#define RNG_REG ((RNGtype *)(0x50060800))

void enableInterrupt();

#endif // __RNG_H__
