#ifndef NETIF_H_
#define NETIF_H_

#include "datatypes.h"
#include "eth.h"
#include "ip.h"

extern ip_t ip_local;
extern mac_t mac_local;

void netif_init(void);
U32 netif_write(void *buffer, U32 length);

#endif //NETIF_H_
