// Kangmin Kim
// CS 2336
// Lab 17
#include <iostream>
#include <bits.h>

using namespace std;

// printBinary is a recursive function that writes the binary
// representation of num to output stream os
void printHexadecimal(int num, ostream& os){
	if(num == 0)
	{
		return;
	}
	else
	{
		
		
		unsigned int unum = static_cast<unsigned int>(num);
		
		printHexadecimal(unum >> 4, os);  // 16 bits = 4; from cs 24  28	
		if(getBits(unum,0,4) >= 0 && getBits(unum,0,4) < 10)
			os << getBits(unum,0,4);
		else if(getBits(unum,0,4) == 10)
			os << 'A';
		else if(getBits(unum,0,4) == 11)
			os << 'B';
		else if(getBits(unum,0,4) == 12)
			os << 'C';
		else if(getBits(unum,0,4) == 13)
			os << 'D';
		else if(getBits(unum,0,4) == 14)
			os << 'E';
		else if(getBits(unum,0,4) == 15)
			os << 'F';

	}
}
