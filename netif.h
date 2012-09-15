#ifndef NETIF_H_
#define NETIF_H_

#include "eth.h"
#include "ip.h"

ip_t ip_local = {192, 168, 1, 200};
mac_t mac_local = {0x48, 0x5b, 0x39, 0x62, 0x1f, 0x60};

#endif //NETIF_H_
