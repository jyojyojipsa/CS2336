// Kangmin Kim
// CS 2336
// Lab 14
#include <iostream>
#include <bits.h>

using namespace std;

// printBinary is a recursive function that writes the binary
// representation of num to output stream os
void printBinary(int num, ostream& os){
	if(num == 0)
	{
		return;
	}
	else
	{
		unsigned int unum = static_cast<unsigned int>(num);
		printBinary(unum >> 1, os);  // 16 bits = 4; from cs 24  28 
		os << getBit(unum, 0);
	}
}
