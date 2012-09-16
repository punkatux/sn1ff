#ifndef MACROS_H_
#define MACROS_H_

#include <stdio.h>
#include "datatypes.h"

#define hexdump_var(var)				\
{												\
	U8 *ptr = (U8 *) &var;				\
	unsigned bytes = sizeof(var);		\
	while(bytes--)							\
		printf("%02X ", *ptr++);		\
	putchar('\n');							\
}

#define hexdump_exp(exp)				\
{												\
	typeof(data) expr = exp;			\
	U8 *ptr = (U8 *) &expr;				\
	unsigned bytes = sizeof(expr);	\
	while(bytes--)							\
		printf("%02X ", *ptr++);		\
	putchar('\n');							\
}

#endif //MACROS_H_
