//Useful Types and Defines
#ifndef __TYPES_H__
#define __TYPES_H__
//Set C++ Dialect
#ifdef __cplusplus
#undef __cplusplus
#endif
#define __cplusplus 201103L

#include <cstdint>

typedef void (*voidFuncPtr)();
typedef void (*voidFloatFuncPtr)(float);
typedef void (*voidBooleanFuncPtr)(bool);
typedef void (*voidUint16FuncPtr)(uint16_t);
typedef uint16_t (*Uint16Uint16FuncPtr)(uint16_t);

typedef union{
	struct{
		uint16_t lo;
		uint16_t hi;
	}u16;
	uint32_t u32;
	uint32_t i32;
	float  f;
}Versatype32;

typedef union{
	struct{
		uint16_t lol;
		uint16_t loh;
		uint16_t hil;
		uint16_t hih;
	}u16;
	struct{
		uint32_t lo;
		uint32_t hi;
	}u32;
	uint64_t u64;
	double d;
}Versatype64;

#ifndef FALSE
	#define FALSE 0
#endif
#ifndef TRUE
	#define TRUE !FALSE
#endif
#ifndef NULL
	#define NULL ((void*)0)
#endif

#ifndef SUCCESS
	#define SUCCESS 0
#endif
#ifndef FAILURE
	#define FAILURE (~SUCCESS)
#endif


#endif
