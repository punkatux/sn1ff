#include <stdio.h>
#include <stdlib.h>

#include "datatypes.h"
#include "macros.h"
#include "arp.h"

int main(void)
{
	static U8 buffer[42];
	arp_request(buffer, (ip_t) {192, 168, 1, 201});
	
	hexdump_var(buffer);

	return EXIT_SUCCESS;
}
