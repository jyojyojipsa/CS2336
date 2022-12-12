// Kangmin Kim
// CS 2336
// Lab 13

#include <bits.h>



int countOneBits(int num)
{
	if (num == 0) // base case
	{
		return 0;
	}
	else // general recursive case
	{
		unsigned int unum = static_cast<unsigned int>(num);
		return countOneBits(unum >> 1) + getBit(unum, 0);
	}
	
	
	
}