#include <stdio.h>
#include <stdlib.h>

#include "macros.h"
#include "endianess.h"

int main(void)
{
	U16 port = 10000;

	hexdump(port);

	hexdump(hton16(port));
	hexdump(ntoh16(hton16(port)));

	return EXIT_SUCCESS;
}
