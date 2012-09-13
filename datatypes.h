#ifndef DATATYPES_H_
#define DATATYPES_H_

#define false FALSE
#define true TRUE

typedef enum {FALSE = 0, TRUE = 1} bool;

#include <stdint.h>

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;

#endif //DATATYPES_H_
