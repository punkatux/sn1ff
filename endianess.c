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
		return 0;
	}
	
	//Little endian
	return 1;
}

/* pointer version
bool is_little_endian(void)
{
	U16 word = 0x1234;
	U8 *byte = (U8 *) &word;

	if(*byte == 0x12)
	{
		//Big endian
		return 0;
	}
	
	//Little endian
	return 1;
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
		return 1;
	}
	
	//Little endian
	return 0;
}

/* pointer version
bool is_big_endian(void)
{
	U16 word = 0x1234;
	U8 *byte = (U8 *) &word;

	if(*byte == 0x12)
	{
		//Big endian
		return 1;
	}
	
	//Little endian
	return 0;
}
*/

