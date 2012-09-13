#include <stdio.h>
#include <stdlib.h>
#include "endianess.h"

int main(void)
{
	printf("%s endian\n", is_little_endian() ? "Little" : "Big");

	return EXIT_SUCCESS;
}
