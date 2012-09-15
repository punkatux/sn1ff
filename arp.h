#ifndef ARP_H_
#define ARP_H_

#include "datatypes.h"
#include "eth.h"
#include "ip.h"

typedef struct arp_header_t {
	U16 hw_type;
	U16 proto;
	U8 hwaddr_len;
	U8 protoaddr_len;
	U16 opcode;
	mac_t hwaddr_src;
	ip_t ipaddr_src;
	mac_t hwaddr_dst;
	ip_t ipaddr_dst;
} arp_header_t;

void arp_request(void *buffer, ip_t ipaddr_dst);

#endif //ARP_H_
