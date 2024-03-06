/* 
 * @File:   std_types.h
 * @Author: Mostafa Ahmed Allam
 * @email:  maag7503@gmail.com
 * @LinkedIn: https://www.linkedin.com/in/mostafa-allam-58869624a/
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

/* ---------------------- Include Section ---------------------- */
#include "std_libraries.h"
#include "compiler.h"
/* ---------------------- Datatype Section ---------------------- */

typedef unsigned char                   uint8;
typedef signed char                     sint8;
typedef unsigned short                  uint16;
typedef signed short                    sint16;
typedef unsigned long                   uint32;
typedef signed long                     sint32;
typedef unsigned long long              uint64;
typedef signed long long                sint64;

typedef float                           float32;
typedef double                          float64;

typedef uint8                           STD_ReturnType;

/* ---------------------- Macro definition Section ---------------------- */

#define ZERO_INIT                       uint8(0x00)

#define E_NOT_OK                        (0x00)
#define E_OK                            (0x01)

#endif	/* STD_TYPES_H */


