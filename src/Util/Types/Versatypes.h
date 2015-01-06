/*
 * Versatypes.h
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#ifndef SRC_UTIL_TYPES_VERSATYPES_H_
#define SRC_UTIL_TYPES_VERSATYPES_H_
#include "BitFields.h"
#ifdef __cplusplus
union VersaType32{
#else
typedef union{
#endif
	uint8_t u8[4];
	uint16_t u16[2];
	struct{
		uint16_t lo;
		uint16_t hi;
	}u16n;
	uint32_t u32;
	int32_t i32;
	float  f;
#ifdef __cplusplus
	inline const uint32_t asUInt32(){
		return u32;
	}
	VersaType32(uint32_t newU32=0UL):u32(newU32){}
	uint32_t getValue() const {
	    return u32;
	}
};
inline bool operator==(const VersaType32 &lhs, const VersaType32 &rhs){
	return (lhs.getValue()==rhs.getValue());
}
#else
}VersaType32;
#endif

#ifdef __cplusplus
union VersaType64{
#else
typedef union{
#endif
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
#ifdef __cplusplus
	inline const uint64_t asUInt64(){
		return u64;
}
	uint64_t getValue() const {
	    return u64;
	}

	VersaType64(uint64_t newU64=0ULL):u64(newU64){}
};
inline bool operator==(const VersaType64 &lhs, const VersaType64 &rhs){
	return (lhs.getValue()==rhs.getValue());
}
#else
}VersaType64;
#endif

#ifdef __cplusplus
namespace std {
    template <>
        class hash<VersaType32>{
        public :
        size_t operator()(const VersaType32 &x ) const{
            return hash<uint32_t>()(x.u32);
        }
    };
}
namespace std {
    template <>
        class hash<VersaType64>{
        public :
        size_t operator()(const VersaType64 &x ) const{
            return hash<uint64_t>()(x.u64);
        }
    };
}

#endif




#endif /* SRC_UTIL_TYPES_VERSATYPES_H_ */
