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

