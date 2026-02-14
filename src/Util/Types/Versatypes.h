/*
 * Versatypes.h
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#pragma once
#ifndef SRC_UTIL_TYPES_VERSATYPES_H_
#define SRC_UTIL_TYPES_VERSATYPES_H_

#include <functional>

#include "BitFields.h"

union VersaType16{
	uint8_t u8[2];
	uint16_t u16 {};
	struct{
		uint8_t lo;
		uint8_t hi;
	}u8n;
	struct{
		int8_t lo;
		int8_t hi;
	}i8n;
	int16_t i16;
	[[nodiscard]] uint16_t asUInt16() const;
	[[nodiscard]] int16_t asInt16() const;
	[[nodiscard]] uint16_t getValue() const;
	bool operator==(const VersaType16 &rhs) const;
};


union VersaType32{
	uint8_t u8[4];
	uint16_t u16[2];
	struct{
		uint16_t lo;
		uint16_t hi;
	}u16n;
	uint32_t u32 {};
	int32_t i32;
	VersaType16 v16[2];
	struct{
		VersaType16 lo;
		VersaType16 hi;
	}v16n;

	float  f;
	[[nodiscard]] uint32_t asUInt32() const;
	[[nodiscard]] int32_t asInt32() const;
	[[nodiscard]] uint32_t getValue() const;
	bool operator==(const VersaType32 &rhs) const;
};


union VersaType64{
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
	uint64_t u64 {};

	int8_t i8[8];
	int16_t i16[4];
	struct{
		int16_t lol;
		int16_t loh;
		int16_t hil;
		int16_t hih;
	}i16n;

	int32_t i32[2];
	struct{
		int32_t lo;
		int32_t hi;
	}i32n;

	int64_t i64;

	VersaType32 v32[2];
	struct{
	  VersaType32 lo;
	  VersaType32 hi;
	}v32n;

	double d;

	[[nodiscard]] uint64_t asUInt64() const;

	[[nodiscard]] int64_t asInt64() const;

	[[nodiscard]] uint64_t getValue() const;
	bool operator==(const VersaType64 &rhs) const;
};


template <>
struct std::hash<VersaType32>{
	size_t operator()(const VersaType32 &x ) const noexcept {
		return hash<uint32_t>()(x.u32);
	}
};
template <>
struct std::hash<VersaType64>{
	size_t operator()(const VersaType64 &x ) const noexcept {
		return hash<uint64_t>()(x.u64);
	}
};


#endif /* SRC_UTIL_TYPES_VERSATYPES_H_ */
