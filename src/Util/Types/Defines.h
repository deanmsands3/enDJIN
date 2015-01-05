/*
 * Defines.h
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#ifndef UTIL_DEFINES_H_
#define UTIL_DEFINES_H_

#ifdef __cplusplus
#undef __cplusplus
#endif
#define __cplusplus 201103L

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#ifndef SUCCESS
	#define SUCCESS 0
#endif
#ifndef FAILURE
	#define FAILURE (~SUCCESS)
#endif

#endif /* UTIL_DEFINES_H_ */
