#ifndef ETH_H_
#define ETH_H_

#include "datatypes.h"

typedef U8 mac_t[6];

typedef struct eth_header_t {
	mac_t mac_dst;
	mac_t mac_src;
	U16 proto;
} eth_header_t;


#endif //ETH_H_
