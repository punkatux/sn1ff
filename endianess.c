#include "endianess.h"
#include "datatypes.h"

bool is_little_endian(void)
{
	union {
		U16 word;
		U8 bytes[2];
	} data;

	data.word = 0x1234;
	if(data.bytes[0] == 0x12)
	{
		//Big endian
		return false;
	}
	
	//Little endian
	return true;
}

/* pointer version
bool is_little_endian(void)
{
	U16 word = 0x1234;
	U8 *byte = (U8 *) &word;

	if(*byte == 0x12)
	{
		//Big endian
		return false;
	}
	
	//Little endian
	return true;
}
*/

bool is_big_endian(void)
{
	union {
		U16 word;
		U8 bytes[2];
	} data;

	data.word = 0x1234;
	if(data.bytes[0] == 0x12)
	{
		//Big endian
		return true;
	}
	
	//Little endian
	return false;
}

/* pointer version
bool is_big_endian(void)
{
	U16 word = 0x1234;
	U8 *byte = (U8 *) &word;

	if(*byte == 0x12)
	{
		//Big endian
		return true;
	}
	
	//Little endian
	return false;
}
*/

U16 hton16(U16 x_host)
{
	U8 *ptr = (U8 *) &x_host;
	U16 x_net = x_host;
	
	if(is_little_endian())
		x_net = (ptr[0] << 8) | ptr[1];

	return x_net;
}

U32 hton32(U32 x_host)
{
	U8 *ptr = (U8 *) &x_host;
	U32 x_net = x_host;
	
	if(is_little_endian())
		x_net = (ptr[0] << 24) | (ptr[1] << 16) | (ptr[2] << 8) | ptr[3];

	return x_net;
}
