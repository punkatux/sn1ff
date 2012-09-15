#include <string.h>

#include "endianess.h"
#include "netif.h"
#include "arp.h"

void arp_request(void *buffer, ip_t ipaddr_dst)
{
	eth_header_t eth_header;
	arp_header_t arp_header;

	mac_t mac_broadcast = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; 

	memcpy(eth_header.mac_dst, mac_broadcast, sizeof(mac_t));
	memcpy(eth_header.mac_src, mac_local, sizeof(mac_t));
	eth_header.proto = hton16(0x0806);										//0x0806 - ARP

	arp_header.hw_type = hton16(0x0001);									//0x0001 - Ethernet
	arp_header.proto = hton16(0x0800);										//0x0800 - IP
	arp_header.hwaddr_len = sizeof(mac_t);
	arp_header.protoaddr_len = sizeof(ip_t);
	arp_header.opcode = hton16(0x0001);										//0x0001 - ARP Request
	memcpy(arp_header.hwaddr_src, mac_local, sizeof(mac_t));
	memcpy(arp_header.ipaddr_src, ip_local, sizeof(ip_t));
	memset(arp_header.hwaddr_dst, 0, sizeof(mac_t));
	memcpy(arp_header.ipaddr_dst, ipaddr_dst, sizeof(ip_t));

	memcpy(buffer, &eth_header, sizeof(eth_header));
	buffer += sizeof(eth_header);
	memcpy(buffer, &arp_header, sizeof(arp_header));
}
