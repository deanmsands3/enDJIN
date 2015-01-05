/*
 * Versatypes.h
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#ifndef SRC_UTIL_TYPES_VERSATYPES_H_
#define SRC_UTIL_TYPES_VERSATYPES_H_
#include "BitFields.h"

typedef union{
	uint8_t u8[4];
	uint16_t u16[2];
	struct{
		uint16_t lo;
		uint16_t hi;
	}u16n;
	uint32_t u32;
	int32_t i32;
	float  f;
}VersaType32;

typedef union{
	uint8_t u8[8];
	uint16_t u16[4];
	struct{
		uint16_t lol;
		uint16_t loh;
		uint16_t hil;
		uint16_t hih;
	}u16n;
	uint32_t u32[2];
	struct{
		uint32_t lo;
		uint32_t hi;
	}u32n;
	uint64_t u64;
	double d;
}VersaType64;





#endif /* SRC_UTIL_TYPES_VERSATYPES_H_ */
