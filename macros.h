#ifndef MACROS_H_
#define MACROS_H_

#include "datatypes.h"

#define hexdump(data)					\
{												\
	typeof(data) x = data;				\
	U8 *ptr = (U8 *) &x;					\
	unsigned bytes = sizeof(data);	\
	while(bytes--)							\
		printf("%02X ", *ptr++);		\
	putchar('\n');							\
}

#endif //MACROS_H_
