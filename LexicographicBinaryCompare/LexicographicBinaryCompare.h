// Copyright Nettention Inc. 
// MIT License.

#pragma once 

#include <stdint.h>

// compares two binarys and returns negative if 1 is smaller, positive if 1 is bigger, or 0 if same.
inline int LexicographicBinaryCompare32(const void* pBinary1, int binary1Length, const void* pBinary2, int binary2Length)
{
	int bigLength1 = binary1Length >> 2;
	int smallLength1 = binary1Length & 3;
	int bigLength2 = binary2Length >> 2;
	int smallLength2 = binary2Length & 3;

	uint32_t* bigPtr1 = (uint32_t*)pBinary1;
	uint32_t* bigPtr2 = (uint32_t*)pBinary2;

	// fast compare
	while (bigLength1 > 0 && bigLength2 > 0)
	{
		if (*bigPtr1 < *bigPtr2)
			return -1;
		if (*bigPtr1 > *bigPtr2)
			return 1;
		bigPtr1++;
		bigPtr2++;

		bigLength1--;
		bigLength2--;
	}

	// compare the remainder
	uint8_t* smallPtr1 = (uint8_t*)bigPtr1;
	uint8_t* smallPtr2 = (uint8_t*)bigPtr2;

	while (smallLength1 > 0 && smallLength2 > 0)
	{
		uint8_t v1, v2;
#ifdef __ANDROID__
		// some old Android compilers does not support __packed keyword.
		memcpy(&v1, smallPtr1, 1);
		memcpy(&v2, smallPtr2, 1);
#else
		v1 = *smallPtr1;
		v2 = *smallPtr2;
#endif
		if (v1 < v2)
			return -1;
		if (v1 > v2)
			return 1;

		smallLength1--;
		smallLength2--;
	}

	if (smallLength1 > 0) // all previous bytes are the same, and the longer binary is the bigger one. if 1 is bigger, then we return positive value.
		return 1;
	if (smallLength2 > 0) // the vice versa case
		return -1;

	// binary contents and the lengths are same.
	return 0;
}
