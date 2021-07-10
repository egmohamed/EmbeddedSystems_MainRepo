#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#ifndef STDINT_H

enum CPU_TYPES
{
	CPU_TYPE_8,
	CPU_TYPE_16,
	CPU_TYPE_32,
	CPU_TYPE_64
};

enum CPU_BIT_ORDER
{
	LSB_FIRST,
	MSB_FIRST
};

enum CPU_BYTE_ORDER
{
	LOW_BYTE_FIRST,
	HIGH_BYTE_FIRST
};

#define WORD_SIZE 			64U
#define CPU_TYPE            CPU_TYPE_64
#define CPU_BIT_ORDER       LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST


#ifndef _Bool
#define _Bool unsigned char
#endif

typedef _Bool              bool_t;
typedef unsigned char      uint8;
typedef signed char        sint8;
typedef char               char_t;

typedef unsigned short int uint16;
typedef signed short int   sint16;

typedef unsigned int       uint32;
typedef signed int         sint32;

typedef unsigned long long uint64;
typedef signed long long   sint64;

typedef float              float32;
typedef double             float64;



typedef volatile unsigned char      vuint8;
typedef volatile signed char        vint8;

typedef volatile unsigned short int vuint16;
typedef volatile signed short int   vint16;

typedef volatile unsigned int       vuint32;
typedef volatile signed int         vint32;

typedef volatile unsigned long long vuint64;
typedef volatile signed long long   vint64;

#ifndef False 
#define False (bool_t) 0
#endif 

#ifndef True
#define True (bool_t) 1
#endif

#endif 		/* STDINT_H */
#endif 		/* PLATFORM_TYPES_H */
