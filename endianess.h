#ifndef ENDIANESS_H_
#define ENDIANESS_H_

#include "datatypes.h"

bool is_little_endian(void);
bool is_big_endian(void);

U16 hton16(U16 x_host);
U32 hton32(U32 x_host);
#define ntoh16(x_net)	hton16(x_net)
#define ntoh32(x_net)	hton32(x_net)

#endif //ENDIANESS_H_
