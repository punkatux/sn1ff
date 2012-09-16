#include <stdlib.h>

#include <sys/socket.h>
#include <netpacket/packet.h>
#include <net/ethernet.h>

#include "endianess.h"
#include "macros.h"
#include "netif.h"

#include <unistd.h>

ip_t ip_local = {192, 168, 1, 200};
mac_t mac_local = {0x48, 0x5b, 0x39, 0x62, 0x1f, 0x60};

static int rawsock = -1;

void netif_init(void)
{
	rawsock = socket(AF_PACKET, SOCK_RAW, hton16(ETH_P_ALL));
	if(rawsock == -1)
	{
		fprintf(stderr, "Can't open RAW socket.\n");
		exit(EXIT_FAILURE);
	}
}

U32 netif_write(void *buffer, U32 length)
{
	if(rawsock != -1)
	{
		return write(rawsock, buffer, length);
	}
	
	return -1;
}
